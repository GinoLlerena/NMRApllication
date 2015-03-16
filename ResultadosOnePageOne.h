#if !defined(AFX_RESULTADOSONEPAGEONE_H__C7C59001_135F_11D2_B39B_BC5FD6588635__INCLUDED_)
#define AFX_RESULTADOSONEPAGEONE_H__C7C59001_135F_11D2_B39B_BC5FD6588635__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ResultadosOnePageOne.h : header file
//

#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageOne dialog

class CResultadosOnePageOne : public CPropertyPage
{
	DECLARE_DYNCREATE(CResultadosOnePageOne)

// Construction
public:
	CResultadosOnePageOne();
	~CResultadosOnePageOne();

// Dialog Data
	//{{AFX_DATA(CResultadosOnePageOne)
	enum { IDD = IDD_LISTCTRL };
	CListCtrl	m_cReportList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CResultadosOnePageOne)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CResultadosOnePageOne)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CImageList *m_cImageListPtr;
	extern friend CProyectoDoc* GetDoc(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTADOSONEPAGEONE_H__C7C59001_135F_11D2_B39B_BC5FD6588635__INCLUDED_)
