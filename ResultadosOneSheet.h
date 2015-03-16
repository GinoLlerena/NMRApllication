// ResultadosOneSheet.h : header file
//
// This class defines custom modal property sheet 
// CResultadosOneSheet.
 
#ifndef __ResultadosOneSheet_H__
#define __ResultadosOneSheet_H__

#include "ResultadosOnePageOne.h"
#include "ResultadosOnePageTwo.h"
#include "ResultadosOnePageThree.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CResultadosOneSheet

class CResultadosOneSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CResultadosOneSheet)

// Construction
public:
	CResultadosOneSheet(CWnd* pWndParent = NULL);

// Attributes
private:
	extern friend CProyectoDoc* GetDoc(void);
	CResultadosOnePageOne	m_cPage1;
	CResultadosOnePageTwo	m_cPage2;
	CResultadosOnePageThree	m_cPage3;
	int m_iIndiceElegido;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResultadosOneSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	int DevuelveIndiceElegido(void);
	void EstableceIndiceElegido(int iIndice);
	virtual ~CResultadosOneSheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CResultadosOneSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __ResultadosOneSheet_H__
