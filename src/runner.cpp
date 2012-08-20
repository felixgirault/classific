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
	__run( new TypedPushButton( tr( "Run" ), TypedPushButton::Neutral ))
{
	HBoxLayout* buttonsLayout = new HBoxLayout( );
	buttonsLayout->addWidget( __explain );
	buttonsLayout->addWidget( __run );

	__layout->addRow( tr( "Working directory" ), __path );
	__layout->addRow( tr( "Execution" ), buttonsLayout );
}



/**
 *
 */

void Runner::run( )
{
	TypedPushButton* button = qobject_cast< TypedPushButton* >( sender( ));
	Execution::Mode mode;

	if ( button == __explain ) {
		mode = Execution::Explain;
	} else if ( button == __run ) {
		mode = Execution::Run;
	} else {
		return;
	}

	Execution* execution = new Execution( mode, __path->dir( ), false );
	emit run( *execution );
}
