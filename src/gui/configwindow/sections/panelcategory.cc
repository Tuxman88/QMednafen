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

# include "panelcategory.h"

Gui::PanelCategory::PanelCategory ( QList< Base::PluginSection* >* new_sections )
   : QWidget ()
{
   sections = new_sections;
   
   buildGui ();
}

Gui::PanelCategory::~PanelCategory ( void )
{
}

void Gui::PanelCategory::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   section_panels = new QList< Gui::PanelSection* > ();
   
   addSections ();
   
   return;
}

void Gui::PanelCategory::addSections ( void )
{
   for ( int i = 0; i < sections->size (); i++ )
   {
      Gui::PanelSection* new_section;
      new_section = new Gui::PanelSection ( sections->operator[] ( i ) );
      section_panels->append ( new_section );
      main_layout->addWidget ( new_section );
   }
   
   main_layout->addStretch ();
   
   return;
}
