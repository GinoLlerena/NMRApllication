// ProyectoView.cpp : implementation of the CProyectoView class
//

#include "stdafx.h"
#include "Proyecto.h"
#include "MainFrm.h"
#include "ProyectoDoc.h"
#include "ProyectoView.h"
#include "Rutinas.h"
#include "ListaPartesDlg.h"
#include "AnguloSheet.h"
#include "RectaSheet.h"
#include "EnlaceSheet.h"
#include "EjeRotacionSheet.h"
#include "ParametroSheet.h"
#include "EnlaceSheet.h"
#include "Fichero.h"
#include "ResultadosOneSheet.h"
#include "PropiedadesDlg.h"
#include "Mathemat.h"
#include	"CalculoTensoresSheet.h"
#include "Tensor.h"
#include "PreferenciasSheet.h"
#include "ParametroVariableSheet.h"
#include "ErrorMsg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProyectoView

IMPLEMENT_DYNCREATE(CProyectoView, CView)

BEGIN_MESSAGE_MAP(CProyectoView, CView)
	//{{AFX_MSG_MAP(CProyectoView)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_INSERTAR_ANILLO, OnInsertarPartesrigidasAnillofenil)
	ON_COMMAND(ID_INSERTAR_BIFENIL, OnInsertarPartesrigidasBifenil)
	ON_COMMAND(ID_INSERTAR_TRIFENIL, OnInsertarPartesrigidasTrifenil)
	ON_COMMAND(ID_VER_CUADRICULA, OnViewGrid)
	ON_UPDATE_COMMAND_UI(ID_VER_CUADRICULA, OnUpdateViewGrid)
	ON_COMMAND(ID_VER_LISTAPARTES, OnViewListapartesrigidas)
	ON_COMMAND(ID_ANILLOFENIL_ANGULOS_EXTERNOS, OnAnillofenilAngulosExternos)
	ON_COMMAND(ID_ANILLOFENIL_ANGULOS_INTERNOS, OnAnillofenilAngulosInternos)
	ON_COMMAND(ID_ANILLOFENIL_INFORMACION, OnAnillofenilInformacion)
	ON_COMMAND(ID_ANILLOFENIL_LADOS_EXTERNOS, OnAnillofenilLadosExternos)
	ON_COMMAND(ID_ANILLOFENIL_LADOS_INTERNOS, OnAnillofenilLadosInternos)
	ON_COMMAND(ID_TRIFENIL_INFORMACION, OnTrifenilInformacion)
	ON_COMMAND(ID_TRIFENIL_LADOS, OnTrifenilLados)	
	ON_COMMAND(ID_BIFENIL_ANGULOS, OnBifenilAngulos)
	ON_COMMAND(ID_BIFENIL_INFORMACION, OnBifenilInformacion)
	ON_COMMAND(ID_BIFENIL_LADOS, OnBifenilLados)
	ON_COMMAND(ID_ANILLOFENIL_EJEROTACION, OnAnillofenilEjerotacion)
	ON_COMMAND(ID_BIFENIL_EJEROTACION, OnBifenilEjerotacion)
	ON_COMMAND(ID_TRIFENIL_EJEROTACION, OnTrifenilEjerotacion)
	ON_COMMAND(ID_INSERTAR_INTERACOBS, OnInteracobs)
	ON_COMMAND(ID_CALCULAR_BARRIDO, OnSistecuac)
	ON_COMMAND(ID_VER_BARRAPARTES, OnVerPartesbar)
	ON_UPDATE_COMMAND_UI(ID_VER_BARRAPARTES, OnUpdateVerPartesbar)
	ON_COMMAND(ID_INSERTAR_INTERACCOMP, OnInteraccomp)
	ON_COMMAND(ID_INSERTAR_VARIABLES, OnParametros)
	ON_COMMAND(ID_VER_LISTARESULTADOS, OnVerResults)
	ON_COMMAND(ID_CALCULAR_COMBDADA, OnVerUnoporuno)
	ON_COMMAND(ID_VER_BARRAPRINCIPAL, OnVerBarraprincipal)
	ON_UPDATE_COMMAND_UI(ID_VER_BARRAPRINCIPAL, OnUpdateVerBarraprincipal)
	ON_COMMAND(ID_INSERTAR_INTERACCIONESDEDISTORCION, OnInsertarInteraccionesdedistorcion)
	ON_COMMAND(ID_OPCIONES_PREFERENCIAS, OnOpcionesPreferencias)
	ON_COMMAND(ID_ARCHIVO_PROPIEDADES, OnArchivoPropiedades)
	ON_COMMAND(ID_OPCIONES_REPORTES_CONFORMAC, OnOpcionesReportesConformac)
	ON_COMMAND(ID_OPCIONES_REPORTES_RESULTSXMAD, OnOpcionesReportesResultsxmad)
	ON_COMMAND(ID_TRIFENIL_ANGULOS_ANGULOSALEJEDEPROYECCION, OnTrifenilAngulosAngulosalejedeproyeccion)
	ON_COMMAND(ID_TRIFENIL_ANGULOS_ANGULOSENTRELOSLADOS, OnTrifenilAngulosAngulosentreloslados)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_OPCIONES_REPORTES_RESULTSXERROR, OnOpcionesReportesResultsxerror)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProyectoView construction/destruction

