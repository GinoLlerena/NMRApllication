// Parametro.h: interface for the CParametro class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAMETRO_H__F54BE801_02BE_11D2_B39A_DCFC9CB9D331__INCLUDED_)
#define AFX_PARAMETRO_H__F54BE801_02BE_11D2_B39A_DCFC9CB9D331__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Structures.h"

class CParametro : public CObject  
{
	DECLARE_SERIAL(CParametro)

// Datos miembros
protected:
	CString m_strEtiqueta;
	double m_dValorActual;

//	Funciones miembro
public:
	// Operations
	void Serialize(CArchive & fichero);

	// Input Data
	void EstableceEtiqueta(CString cCadena);
	void EstableceValorActual(double dValor);
	void EstableceValorActual(CString cCadena);
	void EstableceConStruct(StcParametro *stcParametro);

	// Output Data
	CString DevuelveEtiqueta(void);
	double DevuelveValorActual(void);
	CString DevuelveValorActualAsStr(void);
	StcParametro DevuelveStruct(void);

	// Construction / Destruction
	CParametro();
	virtual ~CParametro();
};

typedef CTypedPtrList< CObList, CParametro*> CParametroList;

#endif // !defined(AFX_PARAMETRO_H__F54BE801_02BE_11D2_B39A_DCFC9CB9D331__INCLUDED_)
