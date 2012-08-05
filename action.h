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

#ifndef ACTION_H
#define ACTION_H

#include <QFrame>

class QLabel;
class QProgressBar;
class QPushButton;

class FilterCollection;



/**
 *	Base class for an action.
 */

class Action : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *	Constructor
		 */

		explicit Action( const QString& name, QWidget* parent = 0 );



		/**
		 *
		 */

		void run( );



		/**
		 *
		 */

		void explain( );

	private:

		FilterCollection* __filters;	//!<

		QLabel* __name;	//!<
		QProgressBar* __progress;	//!<
		QPushButton* __remove;	//!<
		
};

#endif // ACTION_H
