#ifndef _MainBar_H
#define _MainBar_H

#include "ObjectsBox.h"

/////////////////////////////////////////////////////////////////////////////
// CMainBar window

class CMainBar : public CToolBar
{
// Construction
public:
	CMainBar();
	BOOL Init(CWnd* pParentWnd, BOOL bToolTips);
	BOOL SetHorizontal();
	BOOL SetVertical();
	
// Attributes
public:
	CObjectsBox m_ObjectsBox;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bVertical;
	
	virtual ~CMainBar();
	virtual CSize CalcDynamicLayout(int nLength, DWORD dwMode);
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CMainBar)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // _MainBar_H
