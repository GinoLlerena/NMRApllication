// EnlacePageOne.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "EnlacePageOne.h"
#include "EnlaceSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageOne property page

IMPLEMENT_DYNCREATE(CEnlacePageOne, CPropertyPage)

CEnlacePageOne::CEnlacePageOne() : CPropertyPage(CEnlacePageOne::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Enlace");
	m_bEsDeAnilloFenil = FALSE;

	//{{AFX_DATA_INIT(CEnlacePageOne)
	m_strEnlace = _T("");
	m_dLongitud = 0.0;
	m_strEstado = _T("");
	m_strTipo = _T("");
	m_strEtiqueta = _T("");
	m_strEtqtParametro = _T("");
	//}}AFX_DATA_INIT
}

CEnlacePageOne::~CEnlacePageOne()
{
}

void CEnlacePageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnlacePageOne)
	DDX_Control(pDX, IDC_IMAGEN, m_cImagen);
	DDX_CBString(pDX, IDC_ENLACE_ELEGIDO, m_strEnlace);
	DDX_Text(pDX, IDC_LONGITUD, m_dLongitud);
	DDX_CBString(pDX, IDC_ESTADO, m_strEstado);
	DDX_CBString(pDX, IDC_TIPO, m_strTipo);
	DDX_Text(pDX, IDC_ETIQUETA, m_strEtiqueta);
	DDX_CBString(pDX, IDC_ETQTPARAM, m_strEtqtParametro);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnlacePageOne, CPropertyPage)
	//{{AFX_MSG_MAP(CEnlacePageOne)
	ON_CBN_SELENDOK(IDC_ENLACE_ELEGIDO, OnSelendokEnlaceElegido)
	ON_EN_CHANGE(IDC_LONGITUD, OnChangeLongitud)
	ON_CBN_SELENDOK(IDC_ESTADO, OnSelendokEstado)
	ON_CBN_SELENDOK(IDC_TIPO, OnSelendokTipo)
	ON_EN_CHANGE(IDC_ETIQUETA, OnChangeEtiqueta)
	ON_CBN_SELENDOK(IDC_ETQTPARAM, OnSelendokEtqtparam)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageOne message handlers

BOOL CEnlacePageOne::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	HBITMAP hBitmap;
	int iTotalEnlaces = 0;
	CString *pString;

	switch (m_nParteDePagina)
	{
		case AnilloFenil:
			pString = (CString*) EnlaceAnillofenil;
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ANILLOFENIL) );
			m_bEsDeAnilloFenil = TRUE;
			iTotalEnlaces = 6;
			break;
		case Bifenil:
			pString = (CString*) EnlaceBifenil;
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BIFENIL) );
			m_bEsDeAnilloFenil = FALSE;
			iTotalEnlaces = 2;
			break;
		case Trifenil:
			pString = (CString*) EnlaceTrifenil;
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TRIFENIL) );
			m_bEsDeAnilloFenil = FALSE;
         iTotalEnlaces = 4;
			break;
	}

	m_cImagen.SetBitmap(hBitmap);	// Establece el bitmap adecuado.

	for (int iPaso = 0; iPaso < iTotalEnlaces; iPaso++)
	{
		CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_ENLACE_ELEGIDO);
		pCombo->AddString(*(pString + iPaso));
	}

	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount();
		iIndex++)
	{
		CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndex);

		if (pParamVariab != NULL)
		{
			CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_ETQTPARAM);
			pCombo->AddString(pParamVariab->DevuelveEtiqueta());
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CEnlacePageOne::OnSetActive() 
{
	CPropertyPage::OnSetActive();

	CEnlaceSheet *pSheet = STATIC_DOWNCAST(CEnlaceSheet, GetParent());
	int iIndiceActual = pSheet->DevuelveIndiceElegido();
	InicializaControles(iIndiceActual);
	UpdateData(FALSE); // Actualizar siempre antes de establecer enfoque

	CString cStrEnlace = _T("");
	CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_ENLACE_ELEGIDO);
	pCombo->SetCurSel(iIndiceActual);
	pCombo->GetLBText(iIndiceActual, cStrEnlace);
	pSheet->EstableceEnlace(cStrEnlace);
	return TRUE;
}

void CEnlacePageOne::OnSelendokEnlaceElegido() 
{
	CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_ENLACE_ELEGIDO);
	int iIndiceActual = pCombo->GetCurSel();
	InicializaControles(iIndiceActual);	
	UpdateData(FALSE);
	
	CString cStrEnlace = _T("");
	pCombo->GetLBText(iIndiceActual, cStrEnlace);
	CEnlaceSheet *pSheet = STATIC_DOWNCAST(CEnlaceSheet, GetParent());
	pSheet->EstableceIndiceElegido(iIndiceActual);
	pSheet->EstableceEnlace(cStrEnlace);

	pCombo->SetCurSel(iIndiceActual);
}

