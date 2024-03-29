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

#ifndef LAYOUTS_H
#define LAYOUTS_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>



/**
 *
 */

class HBoxLayout : public QHBoxLayout
{
	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		HBoxLayout( QWidget* parent = 0 );

};



/**
 *
 */

class VBoxLayout : public QVBoxLayout
{
	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		VBoxLayout( QWidget* parent = 0 );

};



/**
 *
 */

class FormLayout : public QFormLayout
{
	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		FormLayout( QWidget* parent = 0 );

};

#endif // LAYOUTS_H
