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

# include "stringoption.h"

Gui::StringOption::StringOption ( Base::OptionString* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
   connectAll ();
}

Gui::StringOption::~StringOption ( void )
{
}

void Gui::StringOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   title_label->setFixedWidth ( Base::LabelWidth );
   title_label->setWordWrap ( true );
   value_line = new QLineEdit ();
   value_line->setFixedWidth ( Base::LineWidth );
   
   value_line->setText ( option->currentValue () );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_line );
   
   return;
}

void Gui::StringOption::valuesUpdated ( void )
{
   value_line->setText ( option->currentValue () );
   
   return;
}

void Gui::StringOption::connectAll ( void )
{
   connect ( value_line , SIGNAL ( textChanged ( QString ) ) , this , SLOT ( updateValue ( QString ) ) );
   connect ( option , SIGNAL ( valuesUpdated () ) , this , SLOT ( valuesUpdated () ) );
   
   return;
}

void Gui::StringOption::updateValue ( const QString& value )
{
   option->setCurrentValue ( value );
   
   return;
}
