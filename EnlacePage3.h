#if !defined(AFX_ENLACEPAGE3_H__ACEF7761_2218_11D2_A5A6_D47704C10000__INCLUDED_)
#define AFX_ENLACEPAGE3_H__ACEF7761_2218_11D2_A5A6_D47704C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EnlacePage3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnlacePage3 dialog

class CEnlacePage3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CEnlacePage3)

// Construction
public:
	CEnlacePage3();
	~CEnlacePage3();

// Dialog Data
	//{{AFX_DATA(CEnlacePage3)
	enum { IDD = IDD_ENLACEPAGE3 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CEnlacePage3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CEnlacePage3)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENLACEPAGE3_H__ACEF7761_2218_11D2_A5A6_D47704C10000__INCLUDED_)
