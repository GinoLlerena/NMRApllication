// ParteRigida.cpp: implementation of the CParteRigida class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParteRigida.h"
#include "Rutinas.h"
#include "Material.h"
#include "PtoPerpendicular.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CParteRigida, CObject, 0)

//////////////////////////////////////////////////////////////////////
//	Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParteRigida::CParteRigida() : m_cAngRotacion()
{	
	for (int iPaso = 0; iPaso < 12; iPaso++)
	{
		m_cAngulo[iPaso].EstableceValor(120.0);
		m_cPunto[iPaso].Establece(0.0, 0.0, 0.0);
		m_cAngulo[iPaso].EstableceEstado( _T("Fijo") );
		m_cAngulo[iPaso].EstableceEtiqueta( _T(" ") );
	}

	m_cAngulo[8].EstableceValor(0.0);
	m_cAngulo[11].EstableceValor(0.0);

	m_colorRef = RGB(0, 0, 255);
	m_iEstilo = PS_SOLID;
	m_iGrosor = 55;

}

CParteRigida::~CParteRigida() 
{

}

//////////////////////////////////////////////////////////////////////
//	Input Data
//////////////////////////////////////////////////////////////////////

void CParteRigida::EstableceColor(COLORREF colorRef)
{
	m_colorRef = colorRef;
}

void CParteRigida::EstableceEstilo(int iValor)
{
	m_iEstilo = iValor;
}

void CParteRigida::EstableceGrosor(int iValor)
{
	m_iGrosor = iValor;
}

void CParteRigida::EstableceParte(ParteRigida nParteRigida)
{
	m_nParteRigida = nParteRigida;
}

void CParteRigida::EstableceLado()
{
	int iPaso =	0;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			for (iPaso = 0; iPaso <= 4; iPaso++)	
				m_cLado[iPaso].Establece(m_cPunto[iPaso], m_cPunto[iPaso + 1]);

			m_cLado[iPaso].Establece(m_cPunto[5], m_cPunto[0]);
			
			for (iPaso = 0; iPaso <= 5; iPaso++)	
				m_cLado[iPaso + 6].Establece(m_cPunto[iPaso], m_cPunto[iPaso + 6]);
			break;

		case Bifenil:
			for (iPaso = 0; iPaso <= 1; iPaso++)
				m_cLado[iPaso].Establece(m_cPunto[iPaso], m_cPunto[iPaso + 1]);
			break;

		case Trifenil:
			for (iPaso = 0; iPaso <= 2; iPaso++)
				m_cLado[iPaso].Establece(m_cPunto[3], m_cPunto[iPaso]);
		
			m_cLado[iPaso].Establece(m_cPunto[4], m_cPunto[3]);
			break;
	}
}	

//////////////////////////////////////////////////////////////////////
//	Output Data
//////////////////////////////////////////////////////////////////////

CAngulo & CParteRigida::DevuelveAnguloRotacion()
{
	CAngulo & cAnguloRef = m_cAngRotacion;
	return cAnguloRef;
}

ParteRigida CParteRigida::DevuelveParte()
{
	return m_nParteRigida;
}

CLado & CParteRigida::DevuelveLado(int iIndice)
{
	CLado & cLadoRef = m_cLado[iIndice];
	return cLadoRef;
}

CSpin & CParteRigida::DevuelveSpin(int iIndice)
{
	CSpin & cSpinRef = m_cSpin[iIndice];
	return cSpinRef;
}

CPunto CParteRigida::DevuelvePunto(int iIndice)
{
	CPunto cPto;

	cPto = m_cPunto[iIndice];
	return cPto;
}

CAngulo & CParteRigida::DevuelveAngulo(int iIndice)
{
	CAngulo & cAnguloRef = m_cAngulo[iIndice];
	return cAnguloRef;
}

int CParteRigida::DevuelvePosiciones(int iIndice, CPunto & cPtoUno, CPunto & cPtoDos,
												 CPunto & cPtoTres)
{	
	int iRetorno = 0;

	if ( m_cLado[iIndice].DevuelveIndiceEnlace() && 
		m_cLado[iIndice].DevuelveTipo() == _T("Enlace") )
	{
		cPtoUno = m_cLado[iIndice].DevuelvePtoInicial();
		cPtoDos = m_cLado[iIndice].DevuelvePtoFinal();

		switch (m_nParteRigida)
		{
			case AnilloFenil:
				if (iIndice != 7)
					cPtoTres = m_cLado[0].DevuelvePtoFinal();
				else
					cPtoTres = m_cLado[5].DevuelvePtoInicial();
				break;

			case Bifenil:
				if(iIndice==0)
				{
					cPtoUno	 = m_cLado[iIndice].DevuelvePtoFinal();
					cPtoDos	 = m_cLado[iIndice].DevuelvePtoInicial();
					cPtoTres = m_cLado[1].DevuelvePtoFinal();
				}
				else {
						cPtoUno = m_cLado[iIndice].DevuelvePtoInicial();
						cPtoDos = m_cLado[iIndice].DevuelvePtoFinal();
						cPtoTres = m_cLado[0].DevuelvePtoInicial();
				}
				break;

			case Trifenil:
				if(iIndice==3)
				{
					cPtoUno	 = m_cLado[iIndice].DevuelvePtoFinal();
					cPtoDos	 = m_cLado[iIndice].DevuelvePtoInicial();
				}
				break;
		}

		iRetorno = m_cLado[iIndice].DevuelveIndiceEnlace();
	}

	return iRetorno; 
}

int CParteRigida::DevuelveTotSpines()
{
	int iTotalSpines = 0;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			iTotalSpines = 6;
			break;

		case Bifenil:
			iTotalSpines = 2;
			break;

		case Trifenil:
			iTotalSpines = 4;
			break;
	}

	return iTotalSpines;
}

