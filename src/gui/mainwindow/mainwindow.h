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

# ifndef MAINWINDOW_H_
# define MAINWINDOW_H_

# include <QtGui/QMainWindow>
# include <QtGui/QMenuBar>
# include <QtGui/QMenu>
# include <QtGui/QAction>
# include <QtGui/QIcon>

# include "../../base/base.h"
# include "menubar/menubar.h"
# include "panels/maincontentspanel.h"

namespace Gui
{
   class MainWindow : public QMainWindow
   {
      Q_OBJECT
      
      public:
         explicit MainWindow ( Base::SharedComponents* new_shared_components );
         virtual ~MainWindow ( void );
         
      signals:
         void openRom ( void );
         void openGameDisc ( void );
         void library ( void );
         void config ( void );
         void exitNow ( void );
         void about ( void );
      
      public slots:
         void updateText ( void );
         void closeMainWindow ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         Gui::MenuBar* menubar;
         Gui::MainContentsPanel* main_contents_panel;
   };
}

# endif
