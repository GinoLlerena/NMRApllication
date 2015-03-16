// InteraccComponentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "InteraccComponentDlg.h"
#include "Mainfrm.h"
#include "ProyectoView.h"
#include "InteraccComponent.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInteraccComponentDlg dialog

CInteraccComponentDlg::CInteraccComponentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInteraccComponentDlg::IDD, pParent)
{
	m_strPoloBase1 = _T("");
	m_strPoloBase2 = _T("");
	m_bIsNuevo = FALSE;

	//{{AFX_DATA_INIT(CInteraccComponentDlg)
	m_strPolo1 = _T("");
	m_strPolo2 = _T("");
	m_strInteraccBase = _T("");
	//}}AFX_DATA_INIT
}

void CInteraccComponentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInteraccComponentDlg)
	DDX_Control(pDX, IDC_LIST, m_lbReport);
	DDX_CBString(pDX, IDC_ETQTPOLO1, m_strPolo1);
	DDX_CBString(pDX, IDC_ETQTPOLO2, m_strPolo2);
	DDX_CBString(pDX, IDC_INTRCBASE, m_strInteraccBase);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CInteraccComponentDlg, CDialog)
	//{{AFX_MSG_MAP(CInteraccComponentDlg)
	ON_BN_CLICKED(IDNUEVO, OnNuevo)
	ON_BN_CLICKED(IDGUARDAR, OnGuardar)
	ON_BN_CLICKED(IDELIMINAR, OnEliminar)
	ON_CBN_SELENDOK(IDC_INTRCBASE, OnSelendokIntrcbase)
	ON_CBN_SELENDOK(IDC_ETQTPOLO1, OnSelendokEtqtpolo1)
	ON_CBN_SELENDOK(IDC_ETQTPOLO2, OnSelendokEtqtpolo2)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelchangeList)
	ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInteraccComponentDlg message handlers

BOOL CInteraccComponentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (!InitPolos())
		return FALSE;

	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, FALSE);
	return TRUE;
}

void CInteraccComponentDlg::OnMove(int x, int y) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CDialog::OnMove(x, y);
}


void CInteraccComponentDlg::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CDialog::PostNcDestroy();
}

