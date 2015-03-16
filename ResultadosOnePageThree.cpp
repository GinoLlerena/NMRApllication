// ResultadosOnePageThree.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "ResultadosOnePageThree.h"
#include "MainFrm.h"
#include "ProyectoView.h"
#include "ResultadosOneSheet.h"
#include "Fichero.h"
#include "Tensor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageThree property page

IMPLEMENT_DYNCREATE(CResultadosOnePageThree, CPropertyPage)

CResultadosOnePageThree::CResultadosOnePageThree() : 
	CPropertyPage(CResultadosOnePageThree::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Lista de Tensores");
	m_cImageListPtr = new CImageList;

	m_iCantIconos = 20;
	m_iPaginaActual = 1;

	//{{AFX_DATA_INIT(CResultadosOnePageThree)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CResultadosOnePageThree::~CResultadosOnePageThree()
{
	delete m_cImageListPtr;
}

void CResultadosOnePageThree::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultadosOnePageThree)
	DDX_Control(pDX, IDC_LIST, m_cReportList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultadosOnePageThree, CPropertyPage)
	//{{AFX_MSG_MAP(CResultadosOnePageThree)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST, OnKeydownList)
	ON_BN_CLICKED(IDC_ANTERIORES, OnAnteriores)
	ON_BN_CLICKED(IDC_SIGUIENTES, OnSiguientes)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageThree message handlers

BOOL CResultadosOnePageThree::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	// Leer la cantidad de datos grabados
	CFichero cFichero;
	if (!cFichero.Abre(GetDoc()->DevuelveStrCalculosFichero(), CFile::modeRead))
		return FALSE;

	int iDatosGrabados;
	cFichero.Seek((sizeof(CFileStatus) * 3) + (sizeof(int) * 2), CFile::begin);
	cFichero.Read((char*) &iDatosGrabados, sizeof(int));
	cFichero.Close();
	// Fin.

	// Establecimiento de Rango de páginas
	m_iPaginaActual = 1;
	m_iPaginaFinal = (iDatosGrabados / m_iCantIconos) + 1;
	m_iElementosEnPagFinal = (iDatosGrabados % m_iCantIconos);

	if (!m_cImageListPtr->Create(16, 16, TRUE, 1, 1)) // 16, 16 para small icons
	{
		TRACE0("Failed to create ImageList\n");
		return FALSE;
	}

	m_cImageListPtr->Add(AfxGetApp()->LoadIcon(IDI_TENSOR));

	CRect rect;
	LV_COLUMN lvcolumn;
	TCHAR encabezado[8][25] = { _T("Indice"), _T("Tzz"), _T("Txx - Tyy"), _T("Tyz"),
		_T("Tzx"), _T("Txy"), _T("Error Acumulado"), _T("MAD") };
	m_cReportList.GetWindowRect(&rect);

	for (int i = 0; i < 8; i++)  // add the columns to the list control
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = encabezado[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = rect.Width() / 4;  // SubItem is twice as large
		m_cReportList.InsertColumn(i, &lvcolumn);  // assumes return value is OK.
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CResultadosOnePageThree::OnSetActive() 
{
	if( !EstablecerDatos())
		return FALSE;
	return CPropertyPage::OnSetActive();
}

void CResultadosOnePageThree::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	for (int iIndex = 0; iIndex < m_iCantIconos; iIndex++)
	{
		UINT uState;
		uState = m_cReportList.GetItemState(iIndex, LVIS_SELECTED);
		
		if (uState == LVIS_SELECTED)
		{
			CResultadosOneSheet *pSheet = STATIC_DOWNCAST(CResultadosOneSheet, GetParent());
			int iIndiceElegido = ((m_iPaginaActual - 1) * (m_iCantIconos) + (iIndex + 1));
			pSheet->EstableceIndiceElegido(iIndiceElegido);		// Debido a que iIndex 
																				//	está en base 0.
			break;
		}
	}

	*pResult = 0;
}


