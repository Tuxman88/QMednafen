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

# include "kernel.h"

Core::Kernel::Kernel ( Base::SharedComponents* new_shared_components ) :
   QObject ()
{
   shared_components = new_shared_components;
}

Core::Kernel::~Kernel ( void )
{
}

void Core::Kernel::about ( void )
{
   qDebug () << "Kernel: Displaying About dialog";
   
   return;
}

void Core::Kernel::config ( void )
{
   qDebug () << "Kernel: Displaying Config dialog";
   emit openConfigWindow ();
   
   return;
}

void Core::Kernel::exitNow ( void )
{
   qDebug () << "Kernel: Closing program now";
   emit closeMainWindow ();
   
   return;
}

void Core::Kernel::library ( void )
{
   qDebug () << "Kernel: Displaying Library dialog";
   
   return;
}

void Core::Kernel::openGameDisc ( void )
{
   qDebug () << "Kernel: Opening game disc";
   
   return;
}

void Core::Kernel::openRom ( void )
{
   qDebug () << "Kernel: Opening ROM";
   
   return;
}
