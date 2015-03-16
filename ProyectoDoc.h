// ProyectoDoc.h : interface of the CProyectoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROYECTODOC_H__8D2FBB13_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
#define AFX_PROYECTODOC_H__8D2FBB13_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ParteRigida.h"
#include "InteraccObservada.h"
#include "InteraccComponent.h"
#include "InteraccCalculada.h"
#include "ParametroVariable.h"
#include "Distorcion.h"
#include "Structures.h"

class CProyectoDoc : public CDocument
{
protected: // create from serialization only
	CProyectoDoc();
	DECLARE_DYNCREATE(CProyectoDoc)

// Attributes
public:
	CParteRigidaList			m_cParteRigidaList;
	CInteraccObservadaList	m_cInteraccObservadaList;
	CInteraccComponentList	m_cInteraccComponentList;
	CInteraccCalculadaList	m_cEcuacDipolarList;
	CParametroVariableList	m_cParametroVariableList;
	CDistorcion					m_cDistorcion;
	CParametro					m_cInteraccSelecc[3];
	CString m_strParamFichero;
	CString m_strTensoresFichero;
	CString m_strInteraccFichero;
	int 				m_iPosAnilloFenil,
						m_iPosBifenil,
						m_iPosTrifenil;
	int				m_iContador;
	int				m_iLimiteContador;
	
	
public:
	BOOL m_bFlag;
	double m_dTzz;
	double m_dTxxTyy;
	double m_dTyz;
	double m_dTzx;
	double m_dTxy;
	double m_dPorcentaje;
	double m_dErrorAcumulado;
	double m_dMAD;
	double m_dRho;
	double m_dValoresIgnorados;
	int	m_iLimiteImpresion;
	Simetria m_nSimetria;
	int	 m_iDatosGrabados;

	CParteRigida*  pObjParteRigida;
	int 				m_nCuadricula;
	ParteRigida		m_nParteRigida;
	CPunto			m_cPtoInicio, m_cPtoFin;
	CPunto			m_cPtoPlano;
	BOOL				m_bGrid;
public :
	CString m_strFullName;
	int m_iCantEcuacDipolar;
	int m_iCantParamVariab;
	int m_iCantDatosGrabados;
	int m_iReporte;
	
// Operations
public:
	double DevuelveDihedral(void);
	BOOL InicializaElementosT(void);
	CParteRigida* DevuelveParteRigidaPtr(int);
	CInteraccObservada* DevuelveInteraccObservadaPtr(int);
	CInteraccComponent* DevuelveInteraccComponentPtr(int);
	CPunto DevuelveParteRigidaListPunto(CString, CString&);
private:
	
	CString m_strDescripcionDoc;
	CString m_strCreadorDoc;
	CString m_strAsuntoDoc;
	CString m_strTituloDoc;
	CString m_strCalculosFichero;
	CString m_strUnidDistancia;
	CString m_strUnidAngulo;
	CString m_strUnidInteracc;
	CString m_strPlanoGDI;
public :
	void VaciaEcuacDipolarList(void);
	void VaciaParametroVariableList(void);
	void VaciaInteraccComponentList(void);
	void VaciaInteraccObservadaList(void);
	void VaciaParteRigidaList(void);
	void GrabaResultados(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProyectoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:	
	void CalculaDistorcion();
	CInteraccCalculada* DevuelveEcuacDipolarPtr(int);
	CPunto & DevuelvePtoFinalEjeSimetria(void);
	CPunto & DevuelvePtoInicioEjeSimetria(void);
	void DevuelveTensores(CInteraccObservada *pIntrcObs, double & dTzz, double & dTxxMinusTyy, double & dTyz, double & dTzx, double & dTxy);
	CString DevuelvePlanoGDI(void);
	void EstablecePlanoGDI(CString cCadena);
	CInteraccCalculada* DevuelveInteraccionSeleccPtr(CString str);
	int DevuelveSimetria(void);
	CString DevuelveStrUnidInteracc(void);
	CString DevuelveStrUnidDistancia(void);
	CString DevuelveStrUnidAngulo(void);
	void EstableceSimetria(int iValor);
	void EstableceStrUnidInteracc(CString cStr);
	void EstableceStrUnidAngulo(CString cStr);
	void EstableceStrUnidDistancia(CString cStr);
	CString DevuelveStrDescripcionDoc(void);
	CString DevuelveStrCreadorDoc(void);
	CString DevuelveStrAsuntoDoc(void);
	CString DevuelveStrTituloDoc(void);
	void EstableceStrDescripcionDoc(CString strDescripcion);
	void EstableceStrCreadorDoc(CString strCreador);
	void EstableceStrAsuntoDoc(CString strAsunto);
	void EstableceStrTituloDoc(CString strTitulo);
	void EstableceStrCalculosFichero(CString strFichero);
	CString DevuelveStrCalculosFichero(void);
	CString DevuelveStrTensoresFichero(void);
	CString DevuelveStrInteraccFichero(void);
	CString DevuelveStrParamFichero(void);
	void EstableceStrTensoresFichero(CString strFichero);
	void EstableceStrInteraccFichero(CString strFichero);
	void EstableceStrParamFichero(CString strFichero);
	int DevuelveDatosGrabados(void);
	CParametroVariable* DevuelveParamVariabPtr(int iIndex);
	virtual ~CProyectoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
		
// Generated message map functions
protected:
	//{{AFX_MSG(CProyectoDoc)
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CProyectoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROYECTODOC_H__8D2FBB13_B0D3_11D1_85BD_EF8C0852E550__INCLUDED_)
