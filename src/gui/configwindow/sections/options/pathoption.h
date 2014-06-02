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

# ifndef PATHOPTION_H_
# define PATHOPTION_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QLabel>
# include <QtWidgets/QLineEdit>
# include <QtWidgets/QPushButton>
# include <QtWidgets/QFileDialog>

# include "../../../../base/base.h"

namespace Gui
{
   class PathOption : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PathOption ( Base::OptionPath* new_option );
         virtual ~PathOption ( void );
         
      private slots:
         void updateValue ( const QString& value );
         void valuesUpdated ( void );
         void selectFile ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::OptionPath* option;
         QHBoxLayout* main_layout;
         QLabel* title_label;
         QLineEdit* value_line;
         QPushButton* select_file;
   };
}

# endif