void CInteraccComponentDlg::OnNuevo() 
{
	CString cStr = _T("");
	GetComboText(IDC_INTRCBASE, cStr);

	if (cStr.IsEmpty())
	{
		MessageBox(MSG9, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	m_bIsNuevo = TRUE;
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, FALSE);
	SetComboText(IDC_ETQTPOLO1, _T(""));
	SetComboText(IDC_ETQTPOLO2, _T(""));
	CListBox *pListBox = (CListBox*) GetDlgItem(IDC_LIST);
	pListBox->SetCurSel(-1);

	GetDoc()->SetModifiedFlag(TRUE);
	GetDoc()->UpdateAllViews(NULL);
}

void CInteraccComponentDlg::OnGuardar() 
{
	CString cStr = _T("");
	GetComboText(IDC_INTRCBASE, cStr);

	if (cStr.IsEmpty())
	{
		MessageBox(MSG9, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	CString strText1 = _T("");
	CString strText2 = _T("");
	CString strValor = _T("");

	GetComboText(IDC_ETQTPOLO1, strText1);
	GetComboText(IDC_ETQTPOLO2, strText2);

	if ((strText1 == strText2) || strText1.IsEmpty() || strText2.IsEmpty())
	{
		MessageBox(MSG10, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	CListBox *pListBox = (CListBox*) GetDlgItem(IDC_LIST);

	// Procedimiento: Insertar por primera vez
	if (pListBox->GetCurSel() == LB_ERR)
	{
		// Procedimiento: Comprueba si existe esa interacc. dipolar
		for (int pass = 0; pass < GetDoc()->m_cInteraccComponentList.GetCount(); pass++)
		{
			POSITION Posicion = NULL;
			Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(pass);

			if (Posicion != NULL)
			{
				CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);

				if ((m_strPoloBase1 == pIntrc->DevuelveEtiquetaBase1() && m_strPoloBase2 == 
					pIntrc->DevuelveEtiquetaBase2()) &&
					(strText1 == pIntrc->DevuelveEtiqueta1() && strText2 == 
					pIntrc->DevuelveEtiqueta2()) ||
					(strText2 == pIntrc->DevuelveEtiqueta1() && strText1 == 
					pIntrc->DevuelveEtiqueta2()))
				{
					Posicion = NULL;
					MessageBox(MSG11, "Advertencia", MB_ICONEXCLAMATION);
					return;
				}

				Posicion = NULL;
			}
		}
		// Fin Procedimiento

		pListBox->AddString(strText1 + ", " + strText2);
		pListBox->SetCurSel(pListBox->GetCount() - 1);

		// Para la InteraccComponentList
		CInteraccComponent *pIntrcComponent = new CInteraccComponent;
		pIntrcComponent->EstableceEtiquetaBase1(m_strPoloBase1);
		pIntrcComponent->EstableceEtiquetaBase2(m_strPoloBase2);
		pIntrcComponent->EstableceEtiqueta1(strText1);
		pIntrcComponent->EstableceEtiqueta2(strText2);
		GetDoc()->m_cInteraccComponentList.AddTail(pIntrcComponent);
		// Fin
	}
	else
	{	// Procedimiento: Modificar una interacc. dipolar existente
		int iSelectedIndex = pListBox->GetCurSel();
		CString cStr = _T("");
		pListBox->GetText(iSelectedIndex, cStr);

		if (cStr == (m_strPoloBase1 + ", " + m_strPoloBase2))
		{
			MessageBox(MSG12, "Advertencia", MB_ICONEXCLAMATION);
			return;
		}

		// Procedimiento: Comprueba si existe esa interacc. dipolar
		for (int pass = 0; pass < GetDoc()->m_cInteraccComponentList.GetCount(); pass++)
		{
			if (pass != iSelectedIndex)
			{
				POSITION Posicion = NULL;
				Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(pass);

				if (Posicion != NULL)
				{
					CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);

					if ((m_strPoloBase1 == pIntrc->DevuelveEtiquetaBase1() && m_strPoloBase2 == 
						pIntrc->DevuelveEtiquetaBase2()) &&
						(strText1 == pIntrc->DevuelveEtiqueta1() && strText2 == 
						pIntrc->DevuelveEtiqueta2()) ||
						(strText2 == pIntrc->DevuelveEtiqueta1() && strText1 ==
						pIntrc->DevuelveEtiqueta2()))
					{
						Posicion = NULL;
						MessageBox(MSG11, "Advertencia", MB_ICONEXCLAMATION);
						return;
					}

					Posicion = NULL;
				}
			}
		}
		// Fin Procedimiento

		// Ingresa la modificada interaccion 
		for (int pass = 0; pass < GetDoc()->m_cInteraccComponentList.GetCount(); pass++)
		{
			POSITION Posicion = NULL;
			Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(pass);

			if (Posicion != NULL)
			{
				CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);
				
				if ((m_strPoloBase1 == pIntrc->DevuelveEtiquetaBase1() && m_strPoloBase2 == 
					pIntrc->DevuelveEtiquetaBase2()) &&
					(cStr == (pIntrc->DevuelveEtiqueta1() + ", " + pIntrc->DevuelveEtiqueta2())))
				{
					pIntrc->EstableceEtiquetaBase1(m_strPoloBase1);
					pIntrc->EstableceEtiquetaBase2(m_strPoloBase2);
					pIntrc->EstableceEtiqueta1(strText1);
					pIntrc->EstableceEtiqueta2(strText2);
					break;
				}
			}
		}

		pListBox->DeleteString(iSelectedIndex);
		pListBox->InsertString(iSelectedIndex, strText1 + ", " + strText2);
		pListBox->SetCurSel(iSelectedIndex);
	}

	pListBox->SetFocus();

	if (m_bIsNuevo)
		m_bIsNuevo = FALSE;

	EnableButton(IDNUEVO, TRUE);
	EnableButton(IDGUARDAR, FALSE);
	EnableButton(IDELIMINAR, TRUE);
	return;	
}

void CInteraccComponentDlg::OnEliminar() 
{
	CListBox *pListBox = (CListBox*) GetDlgItem(IDC_LIST);
	int iSelectedItem = pListBox->GetCurSel();
	CString cLbText;
	pListBox->GetText(iSelectedItem, cLbText);

	if (iSelectedItem == LB_ERR)
	{
		MessageBox(MSG13, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	CString strText1 = _T("");
	CString strText2 = _T("");
	CString strText3 = _T("");
	
	GetComboText(IDC_ETQTPOLO1, strText1);
	GetComboText(IDC_ETQTPOLO2, strText2);
	GetComboText(IDC_INTRCBASE, strText3);

	if (strText3 == (strText1 + ", " + strText2))
	{
		MessageBox(MSG14, "Advertencia", MB_ICONEXCLAMATION);
		return;
	}

	// Procedimiento: Comprueba si existe esa interacc. dipolar
	for (int paso = 0; paso < GetDoc()->m_cInteraccComponentList.GetCount(); paso++)
	{
		POSITION Posicion = NULL;
		Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(paso);

		if (Posicion != NULL)
		{
			CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);

			if (m_strPoloBase1 == pIntrc->DevuelveEtiquetaBase1() && m_strPoloBase2 == 
				pIntrc->DevuelveEtiquetaBase2() && strText1 == pIntrc->DevuelveEtiqueta1() && 
				strText2 == pIntrc->DevuelveEtiqueta2())
			{
				delete pIntrc;
				GetDoc()->m_cInteraccComponentList.RemoveAt(Posicion);

				if (pListBox->DeleteString(iSelectedItem) == LB_ERR)
				{
					TRACE0("Error al borrar la cadena en ReportLB");
					return;
				}
				break;
			}

			if (paso == GetDoc()->m_cInteraccComponentList.GetCount() - 1)
			{
				MessageBox(MSG15, "Advertencia", MB_ICONEXCLAMATION);
				return;
			}
		}
	}
	// Fin Procedimiento

	if (pListBox->GetCount() != 0 && pListBox->GetCount() != iSelectedItem)
	{
		for (int paso = 0; paso < GetDoc()->m_cInteraccComponentList.GetCount(); paso++)
		{
			POSITION Posicion = NULL;
			Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(paso);

			if (Posicion != NULL)
			{
				CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);

				if (m_strPoloBase1 == pIntrc->DevuelveEtiquetaBase1() && m_strPoloBase2 ==
					pIntrc->DevuelveEtiquetaBase2())
				{
					SetComboText(IDC_ETQTPOLO1, pIntrc->DevuelveEtiqueta1());
					SetComboText(IDC_ETQTPOLO2, pIntrc->DevuelveEtiqueta2());
					
					pListBox->SetCurSel(0);
					EnableButton(IDELIMINAR, TRUE);
				}
			}
		}
	}
	else
	{
		SetComboText(IDC_ETQTPOLO1, _T(""));
		SetComboText(IDC_ETQTPOLO2, _T(""));
		EnableButton(IDNUEVO, FALSE);
		EnableButton(IDELIMINAR, FALSE);
	}

	EnableButton(IDNUEVO, TRUE);
	EnableButton(IDGUARDAR, FALSE);
	pListBox->SetFocus();
	return;
}

void CInteraccComponentDlg::OnSelendokIntrcbase() 
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_INTRCBASE);
	int iSelected = pCombo->GetCurSel();

	POSITION Posicion = NULL;
	Posicion = GetDoc()->m_cInteraccObservadaList.FindIndex(iSelected);
	
	if (Posicion != NULL)
	{
		CInteraccObservada *pIntrcObs = GetDoc()->m_cInteraccObservadaList.GetAt(Posicion);
		m_strPoloBase1 = pIntrcObs->DevuelveEtiqueta1();
		m_strPoloBase2 = pIntrcObs->DevuelveEtiqueta2();
		Posicion = NULL;
	}

	CListBox *pListBox = (CListBox*) GetDlgItem(IDC_LIST);
	pListBox->ResetContent();

	for (int paso = 0; paso < GetDoc()->m_cInteraccComponentList.GetCount(); paso++)
	{
		Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(paso);

		if (Posicion != NULL)
		{
			CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);
			Posicion = NULL;

			if (m_strPoloBase1 == pIntrc->DevuelveEtiquetaBase1() && 
				m_strPoloBase2 == pIntrc->DevuelveEtiquetaBase2())
			{
				pListBox->AddString(pIntrc->DevuelveEtiqueta1() + ", " + 
					pIntrc->DevuelveEtiqueta2());
			}
		}
	}

	SetComboText(IDC_ETQTPOLO1, _T(""));
	SetComboText(IDC_ETQTPOLO2, _T(""));
	pListBox->SetCurSel(-1);
	EnableButton(IDNUEVO, FALSE);
	EnableButton(IDELIMINAR, FALSE);

}

