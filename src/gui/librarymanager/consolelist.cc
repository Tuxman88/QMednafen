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

# include "consolelist.h"

Gui::ConsoleList::ConsoleList ( Base::SharedComponents* new_shared_components )
   : QListWidget ()
{
   shared_components = new_shared_components;
   connect ( this , SIGNAL ( itemDoubleClicked ( QListWidgetItem* ) ) , this , SLOT ( doubleClicked ( QListWidgetItem* ) ) );
}

Gui::ConsoleList::~ConsoleList ( void )
{
}

void Gui::ConsoleList::setRomList ( QList< Core::RomEntry* >& rom_list )
{
   for ( int i = 0; i < rom_list.size (); i++ )
   {      
      QListWidgetItem* item;
      item = new QListWidgetItem ( rom_list[ i ]->name () , this );
      item->setSizeHint ( QSize ( size ().width () , 30 ) );
      addItem ( item );
      list_items.append ( item );
      launch_paths[ rom_list[ i ]->name () ] = rom_list[ i ]->path ();
   }
   
   return;
}

void Gui::ConsoleList::doubleClicked ( QListWidgetItem* item )
{
   qDebug () << "ConsoleList: Asking to launch game: " << launch_paths[ item->text () ];
   
   emit launchLibraryGame ( launch_paths[ item->text () ] );
   
   return;
}
