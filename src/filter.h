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

#ifndef FILTER_H
#define FILTER_H

#include <QFrame>

#include "environment.h"



/**
 *	Base class for a filter.
 */

class Filter : public QFrame
{
	Q_OBJECT

	public:

		/**
		 *	Constructs a filter with the given name.
		 *
		 *	@param parent Parent widget.
		 */

		Filter( QWidget* parent = 0 );



		/**
		 *
		 */

		virtual bool passes( const Environment::FileInfo& file ) const = 0;

	private:



};

#endif // FILTER_H
