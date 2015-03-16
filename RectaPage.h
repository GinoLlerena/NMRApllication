#if !defined(AFX_RECTAPAGE_H__8D2FBB1E_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
#define AFX_RECTAPAGE_H__8D2FBB1E_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// RectaPage.h : header file
//

#include "ParteRigida.h"

/////////////////////////////////////////////////////////////////////////////
// CRectaPage dialog

class CRectaPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CRectaPage)

// Construction
public:
	CRectaPage();
	~CRectaPage();

	void EstableceControles(void);
	CParteRigida* GetParteRigida(void);
	extern friend void RedibujarVista(void);

// Dialog Data
	//{{AFX_DATA(CRectaPage)
	enum { IDD = IDD_RECTA };
	CStatic	m_cImagen;
	double m_dLongitud;
	double m_dPhi;
	double m_dTeta;
	double m_dX1;
	double m_dX2;
	double m_dY1;
	double m_dY2;
	double m_dZ1;
	double m_dZ2;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRectaPage)
	public:
	virtual BOOL OnApply();
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void OnRectaPageClicked(UINT nCmdID);
	// Generated message map functions
	//{{AFX_MSG(CRectaPage)
	afx_msg void OnSelendokLadoElegido();
	afx_msg void OnChangeLongitud();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECTAPAGE_H__8D2FBB1E_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
