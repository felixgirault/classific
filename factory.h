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

#ifndef FACTORY_H
#define FACTORY_H

#include "basicfactory.h"



/**
 *	A singleton factory.
 */

template< class Child, class Product >
class Factory
{
	public:

		/**
		 *	Returns the name of all registered products.
		 *
		 *	@return Product names.
		 */

		static QStringList names( )
		{
			Factory< Child, Product >* __this = instance( );
			return __this->__factory.names( );
		}



		/**
		 *	Builds and returns a product.
		 *
		 *	@param name Name of the product to build.
		 *	@return An instance of the product, or 0 if it couldn't be build.
		 */

		static Product* build( const QString& name )
		{
			Factory< Child, Product >* __this = instance( );
			return __this->__factory.build( name );
		}

	protected:

		/**
		 *	Private constructor, to avoid multiple instances across the
		 *	application.
		 */

		Factory( ) { }



		/**
		 *	Private copy constructor, to avoid multiple instances across the
		 *	application.
		 *
		 *	@param factory Other factory.
		 */

		Factory( const Factory< Child, Product >& factory )
		{
			Q_UNUSED( factory );
		}



		/**
		 *	Private assignment operator, to avoid multiple instances across
		 *	the application.
		 *
		 *	@param factory Other factory.
		 */

		void operator=( const Factory< Child, Product >& factory )
		{
			Q_UNUSED( factory );
		}



		/**
		 *	Returns a singleton instance of the Factory.
		 *
		 *	@return Singleton instance.
		 */

		static Factory< Child, Product >* instance( )
		{
			static Factory< Child, Product >* instance = new Child( );
			return instance;
		}

	protected:

		BasicFactory< Product > __factory;	//!< The basic factory.

};

#endif // FACTORY_H
