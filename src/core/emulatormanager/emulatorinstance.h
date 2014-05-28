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

# ifndef EMULATORINSTANCE_H_
# define EMULATORINSTANCE_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QStringList>
# include <QtCore/QProcess>
# include <cstdlib>

# include "../../base/base.h"

namespace Core
{
   class EmulatorInstance : public QObject
   {
      Q_OBJECT
                  
      public:
         explicit EmulatorInstance ( Base::SharedComponents* new_shared_components );
         virtual ~EmulatorInstance ( void );
         
         void setGame ( const QString& new_file_name , const QStringList& new_game_options , const int& new_game_type );
         void run ( void );
         
      signals:
         void closeEmulatorInstance ( Core::EmulatorInstance* pointer );
         
      private slots:
         void commandError ( void );
         void commandFinished ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QString file_path;
         QStringList game_options;
         int game_type;
         QProcess emulator_process;
         bool stop_signals;
   };
}

# endif
