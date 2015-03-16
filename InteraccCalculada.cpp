// InteraccCalculada.cpp: implementation of the CInteraccCalculada class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InteraccCalculada.h"
#include "Rutinas.h"
#include "Trigonom.h"
#include "Mathemat.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CInteraccCalculada, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInteraccCalculada::CInteraccCalculada() : CInteraccion(), m_cCoordEsf()
{
	for (int iPaso = 0; iPaso < limCoeff; iPaso++)
		m_dCoefficient[iPaso] = 0.0;
}

CInteraccCalculada::CInteraccCalculada(const CInteraccCalculada & cInteraccCalculada)
{
	m_strEtiqueta1 = cInteraccCalculada.m_strEtiqueta1;
	m_strEtiqueta2 = cInteraccCalculada.m_strEtiqueta2;
	m_dValor = cInteraccCalculada.m_dValor;
	m_cCoordEsf = cInteraccCalculada.m_cCoordEsf;

	for (int iPaso = 0; iPaso < limCoeff; iPaso++)
		m_dCoefficient[iPaso] = cInteraccCalculada.m_dCoefficient[iPaso];

}

CInteraccCalculada::~CInteraccCalculada()
{

}

//////////////////////////////////////////////////////////////////////
//	Input Data
//////////////////////////////////////////////////////////////////////


void CInteraccCalculada::EstableceCoefficiente(int iIndice, double dValor)
{
	m_dCoefficient[iIndice] = dValor;
}

//////////////////////////////////////////////////////////////////////
//	Output Data
//////////////////////////////////////////////////////////////////////


CCoordEsf &	CInteraccCalculada::DevuelveCoordEsf()
{
	CCoordEsf & cCoordEsfRef = m_cCoordEsf;
	return cCoordEsfRef;
}

double CInteraccCalculada::DevuelveCoefficient(int iIndice)
{
	return m_dCoefficient[iIndice];
}


double CInteraccCalculada::DevuelveValorCalculado(double dTzz, double dTxxTyy, 
	double dTyz, double dTzx, double dTxy)
{
	return (m_dCoefficient[0] * dTzz) + (m_dCoefficient[1] * dTxxTyy) +
		(m_dCoefficient[2] * dTyz) + (m_dCoefficient[3] * dTzx) +
		(m_dCoefficient[4] *	dTxy);
}

double CInteraccCalculada::DevuelveConstante(CString cTipo1, CString cTipo2)
{
	if (cTipo1 == _T("Proton") &&	cTipo2 == _T("Proton"))
		return (-120.120);

	if (cTipo1 == _T("Deuterio") &&	cTipo2 == _T("Deuterio"))
		return (-2.830);

	if (cTipo1 == _T("Fluor") && cTipo2 == _T("Fluor"))
		return (-106.302);

	if ((cTipo1 == _T("Proton") && cTipo2 == _T("Deuterio")) ||
		(cTipo1 == _T("Deuterio") && cTipo2 == _T("Proton")))
		return (-18.439);

	if ((cTipo1 == _T("Proton") && cTipo2 == _T("Fluor")) ||
		(cTipo1 == _T("Fluor") && cTipo2 == _T("Proton")))
		return (-113.000);

	if ((cTipo1 == _T("Fluor") &&	cTipo2 == _T("Deuterio")) ||
		(cTipo1 == _T("Deuterio") && cTipo2 == _T("Fluor")))
		return (-17.346);

	return 0;
}

//////////////////////////////////////////////////////////////////////
//	Operations
//////////////////////////////////////////////////////////////////////

void CInteraccCalculada::Serialize(CArchive & archive)
{

	CValorDual::Serialize(archive);
	if (archive.IsStoring())
	{
		for (int iPaso = 0; iPaso < limCoeff; iPaso++)
			archive << m_dCoefficient[iPaso];
	}
	else
	{
		for (int iPaso = 0; iPaso < limCoeff; iPaso++)
			archive >> m_dCoefficient[iPaso];
	}

	//m_cCoordEsf.Serialize(archive);
}

void CInteraccCalculada::EstableceCoeficientes(CPunto cPtoInicial, CPunto cPtoFinal,
												  CString cTipoPtoInicial, CString cTipoPtoFinal,
												  double dAnguloDihedral, Simetria nSimetria)
{
	m_cCoordEsf.Establece(cPtoInicial, cPtoFinal);
	double dConstante = DevuelveConstante(cTipoPtoInicial, cTipoPtoFinal);

	switch (nSimetria)
	{
		case NoSimetria:
			CalculaCoeficientesIndependientes(dConstante);
			break;
		case D2:
			CalculaCoeficientesParaD2(dConstante);
			break;
		case D4:
			CalculaCoeficientesParaD4(dConstante, dAnguloDihedral);
			break;
	}
}

