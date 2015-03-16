// RealizadorCalculo.cpp: implementation of the CRealizadorCalculo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "proyecto.h"
#include "RealizadorCalculo.h"
#include "InteraccComponent.h"
#include "InteraccObservada.h"
#include "SistEcuac.h"
//#include "mathemat.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRealizadorCalculo::CRealizadorCalculo()
{

}

CRealizadorCalculo::~CRealizadorCalculo()
{

}

void CRealizadorCalculo::OptimizaInteraccionesCalculadas()
{
	int iContValidas = 0;
	GetDoc()->m_dErrorAcumulado = 0.0;
	GetDoc()->m_dMAD = 0.0;

	for (int iIndex = 0; iIndex < GetDoc()->m_cInteraccObservadaList.GetCount(); iIndex++)
	{
		CInteraccObservada *pIntrcObs = GetDoc()->DevuelveInteraccObservadaPtr(iIndex);

		if (pIntrcObs != NULL)
		{
			CInteraccCalculada *pEcuacDipolar = GetDoc()->DevuelveEcuacDipolarPtr(iIndex);

			if (pEcuacDipolar != NULL)
			{
				double dTzz = 0.0;
				double dTxxMinusTyy = 0.0;
				double dTyz = 0.0;
				double dTzx = 0.0;
				double dTxy = 0.0; 

				double dValorObservado = pIntrcObs->DevuelveValor();
				GetDoc()->DevuelveTensores(pIntrcObs, dTzz, dTxxMinusTyy, dTyz, dTzx, dTxy);
				double dValorCalculado = pEcuacDipolar->DevuelveValorCalculado(dTzz, dTxxMinusTyy,
					dTyz, dTzx, dTxy);

				if (fabs(dValorObservado - dValorCalculado) <=
					fabs(GetDoc()->m_dPorcentaje * dValorObservado))
				{
					iContValidas++;
					GetDoc()->m_dErrorAcumulado += fabs(dValorObservado - dValorCalculado);
				}
				else
					break;

				pEcuacDipolar->EstableceValor(dValorCalculado);
			}
		}
	}

	if (iContValidas == GetDoc()->m_cInteraccObservadaList.GetCount())
	{
		GetDoc()->m_dMAD = GetDoc()->m_dErrorAcumulado / iContValidas;
		GetDoc()->GrabaResultados();
	}

	GetDoc()->VaciaEcuacDipolarList();
}

void CRealizadorCalculo::InicializaParametros(CParametroVariable *pParamVariab)
{
	for (int iIndice = 0; iIndice < 	GetDoc()->m_cParteRigidaList.GetCount(); iIndice++)
	{
		CParteRigida *pParteRigida = 	GetDoc()->DevuelveParteRigidaPtr(iIndice);

		if (pParteRigida != NULL)
		{
			int iPaso;
			switch (pParteRigida->DevuelveParte())
			{
				case AnilloFenil:
					for (iPaso = 0; iPaso < 12; iPaso++)
					{
						if (pParteRigida->DevuelveAngulo(iPaso).DevuelveEtiqueta() ==
							pParamVariab->DevuelveEtiqueta())
						{
							pParteRigida->DevuelveAngulo(iPaso).EstableceValor(pParamVariab->DevuelveValorActual());
							pParteRigida->ObtieneAngulos();
						}
					}

					if (pParteRigida->DevuelveAnguloRotacion().DevuelveEtiqueta() == 
						pParamVariab->DevuelveEtiqueta())
						pParteRigida->DevuelveAnguloRotacion().EstableceValor(pParamVariab->DevuelveValorActual());

					if (pParteRigida->DevuelveLado(8).DevuelveEtiqueta() == 
						pParamVariab->DevuelveEtiqueta())
						pParteRigida->DevuelveLado(8).EstableceLongitud(
							pParamVariab->DevuelveValorActual());

					break;

				case Bifenil:
					if (pParteRigida->DevuelveAngulo(0).DevuelveEtiqueta() == 
						pParamVariab->DevuelveEtiqueta())
						pParteRigida->DevuelveAngulo(0).EstableceValor(pParamVariab->DevuelveValorActual());
						
					if (pParteRigida->DevuelveAnguloRotacion().DevuelveEtiqueta() == 
						pParamVariab->DevuelveEtiqueta())
						pParteRigida->DevuelveAnguloRotacion().EstableceValor(pParamVariab->DevuelveValorActual());
					break;

				case Trifenil:
					if (pParteRigida->DevuelveAnguloRotacion().DevuelveEtiqueta() == 
						pParamVariab->DevuelveEtiqueta())
						pParteRigida->DevuelveAnguloRotacion().EstableceValor(pParamVariab->DevuelveValorActual());
					break;
			}
		}
	}
}

