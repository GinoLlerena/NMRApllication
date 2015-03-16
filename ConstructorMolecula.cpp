// ConstructorMolecula.cpp: implementation of the CConstructorMolecula class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "proyecto.h"
#include "ConstructorMolecula.h"
#include "ParteRigida.h"
#include "Rutinas.h"
#include "MainFrm.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConstructorMolecula::CConstructorMolecula()
{

}

CConstructorMolecula::~CConstructorMolecula()
{

}

BOOL CConstructorMolecula::InsertaParteRigida(ParteRigida nParte)
{
	int iIndex=0;
	BOOL bRetorno = TRUE;
	if (VerificaCondicionesDeInsercion())
	{
		double dRadio = 0.0;
		GetDoc()->m_nParteRigida = nParte;
		switch(nParte) {
			case AnilloFenil :
				GetDoc()->m_iPosAnilloFenil += 1;
				iIndex = 2;
				break;
			case Bifenil :
				GetDoc()->m_iPosBifenil += 1;
				iIndex = 0;
				break;
			case Trifenil :
				GetDoc()->m_iPosTrifenil+= 1;
				iIndex = 4;
				break;
			}
		dRadio = DevuelveRadioParteRigida();
		IncluyeParteRigida();
		
		if (GetDoc()->m_cParteRigidaList.GetCount() > 1)
		{
			GetDoc()->pObjParteRigida->DevuelveSpin(iIndex).EstableceColor(5);
			GetDoc()->pObjParteRigida->DevuelveSpin(iIndex).EstableceRadio(dRadio);
		}

		GetDoc()->SetModifiedFlag(TRUE);
		GetDoc()->UpdateAllViews(NULL);
	}
	else	bRetorno = FALSE;

	return bRetorno;
}

BOOL CConstructorMolecula::VerificaCondicionesDeInsercion(void)
{
	int countTot, i;
	POSITION posAux;
	CParteRigida *pParteAux;

	countTot = i = 0;
	posAux = GetDoc()->m_cParteRigidaList.FindIndex(i);
		
	while (posAux != NULL)
	{
		pParteAux = GetDoc()->m_cParteRigidaList.GetAt(posAux);

		if (i == 0)
			countTot = pParteAux->DevuelveMaxEnlace();

		if ( countTot < pParteAux->DevuelveMaxEnlace() )
			countTot = pParteAux->DevuelveMaxEnlace();
			
		i++;
		posAux = GetDoc()->m_cParteRigidaList.FindIndex(i);
	}

	if (GetDoc()->m_cParteRigidaList.GetCount() <= countTot )
		return TRUE;

	return FALSE;
}

void CConstructorMolecula::IncluyeParteRigida(void)
{
	CString sTemp;

	switch(GetDoc()->m_nParteRigida)
	{
		case AnilloFenil:
			sTemp = DevuelveItemLista(GetDoc()->m_nParteRigida, GetDoc()->m_iPosAnilloFenil);
			break;
		case Bifenil:
			sTemp = DevuelveItemLista(GetDoc()->m_nParteRigida, GetDoc()->m_iPosBifenil);
			break;
		case Trifenil:
			sTemp = DevuelveItemLista(GetDoc()->m_nParteRigida, GetDoc()->m_iPosTrifenil);
			break;
	}

	GetDoc()->pObjParteRigida = new CParteRigida;
	GetDoc()->pObjParteRigida->Create(GetDoc()->m_nParteRigida);
	GetDoc()->m_cParteRigidaList.AddTail(GetDoc()->pObjParteRigida);
	CMainFrame* pFrame = (CMainFrame*) AfxGetApp()->m_pMainWnd;
	CMainBar* pMainBar = &pFrame->m_wndMainBar;
	pMainBar->m_ObjectsBox.SetCurSel(pMainBar->m_ObjectsBox.AddString(sTemp));
	
}




double CConstructorMolecula::DevuelveRadioParteRigida(void)
{
	double dRadio = 0.0;

	if (!GetDoc()->m_cParteRigidaList.IsEmpty())
	{
		switch (GetDoc()->pObjParteRigida->DevuelveParte())
		{
			case AnilloFenil:
				dRadio = GetDoc()->pObjParteRigida->DevuelveLado(8).DevuelveRadio();
				break;
			case Bifenil:
				dRadio = GetDoc()->pObjParteRigida->DevuelveLado(0).DevuelveRadio();
				break;
			case Trifenil:
				dRadio = GetDoc()->pObjParteRigida->DevuelveLado(3).DevuelveRadio();
				break;
		}
	}

	return dRadio;
}

void CConstructorMolecula::ReconstruyeMolecula(void)
{
	int count, i;
	POSITION posAux;
	CPunto ptoUno, ptoDos, ptoTres;
	CParteRigida *pObjParteAux, *pObjParteTmp;

	count = i = 0;
	posAux = GetDoc()->m_cParteRigidaList.FindIndex(i);

	if (posAux != NULL)
	{
		pObjParteAux = GetDoc()->m_cParteRigidaList.GetAt(posAux);
		pObjParteAux->Construye(GetDoc()->m_cPtoInicio,GetDoc()->m_cPtoFin, 
		GetDoc()->m_cPtoPlano);

		while (posAux != NULL)
		{
			pObjParteAux = GetDoc()->m_cParteRigidaList.GetAt(posAux);

			for (int j = 0; j < 12; j++)
			{	int iValorRetorno = pObjParteAux->DevuelvePosiciones(j, ptoUno, ptoDos, ptoTres);
			
				if (iValorRetorno)
				{
					posAux = GetDoc()->m_cParteRigidaList.FindIndex(iValorRetorno);
					
					if (posAux != NULL)
					{
						pObjParteTmp = GetDoc()->m_cParteRigidaList.GetAt(posAux);

						switch(pObjParteTmp->DevuelveParte())
						{
							case AnilloFenil : 
								pObjParteTmp->DevuelveLado(8).EstableceLongitud(
									CalculaDistancia(ptoUno, ptoDos));
								break;
							case Bifenil :
								pObjParteTmp->DevuelveLado(0).EstableceLongitud(
									CalculaDistancia(ptoUno, ptoDos));
								break;
							case Trifenil :
								pObjParteTmp->DevuelveLado(3).EstableceLongitud(
									CalculaDistancia(ptoUno, ptoDos));
								break;
						}
							
						pObjParteTmp->Construye(ptoUno, ptoDos, ptoTres);
					}
				}
			}

			i++;
			posAux = GetDoc()->m_cParteRigidaList.FindIndex(i);
		}
	}
}

void CConstructorMolecula::EliminaParteRigida(int iPos, ParteRigida nParte)
{
	POSITION Posicion=NULL;

	Posicion= GetDoc()->m_cParteRigidaList.FindIndex(iPos);	 

	if (Posicion != NULL)
	{
		CParteRigida* pPR = GetDoc()->m_cParteRigidaList.GetAt(Posicion);
		GetDoc()->m_cParteRigidaList.RemoveAt(Posicion);
		delete pPR;
		Posicion = NULL;
		ActualizaContadores(nParte);
	}
}

void CConstructorMolecula::ActualizaContadores(ParteRigida nParte)
{
	switch (nParte)
	{
		case AnilloFenil:
			GetDoc()->m_iPosAnilloFenil -= 1;
			break;
		case Bifenil:
			GetDoc()->m_iPosBifenil -= 1;
			break;
		case Trifenil:
			GetDoc()->m_iPosTrifenil -= 1;
			break;
	}

}
