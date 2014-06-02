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

# ifndef INSTANCEMANAGER_H_
# define INSTANCEMANAGER_H_

# include <QtWidgets/QDialog>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QPushButton>
# include <QtGui/QIcon>
# include <QtGui/QListWidget>
# include <QtGui/QListWidgetItem>

# include "../../base/base.h"
# include "../../core/core.h"
# include "instancecontrol.h"

namespace Gui
{
   class InstanceManager : public QDialog
   {
      Q_OBJECT
      
      public:
         explicit InstanceManager ( Base::SharedComponents* new_shared_components );
         virtual ~InstanceManager ( void );
                  
      public slots:
         void openInstanceManager ( Core::EmulatorManager* new_emulator_manager );
         void closeInstanceManager ( void );
         
      private slots:
         void updateText ( void );
         void updateGameList ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         QListWidget* list_widget;
         QVBoxLayout* main_layout;
         QHBoxLayout* buttons_layout;
         QPushButton* button_close;
         Base::SharedComponents* shared_components;
         Core::EmulatorManager* emulator_manager;
         bool already_added;
         QList< Gui::InstanceControl* > list_instances;
         QList< QListWidgetItem* > list_items;
   };
}

# endif
