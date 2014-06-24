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
   connect ( config , SIGNAL ( updateValues () ) , this , SLOT ( reloadText () ) );
   
   reloadText ();
}

Base::Text::~Text ( void )
{
}

void Base::Text::reloadText ( void )
{
   // Open and load the resource file of the text for the application
   QFile resource_file ( QString ( ":/lang-%1" ).arg ( config->operator[] ( Base::KeyCfgGuiLanguage ) ) );
   
   if ( !resource_file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      qDebug () << "Text: ERROR: Can't open resource file " << QString ( ":/lang-%1" ).arg ( config->operator[] ( Base::KeyCfgGuiLanguage ) );
      qDebug () << "      Fallback to default english.";
      
      fillDefault ();
   }
   else
   {
      while ( !resource_file.atEnd () )
      {
         QByteArray raw_line = resource_file.readLine ();
         
         if ( raw_line.size () > 10 )
         {
            QString line ( raw_line );
            QStringList components;
            
            components = line.split ( "=" );
            if ( components.size () == 2 )
            {
               current_text[ components[ 0 ] ] = components[ 1 ].simplified ();
            }
         }
      }
   }
   
   emit updateText ();
   
   return;
}

void Base::Text::fillDefault ( void )
{
   current_text[ QString ( "txt.program.name" ) ]    = QString ( "QMednafen" );
   current_text[ QString ( "txt.program.version" ) ] = QString ( "0.1.0" );
   
   current_text[ QString ( "txt.gui.menu.file" ) ]                  = QString ( "File" );
   current_text[ QString ( "txt.gui.menu.file.openrom" ) ]          = QString ( "Open ROM" );
   current_text[ QString ( "txt.gui.menu.file.opengamedisc" ) ]     = QString ( "Open game disc" );
   current_text[ QString ( "txt.gui.menu.file.exit" ) ]             = QString ( "Exit" );
   current_text[ QString ( "txt.gui.menu.config" ) ]                = QString ( "Options" );
   current_text[ QString ( "txt.gui.menu.config.config" ) ]         = QString ( "Config" );
   current_text[ QString ( "txt.gui.menu.tools" ) ]                 = QString ( "Tools" );
   current_text[ QString ( "txt.gui.menu.tools.instancemanager" ) ] = QString ( "Running games" );
   current_text[ QString ( "txt.gui.menu.tools.library" ) ]         = QString ( "Games library" );
   current_text[ QString ( "txt.gui.menu.help" ) ]                  = QString ( "Help" );
   current_text[ QString ( "txt.gui.menu.help.about" ) ]            = QString ( "Manual" );
   current_text[ QString ( "txt.gui.menu.help.about" ) ]            = QString ( "About" );
   
   current_text[ QString ( "txt.gui.main.version" ) ]                 = QString ( "Version" );
   current_text[ QString ( "txt.gui.main.description" ) ]             = QString ( "A Qt GUI for Mednafen" );
   current_text[ QString ( "txt.gui.main.groupname" ) ]               = QString ( "Main options" );
   current_text[ QString ( "txt.gui.main.openrom" ) ]                 = QString ( "Open ROM" );
   current_text[ QString ( "txt.gui.main.opengamedisc" ) ]            = QString ( "Open game disc" );
   current_text[ QString ( "txt.gui.main.config" ) ]                  = QString ( "Config" );
   current_text[ QString ( "txt.gui.main.openromdescription" ) ]      = QString ( "Select a ROM file to emulate" );
   current_text[ QString ( "txt.gui.main.opengamediscdescription" ) ] = QString ( "Open real or backup game disc" );
   current_text[ QString ( "txt.gui.main.configdescription" ) ]       = QString ( "Configure QMefnafen" );
   current_text[ QString ( "txt.gui.main.about" ) ]                   = QString ( "About" );
   current_text[ QString ( "txt.gui.main.exit" ) ]                    = QString ( "Exit" );
   current_text[ QString ( "txt.gui.main.library" ) ]                 = QString ( "Library" );
   current_text[ QString ( "txt.gui.main.librarydescription" ) ]      = QString ( "Games library" );
   
   current_text[ QString ( "txt.gui.openrom.selectfile" ) ] = QString ( "Select the ROM file to use" );
   
   current_text[ QString ( "txt.gui.about.abouttitle" ) ]          = QString ( "About" );
   current_text[ QString ( "txt.gui.about.abouttab" ) ]            = QString ( "&About" );
   current_text[ QString ( "txt.gui.about.creditstab" ) ]          = QString ( "C&redits" );
   current_text[ QString ( "txt.gui.about.licensetab" ) ]          = QString ( "&License" );
   current_text[ QString ( "txt.gui.about.close" ) ]               = QString ( "&Close" );
   current_text[ QString ( "txt.gui.about.programdescription" ) ]  = QString ( "This program is an open-source project.\\nIt is intented to provide an easy-to-use\\ngraphical interface for the multi-platform\\nemulator Mednafen.\\n\\nThis software was programmed using Qt 5.2.1." );
   current_text[ QString ( "txt.gui.about.alexander.name" ) ]      = QString ( "Alexander Gee" );
   current_text[ QString ( "txt.gui.about.alexander.link" ) ]      = QString ( "https://plus.google.com/+AlexanderGee" );
   current_text[ QString ( "txt.gui.about.alexander.thanks" ) ]    = QString ( "Author of the original Bandai WonderSwan image." );
   current_text[ QString ( "txt.gui.about.doctorg.name" ) ]        = QString ( "Doctor-G" );
   current_text[ QString ( "txt.gui.about.doctorg.link" ) ]        = QString ( "http://doctor-g.deviantart.com" );
   current_text[ QString ( "txt.gui.about.doctorg.thanks" ) ]      = QString ( "Author of the original Sega Genesis image." );
   current_text[ QString ( "txt.gui.about.psychotic.name" ) ]      = QString ( "Psychotic-Carp" );
   current_text[ QString ( "txt.gui.about.psychotic.link" ) ]      = QString ( "http://psychotic-carp.deviantart.com" );
   current_text[ QString ( "txt.gui.about.psychotic.thanks" ) ]    = QString ( "Author of the original NEC PCE Engine/TurboGrafx 16/SuperGrafx image." );
   current_text[ QString ( "txt.gui.about.blueamnesiac.name" ) ]   = QString ( "BLUEamnesiac" );
   current_text[ QString ( "txt.gui.about.blueamnesiac.link" ) ]   = QString ( "blueamnesiac.deviantart.com" );
   current_text[ QString ( "txt.gui.about.blueamnesiac.thanks" ) ] = QString ( "Author of the original Sega Game Gear, Sega Master System, Nintendo Game Boy, Nintendo Game Boy Advance, SNK Neo Geo Pocket and Atari Lynx images." );
   
   current_text[ QString ( "txt.gui.config.systemconfig" ) ]                              = QString ( "&System" );
   current_text[ QString ( "txt.gui.config.systemconfig.language" ) ]                     = QString ( "Language options" );
   current_text[ QString ( "txt.gui.config.systemconfig.selectlanguage" ) ]               = QString ( "Select language" );
   current_text[ QString ( "txt.gui.config.systemconfig.mednafengroup" ) ]                = QString ( "Mednafen options" );
   current_text[ QString ( "txt.gui.config.systemconfig.commandformat" ) ]                = QString ( "Command format" );
   current_text[ QString ( "txt.gui.config.systemconfig.runningversion" ) ]               = QString ( "Mednafen version" );
   current_text[ QString ( "txt.gui.config.systemconfig.pathsgroup" ) ]                   = QString ( "System paths" );
   current_text[ QString ( "txt.gui.config.systemconfig.binarypath" ) ]                   = QString ( "Mednafen binary path" );
   current_text[ QString ( "txt.gui.config.systemconfig.librarypaths" ) ]                 = QString ( "Paths for library (separated by colons)" );
   current_text[ QString ( "txt.gui.config.systemconfig.pluginspaths" ) ]                 = QString ( "Paths for plugins (separated by colons)" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcutsgroup" ) ]               = QString ( "Shortcuts" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.openrom" ) ]             = QString ( "Open ROM file" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.openabout" ) ]           = QString ( "Open about window" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.openinstancemanager" ) ] = QString ( "Open instance manager window" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.opendisc" ) ]            = QString ( "Open game from disc" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.openlibrary" ) ]         = QString ( "Open library window" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.openmanual" ) ]          = QString ( "Open manual window" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.exit" ) ]                = QString ( "Exit program" );
   current_text[ QString ( "txt.gui.config.systemconfig.shortcut.openconfig" ) ]          = QString ( "Open config window" );
   current_text[ QString ( "txt.gui.config.videooptions" ) ]                              = QString ( "&Video options" );
   current_text[ QString ( "txt.gui.config.audiooptions" ) ]                              = QString ( "&Audio options" );
   current_text[ QString ( "txt.gui.config.controloptions" ) ]                            = QString ( "&Control options" );
   current_text[ QString ( "txt.gui.config.ingameoptions" ) ]                             = QString ( "&In-Game options" );
   current_text[ QString ( "txt.gui.config.title" ) ]                                     = QString ( "Configuration" );
   current_text[ QString ( "txt.gui.config.console.lynx" ) ]                              = QString ( "Atari Lynx" );
   current_text[ QString ( "txt.gui.config.console.gb" ) ]                                = QString ( "Nintendo Game Boy (GB/GBC)" );
   current_text[ QString ( "txt.gui.config.console.gba" ) ]                               = QString ( "Nintendo Game Boy Advance (GBA)" );
   current_text[ QString ( "txt.gui.config.console.ngp" ) ]                               = QString ( "SNK Neo Geo Pocket (NGP)" );
   current_text[ QString ( "txt.gui.config.console.nes" ) ]                               = QString ( "Nintendo Entertainment System (NES)" );
   current_text[ QString ( "txt.gui.config.console.pce" ) ]                               = QString ( "NEC PC Engine/TurboGrafx 16/SuperGrafx (PCE)" );
   current_text[ QString ( "txt.gui.config.console.pce_fast" ) ]                          = QString ( "NEC PC Engine/TurboGrafx 16/SuperGrafx (PCE)" );
   current_text[ QString ( "txt.gui.config.console.pcfx" ) ]                              = QString ( "NEC PC-FX (PCFX)" );
   current_text[ QString ( "txt.gui.config.console.gg" ) ]                                = QString ( "Sega Game Gear (GG)" );
   current_text[ QString ( "txt.gui.config.console.md" ) ]                                = QString ( "Sega Genesis/Mega Drive (MD)" );
   current_text[ QString ( "txt.gui.config.console.sms" ) ]                               = QString ( "Sega Master System (SMS)" );
   current_text[ QString ( "txt.gui.config.console.psx" ) ]                               = QString ( "Sony PlayStation (PSX)" );
   current_text[ QString ( "txt.gui.config.console.snes" ) ]                              = QString ( "Super Nintendo Entertainment System (SNES)" );
   current_text[ QString ( "txt.gui.config.console.vb" ) ]                                = QString ( "Nintendo Virtual Boy (VB)" );
   current_text[ QString ( "txt.gui.config.console.wswan" ) ]                             = QString ( "Bandai WonderSwan (WSWAN)" );
   current_text[ QString ( "txt.gui.config.console.unknown" ) ]                           = QString ( "Unknown console (%1)" );
   current_text[ QString ( "txt.gui.config.console.common" ) ]                            = QString ( "All consoles (Common options)" );
   current_text[ QString ( "txt.gui.config.console.author" ) ]                            = QString ( "Author: %1" );
   current_text[ QString ( "txt.gui.config.console.pluginversion" ) ]                     = QString ( "Plugin version: %1" );
   current_text[ QString ( "txt.gui.config.save" ) ]                                      = QString ( "&Save" );
   current_text[ QString ( "txt.gui.config.reload" ) ]                                    = QString ( "&Reload" );
   current_text[ QString ( "txt.gui.config.reset" ) ]                                     = QString ( "Rese&t" );
   
   current_text[ QString ( "txt.gui.instancemanager.title" ) ]           = QString ( "Instance manager" );
   current_text[ QString ( "txt.gui.instancemanager.buttonclose" ) ]     = QString ( "&Close" );
   current_text[ QString ( "txt.gui.instancemanager.buttonclosegame" ) ] = QString ( "&Close" );
   
   current_text[ QString ( "txt.gui.scanningdialog.cancelscan" ) ] = QString ( "&Cancel" );
   current_text[ QString ( "txt.gui.scanningdialog.scanning" ) ]   = QString ( "Scanning" );
   current_text[ QString ( "txt.gui.scanningdialog.scanning" ) ]   = QString ( "Scanning for games" );
   
   current_text[ QString ( "txt.gui.librarymanager.scan" ) ]  = QString ( "&Scan" );
   current_text[ QString ( "txt.gui.librarymanager.close" ) ] = QString ( "&Close" );
   current_text[ QString ( "txt.gui.librarymanager.title" ) ] = QString ( "Library manager" );
   
   current_text[ QString ( "txt.gui.manual.close" ) ] = QString ( "&Close" );
   current_text[ QString ( "txt.gui.manual.title" ) ] = QString ( "Quick user manual" );
   
   return;
}

QString Base::Text::operator[] ( const QString& key )
{
   return ( current_text[ key ] );
}