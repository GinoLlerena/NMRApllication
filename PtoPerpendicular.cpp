// PtoPerpendicular.cpp: implementation of the CPtoPerpendicular class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PtoPerpendicular.h"
#include "Rutinas.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPtoPerpendicular::CPtoPerpendicular()
{
	m_cPtoA.Establece(0,0,0);
	m_cPtoB.Establece(0,0,0);
	m_cPtoC.Establece(0,0,0);
	m_cPtoPerpendicular.Establece(0,0,0);
	m_dRadio = 0.0;
}

CPtoPerpendicular::CPtoPerpendicular(CPunto ptoA, CPunto ptoB, CPunto ptoC, double dRadio)
{
	EstablecePtoPerpendicular(ptoA,ptoB,ptoC,dRadio);
}

CPtoPerpendicular::~CPtoPerpendicular()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CPtoPerpendicular::EstablecePtoPerpendicular(CPunto ptoA, CPunto ptoB, CPunto ptoC, double dRadio)
{
	CPunto cTmp(0,0,0);
	m_cPtoA = ptoA;
	m_cPtoB = ptoB;
	m_cPtoC = ptoC;
	m_cPtoPerpendicular = m_cPtoA;
	m_dRadio = dRadio;
	int nPos = ObtienePosicionEspacial();
	
	ObtienePtoPerpendicular(nPos);
	
	if(nPos==7)
	{
		double d = CalculaDistancia(cTmp, m_cPtoPerpendicular);
		m_cPtoPerpendicular = Conversor(cTmp, m_cPtoPerpendicular, m_dRadio / d );
		m_cPtoPerpendicular.Translada(ptoA);
	}	
}

void CPtoPerpendicular::EstablecePtoPerpendicular(CPunto ptoA, CPunto ptoB, CPunto ptoC)
{
	CPunto cTmp(0,0,0);
	m_cPtoA = ptoA;
	m_cPtoB = ptoB;
	m_cPtoC = ptoC;
	m_cPtoPerpendicular = m_cPtoA;

	m_cPtoPerpendicular.EstableceX( (m_cPtoB.DevuelveY()- m_cPtoA.DevuelveY())*(m_cPtoC.DevuelveZ() - m_cPtoA.DevuelveZ()) 
			- (m_cPtoC.DevuelveY() - m_cPtoA.DevuelveY())*(m_cPtoB.DevuelveZ() - m_cPtoA.DevuelveZ()) );
	m_cPtoPerpendicular.EstableceY( (m_cPtoB.DevuelveZ() - m_cPtoA.DevuelveZ())*(m_cPtoC.DevuelveX() - m_cPtoA.DevuelveX())
			- (m_cPtoB.DevuelveX() - m_cPtoA.DevuelveX())*(m_cPtoC.DevuelveZ() - m_cPtoA.DevuelveZ()) );
	m_cPtoPerpendicular.EstableceZ( (m_cPtoB.DevuelveX() - m_cPtoA.DevuelveX())*(m_cPtoC.DevuelveY() - m_cPtoA.DevuelveY()) 
			- (m_cPtoC.DevuelveX() - m_cPtoA.DevuelveX())*(m_cPtoB.DevuelveY() - m_cPtoA.DevuelveY()) );
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

CPunto CPtoPerpendicular::DevuelvePtoPerpendicular()
{
	return m_cPtoPerpendicular;
}

CPunto CPtoPerpendicular::DevuelveEjeRotacion()
{
	return m_cEjeRotacion;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

int CPtoPerpendicular::ObtienePosicionEspacial()
{
	CPunto	cVector; 

	cVector.Establece((m_cPtoA.DevuelveX() - m_cPtoB.DevuelveX()),
	(m_cPtoA.DevuelveY() - m_cPtoB.DevuelveY()),
	(m_cPtoA.DevuelveZ() - m_cPtoB.DevuelveZ()));

	int n;

	if ((cVector.DevuelveX()!=0) && (cVector.DevuelveY()==0) && (cVector.DevuelveZ()==0))
		n=1;

	if ((cVector.DevuelveX()==0) && (cVector.DevuelveY()!=0) && (cVector.DevuelveZ()==0))
		n=2;

	if ((cVector.DevuelveX()==0) && (cVector.DevuelveY()==0) && (cVector.DevuelveZ()!=0))
		n=3;

	if ((cVector.DevuelveX()!=0) && (cVector.DevuelveY()==0) && (cVector.DevuelveZ()!=0))
		n=4;

	if ((cVector.DevuelveX()!=0) && (cVector.DevuelveY()!=0) && (cVector.DevuelveZ()==0))
		n=5;

	if ((cVector.DevuelveX()==0) && (cVector.DevuelveY()!=0) && (cVector.DevuelveZ()!=0))
		n=6;

	if ((cVector.DevuelveX()!=0) && (cVector.DevuelveY()!=0) && (cVector.DevuelveZ()!=0))
	  n=7;

	return n;
}

void CPtoPerpendicular::ObtienePtoPerpendicular(int n)
{
	 switch(n) {
	 case 1 :
			m_cPtoPerpendicular.EstableceY(m_cPtoPerpendicular.DevuelveY() + m_dRadio);
		break;
	 case 2 :
			m_cPtoPerpendicular.EstableceZ(m_cPtoPerpendicular.DevuelveZ() + m_dRadio);
	  break;
	 case 3 :
			m_cPtoPerpendicular.EstableceX(m_cPtoPerpendicular.DevuelveX() + m_dRadio);
	  break;
	 case 4 :
			m_cPtoPerpendicular.EstableceY(m_cPtoPerpendicular.DevuelveY() + m_dRadio);
	  break;
	 case 5 :
			m_cPtoPerpendicular.EstableceZ(m_cPtoPerpendicular.DevuelveZ() + m_dRadio);
	  break;
	 case 6 :
		   m_cPtoPerpendicular.EstableceX(m_cPtoPerpendicular.DevuelveX() + m_dRadio);
	  break;
	 case 7 :
		m_cPtoPerpendicular.EstableceX( (m_cPtoB.DevuelveY()- m_cPtoA.DevuelveY())*(m_cPtoC.DevuelveZ() - m_cPtoA.DevuelveZ()) 
			- (m_cPtoC.DevuelveY() - m_cPtoA.DevuelveY())*(m_cPtoB.DevuelveZ() - m_cPtoA.DevuelveZ()) );
		m_cPtoPerpendicular.EstableceY( (m_cPtoB.DevuelveZ() - m_cPtoA.DevuelveZ())*(m_cPtoC.DevuelveX() - m_cPtoA.DevuelveX())
			- (m_cPtoB.DevuelveX() - m_cPtoA.DevuelveX())*(m_cPtoC.DevuelveZ() - m_cPtoA.DevuelveZ()) );
		m_cPtoPerpendicular.EstableceZ( (m_cPtoB.DevuelveX() - m_cPtoA.DevuelveX())*(m_cPtoC.DevuelveY() - m_cPtoA.DevuelveY()) 
			- (m_cPtoC.DevuelveX() - m_cPtoA.DevuelveX())*(m_cPtoB.DevuelveY() - m_cPtoA.DevuelveY()) );

	  break;
	 }
}
