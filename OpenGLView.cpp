// OpenGLView.cpp : implementation of the COpenGLView class
// 

#include "Stdafx.h"
#include "Proyecto.h"

#include "ProyectoDoc.h"
#include "OpenGLView.h"
#include "ParteRigida.h"
#include "3DDataSheet.h"
#include "MainFrm.h"
#include "ErrorMsg.h"

#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

unsigned char threeto8[8] = 
{
	0, 0111>>1, 0222>>1, 0333>>1, 0444>>1, 0555>>1, 0666>>1, 0377
};

unsigned char twoto8[4] = 
{
	0, 0x55, 0xaa, 0xff
};

unsigned char oneto8[2] = 
{
	0, 255
};

static int defaultOverride[13] = 
{
	0, 3, 24, 27, 64, 67, 88, 173, 181, 236, 247, 164, 91
};

static PALETTEENTRY defaultPalEntry[20] = 
{
	{ 0,   0,   0,    0 },
	{ 0x80,0,   0,    0 },
	{ 0,   0x80,0,    0 },
	{ 0x80,0x80,0,    0 },
	{ 0,   0,   0x80, 0 },
	{ 0x80,0,   0x80, 0 },
	{ 0,   0x80,0x80, 0 },
	{ 0xC0,0xC0,0xC0, 0 },

	{ 192, 220, 192,  0 },
	{ 166, 202, 240,  0 },
	{ 255, 251, 240,  0 }, 
	{ 160, 160, 164,  0 },
	
	{ 0x80,0x80,0x80, 0 },
	{ 0xFF,0,   0,    0 },
	{ 0,   0xFF,0,    0 },
	{ 0xFF,0xFF,0,    0 },
	{ 0,   0,   0xFF, 0 },
	{ 0xFF,0,   0xFF, 0 },
	{ 0,   0xFF,0xFF, 0 },
	{ 0xFF,0xFF,0xFF, 0 }
};

/////////////////////////////////////////////////////////////////////////////
// COpenGLView
	
IMPLEMENT_DYNCREATE(COpenGLView, CView)

BEGIN_MESSAGE_MAP(COpenGLView, CView)
	//{{AFX_MSG_MAP(COpenGLView)
	ON_COMMAND(ID_OPCIONES_DATOS3D, OnDatos3D)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_VIEW_AXIS, OnViewAxis)
	ON_UPDATE_COMMAND_UI(ID_VIEW_AXIS, OnUpdateViewAxis)
	ON_COMMAND(ID_AXIS_X, OnAxisX)
	ON_UPDATE_COMMAND_UI(ID_AXIS_X, OnUpdateAxisX)
	ON_COMMAND(ID_AXIS_Y, OnAxisY)
	ON_UPDATE_COMMAND_UI(ID_AXIS_Y, OnUpdateAxisY)
	ON_COMMAND(ID_AXIS_Z, OnAxisZ)
	ON_UPDATE_COMMAND_UI(ID_AXIS_Z, OnUpdateAxisZ)
	ON_COMMAND(ID_ROTATE_POSITIVE, OnRotatePositive)
	ON_COMMAND(ID_ROTATE_NEGATIVE, OnRotateNegative)
	ON_COMMAND(ID_APPROACH, OnApproach)
	ON_COMMAND(ID_SEPARATE, OnSeparate)
	ON_COMMAND(ID_VER_BARRA3D, OnVerBarra3D)
	ON_UPDATE_COMMAND_UI(ID_VER_BARRA3D, OnUpdateVerBarra3D)
	ON_WM_TIMER()
	ON_COMMAND(ID_3D_EJECUTAR, On3dEjecutar)
	ON_UPDATE_COMMAND_UI(ID_3D_EJECUTAR, OnUpdate3dEjecutar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLView construction/destruction

COpenGLView::COpenGLView(): m_rectPrint(0, 0, 11505, -15105)
{
	m_pDC = NULL;
	m_pOldPalette = NULL;
	m_fCoordEnZeta = -14;
	m_fValorEnEquis = 0.0f;
	m_fValorEnYe = 0.0f;
	m_fValorEnZeta = 0.0f;
	m_fRotacionEnEquis = 5.0f;
	m_fRotacionEnYe = 5.0f;
	m_fRotacionEnZeta = 5.0f;
	m_bEjeX = FALSE;
	m_bEjeY = FALSE;
	m_bEjeZ = FALSE;
	m_bVerEjes = FALSE;
	m_fZoom = 1.0f;
	m_fCaraFrontal = 3.0f;
	m_fCaraPosterior = 30.0f;
	m_fAngPerspectiva = 45.0f;
	m_bEjecutar = FALSE;
}

COpenGLView::~COpenGLView()
{
}

BOOL COpenGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// An OpenGL window must be created with the following flags and must not
	// include CS_PARENTDC for the class style. Refer to SetPixelFormat
	// documentation in the "Comments" section for further information.
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return CView::PreCreateWindow(cs);
}

