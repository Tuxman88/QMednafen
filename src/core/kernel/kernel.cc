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

# include "kernel.h"

Core::Kernel::Kernel ( Base::SharedComponents* new_shared_components ) :
   QObject ()
{
   qDebug () << "Kernel: Creating EmulatorManager and RomManager instances.";
   shared_components = new_shared_components;
   
   emulator_manager = new Core::EmulatorManager ( shared_components );
   rom_manager = new Core::RomManager ( shared_components );
   
   connect ( rom_manager , SIGNAL ( scanningFolder ( const QString& ) ) , this , SIGNAL ( scanningFolder ( const QString& ) ) );
   connect ( rom_manager , SIGNAL ( updateList () )                     , this , SIGNAL ( updateList () ) );
}

Core::Kernel::~Kernel ( void )
{
   delete emulator_manager;
   delete rom_manager;
}

void Core::Kernel::launchLibraryGame ( const QString& game_path )
{
   qDebug () << "Kernel: Requested to launch a game from the library.";
   launchFile ( game_path );
   
   return;
}

void Core::Kernel::cancelScanProcess ( void )
{
   qDebug () << "Kernel: Requested to stop the scan process.";
   rom_manager->cancelScanProcess ();
   
   return;
}

void Core::Kernel::scanLibraryFolders ( void )
{
   qDebug () << "Kernel: Requesting the RomManager to scan the games folders.";
   rom_manager->scanFolders ();
   
   return;
}

void Core::Kernel::instanceManager ( void )
{
   qDebug () << "Kernel: Displaying Instance Manager dialog";
   emit openInstanceManager ( emulator_manager );
   
   return;
}

void Core::Kernel::about ( void )
{
   qDebug () << "Kernel: Displaying About dialog";
   emit openAboutWindow ();
   
   return;
}

void Core::Kernel::config ( void )
{
   qDebug () << "Kernel: Displaying Config dialog";
   emit openConfigWindow ();
   
   return;
}

void Core::Kernel::exitNow ( void )
{
   qDebug () << "Kernel: Closing program now";
   emit closeLibraryManager ();
   emit closeConfigWindow ();
   emit closeAboutWindow ();
   emit closeInstanceManager ();
   emit closeMainWindow ();
   
   return;
}

void Core::Kernel::library ( void )
{
   qDebug () << "Kernel: Displaying Library dialog";
   emit openLibraryManager ( rom_manager );
   
   return;
}

void Core::Kernel::openGameDisc ( void )
{
   qDebug () << "Kernel: Opening game disc";
   
   QStringList emulator_options = shared_components->plugins ()->getOptions ( "cue" ); // Only the consoles that support discs have CUE extentions
   Core::EmulatorManager::DetectionType game_type = emulator_manager->detectionStringType ( shared_components->plugins ()->detectType ( "cue" ) );
      
   emulator_manager->addInstance ( "-physcd" , game_type , emulator_options );
   
   return;
}

void Core::Kernel::launchFile ( const QString& file_path )
{
   qDebug () << "Kernel: File to open: " << file_path;
   
   QStringList emulator_options = shared_components->plugins ()->getOptions ( extractExtention ( file_path ) );
   Core::EmulatorManager::DetectionType game_type = emulator_manager->detectionStringType ( shared_components->plugins ()->detectType ( extractExtention ( file_path ) ) );
      
   emulator_manager->addInstance ( file_path , game_type , emulator_options );
   
   return;
}

void Core::Kernel::openRom ( void )
{
   QString selected_file = QFileDialog::getOpenFileName ( 0 , shared_components->text ()->operator[] ( Base::KeyTxtGuiOpenROMSelectFile ) );
   
   if ( selected_file == "" )
   {
      return;
   }
   
   launchFile ( selected_file );
   
   return;
}

void Core::Kernel::reloadOptions ( void )
{
   qDebug () << "Kernel: Reloading options";
   
   shared_components->plugins ()->loadValues ();
   
   return;
}

void Core::Kernel::resetOptions ( void )
{
   qDebug () << "Kernel: Reseting options";
   
   shared_components->plugins ()->resetValues ();
   
   return;
}

void Core::Kernel::saveOptions ( void )
{
   qDebug () << "Kernel: Saving options";
   
   shared_components->plugins ()->saveValues ();
   
   return;
}

QString Core::Kernel::extractExtention ( const QString& name )
{
   QString extention;
   QStringList pieces;
   
   pieces = name.split ( "." );
   extention = pieces[ pieces.size () - 1 ];
   
   return ( extention );
}

