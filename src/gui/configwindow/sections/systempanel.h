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
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         void buildLanguageSection ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QVBoxLayout* main_layout;
         
         QGroupBox* language_group;
         QHBoxLayout* language_layout;
         QLabel* language_label;
         QComboBox* language_combo;
         
         QGroupBox* mednafen_group;
         
         QGroupBox* paths_group;
         
         QGroupBox* shortcuts_group;
   };
}

# endif
