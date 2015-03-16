// Angulo.h: interface for the CAngulo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANGULO_H__0365D241_2C0C_11D2_A5A8_907704C10000__INCLUDED_)
#define AFX_ANGULO_H__0365D241_2C0C_11D2_A5A8_907704C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Structures.h"

class CAngulo : public CObject  
{
	DECLARE_SERIAL(CAngulo)

// Datos miembro
protected:
	double m_dValor;
	CString m_strEstado;
	CString m_strEtiqueta;
		
// Funciones miembro
public:
	// Operators
	const CAngulo& operator =(const CAngulo & cAngulo);

	// Operations
	void Serialize(CArchive & fichero);

	// Input Data
	void EstableceValor(double dValor, Medida nUnidad = Grados);
	void EstableceEstado(CString cCadena);
	void EstableceEtiqueta(CString cCadena);

	// Output Data
	double DevuelveValor(Medida nUnidad);
	CString DevuelveEstado(void);
	CString DevuelveEtiqueta(void);

	// Construction / Destruction
	CAngulo();
	CAngulo(double dValor);
	CAngulo(const CAngulo & cAngulo);
	virtual ~CAngulo();
};

typedef CTypedPtrList< CObList, CAngulo*> CAnguloList;

#endif // !defined(AFX_ANGULO_H__0365D241_2C0C_11D2_A5A8_907704C10000__INCLUDED_)
