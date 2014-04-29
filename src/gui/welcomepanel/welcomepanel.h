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

# ifndef WELCOMEPANEL_H_
# define WELCOMEPANEL_H_

# include <QtGui/QWidget>
# include <QtGui/QHBoxLayout>
# include <QtGui/QVBoxLayout>
# include <QtGui/QLabel>
# include <QtGui/QPixmap>

# include "../../base/base.h"

namespace Gui
{
   class WelcomePanel : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit WelcomePanel ( Base::SharedComponents* new_shared_components );
         virtual ~WelcomePanel ( void );
         
      public slots:
         void updateText ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QHBoxLayout* main_layout;
         QVBoxLayout* info_layout;
         QVBoxLayout* version_layout;
         QLabel* program_icon;
         QLabel* program_name;
         QLabel* program_description;
         QLabel* program_version;
   };
}

# endif
