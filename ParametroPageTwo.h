#if !defined(AFX_PARAMETROPAGETWO_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
#define AFX_PARAMETROPAGETWO_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ParametroPageTwo.h : header file
//

#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CParametroPageTwo dialog

class CParametroPageTwo : public CPropertyPage
{
	DECLARE_DYNCREATE(CParametroPageTwo)

// Construction
public:
	CParametroPageTwo();
	~CParametroPageTwo();
	extern friend CProyectoDoc* GetDoc(void);

// Dialog Data
	//{{AFX_DATA(CParametroPageTwo)
	enum { IDD = IDD_PARAMETROPAGE2 };
	CListCtrl	m_cReportList;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParametroPageTwo)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CParametroPageTwo)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CImageList *m_cImageListPtr;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETROPAGETWO_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
