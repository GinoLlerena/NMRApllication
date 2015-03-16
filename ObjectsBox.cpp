// ObjectsBox.cpp : implementation file
//

#include "stdafx.h"
#include <stdlib.h>
#include "ObjectsBox.h"
#include "ProyectoDoc.h"
#include "ProyectoView.h"
#include "Mainfrm.h"
#include "Rutinas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CObjectsBox

CObjectsBox::CObjectsBox()
{
}


CObjectsBox::~CObjectsBox()
{
}

BEGIN_MESSAGE_MAP(CObjectsBox, CComboBox)
	//{{AFX_MSG_MAP(CObjectsBox)
	ON_CONTROL_REFLECT(CBN_SELENDOK, OnSelendok)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CObjectsBox message handlers

void CObjectsBox::OnSelendok() 
{
	CString sTemp;

	ParteRigida nParte;
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	CProyectoView* pView = STATIC_DOWNCAST(CProyectoView, 
		pFrame->GetActiveFrame()->GetActiveView());

	if (GetCurSel() != CB_ERR)
	{
		GetLBText(GetCurSel(), sTemp);

		nParte = DevuelveIdParteRigida(sTemp);
		EstableceParametros(nParte, GetCurSel());

		pView->Invalidate(TRUE);
	}
}

void CObjectsBox::Serialize(CArchive& ar) 
{
	CString strTemp;
	int Tot, actual, i=0;
	if (ar.IsStoring())
	{	Tot = GetCount();
		ar << Tot;
		ar << GetCurSel();
		for(i=0; i< Tot; i++) {
			GetLBText(i, strTemp);
			ar << strTemp;
		}
	}
	else
	{	ar >> Tot;
		ar >> actual;
		for(i=0; i< Tot; i++) {
			ar >> strTemp;
			AddString(strTemp);
		}
		SetCurSel(actual);
	}
}

