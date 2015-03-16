// CoordEsf.cpp: implementation of the CCoordEsf class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CoordEsf.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCoordEsf::CCoordEsf() : m_cAnguloPhi(), m_cAnguloTeta()
{
	m_dDistancia = 0.0;
}

CCoordEsf::~CCoordEsf()
{

}

CCoordEsf::CCoordEsf(CPunto cPtoInicial, CPunto cPtoFinal) : m_cAnguloPhi(), m_cAnguloTeta()
{
	m_dDistancia = 0.0;
	Establece(cPtoInicial, cPtoFinal);
}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CCoordEsf::Establece(CPunto cPtoInicial, CPunto cPtoFinal)
{
	double dEquis = (cPtoFinal.DevuelveX() - cPtoInicial.DevuelveX());
	double dYe = (cPtoFinal.DevuelveY() - cPtoInicial.DevuelveY());
	double dZeta = (cPtoFinal.DevuelveZ() - cPtoInicial.DevuelveZ());
	m_dDistancia = sqrt(pow(dEquis, 2) + pow(dYe, 2) + pow(dZeta, 2));
	m_cAnguloPhi.EstableceValor(acos(dZeta / m_dDistancia), Radianes);
	
	if (dEquis != 0)
		m_cAnguloTeta.EstableceValor(atan(dYe / dEquis), Radianes);
	else
		m_cAnguloTeta.EstableceValor(90.0);
}

void CCoordEsf::Establece(CPunto cPto)
{
	double dEquis = cPto.DevuelveX();
	double dYe = cPto.DevuelveY();
	double dZeta = cPto.DevuelveZ();
	m_dDistancia = sqrt(pow(dEquis, 2) + pow(dYe, 2) + pow(dZeta, 2));
	m_cAnguloPhi.EstableceValor(acos(dZeta / m_dDistancia), Radianes);
	
	if (dEquis != 0)
		m_cAnguloTeta.EstableceValor(atan(dYe / dEquis), Radianes);
	else
		m_cAnguloTeta.EstableceValor(90.0);
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

CAngulo CCoordEsf::DevuelveAnguloPhi()
{
	return m_cAnguloPhi;
}

CAngulo CCoordEsf::DevuelveAnguloTeta()
{
	return m_cAnguloTeta;
}

double CCoordEsf::DevuelveDistancia()
{
	return m_dDistancia;
}

//////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////

const CCoordEsf& CCoordEsf::operator =(const CCoordEsf & cCoord)
{
	m_cAnguloPhi = cCoord.m_cAnguloPhi;
	m_cAnguloTeta = cCoord.m_cAnguloTeta;
	m_dDistancia = cCoord.m_dDistancia;

	return *this;
}
