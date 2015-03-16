// EnlacePageTwo.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "EnlacePageTwo.h"
#include "EnlaceSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageTwo property page

IMPLEMENT_DYNCREATE(CEnlacePageTwo, CPropertyPage)

CEnlacePageTwo::CEnlacePageTwo() : CPropertyPage(CEnlacePageTwo::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Coordenadas");

	//{{AFX_DATA_INIT(CEnlacePageTwo)
	m_strEnlace = _T("");
	m_dLongitud = 0.0;
	m_dAnguloPhi = 0.0;
	m_dAnguloTeta = 0.0;
	m_dX1 = 0.0;
	m_dX2 = 0.0;
	m_dY1 = 0.0;
	m_dY2 = 0.0;
	m_dZ1 = 0.0;
	m_dZ2 = 0.0;
	//}}AFX_DATA_INIT
}

CEnlacePageTwo::~CEnlacePageTwo()
{
}

void CEnlacePageTwo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnlacePageTwo)
	DDX_Text(pDX, IDC_LADOS, m_strEnlace);
	DDX_Text(pDX, IDC_LONGITUD, m_dLongitud);
	DDX_Text(pDX, IDC_PHI, m_dAnguloPhi);
	DDX_Text(pDX, IDC_TETA, m_dAnguloTeta);
	DDX_Text(pDX, IDC_X1, m_dX1);
	DDX_Text(pDX, IDC_X2, m_dX2);
	DDX_Text(pDX, IDC_Y1, m_dY1);
	DDX_Text(pDX, IDC_Y2, m_dY2);
	DDX_Text(pDX, IDC_Z1, m_dZ1);
	DDX_Text(pDX, IDC_Z2, m_dZ2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnlacePageTwo, CPropertyPage)
	//{{AFX_MSG_MAP(CEnlacePageTwo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageTwo message handlers

BOOL CEnlacePageTwo::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CEnlacePageTwo::OnSetActive() 
{
	CEnlaceSheet *pSheet = STATIC_DOWNCAST(CEnlaceSheet, GetParent());
	int iIndiceActual = pSheet->DevuelveIndiceElegido();

	if (pSheet->SiEsDeAnilloFenil())
		iIndiceActual += 6;

	m_strEnlace = pSheet->DevuelveEnlace();
	m_dLongitud = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveLongitud();
	m_dAnguloTeta = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveAnguloTeta().DevuelveValor(Grados);
	m_dAnguloPhi = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveAnguloPhi().DevuelveValor(Grados);
	m_dX1 = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoInicial().DevuelveX();
	m_dY1 = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoInicial().DevuelveY();
	m_dZ1 = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoInicial().DevuelveZ();
	m_dX2 = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoFinal().DevuelveX();
	m_dY2 = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoFinal().DevuelveY();
	m_dZ2 = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoFinal().DevuelveZ();
	UpdateData(FALSE);
	return CPropertyPage::OnSetActive();
}

void CEnlacePageTwo::OnOK() 
{
	CPropertyPage::OnOK();
}


/////////////////////////////////////////////////////////////////////////////
// CEnlacePageTwo Output functions

CParteRigida* CEnlacePageTwo::DevuelveParteRigida()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	return pView->GetDocument()->pObjParteRigida;
}
