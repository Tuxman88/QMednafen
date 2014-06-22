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

# ifndef LIBRARYMANAGER_H_
# define LIBRARYMANAGER_H_

# include <QtWidgets/QDialog>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QPushButton>

# include "../../base/base.h"
# include "../../core/core.h"
# include "consolespanel.h"
# include "scanningdialog.h"

namespace Gui
{
   class LibraryManager : public QDialog
   {
      Q_OBJECT
      
      public:
         explicit LibraryManager ( Base::SharedComponents* new_shared_components );
         virtual ~LibraryManager ( void );
         
      signals:
         void scanLibraryFolders ( void );
         void cancelScanProcess ( void );
         void launchLibraryGame ( const QString& game_path );
         
      public slots:
         void openLibraryManager ( Core::RomManager* rom_manager );
         void closeLibraryManager ( void );
         void scanningFolder ( const QString& folder_name );
         void updateList ( void );
         
      private slots:
         void startScanProcess ( void );
         void cancelScan ( void );
         void updateText ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         Core::RomManager* manager;
         Gui::ConsolesPanel* consoles_panel;
         Gui::ScanningDialog* scanning_dialog;
         QVBoxLayout* main_layout;
         QHBoxLayout* buttons_layout;
         QPushButton* scan_button;
         QPushButton* close_button;
         bool already_added;
   };
}

# endif
