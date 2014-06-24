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
 
# ifndef SYSTEMPANEL_H_
# define SYSTEMPANEL_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QGroupBox>
# include <QtWidgets/QLabel>
# include <QtWidgets/QComboBox>
# include <QtWidgets/QLineEdit>

# include "../../../base/base.h"

namespace Gui
{
   class SystemPanel : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit SystemPanel ( Base::SharedComponents* new_shared_components );
         virtual ~SystemPanel ( void );
         
      public slots:
         void updateText ( void );
         
      private slots:
         void languageChanged ( void );
         void formatChanged ( void );
         void versionChanged ( void );
         void binaryChanged ( void );
         void pluginsChanged ( void );
         void libraryChanged ( void );
         void openRomChanged ( void );
         void openDiscChanged ( void );
         void openAboutChanged ( void );
         void openInstancesChanged ( void );
         void openConfigChanged ( void );
         void openLibraryChanged ( void );
         void openManualChanged ( void );
         void exitChanged ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         void buildLanguageSection ( void );
         void buildMednafenSection ( void );
         void buildPathsSection ( void );
         void buildShortcutsSection ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QVBoxLayout* main_layout;
         
         QGroupBox* language_group;
         QHBoxLayout* language_layout;
         QLabel* language_label;
         QComboBox* language_combo;
         
         QGroupBox* mednafen_group;
         QVBoxLayout* mednafen_layout;
         QHBoxLayout* mednafen_format_layout;
         QHBoxLayout* mednafen_version_layout;
         QLabel* mednafen_format_label;
         QLabel* mednafen_version_label;
         QComboBox* mednafen_format_combo;
         QComboBox* mednafen_version_combo;
         
         QGroupBox* paths_group;
         QVBoxLayout* paths_layout;
         QHBoxLayout* binary_layout;
         QHBoxLayout* plugins_layout;
         QHBoxLayout* library_layout;
         QLabel* binary_label;
         QLabel* plugins_label;
         QLabel* library_label;
         QLineEdit* binary_line;
         QLineEdit* plugins_line;
         QLineEdit* library_line;
         
         QGroupBox* shortcuts_group;
         QVBoxLayout* shortcuts_layout;
         QHBoxLayout* openrom_layout;
         QHBoxLayout* opendisc_layout;
         QHBoxLayout* openabout_layout;
         QHBoxLayout* openinstances_layout;
         QHBoxLayout* openconfig_layout;
         QHBoxLayout* openlibrary_layout;
         QHBoxLayout* openmanual_layout;
         QHBoxLayout* exit_layout;
         QLabel* openrom_label;
         QLabel* opendisc_label;
         QLabel* openabout_label;
         QLabel* openinstances_label;
         QLabel* openconfig_label;
         QLabel* openlibrary_label;
         QLabel* openmanual_label;
         QLabel* exit_label;
         QLineEdit* openrom_line;
         QLineEdit* opendisc_line;
         QLineEdit* openabout_line;
         QLineEdit* openinstances_line;
         QLineEdit* openconfig_line;
         QLineEdit* openlibrary_line;
         QLineEdit* openmanual_line;
         QLineEdit* exit_line;
   };
}

# endif
