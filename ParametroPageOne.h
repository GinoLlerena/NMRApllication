#if !defined(AFX_PARAMETROPAGEONE_H__386CB249_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
#define AFX_PARAMETROPAGEONE_H__386CB249_0517_11D2_B39A_8831FB889C3E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ParametroPageOne.h : header file
//

#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CParametroPageOne dialog

class CParametroPageOne : public CPropertyPage
{
	DECLARE_DYNCREATE(CParametroPageOne)

// Construction
public:
	CParametroPageOne();
	~CParametroPageOne();

// Dialog Data
	//{{AFX_DATA(CParametroPageOne)
	enum { IDD = IDD_PARAMETROPAGE1 };
	double	m_dValorActual;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParametroPageOne)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CProyectoDoc* GetDoc(void);
	void SetEditText(UINT uIdentif, CString cStr);

	// Generated message map functions
	//{{AFX_MSG(CParametroPageOne)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeActual();
	afx_msg void OnGuardar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void GetEditText(UINT uIdentif, CString &cStr);
	void EnableButton(UINT uIdentif, BOOL bBandera);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETROPAGEONE_H__386CB249_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
