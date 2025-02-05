
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

# Default Compiler and Flags
CC = gcc
CCc = g++
AR = ar rcs
RANLIB = ranlib
CFLAGS = -m64 -O3 -g -Wall -fPIC -I../include
CCFLAGS = -m64 -O3 -g -Wall -fPIC -I../include

ifeq ($(OS), Linux)
   CFLAGS += -fopenmp
   CCFLAGS += -fopenmp
   CUSTOM_GCC_PATH = /usr/local/oag/3rdParty/gcc-11.3.0
   ifneq ($(wildcard $(CUSTOM_GCC_PATH)),)
      CC = $(CUSTOM_GCC_PATH)/bin/gcc
      CCC = $(CUSTOM_GCC_PATH)/bin/g++
      AR = $(CUSTOM_GCC_PATH)/bin/gcc-ar -rc
      RANLIB = $(CUSTOM_GCC_PATH)/bin/gcc-ranlib
   endif
endif

# Adjust for macOS
ifeq ($(OS), Darwin)
    CC = clang
    CCC = clang++
    AR = libtool -static -o
    RANLIB = ranlib
    CFLAGS += -mmacosx-version-min=10.13
    CCFLAGS += -mmacosx-version-min=10.13 -std=c++11 -m64 
endif

# Adjust for Architecture
ifeq ($(ARCH), x86_64)
    CFLAGS += -mtune=generic
endif

ifeq ($(ARCH), arm64)
    CFLAGS += -mcpu=native
endif

# Adjust for Windows in a cygwin terminal
ifeq ($(OS), Windows)
    CC = cl  # Use cl from Microsoft Visual Studio
    CCC = cl  # Use cl from Microsoft Visual Studio
    CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -DEXPORT_MDBMTH -I../include -openmp
    CCFLAGS = -EHsc -GR -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -DEXPORT_MDBMTH -I../include -openmp
    LINK = link -nologo -subsystem:windows -dll -LTCG -incremental:no -opt:ref -release -MACHINE:X64
endif

SRC = betai.c \
          bsODEp.c \
          complex.cc \
          counter.c \
          dbessel.c \
          diffeqResDescrip.c \
          dlaran.c \
          drand.c \
          elliptic.c \
          factorial.c \
          factorize.c \
          findMinMax.c \
          gammai.c \
          gaussQuad.c \
          GillMillerIntegration.c \
          gridopt.c \
          gy.c \
          halton.c \
          interp.c \
          ipow.c \
          kstests.c \
          k13.c \
          k23.c \
          lincorr.c \
          linfit.c \
          logfile_gener.c \
          lsfBasisFns.c \
          makeHistogram.c \
          mcTable.c \
          median.c \
          mmid.c \
          moments.c \
          onedoptimize.c \
          poly.c \
          powellMin.c \
          qromb.c \
          rkODE.c \
          rowmedian.c \
          sigLevel.c \
          simplex.c \
          smooth.c \
          topbase.c \
          trapInteg.c \
          wofz.c \
          zeroIH.c \
          zeroInterp.c \
          zeroNewton.c \
          medianfilter.c \
          pointInsideContour.c

ifeq ($(OS), Windows)
  OBJ = $(SRC:.c=.obj)
  OBJ := $(OBJ:.c=.obj)
  LIBRARY = mdbmth.lib
  DLL = mdbmth.dll
  EXP = mdbmth.exp
else
  OBJ = $(SRC:.c=.o)
  OBJ := $(OBJ:.cc=.o)
  LIBRARY = libmdbmth.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)
  $(LIBRARY): $(OBJ)
	$(LINK) -out:$(DLL) -implib:$(LIBRARY) $(OBJ)
  %.obj: %.c
	$(CC) $(CFLAGS) -c $<
  %.obj: %.cc
	$(CCC) $(CCFLAGS) -c $<
else
  $(LIBRARY): $(OBJ)
	$(AR) $(LIBRARY) $(OBJ)
	$(RANLIB) $(LIBRARY)
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
  %.o: %.cc
	$(CCC) $(CCFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIBRARY) $(DLL) $(EXP)

.PHONY: all clean


