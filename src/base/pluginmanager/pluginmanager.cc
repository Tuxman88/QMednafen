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

# include "pluginmanager.h"

Base::PluginManager::PluginManager ( void )
   : QObject ()
{
   plugins_loaded = new QVector< Base::Plugin* > ();
}

Base::PluginManager::~PluginManager ( void )
{
   delete plugins_loaded;
}

void Base::PluginManager::loadValues ( void )
{
   // Iterate over the plugins and ask them to create/load their config values.
   for ( int i = 0; i < plugins_loaded->size (); i++ )
   {
      plugins_loaded->operator[] ( i )->loadOptions ();
   }
   
   return;
}

Base::PluginManager::LoadState Base::PluginManager::load ( QStringList folder_paths )
{  
   // Iterate over the list of paths where might be plugins
   for ( int i = 0; i < folder_paths.size (); i++ )
   {
      qDebug () << "PluginManager::load: Checking folder " << folder_paths[ i ];
      QDir plugins_folder ( folder_paths[ i ] );
      
      // Such folder exists?
      if ( plugins_folder.exists () )
      {
         QStringList filters;
      
         // Exists. Create a filter for the plugin extention, so, when retrieving the list of the plugins
         // contained in such folder, only the .qmp files will be listed.
         filters << "*.qmp";
         plugins_folder.setNameFilters ( filters );
         
         // Get files list.
         QStringList files;
         files = plugins_folder.entryList ();
         
         // Iterate over the list of the files.
         for ( int j = 0; j < files.size (); j++ )
         {
            // Create a file for this plugin file.
            Base::Plugin* new_plugin;
            qDebug () << "PluginManager::load: Validating file " << ( folder_paths[ i ] + files[ j ] );
            QFile plugin_file ( folder_paths[ i ] + files[ j ] );
            
            // Try to open the file
            if ( plugin_file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
            {
               // Validate the plugin file (there is possible to be any other kind of file rather than a plugin)
               /*PLUGIN VALIDATION*/
               
               // Create new plugin
               QString new_save_path = folder_paths[ i ] + files[ j ];
               
               new_save_path.replace ( new_save_path.size () - 3 , 3 , "cfg" );
               
               new_plugin = new Base::Plugin ();
               new_plugin->setSavePath ( new_save_path );
               
               // Load the plugin
               qDebug () << "PluginManager::load: Loading file...";
               plugin_file >> (*new_plugin);
               
               // Store the plugin
               plugins_loaded->append ( new_plugin );
            }
            else
            {
               qDebug () << "PluginManager::load: Error: Can't open plugin file " << files[ j ] << " from " << folder_paths[ i ];
            }
         }
      }
   }
   
   if ( plugins_loaded->size () == 0 )
   {
      return ( NonePluginLoaded );
   }
   
   return ( AllOk );
}

QVector< Base::Plugin* >* Base::PluginManager::pluginsLoaded ( void )
{
   return ( plugins_loaded );
}
