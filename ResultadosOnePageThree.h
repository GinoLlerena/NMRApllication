#if !defined(AFX_RESULTADOSONEPAGETHREE_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
#define AFX_RESULTADOSONEPAGETHREE_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ResultadosOnePageThree.h : header file
//

#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CResultadosOnePageThree dialog

class CResultadosOnePageThree : public CPropertyPage
{
	DECLARE_DYNCREATE(CResultadosOnePageThree)

// Construction
public:
	CResultadosOnePageThree();
	~CResultadosOnePageThree();

// Dialog Data
	//{{AFX_DATA(CResultadosOnePageThree)
	enum { IDD = IDD_LISTCTRL2 };
	CListCtrl	m_cReportList;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CResultadosOnePageThree)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CResultadosOnePageThree)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAnteriores();
	afx_msg void OnSiguientes();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL EstablecerDatos(void);
	int m_iElementosEnPagFinal;
	int m_iPaginaActual;
	int m_iPaginaFinal;
	int m_iCantIconos;
	CImageList *m_cImageListPtr;
	extern friend CProyectoDoc* GetDoc(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTADOSONEPAGETHREE_H__386CB24A_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
