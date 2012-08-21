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

#include <QLabel>

#include "filterframe.h"
#include "filter.h"
#include "titlebar.h"
#include "layouts.h"



/**
 *
 */

FilterFrame::FilterFrame( Filter* filter, const QString& name, QWidget* parent ) :
	QFrame( parent ),
	__filter( filter ),
	__layout( new VBoxLayout( this )),
	__titleBar( new TitleBar( name ))
{
	connect( __titleBar, SIGNAL( toggled( bool )), __filter, SLOT( setHidden( bool )));
	connect( __titleBar, SIGNAL( remove( )), this, SIGNAL( removeMe( )));

	__layout->addWidget( __titleBar );
	__layout->addWidget( __filter );
}



/**
 *
 */

bool FilterFrame::passesFilter( const Environment::FileInfo& file ) const
{
	return __filter->passes( file );
}
