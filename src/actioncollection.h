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

#ifndef ACTIONCOLLECTION_H
#define ACTIONCOLLECTION_H

#include <QFrame>
#include <QVector>

class Action;
class VBoxLayout;
class TypedPushButton;



/**
 *	A collection of actions.
 */

class ActionCollection : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		ActionCollection( QWidget* parent = 0 );

	private:

		/**
		 *	Adds an action frame to the collection.
		 */

		void addFrame( Action* action, const QString& name );

	private slots:

		/**
		 *	Asks for an action to add.
		 */

		void addAction( );



		/**
		 *	Remove the action frame which triggered the slot.
		 */

		void removeFrame( );

	private:

		QVector< Action* > __actions;	//!<

		VBoxLayout* __layout;
		TypedPushButton* __add;

};

#endif // ACTIONCOLLECTION_H
