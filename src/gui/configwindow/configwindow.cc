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

# include "configwindow.h"

Gui::ConfigWindow::ConfigWindow ( Base::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::ConfigWindow::~ConfigWindow ( void )
{
}

void Gui::ConfigWindow::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   tab_panel = new QTabWidget ();
   main_layout->addWidget ( tab_panel );
   
   system_panel = new Gui::SystemPanel ( shared_components );
   
   system_tab_index = tab_panel->addTab ( system_panel , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfig ) );
   
   QVector< Base::Plugin* >* plugin_list;
   plugin_list = shared_components->plugins ()->pluginsLoaded ();
   
   for ( int i = 0; i < plugin_list->size (); i++ )
   {
      Gui::PluginPanel* panel;
      Base::PluginInfo* info;
      info = plugin_list->operator[] ( i )->info();
      panel = new Gui::PluginPanel ( shared_components , plugin_list->operator[] ( i ) );
      plugins_panels.append ( panel );
      
      tab_panel->addTab ( panel , info->consoleDescription () );
   }
   
   buttons_layout = new QHBoxLayout ();
   main_layout->addLayout ( buttons_layout );
   
   save_button = new QPushButton ( "..." );
   reload_button = new QPushButton ( "..." );
   reset_button = new QPushButton ( "..." );
   buttons_layout->addWidget ( reset_button );
   buttons_layout->addStretch ();
   buttons_layout->addWidget ( reload_button );
   buttons_layout->addWidget ( save_button );
   
   QPixmap program_icon ( ":/icon-main-16" );
   setWindowIcon ( QIcon ( program_icon ) );
   
   return;
}

void Gui::ConfigWindow::connectAll ( void )
{
   connect ( save_button                , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( saveOptions () ) );
   connect ( reload_button              , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( reloadOptions () ) );
   connect ( reset_button               , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( resetOptions () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () )    , this , SLOT ( updateText () ) );
   
   return;
}

void Gui::ConfigWindow::updateText ( void )
{
   tab_panel->setTabText  ( system_tab_index , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfig ) );
   save_button->setText   ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSave ) );
   reload_button->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigReload ) );
   reset_button->setText  ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigReset ) );
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigTitle ) );
   
   return;
}

void Gui::ConfigWindow::openConfigWindow ( void )
{
   this->setVisible ( true );
   setMinimumSize ( size () );
   
   return;
}

void Gui::ConfigWindow::closeConfigWindow ( void )
{
   this->setVisible ( false );
   
   return;
}
