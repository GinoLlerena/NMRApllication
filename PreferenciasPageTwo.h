#if !defined(AFX_PREFERENCIASPAGETWO_H__B78598E2_54B7_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_PREFERENCIASPAGETWO_H__B78598E2_54B7_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PreferenciasPageTwo.h : header file
//
#include "ProyectoDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageTwo dialog

class CPreferenciasPageTwo : public CPropertyPage
{
	DECLARE_DYNCREATE(CPreferenciasPageTwo)

// Construction
public:
	CPreferenciasPageTwo();
	~CPreferenciasPageTwo();
	extern friend CProyectoDoc* GetDoc(void);

// Dialog Data
	//{{AFX_DATA(CPreferenciasPageTwo)
	enum { IDD = IDD_PREFERENCIASPAGE2 };
	double	m_dError;
	int		m_iLimite;
	double	m_dValores;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPreferenciasPageTwo)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPreferenciasPageTwo)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCIASPAGETWO_H__B78598E2_54B7_11D2_A5A8_444553540001__INCLUDED_)
