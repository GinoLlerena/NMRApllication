// Lado.cpp: implementation of the CLado class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Lado.h"
#include "Rutinas.h"
#include "CoordEsf.h"
#include "Trigonom.h"
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CLado, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLado::CLado()
{
	m_dRadio = 0.1;
	m_iRebanadas = 40;
	m_cPtoInicial.Establece(0.0, 0.0, 0.0);
	m_cPtoFinal.Establece(0.0, 0.0, 0.0);
	m_cAnguloTeta.EstableceValor(0.0);
	m_cAnguloPhi.EstableceValor(0.0);
	m_strEstado = _T("Fijo");
	m_strTipo = _T("Ninguno");
	m_dLongitud = 1.2;
	m_iIndiceEnlace = 0;
	m_strEtiqueta = _T(" ");
}

CLado::CLado(const CLado & cLado)
{
	m_dRadio = cLado.m_dRadio;
	m_iRebanadas = cLado.m_iRebanadas;
	m_cPtoInicial = cLado.m_cPtoInicial;
	m_cPtoFinal = cLado.m_cPtoFinal;
	m_cAnguloTeta = cLado.m_cAnguloTeta;
	m_cAnguloPhi = cLado.m_cAnguloPhi;
	m_strEstado = cLado.m_strEstado;
	m_strTipo = cLado.m_strTipo;
	m_dLongitud = cLado.m_dLongitud;
	m_iIndiceEnlace = cLado.m_iIndiceEnlace;
	m_strEtiqueta = cLado.m_strEtiqueta;
}

CLado::CLado(CPunto cPtoInicial, CPunto cPtoFinal)
{ 
	m_dRadio = 0.1;
	m_iRebanadas = 40;
	m_strEstado = _T("");
	m_strTipo = _T("Ninguno");
	m_iIndiceEnlace = 0;
	Establece(cPtoInicial, cPtoFinal);

	CCoordEsf cCoorEsf(cPtoInicial, cPtoFinal);
	m_cAnguloTeta = cCoorEsf.DevuelveAnguloTeta();
	m_cAnguloPhi = cCoorEsf.DevuelveAnguloPhi();
	m_strEtiqueta = _T("");
}

CLado::~CLado()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CLado::Establece(CPunto cPtoInicial, CPunto cPtoFinal)
{ 
	m_cPtoInicial = cPtoInicial;
	m_cPtoFinal = cPtoFinal;
	m_dLongitud = CalculaDistancia(cPtoInicial, cPtoFinal);

	CCoordEsf cCoorEsf(cPtoInicial, cPtoFinal);
	m_cAnguloTeta = cCoorEsf.DevuelveAnguloTeta();
	m_cAnguloPhi = cCoorEsf.DevuelveAnguloPhi();	
}

void CLado::EstableceIndiceEnlace(int iValor)
{
	m_iIndiceEnlace = iValor;
}

void CLado::EstableceLongitud(double dValor)
{
	m_dLongitud = dValor;
}

void CLado::EstableceEstado(CString cCadena)
{
	m_strEstado = cCadena;
}

void CLado::EstableceTipo(CString cCadena)
{
	m_strTipo = cCadena;
}

