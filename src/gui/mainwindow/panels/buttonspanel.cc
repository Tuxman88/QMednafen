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

# include "buttonspanel.h" 

Gui::ButtonsPanel::ButtonsPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
   updateText ();
}

Gui::ButtonsPanel::~ButtonsPanel ( void )
{
}

void Gui::ButtonsPanel::buildGui(void)
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   button_about = new QPushButton ( "..." );
   button_exit  = new QPushButton ( "..." );
   
   main_layout->addStretch ();
   main_layout->addWidget ( button_about );
   main_layout->addWidget ( button_exit );
   
   return;
}

void Gui::ButtonsPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )    , this , SLOT ( updateText () ) );
   connect ( button_about               , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( about () ) );
   connect ( button_exit                , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( exitNow () ) );
   
   return;
}

void Gui::ButtonsPanel::updateText ( void )
{
   button_about->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainAbout ) );
   button_exit->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainExit ) );
   
   return;
}
