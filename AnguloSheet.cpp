// AnguloSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "AnguloSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnguloSheet

IMPLEMENT_DYNAMIC(CAnguloSheet, CPropertySheet)

CAnguloSheet::CAnguloSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CAnguloSheet::CAnguloSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_cPagina);
}

CAnguloSheet::~CAnguloSheet()
{
}


BEGIN_MESSAGE_MAP(CAnguloSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CAnguloSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnguloSheet message handlers

BOOL CAnguloSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	InicializaDialogo();
	m_cPagina.EstableceControles();
	return TRUE;
}

void CAnguloSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);
}

void CAnguloSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);	
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CAnguloSheet Operations

void CAnguloSheet::InicializaDialogo(void)
{
	CComboBox* pCombo = (CComboBox*) m_cPagina.GetDlgItem(IDC_ANG_ELEGIDO);
	int iTot;
	HBITMAP hBitmap;

	switch(m_nParte)
	{
		case AnilloFenil:
			if (m_cPagina.m_bEsInterno)
				pString = (CString*) AngIntAnillofenil;
			else
				pString = (CString*) AngExtAnillofenil;

			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MINIANILLO) );
			iTot = 6;
			break;
		case Bifenil:
			pString = (CString*) AngBifenil;
			hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MINIBIFENIL) );
			iTot = 1;
			break;
		case Trifenil:
			if (m_cPagina.m_bEsInterno)
			{
				pString = (CString*) AngIntTrifenil;
				hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MINITRIFENIL) );
				iTot = 3;
			}
			else
			{
				pString = (CString*) AngExtTrifenil;
				hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TRIFENILAVERTURA) );
				iTot = 2;
			}

			
			
			break;
	}  

	m_cPagina.m_cImagen.SetBitmap(hBitmap);	// Establece el bitmap adecuado.

	for (int i = 0; i < iTot; i++)
		pCombo->AddString(*(pString+i));	

	pCombo->SetCurSel(0);

	pCombo = (CComboBox*) m_cPagina.GetDlgItem(IDC_PARAMETRO);
	
	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount();
		iIndex++)
	{
		CParametroVariable *pParamVariab = GetDoc()->DevuelveParamVariabPtr(iIndex);

		if (pParamVariab != NULL)
		{
			pCombo->AddString(pParamVariab->DevuelveEtiqueta());
		}
	}
}

void CAnguloSheet::EsAnguloInterno(BOOL bAngInterno)
{
	m_cPagina.m_bEsInterno = bAngInterno;
}


