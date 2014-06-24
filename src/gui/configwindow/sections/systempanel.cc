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
 
# include "systempanel.h"

Gui::SystemPanel::SystemPanel ( Base::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   updateText ();
   connectAll ();
}

Gui::SystemPanel::~SystemPanel ( void )
{
}

void Gui::SystemPanel::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   buildLanguageSection ();
   buildMednafenSection ();
   buildPathsSection ();
   buildShortcutsSection ();
   
   main_layout->addStretch ();
   
   return;
}

void Gui::SystemPanel::connectAll ( void )
{
   connect ( shared_components->text () , SIGNAL ( updateText () )                   , this , SLOT ( updateText () ) );
   connect ( language_combo             , SIGNAL ( currentIndexChanged ( QString ) ) , this , SLOT ( languageChanged () ) );
   connect ( mednafen_format_combo      , SIGNAL ( currentIndexChanged ( QString ) ) , this , SLOT ( formatChanged()) );
   connect ( mednafen_version_combo     , SIGNAL ( currentIndexChanged ( QString ) ) , this , SLOT ( versionChanged () ) );
   connect ( binary_line                , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( binaryChanged () ) );
   connect ( plugins_line               , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( pluginsChanged () ) );
   connect ( library_line               , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( libraryChanged () ) );
   connect ( openrom_line               , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openRomChanged () ) );
   connect ( opendisc_line              , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openDiscChanged () ) );
   connect ( openabout_line             , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openAboutChanged () ) );
   connect ( openinstances_line         , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openInstancesChanged () ) );
   connect ( openconfig_line            , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openConfigChanged () ) );
   connect ( openlibrary_line           , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openLibraryChanged () ) );
   connect ( openmanual_line            , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( openManualChanged () ) );
   connect ( exit_line                  , SIGNAL ( textChanged ( QString ) )         , this , SLOT ( exitChanged () ) );
   
   return;
}

void Gui::SystemPanel::updateText ( void )
{
   language_group->setTitle        ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigLanguage ) );
   language_label->setText         ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigSelectLanguage ) );
   mednafen_group->setTitle        ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigMednafenGroup ) );
   mednafen_format_label->setText  ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigCommandFormat ) );
   mednafen_version_label->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigRunningVersion ) );
   paths_group->setTitle           ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigPathsGroup ) );
   binary_label->setText           ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigBinaryPath ) );
   library_label->setText          ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigLibraryPaths ) );
   plugins_label->setText          ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigPluginsPaths ) );
   shortcuts_group->setTitle       ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutsGroup ) );
   openabout_label->setText        ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenAbout ) );
   openconfig_label->setText       ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenConfig ) );
   opendisc_label->setText         ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenDisc ) );
   openinstances_label->setText    ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenInstanceManager ) );
   openlibrary_label->setText      ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenLibrary ) );
   openmanual_label->setText       ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenManual ) );
   openrom_label->setText          ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutOpenRom ) );
   exit_label->setText             ( shared_components->text ()->operator[] ( Base::KeyTxtGuiConfigSystemConfigShortcutExit ) );
   
   return;
}

void Gui::SystemPanel::buildLanguageSection ( void )
{
   language_group = new QGroupBox ();
   main_layout->addWidget ( language_group );
   
   language_layout = new QHBoxLayout ();
   language_group->setLayout ( language_layout );
   
   language_label = new QLabel ( "..." );
   language_label->setFixedWidth ( Base::LabelWidth );
   language_label->setWordWrap ( true );
   language_layout->addWidget ( language_label );
   language_layout->addStretch ();
   
   language_combo = new QComboBox ();
   language_combo->setFixedWidth ( Base::ComboWidth );
   language_layout->addWidget ( language_combo );
   language_combo->addItem ( "English" );
   language_combo->addItem ( "Spanish" );
   QString current_language = ( shared_components->config ()->operator[] ( Base::KeyCfgGuiLanguage ) == "english" ) ? "English" : "Spanish";
   language_combo->setCurrentText ( current_language );
   
   return;
}

