#if !defined(AFX_PARAMETROVARIABLEPAGEONE_H__386CB249_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
#define AFX_PARAMETROVARIABLEPAGEONE_H__386CB249_0517_11D2_B39A_8831FB889C3E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ParametroVariablePageOne.h : header file
//

#include "Resource.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CParametroVariablePageOne dialog

class CParametroVariablePageOne : public CPropertyPage
{
	DECLARE_DYNCREATE(CParametroVariablePageOne)

// Construction
public:
	CParametroVariablePageOne();
	~CParametroVariablePageOne();

// Dialog Data
	//{{AFX_DATA(CParametroVariablePageOne)
	enum { IDD = IDD_PARAMVARIABLEPAGE1 };
	CString	m_strEtiqueta;
	double	m_dValorInicial;
	double	m_dValorFinal;
	double	m_dIncremento;	
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParametroVariablePageOne)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CProyectoDoc* GetDoc(void);

	// Generated message map functions
	//{{AFX_MSG(CParametroVariablePageOne)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEtqt();
	afx_msg void OnChangeInicio();
	afx_msg void OnChangeFin();
	afx_msg void OnChangeIncremento();
	afx_msg void OnNuevo();
	afx_msg void OnGuardar();
	afx_msg void OnEliminar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void EnableButton(UINT uIdentif, BOOL bLogico);
	int DevuelveUbicacionListaEtiqueta(CString cEtiqueta);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETROVARIABLEPAGEONE_H__386CB249_0517_11D2_B39A_8831FB889C3E__INCLUDED_)
