#if !defined(AFX_CALCULOTENSORESPAGEDOS_H__29D6CE02_28E9_11D2_A5A7_807704C10000__INCLUDED_)
#define AFX_CALCULOTENSORESPAGEDOS_H__29D6CE02_28E9_11D2_A5A7_807704C10000__INCLUDED_


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CalculoTensoresPageDos.h : header file
//
#include "MainFrm.h"
#include "ProyectoView.h"
/////////////////////////////////////////////////////////////////////////////
// CCalculoTensoresPageDos dialog

class CCalculoTensoresPageDos : public CPropertyPage
{
	DECLARE_DYNCREATE(CCalculoTensoresPageDos)

// Construction
public:
	CCalculoTensoresPageDos();
	~CCalculoTensoresPageDos();
	double DevuelveDistanciaRij(CString str);
	extern friend CProyectoDoc* GetDoc();
	double DevuelveValorSegunEtiqueta(CString );
// Dialog Data
	//{{AFX_DATA(CCalculoTensoresPageDos)
	enum { IDD = IDD_INTERACCELEGIDASPAGE2 };
	CString	m_strDistorcionEtiquetaA;
	CString	m_strDistorcionEtiquetaB;
	CString	m_strDistorcionEtiquetaC;
	CString	m_strSeleccionEtiquetaA;
	CString	m_strSeleccionEtiquetaB;
	CString	m_strSeleccionEtiquetaC;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCalculoTensoresPageDos)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCalculoTensoresPageDos)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	double DevuelveConstante(CString str);
	BOOL InitPolos();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULOTENSORESPAGEDOS_H__29D6CE02_28E9_11D2_A5A7_807704C10000__INCLUDED_)
