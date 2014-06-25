/*
 * QMednafen, a Qt user interface for Mednafen.
 * 
 * Copyright (C) 2014, Moises Chavez Martinez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */  

# include "rommanager.h"

Core::RomManager::RomManager ( Base::SharedComponents* new_shared_components )
   : QObject ()
{
   shared_components = new_shared_components;
   
   library_path = QDir::homePath ();
   
   if ( !library_path.endsWith ( QDir::separator () ) )
   {
      library_path += QDir::separator ();
   }
   
   library_path += ".QMednafenLibrary.lib";
   qDebug () << "RomManager: Library file path: " << library_path;
   
   tryCreateLibrary ();
   loadLibrary ();
   
   scan_paths = shared_components->config ()->operator[] ( Base::KeyCfgCorePathsLibrary ).split ( ";" );
   
   scanning = false;
}

Core::RomManager::~RomManager ( void )
{
}

QList< QString >& Core::RomManager::consoleList ( void )
{
   return ( console_list );
}

QMap< QString, QList< Core::RomEntry* > >& Core::RomManager::entryMap ( void )
{
   return ( entry_map );
}

void Core::RomManager::cancelScanProcess ( void )
{
   qDebug () << "RomManager: Canceling scan processes if any.";
   emit localCancelCall ();
   
   return;
}

void Core::RomManager::tryCreateLibrary ( void )
{
   QFile file ( library_path );
   
   if ( file.exists () )
   {
      return;
   }
   
   if ( !file.open ( QIODevice::WriteOnly | QIODevice::Text ) )
   {
      return;
   }
   
   QTextStream stream ( &file );
   
   stream << "0\n";
   
   return;
}

void Core::RomManager::saveLibrary ( void )
{
   qDebug () << "RomManager: Saving library contents to " << library_path;
   // Try open the output file
   QFile file ( library_path );
   
   if ( !file.open ( QIODevice::WriteOnly | QIODevice::Truncate ) )
   {
      return;
   }
   
   QTextStream output ( &file );
   
   // Create a list of the RomEntry instances
   QList< RomEntry* > roms;
   
   for ( int i = 0; i < console_list.size (); i++ )
   {
      QList< RomEntry* > console_roms;
      console_roms = entry_map[ console_list[ i ] ];
      
      for ( int j = 0; j < console_roms.size (); j++ )
      {
         roms.append ( console_roms[ j ] );
      }
   }
   
   // Send the amount of entries to write
   output << roms.size () << "\n";
   
   // Send the entries
   for ( int i = 0; i < roms.size (); i++ )
   {
      output << roms[ i ]->name () << "\n";
      output << roms[ i ]->console () << "\n";
      output << roms[ i ]->path () << "\n";
   }
   
   return;
}

void Core::RomManager::loadLibrary ( void )
{
   qDebug () << "RomManager: Loading library located in " << library_path;
   QFile file ( library_path );
   
   if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      return;
   }
   
   QByteArray line = file.readLine ();
   unsigned int entry_amount = QString ( line ).toUInt ();
   unsigned int actual_entry = 0;
      
   while ( !file.atEnd () && actual_entry < entry_amount )
   {
      RomEntry* entry = new RomEntry ();
      
      line = file.readLine ();
      entry->setName ( QString ( line ).trimmed () );
      line = file.readLine ();
      entry->setConsole ( QString ( line ).trimmed () );
      line = file.readLine ();
      entry->setPath ( QString ( line ).trimmed () );
      
      if ( !entry_map.contains ( entry->console () ) )
      {
         console_list.append ( entry->console () );
      }
      
      entry_map[ entry->console () ].append ( entry );
            
      actual_entry++;
   }
   
   return;
}

void Core::RomManager::gameFound ( const QString& file_name )
{
   QString console;
   console = shared_components->plugins ()->detectType ( extractExtention ( file_name ) );
   
   RomEntry* entry = new RomEntry ();

   entry->setName ( extractName ( file_name ) );
   entry->setConsole ( console );
   entry->setPath ( file_name );
   
   if ( !entry_map.contains ( entry->console () ) )
   {
      console_list.append ( entry->console () );
   }
      
   entry_map[ entry->console () ].append ( entry );
   
   return;
}

QString Core::RomManager::extractName ( QString file_path )
{
   QStringList path_pieces = file_path.split ( QDir::separator () );
   QString file_name = path_pieces[ path_pieces.size () - 1 ];
   
   return ( file_name );
}

QString Core::RomManager::extractExtention ( const QString& name )
{
   QString extention;
   QStringList pieces;
   
   pieces = name.split ( "." );
   extention = pieces[ pieces.size () - 1 ];
   
   return ( extention );
}

void Core::RomManager::removeAllGames ( void )
{
   for ( int i = 0; i < console_list.size (); i++ )
   {
      QList< RomEntry* > roms;
      roms = entry_map[ console_list[ i ] ];
      
      for ( int j = 0; j < roms.size (); j++ )
      {
         delete roms[ j ];
      }
      
      roms.clear ();
      entry_map[ console_list[ i ] ].clear ();
   }
   
   entry_map.clear ();
   console_list.clear ();
   
   return;
}

void Core::RomManager::scanComplete ( void )
{
   mutex.lock ();
   scanning = false;
   mutex.unlock ();
   
   saveLibrary ();
   
   emit updateList ();
   
   return;
}

void Core::RomManager::scanFolders ( void )
{
   qDebug () << "RomManager: Requested to scan folders for games.";
   mutex.lock ();
   
   if ( scanning )
   {
      mutex.unlock ();
      return;
   }
   
   scanning = true;
   mutex.unlock ();
   
   
   removeAllGames ();
   
   qDebug () << "RomManager: Starting to scan folders for games.";
   
   FolderScanner* folder_scanner;
   folder_scanner = new FolderScanner ( scan_paths ,
                                        shared_components->plugins ()->getValidExtentions () );
   
   connect ( folder_scanner , SIGNAL ( gameFound ( const QString& ) )      , this           , SLOT   ( gameFound      ( const QString& ) ) );
   connect ( folder_scanner , SIGNAL ( scanningFolder ( const QString& ) ) , this           , SIGNAL ( scanningFolder ( const QString& ) ) );
   connect ( folder_scanner , SIGNAL ( scanComplete () )                   , this           , SLOT   ( scanComplete   () ) );
   connect ( this           , SIGNAL ( localCancelCall () )                , folder_scanner , SLOT   ( cancelScanProcess () ) );
   
   QThreadPool::globalInstance ()->start ( folder_scanner );
   
   return;
}