void CRealizadorCalculo::ProcesoIteractivoDeVariacion(int iIndex)
{	
	BOOL bBandera = FALSE;
	CParametroVariable *pParamVariabActual = GetDoc()->DevuelveParamVariabPtr(iIndex);

	if (pParamVariabActual != NULL)
	{
		for (double dValor = pParamVariabActual->DevuelveValorInicial();
			dValor <= pParamVariabActual->DevuelveValorFinal();
			dValor += pParamVariabActual->DevuelveIncremento())
		{
			pParamVariabActual->EstableceValorActual(dValor);
			InicializaParametros(pParamVariabActual);

			CParametroVariable *pParamVariabSgte =
				GetDoc()->DevuelveParamVariabPtr(iIndex + 1);

			if (pParamVariabSgte != NULL)
			{
				ProcesoIteractivoDeVariacion(iIndex + 1);

				bBandera = TRUE;
				pParamVariabSgte->EstableceValorActual(pParamVariabSgte->DevuelveValorInicial());
				InicializaParametros(pParamVariabSgte);
			}
		
			GetConstMol()->ReconstruyeMolecula();

			if (!bBandera)
			{
				GetDoc()->m_iContador++;
				CalculaCoeficientes();	
				IncluyeInteraccionesCalculadas();
				CalculaTensores();
				OptimizaInteraccionesCalculadas();
			}
			
			if (GetDoc()->m_iContador == GetDoc()->m_iLimiteContador)
			{ 
				GetDoc()->m_iContador = 0;
				m_cDlgProgress.StepIt();
			}

			bBandera = FALSE;
		}
	}
}

void CRealizadorCalculo::RealizaCombinacionParametro(CWnd *pParent)
{
	// Establece condiciones de inicio de ciclo.
	if (!GetDoc()->InicializaElementosT())
		return;

	m_cDlgProgress.Create(pParent);

	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount();
		iIndex++)
	{
		CParametroVariable *pParamVariabActual = 
			GetDoc()->DevuelveParamVariabPtr(iIndex);

		if (pParamVariabActual != NULL)
			InicializaParametros(pParamVariabActual);
	}

	CalculaCoeficientes();
	IncluyeInteraccionesCalculadas();
	CalculaTensores();
	OptimizaInteraccionesCalculadas();
	m_cDlgProgress.SetStep(100);
	m_cDlgProgress.StepIt();
	m_cDlgProgress.DestroyWindow();
}

void CRealizadorCalculo::RealizaBarridoDeParametros(CWnd *pParent)
{
	// Establece condiciones de inicio de ciclo.
	if (!GetDoc()->InicializaElementosT())
		return;

	double dTotalInteracciones = 1.0;

	for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount();
		iIndex++)
	{
		CParametroVariable *pParamVariabActual = 
			GetDoc()->DevuelveParamVariabPtr(iIndex);

		if (pParamVariabActual != NULL)
			dTotalInteracciones *= pParamVariabActual->DevuelveTotalInteracciones();
	}

	if (dTotalInteracciones == 1)
		RealizaCombinacionParametro(pParent);
	else
	{
		if (dTotalInteracciones >= 10)
			GetDoc()->m_iLimiteContador = (int) round(dTotalInteracciones / 10.0);
		else
			GetDoc()->m_iLimiteContador = 1;

		m_cDlgProgress.Create(pParent);
		m_cDlgProgress.SetStep(10);
		ProcesoIteractivoDeVariacion(0);
		m_cDlgProgress.DestroyWindow();
	
		for (int iIndex = 0; iIndex < GetDoc()->m_cParametroVariableList.GetCount();
			iIndex++)
		{
			CParametroVariable *pParamVariabActual = 
				GetDoc()->DevuelveParamVariabPtr(iIndex);

			if (pParamVariabActual != NULL) {
				pParamVariabActual->EstableceValorInicial(pParamVariabActual->DevuelveValorInicial());
				InicializaParametros(pParamVariabActual);
				GetConstMol()->ReconstruyeMolecula();
			}
		}
	}
}

