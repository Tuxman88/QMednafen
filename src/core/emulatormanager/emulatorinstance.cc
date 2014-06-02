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

# include "emulatorinstance.h"

Core::EmulatorInstance::EmulatorInstance ( Base::SharedComponents* new_shared_components )
   : QObject ()
{
   shared_components = new_shared_components;
   
   connect ( &emulator_process , SIGNAL ( error ( QProcess::ProcessError ) ) , this , SLOT ( commandError () ) );
   connect ( &emulator_process , SIGNAL ( finished ( int ) ) , this , SLOT ( commandFinished () ) );
   
   stop_signals = false;
}

Core::EmulatorInstance::~EmulatorInstance ( void )
{   
   stop_signals = true;
   qDebug () << "EmulatorInstance: Closing game instance: " << file_path;
   emulator_process.close ();
}

void Core::EmulatorInstance::run ( void )
{
   qDebug () << "EmulatorInstance: Starting game: " << file_path;
   
   QStringList complete_options;
   
   // Check in wich order I must add the options
   // ¿rom_options? ¿options_rom?
   if ( shared_components->config ()->operator[] ( Base::KeyCfgCoreCommandOrder ).toLower () == "rom_options" )
   {
      qDebug () << "EmulatorInstance: Running in ROM>OPTIONS mode.";
      complete_options << file_path << game_options;
   }
   else
   {
      qDebug () << "EmulatorInstance: Running in OPTIONS>ROM mode.";
      complete_options << game_options << file_path;
   }
   
   qDebug () << "EmulatorInstance: Running: " << shared_components->config ()->operator[] ( Base::KeyCfgCorePathsMednafen ) << " " << complete_options;
   
   emulator_process.start ( shared_components->config ()->operator[] ( Base::KeyCfgCorePathsMednafen ) , complete_options );
   
   
   return;
}

void Core::EmulatorInstance::setGame ( const QString& new_file_name , const QStringList& new_game_options , const int& new_game_type )
{
   file_path = new_file_name;
   game_options = new_game_options;
   game_type = new_game_type;
   
   return;
}

void Core::EmulatorInstance::commandError ( void )
{
   if ( !stop_signals )
   {
      qDebug () << "EmulatorInstance: Error launching game.";
      emit closeEmulatorInstance ( this );
   }
   
   return;
}

void Core::EmulatorInstance::commandFinished ( void )
{
   if ( !stop_signals )
   {
      qDebug () << "EmulatorInstance: Game closed.";
      emit closeEmulatorInstance ( this );
   }
   
   return;
}

QString Core::EmulatorInstance::gameName ( void )
{
   QStringList file_pieces = file_path.split ( QDir::separator () );
   
   return ( file_pieces[ file_pieces.size () - 1 ] );
}

int Core::EmulatorInstance::gameType ( void )
{
   return ( game_type );
}