void Gui::SystemPanel::buildMednafenSection ( void )
{
   mednafen_group = new QGroupBox ();
   main_layout->addWidget ( mednafen_group );
   
   mednafen_layout = new QVBoxLayout ();
   mednafen_group->setLayout ( mednafen_layout );
   
   mednafen_format_layout = new QHBoxLayout ();
   mednafen_version_layout = new QHBoxLayout ();
   
   mednafen_layout->addLayout ( mednafen_format_layout );
   mednafen_layout->addLayout ( mednafen_version_layout );
   
   mednafen_format_label = new QLabel ( "..." );
   mednafen_format_label->setFixedWidth ( Base::LabelWidth );
   mednafen_format_label->setWordWrap ( true );
   mednafen_format_combo = new QComboBox ();
   mednafen_format_combo->setFixedWidth ( Base::ComboWidth );
   
   mednafen_format_layout->addWidget ( mednafen_format_label );
   mednafen_format_layout->addStretch ();
   mednafen_format_layout->addWidget ( mednafen_format_combo );
   
   mednafen_version_label = new QLabel ( "..." );
   mednafen_version_label->setFixedWidth ( Base::LabelWidth );
   mednafen_version_label->setWordWrap ( true );
   mednafen_version_combo = new QComboBox ();
   mednafen_version_combo->setFixedWidth ( Base::ComboWidth );
   
   mednafen_version_layout->addWidget ( mednafen_version_label );
   mednafen_version_layout->addStretch ();
   mednafen_version_layout->addWidget ( mednafen_version_combo );
   
   mednafen_format_combo->addItem ( "ROM OPTIONS" );
   mednafen_format_combo->addItem ( "OPTIONS ROM" );
   mednafen_version_combo->addItem ( "0.9.34.1" );
   
   if ( shared_components->config ()->operator[] ( Base::KeyCfgCoreCommandOrder ) == "rom_options" )
      mednafen_format_combo->setCurrentText ( "ROM OPTIONS" );
   else
      mednafen_format_combo->setCurrentText ( "OPTIONS ROM" );
   
   mednafen_version_combo->setCurrentText ( shared_components->config ()->operator[] ( Base::KeyCfgCoreRunVersion ) );
   
   return;
}

void Gui::SystemPanel::buildPathsSection ( void )
{
   paths_group = new QGroupBox ();
   main_layout->addWidget ( paths_group );
   
   paths_layout = new QVBoxLayout ();
   paths_group->setLayout ( paths_layout );
   
   binary_layout = new QHBoxLayout ();
   library_layout = new QHBoxLayout ();
   plugins_layout = new QHBoxLayout ();
   paths_layout->addLayout ( binary_layout );
   paths_layout->addLayout ( library_layout );
   paths_layout->addLayout ( plugins_layout );
   
   binary_label = new QLabel ( "..." );
   binary_label->setFixedWidth ( Base::LabelWidth );
   binary_label->setWordWrap ( true );
   binary_line = new QLineEdit ();
   binary_line->setFixedWidth ( Base::LineWidth );
   binary_layout->addWidget ( binary_label );
   binary_layout->addStretch ();
   binary_layout->addWidget ( binary_line );
   
   library_label = new QLabel ( "..." );
   library_label->setFixedWidth ( Base::LabelWidth );
   library_label->setWordWrap ( true );
   library_line = new QLineEdit ();
   library_line->setFixedWidth ( Base::LineWidth );
   library_layout->addWidget ( library_label );
   library_layout->addStretch ();
   library_layout->addWidget ( library_line );
   
   plugins_label = new QLabel ( "..." );
   plugins_label->setFixedWidth ( Base::LabelWidth );
   plugins_label->setWordWrap ( true );
   plugins_line = new QLineEdit ();
   plugins_line->setFixedWidth ( Base::LineWidth );
   plugins_layout->addWidget ( plugins_label );
   plugins_layout->addStretch ();
   plugins_layout->addWidget ( plugins_line );
   
   binary_line->setText  ( shared_components->config ()->operator[] ( Base::KeyCfgCorePathsMednafen ) );
   library_line->setText ( shared_components->config ()->operator[] ( Base::KeyCfgCorePathsLibrary ) );
   plugins_line->setText ( shared_components->config ()->operator[] ( Base::KeyCfgCorePathsPlugins ) );
   
   return;
}

