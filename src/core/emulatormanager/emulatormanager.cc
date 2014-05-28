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

# include "emulatormanager.h"

Core::EmulatorManager::EmulatorManager ( Base::SharedComponents* new_shared_components ) 
   : QObject ()
{
   shared_components = new_shared_components;
}

Core::EmulatorManager::~EmulatorManager ( void )
{
   qDebug () << "EmulatorManager: Closing game instances if any.";
   QMapIterator< Core::EmulatorInstance* , Core::EmulatorInstance* > iterator ( game_instances );
   QList< Core::EmulatorInstance* > pointers;
   
   while ( iterator.hasNext () )
   {
      iterator.next ();
      pointers.append ( iterator.key () );
   }
   
   for ( int i = 0; i < pointers.size (); i++ )
   {
      game_instances[ pointers[ i ] ] = 0;
      Core::EmulatorInstance* instance;
      instance = pointers[ i ];
      pointers[ i ] = 0;
      delete instance;
   }
   
   pointers.clear ();
}

void Core::EmulatorManager::addInstance ( const QString& file_path , const Core::EmulatorManager::DetectionType& file_type , const QStringList& options )
{
   qDebug () << "EmulatorManager: Receiving request to add game instance.";
   qDebug () << "                 File: " << file_path;
   qDebug () << "                 Detection type: " << file_type << " (" << detectionTypeString ( file_type ) << ")";
   qDebug () << "                 Game options: " << options.size ();
   
   Core::EmulatorInstance* instance;
   instance = new Core::EmulatorInstance ( shared_components );
   instance->setGame ( file_path , options , (int)file_type );
   
   game_instances[ instance ] = instance;
   connect ( instance , SIGNAL ( closeEmulatorInstance ( Core::EmulatorInstance* ) ) , this , SLOT ( closeEmulatorInstance ( Core::EmulatorInstance* ) ) );
   
   instance->run ();
   
   return;
}

void Core::EmulatorManager::closeEmulatorInstance ( Core::EmulatorInstance* instance )
{
   delete instance;
   game_instances.remove ( instance );
   
   return;
}

QString Core::EmulatorManager::detectionTypeString ( const Core::EmulatorManager::DetectionType& file_type )
{
   QString name;
   
   switch ( file_type )
   {
      case Auto:
         name = "Auto";
         break;
         
      case Lynx:
         name = "Lynx";
         break;
         
      case GB:
         name = "GB";
         break;
         
      case GBA:
         name = "GBA";
         break;
         
      case NeoGeoPocket:
         name = "NeoGeoPocket";
         break;
         
      case NES:
         name = "NES";
         break;
         
      case PCE:
         name = "PCE";
         break;
         
      case PCE_FAST:
         name = "PCE_FAST";
         break;
         
      case PCFX:
         name = "PCFX";
         break;
         
      case GG:
         name = "GG";
         break;
         
      case MD:
         name = "MD";
         break;
         
      case SMS:
         name = "SMS";
         break;
         
      case PSX:
         name = "PSX";
         break;
         
      case SNES:
         name = "SNES";
         break;
         
      case VB:
         name = "VB";
         break;
         
      case WSWAN:
         name = "WSWAN";
         break;
   }
   
   return ( name );
}
