#if !defined(AFX_PREFERENCIASPAGETHREE_H__B78598E4_54B7_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_PREFERENCIASPAGETHREE_H__B78598E4_54B7_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PreferenciasPageThree.h : header file
//
#include "ProyectoDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CPreferenciasPageThree dialog

class CPreferenciasPageThree : public CPropertyPage
{
	DECLARE_DYNCREATE(CPreferenciasPageThree)

// Construction
public:
	CPreferenciasPageThree();
	~CPreferenciasPageThree();
	extern friend CProyectoDoc* GetDoc(void);

// Dialog Data
	//{{AFX_DATA(CPreferenciasPageThree)
	enum { IDD = IDD_PREFERENCIASPAGE3 };
	double	m_dPuntoInicialEquis;
	double	m_dPuntoFinalEquis;
	double	m_dPuntoInicialYe;
	double	m_dPuntoFinalYe;
	double	m_dPuntoInicialZeta;
	double	m_dPuntoFinalZeta;
	CString	m_strPlanoGDI;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPreferenciasPageThree)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPreferenciasPageThree)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCIASPAGETHREE_H__B78598E4_54B7_11D2_A5A8_444553540001__INCLUDED_)
