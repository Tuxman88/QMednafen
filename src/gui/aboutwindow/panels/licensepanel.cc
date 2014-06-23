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

# include "licensepanel.h"

Gui::LicensePanel::LicensePanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
}

Gui::LicensePanel::~LicensePanel ( void )
{
}

void Gui::LicensePanel::buildGui(void)
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   text_edit = new QTextEdit ( this );
   main_layout->addWidget ( text_edit );
   
   return;
}


void Gui::LicensePanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   
   return;
}

void Gui::LicensePanel::updateText ( void )
{
   QFile file ( ":/license" );
   
   if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      qDebug () << "LicensePanel: WARNING: Can't load license file.";
      return;
   }
   
   QTextStream stream ( &file );
   
   QString line;
   while ( !stream.atEnd () )
   {
      line = stream.readLine ();
      text_edit->setText ( text_edit->toPlainText () + line + "\n" );
   }
   
   return;
}
