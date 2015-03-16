// Trigonom.cpp: implementation archive.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Trigonom.h"
#include "Mathemat.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
//	Operations
//////////////////////////////////////////////////////////////////////

double degreesToRadians( const double dAngle )
{
	return ( ( M_PI * dAngle ) / 180 );
}

double radiansToDegrees( const double dAngle )
{
	return ( ( 180 * dAngle ) / M_PI );
}

double sen( const double dAngle )
{
	return sin( degreesToRadians( dAngle ) );
}

double cosen( const double dAngle )
{
	return cos( degreesToRadians( dAngle ) );
}

double tg( const double dAngle )
{
	return tan( degreesToRadians( dAngle ) );
}

double cot( const double dAngle )
{
	return ( 1 / tg( dAngle ) );
}

double sec( const double dAngle )
{
	return ( 1 / cosen( dAngle ) );
}

double cosec( const double dAngle )
{
	return ( 1 / sen( dAngle ) );
}

double senDouble( const double dAngle )
{
	return ( 2 * sen( dAngle ) * cosen( dAngle ) );
}

double cosenDouble( const double dAngle )
{
	return ( ( cosen( dAngle ) * cosen( dAngle ) ) -
		( sen( dAngle ) * sen( dAngle ) ) );
}

double tgDouble( const double dAngle )
{
	return ( ( 2 * tg( dAngle ) ) / ( 1 - tgSquare( dAngle ) ) );
}

double cotDouble( const double dAngle )
{
	return ( ( cotSquare( dAngle ) - 1 ) / ( 2 * cot( dAngle ) ) );
}

double senSquare( const double dAngle )
{
	return ( sen( dAngle ) * sen( dAngle ) );
}

double cosenSquare( const double dAngle )
{
	return ( cosen( dAngle ) * cosen( dAngle ) );
}

double tgSquare( const double dAngle )
{
	return ( tg( dAngle ) * tg( dAngle ) );
}

double cotSquare( const double dAngle )
{
	return ( cot( dAngle ) * cot( dAngle ) );
}
