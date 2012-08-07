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

#include <QList>
#include <QMap>



/**
 *	A generic factory.
 */

template< class ProductType >
class Factory
{
	public:

		typedef ProductType* ( *CreateFunction )( );

	private:

		class ProductMetaType
		{
			public:

				/**
				 *	Default constructor.
				 */

				ProductMetaType( )
				{ }



				/**
				 *	Constructor.
				 *
				 *	@param name Name of the product.
				 *	@param description Description of the product.
				 *	@param function Helper function to create the product.
				 */

				ProductMetaType(
					const QString& name,
					const QString& description,
					CreateFunction function
				) :
					__name( name ),
					__description( description ),
					__create( function )
				{ }



				/**
				 *	Returns the name of the product.
				 *
				 *	@return Product name.
				 */

				QString name( ) const
				{
					return __name;
				}



				/**
				 *	Returns the description of the product.
				 *
				 *	@return Product description.
				 */

				QString description( ) const
				{
					return __description;
				}



				/**
				 *	Returns an instance of a product.
				 *
				 *	@return Product instance.
				 */

				ProductType* create( ) const
				{
					return __create( );
				}

			private:

				QString __name;		//!< Name of the product.
				QString __description;	//!< Description of the product.
				CreateFunction __create;	//!< Helper function which creates a product.

		};

	public:

		/**
		 *	Registers a new product.
		 *
		 *	@param name Name of the product.
		 *	@param description Description of the product.
		 *	@param function Helper function to create the product.
		 */

		static void registerProductMetaType(
			const QString& name,
			const QString& description,
			CreateFunction function
		) {
			Factory& __this = instance( );
			__this.__registry.append( ProductMetaType( name, description, function ));
		}



		/**
		 *	Returns a met of informations about all the registered types, in
		 *	the form < name, description >.
		 *
		 *	@return Map of informations.
		 */

		static QMap< QString, QString > informations( )
		{
			Factory& __this = instance( );
			QMap< QString, QString > informations;

			foreach ( ProductMetaType meta, __this.__registry ) {
				informations.insert( meta.name( ), meta.description( ));
			}

			return informations;
		}



		/**
		 *	Creates the product which is associated with the given name.
		 *
		 *	@param name Name of the product.
		 *	@return An instance of the product, or 0 if there is no product
		 *		found with the given name.
		 */

		static ProductType* create( const QString& name )
		{
			Factory& __this = instance( );

			foreach ( ProductMetaType meta, __this.__registry ) {
				if ( name == meta.name( )) {
					return meta.create( );
				}
			}

			return 0;
		}

	private:

		/**
		 *	Private constructor to prevent copy.
		 */

		Factory( )
		{ }



		/**
		 *	Private copy constructor to prevent copy.
		 *
		 *	@param other Other factory.
		 */

		Factory( const Factory& other )
		{
			Q_UNUSED( other );
		}



		/**
		 *	Private assignment operator to prevent copy.
		 *
		 *	@param other Other factory.
		 */

		void operator=( const Factory& other )
		{
			Q_UNUSED( other );
		}



		/**
		 *	Returns a unique instance of the Factory.
		 *
		 *	@return Unique instance.
		 */

		static Factory& instance( )
		{
			static Factory factory;
			return factory;
		}

	private:

		QList< ProductMetaType > __registry;	//!< Regitry of products meta.

};



/**
 *	An utility class to register products for the factory.
 */

template< class AncestorType, class ProductType >
class ProductTypeRegistrar
{
	public:

		/**
		 *	Constructor.
		 *
		 *	@param name Name of the product.
		 *	@param description Description of the product.
		 */

		ProductTypeRegistrar( const QString& name, const QString& description )
		{
			Factory< AncestorType >::registerProductMetaType( name, description, create );
		}



		/**
		 *	Returns an instance of the product.
		 *
		 *	@return Product instance.
		 */

		static AncestorType* create( )
		{
			return new ProductType;
		}

};



/**
 *	A macro to register products easily.
 */

#define REGISTER_PRODUCT( baseClassName, className, name, description ) \
	ProductTypeRegistrar< baseClassName, className > className##Product( \
		QObject::tr( name ), \
		QObject::tr( description ) \
	);

#endif // FACTORY_H
