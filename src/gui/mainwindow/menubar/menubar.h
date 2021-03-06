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

# ifndef MENUBAR_H_
# define MENUBAR_H_

# include <QtWidgets/QMenuBar>
# include <QtWidgets/QMenu>
# include <QtWidgets/QAction>
# include <QtGui/QKeySequence>
# include <QtCore/QDebug>

# include "../../../base/base.h"

namespace Gui
{
   class MenuBar : public QMenuBar
   {
      Q_OBJECT
      
      public:
         explicit MenuBar ( Base::SharedComponents* new_shared_components );
         virtual ~MenuBar ( void );
         
      signals:
         void openRom ( void );
         void openGameDisc ( void );
         void library ( void );
         void instanceManager ( void );
         void config ( void );
         void exitNow ( void );
         void about ( void );
         void openManual ( void );
         
      public slots:
         void updateText ( void );
         void updateConfig ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QMenu* menu_file;
         QMenu* menu_config;
         QMenu* menu_tools;
         QMenu* menu_help;
         QAction* file_openrom;
         QAction* file_opengamedisc;
         QAction* file_separator1;
         QAction* file_exit;
         QAction* config_config;
         QAction* tools_instancemanager;
         QAction* tools_library;
         QAction* help_manual;
         QAction* help_about;
   };
}

# endif
