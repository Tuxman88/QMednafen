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

# ifndef CONFIGWINDOW_H_
# define CONFIGWINDOW_H_

# include <QtWidgets/QDialog>
# include <QtWidgets/QTabWidget>
# include <QtWidgets/QVBoxLayout>

# include "../../base/base.h"
# include "sections/systempanel.h"
# include "sections/pluginpanel.h"

namespace Gui
{
   class ConfigWindow : public QDialog
   {
      Q_OBJECT
      
      public:
         explicit ConfigWindow ( Base::SharedComponents* new_shared_components );
         virtual ~ConfigWindow ( void );
         
      public slots:
         void openConfigWindow ( void );
         void closeConfigWindow ( void );
         
      private:
         Base::SharedComponents* shared_components;
         Gui::SystemPanel* system_panel;
         QTabWidget* tab_panel;
         QVBoxLayout* main_layout;
         QVector< Gui::PluginPanel* > plugins_panels;
   };
}

# endif
