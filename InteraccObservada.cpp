// InteraccObservada.cpp: implementation of the CInteraccObservada class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InteraccObservada.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CInteraccObservada, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInteraccObservada::CInteraccObservada() : CInteraccion()
{
	m_bUsoTzz = FALSE;
	m_bUsoTxxMinusTyy = FALSE;
	m_bUsoTyz = FALSE;
	m_bUsoTzx = FALSE;
	m_bUsoTxy = FALSE;
}

CInteraccObservada::CInteraccObservada(const CInteraccObservada & cInteraccObs)
{
	m_strEtiqueta1 = cInteraccObs.m_strEtiqueta1;
	m_strEtiqueta2 = cInteraccObs.m_strEtiqueta2;
	m_dValor = cInteraccObs.m_dValor;
	m_bUsoTzz = cInteraccObs.m_bUsoTzz;
	m_bUsoTxxMinusTyy = cInteraccObs.m_bUsoTxxMinusTyy;
	m_bUsoTyz = cInteraccObs.m_bUsoTyz;
	m_bUsoTzx = cInteraccObs.m_bUsoTzx;
	m_bUsoTxy = cInteraccObs.m_bUsoTxy;
}

CInteraccObservada::~CInteraccObservada()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CInteraccObservada::EstableceUsoTzz(BOOL bLogico)
{
	m_bUsoTzz = bLogico;
}

void CInteraccObservada::EstableceUsoTxxMinusTyy(BOOL bLogico)
{
	m_bUsoTxxMinusTyy = bLogico;
}

void CInteraccObservada::EstableceUsoTyz(BOOL bLogico)
{
	m_bUsoTyz = bLogico;
}

void CInteraccObservada::EstableceUsoTzx(BOOL bLogico)
{
	m_bUsoTzx = bLogico;
}

void CInteraccObservada::EstableceUsoTxy(BOOL bLogico)
{
	m_bUsoTxy = bLogico;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

BOOL CInteraccObservada::DevuelveUsoTzz()
{
	return m_bUsoTzz;
}

BOOL CInteraccObservada::DevuelveUsoTxxMinusTyy()
{
	return m_bUsoTxxMinusTyy;
}

BOOL CInteraccObservada::DevuelveUsoTyz()
{
	return m_bUsoTyz;
}

BOOL CInteraccObservada::DevuelveUsoTzx()
{
	return m_bUsoTzx;
}

BOOL CInteraccObservada::DevuelveUsoTxy()
{
	return m_bUsoTxy;
}

//////////////////////////////////////////////////////////////////////
// Operations 
//////////////////////////////////////////////////////////////////////

void CInteraccObservada::Serialize(CArchive & archive)
{
	CValorDual::Serialize(archive);

	if (archive.IsStoring())
	{
		archive << m_bUsoTzz;
		archive << m_bUsoTxxMinusTyy;
		archive << m_bUsoTyz;
		archive << m_bUsoTzx;
		archive << m_bUsoTxy;
	}
	else
	{
		archive >> m_bUsoTzz;
		archive >> m_bUsoTxxMinusTyy;
		archive >> m_bUsoTyz;
		archive >> m_bUsoTzx;
		archive >> m_bUsoTxy;
	}
}

//////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////

const CInteraccObservada& CInteraccObservada::operator =(const CInteraccObservada &
																			cInteraccObs)
{
	m_strEtiqueta1 = cInteraccObs.m_strEtiqueta1;
	m_strEtiqueta2 = cInteraccObs.m_strEtiqueta2;
	m_dValor = cInteraccObs.m_dValor;
	m_bUsoTzz = cInteraccObs.m_bUsoTzz;
	m_bUsoTxxMinusTyy = cInteraccObs.m_bUsoTxxMinusTyy;
	m_bUsoTyz = cInteraccObs.m_bUsoTyz;
	m_bUsoTzx = cInteraccObs.m_bUsoTzx;
	m_bUsoTxy = cInteraccObs.m_bUsoTxy;

	return *this;
}
