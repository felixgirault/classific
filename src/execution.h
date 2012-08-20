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

#ifndef EXECUTION_H
#define EXECUTION_H

#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QVector>



/**
 *
 */

class Execution
{
	public:

		/**
		 *
		 */

		enum Mode {
			Explain,
			Run
		};



		/**
		 *
		 */

		class File
		{
			public:

				/**
				 *
				 */

				File( );



				/**
				 *	@param execution
				 *	@param info
				 */

				File( Execution* execution, const QFileInfo& info );



				/**
				 *
				 */

				Execution& execution( ) const;



				/**
				 *
				 */

				QFileInfo info( ) const;



				/**
				 *
				 */

				QString compilePath( const QString& path ) const;



				/**
				 *
				 */

				QStringList explanations( ) const;



				/**
				 *
				 */

				void addExplanation( const QString& explanation );



				/**
				 *
				 */

				QStringList errors( ) const;



				/**
				 *
				 */

				void addError( const QString& error );

			private:

				Execution* __execution;
				QFileInfo __info;

				QStringList __explanations;
				QStringList __errors;

		};

	public:

		/**
		 *	Constructor
		 *
		 *	@param mode Execution mode.
		 *	@param directory The root directory to search in.
		 *	@param recursive Tells if the search is recursive.
		 */

		Execution( Mode mode, const QDir& directory, bool recursive = false );



		/**
		 *
		 */

		Mode mode( ) const;



		/**
		 *	Returns the root directory.
		 *
		 *	@return
		 */

		QDir directory( ) const;



		/**
		 *	Returns if the search is recursive.
		 *
		 *	@return
		 */

		bool recursive( ) const;

	private:

		/**
		 *
		 */

		void scan( const QDir& directory );

	private:

		Mode __mode;			//!<
		QDir __directory;		//!< Root directory.
		bool __recursive;		//!<

		QVector< File > __files;	//!<

};

#endif // EXECUTION_H
