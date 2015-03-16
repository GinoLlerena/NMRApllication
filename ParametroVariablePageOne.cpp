// ParametroVariablePageOne.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "MainFrm.h"
#include "ProyectoView.h"
#include "ParametroVariablePageOne.h"
#include "ParametroVariableSheet.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParametroVariablePageOne property page

IMPLEMENT_DYNCREATE(CParametroVariablePageOne, CPropertyPage)

CParametroVariablePageOne::CParametroVariablePageOne() : 
	CPropertyPage(CParametroVariablePageOne::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Parámetro variable");

	//{{AFX_DATA_INIT(CParametroVariablePageOne)
	m_strEtiqueta = _T("");
	m_dValorInicial = 0.0;
	m_dValorFinal = 0.0;
	m_dIncremento = 0.0;	
	//}}AFX_DATA_INIT
}

CParametroVariablePageOne::~CParametroVariablePageOne()
{
}

void CParametroVariablePageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParametroVariablePageOne)
	DDX_Text(pDX, IDC_ETQT, m_strEtiqueta);
	DDX_Text(pDX, IDC_INICIO, m_dValorInicial);
	DDX_Text(pDX, IDC_FIN, m_dValorFinal);
	DDX_Text(pDX, IDC_INCREMENTO, m_dIncremento);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParametroVariablePageOne, CPropertyPage)
	//{{AFX_MSG_MAP(CParametroVariablePageOne)
	ON_EN_CHANGE(IDC_ETQT, OnChangeEtqt)
	ON_EN_CHANGE(IDC_INICIO, OnChangeInicio)
	ON_EN_CHANGE(IDC_FIN, OnChangeFin)
	ON_EN_CHANGE(IDC_INCREMENTO, OnChangeIncremento)
	ON_BN_CLICKED(IDNUEVO, OnNuevo)
	ON_BN_CLICKED(IDGUARDAR, OnGuardar)
	ON_BN_CLICKED(IDELIMINAR, OnEliminar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParametroVariablePageOne message handlers

BOOL CParametroVariablePageOne::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CParametroVariablePageOne::OnSetActive() 
{
	CParametroVariableSheet *pSheet = STATIC_DOWNCAST(CParametroVariableSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();
	
	if (iIndiceElegido >= 0)
	{
		if (GetDoc()->DevuelveParamVariabPtr(iIndiceElegido) != NULL)
		{
			m_strEtiqueta = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido)->DevuelveEtiqueta();
			m_dValorInicial = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido)->DevuelveValorInicial();
			m_dValorFinal = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido)->DevuelveValorFinal();
			m_dIncremento = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido)->DevuelveIncremento();
		}
	}

	UpdateData(FALSE);

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

void CParametroVariablePageOne::OnChangeEtqt() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CParametroVariablePageOne::OnChangeInicio() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CParametroVariablePageOne::OnChangeFin() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CParametroVariablePageOne::OnChangeIncremento() 
{
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, FALSE);
}

void CParametroVariablePageOne::OnNuevo() 
{
	CParametroVariableSheet *pSheet = STATIC_DOWNCAST( CParametroVariableSheet, GetParent() );
	pSheet->EstableceIndiceElegido(-1);

	m_strEtiqueta = _T("");
	m_dValorInicial = 0.0;
	m_dValorFinal = 0.0;
	m_dIncremento = 0.0;	
	UpdateData(FALSE);		// Inicializa los controles

	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, FALSE);

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

