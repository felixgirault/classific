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

#ifndef FILTER_H
#define FILTER_H

#include <QFrame>

class QLabel;



/**
 *
 */

class Filter : public QFrame
{
	Q_OBJECT

	public:

		explicit Filter( const QString& name, QWidget* parent = 0 );

	private:

		QLabel* __name;	//!<

};

#endif // FILTER_H
