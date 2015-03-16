// EjeRotacionPage.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "EjeRotacionPage.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionPage property page

IMPLEMENT_DYNCREATE(CEjeRotacionPage, CPropertyPage)

CEjeRotacionPage::CEjeRotacionPage() : CPropertyPage(CEjeRotacionPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = "Angulo";

	//{{AFX_DATA_INIT(CEjeRotacionPage)
	m_strEtiqueta = _T("");
	m_dValor = 0.0;
	m_strEstado = _T("");
	m_strParametro = _T("");
	//}}AFX_DATA_INIT
}

CEjeRotacionPage::~CEjeRotacionPage()
{
}

void CEjeRotacionPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEjeRotacionPage)
	DDX_Control(pDX, IDC_IMAGEN, m_cImagen);
	DDX_Text(pDX, IDC_ETQT, m_strEtiqueta);
	DDX_Text(pDX, IDC_VALOR, m_dValor);
	DDX_CBString(pDX, IDC_ESTADO, m_strEstado);
	DDX_CBString(pDX, IDC_PARAMETRO, m_strParametro);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEjeRotacionPage, CPropertyPage)
	//{{AFX_MSG_MAP(CEjeRotacionPage)
	ON_EN_CHANGE(IDC_VALOR, OnChangeValor)
	ON_CBN_SELENDOK(IDC_ESTADO, OnSelendokEstado)
	ON_CBN_SELENDOK(IDC_PARAMETRO, OnSelendokParametro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionPage message handlers

void CEjeRotacionPage::OnChangeValor() 
{
	SetModified(TRUE);	
}

void CEjeRotacionPage::OnSelendokEstado() 
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_ESTADO);
	int iIndice = pCombo->GetCurSel();
	
	if (!iIndice)
		m_strEstado = "Fijo";
	else
		m_strEstado = "Variable";
	
	ActuaSegunEstado();
	SetModified(TRUE);	
}

void CEjeRotacionPage::OnSelendokParametro()
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_PARAMETRO);
	int iIndiceSel = pCombo->GetCurSel();

	CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndiceSel);

	if (pParamVariab != NULL)
	{
		SetEditText(IDC_VALOR, pParamVariab->DevuelveValorActualAsStr());
	}

	SetModified(TRUE);
}

void CEjeRotacionPage::OnOK() 
{
	CPropertyPage::OnOK();
	ActuaSegunEstado();

	GetParteRigida()->DevuelveAnguloRotacion().EstableceValor(m_dValor);
	GetParteRigida()->DevuelveAnguloRotacion().EstableceEstado(m_strEstado);
	GetParteRigida()->DevuelveAnguloRotacion().EstableceEtiqueta(m_strParametro);

	RedibujarVista();
}

BOOL CEjeRotacionPage::OnApply() 
{
	CPropertyPage::OnApply();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionPage aditional functions

CParteRigida* CEjeRotacionPage::GetParteRigida()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	return pView->GetDocument()->pObjParteRigida;
}

void CEjeRotacionPage::EstabControles()
{
	m_strEtiqueta = _T("Rotación");
	CEdit *pEdit = (CEdit*) GetDlgItem(IDC_ETQT);
	pEdit->EnableWindow(FALSE);

	HBITMAP hBitmap;

	switch (m_nParteDePagina)
	{
		case AnilloFenil:
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_EJEANILLOFENIL) );
			break;
		case Bifenil:
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_EJEBIFENIL) );
			break;
		case Trifenil:
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_EJETRIFENIL) );
			break;
	}

	m_cImagen.SetBitmap(hBitmap);	// Establece la imagen adecuada.
	m_dValor = GetParteRigida()->DevuelveAnguloRotacion().DevuelveValor(Grados);
	m_strEstado = GetParteRigida()->DevuelveAnguloRotacion().DevuelveEstado();
	m_strParametro = GetParteRigida()->DevuelveAnguloRotacion().DevuelveEtiqueta();

	ActuaSegunEstado();	
	UpdateData(FALSE);
}

void CEjeRotacionPage::ActuaSegunEstado()
{
	BOOL bHabilitarEstado = FALSE;
	BOOL bHabilitarParametro = FALSE;

	if (m_strEstado == _T("Fijo") &&
		GetDoc()->m_cParametroVariableList.GetCount() > 0)
	{
		SetComboText(IDC_PARAMETRO, _T(""));
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


void CEjeRotacionPage::EnableCombo(UINT uIdentif, BOOL bHabilitar)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->EnableWindow(bHabilitar);
}

void CEjeRotacionPage::SetComboText(UINT uIdentif, CString cString)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->SetWindowText(cString);
}

void CEjeRotacionPage::SetEditText(UINT uIdentif, CString cString)
{
	CEdit *pEdit = (CEdit*) GetDlgItem(uIdentif);
	pEdit->SetWindowText(cString);
}

void CEjeRotacionPage::GetComboText(UINT uIdentif, CString & cString)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->GetWindowText(cString);
}

/////////////////////////////////////////////////////////////////////////////
// Funciones amigas de la Clase CEjeRotacionPage 

void RedibujarVista(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
}
