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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class HBoxLayout;
class ActionCollection;
class Runner;



/**
 *	Main window of the application.
 */

class MainWindow : public QMainWindow
{
	Q_OBJECT
    
	public:

		/**
		 *	Constructor.
		 *
		 *	@param parent Parent widget.
		 */

		MainWindow( QWidget* parent = 0 );

	protected:

		/**
		 *	Reloads the user theme when pressing F5.
		 *
		 *	@param event Event.
		 */

		void keyPressEvent( QKeyEvent* event );

	private:

		HBoxLayout* __layout;
		ActionCollection* __actions;
		Runner* __runner;

};

#endif // MAINWINDOW_H
