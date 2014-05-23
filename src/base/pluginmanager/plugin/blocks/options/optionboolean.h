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

# ifndef OPTIONBOOLEAN_H_
# define OPTIONBOOLEAN_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>
# include <QtCore/QStringList>

# include "../pluginoption.h"

namespace Base
{
   class OptionBoolean : public Base::PluginOption
   {
      Q_OBJECT
      
      public:
         explicit OptionBoolean ( QString options , QStringList values );
         virtual ~OptionBoolean ( void );
         
         void setCurrentValue ( const bool& new_value );
         bool currentValue ( void );
         bool defaultValue ( void );
         virtual void reset ( void );
         virtual void autoLoad ( QMap< QString , QString >& values );
         virtual QString toString ( void );
         
      protected:
         virtual void saveOption ( QTextStream& output_file );
         
      protected:
         bool option_current_value;
         bool option_default_value;
         QString option_command;
   };
}

# endif
