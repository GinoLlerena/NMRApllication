// Spin.cpp: implementation of the CSpin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Spin.h"
#include "Material.h"
#include <gl\gl.h>
#include <gl\glu.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CSpin, CObject, 0)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpin::CSpin()
{
	m_cPuntoCentral.Establece(0,0,0);
	m_dRadio = 0.135;
	m_iSlices = 40;
	m_iStacks = 40;
	m_iElemento = 0;
	m_iColor = 15;
	m_strEtiqueta = _T("");
	m_bEstado = TRUE;	
}

CSpin::CSpin(const CSpin & cSpin)
{
	m_cPuntoCentral = cSpin.m_cPuntoCentral;
	m_dRadio = cSpin.m_dRadio;
	m_iSlices = cSpin.m_iSlices;
	m_iStacks = cSpin.m_iStacks;
	m_iElemento = cSpin.m_iElemento;
	m_iColor = cSpin.m_iColor;
	m_strEtiqueta = cSpin.m_strEtiqueta;
	m_bEstado = cSpin.m_bEstado;
}

CSpin::~CSpin()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CSpin::EstablecePtoCentral(CPunto cPto)
{ 
	m_cPuntoCentral = cPto;
}

void CSpin::EstableceRadio(double dValor)
{
	m_dRadio = dValor;
}

void CSpin::EstableceSlices(int iValor)
{
	m_iSlices = iValor;
}

void CSpin::EstableceStacks(int iValor)
{
	m_iStacks = iValor;
}

void CSpin::EstableceElemento(int iValor)
{
	m_iElemento = iValor;
}

void CSpin::EstableceColor(int iValor)
{
	m_iColor = iValor;
}

void CSpin::EstableceEtiqueta(CString cCadena)
{
	m_strEtiqueta = cCadena;
}

void CSpin::EstableceEstado(BOOL bLogico)
{
	m_bEstado = bLogico;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

CPunto CSpin::DevuelvePtoCentral()
{
	return m_cPuntoCentral;
}

int CSpin::DevuelveElemento()
{
	return m_iElemento;
}

CString CSpin::DevuelveEtiqueta()
{
	return m_strEtiqueta;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CSpin::Serialize(CArchive &fichero)
{
	if (fichero.IsStoring())
	{
		fichero << m_iSlices << m_iStacks << m_iElemento << m_iColor;
		fichero << m_dRadio << m_bEstado << m_strEtiqueta;

	}
	else
	{
		fichero >> m_iSlices >> m_iStacks >> m_iElemento >> m_iColor;
		fichero >> m_dRadio >> m_bEstado >>  m_strEtiqueta;
	}

	m_cPuntoCentral.Serialize(fichero);
}

void CSpin::MuestraImagen()
{
	if (m_bEstado)
	{
		GLUquadricObj *quadricObj;

		quadricObj = gluNewQuadric();
		gluQuadricDrawStyle(quadricObj, GLU_FILL);

		glTranslatef( (float)m_cPuntoCentral.DevuelveX(), (float) m_cPuntoCentral.DevuelveY(),
			(float) m_cPuntoCentral.DevuelveZ() );
		ss_InitMaterials();
		ss_SetTeaMaterial(m_iColor);
		gluSphere(quadricObj, m_dRadio, m_iSlices, m_iStacks);
		glTranslatef( (float)( -1 * m_cPuntoCentral.DevuelveX() ),
			(float)( -1 * m_cPuntoCentral.DevuelveY() ),
			(float)( -1 * m_cPuntoCentral.DevuelveZ() ) );

		gluDeleteQuadric(quadricObj);
	}
}

//////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////

const CSpin& CSpin::operator =(const CSpin & cSpin)
{
	m_cPuntoCentral = cSpin.m_cPuntoCentral;
	m_dRadio = cSpin.m_dRadio;	
	m_iSlices = cSpin.m_iSlices;
	m_iStacks = cSpin.m_iStacks;
	m_iElemento = cSpin.m_iElemento;
	m_iColor = cSpin.m_iColor;	
	m_strEtiqueta = cSpin.m_strEtiqueta;
	m_bEstado = cSpin.m_bEstado;	

	return *this;
}
