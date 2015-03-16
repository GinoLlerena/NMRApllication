// ParametroSheet.h : header file
//
// This class defines custom modal property sheet 
// CParametroSheet.
 
#ifndef __ParametroSheet_H__
#define __ParametroSheet_H__

#include "ParametroPageOne.h"
#include "ParametroPageTwo.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CParametroSheet

class CParametroSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CParametroSheet)

// Construction
public:
	CParametroSheet(CWnd* pWndParent = NULL);

// Attributes
private:
	extern friend CProyectoDoc* GetDoc(void);
	CParametroPageOne m_cPage1;
	CParametroPageTwo m_cPage2;
	int m_iIndiceElegido;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParametroSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	int DevuelveIndiceElegido(void);
	void EstableceIndiceElegido(int iIndice);
	virtual ~CParametroSheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CParametroSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __ParametroSheet_H__
