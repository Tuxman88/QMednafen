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

# ifndef BIREALOPTION_H_
# define BIREALOPTION_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QLabel>
# include <QtWidgets/QDoubleSpinBox>

# include "../../../../base/base.h"

namespace Gui
{
   class BiRealOption : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit BiRealOption ( Base::OptionBiReal* new_option );
         virtual ~BiRealOption ( void );
         
      private:
         void buildGui ( void );
         
      private:
         Base::OptionBiReal* option;
         QHBoxLayout* main_layout;
         QLabel* title_label;
         QLabel* separator_label;
         QDoubleSpinBox* value_spin_a;
         QDoubleSpinBox* value_spin_b;
   };
}

# endif