int CParteRigida::DevuelveMaxEnlace()
{
	int iMaxIndice = 0;

	for (int iPaso = 0; iPaso < 12; iPaso++)
	{
		if (m_cLado[iPaso].DevuelveTipo() == _T("Enlace") && 
			m_cLado[iPaso].DevuelveIndiceEnlace() > iMaxIndice)
		{
			iMaxIndice = m_cLado[iPaso].DevuelveIndiceEnlace();
		}
	}

	return iMaxIndice;
}

BOOL CParteRigida::DevuelvePuntoEtTipo(CString cEtiqueta, CPunto & cPto, CString & cTipo)
{
	int iTotalSpines = 0;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			iTotalSpines = 5;
			break;

		case Bifenil:
			iTotalSpines = 2;
			break;

		case Trifenil:
			iTotalSpines = 4;
			break;
	}

	for (int iPaso = 0; iPaso <= iTotalSpines; iPaso++)	// Modify
	{
		if (m_cSpin[iPaso].DevuelveEtiqueta() == cEtiqueta)
		{
			//cPunto = m_cSpin[iPaso].DevuelvePtoCentral();

			switch (m_nParteRigida)
			{
				case AnilloFenil:
					cTipo = m_cLado[iPaso + 6].DevuelveTipo();
					cPto = m_cLado[iPaso + 6].DevuelvePtoFinal();
					break;

				case Bifenil:
				case Trifenil:
					cTipo = m_cLado[iPaso].DevuelveTipo();
					cPto = m_cLado[iPaso].DevuelvePtoFinal();
					break;
			}

			return TRUE;
		}
	}

	cTipo = _T("");
	return FALSE;
}		

//////////////////////////////////////////////////////////////////////
//	Operations
//////////////////////////////////////////////////////////////////////

void CParteRigida::Serialize(CArchive & fichero)
{
	int iPaso = 0;

	for (iPaso = 0; iPaso < 12; iPaso++)
		m_cLado[iPaso].Serialize(fichero);

	for (iPaso = 0; iPaso < 6; iPaso++)
		m_cSpin[iPaso].Serialize(fichero);

	for (iPaso = 0; iPaso < 12; iPaso++)
		m_cAngulo[iPaso].Serialize(fichero);

	for (iPaso = 0; iPaso < 12; iPaso++)
		m_cPunto[iPaso].Serialize(fichero);
	
	m_cAngRotacion.Serialize(fichero);
	
	if (fichero.IsStoring()) 
		fichero << DevStrParteRigida(m_nParteRigida);
	else
	{
		CString strTemp;
		fichero >> strTemp;
		m_nParteRigida = DevuelveIdParteRigida(strTemp);
	}
}

