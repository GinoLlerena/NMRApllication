@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by PROYECTO.HPJ. >"hlp\Proyecto.hm"
echo. >>"hlp\Proyecto.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Proyecto.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Proyecto.hm"
echo. >>"hlp\Proyecto.hm"
echo // Prompts (IDP_*) >>"hlp\Proyecto.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Proyecto.hm"
echo. >>"hlp\Proyecto.hm"
echo // Resources (IDR_*) >>"hlp\Proyecto.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Proyecto.hm"
echo. >>"hlp\Proyecto.hm"
echo // Dialogs (IDD_*) >>"hlp\Proyecto.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Proyecto.hm"
echo. >>"hlp\Proyecto.hm"
echo // Frame Controls (IDW_*) >>"hlp\Proyecto.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Proyecto.hm"
REM -- Make help for Project PROYECTO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Proyecto.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Proyecto.hlp" goto :Error
if not exist "hlp\Proyecto.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Proyecto.hlp" Debug
if exist Debug\nul copy "hlp\Proyecto.cnt" Debug
if exist Release\nul copy "hlp\Proyecto.hlp" Release
if exist Release\nul copy "hlp\Proyecto.cnt" Release
echo.
goto :done

:Error
echo hlp\Proyecto.hpj(1) : error: Problem encountered creating help file

:done
echo.
