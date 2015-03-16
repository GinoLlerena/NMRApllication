// RealizadorReporte.cpp: implementation of the CRealizadorReporte class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "proyecto.h"
#include "RealizadorReporte.h"
#include "Fichero.h"
#include "Structures.h"
#include "Rutinas.h"
#include "Tensor.h"
#include "Parametro.h"
#include	"Matriz.h"
#include	"Interaccion.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRealizadorReporte::CRealizadorReporte()
{

}

CRealizadorReporte::~CRealizadorReporte()
{

}

void CRealizadorReporte::ImprimeSeleccion(CDC * pDC, int iSeleccion, int iIndex)
{
	// Condiciones del Fichero de Interacciones
	CString cIntFileFullName = _T("");
	cIntFileFullName = ComparaStatusDosFicheros(GetDoc()->m_strFullName , 1);

	if (cIntFileFullName == _T("") )
		return;

	// Condiciones del Fichero de Parámetros
	CString cParFileFullName = _T("");
	cParFileFullName = ComparaStatusDosFicheros(GetDoc()->m_strFullName ,  2);

	if (cParFileFullName == _T("") )
		return;

	// Condiciones del Fichero de Tensores
	CString cTenFileFullName = _T("");
	cTenFileFullName = ComparaStatusDosFicheros(GetDoc()->m_strFullName ,  3);

	if (cTenFileFullName == _T("") )
		return;

	BuscaMejorAjuste(cTenFileFullName, GetDoc()->m_iCantDatosGrabados,iSeleccion);

	LONG iLinea = 0; 
	
	if (iIndex==0) {
		if(iSeleccion==6)
			pDC->TextOut(700,iLinea,"Reporte de Calculos x Error");
		else
			pDC->TextOut(700,iLinea,"Reporte de Calculos x MAD");
		VerificaLinea(iLinea,2);
	}
	if(iIndex < m_cSeleccion.DevuelveCantidadDatos())
	{
		ImprimeReporteParametros( pDC, cParFileFullName,GetDoc()->m_iCantParamVariab,m_cSeleccion.DevuelveIndice(iIndex),iLinea);
		VerificaLinea(iLinea,1);
		ImprimeReporteInteracciones( pDC, cIntFileFullName,GetDoc()->m_iCantEcuacDipolar,m_cSeleccion.DevuelveIndice(iIndex),iLinea);
		VerificaLinea(iLinea,1);
		ImprimeReporteTensores( pDC, cTenFileFullName,m_cSeleccion.DevuelveIndice(iIndex),iLinea);
		VerificaLinea(iLinea,2);
	}

	
}

void CRealizadorReporte::BuscaMejorAjuste(CString & cFileFullName, int iTotal, int iTipo)
{
	CFichero cFichero;

	if (!cFichero.Abre(cFileFullName, CFile::modeRead))
		return;
	
	StcValorDual stcValorDual;
	StcDatos stDato;
	m_cSeleccion.Inicializate();

	for (int iIndex = 0; iIndex <=iTotal; iIndex++)
	{
		for (int iColumna = 1; iColumna <= 7; iColumna++)
		{
			if (iTipo==iColumna) 
			{
			   cFichero.Lee( (char*) &stcValorDual, iColumna + ( iIndex  * 7 ),
					sizeof(StcValorDual) );
				stDato.m_iIndice = iIndex;
				stDato.m_dValor = stcValorDual.dValor;
				m_cSeleccion.BuscaDondeGuardar(stDato);
			}		 
		}
	}
	
	cFichero.Close();
}

CString CRealizadorReporte::ComparaStatusDosFicheros(CString cPathName, int iRegistro)
{
	// cPathName : PathName del fichero de extensión "bin".
	//	iRegistro : Ubicación del status en el fichero de extensión "bin"
	//					1 : para el fichero de extensión "int";
	//					2 : para el fichero de extensión "par";
	//					3 : para el fichero de extensión "ten".

	CFichero cFichero;

	if (!cFichero.Abre(cPathName, CFile::modeRead))
		return ( _T("") );

	CFileStatus cBinFileStatus;	// Status de cualquiera de los fichero
											//	de extensión "int", "par", "ten";
											//	almacenado en el fichero de extensión "bin".
	cFichero.Lee((char*) &cBinFileStatus, iRegistro, sizeof(CFileStatus));
	cFichero.Close();

	CString cExtFullName = _T("");	// FullName de cualquier fichero de 
												// extensión "int", "par", "ten"
	cExtFullName = cBinFileStatus.m_szFullName;

	CFileStatus cExtFileStatus;	// Status de cualquiera de los fichero
											//	de extensión "int", "par", "ten".
	if (!cFichero.Abre(cExtFullName, CFile::modeRead))
		return ( _T("") );

	cFichero.GetStatus(cExtFileStatus);
	
	CString cExtFileName = _T("");	//	Name de cualquier fichero de
												//	extensión "int", "par", "ten"
	cExtFileName = cFichero.GetFileName();

	cFichero.Close();

	switch (SonDiferentesFicheroEstados(cBinFileStatus, cExtFileStatus))
	{
		case TRUE:
		/*	AfxMessageBox( _T("Archivo ") + cPathName + _T(" corrupto."), _T("Advertencia"),
				MB_ICONEXCLAMATION);*/
			cExtFileName = _T("");
			break;

		case FALSE:
			break;
	}

	return cExtFileName;
}


