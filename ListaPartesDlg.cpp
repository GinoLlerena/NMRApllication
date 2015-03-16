// ListaPartesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListaPartesDlg.h"
#include "Mainfrm.h"
#include "ProyectoView.h"
#include "Rutinas.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListaPartesDlg dialog

CListaPartesDlg::CListaPartesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListaPartesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListaPartesDlg)
	//}}AFX_DATA_INIT	
}

CListaPartesDlg::~CListaPartesDlg()
{
}

void CListaPartesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListaPartesDlg)
	DDX_Control(pDX, IDC_LIST_LIST1, m_cList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListaPartesDlg, CDialog)
	//{{AFX_MSG_MAP(CListaPartesDlg)
	ON_BN_CLICKED(IDC_LIST_ACTIVAR, OnListActivar)
	ON_BN_CLICKED(IDC_LIST_ELIMINAR, OnListEliminar)
	ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListaPartesDlg message handlers

BOOL CListaPartesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CMainBar* pMainBar = &pFrame->m_wndMainBar;
	CString str;

	m_cList.ResetContent();

	for (int paso = 0; paso < pMainBar->m_ObjectsBox.GetCount(); paso++)
	{
		pMainBar->m_ObjectsBox.GetLBText(paso, str);
		m_cList.AddString(str);
	}

	m_cList.SetCurSel(0);
	return TRUE;
}

void CListaPartesDlg::OnMove(int x, int y) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CDialog::OnMove(x, y);
}

void CListaPartesDlg::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CDialog::PostNcDestroy();
}

void CListaPartesDlg::OnListActivar() 
{
	if (m_cList.GetCount() == 0)
		return;

	ParteRigida nParte;
	CString str;
	int nPos;
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView* pView = STATIC_DOWNCAST(CProyectoView, 
		pFrame->GetActiveFrame()->GetActiveView());
	CMainBar* pMainBar = &pFrame->m_wndMainBar;

	nPos = m_cList.GetCurSel();
	m_cList.GetText(nPos, str);
	nParte = DevuelveIdParteRigida(str);
	EstableceParametros(nParte,nPos);
	pMainBar->m_ObjectsBox.SetCurSel(nPos);

	pView->Invalidate(TRUE);
}

void CListaPartesDlg::OnListEliminar() 
{
	if (m_cList.GetCount() == 0)
		return;

	CString str;
	ParteRigida nParte;

	int  nPosSel, flag, nPosActual, nTot;
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView* pView = STATIC_DOWNCAST(CProyectoView, 
		pFrame->GetActiveFrame()->GetActiveView());
	CMainBar* pMainBar = &pFrame->m_wndMainBar;

	nPosSel = m_cList.GetCurSel();
	
	if (m_cList.GetCount() == 1 || nPosSel == (m_cList.GetCount() - 1))
		 flag = pView->MessageBox(MSG18, "Advertencia",	MB_ICONEXCLAMATION | MB_OKCANCEL);
	else
		if (nPosSel < (m_cList.GetCount() - 1))
			flag = pView->MessageBox(MSG19, "Advertencia", MB_ICONEXCLAMATION | MB_OKCANCEL);

	if (flag != IDOK)
		return;

	nPosActual = nPosSel-1;
	nTot = m_cList.GetCount();
	
	for (int paso = nTot-1;  paso > nPosActual; paso--)
	{
		m_cList.GetText(paso, str);
		nParte = DevuelveIdParteRigida(str);
		pMainBar->m_ObjectsBox.DeleteString(paso);
		m_cList.DeleteString(paso);
		pView->m_cConstructorMolecula.EliminaParteRigida(paso, nParte);
	}

	if (nPosActual != -1)
	{ 
		m_cList.SetCurSel(nPosActual);
		m_cList.GetText(nPosActual, str);
		nParte = DevuelveIdParteRigida(str);
		EstableceParametros(nParte,nPosActual);
		pMainBar->m_ObjectsBox.SetCurSel(nPosActual);
	}
	else { 
			pView->GetDocument()->m_nParteRigida=Ninguna;
			pMainBar->m_ObjectsBox.SetCurSel(0);
	}
	
	pView->Invalidate(TRUE);
	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

void EstableceParametros(ParteRigida nParte, int nPos)
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView* pView = STATIC_DOWNCAST(CProyectoView, 
		pFrame->GetActiveFrame()->GetActiveView());
	POSITION Posicion;
	Posicion= pView->GetDocument()->m_cParteRigidaList.FindIndex(nPos);
				 
	if (Posicion != NULL) 
		pView->GetDocument()->pObjParteRigida= pView->GetDocument()->m_cParteRigidaList.GetAt(Posicion);
	
	switch(nParte)
	{
		case AnilloFenil:
			pView->GetDocument()->m_nParteRigida = AnilloFenil;
			break;
		case Bifenil:
			pView->GetDocument()->m_nParteRigida = Bifenil;
			break;
		case Trifenil:
			pView->GetDocument()->m_nParteRigida = Trifenil;
			break;
	}
}

