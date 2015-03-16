// Mathemat.cpp: implementation archive.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Mathemat.h"
#include "Trigonom.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

double cube( const double dNumber )
{
	return ( dNumber * dNumber * dNumber );
}

double factorial( const int iNumber )
{
	if ( iNumber <= 1 )
		return 1;
	else
		return ( iNumber * factorial( iNumber - 1 ) );
}

double polinomLagrange( const double dAngle )
{
	return ( ( ( 3 * cosenSquare( dAngle ) ) - 1 ) / 2 );
}

double square( const double dNumber )
{
	return ( dNumber * dNumber );
}

int round( const double dNumber )
{
	double dParteEntera,
			 dParteDecimal;

	dParteDecimal = modf( dNumber, &dParteEntera );

	if ( dNumber >= 0 )
		if ( dParteDecimal >= 0.5 )
			return (int)( dParteEntera + 1 );

	else
		if ( dParteDecimal <= -0.5 )
			return (int)( dParteEntera - 1 );

	return (int) dParteEntera;
}
