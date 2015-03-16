// ParametroVariable.cpp: implementation of the CParametroVariable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParametroVariable.h"
#include "Rutinas.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CParametroVariable, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParametroVariable::CParametroVariable() : CParametro()
{
	m_dValorInicial = 0.0;
	m_dValorFinal = 0.0;
	m_dIncremento = 0.0;
}

CParametroVariable::~CParametroVariable()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CParametroVariable::EstableceValorInicial(double dValor)
{
	m_dValorInicial = dValor;
	m_dValorActual = dValor;
}

void CParametroVariable::EstableceValorInicial(CString cCadena)
{
	m_dValorInicial = CStrToDouble(cCadena);
	m_dValorActual = CStrToDouble(cCadena);
}

void CParametroVariable::EstableceValorFinal(double dValor)
{
	m_dValorFinal = dValor;	
}

void CParametroVariable::EstableceValorFinal(CString cCadena)
{
	m_dValorFinal = CStrToDouble(cCadena);
}

void CParametroVariable::EstableceIncremento(double dValor)
{
	m_dIncremento = dValor;
}

void CParametroVariable::EstableceIncremento(CString cCadena)
{
	m_dIncremento = CStrToDouble(cCadena);
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

double CParametroVariable::DevuelveValorInicial()
{
	return m_dValorInicial;
}

CString CParametroVariable::DevuelveValorInicialAsStr()
{
	return DoubleToCStr(m_dValorInicial);
}

double CParametroVariable::DevuelveValorFinal()
{
	return m_dValorFinal;
}

CString CParametroVariable::DevuelveValorFinalAsStr()
{
	return DoubleToCStr(m_dValorFinal);
}

double CParametroVariable::DevuelveIncremento()
{
	return m_dIncremento;
}

CString CParametroVariable::DevuelveIncrementoAsStr()
{
	return DoubleToCStr(m_dIncremento);
}

int CParametroVariable::DevuelveTotalInteracciones()
{
	int iTotalInteracciones = 0;

	if (m_dIncremento == 0)
	{
		iTotalInteracciones = 1;
		return iTotalInteracciones;
	}

	for (double iIndex = m_dValorInicial; iIndex <= m_dValorFinal; iIndex += m_dIncremento)
		iTotalInteracciones++;

	return iTotalInteracciones;
}

//////////////////////////////////////////////////////////////////////
// Operations 
//////////////////////////////////////////////////////////////////////

void CParametroVariable::Serialize(CArchive & archive)
{
	if (archive.IsStoring())
	{
		archive << m_strEtiqueta;
		archive << m_dValorActual;
		archive << m_dValorInicial;
		archive << m_dValorFinal;
		archive << m_dIncremento;
	}
	else
	{
		archive >> m_strEtiqueta;
		archive >> m_dValorActual;
		archive >> m_dValorInicial;
		archive >> m_dValorFinal;
		archive >> m_dIncremento;
	}
}

//////////////////////////////////////////////////////////////////////
// Operators 
//////////////////////////////////////////////////////////////////////

const CParametroVariable& CParametroVariable::operator =(const CParametroVariable &
																			cParamVariab)
{
	m_strEtiqueta = cParamVariab.m_strEtiqueta;
	m_dValorActual = cParamVariab.m_dValorActual;
	m_dValorInicial = cParamVariab.m_dValorInicial;
	m_dValorFinal = cParamVariab.m_dValorFinal;
	m_dIncremento = cParamVariab.m_dIncremento;

	return *this;
}
