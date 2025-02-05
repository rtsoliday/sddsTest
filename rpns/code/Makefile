# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif


GSL_LIB = $(firstword $(wildcard \
    $(addsuffix /libgsl.a, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ) \
    $(addsuffix /libgsl.so, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ) \
    $(addsuffix /libgsl.dylib, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib )))
GSLCBLAS_LIB = $(firstword $(wildcard \
    $(addsuffix /libgslcblas.a, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ) \
    $(addsuffix /libgslcblas.so, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ) \
    $(addsuffix /libgslcblas.dylib, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib )))


ifeq ($(OS), Linux)
  CC = gcc
  AR = ar rcs
  RANLIB = ranlib
  CFLAGS = -m64 -O3 -g -Wall -fPIC -DUSE_GSL -I../../include
  LDFLAGS = -static-libstdc++ -rdynamic -m64
  PROD_SYS_LIBS = $(GSL_LIB) $(GSLCBLAS_LIB) -lpthread -lm -lrt -ldl -lgcc

  CUSTOM_GCC_PATH = /usr/local/oag/3rdParty/gcc-11.3.0
  ifneq ($(wildcard $(CUSTOM_GCC_PATH)),)
    CC = $(CUSTOM_GCC_PATH)/bin/gcc
    AR = $(CUSTOM_GCC_PATH)/bin/gcc-ar -rc
    RANLIB = $(CUSTOM_GCC_PATH)/bin/gcc-ranlib
  endif
endif

ifeq ($(OS), Darwin)
  CC = clang -Wno-deprecated-non-prototype
  AR = libtool -static -o
  RANLIB = ranlib
  CFLAGS = -m64 -O3 -g -Wall -fPIC -DUSE_GSL -fno-common -mmacosx-version-min=10.13 -I../../include -I/opt/local/include -I/sw/include -I/usr/sfw/include
  LDFLAGS = -mmacosx-version-min=10.13 -std=c++11
  PROD_SYS_LIBS = $(GSL_LIB) $(GSLCBLAS_LIB) -lm
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
    CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -DEXPORT_RPNLIB -I../include
    LINK = link -nologo -subsystem:windows -dll -LTCG -incremental:no -opt:ref -release -MACHINE:X64
endif


# Define helper function for system library checks
define CHECK_FOR_SYSTEM_LIBRARY
  $(words $(notdir $(wildcard \
    $(addsuffix /$(1).a, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ) \
    $(addsuffix /$(1).so, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ) \
    $(addsuffix /$(1).dylib, /usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /lib /lib64 /opt/local/lib /sw/lib /usr/sfw/lib ))))
endef

#Look for system version of GSL
ifeq ($(strip $(call CHECK_FOR_SYSTEM_LIBRARY,libgsl)),0)
  #No system level GSL library found.
  ifeq ($(OS), Windows)
    #Look for private version of GSL used here at APS
    GSL = $(words $(wildcard ../../gsl))
    ifeq ($(GSL), 1)
      CFLAGS += -I../../gsl -DUSE_GSL -DUSE_GSL_FRESNEL
      GSL_LIBS += -lgsl -lgslcblas
      GSL_FLAGS += -L../../gsl
    endif
  endif
else
  CFLAGS += -DUSE_GSL
endif

SRC = array.c \
        conditional.c \
        execute.c \
        get_token_rpn.c \
        infixtopostfix.c \
        logical.c \
        math.c \
        memory.c \
        pcode.c \
        pop_push.c \
        prompt.c \
        rpn_csh.c \
        rpn_data.c \
        rpn_draw.c \
        rpn_error.c \
        rpn_io.c \
        rpn_sub.c \
        stack.c \
        udf.c

ifeq ($(OS), Windows)
  OBJ = $(SRC:.c=.obj)
  LIBRARY = rpnlib.lib
  DLL = rpnlib.dll
  EXP = rpnlib.exp
else
  OBJ = $(SRC:.c=.o)
  LIBRARY = librpnlib.a
  PRODS = rpn rpnl if2pf
endif

all: $(LIBRARY) $(PRODS)

ifeq ($(OS), Windows)
  $(LIBRARY): $(OBJ)
	$(LINK) -out:$(DLL) -implib:$(LIBRARY) $(OBJ) ../../mdbmth/mdbmth.lib ../../mdblib/mdblib.lib
  %.obj: %.c
	$(CC) $(CFLAGS) -c $<
else
  $(PRODS): $(LIBRARY) rpn.o rpnl.o if2pf.o
	$(CC) -o $@ $@.o $(LDFLAGS) -L. -L../../mdbmth -L../../mdblib -lrpnlib -lmdbmth -lmdblib $(PROD_SYS_LIBS)
  $(LIBRARY): $(OBJ)
	$(AR) $(LIBRARY) $(OBJ)
	$(RANLIB) $(LIBRARY)
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) rpn.o rpnl.o if2pf.o $(LIBRARY) $(DLL) $(EXP) $(PRODS) 

.PHONY: all clean


