// Lado.h: interface for the CLado class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LADO_H__64F5C5E1_317C_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_LADO_H__64F5C5E1_317C_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Punto3D.h"
#include "Angulo.h"

class CLado : public CObject  
{
	DECLARE_SERIAL(CLado)

// Datos miembro
protected:
	int m_iRebanadas;
	int m_iIndiceEnlace;
	double m_dRadio;
	double m_dLongitud;
	CPunto m_cPtoInicial;
	CPunto m_cPtoFinal;
	CAngulo m_cAnguloTeta;
	CAngulo m_cAnguloPhi;
	CString m_strEstado;
	CString m_strTipo;
	CString m_strEtiqueta;	// Etiqueta del parámetro

// Funciones miembro
public:
	// Operators
	const CLado& operator =(const CLado & cCilin);

	// Operations
	void Serialize(CArchive & fichero);
	void Construye(void);
	int DeterminaPosicion(CPunto cPto);
	void SituaEnEspacio(CPunto cPtoAux, int iPosicion);
	void MuestraLineaGDI(CDC *pDC, int iFactor, CString cPlano);

	// Input Data
	void Establece(CPunto cPtoInicial, CPunto cPtoFinal);
	void EstableceIndiceEnlace(int iValor);
	void EstableceLongitud(double dValor);
	void EstableceEstado(CString cCadena);
	void EstableceTipo(CString cCadena);
	void EstableceEtiqueta(CString cCadena);

	// Output Data
	int DevuelveIndiceEnlace(void);
	double DevuelveRadio(void);
	double DevuelveLongitud(void);
	CPunto & DevuelvePtoInicial(void);
	CPunto & DevuelvePtoFinal(void);	
	CAngulo & DevuelveAnguloTeta(void);
	CAngulo & DevuelveAnguloPhi(void);
	CString DevuelveEstado(void);
	CString DevuelveTipo(void);
	CString DevuelveEtiqueta(void);

	// Construction / Destruction
	CLado();
	CLado(const CLado & cLado);
	CLado(CPunto, CPunto);
	virtual ~CLado();
};

typedef CTypedPtrList< CObList, CLado*> CLadoList;

#endif // !defined(AFX_LADO_H__64F5C5E1_317C_11D2_A5A8_043A03C10000__INCLUDED_)
