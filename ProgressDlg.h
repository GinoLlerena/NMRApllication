// ProgressDlg.h : header file
// CG: This file was added by the Progress Dialog component

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog

#ifndef __PROGRESSDLG_H__
#define __PROGRESSDLG_H__

#include "Resource.h"

class CProgressDlg : public CDialog
{
// Construction / Destruction
public:
	CProgressDlg(UINT nCaptionID = 0);   // standard constructor
	~CProgressDlg();

	BOOL Create(CWnd *pParent = NULL);

	// Checking for Cancel button
	BOOL CheckCancelButton();
	// Progress Dialog manipulation
	void	SetRange(int nLower, int nUpper);
	int	SetStep(int nStep);
	int	SetPos(int nPos);
	int	OffsetPos(int nPos);
	int	StepIt();
        
// Dialog Data
	//{{AFX_DATA(CProgressDlg)
	enum { IDD = IDD_PROGRESS };
	CProgressCtrl m_Progress;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	  // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	UINT m_nCaptionID;
	int m_nLower;
	int m_nUpper;
	int m_nStep;
	BOOL m_bCancel;
	BOOL m_bParentDisabled;

	void ReEnableParent();
	virtual void OnCancel();
	virtual void OnOK() {}; 
	void UpdatePercent(int nCurrent);
	void PumpMessages();

	// Generated message map functions
	//{{AFX_MSG(CProgressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // __PROGRESSDLG_H__