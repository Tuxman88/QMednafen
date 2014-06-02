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

Gui::InstanceManager::InstanceManager ( Base::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   already_added = false;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::InstanceManager::~InstanceManager ( void )
{
}

void Gui::InstanceManager::connectAll ( void )
{
   connect ( button_close , SIGNAL ( clicked ( bool ) ) , this , SLOT ( closeInstanceManager () ) );
   
   return;
}

void Gui::InstanceManager::buildGui ( void )
{
   setWindowIcon ( QIcon ( ":/icon-main-32" ) );
   
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   list_widget = new QListWidget ();
   main_layout->addWidget ( list_widget );
   
   buttons_layout = new QHBoxLayout ();
   main_layout->addLayout ( buttons_layout );
   
   button_close = new QPushButton ( "..." );
   buttons_layout->addStretch ();
   buttons_layout->addWidget ( button_close );
   
   return;
}

void Gui::InstanceManager::updateText ( void )
{
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiInstanceManagerTitle ) );
   button_close->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiInstanceManagerButtonClose ) );
   
   return;
}

void Gui::InstanceManager::openInstanceManager ( Core::EmulatorManager* new_emulator_manager )
{
   if ( !already_added )
   {
      qDebug () << "InstanceManager: First time displaying. Saving pointer to EmulatorManager.";
      emulator_manager = new_emulator_manager;
      updateGameList ();
      connect ( emulator_manager , SIGNAL ( updateGameList () ) , this , SLOT ( updateGameList () ) );
      already_added = true;
   }
   
   this->setVisible ( true );
   this->setFixedSize ( QSize ( 500 , 300 ) );
   
   return;
}

void Gui::InstanceManager::closeInstanceManager ( void )
{
   setVisible ( false );
   
   return;
}

void Gui::InstanceManager::updateGameList ( void )
{
   qDebug () << "InstanceManager: Updating game list.";
   
   for ( int i = 0; i < list_items.size (); i++ )
   {
      list_widget->removeItemWidget ( list_items[ i ] );
      delete list_instances[ i ];
      list_instances[ i ] = 0;
      delete list_items[ i ];
   }
   
   list_instances.clear ();
   list_items.clear ();
   
   if ( emulator_manager->emulatorInstances ().size () == 0 )
   {
      return;
   }
   
   QList< Core::EmulatorInstance* > game_instances;
   
   game_instances = emulator_manager->emulatorInstances ();
   
   for ( int i = 0; i < game_instances.size (); i++ )
   {
      Gui::InstanceControl* instance_control;
      instance_control = new Gui::InstanceControl ( shared_components );
      instance_control->setGameInstance ( game_instances[ i ] );
      connect ( instance_control , SIGNAL ( closeGameInstance ( Core::EmulatorInstance* ) ) , emulator_manager , SLOT ( closeEmulatorInstance ( Core::EmulatorInstance* ) ) );
      
      list_instances.append ( instance_control );
      
      QListWidgetItem* item;
      item = new QListWidgetItem ( list_widget );
      item->setSizeHint ( QSize ( list_widget->size ().width () , 45 ) );
      list_widget->addItem ( item );
      list_widget->setItemWidget ( item , instance_control );
      list_items.append ( item );
   }
   
   return;
}
