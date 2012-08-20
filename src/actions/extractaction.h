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

#ifndef EXTRACTACTION_H
#define EXTRACTACTION_H

#include "../action.h"

class FormLayout;
class PathEdit;
class QLineEdit;



/**
 *	Extracts archives.
 */

class ExtractAction : public Action
{
	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		ExtractAction( QWidget* parent = 0 );



		/**
		 *	Executes the action.
		 */

		void run( Execution::File& file );

	private:

		FormLayout* __layout;
		PathEdit* __destination;
		QLineEdit* __password;

};

#endif // EXTRACTACTION_H
