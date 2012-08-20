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

#include "executeaction.h"
#include "../factory.h"



/**
 *
 */

REGISTER_PRODUCT( Action, ExecuteAction, "Execute", "Execute commands." )



/**
 *
 */

ExecuteAction::ExecuteAction( QWidget* parent ) :
	Action( parent )
{

}



/**
 *
 */

void ExecuteAction::run( Execution::File& file )
{
	switch ( file.execution( ).mode( )) {
		case Execution::Explain:

			break;

		case Execution::Run:

			break;
	}
}
