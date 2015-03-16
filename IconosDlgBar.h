#if !defined(AFX_ICONOSDLGBAR_H__1B13DBA3_EA29_11D1_B39A_D1074DA31530__INCLUDED_)
#define AFX_ICONOSDLGBAR_H__1B13DBA3_EA29_11D1_B39A_D1074DA31530__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IconosDlg.h : header file
//

#include "PartesListCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CIconosDlgBar dialog

class CIconosDlgBar : public CDialogBar
{
// Construction
public:
	CIconosDlgBar();   // standard constructor
	~CIconosDlgBar();

	CPartesListCtrl m_cPartesListCtrl;
	BOOL Init(CWnd* pParentWnd);
	
// Implementation
protected:

// Generated message map functions
	//{{AFX_MSG(CIconosDlgBar)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONOSDLGBAR_H__1B13DBA3_EA29_11D1_B39A_D1074DA31530__INCLUDED_)
