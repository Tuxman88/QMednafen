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

# include "optionbiinteger.h"

Base::OptionBiInteger::OptionBiInteger ( QString options , QStringList values )
   : PluginOption ()
{
   option_type = BiInteger;
   
   // The integer values only correspond to one command option
   QStringList commands = options.split ( "," );
   option_command_a = commands[ 0 ];
   option_command_b = commands[ 1 ];
   option_description = values[ 0 ];
   option_min_value = values[ 2 ].toLong ();
   option_max_value = values[ 3 ].toLong ();
   QStringList default_values;
   default_values = values[ 4 ].split ( "," );
   option_default_value_a = default_values[ 0 ].toLong ();
   option_default_value_b = default_values[ 1 ].toLong ();
   reset ();
}

Base::OptionBiInteger::~OptionBiInteger ( void )
{
}

QStringList Base::OptionBiInteger::toString ( void )
{
   QStringList string_form;
   
   string_form << QString ( "-%1" ).arg ( option_command_a );
   string_form << QString ( "%1" ).arg ( option_current_value_a );
   string_form << QString ( "-%1" ).arg ( option_command_b );
   string_form << QString ( "%1" ).arg ( option_current_value_b );
   
   return ( string_form );
}

void Base::OptionBiInteger::autoLoad ( QMap< QString , QString >& values )
{
   if ( values.contains ( option_command_a ) )
   {
      option_current_value_a = values[ option_command_a ].toLong ();
   }
   
   if ( values.contains ( option_command_b ) )
   {
      option_current_value_b = values[ option_command_b ].toLong ();
   }
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionBiInteger::saveOption ( QTextStream& output_file )
{
   output_file << option_command_a << "=" << option_current_value_a << "\n";
   output_file << option_command_b << "=" << option_current_value_b << "\n";
   
   return;
}

long int Base::OptionBiInteger::currentValueA ( void )
{
   return ( option_current_value_a );
}

long int Base::OptionBiInteger::currentValueB ( void )
{
   return ( option_current_value_b );
}

long int Base::OptionBiInteger::defaultValueA ( void )
{
   return ( option_default_value_a );
}

long int Base::OptionBiInteger::defaultValueB ( void )
{
   return ( option_default_value_b );
}

void Base::OptionBiInteger::reset ( void )
{
   option_current_value_a = option_default_value_a;
   option_current_value_b = option_default_value_b;
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionBiInteger::setCurrentValues ( const long int& new_value_a , const long int& new_value_b )
{
   option_current_value_a = new_value_a;
   option_current_value_b = new_value_b;
   
   return;
}

long int Base::OptionBiInteger::maxValue ( void )
{
   return ( option_max_value );
}

long int Base::OptionBiInteger::minValue ( void )
{
   return ( option_min_value );
}
