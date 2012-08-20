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

#ifndef STATEFULLINEEDIT_H
#define STATEFULLINEEDIT_H

#include <QLineEdit>



/**
 *
 */

class StatefulLineEdit : public QLineEdit
{
	Q_OBJECT
	Q_ENUMS( State )
	Q_PROPERTY( State state READ state WRITE setState )

	public:

		/**
		 *
		 */

		enum State {
			Valid,
			Invalid
		};

	public:

		/**
		 *
		 */

		StatefulLineEdit( QWidget* parent = 0 );



		/**
		 *
		 */

		StatefulLineEdit( State state, QWidget* parent = 0 );



		/**
		 *
		 */

		State state( ) const;



		/**
		 *
		 */

		void setState( State state );



		/**
		 *
		 */

		void setProperty( const char* name, const QVariant& value );

	private:

		State __state;	//!<

};

#endif // STATEFULLINEEDIT_H
