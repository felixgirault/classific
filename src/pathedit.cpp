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

#include <QFileDialog>

#include "pathedit.h"
#include "layouts.h"
#include "statefullineedit.h"
#include "typedpushbutton.h"



/**
 *
 */

PathEdit::PathEdit( QWidget *parent ) :
	QWidget( parent ),
	__layout( new HBoxLayout( this )),
	__path( new StatefulLineEdit( )),
	__browse( new TypedPushButton( tr( "Browse" ), TypedPushButton::Neutral ))
{
	__path->setText( QDir::currentPath( ));

	connect( __path, SIGNAL( editingFinished( )), this, SLOT( check( )));
	connect( __browse, SIGNAL( clicked( )), this, SLOT( browse( )));

	__layout->addWidget( __path );
	__layout->addWidget( __browse );
}



/**
 *
 */

bool PathEdit::pathExists( ) const
{
	return QDir( path( )).exists( );
}



/**
 *
 */

QString PathEdit::path( ) const
{
	return __path->text( );
}



/**
 *
 */

QDir PathEdit::dir( ) const
{
	return QDir( path( ));
}



/**
 *
 */

void PathEdit::check( ) const
{
	QDir dir( __path->text( ));

	__path->setProperty( "state", dir.exists( ) ? "valid" : "invalid" );
}



/**
 *
 */

void PathEdit::browse( )
{
	QString path = QFileDialog::getExistingDirectory(
		this,
		tr( "Please choose a directory" ),
		__path->text( )
	);

	__path->setText( path );
}
