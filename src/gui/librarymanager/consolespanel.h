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

# ifndef CONSOLESPANEL_H_
# define CONSOLESPANEL_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QTabWidget>

# include "../../base/base.h"
# include "consolelist.h"
# include "../../core/rommanager/rommanager.h"

namespace Gui
{
   class ConsolesPanel : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit ConsolesPanel ( Base::SharedComponents* new_shared_components );
         virtual ~ConsolesPanel ( void );
         
         void setRomManager ( Core::RomManager* new_rom_manager );
         void updateList ( void );
         
      signals:
         void launchLibraryGame ( const QString& game_path );
         
      private:
         void removePanels ( void );
         QString consoleName ( const QString& console_id );
         
      private:
         Base::SharedComponents* shared_components;
         QVBoxLayout* main_layout;
         QTabWidget* tab_panel;
         Core::RomManager* rom_manager;
         QList< QString > consoles_list;
         QMap< QString , ConsoleList* > consoles_map;
   };
}

# endif