CProyectoView::CProyectoView() : m_rectPrint(0, 0, 11505, -15105)
{
	m_iIndiceArrastre = -1;
}

CProyectoView::~CProyectoView()
{
}

BOOL CProyectoView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProyectoView drawing

void CProyectoView::OnDraw(CDC* pDC)
{
	CDC* pDrawDC = pDC;
	CBrush brush;
	CRect client;
	
	pDC->GetClipBox(client);

	if (!brush.CreateSolidBrush(RGB(255, 255, 255)))
		return;

	brush.UnrealizeObject();
	pDrawDC->FillRect(client, &brush);

	if (!pDC->IsPrinting() && GetDocument()->m_bGrid)
		DrawGrid(pDrawDC);

	POSITION pos;
	pos = GetDocument()->m_cParteRigidaList.Find(GetDocument()->pObjParteRigida);

	if (pos != NULL)
	{
		GetDocument()->pObjParteRigida->EstableceParte(GetDocument()->m_nParteRigida);
		m_cConstructorMolecula.ReconstruyeMolecula();
	}

	int i = 0;
	POSITION posAux = NULL;
	CParteRigida *pParteAux;
		
	posAux = GetDocument()->m_cParteRigidaList.FindIndex(i);

	while (posAux != NULL)
	{
		pParteAux = GetDocument()->m_cParteRigidaList.GetAt(posAux);
		
		if (pos != posAux)
		{
			pParteAux->EstableceColor(RGB(0, 0, 255));
			//pParteAux->EstableceEstilo(PS_SOLID);
			GetDocument()->pObjParteRigida->EstableceGrosor(65);
			pParteAux->MuestraImagenGDI(pDC, GetDocument()->m_nCuadricula, GetDocument()->DevuelvePlanoGDI()); 
			pParteAux->MuestraDescripcion(pDC,GetDocument()->m_nCuadricula, GetDocument()->DevuelvePlanoGDI());
		}
		i++;
		posAux = GetDocument()->m_cParteRigidaList.FindIndex(i);
	}

	if (pos != NULL)
	{	
		GetDocument()->pObjParteRigida->EstableceColor(RGB(0, 0, 0));
		GetDocument()->pObjParteRigida->EstableceEstilo(PS_DASH);
		GetDocument()->pObjParteRigida->EstableceGrosor(50);
		GetDocument()->pObjParteRigida->MuestraImagenGDI(pDC, GetDocument()->m_nCuadricula, GetDocument()->DevuelvePlanoGDI());
		GetDocument()->pObjParteRigida->MuestraDescripcion(pDC,GetDocument()->m_nCuadricula, GetDocument()->DevuelvePlanoGDI());
	}
}

/////////////////////////////////////////////////////////////////////////////
// CProyectoView printing

BOOL CProyectoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	pInfo->SetMaxPage(1);
	return DoPreparePrinting(pInfo);
}

void CProyectoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProyectoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CProyectoView diagnostics

#ifdef _DEBUG
void CProyectoView::AssertValid() const
{
	CView::AssertValid();
}

void CProyectoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProyectoDoc* CProyectoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProyectoDoc)));
	return (CProyectoDoc*) m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProyectoView message handlers

