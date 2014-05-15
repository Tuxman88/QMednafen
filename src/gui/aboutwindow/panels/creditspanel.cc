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
   
   author_alexander = new Gui::AuthorSection ( shared_components , "alexander" );
   author_doctorg = new Gui::AuthorSection ( shared_components , "doctorg" );
   author_blueamnesiac = new Gui::AuthorSection ( shared_components , "blueamnesiac" );
   
   main_layout->addWidget ( author_alexander );
   main_layout->addWidget ( author_doctorg );
   main_layout->addWidget ( author_blueamnesiac );
   
   return;
}


void Gui::CreditsPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_alexander    , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_doctorg      , SLOT ( updateText () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , author_blueamnesiac , SLOT ( updateText () ) );
   
   return;
}
