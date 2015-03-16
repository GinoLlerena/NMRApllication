// MainBar.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1997 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "Resource.h"
#include "MainBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define COMBOBOX_INDEX 11
#define COMBOBOX_WIDTH 150
#define COMBOBOX_HEIGHT 150
#define COMBOBOX_BITMAP 8


static UINT BASED_CODE ObjectsButtons[] =
{
	// same order as in the bitmap 'mainfrm.bmp'
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
		ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
		ID_SEPARATOR,
	ID_FILE_PRINT,
	ID_APP_ABOUT,
		ID_SEPARATOR,
	ID_OBJECTS_FIND,
		ID_SEPARATOR,
	ID_VER_CUADRICULA,
};

/////////////////////////////////////////////////////////////////////////////
// CMainBar

CMainBar::CMainBar()
{
}

CMainBar::~CMainBar()
{
}

BOOL CMainBar::Init(CWnd* pParentWnd, BOOL bToolTips)
{
	m_bVertical = FALSE;

	// start out with no borders
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_SIZE_DYNAMIC;

	if (bToolTips)
		dwStyle |= (CBRS_TOOLTIPS | CBRS_FLYBY);
	
	if (!Create(pParentWnd, dwStyle))
	{
		return FALSE;
	}

	LoadBitmap(IDB_MAINFRAMEBAR);

	if(!SetButtons(ObjectsButtons, sizeof(ObjectsButtons) / sizeof(UINT)))
		return FALSE;

	CRect rect(-COMBOBOX_WIDTH, -COMBOBOX_HEIGHT, 0, 0);
	// The ID of the ComboBox is important for two reasons.  One, so you
	// can receive notifications from the control.  And also for ToolTips.
	// During HitTesting if the ToolBar sees that the mouse is one a child
	// control, the toolbar will lookup the controls ID and search for a
	// string in the string table with the same ID to use for ToolTips
	// and StatusBar info.
	if (!m_ObjectsBox.Create(WS_CHILD | CBS_DROPDOWN |
		CBS_AUTOHSCROLL | WS_VSCROLL | CBS_HASSTRINGS, rect, this,
		IDC_MAINBAR_BOX))
	{
		return FALSE;
	}

	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	if (hFont == NULL)
		hFont = (HFONT)GetStockObject(ANSI_VAR_FONT);

	m_ObjectsBox.SendMessage(WM_SETFONT, (WPARAM)hFont);

	if (!SetHorizontal())
		return FALSE;

	return TRUE;
}

BOOL CMainBar::SetHorizontal()
{
	m_bVertical = FALSE;

	SetBarStyle(GetBarStyle() | CBRS_ALIGN_TOP);
	SetButtonInfo(COMBOBOX_INDEX, IDC_MAINBAR_BOX, TBBS_SEPARATOR, COMBOBOX_WIDTH);

	if (m_ObjectsBox.m_hWnd != NULL)
	{
		CRect rect;

		GetItemRect(COMBOBOX_INDEX, rect);
		m_ObjectsBox.SetWindowPos(NULL, rect.left, rect.top, 0, 0, SWP_NOZORDER | 
			SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOCOPYBITS);
		m_ObjectsBox.ShowWindow(SW_SHOW);
	}
	
	return TRUE;
}

BOOL CMainBar::SetVertical()
{
	m_bVertical = TRUE;
	SetButtonInfo(COMBOBOX_INDEX, ID_OBJECTS_FIND, TBBS_BUTTON, COMBOBOX_BITMAP);

	if (m_ObjectsBox.m_hWnd != NULL)
		m_ObjectsBox.ShowWindow(SW_HIDE);

	return TRUE;
}

CSize CMainBar::CalcDynamicLayout(int nLength, DWORD dwMode)
{
	// if we're committing set the buttons appropriately
	if (dwMode & LM_COMMIT)
	{
		if (dwMode & LM_VERTDOCK)
		{
			if (!m_bVertical)
				SetVertical();
		}
		else
		{
			if (m_bVertical)
				SetHorizontal();
		}

		return CToolBar::CalcDynamicLayout(nLength, dwMode);
	}
	else
	{
		BOOL bOld = m_bVertical;
		BOOL bSwitch = (dwMode & LM_HORZ) ? bOld : !bOld;

		if (bSwitch)
		{
			if (bOld)
				SetHorizontal();
			else
				SetVertical();
		}

		CSize sizeResult = CToolBar::CalcDynamicLayout(nLength, dwMode);
		
		if (bSwitch)
		{
			if (bOld)
				SetHorizontal();
			else
				SetVertical();
		}

		return sizeResult;
	}
}

BEGIN_MESSAGE_MAP(CMainBar, CToolBar)
	//{{AFX_MSG_MAP(CMainBar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMainBar message handlers
