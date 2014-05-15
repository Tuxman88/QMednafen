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

# include "authorsection.h"

Gui::AuthorSection::AuthorSection ( Base::SharedComponents* new_shared_components , QString new_author_code )
   : QWidget ()
{
   author_code = new_author_code;
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::AuthorSection::~AuthorSection ( void )
{
}

void Gui::AuthorSection::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   author_name = new QLabel ();
   author_description = new QLabel ();
   author_link = new QLabel ();
   
   main_layout->addWidget ( author_name );
   main_layout->addWidget ( author_link );
   main_layout->addWidget ( author_description );
   
   return;
}

void Gui::AuthorSection::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   
   return;
}

void Gui::AuthorSection::updateText ( void )
{
   author_description->setWordWrap ( true );
   
   QFont font;
   author_name->font ();
   font.setBold ( true );
   font.setPointSize ( 16 );
   author_name->setFont ( font );
   
   author_name->setText        ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAuthorName.arg        ( author_code ) ) );
   author_link->setText        ( QString ( "<a href=\"%1" ).arg ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAuthorLink.arg ( author_code ) ) ) +
                                 QString ( "\">%1" ).arg ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAuthorLink.arg ( author_code ) ) ) +
                                 QString ( "<\\a>" )
                               );
   author_link->setTextFormat ( Qt::RichText );
   author_link->setTextInteractionFlags ( Qt::TextBrowserInteraction );
   author_link->setOpenExternalLinks ( true );
   author_description->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiAboutAuthorDescription.arg ( author_code ) ) );
   
   return;
}