void CProyectoView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	m_rectPrint = pInfo->m_rectDraw;
	TRACE("CProyectoView::OnPrint - rectPrint = (%d, %d, %d, %d)\n",
		m_rectPrint.left, m_rectPrint.top,
		m_rectPrint.right, m_rectPrint.bottom);
	CView::OnPrint(pDC, pInfo);
}

void CProyectoView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu menu;

	switch (GetDocument()->m_nParteRigida)
	{
		case AnilloFenil:
			menu.LoadMenu(IDR_ANILLOFENIL);
			break;
		case Bifenil:
			menu.LoadMenu(IDR_BIFENIL);
			break;
		case Trifenil:
			menu.LoadMenu(IDR_TRIFENIL);
			break;
		default:
			return;
	}
	
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN |
		TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CProyectoView::OnInsertarPartesrigidasAnillofenil() 
{
	if(!m_cConstructorMolecula.InsertaParteRigida(AnilloFenil))
		MessageBox(MSG1, "Advertencia", MB_ICONEXCLAMATION);
	Invalidate(TRUE);
}

void CProyectoView::OnInsertarPartesrigidasBifenil() 
{	
	if(!m_cConstructorMolecula.InsertaParteRigida(Bifenil))
		MessageBox(MSG1, "Advertencia", MB_ICONEXCLAMATION);
	Invalidate(TRUE);
}

void CProyectoView::OnInsertarPartesrigidasTrifenil() 
{	
	if(!m_cConstructorMolecula.InsertaParteRigida(Trifenil))
		MessageBox(MSG1, "Advertencia", MB_ICONEXCLAMATION);
	Invalidate(TRUE);
}

void CProyectoView::DrawGrid(CDC* pDC)
{
	// Center lines
	CPen penDash;
	penDash.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&penDash);
	CRect rect;

	pDC->GetClipBox(&rect);

	pDC->MoveTo(0, rect.top);
	pDC->LineTo(0, rect.bottom );
	pDC->MoveTo(rect.left , 0);
	pDC->LineTo(rect.right, 0);
	
	// Major unit lines
	CPen penDot;
	penDot.CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	pDC->SelectObject(&penDot);

	for (int x = 0; x < rect.right; x += GetDocument()->m_nCuadricula)
	{
		if (x != 0)
		{
			pDC->MoveTo(x, rect.top);
			pDC->LineTo(x, rect.bottom);
			pDC->MoveTo(-x, rect.top);
			pDC->LineTo(-x, rect.bottom);
		}
	}

	for (int y =0; y < rect.top; y += GetDocument()->m_nCuadricula)
	{
		if (y != 0)
		{
			pDC->MoveTo(rect.left, y);
			pDC->LineTo(rect.right, y);
			pDC->MoveTo(rect.left, -y);
			pDC->LineTo(rect.right, -y);
		}
	}

	pDC->SelectObject(pOldPen);
	pDC->SetBkColor(RGB(255, 255, 255));
}

void CProyectoView::OnViewGrid()
{
	GetDocument()->m_bGrid = !GetDocument()->m_bGrid;
	Invalidate(FALSE);
}

void CProyectoView::OnUpdateViewGrid(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->m_bGrid);
}

void CProyectoView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	CRect rect;
	
	GetClientRect(&rect);
	pDC->SetMapMode(MM_HIMETRIC);
	pDC->SetViewportExt(rect.right, -rect.bottom);
	pDC->SetViewportOrg(rect.right / 2, rect.bottom / 2);
	
	CView::OnPrepareDC(pDC, pInfo);
}

void CProyectoView::OnViewListapartesrigidas() 
{
	CListaPartesDlg cListPartes;
	cListPartes.DoModal();
}

////////////////////////////////////////////////////////////////
// Opciones del Menú Emergente del AnilloFenil

void CProyectoView::OnAnillofenilAngulosExternos() 
{
	CAnguloSheet cSheet("Modificar los ángulos externos del anillofenil");
	cSheet.m_nParte = AnilloFenil;
	cSheet.EsAnguloInterno(FALSE);
	cSheet.DoModal();
}

