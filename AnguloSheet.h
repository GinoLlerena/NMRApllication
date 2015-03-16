#if !defined(AFX_ANGULOSHEET_H__7A68F479_CDB3_11D1_860D_CB4F165FF450__INCLUDED_)
#define AFX_ANGULOSHEET_H__7A68F479_CDB3_11D1_860D_CB4F165FF450__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AnguloSheet.h : header file
//

#include "AnguloPage.h"
#include "Structures.h"
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////

static char *AngIntAnillofenil[6] = { "FAB",
	"ABC",	"BCD",	"CDE",	"DEF",
	"EFA" };

static char *AngExtAnillofenil[6] = { "FAA'",
	"B'BC",	"BCC'",	"CDD'",	"E'EF",
	"F'FA" };

static char *AngBifenil[1] = { "ABC" };

static char *AngIntTrifenil[3] = { "AOG","BOG","COG" };
static char *AngExtTrifenil[2] = { "AOB","BOC"};

/////////////////////////////////////////////////////////////////////////////
// CAnguloSheet

class CAnguloSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CAnguloSheet)

// Construction
public:
	CAnguloSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CAnguloSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CAnguloPage m_cPagina;
	ParteRigida m_nParte;
	CString *pString;
		
// Operations
public:
	void InicializaDialogo(void);
	void EsAnguloInterno(BOOL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnguloSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAnguloSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAnguloSheet)
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	extern friend CProyectoDoc* GetDoc(void);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANGULOSHEET_H__7A68F479_CDB3_11D1_860D_CB4F165FF450__INCLUDED_)
