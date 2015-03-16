// Parametro.cpp: implementation of the CParametro class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Parametro.h"
#include "Rutinas.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CParametro, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParametro::CParametro()
{
	m_strEtiqueta = _T("");
	m_dValorActual = 0.0;
}

CParametro::~CParametro()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CParametro::EstableceEtiqueta(CString cCadena)
{
	m_strEtiqueta = cCadena;
}

void CParametro::EstableceValorActual(double dValor)
{
	m_dValorActual = dValor;
}

void CParametro::EstableceValorActual(CString cCadena)
{
	m_dValorActual = CStrToDouble(cCadena);
}

void CParametro::EstableceConStruct(StcParametro * stcParametro)
{
	m_strEtiqueta = stcParametro->strEtiqueta1;
	m_dValorActual = stcParametro->dValor;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

CString CParametro::DevuelveEtiqueta()
{
	return m_strEtiqueta;
}

double CParametro::DevuelveValorActual()
{
	return m_dValorActual;
}

CString CParametro::DevuelveValorActualAsStr()
{
	return DoubleToCStr(m_dValorActual);
}

StcParametro CParametro::DevuelveStruct()
{
	StcParametro stcParametro;
	_tcscpy(stcParametro.strEtiqueta1, m_strEtiqueta);
	stcParametro.dValor = m_dValorActual;

	return stcParametro;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CParametro::Serialize(CArchive & fichero)
{
   if ( fichero.IsStoring() )
	{
		fichero << m_strEtiqueta;
		fichero << m_dValorActual;
	}
	else
	{
		fichero >> m_strEtiqueta;
		fichero >> m_dValorActual;
	}
}
