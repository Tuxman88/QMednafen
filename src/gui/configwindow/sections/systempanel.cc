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
 
# include "systempanel.h"

Gui::SystemPanel::SystemPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::SystemPanel::~SystemPanel ( void )
{
}

void Gui::SystemPanel::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   buildLanguageSection ();
   
   main_layout->addStretch ();
   
   return;
}

void Gui::SystemPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )                   , this , SLOT ( updateText () ) );
   connect ( language_combo             , SIGNAL ( currentIndexChanged ( QString ) ) , this , SLOT ( languageChanged () ) );
   
   return;
}

void Gui::SystemPanel::updateText ( void )
{
   language_group->setTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigLanguage ) );
   language_label->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigSelectLanguage ) );
   
   return;
}

void Gui::SystemPanel::buildLanguageSection ( void )
{
   language_group = new QGroupBox ();
   main_layout->addWidget ( language_group );
   
   language_layout = new QHBoxLayout ();
   language_group->setLayout ( language_layout );
   
   language_label = new QLabel ( "..." );
   language_layout->addWidget ( language_label );
   language_layout->addStretch ();
   
   language_combo = new QComboBox ();
   language_layout->addWidget ( language_combo );
   language_combo->addItem ( "English" );
   language_combo->addItem ( "Spanish" );
   QString current_language = ( shared_components->config ()->operator[] ( Base::KeyCfgGuiLanguage ) == "english" ) ? "English" : "Spanish";
   language_combo->setCurrentText ( current_language );
   
   return;
}

void Gui::SystemPanel::languageChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiLanguage , language_combo->currentText ().toLower () );
   
   return;
}
