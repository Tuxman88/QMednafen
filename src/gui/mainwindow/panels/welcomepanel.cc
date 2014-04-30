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

# include "welcomepanel.h"


Gui::WelcomePanel::WelcomePanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   program_icon = new QLabel ();
   program_icon->setPixmap ( QPixmap ( ":/icon-main-128" ) );
   main_layout->addWidget ( program_icon );
   
   info_layout = new QVBoxLayout ();
   
   program_name = new QLabel ( "..." );
   program_description = new QLabel ( "..." );
   info_layout->addWidget ( program_name );
   info_layout->addWidget ( program_description );
   info_layout->addStretch ();
   main_layout->addLayout ( info_layout );
   
   version_layout = new QVBoxLayout ();
   
   program_version = new QLabel ( "..." );
   version_layout->addWidget ( program_version );
   version_layout->addStretch ();
   main_layout->addLayout ( version_layout );
   
   updateText ();
}

Gui::WelcomePanel::~WelcomePanel ( void )
{
}

void Gui::WelcomePanel::updateText ( void )
{
   program_name->setText ( shared_components->text ()->operator[] ( Base::KeyTxtProgramName ) );
   program_description->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainDescription ) );
   program_version->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMainVersion ) + 
                              QString ( ": " ) +
                              shared_components->text ()->operator[] ( Base::KeyTxtProgramVersion ) );
   
   QFont font;
   font = program_name->font ();
   font.setPointSize ( 22 );
   program_name->setFont ( font );
   
   font = program_version->font ();
   font.setPointSize ( 10 );
   program_version->setFont ( font );
   
   font = program_description->font ();
   font.setPointSize ( 10 );
   program_description->setFont ( font );
   
   return;
}
