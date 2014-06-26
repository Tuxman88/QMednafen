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

# include "creditspanel.h"

Gui::CreditsPanel::CreditsPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
}

Gui::CreditsPanel::~CreditsPanel ( void )
{
}

void Gui::CreditsPanel::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   author_alexander      = new Gui::AuthorSection ( shared_components , "alexander" );
   author_doctorg        = new Gui::AuthorSection ( shared_components , "doctorg" );
   author_blueamnesiac   = new Gui::AuthorSection ( shared_components , "blueamnesiac" );
   author_psychotic      = new Gui::AuthorSection ( shared_components , "psychotic" );
   author_s4rs           = new Gui::AuthorSection ( shared_components , "s4rs" );
   author_wardee         = new Gui::AuthorSection ( shared_components , "wardee" );
   author_waterrat       = new Gui::AuthorSection ( shared_components , "waterrat" );
   author_wikimedia      = new Gui::AuthorSection ( shared_components , "wikimedia" );
   
   main_layout->addWidget ( author_alexander );
   main_layout->addWidget ( author_doctorg );
   main_layout->addWidget ( author_blueamnesiac );
   main_layout->addWidget ( author_psychotic );
   main_layout->addWidget ( author_s4rs );
   main_layout->addWidget ( author_wardee );
   main_layout->addWidget ( author_waterrat );
   main_layout->addWidget ( author_wikimedia );
   
   return;
}


void Gui::CreditsPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_alexander      , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_doctorg        , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_blueamnesiac   , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_psychotic      , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_s4rs           , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_wardee         , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_waterrat       , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_wikimedia      , SLOT ( updateText () ) );
   
   return;
}
