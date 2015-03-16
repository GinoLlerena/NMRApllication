#if !defined(AFX_EJEROTACIONPAGE_H__B00E0143_0694_11D2_B39A_978473300C33__INCLUDED_)
#define AFX_EJEROTACIONPAGE_H__B00E0143_0694_11D2_B39A_978473300C33__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EjeRotacionPage.h : header file
//

#include "ParteRigida.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CEjeRotacionPage dialog

class CEjeRotacionPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CEjeRotacionPage)

// Construction
public:
	ParteRigida m_nParteDePagina;

	extern friend CProyectoDoc* GetDoc(void);
	CParteRigida* GetParteRigida(void);
	void EstabControles(void);
	extern friend void RedibujarVista(void);
	CEjeRotacionPage();
	~CEjeRotacionPage();

private:
	void GetComboText(UINT uIdentif, CString &cString);
	void SetEditText(UINT uIdentif, CString cString);
	void SetComboText(UINT uIdentif, CString cString);

// Dialog Data
	//{{AFX_DATA(CEjeRotacionPage)
	enum { IDD = IDD_EJE };
	CStatic	m_cImagen;
	CString	m_strEtiqueta;
	double	m_dValor;
	CString	m_strEstado;
	CString	m_strParametro;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CEjeRotacionPage)
	public:
	virtual void OnOK();
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CEjeRotacionPage)
	afx_msg void OnChangeValor();
	afx_msg void OnSelendokEstado();
	afx_msg void OnSelendokParametro();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void EnableCombo(UINT uIdentif, BOOL bHabilitar);
	void ActuaSegunEstado(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EJEROTACIONPAGE_H__B00E0143_0694_11D2_B39A_978473300C33__INCLUDED_)
