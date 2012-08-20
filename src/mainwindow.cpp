/**
 *	Copyright (C) 2012 Félix Girault
 *
 *	This file is part of Njeen.
 *
 *	Njeen is free software: you can redistribute it and/or modify it under the
 *	terms of the GNU General Public License as published by the Free Software
 *	Foundation, either version 3 of the License, or (at your option) any later
 *	version.
 *
 *	This program is distributed in the hope that it will be useful, but WITHOUT
 *	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *	FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *	more details.
 *
 *	You should have received a copy of the GNU General Public License along
 *	with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QLayout>
#include <QKeyEvent>

#include "mainwindow.h"
#include "layouts.h"
#include "actioncollection.h"
#include "runner.h"
#include "njeenapplication.h"



/**
 *
 */

MainWindow::MainWindow( QWidget* parent ) :
	QMainWindow( parent ),
	__layout( new VBoxLayout( )),
	__actions( new ActionCollection( )),
	__runner( new Runner( ))
{
	connect(
		__runner, SIGNAL( run( Execution& )),
		__actions, SLOT( runActions( Execution& ))
	);

	__layout->addWidget( __actions );
	__layout->setAlignment( __actions, Qt::AlignHCenter );

	__layout->addWidget( __runner );

	QWidget* centralWidget = new QWidget( );
	centralWidget->setLayout( __layout );

	setCentralWidget( centralWidget );
	resize( 600, 0 );
}



/**
 *
 */

void MainWindow::keyPressEvent( QKeyEvent* event )
{
	if ( event->key( ) == Qt::Key_F5 ) {
		NjeenApplication* application = qobject_cast< NjeenApplication* >( qApp );
		application->loadTheme( );
	}
}
