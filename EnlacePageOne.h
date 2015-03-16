#if !defined(AFX_ENLACEPAGEONE_H__6F046CA8_0A2E_11D2_B39A_D414BC408033__INCLUDED_)
#define AFX_ENLACEPAGEONE_H__6F046CA8_0A2E_11D2_B39A_D414BC408033__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EnlacePageOne.h : header file
//

#include "ParteRigida.h"
#include "ProyectoDoc.h"
#include "Structures.h"

/////////////////////////////////////////////////////////////////////////////

static char *EnlaceAnillofenil[6] = { "AA'",	"BB'", "CC'", "DD'", "EE'", "FF'" };
static char *EnlaceBifenil[2] = { "AB", "BC" };
static char *EnlaceTrifenil[4] = { "OA", "OB", "OC", "DO" };

/////////////////////////////////////////////////////////////////////////////
// CEnlacePageOne dialog

class CEnlacePageOne : public CPropertyPage
{
	DECLARE_DYNCREATE(CEnlacePageOne)

// Construction
public:
	void SetEditText(UINT uIdentif, CString cString);
	int DevuelveMaxIndiceMolecula();
	void PerteneceA(ParteRigida nParteRigida);
	BOOL SiEsDeAnilloFenil(void);
	extern friend void RedibujarVista(void);
	extern friend CProyectoDoc* GetDoc(void);
	void EsDeAnilloFenil(BOOL bBandera);
	CEnlacePageOne();
	~CEnlacePageOne();

// Dialog Data
	//{{AFX_DATA(CEnlacePageOne)
	enum { IDD = IDD_ENLACEPAGE1 };
	CStatic	m_cImagen;
	CString	m_strEnlace;
	double	m_dLongitud;
	CString	m_strEstado;
	CString	m_strTipo;
	CString	m_strEtiqueta;
	CString	m_strEtqtParametro;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CEnlacePageOne)
	public:
	virtual BOOL OnSetActive();
	virtual void OnOK();
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CEnlacePageOne)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelendokEnlaceElegido();
	afx_msg void OnChangeLongitud();
	afx_msg void OnSelendokEstado();
	afx_msg void OnSelendokTipo();
	afx_msg void OnChangeEtiqueta();
	afx_msg void OnSelendokEtqtparam();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bEsDeAnilloFenil;
	ParteRigida m_nParteDePagina;

private:
	void EnableCombo(UINT uIdentif, BOOL bBandera);
	void HabilitaControles(int iIndiceActual);
	void InicializaControles(int iIndiceActual);
	void EnableEdit(UINT uIdentif, BOOL bBandera);
	CParteRigida* DevuelveParteRigida(void);
	void GetComboText(UINT uIdentif, CString &cString);
	void ActualizaEnlaces(int iIndiceActual);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENLACEPAGEONE_H__6F046CA8_0A2E_11D2_B39A_D414BC408033__INCLUDED_)
