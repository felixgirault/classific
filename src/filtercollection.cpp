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

#include "filtercollection.h"
#include "filterframe.h"
#include "factory.h"
#include "typedpushbutton.h"
#include "layouts.h"
#include "picker.h"



/**
 *
 */

FilterCollection::FilterCollection( QWidget* parent ) :
	QFrame( parent ),
	__layout( new VBoxLayout( this )),
	__add( new TypedPushButton( tr( "Add filter" ), TypedPushButton::Positive, this ))
{
	connect( __add, SIGNAL( clicked( )), this, SLOT( addFilter( )));

	__layout->addWidget( __add );
	setLayout( __layout );
}



/**
 *
 */

void FilterCollection::addFrame( const QString& name, Filter* filter )
{
	FilterFrame* frame = new FilterFrame( name, filter );
	connect( frame, SIGNAL( removeMe( )), this, SLOT( removeFrame( )));

	__layout->insertWidget( __layout->count( ) - 1, frame );
}



/**
 *
 */

void FilterCollection::addFilter( )
{
	QMap< QString, QString > informations = Factory< Filter >::informations( );

	Picker picker( informations, this );
	if ( picker.exec( ) == QDialog::Rejected ) {
		return;
	}

	Filter* filter = Factory< Filter >::create( picker.selected( ));
	if ( filter ) {
		addFrame( picker.selected( ), filter );
	}
}



/**
 *
 */

void FilterCollection::removeFrame( )
{
	FilterFrame* frame = qobject_cast< FilterFrame* >( sender( ));
	if ( !frame ) {
		return;
	}

	layout( )->removeWidget( frame );
	frame->deleteLater( );
}