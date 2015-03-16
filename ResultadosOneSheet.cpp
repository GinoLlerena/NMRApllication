// ResultadosOneSheet.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ResultadosOneSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultadosOneSheet

IMPLEMENT_DYNAMIC(CResultadosOneSheet, CPropertySheet)

CResultadosOneSheet::CResultadosOneSheet(CWnd* pWndParent) :
	CPropertySheet(IDS_RESULTSONESHT_CAPTION, pWndParent)
{
	// Add all of the property pages here.  Note that
	// the order that they appear in here will be
	// the order they appear in on screen.  By default,
	// the first page of the set is the active one.
	// One way to make a different property page the 
	// active one is to call SetActivePage().

	m_iIndiceElegido = 1;
	m_psh.dwFlags |= PSH_NOAPPLYNOW;
	AddPage(&m_cPage1);
	AddPage(&m_cPage2);
	AddPage(&m_cPage3);
}

CResultadosOneSheet::~CResultadosOneSheet()
{
}


BEGIN_MESSAGE_MAP(CResultadosOneSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CResultadosOneSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CResultadosOneSheet message handlers

BOOL CResultadosOneSheet::OnInitDialog() 
{
	CButton *pButton = (CButton*) GetDlgItem(IDOK);
	pButton->ShowWindow(FALSE);
	pButton = (CButton*) GetDlgItem(IDCANCEL);
	pButton->SetWindowText("Cerrar");

	m_iIndiceElegido = 1;
	CPropertySheet::OnInitDialog();
	return TRUE;
}

void CResultadosOneSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);
}

void CResultadosOneSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CResultadosOneSheet aditional functions

void CResultadosOneSheet::EstableceIndiceElegido(int iIndice)
{
	m_iIndiceElegido = iIndice;
}

int CResultadosOneSheet::DevuelveIndiceElegido()
{
	return m_iIndiceElegido;
}


