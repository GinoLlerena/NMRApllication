// Rutinas.cpp: implementation archive.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Rutinas.h"
#include "Trigonom.h"
#include "Material.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

CPunto Conversor( CPunto cPtoInicial, CPunto cPtoFinal, double dK)
{
	CPunto cPto;
	double dNewEquis = 0.0;
	double dNewYe = 0.0;
	double dNewZeta = 0.0;

	dNewEquis = cPtoInicial.DevuelveX() + ( cPtoFinal.DevuelveX() -
		cPtoInicial.DevuelveX() ) * dK;
	dNewYe = cPtoInicial.DevuelveY() + ( cPtoFinal.DevuelveY() -
		cPtoInicial.DevuelveY()) * dK;
	dNewZeta = cPtoInicial.DevuelveZ() + ( cPtoFinal.DevuelveZ() -
		cPtoInicial.DevuelveZ()) * dK;
	cPto.Establece(dNewEquis, dNewYe, dNewZeta);
  
	return cPto;
}

double CalculaDistancia(CPunto cPtoUno, CPunto cPtoDos)
{
	return sqrt( pow(cPtoDos.DevuelveX() - cPtoUno.DevuelveX(), 2) +
		pow(cPtoDos.DevuelveY() - cPtoUno.DevuelveY(), 2) +
		pow(cPtoDos.DevuelveZ() - cPtoUno.DevuelveZ(), 2) );
}

CString DevuelveItemLista(ParteRigida nParteRigida, UINT uSecuencia)
{
	CString cCadena = _T("");
	
	switch (nParteRigida)
	{
		case AnilloFenil :
			cCadena.Format(_T("AnilloFenil  %d"), uSecuencia);			
			break;
		case Bifenil :
			cCadena.Format(_T("Bifenil %d"), uSecuencia);
			break;
		case Trifenil :
			cCadena.Format(_T("Trifenil %d"), uSecuencia);
			break;
	}
	
	return cCadena;
}

CString DevStrParteRigida(ParteRigida nParteRigida)
{
	CString cCadena = _T("");

	switch (nParteRigida)
	{
		case AnilloFenil:
			cCadena = _T("AnilloFenil ");
			break;
		case Bifenil:
			cCadena = _T("Bifenil ");
			break;
		case Trifenil:
			cCadena = _T("Trifenil ");
			break;
	}

	return cCadena;
}

ParteRigida DevuelveIdParteRigida(CString cCadena)
{
	int nPos = cCadena.Find(' ');
	
	switch (nPos)
	{
		case 11:
			return AnilloFenil;
		case 7:
			return Bifenil;
		case 8:
			return Trifenil;
	}

	return Ninguna;
}


CString DevuelveEnumSimetriaAsString(Simetria nSimetria)
{
	CString cCadena = _T("");

	switch (nSimetria)
	{
		case D4:
			cCadena = _T("D4");
			break;
		case D2:
			cCadena = _T("D2");
			break;
		case NoSimetria:
			cCadena = _T("NoSimetria");
			break;
	}

	return cCadena;
}

Simetria DevuelveStringAsEnumSimetria(CString cCadena)
{
	if ( cCadena == _T("D4") )
		return D4;

	if ( cCadena ==  _T("D2") )
		return D2;

	return NoSimetria;	
}

int CStrToInt(CString cCadena)
{
	cCadena.GetBuffer(2);	// Hasta el nro. 99
	int iNumero = atoi(cCadena);
	cCadena.ReleaseBuffer();

	return iNumero;
}

CString DoubleToCStr(double dValor)
{
	CString cCadena;
	cCadena.Format("%f", dValor);
	return cCadena;
}

double CStrToDouble(CString cCadena)
{
	cCadena.GetBuffer(25);	// Hasta el nro. 99
	double dNumero = atof(cCadena);
	cCadena.ReleaseBuffer();

	return dNumero;
}

double DeterminaAng(double dAng1 /* en Grados */, double dD1, double dAng2 /* en Grados */,
						  double dD2, double dH)
{
	double dAlfa;

	dAlfa = asin( ( sen(dAng1) * dD1 - sen(dAng2) * dD2 ) / dH );
	return radiansToDegrees(dAlfa);
}

double AnguloDosRectas(CPunto cPtoU, CPunto cPtoV)
{
	CPunto cPtoTemp(0,0,0);
	double mU = CalculaDistancia(cPtoTemp, cPtoU);
	double mV = CalculaDistancia(cPtoTemp, cPtoV);

	return ( cPtoU.DevuelveX() * cPtoV.DevuelveX() + cPtoU.DevuelveY() * cPtoV.DevuelveY() +
		cPtoU.DevuelveZ() * cPtoV.DevuelveZ() ) / (mU * mV);
}

CPunto RetornaVector(CPunto cPtoA, CPunto cPtoB)
{
	CPunto cTmp( cPtoB.DevuelveX() - cPtoA.DevuelveX(), cPtoB.DevuelveY() - cPtoA.DevuelveY(),
		cPtoB.DevuelveZ() - cPtoA.DevuelveZ() );

	return cTmp;
}

