// ResultadosOnePageTwo.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "ResultadosOnePageTwo.h"
#include "ResultadosOneSheet.h"
#include "Fichero.h"
#include "Parametro.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageTwo property page

IMPLEMENT_DYNCREATE(CResultadosOnePageTwo, CPropertyPage)

CResultadosOnePageTwo::CResultadosOnePageTwo() :
	CPropertyPage(CResultadosOnePageTwo::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Parámetros");
	m_cImageListPtr = new CImageList;

	//{{AFX_DATA_INIT(CResultadosOnePageTwo)
	//}}AFX_DATA_INIT
}

CResultadosOnePageTwo::~CResultadosOnePageTwo()
{
	delete m_cImageListPtr;
}

void CResultadosOnePageTwo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultadosOnePageTwo)
	DDX_Control(pDX, IDC_LIST, m_cReportList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultadosOnePageTwo, CPropertyPage)
	//{{AFX_MSG_MAP(CResultadosOnePageTwo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageTwo message handlers

BOOL CResultadosOnePageTwo::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	if (!m_cImageListPtr->Create(16, 16, TRUE, 1, 1)) // 16, 16 para small icons
	{
		TRACE0("Failed to create ImageList\n");
		return FALSE;
	}

	m_cImageListPtr->Add(AfxGetApp()->LoadIcon(IDI_PARAM));

	CRect rect;
	LV_COLUMN lvcolumn;
	TCHAR encabezado[3][25] = {_T("Parámetro"), _T("Valor"), _T("Unidades")};
	m_cReportList.GetWindowRect(&rect);

	for (int i = 0; i < 3; i++)  // add the columns to the list control
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = encabezado[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = rect.Width() / 3;  // SubItem is twice as large
		m_cReportList.InsertColumn(i, &lvcolumn);  // assumes return value is OK.
	}
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CResultadosOnePageTwo::OnSetActive() 
{
	UpdateData(TRUE);
	m_cReportList.DeleteAllItems();
	m_cReportList.SetImageList(m_cImageListPtr, LVSIL_SMALL);

	// Leer la cantidad de registros a ser mostrados
	CFichero cFichero;
	if (!cFichero.Abre(GetDoc()->DevuelveStrCalculosFichero(), CFile::modeRead))
		return FALSE;
	
	int iCantIconos;
	cFichero.Seek((sizeof(CFileStatus) * 3) + sizeof(int), CFile::begin);
	cFichero.Read((char*) &iCantIconos, sizeof(int));
	cFichero.Close();
	//	Fin.

	CResultadosOneSheet *pSheet = STATIC_DOWNCAST(CResultadosOneSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	LV_ITEM lvitem;
	int iActualItem = 0;

	// Leer fichero de Parámetros
	if (!cFichero.Abre(GetDoc()->DevuelveStrParamFichero(), CFile::modeRead))
		return FALSE;

	for (int iItem = 0; iItem < iCantIconos; iItem++)  // will now insert the items and 
																		//	subitems into the list view.
	{
		StcParametro stcParametro;
		cFichero.Lee((char*) &stcParametro, ((iIndiceElegido  - 1) * iCantIconos) +
			(iItem + 1), sizeof(StcParametro));

		CParametro *pParam = new CParametro;
		pParam->EstableceConStruct(&stcParametro);

		for (int iSubItem = 0; iSubItem < 3; iSubItem++)
		{
			TCHAR palabra[25] = { _T("") };
			lvitem.mask = LVIF_TEXT | (iSubItem == 0 ? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0) ? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			CString str = _T("");
						
			switch (iSubItem)
			{
				case 0:
					str = pParam->DevuelveEtiqueta();
					break;
				case 1:
					str.Format("%f", pParam->DevuelveValorActual());
					break;
				case 2:
					//str.Format("%f", pParam->RetornUnidad());
					str = _T("Grados.");
					break;
			}
			
			_tcscpy(palabra, str);
			lvitem.pszText = palabra;
			lvitem.iImage = 0;
			
			if (iSubItem == 0)
				iActualItem = m_cReportList.InsertItem(&lvitem);
			else
				m_cReportList.SetItem(&lvitem);
		}

		delete pParam;
		pParam = NULL;
	}

	cFichero.Close();	
	return CPropertyPage::OnSetActive();
}

/*CProyectoDoc* CResultadosOnePageTwo::GetDoc()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());
	return pDoc;
}*/
