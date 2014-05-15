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

# ifndef ABOUTWINDOW_H_
# define ABOUTWINDOW_H_

# include <QtWidgets/QDialog>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QTabWidget>
# include <QtWidgets/QPushButton>

# include "../../base/base.h"
# include "panels/aboutpanel.h"
# include "panels/creditspanel.h"
# include "panels/licensepanel.h"

namespace Gui
{
   class AboutWindow : public QDialog
   {
      Q_OBJECT
      
      public:
         explicit AboutWindow ( Base::SharedComponents* new_shared_components );
         virtual ~AboutWindow ( void );
         
      public slots:
         void updateText ( void );
         void openAboutWindow ( void );
         void closeAboutWindow ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         QVBoxLayout* main_layout;
         QTabWidget* tab_widget;
         QHBoxLayout* buttons_layout;
         QPushButton* close_button;
         Base::SharedComponents* shared_components;
         Gui::AboutPanel* about_panel;
         Gui::CreditsPanel* credits_panel;
         Gui::LicensePanel* license_panel;
         int about_tab_index;
         int credits_tab_index;
         int license_tab_index;
   };
}

# endif
