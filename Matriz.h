// Matriz.h: interface for the CMatriz class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIZ_H__573BB561_4629_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_MATRIZ_H__573BB561_4629_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

const int iOrdenMatriz = 10;

class CMatriz : public CObject  
{
//	Datos miembro
public:
	double m_dValor[iOrdenMatriz][iOrdenMatriz + 1];

protected:	
	double U[iOrdenMatriz];
	double T[iOrdenMatriz][iOrdenMatriz];
	double G[iOrdenMatriz];
	double EI[iOrdenMatriz][iOrdenMatriz];
	int L;
	int N;

//	Funciones miembro
private:
	BOOL EsDiagonalizada();
	//	Operations
	void Determ(double X, double & SL);
	void Bisec(double XL, double XH, double &XM);

public:
	void DiagonalizaMatriz();
	void CalculosFinales(void);

	//	Input Data
	void EstableceOrdenMatriz(int iValor);
	void EstableceCoeficientes(int iFila, int iColumna, double dValor);

	//	Output Data
	double DevuelveValorPropio(int iFila);

	//	Construction / Destruction
	CMatriz();
	virtual ~CMatriz();
};

#endif // !defined(AFX_MATRIZ_H__573BB561_4629_11D2_A5A8_444553540001__INCLUDED_)
