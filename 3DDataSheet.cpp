// 3DDataSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "3DDataSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C3DDataSheet

IMPLEMENT_DYNAMIC(C3DDataSheet, CPropertySheet)

C3DDataSheet::C3DDataSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

C3DDataSheet::C3DDataSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_cPagina.m_psp.dwFlags |= PSP_USETITLE;
	m_cPagina.m_psp.pszTitle = "Datos Generales";
	AddPage(&m_cPagina);
}

C3DDataSheet::~C3DDataSheet()
{
}


BEGIN_MESSAGE_MAP(C3DDataSheet, CPropertySheet)
	//{{AFX_MSG_MAP(C3DDataSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C3DDataSheet message handlers

BOOL C3DDataSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	m_cPagina.EstableceControles();
	
	return TRUE;
}
