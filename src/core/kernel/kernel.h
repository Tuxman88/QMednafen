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

# ifndef KERNEL_H_
# define KERNEL_H_

# include <QtCore/QObject>
# include <QtCore/QDebug>

# include "../../base/base.h"

namespace Core
{
   class Kernel : public QObject
   {
      Q_OBJECT
      
      public:
         explicit Kernel ( Base::SharedComponents* new_shared_components );
         virtual ~Kernel ( void );
         
      signals:
         void closeMainWindow ( void );
         void closeConfigWindow ( void );
         void closeAboutWindow ( void );
         void openConfigWindow ( void );
         void openAboutWindow ( void );
         
      public slots:
         void openRom ( void );
         void openGameDisc ( void );
         void library ( void );
         void config ( void );
         void exitNow ( void );
         void about ( void );
         
      private:
         Base::SharedComponents* shared_components;
   };
}

# endif
