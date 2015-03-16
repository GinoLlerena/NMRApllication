// PreferenciasPageOne.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "PreferenciasPageOne.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageOne property page

IMPLEMENT_DYNCREATE(CPreferenciasPageOne, CPropertyPage)

CPreferenciasPageOne::CPreferenciasPageOne() : CPropertyPage(CPreferenciasPageOne::IDD)
{
	//{{AFX_DATA_INIT(CPreferenciasPageOne)
	m_iSimetria = -1;
	m_strAngulo = _T("");
	m_strDistancia = _T("");
	m_strInteraccion = _T("");
	//}}AFX_DATA_INIT
}

CPreferenciasPageOne::~CPreferenciasPageOne()
{
}

void CPreferenciasPageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreferenciasPageOne)
	DDX_Radio(pDX, IDC_SIMETRIA, m_iSimetria);
	DDX_CBString(pDX, IDC_UNID_ANGULO, m_strAngulo);
	DDX_CBString(pDX, IDC_UNID_DISTANCIA, m_strDistancia);
	DDX_CBString(pDX, IDC_UNID_INTERACC, m_strInteraccion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreferenciasPageOne, CPropertyPage)
	//{{AFX_MSG_MAP(CPreferenciasPageOne)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageOne message handlers

void CPreferenciasPageOne::OnOK() 
{
	CPropertyPage::OnOK();

	GetDoc()->EstableceStrUnidDistancia(m_strDistancia);
	GetDoc()->EstableceStrUnidAngulo(m_strAngulo);
	GetDoc()->EstableceStrUnidInteracc(m_strInteraccion);
	GetDoc()->EstableceSimetria(m_iSimetria);

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

BOOL CPreferenciasPageOne::OnInitDialog() 
{
// Unidades pred. de Distancias
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_UNID_DISTANCIA);
	pCombo->AddString(_T("Amstrong (A)"));
	m_strDistancia = GetDoc()->DevuelveStrUnidDistancia();

	// Unidades pred. de Angulos
	pCombo = (CComboBox*) GetDlgItem(IDC_UNID_ANGULO);
	pCombo->AddString(_T("Grados"));
	//pCombo->AddString(_T("Radianes"));
	m_strAngulo = GetDoc()->DevuelveStrUnidAngulo();

	// Unidades pred. de Interacciones
	pCombo = (CComboBox*) GetDlgItem(IDC_UNID_INTERACC);
	pCombo->AddString(_T("KHz"));
	//pCombo->AddString(_T("Hz"));
	//pCombo->AddString(_T("mHz"));
	m_strInteraccion = GetDoc()->DevuelveStrUnidInteracc();

	// Simetría de la molécula
	m_iSimetria = GetDoc()->DevuelveSimetria();

	//	Plano GDI de la aplicación
	
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
