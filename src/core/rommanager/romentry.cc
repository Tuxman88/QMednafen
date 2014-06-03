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

# include "romentry.h"

Core::RomEntry::RomEntry ( void )
   : QObject ()
{
}

Core::RomEntry::~RomEntry ( void )
{
}

QString Core::RomEntry::console ( void )
{
   return ( rom_console );
}

QString Core::RomEntry::name ( void )
{
   return ( rom_name );
}

QString Core::RomEntry::path ( void )
{
   return ( rom_path );
}

void Core::RomEntry::setConsole ( QString new_console )
{
   rom_console = new_console;
   
   return;
}

void Core::RomEntry::setName ( QString new_name )
{
   rom_name = new_name;
   
   return;
}

void Core::RomEntry::setPath ( QString new_path )
{
   rom_path = new_path;
   
   return;
}
