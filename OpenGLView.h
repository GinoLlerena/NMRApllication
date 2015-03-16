// OpenGLView.h : interface of the COpenGLView class
//
/////////////////////////////////////////////////////////////////////////////
#ifndef _OpenGLView_H
#define _OpenGLView_H

#include "gl\gl.h"
#include "gl\glu.h"
#include "ParteRigida.h"
#include "Structures.h"
#include "ProyectoDoc.h"

class COpenGLView : public CView
{
private:
	CRect m_rectPrint;
public: // changed from protected
	COpenGLView();
	DECLARE_DYNCREATE(COpenGLView)

// Attributes
public:
	CProyectoDoc*	GetDocument();
	CPalette    m_cPalette;
   CPalette*	m_pOldPalette;
	CRect		m_oldRect;
	CClientDC*	m_pDC;
	float		m_fCoordEnZeta;
	float		m_fAspect;
	float		m_fRotacionEnEquis;
	float		m_fRotacionEnYe;
	float		m_fRotacionEnZeta;
	float		m_fValorEnEquis;
	float		m_fValorEnYe;
	float		m_fValorEnZeta;
	float		m_fCaraFrontal;
	float		m_fCaraPosterior;
	float		m_fAngPerspectiva;
	float		m_fZoom;
	BOOL		m_bEjeX;
	BOOL		m_bEjeY;
	BOOL		m_bEjeZ;
	BOOL		m_bVerEjes;
	BOOL		m_bEjecutar;

// Operations
public:
	void Init();
	void CreateRGBPalette(void);
	BOOL bSetupPixelFormat(void);
	unsigned char ComponentFromIndex(int i, UINT nbits, UINT shift);
	void DrawScene(void);
	void ViewAxisEquis(void);
	void ViewAxisYe(void);
	void ViewAxisZeta(void);
	void ActualizaPerspectiva(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenGLView();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLView)
	afx_msg void OnDatos3D(void);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnViewAxis(void);
	afx_msg void OnUpdateViewAxis(CCmdUI* pCmdUI);
	afx_msg void OnAxisX(void);
	afx_msg void OnUpdateAxisX(CCmdUI* pCmdUI);
	afx_msg void OnAxisY(void);
	afx_msg void OnUpdateAxisY(CCmdUI* pCmdUI);
	afx_msg void OnAxisZ(void);
	afx_msg void OnUpdateAxisZ(CCmdUI* pCmdUI);
	afx_msg void OnRotatePositive(void);
	afx_msg void OnRotateNegative(void);
	afx_msg void OnApproach(void);
	afx_msg void OnSeparate(void);
	afx_msg void OnVerBarra3D();
	afx_msg void OnUpdateVerBarra3D(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void On3dEjecutar();
	afx_msg void OnUpdate3dEjecutar(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HexView.cpp
inline CProyectoDoc* COpenGLView::GetDocument()
   { return (CProyectoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

#endif
