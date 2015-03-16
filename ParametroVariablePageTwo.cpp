// ParametroVariablePageTwo.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "ParametroVariablePageTwo.h"
#include "MainFrm.h"
#include "ProyectoView.h"
#include "ParametroVariableSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParametroVariablePageTwo property page

IMPLEMENT_DYNCREATE(CParametroVariablePageTwo, CPropertyPage)

CParametroVariablePageTwo::CParametroVariablePageTwo() : 
	CPropertyPage(CParametroVariablePageTwo::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Lista de Parámetros Variables");
	m_cImageListPtr = new CImageList;

	//{{AFX_DATA_INIT(CParametroVariablePageTwo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CParametroVariablePageTwo::~CParametroVariablePageTwo()
{
	delete m_cImageListPtr;
}

void CParametroVariablePageTwo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParametroVariablePageTwo)
	DDX_Control(pDX, IDC_LIST, m_cReportList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParametroVariablePageTwo, CPropertyPage)
	//{{AFX_MSG_MAP(CParametroVariablePageTwo)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParametroVariablePageTwo message handlers

BOOL CParametroVariablePageTwo::OnInitDialog() 
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
	TCHAR encabezado[4][25] = {_T("Parámetros"), _T("Valor Inicial"), _T("Valor Final"),
		_T("Incremento")};
	m_cReportList.GetWindowRect(&rect);

	for (int i = 0; i < 4; i++)  // add the columns to the list control
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

/*CProyectoDoc* CParametroVariablePageTwo::GetDoc()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	CProyectoDoc *pDoc = STATIC_DOWNCAST(CProyectoDoc, pView->GetDocument());
	return pDoc;
}*/

BOOL CParametroVariablePageTwo::OnSetActive() 
{
	UpdateData(TRUE);
	m_cReportList.DeleteAllItems();
	int iCantIconos = GetDoc()->m_cParametroVariableList.GetCount();
	
	m_cReportList.SetImageList(m_cImageListPtr, LVSIL_SMALL);
	LV_ITEM lvitem;
	int iActualItem = 0;
	CString str = _T("");
	
	for (int iItem = 0; iItem < iCantIconos; iItem++)  // will now insert the items and subitems into the list view.
	{
		for (int iSubItem = 0; iSubItem < 4; iSubItem++)
		{
			TCHAR palabra[25] = { _T("") };
			lvitem.mask = LVIF_TEXT | (iSubItem == 0 ? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0) ? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			str = _T("");
						
			switch (iSubItem)
			{
				case 0:
					str = GetDoc()->DevuelveParamVariabPtr(iItem)->DevuelveEtiqueta();
					break;
				case 1:
					str.Format("%f", GetDoc()->DevuelveParamVariabPtr(iItem)->DevuelveValorInicial());
					break;
				case 2:
					str.Format("%f", GetDoc()->DevuelveParamVariabPtr(iItem)->DevuelveValorFinal());
					break;
				case 3:
					str.Format("%f", GetDoc()->DevuelveParamVariabPtr(iItem)->DevuelveIncremento());
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
	}
	
	//m_cReportList.SetBkColor(RGB(255, 255, 255)); // UGLY!
	return CPropertyPage::OnSetActive();
}

void CParametroVariablePageTwo::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount(); iIndex++)
	{
		UINT uState;
		uState = m_cReportList.GetItemState(iIndex, LVIS_SELECTED);
		
		if (uState == LVIS_SELECTED)
		{
			CParametroVariableSheet *pSheet = STATIC_DOWNCAST(CParametroVariableSheet,
				GetParent());
			pSheet->EstableceIndiceElegido(iIndex);
			break;
		}
	}

	*pResult = 0;
}
