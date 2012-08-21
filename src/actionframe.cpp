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
	__layout( new VBoxLayout( this )),
	__titleBar( new TitleBar( name )),
	__filters( new FilterCollection( ))
{
	connect( __titleBar, SIGNAL( toggled( bool )), __action, SLOT( setHidden( bool )));
	connect( __titleBar, SIGNAL( toggled( bool )), __filters, SLOT( setHidden( bool )));
	connect( __titleBar, SIGNAL( remove( )), this, SIGNAL( removeMe( )));

	__layout->addWidget( __titleBar );
	__layout->addWidget( __action );
	__layout->addWidget( __filters );
}



/**
 *
 */

void ActionFrame::runAction( Environment* environment )
{
	Environment::FileInfoList files = environment->files( );

	__filters->applyFilters( files );
	__action->run( files );
}
