// InteraccObservadaPageOne.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "InteraccObservadaPageOne.h"
#include "InteraccObservadaSheet.h"
#include "InteraccComponent.h"
#include "Rutinas.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CInteraccObservadaPageOne, CPropertyPage)

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageOne property page

CInteraccObservadaPageOne::CInteraccObservadaPageOne() : CPropertyPage(CInteraccObservadaPageOne::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Interacc. Obsservada");

	//{{AFX_DATA_INIT(CInteraccObservadaPageOne)
	m_strEtiqueta1 = _T("");
	m_strEtiqueta2 = _T("");
	m_dValorObservado = 0.0;
	m_bUsoTzz = FALSE;
	m_bUsoTxxMinusTyy = FALSE;
	m_bUsoTyz = FALSE;
	m_bUsoTzx = FALSE;
	m_bUsoTxy = FALSE;
	//}}AFX_DATA_INIT
}

CInteraccObservadaPageOne::~CInteraccObservadaPageOne()
{
}

void CInteraccObservadaPageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInteraccObservadaPageOne)
	DDX_CBString(pDX, IDC_ETQTPOLO1, m_strEtiqueta1);
	DDX_CBString(pDX, IDC_ETQTPOLO2, m_strEtiqueta2);
	DDX_Text(pDX, IDC_VALOROBSERVADO, m_dValorObservado);
	DDX_Check(pDX, IDC_TZZ, m_bUsoTzz);
	DDX_Check(pDX, IDC_TXXMINUSTYY, m_bUsoTxxMinusTyy);
	DDX_Check(pDX, IDC_TYZ, m_bUsoTyz);
	DDX_Check(pDX, IDC_TZX, m_bUsoTzx);
	DDX_Check(pDX, IDC_TXY, m_bUsoTxy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInteraccObservadaPageOne, CPropertyPage)
	//{{AFX_MSG_MAP(CInteraccObservadaPageOne)
	ON_CBN_SELENDOK(IDC_ETQTPOLO1, OnSelendokEtqtpolo1)
	ON_CBN_SELENDOK(IDC_ETQTPOLO2, OnSelendokEtqtpolo2)
	ON_EN_CHANGE(IDC_VALOROBSERVADO, OnChangeValorobservado)
	ON_BN_CLICKED(IDC_TZZ, OnTzz)
	ON_BN_CLICKED(IDC_TXXMINUSTYY, OnTxxminustyy)
	ON_BN_CLICKED(IDC_TYZ, OnTyz)
	ON_BN_CLICKED(IDC_TZX, OnTzx)
	ON_BN_CLICKED(IDC_TXY, OnTxy)
	ON_BN_CLICKED(IDNUEVO, OnNuevo)
	ON_BN_CLICKED(IDGUARDAR, OnGuardar)
	ON_BN_CLICKED(IDELIMINAR, OnEliminar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageOne message handlers

BOOL CInteraccObservadaPageOne::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	if ( !InicializaComboBoxes() )
		return FALSE;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CInteraccObservadaPageOne::OnSetActive() 
{
	CInteraccObservadaSheet *pSheet = STATIC_DOWNCAST(CInteraccObservadaSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();
	
	if (iIndiceElegido >= 0)
	{
		if (GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido) != NULL)
		{
			m_strEtiqueta1 = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveEtiqueta1();
			m_strEtiqueta2 = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveEtiqueta2();
			m_dValorObservado =
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveValor();
			m_bUsoTzz = GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveUsoTzz();
			m_bUsoTxxMinusTyy = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveUsoTxxMinusTyy();
			m_bUsoTyz = GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveUsoTyz();
			m_bUsoTzx = GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveUsoTzx();
			m_bUsoTxy = GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido)->DevuelveUsoTxy();
		}
	}

	UpdateData(FALSE);	// Inicializa a todos los controles.
	
	if (iIndiceElegido >= 0)
	{
		EnableButton(IDNUEVO, TRUE);
		EnableButton(IDELIMINAR, TRUE);
	}
	else
	{
		EnableButton(IDNUEVO, FALSE);
		EnableButton(IDELIMINAR, FALSE);
	}

	EnableButton(IDGUARDAR, FALSE);	
	return CPropertyPage::OnSetActive();
}

void CInteraccObservadaPageOne::OnSelendokEtqtpolo1() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);	
}

void CInteraccObservadaPageOne::OnSelendokEtqtpolo2() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnChangeValorobservado() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnTzz() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnTxxminustyy() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnTyz() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnTzx() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);	
}

