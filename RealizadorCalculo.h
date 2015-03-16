// RealizadorCalculo.h: interface for the CRealizadorCalculo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REALIZADORCALCULO_H__FF128462_5431_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_REALIZADORCALCULO_H__FF128462_5431_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include	"ProyectoDoc.h"
#include "ProgressDlg.h"
#include "ConstructorMolecula.h"

class CConstructorMolecula;

class CRealizadorCalculo : public CObject  
{
public :
	CProgressDlg	m_cDlgProgress;
	CConstructorMolecula *m_pConstructorMolecula;
public:
	CRealizadorCalculo();
	virtual ~CRealizadorCalculo();
	void OptimizaInteraccionesCalculadas();
	void InicializaParametros(CParametroVariable *pParamVariab);
	void ProcesoIteractivoDeVariacion(int iIndex);
	void RealizaBarridoDeParametros(CWnd *pParent = NULL);
	void RealizaCombinacionParametro(CWnd *pParent = NULL);
	void IncluyeInteraccionesCalculadas(void);
	void CalculaCoeficientes(void);
	void CalculaTensores(void);
	void EstableceConstructorMolecula(CConstructorMolecula *pConstMol)
	{
		m_pConstructorMolecula = pConstMol;
	}
private :
	CConstructorMolecula* GetConstMol() { return m_pConstructorMolecula;}
	extern friend CProyectoDoc* GetDoc(void);
};

#endif // !defined(AFX_REALIZADORCALCULO_H__FF128462_5431_11D2_A5A8_444553540001__INCLUDED_)
