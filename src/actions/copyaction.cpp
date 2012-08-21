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

#include "copyaction.h"
#include "../layouts.h"
#include "../pathedit.h"
#include "../factory.h"



/**
 *
 */

REGISTER_PRODUCT( Action, CopyAction, "Copy", "Copies files." )



/**
 *
 */

CopyAction::CopyAction( QWidget* parent ) :
	Action( parent ),
	__layout( new FormLayout( this )),
	__destination( new PathEdit( this ))
{
	__layout->addRow( tr( "Destination" ), __destination );
}



/**
 *
 */

void CopyAction::run( Environment::FileInfo& file )
{
	QString path = file.compilePath( __destination->path( ));

	switch ( file.environment( )->mode( )) {
		case Environment::Explain:
			file.addExplanation( QString( "Will be copied to '%s'" ).arg( path ));
			break;

		case Environment::Run:
			{
				bool copied = QFile::copy(
					file.canonicalFilePath( ),
					QDir( path ).filePath( file.fileName( ))
				);

				if ( copied ) {
					file.addExplanation( QString( "Has been copied to '%s'" ).arg( path ));
				} else {
					file.addError( QString( "Couldn't be copied to '%s'" ).arg( path ));
				}
			}
			break;
	}
}
