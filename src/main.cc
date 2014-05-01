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

# include <QtGui/QApplication>
# include "gui/gui.h"
# include "core/core.h"
# include "base/base.h"

int main ( int argc , char** argv )
{
   QApplication app ( argc , argv );
   
   Base::SharedComponents* shared_components;
   Core::Kernel* kernel;
   Gui::MainWindow* main_window;
   
   shared_components = new Base::SharedComponents ();
   kernel = new Core::Kernel ( shared_components );
   main_window = new Gui::MainWindow ( shared_components );
   
   QObject::connect ( main_window , SIGNAL ( exitNow () )      , kernel , SLOT ( exitNow () ) );
   QObject::connect ( main_window , SIGNAL ( about () )        , kernel , SLOT ( about () ) );
   QObject::connect ( main_window , SIGNAL ( openGameDisc () ) , kernel , SLOT ( openGameDisc () ) );
   QObject::connect ( main_window , SIGNAL ( openRom () )      , kernel , SLOT ( openRom () ) );
   QObject::connect ( main_window , SIGNAL ( config () )       , kernel , SLOT ( config () ) );
   QObject::connect ( main_window , SIGNAL ( library () )      , kernel , SLOT ( library () ) );
   
   QObject::connect ( kernel , SIGNAL ( closeMainWindow () ) , main_window , SLOT ( closeMainWindow () ) );
   
   main_window->show ();
   main_window->setFixedSize ( main_window->size () );
   
   app.exec ();
   
   delete shared_components;
   delete kernel;
   delete main_window;
   
   return ( 0 );
}
