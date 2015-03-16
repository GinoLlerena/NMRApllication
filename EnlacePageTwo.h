#if !defined(AFX_ENLACEPAGETWO_H__6F046CA9_0A2E_11D2_B39A_D414BC408033__INCLUDED_)
#define AFX_ENLACEPAGETWO_H__6F046CA9_0A2E_11D2_B39A_D414BC408033__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EnlacePageTwo.h : header file
//

#include "ParteRigida.h"

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageTwo dialog

class CEnlacePageTwo : public CPropertyPage
{
	DECLARE_DYNCREATE(CEnlacePageTwo)

// Construction
public:
	CEnlacePageTwo();
	~CEnlacePageTwo();

// Dialog Data
	//{{AFX_DATA(CEnlacePageTwo)
	enum { IDD = IDD_ENLACEPAGE2 };
	CString	m_strEnlace;
	double	m_dLongitud;
	double	m_dAnguloPhi;
	double	m_dAnguloTeta;
	double	m_dX1;
	double	m_dX2;
	double	m_dY1;
	double	m_dY2;
	double	m_dZ1;
	double	m_dZ2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CEnlacePageTwo)
	public:
	virtual BOOL OnSetActive();
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CEnlacePageTwo)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CParteRigida* DevuelveParteRigida(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENLACEPAGETWO_H__6F046CA9_0A2E_11D2_B39A_D414BC408033__INCLUDED_)
