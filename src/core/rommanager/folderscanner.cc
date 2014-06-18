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

# include "folderscanner.h"

Core::FolderScanner::FolderScanner ( const QStringList& new_folders_to_scan , const QStringList& new_supported_extentions )
{
   folders_to_scan = new_folders_to_scan;
   supported_extentions = new_supported_extentions;
}

void Core::FolderScanner::run ()
{
   qDebug () << "FolderScanner: Starting scanning process of folders for games.";
   
   for ( int i = 0; i < folders_to_scan.size (); i++ )
   {
      if ( folders_to_scan[ i ] != "/" )
      {
         scanFolder ( folders_to_scan[ i ] );
      }
   }
   
   return;
}

void Core::FolderScanner::scanFolder ( const QString& path_to_scan )
{
   qDebug () << "FolderScanner: Scanning " << path_to_scan;
   
   emit scanningFolder ( path_to_scan );
   
   return;
}
