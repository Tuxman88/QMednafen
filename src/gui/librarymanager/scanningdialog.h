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

# ifndef SCANNINGDIALOG_H_
# define SCANNINGDIALOG_H_

# include <QtWidgets/QDialog>
# include <QtWidgets/QVBoxLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QPushButton>
# include <QtWidgets/QLabel>

# include "../../base/base.h"

namespace Gui
{
   class ScanningDialog : public QDialog
   {
      Q_OBJECT 
      
      public:
         explicit ScanningDialog ( Base::SharedComponents* new_shared_components );
         virtual ~ScanningDialog ( void );
         
      signals:
         void cancelScan ( void );
         
      public slots:
         void scanningFolder ( const QString& folder_name );
         
      private slots:
         void updateText ( void );
         
      private:
         void buildGui ( void );
         void connectAll ( void );
         
      private:
         Base::SharedComponents* shared_components;
         QVBoxLayout* main_layout;
         QHBoxLayout* buttons_layout;
         QLabel* scanning_label;
         QPushButton* cancel_button;
   };
}

# endif
