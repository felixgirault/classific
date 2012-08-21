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

#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QFrame>

class HBoxLayout;
class QProgressBar;
class QLabel;
class TypedPushButton;



/**
 *
 */

class TitleBar : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *
		 */

		TitleBar( const QString& title, bool hasProgress = false, QWidget* parent = 0 );



		/**
		 *
		 */

		void setMaximumProgress( int maximum );

	public slots:

		/**
		 *
		 */

		void progress( );

	signals:

		/**
		 *
		 */

		void toggled( bool toggle );



		/**
		 *
		 */

		void remove( );

	private slots:

		/**
		 *
		 */

		void toggle( bool toggle );

	private:

		HBoxLayout* __layout;
		QProgressBar* __progress;
		QLabel* __title;			//!< Title label.
		TypedPushButton* __toggle;	//!< A button to request toggling.
		TypedPushButton* __remove;	//!< A button to request closing.
		
};

#endif // TITLEBAR_H