void CProyectoView::OnAnillofenilAngulosInternos() 
{
	CAnguloSheet cSheet("Modificar los ángulos internos del anillofenil");
	cSheet.m_nParte = AnilloFenil;
	cSheet.EsAnguloInterno(TRUE);
	cSheet.DoModal();
}

void CProyectoView::OnAnillofenilEjerotacion() 
{
	CEjeRotacionSheet cSheet("Modificar el eje de rotación del anillo fenil");
	cSheet.PerteneceA(AnilloFenil);
	cSheet.DoModal();
}

void CProyectoView::OnAnillofenilInformacion() 
{
	// TODO: Add your command handler code here
	
}

void CProyectoView::OnAnillofenilLadosExternos() 
{
	CEnlaceSheet cSheet;
	cSheet.SetTitle(_T("Modificar los enlaces del anillo fenil"));
	cSheet.PerteneceA(AnilloFenil);
	cSheet.DoModal();
}

void CProyectoView::OnAnillofenilLadosInternos() 
{
	CRectaSheet cSheet("Modificar los lados internos del anillofenil");
	cSheet.m_nParte = AnilloFenil;
	cSheet.DoModal();	
}

////////////////////////////////////////////////////////////////
// Opciones del Menú Emergente del Bifenil

void CProyectoView::OnBifenilAngulos() 
{
	CAnguloSheet cSheet("Modificar los ángulos del bifenil");
	cSheet.m_nParte = Bifenil;
	cSheet.DoModal();
}

void CProyectoView::OnBifenilEjerotacion() 
{
	CEjeRotacionSheet cSheet("Modificar el eje de rotación de bifenil");
	cSheet.PerteneceA(Bifenil);
	cSheet.DoModal();
}

void CProyectoView::OnBifenilInformacion() 
{
	// TODO: Add your command handler code here
	
}

void CProyectoView::OnBifenilLados() 
{
	CEnlaceSheet cSheet;
	cSheet.SetTitle(_T("Modificar los lados del bifenil"));
	cSheet.PerteneceA(Bifenil);
	cSheet.DoModal();
}

////////////////////////////////////////////////////////////////
// Opciones del Menú Emergente del Trifenil

void CProyectoView::OnTrifenilAngulosAngulosalejedeproyeccion() 
{
	CAnguloSheet cSheet("Modificar los ángulos internos del trifenil");
	cSheet.m_nParte = Trifenil;
	cSheet.EsAnguloInterno(TRUE);
	cSheet.DoModal();	
}

void CProyectoView::OnTrifenilAngulosAngulosentreloslados() 
{
	CAnguloSheet cSheet("Modificar los ángulos internos del trifenil");
	cSheet.m_nParte = Trifenil;
	cSheet.EsAnguloInterno(FALSE);
	cSheet.DoModal();	
}

void CProyectoView::OnTrifenilEjerotacion() 
{
	CEjeRotacionSheet cSheet("Modificar el eje de rotación del trifenil");
	cSheet.PerteneceA(Trifenil);
	cSheet.DoModal();
}

void CProyectoView::OnTrifenilInformacion() 
{
	// TODO: Add your command handler code here
	
}

void CProyectoView::OnTrifenilLados() 
{
	CEnlaceSheet cSheet;
	cSheet.SetTitle(_T("Modificar los lados del trifenil"));
	cSheet.PerteneceA(Trifenil);
	cSheet.DoModal();
}

////////////////////////////////////////////////////////////////////
// Más funciones miembro

void CProyectoView::OnInteracobs() 
{
	m_cActualizador.ActualizaRegistroInteraccionesObservadas(this);
}

void CProyectoView::OnSistecuac() 
{	
	if (VerificaCondiciones())
		ProcesaResultados(TRUE);
}

void CProyectoView::OnVerPartesbar() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	
	BOOL bVisible = ((pFrame->m_wndIconosDlgBar.GetStyle() & WS_VISIBLE) != 0);
	pFrame->ShowControlBar(&pFrame->m_wndIconosDlgBar, !bVisible, FALSE);
	pFrame->RecalcLayout();
	Invalidate(TRUE);
}

void CProyectoView::OnUpdateVerPartesbar(CCmdUI* pCmdUI) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	pFrame->m_bVerPartesBar = ((pFrame->m_wndIconosDlgBar.GetStyle() & WS_VISIBLE) != 0);
	pCmdUI->SetCheck(pFrame->m_bVerPartesBar);
}

