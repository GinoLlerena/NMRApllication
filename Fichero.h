// Fichero.h: interface for the CFichero class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FICHERO_H__F83BF084_11BB_11D2_B39B_9077C2B59131__INCLUDED_)
#define AFX_FICHERO_H__F83BF084_11BB_11D2_B39B_9077C2B59131__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CFichero : public CFile  
{
//	Funciones miembro
public:
	// Operations
	BOOL Abre(CString cStrFileName, UINT uAbrirFlags);
	void Escribe(const char* lpBuffer, UINT uBytes);
	void Lee(char *lpBuf, unsigned long ulPosicion, UINT uBytes);
	BOOL AbreConDlg(CString cStrFileName);

	// Construction / Destruction
	CFichero();
	virtual ~CFichero();
};

#endif // !defined(AFX_FICHERO_H__F83BF084_11BB_11D2_B39B_9077C2B59131__INCLUDED_)
