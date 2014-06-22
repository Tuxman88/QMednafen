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

# ifndef ROMMANAGER_H_
# define ROMMANAGER_H_

# include <QtCore/QObject>
# include <QtCore/QMap>
# include <QtCore/QList>
# include <QtCore/QThreadPool>
# include <QtCore/QMutex>

# include "../../base/base.h"
# include "romentry.h"
# include "folderscanner.h"

namespace Core
{
   class RomManager : public QObject
   {
      Q_OBJECT
      
      public:
         explicit RomManager ( Base::SharedComponents* new_shared_components );
         virtual ~RomManager ( void );
         
         QList< QString >& consoleList ( void );
         QMap< QString , QList< RomEntry* > >& entryMap ( void );
         
      signals:
         void scanningFolder ( const QString& folder_name );
         void updateList ( void );
         void localCancelCall ( void );
         
      public slots:
         void scanFolders ( void );
         void cancelScanProcess ( void );
         
      private slots:
         void gameFound ( const QString& file_name );
         void scanComplete ( void );
         
      private:
         void tryCreateLibrary ( void );
         void loadLibrary ( void );
         void saveLibrary ( void );
         void removeAllGames ( void );
         QString extractExtention ( const QString& file_path );
         QString extractName ( QString file_path );
         
      private:
         Base::SharedComponents* shared_components;
         QString library_path;
         QStringList scan_paths;
         QList< QString > console_list;
         QMap< QString , QList< RomEntry* > > entry_map;
         bool scanning;
         QMutex mutex;
   };
}

# endif
