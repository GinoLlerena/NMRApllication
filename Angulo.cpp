// Angulo.cpp: implementation of the CAngulo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Angulo.h"
#include "Trigonom.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CAngulo, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAngulo::CAngulo()
{
	m_dValor = 0.0;
	m_strEstado = _T("Fijo");
	m_strEtiqueta = _T("");
}

CAngulo::CAngulo(double dValor)
{
	m_dValor = dValor;
	m_strEstado = _T("Fijo");
	m_strEtiqueta = _T("");
}

CAngulo::CAngulo(const CAngulo & cAngulo)
{
	m_dValor = cAngulo.m_dValor;
	m_strEstado = cAngulo.m_strEstado;
	m_strEtiqueta = cAngulo.m_strEtiqueta;
}

CAngulo::~CAngulo()
{

}
	
//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CAngulo::EstableceValor(double dValor, Medida nUnidad)
{
	switch (nUnidad)
	{
		case Grados:
			m_dValor = dValor;
			break;
		case Radianes:
			m_dValor = radiansToDegrees(dValor);
			break;
	}
}

void CAngulo::EstableceEstado(CString cCadena)
{
	m_strEstado = cCadena;
}

void CAngulo::EstableceEtiqueta(CString cCadena)
{
	m_strEtiqueta = cCadena;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

double CAngulo::DevuelveValor(Medida nUnidad)
{
	switch (nUnidad)
	{
		case Grados:
			return m_dValor;
		case Radianes:
			return degreesToRadians(m_dValor);
	}

	return 0;
}

CString CAngulo::DevuelveEstado()
{
	return m_strEstado;
}

CString CAngulo::DevuelveEtiqueta()
{
	return m_strEtiqueta;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CAngulo::Serialize(CArchive &fichero)
{
   if (fichero.IsStoring())
	{
		fichero << m_dValor;
		fichero << m_strEstado;
		fichero << m_strEtiqueta;
	}
	else
	{
		fichero >> m_dValor;
		fichero >> m_strEstado;
		fichero >> m_strEtiqueta;
	}
}

//////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////

const CAngulo& CAngulo::operator =(const CAngulo & cAngulo)
{
	m_dValor = cAngulo.m_dValor;
	m_strEstado = cAngulo.m_strEstado;
	m_strEtiqueta = cAngulo.m_strEtiqueta;

	return *this;
}
