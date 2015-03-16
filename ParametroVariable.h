// ParametroVariable.h: interface for the CParametroVariable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAMETROVARIABLE_H__B2F65524_9B1D_11D1_B39B_CAD19E31C574__INCLUDED_)
#define AFX_PARAMETROVARIABLE_H__B2F65524_9B1D_11D1_B39B_CAD19E31C574__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Parametro.h"

class CParametroVariable : public CParametro  
{
	DECLARE_SERIAL(CParametroVariable)

// Datos miembros
protected:
	double m_dValorInicial;
	double m_dValorFinal;
	double m_dIncremento;

//	Funciones miembro
public:
	//	Operators
	const CParametroVariable& operator =(const CParametroVariable & cParamVariab);

	// Operations
	void Serialize(CArchive & archive);

	// Input Data
	void EstableceValorInicial(double dValor);
	void EstableceValorInicial(CString cCadena);
	void EstableceValorFinal(double dValor);
	void EstableceValorFinal(CString cCadena);
	void EstableceIncremento(double dValor);
	void EstableceIncremento(CString cCadena);

	// Output Data
	double DevuelveValorInicial(void);
	CString DevuelveValorInicialAsStr(void);
	double DevuelveValorFinal(void);
	CString DevuelveValorFinalAsStr(void);
	double DevuelveIncremento(void);
	CString DevuelveIncrementoAsStr(void);
	int DevuelveTotalInteracciones(void);

	//	Construction / Destruction
	CParametroVariable();
	virtual ~CParametroVariable();
};

typedef CTypedPtrList< CObList, CParametroVariable*> CParametroVariableList;

#endif // !defined(AFX_PARAMETROVARIABLE_H__B2F65524_9B1D_11D1_B39B_CAD19E31C574__INCLUDED_)
