// Tensor.h: interface for the CTensor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TENSOR_H__A80BE044_12EF_11D2_B39B_934F7A9469BE__INCLUDED_)
#define AFX_TENSOR_H__A80BE044_12EF_11D2_B39B_934F7A9469BE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ValorDual.h"

class CTensor : public CValorDual  
{
//	Funciones miembro
public:
	//	Construction / Destruction
	CTensor();
	virtual ~CTensor();
};

typedef CTypedPtrList< CObList, CTensor*> CTensorList;

#endif // !defined(AFX_TENSOR_H__A80BE044_12EF_11D2_B39B_934F7A9469BE__INCLUDED_)
