// EnlacePage3.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "EnlacePage3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnlacePage3 property page

IMPLEMENT_DYNCREATE(CEnlacePage3, CPropertyPage)

CEnlacePage3::CEnlacePage3() : CPropertyPage(CEnlacePage3::IDD)
{
	//{{AFX_DATA_INIT(CEnlacePage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CEnlacePage3::~CEnlacePage3()
{
}

void CEnlacePage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnlacePage3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnlacePage3, CPropertyPage)
	//{{AFX_MSG_MAP(CEnlacePage3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnlacePage3 message handlers
