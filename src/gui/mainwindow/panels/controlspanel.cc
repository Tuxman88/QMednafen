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

# include "controlspanel.h"

Gui::ControlsPanel::ControlsPanel ( Base::SharedComponents* new_shared_components )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
   updateText ();
}

Gui::ControlsPanel::~ControlsPanel ( void )
{
}

void Gui::ControlsPanel::buildGui ( void )
{
   main_layout = new QGridLayout ( this );
   setLayout ( main_layout );
   button_config = new QPushButton ( "..." );
   button_library = new QPushButton ( "..." );
   button_open_game_disc = new QPushButton ( "..." );
   button_open_rom = new QPushButton ( "..." );
   label_config = new QLabel ( "..." );
   label_library = new QLabel ( "..." );
   label_open_game_disc = new QLabel ( "..." );
   label_open_rom = new QLabel ( "..." );
   
   main_layout->addWidget ( button_open_rom , 0 , 0 );
   main_layout->addWidget ( label_open_rom , 0 , 1 );
   main_layout->addWidget ( button_open_game_disc , 1 , 0 );
   main_layout->addWidget ( label_open_game_disc , 1 , 1 );
   main_layout->addWidget ( button_library , 2 , 0 );
   main_layout->addWidget ( label_library , 2 , 1 );
   main_layout->addWidget ( button_config , 3 , 0 );
   main_layout->addWidget ( label_config , 3 , 1 );
   
   return;
}

void Gui::ControlsPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )    , this , SLOT   ( updateText () ) );
   connect ( button_open_rom            , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( openRom () ) );
   connect ( button_open_game_disc      , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( openGameDisc () ) );
   connect ( button_library             , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( library () ) );
   connect ( button_config              , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( config () ) );
   
   return;
}

void Gui::ControlsPanel::updateText ( void )
{
   setTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainGroupName ) );
   
   button_open_rom->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainOpenRom ) );
   button_open_game_disc->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainOpenGameDisc ) );
   button_library->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainLibrary ) );
   button_config->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainConfig ) );
   
   label_open_rom->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainOpenRomDescription ) );
   label_open_game_disc->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainOpenGameDiscDescription ) );
   label_library->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainLibraryDescription ) );
   label_config->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainConfigDescription ) );
   
   return;
}