void COpenGLView::OnDestroy() 
{
	HGLRC hrc;

	hrc = ::wglGetCurrentContext();
	::wglMakeCurrent(NULL,	NULL);

	if (hrc)
		::wglDeleteContext(hrc);

	if (m_pOldPalette)
		m_pDC->SelectPalette(m_pOldPalette, FALSE);

	if (m_pDC)
		delete m_pDC;

	CView::OnDestroy();
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLView drawing

void COpenGLView::OnDraw(CDC* pDC)
{
	CProyectoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	DrawScene();
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLView diagnostics

#ifdef _DEBUG
void COpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProyectoDoc* COpenGLView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CProyectoDoc, m_pDocument);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLView message handlers

int COpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	Init();	// initialize OpenGL

	return 0;
}

void COpenGLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	if (cy > 0)
	{ 	
		glViewport(0, 0, cx, cy);

		if((m_oldRect.right > cx) || (m_oldRect.bottom > cy))
			RedrawWindow();

		m_oldRect.right = cx;
		m_oldRect.bottom = cy;
	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(m_fAngPerspectiva, (GLdouble)cx/cy, m_fCaraFrontal, m_fCaraPosterior);
		glMatrixMode(GL_MODELVIEW);
	}
}

/////////////////////////////////////////////////////////////////////////////
// GL helper functions

void COpenGLView::Init()
{
	PIXELFORMATDESCRIPTOR pfd;
	int		n;
	HGLRC 	hrc;
	GLfloat	fMaxObjSize;
	
	m_pDC = new CClientDC(this);
	ASSERT(m_pDC != NULL);

	glDrawBuffer(GL_RIGHT);
	
	if (!bSetupPixelFormat())
	  return;

	n = ::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	CreateRGBPalette();

	hrc = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);

	GetClientRect(&m_oldRect);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);

	if (m_oldRect.bottom)
		m_fAspect = (GLfloat)m_oldRect.right/m_oldRect.bottom;
	else	// don't divide by zero, not that we should ever run into that...
		m_fAspect = 1.0f;

	fMaxObjSize = 3.0f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(m_fAngPerspectiva, m_fAspect, m_fCaraFrontal, m_fCaraPosterior);
	glMatrixMode(GL_MODELVIEW);
}

BOOL COpenGLView::bSetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd = 
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
		1,										 // version number
		PFD_DRAW_TO_WINDOW |				 // support window
			PFD_SUPPORT_OPENGL |			 // support OpenGL
			PFD_DOUBLEBUFFER,				 // double buffered
		PFD_TYPE_RGBA,						 // RGBA type
		24, 									 // 24-bit color depth
		0, 0, 0, 0, 0, 0,					 // color bits ignored
		0,										 // no alpha buffer
		0,										 // shift bit ignored
		0,										 // no accumulation buffer
		0, 0, 0, 0,							 // accum bits ignored
		32, 									 // 32-bit z-buffer
		0,										 // no stencil buffer
		0,										 // no auxiliary buffer
		PFD_MAIN_PLANE, 					 // main layer
		0,										 // reserved
		0, 0, 0								 // layer masks ignored
	};
	
	int pixelformat;

	if ( (pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0 )
	{
		MessageBox(MSG20);
		return FALSE;
	}

	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		MessageBox(MSG21);
		return FALSE;
	}

	return TRUE;
}

unsigned char COpenGLView::ComponentFromIndex(int i, UINT nbits, UINT shift)
{
	unsigned char val;

	val = (unsigned char) (i >> shift);
	
	switch (nbits) 
	{
		case 1:
			val &= 0x1;
			return oneto8[val];
		case 2:
			val &= 0x3;
			return twoto8[val];
		case 3:
			val &= 0x7;
			return threeto8[val];
		default:
			return 0;
	}
}

