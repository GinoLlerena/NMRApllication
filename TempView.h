#if !defined(AFX_TEMPVIEW_H__9B634783_1BAE_11D2_B39C_E74415D12798__INCLUDED_)
#define AFX_TEMPVIEW_H__9B634783_1BAE_11D2_B39C_E74415D12798__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TempView.h : header file
//
#include "ProyectoDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CTempView view
#include "RealizadorReporte.h"

class CTempView : public CScrollView
{
public:
	CTempView();           // protected constructor used by dynamic creation
	CRealizadorReporte m_cRealizadorReporte;
	DECLARE_DYNCREATE(CTempView)

// Attributes
public:
	CProyectoDoc	*GetDocument();
	int m_iPage;
	int m_iTotalPage;
// Operations
public:
	void SwitchToGDI();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTempView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTempView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTempView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void PrintPageFooter(CDC *pDC, int iPage);
};

#ifndef _DEBUG  // debug version in ProyectoView.cpp
inline CProyectoDoc* CTempView::GetDocument()
   { return (CProyectoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEMPVIEW_H__9B634783_1BAE_11D2_B39C_E74415D12798__INCLUDED_)
