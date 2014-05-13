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
   
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   tab_panel = new QTabWidget ();
   main_layout->addWidget ( tab_panel );
   
   system_panel = new Gui::SystemPanel ( shared_components );
   
   tab_panel->addTab ( system_panel , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfig ) );
   
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
}

Gui::ConfigWindow::~ConfigWindow ( void )
{
}

void Gui::ConfigWindow::openConfigWindow ( void )
{
   this->setVisible ( true );
   
   return;
}

void Gui::ConfigWindow::closeConfigWindow ( void )
{
   this->setVisible ( false );
   
   return;
}
