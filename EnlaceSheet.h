// EnlaceSheet.h : header file
//
// This class defines custom modal property sheet 
// CEnlaceSheet.
 
#ifndef __ENLACESHEET_H__
#define __ENLACESHEET_H__

#include "EnlacePageOne.h"
#include "EnlacePageTwo.h"
#include "EnlacePageThree.h"
/////////////////////////////////////////////////////////////////////////////
// CEnlaceSheet

class CEnlaceSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CEnlaceSheet)

// Construction
public:
	CEnlaceSheet(CWnd* pWndParent = NULL);

// Attributes
public:
	CEnlacePageOne m_cPaginaOne;
	CEnlacePageTwo m_cPaginaTwo;
	CEnlacePageThree m_cPaginaThree;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnlaceSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	CString DevuelveEnlace(void);
	void EstableceEnlace(CString cStrEtiqueta);
	void PerteneceA(ParteRigida nParteRigida);
	BOOL SiEsDeAnilloFenil(void);
	void EsDeAnilloFenil(BOOL bBandera);
	int DevuelveIndiceElegido(void);
	void EstableceIndiceElegido(int iIndice);
	virtual ~CEnlaceSheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CEnlaceSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int m_iIndiceElegido;
	CString m_strEnlaceActual;
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __ENLACESHEET_H__
