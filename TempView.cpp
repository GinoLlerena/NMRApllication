// TempView.cpp : implementation file
//

#include "stdafx.h"
#include "proyecto.h"
#include "TempView.h"
#include "ProyectoDoc.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTempView

IMPLEMENT_DYNCREATE(CTempView, CScrollView)

CTempView::CTempView() 
{
	m_iPage = 0;
}

CTempView::~CTempView()
{
}


BEGIN_MESSAGE_MAP(CTempView, CScrollView)
	//{{AFX_MSG_MAP(CTempView)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTempView drawing

void CTempView::OnDraw(CDC* pDC)
{
	CFont font;
	int nHeight;
	TEXTMETRIC tm;

	font.CreateFont(-200, 0, 0, 0, 400, FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_ROMAN, "Times New Roman");
	CFont* pOldFont = (CFont*) pDC->SelectObject(&font);
	pDC->GetTextMetrics(&tm);
	nHeight = tm.tmHeight + tm.tmExternalLeading;
	switch(GetDocument()->m_iReporte) {
		case 6 :
		case 7 :
			m_cRealizadorReporte.ImprimeSeleccion(pDC, GetDocument()->m_iReporte,m_iPage);
			m_iTotalPage = m_cRealizadorReporte.m_cSeleccion.DevuelveCantidadDatos();
			break;
		default :
			m_cRealizadorReporte.ImprimeReporteConformacion( pDC, m_iPage);
			m_iTotalPage = GetDocument()->m_cParteRigidaList.GetCount();
			break;
	}
	pDC->SelectObject(pOldFont);

}

/////////////////////////////////////////////////////////////////////////////
// CTempView diagnostics

#ifdef _DEBUG
void CTempView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CTempView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CProyectoDoc* CTempView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProyectoDoc)));
	return (CProyectoDoc*) m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTempView message handlers

void CTempView::SwitchToGDI()
{
	
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());

	if (pFrame->m_bVerPartesBar)
		pFrame->m_wndIconosDlgBar.ShowWindow(SW_SHOW);

	if (pFrame->m_bVerMainBar)
		pFrame->m_wndMainBar.ShowWindow(SW_SHOW);

	pFrame->m_wnd3DToolBar.ShowWindow(SW_HIDE);
	pFrame->SwitchToView(GDI);
	
}	


void CTempView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	CSize sizeTotal(11520, 15120);
	CSize sizePage(sizeTotal.cx/2,
						sizeTotal.cy/2);
	CSize sizeLine(sizeTotal.cx/100,
						sizeTotal.cy/100);
	SetScrollSizes(MM_TWIPS, sizeTotal, sizePage, sizeLine);
	
}

BOOL CTempView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	pInfo->SetMaxPage(m_iTotalPage );
	return DoPreparePrinting(pInfo);
}


void CTempView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	switch (nChar) {
    case VK_UP:
      OnVScroll(SB_LINEUP, 0, NULL);
      break;
    case VK_DOWN:
      OnVScroll(SB_LINEDOWN, 0, NULL);
      break;
	 case VK_PRIOR:
       if(m_iPage>0){
			m_iPage--;
			Invalidate(TRUE);
		 }
		 break;
    case VK_NEXT:
       if(m_iPage < m_iTotalPage-1) {
			m_iPage++;
			Invalidate(TRUE);
		 }
	   break;
    case VK_ESCAPE:
		pFrame->ShowControlBar(&pFrame->m_wndIconosDlgBar, pFrame->m_bVerPartesBar, TRUE);
		pFrame->ShowControlBar(&pFrame->m_wndMainBar, pFrame->m_bVerMainBar, TRUE);
		pFrame->ShowControlBar(&pFrame->m_wnd3DToolBar, FALSE, TRUE);
		pFrame->SwitchToView(GDI);
      break;
    default:
      break;
    }
}




void CTempView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	CFont font;
	int nHeight;
	TEXTMETRIC tm;


	int iPage = pInfo->m_nCurPage-1;
	font.CreateFont(-200, 0, 0, 0, 400, FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_ROMAN, "Times New Roman");
	CFont* pOldFont = (CFont*) pDC->SelectObject(&font);
	pDC->GetTextMetrics(&tm);
	nHeight = tm.tmHeight + tm.tmExternalLeading;
	switch(GetDocument()->m_iReporte) {
		case 6 :
		case 7 :
			m_cRealizadorReporte.ImprimeSeleccion(pDC, GetDocument()->m_iReporte,iPage);
			break;
		default :
			m_cRealizadorReporte.ImprimeReporteConformacion( pDC, iPage);
			break;
	}
	PrintPageFooter(pDC, iPage);
	pDC->SelectObject(pOldFont);

}

void CTempView::PrintPageFooter(CDC * pDC, int iPage)
{
    CString str;

    CPoint point(700, -15000); // move 10 inches down
	 switch(GetDocument()->m_iReporte) {
		case 6 :
		case 7 :
			str.Format("Documento %s", (LPCSTR) GetDoc()->m_strFullName);
			break;
		default :
			 str.Format("Documento %s", (LPCSTR) GetDocument()->GetTitle());
			break;
	}
    
	 pDC->TextOut(point.x, point.y, str);
    str.Format("Page %d", iPage+1);
    CSize size = pDC->GetTextExtent(str);
    point.x += 10300 - size.cx;
    pDC->TextOut(point.x, point.y, str); // right-justified


}
