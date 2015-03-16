// ProyectoDoc.cpp : implementation of the CProyectoDoc class
//

#include "stdafx.h"
#include "Resource.h"
#include "Proyecto.h"
#include "ProyectoDoc.h"
#include "ProyectoView.h"
#include "OpenGLView.h"
#include "MainFrm.h"
#include "SistEcuac.h"
#include "Fichero.h"
#include "Tensor.h"
#include "Rutinas.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProyectoDoc

IMPLEMENT_DYNCREATE(CProyectoDoc, CDocument)

BEGIN_MESSAGE_MAP(CProyectoDoc, CDocument)
	//{{AFX_MSG_MAP(CProyectoDoc)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CProyectoDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CProyectoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IProyecto to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {DC80CA4B-0D48-11D2-B39A-DCF0D4C56A32}
static const IID IID_IProyecto =
{ 0xdc80ca4b, 0xd48, 0x11d2, { 0xb3, 0x9a, 0xdc, 0xf0, 0xd4, 0xc5, 0x6a, 0x32 } };

BEGIN_INTERFACE_MAP(CProyectoDoc, CDocument)
	INTERFACE_PART(CProyectoDoc, IID_IProyecto, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProyectoDoc construction/destruction

CProyectoDoc::CProyectoDoc()
{
	m_dTzz = m_dTxxTyy = m_dTyz = m_dTzx = m_dTxy = 0.0;
	m_dPorcentaje = 10.0;
	m_dErrorAcumulado = 0.0;
	m_nSimetria = D2;
	m_dMAD = 0.0;
	m_iDatosGrabados = 0;
	m_strParamFichero = _T("");
	m_strTensoresFichero = _T("");
	m_strInteraccFichero = _T("");
	m_iPosAnilloFenil = 0;
	m_iPosBifenil = 0;
	m_iPosTrifenil = 0;
	m_iContador = 0;
	m_iLimiteContador = 0;
	m_dValoresIgnorados = 0.000001;
	m_iLimiteImpresion = 25;

	m_bFlag = FALSE;
	m_strUnidDistancia = _T("Amstrong (A)");
	m_strUnidAngulo = _T("Grados");
	m_strUnidInteracc = _T("mHz");
	m_strPlanoGDI = _T("ZX");

	m_nParteRigida = Ninguna;
	pObjParteRigida = NULL;
	m_bGrid = TRUE;
	m_nCuadricula = 1000;
	m_cPtoInicio.Establece(0,0,-1.08); //por mientras
	m_cPtoFin.Establece(0,0,0);//por mientras
	m_cPtoPlano.Establece(300,0,0);	

	EnableAutomation();

	AfxOleLockApp();
}

CProyectoDoc::~CProyectoDoc()
{
	AfxOleUnlockApp();
}

BOOL CProyectoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
		
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CProyectoDoc serialization

void CProyectoDoc::Serialize(CArchive& ar)
{
	// Grabación / Recuperación
	CString strTemp;
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());

	m_cParteRigidaList.Serialize(ar);
	pFrame->Serialize(ar);
	m_cParametroVariableList.Serialize(ar);
	m_cInteraccObservadaList.Serialize(ar);
	m_cInteraccComponentList.Serialize(ar);

	m_cPtoInicio.Serialize(ar);
	m_cPtoFin.Serialize(ar);

	m_cDistorcion.Serialize(ar);
	m_cInteraccSelecc[0].Serialize(ar);
	m_cInteraccSelecc[1].Serialize(ar);
	m_cInteraccSelecc[2].Serialize(ar);
	
	if (ar.IsStoring())
	{
		ar << m_strTituloDoc;
		ar << m_strAsuntoDoc;
		ar << m_strCreadorDoc;
		ar << m_strDescripcionDoc;
		ar << m_iPosAnilloFenil << m_iPosBifenil << m_iPosTrifenil;

		ar << pObjParteRigida;
		ar << m_nCuadricula << m_bGrid  << DevStrParteRigida(m_nParteRigida);
		ar << DevuelveEnumSimetriaAsString(m_nSimetria);

		ar << m_strUnidDistancia;
		ar << m_strUnidAngulo;
		ar << m_strUnidInteracc;
		ar	<< m_dValoresIgnorados;
		ar	<< m_iLimiteImpresion;;
	}
	else
	{
		ar >> m_strTituloDoc;
		ar >> m_strAsuntoDoc;
		ar >> m_strCreadorDoc;
		ar >> m_strDescripcionDoc;
		ar >> m_iPosAnilloFenil >> m_iPosBifenil >> m_iPosTrifenil;

		ar >> pObjParteRigida;
		ar >> m_nCuadricula >> m_bGrid >> strTemp;
		m_nParteRigida = DevuelveIdParteRigida(strTemp);

		ar >> strTemp;
		m_nSimetria = DevuelveStringAsEnumSimetria(strTemp);

		ar >> m_strUnidDistancia;
		ar >> m_strUnidAngulo;
		ar >> m_strUnidInteracc;
		ar	>> m_dValoresIgnorados;
		ar	>> m_iLimiteImpresion;;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CProyectoDoc diagnostics

#ifdef _DEBUG
void CProyectoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProyectoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProyectoDoc commands

BOOL CProyectoDoc::InicializaElementosT(void)
{

	m_dTzz = m_dTxxTyy = m_dTyz = m_dTzx = m_dTxy = 0.0;
	m_iDatosGrabados = 0;

	CFichero cFichero;	// Fichero de Interacciones Calculadas
	if (!cFichero.Abre(m_strInteraccFichero, CFile::modeCreate | CFile::modeReadWrite ))
		return FALSE;
	cFichero.Close();

	//	Fichero de Parámetros
	if (!cFichero.Abre(m_strParamFichero, CFile::modeCreate | CFile::modeReadWrite ))
		return FALSE;
	cFichero.Close();

	//	Fichero de Tensores
	if (!cFichero.Abre(m_strTensoresFichero, CFile::modeCreate | CFile::modeReadWrite ))
		return FALSE;
	cFichero.Close();

	return TRUE;
}



double CProyectoDoc::DevuelveDihedral(void)
{
	for (int iIndex = 0; iIndex < m_cParametroVariableList.GetCount(); iIndex++)
	{
		CParametroVariable *pParamVariab = DevuelveParamVariabPtr(iIndex);
	
		if (pParamVariab != NULL)
		{
			if (pParamVariab->DevuelveEtiqueta() == _T("Dihedral"))
				return pParamVariab->DevuelveValorActual();
		}
	}

	return 0;
}

CPunto CProyectoDoc::DevuelveParteRigidaListPunto(CString strEtiqueta, CString &strTipo)
{
	CPunto cPunto;

	for (int iIndex = 0; iIndex < m_cParteRigidaList.GetCount(); iIndex++)
	{
		CParteRigida *pParteRigida = DevuelveParteRigidaPtr(iIndex);

		if (pParteRigida != NULL)
			if (pParteRigida->DevuelvePuntoEtTipo(strEtiqueta, cPunto, strTipo))
				break;
	}

	return cPunto;
}



void CProyectoDoc::VaciaEcuacDipolarList(void)
{
	while (m_cEcuacDipolarList.GetHeadPosition())
	{
      delete m_cEcuacDipolarList.RemoveHead();
	}
}
	
void CProyectoDoc::VaciaInteraccComponentList(void)
{
	while (m_cInteraccComponentList.GetHeadPosition())
	{
      delete m_cInteraccComponentList.RemoveHead();
	}
}

void CProyectoDoc::VaciaParametroVariableList(void)
{
	while (m_cParametroVariableList.GetHeadPosition())
	{
      delete m_cParametroVariableList.RemoveHead();
	}
}

void CProyectoDoc::VaciaParteRigidaList(void)
{
	while (m_cParteRigidaList.GetHeadPosition())
	{
      delete m_cParteRigidaList.RemoveHead();
	}
}

void CProyectoDoc::VaciaInteraccObservadaList(void)
{
	while (m_cInteraccObservadaList.GetHeadPosition())
	{
      delete m_cInteraccObservadaList.RemoveHead();
	}
}

void CProyectoDoc::GrabaResultados(void)
{
	//	Fichero: Param.txt
	CFichero cFichero;
	if (!cFichero.Abre(m_strParamFichero, CFile::modeWrite ))
		return;

	for (int iIndex = 0; iIndex < m_cParametroVariableList.GetCount(); iIndex++)
	{
		CParametroVariable *pParamVariab = DevuelveParamVariabPtr(iIndex);

		if (pParamVariab != NULL)
		{
			cFichero.Escribe((char*) &(pParamVariab->DevuelveStruct()),
				sizeof(StcParametro));
		}
	}

	cFichero.Close();

	//	Fichero: Interacc.txt
	if (!cFichero.Abre(m_strInteraccFichero,CFile::modeWrite ))
		return;

	for (int iIndex = 0; iIndex < m_cEcuacDipolarList.GetCount(); iIndex++)
	{
		CInteraccCalculada *pEcuacDipolar = DevuelveEcuacDipolarPtr(iIndex);

		if (pEcuacDipolar != NULL)
		{
			CInteraccion *pIntrc = new CInteraccion;
			pIntrc->EstableceEtiqueta1( pEcuacDipolar->DevuelveEtiqueta1() );
			pIntrc->EstableceEtiqueta2( pEcuacDipolar->DevuelveEtiqueta2() );
			pIntrc->EstableceValor( pEcuacDipolar->DevuelveValor() );

			cFichero.Escribe((char*) &(pIntrc->DevuelveStruct()), sizeof(StcValorDual));
			delete pIntrc;
			pIntrc = NULL;
		}
	}

	cFichero.Close();

	// Fichero: Tensores.txt
	if (!cFichero.Abre(m_strTensoresFichero, CFile::modeWrite ))
		return;

	CTensor *pTensor = new CTensor;		// Tzz
	pTensor->EstableceEtiqueta1(_T("z"));
	pTensor->EstableceEtiqueta2(_T("z"));
	pTensor->EstableceValor(m_dTzz);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;

	pTensor = new CTensor;					// TxxTyy
	pTensor->EstableceEtiqueta1(_T("xx"));
	pTensor->EstableceEtiqueta2(_T("yy"));
	pTensor->EstableceValor(m_dTxxTyy);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;

	pTensor = new CTensor;					// Tyz
	pTensor->EstableceEtiqueta1(_T("y"));
	pTensor->EstableceEtiqueta2(_T("z"));
	pTensor->EstableceValor(m_dTyz);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;

	pTensor = new CTensor;					// Tzx
	pTensor->EstableceEtiqueta1(_T("z"));
	pTensor->EstableceEtiqueta2(_T("x"));
	pTensor->EstableceValor(m_dTzx);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;

	pTensor = new CTensor;					// Txy
	pTensor->EstableceEtiqueta1(_T("x"));
	pTensor->EstableceEtiqueta2(_T("y"));
	pTensor->EstableceValor(m_dTxy);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;

	pTensor = new CTensor;					// Error Acumulado
	pTensor->EstableceEtiqueta1(_T("Error Acumulado"));
	pTensor->EstableceEtiqueta2(_T("Error Acumulado"));
	pTensor->EstableceValor(m_dErrorAcumulado);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;

	pTensor = new CTensor;					// MAD
	pTensor->EstableceEtiqueta1(_T("MAD"));
	pTensor->EstableceEtiqueta2(_T("MAD"));
	pTensor->EstableceValor(m_dMAD);
	cFichero.Escribe((char*) &(pTensor->DevuelveStruct()), sizeof(StcValorDual));
	delete pTensor;
	pTensor = NULL;

	cFichero.Close();

	m_iDatosGrabados += 1;
}

CParteRigida* CProyectoDoc::DevuelveParteRigidaPtr(int iIndex)
{
	if (iIndex < 0)
		return NULL;

	POSITION Posicion = NULL;
	Posicion = m_cParteRigidaList.FindIndex(iIndex);

	CParteRigida *pParteRigida = NULL;

	if (Posicion)
	{
		pParteRigida = m_cParteRigidaList.GetAt(Posicion);
		Posicion = NULL;	
	}

	return pParteRigida;
}

CInteraccObservada* CProyectoDoc::DevuelveInteraccObservadaPtr(int iIndex)
{
	if (iIndex < 0)
		return NULL;

	POSITION Posicion = NULL;
	Posicion = m_cInteraccObservadaList.FindIndex(iIndex);

	CInteraccObservada *pIntrcObs = NULL;

	if (Posicion)
	{
		pIntrcObs = m_cInteraccObservadaList.GetAt(Posicion);
		Posicion = NULL;	
	}

	return pIntrcObs;
}

CInteraccComponent* CProyectoDoc::DevuelveInteraccComponentPtr(int iIndex)
{
	if (iIndex < 0)
		return NULL;

	POSITION Posicion = NULL;
	Posicion = m_cInteraccComponentList.FindIndex(iIndex);

	CInteraccComponent *pIntrcComponent = NULL;

	if (Posicion)
	{
		pIntrcComponent = m_cInteraccComponentList.GetAt(Posicion);
		Posicion = NULL;	
	}

	return pIntrcComponent;
}

CInteraccCalculada* CProyectoDoc::DevuelveEcuacDipolarPtr(int iIndex)
{
	if (iIndex < 0)
		return NULL;

	POSITION Posicion = NULL;
	Posicion = m_cEcuacDipolarList.FindIndex(iIndex);

	CInteraccCalculada *pEcuacDipolar = NULL;

	if (Posicion)
	{
		pEcuacDipolar = m_cEcuacDipolarList.GetAt(Posicion);
		Posicion = NULL;	
	}

	return pEcuacDipolar;
}


CParametroVariable* CProyectoDoc::DevuelveParamVariabPtr(int iIndex)
{
	if (iIndex < 0)
		return NULL;

	POSITION Posicion = NULL;
	Posicion = m_cParametroVariableList.FindIndex(iIndex);

	CParametroVariable *pParamVariab = NULL;

	if (Posicion)
	{
		pParamVariab = m_cParametroVariableList.GetAt(Posicion);
		Posicion = NULL;	
	}

	return pParamVariab;
}


int CProyectoDoc::DevuelveDatosGrabados()
{
	return m_iDatosGrabados;
}

void CProyectoDoc::EstableceStrParamFichero(CString strFichero)
{
	m_strParamFichero = strFichero;
}

void CProyectoDoc::EstableceStrInteraccFichero(CString strFichero)
{
	m_strInteraccFichero = strFichero;
}

void CProyectoDoc::EstableceStrTensoresFichero(CString strFichero)
{
	m_strTensoresFichero = strFichero;
}

CString CProyectoDoc::DevuelveStrParamFichero()
{
	return m_strParamFichero;
}

CString CProyectoDoc::DevuelveStrInteraccFichero()
{
	return m_strInteraccFichero;
}

CString CProyectoDoc::DevuelveStrTensoresFichero()
{
	return m_strTensoresFichero;
}

void CProyectoDoc::EstableceStrCalculosFichero(CString strFichero)
{
	m_strCalculosFichero = strFichero;	
}

CString CProyectoDoc::DevuelveStrCalculosFichero()
{
	return m_strCalculosFichero;
}

void CProyectoDoc::EstableceStrTituloDoc(CString strTitulo)
{
	m_strTituloDoc = strTitulo;
}

void CProyectoDoc::EstableceStrAsuntoDoc(CString strAsunto)
{
	m_strAsuntoDoc = strAsunto;
}

void CProyectoDoc::EstableceStrCreadorDoc(CString strCreador)
{
	m_strCreadorDoc = strCreador;
}

void CProyectoDoc::EstableceStrDescripcionDoc(CString strDescripcion)
{
	m_strDescripcionDoc = strDescripcion;
}

CString CProyectoDoc::DevuelveStrTituloDoc()
{
	return m_strTituloDoc;
}

CString CProyectoDoc::DevuelveStrAsuntoDoc()
{
	return m_strAsuntoDoc;
}

CString CProyectoDoc::DevuelveStrCreadorDoc()
{
	return m_strCreadorDoc;
}

CString CProyectoDoc::DevuelveStrDescripcionDoc()
{
	return m_strDescripcionDoc;
}

void CProyectoDoc::DeleteContents() 
{
	if (AfxGetMainWnd() != NULL )
	{
		if ( AfxGetMainWnd()->IsKindOf( RUNTIME_CLASS(CMainFrame) ) )
		{
			m_iPosAnilloFenil = 0;
			m_iPosBifenil = 0;
			m_iPosTrifenil = 0;
			CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());

			if (pFrame != NULL)
			{
				CMainBar* pMainBar = &pFrame->m_wndMainBar;
				pMainBar->m_ObjectsBox.ResetContent();
			}

			VaciaParteRigidaList();
			VaciaInteraccObservadaList();
			VaciaInteraccComponentList();
			VaciaEcuacDipolarList();
			VaciaParametroVariableList();
		}
	}

	CDocument::DeleteContents();
}

void CProyectoDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(IsModified());
}


