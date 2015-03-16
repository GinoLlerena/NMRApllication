// ParametroVariableSheet.h : header file
//
// This class defines custom modal property sheet 
// CParametroVariableSheet.
 
#ifndef __ParametroVariableSheet_H__
#define __ParametroVariableSheet_H__

#include "ParametroVariablePageOne.h"
#include "ParametroVariablePageTwo.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CParametroVariableSheet

class CParametroVariableSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CParametroVariableSheet)

// Construction
public:
	CParametroVariableSheet(CWnd* pWndParent = NULL);

// Attributes
private:
	extern friend CProyectoDoc* GetDoc(void);
	CParametroVariablePageOne m_cPage1;
	CParametroVariablePageTwo m_cPage2;
	int m_iIndiceElegido;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParametroVariableSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	int DevuelveIndiceElegido(void);
	void EstableceIndiceElegido(int iIndice);
	virtual ~CParametroVariableSheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CParametroVariableSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __ParametroVariableSheet_H__