void CRealizadorReporte::ImprimeReporteParametros(CDC * pDC, CString & cFileFullName,
															int iTotalParametros, int iPosicion, LONG &iLinea)
{
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	LONG nHeight = tm.tmHeight + tm.tmExternalLeading;
	CFichero cFichero;

	if (!cFichero.Abre(cFileFullName, CFile::modeRead))
		return;

			
	CString cCadena = _T("");
	cCadena = _T("Resultados Obtenidos :");
	pDC->TextOut( 700, iLinea*nHeight, cCadena );
	VerificaLinea(iLinea,2);
	cCadena = _T("Parámetros");
	pDC->TextOut( 700, iLinea*nHeight, cCadena );
	cCadena = _T("Valor Actual");
	pDC->TextOut( 2200, iLinea*nHeight, cCadena );
	cCadena = _T("Unidades");
	pDC->TextOut( 3700, iLinea*nHeight, cCadena );
	VerificaLinea(iLinea,1);
	
	for (int i = 1; i <= iTotalParametros; i++)
	{
		StcParametro stcParametro;
		cFichero.Lee( (char*) &stcParametro, (iPosicion * iTotalParametros) + i, sizeof(StcParametro) );
		CParametro *pParam = new CParametro;
		pParam->EstableceConStruct(&stcParametro);
		cCadena = pParam->DevuelveEtiqueta();
		pDC->TextOut( 700, iLinea*nHeight, cCadena);
		cCadena.Format( "%f", pParam->DevuelveValorActual() );
		pDC->TextOut( 2200, iLinea*nHeight, cCadena);
		cCadena = _T("Grados");
		pDC->TextOut( 3800, iLinea*nHeight, cCadena);
		VerificaLinea(iLinea,1);
		delete pParam;
		pParam = NULL;
	}
	cFichero.Close();
}

void CRealizadorReporte::ImprimeReporteInteracciones(CDC * pDC, CString & cFileFullName,
																int iTotalInteracciones, int iPosicion, LONG &iLinea)
{
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	LONG nHeight = tm.tmHeight + tm.tmExternalLeading;
	CFichero cFichero;

	if (!cFichero.Abre(cFileFullName, CFile::modeRead))
		return;


	CString cCadena = _T("");
	cCadena = _T("Interacc. Dip.");
	pDC->TextOut( 700, iLinea*nHeight, cCadena );
	cCadena = _T("Valor Actual");
	pDC->TextOut( 2200, iLinea*nHeight, cCadena );
	cCadena = _T("Unidades");
	pDC->TextOut( 3700, iLinea*nHeight, cCadena );
	VerificaLinea(iLinea,1);

	for (int i = 1; i <= iTotalInteracciones; i++)
	{
		StcValorDual stcValorDual;
		cFichero.Lee( (char*) &stcValorDual, (iPosicion*iTotalInteracciones)+i, sizeof(StcValorDual) );
		CInteraccion *pIntrc = new CInteraccion;
		pIntrc->EstableceConStruct(&stcValorDual);
		cCadena = pIntrc->DevuelveEtiquetas();
		pDC->TextOut( 900, iLinea*nHeight , cCadena);
		cCadena.Format( "%f", pIntrc->DevuelveValor() );
		pDC->TextOut( 2300, iLinea*nHeight, cCadena);
		cCadena = _T("KHz");
		pDC->TextOut( 3800, iLinea*nHeight, cCadena);
		VerificaLinea(iLinea,1);
		delete pIntrc;
		pIntrc = NULL;
	}

	cFichero.Close();
}

