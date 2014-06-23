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
   plugin_audio_options = new QList< Base::PluginSection* > ();
   plugin_video_options = new QList< Base::PluginSection* > ();
   plugin_controls_options = new QList< Base::PluginSection* > ();
   plugin_ingame_options = new QList< Base::PluginSection* > ();
}

Base::Plugin::~Plugin ( void )
{
   delete plugin_info;
      
   for ( int i = 0; i < plugin_audio_options->size (); i++ )
   {
      delete plugin_audio_options->operator[] ( i );
   }
   
   for ( int i = 0; i < plugin_video_options->size (); i++ )
   {
      delete plugin_video_options->operator[] ( i );
   }
   
   for ( int i = 0; i < plugin_controls_options->size (); i++ )
   {
      delete plugin_controls_options->operator[] ( i );
   }
   
   for ( int i = 0; i < plugin_ingame_options->size (); i++ )
   {
      delete plugin_ingame_options->operator[] ( i );
   }
   
   plugin_audio_options->clear ();
   plugin_video_options->clear ();
   plugin_controls_options->clear ();
   plugin_ingame_options->clear ();
   
   delete plugin_audio_options;
   delete plugin_video_options;
   delete plugin_controls_options;
   delete plugin_ingame_options;
}

bool Base::Plugin::isSupported ( const QString& running_version )
{
   if ( running_version == "any" )
   {
      return ( true );
   }
   
   if ( plugin_info->supportedVersions ().contains ( "any" ) )
   {
      return ( true );
   }
   
   return ( plugin_info->supportedVersions ().contains ( running_version ) );
}

QStringList Base::Plugin::getOptions ( void )
{
   QStringList options;
   
   for ( int i = 0; i < plugin_audio_options->size (); i++ )
   {
      options << plugin_audio_options->operator[] ( i )->getOptions ();
   }
   
   for ( int i = 0; i < plugin_video_options->size (); i++ )
   {
      options << plugin_video_options->operator[] ( i )->getOptions ();;
   }
   
   for ( int i = 0; i < plugin_controls_options->size (); i++ )
   {
      options << plugin_controls_options->operator[] ( i )->getOptions ();;
   }
   
   for ( int i = 0; i < plugin_ingame_options->size (); i++ )
   {
      options << plugin_ingame_options->operator[] ( i )->getOptions ();;
   }
   
   return ( options );
}

void Base::Plugin::loadOptions ( void )
{
   // Test if the file that should store the configurations already exists.
   // If it exists, open and load. If doesn't exists, call the save member function,
   // so a new config file will be created.
      
   qDebug () << "Plugin: Loading options from " << save_path;
   
   QFile file ( save_path );
   
   if ( !file.exists () )
   {
      qDebug () << "Plugin: Options not found, creating.";
      saveOptions ();
   }
   else
   {
      // The whole contents of the file are pairs like this:
      // KEY=VALUE
      // So, read all of them, store the keys and values in a QMap, and
      // send such options to the sections to auto-load
      QMap< QString , QString > values;
      
      if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
      {
         qDebug () << "Plugin: Warning: Can't open config file " << save_path;
         
         return;
      }
      
      while ( !file.atEnd () )
      {
         QString line;
         line = file.readLine ().simplified ();
         
         if ( line != "" )
         {
            QStringList key_value;
            
            key_value = line.split ( "=" );
            values[ key_value[ 0 ] ] = key_value[ 1 ];
         }
      }
      
      // Iterate over all the sections and send them the info loaded for autoload
      // Important: This is done using an overloaded operator, QMap doesn't have operators by itself
      
      for ( int i = 0; i < plugin_video_options->size (); i++ )
      {
         plugin_video_options->operator[] ( i )->autoLoad ( values );
      }
      
      for ( int i = 0; i < plugin_audio_options->size (); i++ )
      {
         plugin_audio_options->operator[] ( i )->autoLoad ( values );
      }
      
      for ( int i = 0; i < plugin_controls_options->size (); i++ )
      {
         plugin_controls_options->operator[] ( i )->autoLoad ( values );
      }
      
      for ( int i = 0; i < plugin_ingame_options->size (); i++ )
      {
         plugin_ingame_options->operator[] ( i )->autoLoad ( values );
      }
      
   }
   
   return;
}

