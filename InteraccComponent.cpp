// InteraccComponent.cpp: implementation of the CInteraccComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InteraccComponent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CInteraccComponent, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInteraccComponent::CInteraccComponent()
{
	m_strEtiquetaBase1 = _T("");
	m_strEtiquetaBase2 = _T("");
}

CInteraccComponent::~CInteraccComponent()
{

}

CInteraccComponent::CInteraccComponent(const CInteraccComponent & cInteraccComponente)
{
	m_strEtiqueta1 = cInteraccComponente.m_strEtiqueta1;
	m_strEtiqueta2 = cInteraccComponente.m_strEtiqueta2;
	m_dValor = cInteraccComponente.m_dValor;
	m_strEtiquetaBase1 = cInteraccComponente.m_strEtiquetaBase1;
	m_strEtiquetaBase2 = cInteraccComponente.m_strEtiquetaBase2;
	m_cCoordEsf = cInteraccComponente.m_cCoordEsf;

	for (int iPaso = 0; iPaso < limCoeff; iPaso++)
		m_dCoefficient[iPaso] = cInteraccComponente.m_dCoefficient[iPaso];

}

void CInteraccComponent::EstableceEtiquetaBase1(CString cCadena)
{
	m_strEtiquetaBase1 = cCadena;
}

void CInteraccComponent::EstableceEtiquetaBase2(CString cCadena)
{
	m_strEtiquetaBase2 = cCadena;
}

CString CInteraccComponent::DevuelveEtiquetaBase1()
{
	return m_strEtiquetaBase1;
}

CString CInteraccComponent::DevuelveEtiquetaBase2()
{
	return m_strEtiquetaBase2;
}

CString CInteraccComponent::DevuelveEtiquetasBase()
{
	return m_strEtiquetaBase1 + _T(", ") + m_strEtiquetaBase2;
}

void CInteraccComponent::Serialize(CArchive & archive)
{
	CInteraccCalculada::Serialize(archive);

	if (archive.IsStoring())
	{
		archive << m_strEtiquetaBase1;
		archive << m_strEtiquetaBase2;
	}
	else
	{
		archive >> m_strEtiquetaBase1;
		archive >> m_strEtiquetaBase2;
	}	
}

const CInteraccComponent& CInteraccComponent::operator =(const CInteraccComponent&
																			cInteraccComponente)
{
	m_strEtiqueta1 = cInteraccComponente.m_strEtiqueta1;
	m_strEtiqueta2 = cInteraccComponente.m_strEtiqueta2;
	m_dValor = cInteraccComponente.m_dValor;
	m_strEtiquetaBase1 = cInteraccComponente.m_strEtiquetaBase1;
	m_strEtiquetaBase2 = cInteraccComponente.m_strEtiquetaBase2;
	m_cCoordEsf = cInteraccComponente.m_cCoordEsf;

	for (int iPaso = 0; iPaso < limCoeff; iPaso++)
		m_dCoefficient[iPaso] = cInteraccComponente.m_dCoefficient[iPaso];

	return *this;
}

