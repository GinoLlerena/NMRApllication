// InteraccObservada.h: interface for the CInteraccObservada class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERACCOBSERVADA_H__B753DAE2_1316_11D2_B39B_86B536374D36__INCLUDED_)
#define AFX_INTERACCOBSERVADA_H__B753DAE2_1316_11D2_B39B_86B536374D36__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Interaccion.h"

class CInteraccObservada : public CInteraccion  
{
	DECLARE_SERIAL(CInteraccObservada)

// Datos miembros
protected:
	BOOL m_bUsoTzz;
	BOOL m_bUsoTxxMinusTyy;
	BOOL m_bUsoTyz;
	BOOL m_bUsoTzx;
	BOOL m_bUsoTxy;

// Funciones miembro
public:
	// Operators
	const CInteraccObservada& operator =(const CInteraccObservada & cInteraccObs);

	// Operations
	void Serialize(CArchive & fichero);

	// Input Data
	void EstableceUsoTzz(BOOL bLogico);
	void EstableceUsoTxxMinusTyy(BOOL bLogico);
	void EstableceUsoTyz(BOOL bLogico);
	void EstableceUsoTzx(BOOL bLogico);
	void EstableceUsoTxy(BOOL bLogico);
	
	// Output Data
	BOOL DevuelveUsoTzz(void);
	BOOL DevuelveUsoTxxMinusTyy(void);
	BOOL DevuelveUsoTyz(void);
	BOOL DevuelveUsoTzx(void);
	BOOL DevuelveUsoTxy(void);	
	
	// Construction / Destruction
	CInteraccObservada();
	CInteraccObservada(const CInteraccObservada& cInteraccObs);
	virtual ~CInteraccObservada();
};

typedef CTypedPtrList< CObList, CInteraccObservada*> CInteraccObservadaList;

#endif // !defined(AFX_INTERACCOBSERVADA_H__B753DAE2_1316_11D2_B39B_86B536374D36__INCLUDED_)
