// ParametroVariableSheet.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ParametroVariableSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParametroVariableSheet

IMPLEMENT_DYNAMIC(CParametroVariableSheet, CPropertySheet)

CParametroVariableSheet::CParametroVariableSheet(CWnd* pWndParent)
	 : CPropertySheet(IDS_PARAMETROSHT_CAPTION, pWndParent)
{
	// Add all of the property pages here.  Note that
	// the order that they appear in here will be
	// the order they appear in on screen.  By default,
	// the first page of the set is the active one.
	// One way to make a different property page the 
	// active one is to call SetActivePage().

	m_iIndiceElegido = -1;
	m_psh.dwFlags |= PSH_NOAPPLYNOW;
	AddPage(&m_cPage1);
	AddPage(&m_cPage2);
}

CParametroVariableSheet::~CParametroVariableSheet()
{
}


BEGIN_MESSAGE_MAP(CParametroVariableSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CParametroVariableSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CParametroVariableSheet message handlers

BOOL CParametroVariableSheet::OnInitDialog() 
{
	CButton *pButton = (CButton*) GetDlgItem(IDOK);
	pButton->ShowWindow(FALSE);
	pButton = (CButton*) GetDlgItem(IDCANCEL);
	pButton->SetWindowText("Cerrar");

	if (GetDoc()->m_cParametroVariableList.GetCount() > 0)
		m_iIndiceElegido = 0;

	CPropertySheet::OnInitDialog();
	return TRUE;
}

void CParametroVariableSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);
}

void CParametroVariableSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);	
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CParametroVariableSheet aditional functions

void CParametroVariableSheet::EstableceIndiceElegido(int iIndice)
{
	m_iIndiceElegido = iIndice;
}

int CParametroVariableSheet::DevuelveIndiceElegido()
{
	return m_iIndiceElegido;
}


