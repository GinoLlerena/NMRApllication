//	3DToolBar.cpp : implementation of the C3DToolBar class
//

#include "stdafx.h"
#include "3DToolBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////
//	C3DToolBar

BEGIN_MESSAGE_MAP(C3DToolBar, CToolBar)
	//{{AFX_MSG_MAP(C3DToolBar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////
//	C3DToolBar construction/destruction

C3DToolBar::C3DToolBar()
{
}

C3DToolBar::~C3DToolBar()
{
}

///////////////////////////////////////////////////////////
//	C3DToolBar diagnostics

#ifdef _DEBUG
void C3DToolBar::AssertValid() const
{
	CToolBar::AssertValid();
}

void C3DToolBar::Dump(CDumpContext& dc) const
{
	CToolBar::Dump(dc);
}
#endif // _DEBUG

///////////////////////////////////////////////////////////
//	C3DToolBar message handlers
