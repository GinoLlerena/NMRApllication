// 3DDataPage.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "3DDataPage.h"
#include "Mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C3DDataPage property page

IMPLEMENT_DYNCREATE(C3DDataPage, CPropertyPage)

C3DDataPage::C3DDataPage() : CPropertyPage(C3DDataPage::IDD)
{
	//{{AFX_DATA_INIT(C3DDataPage)
	m_fCaraFrontal = 0.0f;
	m_fCaraPosterior = 0.0f;
	m_fRotarEjeX = 0.0f;
	m_fRotarEjeY = 0.0f;
	m_fRotarEjeZ = 0.0f;
	m_fZoom = 0.0f;
	m_fAngPerspectiva = 0.0f;
	m_fValorEjeX = 0.0f;
	m_fValorEjeY = 0.0f;
	m_fValorEjeZ = 0.0f;
	//}}AFX_DATA_INIT
}

C3DDataPage::~C3DDataPage()
{
}

void C3DDataPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C3DDataPage)
	DDX_Text(pDX, IDC_CARA_FRONTAL, m_fCaraFrontal);
	DDX_Text(pDX, IDC_CARA_POSTERIOR, m_fCaraPosterior);
	DDX_Text(pDX, IDC_ROTAR_EJEX, m_fRotarEjeX);
	DDX_Text(pDX, IDC_ROTAR_EJEY, m_fRotarEjeY);
	DDX_Text(pDX, IDC_ROTAR_EJEZ, m_fRotarEjeZ);
	DDX_Text(pDX, IDC_ZOOM, m_fZoom);
	DDX_Text(pDX, IDC_ANG_PERSPECTIVA, m_fAngPerspectiva);
	DDX_Text(pDX, IDC_VALOR_EJEX, m_fValorEjeX);
	DDX_Text(pDX, IDC_VALOR_EJEY, m_fValorEjeY);
	DDX_Text(pDX, IDC_VALOR_EJEZ, m_fValorEjeZ);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(C3DDataPage, CPropertyPage)
	//{{AFX_MSG_MAP(C3DDataPage)
	ON_EN_CHANGE(IDC_ZOOM, OnChangeZoom)
	ON_EN_CHANGE(IDC_CARA_FRONTAL, OnChangeCaraFrontal)
	ON_EN_CHANGE(IDC_CARA_POSTERIOR, OnChangeCaraPosterior)
	ON_EN_CHANGE(IDC_ROTAR_EJEX, OnChangeRotarEjex)
	ON_EN_CHANGE(IDC_ROTAR_EJEY, OnChangeRotarEjey)
	ON_EN_CHANGE(IDC_ROTAR_EJEZ, OnChangeRotarEjez)
	ON_EN_CHANGE(IDC_ANG_PERSPECTIVA, OnChangeAngPerspectiva)
	ON_EN_CHANGE(IDC_VALOR_EJEX, OnChangeValorEjex)
	ON_EN_CHANGE(IDC_VALOR_EJEY, OnChangeValorEjey)
	ON_EN_CHANGE(IDC_VALOR_EJEZ, OnChangeValorEjez)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C3DDataPage message handlers

void C3DDataPage::OnChangeZoom() 
{
	SetModified(TRUE);
}

void C3DDataPage::OnChangeCaraFrontal() 
{
	SetModified(TRUE);
}

void C3DDataPage::OnChangeCaraPosterior() 
{
	SetModified(TRUE);
}

void C3DDataPage::OnChangeRotarEjex() 
{
	SetModified(TRUE);
}

void C3DDataPage::OnChangeRotarEjey() 
{
	SetModified(TRUE);
}

void C3DDataPage::OnChangeRotarEjez() 
{
	SetModified(TRUE);
}

COpenGLView* C3DDataPage::GetOpenGLView(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	COpenGLView *pView = STATIC_DOWNCAST(COpenGLView, pFrame->GetActiveView());

	return pView;
}

void C3DDataPage::EstableceControles(void)
{
	m_fZoom = GetOpenGLView()->m_fZoom;
	m_fCaraFrontal = GetOpenGLView()->m_fCaraFrontal;
	m_fCaraPosterior = GetOpenGLView()->m_fCaraPosterior;
	m_fRotarEjeX = GetOpenGLView()->m_fRotacionEnEquis;
	m_fRotarEjeY = GetOpenGLView()->m_fRotacionEnYe;
	m_fRotarEjeZ = GetOpenGLView()->m_fRotacionEnZeta;
	m_fAngPerspectiva = GetOpenGLView()->m_fAngPerspectiva;
	m_fValorEjeX = GetOpenGLView()->m_fValorEnEquis;
	m_fValorEjeY = GetOpenGLView()->m_fValorEnYe;
	m_fValorEjeZ = GetOpenGLView()->m_fValorEnZeta;

	UpdateData(FALSE);
}

BOOL C3DDataPage::OnApply() 
{
	CPropertyPage::OnApply();
	return TRUE;
}

void C3DDataPage::OnOK() 
{
	CPropertyPage::OnOK();

	GetOpenGLView()->m_fZoom = m_fZoom;
	GetOpenGLView()->m_fCaraFrontal = m_fCaraFrontal;
	GetOpenGLView()->m_fCaraPosterior = m_fCaraPosterior;
	GetOpenGLView()->m_fRotacionEnEquis = m_fRotarEjeX;
	GetOpenGLView()->m_fRotacionEnYe = m_fRotarEjeY;
	GetOpenGLView()->m_fRotacionEnZeta = m_fRotarEjeZ;
	GetOpenGLView()->m_fAngPerspectiva = m_fAngPerspectiva;
	GetOpenGLView()->m_fValorEnEquis = m_fValorEjeX;
	GetOpenGLView()->m_fValorEnYe = m_fValorEjeY;
	GetOpenGLView()->m_fValorEnZeta = m_fValorEjeZ;

	GetOpenGLView()->ActualizaPerspectiva();
}

void C3DDataPage::OnChangeAngPerspectiva() 
{
	SetModified(TRUE);	
}

void C3DDataPage::OnChangeValorEjex() 
{
	SetModified(TRUE);	
}

void C3DDataPage::OnChangeValorEjey() 
{
	SetModified(TRUE);	
}

void C3DDataPage::OnChangeValorEjez() 
{
	SetModified(TRUE);	
}
