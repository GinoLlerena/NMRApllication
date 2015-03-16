// Punto3D.h: interface for the CPunto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUNTO3D_H__70CFA702_314F_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_PUNTO3D_H__70CFA702_314F_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPunto : public CObject  
{
	DECLARE_SERIAL(CPunto)
 
//	Datos miembro
protected:
	double m_dX;
	double m_dY;
	double m_dZ;

// Funciones miembro
public:
	//	Operators
	const CPunto& operator =(const CPunto & cPto);

	//	Operations
	void Serialize(CArchive & fichero);
	void Translada(double dX = 0, double dY = 0, double dZ = 0);
	void Translada(CPunto cPto);
	void Rota3D(CPunto cPto, double dAnguloValor);

	//	Input Data
	void Establece(double dX, double dY, double dZ);
	void EstableceX(double dValor);
	void EstableceY(double dValor);
	void EstableceZ(double dValor);

	//	Output Data
	double DevuelveX(void);
	double DevuelveY(void);
	double DevuelveZ(void);

	//	Construction / Destruction
	CPunto();
	CPunto(double dX, double dY, double dZ);
	CPunto(const CPunto & cPto);
	virtual ~CPunto();
};

typedef CTypedPtrList< CObList, CPunto*> CPuntoList;

#endif // !defined(AFX_PUNTO3D_H__70CFA702_314F_11D2_A5A8_043A03C10000__INCLUDED_)
