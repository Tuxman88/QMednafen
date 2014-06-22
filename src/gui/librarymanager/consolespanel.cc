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

# include "consolespanel.h"

Gui::ConsolesPanel::ConsolesPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   tab_panel = new QTabWidget ();
   main_layout->addWidget ( tab_panel );
}

Gui::ConsolesPanel::~ConsolesPanel ( void )
{
}

void Gui::ConsolesPanel::setRomManager ( Core::RomManager* new_rom_manager )
{
   rom_manager = new_rom_manager;
   
   return;
}

void Gui::ConsolesPanel::updateList ( void )
{
   removePanels ();
   
   // Create a copy of the console list
   consoles_list = rom_manager->consoleList ();
   
   for ( int i = 0; i < consoles_list.size (); i++ )
   {
      ConsoleList* game_list;
      
      game_list = new ConsoleList ( shared_components );
      game_list->setRomList ( rom_manager->entryMap ()[ consoles_list[ i ] ] );
      consoles_map[ consoles_list[ i ] ] = game_list;
      tab_panel->addTab ( game_list , consoles_list[ i ] );
      connect ( game_list , SIGNAL ( launchLibraryGame ( const QString& ) ) , this , SIGNAL ( launchLibraryGame ( const QString& ) ) );
   }
   
   return;
}

void Gui::ConsolesPanel::removePanels ( void )
{
   for ( int i = 0; i < consoles_list.size (); i++ )
   {
      int index = tab_panel->indexOf ( consoles_map[ consoles_list[ i ] ] );
      
      if ( index != -1 ) // If the widget is found
      {
         tab_panel->removeTab ( index );
      }
      
      delete consoles_map[ consoles_list[ i ] ];
      consoles_map[ consoles_list[ i ] ] = 0;
   }
   
   consoles_list.clear ();
   consoles_map.clear ();
   
   qDebug () << "Salen: " << consoles_list.size ();
   return;
}
