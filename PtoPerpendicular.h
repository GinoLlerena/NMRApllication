// PtoPerpendicular.h: interface for the CPtoPerpendicular class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PTOPERPENDICULAR_H__33262561_4A76_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_PTOPERPENDICULAR_H__33262561_4A76_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Punto3d.h"

class CPtoPerpendicular : public CObject  
{
// Datos miembro
protected:
	CPunto m_cEjeRotacion;
	CPunto m_cPtoA;
	CPunto m_cPtoB;
	CPunto m_cPtoC;
	CPunto m_cPtoPerpendicular;
	double m_dRadio;

// Funciones miembro
private :
	// Operations
	void ObtienePtoPerpendicular(int);
	int ObtienePosicionEspacial(void);

public:
	// Input Data
	void EstablecePtoPerpendicular(CPunto ptoA, CPunto ptoB, CPunto ptoC, double dRadio);
	void EstablecePtoPerpendicular(CPunto ptoA, CPunto ptoB, CPunto ptoC);

	// Output Data
	CPunto DevuelvePtoPerpendicular(void);
	CPunto DevuelveEjeRotacion(void);

	// Construction / Destruction
	CPtoPerpendicular();
	CPtoPerpendicular(CPunto, CPunto, CPunto, double);
	virtual ~CPtoPerpendicular();
};

#endif // !defined(AFX_PTOPERPENDICULAR_H__33262561_4A76_11D2_A5A8_444553540001__INCLUDED_)
