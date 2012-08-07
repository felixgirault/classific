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

#include "actionframe.h"
#include "action.h"
#include "filtercollection.h"
#include "titlebar.h"
#include "layouts.h"



/**
 *
 */

ActionFrame::ActionFrame( Action* action, const QString& name, QWidget *parent ) :
	QFrame( parent ),
	__action( action ),
	__titleBar( new TitleBar( name, this )),
	__filters( new FilterCollection( this ))
{
	connect( __titleBar, SIGNAL( remove( )), this, SIGNAL( removeMe( )));

	VBoxLayout* layout = new VBoxLayout( );
	layout->addWidget( __titleBar );
	layout->addWidget( __action );
	layout->addWidget( __filters );

	setLayout( layout );
}
