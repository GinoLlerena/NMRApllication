# Microsoft Developer Studio Generated NMAKE File, Based on Proyecto.dsp
!IF "$(CFG)" == ""
CFG=Proyecto - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Proyecto - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Proyecto - Win32 Release" && "$(CFG)" !=\
 "Proyecto - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Proyecto - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Proyecto.exe" "$(OUTDIR)\Proyecto.bsc"

!ELSE 

ALL : "$(OUTDIR)\Proyecto.exe" "$(OUTDIR)\Proyecto.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Angulo.obj"
	-@erase "$(INTDIR)\Angulo.sbr"
	-@erase "$(INTDIR)\AnguloPage.obj"
	-@erase "$(INTDIR)\AnguloPage.sbr"
	-@erase "$(INTDIR)\AnguloSheet.obj"
	-@erase "$(INTDIR)\AnguloSheet.sbr"
	-@erase "$(INTDIR)\AnilloFenil.obj"
	-@erase "$(INTDIR)\AnilloFenil.sbr"
	-@erase "$(INTDIR)\BIFENIL.OBJ"
	-@erase "$(INTDIR)\BIFENIL.SBR"
	-@erase "$(INTDIR)\Cilindro.obj"
	-@erase "$(INTDIR)\Cilindro.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\Material.obj"
	-@erase "$(INTDIR)\Material.sbr"
	-@erase "$(INTDIR)\Proyecto.obj"
	-@erase "$(INTDIR)\Proyecto.pch"
	-@erase "$(INTDIR)\Proyecto.res"
	-@erase "$(INTDIR)\Proyecto.sbr"
	-@erase "$(INTDIR)\ProyectoDoc.obj"
	-@erase "$(INTDIR)\ProyectoDoc.sbr"
	-@erase "$(INTDIR)\ProyectoView.obj"
	-@erase "$(INTDIR)\ProyectoView.sbr"
	-@erase "$(INTDIR)\Punto3D.obj"
	-@erase "$(INTDIR)\Punto3D.sbr"
	-@erase "$(INTDIR)\RectaPage.obj"
	-@erase "$(INTDIR)\RectaPage.sbr"
	-@erase "$(INTDIR)\RectaSheet.obj"
	-@erase "$(INTDIR)\RectaSheet.sbr"
	-@erase "$(INTDIR)\Rutinas.obj"
	-@erase "$(INTDIR)\Rutinas.sbr"
	-@erase "$(INTDIR)\Spin.obj"
	-@erase "$(INTDIR)\Spin.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TRIFENIL.OBJ"
	-@erase "$(INTDIR)\TRIFENIL.SBR"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Proyecto.bsc"
	-@erase "$(OUTDIR)\Proyecto.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Proyecto.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0xc0a /fo"$(INTDIR)\Proyecto.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Proyecto.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Angulo.sbr" \
	"$(INTDIR)\AnguloPage.sbr" \
	"$(INTDIR)\AnguloSheet.sbr" \
	"$(INTDIR)\AnilloFenil.sbr" \
	"$(INTDIR)\BIFENIL.SBR" \
	"$(INTDIR)\Cilindro.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\Material.sbr" \
	"$(INTDIR)\Proyecto.sbr" \
	"$(INTDIR)\ProyectoDoc.sbr" \
	"$(INTDIR)\ProyectoView.sbr" \
	"$(INTDIR)\Punto3D.sbr" \
	"$(INTDIR)\RectaPage.sbr" \
	"$(INTDIR)\RectaSheet.sbr" \
	"$(INTDIR)\Rutinas.sbr" \
	"$(INTDIR)\Spin.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TRIFENIL.SBR"

"$(OUTDIR)\Proyecto.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Proyecto.pdb" /machine:I386 /out:"$(OUTDIR)\Proyecto.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Angulo.obj" \
	"$(INTDIR)\AnguloPage.obj" \
	"$(INTDIR)\AnguloSheet.obj" \
	"$(INTDIR)\AnilloFenil.obj" \
	"$(INTDIR)\BIFENIL.OBJ" \
	"$(INTDIR)\Cilindro.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Material.obj" \
	"$(INTDIR)\Proyecto.obj" \
	"$(INTDIR)\Proyecto.res" \
	"$(INTDIR)\ProyectoDoc.obj" \
	"$(INTDIR)\ProyectoView.obj" \
	"$(INTDIR)\Punto3D.obj" \
	"$(INTDIR)\RectaPage.obj" \
	"$(INTDIR)\RectaSheet.obj" \
	"$(INTDIR)\Rutinas.obj" \
	"$(INTDIR)\Spin.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TRIFENIL.OBJ"

"$(OUTDIR)\Proyecto.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Proyecto.exe"

!ELSE 

