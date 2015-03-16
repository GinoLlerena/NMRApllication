# Microsoft Developer Studio Project File - Name="Proyecto" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Proyecto - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Proyecto.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Proyecto.mak" CFG="Proyecto - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Proyecto - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Proyecto - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Proyecto - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 opengl32.lib glu32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /profile

!ENDIF 

# Begin Target

# Name "Proyecto - Win32 Release"
# Name "Proyecto - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\3DDataPage.cpp
# End Source File
# Begin Source File

SOURCE=.\3DDataSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\3DToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\Actualizador.cpp
# End Source File
# Begin Source File

SOURCE=.\Angulo.cpp
# End Source File
# Begin Source File

SOURCE=.\AnguloPage.cpp
# End Source File
# Begin Source File

SOURCE=.\AnguloSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\CalculoTensoresPageDos.cpp
# End Source File
# Begin Source File

SOURCE=.\CalculoTensoresPageUno.cpp
# End Source File
# Begin Source File

SOURCE=.\CalculoTensoresSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ConstructorMolecula.cpp
# End Source File
# Begin Source File

SOURCE=.\CoordEsf.cpp
# End Source File
# Begin Source File

SOURCE=.\Distorcion.cpp
# End Source File
# Begin Source File

SOURCE=.\EjeRotacionPage.cpp
# End Source File
# Begin Source File

SOURCE=.\EjeRotacionSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\EnlacePageOne.cpp
# End Source File
# Begin Source File

SOURCE=.\EnlacePageThree.cpp
# End Source File
# Begin Source File

SOURCE=.\EnlacePageTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\EnlaceSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\Fichero.cpp
# End Source File
# Begin Source File

SOURCE=.\IconosDlgBar.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccCalculada.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccComponentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Interaccion.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccObservada.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccObservadaPageOne.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccObservadaPageTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\InteraccObservadaSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\Lado.cpp
# End Source File
# Begin Source File

SOURCE=.\ListaPartesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainBar.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Material.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathemat.cpp
# End Source File
# Begin Source File

SOURCE=.\Matriz.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectsBox.cpp
# End Source File
# Begin Source File

SOURCE=.\OpenGLView.cpp
# End Source File
# Begin Source File

SOURCE=.\Parametro.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroPageOne.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroPageTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroVariable.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroVariablePageOne.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroVariablePageTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\ParametroVariableSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ParteRigida.cpp
# End Source File
# Begin Source File

SOURCE=.\PartesListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\PreferenciasPageOne.cpp
# End Source File
# Begin Source File

SOURCE=.\PreferenciasPageThree.cpp
# End Source File
# Begin Source File

SOURCE=.\PreferenciasPageTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\PreferenciasSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgressDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PropiedadesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Proyecto.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\Proyecto.hpj

!IF  "$(CFG)" == "Proyecto - Win32 Release"

USERDEP__PROYE="$(ProjDir)\hlp\AfxCore.rtf"	"$(ProjDir)\hlp\AfxPrint.rtf"	
# Begin Custom Build - Making help file...
OutDir=.\Release
ProjDir=.
TargetName=Proyecto
InputPath=.\hlp\Proyecto.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	call "$(ProjDir)\makehelp.bat"

# End Custom Build

!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

USERDEP__PROYE="$(ProjDir)\hlp\AfxCore.rtf"	"$(ProjDir)\hlp\AfxPrint.rtf"	
# Begin Custom Build - Making help file...
OutDir=.\Debug
ProjDir=.
TargetName=Proyecto
InputPath=.\hlp\Proyecto.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	call "$(ProjDir)\makehelp.bat"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Proyecto.odl
# End Source File
# Begin Source File

SOURCE=.\Proyecto.rc
# End Source File
# Begin Source File

SOURCE=.\ProyectoDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ProyectoView.cpp
# End Source File
# Begin Source File

SOURCE=.\PtoPerpendicular.cpp
# End Source File
# Begin Source File

SOURCE=.\Punto3D.cpp
# End Source File
# Begin Source File

SOURCE=.\RealizadorCalculo.cpp
# End Source File
# Begin Source File

SOURCE=.\RealizadorReporte.cpp
# End Source File
# Begin Source File

SOURCE=.\RectaPage.cpp
# End Source File
# Begin Source File

SOURCE=.\RectaSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ResultadosOnePageOne.cpp
# End Source File
# Begin Source File

