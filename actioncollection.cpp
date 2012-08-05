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

#include <QVBoxLayout>
#include <QPushButton>

#include "actioncollection.h"
#include "factory.h"



ActionCollection::ActionCollection( QWidget* parent ) :
	QFrame( parent ),
	__layout( new QVBoxLayout( this )),
	__add( new QPushButton( tr( "Add" ), this ))
{
	connect( __add, SIGNAL( clicked( )), this, SLOT( addAction( )));

	__layout->addWidget( __add );

	setLayout( __layout );
}



void ActionCollection::addAction( )
{
	QMap< QString, QString > informations = Factory< Action >::informations( );
}



void ActionCollection::removeAction( )
{

}