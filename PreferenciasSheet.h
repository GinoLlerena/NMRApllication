#if !defined(AFX_PREFERENCIASSHEET_H__B78598E5_54B7_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_PREFERENCIASSHEET_H__B78598E5_54B7_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PreferenciasSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreferenciasSheet
#include "PreferenciasPageOne.h"
#include "PreferenciasPageTwo.h"
#include "PreferenciasPageThree.h"

class CPreferenciasSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPreferenciasSheet)

// Construction
public:
	CPreferenciasSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPreferenciasSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CPreferenciasPageOne	 m_cPageOne;
	CPreferenciasPageTwo	 m_cPageTwo;
	CPreferenciasPageThree m_cPageThree;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreferenciasSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPreferenciasSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPreferenciasSheet)
	afx_msg void OnMove(int x, int y);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCIASSHEET_H__B78598E5_54B7_11D2_A5A8_444553540001__INCLUDED_)
