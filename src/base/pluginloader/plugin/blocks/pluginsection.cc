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

# include "pluginsection.h"

Base::PluginSection::PluginSection ( void )
   : QObject ()
{
   section_name = "Section";
}

Base::PluginSection::~PluginSection ( void )
{
}

QString Base::PluginSection::name ( void )
{
   return ( section_name );
}

QFile& operator>> ( QFile& input_file , Base::PluginSection& plugin_section )
{
   QString line;
   
   while ( line != "[/]" )
   {
      line = input_file.readLine ();
      line = line.simplified ();
      
      if ( line != "[/]" && line.size () > 0 )
      {
         QStringList pieces;
         
         pieces = line.split ( "=" );
         pieces[ 0 ] = pieces[ 0 ].simplified ();
         pieces[ 0 ] = pieces[ 0 ].toLower ();
         pieces[ 1 ] = pieces[ 1 ].simplified ();
         
         
      }
   }
   
   return ( input_file );
}