void CProyectoDoc::EstableceStrUnidDistancia(CString cStr)
{
	m_strUnidDistancia = cStr;
}

void CProyectoDoc::EstableceStrUnidAngulo(CString cStr)
{
	m_strUnidAngulo = cStr;
}

void CProyectoDoc::EstableceStrUnidInteracc(CString cStr)
{
	m_strUnidInteracc = cStr;
}

void CProyectoDoc::EstableceSimetria(int iValor)
{
	switch (iValor)
	{
		case 0:
			m_nSimetria = D4;
			break;
		case 1:
			m_nSimetria = D2;
			break;
		case 2:
			m_nSimetria = NoSimetria;
			break;
	}
}

CString CProyectoDoc::DevuelveStrUnidDistancia()
{
	return m_strUnidDistancia;
}

CString CProyectoDoc::DevuelveStrUnidAngulo()
{
	return m_strUnidAngulo;
}

CString CProyectoDoc::DevuelveStrUnidInteracc()
{
	return m_strUnidInteracc;
}

int CProyectoDoc::DevuelveSimetria()
{
	switch (m_nSimetria)
	{
		case D4:
			return 0;
		case D2:
			return 1;
		case NoSimetria:
			return 2;
	}

	return -1;
}


CInteraccCalculada* CProyectoDoc::DevuelveInteraccionSeleccPtr(CString str)
{
	for (int iPaso = 0; iPaso < m_cEcuacDipolarList.GetCount(); iPaso++)
	{
		CInteraccCalculada *pIntrc= DevuelveEcuacDipolarPtr(iPaso);

		if (pIntrc!= NULL)
		{
			if (pIntrc->DevuelveEtiquetas() == str)
				return pIntrc;
		}
	}

	return NULL;
}

