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

# ifndef KEYS_H_
# define KEYS_H_

# include <QtCore/QString>

namespace Base
{
   /*
   * Keys about program configuration.
   */

   const QString KeyCfgGuiLanguage = "cfg.gui.language";
   const QString ValCfgGuiLanguage = "english";
   
   const QString KeyCfgGuiShortcutOpenRom = "cfg.gui.shortcut.openrom";
   const QString ValCfgGuiShortcutOpenRom = "Ctrl+O";
   
   const QString KeyCfgGuiShortcutOpenGameDisc = "cfg.gui.shortcut.opengamedisc";
   const QString ValCfgGuiShortcutOpenGameDisc = "Ctrl+D";
   
   const QString KeyCfgGuiShortcutLibrary = "cfg.gui.shortcut.library";
   const QString ValCfgGuiShortcutLibrary = "Ctrl+L";
   
   const QString KeyCfgGuiShortcutExit = "cfg.gui.shortcut.exit";
   const QString ValCfgGuiShortcutExit = "Ctrl+X";
   
   const QString KeyCfgGuiShortcutConfig = "cfg.gui.shortcut.config";
   const QString ValCfgGuiShortcutConfig = "Ctrl+C";
   
   const QString KeyCfgGuiShortcutAbout = "cfg.gui.shortcut.about";
   const QString ValCfgGuiShortcutAbout = "Ctrl+A";
   
   const QString KeyCfgCorePathsPlugins = "cfg.core.plugins.paths";
   const QString ValCfgCorePathsPlugins = "/";
   
   const QString KeyCfgCorePathsMednafen = "cfg.core.mednafen.path";
   const QString ValCfgCorePathsMednafen = "/usr/bin/mednafen";

   /*
   * Keys about text. (there are just keys, the values are controlled in other place, in the "Text" class).
   */

   const QString KeyTxtProgramName    = "txt.program.name";
   const QString KeyTxtProgramVersion = "txt.program.version";
   
   const QString KeyTxtGuiMenuFile             = "txt.gui.menu.file";
   const QString KeyTxtGuiMenuFileOpenRom      = "txt.gui.menu.file.openrom";
   const QString KeyTxtGuiMenuFileOpenGameDisc = "txt.gui.menu.file.opengamedisc";
   const QString KeyTxtGuiMenuFileLibrary      = "txt.gui.menu.file.library";
   const QString KeyTxtGuiMenuFileExit         = "txt.gui.menu.file.exit";
   const QString KeyTxtGuiMenuConfig           = "txt.gui.menu.config";
   const QString KeyTxtGuiMenuConfigConfig     = "txt.gui.menu.config.config";
   const QString KeyTxtGuiMenuHelp             = "txt.gui.menu.help";
   const QString KeyTxtGuiMenuHelpAbout        = "txt.gui.menu.help.about";
   
   const QString KeyTxtGuiMainVersion                 = "txt.gui.main.version";
   const QString KeyTxtGuiMainDescription             = "txt.gui.main.description";
   const QString KeyTxtGuiMainGroupName               = "txt.gui.main.groupname";
   const QString KeyTxtGuiMainOpenRom                 = "txt.gui.main.openrom";
   const QString KeyTxtGuiMainOpenGameDisc            = "txt.gui.main.opengamedisc";
   const QString KeyTxtGuiMainConfig                  = "txt.gui.main.config";
   const QString KeyTxtGuiMainOpenRomDescription      = "txt.gui.main.openromdescription";
   const QString KeyTxtGuiMainOpenGameDiscDescription = "txt.gui.main.opengamediscdescription";
   const QString KeyTxtGuiMainConfigDescription       = "txt.gui.main.configdescription";
   const QString KeyTxtGuiMainAbout                   = "txt.gui.main.about";
   const QString KeyTxtGuiMainExit                    = "txt.gui.main.exit";
   const QString KeyTxtGuiMainLibrary                 = "txt.gui.main.library";
   const QString KeyTxtGuiMainLibraryDescription      = "txt.gui.main.librarydescription";
   
   const QString KeyTxtGuiConfigSystemConfig          = "txt.gui.config.systemconfig";
   const QString KeyTxtGuiConfigVideoOptions          = "txt.gui.config.videooptions";
   const QString KeyTxtGuiConfigAudioOptions          = "txt.gui.config.audiooptions";
   const QString KeyTxtGuiConfigControlOptions        = "txt.gui.config.controloptions";
   const QString KeyTxtGuiConfigInGameOptions         = "txt.gui.config.ingameoptions";
   const QString KeyTxtGuiConfigConsoleName           = "txt.gui.config.console.%1";
   const QString KeyTxtGuiConfigConsoleAuthor         = "txt.gui.config.console.author";
   const QString KeyTxtGuiConfigTitle                 = "txt.gui.config.title";
   const QString KeyTxtGuiConfigSave                  = "txt.gui.config.save";
   const QString KeyTxtGuiConfigReload                = "txt.gui.config.reload";
   const QString KeyTxtGuiConfigReset                 = "txt.gui.config.reset";
   const QString KeyTxtGuiConfigConsolePluginVersion  = "txt.gui.config.console.pluginversion";
   
   const QString KeyTxtGuiAboutAboutTitle         = "txt.gui.about.abouttitle";
   const QString KeyTxtGuiAboutAboutTab           = "txt.gui.about.abouttab";
   const QString KeyTxtGuiAboutCreditsTab         = "txt.gui.about.creditstab";
   const QString KeyTxtGuiAboutLicenseTab         = "txt.gui.about.licensetab";
   const QString KeyTxtGuiAboutClose              = "txt.gui.about.close";
   const QString KeyTxtGuiAboutProgramDescription = "txt.gui.about.programdescription";
   const QString KeyTxtGuiAboutAuthorName         = "txt.gui.about.%1.name";
   const QString KeyTxtGuiAboutAuthorLink         = "txt.gui.about.%1.link";
   const QString KeyTxtGuiAboutAuthorDescription  = "txt.gui.about.%1.thanks";
   
   const QString KeyTxtGuiOpenROMSelectFile = "txt.gui.openrom.selectfile";
}

# endif
 
