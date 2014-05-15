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

# include "aboutpanel.h"

Gui::AboutPanel::AboutPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::AboutPanel::~AboutPanel ( void )
{
   delete pixmap;
}

void Gui::AboutPanel::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   program_icon_layout = new QHBoxLayout ();
   main_layout->addLayout ( program_icon_layout );
   
   program_icon = new QLabel ();
   pixmap = new QPixmap ( ":/icon-main-256" );
   program_icon->setPixmap ( *pixmap );
   
   program_icon_layout->addStretch ();
   program_icon_layout->addWidget ( program_icon );
   program_icon_layout->addStretch ();
   
   program_info_layout = new QHBoxLayout ();
   main_layout->addLayout ( program_info_layout );
   
   program_info = new QLabel ();
   program_info_layout->addWidget ( program_info );
   
   return;
}

void Gui::AboutPanel::updateText ( void )
{
   program_info->setWordWrap ( true );
   program_info->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutProgramDescription ) );
   
   return;
}

void Gui::AboutPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   
   return;
}
