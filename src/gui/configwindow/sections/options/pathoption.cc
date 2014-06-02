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

# include "pathoption.h"

Gui::PathOption::PathOption ( Base::OptionPath* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
   connectAll ();
}

Gui::PathOption::~PathOption ( void )
{
}

void Gui::PathOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   value_line = new QLineEdit ();
   select_file = new QPushButton ( "..." );
   
   value_line->setText ( option->currentValue () );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_line );
   main_layout->addWidget ( select_file );
   
   return;
}

void Gui::PathOption::selectFile ( void )
{
   QString file_selected;
   file_selected = QFileDialog::getOpenFileName ( this );
   
   if ( file_selected == "" )
   {
      return;
   }
   
   value_line->setText ( file_selected );
   updateValue ( file_selected );
   
   return;
}

void Gui::PathOption::valuesUpdated ( void )
{
   value_line->setText ( option->currentValue () );
   
   return;
}

void Gui::PathOption::connectAll ( void )
{
   connect ( value_line , SIGNAL ( textChanged ( QString ) ) , this , SLOT ( updateValue ( QString ) ) );
   connect ( option , SIGNAL ( valuesUpdated () ) , this , SLOT ( valuesUpdated () ) );
   connect ( select_file , SIGNAL ( clicked ( bool ) ) , this , SLOT ( selectFile () ) );
   
   return;
}

void Gui::PathOption::updateValue ( const QString& value )
{
   option->setCurrentValue ( value );
   
   return;
}
