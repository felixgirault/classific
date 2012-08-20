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

#include <QVBoxLayout>
#include <QPushButton>
#include <QCommandLinkButton>

#include "picker.h"



/**
 *
 */

Picker::Picker( const QMap< QString, QString >& items, QWidget* parent ) :
	QDialog( parent )
{
	QVBoxLayout* layout = new QVBoxLayout( this );
	QMapIterator< QString, QString > it( items );

	while ( it.hasNext( )) {
		it.next( );

		QCommandLinkButton* button = new QCommandLinkButton( it.key( ), it.value( ));
		connect( button, SIGNAL( clicked( )), this, SLOT( accept( )));

		layout->addWidget( button );
	}

	QPushButton* cancel = new QPushButton( tr( "Cancel" ));
	connect( cancel, SIGNAL( clicked( )), this, SLOT( reject( )));

	layout->addWidget( cancel );
}



/**
 *
 */

QString Picker::selected( ) const
{
	return __selected;
}



/**
 *
 */

QString Picker::pick( const QMap< QString, QString >& informations, QWidget* parent )
{
	Picker picker( informations, parent );
	picker.exec( );

	return picker.selected( );
}



/**
 *
 */

void Picker::accept( )
{
	QCommandLinkButton* button = qobject_cast< QCommandLinkButton* >( sender( ));
	if ( !button ) {
		return;
	}

	__selected = button->text( );
	QDialog::accept( );
}
