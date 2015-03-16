// CalculoTensoresPageDos.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "CalculoTensoresPageDos.h"
#include "InteraccComponent.h"
#include "Rutinas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresPageDos property page

IMPLEMENT_DYNCREATE(CCalculoTensoresPageDos, CPropertyPage)

CCalculoTensoresPageDos::CCalculoTensoresPageDos() : CPropertyPage(CCalculoTensoresPageDos::IDD)
{
	//{{AFX_DATA_INIT(CCalculoTensoresPageDos)
	m_strDistorcionEtiquetaA = _T("");
	m_strDistorcionEtiquetaB = _T("");
	m_strDistorcionEtiquetaC = _T("");
	m_strSeleccionEtiquetaA = _T("");
	m_strSeleccionEtiquetaB = _T("");
	m_strSeleccionEtiquetaC = _T("");
	//}}AFX_DATA_INIT
}

CCalculoTensoresPageDos::~CCalculoTensoresPageDos()
{
}

void CCalculoTensoresPageDos::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculoTensoresPageDos)
	DDX_CBString(pDX, IDC_INTA, m_strDistorcionEtiquetaA);
	DDX_CBString(pDX, IDC_INTB, m_strDistorcionEtiquetaB);
	DDX_CBString(pDX, IDC_INTC, m_strDistorcionEtiquetaC);
	DDX_CBString(pDX, IDC_SELECC1, m_strSeleccionEtiquetaA);
	DDX_CBString(pDX, IDC_SELECC2, m_strSeleccionEtiquetaB);
	DDX_CBString(pDX, IDC_SELECC3, m_strSeleccionEtiquetaC);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalculoTensoresPageDos, CPropertyPage)
	//{{AFX_MSG_MAP(CCalculoTensoresPageDos)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresPageDos message handlers

BOOL CCalculoTensoresPageDos::InitPolos()
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
			
			CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_INTA);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_INTB);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_INTC);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC1);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC2);
			pCombo->AddString(cStr);
			pCombo = (CComboBox*) GetDlgItem(IDC_SELECC3);
			pCombo->AddString(cStr);
		}
	}

	return TRUE;
}

BOOL CCalculoTensoresPageDos::OnInitDialog() 
{
	if (!InitPolos())
		return FALSE;

	m_strDistorcionEtiquetaA = GetDoc()->m_cDistorcion.DevuelveEtiquetasInteraccA();
	m_strDistorcionEtiquetaB = GetDoc()->m_cDistorcion.DevuelveEtiquetasInteraccB();
	m_strDistorcionEtiquetaC = GetDoc()->m_cDistorcion.DevuelveEtiquetasInteraccC();
	m_strSeleccionEtiquetaA = GetDoc()->m_cInteraccSelecc[0].DevuelveEtiqueta();
	m_strSeleccionEtiquetaB = GetDoc()->m_cInteraccSelecc[1].DevuelveEtiqueta();
	m_strSeleccionEtiquetaC = GetDoc()->m_cInteraccSelecc[2].DevuelveEtiqueta();
	UpdateData(FALSE);
	
	return TRUE;  
}

void CCalculoTensoresPageDos::OnOK() 
{
	CPropertyPage::OnOK();

	GetDoc()->m_cDistorcion.EstableceEtiquetasInteraccA(m_strDistorcionEtiquetaA);
	GetDoc()->m_cDistorcion.EstableceInteraccion( 0,
		DevuelveValorSegunEtiqueta(m_strDistorcionEtiquetaA) );
	GetDoc()->m_cDistorcion.EstableceDistancia( 
		DevuelveDistanciaRij(m_strDistorcionEtiquetaA) );
	GetDoc()->m_cDistorcion.EstableceConstante(
		DevuelveConstante(m_strDistorcionEtiquetaA) );

	GetDoc()->m_cDistorcion.EstableceEtiquetasInteraccB(m_strDistorcionEtiquetaB);
	GetDoc()->m_cDistorcion.EstableceInteraccion( 1,
		DevuelveValorSegunEtiqueta(m_strDistorcionEtiquetaB) );

	GetDoc()->m_cDistorcion.EstableceEtiquetasInteraccC(m_strDistorcionEtiquetaC);
	GetDoc()->m_cDistorcion.EstableceInteraccion( 2,
		DevuelveValorSegunEtiqueta(m_strDistorcionEtiquetaC) );

	GetDoc()->m_cInteraccSelecc[0].EstableceValorActual(
		DevuelveValorSegunEtiqueta(m_strSeleccionEtiquetaA) );
	GetDoc()->m_cInteraccSelecc[0].EstableceEtiqueta(m_strSeleccionEtiquetaA);

	GetDoc()->m_cInteraccSelecc[1].EstableceValorActual(
		DevuelveValorSegunEtiqueta(m_strSeleccionEtiquetaB) );
	GetDoc()->m_cInteraccSelecc[1].EstableceEtiqueta(m_strSeleccionEtiquetaB);

	GetDoc()->m_cInteraccSelecc[2].EstableceValorActual(
		DevuelveValorSegunEtiqueta(m_strSeleccionEtiquetaC) );
	GetDoc()->m_cInteraccSelecc[2].EstableceEtiqueta(m_strSeleccionEtiquetaC);

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

double CCalculoTensoresPageDos::DevuelveDistanciaRij(CString str)
{
	double dValor =0;
	CPunto cPtoInicial;
	CPunto cPtoFinal;
	CString cStr;
	CString cStrEtiqueta1= _T("");
	CString cStrEtiqueta2= _T("");
	if(!DevuelveEtiquetasDij(str,cStrEtiqueta1,cStrEtiqueta2))
		return -1;
	cPtoInicial = GetDoc()->DevuelveParteRigidaListPunto(cStrEtiqueta1,cStr);
	cPtoFinal = GetDoc()->DevuelveParteRigidaListPunto(cStrEtiqueta2,cStr);
	dValor=CalculaDistancia(cPtoInicial, cPtoFinal);

	return dValor;

}

double CCalculoTensoresPageDos::DevuelveValorSegunEtiqueta(CString cStr)
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


double CCalculoTensoresPageDos::DevuelveConstante(CString str)
{
	double dValor=0.0;
	CPunto cTmp;
	CString cStrTipoUno;
	CString cStrTipoDos;
	CInteraccComponent CIc;

	for (int iPaso = 0; iPaso < GetDoc()->m_cInteraccObservadaList.GetCount(); iPaso++)
	{
		CInteraccObservada *pIntrcObs = GetDoc()->DevuelveInteraccObservadaPtr(iPaso);

		if (pIntrcObs != NULL)
		{
			if (pIntrcObs->DevuelveEtiquetas() == str)
			{
				cTmp = GetDoc()->DevuelveParteRigidaListPunto(pIntrcObs->DevuelveEtiqueta1(),
						cStrTipoUno);
				cTmp = GetDoc()->DevuelveParteRigidaListPunto(pIntrcObs->DevuelveEtiqueta2(),
						cStrTipoDos);
				dValor = CIc.DevuelveConstante(cStrTipoUno, cStrTipoDos);
			}
		}
	}
	return dValor;
}
