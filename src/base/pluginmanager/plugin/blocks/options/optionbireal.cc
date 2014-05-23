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

# include "optionbireal.h"

Base::OptionBiReal::OptionBiReal ( QString options , QStringList values )
   : PluginOption ()
{
   option_type = BiReal;
   
   // The integer values only correspond to one command option
   QStringList commands = options.split ( "," );
   option_command_a = commands[ 0 ];
   option_command_b = commands[ 1 ];
   option_description = values[ 0 ];
   option_min_value = values[ 2 ].toDouble ();
   option_max_value = values[ 3 ].toDouble ();
   QStringList default_values;
   default_values = values[ 4 ].split ( "," );
   option_default_value_a = default_values[ 0 ].toDouble ();
   option_default_value_b = default_values[ 1 ].toDouble ();
   reset ();
}

Base::OptionBiReal::~OptionBiReal ( void )
{
}

QString Base::OptionBiReal::toString ( void )
{
   QString string_form;
   
   string_form = QString ( "-%1 %2 -%3 %4 " ).arg ( option_command_a )
                                           .arg ( option_current_value_a )
                                           .arg ( option_command_b )
                                           .arg ( option_current_value_b );
   
   return ( string_form );
}

void Base::OptionBiReal::autoLoad ( QMap< QString , QString >& values )
{
   if ( values.contains ( option_command_a ) )
   {
      option_current_value_a = values[ option_command_a ].toDouble ();
   }
   
   if ( values.contains ( option_command_b ) )
   {
      option_current_value_b = values[ option_command_b ].toDouble ();
   }
   
   return;
}

void Base::OptionBiReal::saveOption ( QTextStream& output_file )
{
   output_file << option_command_a << "=" << option_current_value_a << "\n";
   output_file << option_command_b << "=" << option_current_value_b << "\n";
   
   return;
}

double Base::OptionBiReal::currentValueA ( void )
{
   return ( option_current_value_a );
}

double Base::OptionBiReal::currentValueB ( void )
{
   return ( option_current_value_b );
}

double Base::OptionBiReal::defaultValueA ( void )
{
   return ( option_default_value_a );
}

double Base::OptionBiReal::defaultValueB ( void )
{
   return ( option_default_value_b );
}

void Base::OptionBiReal::reset ( void )
{
   option_current_value_a = option_default_value_a;
   option_current_value_b = option_default_value_b;
   
   return;
}

void Base::OptionBiReal::setCurrentValues ( const double& new_value_a , const double& new_value_b )
{
   option_current_value_a = new_value_a;
   option_current_value_b = new_value_b;
   
   return;
}

double Base::OptionBiReal::maxValue ( void )
{
   return ( option_max_value );
}

double Base::OptionBiReal::minValue ( void )
{
   return ( option_min_value );
}