void CParteRigida::Construye(CPunto cPtoA, CPunto cPtoB, CPunto cPtoC)
{	
	double dDistancia = CalculaDistancia(cPtoA, cPtoB);
	
	CPunto cPtoAux(0,0,0);
	CPtoPerpendicular cPtoPerpendicular;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			cPtoPerpendicular.EstablecePtoPerpendicular(cPtoA, cPtoB, cPtoC);

			m_cPunto[8] = cPtoA;
			m_cPunto[2] = Conversor(cPtoA, cPtoB, m_cLado[8].DevuelveLongitud() / dDistancia);

			cPtoAux = cPtoPerpendicular.DevuelvePtoPerpendicular();

			m_cPunto[1] = GirarLado( m_cPunto[8], m_cPunto[2], cPtoAux, 
				( -1 * ( 180 - m_cAngulo[2].DevuelveValor(Grados) / 2 ) ), 
				m_cLado[1].DevuelveLongitud() );

			m_cPunto[3] = GirarLado( m_cPunto[8], m_cPunto[2], cPtoAux,
				( 180 - m_cAngulo[2].DevuelveValor(Grados) / 2 ), 
				m_cLado[2].DevuelveLongitud() );

			m_cPunto[0] = GirarLado( m_cPunto[2], m_cPunto[1], cPtoAux,
				m_cAngulo[1].DevuelveValor(Grados),
				m_cLado[0].DevuelveLongitud() );

			m_cPunto[4] = GirarLado( m_cPunto[2], m_cPunto[3], cPtoAux,
				( -1 * m_cAngulo[3].DevuelveValor(Grados) ),
				m_cLado[3].DevuelveLongitud() );

			m_cPunto[5] = GirarLado( m_cPunto[3], m_cPunto[4], cPtoAux,
				( -1 * m_cAngulo[0].DevuelveValor(Grados) ),
				m_cLado[5].DevuelveLongitud() );

			m_cPunto[6] = GirarLado( m_cPunto[5], m_cPunto[0], cPtoAux,
				m_cAngulo[6].DevuelveValor(Grados), 
				m_cLado[6].DevuelveLongitud() );

			m_cPunto[7] = GirarLado( m_cPunto[2], m_cPunto[1], cPtoAux,
				( -1 * m_cAngulo[7].DevuelveValor(Grados) ),
				m_cLado[7].DevuelveLongitud() );

			m_cPunto[9] = GirarLado( m_cPunto[2], m_cPunto[3], cPtoAux,
				m_cAngulo[9].DevuelveValor(Grados),
				m_cLado[9].DevuelveLongitud() );

			m_cPunto[10] = GirarLado( m_cPunto[5], m_cPunto[4], cPtoAux,
				( -1 * m_cAngulo[10].DevuelveValor(Grados) ),
				m_cLado[10].DevuelveLongitud() );

			m_cPunto[11] = GirarLado( m_cPunto[0], m_cPunto[5], cPtoAux,
				( -1 * (180 - m_cAngulo[5].DevuelveValor(Grados) / 2) ) + 
				m_cAngulo[11].DevuelveValor(Grados),
				m_cLado[11].DevuelveLongitud() );

			m_cPunto[8] = GirarLado( m_cPunto[1], m_cPunto[2], cPtoAux,
				(180 - m_cAngulo[2].DevuelveValor(Grados) / 2) -
				m_cAngulo[8].DevuelveValor(Grados),
				m_cLado[8].DevuelveLongitud() );

			break;

		case Bifenil :
			cPtoPerpendicular.EstablecePtoPerpendicular(cPtoA, cPtoB, cPtoC);
			cPtoAux = cPtoPerpendicular.DevuelvePtoPerpendicular();

			m_cPunto[0] = cPtoA;
			m_cPunto[1] = Conversor( cPtoA, cPtoB,
				(m_cLado[0].DevuelveLongitud() / dDistancia) );
			m_cPunto[2] = GirarLado( cPtoA, m_cPunto[1], cPtoAux,
				( 180 + m_cAngulo[0].DevuelveValor(Grados) ),
				m_cLado[1].DevuelveLongitud() );
			break;

		case Trifenil :
			m_cPunto[4] = cPtoA;
			m_cPunto[3] = Conversor( cPtoA, cPtoB,
				(m_cLado[3].DevuelveLongitud() / dDistancia) );

			double d = ( m_cLado[0].DevuelveLongitud() * 
				cos( m_cAngulo[0].DevuelveValor(Radianes) ) );

			m_cPunto[5] = Conversor( m_cPunto[4], m_cPunto[3], 
				(m_cLado[3].DevuelveLongitud() + d ) / m_cLado[3].DevuelveLongitud() ); //Punto Proyectado

			cPtoPerpendicular.EstablecePtoPerpendicular( m_cPunto[5], m_cPunto[3], cPtoAux,
				m_cLado[0].DevuelveLongitud() * sin( m_cAngulo[0].DevuelveValor(Radianes) ) );
			m_cPunto[0] = cPtoPerpendicular.DevuelvePtoPerpendicular();

			cPtoAux = m_cPunto[5];
			cPtoAux.Translada( ( -1 * m_cPunto[3].DevuelveX() ),
				( -1 * m_cPunto[3].DevuelveY() ),
				( -1 * m_cPunto[3].DevuelveZ() ) );
			m_cPunto[0].Translada( ( -1 * m_cPunto[3].DevuelveX() ),
				( -1 * m_cPunto[3].DevuelveY() ),						  
				( -1 * m_cPunto[3].DevuelveZ() ) );
			m_cPunto[0].Rota3D(cPtoAux, 90);
			m_cPunto[0].Translada(m_cPunto[3]);

			//////////////////////////////////////////////////////////////////////////////////

			d = ( m_cLado[1].DevuelveLongitud() * 
				cos( m_cAngulo[1].DevuelveValor(Radianes) ) );

			m_cPunto[5] = Conversor( m_cPunto[4], m_cPunto[3], 
				(m_cLado[3].DevuelveLongitud() + d ) / m_cLado[3].DevuelveLongitud() ); //Punto Proyectado

			cPtoPerpendicular.EstablecePtoPerpendicular( m_cPunto[5], m_cPunto[3], cPtoAux,
				m_cLado[1].DevuelveLongitud() * sin( m_cAngulo[1].DevuelveValor(Radianes) ) );
			m_cPunto[1] = cPtoPerpendicular.DevuelvePtoPerpendicular();
			cPtoAux = m_cPunto[5];
			cPtoAux.Translada( ( -1 * m_cPunto[3].DevuelveX() ),
				( -1 * m_cPunto[3].DevuelveY() ),
				( -1 * m_cPunto[3].DevuelveZ() ) );
			m_cPunto[1].Translada( ( -1 * m_cPunto[3].DevuelveX() ),
				( -1 * m_cPunto[3].DevuelveY() ),
				( -1 * m_cPunto[3].DevuelveZ() ) );
			m_cPunto[1].Rota3D(cPtoAux, m_cAngulo[6].DevuelveValor(Grados)+90 );
			m_cPunto[1].Translada(m_cPunto[3]);

			///////////////////////////////////////////////////////////////////////////////////

			d = ( m_cLado[2].DevuelveLongitud() * 
				cos( m_cAngulo[2].DevuelveValor(Radianes) ) );

			m_cPunto[5] = Conversor( m_cPunto[4], m_cPunto[3], 
				(m_cLado[3].DevuelveLongitud() + d ) / m_cLado[3].DevuelveLongitud() ); //Punto Proyectado

			cPtoPerpendicular.EstablecePtoPerpendicular( m_cPunto[5], m_cPunto[3], cPtoAux,
				m_cLado[2].DevuelveLongitud() * sin( m_cAngulo[2].DevuelveValor(Radianes) ) );
			m_cPunto[2] = cPtoPerpendicular.DevuelvePtoPerpendicular();
										
			cPtoAux = m_cPunto[5];
			cPtoAux.Translada( ( -1 * m_cPunto[3].DevuelveX() ),
				( -1 * m_cPunto[3].DevuelveY() ),
				( -1 * m_cPunto[3].DevuelveZ() ) );
			m_cPunto[2].Translada( ( -1 * m_cPunto[3].DevuelveX() ),
				( -1 * m_cPunto[3].DevuelveY() ),
				( -1 * m_cPunto[3].DevuelveZ() ) );
			
			
			m_cPunto[2].Rota3D(cPtoAux, m_cAngulo[6].DevuelveValor(Grados)+m_cAngulo[7].DevuelveValor(Grados)+90);
			m_cPunto[2].Translada(m_cPunto[3]);
			break;
	}

	RotaEje( m_cAngRotacion.DevuelveValor(Grados) );
	EstableceLado();
}

