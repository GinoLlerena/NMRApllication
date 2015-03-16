// 3DToolBar.h : interface of the C3DToolBar class
//
/////////////////////////////////////////////////////////////////////////////
#ifndef _3DToolBar_H
#define _3DToolBar_H

class C3DToolBar : public CToolBar
{
public:
	C3DToolBar();

// Attributes
public:

//	Implementation
public:
	virtual ~C3DToolBar();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(C3DToolBar)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#endif
