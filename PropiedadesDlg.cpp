// PropiedadesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "PropiedadesDlg.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropiedadesDlg dialog


CPropiedadesDlg::CPropiedadesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPropiedadesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropiedadesDlg)
	m_strTitulo = _T("");
	m_strAsunto = _T("");
	m_strCreador = _T("");
	m_strDescripcion = _T("");
	m_strProyecto = _T("");
	m_strCarpeta = _T("");
	//}}AFX_DATA_INIT
}


void CPropiedadesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropiedadesDlg)
	DDX_Text(pDX, IDC_TITULO, m_strTitulo);
	DDX_Text(pDX, IDC_ASUNTO, m_strAsunto);
	DDX_Text(pDX, IDC_CREADOR, m_strCreador);
	DDX_Text(pDX, IDC_DESCRIPCION, m_strDescripcion);
	DDX_Text(pDX, IDC_NOMBREPROY, m_strProyecto);
	DDX_Text(pDX, IDC_CARPETA, m_strCarpeta);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropiedadesDlg, CDialog)
	//{{AFX_MSG_MAP(CPropiedadesDlg)
	ON_EN_CHANGE(IDC_TITULO, OnChangeTitulo)
	ON_EN_CHANGE(IDC_ASUNTO, OnChangeAsunto)
	ON_EN_CHANGE(IDC_CREADOR, OnChangeCreador)
	ON_EN_CHANGE(IDC_DESCRIPCION, OnChangeDescripcion)
	ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropiedadesDlg message handlers

BOOL CPropiedadesDlg::OnInitDialog() 
{
	// Inicializando los controles
	m_strProyecto = DevuelveDoc()->GetTitle();
	m_strCarpeta = DevuelveDoc()->GetPathName();
	m_strTitulo = DevuelveDoc()->DevuelveStrTituloDoc();
	m_strAsunto = DevuelveDoc()->DevuelveStrAsuntoDoc();
	m_strCreador = DevuelveDoc()->DevuelveStrCreadorDoc();
	m_strDescripcion = DevuelveDoc()->DevuelveStrDescripcionDoc();

	EnableButton(IDOK, FALSE);
	EnableButton(IDCANCEL, TRUE);

	CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPropiedadesDlg::OnMove(int x, int y) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CDialog::OnMove(x, y);
}

void CPropiedadesDlg::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);	
	CDialog::PostNcDestroy();
}

void CPropiedadesDlg::OnChangeTitulo() 
{
	EnableButton(IDOK, TRUE);
	EnableButton(IDCANCEL, TRUE);
}

void CPropiedadesDlg::OnChangeAsunto() 
{
	EnableButton(IDOK, TRUE);
	EnableButton(IDCANCEL, TRUE);
}

void CPropiedadesDlg::OnChangeCreador() 
{
	EnableButton(IDOK, TRUE);
	EnableButton(IDCANCEL, TRUE);
}

void CPropiedadesDlg::OnChangeDescripcion() 
{
	EnableButton(IDOK, TRUE);
	EnableButton(IDCANCEL, TRUE);	
}

void CPropiedadesDlg::OnOK() 
{
	CDialog::OnOK();

	// Grabando datos
	DevuelveDoc()->EstableceStrTituloDoc(m_strTitulo);
	DevuelveDoc()->EstableceStrAsuntoDoc(m_strAsunto);
	DevuelveDoc()->EstableceStrCreadorDoc(m_strCreador);
	DevuelveDoc()->EstableceStrDescripcionDoc(m_strDescripcion);
	DevuelveDoc()->SetModifiedFlag(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// Our CPropiedadesDlg functions

CProyectoDoc* CPropiedadesDlg::DevuelveDoc()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());
	return pDoc;
}

void CPropiedadesDlg::EnableButton(UINT uIdentif, BOOL bBandera)
{
	CButton *pButton = (CButton*) GetDlgItem(uIdentif);
	pButton->EnableWindow(bBandera);
}
