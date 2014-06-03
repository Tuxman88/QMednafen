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

# ifndef ROMENTRY_H_
# define ROMENTRY_H_

# include <QtCore/QObject>
# include <QtCore/QString>

namespace Core
{
   class RomEntry : public QObject
   {
      Q_OBJECT
      
      public:
         explicit RomEntry ( void );
         virtual ~RomEntry ( void );
         
         QString path ( void );
         QString name ( void );
         QString console ( void );
         void setPath ( QString new_path );
         void setName ( QString new_name );
         void setConsole ( QString new_console );
         
      private:
         QString rom_path;
         QString rom_name;
         QString rom_console;
   };
}

# endif