void Gui::SystemPanel::buildShortcutsSection ( void )
{
   shortcuts_group = new QGroupBox ();
   main_layout->addWidget ( shortcuts_group );
   
   shortcuts_layout = new QVBoxLayout ();
   shortcuts_group->setLayout ( shortcuts_layout );
   
   openrom_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( openrom_layout );
   opendisc_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( opendisc_layout );
   openabout_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( openabout_layout );
   openinstances_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( openinstances_layout );
   openconfig_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( openconfig_layout );
   openlibrary_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( openlibrary_layout );
   openmanual_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( openmanual_layout );
   exit_layout = new QHBoxLayout ();
   shortcuts_layout->addLayout ( exit_layout );
   
   openrom_label = new QLabel ( "..." );
   openrom_label->setFixedWidth ( Base::LabelWidth );
   openrom_label->setWordWrap ( true );
   openrom_line = new QLineEdit ();
   openrom_line->setFixedWidth ( Base::LineWidth );
   openrom_layout->addWidget ( openrom_label );
   openrom_layout->addStretch ();
   openrom_layout->addWidget ( openrom_line );
   
   opendisc_label = new QLabel ( "..." );
   opendisc_label->setFixedWidth ( Base::LabelWidth );
   opendisc_label->setWordWrap ( true );
   opendisc_line = new QLineEdit ();
   opendisc_line->setFixedWidth ( Base::LineWidth );
   opendisc_layout->addWidget ( opendisc_label );
   opendisc_layout->addStretch ();
   opendisc_layout->addWidget ( opendisc_line );
   
   openabout_label = new QLabel ( "..." );
   openabout_label->setFixedWidth ( Base::LabelWidth );
   openabout_label->setWordWrap ( true );
   openabout_line = new QLineEdit ();
   openabout_line->setFixedWidth ( Base::LineWidth );
   openabout_layout->addWidget ( openabout_label );
   openabout_layout->addStretch ();
   openabout_layout->addWidget ( openabout_line );
   
   openinstances_label = new QLabel ( "..." );
   openinstances_label->setFixedWidth ( Base::LabelWidth );
   openinstances_label->setWordWrap ( true );
   openinstances_line = new QLineEdit ();
   openinstances_line->setFixedWidth ( Base::LineWidth );
   openinstances_layout->addWidget ( openinstances_label );
   openinstances_layout->addStretch ();
   openinstances_layout->addWidget ( openinstances_line );
   
   openconfig_label = new QLabel ( "..." );
   openconfig_label->setFixedWidth ( Base::LabelWidth );
   openconfig_label->setWordWrap ( true );
   openconfig_line = new QLineEdit ();
   openconfig_line->setFixedWidth ( Base::LineWidth );
   openconfig_layout->addWidget ( openconfig_label );
   openconfig_layout->addStretch ();
   openconfig_layout->addWidget ( openconfig_line );
   
   openlibrary_label = new QLabel ( "..." );
   openlibrary_label->setFixedWidth ( Base::LabelWidth );
   openlibrary_label->setWordWrap ( true );
   openlibrary_line = new QLineEdit ();
   openlibrary_line->setFixedWidth ( Base::LineWidth );
   openlibrary_layout->addWidget ( openlibrary_label );
   openlibrary_layout->addStretch ();
   openlibrary_layout->addWidget ( openlibrary_line );
   
   openmanual_label = new QLabel ( "..." );
   openmanual_label->setFixedWidth ( Base::LabelWidth );
   openmanual_label->setWordWrap ( true );
   openmanual_line = new QLineEdit ();
   openmanual_line->setFixedWidth ( Base::LineWidth );
   openmanual_layout->addWidget ( openmanual_label );
   openmanual_layout->addStretch ();
   openmanual_layout->addWidget ( openmanual_line );
   
   exit_label = new QLabel ( "..." );
   exit_label->setFixedWidth ( Base::LabelWidth );
   exit_label->setWordWrap ( true );
   exit_line = new QLineEdit ();
   exit_line->setFixedWidth ( Base::LineWidth );
   exit_layout->addWidget ( exit_label );
   exit_layout->addStretch ();
   exit_layout->addWidget ( exit_line );
   
   openrom_line->setText       ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutOpenRom ) );
   opendisc_line->setText      ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutOpenGameDisc ) );
   openabout_line->setText     ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutAbout ) );
   openinstances_line->setText ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutInstanceManager ) );
   openconfig_line->setText    ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutConfig ) );
   openlibrary_line->setText   ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutLibrary ) );
   openmanual_line->setText   ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutManual ) );
   exit_line->setText          ( shared_components->config ()->operator[] ( Base::KeyCfgGuiShortcutExit ) );
   
   return;
}

void Gui::SystemPanel::languageChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiLanguage , language_combo->currentText ().toLower () );
   
   return;
}

void Gui::SystemPanel::formatChanged ( void )
{
   QString format;
   
   if ( mednafen_format_combo->currentText () == "ROM OPTIONS" )
      format = "rom_options";
   else
      format = "options_rom";
      
   shared_components->config ()->set ( Base::KeyCfgCoreCommandOrder , format );
   
   return;
}

void Gui::SystemPanel::versionChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgCoreRunVersion , mednafen_version_combo->currentText () );
   
   return;
}

void Gui::SystemPanel::binaryChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgCorePathsMednafen , binary_line->text () );
   
   return;
}

void Gui::SystemPanel::libraryChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgCorePathsLibrary , library_line->text () );
   
   return;
}

void Gui::SystemPanel::pluginsChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgCorePathsPlugins , plugins_line->text () );
   
   return;
}

void Gui::SystemPanel::exitChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutExit , exit_line->text () );
   
   return;
}

void Gui::SystemPanel::openAboutChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutAbout , openabout_line->text () );
   
   return;
}

void Gui::SystemPanel::openConfigChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutConfig , openconfig_line->text () );
   
   return;
}

void Gui::SystemPanel::openDiscChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutOpenGameDisc , opendisc_line->text () );
   
   return;
}

void Gui::SystemPanel::openInstancesChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutInstanceManager , openinstances_line->text () );
   
   return;
}

void Gui::SystemPanel::openLibraryChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutLibrary , openlibrary_line->text () );
   
   return;
}

void Gui::SystemPanel::openManualChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutManual , openmanual_line->text () );
   
   return;
}

void Gui::SystemPanel::openRomChanged ( void )
{
   shared_components->config ()->set ( Base::KeyCfgGuiShortcutOpenRom , openrom_line->text () );
   
   return;
}
