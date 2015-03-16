// ValorDual.h: interface for the CValorDual class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VALORDUAL_H__A80BE043_12EF_11D2_B39B_934F7A9469BE__INCLUDED_)
#define AFX_VALORDUAL_H__A80BE043_12EF_11D2_B39B_934F7A9469BE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Structures.h"

class CValorDual : public CObject  
{
	DECLARE_SERIAL(CValorDual)
//	Datos miembros
protected:
	CString m_strEtiqueta1;
	CString m_strEtiqueta2;
	double m_dValor;	

// Funciones miembros
public:
	void Serialize(CArchive & ar);
	// Operators
	const CValorDual& operator =(const CValorDual & cValorDual);

	// Input Data
	void EstableceEtiqueta1(CString cCadena);
	void EstableceEtiqueta2(CString cCadena);
	void EstableceValor(CString cCadena);
	void EstableceValor(double dValor);
	void EstableceConStruct(StcValorDual * stcValDual);

	// Output Data
	CString DevuelveEtiqueta1(void);
	CString DevuelveEtiqueta2(void);
	double DevuelveValor(void);
	CString DevuelveValorAsStr(void);
	StcValorDual DevuelveStruct(void);
	CString DevuelveEtiquetas(void);	
	CString DevuelveEtiquetasInvertidas(void);

	// Construction / Destruction
	CValorDual();
	virtual ~CValorDual();
};

#endif // !defined(AFX_VALORDUAL_H__A80BE043_12EF_11D2_B39B_934F7A9469BE__INCLUDED_)
