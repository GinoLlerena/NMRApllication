// Proyecto.h : main header file for the PROYECTO application
//

#if !defined(AFX_PROYECTO_H__8D2FBB0D_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
#define AFX_PROYECTO_H__8D2FBB0D_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProyectoApp:
// See Proyecto.cpp for the implementation of this class
//

class CProyectoApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CProyectoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProyectoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation

	//{{AFX_MSG(CProyectoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROYECTO_H__8D2FBB0D_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
