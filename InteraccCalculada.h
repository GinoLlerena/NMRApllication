// InteraccCalculada.h: interface for the CInteraccCalculada class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERACCCALCULADA_H__B753DAE3_1316_11D2_B39B_86B536374D36__INCLUDED_)
#define AFX_INTERACCCALCULADA_H__B753DAE3_1316_11D2_B39B_86B536374D36__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Interaccion.h"
#include "CoordEsf.h"
#include "Structures.h"
#define	limCoeff		5

class CInteraccCalculada: public CInteraccion
{
	DECLARE_SERIAL(CInteraccCalculada)

//	Datos miembros
protected:
	CCoordEsf m_cCoordEsf;
	double m_dCoefficient[limCoeff];

//	Funciones miembro
public:
	// Operators
	const CInteraccCalculada& operator =(const CInteraccCalculada & cInteraccCalculada);

	// Operations
	void Serialize(CArchive& fichero);
	void CalculaCoeficientesIndependientes(double dConstante);
	void CalculaCoeficientesParaD2(double dConstante);
	void CalculaCoeficientesParaD4(double dConstante, double dAnguloDihedral);
	void EstableceCoeficientes(CPunto cPtoInicial, CPunto cPtoFinal, CString cTipoPtoInicial,
		CString cTipoPtoFinal, double dAnguloDihedral, Simetria nSimetria);
	//void CalculaCoeficientesSinDistorcion(double);

	// Input Data
	void EstableceCoefficiente(int iIndice, double dValor);

	// Output Data
	CCoordEsf & DevuelveCoordEsf(void);
	double DevuelveCoefficient(int iIndice);
	
	double DevuelveValorCalculado(double dTzz = 0, double dTxxTyy = 0, double dTyz = 0,
		double dTzx = 0, double dTxy = 0);
	double DevuelveConstante(CString cTipo1, CString cTipo2);

	// Construction / Destruction
	CInteraccCalculada();
	CInteraccCalculada(const CInteraccCalculada & CInteraccCalculada);
	virtual ~CInteraccCalculada();
};

typedef CTypedPtrList< CObList, CInteraccCalculada*> CInteraccCalculadaList;

#endif // !defined(AFX_INTERACCALCULADA_H__B753DAE3_1316_11D2_B39B_86B536374D36__INCLUDED_)
