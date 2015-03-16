// ParametroPageOne.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "MainFrm.h"
#include "ProyectoView.h"
#include "ParametroPageOne.h"
#include "ParametroSheet.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParametroPageOne property page

IMPLEMENT_DYNCREATE(CParametroPageOne, CPropertyPage)

CParametroPageOne::CParametroPageOne() : 
	CPropertyPage(CParametroPageOne::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Parámetro");

	//{{AFX_DATA_INIT(CParametroPageOne)
	m_dValorActual = 0.0;
	//}}AFX_DATA_INIT
}

CParametroPageOne::~CParametroPageOne()
{
}

void CParametroPageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParametroPageOne)
	DDX_Text(pDX, IDC_ACTUAL, m_dValorActual);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParametroPageOne, CPropertyPage)
	//{{AFX_MSG_MAP(CParametroPageOne)
	ON_EN_CHANGE(IDC_ACTUAL, OnChangeActual)
	ON_BN_CLICKED(IDGUARDAR, OnGuardar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParametroPageOne message handlers

BOOL CParametroPageOne::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CParametroPageOne::OnSetActive() 
{
	CString cStrEtiqueta = _T("");
	CString cStrValorActual = _T("0.0");

	CParametroSheet *pSheet = STATIC_DOWNCAST(CParametroSheet, GetParent());
	int iIndice = pSheet->DevuelveIndiceElegido();
	
	if (iIndice >= 0)
	{
		if (GetDoc()->DevuelveParamVariabPtr(iIndice) != NULL)
		{
			cStrEtiqueta = GetDoc()->DevuelveParamVariabPtr(iIndice)->DevuelveEtiqueta();
			cStrValorActual = 
				GetDoc()->DevuelveParamVariabPtr(iIndice)->DevuelveValorActualAsStr();			
		}
	}

  	SetEditText(IDC_ETQT, cStrEtiqueta);
	SetEditText(IDC_ACTUAL, cStrValorActual);
	UpdateData(TRUE);
	
	EnableButton(IDGUARDAR, FALSE);	
	return CPropertyPage::OnSetActive();
}

void CParametroPageOne::OnChangeActual() 
{
	EnableButton(IDGUARDAR, TRUE);
}

void CParametroPageOne::OnGuardar() 
{
	CString cStrValorActual = _T("");
	GetEditText(IDC_ACTUAL, cStrValorActual);

	if (cStrValorActual.IsEmpty())
	{
		MessageBox(MSG22, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	// Procedimiento: Modifica parámetro.
	CParametroSheet *pSheet = STATIC_DOWNCAST(CParametroSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndiceElegido);

	if (pParamVariab != NULL)
	{
		pParamVariab->EstableceValorActual(cStrValorActual);
	}
	// Fin.

	EnableButton(IDGUARDAR, FALSE);

}


/////////////////////////////////////////////////////////////////////////////
// CParametroPageOne functions

CProyectoDoc* CParametroPageOne::GetDoc(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());
	return pDoc;
}

void CParametroPageOne::SetEditText(UINT uIdentif, CString cStr)
{
	CEdit *pEdit = (CEdit*) GetDlgItem(uIdentif);
	pEdit->SetWindowText(cStr);
}

void CParametroPageOne::EnableButton(UINT uIdentif, BOOL bBandera)
{
	CButton *pButton = (CButton*) GetDlgItem(uIdentif);
	pButton->EnableWindow(bBandera);
}

void CParametroPageOne::GetEditText(UINT uIdentif, CString & cStr)
{
	CEdit *pEdit = (CEdit*) GetDlgItem(uIdentif);
	pEdit->GetWindowText(cStr);
}

