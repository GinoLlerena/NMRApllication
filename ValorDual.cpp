// ValorDual.cpp: implementation of the CValorDual class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ValorDual.h"
#include "Rutinas.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CValorDual, CObject, 0)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CValorDual::CValorDual()
{
	TRACE("Constructing CValorDual...\n");
	m_strEtiqueta1 = _T("");
	m_strEtiqueta2 = _T("");
	m_dValor = 0.0;
}

CValorDual::~CValorDual()
{

}

//////////////////////////////////////////////////////////////////////
//	Input Data
//////////////////////////////////////////////////////////////////////

void CValorDual::EstableceEtiqueta1(CString cCadena)
{
	m_strEtiqueta1 = cCadena;
}

void CValorDual::EstableceEtiqueta2(CString cCadena)
{
	m_strEtiqueta2 = cCadena;
}

void CValorDual::EstableceValor(double dValor)
{
	m_dValor = dValor;
}

void CValorDual::EstableceValor(CString cCadena)
{
	m_dValor = CStrToDouble(cCadena);
}

void CValorDual::EstableceConStruct(StcValorDual * stcValDual)
{
	m_strEtiqueta1 = stcValDual->strEtiqueta1;
	m_strEtiqueta2 = stcValDual->strEtiqueta2;
	m_dValor = stcValDual->dValor;
}

//////////////////////////////////////////////////////////////////////
//	Output Data
//////////////////////////////////////////////////////////////////////

CString CValorDual::DevuelveEtiqueta1()
{
	return m_strEtiqueta1;
}

CString CValorDual::DevuelveEtiqueta2()
{
	return m_strEtiqueta2;
}

double CValorDual::DevuelveValor()
{
	return m_dValor;
}

CString CValorDual::DevuelveValorAsStr()
{
	return DoubleToCStr(m_dValor);
}

StcValorDual CValorDual::DevuelveStruct()
{
	StcValorDual stcValDual;
	stcValDual.dValor = m_dValor;
	_tcscpy(stcValDual.strEtiqueta1, m_strEtiqueta1);
	_tcscpy(stcValDual.strEtiqueta2, m_strEtiqueta2);

	return stcValDual;
}

CString CValorDual::DevuelveEtiquetas()
{
	return m_strEtiqueta1 + _T(", ") + m_strEtiqueta2;
}

CString CValorDual::DevuelveEtiquetasInvertidas()
{
	return m_strEtiqueta2 + _T(", ") + m_strEtiqueta1;
}

//////////////////////////////////////////////////////////////////////
//	Operations
//////////////////////////////////////////////////////////////////////

const CValorDual& CValorDual::operator =(const CValorDual & cValorDual)
{
	m_strEtiqueta1 = cValorDual.m_strEtiqueta1;
	m_strEtiqueta2 = cValorDual.m_strEtiqueta2;
	m_dValor = cValorDual.m_dValor;

	return *this;
}

void CValorDual::Serialize(CArchive & ar)
{
	
	if (ar.IsStoring())
	{
		ar << m_strEtiqueta1 ;
		ar << m_strEtiqueta2 ;
		ar << m_dValor ;
	}
	else
	{
		ar >> m_strEtiqueta1 ;
		ar >> m_strEtiqueta2 ;
		ar >> m_dValor ;
	}

}