void CInteraccComponentDlg::OnSelendokEtqtpolo1() 
{
	EnableButton(IDGUARDAR, TRUE);	
}

void CInteraccComponentDlg::OnSelendokEtqtpolo2() 
{
	EnableButton(IDGUARDAR, TRUE);	
}

void CInteraccComponentDlg::OnSelchangeList() 
{
	CListBox *pListBox = (CListBox*) GetDlgItem(IDC_LIST);
	CString cStr = _T("");
	pListBox->GetText(pListBox->GetCurSel(), cStr);

	for (int paso = 0; paso < GetDoc()->m_cInteraccComponentList.GetCount(); paso++)
	{
		POSITION Posicion = NULL;
		Posicion = GetDoc()->m_cInteraccComponentList.FindIndex(paso);

		if (Posicion != NULL)
		{
			CInteraccComponent *pIntrc = GetDoc()->m_cInteraccComponentList.GetAt(Posicion);

			if (pIntrc->DevuelveEtiquetas() == cStr)
			{
				SetComboText(IDC_ETQTPOLO1, pIntrc->DevuelveEtiqueta1());
				SetComboText(IDC_ETQTPOLO2, pIntrc->DevuelveEtiqueta2());
			}

			Posicion = NULL;
		}	
	}

	EnableButton(IDNUEVO, TRUE);
	EnableButton(IDGUARDAR, TRUE);
	EnableButton(IDELIMINAR, TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// Our CInteraccComponentDlg functions

CProyectoDoc* CInteraccComponentDlg::GetDoc(void)
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());

	return pDoc;
}

