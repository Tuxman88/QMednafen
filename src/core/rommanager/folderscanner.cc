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
   
   for ( int i = 0; i < new_supported_extentions.size (); i++ )
   {
      supported_extentions << QString ( "*.%1" ).arg ( new_supported_extentions[ i ] );
   }
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
   
   emit scanComplete ();
   
   return;
}

void Core::FolderScanner::scanFolder ( const QString& path_to_scan )
{   
   QString path;
   path = path_to_scan;
   
   if ( !path.endsWith ( QDir::separator () ) )
   {
      path += QDir::separator ();
   }
   
   qDebug () << "FolderScanner: Scanning " << path;
 
   emit scanningFolder ( path );
   
   QDir dir ( path );
   
   // First, get folders
   QStringList folders_to_scan;
   
   // Get All the folders of this path and sort them by name
   folders_to_scan = dir.entryList ( supported_extentions , QDir::AllDirs , QDir::Name );
   
   // Now, get All the files of this path that match the filters and sort them by name
   QStringList files_found;
   files_found = dir.entryList ( supported_extentions , QDir::Files , QDir::Name );
   
   for ( int i = 0; i < files_found.size (); i++ )
   {
      qDebug () << "FolderScanner: Found: " << files_found[ i ];
      emit gameFound ( path + files_found[ i ] );
   }
   
   // Now, scan the sub-folders
   for ( int i = 0; i < folders_to_scan.size (); i++ )
   {
      if ( folders_to_scan[ i ] != "." &&
           folders_to_scan[ i ] != ".."
         )
      {
         scanFolder ( path + folders_to_scan[ i ] );
      }
   }
   
   return;
}