void Base::Plugin::saveOptions ( void )
{
   // Try to open the file in write-mode and try to save all the configurations.
   qDebug () << "Plugin: Saving options to " << save_path;
   QFile file ( save_path );
   
   if ( !file.open ( QIODevice::WriteOnly | QIODevice::Text ) )
   {
      qDebug () << "Plugin: Warning: Can't open config file " << save_path;
      return;
   }
   
   QTextStream output_file ( &file );
   
   for ( int i = 0; i < plugin_video_options->size (); i++ )
   {
      output_file << plugin_video_options->operator[] ( i );
   }
   
   for ( int i = 0; i < plugin_audio_options->size (); i++ )
   {
      output_file << plugin_audio_options->operator[] ( i );
   }
   
   for ( int i = 0; i < plugin_controls_options->size (); i++ )
   {
      output_file << plugin_controls_options->operator[] ( i );
   }
   
   for ( int i = 0; i < plugin_ingame_options->size (); i++ )
   {
      output_file << plugin_ingame_options->operator[] ( i );
   }
   
   return;
}

void Base::Plugin::resetOptions ( void )
{
   for ( int i = 0; i < plugin_video_options->size (); i++ )
   {
      plugin_video_options->operator[] ( i )->resetValues ();
   }
   
   for ( int i = 0; i < plugin_audio_options->size (); i++ )
   {
      plugin_audio_options->operator[] ( i )->resetValues ();
   }
   
   for ( int i = 0; i < plugin_controls_options->size (); i++ )
   {
      plugin_controls_options->operator[] ( i )->resetValues ();
   }
   
   for ( int i = 0; i < plugin_ingame_options->size (); i++ )
   {
      plugin_ingame_options->operator[] ( i )->resetValues ();
   }
   
   return;
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

QList< Base::PluginSection* >* Base::Plugin::audioOptions ( void )
{
   return ( plugin_audio_options );
}

QList< Base::PluginSection* >* Base::Plugin::controlsOptions ( void )
{
   return ( plugin_controls_options );
}

QList< Base::PluginSection* >* Base::Plugin::videoOptions ( void )
{
   return ( plugin_video_options );
}

QList< Base::PluginSection* >* Base::Plugin::inGameOptions ( void )
{
   return ( plugin_ingame_options );
}

QFile& operator>> ( QFile& input_file , Base::Plugin& plugin )
{
   QString line;
   
   // While there is no found the EOF signal
   qDebug () << "Plugin: Loading " << input_file.fileName ();
   
   while ( line != "[EOF]" && !input_file.atEnd () )
   {
      // Read a line and clean it
      line = input_file.readLine ();
      line = line.simplified ();
      line = line.toUpper ();
      
      // If is not the EOF and is not an empty string
      if ( line != "[EOF]" && line.size () > 0 )
      {
         // Is the INFO section of the plugin?
         if ( line == "[INFO]" )
         {
            qDebug () << "Plugin: Found  \"[INFO]\"  section.";
            input_file >> (*(plugin.plugin_info));
         }
         
         // Is the VIDEO section of the plugin?
         else 
         {
            QString section = line;
            qDebug () << "Plugin: Found " << line << " section.";
            
            // Read lines and discard them until a non-empty line is
            // found. Such line is the name of the section
            line = input_file.readLine ();
            line = line.simplified ();
            
            while ( line == "" )
            {
               line = input_file.readLine ();
               line = line.simplified ();
            }
            
            // Read the section info until and the next non-empty line.
            // Do that until reaching the [/] signal that denote the end of the block
            while ( line != "[/]" )
            {
               // At this moment I already have the name of the section,
               // just create a new section instance and load it.
               Base::PluginSection* new_section;
               
               new_section = new Base::PluginSection ();
               new_section->setName ( line );
               
               input_file >> (*new_section);
               
               // Store in the needed section
               if ( section == "[VIDEO]" )
                  plugin.plugin_video_options->append ( new_section );
               else if ( section == "[AUDIO]" )
                  plugin.plugin_audio_options->append ( new_section );
               else if ( section == "[CONTROLS]" )
                  plugin.plugin_controls_options->append ( new_section );
               else if ( section == "[INGAME]" )
                  plugin.plugin_ingame_options->append ( new_section );
               
               // Find the next non-empty line, that is the name of the next section or
               // the [/] signal.
               line = input_file.readLine ();
               line = line.simplified ();
               
               while ( line == "" )
               {
                  line = input_file.readLine ();
                  line = line.simplified ();
               }
            }
         }
      }
   }
   
   return ( input_file );
}
