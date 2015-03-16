// PreferenciasSheet.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "PreferenciasSheet.h"
#include "ProyectoView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasSheet

IMPLEMENT_DYNAMIC(CPreferenciasSheet, CPropertySheet)

CPreferenciasSheet::CPreferenciasSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CPreferenciasSheet::CPreferenciasSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_cPageOne);
	AddPage(&m_cPageTwo);
	AddPage(&m_cPageThree);
}

CPreferenciasSheet::~CPreferenciasSheet()
{
}


BEGIN_MESSAGE_MAP(CPreferenciasSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CPreferenciasSheet)
	ON_WM_MOVE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasSheet message handlers

void CPreferenciasSheet::OnMove(int x, int y) 
{

	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMove(x, y);

}

void CPreferenciasSheet::OnDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);

	CPropertySheet::OnDestroy();

}
