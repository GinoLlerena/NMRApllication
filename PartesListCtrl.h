#if !defined(AFX_PARTESLISTCTRL_H__1B13DBA4_EA29_11D1_B39A_D1074DA31530__INCLUDED_)
#define AFX_PARTESLISTCTRL_H__1B13DBA4_EA29_11D1_B39A_D1074DA31530__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PartesListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPartesListCtrl window

class CPartesListCtrl : public CListCtrl
{
// Construction
public:
	CPartesListCtrl();
	BOOL Init(CWnd* pParentWnd);

// Attributes
public:
	CImageList m_cImageList;
	BOOL m_bCaptured;
	int m_iSelected;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPartesListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPartesListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPartesListCtrl)
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARTESLISTCTRL_H__1B13DBA4_EA29_11D1_B39A_D1074DA31530__INCLUDED_)
