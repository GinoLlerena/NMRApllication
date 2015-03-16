// InteraccObservadaPageOne.h : header file
//

#ifndef __INTERACCOBSERVADAPAGEONE_H__
#define __INTERACCOBSERVADAPAGEONE_H__

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageOne dialog

#include "Resource.h"
#include "ProyectoDoc.h"

class CInteraccObservadaPageOne : public CPropertyPage
{
	DECLARE_DYNCREATE(CInteraccObservadaPageOne)

// Construction
public:
	int DevuelveTotalPolos(void);
	CInteraccObservadaPageOne();
	~CInteraccObservadaPageOne();
	extern friend CProyectoDoc* GetDoc(void);

// Dialog Data
	//{{AFX_DATA(CInteraccObservadaPageOne)
	enum { IDD = IDD_INTERACCOBSERVADAPAGE1 };
	CString	m_strEtiqueta1;
	CString	m_strEtiqueta2;
	double	m_dValorObservado;
	BOOL	m_bUsoTzz;
	BOOL	m_bUsoTxxMinusTyy;
	BOOL	m_bUsoTyz;
	BOOL	m_bUsoTzx;
	BOOL	m_bUsoTxy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CInteraccObservadaPageOne)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CInteraccObservadaPageOne)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelendokEtqtpolo1();
	afx_msg void OnSelendokEtqtpolo2();
	afx_msg void OnChangeValorobservado();
	afx_msg void OnTzz();
	afx_msg void OnTxxminustyy();
	afx_msg void OnTyz();
	afx_msg void OnTzx();
	afx_msg void OnTxy();
	afx_msg void OnNuevo();
	afx_msg void OnGuardar();
	afx_msg void OnEliminar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL InicializaComboBoxes(void);
	int DevuelveUbicacionListaEtiquetas(CString cEtiqueta1, CString cEtiqueta2);
	void ModificaInteraccComponentList(CString cAnteriorEtiqueta1, CString cAnteriorEtiqueta2,
		CString cEtiqueta1, CString cEtiqueta2);
	void EnableButton(UINT uIdentif, BOOL bLogico);
};

#endif // __INTERACCOBSERVADAPAGEONE_H__
