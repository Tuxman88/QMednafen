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

# ifndef PLUGINMANAGER_H_
# define PLUGINMANAGER_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QVector>
# include <QtCore/QDir>
# include <QtCore/QStringList>
# include <QtCore/QDebug>

# include "plugin/plugin.h"
# include "../../base/configuration/configuration.h"

namespace Base
{
   class PluginManager : public QObject
   {
      Q_OBJECT
      
      public:
         enum LoadState
         {
            AllOk = 0 ,
            NonePluginLoaded
         };
      
      public:
         explicit PluginManager ( Base::Configuration* new_shared_configuration );
         virtual ~PluginManager ( void );
         
         LoadState load ( QStringList folder_paths );
         void loadValues ( void );
         void saveValues ( void );
         void resetValues ( void );
         QVector< Base::Plugin* >* pluginsLoaded ( void );
         QStringList getOptions ( const QString& file_extention );
         QString detectType ( const QString& file_extention );
         
      private:
         Base::Configuration* shared_configuration;
         QVector< Base::Plugin* >* plugins_loaded;
   };
}

# endif