void CRealizadorReporte::ImprimeReporteTensores(CDC * pDC, CString cFileFullName,
														 int iPosicion, LONG &iLinea)
{
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	LONG nHeight = tm.tmHeight + tm.tmExternalLeading;
	CFichero cFichero;
	double dTxx, dTyy, dTzz, dTxxTyy, dTyz, dTzx, dTxy;

	if (!cFichero.Abre(cFileFullName, CFile::modeRead))
		return;

	CString cCadena = _T("");
	cCadena = _T("Tzz");
	pDC->TextOut( 700, iLinea*nHeight, cCadena );
	cCadena = _T("Txx - Tyy");
	pDC->TextOut( 1400, iLinea*nHeight, cCadena );
	cCadena = _T("Tyz");
	pDC->TextOut( 2400, iLinea*nHeight, cCadena );
	cCadena = _T("Tzx");
	pDC->TextOut( 3100, iLinea*nHeight, cCadena );
	cCadena = _T("Txy");
	pDC->TextOut( 3800, iLinea*nHeight, cCadena );
	cCadena = _T("Error");
	pDC->TextOut( 4500, iLinea*nHeight, cCadena );
	cCadena = _T("MAD");
	pDC->TextOut( 5200, iLinea*nHeight, cCadena );
	VerificaLinea(iLinea,1);

	for (int i= 1; i<= 7; i++)
	{
		int iPos;
		StcValorDual stcValorDual;
		cFichero.Lee( (char*) &stcValorDual, (iPosicion * 7)+i ,
			sizeof(StcValorDual) );
		CTensor *pTensor = new CTensor;
		pTensor->EstableceConStruct(&stcValorDual);
		cCadena.Format( "%.4f", pTensor->DevuelveValor() );
		switch (i)
		{
			case 1:
				iPos= 650;
				dTzz = pTensor->DevuelveValor();
				break;
			case 2:
				iPos= 1475;
				dTxxTyy = pTensor->DevuelveValor();
				break;
			case 3:
				iPos= 2350;
				dTyz = pTensor->DevuelveValor();
				break;
			case 4:
				iPos= 3050;
				dTzx = pTensor->DevuelveValor();
				break;
			case 5:
				iPos= 3750;
				dTxy = pTensor->DevuelveValor();
				break;
			case 6:
				iPos= 4450;
				break;
			case 7:
				iPos= 5150;
				break;
		}
		pDC->TextOut( iPos, iLinea*nHeight, cCadena);
		delete pTensor;
		pTensor = NULL;
	}
	VerificaLinea(iLinea,2);
	CMatriz cMatriz;
	dTxx = (dTxxTyy - dTzz) / 2;
	dTyy = dTxx - dTxxTyy;
	cMatriz.EstableceOrdenMatriz(3);
	cMatriz.EstableceCoeficientes(1,1,dTxx);
	cMatriz.EstableceCoeficientes(1,2,dTxy);
	cMatriz.EstableceCoeficientes(1,3,dTzx);
	cMatriz.EstableceCoeficientes(2,1,dTxy);
	cMatriz.EstableceCoeficientes(2,2,dTyy);
	cMatriz.EstableceCoeficientes(2,3,dTyz);
	cMatriz.EstableceCoeficientes(3,1,dTzx);
	cMatriz.EstableceCoeficientes(3,2,dTyz);
	cMatriz.EstableceCoeficientes(3,3,dTzz);
	cMatriz.DiagonalizaMatriz();
	cCadena.Format("Sxx : %f", cMatriz.DevuelveValorPropio(1));
	pDC->TextOut( 700, iLinea*nHeight, cCadena);
	VerificaLinea(iLinea,1);
	cCadena.Format("Syy : %f", cMatriz.DevuelveValorPropio(2));
	pDC->TextOut( 700, iLinea*nHeight, cCadena );
	VerificaLinea(iLinea,1);
	cCadena.Format("Szz : %f", cMatriz.DevuelveValorPropio(3));
	pDC->TextOut( 700, iLinea*nHeight, cCadena);
	VerificaLinea(iLinea,1);
	cFichero.Close();
}


void CRealizadorReporte::ImprimeReporteConformacion(CDC * pDC, int iIndex)
{
	LONG nActualLinea = 0;
	if (iIndex==0) {
		pDC->TextOut(700,nActualLinea,"Reporte Conformación de la Molécula");
		nActualLinea=2;
	}
	CParteRigida *pParteRigida = GetDoc()->DevuelveParteRigidaPtr(iIndex);
	if (pParteRigida != NULL)
		pParteRigida->ImprimeConformacion(pDC,nActualLinea);
}


void CRealizadorReporte::VerificaLinea(LONG &iLinea, int iInc)
{
	if ( (abs(iLinea) >= 62) || (abs(iLinea-iInc) >= 62))
	{
		iLinea = 0;
	}	
	else
		iLinea-=iInc;
}


