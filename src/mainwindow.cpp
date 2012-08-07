/**
 *	Njeen - Files processing made easy.
 *	Copyright (C) 2012 Félix Girault
 *
 *	This program is free software: you can redistribute it and/or modify it
 *	under the terms of the GNU General Public License as published by the Free
 *	Software Foundation, either version 3 of the License, or (at your option)
 *	any later version.
 *
 *	This program is distributed in the hope that it will be useful, but WITHOUT
 *	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *	FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *	more details.
 *
 *	You should have received a copy of the GNU General Public License along
 *	with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include <QKeyEvent>
#include <QDir>
#include <QFile>

#include "mainwindow.h"
#include "actioncollection.h"



/**
 *
 */

MainWindow::MainWindow( QWidget* parent ) :
	QMainWindow( parent ),
	__actions( new ActionCollection( this ))
{
	setCentralWidget( __actions );
	resize( 400, 0 );

	loadTheme( );
}



/**
 *
 */

void MainWindow::keyPressEvent( QKeyEvent* event )
{
	if ( event->key( ) == Qt::Key_F5 ) {
		loadTheme( );
	}
}



/**
 *
 */

void MainWindow::loadTheme( )
{
	QString theme( "njeen" );
	QDir dir = QDir::current( );
	dir.cd( "themes" );

	QString filePath = dir.filePath( QString( "%1.css" ).arg( theme ));
	QFile file( filePath );

	if ( file.open( QFile::ReadOnly | QFile::Text )) {
		qApp->setStyleSheet( file.readAll( ));
		file.close( );
	}
}
