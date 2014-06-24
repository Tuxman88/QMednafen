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

# include "birealoption.h"

Gui::BiRealOption::BiRealOption ( Base::OptionBiReal* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
   connectAll ();
}

Gui::BiRealOption::~BiRealOption ( void )
{
}

void Gui::BiRealOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   title_label->setFixedWidth ( Base::LabelWidth );
   title_label->setWordWrap ( true );
   separator_label = new QLabel ( "x" );
   value_spin_a = new QDoubleSpinBox ();
   value_spin_a->setFixedWidth ( Base::BiSpinWidth );
   value_spin_b = new QDoubleSpinBox ();
   value_spin_b->setFixedWidth ( Base::BiSpinWidth );
   
   value_spin_a->setRange ( option->minValue () , option->maxValue () );
   value_spin_a->setValue ( option->currentValueA () );
   value_spin_a->setSingleStep ( 0.01 );
   value_spin_b->setRange ( option->minValue () , option->maxValue () );
   value_spin_b->setValue ( option->currentValueB () );
   value_spin_b->setSingleStep ( 0.01 );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_spin_a );
   main_layout->addWidget ( separator_label );
   main_layout->addWidget ( value_spin_b );
   
   return;
}

void Gui::BiRealOption::valuesUpdated ( void )
{
   value_spin_a->setValue ( option->currentValueA () );
   value_spin_b->setValue ( option->currentValueB () );
   
   return;
}

void Gui::BiRealOption::connectAll ( void )
{
   connect ( value_spin_a , SIGNAL ( valueChanged ( double ) ) , this , SLOT ( updateValueA ( const double& ) ) );
   connect ( value_spin_b , SIGNAL ( valueChanged ( double ) ) , this , SLOT ( updateValueB ( const double& ) ) );
   connect ( option , SIGNAL ( valuesUpdated () ) , this , SLOT ( valuesUpdated () ) );   
   
   return;
}

void Gui::BiRealOption::updateValueA ( const double& value )
{
   option->setCurrentValues ( value , option->currentValueB () );
   
   return;
}

void Gui::BiRealOption::updateValueB ( const double& value )
{
   option->setCurrentValues ( option->currentValueA () , value );
   
   return;
}