ALL : "$(OUTDIR)\Proyecto.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Angulo.obj"
	-@erase "$(INTDIR)\AnguloPage.obj"
	-@erase "$(INTDIR)\AnguloSheet.obj"
	-@erase "$(INTDIR)\AnilloFenil.obj"
	-@erase "$(INTDIR)\BIFENIL.OBJ"
	-@erase "$(INTDIR)\Cilindro.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Material.obj"
	-@erase "$(INTDIR)\Proyecto.obj"
	-@erase "$(INTDIR)\Proyecto.pch"
	-@erase "$(INTDIR)\Proyecto.res"
	-@erase "$(INTDIR)\ProyectoDoc.obj"
	-@erase "$(INTDIR)\ProyectoView.obj"
	-@erase "$(INTDIR)\Punto3D.obj"
	-@erase "$(INTDIR)\RectaPage.obj"
	-@erase "$(INTDIR)\RectaSheet.obj"
	-@erase "$(INTDIR)\Rutinas.obj"
	-@erase "$(INTDIR)\Spin.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TRIFENIL.OBJ"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Proyecto.exe"
	-@erase "$(OUTDIR)\Proyecto.ilk"
	-@erase "$(OUTDIR)\Proyecto.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\Proyecto.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0xc0a /fo"$(INTDIR)\Proyecto.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Proyecto.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\Proyecto.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\Proyecto.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Angulo.obj" \
	"$(INTDIR)\AnguloPage.obj" \
	"$(INTDIR)\AnguloSheet.obj" \
	"$(INTDIR)\AnilloFenil.obj" \
	"$(INTDIR)\BIFENIL.OBJ" \
	"$(INTDIR)\Cilindro.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Material.obj" \
	"$(INTDIR)\Proyecto.obj" \
	"$(INTDIR)\Proyecto.res" \
	"$(INTDIR)\ProyectoDoc.obj" \
	"$(INTDIR)\ProyectoView.obj" \
	"$(INTDIR)\Punto3D.obj" \
	"$(INTDIR)\RectaPage.obj" \
	"$(INTDIR)\RectaSheet.obj" \
	"$(INTDIR)\Rutinas.obj" \
	"$(INTDIR)\Spin.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TRIFENIL.OBJ"

"$(OUTDIR)\Proyecto.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "Proyecto - Win32 Release" || "$(CFG)" ==\
 "Proyecto - Win32 Debug"
SOURCE=.\Angulo.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_ANGUL=\
	".\Angulo.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Angulo.obj"	"$(INTDIR)\Angulo.sbr" : $(SOURCE) $(DEP_CPP_ANGUL)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_ANGUL=\
	".\Angulo.h"\
	

"$(INTDIR)\Angulo.obj" : $(SOURCE) $(DEP_CPP_ANGUL) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\AnguloPage.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_ANGULO=\
	".\AnguloPage.h"\
	".\Proyecto.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AnguloPage.obj"	"$(INTDIR)\AnguloPage.sbr" : $(SOURCE)\
 $(DEP_CPP_ANGULO) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_ANGULO=\
	".\AnguloPage.h"\
	".\Proyecto.h"\
	

"$(INTDIR)\AnguloPage.obj" : $(SOURCE) $(DEP_CPP_ANGULO) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\AnguloSheet.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_ANGULOS=\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\Proyecto.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AnguloSheet.obj"	"$(INTDIR)\AnguloSheet.sbr" : $(SOURCE)\
 $(DEP_CPP_ANGULOS) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_ANGULOS=\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\Proyecto.h"\
	

"$(INTDIR)\AnguloSheet.obj" : $(SOURCE) $(DEP_CPP_ANGULOS) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\AnilloFenil.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_ANILL=\
	".\Angulo.h"\
	".\AnilloFenil.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	".\StdAfx.h"\
	

"$(INTDIR)\AnilloFenil.obj"	"$(INTDIR)\AnilloFenil.sbr" : $(SOURCE)\
 $(DEP_CPP_ANILL) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_ANILL=\
	".\Angulo.h"\
	".\AnilloFenil.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	

"$(INTDIR)\AnilloFenil.obj" : $(SOURCE) $(DEP_CPP_ANILL) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\BIFENIL.CPP

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_BIFEN=\
	".\Angulo.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\SSCOMMON.H"\
	".\StdAfx.h"\
	

"$(INTDIR)\BIFENIL.OBJ"	"$(INTDIR)\BIFENIL.SBR" : $(SOURCE) $(DEP_CPP_BIFEN)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_BIFEN=\
	".\Angulo.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\SSCOMMON.H"\
	

"$(INTDIR)\BIFENIL.OBJ" : $(SOURCE) $(DEP_CPP_BIFEN) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Cilindro.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_CILIN=\
	".\Cilindro.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Cilindro.obj"	"$(INTDIR)\Cilindro.sbr" : $(SOURCE) $(DEP_CPP_CILIN)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_CILIN=\
	".\Cilindro.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	

"$(INTDIR)\Cilindro.obj" : $(SOURCE) $(DEP_CPP_CILIN) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_MAINF=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\MainFrm.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\StdAfx.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_MAINF=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\MainFrm.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Material.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_MATER=\
	".\Material.h"\
	".\SSCOMMON.H"\
	".\StdAfx.h"\
	

"$(INTDIR)\Material.obj"	"$(INTDIR)\Material.sbr" : $(SOURCE) $(DEP_CPP_MATER)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_MATER=\
	".\Material.h"\
	".\SSCOMMON.H"\
	

