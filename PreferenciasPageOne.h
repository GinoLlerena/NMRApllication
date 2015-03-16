#if !defined(AFX_PREFERENCIASPAGEONE_H__B78598E3_54B7_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_PREFERENCIASPAGEONE_H__B78598E3_54B7_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PreferenciasPageOne.h : header file
//
#include "ProyectoDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageOne dialog

class CPreferenciasPageOne : public CPropertyPage
{
	DECLARE_DYNCREATE(CPreferenciasPageOne)

// Construction
public:
	CPreferenciasPageOne();
	~CPreferenciasPageOne();
	extern friend CProyectoDoc* GetDoc(void);

// Dialog Data
	//{{AFX_DATA(CPreferenciasPageOne)
	enum { IDD = IDD_PREFERENCIASPAGE1 };
	int		m_iSimetria;
	CString	m_strAngulo;
	CString	m_strDistancia;
	CString	m_strInteraccion;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPreferenciasPageOne)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPreferenciasPageOne)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCIASPAGEONE_H__B78598E3_54B7_11D2_A5A8_444553540001__INCLUDED_)
