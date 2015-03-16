// Actualizador.h: interface for the CActualizador class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTUALIZADOR_H__970FD781_5578_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_ACTUALIZADOR_H__970FD781_5578_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ProyectoDoc.h"

class CActualizador : public CObject  
{
public:
	void ActualizaRegistroInteraccionesObservadas(CWnd *pParent = NULL);
	void ActualizaRegistroInteraccionesComponentes(CWnd *pParent = NULL);
	void ActualizaRegistroParametrosVariables(void);
	CActualizador();
	virtual ~CActualizador();
	extern friend CProyectoDoc* GetDoc(void);

};

#endif // !defined(AFX_ACTUALIZADOR_H__970FD781_5578_11D2_A5A8_444553540001__INCLUDED_)
