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

# include "biintegeroption.h"

Gui::BiIntegerOption::BiIntegerOption ( Base::OptionBiInteger* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
}

Gui::BiIntegerOption::~BiIntegerOption ( void )
{
}

void Gui::BiIntegerOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   separator_label = new QLabel ( "x" );
   value_spin_a = new QSpinBox ();
   value_spin_b = new QSpinBox ();
   
   value_spin_a->setRange ( option->minValue () , option->maxValue () );
   value_spin_a->setValue ( option->currentValueA () );
   value_spin_b->setRange ( option->minValue () , option->maxValue () );
   value_spin_b->setValue ( option->currentValueB () );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_spin_a );
   main_layout->addWidget ( separator_label );
   main_layout->addWidget ( value_spin_b );
   
   return;
}
