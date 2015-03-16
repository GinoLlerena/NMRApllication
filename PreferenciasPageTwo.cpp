// PreferenciasPageTwo.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "PreferenciasPageTwo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageTwo property page

IMPLEMENT_DYNCREATE(CPreferenciasPageTwo, CPropertyPage)

CPreferenciasPageTwo::CPreferenciasPageTwo() : CPropertyPage(CPreferenciasPageTwo::IDD)
{
	//{{AFX_DATA_INIT(CPreferenciasPageTwo)
	m_dError = 0.0;
	m_iLimite = 0;
	m_dValores = 0.0;
	//}}AFX_DATA_INIT
}

CPreferenciasPageTwo::~CPreferenciasPageTwo()
{
}

void CPreferenciasPageTwo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreferenciasPageTwo)
	DDX_Text(pDX, IDC_ERROR, m_dError);
	DDX_Text(pDX, IDC_LIMITE, m_iLimite);
	DDX_Text(pDX, IDC_VALORES, m_dValores);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreferenciasPageTwo, CPropertyPage)
	//{{AFX_MSG_MAP(CPreferenciasPageTwo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageTwo message handlers

void CPreferenciasPageTwo::OnOK() 
{

	CPropertyPage::OnOK();
	GetDoc()->m_dPorcentaje			=	m_dError;
	GetDoc()->m_iLimiteImpresion	=	m_iLimite;
	GetDoc()->m_dValoresIgnorados =	m_dValores;

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);

}

BOOL CPreferenciasPageTwo::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_dError   = GetDoc()->m_dPorcentaje;
	m_iLimite  = GetDoc()->m_iLimiteImpresion;
	m_dValores = GetDoc()->m_dValoresIgnorados;

	UpdateData(FALSE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
