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
# include "base/base.h"

int main ( int argc , char** argv )
{
   QApplication app ( argc , argv );
   
   Base::SharedComponents* shared_components;
   Gui::MainWindow* main_window;
   
   shared_components = new Base::SharedComponents ();
   main_window = new Gui::MainWindow ( shared_components );
   
   main_window->show ();
   main_window->setFixedSize ( main_window->size () );
   
   app.exec ();
   
   delete shared_components;
   delete main_window;
   
   return ( 0 );
}