SOURCE=.\ResultadosOnePageThree.cpp
# End Source File
# Begin Source File

SOURCE=.\ResultadosOnePageTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\ResultadosOneSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\Rutinas.cpp
# End Source File
# Begin Source File

SOURCE=.\Seleccionadora.cpp
# End Source File
# Begin Source File

SOURCE=.\SistEcuac.cpp
# End Source File
# Begin Source File

SOURCE=.\Spin.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TempView.cpp
# End Source File
# Begin Source File

SOURCE=.\Tensor.cpp
# End Source File
# Begin Source File

SOURCE=.\Trigonom.cpp
# End Source File
# Begin Source File

SOURCE=.\ValorDual.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\3DDataPage.h
# End Source File
# Begin Source File

SOURCE=.\3DDataSheet.h
# End Source File
# Begin Source File

SOURCE=.\3DToolBar.h
# End Source File
# Begin Source File

SOURCE=.\Actualizador.h
# End Source File
# Begin Source File

SOURCE=.\Angulo.h
# End Source File
# Begin Source File

SOURCE=.\AnguloPage.h
# End Source File
# Begin Source File

SOURCE=.\AnguloSheet.h
# End Source File
# Begin Source File

SOURCE=.\CalculoTensoresPageDos.h
# End Source File
# Begin Source File

SOURCE=.\CalculoTensoresPageUno.h
# End Source File
# Begin Source File

SOURCE=.\CalculoTensoresSheet.h
# End Source File
# Begin Source File

SOURCE=.\ConstructorMolecula.h
# End Source File
# Begin Source File

SOURCE=.\CoordEsf.h
# End Source File
# Begin Source File

SOURCE=.\Distorcion.h
# End Source File
# Begin Source File

SOURCE=.\EjeRotacionPage.h
# End Source File
# Begin Source File

SOURCE=.\EjeRotacionSheet.h
# End Source File
# Begin Source File

SOURCE=.\EnlacePageOne.h
# End Source File
# Begin Source File

SOURCE=.\EnlacePageThree.h
# End Source File
# Begin Source File

SOURCE=.\EnlacePageTwo.h
# End Source File
# Begin Source File

SOURCE=.\EnlaceSheet.h
# End Source File
# Begin Source File

SOURCE=.\ErrorMsg.h
# End Source File
# Begin Source File

SOURCE=.\Fichero.h
# End Source File
# Begin Source File

SOURCE=.\IconosDlgBar.h
# End Source File
# Begin Source File

SOURCE=.\InteraccCalculada.h
# End Source File
# Begin Source File

SOURCE=.\InteraccComponent.h
# End Source File
# Begin Source File

SOURCE=.\InteraccComponentDlg.h
# End Source File
# Begin Source File

SOURCE=.\Interaccion.h
# End Source File
# Begin Source File

SOURCE=.\InteraccObservada.h
# End Source File
# Begin Source File

SOURCE=.\InteraccObservadaPageOne.h
# End Source File
# Begin Source File

SOURCE=.\InteraccObservadaPageTwo.h
# End Source File
# Begin Source File

SOURCE=.\InteraccObservadaSheet.h
# End Source File
# Begin Source File

SOURCE=.\Lado.h
# End Source File
# Begin Source File

SOURCE=.\ListaPartesDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainBar.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Material.h
# End Source File
# Begin Source File

SOURCE=.\Mathemat.h
# End Source File
# Begin Source File

SOURCE=.\Matriz.h
# End Source File
# Begin Source File

SOURCE=.\ObjectsBox.h
# End Source File
# Begin Source File

SOURCE=.\OpenGLView.h
# End Source File
# Begin Source File

SOURCE=.\Parametro.h
# End Source File
# Begin Source File

SOURCE=.\ParametroPageOne.h
# End Source File
# Begin Source File

SOURCE=.\ParametroPageTwo.h
# End Source File
# Begin Source File

SOURCE=.\ParametroSheet.h
# End Source File
# Begin Source File

SOURCE=.\ParametroVariable.h
# End Source File
# Begin Source File

SOURCE=.\ParametroVariablePageOne.h
# End Source File
# Begin Source File

SOURCE=.\ParametroVariablePageTwo.h
# End Source File
# Begin Source File

SOURCE=.\ParametroVariableSheet.h
# End Source File
# Begin Source File

SOURCE=.\ParteRigida.h
# End Source File
# Begin Source File