void CProyectoView::OnInteraccomp() 
{
	m_cActualizador.ActualizaRegistroInteraccionesComponentes(this);
}

void CProyectoView::OnParametros()
{
	//cActualizador.ActualizaRegistroParametrosVariables();
	CParametroVariableSheet cParametroVariableSheet;
	cParametroVariableSheet.DoModal();
}

void CProyectoView::OnVerResults() 
{
	BOOL bOpenFileDialog = TRUE;
	static char BASED_CODE szDefExt[] = "bin";
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	static char BASED_CODE szFilter[] = "Binary Files (*.bin)|*.bin||";
	CString cStrFileName = _T("Calculos");

	CFileDialog cFileDlg(bOpenFileDialog, szDefExt, cStrFileName, dwFlags, szFilter, NULL);
	CFichero cFichero;
	
	switch (cFileDlg.DoModal())
	{
		case IDOK:
			if (!cFichero.Abre(cFileDlg.GetPathName(), CFile::modeRead))
				return;

			cFichero.Close();
			break;

		case IDCANCEL:
			return;
	}

	// Condiciones del Fichero de Interacciones
	CString cExtFullName = _T("");
	cExtFullName = m_cRealizadorReporte.ComparaStatusDosFicheros(cFileDlg.GetPathName(), 1);

	if (cExtFullName == _T("") )
		return;

	GetDocument()->EstableceStrInteraccFichero(cExtFullName);

	// Condiciones del Fichero de Parámetros
	cExtFullName = m_cRealizadorReporte.ComparaStatusDosFicheros(cFileDlg.GetPathName(), 2);

	if (cExtFullName == _T("") )
		return;

	GetDocument()->EstableceStrParamFichero(cExtFullName);

	// Condiciones del Fichero de Tensores
	cExtFullName = m_cRealizadorReporte.ComparaStatusDosFicheros(cFileDlg.GetPathName(), 3);

	if (cExtFullName == _T("") )
		return;
	
	GetDocument()->EstableceStrTensoresFichero(cExtFullName);
	GetDocument()->EstableceStrCalculosFichero(cFileDlg.GetPathName());

	CResultadosOneSheet cSheet;
	cSheet.DoModal();
}

void CProyectoView::OnVerUnoporuno() 
{
	if (VerificaCondiciones())
		ProcesaResultados(FALSE);
}

void CProyectoView::OnVerBarraprincipal() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	BOOL bVisible = ((pFrame->m_wndMainBar.GetStyle() & WS_VISIBLE) != 0);

	pFrame->ShowControlBar(&pFrame->m_wndMainBar, !bVisible, FALSE);
	pFrame->RecalcLayout();
}

void CProyectoView::OnUpdateVerBarraprincipal(CCmdUI* pCmdUI) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	pFrame->m_bVerMainBar = ((pFrame->m_wndMainBar.GetStyle() & WS_VISIBLE) != 0);
	pCmdUI->SetCheck(pFrame->m_bVerMainBar );
}

void CProyectoView::OnArchivoPropiedades() 
{
	CPropiedadesDlg cDialog;
	cDialog.DoModal();	
}

void CProyectoView::OnInsertarInteraccionesdedistorcion() 
{
	CCalculoTensoresSheet cDlg;
	cDlg.DoModal();	
}

void CProyectoView::OnOpcionesPreferencias() 
{
	CPreferenciasSheet cDlg("Preferencias");
	cDlg.DoModal();	
}

void CProyectoView::OnOpcionesReportesConformac() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	GetDocument()->m_iReporte = 5;

	pFrame->ShowControlBar(&pFrame->m_wndIconosDlgBar, FALSE, FALSE);
	pFrame->ShowControlBar(&pFrame->m_wndMainBar, FALSE, FALSE);
	pFrame->SwitchToView(TEMP);	

	
}


void CProyectoView::OnOpcionesReportesResultsxmad() 
{
	GetDocument()->m_iReporte = 7;
	ReportaInformacion();
}

