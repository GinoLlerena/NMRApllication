// Seleccionadora.h: interface for the CSeleccionadora class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECCIONADORA_H__F1A16F61_4AC4_11D2_A5A8_444553540001__INCLUDED_)
#define AFX_SELECCIONADORA_H__F1A16F61_4AC4_11D2_A5A8_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

struct StcDatos
{
	int m_iIndice;
	double m_dValor;
};

class CSeleccionadora : public CObject  
{
// Datos miembro
protected:
	StcDatos m_stDatos[25];
	int m_iCantidadDatos;
	int m_iLimite;

// Funciones miembro
public:
	void Inicializate();
	// Operations
	void GuardaEnPosicion(int iIndice, StcDatos stDato);
	void BuscaDondeGuardar(StcDatos stDato);

	// Output Data
	int DevuelveCantidadDatos(void);
	int DevuelveIndice(int iIndice);

	// Construction / Destruction
	CSeleccionadora();
	virtual ~CSeleccionadora();
};

#endif // !defined(AFX_SELECCIONADORA_H__F1A16F61_4AC4_11D2_A5A8_444553540001__INCLUDED_)
