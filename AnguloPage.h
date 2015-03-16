#if !defined(AFX_ANGULOPAGE_H__8D2FBB1D_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
#define AFX_ANGULOPAGE_H__8D2FBB1D_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 
// _MSC_VER >= 1000
// AnguloPage.h : header file
//

#include "ParteRigida.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CAnguloPage dialog

class CParteRigida;

class CAnguloPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CAnguloPage)

// Construction
public:
	CAnguloPage();
	~CAnguloPage();
	CParteRigida* GetParteRigida();
	BOOL m_bEsInterno;

// Funciones
public:
	void EstableceControles(void);
	extern friend void RedibujarVista(void);

private:
	void GetComboText(UINT uIdentif, CString &cString);
	void SetEditText(UINT uIdentif, CString cString);
	void SetComboText(UINT uIdentif, CString cString);
	void ActuaSegunEstado(void);

public:
	void EnableCombo(UINT uIdentif, BOOL bHabilitar);
	extern friend CProyectoDoc* GetDoc(void);
// Dialog Data
	//{{AFX_DATA(CAnguloPage)
	enum { IDD = IDD_ANGULO };
	CStatic	m_cImagen;
	double	m_dValor;
	CString	m_strEstado;
	CString	m_strParametro;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAnguloPage)
	public:
	virtual void OnOK();
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAnguloPage)
	afx_msg void OnSelendokAngElegido();
	afx_msg void OnChangeValor();
	afx_msg void OnSelendokEstado();
	afx_msg void OnSelendokParametro();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANGULOPAGE_H__8D2FBB1D_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
