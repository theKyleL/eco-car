@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=redHSVmask1_mex
set MEX_NAME=redHSVmask1_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for redHSVmask1 > redHSVmask1_mex.mki
echo COMPILER=%COMPILER%>> redHSVmask1_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> redHSVmask1_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> redHSVmask1_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> redHSVmask1_mex.mki
echo LINKER=%LINKER%>> redHSVmask1_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> redHSVmask1_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> redHSVmask1_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> redHSVmask1_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> redHSVmask1_mex.mki
echo BORLAND=%BORLAND%>> redHSVmask1_mex.mki
echo OMPFLAGS= >> redHSVmask1_mex.mki
echo OMPLINKFLAGS= >> redHSVmask1_mex.mki
echo EMC_COMPILER=msvc140>> redHSVmask1_mex.mki
echo EMC_CONFIG=optim>> redHSVmask1_mex.mki
"C:\Program Files\MATLAB\R2016b\bin\win64\gmake" -B -f redHSVmask1_mex.mk
