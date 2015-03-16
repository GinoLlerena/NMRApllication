// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Proyecto.h"
#include "MainFrm.h"
#include "ProyectoDoc.h"
#include "ProyectoView.h"
#include "OpenGLView.h"
#include "TempView.h"
#include "Splash.h"
#include "Fichero.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VER_GDI, OnViewGDIview)
	ON_COMMAND(ID_VER_OPENGL, OnViewOpenGLview)
	ON_UPDATE_COMMAND_UI(ID_VER_OPENGL, OnUpdateViewOpenGLview)
	ON_UPDATE_COMMAND_UI(ID_VER_GDI, OnUpdateViewGDIview)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bVerMainBar = TRUE;
	m_bVerModo3DBar = TRUE;
	m_bVerPartesBar = TRUE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	EnableDocking(CBRS_ALIGN_ANY);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	if (!m_wnd3DToolBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC |
		CBRS_TOP|((m_bToolTips)?(CBRS_TOOLTIPS|CBRS_FLYBY):0)) 
		|| !m_wnd3DToolBar.LoadToolBar(IDR_3DTOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndMainBar.Init(this, m_bToolTips))
	{
		TRACE0("Failed to create MainBar\n");
		return -1;
	}	

	if (!m_wndIconosDlgBar.Init(this))
	{
		TRACE0("Failed to create IconosDlgBar\n");
		return -1;
	}

	m_wnd3DToolBar.SetWindowText(_T("Vision 3D"));
	m_wnd3DToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wnd3DToolBar.ShowWindow(SW_HIDE);

	m_wndMainBar.SetWindowText(_T("Menú"));
	m_wndMainBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndMainBar.ShowWindow(SW_SHOW);

	m_wndIconosDlgBar.SetWindowText(_T("Partes Rígidas"));
	m_wndIconosDlgBar.EnableDocking(CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT);
	m_wndIconosDlgBar.ShowWindow(SW_SHOW);

	DockControlBar(&m_wndMainBar, AFX_IDW_DOCKBAR_TOP);
	DockControlBar(&m_wnd3DToolBar, AFX_IDW_DOCKBAR_TOP);
	DockControlBar(&m_wndIconosDlgBar, AFX_IDW_DOCKBAR_LEFT | AFX_IDW_DOCKBAR_RIGHT);

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

void CMainFrame::SwitchToView(eView nView)
{	
	CView* pOldActiveView = GetActiveView();
	CView* pNewActiveView = (CView*)GetDlgItem(nView);

	if (pNewActiveView == NULL)
	{	
		switch(nView)
		{
			
			case GDI:
				pNewActiveView = (CView*)new CProyectoView;
				break;
			
			case OPENGL:
				pNewActiveView = (CView*)new COpenGLView;
				break;
			
			case TEMP:
				pNewActiveView = (CView*)new CTempView;
				break;
		}
		
		CCreateContext context; 						
		context.m_pCurrentDoc = pOldActiveView->GetDocument(); 
		pNewActiveView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault,
			this, nView, &context);		 
		pNewActiveView->OnInitialUpdate();
	}

	SetActiveView(pNewActiveView);						  
	pNewActiveView->ShowWindow(SW_SHOW); 
	pOldActiveView->ShowWindow(SW_HIDE);

	pOldActiveView->SetDlgCtrlID(
		pOldActiveView->GetRuntimeClass() ==
		RUNTIME_CLASS(CProyectoView) ? GDI : 
		(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(COpenGLView) ? OPENGL : TEMP));
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout(); 
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnViewGDIview() 
{
	ShowControlBar(&m_wndIconosDlgBar, m_bVerPartesBar, TRUE);
	ShowControlBar(&m_wndMainBar, m_bVerMainBar, TRUE);
	ShowControlBar(&m_wnd3DToolBar, FALSE, TRUE);
	
	SwitchToView(GDI);
}

void CMainFrame::OnUpdateViewGDIview(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(
		!GetActiveView()->IsKindOf(RUNTIME_CLASS(CProyectoView)));
}

void CMainFrame::OnViewOpenGLview() 
{
	ShowControlBar(&m_wndIconosDlgBar, FALSE, FALSE);
	ShowControlBar(&m_wndMainBar, FALSE, FALSE);
	ShowControlBar(&m_wnd3DToolBar, m_bVerModo3DBar, FALSE);
	RecalcLayout();
	SwitchToView(OPENGL);	
	
}

void CMainFrame::OnUpdateViewOpenGLview(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(
		!GetActiveView()->IsKindOf(RUNTIME_CLASS(COpenGLView)));
}

void CMainFrame::Serialize(CArchive& ar) 
{
	m_wndMainBar.m_ObjectsBox.Serialize(ar);
}



