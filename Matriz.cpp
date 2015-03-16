// Matriz.cpp: implementation of the CMatriz class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Matriz.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMatriz::CMatriz()
{

}

CMatriz::~CMatriz()
{

}

//////////////////////////////////////////////////////////////////////
// Input Data
//////////////////////////////////////////////////////////////////////

void CMatriz::EstableceOrdenMatriz(int iValor)
{
	N = iValor;
}

void CMatriz::EstableceCoeficientes(int iFila, int iColumna, double dValor)
{
	//	En el ingreso de los coeficientes, la fila y columna cero (0) no existe
	//	todo es a partir de 1 (uno) hacia iOrdenMatriz.
	m_dValor[iFila][iColumna] = dValor;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

double CMatriz::DevuelveValorPropio(int iFila)
{
	return EI[N][iFila];
}

//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

void CMatriz::Determ(double X, double &SL)
{
	G[0] = 1;

	if (L == 1)
		return;

	G[1] = m_dValor[1][1] - X;

	if (L == 1)
		return;

	for (int K = 2; K <= L; K++)
		G[K] = (m_dValor[K][K] - X) * G[K - 1] - m_dValor[K][K - 1] * m_dValor[K][K - 1] *
			G[K - 2];

	SL = G[L];
	return;
}

void CMatriz::Bisec(double XL, double XH, double & XM)
{
	double KA; // por nstra. cuenta
	KA = 0;

	double YL = 0; // por nstra. cuenta
	double YH = 0; // por nstra. cuenta
	double YM = 0; // por nstra. cuenta

	Determ(XL, YL);
	Determ(XH, YH);

	double XB; // por nstra. cuenta

	for (;;)
	{
		KA = KA + 1;

		if (KA > 99)
			return;

		double DX; // por nstra. cuenta
		DX = XH - XL;

		if (DX < 0.0000001)
			return;

		if (DX > 1)
		{
			XM = (XL + XH) / 2;
			Determ(XM, YM);
		}
		else
		{
			XB = XM;
			XM = (XL * YH - XH * YL) / (YH - YL);
			Determ(XM, YM);

			if (fabs(XB - XM) < 0.000001)
				return;
		}

		if (YL * YM < 0)
		{
			XH = XM;
			YH = YM;
		}
		else
		{
			XL = XM;
			YL = YM;
		}
	}
}

void CMatriz::CalculosFinales()
{
	double S;	// por nuestra cuenta

	for (int IR = 1; IR <= (N - 2); IR++)
	{
		S = 0;

		for (int I = 1; I <= N; I++)
		{
			U[I] = 0;

			if (I > IR + 1)
				U[I] = m_dValor[I][IR];

			if (I > IR)
				S = S + m_dValor[I][IR] * m_dValor[I][IR];
		}

		double W; // por nstra. cuenta
		W = 1;

		if (m_dValor[IR + 1][IR] < 0)
			W = -1;

		double SSR; // por nstra. cuenta
		SSR = sqrt(S);

		double H; // por nstra. cuenta
		H = S + fabs(m_dValor[IR + 1][IR]) * SSR;
		U[IR + 1] = m_dValor[IR + 1][IR] + SSR * W;

		double UAU; // por nstra. cuenta
		UAU = 0;

		for (int I = 1; I <= N; I++)
		{
			for (int J = 1; J <= N; J++)
			{
				UAU = UAU + U[I] * m_dValor[I][J] * U[J];

				if ((I <= IR) && (J <= IR))
					T[I][J] = m_dValor[I][J];
				else
				{
					if ((J == IR) && (I >= IR + 2))
						T[I][J] = 0;
					else
					{
						double B23; // por nstra. cuenta
						B23 = 0;

						for (int K = 1; K <= N; K++)
							B23 = B23 - (U[I] * m_dValor[K][J] + m_dValor[I][K] * U[J]) * U[K];

						T[I][J] = m_dValor[I][J] + B23 / H;
					}
				}
			}
		}

		UAU = UAU / H / H;

		for (int I = 1; I <= N; I++)
		{
			for (int J = 1; J <= N; J++)
			{
				m_dValor[I][J] = T[I][J] + UAU * U[I] * U[J];

				if (fabs(m_dValor[I][J]) < 0.000001)
					m_dValor[I][J] = 0;
			}
		}
	}

	double KM; // por nstra. cuenta
	KM = N;

	double XL; // por nstra. cuenta
	double XH; // por nstra. cuenta

	for (L = 1; L <= KM; L++)
	{
		if (L == 1)
			EI[1][1] = m_dValor[1][1];
		else
		{
			for (int J = 1; J <= L; J++)
			{
				XL = EI[L - 1][J - 1];
				XH = EI[L - 1][J];

				double XM; // por nstra. cuenta
				XM = J;
				Bisec(XL, XH, XM);
				EI[L][J] = XM;
			}
		}

		EI[L][0] = -99;
		EI[L][L + 1] = 99;
	}
}

BOOL CMatriz::EsDiagonalizada()
{
	BOOL bBandera = FALSE;
	if(m_dValor[1][2]==0.0 && m_dValor[1][3]==0.0 && m_dValor[2][3]==0.0)
		bBandera = TRUE;

	if(bBandera)
	{
		EI[N][1] = m_dValor[1][1];
		EI[N][2] = m_dValor[2][2];
		EI[N][3] = m_dValor[3][3];
	}

return bBandera;
}

void CMatriz::DiagonalizaMatriz()
{ 
	BOOL bBandera = FALSE;
	double dValor = 0.0;

	if (EsDiagonalizada())
		return;
	
	if(m_dValor[1][3]==0.0 && m_dValor[2][3]==0.0)
	{
		EstableceOrdenMatriz(2);
		EI[N][3] = m_dValor[3][3];
	}
	
	if(m_dValor[1][2]==0.0 && m_dValor[2][3]==0.0)
	{
		EstableceOrdenMatriz(2);
		m_dValor[1][2] = m_dValor[2][1] = m_dValor[1][3];
		m_dValor[2][2] = m_dValor[3][3];
		dValor = m_dValor[2][2];
		bBandera = TRUE;
	}

	CalculosFinales();

	if (bBandera)
	{
		EI[N][3] = EI[N][2];  
		EI[N][2] = -EI[N][3] - EI[1][1];
	}


}
