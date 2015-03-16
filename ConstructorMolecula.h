// ConstructorMolecula.h: interface for the CConstructorMolecula class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONSTRUCTORMOLECULA_H__FF128461_5431_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_CONSTRUCTORMOLECULA_H__FF128461_5431_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 
#include "Structures.h"
#include "ProyectoDoc.h"

class CConstructorMolecula : public CObject  
{
public:
	void EliminaParteRigida(int iPos, ParteRigida nParte);
	CConstructorMolecula();
	virtual ~CConstructorMolecula();
	BOOL InsertaParteRigida(ParteRigida nParte);
	BOOL VerificaCondicionesDeInsercion(void);
	void IncluyeParteRigida(void);
	double DevuelveRadioParteRigida(void);
	void ReconstruyeMolecula(void);
private :
	void ActualizaContadores(ParteRigida nParte);
	extern friend CProyectoDoc* GetDoc(void);
};

#endif // !defined(AFX_CONSTRUCTORMOLECULA_H__FF128461_5431_11D2_A5A8_444553540001__INCLUDED_)
