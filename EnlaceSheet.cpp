// EnlaceSheet.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "EnlaceSheet.h"
#include "MainFrm.h"
#include "ProyectoView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnlaceSheet

IMPLEMENT_DYNAMIC(CEnlaceSheet, CPropertySheet)

CEnlaceSheet::CEnlaceSheet(CWnd* pWndParent)
	 : CPropertySheet(IDS_ENLACESHT_CAPTION, pWndParent)
{
	m_iIndiceElegido = 0;
	// Add all of the property pages here.  Note that
	// the order that they appear in here will be
	// the order they appear in on screen.  By default,
	// the first page of the set is the active one.
	// One way to make a different property page the 
	// active one is to call SetActivePage().

	AddPage(&m_cPaginaOne);
	AddPage(&m_cPaginaTwo);
	AddPage(&m_cPaginaThree);
}

CEnlaceSheet::~CEnlaceSheet()
{
}


BEGIN_MESSAGE_MAP(CEnlaceSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CEnlaceSheet)
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CEnlaceSheet message handlers

BOOL CEnlaceSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	return TRUE;
}

void CEnlaceSheet::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::OnMoving(fwSide, pRect);
}

void CEnlaceSheet::PostNcDestroy() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView *pView = STATIC_DOWNCAST(CProyectoView, pFrame->GetActiveView());
	pView->Invalidate(TRUE);
	CPropertySheet::PostNcDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// CEnlaceSheet Input functions

void CEnlaceSheet::EstableceIndiceElegido(int iIndice)
{
	m_iIndiceElegido = iIndice;
}

void CEnlaceSheet::EsDeAnilloFenil(BOOL bBandera)
{
	m_cPaginaOne.EsDeAnilloFenil(bBandera);
}

void CEnlaceSheet::PerteneceA(ParteRigida nParteRigida)
{
	m_cPaginaOne.PerteneceA(nParteRigida);
}

void CEnlaceSheet::EstableceEnlace(CString cStrEnlace)
{
	m_strEnlaceActual = cStrEnlace;
}

/////////////////////////////////////////////////////////////////////////////
// CEnlaceSheet Output functions

int CEnlaceSheet::DevuelveIndiceElegido()
{
	return m_iIndiceElegido;
}

BOOL CEnlaceSheet::SiEsDeAnilloFenil()
{
	return m_cPaginaOne.SiEsDeAnilloFenil();
}

CString CEnlaceSheet::DevuelveEnlace()
{
	return m_strEnlaceActual;
}
