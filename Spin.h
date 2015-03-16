// Spin.h: interface for the CSpin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPIN_H__B69F79C1_3138_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_SPIN_H__B69F79C1_3138_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Punto3D.h"

class CSpin : public CObject  
{
	DECLARE_SERIAL(CSpin)

//	Datos miembro
protected:
	CPunto m_cPuntoCentral;
	double m_dRadio;
	int m_iSlices;
	int m_iStacks;
	int m_iElemento;
	int m_iColor;
	CString m_strEtiqueta;
	BOOL m_bEstado;

//	Funciones miembro
public:
	//	Operators
	const CSpin& operator =(const CSpin & cSpin);

	// Operations
	void Serialize(CArchive & fichero);
	void MuestraImagen();

	//	Input Data
	void EstablecePtoCentral(CPunto cPto);
	void EstableceRadio(double dValor);
	void EstableceSlices(int iValor);
	void EstableceStacks(int iValor);
	void EstableceElemento(int iValor);
	void EstableceColor(int iValor);
	void EstableceEtiqueta(CString cCadena);
	void EstableceEstado(BOOL bLogico);

	// Output Data
	CPunto DevuelvePtoCentral(void);
	int DevuelveElemento(void);
	CString DevuelveEtiqueta(void);

	//	Construction / Destruction
	CSpin();
	CSpin(const CSpin & cSpin);
	virtual ~CSpin();
};

typedef CTypedPtrList< CObList, CSpin*> CSpinList;

#endif // !defined(AFX_SPIN_H__B69F79C1_3138_11D2_A5A8_043A03C10000__INCLUDED_)