void CLado::EstableceEtiqueta(CString cCadena)
{
	m_strEtiqueta = cCadena;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

int CLado::DevuelveIndiceEnlace()
{
	return m_iIndiceEnlace;
}

double CLado::DevuelveRadio()
{
	return m_dRadio;
}

double CLado::DevuelveLongitud()
{
	return m_dLongitud;
}

CPunto & CLado::DevuelvePtoInicial()
{
	CPunto & cPtoRef = m_cPtoInicial;
	return cPtoRef;
}

CPunto & CLado::DevuelvePtoFinal()
{
	CPunto & cPtoRef = m_cPtoFinal;
	return cPtoRef;
}

CAngulo & CLado::DevuelveAnguloTeta()
{
	CAngulo & cAnguloRef = m_cAnguloTeta;
	return cAnguloRef;
}

CAngulo & CLado::DevuelveAnguloPhi()
{
	CAngulo & cAnguloRef = m_cAnguloPhi;
	return cAnguloRef;
}

CString CLado::DevuelveEstado()
{
	return m_strEstado;
}

CString CLado::DevuelveTipo()
{
	return m_strTipo;
}

CString CLado::DevuelveEtiqueta()
{
	return m_strEtiqueta;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CLado::Serialize(CArchive & fichero)
{
	if (fichero.IsStoring())
	{
		fichero << m_dRadio << m_dLongitud << m_iRebanadas;
		fichero << m_iIndiceEnlace << m_strEstado << m_strTipo;
	}
	else
	{
		fichero >> m_dRadio >> m_dLongitud >> m_iRebanadas;
		fichero >> m_iIndiceEnlace >> m_strEstado >> m_strTipo;
	}

	m_cPtoInicial.Serialize(fichero);
	m_cPtoFinal.Serialize(fichero);
	m_cAnguloTeta.Serialize(fichero);
	m_cAnguloPhi.Serialize(fichero);
}

void CLado::Construye()
{
	GLUquadricObj *quadricObj;
	quadricObj = gluNewQuadric();

	CPunto cPtoTemp;
	CPunto cPtoAux = m_cPtoFinal;
	cPtoAux.Translada( (-1 * m_cPtoInicial.DevuelveX()), (-1 * m_cPtoInicial.DevuelveY()), 
		(-1 * m_cPtoInicial.DevuelveZ()) );

	glPushMatrix();
	glTranslatef( (float)m_cPtoInicial.DevuelveX(), (float)m_cPtoInicial.DevuelveY(), 
		(float)m_cPtoInicial.DevuelveZ() );

	int iPosicion = DeterminaPosicion(cPtoAux);

	if ((iPosicion != 13) && (iPosicion != 14))
		SituaEnEspacio(cPtoAux, iPosicion);
	else 
	{ 
		if (iPosicion == 13)
		{
			SituaEnEspacio(cPtoAux, iPosicion);
			cPtoTemp.Establece(cPtoAux.DevuelveX(), 0, cPtoAux.DevuelveY());
			iPosicion = DeterminaPosicion(cPtoTemp);
			SituaEnEspacio(cPtoAux, iPosicion);
		}
		else
		{	
			cPtoTemp.Establece(cPtoAux.DevuelveX(), 0, cPtoAux.DevuelveZ());
			iPosicion = DeterminaPosicion(cPtoTemp);
			SituaEnEspacio(cPtoTemp, iPosicion);
			double l = sqrt( pow(cPtoAux.DevuelveX(), 2) + pow(cPtoAux.DevuelveZ(), 2) );
			cPtoTemp.Establece(0, cPtoAux.DevuelveY(), l);
			iPosicion = DeterminaPosicion(cPtoTemp);
			SituaEnEspacio(cPtoTemp, iPosicion);
		}
	}
	
	gluQuadricDrawStyle(quadricObj, GLU_FILL);
	gluQuadricTexture(quadricObj, TRUE);
	gluCylinder(quadricObj, m_dRadio, m_dRadio, m_dLongitud, 25, 25);
	glPopMatrix();

	gluDeleteQuadric(quadricObj);
}

int CLado::DeterminaPosicion(CPunto cPto)
{
	int iPosicion = (-1 * 1);
   double dEquis = cPto.DevuelveX();
	double dYe = cPto.DevuelveY();
	double dZeta = cPto.DevuelveZ();
	
	if (dEquis == 0.0 && dYe == 0.0 && dZeta < 0.0) // eje Z
		iPosicion = 0;

	if (dEquis != 0.0 && dYe == 0.0 && dZeta == 0.0) // eje X
	{ 
		if (dEquis > 0)
			iPosicion = 1;
		else
			iPosicion = 2;
	}

	if (dEquis == 0.0 && dYe != 0.0 && dZeta == 0.0) // eje Y
	{	
		if (dYe > 0)
			iPosicion = 3;
		else
			iPosicion = 4;
	}

	if (dEquis != 0.0 && dYe == 0.0 && dZeta != 0.0) // plano XZ
	{
		if ( (dEquis > 0) && (dZeta > 0) ) iPosicion = 5; // 1er cuadrante
		if ( (dEquis > 0) && (dZeta < 0) ) iPosicion = 6; // 2do 
		if ( (dEquis < 0) && (dZeta < 0) ) iPosicion = 7; // 3ro
		if ( (dEquis < 0) && (dZeta > 0) ) iPosicion = 8; // 4to
	}

	if (dEquis == 0.0 && dYe != 0.0 && dZeta != 0.0) // eje YZ
	{
		if ( (dYe > 0) && (dZeta > 0) ) iPosicion = 9;  //1er
		if ( (dYe > 0) && (dZeta < 0) ) iPosicion = 10; //2do
		if ( (dYe < 0) && (dZeta < 0) ) iPosicion = 11; //3ro
		if ( (dYe < 0) && (dZeta > 0) ) iPosicion = 12; //4to
	}

	if (dEquis != 0.0 && dYe != 0.0 && dZeta == 0.0) // eje XY
	{
		 iPosicion = 13;
	}
	
	if (dEquis != 0.0 && dYe != 0.0 && dZeta != 0.0)
		iPosicion = 14;

	return (iPosicion);    
}

void CLado::SituaEnEspacio(CPunto cPtoAux, int iPosicion)
{
	double dAnguloValor;

	switch (iPosicion)
	{
		case 0:
			glRotatef(180, 0.0f, 1.0f, 0.0f);
			break;
		case 1:
			glRotatef(90, 0.0f, 1.0f, 0.0f);
			break;
		case 2:
			glRotatef( (-1 * 90), 0.0f, 1.0f, 0.0f );
			break;
		case 3:
			glRotatef( (-1 * 90), 1.0f, 0.0f, 0.0f );
			break;
		case 4:
			glRotatef(90, 1.0f, 0.0f, 0.0f);
			break;
		case 5:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveX() / cPtoAux.DevuelveZ() ) );
			glRotatef( (float)dAnguloValor, 0.0f, 1.0f, 0.0f );
			break;
		case 6:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveX() /
				cPtoAux.DevuelveZ() ) )	+ 180;
			glRotatef( (float)dAnguloValor, 0.0f, 1.0f, 0.0f );
			break;
		case 7:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveX() /
				cPtoAux.DevuelveZ() ) ) + 180;
			glRotatef( (float)dAnguloValor, 0.0f, 1.0f, 0.0f );
			break;
		case 8:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveX() /
				cPtoAux.DevuelveZ() ) ) + 360;
			glRotatef( (float)dAnguloValor, 0.0f, 1.0f, 0.0f );
			break;
		case 9:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveY() / cPtoAux.DevuelveZ() ) );
			glRotatef( (float)(-1 * dAnguloValor), 1.0f, 0.0f, 0.0f );
			break;
		case 10:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveY() /
				cPtoAux.DevuelveZ() ) ) + 180;
			glRotatef( (float)(-1 * dAnguloValor), 1.0f, 0.0f, 0.0f );
			break;
		case 11:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveY() /
				cPtoAux.DevuelveZ() ) ) + 180;
			glRotatef( (float)(-1 * dAnguloValor), 1.0f, 0.0f, 0.0f );
			break;
		case 12:
			dAnguloValor = radiansToDegrees( atan( cPtoAux.DevuelveY() /
				cPtoAux.DevuelveZ() ) )	+ 360;
			glRotatef( (float)(-1 * dAnguloValor), 1.0f, 0.0f, 0.0f );
			break;
		case 13:
			glRotatef( (float)(-1 * 90), 1.0f, 0.0f, 0.0f );
			break;
	}
}

