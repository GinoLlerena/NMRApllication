#if !defined(AFX_CALCULOTENSORESSHEET_H__29D6CE03_28E9_11D2_A5A7_807704C10000__INCLUDED_)
#define AFX_CALCULOTENSORESSHEET_H__29D6CE03_28E9_11D2_A5A7_807704C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CalculoTensoresSheet.h : header file
//
#include "CalculoTensoresPageUno.h"
#include "CalculoTensoresPageDos.h"


/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresSheet

class CCalculoTensoresSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CCalculoTensoresSheet)

// Construction
public:
	CCalculoTensoresSheet(CWnd* pWndParent = NULL);


	

// Attributes
public:
	CCalculoTensoresPageUno m_cPageUno;
	CCalculoTensoresPageDos m_cPageDos;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculoTensoresSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	extern friend CProyectoDoc* GetDoc(void);
	virtual ~CCalculoTensoresSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCalculoTensoresSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULOTENSORESSHEET_H__29D6CE03_28E9_11D2_A5A7_807704C10000__INCLUDED_)
