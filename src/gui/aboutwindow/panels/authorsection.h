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

# ifndef AUTHORSECTION_H_
# define AUTHORSECTION_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QLabel>

# include "../../../base/base.h"

namespace Gui
{
   class AuthorSection : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit AuthorSection ( Base::SharedComponents* new_shared_components , QString new_author_code );
         virtual ~AuthorSection ( void );
         
      public slots:
         void updateText ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QVBoxLayout* main_layout;
         QString author_code;
         QLabel* author_name;
         QLabel* author_link;
         QLabel* author_description;
   };
}

# endif
