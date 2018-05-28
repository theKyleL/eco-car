@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=FindCircle_mex
set MEX_NAME=FindCircle_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for FindCircle > FindCircle_mex.mki
echo COMPILER=%COMPILER%>> FindCircle_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> FindCircle_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> FindCircle_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> FindCircle_mex.mki
echo LINKER=%LINKER%>> FindCircle_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> FindCircle_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> FindCircle_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> FindCircle_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> FindCircle_mex.mki
echo BORLAND=%BORLAND%>> FindCircle_mex.mki
echo OMPFLAGS= >> FindCircle_mex.mki
echo OMPLINKFLAGS= >> FindCircle_mex.mki
echo EMC_COMPILER=msvc140>> FindCircle_mex.mki
echo EMC_CONFIG=optim>> FindCircle_mex.mki
"C:\Program Files\MATLAB\R2016b\bin\win64\gmake" -B -f FindCircle_mex.mk
