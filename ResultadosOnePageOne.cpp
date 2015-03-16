// ResultadosOnePageOne.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "ResultadosOnePageOne.h"
#include "ResultadosOneSheet.h"
#include "Fichero.h"
#include "Interaccion.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageOne property page

IMPLEMENT_DYNCREATE(CResultadosOnePageOne, CPropertyPage)

CResultadosOnePageOne::CResultadosOnePageOne() :
	CPropertyPage(CResultadosOnePageOne::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Interacciones");
	m_cImageListPtr = new CImageList;

	//{{AFX_DATA_INIT(CResultadosOnePageOne)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CResultadosOnePageOne::~CResultadosOnePageOne()
{
	delete m_cImageListPtr;
}

void CResultadosOnePageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultadosOnePageOne)
	DDX_Control(pDX, IDC_LIST, m_cReportList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultadosOnePageOne, CPropertyPage)
	//{{AFX_MSG_MAP(CResultadosOnePageOne)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageOne message handlers

BOOL CResultadosOnePageOne::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	if (!m_cImageListPtr->Create(16, 16, TRUE, 1, 1)) // 16, 16 para small icons
	{
		TRACE0("Failed to create ImageList\n");
		return FALSE;
	}

	m_cImageListPtr->Add(AfxGetApp()->LoadIcon(IDI_INTERACC));

	CRect rect;
	LV_COLUMN lvcolumn;
	TCHAR encabezado[3][25] = { _T("Interacc. Dipolar"), _T("Valor Calculado"),
		_T("Unidades") };
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

BOOL CResultadosOnePageOne::OnSetActive() 
{
	UpdateData(TRUE);
	m_cReportList.DeleteAllItems();
	m_cReportList.SetImageList(m_cImageListPtr, LVSIL_SMALL);
	
	// Leer la cantidad de Registros
	CFichero cFichero;
	if (!cFichero.Abre(GetDoc()->DevuelveStrCalculosFichero(), CFile::modeRead))
		return FALSE;

	int iCantIconos;
	cFichero.Seek(sizeof(CFileStatus) * 3, CFile::begin);
	cFichero.Read((char*) &iCantIconos, sizeof(int));
	cFichero.Close();
	//	Fin.

	CResultadosOneSheet *pSheet = STATIC_DOWNCAST(CResultadosOneSheet, GetParent());
	int iIndiceElegido = pSheet->DevuelveIndiceElegido();

	LV_ITEM lvitem;
	int iActualItem = 0;

	// Leer fichero de Interacciones
	if (!cFichero.Abre(GetDoc()->DevuelveStrInteraccFichero(), CFile::modeRead))
		return FALSE;

	for (int iItem = 0; iItem < iCantIconos; iItem++)  // will now insert the items and 
																		//	subitems into the list view.
	{
		StcValorDual stcValDual;
		cFichero.Lee((char*) &stcValDual, ((iIndiceElegido  - 1) * iCantIconos) +
			(iItem + 1), sizeof(StcValorDual));
		
		CInteraccion *pIntrc = new CInteraccion;
		pIntrc->EstableceConStruct(&stcValDual);

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
					str = pIntrc->DevuelveEtiqueta1() + ", " + pIntrc->DevuelveEtiqueta2();
					break;
				case 1:
					str.Format("%f", pIntrc->DevuelveValor());
					break;
				case 2:
					//str.Format("%f", pIntrc->RetornUnidad());
					str = _T("KHz.");
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

		delete pIntrc;
		pIntrc = NULL;
	}

	cFichero.Close();
	return CPropertyPage::OnSetActive();
}

/*CProyectoDoc* CResultadosOnePageOne::GetDoc()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());
	return pDoc;
}*/