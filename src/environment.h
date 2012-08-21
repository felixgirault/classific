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

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QList>



/**
 *
 */

class Environment : public QObject
{
	public:

		/**
		 *
		 */

		enum ExecutionMode {
			Explain,
			Run
		};



		/**
		 *
		 */

		class FileInfo : public QFileInfo
		{
			public:

				/**
				 *
				 */

				FileInfo( );



				/**
				 *	@param base
				 *	@param environment
				 */

				FileInfo( const QFileInfo& base, Environment* environment );



				/**
				 *
				 */

				Environment* environment( ) const;



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

				Environment* __environment;	//!<

				QStringList __explanations;	//!<
				QStringList __errors;		//!<

		};



		/**
		 *
		 */

		typedef QList< FileInfo > FileInfoList;

	public:

		/**
		 *	Constructor
		 *
		 *	@param mode Execution mode.
		 *	@param directory The root directory to search in.
		 *	@param recursive Tells if the search is recursive.
		 */

		Environment( ExecutionMode mode, const QDir& directory, bool recursive = false, QObject* parent = 0 );



		/**
		 *
		 */

		ExecutionMode mode( ) const;



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



		/**
		 *
		 */

		FileInfoList files( ) const;



		/**
		 *
		 */

		void refresh( );

	private:

		/**
		 *
		 */

		void scan( const QDir& directory );

	private:

		ExecutionMode __mode;	//!< Execution mode.
		QDir __directory;		//!< Root directory.
		bool __recursive;		//!< Whether the search is recursive or not.

		FileInfoList __files;	//!< Found files.

};

#endif // ENVIRONMENT_H
