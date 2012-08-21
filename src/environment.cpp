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

#include <QFileInfoList>

#include "environment.h"



/**
 *
 */

Environment::FileInfo::FileInfo( ) :
	__environment( 0 )
{ }



/**
 *
 */

Environment::FileInfo::FileInfo( const QFileInfo& base, Environment* environment ) :
	QFileInfo( base ),
	__environment( environment )
{ }



/**
 *
 */

Environment* Environment::FileInfo::environment( ) const
{
	return __environment;
}



/**
 *
 */

QString Environment::FileInfo::compilePath( const QString& path ) const
{
	QString compiled = path;

	// root directory
	compiled.replace( "%ROOT%", __environment->directory( ).canonicalPath( ));

	// current directory
	compiled.replace( "%DIR", canonicalPath( ));

	return compiled;
}



/**
 *
 */

QStringList Environment::FileInfo::explanations( ) const
{
	return __explanations;
}



/**
 *
 */

void Environment::FileInfo::addExplanation( const QString& explanation )
{
	__explanations.append( explanation );
}



/**
 *
 */

QStringList Environment::FileInfo::errors( ) const
{
	return __errors;
}



/**
 *
 */

void Environment::FileInfo::addError( const QString& error )
{
	__errors.append( error );
}



/**
 *
 */

Environment::Environment( ExecutionMode mode, const QDir& directory, bool recursive, QObject* parent ) :
	QObject( parent ),
	__mode( mode ),
	__directory( directory ),
	__recursive( recursive )
{ }



/**
 *
 */

Environment::ExecutionMode Environment::mode( ) const
{
	return __mode;
}



/**
 *	Returns the root directory.
 *
 *	@return
 */

QDir Environment::directory( ) const
{
	return __directory;
}



/**
 *
 */

bool Environment::recursive( ) const
{
	return __recursive;
}



/**
 *
 */

Environment::FileInfoList Environment::files( ) const
{
	return __files;
}



/**
 *
 */

void Environment::refresh( )
{
	scan( __directory );
}



/**
 *
 */

void Environment::scan( const QDir& directory )
{
	QFileInfoList files = directory.entryInfoList(
		QStringList( ),
		QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files
	);

	foreach ( const QFileInfo& file, files ) {
		if ( __recursive && file.isDir( )) {
			scan( file.absoluteFilePath( ));
		}

		if ( file.isFile( )) {
			__files.append( FileInfo( file, this ));
		}
	}
}
