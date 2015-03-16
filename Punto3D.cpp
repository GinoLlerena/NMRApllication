// Punto3D.cpp: implementation of the CPunto class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Punto3D.h"
#include "Trigonom.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CPunto, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPunto::CPunto()
{
	m_dX = m_dY = m_dZ = 0.0;
}

CPunto::CPunto(double dX, double dY, double dZ)
{
	m_dX = dX;
	m_dY = dY;
	m_dZ = dZ;
}

CPunto::CPunto(const CPunto & cPto)
{
	m_dX = cPto.m_dX;
	m_dY = cPto.m_dY;
	m_dZ = cPto.m_dZ;
}

CPunto::~CPunto()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CPunto::Establece(double dX, double dY, double dZ)
{
	m_dX = dX;
	m_dY = dY;
	m_dZ = dZ;
}

void CPunto::EstableceX(double dValor)
{
	m_dX = dValor;
}

void CPunto::EstableceY(double dValor)
{
	m_dY = dValor;
}

void CPunto::EstableceZ(double dValor)
{
	m_dZ = dValor;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

double CPunto::DevuelveX()
{
	return m_dX;
}

double CPunto::DevuelveY()
{
	return m_dY;
}

double CPunto::DevuelveZ()
{
	return m_dZ;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CPunto::Serialize(CArchive & fichero)
{
	if (fichero.IsStoring())
	{
		fichero << m_dX << m_dY << m_dZ;
	}
	else
	{
		fichero >> m_dX >> m_dY >> m_dZ;
	}
}

void CPunto::Rota3D(CPunto cPto, double dAnguloValor)
{
	double dDistancia,
		dCoeffA, dCoeffB, dCoeffC,
		dFactorA, dFactorB,
		dFactorC, dFactorD,
		dFactorE, dFactorF,
		dFactorG, dFactorH,
		dFactorI,
		dNewEquis, dNewYe, dNewZeta;

	// Conversión de Grados a Radianes
	dAnguloValor = degreesToRadians(dAnguloValor);

	dDistancia = sqrt( pow( cPto.DevuelveX(), 2 ) + pow( cPto.DevuelveY(), 2 ) +
		pow( cPto.DevuelveZ(), 2 ) );

	dCoeffA = cPto.DevuelveX() / dDistancia;
	dCoeffB = cPto.DevuelveY() / dDistancia;
	dCoeffC = cPto.DevuelveZ() / dDistancia;

	dFactorA = pow( dCoeffA, 2 ) + ( 1 - pow( dCoeffA, 2 ) ) * cos(dAnguloValor);
	dFactorB = dCoeffA * dCoeffB * ( 1 - cos(dAnguloValor) ) + dCoeffC * sin(dAnguloValor);
	dFactorC = dCoeffA * dCoeffC * ( 1 - cos(dAnguloValor) ) - dCoeffB *	sin(dAnguloValor);
	dFactorD = dCoeffA * dCoeffB * ( 1 - cos(dAnguloValor) ) - dCoeffC *	sin(dAnguloValor);
	dFactorE = pow( dCoeffB, 2 ) + ( 1 - pow( dCoeffB, 2 ) ) * cos(dAnguloValor);
	dFactorF = dCoeffB * dCoeffC * ( 1 - cos(dAnguloValor) ) + dCoeffA *	sin(dAnguloValor);
	dFactorG = dCoeffA * dCoeffC * ( 1 - cos(dAnguloValor) ) + dCoeffB *	sin(dAnguloValor);
	dFactorH = dCoeffB * dCoeffC * ( 1 - cos(dAnguloValor) ) - dCoeffA *	sin(dAnguloValor);
	dFactorI = pow( dCoeffC, 2 ) + ( 1 - pow( dCoeffC, 2 ) ) * cos(dAnguloValor);

	dNewEquis = m_dX * dFactorA + m_dY * dFactorD + m_dZ * dFactorG;
	dNewYe = m_dX * dFactorB + m_dY * dFactorE + m_dZ * dFactorH;
	dNewZeta = m_dX * dFactorC + m_dY * dFactorF + m_dZ * dFactorI;

	m_dX = dNewEquis;
	m_dY = dNewYe;
	m_dZ = dNewZeta;
}

void CPunto::Translada(double dX, double dY, double dZ)
{
	m_dX = m_dX + dX;
	m_dY = m_dY + dY;
	m_dZ = m_dZ + dZ;
}

void CPunto::Translada(CPunto cPto)
{
	m_dX = m_dX + cPto.m_dX;
	m_dY = m_dY + cPto.m_dY;
	m_dZ = m_dZ + cPto.m_dZ;
}

//////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////

const CPunto& CPunto::operator =(const CPunto & cPto)
{
	m_dX = cPto.m_dX;
	m_dY = cPto.m_dY;
	m_dZ = cPto.m_dZ;

	return *this;
}
