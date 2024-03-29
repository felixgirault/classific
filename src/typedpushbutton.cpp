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

#include <QVariant>
#include <QStyle>

#include "typedpushbutton.h"



/**
 *
 */

TypedPushButton::TypedPushButton( QWidget* parent ) :
	QPushButton( parent )
{ }



/**
 *
 */

TypedPushButton::TypedPushButton( const QString& text, QWidget* parent ) :
	QPushButton( text, parent )
{ }



/**
 *
 */

TypedPushButton::TypedPushButton(
	const QString& text,
	Type type,
	QWidget* parent
) :
	QPushButton( text, parent )
{
	setProperty( "type", QVariant( type ));
}



/**
 *
 */

TypedPushButton::Type TypedPushButton::type( ) const
{
	return __type;
}



/**
 *
 */

void TypedPushButton::setType( Type type )
{
	__type = type;
}



/**
 *
 */

void TypedPushButton::setProperty( const char* name, const QVariant& value )
{
	QPushButton::setProperty( name, value );

	style( )->unpolish( this );
	style( )->polish( this );
}