void CParteRigida::MuestraImagen()
{
	int iPaso = 0;
	
	switch (m_nParteRigida)
	{
		case AnilloFenil:
			for (iPaso = 0; iPaso <= 5; iPaso++)
			{
				m_cSpin[iPaso].EstableceColor( 
					DevuelveIndMaterial(	m_cLado[iPaso + 6].DevuelveTipo() ) );
				m_cSpin[iPaso].EstablecePtoCentral( m_cPunto[iPaso + 6] );
			}

			for (iPaso = 0; iPaso <= 5; iPaso++)
				m_cSpin[iPaso].MuestraImagen();

			ss_InitMaterials();
			ss_SetTeaMaterial(TURQUOISE);

			for (iPaso = 0; iPaso <= 11; iPaso++)
				m_cLado[iPaso].Construye();
			break;

		case Bifenil :
			m_cSpin[0].EstableceColor( DevuelveIndMaterial(	m_cLado[0].DevuelveTipo() ) );
			m_cSpin[2].EstableceColor( DevuelveIndMaterial(	m_cLado[1].DevuelveTipo() ) );

			for (iPaso = 0; iPaso <= 2; iPaso++)
				m_cSpin[iPaso].EstablecePtoCentral( m_cPunto[iPaso] );

			m_cSpin[1].EstableceColor(5);
			m_cSpin[1].EstableceRadio( m_cLado[1].DevuelveRadio() );

			for (iPaso = 0; iPaso <= 2; iPaso++)
				m_cSpin[iPaso].MuestraImagen();

			ss_InitMaterials();
			ss_SetTeaMaterial(TURQUOISE);

			for (iPaso = 0; iPaso <= 1; iPaso++) 
				m_cLado[iPaso].Construye(); 
			break;

		case Trifenil :
			

			for (iPaso = 0; iPaso <= 4; iPaso++)
			{
				if (iPaso < 3)
				{
					m_cSpin[iPaso].EstableceColor( 
						DevuelveIndMaterial(	m_cLado[iPaso].DevuelveTipo() ) );
				}
				m_cSpin[iPaso].EstablecePtoCentral( m_cPunto[iPaso] );
			}

			m_cSpin[3].EstableceColor(5);
			m_cSpin[3].EstableceRadio( m_cLado[1].DevuelveRadio() );

			for (iPaso = 0; iPaso <= 4; iPaso++)
				m_cSpin[iPaso].MuestraImagen();

			ss_InitMaterials();
			ss_SetTeaMaterial(TURQUOISE);
			
			for (iPaso = 0; iPaso <= 3; iPaso++)
				m_cLado[iPaso].Construye();
			break;
	}
}

void CParteRigida::MuestraImagenGDI(CDC *pDC, int nCuadricula, CString cPlano)
{
	int iPaso = 0;
	CPen cPen;
	cPen.CreatePen(m_iEstilo, m_iGrosor, m_colorRef);
	pDC->SelectObject(&cPen);

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			for (iPaso = 0; iPaso < 12; iPaso++)
				m_cLado[iPaso].MuestraLineaGDI(pDC, nCuadricula, cPlano);
			break;

		case Bifenil:
			for (iPaso = 0; iPaso < 12; iPaso++)
				m_cLado[iPaso].MuestraLineaGDI(pDC, nCuadricula, cPlano);
			break;

		case Trifenil:
			for (iPaso = 0; iPaso < 4; iPaso++)
				m_cLado[iPaso].MuestraLineaGDI(pDC, nCuadricula, cPlano);
			break;
	}
}

void CParteRigida::ObtieneAngulos()
{	
	if (m_nParteRigida == AnilloFenil )
	{
		double dAlfa = 0.0;

		dAlfa = DeterminaAng(
			(m_cAngulo[2].DevuelveValor(Grados) / 2),
			m_cLado[1].DevuelveLongitud(),
			(m_cAngulo[5].DevuelveValor(Grados) / 2),
			m_cLado[5].DevuelveLongitud(),
			m_cLado[0].DevuelveLongitud() ) ;

		m_cAngulo[0].EstableceValor( (90 - m_cAngulo[5].DevuelveValor(Grados) * 0.5) +
			90 + dAlfa);
		m_cAngulo[1].EstableceValor( (90 - m_cAngulo[2].DevuelveValor(Grados) * 0.5) +
			90 - dAlfa);
		m_cAngulo[3].EstableceValor( (90 -m_cAngulo[2].DevuelveValor(Grados) * 0.5) +
			90 - dAlfa);
		m_cAngulo[4].EstableceValor( (90 - m_cAngulo[5].DevuelveValor(Grados) * 0.5) +
			90 + dAlfa);
	}
}

