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

# include "scanningdialog.h"

Gui::ScanningDialog::ScanningDialog ( Base::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   
   buildGui ();
   connectAll ();
   updateText ();
}

Gui::ScanningDialog::~ScanningDialog ( void )
{
}

void Gui::ScanningDialog::scanningFolder ( const QString& folder_name )
{
   scanning_label->setText ( QString ( "%1: %2" ).arg ( shared_components->text ()->operator[] ( Base::KeyTxtGuiScanningDialogScanning ) ).arg ( folder_name ) );
   
   return;
}

void Gui::ScanningDialog::buildGui ( void )
{
   main_layout = new QVBoxLayout ( this );
   setLayout ( main_layout );
   
   buttons_layout = new QHBoxLayout ();
   
   scanning_label = new QLabel ( "...: ..." );
   scanning_label->setWordWrap ( true );
   main_layout->addWidget ( scanning_label );
   
   cancel_button = new QPushButton ( "..." );
   main_layout->addLayout ( buttons_layout );
   buttons_layout->addWidget ( cancel_button );
   
   QPixmap program_icon ( ":/icon-main-16" );
   setWindowIcon ( QIcon ( program_icon ) );
   
   return;
}

void Gui::ScanningDialog::connectAll ( void )
{
   connect ( cancel_button              , SIGNAL ( clicked ( bool ) ) , this , SIGNAL ( cancelScan () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () )    , this , SLOT   ( updateText () ) );
   
   return;
}

void Gui::ScanningDialog::updateText ( void )
{
   scanning_label->setText ( QString ( "%1: ..." ).arg ( shared_components->text ()->operator[] ( Base::KeyTxtGuiScanningDialogScanning ) ) );
   cancel_button->setText ( shared_components->text ()->operator[] ( Base::KeyTxtGuiScanningDialogCancelScan ) );
   setWindowTitle ( shared_components->text ()->operator[] ( Base::KeyTxtGuiScanningDialogTitle ) );
    
   return;
}
