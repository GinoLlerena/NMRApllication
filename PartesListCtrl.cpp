// PartesListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "PartesListCtrl.h"
#include "MainFrm.h"
#include "ProyectoView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPartesListCtrl

CPartesListCtrl::CPartesListCtrl()
{
	m_bCaptured = FALSE;
	m_iSelected = -1;
}

CPartesListCtrl::~CPartesListCtrl()
{
}

BEGIN_MESSAGE_MAP(CPartesListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CPartesListCtrl)
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBegindrag)
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPartesListCtrl message handlers

BOOL CPartesListCtrl::Init(CWnd* pParentWnd)
{
	HICON hIcon[3];
	int n;

	if (!m_cImageList.Create(32, 32, ILC_COLOR,
		0, 3)) // 32, 32 para grandes iconos
	{
		TRACE0("Failed to create ImageList\n");
		return FALSE;
	}

	hIcon[0] = AfxGetApp()->LoadIcon(IDI_ANILLOFENIL);
	hIcon[1] = AfxGetApp()->LoadIcon(IDI_BIFENIL);
	hIcon[2] = AfxGetApp()->LoadIcon(IDI_TRIFENIL);
	
	for (n = 0; n < 3; n++)
	{
		 m_cImageList.Add(hIcon[n]);
	}

	static char* parteRigida[] = {"Anillo Fenil", "Bifenil", "Trifenil"};

	RECT rect;
	rect.left = 10;
	rect.top = 10;
	rect.right = 154;
	rect.bottom = 150;

	if (!Create(WS_BORDER | WS_CHILD | WS_VISIBLE | LVS_ALIGNTOP | CBRS_SIZE_DYNAMIC |
		WS_TABSTOP | LVS_SINGLESEL | LVS_ICON, rect,	pParentWnd, IDC_PARTESLIST1))
	{
		TRACE0("Falla al crear CPartesListCtrl\n");
		return FALSE;
	}
	
	SetImageList(&m_cImageList, LVSIL_NORMAL);
	
	for (n = 0; n < 3; n++)
	{
		InsertItem(n, parteRigida[n], n);
	}

	SetBkColor(RGB(0, 196, 255)); // UGLY!

	return TRUE;
}

void CPartesListCtrl::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_iSelected = pNMListView->iItem;

	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->m_iIndiceArrastre = m_iSelected;

	*pResult = 0;
}

BOOL CPartesListCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	
	if (pView->m_iIndiceArrastre != -1)
		SetCursor( AfxGetApp()->LoadCursor(IDC_CURSORDRAG) );
	else
		SetCursor( AfxGetApp()->LoadStandardCursor(IDC_ARROW) );

	return TRUE;
}

void CPartesListCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	
	if (nFlags != MK_LBUTTON)
		pView->m_iIndiceArrastre = -1;
}
