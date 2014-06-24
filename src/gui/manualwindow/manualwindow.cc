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

# include "manualwindow.h"

Gui::ManualWindow::ManualWindow ( Base::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::ManualWindow::~ManualWindow ( void )
{
}

void Gui::ManualWindow::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   document_body = new QTextBrowser ();
   document_body->setReadOnly ( true );
   document_body->setOpenExternalLinks ( true );
   main_layout->addWidget ( document_body );
   
   buttons_layout = new QHBoxLayout ();
   main_layout->addLayout ( buttons_layout );
   
   close_button = new QPushButton ( "..." );
   buttons_layout->addStretch ();
   buttons_layout->addWidget ( close_button );
   
   setWindowIcon ( QIcon ( ":/icon-main-32" ) );
   
   QFile file ( ":/manual" );
   
   if ( !file.open ( QFile::ReadOnly | QFile::Text ) )
   {
      qDebug () << "ManualWindow: Error: Can't open manual file.";
      return;
   }
   
   QTextStream in ( &file );
   
   document_body->document ()->setHtml ( in.readAll () );
   document_body->moveCursor ( QTextCursor::Start );
   
   setMinimumSize ( QSize ( 640 , 480 ) );
   
   return;
}

void Gui::ManualWindow::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )    , this , SLOT ( updateText () ) );
   connect ( close_button               , SIGNAL ( clicked ( bool ) ) , this , SLOT ( closeManualWindow () ) );
   
   return;
}

void Gui::ManualWindow::updateText ( void )
{
   close_button->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiManualClose ) );
   setWindowTitle        ( shared_components->text ()->operator[] ( Base::KeyTxtGuiManualTitle ) );
   
   return;
}

void Gui::ManualWindow::closeManualWindow ( void )
{
   setVisible ( false );
   
   return;
}

void Gui::ManualWindow::openManualWindow ( void )
{
   setVisible ( true );
   
   return;
}
