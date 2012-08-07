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

#include "actioncollection.h"
#include "actionframe.h"
#include "factory.h"
#include "typedpushbutton.h"
#include "layouts.h"
#include "picker.h"



/**
 *
 */

ActionCollection::ActionCollection( QWidget* parent ) :
	QFrame( parent ),
	__layout( new VBoxLayout( this )),
	__add( new TypedPushButton( tr( "Add action" ), TypedPushButton::Positive, this ))
{
	connect( __add, SIGNAL( clicked( )), this, SLOT( addAction( )));

	__layout->addWidget( __add );

	setLayout( __layout );
}



/**
 *
 */

void ActionCollection::addFrame( Action* action, const QString& name )
{
	ActionFrame* frame = new ActionFrame( action, name );
	connect( frame, SIGNAL( removeMe( )), this, SLOT( removeFrame( )));

	__layout->insertWidget( __layout->count( ) - 1, frame );
}



/**
 *
 */

void ActionCollection::addAction( )
{
	QMap< QString, QString > informations = Factory< Action >::informations( );

	Picker picker( informations, this );
	if ( picker.exec( ) == QDialog::Rejected ) {
		return;
	}

	Action* action = Factory< Action >::create( picker.selected( ));
	if ( action ) {
		addFrame( action, picker.selected( ));
	}
}



/**
 *
 */

void ActionCollection::removeFrame( )
{
	ActionFrame* frame = qobject_cast< ActionFrame* >( sender( ));
	if ( !frame ) {
		return;
	}

	layout( )->removeWidget( frame );
	frame->deleteLater( );
}
