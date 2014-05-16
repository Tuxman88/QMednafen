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
# include <QtWidgets/QScrollArea>
# include <QtWidgets/QVBoxLayout>
# include <QtCore/QEvent>

# include "../../../base/base.h"
# include "sectionpanel.h"

namespace Gui
{
   class CategoryPanel : public QScrollArea
   {
      Q_OBJECT
      
      public:
         explicit CategoryPanel ( QList< Base::PluginSection* >* new_sections );
         virtual ~CategoryPanel ( void );
         
      private:
         void buildGui ( void );
         void addSections ( void );
         bool eventFilter ( QObject *o , QEvent *e );
         
      private:
         QList< Base::PluginSection* >* sections;
         QList< Gui::SectionPanel* >* section_panels;
         QVBoxLayout* main_layout;
         QWidget* scroll_area_widget_contents;
   };
}

# endif
