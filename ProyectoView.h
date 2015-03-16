// ProyectoView.h : interface of the CProyectoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROYECTOVIEW_H__8D2FBB15_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
#define AFX_PROYECTOVIEW_H__8D2FBB15_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Structures.h"
#include "ProyectoDoc.h"
#include "Punto3D.h"
#include "MainBar.h"
#include "RealizadorReporte.h"
#include "ConstructorMolecula.h"
#include "RealizadorCalculo.h"
#include "Actualizador.h"

class CProyectoView : public CView
{
private:
	CRect				m_rectPrint;
public :
	CRealizadorReporte m_cRealizadorReporte;
	CConstructorMolecula m_cConstructorMolecula;
	CRealizadorCalculo m_cRealizadorCalculo;
	CActualizador m_cActualizador;

public: // changed from protected
	CProyectoView();
	DECLARE_DYNCREATE(CProyectoView)

// Attributes
public:

	CProyectoDoc	*GetDocument();
	BOOL				m_bCaptured;
	int				m_iIndiceArrastre;
	
// Operations
public:
	BOOL VerificaCondiciones(void);
	
private:
	void ReportaInformacion();
	double DevuelveRadioParteRigida(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProyectoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ProcesaResultados(BOOL bBandera);
	virtual ~CProyectoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void DrawGrid(CDC* pDC);

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProyectoView)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnInsertarPartesrigidasAnillofenil();
	afx_msg void OnInsertarPartesrigidasBifenil();
	afx_msg void OnInsertarPartesrigidasTrifenil();
	afx_msg void OnViewGrid();
	afx_msg void OnUpdateViewGrid(CCmdUI* pCmdUI);
	afx_msg void OnViewListapartesrigidas();
	afx_msg void OnAnillofenilAngulosExternos();
	afx_msg void OnAnillofenilAngulosInternos();
	afx_msg void OnAnillofenilInformacion();
	afx_msg void OnAnillofenilLadosExternos();
	afx_msg void OnAnillofenilLadosInternos();
	afx_msg void OnTrifenilInformacion();
	afx_msg void OnTrifenilLados();
	afx_msg void OnBifenilAngulos();
	afx_msg void OnBifenilInformacion();
	afx_msg void OnBifenilLados();
	afx_msg void OnAnillofenilEjerotacion();
	afx_msg void OnBifenilEjerotacion();
	afx_msg void OnTrifenilEjerotacion();
	afx_msg void OnInteracobs();
	afx_msg void OnSistecuac();
	afx_msg void OnVerPartesbar();
	afx_msg void OnUpdateVerPartesbar(CCmdUI* pCmdUI);
	afx_msg void OnInteraccomp();
	afx_msg void OnParametros();
	afx_msg void OnVerResults();
	afx_msg void OnVerUnoporuno();
	afx_msg void OnVerBarraprincipal();
	afx_msg void OnUpdateVerBarraprincipal(CCmdUI* pCmdUI);
	afx_msg void OnInsertarInteraccionesdedistorcion();
	afx_msg void OnOpcionesPreferencias();
	afx_msg void OnArchivoPropiedades();
	afx_msg void OnOpcionesReportesConformac();
	afx_msg void OnOpcionesReportesResultsxmad();
	afx_msg void OnTrifenilAngulosAngulosalejedeproyeccion();
	afx_msg void OnTrifenilAngulosAngulosentreloslados();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnOpcionesReportesResultsxerror();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ProyectoView.cpp
inline CProyectoDoc* CProyectoView::GetDocument()
   { return (CProyectoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROYECTOVIEW_H__8D2FBB15_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
