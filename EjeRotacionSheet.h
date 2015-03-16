#if !defined(AFX_EJEROTACIONSHEET_H__031B8534_DA8D_11D1_8615_9C9634D91B50__INCLUDED_)
#define AFX_EJEROTACIONSHEET_H__031B8534_DA8D_11D1_8615_9C9634D91B50__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EjeRotacionSheet.h : header file
//

#include "EjeRotacionPage.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionSheet

class CEjeRotacionSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CEjeRotacionSheet)

// Construction
public:
	CEjeRotacionSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CEjeRotacionSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CEjeRotacionPage m_cPagina;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEjeRotacionSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	void PerteneceA(ParteRigida nParteRigida);
	virtual ~CEjeRotacionSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEjeRotacionSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	extern friend CProyectoDoc* GetDoc(void);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EJEROTACIONSHEET_H__031B8534_DA8D_11D1_8615_9C9634D91B50__INCLUDED_)
