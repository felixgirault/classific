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

#ifndef FILTERCOLLECTION_H
#define FILTERCOLLECTION_H

#include <QFrame>
#include <QVector>

class Filter;
class VBoxLayout;
class TypedPushButton;



/**
 *	A collection of filters.
 */

class FilterCollection : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		FilterCollection( QWidget* parent = 0 );

	private:

		/**
		 *	Adds a filter frame to the collection.
		 */

		void addFrame( const QString& name, Filter* filter );

	private slots:

		/**
		 *	Asks for a filter to add.
		 */

		void addFilter( );



		/**
		 *	Remove the filter frame which triggered the slot.
		 */

		void removeFrame( );

	private:

		QVector< Filter* > __filters;	//!<

		VBoxLayout* __layout;
		TypedPushButton* __add;
		
};

#endif // FILTERCOLLECTION_H