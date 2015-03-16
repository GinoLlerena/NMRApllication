// SistEcuac.cpp: implementation of the CSistEcuac class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SistEcuac.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSistEcuac::CSistEcuac()
{
	m_iCantVariab = 0;
	for(int i = 0; i<limValor; i++)
	{
		for(int j = 0; j<limValor+1; j++)
			m_cMatriz.m_dValor[i][j] = 0;
		m_dResult[i] = 0;;
		m_bEcuacion[i] = FALSE;
	}
	m_dValorMinimo = 0.00001;	
}

CSistEcuac::~CSistEcuac()
{

}

//////////////////////////////////////////////////////////////////////
//	Input Data
//////////////////////////////////////////////////////////////////////

void CSistEcuac::EstableceCantVariab(int iValor)
{
	m_iCantVariab = iValor;
}

void CSistEcuac::EstableceCoeff(int iFila, int iColumna, double dValor)
{
	m_cMatriz.m_dValor[iFila][iColumna] = dValor;
}

void CSistEcuac::EstableceResultado(int iFila, double dValor)
{
	m_cMatriz.m_dValor[iFila][m_iCantVariab] = dValor;
}

void CSistEcuac::EstableceValor(int iFila, int iColumna, double dValor)
{
	m_cMatriz.m_dValor[iFila][iColumna] = dValor;
}

//////////////////////////////////////////////////////////////////////
// Output Data
//////////////////////////////////////////////////////////////////////

int CSistEcuac::DevuelveCantVariab()
{
	return m_iCantVariab;
}

double CSistEcuac::DevuelveCoeff(int iFila, int iColumna)
{
	return m_cMatriz.m_dValor[iFila][iColumna];
}

double CSistEcuac::DevuelveResultado(int iFila)
{
	return m_cMatriz.m_dValor[iFila][m_iCantVariab];
}

double CSistEcuac::DevuelveValor(int iFila, int iColumna)
{
	return m_cMatriz.m_dValor[iFila][iColumna];
}

//////////////////////////////////////////////////////////////////////
//	Operations
//////////////////////////////////////////////////////////////////////

void CSistEcuac::Gauss()
{
	int PV;
	double EPS = 1;
	while ((EPS + 1.0) > 1.0)
	{
		EPS = EPS / 2.0;
	}

	EPS = EPS * 2.0;

	
	double EPS2 = 0.0;
	EPS2 = EPS * 2;

	double DET = 1.0;
	// definidos aqu¡
	double TM = 0.0;
	double R = 0.0;
	double TEMP = 0.0;
	double VA = 0.0;

	for (int I = 0; I <= (m_iCantVariab - 2); I++)
	{
		PV = I;

		for (int J = I + 1; J <= (m_iCantVariab - 1); J++)
			if (fabs(m_cMatriz.m_dValor[PV][I]) < fabs(m_cMatriz.m_dValor[J][I]))
				PV = J;

		if (PV != I)
		{
			for (int JC = 0; JC <= m_iCantVariab; JC++)
			{
				TM = m_cMatriz.m_dValor[I][JC];
				m_cMatriz.m_dValor[I][JC] = m_cMatriz.m_dValor[PV][JC];
				m_cMatriz.m_dValor[PV][JC] = TM;
			}

			DET = -1 * DET;
		}

		if (m_cMatriz.m_dValor[I][I] == 0)
		{
			//printf(" La matriz es singular");
			return;
		}

		for (int JR = I + 1; JR <= (m_iCantVariab - 1); JR++)
			if (m_cMatriz.m_dValor[JR][I] != 0)
			{
				R = m_cMatriz.m_dValor[JR][I] / m_cMatriz.m_dValor[I][I];

				for (int KC = I + 1; KC <= m_iCantVariab; KC++)
				{
					TEMP = m_cMatriz.m_dValor[JR][KC];
					m_cMatriz.m_dValor[JR][KC] = m_cMatriz.m_dValor[JR][KC] - R * m_cMatriz.m_dValor[I][KC];

					if (fabs(m_cMatriz.m_dValor[JR][KC]) < (EPS2 * TEMP))
						m_cMatriz.m_dValor[JR][KC] = 0.0;
						//	Si el resultado de la resta es menor que
						// el doble del épsilon de la máquina por el valor
						// original, se cambia su valor a cero.
				}
			}
	}

	for (int I = 0; I <= (m_iCantVariab - 1); I++)
		DET = DET * m_cMatriz.m_dValor[I][I];

	//printf("\t\t\tDETERMINANTE = %f\n", DET);

	if (m_cMatriz.m_dValor[m_iCantVariab - 1][m_iCantVariab - 1] == 0)
	{
		//printf(" La matriz es singular" );
		return;
	}

	m_cMatriz.m_dValor[m_iCantVariab - 1][m_iCantVariab] /= m_cMatriz.m_dValor[m_iCantVariab - 1][m_iCantVariab - 1];

	for (int NV = m_iCantVariab - 2; NV >= 0; NV--)
	{
		VA = m_cMatriz.m_dValor[NV][m_iCantVariab];

		for (int K = NV + 1; K <= (m_iCantVariab - 1); K++)
			VA = VA - m_cMatriz.m_dValor[NV][K] * m_cMatriz.m_dValor[K][m_iCantVariab];

		m_cMatriz.m_dValor[NV][m_iCantVariab] = VA / m_cMatriz.m_dValor[NV][NV];
	}

	return;
}

