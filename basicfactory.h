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

#ifndef BASICFACTORY_H
#define BASICFACTORY_H

#include <QMap>
#include <QString>
#include <QStringList>



/**
 *	Abstract instance builder.
 */

class AbstractBuilder
{
	public:

		/**
		 *	Builds and returns a product.
		 *
		 *	@return An instance of the product.
		 */

		virtual void* build( ) = 0;

};



/**
 *	Instance builder to be used in a BasicFactory.
 */

template < class Product >
class Builder : public AbstractBuilder
{
	public:

		/**
		 *	Builds and returns a product.
		 *
		 *	@return An instance of the product.
		 */

		virtual void* build( )
		{
			return ( void* )( new Product( ));
		}

};



/**
 *	A basic factory.
 */

template< class Product >
class BasicFactory
{
	public:

		/**
		 *	Frees allocated memory.
		 */

		~BasicFactory< Product >( )
		{
			QMapIterator< QString, AbstractBuilder* > it( __builders );

			while ( it.hasNext( )) {
				it.next( );
				delete it.value( );
			}
		}



		/**
		 *	Registers a new product to be produced by the factory.
		 *
		 *	@param name Product name.
		 *	@param builder Instance builder.
		 */

		void registerProduct( const QString& name, AbstractBuilder* builder )
		{
			__builders.insert( name, builder );
		}



		/**
		 *	Returns the name of all registered products.
		 *
		 *	@return Product names.
		 */

		QStringList names( )
		{
			return __builders.keys( );
		}



		/**
		 *	Builds and returns a product.
		 *
		 *	@param name Name of the product to build.
		 *	@return An instance of the product, or 0 if it couldn't be build.
		 */

		Product* build( const QString& name )
		{
			return __builders.contains( name )
				? ( Product* )( __builders.value( name )->build( ))
				: 0;
		}

	private:

		QMap< QString, AbstractBuilder* > __builders;	//!< Registered builders.

};

#endif // BASICFACTORY_H