BOOL CProyectoView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	CPoint cPtoCursor;
	GetCursorPos(&cPtoCursor);
	ScreenToClient(&cPtoCursor);

	if (ChildWindowFromPoint(cPtoCursor) != this)
		return FALSE;

	if (m_iIndiceArrastre != -1)
		SetCursor( AfxGetApp()->LoadCursor(IDC_CURSORDRAG) );
	else
		SetCursor( AfxGetApp()->LoadStandardCursor(IDC_ARROW) );

	return TRUE;
}

void CProyectoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	switch (m_iIndiceArrastre)
	{
		case 0:
			OnInsertarPartesrigidasAnillofenil();
			break;
		case 1:
			OnInsertarPartesrigidasBifenil();
			break;
		case 2:
			OnInsertarPartesrigidasTrifenil();
			break;
	}
	
	m_iIndiceArrastre = -1;
}

void CProyectoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (nFlags != MK_LBUTTON)
		m_iIndiceArrastre = -1;
}

BOOL CProyectoView::VerificaCondiciones()
{
		if (GetDocument()->m_cParteRigidaList.IsEmpty())
	{
		MessageBox(MSG4, "Advertencia", MB_ICONEXCLAMATION);
		return FALSE;
	}

	if (GetDocument()->m_cInteraccObservadaList.IsEmpty())
	{
		MessageBox(MSG5, "Advertencia", MB_ICONEXCLAMATION);
		return FALSE;
	}

	int iSimetria = GetDocument()->DevuelveSimetria();
	int iIndice;
	
	switch (iSimetria)
	{
		case 0:	// Simetría D4
			for (iIndice = 0; iIndice <= 1; iIndice++)
			{
				if ( GetDocument()->m_cInteraccSelecc[iIndice].DevuelveEtiqueta().IsEmpty() )
				{
					MessageBox(MSG6, "Advertencia", MB_ICONEXCLAMATION);
					return FALSE;
				}
			}
			break;

		case 1:	// Simetría D2
		case 2:	// Sin Simetría
			for (iIndice = 0; iIndice <= 2; iIndice++)
			{
				if ( GetDocument()->m_cInteraccSelecc[iIndice].DevuelveEtiqueta().IsEmpty() )
				{
					MessageBox(MSG6, "Advertencia", MB_ICONEXCLAMATION);
					return FALSE;
				}
			}

			if ( iSimetria == 2)
			{
				if ( GetDocument()->m_cDistorcion.DevuelveEtiquetasInteraccA().IsEmpty() )
				{
					MessageBox(MSG6, "Advertencia", MB_ICONEXCLAMATION);
					return FALSE;
				}
				
				if ( GetDocument()->m_cDistorcion.DevuelveEtiquetasInteraccB().IsEmpty() )
				{
					MessageBox(MSG6, "Advertencia", MB_ICONEXCLAMATION);
					return FALSE;
				}

				if ( GetDocument()->m_cDistorcion.DevuelveEtiquetasInteraccC().IsEmpty() )
				{
					MessageBox(MSG6, "Advertencia", MB_ICONEXCLAMATION);
					return FALSE;
				}
			}
			break;
	}

	return TRUE;
}

