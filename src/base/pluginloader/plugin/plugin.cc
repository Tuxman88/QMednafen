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

# include "plugin.h"

Base::Plugin::Plugin ( void )
{
   plugin_info = new Base::PluginInfo ();
}

Base::Plugin::~Plugin ( void )
{
   delete plugin_info;
}

Base::PluginInfo* Base::Plugin::info ( void )
{
   return ( plugin_info );
}

QString Base::Plugin::savePath ( void )
{
   return ( save_path );
}

void Base::Plugin::setSavePath ( QString new_save_path )
{
   save_path = new_save_path;
   
   return;
}

QFile& operator>> ( QFile& input_file , Base::Plugin& plugin )
{
   QString line;
   
   while ( line != "[EOF]" && !input_file.atEnd () )
   {
      line = input_file.readLine ();
      line = line.simplified ();
      line = line.toUpper ();
      
      if ( line != "[EOF]" && line.size () > 0 )
      {
         if ( line == "[INFO]" )
         {
            input_file >> (*(plugin.plugin_info));
         }
      }
   }
   
   return ( input_file );
}