SOURCE=.\PartesListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\PreferenciasPageOne.h
# End Source File
# Begin Source File

SOURCE=.\PreferenciasPageThree.h
# End Source File
# Begin Source File

SOURCE=.\PreferenciasPageTwo.h
# End Source File
# Begin Source File

SOURCE=.\PreferenciasSheet.h
# End Source File
# Begin Source File

SOURCE=.\ProgressDlg.h
# End Source File
# Begin Source File

SOURCE=.\PropiedadesDlg.h
# End Source File
# Begin Source File

SOURCE=.\Proyecto.h
# End Source File
# Begin Source File

SOURCE=.\ProyectoDoc.h
# End Source File
# Begin Source File

SOURCE=.\ProyectoView.h
# End Source File
# Begin Source File

SOURCE=.\PtoPerpendicular.h
# End Source File
# Begin Source File

SOURCE=.\Punto3D.h
# End Source File
# Begin Source File

SOURCE=.\RealizadorCalculo.h
# End Source File
# Begin Source File

SOURCE=.\RealizadorReporte.h
# End Source File
# Begin Source File

SOURCE=.\RectaPage.h
# End Source File
# Begin Source File

SOURCE=.\RectaSheet.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ResultadosOnePageOne.h
# End Source File
# Begin Source File

SOURCE=.\ResultadosOnePageThree.h
# End Source File
# Begin Source File

SOURCE=.\ResultadosOnePageTwo.h
# End Source File
# Begin Source File

SOURCE=.\ResultadosOneSheet.h
# End Source File
# Begin Source File

SOURCE=.\Rutinas.h
# End Source File
# Begin Source File

SOURCE=.\Seleccionadora.h
# End Source File
# Begin Source File

SOURCE=.\SistEcuac.h
# End Source File
# Begin Source File

SOURCE=.\Spin.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\Sscommon.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Structures.h
# End Source File
# Begin Source File

SOURCE=.\TempView.h
# End Source File
# Begin Source File

SOURCE=.\Tensor.h
# End Source File
# Begin Source File

SOURCE=.\Trigonom.h
# End Source File
# Begin Source File

SOURCE=.\ValorDual.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\hlp\3DTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\_AnilloFenil.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\_AnilloFenilRotacion.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\_Bifenil.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\_BifenilRotacion.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\_Trifenil.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\_TrifenilRotacion.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AnilloFe.ico
# End Source File
# Begin Source File

SOURCE=.\Res\AnilloFenil.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\Bifenil.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bifenil.ico
# End Source File
# Begin Source File

SOURCE=.\res\CursorAF.cur
# End Source File
# Begin Source File

SOURCE=.\res\CursorBF.cur
# End Source File
# Begin Source File

SOURCE=.\res\CursorTF.cur
# End Source File
# Begin Source File

SOURCE=.\Res\DragParteRigida.cur
# End Source File
# Begin Source File

SOURCE=.\Res\Interacc.ico
# End Source File
# Begin Source File

SOURCE=.\Res\MainFrm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Param.ico
# End Source File
# Begin Source File

SOURCE=.\res\Proyecto.ico
# End Source File
# Begin Source File

SOURCE=.\res\Proyecto.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ProyectoDoc.ico
# End Source File
# Begin Source File

SOURCE=.\Res\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\Tensor.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\Toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\Trifenil.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Trifenil.ico
# End Source File
# Begin Source File

SOURCE=.\Res\TrifenilAvertura.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AfxPrint.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\MakeHelp.bat
# End Source File
# Begin Source File

SOURCE=.\hlp\Proyecto.cnt
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Proyecto.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Proyecto : {65796F72-7463-736F-2056-432B2B5C4E65}
# 	1:17:CG_IDS_DISK_SPACE:126
# 	1:19:CG_IDS_PHYSICAL_MEM:125
# 	1:25:CG_IDS_DISK_SPACE_UNAVAIL:127
# 	2:14:PhysicalMemory:CG_IDS_PHYSICAL_MEM
# 	2:9:DiskSpace:CG_IDS_DISK_SPACE
# 	2:16:SpaceUnavailable:CG_IDS_DISK_SPACE_UNAVAIL
# 	2:7:NewFunc:1
# 	2:10:SysInfoKey:1234
# End Section
# Section Proyecto : {00000000-0000-0000-0000-000000000000}
# 	1:10:IDB_SPLASH:133
# 	2:21:SplashScreenInsertKey:4.0
# End Section
