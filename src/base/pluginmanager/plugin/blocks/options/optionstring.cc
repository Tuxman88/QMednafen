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

# include "optionstring.h"

Base::OptionString::OptionString ( QString options , QStringList values )
   : PluginOption ()
{
   option_type = String;
   
   // The QString values only correspond to one comman option
   option_command = options;
   option_description = values[ 0 ];
   option_default_value = values[ 2 ];
   reset ();
}

Base::OptionString::~OptionString ( void )
{
}

QStringList Base::OptionString::toString ( void )
{
   QStringList string_form;
   
   string_form << QString ( "-%1" ).arg ( option_command );
   string_form << QString ( "\"%1\"" ).arg ( option_current_value );
   
   return ( string_form );
}

void Base::OptionString::autoLoad ( QMap< QString, QString >& values )
{
   if ( values.contains ( option_command ) )
   {
      option_current_value = ( values[ option_command ] );
   }
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionString::saveOption ( QTextStream& output_file )
{
   output_file << option_command << "=" << option_current_value << "\n";
   
   return;
}

QString Base::OptionString::currentValue ( void )
{
   return ( option_current_value );
}

QString Base::OptionString::defaultValue ( void )
{
   return ( option_default_value );
}

void Base::OptionString::reset ( void )
{
   option_current_value = option_default_value;
   
   emit valuesUpdated ();
   
   return;
}

void Base::OptionString::setCurrentValue ( const QString& new_value )
{
   option_current_value = new_value;
   
   return;
}