void CParteRigida::RotaEje(double dAnguloValor)
{
	double dNewEquis, dNewYe, dNewZeta;
	int iPaso = 0;
	CPunto cPtoAux;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			dNewEquis = m_cPunto[2].DevuelveX();
			dNewYe = m_cPunto[2].DevuelveY();
			dNewZeta = m_cPunto[2].DevuelveZ();
			cPtoAux = m_cPunto[5];
			cPtoAux.Translada( (-1 * dNewEquis), (-1 * dNewYe), (-1 * dNewZeta) );

			for (iPaso = 0; iPaso < 12; iPaso++)
			{
				if ( (iPaso != 2) || (iPaso != 5) )
				{
					m_cPunto[iPaso].Translada( (-1 * dNewEquis), (-1 * dNewYe),
						(-1 * dNewZeta) );
					m_cPunto[iPaso].Rota3D(cPtoAux, dAnguloValor);
					m_cPunto[iPaso].Translada(dNewEquis, dNewYe, dNewZeta);
				}
			}
			break;

		case Bifenil:
			dNewEquis = m_cPunto[1].DevuelveX();
			dNewYe = m_cPunto[1].DevuelveY();
			dNewZeta = m_cPunto[1].DevuelveZ();
			m_cPunto[2].Translada( (-1 * dNewEquis), (-1 * dNewYe), (-1 * dNewZeta) );
			m_cPunto[2].Rota3D(m_cPunto[1], dAnguloValor);
			m_cPunto[2].Translada(dNewEquis, dNewYe, dNewZeta);
			break;

		case Trifenil:
			dNewEquis = m_cPunto[4].DevuelveX();
			dNewYe = m_cPunto[4].DevuelveY();
			dNewZeta = m_cPunto[4].DevuelveZ();

			m_cPunto[0].Translada( (-1 * dNewEquis), (-1 * dNewYe), (-1 * dNewZeta) );
			m_cPunto[1].Translada( (-1 * dNewEquis), (-1 * dNewYe), (-1 * dNewZeta) );
			m_cPunto[2].Translada( (-1 * dNewEquis), (-1 * dNewYe), (-1 * dNewZeta) );
			m_cPunto[3].Translada( (-1 * dNewEquis), (-1 * dNewYe), (-1 * dNewZeta) );
			m_cPunto[0].Rota3D(m_cPunto[3], dAnguloValor);
			m_cPunto[1].Rota3D(m_cPunto[3], dAnguloValor);
			m_cPunto[2].Rota3D(m_cPunto[3], dAnguloValor);
			m_cPunto[0].Translada(dNewEquis, dNewYe, dNewZeta);
			m_cPunto[1].Translada(dNewEquis, dNewYe, dNewZeta);
			m_cPunto[2].Translada(dNewEquis, dNewYe, dNewZeta);
			m_cPunto[3].Translada(dNewEquis, dNewYe, dNewZeta);
		break;
	}
}

//////////////////////////////////////////////////////////////////////
//	Operators
//////////////////////////////////////////////////////////////////////

const CParteRigida& CParteRigida::operator =(const CParteRigida & cParteRigida)
{
	for (int iPaso = 0; iPaso < 12; iPaso++)
	{
		m_cAngulo[iPaso] = cParteRigida.m_cAngulo[iPaso];
		m_cPunto[iPaso] = cParteRigida.m_cPunto[iPaso];
		m_cLado[iPaso] = cParteRigida.m_cLado[iPaso];
	}

	for (iPaso = 0; iPaso < 6; iPaso++)
	{
		m_cSpin[iPaso] = cParteRigida.m_cSpin[iPaso];	
	}

	m_cAngRotacion = cParteRigida.m_cAngRotacion;
	m_nParteRigida = cParteRigida.m_nParteRigida;
	m_colorRef = cParteRigida.m_colorRef;
	m_iEstilo = cParteRigida.m_iEstilo;
	m_iGrosor = cParteRigida.m_iGrosor;

	return *this;
}

void CParteRigida::MuestraDescripcion(CDC * pDC, int iFactor, CString cPlano)
{
	int iPaso;
	switch (m_nParteRigida)
	{
		case AnilloFenil:
			for (iPaso = 6; iPaso < 12; iPaso++) {
				if ( cPlano == _T("XY") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveX()*iFactor),(int)(m_cPunto[iPaso].DevuelveY()*iFactor),m_cSpin[iPaso-6].DevuelveEtiqueta());
				if ( cPlano == _T("XZ") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveX()*iFactor),(int)(m_cPunto[iPaso].DevuelveZ()*iFactor),m_cSpin[iPaso-6].DevuelveEtiqueta());
				if ( cPlano == _T("YX") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveY()*iFactor),(int)(m_cPunto[iPaso].DevuelveX()*iFactor),m_cSpin[iPaso-6].DevuelveEtiqueta());
				if ( cPlano == _T("YZ") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveY()*iFactor),(int)(m_cPunto[iPaso].DevuelveZ()*iFactor),m_cSpin[iPaso-6].DevuelveEtiqueta());
				if ( cPlano == _T("ZX") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveZ()*iFactor),(int)(m_cPunto[iPaso].DevuelveX()*iFactor),m_cSpin[iPaso-6].DevuelveEtiqueta());
				if ( cPlano == _T("ZY") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveZ()*iFactor),(int)(m_cPunto[iPaso].DevuelveY()*iFactor),m_cSpin[iPaso-6].DevuelveEtiqueta());
			}
			break;

		case Bifenil:
			if ( cPlano == _T("XY") )
				pDC->TextOut((int)(m_cPunto[2].DevuelveX()*iFactor),(int)(m_cPunto[2].DevuelveY()*iFactor),m_cSpin[2].DevuelveEtiqueta());
			if ( cPlano == _T("XZ") )
				pDC->TextOut((int)(m_cPunto[2].DevuelveX()*iFactor),(int)(m_cPunto[2].DevuelveZ()*iFactor),m_cSpin[2].DevuelveEtiqueta());
			if ( cPlano == _T("YX") )
				pDC->TextOut((int)(m_cPunto[2].DevuelveY()*iFactor),(int)(m_cPunto[2].DevuelveX()*iFactor),m_cSpin[2].DevuelveEtiqueta());
			if ( cPlano == _T("YZ") )
				pDC->TextOut((int)(m_cPunto[2].DevuelveY()*iFactor),(int)(m_cPunto[2].DevuelveZ()*iFactor),m_cSpin[2].DevuelveEtiqueta());
			if ( cPlano == _T("ZX") )
				pDC->TextOut((int)(m_cPunto[2].DevuelveZ()*iFactor),(int)(m_cPunto[2].DevuelveX()*iFactor),m_cSpin[2].DevuelveEtiqueta());
			if ( cPlano == _T("ZY") )
				pDC->TextOut((int)(m_cPunto[2].DevuelveZ()*iFactor),(int)(m_cPunto[2].DevuelveY()*iFactor),m_cSpin[2].DevuelveEtiqueta());
			break;

		case Trifenil:
			for (iPaso = 0; iPaso < 3; iPaso++) {
				if ( cPlano == _T("XY") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveX()*iFactor),(int)(m_cPunto[iPaso].DevuelveY()*iFactor),m_cSpin[iPaso].DevuelveEtiqueta());
				if ( cPlano == _T("XZ") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveX()*iFactor),(int)(m_cPunto[iPaso].DevuelveZ()*iFactor),m_cSpin[iPaso].DevuelveEtiqueta());
				if ( cPlano == _T("YX") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveY()*iFactor),(int)(m_cPunto[iPaso].DevuelveX()*iFactor),m_cSpin[iPaso].DevuelveEtiqueta());
				if ( cPlano == _T("YZ") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveY()*iFactor),(int)(m_cPunto[iPaso].DevuelveZ()*iFactor),m_cSpin[iPaso].DevuelveEtiqueta());
				if ( cPlano == _T("ZX") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveZ()*iFactor),(int)(m_cPunto[iPaso].DevuelveX()*iFactor),m_cSpin[iPaso].DevuelveEtiqueta());
				if ( cPlano == _T("ZY") )
					pDC->TextOut((int)(m_cPunto[iPaso].DevuelveZ()*iFactor),(int)(m_cPunto[iPaso].DevuelveY()*iFactor),m_cSpin[iPaso].DevuelveEtiqueta());
			}
			break;
	}
}

