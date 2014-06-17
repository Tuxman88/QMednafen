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

# include "instancemanager.h"

Gui::InstanceControl::InstanceControl ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::InstanceControl::~InstanceControl ( void )
{
}

void Gui::InstanceControl::setGameInstance ( Core::EmulatorInstance* new_game_instance )
{
   game_instance = new_game_instance;
   game_name->setText ( game_instance->gameName () );
   
   switch ( game_instance->gameType () )
   {
      case 0:
         console_icon->setPixmap ( QPixmap ( ":/unit-auto-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 1:
         console_icon->setPixmap ( QPixmap ( ":/unit-lynx-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 2:
         console_icon->setPixmap ( QPixmap ( ":/unit-gb-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 3:
         console_icon->setPixmap ( QPixmap ( ":/unit-gba-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 4:
         console_icon->setPixmap ( QPixmap ( ":/unit-ngp-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 5:
         console_icon->setPixmap ( QPixmap ( ":/unit-nes-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 6:
         console_icon->setPixmap ( QPixmap ( ":/unit-pce-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 7:
         console_icon->setPixmap ( QPixmap ( ":/unit-pce_fast-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 8:
         console_icon->setPixmap ( QPixmap ( ":/unit-pcfx-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 9:
         console_icon->setPixmap ( QPixmap ( ":/unit-gg-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 10:
         console_icon->setPixmap ( QPixmap ( ":/unit-md-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 11:
         console_icon->setPixmap ( QPixmap ( ":/unit-sms-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 12:
         console_icon->setPixmap ( QPixmap ( ":/unit-psx-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 13:
         console_icon->setPixmap ( QPixmap ( ":/unit-snes-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 14:
         console_icon->setPixmap ( QPixmap ( ":/unit-vb-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
         
      case 15:
         console_icon->setPixmap ( QPixmap ( ":/unit-wswan-256" ).scaled ( QSize ( 30 , 30 ) , Qt::KeepAspectRatio , Qt::SmoothTransformation ) );
         break;
   }
   
   return;
}

void Gui::InstanceControl::closeGame ( void )
{
   emit closeGameInstance ( game_instance );
   
   return;
}

void Gui::InstanceControl::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   console_icon = new QLabel ();
   game_name = new QLabel ( "..." );
   close_game = new QPushButton ( "..." );
   
   main_layout->addWidget ( console_icon );
   main_layout->addWidget ( game_name );
   main_layout->addStretch ();
   main_layout->addWidget ( close_game );
   
   return;
}

void Gui::InstanceControl::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   connect ( close_game , SIGNAL ( clicked ( bool ) ) , this , SLOT ( closeGame () ) );
   
   return;
}

void Gui::InstanceControl::updateText ( void )
{
   close_game->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiInstanceManagerButtonCloseGame ) );
   
   return;
}
