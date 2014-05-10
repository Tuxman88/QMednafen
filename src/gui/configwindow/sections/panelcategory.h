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

# ifndef PANELCATEGORY_H_
# define PANELCATEGORY_H_

# include <QtWidgets/QWidget>
# include <QtWidgets/QVBoxLayout>

# include "../../../base/base.h"
# include "panelsection.h"

namespace Gui
{
   class PanelCategory : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PanelCategory ( QList< Base::PluginSection* >* new_sections );
         virtual ~PanelCategory ( void );
         
      private:
         void buildGui ( void );
         void addSections ( void );
         
      private:
         QList< Base::PluginSection* >* sections;
         QList< Gui::PanelSection* >* section_panels;
         QVBoxLayout* main_layout;
   };
}

# endif
