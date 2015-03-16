// ParteRigida.h: interface for the CParteRigida class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTERIGIDA_H__27921CC3_31BE_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_PARTERIGIDA_H__27921CC3_31BE_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Angulo.h"
#include "Punto3D.h"
#include "Lado.h"
#include "Spin.h"
#include "Structures.h"

class CParteRigida : public CObject  
{
	DECLARE_SERIAL(CParteRigida)

//	Datos miembro
protected:
	CAngulo m_cAngRotacion;
	ParteRigida m_nParteRigida;
	CLado m_cLado[12];
	CSpin m_cSpin[6];
	CPunto m_cPunto[12];
	CAngulo m_cAngulo[12];
	COLORREF m_colorRef;
	int m_iEstilo;
	int m_iGrosor;


//	Funciones miembro
public:
	//	Operators
	const CParteRigida& operator =(const CParteRigida & cParteRigida);

	//	Operations
	void Serialize(CArchive & fichero);
	void Construye(CPunto cPtoA, CPunto cPtoB, CPunto cPtoC);
	void MuestraImagen(void);
	void MuestraImagenGDI(CDC *pDC, int iCuadricula, CString cPlano);
	void MuestraDescripcion(CDC *pDC,int iFactor, CString cPlano);
	void ObtieneAngulos(void);

private:
	void RotaEje(double dAnguloValor);
	
public:
	//	Input Data
	void EstableceColor(COLORREF colorRef);
	void EstableceEstilo(int iValor);
	void EstableceGrosor(int iValor);
	void EstableceParte(ParteRigida nParteRigida);	

private:
	void EstableceLado(void);

public:
	void Create(ParteRigida nParte);
	void ImprimeAngulosInternosTrifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimePuntosInternosTrifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimePuntosInternosBifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimePuntosInternosAnilloFenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeAngulosExternosAnilloFenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeAngulosInternosBifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeAngulosInternos(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeAngulosExternos(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeAngulosInternosAnilloFenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeLadosExternos(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeLadosExternosAnilloFenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeLadosInternos(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeLadosInternosAnilloFenil(CDC * pDC, LONG & nActualLinea,	LONG nAltura);
	void ImprimeLadosInternosBifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeLadosInternosTrifenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimePuntosExternos(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimePuntosExternosAnilloFenil(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimePuntosInternos(CDC * pDC, LONG & nActualLinea, LONG nAltura);
	void ImprimeConformacion(CDC *pDC,LONG & nActualLinea);

	//	Output Data
	CAngulo & DevuelveAnguloRotacion(void);	// Este tipo de función permite hacer
															// uso de las funciones Establece... y
															// Devuelve... del objeto.
															// Objeto: m_cAnguloRotacion.
	ParteRigida DevuelveParte(void);				// Este tipo de función sólo permite hacer
															// uso de las funciones Devuelve... del objeto.
															// Objeto: m_nParteRigida.
	CLado & DevuelveLado(int iIndice);
	CSpin & DevuelveSpin(int iIndice);
	CPunto DevuelvePunto(int iIndice);
	CAngulo & DevuelveAngulo(int iIndice);
	int DevuelvePosiciones(int iIndice, CPunto & cPtoUno, CPunto & cPtoDos, CPunto & cPtoTres);
   int DevuelveTotSpines(void);
	int DevuelveMaxEnlace(void);
	BOOL DevuelvePuntoEtTipo(CString cEtiqueta, CPunto & cPto, CString & cTipo);	

	//	Construction / Destruction
	CParteRigida();
	virtual ~CParteRigida();
};

typedef CTypedPtrList< CObList, CParteRigida*> CParteRigidaList;

#endif // !defined(AFX_PARTERIGIDA_H__27921CC3_31BE_11D2_A5A8_043A03C10000__INCLUDED_)