void CLado::MuestraLineaGDI(CDC *pDC, int iFactor, CString cPlano)
{
	if ( cPlano == _T("XY") )
	{
		pDC->MoveTo( (int)(m_cPtoInicial.DevuelveX() * iFactor),
			(int)(m_cPtoInicial.DevuelveY() * iFactor) );
		pDC->LineTo( (int)(m_cPtoFinal.DevuelveX() * iFactor),
			(int)(m_cPtoFinal.DevuelveY() * iFactor) );
	}

	if ( cPlano == _T("XZ") )
	{
		pDC->MoveTo( (int)(m_cPtoInicial.DevuelveX() * iFactor),
			(int)(m_cPtoInicial.DevuelveZ() * iFactor) );
		pDC->LineTo( (int)(m_cPtoFinal.DevuelveX() * iFactor),
			(int)(m_cPtoFinal.DevuelveZ() * iFactor) );
	}

	if ( cPlano == _T("YX") )
	{
		pDC->MoveTo( (int)(m_cPtoInicial.DevuelveY() * iFactor),
			(int)(m_cPtoInicial.DevuelveX() * iFactor) );
		pDC->LineTo( (int)(m_cPtoFinal.DevuelveY() * iFactor),
			(int)(m_cPtoFinal.DevuelveX() * iFactor) );
	}

	if ( cPlano == _T("YZ") )
	{
		pDC->MoveTo( (int)(m_cPtoInicial.DevuelveY() * iFactor),
			(int)(m_cPtoInicial.DevuelveZ() * iFactor) );
		pDC->LineTo( (int)(m_cPtoFinal.DevuelveY() * iFactor),
			(int)(m_cPtoFinal.DevuelveZ() * iFactor) );
	}

	if ( cPlano == _T("ZX") )
	{
		pDC->MoveTo( (int)(m_cPtoInicial.DevuelveZ() * iFactor),
			(int)(m_cPtoInicial.DevuelveX() * iFactor) );
		pDC->LineTo( (int)(m_cPtoFinal.DevuelveZ() * iFactor),
			(int)(m_cPtoFinal.DevuelveX() * iFactor) );
	}

	if ( cPlano == _T("ZY") )
	{
		pDC->MoveTo( (int)(m_cPtoInicial.DevuelveZ() * iFactor),
			(int)(m_cPtoInicial.DevuelveY() * iFactor) );
		pDC->LineTo( (int)(m_cPtoFinal.DevuelveZ() * iFactor),
			(int)(m_cPtoFinal.DevuelveY() * iFactor) );
	}
}

//////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////

const CLado& CLado::operator =(const CLado & cCilin)
{
	m_iRebanadas = cCilin.m_iRebanadas;
	m_iIndiceEnlace = cCilin.m_iIndiceEnlace;
	m_dRadio = cCilin.m_dRadio;
	m_dLongitud = cCilin.m_dLongitud ;
	m_cPtoInicial = cCilin.m_cPtoInicial;
	m_cPtoFinal = cCilin.m_cPtoFinal;
	m_cAnguloTeta = cCilin.m_cAnguloTeta;
	m_cAnguloPhi = cCilin.m_cAnguloPhi;
	m_strEstado = cCilin.m_strEstado ;
	m_strTipo = cCilin.m_strTipo ;
	m_strEtiqueta = cCilin.m_strEtiqueta;

	return *this;
}
