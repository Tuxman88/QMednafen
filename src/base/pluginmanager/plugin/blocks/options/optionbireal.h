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

# ifndef OPTIONBIREAL_H_
# define OPTIONBIREAL_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>
# include <QtCore/QStringList>
# include <QtCore/QMap>

# include "../pluginoption.h"

namespace Base
{
   class OptionBiReal : public Base::PluginOption
   {
      Q_OBJECT
      
      public:
         explicit OptionBiReal ( QString options , QStringList values );
         virtual ~OptionBiReal ( void );
         
         void setCurrentValues ( const double& new_value_a , const double& new_value_b );
         double currentValueA ( void );
         double defaultValueA ( void );
         double currentValueB ( void );
         double defaultValueB ( void );
         double maxValue ( void );
         double minValue ( void );
         virtual void reset ( void );
         virtual void autoLoad ( QMap< QString , QString >& values );
         virtual QStringList toString ( void );
         
      protected:
         virtual void saveOption ( QTextStream& output_file );
         
      protected:
         double option_current_value_a;
         double option_current_value_b;
         double option_default_value_a;
         double option_default_value_b;
         double option_min_value;
         double option_max_value;
         QString option_command_a;
         QString option_command_b;
   };
}

# endif
