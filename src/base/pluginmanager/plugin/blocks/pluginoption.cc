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

# include "pluginoption.h"

Base::PluginOption::PluginOption ( void )
   : QObject ()
{
   option_description = "None description";
   option_type = None;
}

Base::PluginOption::~PluginOption ( void )
{
}

QStringList Base::PluginOption::toString ( void )
{
   QStringList option;
   
   return ( option );
}

void Base::PluginOption::autoLoad ( QMap< QString , QString >& values )
{
   values.size ();
   return;
}

QString Base::PluginOption::description ( void )
{
   return ( option_description );
}

Base::PluginOption::OptionType Base::PluginOption::type ( void )
{
   return ( option_type );
}

void Base::PluginOption::reset ( void )
{
   return;
}

QTextStream& operator<< ( QTextStream& output_file , Base::PluginOption* plugin_option )
{
   plugin_option->saveOption ( output_file );
   
   return ( output_file );
}

void Base::PluginOption::saveOption ( QTextStream& output_file )
{
   output_file << "PluginOption: Error: Logical error found.\n";
   
   return;
}
