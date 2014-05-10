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

# include "configuration.h"

Base::Configuration::Configuration ( void )
   : QObject ()
{
   settings = new QSettings ( tr ( "TuxmanSoft" ) , tr ( "QMednafen 0.1.0" ) );
   
   // Validate the information of the configuration. Check if all the needed keys exists.
   
   if ( !settings->contains ( Base::KeyCfgGuiLanguage ) )
      settings->setValue ( Base::KeyCfgGuiLanguage , Base::ValCfgGuiLanguage );
   
   if ( !settings->contains ( Base::KeyCfgGuiShortcutOpenRom ) )
      settings->setValue ( Base::KeyCfgGuiShortcutOpenRom , Base::ValCfgGuiShortcutOpenRom );
   
   if ( !settings->contains ( Base::KeyCfgGuiShortcutOpenGameDisc ) )
      settings->setValue ( Base::KeyCfgGuiShortcutOpenGameDisc , Base::ValCfgGuiShortcutOpenGameDisc );
   
   if ( !settings->contains ( Base::KeyCfgGuiShortcutLibrary ) )
      settings->setValue ( Base::KeyCfgGuiShortcutLibrary , Base::ValCfgGuiShortcutLibrary );
   
   if ( !settings->contains ( Base::KeyCfgGuiShortcutExit ) )
      settings->setValue ( Base::KeyCfgGuiShortcutExit , Base::ValCfgGuiShortcutExit );
   
   if ( !settings->contains ( Base::KeyCfgGuiShortcutConfig ) )
      settings->setValue ( Base::KeyCfgGuiShortcutConfig , Base::ValCfgGuiShortcutConfig );
   
   if ( !settings->contains ( Base::KeyCfgGuiShortcutAbout ) )
      settings->setValue ( Base::KeyCfgGuiShortcutAbout , Base::ValCfgGuiShortcutAbout );
   
   if ( !settings->contains ( Base::KeyCfgCorePathsPlugins ) )
      settings->setValue ( Base::KeyCfgCorePathsPlugins , Base::ValCfgCorePathsPlugins );
   
   if ( !settings->contains ( Base::KeyCfgCorePathsMednafen ) )
      settings->setValue ( Base::KeyCfgCorePathsMednafen , Base::ValCfgCorePathsMednafen );
   
   settings->sync ();
}

Base::Configuration::~Configuration ( void )
{
   delete settings;
}

void Base::Configuration::resetValues ( void )
{
   settings->setValue ( Base::KeyCfgGuiLanguage , Base::ValCfgGuiLanguage );
   settings->setValue ( Base::KeyCfgGuiShortcutOpenRom , Base::ValCfgGuiShortcutOpenRom );
   settings->setValue ( Base::KeyCfgGuiShortcutOpenGameDisc , Base::ValCfgGuiShortcutOpenGameDisc );
   settings->setValue ( Base::KeyCfgGuiShortcutLibrary , Base::ValCfgGuiShortcutLibrary );
   settings->setValue ( Base::KeyCfgGuiShortcutExit , Base::ValCfgGuiShortcutExit );
   settings->setValue ( Base::KeyCfgGuiShortcutConfig , Base::ValCfgGuiShortcutConfig );
   settings->setValue ( Base::KeyCfgGuiShortcutAbout , Base::ValCfgGuiShortcutAbout );
   settings->setValue ( Base::KeyCfgCorePathsPlugins , Base::ValCfgCorePathsPlugins );
   settings->setValue ( Base::KeyCfgCorePathsMednafen , Base::ValCfgCorePathsMednafen );
   
   emit updateValues ();
   
   return;
}

void Base::Configuration::set ( const QString& key , const QString& value )
{
   settings->setValue ( key , value );
   
   return;
}

QString Base::Configuration::operator[] ( const QString& key )
{
   return ( settings->value ( key ).toString () );
} 
