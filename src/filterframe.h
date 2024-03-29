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

#ifndef FILTERFRAME_H
#define FILTERFRAME_H

#include <QFrame>
#include <QWidget>

#include "environment.h"

class Filter;
class VBoxLayout;
class TitleBar;



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

		FilterFrame( Filter* filter, const QString& name, QWidget* parent = 0 );



		/**
		 *
		 */

		bool passesFilter( const Environment::FileInfo& file ) const;

	signals:

		/**
		 *
		 */

		void removeMe( );

	private:

		Filter* __filter;		//!< Filter.

		VBoxLayout* __layout;
		TitleBar* __titleBar;	//!< Title bar.

};

#endif // FILTERFRAME_H
