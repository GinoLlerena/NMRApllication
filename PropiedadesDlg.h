#if !defined(AFX_PROPIEDADESDLG_H__CA922F61_1B74_11D2_B39C_F1746309B063__INCLUDED_)
#define AFX_PROPIEDADESDLG_H__CA922F61_1B74_11D2_B39C_F1746309B063__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropiedadesDlg.h : header file
//

#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CPropiedadesDlg dialog

class CPropiedadesDlg : public CDialog
{
// Construction
public:
	CPropiedadesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPropiedadesDlg)
	enum { IDD = IDD_PROPIEDADES };
	CString	m_strTitulo;
	CString	m_strAsunto;
	CString	m_strCreador;
	CString	m_strDescripcion;
	CString	m_strProyecto;
	CString	m_strCarpeta;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropiedadesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropiedadesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeTitulo();
	afx_msg void OnChangeAsunto();
	afx_msg void OnChangeCreador();
	afx_msg void OnChangeDescripcion();
	virtual void OnOK();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void EnableButton(UINT uIdentif, BOOL bBandera);
	CProyectoDoc* DevuelveDoc(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPIEDADESDLG_H__CA922F61_1B74_11D2_B39C_F1746309B063__INCLUDED_)
