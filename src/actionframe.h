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

#ifndef ACTIONFRAME_H
#define ACTIONFRAME_H

#include <QFrame>

class Action;
class TitleBar;
class FilterCollection;



/**
 *	An interface wrapper for actions.
 */

class ActionFrame : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *	Constructor.
		 *
		 *	@param action
		 *	@param parent Parent widget
		 */

		ActionFrame( Action* action, const QString& name, QWidget* parent = 0 );

	signals:

		/**
		 *
		 */

		void removeMe( );
		
	private:

		Action* __action;			//!< Action.
		TitleBar* __titleBar;		//!< Title bar.
		FilterCollection* __filters;	//!< Collection of filters.
		
};

#endif // ACTIONFRAME_H
