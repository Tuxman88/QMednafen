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

# include "consoleinfopanel.h"

Gui::ConsoleInfoPanel::ConsoleInfoPanel ( Base::SharedComponents* new_shared_components , Base::PluginInfo* new_plugin_info )
   : QWidget ()
{
   shared_components = new_shared_components;
   plugin_info = new_plugin_info;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::ConsoleInfoPanel::~ConsoleInfoPanel ( void )
{
}

void Gui::ConsoleInfoPanel::updateText ( void )
{
   QFont font;
   font = console_name->font ();
   font.setBold ( true );
   font.setItalic ( true );
   font.setPointSize ( 16 );
   console_name->setFont ( font );
   
   console_name->setText ( getConsoleName ( plugin_info->console () ) );
   
   return;
}

void Gui::ConsoleInfoPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   
   return;
}

void Gui::ConsoleInfoPanel::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   icon_layout = new QVBoxLayout ();
   main_layout->addLayout ( icon_layout );
   
   main_layout->addSpacing ( 5 );
   
   info_layout = new QVBoxLayout ();
   main_layout->addLayout ( info_layout );
   
   main_layout->addStretch ();
   
   QPixmap icon ( QString ( ":/unit-%1-256" ).arg ( plugin_info->console () ) );
   console_icon = new QLabel ();
   
   if ( icon.isNull () )
   {
      QPixmap backup_icon ( ":/unit-unknown-256" );
      console_icon->setPixmap ( backup_icon );
   }
   else
   {
      console_icon->setPixmap ( icon );
   }
   
   console_icon->setPixmap ( console_icon->pixmap ()->scaled ( QSize ( 150 , 150 ) ,  Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
   icon_layout->addWidget ( console_icon );
   
   console_name       = new QLabel ( ".." );
   plugin_author      = new QLabel ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigConsoleAuthor ).arg ( plugin_info->author () ) );
   plugin_name        = new QLabel ( plugin_info->name () );
   plugin_version     = new QLabel ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigConsolePluginVersion ).arg ( plugin_info->version () ) );
   plugin_description = new QLabel ( plugin_info->description () );
   
   info_layout->addWidget ( console_name );
   info_layout->addWidget ( plugin_author );
   info_layout->addWidget ( plugin_version );
   info_layout->addWidget ( plugin_name );
   info_layout->addWidget ( plugin_description );
   info_layout->addStretch ();
   
   return;
}

QString Gui::ConsoleInfoPanel::getConsoleName ( QString console_code )
{
   QString name;
   QStringList list;
   list << "lynx"
        << "gb"
        << "gba"
        << "ngp"
        << "nes"
        << "pce"
        << "pce_fast"
        << "pcfx"
        << "gg"
        << "md"
        << "sms"
        << "psx"
        << "snes"
        << "vb"
        << "wswan";
        
   console_code = console_code.toLower ();
   
   if ( list.contains ( console_code ) )
   {
      name = shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigConsoleName.arg ( console_code ) );
   }
   else
   {
      name = shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigConsoleName.arg ( "unknown" ) );
   }
   
   return ( name );
}
