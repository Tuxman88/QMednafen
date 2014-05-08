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

# include "plugininfo.h"

Base::PluginInfo::PluginInfo ( void )
   : QObject ()
{
   plugin_author = "Unknown";
   plugin_console = "Unknown";
   plugin_description = "None";
   plugin_name = "Unknown";
   plugin_version = "Unknown";
}

Base::PluginInfo::~PluginInfo(void)
{
}

QString Base::PluginInfo::author ( void ) const
{
   return ( plugin_author );
}

QString Base::PluginInfo::console ( void ) const
{
   return ( plugin_console );
}

QString Base::PluginInfo::description ( void ) const
{
   return ( plugin_description );
}

QString Base::PluginInfo::name ( void ) const
{
   return ( plugin_name );
}

QString Base::PluginInfo::version ( void ) const
{
   return ( plugin_version );
}

QFile& operator>> ( QFile& input_file , Base::PluginInfo& plugin_info )
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
         
         if ( pieces[ 0 ] == "plugin.name" )
         {
            plugin_info.plugin_name = pieces[ 1 ];
         }
         else if ( pieces[ 0 ] == "plugin.version" )
         {
            plugin_info.plugin_version = pieces[ 1 ];            
         }
         else if ( pieces[ 0 ] == "plugin.console" )
         {
            plugin_info.plugin_console = pieces[ 1 ];            
         }
         else if ( pieces[ 0 ] == "plugin.author" )
         {
            plugin_info.plugin_author = pieces[ 1 ];            
         }
         else if ( pieces[ 0 ] == "plugin.description" )
         {
            plugin_info.plugin_description = pieces[ 1 ];            
         }
      }
   }
   
   return ( input_file );
}