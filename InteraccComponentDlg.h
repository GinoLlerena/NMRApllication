#if !defined(AFX_INTERACCCOMPONENTDLG_H__A3686E22_F78B_11D1_B39A_9E3FDA774A3C__INCLUDED_)
#define AFX_INTERACCCOMPONENTDLG_H__A3686E22_F78B_11D1_B39A_9E3FDA774A3C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// InteraccComponentDlg.h : header file
//

#include "Resource.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CInteraccComponentDlg dialog

class CInteraccComponentDlg : public CDialog
{
// Construction
public:
	CInteraccComponentDlg(CWnd* pParent = NULL);   // standard constructor
	CProyectoDoc* GetDoc(void);
	int GetTotalPolos(void);
	BOOL InitPolos(void);
	CInteraccObservadaList GetInteraccObservadaList(void);

//	Data members
private:
	CString m_strPoloBase1;
	CString m_strPoloBase2;

//	Attributes
public:
	BOOL	m_bIsNuevo;

// Functions members
private:
	void EnableButton(UINT, BOOL);
	void SetComboText(UINT, CString);
	void GetComboText(UINT, CString&);

// Dialog Data
	//{{AFX_DATA(CInteraccComponentDlg)
	enum { IDD = IDD_INTERACCCOMPONENTS };
	CListBox	m_lbReport;
	CString	m_strPolo1;
	CString	m_strPolo2;
	CString	m_strInteraccBase;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInteraccComponentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInteraccComponentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnNuevo();
	afx_msg void OnGuardar();
	afx_msg void OnEliminar();
	afx_msg void OnSelendokIntrcbase();
	afx_msg void OnSelendokEtqtpolo1();
	afx_msg void OnSelendokEtqtpolo2();
	afx_msg void OnSelchangeList();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERACCCOMPONENTDLG_H__A3686E22_F78B_11D1_B39A_9E3FDA774A3C__INCLUDED_)
