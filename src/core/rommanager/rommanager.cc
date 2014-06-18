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
   
   tryCreateLibrary ();
   loadLibrary ();
   
   scan_paths = shared_components->config ()->operator[] ( Base::KeyCfgCorePathsLibrary ).split ( ":" );
}

Core::RomManager::~RomManager ( void )
{
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
   
   qDebug () << "RomManager: Entries to load: " << entry_amount;
   
   while ( !file.atEnd () && actual_entry < entry_amount )
   {
      RomEntry* entry = new RomEntry ();
      
      line = file.readLine ();
      entry->setName ( line );
      line = file.readLine ();
      entry->setConsole ( line );
      line = file.readLine ();
      entry->setPath ( line );
      
      entry_map[ entry->console () ].append ( entry );
      
      if ( !entry_map.contains ( entry->console () ) )
      {
         console_list.append ( entry->console () );
      }
      
      actual_entry++;
   }
   
   return;
}

void Core::RomManager::gameFound ( const QString& file_name )
{
   qDebug () << "RomManager: Found game: " << file_name;
   
   return;
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
   }
   
   entry_map.clear ();
   
   return;
}

void Core::RomManager::scanFolders ( void )
{
   removeAllGames ();
   
   FolderScanner* folder_scanner;
   folder_scanner = new FolderScanner ( scan_paths ,
                                        shared_components->plugins ()->getValidExtentions () );
   
   connect ( folder_scanner , SIGNAL ( gameFound ( const QString& ) ) , this , SLOT ( gameFound ( const QString& ) ) );
   connect ( folder_scanner , SIGNAL ( scanningFolder ( const QString& ) ) , this , SIGNAL ( scanningFolder ( const QString& ) ) );
   
   QThreadPool::globalInstance ()->start ( folder_scanner );
   
   return;
}
