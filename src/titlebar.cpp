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

#include <QLabel>

#include "titlebar.h"
#include "layouts.h"
#include "typedpushbutton.h"



/**
 *
 */

TitleBar::TitleBar( const QString& title, QWidget* parent ) :
	QFrame( parent ),
	__title( new QLabel( title, this )),
	__toggle( new TypedPushButton( tr( "-" ), TypedPushButton::Neutral )),
	__remove( new TypedPushButton( tr( "x" ), TypedPushButton::Negative ))
{
	connect( __toggle, SIGNAL( toggled( bool )), this, SIGNAL( toggled( bool )));
	connect( __toggle, SIGNAL( toggled( bool )), this, SLOT( toggle( bool )));
	connect( __remove, SIGNAL( clicked( )), this, SIGNAL( remove( )));

	__toggle->setCheckable( true );

	HBoxLayout* layout = new HBoxLayout( this );
	layout->addWidget( __title, 100 );
	layout->addWidget( __toggle );
	layout->addWidget( __remove );
}



/**
 *
 */

void TitleBar::toggle( bool toggle )
{
	if ( toggle ) {
		__toggle->setText( tr( "+" ));
	} else {
		__toggle->setText( tr( "-" ));
	}
}
