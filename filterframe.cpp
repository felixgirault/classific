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

#include <QLabel>

#include "filterframe.h"
#include "filter.h"
#include "layouts.h"
#include "typedpushbutton.h"



/**
 *
 */

FilterFrame::FilterFrame( const QString& name, Filter* filter, QWidget *parent ) :
	QFrame( parent ),
	__filter( filter ),
	__name( new QLabel( name, this )),
	__remove( new TypedPushButton( tr( "x" ), TypedPushButton::Negative, this ))
{
	connect( __remove, SIGNAL( clicked( )), this, SIGNAL( removeMe( )));

	VBoxLayout* layout = new VBoxLayout( );

	HBoxLayout* barLayout = new HBoxLayout( );
	barLayout->addWidget( __name, 100 );
	barLayout->addWidget( __remove );

	layout->addLayout( barLayout );
	layout->addWidget( __filter );

	setLayout( layout );
}
