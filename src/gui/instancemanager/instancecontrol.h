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

# ifndef INSTANCECONTROL_H_
# define INSTANCECONTROL_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QLabel>
# include <QtWidgets/QPushButton>

# include "../../base/base.h"
# include "../../core/core.h"

namespace Gui
{
   class InstanceControl : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit InstanceControl ( Base::SharedComponents* new_shared_components );
         virtual ~InstanceControl ( void );
         
         void setGameInstance ( Core::EmulatorInstance* new_game_instance );
         
      signals:
         void closeGameInstance ( Core::EmulatorInstance* game_instance );
         
      private slots:
         void updateText ( void );
         void closeGame ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         Core::EmulatorInstance* game_instance;
         QHBoxLayout* main_layout;
         QLabel* console_icon;
         QLabel* game_name;
         QPushButton* close_game;
   };
}

# endif