void CRealizadorCalculo::IncluyeInteraccionesCalculadas(void)
{
	double dCoefficient[5];
	int iCantIntrcComp;

	for (int iIndex1 = 0; iIndex1 < GetDoc()->m_cInteraccObservadaList.GetCount(); iIndex1++)
	{
		for (int iIndex2 = 0; iIndex2 < 5; iIndex2++)
		{
			dCoefficient[iIndex2] = 0.0;
		}

		iCantIntrcComp = 0;
		CInteraccObservada *pInteraccObs = GetDoc()->DevuelveInteraccObservadaPtr(iIndex1);

		if (pInteraccObs != NULL)
		{
			CString strPolo1 = pInteraccObs->DevuelveEtiqueta1();
			CString strPolo2 = pInteraccObs->DevuelveEtiqueta2();

			for (int iIndex2 = 0; iIndex2 < GetDoc()->m_cInteraccComponentList.GetCount(); iIndex2++)
			{
				CInteraccComponent *pInteraccComponent = GetDoc()->DevuelveInteraccComponentPtr(iIndex2);

				if (pInteraccComponent != NULL)
				{
					if (pInteraccComponent->DevuelveEtiquetaBase1() == strPolo1 &&
						pInteraccComponent->DevuelveEtiquetaBase2() == strPolo2)
					{
						for(int iPaso = 0; iPaso < 5; iPaso++)
						{
							dCoefficient[iPaso] += pInteraccComponent->DevuelveCoefficient(iPaso);
						}

						iCantIntrcComp += 1;
					}
				}
			}

			for (int iIndex2 = 0; iIndex2 < 5; iIndex2++)
			{
				dCoefficient[iIndex2] /= iCantIntrcComp;
			}

			
			CInteraccComponent *pEcuacDipolar = new CInteraccComponent;
			pEcuacDipolar->EstableceEtiquetaBase1(strPolo1);
			pEcuacDipolar->EstableceEtiquetaBase2(strPolo2);
			pEcuacDipolar->EstableceEtiqueta1(strPolo1);
			pEcuacDipolar->EstableceEtiqueta2(strPolo2);

			CPunto cPtoInicial;
			CPunto cPtoFinal;
			CString cStrTipo1 = _T("");
			CString cStrTipo2 = _T("");
			cPtoInicial = GetDoc()->DevuelveParteRigidaListPunto(strPolo1, cStrTipo1);
			cPtoFinal = GetDoc()->DevuelveParteRigidaListPunto(strPolo2, cStrTipo2);
			pEcuacDipolar->DevuelveCoordEsf().Establece(cPtoInicial, cPtoFinal);

			for (int iIndex2 = 0; iIndex2 < 5; iIndex2++)
			{
				pEcuacDipolar->EstableceCoefficiente(iIndex2, dCoefficient[iIndex2]);
			}

			GetDoc()->m_cEcuacDipolarList.AddTail(pEcuacDipolar);
		}
	}
}


