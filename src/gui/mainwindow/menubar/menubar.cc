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

# include "menubar.h"

Gui::MenuBar::MenuBar ( Base::SharedComponents* new_shared_components )
   : QMenuBar ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
   updateText ();
}

Gui::MenuBar::~MenuBar ( void )
{
}

void Gui::MenuBar::buildGui(void)
{
   menu_file   = addMenu ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuFile ) );
   menu_config = addMenu ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuConfig ) );
   menu_help   = addMenu ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuHelp ) );
   
   file_openrom      = menu_file->addAction ( "..." );
   file_opengamedisc = menu_file->addAction ( "..." );
   file_separator1   = menu_file->addSeparator ();
   file_library      = menu_file->addAction ( "..." );
   file_separator2   = menu_file->addSeparator ();
   file_exit         = menu_file->addAction ( "..." );
   config_config     = menu_config->addAction ( "..." );
   help_about        = menu_help->addAction ( "..." );
   
   return;
}

void Gui::MenuBar::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )      , this , SLOT   ( updateText () ) );
   connect ( file_openrom               , SIGNAL ( triggered ( bool ) ) , this , SIGNAL ( openRom () ) );
   connect ( file_opengamedisc          , SIGNAL ( triggered ( bool ) ) , this , SIGNAL ( openGameDisc () ) );
   connect ( file_library               , SIGNAL ( triggered ( bool ) ) , this , SIGNAL ( library () ) );
   connect ( file_exit                  , SIGNAL ( triggered ( bool ) ) , this , SIGNAL ( exitNow () ) );
   connect ( config_config              , SIGNAL ( triggered ( bool ) ) , this , SIGNAL ( config () ) );
   connect ( help_about                 , SIGNAL ( triggered ( bool ) ) , this , SIGNAL ( about () ) );
   
   return;
}

void Gui::MenuBar::updateText ( void )
{
   file_openrom->setText      ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuFileOpenRom ) );
   file_opengamedisc->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuFileOpenGameDisc ) );
   file_library->setText      ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuFileLibrary ) );
   file_exit->setText         ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuFileExit ) );
   config_config->setText     ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuConfigConfig ) );
   help_about->setText        ( shared_components->text ()->operator[] ( Base::KeyTxtGuiMenuHelpAbout ) );
   
   return;
}
