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
   
   buildGui ();
   connectAll ();
   updateText ();
}

Gui::MainWindow::~MainWindow ( void )
{
}

void Gui::MainWindow::buildGui ( void )
{
   menubar = new Gui::MenuBar ( shared_components );
   main_contents_panel = new Gui::MainContentsPanel ( shared_components );
   
   setMenuBar ( menubar );
   setCentralWidget ( main_contents_panel );
   setWindowIcon ( QIcon ( ":/icon-main-32" ) );
   
   return;
}

void Gui::MainWindow::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )   , this , SLOT   ( updateText () ) );
   connect ( menubar                    , SIGNAL ( openRom () )      , this , SIGNAL ( openRom () ) );   
   connect ( menubar                    , SIGNAL ( openGameDisc () ) , this , SIGNAL ( openGameDisc () ) );
   connect ( menubar                    , SIGNAL ( library () )      , this , SIGNAL ( library () ) );
   connect ( menubar                    , SIGNAL ( config () )       , this , SIGNAL ( config () ) );
   connect ( menubar                    , SIGNAL ( exitNow () )      , this , SIGNAL ( exitNow () ) );
   connect ( menubar                    , SIGNAL ( about () )        , this , SIGNAL ( about () ) );
   connect ( main_contents_panel        , SIGNAL ( openRom () )      , this , SIGNAL ( openRom () ) );   
   connect ( main_contents_panel        , SIGNAL ( openGameDisc () ) , this , SIGNAL ( openGameDisc () ) );
   connect ( main_contents_panel        , SIGNAL ( library () )      , this , SIGNAL ( library () ) );
   connect ( main_contents_panel        , SIGNAL ( config () )       , this , SIGNAL ( config () ) );
   connect ( main_contents_panel        , SIGNAL ( exitNow () )      , this , SIGNAL ( exitNow () ) );
   connect ( main_contents_panel        , SIGNAL ( about () )        , this , SIGNAL ( about () ) );
   
   return;
}

void Gui::MainWindow::updateText ( void )
{
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtProgramName ) +
                    QString ( " " ) + 
                    shared_components->text ()->operator[] ( Base::KeyTxtProgramVersion ) );
   
   return;
}

void Gui::MainWindow::closeMainWindow ( void )
{
   this->close ();
   
   return;
}
