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
}



/**
 *
 */

void FilterCollection::addFrame( Filter* filter, const QString& name )
{
	FilterFrame* frame = new FilterFrame( filter, name );
	connect( frame, SIGNAL( removeMe( )), this, SLOT( removeFrame( )));

	__layout->insertWidget( __layout->count( ) - 1, frame );
}



/**
 *
 */

void FilterCollection::addFilter( )
{
	QMap< QString, QString > informations = Factory< Filter >::informations( );
	QString selected = Picker::pick( informations, this );

	Filter* filter = Factory< Filter >::create( selected );
	if ( filter ) {
		addFrame( filter, selected );
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
