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

# ifndef PANELSECTION_H_
# define PANELSECTION_H_

# include <QtWidgets/QGroupBox>
# include <QtWidgets/QVBoxLayout>

# include "../../../base/base.h"
# include "options/integeroption.h"
# include "options/realoption.h"
# include "options/booleanoption.h"
# include "options/enumoption.h"
# include "options/biintegeroption.h"
# include "options/birealoption.h"

namespace Gui
{
   class PanelSection : public QGroupBox
   {
      Q_OBJECT
      
      public:
         explicit PanelSection ( Base::PluginSection* plugin_section );
         virtual ~PanelSection ( void );
         
      private:
         void buildGui ( void );
         
      private:
         Base::PluginSection* section_information;
         QVBoxLayout* main_layout;
   };
}

# endif
