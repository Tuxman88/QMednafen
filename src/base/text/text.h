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

# ifndef TEXT_H_
# define TEXT_H_

# include <QtCore/QObject>
# include <QtCore/QMap>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QStringList>
# include <QtCore/QDebug>

# include "../configuration/configuration.h"
# include "../keys.h"

namespace Base
{
   class Text : public QObject
   {
      Q_OBJECT
      
      public:
         explicit Text ( Base::Configuration* new_config );
         virtual ~Text ( void );
         
         QString operator[] ( const QString& key );
         
      signals:
         void updateText ( void );
         
      private:
         void fillDefault ( void );
         Base::Configuration* config;
         QMap< QString , QString > current_text;
   };
}

# endif