void CParteRigida::ImprimeConformacion(CDC * pDC, LONG & nActualLinea )
{
	TEXTMETRIC tm;
	CString cCadena = _T("");
	LONG nAltura;
	
	pDC->GetTextMetrics(&tm);
	nAltura = tm.tmHeight + tm.tmExternalLeading;
	nActualLinea -= (nActualLinea *nAltura);
		
	switch (m_nParteRigida)
	{
		case AnilloFenil:
			cCadena = _T("Anillo Fenil");
			pDC->TextOut( 700, nActualLinea, cCadena );
			break;
		case Bifenil:
			cCadena = _T("BiFenil");
			pDC->TextOut( 700, nActualLinea, cCadena );
			break;
		case Trifenil:
			cCadena = _T("TriFenil");
			pDC->TextOut( 700, nActualLinea, cCadena );
			break;
	}

	nActualLinea -= (2 *nAltura);

	ImprimePuntosInternos(pDC, nActualLinea, nAltura);
	ImprimePuntosExternos(pDC, nActualLinea, nAltura);
	ImprimeLadosInternos(pDC, nActualLinea, nAltura);
	ImprimeLadosExternos(pDC, nActualLinea, nAltura);
	ImprimeAngulosInternos(pDC, nActualLinea, nAltura);
	ImprimeAngulosExternos(pDC, nActualLinea, nAltura);

}

////////////////////
//	Puntos Internos
////////////////////

void CParteRigida::ImprimePuntosInternos(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	CString cStrTitulo = _T("");

	cStrTitulo = _T("Puntos Internos");
	pDC->TextOut( 950, nActualLinea, cStrTitulo );
	nActualLinea -= nAltura;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			ImprimePuntosInternosAnilloFenil(pDC, nActualLinea, nAltura);
			break;
		case Bifenil:
			ImprimePuntosInternosBifenil(pDC, nActualLinea, nAltura);
			break;
		case Trifenil:
			ImprimePuntosInternosTrifenil(pDC, nActualLinea, nAltura);
			break;
	}	

	nActualLinea -= nAltura;
}

void CParteRigida::ImprimePuntosInternosAnilloFenil(CDC * pDC, LONG & nActualLinea,
																	 LONG nAltura)
{
	for (int iIndex2 = 0; iIndex2 < 6; iIndex2++)
	{
		CString cStrPunto = _T("");

		switch (iIndex2)
		{
			case 0:
				cStrPunto = _T(" A -> ");
				break;
			case 1:
				cStrPunto = _T(" B -> ");
				break;
			case 2:
				cStrPunto = _T(" C -> ");
				break;
			case 3:
				cStrPunto = _T(" D -> ");
				break;
			case 4:
				cStrPunto = _T(" E -> ");
				break;
			case 5:
				cStrPunto = _T(" F -> ");
				break;
		}

		CString cCadena = _T("");
		cCadena.Format("x: %7.5f  y: %7.5f  z: %7.5f",
			m_cPunto[iIndex2].DevuelveX(),
			m_cPunto[iIndex2].DevuelveY(),
			m_cPunto[iIndex2].DevuelveZ() );

		pDC->TextOut( 1100, nActualLinea, cStrPunto + cCadena );
		nActualLinea -= nAltura;
	}
}

void CParteRigida::ImprimePuntosInternosBifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	for (int iIndex2 = 0; iIndex2 < 3; iIndex2++)
	{
		CString cStrPunto = _T("");

		switch (iIndex2)
		{
			case 0:
				cStrPunto = _T(" A -> ");
				break;
			case 1:
				cStrPunto = _T(" B -> ");
				break;
			case 2:
				cStrPunto = _T(" C -> ");
				break;
		}

		CString cCadena = _T("");
		cCadena.Format("x: %7.5f  y: %7.5f  z: %7.5f",
			m_cPunto[iIndex2].DevuelveX(),
			m_cPunto[iIndex2].DevuelveY(),
			m_cPunto[iIndex2].DevuelveZ() );

		pDC->TextOut( 1100, nActualLinea, cStrPunto + cCadena );
		nActualLinea -= nAltura;
	}
}

void CParteRigida::ImprimePuntosInternosTrifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	for (int iIndex2 = 0; iIndex2 < 5; iIndex2++)
	{
		CString cStrPunto = _T("");

		switch (iIndex2)
		{
			case 0:
				cStrPunto = _T(" A -> ");
				break;
			case 1:
				cStrPunto = _T(" B -> ");
				break;
			case 2:
				cStrPunto = _T(" C -> ");
				break;
			case 3:
				cStrPunto = _T(" O -> ");
				break;
			case 4:
				cStrPunto = _T(" D -> ");
				break;
		}

		CString cCadena = _T("");
		cCadena.Format("x: %7.5f  y: %7.5f  z: %7.5f",
			m_cPunto[iIndex2].DevuelveX(),
			m_cPunto[iIndex2].DevuelveY(),
			m_cPunto[iIndex2].DevuelveZ() );

		pDC->TextOut( 1100, nActualLinea, cStrPunto + cCadena );
		nActualLinea -= nAltura;
	}
}

////////////////////
//	Puntos Externos
////////////////////

void CParteRigida::ImprimePuntosExternos(CDC * pDC, LONG & nActualLinea,
													  LONG nAltura)
{
	CString cStrTitulo = _T("");

	cStrTitulo = _T("Puntos Externos");
	pDC->TextOut( 950, nActualLinea, cStrTitulo );
	nActualLinea -= nAltura;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			ImprimePuntosExternosAnilloFenil(pDC, nActualLinea, nAltura);
			break;
		case Bifenil:
			// No tiene puntos externos
			break;
		case Trifenil:
			// No tiene puntos externos
			break;
	}

	nActualLinea -= nAltura;
}

void CParteRigida::ImprimePuntosExternosAnilloFenil(CDC * pDC, LONG & nActualLinea,
																	 LONG nAltura)
{	
	for (int iIndex2 = 6; iIndex2 < 12; iIndex2++)
	{
		CString cStrPunto = _T("");

		switch (iIndex2)
		{
			case 6:
				cStrPunto = _T(" A' -> ");
				break;
			case 7:
				cStrPunto = _T(" B' -> ");
				break;
			case 8:
				cStrPunto = _T(" C' -> ");
				break;
			case 9:
				cStrPunto = _T(" D' -> ");
				break;
			case 10:
				cStrPunto = _T(" E' -> ");
				break;
			case 11:
				cStrPunto = _T(" F' -> ");
				break;
		}

		CString cCadena = _T("");
		cCadena.Format("x: %7.5f  y: %7.5f  z: %7.5f",
			m_cPunto[iIndex2].DevuelveX(),
			m_cPunto[iIndex2].DevuelveY(),
			m_cPunto[iIndex2].DevuelveZ() );

		pDC->TextOut( 1100, nActualLinea, cStrPunto + cCadena );
		nActualLinea -= nAltura;
	}
}

////////////////////
//	Lados Internos
////////////////////

void CParteRigida::ImprimeLadosInternos(CDC * pDC, LONG & nActualLinea,	
													 LONG nAltura)
{
	CString cStrTitulo = _T("");

	cStrTitulo = _T("Lados Internos");
	pDC->TextOut( 950, nActualLinea, cStrTitulo );
	nActualLinea -= nAltura;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			ImprimeLadosInternosAnilloFenil(pDC, nActualLinea, nAltura);
			break;
		case Bifenil:
			ImprimeLadosInternosBifenil(pDC, nActualLinea, nAltura);
			break;
		case Trifenil:
			ImprimeLadosInternosTrifenil(pDC, nActualLinea, nAltura);
			break;
	}

	nActualLinea -= nAltura;
}

void CParteRigida::ImprimeLadosInternosAnilloFenil(CDC * pDC, LONG & nActualLinea,
																	LONG nAltura)
{
	for (int iIndex2 = 0; iIndex2 < 6; iIndex2++)
	{
		CString cStrLado = _T("");

		switch (iIndex2)
		{
			case 0:
				cStrLado = _T(" AB -> ");
				break;
			case 1:
				cStrLado = _T(" BC -> ");
				break;
			case 2:
				cStrLado = _T(" CD -> ");
				break;
			case 3:
				cStrLado = _T(" DE -> ");
				break;
			case 4:
				cStrLado = _T(" EF -> ");
				break;
			case 5:
				cStrLado = _T(" FA -> ");
				break;
		}

		CString cCadena = _T("");

		if (iIndex2 == 5)
		{
			cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[iIndex2], m_cPunto[0] ));
			pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
		}
		else
		{
			cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[iIndex2], m_cPunto[iIndex2 + 1] ));
			pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
		}

		nActualLinea -= nAltura;
	}
}

