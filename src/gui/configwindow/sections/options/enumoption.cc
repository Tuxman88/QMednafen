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

# include "enumoption.h"

Gui::EnumOption::EnumOption ( Base::OptionEnum* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
}

Gui::EnumOption::~EnumOption ( void )
{
}

void Gui::EnumOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   value_combo = new QComboBox ();
   
   QStringList items;
   
   for ( int i = 0; i < option->names ().size (); i++ )
   {
      index_name_value[ option->names ()[ i ] ] = option->values ()[ i ];
      index_value_name[ option->values ()[ i ] ] = option->names ()[ i ];
      items << option->names ()[ i ];
   }
   
   value_combo->addItems ( items );
   value_combo->setCurrentText ( index_value_name[ option->currentValue () ] );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_combo );
   
   return;
}
