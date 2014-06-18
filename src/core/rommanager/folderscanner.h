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

# ifndef FOLDERSCANNER_H_
# define FOLDERSCANNER_H_

# include <QtCore/QObject>
# include <QtCore/QRunnable>
# include <QtCore/QStringList>
# include <QtCore/QDir>
# include <QtCore/QDebug>

namespace Core
{
   class FolderScanner : public QObject , public QRunnable
   {
      Q_OBJECT
      
      public:
         explicit FolderScanner ( const QStringList& new_folders_to_scan , const QStringList& new_supported_extentions );
         
         void run ();
         void scanFolder ( const QString& path_to_scan );
         
      signals:
         void scanningFolder ( const QString& folder_name );
         void gameFound ( const QString& file_name );
         
      private:
         QStringList folders_to_scan;
         QStringList supported_extentions;
   };
}

# endif
