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
