// EnlacePageThree.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "EnlacePageThree.h"
#include "EnlaceSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#include "CoordEsf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageThree property page

IMPLEMENT_DYNCREATE(CEnlacePageThree, CPropertyPage)

CEnlacePageThree::CEnlacePageThree() : CPropertyPage(CEnlacePageThree::IDD)
{
	//{{AFX_DATA_INIT(CEnlacePageThree)
	m_dLongitud = 0.0;
	m_dLongitud2 = 0.0;
	m_dPhi = 0.0;
	m_dPhi2 = 0.0;
	m_dTeta = 0.0;
	m_dTeta2 = 0.0;
	//}}AFX_DATA_INIT
}

CEnlacePageThree::~CEnlacePageThree()
{
}

void CEnlacePageThree::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnlacePageThree)
	DDX_Text(pDX, IDC_LONGITUD, m_dLongitud);
	DDX_Text(pDX, IDC_LONGITUD2, m_dLongitud2);
	DDX_Text(pDX, IDC_PHI, m_dPhi);
	DDX_Text(pDX, IDC_PHI2, m_dPhi2);
	DDX_Text(pDX, IDC_TETA, m_dTeta);
	DDX_Text(pDX, IDC_TETA2, m_dTeta2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnlacePageThree, CPropertyPage)
	//{{AFX_MSG_MAP(CEnlacePageThree)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageThree message handlers

BOOL CEnlacePageThree::OnSetActive() 
{	
	CEnlaceSheet *pSheet = STATIC_DOWNCAST(CEnlaceSheet, GetParent());
	int iIndiceActual = pSheet->DevuelveIndiceElegido();

	if (pSheet->SiEsDeAnilloFenil())
		iIndiceActual += 6;

	CCoordEsf cCesfIni,cCesfFin;

	cCesfIni.Establece( 
		DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoInicial() );
	cCesfFin.Establece(
		DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelvePtoFinal() );
	
	m_dLongitud = cCesfIni.DevuelveDistancia();
	m_dTeta = cCesfIni.DevuelveAnguloTeta().DevuelveValor(Grados);
	m_dPhi = cCesfIni.DevuelveAnguloPhi().DevuelveValor(Grados);

	m_dLongitud2 = cCesfFin.DevuelveDistancia();
	m_dTeta2 = cCesfFin.DevuelveAnguloTeta().DevuelveValor(Grados);
	m_dPhi2 = cCesfFin.DevuelveAnguloPhi().DevuelveValor(Grados);
	UpdateData(FALSE);

	return CPropertyPage::OnSetActive();
}

void CEnlacePageThree::OnOK() 
{
	CPropertyPage::OnOK();
}

CParteRigida* CEnlacePageThree::DevuelveParteRigida()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	return pView->GetDocument()->pObjParteRigida;
}
