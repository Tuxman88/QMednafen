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

# include "realoption.h"

Gui::RealOption::RealOption ( Base::OptionReal* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
   connectAll ();
}

Gui::RealOption::~RealOption ( void )
{
}

void Gui::RealOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   title_label->setFixedWidth ( Base::LabelWidth );
   title_label->setWordWrap ( true );
   value_spin = new QDoubleSpinBox ();
   value_spin->setFixedWidth ( Base::SpinWidth );
   
   value_spin->setRange ( option->minValue () , option->maxValue () );
   value_spin->setValue ( option->currentValue () );
   value_spin->setSingleStep ( 0.01 );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_spin );
   
   return;
}

void Gui::RealOption::valuesUpdated ( void )
{
   value_spin->setValue ( option->currentValue () );
   
   return;
}

void Gui::RealOption::connectAll ( void )
{
   connect ( value_spin , SIGNAL ( valueChanged ( double ) ) , this , SLOT ( updateValue ( double ) ) );
   connect ( option , SIGNAL ( valuesUpdated () ) , this , SLOT ( valuesUpdated () ) );
   
   return;
}

void Gui::RealOption::updateValue ( const double& value )
{
   option->setCurrentValue ( value );
   
   return;
}
