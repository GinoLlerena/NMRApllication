// AnguloPage.cpp : implementation file of CAnguloPage class.
//

#include "stdafx.h"
#include "Resource.h"
#include "Proyecto.h"
#include "AnguloPage.h"
#include "ProyectoView.h"
#include "MainFrm.h"
#include "Structures.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnguloPage property page

IMPLEMENT_DYNCREATE(CAnguloPage, CPropertyPage)

CAnguloPage::CAnguloPage() : CPropertyPage(CAnguloPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Angulo");

	//{{AFX_DATA_INIT(CAnguloPage)
	m_dValor = 0.0;
	m_strEstado = _T("");
	m_strParametro = _T("");
	//}}AFX_DATA_INIT

	m_bEsInterno = TRUE;
}

CAnguloPage::~CAnguloPage()
{
}

void CAnguloPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnguloPage)
	DDX_Control(pDX, IDC_IMAGEN, m_cImagen);
	DDX_Text(pDX, IDC_VALOR, m_dValor);
	DDX_CBString(pDX, IDC_ESTADO, m_strEstado);
	DDX_CBString(pDX, IDC_PARAMETRO, m_strParametro);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnguloPage, CPropertyPage)
	//{{AFX_MSG_MAP(CAnguloPage)
	ON_CBN_SELENDOK(IDC_ANG_ELEGIDO, OnSelendokAngElegido)
	ON_EN_CHANGE(IDC_VALOR, OnChangeValor)
	ON_CBN_SELENDOK(IDC_ESTADO, OnSelendokEstado)
	ON_CBN_SELENDOK(IDC_PARAMETRO, OnSelendokParametro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnguloPage message handlers

void CAnguloPage::OnSelendokAngElegido() 
{
	EstableceControles();
}

void CAnguloPage::OnChangeValor()
{
	SetModified(TRUE);
}

void CAnguloPage::OnSelendokEstado() 
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_ESTADO);
	int iIndice = pCombo->GetCurSel();

	if (!iIndice)
		m_strEstado = _T("Fijo");
	else
		m_strEstado = _T("Variable");

	ActuaSegunEstado();
	SetModified(TRUE);
}

void CAnguloPage::OnSelendokParametro() 
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_PARAMETRO);
	int iIndiceSel = pCombo->GetCurSel();

	CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndiceSel-1);

	if (pParamVariab != NULL)
	{
		SetEditText(IDC_VALOR, pParamVariab->DevuelveValorActualAsStr());
		SetModified(TRUE);
	}	
}

void CAnguloPage::OnOK() 
{
	CPropertyPage::OnOK();
	ActuaSegunEstado();

	CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_ANG_ELEGIDO);
	int iIndex = pCombo->GetCurSel();

	if (!m_bEsInterno)
		iIndex += 6;

	GetParteRigida()->DevuelveAngulo(iIndex).EstableceValor(m_dValor);
	GetParteRigida()->DevuelveAngulo(iIndex).EstableceEstado(m_strEstado);
	GetParteRigida()->DevuelveAngulo(iIndex).EstableceEtiqueta(m_strParametro);

	switch (iIndex)
	{
		case 2:
		case 5:
			GetParteRigida()->ObtieneAngulos();
		break;
	}
		
	RedibujarVista();
}

BOOL CAnguloPage::OnApply() 
{
	CPropertyPage::OnApply();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAnguloPage aditional functions

CParteRigida* CAnguloPage::GetParteRigida(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());

	return pView->GetDocument()->pObjParteRigida;
}

void CAnguloPage::EstableceControles(void)
{
	CComboBox* pCombo= (CComboBox*) GetDlgItem(IDC_ANG_ELEGIDO);
	int iIndex = pCombo->GetCurSel();
	
	if (!m_bEsInterno)
		iIndex += 6;

	m_dValor = GetParteRigida()->DevuelveAngulo(iIndex).DevuelveValor(Grados);
	m_strEstado = GetParteRigida()->DevuelveAngulo(iIndex).DevuelveEstado();
	m_strParametro = GetParteRigida()->DevuelveAngulo(iIndex).DevuelveEtiqueta();
	ActuaSegunEstado();
	UpdateData(FALSE);
}

void CAnguloPage::ActuaSegunEstado(void)
{
	BOOL bHabilitarEstado = FALSE;
	BOOL bHabilitarParametro = FALSE;

	if (m_strEstado == _T("Fijo") &&
		GetDoc()->m_cParametroVariableList.GetCount() > 0)
	{
		//SetComboText(IDC_PARAMETRO, _T(""));
		bHabilitarEstado = TRUE;
	}

	if (m_strEstado == _T("Variable"))
	{
		bHabilitarEstado = TRUE;
		bHabilitarParametro = TRUE;
	}

	EnableCombo(IDC_ESTADO, bHabilitarEstado);
	EnableCombo(IDC_PARAMETRO, bHabilitarParametro);
}

void CAnguloPage::EnableCombo(UINT uIdentif, BOOL bHabilitar)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->EnableWindow(bHabilitar);
}

void CAnguloPage::SetComboText(UINT uIdentif, CString cString)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->SetWindowText(cString);
}

void CAnguloPage::SetEditText(UINT uIdentif, CString cString)
{
	CEdit *pEdit = (CEdit*) GetDlgItem(uIdentif);
	pEdit->SetWindowText(cString);
}

void CAnguloPage::GetComboText(UINT uIdentif, CString & cString)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->GetWindowText(cString);
}
