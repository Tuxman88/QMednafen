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

# include "optioninteger.h"

Base::OptionInteger::OptionInteger ( QString options , QStringList values )
   : PluginOption ()
{
   option_type = Integer;
   
   // The integer values only correspond to one command option
   option_command = options;
   option_description = values[ 0 ];
   option_min_value = values[ 2 ].toLong ();
   option_max_value = values[ 3 ].toLong ();
   option_default_value = values[ 4 ].toLong ();
   reset ();
}

Base::OptionInteger::~OptionInteger ( void )
{
}

QString Base::OptionInteger::toString ( void )
{
   QString string_form;
   
   string_form = QString ( "-%1 %2" ).arg ( option_command ).arg ( option_current_value );
   
   return ( string_form );
}

void Base::OptionInteger::autoLoad ( QMap< QString, QString >& values )
{
   if ( values.contains ( option_command ) )
   {
      option_current_value = values[ option_command ].toLong ();
   }
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionInteger::saveOption ( QTextStream& output_file )
{
   output_file << option_command << "=" << option_current_value << "\n";
   
   return;
}

long int Base::OptionInteger::currentValue ( void )
{
   return ( option_current_value );
}

long int Base::OptionInteger::defaultValue ( void )
{
   return ( option_default_value );
}

void Base::OptionInteger::reset ( void )
{
   option_current_value = option_default_value;
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionInteger::setCurrentValue ( const long int& new_value )
{
   option_current_value = new_value;
   
   return;
}

long int Base::OptionInteger::maxValue ( void )
{
   return ( option_max_value );
}

long int Base::OptionInteger::minValue ( void )
{
   return ( option_min_value );
}
