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
   
   already_added = false;
}

Gui::LibraryManager::~LibraryManager ( void )
{
}

void Gui::LibraryManager::buildGui ( void )
{   
   return;
}

void Gui::LibraryManager::connectAll ( void )
{
   return;
}

void Gui::LibraryManager::scanningFolder ( const QString& folder_name )
{
   return;
}

void Gui::LibraryManager::updateList ( void )
{
   qDebug () << "LibraryManager: Updating game list.";
   
   return;
}

void Gui::LibraryManager::closeLibraryManager ( void )
{
   setVisible ( false );
   
   return;
}

void Gui::LibraryManager::openLibraryManager ( Core::RomManager* rom_manager )
{
   if ( !already_added )
   {
      manager = rom_manager;
      
      updateList ();
   }
   
   setVisible ( true );
   
   return;
}
