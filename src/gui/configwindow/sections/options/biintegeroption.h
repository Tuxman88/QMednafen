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

# ifndef BIINTEGEROPTION_H_
# define BIINTEGEROPTION_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QLabel>
# include <QtWidgets/QSpinBox>
# include <QtCore/QString>

# include "../../../../base/base.h"

namespace Gui
{
   class BiIntegerOption : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit BiIntegerOption ( Base::OptionBiInteger* new_option );
         virtual ~BiIntegerOption ( void );
         
      private slots:
         void updateValueA ( const int& value );
         void updateValueB ( const int& value );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::OptionBiInteger* option;
         QHBoxLayout* main_layout;
         QLabel* title_label;
         QLabel* separator_label;
         QSpinBox* value_spin_a;
         QSpinBox* value_spin_b;
   };
}

# endif
