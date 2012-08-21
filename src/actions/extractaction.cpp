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

#include <QLineEdit>

#include "extractaction.h"
#include "../factory.h"
#include "../layouts.h"
#include "../pathedit.h"



/**
 *
 */

REGISTER_PRODUCT( Action, ExtractAction, "Extract", "Extract archives." )



/**
 *
 */

ExtractAction::ExtractAction( QWidget* parent ) :
	Action( parent ),
	__layout( new FormLayout( this )),
	__destination( new PathEdit( this )),
	__password( new QLineEdit( this ))
{
	__password->setEchoMode( QLineEdit::Password );

	__layout->addRow( tr( "Destination" ), __destination );
	__layout->addRow( tr( "Password" ), __password );
}



/**
 *
 */

void ExtractAction::run( Environment::FileInfo& file )
{
	QString path = file.compilePath( __destination->path( ));

	switch ( file.environment( )->mode( )) {
		case Environment::Explain:
			file.addExplanation( QString( "Will be extracted to '%s'" ).arg( path ));
			break;

		case Environment::Run:
			{
				bool extracted = true;

				if ( extracted ) {
					file.addExplanation( QString( "Has been extracted to '%s'" ).arg( path ));
				} else {
					file.addError( QString( "Couldn't be extracted to '%s'" ).arg( path ));
				}
			}
			break;
	}
}
