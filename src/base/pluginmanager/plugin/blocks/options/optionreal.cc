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

# include "optionreal.h"

Base::OptionReal::OptionReal ( QString options , QStringList values )
   : PluginOption ()
{
   option_type = Real;
   
   // The integer values only correspond to one command option
   option_command = options;
   option_description = values[ 0 ];
   option_min_value = values[ 2 ].toDouble ();
   option_max_value = values[ 3 ].toDouble ();
   option_default_value = values[ 4 ].toDouble ();
   reset ();
}

Base::OptionReal::~OptionReal ( void )
{
}

QStringList Base::OptionReal::toString ( void )
{
   QStringList string_form;
   
   string_form << QString ( "-%1" ).arg ( option_command );
   string_form << QString ( "%1" ).arg ( option_current_value );
      
   return ( string_form );
}

void Base::OptionReal::autoLoad ( QMap< QString, QString >& values )
{
   if ( values.contains ( option_command ) )
   {
      option_current_value = values[ option_command ].toDouble ();
   }
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionReal::saveOption ( QTextStream& output_file )
{
   output_file << option_command << "=" << option_current_value << "\n";
   
   return;
}

double Base::OptionReal::currentValue ( void )
{
   return ( option_current_value );
}

double Base::OptionReal::defaultValue ( void )
{
   return ( option_default_value );
}

void Base::OptionReal::reset ( void )
{
   option_current_value = option_default_value;
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionReal::setCurrentValue ( const double& new_value )
{
   option_current_value = new_value;
   
   return;
}

double Base::OptionReal::maxValue ( void )
{
   return ( option_max_value );
}

double Base::OptionReal::minValue ( void )
{
   return ( option_min_value );
}
