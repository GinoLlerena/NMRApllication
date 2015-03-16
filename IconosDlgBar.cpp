// IconosDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "IconosDlgBar.h"
#include "Resource.h"
#include "ProyectoView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconosDlgBar dialog

CIconosDlgBar::CIconosDlgBar() : CDialogBar()
{
}

CIconosDlgBar::~CIconosDlgBar()
{
}

BEGIN_MESSAGE_MAP(CIconosDlgBar, CDialogBar)
	//{{AFX_MSG_MAP(CIconosDlgBar)
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconosDlgBar message handlers

BOOL CIconosDlgBar::Init(CWnd* pParentWnd)
{
	if (!Create(pParentWnd, IDD_ICONOS,
		CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT | CBRS_TOOLTIPS | CBRS_FLYBY, // | CBRS_HIDE_INPLACE,
		ID_VER_BARRAPARTES))
	{
		TRACE0("Falla al crear CIconosDlgBar\n");
		return FALSE;      // falla al crear
	}

	if (!m_cPartesListCtrl.Init(this))
	{
		TRACE0("Falla al crear CPartesListCtrl\n");
		return FALSE;      // falla al crear
	}

	return TRUE;
}

BOOL CIconosDlgBar::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	
	if (pView->m_iIndiceArrastre != -1)
		SetCursor( AfxGetApp()->LoadCursor(IDC_CURSORDRAG) );
	else
		SetCursor( AfxGetApp()->LoadStandardCursor(IDC_ARROW) );

	return TRUE;
}

void CIconosDlgBar::OnMouseMove(UINT nFlags, CPoint point) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	
	if (nFlags != MK_LBUTTON)
		pView->m_iIndiceArrastre = -1;
}
