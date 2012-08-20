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

#include <QDir>
#include <QFile>

#include "njeenapplication.h"



/**
 *
 */

NjeenApplication::NjeenApplication( int& argc, char** argv ) :
	QApplication( argc, argv )
{
	loadTheme( );
}



/**
 *
 */

void NjeenApplication::loadTheme( )
{
	QString theme( "Njeen" );

	QDir dir = QDir::current( );
	dir.cd( "themes" );
	dir.cd( theme );

	QString filePath = dir.filePath( "style.css" );
	QFile file( filePath );

	if ( file.open( QFile::ReadOnly | QFile::Text )) {
		setStyleSheet( file.readAll( ));
		file.close( );
	}
}
