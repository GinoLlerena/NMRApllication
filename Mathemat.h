// Mathemat.h: interface archive.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATHEMAT_H__0C3372C5_324B_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_MATHEMAT_H__0C3372C5_324B_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include <math.h>

#define M_PI 3.14159265358979323846264338327950288419716939937510

/*	Funci�n : Cube
*	Forma de uso : Cube( dNumber )
*	Esta funci�n devuelve el cubo
*	de un n�mero.
*/
double cube( const double dNumber );

/*	Funci�n : Factorial
*	Forma de uso : Factorial( iNumber )
*	Esta funci�n devuelve el factorial
*	de un n�mero.
*/
double factorial( const int iNumber );

/* Funci�n : PolinomLagrange
*	Forma de uso : PolinomLagrange( dAngle )
*	Esta funci�n devuelve el polinomio de Lagrange
*	de un �ngulo ingresado en grados.
*/
double polinomLagrange( const double dAngle );

/*	Funci�n : Round
*	Forma de uso : Round( dNumber )
*	Esta funci�n redondea el n�mero a
*	su entero correcto.
*/
//int round( const double dNumber );

/*	Funci�n : Square
*	Forma de uso : Square( dNumber )
*	Esta funci�n devuelve el cuadrado
*	de un n�mero.
*/
double square( const double dNumber );


#endif // !defined(AFX_MATHEMAT_H__0C3372C5_324B_11D2_A5A8_043A03C10000__INCLUDED_)
