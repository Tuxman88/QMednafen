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

# include "sharedcomponents.h" 

Base::SharedComponents::SharedComponents ( void )
   : QObject ()
{
   shared_configuration = new Base::Configuration ();
   shared_text = new Base::Text ( shared_configuration );
   shared_plugins = new Base::PluginLoader ();
   
   shared_plugins->load ( shared_configuration->operator[] ( Base::KeyCfgCorePathsPlugins ).split ( ";" ) );
}

Base::SharedComponents::~SharedComponents ( void )
{
   delete shared_configuration;
   delete shared_text;
   delete shared_plugins;
}

Base::Configuration* Base::SharedComponents::config ( void )
{
   return ( shared_configuration );
}

Base::Text* Base::SharedComponents::text ( void )
{
   return ( shared_text );
}

Base::PluginLoader* Base::SharedComponents::plugins ( void )
{
   return ( shared_plugins );
}
