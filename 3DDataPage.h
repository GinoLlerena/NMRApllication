#if !defined(AFX_3DDATAPAGE_H__42178DA3_DF90_11D1_8622_91CAF4D51C50__INCLUDED_)
#define AFX_3DDATAPAGE_H__42178DA3_DF90_11D1_8622_91CAF4D51C50__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// 3DDataPage.h : header file
//

#include "OpenGLView.h"

/////////////////////////////////////////////////////////////////////////////
// C3DDataPage dialog

class C3DDataPage : public CPropertyPage
{
	DECLARE_DYNCREATE(C3DDataPage)

// Construction
public:
	C3DDataPage();
	~C3DDataPage();
	void EstableceControles(void);

private:
	COpenGLView* GetOpenGLView(void);

// Dialog Data
	//{{AFX_DATA(C3DDataPage)
	enum { IDD = IDD_3DDATA };
	float	m_fCaraFrontal;
	float	m_fCaraPosterior;
	float	m_fRotarEjeX;
	float	m_fRotarEjeY;
	float	m_fRotarEjeZ;
	float	m_fZoom;
	float	m_fAngPerspectiva;
	float	m_fValorEjeX;
	float	m_fValorEjeY;
	float	m_fValorEjeZ;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(C3DDataPage)
	public:
	virtual BOOL OnApply();
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(C3DDataPage)
	afx_msg void OnChangeZoom();
	afx_msg void OnChangeCaraFrontal();
	afx_msg void OnChangeCaraPosterior();
	afx_msg void OnChangeRotarEjex();
	afx_msg void OnChangeRotarEjey();
	afx_msg void OnChangeRotarEjez();
	afx_msg void OnChangeAngPerspectiva();
	afx_msg void OnChangeValorEjex();
	afx_msg void OnChangeValorEjey();
	afx_msg void OnChangeValorEjez();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3DDATAPAGE_H__42178DA3_DF90_11D1_8622_91CAF4D51C50__INCLUDED_)
