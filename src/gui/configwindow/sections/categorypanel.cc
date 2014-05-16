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

# include "categorypanel.h"

Gui::CategoryPanel::CategoryPanel ( QList< Base::PluginSection* >* new_sections )
   : QScrollArea ()
{
   sections = new_sections;
   
   buildGui ();
}

Gui::CategoryPanel::~CategoryPanel ( void )
{
}

void Gui::CategoryPanel::buildGui ( void )
{
   setWidgetResizable ( true );
   setFrameStyle ( QFrame::NoFrame );
   setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
   setVerticalScrollBarPolicy ( Qt::ScrollBarAsNeeded );
   scroll_area_widget_contents = new QWidget ( this );
   scroll_area_widget_contents->setSizePolicy ( QSizePolicy::Preferred , QSizePolicy::Preferred );
   main_layout = new QVBoxLayout ( scroll_area_widget_contents );
   scroll_area_widget_contents->setLayout ( main_layout );
   setWidget ( scroll_area_widget_contents );
   scroll_area_widget_contents->installEventFilter ( this );
   section_panels = new QList< Gui::SectionPanel* > ();
   addSections ();
   
   return;
}

bool Gui::CategoryPanel::eventFilter ( QObject *o , QEvent *e )
{
   if ( o == scroll_area_widget_contents && e->type() == QEvent::Resize )
   {
      setMinimumWidth ( scroll_area_widget_contents->minimumSizeHint ().width () );
   }
 
   return false;
}

void Gui::CategoryPanel::addSections ( void )
{
   for ( int i = 0; i < sections->size (); i++ )
   {
      Gui::SectionPanel* new_section;
      new_section = new Gui::SectionPanel ( sections->operator[] ( i ) );
      section_panels->append ( new_section );
      main_layout->addWidget ( new_section );
   }
   
   main_layout->addStretch ();
   
   return;
}
