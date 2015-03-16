// RealizadorReporte.h: interface for the CRealizadorReporte class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REALIZADORREPORTE_H__31930CA4_5416_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_REALIZADORREPORTE_H__31930CA4_5416_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "Seleccionadora.h"
#include	"ProyectoDoc.h"

class CRealizadorReporte : public CObject  
{
public :
	CSeleccionadora m_cSeleccion;

public:
	CRealizadorReporte();
	virtual ~CRealizadorReporte();
	void ImprimeSeleccion(CDC * pDC, int iSeleccion, int iIndex);
	void BuscaMejorAjuste(CString & cFileFullName, int iTotal, int iTipo);
	CString ComparaStatusDosFicheros(CString cPathName, int iRegistro);
	void ImprimeReporteConformacion(CDC * pDC, int iIndex);
	void ImprimeReporteTensores(CDC * pDC, CString cFileFullName, int iPosicion, LONG &iLinea);
	void ImprimeReporteInteracciones(CDC * pDC, CString & cFileFullName, int iTotalLineasImprimir, int iTotalCopias, LONG & iLinea);
	void ImprimeReporteParametros(CDC * pDC, CString & cFileFullName, int iTotalParametros,
	int iPosicion, LONG &iLinea);
	void VerificaLinea(LONG &iLinea, int iInc);
private :
	extern friend CProyectoDoc* GetDoc(void);
		
};

#endif // !defined(AFX_REALIZADORREPORTE_H__31930CA4_5416_11D2_A5A8_444553540001__INCLUDED_)
