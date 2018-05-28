START_DIR = C:\Users\AUSTIN~1\DOCUME~1\ECOCAR~1\VISION~1\FROMVI~1

MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2016b
MAKEFILE = FindCircle_mex.mk

include FindCircle_mex.mki


SRC_FILES =  \
	FindCircle_mexutil.c \
	FindCircle_data.c \
	FindCircle_initialize.c \
	FindCircle_terminate.c \
	FindCircle.c \
	imfindcircles.c \
	validateattributes.c \
	isfinite.c \
	eml_int_forloop_overflow_check.c \
	chaccum.c \
	all.c \
	isequal.c \
	rgb2gray.c \
	abs.c \
	warning.c \
	imfilter.c \
	padarray.c \
	convn.c \
	xaxpy.c \
	multithresh.c \
	im2uint8.c \
	imhist.c \
	sum.c \
	error.c \
	assertValidSizeArg.c \
	unique.c \
	sortIdx.c \
	mergesort.c \
	indexShapeCheck.c \
	nullAssignment.c \
	sort1.c \
	find.c \
	sub2ind.c \
	chcenters.c \
	ordfilt2.c \
	toLogicalCheck.c \
	regionprops.c \
	bwconncomp.c \
	round1.c \
	_coder_FindCircle_info.c \
	_coder_FindCircle_api.c \
	_coder_FindCircle_mex.c \
	FindCircle_emxutil.c

MEX_FILE_NAME_WO_EXT = FindCircle_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
TARGET = $(MEX_FILE_NAME)

BlockModules_LIBS = "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwrgb2gray_tbb.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwgrayto8.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwtbbhist.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwgetnumcores.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwordfilt2.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwimregionalmax.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwippreconstruct.lib" 
SYS_LIBS = $(BlockModules_LIBS) libmwblas.lib 


#
#====================================================================
# gmake makefile fragment for building MEX functions using MSVC
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#
SHELL = cmd
OBJEXT = obj
CC = $(COMPILER)
LD = $(LINKER)
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLIST  = $(OBJLISTC:.cpp=.$(OBJEXT))

TARGETMT = $(TARGET).manifest
MEX = $(TARGETMT)
STRICTFP = /fp:strict

target: $(MEX)

MATLAB_INCLUDES = /I "$(MATLAB_ROOT)\simulink\include"
MATLAB_INCLUDES+= /I "$(MATLAB_ROOT)\toolbox\shared\simtargets"
SYS_INCLUDE = $(MATLAB_INCLUDES)

# Additional includes

SYS_INCLUDE += /I "$(START_DIR)"
SYS_INCLUDE += /I "$(START_DIR)\codegen\mex\FindCircle"
SYS_INCLUDE += /I ".\interface"
SYS_INCLUDE += /I "$(MATLAB_ROOT)\extern\include"
SYS_INCLUDE += /I "."

DIRECTIVES = $(MEX_FILE_NAME_WO_EXT)_mex.arf
COMP_FLAGS = $(COMPFLAGS) $(OMPFLAGS)
LINK_FLAGS = $(filter-out /export:mexFunction, $(LINKFLAGS))
LINK_FLAGS += /NODEFAULTLIB:LIBCMT
ifeq ($(EMC_CONFIG),optim)
  COMP_FLAGS += $(OPTIMFLAGS) $(STRICTFP)
  LINK_FLAGS += $(LINKOPTIMFLAGS)
else
  COMP_FLAGS += $(DEBUGFLAGS)
  LINK_FLAGS += $(LINKDEBUGFLAGS)
endif
LINK_FLAGS += $(OMPLINKFLAGS)
LINK_FLAGS += /OUT:$(TARGET)
LINK_FLAGS +=  /LIBPATH:"$(MATLAB_ROOT)\extern\lib\win64\microsoft"

CFLAGS = $(COMP_FLAGS)   $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(COMP_FLAGS)   $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CC) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\FindCircle/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CFLAGS) "$<"



%.$(OBJEXT) : $(START_DIR)/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\FindCircle/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CC) $(CPPFLAGS) "$<"



$(TARGET): $(OBJLIST) $(MAKEFILE) $(DIRECTIVES)
	$(LD) $(LINK_FLAGS) $(OBJLIST) $(USER_LIBS) $(SYS_LIBS) @$(DIRECTIVES)
	@cmd /C "echo Build completed using compiler $(EMC_COMPILER)"

$(TARGETMT): $(TARGET)
	mt -outputresource:"$(TARGET);2" -manifest "$(TARGET).manifest"

#====================================================================

