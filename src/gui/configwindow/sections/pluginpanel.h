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

# ifndef PLUGINPANEL_H_
# define PLUGINPANEL_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QTabWidget>

# include "../../../base/base.h"
# include "categorypanel.h"
# include "consoleinfopanel.h"

namespace Gui
{
   class PluginPanel : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PluginPanel ( Base::SharedComponents* new_shared_components , Base::Plugin* new_plugin );
         virtual ~PluginPanel ( void );
         
      public slots:
         void updateText ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         void addVideoOptions ( void );
         void addAudioOptions ( void );
         void addControlOptions ( void );
         void addInGameOptions ( void );
         
      private:
         Base::SharedComponents* shared_components;
         Base::Plugin* plugin;
         QVector< Gui::CategoryPanel* > plugin_categories;
         QVBoxLayout* main_layout;
         QTabWidget* tab_widgets;
         Gui::ConsoleInfoPanel* console_info;
         int video_tab_index;
         int audio_tab_index;
         int controls_tab_index;
         int ingame_tab_index;
   };
}

# endif
