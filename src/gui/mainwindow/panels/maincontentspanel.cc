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

# include "maincontentspanel.h"

Gui::MainContentsPanel::MainContentsPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
}

Gui::MainContentsPanel::~MainContentsPanel ( void )
{
}

void Gui::MainContentsPanel::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   welcome_panel = new Gui::WelcomePanel ( shared_components );
   main_layout->addWidget ( welcome_panel );
   main_layout->addStretch ();
   
   controls_panel = new Gui::ControlsPanel ( shared_components );
   main_layout->addWidget ( controls_panel );
   main_layout->addStretch ();
   
   buttons_panel = new Gui::ButtonsPanel ( shared_components );
   main_layout->addWidget ( buttons_panel );
   
   return;
}

void Gui::MainContentsPanel::connectAll ( void )
{
   connect ( controls_panel , SIGNAL ( openRom () )      , this , SIGNAL ( openRom () ) );
   connect ( controls_panel , SIGNAL ( openGameDisc () ) , this , SIGNAL ( openGameDisc () ) );
   connect ( controls_panel , SIGNAL ( library () )      , this , SIGNAL ( library () ) );
   connect ( controls_panel , SIGNAL ( config () )       , this , SIGNAL ( config () ) );
   connect ( buttons_panel  , SIGNAL ( about () )        , this , SIGNAL ( about () ) );
   connect ( buttons_panel  , SIGNAL ( exitNow () )      , this , SIGNAL ( exitNow () ) );
   
   return;
}
