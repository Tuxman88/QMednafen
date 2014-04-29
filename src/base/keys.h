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

   /*
   * Keys about text. (there are just keys, the values are controlled in other place, in the "Text" class).
   */

   const QString KeyTxtProgramName = "txt.program.name";
   const QString KeyTxtProgramVersion = "txt.program.version";
   const QString KeyTxtGuiMenuFile = "txt.gui.menu.file";
   const QString KeyTxtGuiMenuFileOpenRom = "txt.gui.menu.file.openrom";
   const QString KeyTxtGuiMenuFileOpenGameDisc = "txt.gui.menu.file.opengamedisc";
   const QString KeyTxtGuiMenuFileExit = "txt.gui.menu.file.exit";
   const QString KeyTxtGuiMenuConfig = "txt.gui.menu.config";
   const QString KeyTxtGuiMenuConfigConfig = "txt.gui.menu.config.config";
   const QString KeyTxtGuiMenuHelp = "txt.gui.menu.help";
   const QString KeyTxtGuiMenuHelpAbout = "txt.gui.menu.help.about";
   const QString KeyTxtGuiMainVersion = "txt.gui.main.version";
   const QString KeyTxtGuiMainDescription = "txt.gui.main.description";
   const QString KeyTxtGuiMainGroupName = "txt.gui.main.groupname";
   const QString KeyTxtGuiMainOpenRom = "txt.gui.main.openrom";
   const QString KeyTxtGuiMainOpenGameDisc = "txt.gui.main.opengamedisc";
   const QString KeyTxtGuiMainConfig = "txt.gui.main.config";
   const QString KeyTxtGuiMainOpenRomDescription = "txt.gui.main.openromdescription";
   const QString KeyTxtGuiMainOpenGameDiscDescription = "txt.gui.main.opengamediscdescription";
   const QString KeyTxtGuiMainConfigDescription = "txt.gui.main.configdescription";
   const QString KeyTxtGuiMainAbout = "txt.gui.main.about";
   const QString KeyTxtGuiMainExit = "txt.gui.main.exit";
}

# endif
 