void CProyectoView::ProcesaResultados(BOOL bBandera)
{
	if(!bBandera) {
		CParametroSheet cParamSheet;
		cParamSheet.DoModal();
	}

	BOOL bOpenFileDialog = FALSE;
	static char BASED_CODE szDefExt[] = "bin";
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	static char BASED_CODE szFilter[] = "Binary Files (*.bin)|*.bin||";
	CString cStrFileName = _T("Calculos");

	CFileDialog cFileDlg(bOpenFileDialog, szDefExt, cStrFileName, dwFlags, szFilter, NULL);
	CString strPath = _T("");
	CFichero cFichero;
	
	switch (cFileDlg.DoModal())
	{
		case IDOK:
			if (!cFichero.Abre(cFileDlg.GetPathName(), CFile::modeCreate | 
				CFile::modeReadWrite))
				return; 

			cFichero.Close();

			strPath = 
				(cFileDlg.GetPathName()).Left((cFileDlg.GetPathName()).GetLength() - 3);

			GetDocument()->EstableceStrCalculosFichero(cFileDlg.GetPathName());
			GetDocument()->EstableceStrInteraccFichero(_T(strPath + "int"));
			GetDocument()->EstableceStrParamFichero(_T(strPath + "par"));
			GetDocument()->EstableceStrTensoresFichero(_T(strPath + "ten"));
			break;

		case IDCANCEL:
			return;
	}

	m_cRealizadorCalculo.EstableceConstructorMolecula(&m_cConstructorMolecula);

	if (bBandera)
		m_cRealizadorCalculo.RealizaBarridoDeParametros(this);
	else
		m_cRealizadorCalculo.RealizaCombinacionParametro(this);

	CFileStatus cInteraccFileStatus;
	CFileStatus cParamFileStatus;
	CFileStatus cTensoresFileStatus;

	if (!cFichero.Abre(GetDocument()->DevuelveStrInteraccFichero(), CFile::modeRead))
		return;

	cFichero.GetStatus(cInteraccFileStatus);
	cFichero.Close();

	if (!cFichero.Abre(GetDocument()->DevuelveStrParamFichero(), CFile::modeRead))
		return;

	cFichero.GetStatus(cParamFileStatus);
	cFichero.Close();

	if (!cFichero.Abre(GetDocument()->DevuelveStrTensoresFichero(), CFile::modeRead))
		return;

	cFichero.GetStatus(cTensoresFileStatus);
	cFichero.Close();

	if (!cFichero.Abre(cFileDlg.GetPathName(), CFile::modeWrite))
		return;

	cFichero.Escribe((char*) &cInteraccFileStatus, sizeof(CFileStatus));
	cFichero.Escribe((char*) &cParamFileStatus, sizeof(CFileStatus));
	cFichero.Escribe((char*) &cTensoresFileStatus, sizeof(CFileStatus));
	int iCantidad = GetDocument()->m_cInteraccObservadaList.GetCount();
	//int iCantidad = GetDocument()->m_cEcuacDipolarList.GetCount();
	cFichero.Escribe((char*) &iCantidad, sizeof(int));
	iCantidad = GetDocument()->m_cParametroVariableList.GetCount();
	cFichero.Escribe((char*) &iCantidad, sizeof(int));
	iCantidad = GetDocument()->DevuelveDatosGrabados();
	cFichero.Escribe((char*) &iCantidad, sizeof(int));
	cFichero.Close();

	CResultadosOneSheet cResultSheet;
	cResultSheet.DoModal();
}

void CProyectoView::ReportaInformacion()
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());


	BOOL bOpenFileDialog = TRUE;
	static char BASED_CODE szDefExt[] = "bin";
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	static char BASED_CODE szFilter[] = "Binary Files (*.bin)|*.bin||";
	CString cStrFileName = _T("Calculos");

	CFichero cFichero;
	CFileDialog cFileDlg(bOpenFileDialog, szDefExt, cStrFileName, dwFlags, szFilter, NULL);
	switch (cFileDlg.DoModal())
	{
		case IDOK:
			if (!cFichero.Abre(cFileDlg.GetPathName(), CFile::modeRead))
				return;

			cFichero.Seek(sizeof(CFileStatus) * 3, CFile::begin);
			cFichero.Read( (char*) &GetDocument()->m_iCantEcuacDipolar, sizeof(int) );
		
			cFichero.Seek( (sizeof(CFileStatus) * 3) + sizeof(int), CFile::begin);
			cFichero.Read( (char*) &GetDocument()->m_iCantParamVariab, sizeof(int) );

			cFichero.Seek( (sizeof(CFileStatus) * 3) + (sizeof(int) * 2), CFile::begin);
			cFichero.Read( (char*) &GetDocument()->m_iCantDatosGrabados, sizeof(int) );

			cFichero.Close();
			break;

		case IDCANCEL:
			return ;
	}
	 
	GetDocument()->m_strFullName = cFileDlg.GetPathName();
	pFrame->ShowControlBar(&pFrame->m_wndIconosDlgBar, FALSE, FALSE);
	pFrame->ShowControlBar(&pFrame->m_wndMainBar, FALSE, FALSE);
	pFrame->SwitchToView(TEMP);
	

}

void CProyectoView::OnOpcionesReportesResultsxerror() 
{
	GetDocument()->m_iReporte = 6;
	ReportaInformacion();
}
