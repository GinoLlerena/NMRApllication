// InteraccObservadaPageTwo.h : header file
//

#ifndef __INTERACCOBSERVADAPAGETWO_H__
#define __INTERACCOBSERVADAPAGETWO_H__

/////////////////////////////////////////////////////////////////////////////
// CInteraccObservadaPageTwo dialog

#include "Resource.h"
#include "ProyectoDoc.h"

class CInteraccObservadaPageTwo : public CPropertyPage
{
	DECLARE_DYNCREATE(CInteraccObservadaPageTwo)

// Construction
public:
	CInteraccObservadaPageTwo();
	~CInteraccObservadaPageTwo();
	extern friend CProyectoDoc* GetDoc(void);

private:
	CImageList *m_cImageListPtr;

// Dialog Data
	//{{AFX_DATA(CInteraccObservadaPageTwo)
	enum { IDD = IDD_INTERACCOBSERVADAPAGE2 };
	CListCtrl	m_cReportList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CInteraccObservadaPageTwo)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CInteraccObservadaPageTwo)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickLcreport(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif // __INTERACCOBSERVADAPAGETWO_H__
