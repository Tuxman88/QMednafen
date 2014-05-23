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

# ifndef PLUGINOPTION_H_
# define PLUGINOPTION_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>
# include <QtCore/QMap>

namespace Base { class PluginOption; }

QTextStream& operator<< ( QTextStream& output_file , Base::PluginOption* plugin_option );

namespace Base
{
   class PluginOption : public QObject
   {
      Q_OBJECT
      
      public:
         enum OptionType
         {
            None = 0 ,
            Boolean ,
            Integer ,
            BiInteger ,
            Real ,
            BiReal ,
            Enum
         };
      
      public:
         explicit PluginOption ( void );
         virtual ~PluginOption ( void );
         
         virtual OptionType type ( void );
         virtual QString description ( void );
         virtual void autoLoad ( QMap< QString , QString >& values );
         virtual void reset ( void );
         virtual QString toString ( void );
         
         friend QTextStream& (::operator<<) ( QTextStream& output_file , Base::PluginOption* plugin_option );
         
      protected:
         virtual void saveOption ( QTextStream& output_file );
         
      protected:
         QString option_description;
         OptionType option_type;
   };
}

# endif
