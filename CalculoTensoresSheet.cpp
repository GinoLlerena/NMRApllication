// CalculoTensoresSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Proyecto.h"
#include "ProyectoDoc.h"
#include "ProyectoView.h"
#include "Mainfrm.h"
#include "CalculoTensoresSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresSheet

IMPLEMENT_DYNAMIC(CCalculoTensoresSheet, CPropertySheet)

CCalculoTensoresSheet::CCalculoTensoresSheet(CWnd* pWndParent)
	 : CPropertySheet(IDS_PARAMETROSHT_CAPTION, pWndParent)
{
	int iSimetria = GetDoc()->DevuelveSimetria();

	switch (iSimetria)
	{
		case 0:	// D4
		case 1:	// D2
			AddPage(&m_cPageUno);
			break;
		case 2:	// Sin Simetria
			AddPage(&m_cPageDos);
			break;
		case -1:
			break;
	}
}

CCalculoTensoresSheet::~CCalculoTensoresSheet()
{
}


BEGIN_MESSAGE_MAP(CCalculoTensoresSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CCalculoTensoresSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresSheet message handlers


/////////////////////////////////////////////////////////////////////////////
// CCalculosTensoresSheet aditional functions

