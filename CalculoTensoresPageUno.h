#if !defined(AFX_CALCULOTENSORESPAGEUNO_H__29D6CE01_28E9_11D2_A5A7_807704C10000__INCLUDED_)
#define AFX_CALCULOTENSORESPAGEUNO_H__29D6CE01_28E9_11D2_A5A7_807704C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CalculoTensoresPageUno.h : header file
//
#include "MainFrm.h"
#include "ProyectoView.h"

/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresPageUno dialog

class CCalculoTensoresPageUno : public CPropertyPage
{
	DECLARE_DYNCREATE(CCalculoTensoresPageUno)

// Construction
public:
//	extern friend CProyectoDoc* GetDoc(void);
	CCalculoTensoresPageUno();
	~CCalculoTensoresPageUno();
	friend CProyectoDoc* GetDoc();
	double DevuelveValorSegunEtiqueta(CString cStr);
// Dialog Data
	//{{AFX_DATA(CCalculoTensoresPageUno)
	enum { IDD = IDD_INTERACCELEGIDASPAGE1 };
	CString	m_strSeleccionA;
	CString	m_strSeleccionB;
	CString	m_strSeleccionC;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCalculoTensoresPageUno)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCalculoTensoresPageUno)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL InitPolos();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULOTENSORESPAGEUNO_H__29D6CE01_28E9_11D2_A5A7_807704C10000__INCLUDED_)