void CResultadosOnePageThree::OnKeydownList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	CButton *pButtonA = (CButton*) GetDlgItem(IDC_ANTERIORES);
	CButton *pButtonS = (CButton*) GetDlgItem(IDC_SIGUIENTES);
	

	switch (pLVKeyDow->wVKey)
	{
		case VK_NEXT:			// Page Down Key
			if (m_iPaginaActual < m_iPaginaFinal) {
				m_iPaginaActual += 1;
				pButtonA->EnableWindow(TRUE);
			}
			if (m_iPaginaActual == m_iPaginaFinal) 
				pButtonS->EnableWindow(FALSE);

			break;

		case VK_PRIOR:			// Page Up Key
			if (m_iPaginaActual != 1) {
				pButtonS->EnableWindow(TRUE);
				m_iPaginaActual -= 1; 
			}
			if(m_iPaginaActual == 1)
				pButtonA->EnableWindow(FALSE);
			

			break;
	}
	EstablecerDatos();
	*pResult = 0;
}

void CResultadosOnePageThree::OnAnteriores() 
{
	CButton *pButtonA = (CButton*) GetDlgItem(IDC_ANTERIORES);
	CButton *pButtonS = (CButton*) GetDlgItem(IDC_SIGUIENTES);
	if (m_iPaginaActual != 1) {
		pButtonS->EnableWindow(TRUE);
		m_iPaginaActual -= 1;
	}
	if(m_iPaginaActual == 1)
		pButtonA->EnableWindow(FALSE);
	EstablecerDatos();
}

void CResultadosOnePageThree::OnSiguientes() 
{
	CButton *pButtonA = (CButton*) GetDlgItem(IDC_ANTERIORES);
	CButton *pButtonS = (CButton*) GetDlgItem(IDC_SIGUIENTES);
	
	if (m_iPaginaActual < m_iPaginaFinal) {
		m_iPaginaActual += 1;
		pButtonA->EnableWindow(TRUE);
	}
	if (m_iPaginaActual == m_iPaginaFinal)
		pButtonS->EnableWindow(FALSE);
	EstablecerDatos();
}

BOOL CResultadosOnePageThree::EstablecerDatos()
{
	UpdateData(TRUE);
	m_cReportList.DeleteAllItems();	
	m_cReportList.SetImageList(m_cImageListPtr, LVSIL_SMALL);

	LV_ITEM lvitem;
	int iActualItem = 0;
	int iPorAhora = 0;

	if (m_iPaginaActual == m_iPaginaFinal)
		m_iCantIconos = m_iElementosEnPagFinal;
	else
		m_iCantIconos = 20;

	CFichero cFichero;
	if (!cFichero.Abre(GetDoc()->DevuelveStrTensoresFichero(), CFile::modeRead))
		return FALSE;

	for (int iItem = 0; iItem < m_iCantIconos; iItem++)	// will now insert the items and
																			//	subitems into the list view.
	{
		for (int iSubItem = 0; iSubItem < 8; iSubItem++)
		{
			CString str = _T("");

			if (iSubItem == 0)	// Para el Indice
				str.Format("%d", ((m_iPaginaActual - 1) * m_iCantIconos) + (iItem + 1));

			if (iSubItem > 0)		// Para los Tensores y Estadisticas
			{
				StcValorDual stcValorDual;
				cFichero.Lee((char*) &stcValorDual, ((m_iPaginaActual - 1) * m_iCantIconos) + 
					iPorAhora + iSubItem, sizeof(StcValorDual));

				CTensor *pTensor = new CTensor;
				pTensor->EstableceConStruct(&stcValorDual);

				str.Format("%f", pTensor->DevuelveValor());
				delete pTensor;
				pTensor = NULL;
			}

			TCHAR palabra[25] = { _T("") };
			lvitem.mask = LVIF_TEXT | (iSubItem == 0 ? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0) ? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			
			_tcscpy(palabra, str);
			lvitem.pszText = palabra;
			lvitem.iImage = 0;

			if (iSubItem == 0)
				iActualItem = m_cReportList.InsertItem(&lvitem);
			else
				m_cReportList.SetItem(&lvitem);
		}	

		iPorAhora += 7;
	}

	cFichero.Close();

	return TRUE;
}