void COpenGLView::CreateRGBPalette()
{
	PIXELFORMATDESCRIPTOR pfd;
	LOGPALETTE *pPal;
	int n, i;

	n = ::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	if (pfd.dwFlags & PFD_NEED_PALETTE)
	{
		n = 1 << pfd.cColorBits;
		pPal = (PLOGPALETTE) new char[sizeof(LOGPALETTE) + n * sizeof(PALETTEENTRY)];

		ASSERT(pPal != NULL);

		pPal->palVersion = 0x300;
		pPal->palNumEntries = n;
		
		for (i = 0; i < n; i++)
		{
			pPal->palPalEntry[i].peRed =
			  ComponentFromIndex(i, pfd.cRedBits, pfd.cRedShift);
			pPal->palPalEntry[i].peGreen =
			  ComponentFromIndex(i, pfd.cGreenBits, pfd.cGreenShift);
			pPal->palPalEntry[i].peBlue =
			  ComponentFromIndex(i, pfd.cBlueBits, pfd.cBlueShift);
			pPal->palPalEntry[i].peFlags = 0;
		}

		/* fix up the palette to include the default GDI palette */
		if ((pfd.cColorBits == 8)									&&
			(pfd.cRedBits	 == 3) && (pfd.cRedShift	== 0) &&
			(pfd.cGreenBits == 3) && (pfd.cGreenShift == 3) &&
			(pfd.cBlueBits  == 2) && (pfd.cBlueShift	== 6)
		  )
		{
			for (i = 1 ; i <= 12 ; i++)
				pPal->palPalEntry[defaultOverride[i]] = defaultPalEntry[i];
		}

		m_cPalette.CreatePalette(pPal);
		delete pPal;

		m_pOldPalette = m_pDC->SelectPalette(&m_cPalette, FALSE);
		m_pDC->RealizePalette();
	}
}

void COpenGLView::DrawScene(void)
{	
	static float ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
	static float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
	static float diffuse1[] = {0.5f, 0.5f, 0.5f, 1.0f};
	static float position[] = {90.0f, 90.0f, 150.0f, 0.0f};
	static float position1[] = {-200.0, -200.0, -200.0, 0.0};
	static BOOL  bBusy = FALSE;
	CParteRigida *pParteAux;
	POSITION posAux;

	if (bBusy)
		return;

	bBusy = TRUE;

	glPushMatrix();

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glFrontFace(GL_CCW);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDepthFunc(GL_LEQUAL);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_AUTO_NORMAL);
 	
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient );
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse );
		glLightfv(GL_LIGHT0, GL_POSITION, position );
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient );
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1 );
		glLightfv(GL_LIGHT1, GL_POSITION, position1);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);

		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);

		glTranslatef(0.0f, 0.0f, m_fCoordEnZeta);

		glRotatef(m_fValorEnEquis, 1.0f, 0.0f, 0.0f);
		glRotatef(m_fValorEnYe, 0.0f, 1.0f, 0.0f);
		glRotatef(m_fValorEnZeta, 0.0f, 0.0f, 1.0f);

		ViewAxisEquis();
		ViewAxisYe();
		ViewAxisZeta();
	
		int i = 0;
		
		posAux = GetDocument()->m_cParteRigidaList.FindIndex(i);
		
		while (posAux != NULL)
		{
			pParteAux = GetDocument()->m_cParteRigidaList.GetAt(posAux);
			pParteAux->MuestraImagen(); 
			i++;
			posAux = GetDocument()->m_cParteRigidaList.FindIndex(i);
		}
		
	glPopMatrix();

	glFinish();
	SwapBuffers(wglGetCurrentDC());

   bBusy = FALSE;
}

void COpenGLView::ViewAxisEquis(void)
{
	if (m_bVerEjes && m_bEjeX)
	{
		glBegin(GL_LINES);

			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(-50.0f, 0.0f, 0.0f);

         glColor3f(1.0f, 0.0f, 1.0f);
         glVertex3f(50.0f, 0.0f, 0.0f);
	
		glEnd();
	}
}

void COpenGLView::ViewAxisYe(void)
{
	if (m_bVerEjes && m_bEjeY)
	{
		glBegin(GL_LINES);

			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, -50.0f, 0.0f);

         glColor3f(1.0f, 0.0f, 1.0f);
         glVertex3f(0.0f, 50.0f, 0.0f);
	
		glEnd();
	}
}

void COpenGLView::ViewAxisZeta(void)
{
	if (m_bVerEjes && m_bEjeZ)
	{
		glBegin(GL_LINES);

			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, -50.0f);
			
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 50.0f);

		glEnd();
	}
}

void COpenGLView::OnViewAxis(void)
{
	m_bVerEjes ^= 1;
	DrawScene();
}

void COpenGLView::OnAxisX(void)
{
	m_bEjeX ^= 1;
	DrawScene();
}

void COpenGLView::OnAxisY(void)
{
	m_bEjeY ^= 1;
	DrawScene();
}

void COpenGLView::OnAxisZ(void)
{
	m_bEjeZ ^= 1;
	DrawScene();
}

