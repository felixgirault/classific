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

#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

#include "factory.h"
#include "filter.h"



/**
 *	A factory of filters.
 */

class FilterFactory : public Factory< FilterFactory, Filter >
{
	friend class Factory< FilterFactory, Filter >;

	protected:

		/**
		 *	Registers filters.
		 */

		FilterFactory( );

};

#endif // FILTERFACTORY_H
