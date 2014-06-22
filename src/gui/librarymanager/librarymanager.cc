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

# include "librarymanager.h"

Gui::LibraryManager::LibraryManager ( Base::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
   updateText ();
   
   already_added = false;
}

Gui::LibraryManager::~LibraryManager ( void )
{
}

void Gui::LibraryManager::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   consoles_panel = new Gui::ConsolesPanel ( shared_components );
   main_layout->addWidget ( consoles_panel );
   
   buttons_layout = new QHBoxLayout ();
   main_layout->addLayout ( buttons_layout );
   
   scan_button = new QPushButton ( "..." );
   close_button = new QPushButton ( "..." );
   
   buttons_layout->addWidget ( scan_button );
   buttons_layout->addStretch ();
   buttons_layout->addWidget ( close_button );
   
   scanning_dialog = new Gui::ScanningDialog ( shared_components );
   
   QPixmap program_icon ( ":/icon-main-16" );
   setWindowIcon ( QIcon ( program_icon ) );
   
   return;
}

void Gui::LibraryManager::connectAll ( void )
{
   connect ( close_button               , SIGNAL ( clicked ( bool ) )                     , this , SLOT   ( closeLibraryManager () ) );
   connect ( scan_button                , SIGNAL ( clicked ( bool ) )                     , this , SLOT   ( startScanProcess () ) );
   connect ( scanning_dialog            , SIGNAL ( cancelScan () )                        , this , SLOT   ( cancelScan () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () )                        , this , SLOT   ( updateText () ) );
   connect ( consoles_panel             , SIGNAL ( launchLibraryGame ( const QString& ) ) , this , SIGNAL ( launchLibraryGame ( const QString& ) ) );
   
   return;
}

void Gui::LibraryManager::updateText ( void )
{
   scan_button->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiLibraryManagerScan ) );
   close_button->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiLibraryManagerClose ) );
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiLibraryManagerTitle ) );
   
   return;
}

void Gui::LibraryManager::cancelScan ( void )
{
   scanning_dialog->setVisible ( false );
   emit cancelScanProcess ();
   scan_button->setEnabled ( true );
   
   return;
}

void Gui::LibraryManager::startScanProcess ( void )
{
   scan_button->setEnabled ( false );
   scanning_dialog->setFixedSize ( QSize ( 600 , 100 ) );
   scanning_dialog->setVisible ( true );
   emit scanLibraryFolders ();
   
   return;
}

void Gui::LibraryManager::scanningFolder ( const QString& folder_name )
{
   scanning_dialog->scanningFolder ( folder_name );
   
   return;
}

void Gui::LibraryManager::updateList ( void )
{
   qDebug () << "LibraryManager: Updating game list.";
   
   scan_button->setEnabled ( true );
   scanning_dialog->setVisible ( false );
   
   consoles_panel->setRomManager ( manager );
   consoles_panel->updateList ();
   
   return;
}

void Gui::LibraryManager::closeLibraryManager ( void )
{
   setVisible ( false );
   cancelScan ();
   
   return;
}

void Gui::LibraryManager::openLibraryManager ( Core::RomManager* rom_manager )
{
   if ( !already_added )
   {
      manager = rom_manager;
      
      updateList ();
      already_added = true;
   }
   
   setFixedSize ( QSize ( 600 , 400 ) );
   setVisible ( true );
   
   return;
}
