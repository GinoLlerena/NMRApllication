// Seleccionadora.cpp: implementation of the CSeleccionadora class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Seleccionadora.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSeleccionadora::CSeleccionadora()
{
	m_iCantidadDatos = -1;
   m_iLimite = 24;

	for(int iPaso = 0; iPaso <= m_iLimite; iPaso++)
	{
		m_stDatos[iPaso].m_dValor = 0.0;
		m_stDatos[iPaso].m_iIndice = 0;
	}
}

CSeleccionadora::~CSeleccionadora()
{

}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

int CSeleccionadora::DevuelveIndice(int iIndice)
{
	return m_stDatos[iIndice].m_iIndice;
}

int CSeleccionadora::DevuelveCantidadDatos()
{
	return m_iCantidadDatos;
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CSeleccionadora::BuscaDondeGuardar(StcDatos stDato)
{
	BOOL bBandera = FALSE;
  if ( m_iCantidadDatos < 0 )
  {
     m_stDatos[0] = stDato;
     m_iCantidadDatos += 1;
  }
  else
  {
	for(int i = 0; i <= m_iCantidadDatos; i++)
	 if(m_stDatos[i].m_dValor > stDato.m_dValor)
	 { 
		 GuardaEnPosicion(i, stDato);
		 bBandera = TRUE;
		 break;
	 }
	
	 if(m_iCantidadDatos < m_iLimite  && !bBandera)
	     GuardaEnPosicion(m_iCantidadDatos + 1, stDato);
  }
}

void CSeleccionadora::GuardaEnPosicion(int iIndice, StcDatos stDato)
{
	if ( iIndice > m_iCantidadDatos && iIndice <= m_iLimite ) 
     m_stDatos[iIndice] = stDato;
	else {
		for(int i = m_iLimite ; i > iIndice; i--)
	      m_stDatos[i] = m_stDatos[i-1];
		m_stDatos[iIndice] = stDato;
	}
	if ( m_iCantidadDatos < m_iLimite ) 
		  m_iCantidadDatos += 1;

}

void CSeleccionadora::Inicializate()
{
	m_iCantidadDatos = -1;
   m_iLimite = 24;

	for(int iPaso = 0; iPaso <= m_iLimite; iPaso++)
	{
		m_stDatos[iPaso].m_dValor = 0.0;
		m_stDatos[iPaso].m_iIndice = 0;
	}
}
