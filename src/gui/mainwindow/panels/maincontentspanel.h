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

# ifndef MAINCONTENTSPANEL_H_
# define MAINCONTENTSPANEL_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QVBoxLayout>

# include "../../../base/base.h"
# include "welcomepanel.h"
# include "controlspanel.h"
# include "buttonspanel.h"

namespace Gui
{
   class MainContentsPanel : public QWidget
   {
      Q_OBJECT

      public:
         explicit MainContentsPanel ( Base::SharedComponents* new_shared_components );
         virtual ~MainContentsPanel ( void );
         
      signals:
         void openRom ( void );
         void openGameDisc ( void );
         void library ( void );
         void config ( void );
         void exitNow ( void );
         void about ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );

      private:
         Base::SharedComponents* shared_components;
         QVBoxLayout* main_layout;
         Gui::WelcomePanel* welcome_panel;
         Gui::ControlsPanel* controls_panel;
         Gui::ButtonsPanel* buttons_panel;
   };
}

# endif
