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

# include "pluginsection.h"

Base::PluginSection::PluginSection ( void )
   : QObject ()
{
   section_name = "Section";
   section_options = new QList< Base::PluginOption* > ();
}

Base::PluginSection::~PluginSection ( void )
{
   for ( int i = 0; i < section_options->size (); i++ )   
   {
      delete section_options->operator[] ( i );
   }
   
   section_options->clear ();
   
   delete section_options;
}

QStringList Base::PluginSection::getOptions ( void )
{
   QStringList options;
   
   for ( int i = 0; i < section_options->size (); i++ )
   {
      options << section_options->operator[] ( i )->toString ();
   }
   
   return ( options );
}

QString Base::PluginSection::name ( void )
{
   return ( section_name );
}

void Base::PluginSection::setName ( const QString& new_name )
{
   section_name = new_name.split ( "=" )[ 1 ];
   
   return;
}

QList< Base::PluginOption* >* Base::PluginSection::options ( void )
{
   return ( section_options );
}

void Base::PluginSection::autoLoad ( QMap< QString , QString >& values )
{
   // Iterate over the options, ask them their command names and check in the QMap if there is a value for them.
   for ( int i = 0; i < section_options->size (); i++ )
   {
      section_options->operator[] ( i )->autoLoad ( values );
   }
   
   return;
}

QTextStream& operator<< ( QTextStream& output_file , Base::PluginSection* plugin_section )
{
   for ( int i = 0; i < plugin_section->section_options->size (); i++ )
   {
      output_file << plugin_section->section_options->operator[] ( i );
   }
   
   return ( output_file );
}

QFile& operator>> ( QFile& input_file , Base::PluginSection& plugin_section )
{
   QString line;
   
   while ( line != "endsection" )
   {
      line = input_file.readLine ();
      line = line.simplified ();
      
      if ( line != "endsection" && line.size () > 0 )
      {
         QStringList pieces;
         QString command_options;
         QStringList command_info;
         
         pieces = line.split ( "=" );
         
         command_options = pieces[ 0 ].simplified ();
         command_options = command_options.toLower ();
         
         command_info = pieces[ 1 ].split ( "|" );
         
         // Check the type of the option
         Base::PluginOption* new_option;
         
         if ( command_info[ 1 ] == "integer" )
         {
            new_option = new Base::OptionInteger ( command_options , command_info );
         }
         else if ( command_info[ 1 ] == "real" )
         {
            new_option = new Base::OptionReal ( command_options , command_info );
         }
         else if ( command_info[ 1 ] == "enum" )
         {
            new_option = new Base::OptionEnum ( command_options , command_info );
         }
         else if ( command_info[ 1 ] == "bi-real" )
         {
            new_option = new Base::OptionBiReal ( command_options , command_info );
         }
         else if ( command_info[ 1 ] == "bi-integer" )
         {
            new_option = new Base::OptionBiInteger ( command_options , command_info );
         }
         else if ( command_info[ 1 ] == "boolean" )
         {
            new_option = new Base::OptionBoolean ( command_options , command_info );
         }
         else if ( command_info[ 1 ] == "enum" )
         {
            new_option = new Base::OptionEnum ( command_options , command_info );
         }
         
         plugin_section.section_options->append ( new_option );
      }
   }
   
   return ( input_file );
}