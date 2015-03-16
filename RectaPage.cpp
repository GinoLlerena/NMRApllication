// RectaPage.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "Proyecto.h"
#include "RectaPage.h"
#include "ProyectoView.h"
#include "MainFrm.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRectaPage property page

IMPLEMENT_DYNCREATE(CRectaPage, CPropertyPage)

CRectaPage::CRectaPage() : CPropertyPage(CRectaPage::IDD)
{
	//{{AFX_DATA_INIT(CRectaPage)
	m_dLongitud = 0.0;
	m_dPhi = 0.0;
	m_dTeta = 0.0;
	m_dX1 = 0.0;
	m_dX2 = 0.0;
	m_dY1 = 0.0;
	m_dY2 = 0.0;
	m_dZ1 = 0.0;
	m_dZ2 = 0.0;
	//}}AFX_DATA_INIT
}

CRectaPage::~CRectaPage()
{
}

void CRectaPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRectaPage)
	DDX_Control(pDX, IDC_IMAGEN, m_cImagen);
	DDX_Text(pDX, IDC_LONGITUD, m_dLongitud);
	DDX_Text(pDX, IDC_PHI, m_dPhi);
	DDX_Text(pDX, IDC_TETA, m_dTeta);
	DDX_Text(pDX, IDC_X1, m_dX1);
	DDX_Text(pDX, IDC_X2, m_dX2);
	DDX_Text(pDX, IDC_Y1, m_dY1);
	DDX_Text(pDX, IDC_Y2, m_dY2);
	DDX_Text(pDX, IDC_Z1, m_dZ1);
	DDX_Text(pDX, IDC_Z2, m_dZ2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRectaPage, CPropertyPage)
	//{{AFX_MSG_MAP(CRectaPage)
	ON_CBN_SELENDOK(IDC_LADO_ELEGIDO, OnSelendokLadoElegido)
	ON_EN_CHANGE(IDC_LONGITUD, OnChangeLongitud)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRectaPage message handlers

CParteRigida* CRectaPage::GetParteRigida(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());

	return pView->GetDocument()->pObjParteRigida;
}

void CRectaPage::EstableceControles(void)
{
	CComboBox* plB = (CComboBox*) GetDlgItem(IDC_LADO_ELEGIDO);
	int paso = plB->GetCurSel();

	m_dLongitud = GetParteRigida()->DevuelveLado(paso).DevuelveLongitud();
	m_dTeta = GetParteRigida()->DevuelveLado(paso).DevuelveAnguloTeta().DevuelveValor(Grados);
	m_dPhi = GetParteRigida()->DevuelveLado(paso).DevuelveAnguloPhi().DevuelveValor(Grados);
	m_dX1 = GetParteRigida()->DevuelveLado(paso).DevuelvePtoInicial().DevuelveX();
	m_dY1 = GetParteRigida()->DevuelveLado(paso).DevuelvePtoInicial().DevuelveY();
	m_dZ1 = GetParteRigida()->DevuelveLado(paso).DevuelvePtoInicial().DevuelveZ();
	m_dX2 = GetParteRigida()->DevuelveLado(paso).DevuelvePtoFinal().DevuelveX();
	m_dY2 = GetParteRigida()->DevuelveLado(paso).DevuelvePtoFinal().DevuelveY();
	m_dZ2 = GetParteRigida()->DevuelveLado(paso).DevuelvePtoFinal().DevuelveZ();

	UpdateData(FALSE);
}

void CRectaPage::OnSelendokLadoElegido() 
{
	EstableceControles();
}

void CRectaPage::OnChangeLongitud() 
{
	SetModified(TRUE);
}

void CRectaPage::OnOK() 
{
	if (m_dLongitud <= 0.0)
	{
		MessageBox(MSG24);
		return;
	}

	CPropertyPage::OnOK();

	CComboBox* plB = (CComboBox*) GetDlgItem(IDC_LADO_ELEGIDO);
	int paso = plB->GetCurSel();

	GetParteRigida()->DevuelveLado(paso).EstableceLongitud(m_dLongitud);
	GetParteRigida()->DevuelveLado(paso).DevuelveAnguloTeta().EstableceValor(m_dTeta);
	GetParteRigida()->DevuelveLado(paso).DevuelveAnguloPhi().EstableceValor(m_dPhi);
	GetParteRigida()->DevuelveLado(paso).DevuelvePtoInicial().Establece(m_dX1, m_dY1, m_dZ1);
	GetParteRigida()->DevuelveLado(paso).DevuelvePtoFinal().Establece(m_dX2, m_dY2, m_dZ2);

	GetParteRigida()->ObtieneAngulos();
	
	RedibujarVista();
}

BOOL CRectaPage::OnApply() 
{
	CPropertyPage::OnApply();
	return TRUE;
}