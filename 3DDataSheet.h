#if !defined(AFX_3DDATASHEET_H__42178DA4_DF90_11D1_8622_91CAF4D51C50__INCLUDED_)
#define AFX_3DDATASHEET_H__42178DA4_DF90_11D1_8622_91CAF4D51C50__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// 3DDataSheet.h : header file
//

#include "3DDataPage.h"

/////////////////////////////////////////////////////////////////////////////
// C3DDataSheet

class C3DDataSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(C3DDataSheet)

// Construction
public:
	C3DDataSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	C3DDataSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	C3DDataPage m_cPagina;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C3DDataSheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~C3DDataSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(C3DDataSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3DDATASHEET_H__42178DA4_DF90_11D1_8622_91CAF4D51C50__INCLUDED_)
