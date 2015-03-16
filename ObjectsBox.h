#if !defined(AFX_OBJECTSBOX_H__50277B93_CC24_11D1_85F9_B6D022AF2350__INCLUDED_)
#define AFX_OBJECTSBOX_H__50277B93_CC24_11D1_85F9_B6D022AF2350__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ObjectsBox.h : header file
//

#include "Structures.h"

/////////////////////////////////////////////////////////////////////////////
// CObjectsBox window

class CObjectsBox : public CComboBox
{
// Construction
public:
	CObjectsBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CObjectsBox)
	public:
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CObjectsBox();
	extern friend void EstableceParametros(ParteRigida , int );
		// Generated message map functions
protected:
	//{{AFX_MSG(CObjectsBox)
	afx_msg void OnSelendok();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OBJECTSBOX_H__50277B93_CC24_11D1_85F9_B6D022AF2350__INCLUDED_)