void CEnlacePageOne::OnChangeLongitud() 
{
	SetModified(TRUE);	
}

void CEnlacePageOne::OnSelendokEstado() 
{
	CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_ESTADO);
	int iSelected = pCombo->GetCurSel();
	CString cStrEstado = _T("");
	pCombo->GetLBText(iSelected, cStrEstado);

	if (cStrEstado == _T("Variable"))
		EnableEdit(IDC_ETQTPARAM, TRUE);
	else
	{
		EnableEdit(IDC_ETQTPARAM, FALSE);
	}

	SetModified(TRUE);	
}

void CEnlacePageOne::OnSelendokEtqtparam() 
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_ETQTPARAM);
	int iIndiceSel = pCombo->GetCurSel();

	CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndiceSel-1);

	if (pParamVariab != NULL)
	{
		SetEditText(IDC_LONGITUD, pParamVariab->DevuelveValorActualAsStr());
		SetModified(TRUE);
	}
}

void CEnlacePageOne::OnSelendokTipo() 
{
	CComboBox* pCombo = (CComboBox*) GetDlgItem(IDC_TIPO);
	int iSelected = pCombo->GetCurSel();
	CString cStrTipo = _T("");
	pCombo->GetLBText(iSelected, cStrTipo);

	if (cStrTipo == _T("Fluor") || cStrTipo == _T("Proton") || cStrTipo == _T("Deuterio"))
		EnableEdit(IDC_ETIQUETA, TRUE);
	else
		EnableEdit(IDC_ETIQUETA, FALSE);

	SetModified(TRUE);
}

void CEnlacePageOne::OnChangeEtiqueta() 
{
	SetModified(TRUE);
}

void CEnlacePageOne::OnOK() 
{
	CEnlaceSheet *pSheet = STATIC_DOWNCAST(CEnlaceSheet, GetParent());
	int iIndiceActual = pSheet->DevuelveIndiceElegido();

	DevuelveParteRigida()->DevuelveSpin(iIndiceActual).EstableceEtiqueta(m_strEtiqueta); // Ver en BF y TF.

	if (m_bEsDeAnilloFenil)
		iIndiceActual += 6;

   DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceLongitud(m_dLongitud);
	DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceEstado(m_strEstado);
	DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceEtiqueta(
		m_strEtqtParametro);
	DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceTipo(m_strTipo);

   ActualizaEnlaces(iIndiceActual);
	RedibujarVista();

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);

	CPropertyPage::OnOK();
}

BOOL CEnlacePageOne::OnApply() 
{
	CPropertyPage::OnApply();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageOne Input Data functions

void CEnlacePageOne::EsDeAnilloFenil(BOOL bBandera)
{
	m_bEsDeAnilloFenil = bBandera;
}

void CEnlacePageOne::PerteneceA(ParteRigida nParteRigida)
{
	m_nParteDePagina = nParteRigida;
}

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageOne Output Data functions


CParteRigida* CEnlacePageOne::DevuelveParteRigida()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	return pView->GetDocument()->pObjParteRigida;
}

int CEnlacePageOne::DevuelveMaxIndiceMolecula()
{
	int iCountTot = 0;
	
	for (int iIndice = 0; iIndice < GetDoc()->m_cParteRigidaList.GetCount();
		iIndice++)
	{
		CParteRigida *pParteRigida = GetDoc()->DevuelveParteRigidaPtr(iIndice);

		if (pParteRigida != NULL)
		{
			if (iCountTot < pParteRigida->DevuelveMaxEnlace())
				iCountTot = pParteRigida->DevuelveMaxEnlace();
		}
	}

	return iCountTot;
}

void CEnlacePageOne::GetComboText(UINT uIdentif, CString & cString)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->GetWindowText(cString);
}

BOOL CEnlacePageOne::SiEsDeAnilloFenil()
{
	return m_bEsDeAnilloFenil;
}

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageOne aditional functions

void CEnlacePageOne::InicializaControles(int iIndiceActual)
{
	m_strEtiqueta = DevuelveParteRigida()->DevuelveSpin(iIndiceActual).DevuelveEtiqueta();

	if (m_bEsDeAnilloFenil)
		iIndiceActual += 6;

	m_dLongitud = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveLongitud();
	m_strEstado = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveEstado();
	m_strTipo = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveTipo();
	m_strEtqtParametro = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveEtiqueta();
	HabilitaControles(iIndiceActual);
}

