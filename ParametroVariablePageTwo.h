#if !defined(AFX_PARAMETROVARIABLEPAGETWO_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
#define AFX_PARAMETROVARIABLEPAGETWO_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ParametroVariablePageTwo.h : header file
//

#include "Resource.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CParametroVariablePageTwo dialog

class CParametroVariablePageTwo : public CPropertyPage
{
	DECLARE_DYNCREATE(CParametroVariablePageTwo)

// Construction
public:
	CParametroVariablePageTwo();
	~CParametroVariablePageTwo();
	extern friend CProyectoDoc* GetDoc(void);

// Dialog Data
	//{{AFX_DATA(CParametroVariablePageTwo)
	enum { IDD = IDD_LISTCTRL };
	CListCtrl	m_cReportList;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParametroVariablePageTwo)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CParametroVariablePageTwo)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CImageList *m_cImageListPtr;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETROVARIABLEPAGETWO_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
