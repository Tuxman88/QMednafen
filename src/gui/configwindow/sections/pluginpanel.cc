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

# include "pluginpanel.h"

Gui::PluginPanel::PluginPanel ( Base::SharedComponents* new_shared_components , Base::Plugin* new_plugin )
   : QWidget ()
{
   shared_components = new_shared_components;
   plugin = new_plugin;
   
   buildGui ();
   connectAll ();
}

Gui::PluginPanel::~PluginPanel ( void )
{
}

void Gui::PluginPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
   
   return;
}

void Gui::PluginPanel::updateText ( void )
{
   tab_widgets->setTabText ( audio_tab_index    , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigAudioOptions ) );
   tab_widgets->setTabText ( controls_tab_index , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigControlOptions ) );
   tab_widgets->setTabText ( video_tab_index    , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigVideoOptions ) );
   
   return;
}

void Gui::PluginPanel::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   tab_widgets = new QTabWidget ();
   main_layout->addWidget ( tab_widgets );
   
   if ( plugin->videoOptions ()->size () > 0 )
   {
      addVideoOptions ();
   }
   
   if ( plugin->audioOptions ()->size () > 0 )
   {
      addAudioOptions ();
   }
   
   if ( plugin->controlsOptions ()->size () > 0 )
   {
      addControlOptions ();
   }
   
   return;
}

void Gui::PluginPanel::addVideoOptions ( void )
{
   Gui::PanelCategory* category;
   category = new Gui::PanelCategory ( plugin->videoOptions () );
   video_tab_index = tab_widgets->addTab ( category , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigVideoOptions ) );
   
   return;
}

void Gui::PluginPanel::addAudioOptions ( void )
{
   Gui::PanelCategory* category;
   category = new Gui::PanelCategory ( plugin->audioOptions () );
   audio_tab_index = tab_widgets->addTab ( category , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigAudioOptions ) );
   
   return;
}

void Gui::PluginPanel::addControlOptions ( void )
{
   Gui::PanelCategory* category;
   category = new Gui::PanelCategory ( plugin->controlsOptions () );
   controls_tab_index = tab_widgets->addTab ( category , shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigControlOptions ) );
   
   return;
}
