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

# include "sectionpanel.h"

Gui::SectionPanel::SectionPanel ( Base::PluginSection* plugin_section )
   : QGroupBox ()
{
   section_information = plugin_section;
   
   buildGui ();
}

Gui::SectionPanel::~SectionPanel ( void )
{
}

void Gui::SectionPanel::buildGui ( void )
{
   setTitle ( section_information->name () );
   
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   for ( int i = 0; i < section_information->options ()->size (); i++ )
   {
      Base::PluginOption* option;
      option = section_information->options ()->operator[] ( i );
      
      switch ( option->type () )
      {
         case Base::PluginOption::Integer:
         {
            Gui::IntegerOption* integer_option;
            integer_option = new Gui::IntegerOption ( dynamic_cast< Base::OptionInteger* > ( option ) );
            main_layout->addWidget ( integer_option );
         }
            break;
            
         case Base::PluginOption::Real:
         {
            Gui::RealOption* real_option;
            real_option = new Gui::RealOption ( dynamic_cast< Base::OptionReal* > ( option ) );
            main_layout->addWidget ( real_option );
         }
            break;
            
         case Base::PluginOption::Boolean:
         {
            Gui::BooleanOption* boolean_option;
            boolean_option = new Gui::BooleanOption ( dynamic_cast< Base::OptionBoolean* > ( option ) );
            main_layout->addWidget ( boolean_option );
         }
            break;
            
         case Base::PluginOption::Enum:
         {
            Gui::EnumOption* enum_option;
            enum_option = new Gui::EnumOption ( dynamic_cast< Base::OptionEnum* > ( option ) );
            main_layout->addWidget ( enum_option );
         }
            break;
            
         case Base::PluginOption::BiInteger:
         {
            Gui::BiIntegerOption* biinteger_option;
            biinteger_option = new Gui::BiIntegerOption ( dynamic_cast< Base::OptionBiInteger* > ( option ) );
            main_layout->addWidget ( biinteger_option );
         }
            break;
            
         case Base::PluginOption::BiReal:
         {
            Gui::BiRealOption* bireal_option;
            bireal_option = new Gui::BiRealOption ( dynamic_cast< Base::OptionBiReal* > ( option ) );
            main_layout->addWidget ( bireal_option );
         }
            break;
            
         case Base::PluginOption::None:
            break;
      }
   }
   
   main_layout->addStretch ();
   
   return;
}