void CEnlacePageOne::HabilitaControles(int iIndiceActual)
{
	POSITION PosActual = GetDoc()->m_cParteRigidaList.Find(DevuelveParteRigida());
	POSITION PosHead = GetDoc()->m_cParteRigidaList.GetHeadPosition();
	BOOL bHabilitar = FALSE;

	if (iIndiceActual == 8 || iIndiceActual == 11)
		EnableCombo(IDC_ESTADO, !bHabilitar);
	else
		EnableCombo(IDC_ESTADO, bHabilitar);
	
	if (PosActual != PosHead)
	{
		switch (DevuelveParteRigida()->DevuelveParte())
		{
			case AnilloFenil:
				if (iIndiceActual == 8)
				{
					bHabilitar = TRUE;
					EnableCombo(IDC_ESTADO, !bHabilitar);
				}
				else
					bHabilitar = FALSE;					
				break;

			case Bifenil:
				if (iIndiceActual == 0)
					bHabilitar = TRUE;
				else
					bHabilitar = FALSE;
				break;

			case Trifenil:
				if (iIndiceActual == 3)
					bHabilitar = TRUE;
				else
					bHabilitar = FALSE;
				break;
		}
	}

	if (bHabilitar)
	{
		DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceTipo(_T("Enlazado"));
		m_strTipo = _T("Enlazado");
	}

	EnableEdit(IDC_LONGITUD, !bHabilitar);
	EnableCombo(IDC_TIPO, !bHabilitar);

	if (DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveIndiceEnlace())
	{
		if (GetDoc()->m_cParteRigidaList.FindIndex(
			DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveIndiceEnlace()) != NULL)
		{
			EnableCombo(IDC_TIPO, FALSE);
		}
		else
			EnableCombo(IDC_TIPO, TRUE);
	}

	if (m_strTipo == _T("Fluor") || m_strTipo == _T("Proton"))
		EnableEdit(IDC_ETIQUETA, TRUE);
	else
		EnableEdit(IDC_ETIQUETA, FALSE);
}


void CEnlacePageOne::ActualizaEnlaces(int iIndiceActual)
{
	int iMaxIndice = 0;
	int iMaxIndMolecula = 0;
 
	if (m_strTipo == "Enlace")
	{
		if (DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveIndiceEnlace() == 0)
		{
			double radio;
			int iIndice = 0;

			iMaxIndice = GetDoc()->m_cParteRigidaList.GetCount();
			iMaxIndMolecula = DevuelveMaxIndiceMolecula();
			if (iMaxIndice <= iMaxIndMolecula)
				iMaxIndice = iMaxIndMolecula + 1;

			DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceIndiceEnlace(iMaxIndice);

			switch (DevuelveParteRigida()->DevuelveParte())
			{
				case AnilloFenil:
					radio = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveRadio();
					DevuelveParteRigida()->DevuelveSpin(iIndiceActual - 6).EstableceColor(5);
					DevuelveParteRigida()->DevuelveSpin(iIndiceActual - 6).EstableceRadio(radio);					
					break;
				case Bifenil:
					radio = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveRadio();
					if (iIndiceActual == 1)
						iIndice = 2;
					else
						iIndice = 0;

					DevuelveParteRigida()->DevuelveSpin(iIndice).EstableceColor(5);
					DevuelveParteRigida()->DevuelveSpin(iIndice).EstableceRadio(radio);
					break;
				case Trifenil:
					radio = DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveRadio();
					DevuelveParteRigida()->DevuelveSpin(2).EstableceColor(5);
					DevuelveParteRigida()->DevuelveSpin(2).EstableceRadio(radio);
					DevuelveParteRigida()->DevuelveSpin(0).EstableceColor(5);
					DevuelveParteRigida()->DevuelveSpin(0).EstableceRadio(radio);
					break;
			}
		}
	}
   else
		if (DevuelveParteRigida()->DevuelveLado(iIndiceActual).DevuelveIndiceEnlace() != 0)
			DevuelveParteRigida()->DevuelveLado(iIndiceActual).EstableceIndiceEnlace(0);
}


void CEnlacePageOne::EnableEdit(UINT uIdentif, BOOL bBandera)
{
	CEdit *pEdit = (CEdit*) GetDlgItem(uIdentif);
	pEdit->EnableWindow(bBandera);
}

void CEnlacePageOne::EnableCombo(UINT uIdentif, BOOL bBandera)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->EnableWindow(bBandera);
}

void CEnlacePageOne::SetEditText(UINT uIdentif, CString cString)
{
	CEdit *pEdit = (CEdit*) GetDlgItem(uIdentif);
	pEdit->SetWindowText(cString);
}

