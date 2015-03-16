// CoordEsf.h: interface for the CCoordEsf class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDESF_H__6AA62F82_2EB5_11D2_A5A8_907704C10000__INCLUDED_)
#define AFX_COORDESF_H__6AA62F82_2EB5_11D2_A5A8_907704C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Punto3D.h"
#include "Angulo.h"

class CCoordEsf : public CObject
{
// Datos miembros
protected:
	CAngulo m_cAnguloPhi;
	CAngulo m_cAnguloTeta;
	double m_dDistancia;

// Funciones miembro
public:
	// Operators
	const CCoordEsf& operator =(const CCoordEsf & cCoord);

	// Input Data
	void Establece(CPunto cPto);
	void Establece(CPunto cPtoInicial, CPunto cPtoFinal);

	// Output Data
	CAngulo DevuelveAnguloPhi(void);
	CAngulo DevuelveAnguloTeta(void);
	double DevuelveDistancia(void);

	// Construction / Destruction
	CCoordEsf();
	CCoordEsf(CPunto cPtoInicial, CPunto cPtoFinal);
	virtual ~CCoordEsf();
};

#endif // !defined(AFX_COORDESF_H__6AA62F82_2EB5_11D2_A5A8_907704C10000__INCLUDED_)