void CParametroVariablePageOne::OnGuardar() 
{
	UpdateData(TRUE);

	if ( m_strEtiqueta == _T("") )
	{
		MessageBox(MSG16, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	CParametroVariableSheet *pSheet = STATIC_DOWNCAST(CParametroVariableSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	// Procedimiento: Modifica un parámetro variable.
	if (iIndiceElegido >= 0)
	{
		CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndiceElegido);

		if (pParamVariab != NULL)
		{
			int iIndice = -1;

			iIndice = DevuelveUbicacionListaEtiqueta(m_strEtiqueta);

			if ( (iIndice == -1) ||					// Etiqueta no existe en la lista.
				(iIndice == iIndiceElegido) )		// Etiqueta existe en la misma 
															//	ubicación iIndiceElegido dentro de la lista.
			{
				pParamVariab->EstableceEtiqueta(m_strEtiqueta);
				pParamVariab->EstableceValorInicial(m_dValorInicial);
				pParamVariab->EstableceValorFinal(m_dValorFinal);
				pParamVariab->EstableceIncremento(m_dIncremento);
			}
			else
			{
				MessageBox(MSG23, "Advertencia", MB_ICONEXCLAMATION);
				return;
			}
		}
	}

	// Procedimiento: Adiciona nuevo parámetro variable.
	if (iIndiceElegido == -1)
	{
		int iIndice = -1;

		iIndice = DevuelveUbicacionListaEtiqueta(m_strEtiqueta);

		if ( (iIndice == iIndiceElegido) )		// Etiquetas no existen en la lista.
		{
			//	Adiciona nueva parámetro variable
			CParametroVariable *pParamVariab = new CParametroVariable;
			pParamVariab->EstableceEtiqueta(m_strEtiqueta);
			pParamVariab->EstableceValorInicial(m_dValorInicial);
			pParamVariab->EstableceValorFinal(m_dValorFinal);
			pParamVariab->EstableceIncremento(m_dIncremento);
			GetDoc()->m_cParametroVariableList.AddTail(pParamVariab);

			CParametroVariableSheet *pSheet = 
				STATIC_DOWNCAST( CParametroVariableSheet, GetParent() );
			int iTotalElementos = GetDoc()->m_cParametroVariableList.GetCount();
			pSheet->EstableceIndiceElegido(iTotalElementos - 1);
		}
		else
		{
			MessageBox(MSG23, "Advertencia", MB_ICONEXCLAMATION);
			return;
		}
	}

	EnableButton(IDNUEVO, TRUE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, TRUE);
	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

void CParametroVariablePageOne::OnEliminar() 
{
	CParametroVariableSheet *pSheet = STATIC_DOWNCAST( CParametroVariableSheet, GetParent() );
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	// Procedimiento: Elimina parámetro variable.
	POSITION Posicion = NULL;
	Posicion = GetDoc()->m_cParametroVariableList.FindIndex(iIndiceElegido);

	if (Posicion != NULL)
	{
		CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndiceElegido);

		if (pParamVariab != NULL)
		{
			delete pParamVariab;
			GetDoc()->m_cParametroVariableList.RemoveAt(Posicion);
		}
	}
	// Fin.

	// Procedimiento: Obtiene valores de un parámetro variable,
	//						que va a mostrarse.
	if (GetDoc()->m_cParametroVariableList.GetCount() > 0)
	{
		if (iIndiceElegido != 0)
		{
			m_strEtiqueta = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido - 1)->DevuelveEtiqueta();
			m_dValorInicial = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido - 1)->DevuelveValorInicial();
			m_dValorFinal = 
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido - 1)->DevuelveValorFinal();
			m_dIncremento =
				GetDoc()->DevuelveParamVariabPtr(iIndiceElegido - 1)->DevuelveIncremento();

			pSheet->EstableceIndiceElegido(iIndiceElegido - 1);
		}
		else
		{
			m_strEtiqueta = GetDoc()->DevuelveParamVariabPtr(0)->DevuelveEtiqueta();
			m_dValorInicial = GetDoc()->DevuelveParamVariabPtr(0)->DevuelveValorInicial();
			m_dValorFinal = GetDoc()->DevuelveParamVariabPtr(0)->DevuelveValorFinal();
			m_dIncremento = GetDoc()->DevuelveParamVariabPtr(0)->DevuelveIncremento();

			pSheet->EstableceIndiceElegido(0);
		}
	}
	else
	{
		m_strEtiqueta = _T("");
		m_dValorInicial = 0.0;
		m_dValorFinal = 0.0;
		m_dIncremento = 0.0;

		pSheet->EstableceIndiceElegido(-1);
	}
	// Fin.

  	UpdateData(FALSE);
	EnableButton(IDGUARDAR, FALSE);

	if (GetDoc()->m_cParametroVariableList.GetCount() > 0)
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
// CParametroVariablePageOne functions

CProyectoDoc* CParametroVariablePageOne::GetDoc(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());
	return pDoc;
}

void CParametroVariablePageOne::EnableButton(UINT uIdentif, BOOL bLogico)
{
	CButton *pButton = (CButton*) GetDlgItem(uIdentif);
	pButton->EnableWindow(bLogico);
}

int CParametroVariablePageOne::DevuelveUbicacionListaEtiqueta(CString cEtiqueta)
{
	int iUbicacionEtiquetas = -1;

	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount(); iIndex++)
	{
		CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndex);

		if (pParamVariab != NULL)
		{
			if (pParamVariab->DevuelveEtiqueta() == cEtiqueta)
			{
				iUbicacionEtiquetas = iIndex;
				break;
			}
		}
	}

	return iUbicacionEtiquetas;
}
