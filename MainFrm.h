// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__8D2FBB11_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
#define AFX_MAINFRM_H__8D2FBB11_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "3DToolBar.h"
#include "MainBar.h"
#include "IconosDlgBar.h"

enum eView {GDI = 1, OPENGL = 2, TEMP = 3 };

class CMainFrame : public CFrameWnd
{
public:
	void SwitchToView(eView nView);

public: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	BOOL m_bToolTips;
	BOOL m_bVerModo3DBar;
	BOOL m_bVerMainBar;
	BOOL m_bVerPartesBar;
	C3DToolBar m_wnd3DToolBar;
	CMainBar m_wndMainBar;
	CIconosDlgBar m_wndIconosDlgBar;	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:	
	
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // control bar embedded members
	CStatusBar  m_wndStatusBar;

// Generated message map functions
protected:
	//CDialogBar m_wndPartesDlgBar;
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewGDIview();
	afx_msg void OnViewOpenGLview();
	afx_msg void OnUpdateViewOpenGLview(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewGDIview(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__8D2FBB11_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
