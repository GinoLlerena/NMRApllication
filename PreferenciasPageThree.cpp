// PreferenciasPageThree.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "PreferenciasPageThree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageThree property page

IMPLEMENT_DYNCREATE(CPreferenciasPageThree, CPropertyPage)

CPreferenciasPageThree::CPreferenciasPageThree() : CPropertyPage(CPreferenciasPageThree::IDD)
{
	//{{AFX_DATA_INIT(CPreferenciasPageThree)
	m_dPuntoInicialEquis = 0.0;
	m_dPuntoFinalEquis = 0.0;
	m_dPuntoInicialYe = 0.0;
	m_dPuntoFinalYe = 0.0;
	m_dPuntoInicialZeta = 0.0;
	m_dPuntoFinalZeta = 0.0;
	m_strPlanoGDI = _T("");
	//}}AFX_DATA_INIT
}

CPreferenciasPageThree::~CPreferenciasPageThree()
{
}

void CPreferenciasPageThree::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreferenciasPageThree)
	DDX_Text(pDX, IDC_EJEX1, m_dPuntoInicialEquis);
	DDX_Text(pDX, IDC_EJEX2, m_dPuntoFinalEquis);
	DDX_Text(pDX, IDC_EJEY1, m_dPuntoInicialYe);
	DDX_Text(pDX, IDC_EJEY2, m_dPuntoFinalYe);
	DDX_Text(pDX, IDC_EJEZ1, m_dPuntoInicialZeta);
	DDX_Text(pDX, IDC_EJEZ2, m_dPuntoFinalZeta);
	DDX_CBString(pDX, IDC_PLANO, m_strPlanoGDI);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreferenciasPageThree, CPropertyPage)
	//{{AFX_MSG_MAP(CPreferenciasPageThree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageThree message handlers

void CPreferenciasPageThree::OnOK() 
{
	CPropertyPage::OnOK();
	
	GetDoc()->DevuelvePtoInicioEjeSimetria().EstableceX(m_dPuntoInicialEquis);
	GetDoc()->DevuelvePtoInicioEjeSimetria().EstableceY(m_dPuntoInicialYe);
	GetDoc()->DevuelvePtoInicioEjeSimetria().EstableceZ(m_dPuntoInicialZeta);
	GetDoc()->DevuelvePtoFinalEjeSimetria().EstableceX(m_dPuntoFinalEquis);
	GetDoc()->DevuelvePtoFinalEjeSimetria().EstableceY(m_dPuntoFinalYe);
	GetDoc()->DevuelvePtoFinalEjeSimetria().EstableceZ(m_dPuntoFinalZeta);
	GetDoc()->EstablecePlanoGDI(m_strPlanoGDI);
	
	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

BOOL CPreferenciasPageThree::OnInitDialog() 
{

	m_dPuntoInicialEquis = GetDoc()->DevuelvePtoInicioEjeSimetria().DevuelveX();
	m_dPuntoInicialYe = GetDoc()->DevuelvePtoInicioEjeSimetria().DevuelveY();
	m_dPuntoInicialZeta = GetDoc()->DevuelvePtoInicioEjeSimetria().DevuelveZ();
	m_dPuntoFinalEquis = GetDoc()->DevuelvePtoFinalEjeSimetria().DevuelveX();
	m_dPuntoFinalYe = GetDoc()->DevuelvePtoFinalEjeSimetria().DevuelveY();
	m_dPuntoFinalZeta = GetDoc()->DevuelvePtoFinalEjeSimetria().DevuelveZ();
	m_strPlanoGDI = GetDoc()->DevuelvePlanoGDI();

	CPropertyPage::OnInitDialog();
	
	return TRUE;  
}
