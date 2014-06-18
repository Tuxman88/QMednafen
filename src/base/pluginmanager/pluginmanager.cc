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

Base::PluginManager::PluginManager ( Base::Configuration* new_shared_configuration )
   : QObject ()
{
   shared_configuration = new_shared_configuration;
   plugins_loaded = new QVector< Base::Plugin* > ();
}

Base::PluginManager::~PluginManager ( void )
{
   delete plugins_loaded;
}

void Base::PluginManager::loadValues ( void )
{
   qDebug () << "PluginManager: Requesting plugins to auto-load configuration values.";
   
   // Iterate over the plugins and ask them to create/load their config values.
   for ( int i = 0; i < plugins_loaded->size (); i++ )
   {
      plugins_loaded->operator[] ( i )->loadOptions ();
   }
   
   return;
}

void Base::PluginManager::saveValues ( void )
{
   qDebug () << "PluginManager: Requesting plugins to auto-save configuration values.";
   
   // Iterate over the plugins and ask them to create/save their config values.
   for ( int i = 0; i < plugins_loaded->size (); i++ )
   {
      plugins_loaded->operator[] ( i )->saveOptions ();
   }
   
   return;
}

void Base::PluginManager::resetValues ( void )
{
   qDebug () << "PluginManager: Requesting plugins to auto-reset configuration values.";
   
   // Iterate over the plugins and ask them to create/save their config values.
   for ( int i = 0; i < plugins_loaded->size (); i++ )
   {
      plugins_loaded->operator[] ( i )->resetOptions ();
   }
   
   return;
}

Base::PluginManager::LoadState Base::PluginManager::load ( QStringList folder_paths )
{  
   // Iterate over the list of paths where might be plugins
   for ( int i = 0; i < folder_paths.size (); i++ )
   {
      qDebug () << "PluginManager: Looking for plugins on folder " << folder_paths[ i ];
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
            QFile plugin_file ( folder_paths[ i ] + ( ( folder_paths[ i ].endsWith ( QDir::separator () ) ) ? QString ( "" ) : QDir::separator () ) + files[ j ] );
            
            // Try to open the file
            if ( plugin_file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
            {
               // Validate the plugin file (there is possible to be any other kind of file rather than a plugin)
               /*PLUGIN VALIDATION*/
               
               // Create new plugin
               QString new_save_path = folder_paths[ i ] + ( ( folder_paths[ i ].endsWith ( QDir::separator () ) ) ? QString ( "" ) : QDir::separator () ) + files[ j ];
               
               new_save_path.replace ( new_save_path.size () - 3 , 3 , "cfg" );
               
               new_plugin = new Base::Plugin ();
               new_plugin->setSavePath ( new_save_path );
               
               // Load the plugin
               plugin_file >> (*new_plugin);
               
               // Store the plugin if it has options to offer
               if ( ( new_plugin->audioOptions ()->size () > 0 ) ||
                    ( new_plugin->controlsOptions ()->size () > 0 ) ||
                    ( new_plugin->videoOptions ()->size () > 0 ) ||
                    ( new_plugin->inGameOptions ()->size () > 0 )
                  )
               {
                  // The plugin is not empty... is supported?
                  if ( new_plugin->isSupported ( shared_configuration->operator[] ( Base::KeyCfgCoreRunVersion ) ) )
                  {
                     plugins_loaded->append ( new_plugin );
                  }
                  else
                  {
                     qDebug () << "PluginManager: Can't use plugin.";
                     qDebug () << "               File: " << plugin_file.fileName ();
                     qDebug () << "               Running version: " << shared_configuration->operator[] ( Base::KeyCfgCoreRunVersion );
                     qDebug () << "               Plugin supported versions: " << new_plugin->info ()->supportedVersions ();
                     
                     delete new_plugin;
                  }
               }
               else
               {
                  delete new_plugin;
               }
            }
            else
            {
               qDebug () << "PluginManager: Error: Can't open plugin file " << files[ j ] << " from " << folder_paths[ i ];
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

QStringList Base::PluginManager::getOptions ( const QString& file_extention )
{
   qDebug () << "PluginManager: Requesting plugins options for file extention " << file_extention;
   QStringList options;
   
   for ( int i = 0; i < plugins_loaded->size (); i++ )
   {
      if ( plugins_loaded->operator[] ( i )->info()->hasExtention ( file_extention ) )
      {
         options << plugins_loaded->operator[] ( i )->getOptions ();
      }
   }
   
   return ( options );
}

QString Base::PluginManager::detectType ( const QString& file_extention )
{
   QString console_type = "auto";
   
   qDebug () << "PluginManager: Requesting plugins options for console type of " << file_extention;
   
   for ( int i = 0; i < plugins_loaded->size () && console_type == "auto"; i++ )
   {
      if ( plugins_loaded->operator[] ( i )->info()->hasExtention ( file_extention ) &&
           plugins_loaded->operator[] ( i )->info()->console ().toLower () != "common"
         )
      {
         console_type = plugins_loaded->operator[] ( i )->info()->console ().toLower ();
      }
   }
   
   return ( console_type );
}

QStringList Base::PluginManager::getValidExtentions ( void )
{
   QStringList valid_extentions;
   
   for ( int i = 0; i < plugins_loaded->size (); i++ )
   {
      valid_extentions << plugins_loaded->operator[] ( i )->info ()->extentions ();
   }
   
   return ( valid_extentions );
}
