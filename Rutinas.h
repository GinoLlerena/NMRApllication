// Rutinas.h: interface archive.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUTINAS_H__25A2DA61_3283_11D2_A5A8_003A03C10000__INCLUDED_)
#define AFX_RUTINAS_H__25A2DA61_3283_11D2_A5A8_003A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Punto3d.h"
#include "Structures.h"

CPunto Conversor(CPunto cPtoInicial, CPunto cPtoFinal, double dK);
double CalculaDistancia(CPunto cPtoUno, CPunto cPtoDos);
CString DevuelveItemLista(ParteRigida nParteRigida, UINT uSecuencia);
CString DevStrParteRigida(ParteRigida nParteRigida);
ParteRigida DevuelveIdParteRigida(CString cCadena);
CString DevuelveEnumSimetriaAsString(Simetria nSimetria);
Simetria DevuelveStringAsEnumSimetria(CString cCadena);
int CStrToInt(CString cCadena);
CString DoubleToCStr(double dValor);
double CStrToDouble(CString cCadena);
double DeterminaAng(double dAng1, double dD1, double dAng2, double dD2, double dH);
double AnguloDosRectas(CPunto cPtoU, CPunto cPtoV);
CPunto RetornaVector(CPunto cPtoA, CPunto cPtoB);
CPunto GirarLado(CPunto cGiro, CPunto cOri, CPunto cPer,double dAng, double dLong);
BOOL SonDiferentesFicheroEstados(CFileStatus cFileStatus1, CFileStatus cFileStatus2);
int DevuelveIndMaterial(CString cTipoSpin);
BOOL DevuelveEtiquetasDij(CString cCadena, CString & cEtiqueta1, CString & cEtiqueta2);
CString DevuelveEtiquetas(CString cEtiqueta1, CString cEtiqueta2);
CString DevuelveEtiquetasInvertidas(CString cEtiqueta1, CString cEtiqueta2);

void DevCoordEsf(CPunto cPto, double & dAnguloTeta, double & dAnguloPhi, 
					  double & dDistancia);				// Temporal
void DevCoordEsf2Ptos(CPunto cPto1, CPunto cPto2, double & dAnguloTeta, double & dAnguloPhi,
							 double & dDistancia);		// Temporal


#endif // !defined(AFX_RUTINAS_H__25A2DA61_3283_11D2_A5A8_003A03C10000__INCLUDED_)
