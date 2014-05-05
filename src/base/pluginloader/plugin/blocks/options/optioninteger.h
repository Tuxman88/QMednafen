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

# ifndef OPTIONINTEGER_H_
# define OPTIONINTEGER_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>
# include <QtCore/QStringList>

# include "../pluginoption.h"

namespace Base
{
   class OptionInteger : public Base::PluginOption
   {
      Q_OBJECT
      
      public:
         explicit OptionInteger ( QString options , QStringList values );
         virtual ~OptionInteger ( void );
         
         void setCurrentValue ( const long int& new_value );
         long int currentValue ( void );
         long int defaultValue ( void );
         long int maxValue ( void );
         long int minValue ( void );
         virtual void reset ( void );
         
      protected:
         long int option_current_value;
         long int option_default_value;
         long int option_min_value;
         long int option_max_value;
         QString option_command;
   };
}

# endif
