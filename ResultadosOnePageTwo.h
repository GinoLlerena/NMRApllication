#if !defined(AFX_RESULTADOSONEPAGETWO_H__C7C59004_135F_11D2_B39B_BC5FD6588635__INCLUDED_)
#define AFX_RESULTADOSONEPAGETWO_H__C7C59004_135F_11D2_B39B_BC5FD6588635__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ResultadosOnePageTwo.h : header file
//

#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageTwo dialog

class CResultadosOnePageTwo : public CPropertyPage
{
	DECLARE_DYNCREATE(CResultadosOnePageTwo)

// Construction
public:
	CResultadosOnePageTwo();
	~CResultadosOnePageTwo();

// Dialog Data
	//{{AFX_DATA(CResultadosOnePageTwo)
	enum { IDD = IDD_LISTCTRL };
	CListCtrl	m_cReportList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CResultadosOnePageTwo)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CResultadosOnePageTwo)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CImageList *m_cImageListPtr;
	extern friend CProyectoDoc* GetDoc(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTADOSONEPAGETWO_H__C7C59004_135F_11D2_B39B_BC5FD6588635__INCLUDED_)