"$(INTDIR)\Material.obj" : $(SOURCE) $(DEP_CPP_MATER) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Proyecto.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_PROYE=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\MainFrm.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\StdAfx.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\Proyecto.obj"	"$(INTDIR)\Proyecto.sbr" : $(SOURCE) $(DEP_CPP_PROYE)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_PROYE=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\MainFrm.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\Proyecto.obj" : $(SOURCE) $(DEP_CPP_PROYE) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Proyecto.rc
DEP_RSC_PROYEC=\
	".\res\Proyecto.ico"\
	".\res\Proyecto.rc2"\
	".\res\ProyectoDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\Proyecto.res" : $(SOURCE) $(DEP_RSC_PROYEC) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ProyectoDoc.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_PROYECT=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\StdAfx.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\ProyectoDoc.obj"	"$(INTDIR)\ProyectoDoc.sbr" : $(SOURCE)\
 $(DEP_CPP_PROYECT) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_PROYECT=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\ProyectoDoc.obj" : $(SOURCE) $(DEP_CPP_PROYECT) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\ProyectoView.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_PROYECTO=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	".\StdAfx.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\ProyectoView.obj"	"$(INTDIR)\ProyectoView.sbr" : $(SOURCE)\
 $(DEP_CPP_PROYECTO) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_PROYECTO=\
	".\Angulo.h"\
	".\AnguloPage.h"\
	".\AnguloSheet.h"\
	".\AnilloFenil.h"\
	".\Bifenil.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Proyecto.h"\
	".\ProyectoDoc.h"\
	".\ProyectoView.h"\
	".\Punto3D.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	".\Trifenil.h"\
	

"$(INTDIR)\ProyectoView.obj" : $(SOURCE) $(DEP_CPP_PROYECTO) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Punto3D.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_PUNTO=\
	".\Punto3D.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Punto3D.obj"	"$(INTDIR)\Punto3D.sbr" : $(SOURCE) $(DEP_CPP_PUNTO)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_PUNTO=\
	".\Punto3D.h"\
	

"$(INTDIR)\Punto3D.obj" : $(SOURCE) $(DEP_CPP_PUNTO) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\RectaPage.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_RECTA=\
	".\Proyecto.h"\
	".\RectaPage.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RectaPage.obj"	"$(INTDIR)\RectaPage.sbr" : $(SOURCE)\
 $(DEP_CPP_RECTA) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_RECTA=\
	".\Proyecto.h"\
	".\RectaPage.h"\
	

"$(INTDIR)\RectaPage.obj" : $(SOURCE) $(DEP_CPP_RECTA) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\RectaSheet.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_RECTAS=\
	".\Proyecto.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RectaSheet.obj"	"$(INTDIR)\RectaSheet.sbr" : $(SOURCE)\
 $(DEP_CPP_RECTAS) "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_RECTAS=\
	".\Proyecto.h"\
	".\RectaPage.h"\
	".\RectaSheet.h"\
	

"$(INTDIR)\RectaSheet.obj" : $(SOURCE) $(DEP_CPP_RECTAS) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Rutinas.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_RUTIN=\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Rutinas.obj"	"$(INTDIR)\Rutinas.sbr" : $(SOURCE) $(DEP_CPP_RUTIN)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_RUTIN=\
	".\Punto3D.h"\
	".\Rutinas.h"\
	

"$(INTDIR)\Rutinas.obj" : $(SOURCE) $(DEP_CPP_RUTIN) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\Spin.cpp

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_SPIN_=\
	".\Material.h"\
	".\Punto3D.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	".\StdAfx.h"\
	

"$(INTDIR)\Spin.obj"	"$(INTDIR)\Spin.sbr" : $(SOURCE) $(DEP_CPP_SPIN_)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_SPIN_=\
	".\Material.h"\
	".\Punto3D.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	

"$(INTDIR)\Spin.obj" : $(SOURCE) $(DEP_CPP_SPIN_) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Proyecto - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Proyecto.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Proyecto.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Proyecto.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Proyecto.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TRIFENIL.CPP

!IF  "$(CFG)" == "Proyecto - Win32 Release"

DEP_CPP_TRIFE=\
	".\Angulo.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	".\StdAfx.h"\
	".\Trifenil.h"\
	

"$(INTDIR)\TRIFENIL.OBJ"	"$(INTDIR)\TRIFENIL.SBR" : $(SOURCE) $(DEP_CPP_TRIFE)\
 "$(INTDIR)" "$(INTDIR)\Proyecto.pch"


!ELSEIF  "$(CFG)" == "Proyecto - Win32 Debug"

DEP_CPP_TRIFE=\
	".\Angulo.h"\
	".\Cilindro.h"\
	".\Material.h"\
	".\Punto3D.h"\
	".\Rutinas.h"\
	".\Spin.h"\
	".\SSCOMMON.H"\
	".\Trifenil.h"\
	

"$(INTDIR)\TRIFENIL.OBJ" : $(SOURCE) $(DEP_CPP_TRIFE) "$(INTDIR)"\
 "$(INTDIR)\Proyecto.pch"


!ENDIF 


!ENDIF 

