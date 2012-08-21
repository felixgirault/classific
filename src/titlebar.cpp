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

#include <QProgressBar>
#include <QLabel>

#include "titlebar.h"
#include "layouts.h"
#include "typedpushbutton.h"



/**
 *
 */

TitleBar::TitleBar( const QString& title, bool hasProgress, QWidget* parent ) :
	QFrame( parent ),
	__layout( new HBoxLayout( this )),
	__progress( 0 ),
	__title( new QLabel( title )),
	__toggle( new TypedPushButton( tr( "-" ), TypedPushButton::Neutral )),
	__remove( new TypedPushButton( tr( "x" ), TypedPushButton::Negative ))
{
	connect( __toggle, SIGNAL( toggled( bool )), this, SIGNAL( toggled( bool )));
	connect( __toggle, SIGNAL( toggled( bool )), this, SLOT( toggle( bool )));
	connect( __remove, SIGNAL( clicked( )), this, SIGNAL( remove( )));

	if ( hasProgress ) {
		__progress = new QProgressBar( );
		__progress->setTextVisible( false );
		__progress->setRange( 0, 0 );

		__title->setParent( __progress );
		__layout->addWidget( __progress, 100 );
	} else {
		__layout->addWidget( __title, 100 );
	}

	__toggle->setCheckable( true );

	__layout->addWidget( __toggle );
	__layout->addWidget( __remove );
}



/**
 *
 */

void TitleBar::setMaximumProgress( int maximum )
{
	if ( __progress ) {
		__progress->setMaximum( maximum );
	}
}



/**
 *
 */

void TitleBar::progress( )
{
	if ( __progress ) {
		__progress->setValue( __progress->value( ) + 1 );
	}
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
