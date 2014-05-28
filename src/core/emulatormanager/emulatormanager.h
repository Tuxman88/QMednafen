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

# ifndef EMULATORMANAGER_H_
# define EMULATORMANAGER_H_

# include <QtCore/QObject>
# include <QtCore/QDebug>
# include <QtCore/QStringList>
# include <QtCore/QMapIterator>

# include "../../base/base.h"
# include "emulatorinstance.h"

namespace Core
{
   class EmulatorManager : public QObject
   {
      Q_OBJECT
      
      public:
         enum DetectionType
         {
            Auto = 0 ,
            Lynx ,
            GB ,
            GBA ,
            NeoGeoPocket ,
            NES ,
            PCE ,
            PCE_FAST ,
            PCFX ,
            GG ,
            MD ,
            SMS ,
            PSX ,
            SNES ,
            VB ,
            WSWAN
         };
      
      public:
         explicit EmulatorManager ( Base::SharedComponents* new_shared_components );
         virtual ~EmulatorManager ( void );
         
         void addInstance ( const QString& file_path , const DetectionType& file_type , const QStringList& options );
         
      private slots:
         void closeEmulatorInstance ( Core::EmulatorInstance* instance );
         
      private:
         QString detectionTypeString ( const DetectionType& file_type );
         
      private:
         Base::SharedComponents* shared_components;
         QMap< Core::EmulatorInstance* , Core::EmulatorInstance* > game_instances;
   };
}

# endif
