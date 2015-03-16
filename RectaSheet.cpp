// RectaSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "RectaSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRectaSheet

IMPLEMENT_DYNAMIC(CRectaSheet, CPropertySheet)

CRectaSheet::CRectaSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CRectaSheet::CRectaSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_cPagina.m_psp.dwFlags |= PSP_USETITLE;
	m_cPagina.m_psp.pszTitle = "Propiedades";
	AddPage(&m_cPagina);
}

CRectaSheet::~CRectaSheet()
{
}


BEGIN_MESSAGE_MAP(CRectaSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CRectaSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRectaSheet message handlers

BOOL CRectaSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	InicializaDialogo();
	m_cPagina.EstableceControles();
	return TRUE;
}

void CRectaSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);
}

void CRectaSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CRectaSheet Operations

void CRectaSheet::InicializaDialogo(void)
{
	CComboBox* plB = (CComboBox*) m_cPagina.GetDlgItem(IDC_LADO_ELEGIDO);
	int iTot = 0;

	switch(m_nParte)
	{
		case AnilloFenil:
			pString = (CString*) LadIntAnillofenil;
			iTot = 6;
			break;
		/*
		case Bifenil:
			pString = (CString*) LadBifenil;
			iTot = 2;
			break;

		case Trifenil:
			pString = (CString*) LadTrifenil;
			iTot = 3;
			break;
      */
	}

	for (int i = 0; i < iTot; i++)
		plB->AddString(*(pString+i));	

	plB->SetCurSel(0);
}