void CRealizadorCalculo::CalculaCoeficientes(void)
{
	for (int iIndex = 0; iIndex < GetDoc()->m_cInteraccComponentList.GetCount(); iIndex++)
	{
		CInteraccComponent *pInteraccComponent = GetDoc()->DevuelveInteraccComponentPtr(iIndex);

		if (pInteraccComponent != NULL)
		{
			CPunto cPtoInicial;
			CPunto cPtoFinal;
			CString cStrTipoPtoInicial = _T("");
			CString cStrTipoPtoFinal = _T("");
			cPtoInicial = GetDoc()->DevuelveParteRigidaListPunto(pInteraccComponent->DevuelveEtiqueta1(),
				cStrTipoPtoInicial);
			cPtoFinal = GetDoc()->DevuelveParteRigidaListPunto(pInteraccComponent->DevuelveEtiqueta2(),
				cStrTipoPtoFinal);
			double dDihedral = GetDoc()->DevuelveDihedral();
			pInteraccComponent->EstableceCoeficientes(cPtoInicial, cPtoFinal, cStrTipoPtoInicial,
				cStrTipoPtoFinal, dDihedral, GetDoc()->m_nSimetria);
		}

		pInteraccComponent = NULL;
	}
}


void CRealizadorCalculo::CalculaTensores()
{
	int iCantVariables;
	int iSuma = 0;

	switch(GetDoc()->m_nSimetria)
	{
	case D2 :
		iCantVariables = 3;
		break;
	case D4 :
		iCantVariables = 2;
		break;
	case NoSimetria :
		iCantVariables = 3;
		iSuma = 2;
		GetDoc()->CalculaDistorcion();
		GetDoc()->m_dTzz = GetDoc()->m_cDistorcion.DevuelveTzz();
		GetDoc()->m_dTxxTyy = GetDoc()->m_cDistorcion.DevuelveTxxMinusTyy();
		break;
	}


	CSistEcuac cSistEcuac;
	cSistEcuac.EstableceCantVariab(iCantVariables);
	int iIndex = -1; 
	CInteraccCalculada *pEcuacDipolar;

	for (int iPaso1 = 0; iPaso1 < iCantVariables; iPaso1++)
	{
		iIndex++;
		pEcuacDipolar = GetDoc()->DevuelveInteraccionSeleccPtr(
			GetDoc()->m_cInteraccSelecc[iIndex].DevuelveEtiqueta());

		if (pEcuacDipolar != NULL)
		{
			for (int iPaso2 = 0; iPaso2 <= iCantVariables; iPaso2++)
			{
				if (iPaso2 == iCantVariables)
				{
					if(GetDoc()->m_nSimetria==D2 || GetDoc()->m_nSimetria==D4)
						cSistEcuac.EstableceValor(iPaso1, iPaso2, 
							GetDoc()->m_cInteraccSelecc[iIndex].DevuelveValorActual());
					else {
							double dValor = GetDoc()->m_cInteraccSelecc[iIndex].DevuelveValorActual() - 
							pEcuacDipolar->DevuelveCoefficient(0) * GetDoc()->m_dTzz -
							pEcuacDipolar->DevuelveCoefficient(1)* GetDoc()->m_dTxxTyy;
							cSistEcuac.EstableceValor(iPaso1, iPaso2, dValor);
					}
				}
				else
				{	if(iPaso2== iCantVariables-1 && GetDoc()->m_nSimetria==D2)
						cSistEcuac.EstableceValor(iPaso1, iPaso2,
							pEcuacDipolar->DevuelveCoefficient(iPaso2+2));		
					else
						cSistEcuac.EstableceValor(iPaso1, iPaso2,
							pEcuacDipolar->DevuelveCoefficient(iPaso2+iSuma));
				}
			}
		}
	}
	
	cSistEcuac.ResuelveSistemaDeEcuaciones();
	switch(GetDoc()->m_nSimetria) {
	case D2 :
	case D4 :
		GetDoc()->m_dTzz = cSistEcuac.DevuelveResultado(0);
		GetDoc()->m_dTxxTyy = cSistEcuac.DevuelveResultado(1);
		if ( GetDoc()->m_nSimetria == D2 )
		   GetDoc()->m_dTxy = cSistEcuac.DevuelveResultado(2);
	break;
	case NoSimetria :
		GetDoc()->m_dTyz = cSistEcuac.DevuelveResultado(0);
		GetDoc()->m_dTzx = cSistEcuac.DevuelveResultado(1);
		GetDoc()->m_dTxy = cSistEcuac.DevuelveResultado(2);
		break;
	}

}