int CInteraccComponentDlg::GetTotalPolos(void)
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

BOOL CInteraccComponentDlg::InitPolos(void)
{
	for (int pass = 0; pass < GetDoc()->m_cInteraccObservadaList.GetCount(); pass++)
	{
		POSITION Posicion = NULL;
		Posicion = GetDoc()->m_cInteraccObservadaList.FindIndex(pass);

		if (Posicion != NULL)
		{
			CInteraccObservada *pIntrcObs = GetDoc()->m_cInteraccObservadaList.GetAt(Posicion);

			CString cStr = _T("");
			cStr = pIntrcObs->DevuelveEtiqueta1() + ", " + pIntrcObs->DevuelveEtiqueta2();
			
			CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_INTRCBASE);
			pCombo->AddString(cStr);
		}
	}

	if (!GetTotalPolos())
		return FALSE;

	CListBox *pListBox = (CListBox*) GetDlgItem(IDC_LIST);
	pListBox->ResetContent();

	for (int pass = 1; pass <= GetTotalPolos(); pass++)
	{
		CString cStr = _T("");
		cStr.Format("%d", pass);
		CComboBox *pCombo1 = (CComboBox*) GetDlgItem(IDC_ETQTPOLO1);
		pCombo1->AddString(cStr);
		CComboBox *pCombo2 = (CComboBox*) GetDlgItem(IDC_ETQTPOLO2);
		pCombo2->AddString(cStr);
	}

	return TRUE;
}

void CInteraccComponentDlg::EnableButton(UINT uIdentif, BOOL bBandera)
{
	CButton *pButton = (CButton*) GetDlgItem(uIdentif);
	pButton->EnableWindow(bBandera);
}

void CInteraccComponentDlg::SetComboText(UINT uIdentif, CString cStr)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->SetWindowText(cStr);
}

void CInteraccComponentDlg::GetComboText(UINT uIdentif, CString &cStr)
{
	CComboBox *pCombo = (CComboBox*) GetDlgItem(uIdentif);
	pCombo->GetWindowText(cStr);
}