void CProyectoDoc::EstablecePlanoGDI(CString cCadena)
{
	m_strPlanoGDI = cCadena;
}

CString CProyectoDoc::DevuelvePlanoGDI()
{
	return m_strPlanoGDI;
}


void CProyectoDoc::DevuelveTensores(CInteraccObservada * pIntrcObs, double & dTzz, double & dTxxMinusTyy, double & dTyz, double & dTzx, double & dTxy)
{
	if ( pIntrcObs->DevuelveUsoTzz() )
		dTzz = m_dTzz;
	else
		dTzz = 0.0;

	if ( pIntrcObs->DevuelveUsoTxxMinusTyy() )
		dTxxMinusTyy = m_dTxxTyy;
	else
		dTxxMinusTyy = 0.0;

	if ( pIntrcObs->DevuelveUsoTyz() )
		dTyz = m_dTyz;
	else
		dTyz = 0.0;

	if ( pIntrcObs->DevuelveUsoTzx() )
		dTzx = m_dTzx;
	else
		dTzx = 0.0;

	if ( pIntrcObs->DevuelveUsoTxy() )
		dTxy = m_dTxy;
	else
		dTxy = 0.0;
}

CPunto & CProyectoDoc::DevuelvePtoInicioEjeSimetria()
{
	CPunto & cPtoRef = m_cPtoInicio;
	return cPtoRef;
}

CPunto & CProyectoDoc::DevuelvePtoFinalEjeSimetria()
{
	CPunto & cPtoRef = m_cPtoFin;
	return cPtoRef;
}

void CProyectoDoc::CalculaDistorcion()
{
	
	m_cDistorcion.RealizaCalculos();
	m_dRho = m_cDistorcion.DevuelveRho();
	m_dTzz = m_cDistorcion.DevuelveTzz();
	m_dTxxTyy = m_cDistorcion.DevuelveTxxMinusTyy();

}
