// EjeRotacionSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "EjeRotacionSheet.h"
#include "ParametroVariable.h"
#include "ProyectoView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
 
/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionSheet

IMPLEMENT_DYNAMIC(CEjeRotacionSheet, CPropertySheet)

CEjeRotacionSheet::CEjeRotacionSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CEjeRotacionSheet::CEjeRotacionSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_cPagina.m_psp.dwFlags |= PSP_USETITLE;
	m_cPagina.m_psp.pszTitle = "Propiedades";
	AddPage(&m_cPagina);
}

CEjeRotacionSheet::~CEjeRotacionSheet()
{
}

BEGIN_MESSAGE_MAP(CEjeRotacionSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CEjeRotacionSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionSheet message handlers

BOOL CEjeRotacionSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();

	CComboBox *pCombo = (CComboBox*) m_cPagina.GetDlgItem(IDC_PARAMETRO);

	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount();
		iIndex++)
	{
		CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndex);

		if (pParamVariab != NULL)
		{
			pCombo->AddString(pParamVariab->DevuelveEtiqueta());
		}
	}

	m_cPagina.EstabControles();
	return TRUE;
}

void CEjeRotacionSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);
}

void CEjeRotacionSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionSheet Operations


void CEjeRotacionSheet::PerteneceA(ParteRigida nParteRigida)
{
	m_cPagina.m_nParteDePagina = nParteRigida;
}