CPunto GirarLado(CPunto cGiro, CPunto cOri, CPunto cPer,double dAng, double dLong )
{
	CPunto cTmp = cGiro;
	double d = CalculaDistancia(cOri, cGiro);

	cTmp.Translada(-cOri.DevuelveX(), -cOri.DevuelveY(), -cOri.DevuelveZ());
	cTmp.Rota3D(cPer, dAng);
	cTmp.Translada(cOri);

	cTmp= Conversor(cOri, cTmp, dLong/d);

	return cTmp;
}

BOOL SonDiferentesFicheroEstados(CFileStatus cFileStatus1, CFileStatus cFileStatus2)
{
	if (cFileStatus1.m_ctime != cFileStatus2.m_ctime)
	{
		TRACE("m_ctime - Archivo Corrupto");
		return TRUE;
	}

	if (cFileStatus1.m_mtime != cFileStatus2.m_mtime)
	{
		TRACE("m_mtime - Archivo Corrupto");
		return TRUE;
	}

	if (cFileStatus1.m_atime != cFileStatus2.m_atime)
	{
		TRACE("m_atime - Archivo Corrupto");
		return TRUE;
	}

	if (cFileStatus1.m_size != cFileStatus2.m_size)
	{
		TRACE("m_size - Archivo Corrupto");
		return TRUE;
	}

	if (cFileStatus1.m_attribute != cFileStatus2.m_attribute)
	{
		TRACE("m_attribute - Archivo Corrupto");
		return TRUE;
	}

	CString strFullName1 = _T("");
	strFullName1 = cFileStatus1.m_szFullName;
	CString strFullName2 = _T("");
	strFullName2 = cFileStatus2.m_szFullName;
	
	if (strFullName1 != strFullName2)
	{
		TRACE("m_szFullName - Archivo Corrupto");
		return TRUE;
	}

	return FALSE;
}

int DevuelveIndMaterial(CString cTipoSpin)
{	//13, 15, 7 son colores disponibles.
	
	if ( cTipoSpin == _T("Fluor") )
		return 14;

	if ( cTipoSpin == _T("Proton") ) 
		return 10;

	if ( cTipoSpin == _T("Deuterio") )
		return 11;

	if ( cTipoSpin == _T("Cloro") )
		return 3;

	if ( cTipoSpin == _T("Bromo") )
		return 12;

	if ( cTipoSpin == _T("Ninguno") )
		return 5;

	return FALSE;
}

BOOL DevuelveEtiquetasDij(CString cCadena, CString & cEtiqueta1, CString & cEtiqueta2)
{
	int iPosicion1 = cCadena.Find(',');
	int iPosicion2 = cCadena.Find(' ');

	cEtiqueta1 = cCadena.Left(iPosicion1);

	if (iPosicion2 == -1)
		cEtiqueta2 = cCadena.Right(cCadena.GetLength() - iPosicion1);
	else
		cEtiqueta2 = cCadena.Right( cCadena.GetLength() - (iPosicion2 + 1) );

	if ( ( cEtiqueta1.IsEmpty() ) || ( cEtiqueta2.IsEmpty() ) )
		return FALSE;

	return TRUE;
}

CString DevuelveEtiquetas(CString cEtiqueta1, CString cEtiqueta2)
{
	return cEtiqueta1 + _T(", ") + cEtiqueta2;
}

CString DevuelveEtiquetasInvertidas(CString cEtiqueta1, CString cEtiqueta2)
{
	return cEtiqueta2 + _T(", ") + cEtiqueta1;
}

void DevCoordEsf(CPunto cPto, double & dAnguloTeta, double & dAnguloPhi, double & dDistancia)
{
	CPunto cPtoTemp(0.0, 0.0, 0.0);
	dDistancia = CalculaDistancia(cPto, cPtoTemp);
	dAnguloPhi = acos(cPto.DevuelveZ() / dDistancia);

	if (cPto.DevuelveX() != 0)
		dAnguloTeta = atan( cPto.DevuelveY() / cPto.DevuelveX() );
	else
		dAnguloTeta = degreesToRadians(90.0);
}

void DevCoordEsf2Ptos(CPunto cPto1, CPunto cPto2, double & dAnguloTeta, double & dAnguloPhi,
							 double & dDistancia)
{
	double dNewX = cPto2.DevuelveX() - cPto1.DevuelveX();
	double dNewY = cPto2.DevuelveY() - cPto1.DevuelveY();
	double dNewZ = cPto2.DevuelveZ() - cPto1.DevuelveZ();

	dDistancia = CalculaDistancia(cPto1, cPto2);
	dAnguloPhi = acos(dNewZ / dDistancia);

	if (dNewX != 0)
		dAnguloTeta = atan(dNewY / dNewX);
	else
		dAnguloTeta = degreesToRadians(90.0);
}
