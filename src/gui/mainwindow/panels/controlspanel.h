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

# ifndef CONTROLSPANEL_H_
# define CONTROLSPANEL_H_

# include <QtWidgets/QGroupBox>
# include <QtWidgets/QGridLayout>
# include <QtWidgets/QPushButton>
# include <QtWidgets/QLabel>

# include "../../../base/base.h"

namespace Gui
{
   class ControlsPanel : public QGroupBox
   {
      Q_OBJECT
      
      public:
         explicit ControlsPanel ( Base::SharedComponents* new_shared_components );
         virtual ~ControlsPanel ( void );
         
      signals:
         void openRom ( void );
         void openGameDisc ( void );
         void library ( void );
         void config ( void );
         
      public slots:
         void updateText ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QGridLayout* main_layout;
         QPushButton* button_open_rom;
         QPushButton* button_open_game_disc;
         QPushButton* button_library;
         QPushButton* button_config;
         QLabel* label_open_rom;
         QLabel* label_open_game_disc;
         QLabel* label_library;
         QLabel* label_config;
   };
}

# endif
