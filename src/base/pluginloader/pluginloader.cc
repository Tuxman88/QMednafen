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

# include "pluginloader.h"

Base::PluginLoader::PluginLoader ( void )
   : QObject ()
{
   plugins_loaded = new QVector< Base::Plugin* > ();
}

Base::PluginLoader::~PluginLoader ( void )
{
   delete plugins_loaded;
}

Base::PluginLoader::LoadState Base::PluginLoader::load ( QStringList folder_paths )
{
   qDebug () << "Folders: " << folder_paths;    
   
   for ( int i = 0; i < folder_paths.size (); i++ )
   {
      QDir plugins_folder ( folder_paths[ i ] );
      qDebug () << "Checking: " << folder_paths[ i ];
      
      if ( plugins_folder.exists () )
      {
         QStringList filters;
      
         filters << "*.qmp";
         plugins_folder.setNameFilters ( filters );
         
         QStringList files;
         files = plugins_folder.entryList ();
         
         for ( int j = 0; j < files.size (); j++ )
         {
            qDebug () << "From: " << folder_paths[ i ] << " as " << files[ j ];
            Base::Plugin* new_plugin;
            QFile plugin_file ( folder_paths[ i ] + files[ j ] );
            
            if ( plugin_file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
            {
               new_plugin = new Base::Plugin ();
               
               qDebug () << "Loading plugin";
               plugin_file >> (*new_plugin);
               plugins_loaded->append ( new_plugin );
            }            
            else
            {
               qDebug () << "PluginLoader::load: Error: Can't open plugin file " << files[ j ] << " from " << folder_paths[ i ];
            }
         }
      }
   }
   
   return ( AllOk );
}

QVector< Base::Plugin* >* Base::PluginLoader::pluginsLoaded ( void )
{
   return ( plugins_loaded );
}
