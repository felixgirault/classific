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

#ifndef RUNNER_H
#define RUNNER_H

#include <QFrame>

#include "execution.h"

class FormLayout;
class PathEdit;
class TypedPushButton;



/**
 *
 */

class Runner : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *
		 */

		Runner( QWidget* parent = 0 );

	signals:

		/**
		 *
		 */

		void run( Execution& execution );

	private slots:

		/**
		 *
		 */

		void run( );
		
	private:

		FormLayout* __layout;		//!<
		PathEdit* __path;			//!<
		TypedPushButton* __explain;	//!<
		TypedPushButton* __run;		//!<
		
};

#endif // RUNNER_H
