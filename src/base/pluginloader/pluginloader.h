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

# ifndef PLUGINLOADER_H_
# define PLUGINLOADER_H_

# include <QtCore/QObject>
# include <QtCore/QString>

# include "plugin.h"

namespace Base
{
   class PluginLoader : public QObject
   {
      Q_OBJECT
      
      public:
         enum LoadState
         {
            AllOk = 0 ,
            CantOpenFile
         };
      
      public:
         explicit PluginLoader ( void );
         virtual ~PluginLoader ( void );
         LoadState load ( QString file_path );
         
      private:
   };
}

# endif
