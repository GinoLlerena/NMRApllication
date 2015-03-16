// InteraccObservadaPageTwo.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "InteraccObservadaPageTwo.h"
#include "InteraccObservadaSheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CInteraccObservadaPageTwo, CPropertyPage)

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageTwo property page

CInteraccObservadaPageTwo::CInteraccObservadaPageTwo() :
	CPropertyPage(CInteraccObservadaPageTwo::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = _T("Lista de Interacciones");
	m_cImageListPtr = new CImageList;
	//{{AFX_DATA_INIT(CInteraccObservadaPageTwo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CInteraccObservadaPageTwo::~CInteraccObservadaPageTwo()
{
	delete m_cImageListPtr;
}

void CInteraccObservadaPageTwo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInteraccObservadaPageTwo)
	DDX_Control(pDX, IDC_LCREPORT, m_cReportList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInteraccObservadaPageTwo, CPropertyPage)
	//{{AFX_MSG_MAP(CInteraccObservadaPageTwo)
	ON_NOTIFY(NM_CLICK, IDC_LCREPORT, OnClickLcreport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageTwo message handlers

BOOL CInteraccObservadaPageTwo::OnInitDialog() 
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
	TCHAR encabezado[3][25] = { _T("Interacc. Dipolar"), _T("Valor Observado"),
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

BOOL CInteraccObservadaPageTwo::OnSetActive() 
{
	UpdateData(TRUE);
	m_cReportList.DeleteAllItems();
	int iCantIconos = GetDoc()->m_cInteraccObservadaList.GetCount();

	m_cReportList.SetImageList(m_cImageListPtr, LVSIL_SMALL);
	LV_ITEM lvitem;
	int iActualItem = 0;
	CString str = _T("");

	for (int iItem = 0; iItem < iCantIconos; iItem++)  // will now insert the items and subitems into the list view.
	{
		for (int iSubItem = 0; iSubItem < 3; iSubItem++)
		{
			TCHAR palabra[25] = { _T("") };
			lvitem.mask = LVIF_TEXT | (iSubItem == 0 ? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0) ? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			str = _T("");
						
			switch (iSubItem)
			{
				case 0:
					str = GetDoc()->DevuelveInteraccObservadaPtr(iItem)->DevuelveEtiquetas();
					break;
				case 1:
					str.Format("%f",
						GetDoc()->DevuelveInteraccObservadaPtr(iItem)->DevuelveValor() );
					break;
				case 2:
					/*
					str.Format("%f", 
						GetDoc()->DevuelveInteraccObservadaPtr(iItem)->DevuelveValorFinal());
					*/
					str = _T("kHz");
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

void CInteraccObservadaPageTwo::OnClickLcreport(NMHDR* pNMHDR, LRESULT* pResult) 
{
	for (int iIndex = 0; iIndex < GetDoc()->m_cInteraccObservadaList.GetCount(); iIndex++)
	{
		UINT uState;
		uState = m_cReportList.GetItemState(iIndex, LVIS_SELECTED);
		
		if (uState == LVIS_SELECTED)
		{
			CInteraccObservadaSheet *pSheet = STATIC_DOWNCAST(CInteraccObservadaSheet,
				GetParent() );
			pSheet->EstableceIndiceElegido(iIndex);
			break;
		}
	}

	*pResult = 0;
}
