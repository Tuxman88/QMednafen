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

# include "integeroption.h"

Gui::IntegerOption::IntegerOption ( Base::OptionInteger* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
   connectAll ();
}

Gui::IntegerOption::~IntegerOption ( void )
{
}

void Gui::IntegerOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   value_spin = new QSpinBox ();
   
   value_spin->setRange ( option->minValue () , option->maxValue () );
   value_spin->setValue ( option->currentValue () );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_spin );
   
   return;
}

void Gui::IntegerOption::valuesUpdated ( void )
{
   value_spin->setValue ( option->currentValue () );
   
   return;
}

void Gui::IntegerOption::connectAll ( void )
{
   connect ( value_spin , SIGNAL ( valueChanged ( int ) ) , this , SLOT ( updateValue ( int ) ) );
   connect ( option , SIGNAL ( valuesUpdated () ) , this , SLOT ( valuesUpdated () ) );
   
   return;
}

void Gui::IntegerOption::updateValue ( const int& value )
{
   option->setCurrentValue ( value );
   
   return;
}
