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

# ifndef CONSOLEENTRY_H_
# define CONSOLEENTRY_H_

# include <QtWidgets/QWidget>

# include "../../base/base.h"

namespace Gui
{
   class ConsoleEntry : public QWidget
   {
      Q_OBJECT
      
      public:     
         explicit ConsoleEntry ( Base::SharedComponents* new_shared_components );
         virtual ~ConsoleEntry ( void );
         
      private:
         Base::SharedComponents* shared_components;
   };
}

# endif
