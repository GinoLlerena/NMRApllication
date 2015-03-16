// Distorcion.cpp: implementation of the CDistorcion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Distorcion.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CDistorcion, CObject, 0)

//////////////////////////////////////////////////////////////////////
//	Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDistorcion::CDistorcion()
{
	for (int iPaso = 0; iPaso < 3; iPaso++) 
		m_dInteraccion[iPaso] = 0.0;

	m_strEtiquetasInteraccA = _T(" ");
	m_strEtiquetasInteraccB = _T(" ");
	m_strEtiquetasInteraccC = _T(" ");
	m_dDistanciaSub12 = 0.0;
	m_dConstante = 0.0;
	m_dTzz = 0.0;
	m_dTxxMinusTyy = 0.0;
	m_dRho = 0.0;
}

CDistorcion::~CDistorcion()
{

}

//////////////////////////////////////////////////////////////////////
//	Input Data
//////////////////////////////////////////////////////////////////////

void CDistorcion::EstableceEtiquetasInteraccA(CString cCadena)
{
	m_strEtiquetasInteraccA = cCadena;
}

void CDistorcion::EstableceEtiquetasInteraccB(CString cCadena)
{
	m_strEtiquetasInteraccB = cCadena;
}

void CDistorcion::EstableceEtiquetasInteraccC(CString cCadena)
{
	m_strEtiquetasInteraccC = cCadena;
}

void CDistorcion::EstableceInteraccion(int iIndice, double dValor)
{
	m_dInteraccion[iIndice] = dValor;
}

void CDistorcion::EstableceDistancia(double dValor)
{
	m_dDistanciaSub12 = dValor;
}

void CDistorcion::EstableceConstante(double dValor)
{
	m_dConstante = dValor;
}

//////////////////////////////////////////////////////////////////////
//	Output Data
//////////////////////////////////////////////////////////////////////

CString CDistorcion::DevuelveEtiquetasInteraccA()
{
	return m_strEtiquetasInteraccA;
}

CString CDistorcion::DevuelveEtiquetasInteraccB()
{
	return m_strEtiquetasInteraccB;
}

CString CDistorcion::DevuelveEtiquetasInteraccC()
{
	return m_strEtiquetasInteraccC;
}

double CDistorcion::DevuelveRho()
{
	return m_dRho;
}

double CDistorcion::DevuelveTzz()
{
	return m_dTzz;
}

double CDistorcion::DevuelveTxxMinusTyy()
{
	return m_dTxxMinusTyy;
}

//////////////////////////////////////////////////////////////////////
//	Operations
//////////////////////////////////////////////////////////////////////

void CDistorcion::Serialize(CArchive & fichero)
{
   if (fichero.IsStoring())
	{
		fichero << m_strEtiquetasInteraccA;
		fichero << m_strEtiquetasInteraccB;
		fichero << m_strEtiquetasInteraccC;
		fichero << m_dInteraccion[0] << m_dInteraccion[1] << m_dInteraccion[2];
		fichero << m_dDistanciaSub12;
		fichero << m_dConstante;
		fichero << m_dTzz;
		fichero << m_dTxxMinusTyy;
		fichero << m_dRho;
	}
	else
	{
		fichero >> m_strEtiquetasInteraccA;
		fichero >> m_strEtiquetasInteraccB;
		fichero >> m_strEtiquetasInteraccC;
		fichero >> m_dInteraccion[0] >> m_dInteraccion[1] >> m_dInteraccion[2];
		fichero >> m_dDistanciaSub12;
		fichero >> m_dConstante;
		fichero >> m_dTzz;
		fichero >> m_dTxxMinusTyy;
		fichero >> m_dRho;
	}
}

void CDistorcion::CalculaRho()
{
	double dNumerador, dDenominador;

	dNumerador = ( 4 * m_dInteraccion[0] ) - ( 128 * m_dInteraccion[1] ) + 
		(36 * sqrt((double)3)* m_dInteraccion[2]);
	dDenominador = ( 27  * m_dInteraccion[0] ) - ( 384 * m_dInteraccion[1] ) +
		(63 * sqrt((double)3) * m_dInteraccion[2]);

	m_dRho = dNumerador / dDenominador;
}

void CDistorcion::CalculaTzz()
{
	m_dTzz = (1 / m_dConstante) * m_dInteraccion[0] * pow(m_dDistanciaSub12, 3);
}

void CDistorcion::CalculaTxxMinusTyy()
{
	m_dTxxMinusTyy = ( (1 / m_dConstante) * m_dInteraccion[2] * pow(m_dDistanciaSub12, 3) * 6 *
		sqrt(3) / (1 - 3 * m_dRho) ) + m_dTzz;
}

void CDistorcion::RealizaCalculos()
{
	CalculaRho();
	CalculaTzz();
	CalculaTxxMinusTyy();
}
