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

#ifndef TYPEDPUSHBUTTON_H
#define TYPEDPUSHBUTTON_H

#include <QPushButton>



/**
 *
 */

class TypedPushButton : public QPushButton
{
	Q_OBJECT
	Q_ENUMS( Type )
	Q_PROPERTY( Type type READ type WRITE setType )

	public:

		/**
		 *	Possible types for the button.
		 */

		enum Type {
			Negative,
			Neutral,
			Positive
		};

	public:

		/**
		 *	Default constructor.
		 *
		 *	@param parent Parent widget.
		 */

		TypedPushButton( QWidget* parent = 0 );



		/**
		 *	Constructor.
		 *
		 *	@param text Button text.
		 *	@param parent Parent widget.
		 */

		TypedPushButton( const QString& text, QWidget* parent = 0 );



		/**
		 *	Constructor.
		 *
		 *	@param text Button text.
		 *	@param type Button type.
		 *	@param parent Parent widget.
		 */

		TypedPushButton(
			const QString& text,
			Type type,
			QWidget* parent = 0
		);



		/**
		 *	Returns the type of the button.
		 *
		 *	@return Button type.
		 */

		Type type( ) const;



		/**
		 *	Sets the button type.
		 *
		 *	@param type Button type.
		 */

		void setType( Type type );



		/**
		 *	Returns the type of the button.
		 *
		 *	@return Button type.
		 */

		void setProperty( const char* name, const QVariant& value );

	private:

		Type __type;	//!< Type of the button.

};

#endif // TYPEDPUSHBUTTON_H
