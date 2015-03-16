// Actualizador.cpp: implementation of the CActualizador class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Actualizador.h"
#include "InteraccObservadaSheet.h"
#include "InteraccComponentDlg.h"
#include "ParametroVariableSheet.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CActualizador::CActualizador()
{

}

CActualizador::~CActualizador()
{

}

void CActualizador::ActualizaRegistroInteraccionesObservadas(CWnd *pParent)
{
	CInteraccObservadaSheet cInteraccObservadaSheet;

	if (!cInteraccObservadaSheet.DevuelveTotalPolos() )
	{
		pParent->MessageBox(MSG2, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	if (cInteraccObservadaSheet.DevuelveTotalPolos() == 1)
	{
		pParent->MessageBox(MSG3, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}
	
	cInteraccObservadaSheet.DoModal();
}

void CActualizador::ActualizaRegistroInteraccionesComponentes(CWnd *pParent)
{
	CInteraccComponentDlg cInteraccComponentDlg;

	if (GetDoc()->m_cInteraccObservadaList.GetCount() == 0)
	{
		pParent->MessageBox(MSG7, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	cInteraccComponentDlg.DoModal();
}

void CActualizador::ActualizaRegistroParametrosVariables()
{
	CParametroVariableSheet cParametroVariableSheet;
	cParametroVariableSheet.DoModal();
}