void CInteraccCalculada::CalculaCoeficientesIndependientes(double dConstante)
{
	double dNumerador = 0.0;
	double dDenominador = cube( m_cCoordEsf.DevuelveDistancia() );
	double dAnguloPhi = m_cCoordEsf.DevuelveAnguloPhi().DevuelveValor(Grados);
	double dAnguloTeta = m_cCoordEsf.DevuelveAnguloTeta().DevuelveValor(Grados);

	// Coeficiente relativo a Tzz
	dNumerador = polinomLagrange(dAnguloPhi);
	m_dCoefficient[0] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a (Txx - Tyy)
	dNumerador = 0.5 * senSquare(dAnguloPhi) * cosenDouble(dAnguloTeta);
	m_dCoefficient[1] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Tyz
	dNumerador = senDouble(dAnguloPhi) * sen(dAnguloTeta);
	m_dCoefficient[2] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Tzx
	dNumerador = senDouble(dAnguloPhi) * cosen(dAnguloTeta);
	m_dCoefficient[3] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Txy
	dNumerador = senSquare(dAnguloPhi) * senDouble(dAnguloTeta);
	m_dCoefficient[4] = dConstante * dNumerador / dDenominador;
}

void CInteraccCalculada::CalculaCoeficientesParaD2(double dConstante)
{
	double dNumerador = 0.0;
	double dDenominador = cube( m_cCoordEsf.DevuelveDistancia() );
	double dAnguloPhi = m_cCoordEsf.DevuelveAnguloPhi().DevuelveValor(Grados);
	double dAnguloTeta = m_cCoordEsf.DevuelveAnguloTeta().DevuelveValor(Grados);

	// Coeficiente relativo a Tzz
	dNumerador = polinomLagrange(dAnguloPhi);
	m_dCoefficient[0] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a (Txx - Tyy)
	dNumerador = 0.5 * senSquare(dAnguloPhi) * cosenDouble(dAnguloTeta);
	m_dCoefficient[1] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Tyz
	m_dCoefficient[2] = 0.0;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Tzx
	m_dCoefficient[3] = 0.0;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Txy
	dNumerador = senSquare(dAnguloPhi) * senDouble(dAnguloTeta);
	m_dCoefficient[4] = dConstante * dNumerador / dDenominador;	
}

void CInteraccCalculada::CalculaCoeficientesParaD4(double dConstante, double dAnguloDihedral)
{
	double dNumerador = 0.0;
	double dDenominador = cube( m_cCoordEsf.DevuelveDistancia() );
	double dAnguloPhi = m_cCoordEsf.DevuelveAnguloPhi().DevuelveValor(Grados);
	double dAnguloTeta = m_cCoordEsf.DevuelveAnguloTeta().DevuelveValor(Grados);

	// Coeficiente relativo a Tzz
	dNumerador = polinomLagrange(dAnguloPhi);
	m_dCoefficient[0] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a (Txx - Tyy)
	dNumerador = 0.5 * senSquare(dAnguloPhi) * ( cosenDouble(dAnguloTeta) + 
		( tg(dAnguloDihedral) * senDouble(dAnguloTeta) ) );
	m_dCoefficient[1] = dConstante * dNumerador / dDenominador;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Tyz
	m_dCoefficient[2] = 0.0;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Tzx
	m_dCoefficient[3] = 0.0;

	///////////////////////////////////////////////////////////////////////////
	// Coeficiente relativo a Txy
	m_dCoefficient[4] = 0.0;
}

//////////////////////////////////////////////////////////////////////
//	Operators
//////////////////////////////////////////////////////////////////////

const CInteraccCalculada& CInteraccCalculada::operator =(const CInteraccCalculada &
																			cInteraccCalculada)
{
	m_strEtiqueta1 = cInteraccCalculada.m_strEtiqueta1;
	m_strEtiqueta2 = cInteraccCalculada.m_strEtiqueta2;
	m_dValor = cInteraccCalculada.m_dValor;
	m_cCoordEsf = cInteraccCalculada.m_cCoordEsf;

	for (int iPaso = 0; iPaso < limCoeff; iPaso++)
		m_dCoefficient[iPaso] = cInteraccCalculada.m_dCoefficient[iPaso];

	return *this;
}
