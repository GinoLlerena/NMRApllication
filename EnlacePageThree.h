#if !defined(AFX_ENLACEPAGETHREE_H__ACEF7762_2218_11D2_A5A6_D47704C10000__INCLUDED_)
#define AFX_ENLACEPAGETHREE_H__ACEF7762_2218_11D2_A5A6_D47704C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EnlacePageThree.h : header file
//
#include "ParteRigida.h"
/////////////////////////////////////////////////////////////////////////////
// CEnlacePageThree dialog

class CEnlacePageThree : public CPropertyPage
{
	DECLARE_DYNCREATE(CEnlacePageThree)

// Construction
public:
	CEnlacePageThree();
	~CEnlacePageThree();
	CParteRigida* DevuelveParteRigida();
// Dialog Data
	//{{AFX_DATA(CEnlacePageThree)
	enum { IDD = IDD_ENLACEPAGE3 };
	double	m_dLongitud;
	double	m_dLongitud2;
	double	m_dPhi;
	double	m_dPhi2;
	double	m_dTeta;
	double	m_dTeta2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CEnlacePageThree)
	public:
	virtual BOOL OnSetActive();
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CEnlacePageThree)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENLACEPAGETHREE_H__ACEF7762_2218_11D2_A5A6_D47704C10000__INCLUDED_)
