// Fichero.cpp: implementation of the CFichero class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Fichero.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFichero::CFichero()
{

}

CFichero::~CFichero()
{

}
//////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////

BOOL CFichero::AbreConDlg(CString cStrFileName)
{
	//	Atributos de cFileDlg
	BOOL bOpenFileDialog = FALSE;
	static char BASED_CODE szDefExt[] = "bin";
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	static char BASED_CODE szFilter[] = "Binary Files (*.bin)|*.bin||";
	
	CFileDialog cFileDlg(bOpenFileDialog, szDefExt, cStrFileName, dwFlags, szFilter, NULL);
	
	switch (cFileDlg.DoModal())
	{
		case IDOK:
			if (!Abre(cFileDlg.GetFileName(), CFile::modeCreate | CFile::modeReadWrite ))
				return FALSE;
			return TRUE;

		case IDCANCEL:
			return FALSE;
	}

	return FALSE;
}

BOOL CFichero::Abre(CString cStrFileName, UINT uAbrirFlags)
{
	TCHAR tFileName[60];

	_tcscpy(tFileName, cStrFileName);

	if (!Open(tFileName, uAbrirFlags))
	{
		TRACE1("CFichero - Archivo %s no pudo abrirse.\n", cStrFileName);
		return FALSE;
	}

	return TRUE;
}

void CFichero::Lee(char *lpBuf, unsigned long ulPosicion, UINT uBytes)
{	
	TRY
	{
		Seek((ulPosicion - 1) * uBytes, CFile::begin);
	}
	CATCH( CFileException, pFileException )
	{
		#ifdef _DEBUG
			afxDump << "No pudo buscar los bytes en el Fichero." << pFileException->m_cause
				<< "\n";
		#endif
	}
	END_CATCH
			
	TRY
	{
		Read(lpBuf, uBytes);
	}
	CATCH( CFileException, pFileException )
	{
		#ifdef _DEBUG
			afxDump << "No pudo leerse el Fichero." << pFileException->m_cause << "\n";
		#endif
	}
	END_CATCH
}

void CFichero::Escribe(const char* lpBuffer, UINT uBytes)
{	
	SeekToEnd();

	TRY
	{
		Write(lpBuffer, uBytes);
	}
	CATCH( CFileException, pFileException )
	{
		#ifdef _DEBUG
			afxDump << "No pudo escribirse en el Fichero." << pFileException->m_cause << "\n";
		#endif
	}
	END_CATCH
}