void COpenGLView::OnRotatePositive(void)
{
	if (m_bEjeX || m_bEjeY || m_bEjeZ)
	{	
		if (m_bEjeX)
			m_fValorEnEquis += m_fRotacionEnEquis;

		if (m_bEjeY)
			m_fValorEnYe += m_fRotacionEnYe;

		if (m_bEjeZ)
			m_fValorEnZeta += m_fRotacionEnZeta;

		DrawScene();
	}
}

void COpenGLView::OnRotateNegative(void)
{
	if (m_bEjeX || m_bEjeY || m_bEjeZ)
	{
		if (m_bEjeX)
			m_fValorEnEquis -= m_fRotacionEnEquis;

		if (m_bEjeY)
			m_fValorEnYe -= m_fRotacionEnYe;

		if (m_bEjeZ)
			m_fValorEnZeta -= m_fRotacionEnZeta;

		DrawScene();
	}
}

void COpenGLView::OnApproach(void)
{
	m_fCoordEnZeta += m_fZoom;
	DrawScene();
}

void COpenGLView::OnSeparate(void)
{
	m_fCoordEnZeta -= m_fZoom;
	DrawScene();
}

void COpenGLView::OnUpdateViewAxis(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bVerEjes);
}

void COpenGLView::OnUpdateAxisX(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck(m_bEjeX);
}

void COpenGLView::OnUpdateAxisY(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck(m_bEjeY);
}

void COpenGLView::OnUpdateAxisZ(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck(m_bEjeZ);
}

void COpenGLView::OnDatos3D(void) 
{
	C3DDataSheet cSheet("Modificar los datos tridimensionales");
	cSheet.DoModal();
}

void COpenGLView::ActualizaPerspectiva(void)
{
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(m_fAngPerspectiva, m_fAspect, m_fCaraFrontal, m_fCaraPosterior);
	glMatrixMode(GL_MODELVIEW);

	DrawScene();
}

void COpenGLView::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{
		ar << m_fZoom << m_bEjeX << m_bEjeY << m_bEjeZ;
		ar << m_fCoordEnZeta << m_fRotacionEnEquis;
		ar << m_fRotacionEnYe << m_fRotacionEnZeta;
		ar << m_fCaraFrontal << m_fCaraPosterior << m_fAngPerspectiva;
		ar << m_fValorEnEquis << m_fValorEnYe << m_fValorEnZeta;		
	}
	else
	{
		ar >> m_fZoom >> m_bEjeX >> m_bEjeY >> m_bEjeZ;
		ar >> m_fCoordEnZeta >> m_fRotacionEnEquis;
		ar >> m_fRotacionEnYe >> m_fRotacionEnZeta;
		ar >> m_fCaraFrontal >> m_fCaraPosterior >> m_fAngPerspectiva;
		ar >> m_fValorEnEquis >> m_fValorEnYe >> m_fValorEnZeta;
	}
}

void COpenGLView::OnVerBarra3D() 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
		
	BOOL bVisible = ((pFrame->m_wnd3DToolBar.GetStyle() & WS_VISIBLE) != 0);
	pFrame->ShowControlBar(&pFrame->m_wnd3DToolBar, !bVisible, FALSE);
	pFrame->RecalcLayout();
}

void COpenGLView::OnUpdateVerBarra3D(CCmdUI* pCmdUI) 
{
	CMainFrame *pFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	
	pFrame->m_bVerModo3DBar = ((pFrame->m_wnd3DToolBar.GetStyle() & WS_VISIBLE) != 0);
	pCmdUI->SetCheck(	pFrame->m_bVerModo3DBar);
}

void COpenGLView::OnTimer(UINT nIDEvent) 
{
	m_fValorEnEquis += 3;
	m_fValorEnYe += 5;
	m_fValorEnZeta += 1;
	
	DrawScene();
	CView::OnTimer(nIDEvent);
	MSG msg;
	while(::PeekMessage(&msg, m_hWnd, WM_TIMER, WM_TIMER, PM_REMOVE));
}

void COpenGLView::On3dEjecutar() 
{
	m_bEjecutar = m_bEjecutar ? FALSE : TRUE;
	static float wAngleX;
	static float wAngleY;
	static float wAngleZ;
	
	if (m_bEjecutar)
	{
		wAngleX = m_fValorEnEquis;
		wAngleY = m_fValorEnYe;
		wAngleZ = m_fValorEnZeta;
		SetTimer(1, 15, NULL);
	}
	else
	{
		m_fValorEnEquis = wAngleX;
		m_fValorEnYe = wAngleY;
		m_fValorEnZeta = wAngleZ;
		KillTimer(1);
		DrawScene();
	}
}

void COpenGLView::OnUpdate3dEjecutar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bEjecutar);	
}
