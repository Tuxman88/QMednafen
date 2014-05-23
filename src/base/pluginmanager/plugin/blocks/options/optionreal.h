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

# ifndef OPTIONREAL_H_
# define OPTIONREAL_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>
# include <QtCore/QStringList>

# include "../pluginoption.h"

namespace Base
{
   class OptionReal : public Base::PluginOption
   {
      Q_OBJECT
      
      public:
         explicit OptionReal ( QString options , QStringList values );
         virtual ~OptionReal ( void );
         
         void setCurrentValue ( const double& new_value );
         double currentValue ( void );
         double defaultValue ( void );
         double maxValue ( void );
         double minValue ( void );
         virtual void reset ( void );
         virtual void autoLoad ( QMap< QString , QString >& values );
         virtual QString toString ( void );
         
      protected:
         virtual void saveOption ( QTextStream& output_file );
         
      protected:
         double option_current_value;
         double option_default_value;
         double option_min_value;
         double option_max_value;
         QString option_command;
   };
}

# endif
