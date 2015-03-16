// InteraccObservadaSheet.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "InteraccObservadaSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaSheet

IMPLEMENT_DYNAMIC(CInteraccObservadaSheet, CPropertySheet)

CInteraccObservadaSheet::CInteraccObservadaSheet(CWnd* pWndParent)
	 : CPropertySheet(IDS_INTERACCOBSSHT_CAPTION, pWndParent)
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

CInteraccObservadaSheet::~CInteraccObservadaSheet()
{
}


BEGIN_MESSAGE_MAP(CInteraccObservadaSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CInteraccObservadaSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaSheet message handlers

BOOL CInteraccObservadaSheet::OnInitDialog() 
{
	CButton *pButton = (CButton*) GetDlgItem(IDOK);
	pButton->ShowWindow(FALSE);
	pButton = (CButton*) GetDlgItem(IDCANCEL);
	pButton->SetWindowText("Cerrar");

	if (GetDoc()->m_cInteraccObservadaList.GetCount() > 0)
		m_iIndiceElegido = 0;

	CPropertySheet::OnInitDialog();
	return TRUE;
}

void CInteraccObservadaSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);	
}

void CInteraccObservadaSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);	
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaSheet aditional functions

void CInteraccObservadaSheet::EstableceIndiceElegido(int iValor)
{
	m_iIndiceElegido = iValor;
}

int CInteraccObservadaSheet::DevuelveIndiceElegido()
{
	return m_iIndiceElegido;
}


int CInteraccObservadaSheet::DevuelveTotalPolos()
{
	return m_cPage1.DevuelveTotalPolos();
}
