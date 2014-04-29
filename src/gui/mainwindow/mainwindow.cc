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

# include "mainwindow.h"

Gui::MainWindow::MainWindow ( Base::SharedComponents* new_shared_components )
   : QMainWindow ()
{
   shared_components = new_shared_components;
   
   // Build components
   menubar = new Gui::MenuBar ( shared_components );
   main_contents_panel = new Gui::MainContentsPanel ( shared_components );
   
   // Set components
   setMenuBar ( menubar );
   setCentralWidget ( main_contents_panel );
   
   // Configure Gui
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtProgramName ) + QString ( " " ) + shared_components->text ()->operator[] ( Base::KeyTxtProgramVersion ) );
   setWindowIcon ( QIcon ( ":/icon-main-32" ) );
}

Gui::MainWindow::~MainWindow ( void )
{
}
