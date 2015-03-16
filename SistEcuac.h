// SistEcuac.h: interface for the CSistEcuac class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SISTECUAC_H__6FB97641_31B6_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_SISTECUAC_H__6FB97641_31B6_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Matriz.h"
#define limValor 10

class CSistEcuac : public CObject  
{
// Datos miembro
private:	
	int		m_iCantVariab;
	CMatriz  m_cMatriz;
	BOOLEAN  m_bEcuacion[limValor];
	double	m_dResult[limValor];
	double m_dValorMinimo;

//	Funciones miembro
private:	
	//	Operations
	void CopiaResultados(void);
	void EliminaColumna(int iColumna);
	void EliminaFila(int iFila);
	int BuscaEcuacionDeCalculo(int iPosicion = 0);
	int BuscaResultadoFaltante(int iPosicion = 0);
	int ExaminaMatriz();

public:
	void Gauss(void);
	void ResuelveSistemaDeEcuaciones(void);

	//	Input Data
	void EstableceCantVariab(int iValor);
	void EstableceCoeff(int iFila, int iColumna, double dValor);
	void EstableceResultado(int iFila, double dValor);
	void EstableceValor(int iFila, int iColumna, double dValor);

	//	Output Data
	int DevuelveCantVariab(void);
	double DevuelveCoeff(int iFila, int iColumna);
	double DevuelveResultado(int iFila);
	double DevuelveValor(int iFila, int iColumna);

	//	Construction / Destruction
	CSistEcuac();
	virtual ~CSistEcuac();
};

#endif // !defined(AFX_SISTECUAC_H__6FB97641_31B6_11D2_A5A8_043A03C10000__INCLUDED_)
