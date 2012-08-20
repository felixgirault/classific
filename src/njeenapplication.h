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

#ifndef NJEENAPPLICATION_H
#define NJEENAPPLICATION_H

#include <QApplication>
#include <QEvent>



/**
 *	The Njeen application.
 */

class NjeenApplication : public QApplication
{
	Q_OBJECT

	public:

		/**
		 *	Constructor.
		 *
		 *	@param argc Command line argument count.
		 *	@param argv Command line arguments.
		 */

		NjeenApplication( int& argc, char** argv );



		/**
		 *	Loads the user theme.
		 */

		void loadTheme( );
		
};

#endif // NJEENAPPLICATION_H
