// InteraccComponent.h: interface for the CInteraccComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERACCCOMPONENT_H__FFA2A162_5ABE_11D2_A5AA_444553540001__INCLUDED_)
#define AFX_INTERACCCOMPONENT_H__FFA2A162_5ABE_11D2_A5AA_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "InteraccCalculada.h"

class CInteraccComponent : public CInteraccCalculada  
{
	DECLARE_SERIAL(CInteraccComponent)
protected :
	CString m_strEtiquetaBase1;
	CString m_strEtiquetaBase2;	

public:
	 CInteraccComponent(const CInteraccComponent& cInteraccComponente);
	const CInteraccComponent& operator =(const CInteraccComponent & cInteraccComponente);
	CInteraccComponent();
	virtual ~CInteraccComponent();
	void Serialize(CArchive& fichero);

	void EstableceEtiquetaBase1(CString cCadena);
	void EstableceEtiquetaBase2(CString cCadena);
	CString DevuelveEtiquetaBase1(void);
	CString DevuelveEtiquetaBase2(void);
	CString DevuelveEtiquetasBase(void);

};

typedef CTypedPtrList< CObList, CInteraccComponent*> CInteraccComponentList;

#endif // !defined(AFX_INTERACCCOMPONENT_H__FFA2A162_5ABE_11D2_A5AA_444553540001__INCLUDED_)
