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

#include "execution.h"



/**
 *
 */

Execution::File::File( ) :
	__execution( 0 )
{ }



/**
 *
 */

Execution::File::File( Execution* execution, const QFileInfo& info ) :
	__execution( execution ),
	__info( info )
{ }



/**
 *
 */

Execution& Execution::File::execution( ) const
{
	return *__execution;
}



/**
 *
 */

QFileInfo Execution::File::info( ) const
{
	return __info;
}



/**
 *
 */

QString Execution::File::compilePath( const QString& path ) const
{
	QString compiled = path;

	// root directory
	compiled.replace( "%ROOT%", __execution->directory( ).canonicalPath( ));

	// current directory
	compiled.replace( "%DIR", __info.canonicalPath( ));

	return compiled;
}



/**
 *
 */

QStringList Execution::File::explanations( ) const
{
	return __explanations;
}



/**
 *
 */

void Execution::File::addExplanation( const QString& explanation )
{
	__explanations.append( explanation );
}



/**
 *
 */

QStringList Execution::File::errors( ) const
{
	return __errors;
}



/**
 *
 */

void Execution::File::addError( const QString& error )
{
	__errors.append( error );
}



/**
 *
 */

Execution::Execution( Mode mode, const QDir& directory, bool recursive ) :
	__mode( mode ),
	__directory( directory ),
	__recursive( recursive )
{
	scan( __directory );
}



/**
 *
 */

Execution::Mode Execution::mode( ) const
{
	return __mode;
}



/**
 *	Returns the root directory.
 *
 *	@return
 */

QDir Execution::directory( ) const
{
	return __directory;
}



/**
 *	Returns if the search is recursive.
 *
 *	@return
 */

bool Execution::recursive( ) const
{
	return __recursive;
}



/**
 *
 */

void Execution::scan( const QDir& directory )
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
			__files.append( File( this, file ));
		}
	}
}
