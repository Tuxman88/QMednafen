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

# include "aboutwindow.h"

Gui::AboutWindow::AboutWindow ( Base::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::AboutWindow::~AboutWindow ( void )
{
}

void Gui::AboutWindow::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   
   return;
}

void Gui::AboutWindow::updateText ( void )
{
   tab_widget->setTabText ( about_tab_index   , shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAboutTab ) );
   tab_widget->setTabText ( credits_tab_index , shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutCreditsTab ) );
   tab_widget->setTabText ( license_tab_index , shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutLicenseTab ) );
   
   close_button->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutClose ) );
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAboutTitle ) );
   
   return;
}

void Gui::AboutWindow::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   tab_widget = new QTabWidget ();
   main_layout->addWidget ( tab_widget );
   
   about_panel   = new Gui::AboutPanel ( shared_components );
   credits_panel = new Gui::CreditsPanel ( shared_components );
   license_panel = new Gui::LicensePanel ( shared_components );
   
   about_tab_index   = tab_widget->addTab ( about_panel   , shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAboutTab ) );
   credits_tab_index = tab_widget->addTab ( credits_panel , shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutCreditsTab ) );
   license_tab_index = tab_widget->addTab ( license_panel , shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutLicenseTab ) );
   
   buttons_layout = new QHBoxLayout ();
   main_layout->addLayout ( buttons_layout );
   buttons_layout->addStretch ();
   
   close_button = new QPushButton ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutClose ) );
   buttons_layout->addWidget ( close_button );
   
   connect ( close_button , SIGNAL ( clicked ( bool ) ) , this , SLOT ( closeAboutWindow () ) );
   
   setWindowIcon ( QPixmap ( ":/icon-main-16" ) );
   
   return;
}

void Gui::AboutWindow::closeAboutWindow ( void )
{
   this->setVisible ( false );
   
   return;
}

void Gui::AboutWindow::openAboutWindow ( void )
{
   this->setVisible ( true );
   setFixedSize ( size () );
   
   return;
}
