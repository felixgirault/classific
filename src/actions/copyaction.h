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

#ifndef COPYACTION_H
#define COPYACTION_H

#include "../action.h"

class FormLayout;
class PathEdit;



/**
 *	Copies files.
 */

class CopyAction : public Action
{
	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		CopyAction( QWidget* parent = 0 );

	protected:

		/**
		 *	Executes the action.
		 */

		void run( Environment::FileInfo& file );

	private:

		FormLayout* __layout;
		PathEdit* __destination;

};

#endif // COPYACTION_H
