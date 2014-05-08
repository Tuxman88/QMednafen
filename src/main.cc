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

# include <QtWidgets/QApplication>
# include "gui/gui.h"
# include "core/core.h"
# include "base/base.h"

int main ( int argc , char** argv )
{
   // Prepare Qt system
   QApplication app ( argc , argv );
   
   // Create basic and neede pointers
   Base::SharedComponents* shared_components;
   Core::Kernel* kernel;
   Gui::MainWindow* main_window;
   Gui::ConfigWindow* config_window;
   
   // Create components
   shared_components = new Base::SharedComponents ();
   
   if ( shared_components->pluginLoadState () == Base::PluginManager::NonePluginLoaded )
   {
      /*
       * ADD ERROR REPORTING
       */
      qDebug () << "QMednafen: Error: None plugin loaded.";
      
      return ( 1 );
   }
   
   shared_components->plugins ()->loadValues ();
   
   kernel = new Core::Kernel ( shared_components );
   main_window = new Gui::MainWindow ( shared_components );
   config_window = new Gui::ConfigWindow ( shared_components );
   
   // Connect signals from the MainWindow
   QObject::connect ( main_window , SIGNAL ( exitNow () )      , kernel , SLOT ( exitNow () ) );
   QObject::connect ( main_window , SIGNAL ( about () )        , kernel , SLOT ( about () ) );
   QObject::connect ( main_window , SIGNAL ( openGameDisc () ) , kernel , SLOT ( openGameDisc () ) );
   QObject::connect ( main_window , SIGNAL ( openRom () )      , kernel , SLOT ( openRom () ) );
   QObject::connect ( main_window , SIGNAL ( config () )       , kernel , SLOT ( config () ) );
   QObject::connect ( main_window , SIGNAL ( library () )      , kernel , SLOT ( library () ) );
   
   // Connect signals from the Kernel
   QObject::connect ( kernel , SIGNAL ( closeMainWindow () ) , main_window , SLOT ( closeMainWindow () ) );
   QObject::connect ( kernel , SIGNAL ( openConfigWindow () ) , config_window , SLOT ( openConfigWindow () ) );
   
   // Display window
   main_window->show ();
   // Make the window no resizable
   main_window->setFixedSize ( main_window->size () );
   
   // Run the application
   app.exec ();
   
   // Delete needed components
   delete shared_components;
   delete kernel;
   delete main_window;
   
   return ( 0 );
}
