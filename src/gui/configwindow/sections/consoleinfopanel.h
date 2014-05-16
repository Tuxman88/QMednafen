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

# ifndef CONSOLEINFOPANEL_H_
# define CONSOLEINFOPANEL_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QLabel>

# include "../../../base/base.h"

namespace Gui
{
   class ConsoleInfoPanel : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit ConsoleInfoPanel ( Base::SharedComponents* new_shared_components , Base::PluginInfo* new_plugin_info );
         virtual ~ConsoleInfoPanel ( void );
         
      public slots:
         void updateText ( void );
         
      private:
         void buildGui ( void );
         QString getConsoleName ( QString console_code );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         Base::PluginInfo* plugin_info;
         QHBoxLayout* main_layout;
         QVBoxLayout* icon_layout;
         QVBoxLayout* info_layout;
         QLabel* console_icon;
         QLabel* console_name;
         QLabel* plugin_name;
         QLabel* plugin_author;
         QLabel* plugin_description;
         QLabel* plugin_version;
   };
}

# endif
