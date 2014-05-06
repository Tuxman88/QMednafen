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

# include "optionenum.h"

Base::OptionEnum::OptionEnum ( QString options , QStringList values )
   : PluginOption ()
{
   option_type = Enum;
   
   // The bool values only correspond to one comman option
   option_command = options;
   option_description = values[ 0 ];
   
   QStringList possible_values;
   possible_values = values[ 2 ].split ( ";" );
   
   for ( int i = 0; i < possible_values.size (); i++ )
   {
      QStringList correct_values;
      correct_values = possible_values[ i ].split ( "," );
      option_values.append ( correct_values[ 0 ] );
      option_names.append ( correct_values[ 1 ] );
   }
   
   option_default_value = values[ 3 ];
   reset ();
}

Base::OptionEnum::~OptionEnum ( void )
{
}

QString Base::OptionEnum::currentValue ( void )
{
   return ( option_current_value );
}

QString Base::OptionEnum::defaultValue ( void )
{
   return ( option_default_value );
}

void Base::OptionEnum::reset ( void )
{
   option_current_value = option_default_value;
   
   return;
}

void Base::OptionEnum::setCurrentValue ( const QString& new_value )
{
   option_current_value = new_value;
   
   return;
}

QList< QString > Base::OptionEnum::names ( void )
{
   return ( option_names );
}

QList< QString > Base::OptionEnum::values ( void )
{
   return ( option_values );
}
