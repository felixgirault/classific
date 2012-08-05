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
 *	AbstractBuilder.
 */

class AbstractBuilder
{
	public:

		virtual void* build( ) = 0;

};



/**
 *	Builder.
 */

template < class Product >
class Builder : public AbstractBuilder
{
	public:

		/**
		 *
		 */

		virtual void* build( )
		{
			return ( void* )( new Product( ));
		}

};



/**
 *
 */

template< class Product >
class BasicFactory
{
	public:

		/**
		 *	Destructor.
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
		 *
		 *
		 *	@param key
		 *	@param builder
		 */

		void registerBuilder( const QString& name, AbstractBuilder* builder )
		{
			__builders.insert( name, builder );
		}



		/**
		 *	@brief availableBuilders
		 *	@return
		 */

		QStringList availableBuilders( )
		{
			return __builders.keys( );
		}



		/**
		 *
		 *
		 *	@param key
		 *	@return
		 */

		Product* build( const QString& name )
		{
			return __builders.contains( name )
				? ( Product* )( __builders.value( name )->build( ))
				: 0;
		}

	private:

		QMap< QString, AbstractBuilder* > __builders;	//!<

};

#endif // BASICFACTORY_H
