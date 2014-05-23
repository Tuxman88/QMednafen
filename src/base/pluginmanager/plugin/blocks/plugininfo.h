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

# ifndef PLUGININFO_H_
# define PLUGININFO_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QDebug>

namespace Base { class PluginInfo; }

QFile& operator>> ( QFile& input_file , Base::PluginInfo& plugin_info );

namespace Base
{
   class PluginInfo : public QObject
   {
      Q_OBJECT
      
      public:
         explicit PluginInfo ( void );
         virtual ~PluginInfo ( void );
         
         QString name ( void ) const;
         QString version ( void ) const;
         QString console ( void ) const;
         QString consoleDescription ( void ) const;
         QString author ( void ) const;
         QString description ( void ) const;
         QStringList extentions ( void ) const;
         bool hasExtention ( const QString& extention );
         
         friend QFile& (::operator>>) ( QFile& input_file , Base::PluginInfo& plugin_info );
         
      private:
         QString plugin_name;
         QString plugin_version;
         QString plugin_console;
         QString plugin_console_description;
         QString plugin_author;
         QString plugin_description;
         QStringList plugin_extentions;
   };
}

# endif
