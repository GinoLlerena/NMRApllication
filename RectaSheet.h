#if !defined(AFX_RECTASHEET_H__E7C40193_CEF6_11D1_8611_9EC4C1F4F450__INCLUDED_)
#define AFX_RECTASHEET_H__E7C40193_CEF6_11D1_8611_9EC4C1F4F450__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// RectaSheet.h : header file
//

#include "RectaPage.h"

/////////////////////////////////////////////////////////////////////////////

static char *LadIntAnillofenil[6] = { "AB",
	"BC",	"CD",	"DE",	"EF",	"FA" };

/*
static char *LadExtAnillofenil[6] = { "AA'",
	"BB'",	"CC'",	"DD'",	"EE'",
	"FF'" };

static char *BrazoTrifenil[1] = { "AO" };
*/

/////////////////////////////////////////////////////////////////////////////
// CRectaSheet

class CRectaSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CRectaSheet)

// Construction
public:
	CRectaSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CRectaSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CRectaPage m_cPagina;
	ParteRigida m_nParte;
	CString *pString;

// Operations
public:
	void InicializaDialogo(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRectaSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRectaSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRectaSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECTASHEET_H__E7C40193_CEF6_11D1_8611_9EC4C1F4F450__INCLUDED_)
