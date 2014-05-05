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

# ifndef PLUGIN_H_
# define PLUGIN_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <cstdlib>

# include "blocks/plugininfo.h"

namespace Base { class Plugin; };

QFile& operator>> ( QFile& input_file , Base::Plugin& plugin );

namespace Base
{
   class Plugin : public QObject
   {
      Q_OBJECT
      
      public:
         explicit Plugin ( void );
         virtual ~Plugin ( void );
         
         Base::PluginInfo* info ( void );
         void setSavePath ( QString new_save_path );
         QString savePath ( void );
         
         friend QFile& (::operator>>) ( QFile& input_file , Base::Plugin& plugin );
         
      private:
         QString save_path;
         Base::PluginInfo* plugin_info;
   };
}

# endif
