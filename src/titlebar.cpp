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

#include "titlebar.h"
#include "layouts.h"
#include "typedpushbutton.h"



/**
 *
 */

TitleBar::TitleBar( const QString& title, QWidget* parent ) :
	QFrame( parent ),
   __title( new QLabel( title, this )),
   __remove( new TypedPushButton( tr( "x" ), TypedPushButton::Negative, this ))
{
	connect( __remove, SIGNAL( clicked( )), this, SIGNAL( remove( )));

	HBoxLayout* layout = new HBoxLayout( );
	layout->addWidget( __title, 100 );
	layout->addWidget( __remove );

	setLayout( layout );
}
