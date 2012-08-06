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

#ifndef FILTERFRAME_H
#define FILTERFRAME_H

#include <QFrame>

class QLabel;
class TypedPushButton;

class Filter;



/**
 *	An interface wrapper for filters.
 */

class FilterFrame : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *	Constructor.
		 *
		 *	@param filter
		 *	@param parent Parent widget
		 */

		FilterFrame( const QString& name, Filter* filter, QWidget* parent = 0 );

	signals:

		/**
		 *
		 */

		void removeMe( );

	private:

		Filter* __filter;			//!< Filter.

		QLabel* __name;			//!< Name label.
		TypedPushButton* __remove;	//!< A button to close the frame.

};

#endif // FILTERFRAME_H
