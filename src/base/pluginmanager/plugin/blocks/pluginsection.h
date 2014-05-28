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

# ifndef PLUGINSECTION_H_
# define PLUGINSECTION_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>
# include <QtCore/QList>
# include <QtCore/QMap>

# include "pluginoption.h"
# include "options/optioninteger.h"
# include "options/optionreal.h"
# include "options/optionenum.h"
# include "options/optionbiinteger.h"
# include "options/optionbireal.h"
# include "options/optionboolean.h"
# include "options/optionenum.h"
# include "options/optionstring.h"

namespace Base { class PluginSection; }

QFile& operator>> ( QFile& input_file , Base::PluginSection& plugin_section );
QTextStream& operator<< ( QTextStream& output_file , Base::PluginSection* plugin_section );

namespace Base
{
   class PluginSection : public QObject
   {
      Q_OBJECT
      
      public:
         explicit PluginSection ( void );
         virtual ~PluginSection ( void );
         
         QString name ( void );
         void setName ( const QString& new_name );
         QList< Base::PluginOption* >* options ( void );
         void autoLoad ( QMap< QString , QString >& values );
         void resetValues ( void );
         QStringList getOptions ( void );
         
         friend QFile& (::operator>>) ( QFile& input_file , Base::PluginSection& plugin_section );
         friend QTextStream& (::operator<<) ( QTextStream& output_file , Base::PluginSection* plugin_section );
         
      private:
         QString section_name;
         QList< Base::PluginOption* >* section_options;
   };
}

# endif
