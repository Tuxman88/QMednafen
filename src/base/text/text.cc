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

# include "text.h"

Base::Text::Text ( Base::Configuration* new_config )
   : QObject ()
{
   config = new_config;
   
   // Open and load the resource file of the text for the application
   QFile resource_file ( QString ( ":/lang-%1" ).arg ( config->operator[] ( Base::KeyCfgGuiLanguage ) ) );
   
   if ( !resource_file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      qDebug () << "Base::Text::Text: ERROR: Can't open resource file " << QString ( ":/lang-%1" ).arg ( config->operator[] ( Base::KeyCfgGuiLanguage ) );
      qDebug () << "                         Fallback to default english.";
      
      fillDefault ();
   }
   else
   {
      while ( !resource_file.atEnd () )
      {
         QByteArray raw_line = resource_file.readLine ();
         QString line ( raw_line );
         QStringList components;
         
         components = line.split ( "=" );
         current_text[ components[ 0 ] ] = components[ 1 ].simplified ();
      }
   }
}

Base::Text::~Text ( void )
{
}

void Base::Text::fillDefault ( void )
{
   current_text[ QString ( "txt.program.name" ) ] = QString ( "QMednafen" );
   current_text[ QString ( "txt.program.version" ) ] = QString ( "0.1.0" );
   current_text[ QString ( "txt.gui.menu.file" ) ] = QString ( "File" );
   current_text[ QString ( "txt.gui.menu.file.openrom" ) ] = QString ( "Open ROM" );
   current_text[ QString ( "txt.gui.menu.file.opengamedisc" ) ] = QString ( "Open game disc" );
   current_text[ QString ( "txt.gui.menu.file.library" ) ] = QString ( "Games library" );
   current_text[ QString ( "txt.gui.menu.file.exit" ) ] = QString ( "Exit" );
   current_text[ QString ( "txt.gui.menu.config" ) ] = QString ( "Options" );
   current_text[ QString ( "txt.gui.menu.config.config" ) ] = QString ( "Config" );
   current_text[ QString ( "txt.gui.menu.help" ) ] = QString ( "Help" );
   current_text[ QString ( "txt.gui.menu.help.about" ) ] = QString ( "About" );
   current_text[ QString ( "txt.gui.main.version" ) ] = QString ( "Version" );
   current_text[ QString ( "txt.gui.main.description" ) ] = QString ( "A Qt GUI for Mednafen" );
   current_text[ QString ( "txt.gui.main.groupname" ) ] = QString ( "Main options" );
   current_text[ QString ( "txt.gui.main.openrom" ) ] = QString ( "Open ROM" );
   current_text[ QString ( "txt.gui.main.opengamedisc" ) ] = QString ( "Open game disc" );
   current_text[ QString ( "txt.gui.main.config" ) ] = QString ( "Config" );
   current_text[ QString ( "txt.gui.main.openromdescription" ) ] = QString ( "Select a ROM file to emulate" );
   current_text[ QString ( "txt.gui.main.opengamediscdescription" ) ] = QString ( "Open real or backup game disc" );
   current_text[ QString ( "txt.gui.main.configdescription" ) ] = QString ( "Configure QMefnafen" );
   current_text[ QString ( "txt.gui.main.about" ) ] = QString ( "About" );
   current_text[ QString ( "txt.gui.main.exit" ) ] = QString ( "Exit" );
   current_text[ QString ( "txt.gui.main.library" ) ] = QString ( "Library" );
   current_text[ QString ( "txt.gui.main.librarydescription" ) ] = QString ( "Games library" );
   current_text[ QString ( "txt.gui.config.systemconfig" ) ] = QString ( "&System" );
   current_text[ QString ( "txt.gui.config.videooptions" ) ] = QString ( "&Video options" );
   current_text[ QString ( "txt.gui.config.audiooptions" ) ] = QString ( "&Audio options" );
   current_text[ QString ( "txt.gui.config.controloptions" ) ] = QString ( "&Control options" );
   current_text[ QString ( "txt.gui.about.abouttitle" ) ] = QString ( "About" );
   current_text[ QString ( "txt.gui.about.abouttab" ) ] = QString ( "&About" );
   current_text[ QString ( "txt.gui.about.creditstab" ) ] = QString ( "C&redits" );
   current_text[ QString ( "txt.gui.about.licensetab" ) ] = QString ( "&License" );
   current_text[ QString ( "txt.gui.about.close" ) ] = QString ( "&Close" );
   current_text[ QString ( "txt.gui.about.programdescription" ) ] = QString ( "This program is an open-source project.\\nIt is intented to provide an easy-to-use\\ngraphical interface for the multi-platform\\nemulator Mednafen.\\n\\nThis software was programmed using Qt 5.2.1." );
   current_text[ QString ( "txt.gui.about.alexander.name" ) ] = QString ( "Alexander Gee" );
   current_text[ QString ( "txt.gui.about.alexander.link" ) ] = QString ( "https://plus.google.com/+AlexanderGee" );
   current_text[ QString ( "txt.gui.about.alexander.thanks" ) ] = QString ( "Author of the original Bandai WonderSwan image." );
   current_text[ QString ( "txt.gui.about.doctorg.name" ) ] = QString ( "Doctor-G" );
   current_text[ QString ( "txt.gui.about.doctorg.link" ) ] = QString ( "http://doctor-g.deviantart.com" );
   current_text[ QString ( "txt.gui.about.doctorg.thanks" ) ] = QString ( "Author of the original Sega Genesis image." );
   current_text[ QString ( "txt.gui.about.blueamnesiac.name" ) ] = QString ( "BLUEamnesiac" );
   current_text[ QString ( "txt.gui.about.blueamnesiac.link" ) ] = QString ( "blueamnesiac.deviantart.com" );
   current_text[ QString ( "txt.gui.about.blueamnesiac.thanks" ) ] = QString ( "Author of the original Sega Game Gear, Sega Master System, Nintendo Game Boy, Nintendo Game Boy Advance, SNK Neo Geo Pocket and Atari Lynx images." );
   
   return;
}

QString Base::Text::operator[] ( const QString& key )
{
   return ( current_text[ key ] );
}