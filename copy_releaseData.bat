echo off
set TargetFolder="ReleaseFolder"
REM ============================================================================
echo [1] if folder exist, remove
if exist %TargetFolder% RD /s /q    %TargetFolder%
REM ============================================================================
echo [2] create folder : %TargetFolder%
md %TargetFolder%
if exist %TargetFolder%         echo [2] check folder exist, result: Yes
if not exist %TargetFolder%     echo [2] check folder exist, result: No
if not exist %TargetFolder%     goto fail
REM ============================================================================
echo [3] copy our binary file(s)
copy .\Release\CHttpAuth.exe                             %TargetFolder%
REM copy .\Release\InstallationWizard.pdb                             %TargetFolder%\PDB
REM ============================================================================
echo [4] copy files, Qt*.dll
copy %QTDIR%\bin\QtCore4.dll        %TargetFolder%
copy %QTDIR%\bin\QtGui4.dll         %TargetFolder%
copy %QTDIR%\bin\QtNetwork4.dll     %TargetFolder%
copy %QTDIR%\bin\QtXml4.dll         %TargetFolder%
REM copy %QTDIR%\lib\QtCore4.pdb        %TargetFolder%\PDB
REM copy %QTDIR%\lib\QtGui4.pdb         %TargetFolder%\PDB
REM copy %QTDIR%\lib\QtNetwork4.pdb     %TargetFolder%\PDB
REM copy %QTDIR%\lib\QtXml4.pdb     %TargetFolder%\PDB

REM ============================================================================
echo [6] copy Translations
xcopy /s/i/y/q .\lang\*.qm   %TargetFolder%\lang
REM ============================================================================
echo [6] copy other resource
md %TargetFolder%/Images
xcopy /s/i/y/q .\Images\*.png   %TargetFolder%\Images
xcopy /s/i/y/q .\Graphics\Components\*.png   %TargetFolder%\Graphics\Components
xcopy /s/i/y/q .\qss\*.qss   %TargetFolder%\qss
REM ============================================================================
echo [SUCCESS]
goto end

REM ============================================================================
:fail
echo [FAIL][ERROR] please check
goto end


REM ============================================================================
:end
echo end
echo on
pause