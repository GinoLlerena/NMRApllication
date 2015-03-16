#if !defined(AFX_LISTAPARTESDLG_H__B7E81203_CD2E_11D1_8608_94C97DE61C50__INCLUDED_)
#define AFX_LISTAPARTESDLG_H__B7E81203_CD2E_11D1_8608_94C97DE61C50__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ListaPartesDlg.h : header file
//

#include "resource.h"
#include "Structures.h"

/////////////////////////////////////////////////////////////////////////////
// CListaPartesDlg dialog

class CListaPartesDlg : public CDialog
{
// Construction
public:
	CListaPartesDlg(CWnd* pParent = NULL);   // standard constructor
	~CListaPartesDlg();
	friend void EstableceParametros(ParteRigida , int );
//	Data Members

// Functions 
	// Dialog Data
	//{{AFX_DATA(CListaPartesDlg)
	enum { IDD = IDD_LIST };
	CListBox	m_cList;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListaPartesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListaPartesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnListActivar();
	afx_msg void OnListEliminar();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTAPARTESDLG_H__B7E81203_CD2E_11D1_8608_94C97DE61C50__INCLUDED_)
