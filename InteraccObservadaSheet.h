// InteraccObservadaSheet.h : header file
//
// This class defines custom modal property sheet 
// CInteraccObservadaSheet.

#ifndef __InteraccObservadaSheet_H__
#define __InteraccObservadaSheet_H__

#include "InteraccObservadaPageOne.h"
#include "InteraccObservadaPageTwo.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaSheet

class CInteraccObservadaSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CInteraccObservadaSheet)

// Construction
public:
	CInteraccObservadaSheet(CWnd* pWndParent = NULL);

// Attributes
private:
	extern friend CProyectoDoc* GetDoc(void);
	CInteraccObservadaPageOne m_cPage1;
	CInteraccObservadaPageTwo m_cPage2;
	int m_iIndiceElegido;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInteraccObservadaSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	int DevuelveTotalPolos(void);
	int DevuelveIndiceElegido(void);
	void EstableceIndiceElegido(int iValor);
	virtual ~CInteraccObservadaSheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CInteraccObservadaSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

#endif	// __InteraccObservadaSheet_H__