void CParteRigida::ImprimeLadosInternosBifenil(CDC * pDC, LONG & nActualLinea, 
															  LONG nAltura)
{
	CString cCadena = _T("");
	CString cStrLado = _T("");

	cStrLado = _T(" AB -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[0], m_cPunto[1] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" BC -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[1], m_cPunto[2] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;
}

void CParteRigida::ImprimeLadosInternosTrifenil(CDC * pDC, LONG & nActualLinea,
																LONG nAltura)
{
	CString cCadena = _T("");
	CString cStrLado = _T("");

	cStrLado = _T(" OA -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[3], m_cPunto[0] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" OB -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[3], m_cPunto[1] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" OC -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[3], m_cPunto[2] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;
	
	cStrLado = _T(" DO -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[4], m_cPunto[3] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;
}

////////////////////
//	Lados Externos
////////////////////

void CParteRigida::ImprimeLadosExternos(CDC * pDC, LONG & nActualLinea,	
													 LONG nAltura)
{
	CString cStrTitulo = _T("");

	cStrTitulo = _T("Lados Externos");
	pDC->TextOut( 950, nActualLinea, cStrTitulo );
	nActualLinea -= nAltura;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			ImprimeLadosExternosAnilloFenil(pDC, nActualLinea, nAltura);
			break;
		case Bifenil:
			// No tiene lados externos
			break;
		case Trifenil:
			// No tiene lados externos
			break;
	}

	nActualLinea -= nAltura;
}

void CParteRigida::ImprimeLadosExternosAnilloFenil(CDC * pDC, LONG & nActualLinea,
																	LONG nAltura)
{
	CString cStrLado = _T("");
	CString cCadena = _T("");

	cStrLado = _T(" AA' -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[0], m_cPunto[6] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" BB' -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[1], m_cPunto[7] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" CC' -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[2], m_cPunto[8] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" DD' -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[3], m_cPunto[9] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" EE' -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[4], m_cPunto[10] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;

	cStrLado = _T(" FF' -> ");
	cCadena.Format("%7.5f",	CalculaDistancia( m_cPunto[5], m_cPunto[11] ));
	pDC->TextOut( 1100, nActualLinea, cStrLado + cCadena );
	nActualLinea -= nAltura;
}

////////////////////
//	Angulos Internos
////////////////////

void CParteRigida::ImprimeAngulosInternos(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	CString cStrTitulo = _T("");

	cStrTitulo = _T("Angulos Internos");
	pDC->TextOut( 950, nActualLinea, cStrTitulo );
	nActualLinea -= nAltura;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			ImprimeAngulosInternosAnilloFenil(pDC, nActualLinea, nAltura);
			break;
		case Bifenil:
			ImprimeAngulosInternosBifenil(pDC, nActualLinea, nAltura);
			break;
		case Trifenil:
			ImprimeAngulosInternosTrifenil(pDC, nActualLinea, nAltura);
			break;
	}

	nActualLinea -= nAltura;
}

void CParteRigida::ImprimeAngulosInternosAnilloFenil(CDC * pDC, LONG & nActualLinea,
																	  LONG nAltura)
{
	for (int iIndex2 = 0; iIndex2 < 6; iIndex2++)
	{
		CString cStrAngulo = _T("");

		switch (iIndex2)
		{
			case 0:
				cStrAngulo = _T(" FAB -> ");
				break;
			case 1:
				cStrAngulo = _T(" ABC -> ");
				break;
			case 2:
				cStrAngulo = _T(" BCD -> ");
				break;
			case 3:
				cStrAngulo = _T(" CDE -> ");
				break;
			case 4:
				cStrAngulo = _T(" DEF -> ");
				break;
			case 5:
				cStrAngulo = _T(" EFA -> ");
				break;
		}

		CString cCadena = _T("");

		cCadena.Format("%7.5f",	m_cAngulo[iIndex2].DevuelveValor(Grados) );
		pDC->TextOut( 1100, nActualLinea, cStrAngulo + cCadena );
		nActualLinea -= nAltura;
	}
}

void CParteRigida::ImprimeAngulosInternosBifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	CString cStrAngulo = _T("");
	CString cCadena = _T("");

	cStrAngulo = _T(" ABC -> ");
	cCadena.Format("%7.5f",	m_cAngulo[0].DevuelveValor(Grados) );
	pDC->TextOut( 1100, nActualLinea, cStrAngulo + cCadena );
	nActualLinea -= nAltura;
}

void CParteRigida::ImprimeAngulosInternosTrifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	CString cStrAngulo = _T("");
	CString cCadena = _T("");

	cStrAngulo = _T(" AOG -> ");
	cCadena.Format("%7.5f",	m_cAngulo[0].DevuelveValor(Grados) );
	pDC->TextOut( 1100, nActualLinea, cStrAngulo + cCadena );
	nActualLinea -= nAltura;
}

////////////////////
//	Angulos Externos
////////////////////

void CParteRigida::ImprimeAngulosExternos(CDC * pDC, LONG & nActualLinea, LONG nAltura)
{
	CString cStrTitulo = _T("");

	cStrTitulo = _T("Angulos Externos");
	pDC->TextOut( 950, nActualLinea, cStrTitulo );
	nActualLinea -= nAltura;

	switch (m_nParteRigida)
	{
		case AnilloFenil:
			ImprimeAngulosExternosAnilloFenil(pDC, nActualLinea, nAltura);
			break;
		case Bifenil:
			// No tiene angulos externos
			break;
		case Trifenil:
			// No tiene angulos externos
			break;
	}

	nActualLinea -= nAltura;
}

void CParteRigida::ImprimeAngulosExternosAnilloFenil(CDC * pDC, LONG & nActualLinea,
																	  LONG nAltura)
{
	for (int iIndex2 = 6; iIndex2 < 12; iIndex2++)
	{
		CString cStrAngulo = _T("");

		switch (iIndex2)
		{
			case 6:
				cStrAngulo = _T(" FAA' -> ");
				break;
			case 7:
				cStrAngulo = _T(" B'BC -> ");
				break;
			case 8:
				cStrAngulo = _T(" BCC' -> ");
				break;
			case 9:
				cStrAngulo = _T(" CDD' -> ");
				break;
			case 10:
				cStrAngulo = _T(" E'EF -> ");
				break;
			case 11:
				cStrAngulo = _T(" F'FA -> ");
				break;
		}

		CString cCadena = _T("");
		cCadena.Format("%7.5f", m_cAngulo[iIndex2].DevuelveValor(Grados) );
		pDC->TextOut( 1100, nActualLinea, cStrAngulo + cCadena );
		nActualLinea -= nAltura;
	}
}

void CParteRigida::Create(ParteRigida nParte)
{
	int i=0;
	switch (nParte)
	{
		case AnilloFenil:
			for(i=0;i<6;i++)
				m_cLado[i].EstableceLongitud(1.39);
			for(i=6;i<12;i++)
				m_cLado[i].EstableceLongitud(1.08);
			break;
		case Bifenil:
			m_cLado[0].EstableceLongitud(1.343);
			m_cLado[1].EstableceLongitud(1.419);	
			m_cAngulo[0].EstableceValor(60);
			break;
		case Trifenil:
			m_cLado[3].EstableceLongitud(1.419);
			for(i=0;i<3;i++) {
				m_cLado[i].EstableceLongitud(1.09);
				m_cAngulo[i].EstableceValor(70.53);
			}
			break;
	}
}

