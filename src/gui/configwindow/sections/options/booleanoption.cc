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

# include "booleanoption.h"

Gui::BooleanOption::BooleanOption ( Base::OptionBoolean* new_option )
   : QWidget ()
{
   option = new_option;
   
   buildGui ();
   connectAll ();
}

Gui::BooleanOption::~BooleanOption ( void )
{
}

void Gui::BooleanOption::buildGui ( void )
{
   main_layout = new QHBoxLayout ( this );
   setLayout ( main_layout );
   
   title_label = new QLabel ( option->description () );
   title_label->setFixedWidth ( Base::LabelWidth );
   title_label->setWordWrap ( true );
   value_check = new QCheckBox ();
   
   value_check->setChecked ( option->currentValue () );
   
   main_layout->addWidget ( title_label );
   main_layout->addStretch ();
   main_layout->addWidget ( value_check );
   
   return;
}

void Gui::BooleanOption::valuesUpdated ( void )
{
   value_check->setChecked ( option->currentValue () );
   
   return;
}

void Gui::BooleanOption::connectAll ( void )
{
   connect ( value_check , SIGNAL ( stateChanged ( int ) ) , this , SLOT ( updateValue ( int ) ) );
   connect ( option , SIGNAL ( valuesUpdated () ) , this , SLOT ( valuesUpdated () ) );
   
   return;
}

void Gui::BooleanOption::updateValue ( const int& value )
{
   option->setCurrentValue ( value == Qt::Checked );
   
   return;
}
