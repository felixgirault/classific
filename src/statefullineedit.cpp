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

#include <QStyle>

#include "statefullineedit.h"



/**
 *
 */

StatefulLineEdit::StatefulLineEdit( QWidget *parent ) :
	QLineEdit( parent )
{ }



/**
 *
 */

StatefulLineEdit::StatefulLineEdit( State state, QWidget *parent ) :
	QLineEdit( parent )
{
	setProperty( "state", state );
}



/**
 *
 */

StatefulLineEdit::State StatefulLineEdit::state( ) const
{
	return __state;
}



/**
 *
 */

void StatefulLineEdit::setState( State state )
{
	__state = state;
}



/**
 *
 */

void StatefulLineEdit::setProperty( const char* name, const QVariant& value )
{
	QLineEdit::setProperty( name, value );

	style( )->unpolish( this );
	style( )->polish( this );
}
