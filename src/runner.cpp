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

#include <QTableWidget>
#include <QStringListModel>

#include "runner.h"
#include "layouts.h"
#include "pathedit.h"
#include "typedpushbutton.h"



/**
 *
 */

Runner::Runner( QWidget* parent ) :
	QFrame( parent ),
	__layout( new FormLayout( this )),
	__path( new PathEdit( )),
	__explain( new TypedPushButton( tr( "Explain" ), TypedPushButton::Neutral )),
	__run( new TypedPushButton( tr( "Run" ), TypedPushButton::Neutral )),
	__outputView( new QTableView( )),
	__outputModel( new QStringListModel( ))
{
	__outputView->setModel( __outputModel );

	connect( __explain, SIGNAL( clicked( )), this, SLOT( run( )));
	connect( __run, SIGNAL( clicked( )), this, SLOT( run( )));

	HBoxLayout* buttonsLayout = new HBoxLayout( );
	buttonsLayout->addWidget( __explain );
	buttonsLayout->addWidget( __run );

	__layout->addRow( tr( "Working directory" ), __path );
	__layout->addRow( tr( "Execution" ), buttonsLayout );
	__layout->addRow( tr( "Output" ), __outputView );
}



/**
 *
 */

void Runner::report( Environment* environment )
{
	QStringList fileNames;

	foreach ( Environment::FileInfo file, environment->files( )) {
		fileNames.append( file.fileName( ));
	}

	__outputModel->setStringList( fileNames );
}



/**
 *
 */

void Runner::run( )
{
	TypedPushButton* button = qobject_cast< TypedPushButton* >( sender( ));
	Environment::ExecutionMode mode;

	if ( button == __explain ) {
		mode = Environment::Explain;
	/*} else if ( button == __run ) {
		mode = Environment::Run;*/
	} else {
		return;
	}

	Environment* environment = new Environment( mode, __path->dir( ), false );
	emit run( environment );
}
