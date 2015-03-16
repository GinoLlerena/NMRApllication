// CalculoTensoresPageUno.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "ProyectoView.h"
#include "Mainfrm.h"
#include "ProyectoDoc.h"
#include "CalculoTensoresPageUno.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresPageUno property page

IMPLEMENT_DYNCREATE(CCalculoTensoresPageUno, CPropertyPage)

CCalculoTensoresPageUno::CCalculoTensoresPageUno() : CPropertyPage(CCalculoTensoresPageUno::IDD)
{
	//{{AFX_DATA_INIT(CCalculoTensoresPageUno)
	m_strSeleccionA = _T("");
	m_strSeleccionB = _T("");
	m_strSeleccionC = _T("");
	//}}AFX_DATA_INIT
}

CCalculoTensoresPageUno::~CCalculoTensoresPageUno()
{
}

void CCalculoTensoresPageUno::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculoTensoresPageUno)
	DDX_CBString(pDX, IDC_SELECC1, m_strSeleccionA);
	DDX_CBString(pDX, IDC_SELECC2, m_strSeleccionB);
	DDX_CBString(pDX, IDC_SELECC3, m_strSeleccionC);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalculoTensoresPageUno, CPropertyPage)
	//{{AFX_MSG_MAP(CCalculoTensoresPageUno)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresPageUno message handlers

BOOL CCalculoTensoresPageUno::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	CComboBox *pCombo;
	
	if (!InitPolos())
		return FALSE;

	int iSimetria = GetDoc()->DevuelveSimetria();

	switch (iSimetria)
	{
		case 0:	// D4
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC3);
			pCombo->EnableWindow(FALSE);
			break;
		case 1:	// D2
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC3);
			pCombo->EnableWindow(TRUE);
			break;
	}

	m_strSeleccionA = GetDoc()->m_cInteraccSelecc[0].DevuelveEtiqueta();
	m_strSeleccionB = GetDoc()->m_cInteraccSelecc[1].DevuelveEtiqueta();
	m_strSeleccionC = GetDoc()->m_cInteraccSelecc[2].DevuelveEtiqueta();
	UpdateData(FALSE);

	return TRUE;
}

BOOL CCalculoTensoresPageUno::InitPolos()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	
	for (int pass = 0; pass < pView->GetDocument()->m_cInteraccObservadaList.GetCount(); pass++)
	{
		POSITION Posicion = NULL;
		Posicion = pView->GetDocument()->m_cInteraccObservadaList.FindIndex(pass);

		if (Posicion != NULL)
		{
			CInteraccObservada *pIntrcObs = pView->GetDocument()->m_cInteraccObservadaList.GetAt(Posicion);

			CString cStr = _T("");
			cStr = pIntrcObs->DevuelveEtiqueta1() + ", " + pIntrcObs->DevuelveEtiqueta2();
			
			CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_SELECC1);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC2);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC3);
			pCombo->AddString(cStr);
		}
	}

	return TRUE;
}

double CCalculoTensoresPageUno::DevuelveValorSegunEtiqueta(CString cStr)
{
	for (int iPaso = 0; iPaso < GetDoc()->m_cInteraccObservadaList.GetCount(); iPaso++)
	{
		CInteraccObservada *pIntrcObs = GetDoc()->DevuelveInteraccObservadaPtr(iPaso);

		if (pIntrcObs != NULL)
		{
			if (pIntrcObs->DevuelveEtiquetas() == cStr)
				return pIntrcObs->DevuelveValor();
		}
	}
	return 0;
}


CProyectoDoc* GetDoc()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	//CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CView *pView = pFrame->GetActiveView();
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());

	return pDoc;
}



void CCalculoTensoresPageUno::OnOK() 
{
	CPropertyPage::OnOK();
	
	GetDoc()->m_cInteraccSelecc[0].EstableceValorActual(DevuelveValorSegunEtiqueta(m_strSeleccionA));
	GetDoc()->m_cInteraccSelecc[0].EstableceEtiqueta(m_strSeleccionA);

	GetDoc()->m_cInteraccSelecc[1].EstableceValorActual(DevuelveValorSegunEtiqueta(m_strSeleccionB));
	GetDoc()->m_cInteraccSelecc[1].EstableceEtiqueta(m_strSeleccionB);

	GetDoc()->m_cInteraccSelecc[2].EstableceValorActual(DevuelveValorSegunEtiqueta(m_strSeleccionC));
	GetDoc()->m_cInteraccSelecc[2].EstableceEtiqueta(m_strSeleccionC);

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CCalculosTensoresPageUno aditional functions