void CInteraccObservadaPageOne::OnTxy() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnNuevo() 
{
	CInteraccObservadaSheet *pSheet = STATIC_DOWNCAST( CInteraccObservadaSheet, GetParent() );
	pSheet->EstableceIndiceElegido(-1);

	m_strEtiqueta1 = _T(" ");
	m_strEtiqueta2 = _T(" ");
	m_dValorObservado = 0.0;
	m_bUsoTzz = TRUE;
	m_bUsoTxxMinusTyy = TRUE;
	m_bUsoTyz = FALSE;
	m_bUsoTzx = FALSE;
	m_bUsoTxy = FALSE;
	UpdateData(FALSE);		// Inicializa a todos los controles

	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, FALSE);
}

void CInteraccObservadaPageOne::OnGuardar() 
{
	UpdateData(TRUE);

	if ( m_strEtiqueta1 == _T(" ") )
	{
		MessageBox(MSG16, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	if ( m_strEtiqueta2 == _T(" ") )
	{
		MessageBox(MSG16, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	if (m_strEtiqueta1 == m_strEtiqueta2)
	{
		MessageBox(MSG10, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	CInteraccObservadaSheet *pSheet = STATIC_DOWNCAST(CInteraccObservadaSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	// Procedimiento: Modifica una interacción observada.
	if (iIndiceElegido >= 0)
	{
		CInteraccObservada *pInteraccObs =
			GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido);

		if (pInteraccObs != NULL)
		{
			int iIndice = -1;

			iIndice = DevuelveUbicacionListaEtiquetas(m_strEtiqueta1, m_strEtiqueta2);

			if ( (iIndice == -1) ||					// Etiquetas no existen en la lista.
				(iIndice == iIndiceElegido) )		// Etiquetas existen en la misma 
															//	ubicación iIndiceElegido dentro de la lista.
			{
				CString cAnteriorEtiqueta1 = pInteraccObs->DevuelveEtiqueta1();
				CString cAnteriorEtiqueta2 = pInteraccObs->DevuelveEtiqueta2();

				pInteraccObs->EstableceEtiqueta1(m_strEtiqueta1);
				pInteraccObs->EstableceEtiqueta2(m_strEtiqueta2);
				pInteraccObs->EstableceValor(m_dValorObservado);
				pInteraccObs->EstableceUsoTzz(m_bUsoTzz);
				pInteraccObs->EstableceUsoTxxMinusTyy(m_bUsoTxxMinusTyy);
				pInteraccObs->EstableceUsoTyz(m_bUsoTyz);
				pInteraccObs->EstableceUsoTzx(m_bUsoTzx);
				pInteraccObs->EstableceUsoTxy(m_bUsoTxy);

				ModificaInteraccComponentList(cAnteriorEtiqueta1, cAnteriorEtiqueta2,
					m_strEtiqueta1, m_strEtiqueta2);
			}
			else
			{
				MessageBox(MSG17, "Advertencia", MB_ICONEXCLAMATION);
				return;
			}
		}
	}

	// Procedimiento: Adiciona nueva interacción observada
	//						e interacción componente
	if (iIndiceElegido == -1)
	{
		int iIndice = -1;

		iIndice = DevuelveUbicacionListaEtiquetas(m_strEtiqueta1, m_strEtiqueta2);

		if ( (iIndice == iIndiceElegido) )		// Etiquetas no existen en la lista.
		{
			//	Adiciona nueva interacción observada
			CInteraccObservada *pInteraccObs = new CInteraccObservada;
			pInteraccObs->EstableceEtiqueta1(m_strEtiqueta1);
			pInteraccObs->EstableceEtiqueta2(m_strEtiqueta2);
			pInteraccObs->EstableceValor(m_dValorObservado);
			pInteraccObs->EstableceUsoTzz(m_bUsoTzz);
			pInteraccObs->EstableceUsoTxxMinusTyy(m_bUsoTxxMinusTyy);
			pInteraccObs->EstableceUsoTyz(m_bUsoTyz);
			pInteraccObs->EstableceUsoTzx(m_bUsoTzx);
			pInteraccObs->EstableceUsoTxy(m_bUsoTxy);
			GetDoc()->m_cInteraccObservadaList.AddTail(pInteraccObs);

			//	Adiciona nueva interacción componente
			CInteraccComponent *pInteraccComponent = new CInteraccComponent;
			pInteraccComponent->EstableceEtiquetaBase1(m_strEtiqueta1);
			pInteraccComponent->EstableceEtiquetaBase2(m_strEtiqueta2);
			pInteraccComponent->EstableceEtiqueta1(m_strEtiqueta1);
			pInteraccComponent->EstableceEtiqueta2(m_strEtiqueta2);
			GetDoc()->m_cInteraccComponentList.AddTail(pInteraccComponent);

			CInteraccObservadaSheet *pSheet = 
				STATIC_DOWNCAST(CInteraccObservadaSheet, GetParent());
			int iTotalElementos = GetDoc()->m_cInteraccObservadaList.GetCount();
			pSheet->EstableceIndiceElegido(iTotalElementos - 1);
		}
		else
		{
			MessageBox(MSG17, "Advertencia", MB_ICONEXCLAMATION);
			return;
		}
	}

	EnableButton(IDNUEVO, TRUE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, TRUE);
	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

void CInteraccObservadaPageOne::OnEliminar() 
{
	CInteraccObservadaSheet *pSheet = STATIC_DOWNCAST(CInteraccObservadaSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	CString cEtiquetas = _T("");

	// Procedimiento: Elimina interacción observada.
	POSITION Posicion = NULL;
	Posicion = GetDoc()->m_cInteraccObservadaList.FindIndex(iIndiceElegido);

	if (Posicion != NULL)
	{
		CInteraccObservada *pInteraccObs = 
			GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido);

		cEtiquetas = pInteraccObs->DevuelveEtiquetas();

		if (pInteraccObs != NULL)
		{
			delete pInteraccObs;
			GetDoc()->m_cInteraccObservadaList.RemoveAt(Posicion);
		}
	}
	// Fin.

	// Procedimiento: Elimina interacciones componentes de la interacción observada.
	for (int iIndex = 0; iIndex < GetDoc()->m_cInteraccComponentList.GetCount(); iIndex++)
	{
		Posicion  = NULL;
		Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(iIndex);

		if (Posicion != NULL)
		{
			CInteraccComponent *pInteraccComponent =
				GetDoc()->m_cInteraccComponentList.GetAt(Posicion);

			if ( (pInteraccComponent != NULL) &&
				( cEtiquetas == pInteraccComponent->DevuelveEtiquetasBase() ) )
			{
				delete pInteraccComponent;
				GetDoc()->m_cInteraccComponentList.RemoveAt(Posicion);
				iIndex -= 1;
			}
		}
	}
	// Fin

	// Procedimiento: Obtiene valores de una interacción observada,
	//						que va a mostrarse.
	if (GetDoc()->m_cInteraccObservadaList.GetCount() > 0)
	{
		if (iIndiceElegido != 0)
		{
			m_strEtiqueta1 = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveEtiqueta1();
			m_strEtiqueta2 =
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveEtiqueta2();
			m_dValorObservado =
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveValor();
			m_bUsoTzz = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveUsoTzz();
			m_bUsoTxxMinusTyy = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveUsoTxxMinusTyy();
			m_bUsoTyz = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveUsoTyz();
			m_bUsoTzx = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveUsoTzx();
			m_bUsoTxy = 
				GetDoc()->DevuelveInteraccObservadaPtr(iIndiceElegido - 1)->DevuelveUsoTxy();

			pSheet->EstableceIndiceElegido(iIndiceElegido - 1);
		}
		else
		{
			m_strEtiqueta1 = GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveEtiqueta1();
			m_strEtiqueta2 = GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveEtiqueta2();
			m_dValorObservado = 
				GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveValor();
			m_bUsoTzz = GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveUsoTzz();
			m_bUsoTxxMinusTyy =
				GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveUsoTxxMinusTyy();
			m_bUsoTyz = GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveUsoTyz();
			m_bUsoTzx = GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveUsoTzx();
			m_bUsoTxy = GetDoc()->DevuelveInteraccObservadaPtr(0)->DevuelveUsoTxy();

			pSheet->EstableceIndiceElegido(0);
		}
	}
	else
	{
		m_strEtiqueta1 = _T(" ");
		m_strEtiqueta2 = _T(" ");
		m_dValorObservado = 0.0;
		m_bUsoTzz = FALSE;
		m_bUsoTxxMinusTyy = FALSE;
		m_bUsoTyz = FALSE;
		m_bUsoTzx = FALSE;
		m_bUsoTxy = FALSE;

		pSheet->EstableceIndiceElegido(-1);
	}
	// Fin.

  	UpdateData(FALSE);
	EnableButton(IDGUARDAR, FALSE);

	if (GetDoc()->m_cInteraccObservadaList.GetCount() > 0)
	{
		EnableButton(IDNUEVO, TRUE);
		EnableButton(IDELIMINAR, TRUE);
	}
	else
	{
		EnableButton(IDNUEVO, FALSE);
		EnableButton(IDELIMINAR, FALSE);
	}

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageOne functions

void CInteraccObservadaPageOne::EnableButton(UINT uIdentif, BOOL bLogico)
{
	CButton *pButton = (CButton*) GetDlgItem(uIdentif);
	pButton->EnableWindow(bLogico);
}

int CInteraccObservadaPageOne::DevuelveUbicacionListaEtiquetas(CString cEtiqueta1,
																					CString cEtiqueta2)
{
	int iUbicacionEtiquetas = -1;

	for (int iIndex = 0; iIndex < GetDoc()->m_cInteraccObservadaList.GetCount(); iIndex++)
	{
		CInteraccObservada *pInteraccObs = GetDoc()->DevuelveInteraccObservadaPtr(iIndex);

		if (pInteraccObs != NULL)
		{
			if ( ( DevuelveEtiquetas(cEtiqueta1, cEtiqueta2) ==
				pInteraccObs->DevuelveEtiquetas() ) ||
				( DevuelveEtiquetasInvertidas(cEtiqueta1, cEtiqueta2) == 
				pInteraccObs->DevuelveEtiquetas() ) )
			{
				iUbicacionEtiquetas = iIndex;
				break;
			}
		}
	}

	return iUbicacionEtiquetas;
}

void CInteraccObservadaPageOne::ModificaInteraccComponentList(CString cAnteriorEtiqueta1,
																				  CString cAnteriorEtiqueta2,
																				  CString cEtiqueta1,
																				  CString cEtiqueta2)
{
	for (int iIndex = 0; iIndex < GetDoc()->m_cInteraccComponentList.GetCount(); iIndex++)
	{
		CInteraccComponent *pInteraccComponent = 
			GetDoc()->DevuelveInteraccComponentPtr(iIndex);

		if (pInteraccComponent != NULL)
		{
			if ( DevuelveEtiquetas(cAnteriorEtiqueta1, cAnteriorEtiqueta2) ==
				pInteraccComponent->DevuelveEtiquetasBase() )
			{
				pInteraccComponent->EstableceEtiquetaBase1(cEtiqueta1);
				pInteraccComponent->EstableceEtiquetaBase2(cEtiqueta2);

				if (DevuelveEtiquetas(cAnteriorEtiqueta1, cAnteriorEtiqueta2) ==
					pInteraccComponent->DevuelveEtiquetas() )
				{
					pInteraccComponent->EstableceEtiqueta1(cEtiqueta1);
					pInteraccComponent->EstableceEtiqueta2(cEtiqueta2);
				}
			}
		}
	}
}

BOOL CInteraccObservadaPageOne::InicializaComboBoxes()
{
	if ( !DevuelveTotalPolos() )
		return FALSE;

	CComboBox *pCombo1 = (CComboBox*) GetDlgItem(IDC_ETQTPOLO1);
	CComboBox *pCombo2 = (CComboBox*) GetDlgItem(IDC_ETQTPOLO2);

	// Inicializa los combo boxes
	for (int iPaso = 0; iPaso < GetDoc()->m_cParteRigidaList.GetCount(); iPaso++)
	{
		CParteRigida *pParteRigida = GetDoc()->DevuelveParteRigidaPtr(iPaso);

		if (pParteRigida != NULL)
		{
			for (int iPaso2 = 0; iPaso2 < 6; //pParteRigida->DevuelveTot()
				iPaso2++)
			{
				if ( !pParteRigida->DevuelveSpin(iPaso2).DevuelveEtiqueta().IsEmpty() )
				{
					pCombo1->AddString( pParteRigida->DevuelveSpin(iPaso2).DevuelveEtiqueta() );
					pCombo2->AddString( pParteRigida->DevuelveSpin(iPaso2).DevuelveEtiqueta() );
				}
			}
		}
	}

	return TRUE;
}

int CInteraccObservadaPageOne::DevuelveTotalPolos()
{
	int iIndex = 0;
	int iPolosTot = 0;
	POSITION posAux = NULL;

	posAux = GetDoc()->m_cParteRigidaList.FindIndex(iIndex);

	while (posAux != NULL)
	{
		CParteRigida *pParteAux = NULL;
		pParteAux = GetDoc()->m_cParteRigidaList.GetAt(posAux);
		iPolosTot += pParteAux->DevuelveTotSpines(); 
		iIndex++;
		posAux = GetDoc()->m_cParteRigidaList.FindIndex(iIndex);
	}

	return iPolosTot;
}
