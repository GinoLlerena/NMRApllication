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

/*	Función : Cube
*	Forma de uso : Cube( dNumber )
*	Esta función devuelve el cubo
*	de un número.
*/
double cube( const double dNumber );

/*	Función : Factorial
*	Forma de uso : Factorial( iNumber )
*	Esta función devuelve el factorial
*	de un número.
*/
double factorial( const int iNumber );

/* Función : PolinomLagrange
*	Forma de uso : PolinomLagrange( dAngle )
*	Esta función devuelve el polinomio de Lagrange
*	de un ángulo ingresado en grados.
*/
double polinomLagrange( const double dAngle );

/*	Función : Round
*	Forma de uso : Round( dNumber )
*	Esta función redondea el número a
*	su entero correcto.
*/
//int round( const double dNumber );

/*	Función : Square
*	Forma de uso : Square( dNumber )
*	Esta función devuelve el cuadrado
*	de un número.
*/
double square( const double dNumber );


#endif // !defined(AFX_MATHEMAT_H__0C3372C5_324B_11D2_A5A8_043A03C10000__INCLUDED_)
