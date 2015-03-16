// Distorcion.h: interface for the CDistorcion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISTORCION_H__27921CC1_31BE_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_DISTORCION_H__27921CC1_31BE_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDistorcion : public CObject  
{
	DECLARE_SERIAL(CDistorcion)

//	Datos miembro
private:
	CString m_strEtiquetasInteraccA;		// Etiqueta de D sub 1,2
	CString m_strEtiquetasInteraccB;		// Etiqueta de D sub 1,4
	CString m_strEtiquetasInteraccC;		// Etiqueta de D sub 1,5
	double m_dInteraccion[3];				// i = 0 .. Valor de D sub 1,2;
													//     1 .. Valor de D sub 1,4;
													//     2 .. Valor de D sub 1,5;
	double m_dDistanciaSub12;				// Distancia de D sub 1,2
	double m_dConstante;
	double m_dTzz;
	double m_dTxxMinusTyy;
	double m_dRho;

//	Funciones miembro
public:
	//	Operations
	void Serialize(CArchive & cFichero);
	void RealizaCalculos(void);

private:
	void CalculaRho(void);
	void CalculaTzz(void);
	void CalculaTxxMinusTyy(void);

public:
	//	Input Data
	void EstableceEtiquetasInteraccA(CString cCadena);
	void EstableceEtiquetasInteraccB(CString cCadena);
	void EstableceEtiquetasInteraccC(CString cCadena);
	void EstableceInteraccion(int iIndice, double dValor);
	void EstableceDistancia(double dValor);
	void EstableceConstante(double dValor);

	//	Output Data
	CString DevuelveEtiquetasInteraccA(void);
	CString DevuelveEtiquetasInteraccB(void);
	CString DevuelveEtiquetasInteraccC(void);
	double DevuelveRho(void);
	double DevuelveTzz(void);
	double DevuelveTxxMinusTyy(void);

	//	Construction / Destruction
	CDistorcion();
	virtual ~CDistorcion();
};

#endif // !defined(AFX_DISTORCION_H__27921CC1_31BE_11D2_A5A8_043A03C10000__INCLUDED_)