int CSistEcuac::ExaminaMatriz()
{
	int iPos = 0;
	int iTotal=0;
	int iContador =0;
	double dSuma = 0;
	
	

	for(int i=0; i<m_iCantVariab;i++)
	{
		iPos = 0;
		iContador =0;
		dSuma = 0;
		for(int j=0; j<m_iCantVariab;j++)
		{
			if(!m_bEcuacion[j])
				if(fabs(m_cMatriz.m_dValor[i][j]) > fabs(m_dValorMinimo)) //!=0)
				{
					iPos = j;
					iContador++;
				}
			if(iContador>1)
				break;
		}
		if(iContador==1)
		{
			m_bEcuacion[i] = TRUE;
			for(int j =0; j<m_iCantVariab;j++)
				if(j!=iPos)
				   dSuma+=m_cMatriz.m_dValor[i][j]*m_dResult[j];
			if(fabs(m_cMatriz.m_dValor[i][iPos]) > fabs(m_dValorMinimo))
				m_dResult[iPos] = (m_cMatriz.m_dValor[i][m_iCantVariab]-dSuma)/m_cMatriz.m_dValor[i][iPos];
			else
				m_dResult[iPos] = 0;
				


			iTotal++;
		}
	}

	return iTotal;
}



void CSistEcuac::ResuelveSistemaDeEcuaciones()
{
	int i,j;
	int iPosVariable, iEcuacion;
	double dSuma;
	dSuma=0;
	


	int iTotal = ExaminaMatriz();

	if (iTotal==0)
			Gauss();
	else	if(iTotal==m_iCantVariab )
				CopiaResultados();
			else	if(iTotal==(m_iCantVariab-1) )
						{
							iPosVariable = BuscaResultadoFaltante();
							iEcuacion = BuscaEcuacionDeCalculo();
							for(i =0; i<m_iCantVariab;i++)
								dSuma+=m_cMatriz.m_dValor[iEcuacion][i]*m_dResult[i];
							if(fabs(m_cMatriz.m_dValor[iEcuacion][iPosVariable]) > fabs(m_dValorMinimo))
								m_dResult[iPosVariable] = (m_cMatriz.m_dValor[iEcuacion][m_iCantVariab]-dSuma)/m_cMatriz.m_dValor[iEcuacion][iPosVariable];
							else
								m_dResult[iPosVariable] = 0;
							CopiaResultados();
						}
					else
						{ for(i=0; i<m_iCantVariab;i++)
								for(j=0; j<m_iCantVariab;j++)
									m_cMatriz.m_dValor[i][m_iCantVariab]-=m_cMatriz.m_dValor[i][j]*m_dResult[j];

							for(i =0; i<m_iCantVariab;i++)
								{
									if(m_bEcuacion[i])
										EliminaFila(i);
									if(m_dResult[i]!=0)
										EliminaColumna(i);
								}
							int iCant = m_iCantVariab;
							m_iCantVariab = m_iCantVariab - iTotal;
							Gauss();
							j=0;
							for(i=0; i<iCant; i++)
								if(m_dResult[i] == 0)
								{	
									m_dResult[i] = m_cMatriz.m_dValor[j][m_iCantVariab];
									j++;
								}
							CopiaResultados();
					}
}


int CSistEcuac::BuscaResultadoFaltante(int iPosicion)
{
	int iPos=-1;
	for(int i=iPosicion; i<m_iCantVariab;i++)
		for(int j=0; j<m_iCantVariab;j++)
		if(m_dResult[i]==0 && fabs(m_cMatriz.m_dValor[i][j]) > fabs(m_dValorMinimo))
		{
			iPos=i;
			break;
		}
	return iPos;
}

int CSistEcuac::BuscaEcuacionDeCalculo(int iPosicion)
{
	int iPos=-1;
	for(int i=iPosicion; i<m_iCantVariab;i++)
		if(!m_bEcuacion[i])
		{
			iPos=i;
			break;
		}
	return iPos;
}

void CSistEcuac::EliminaFila(int iFila)
{
	for(int i=iFila; i<m_iCantVariab-1; i++)
		for(int j=0; j<=m_iCantVariab; j++)
			m_cMatriz.m_dValor[i][j] = m_cMatriz.m_dValor[i+1][j];
}

void CSistEcuac::EliminaColumna(int iColumna)
{
	for(int i=0; i<m_iCantVariab; i++)
		for(int j=iColumna; j<m_iCantVariab; j++)
				m_cMatriz.m_dValor[i][j] = m_cMatriz.m_dValor[i][j+1];

}

void CSistEcuac::CopiaResultados()
{
	for(int i =0; i<m_iCantVariab;i++)
		m_cMatriz.m_dValor[i][m_iCantVariab] = m_dResult[i];
}
