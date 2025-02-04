
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

# Default Compiler and Flags
CC = gcc
AR = ar rcs
RANLIB = ranlib
CFLAGS = -O3 -g -Wall -fPIC

ifeq ($(OS), Linux)
   CUSTOM_GCC_PATH = /usr/local/oag/3rdParty/gcc-11.3.0
   ifneq ($(wildcard $(CUSTOM_GCC_PATH)),)
      CC = $(CUSTOM_GCC_PATH)/bin/gcc
      AR = $(CUSTOM_GCC_PATH)/bin/gcc-ar -rc
      RANLIB = $(CUSTOM_GCC_PATH)/bin/gcc-ranlib
   endif
endif

# Adjust for macOS
ifeq ($(OS), Darwin)
    CC = clang  # Use Clang on macOS
    AR = libtool -static -o  # macOS prefers `libtool` for static libraries
    RANLIB = ranlib
    CFLAGS += -Wno-deprecated-non-prototype
endif

# Adjust for Architecture
ifeq ($(ARCH), x86_64)
    CFLAGS += -mtune=generic
endif

ifeq ($(ARCH), aarch64)
    CFLAGS += -mcpu=native
endif

ifeq ($(ARCH), arm64)
    CFLAGS += -mcpu=native
endif

# Adjust for Windows in a cygwin terminal
ifeq ($(OS), Windows)
    CC = cl  # Use cl from Microsoft Visual Studio
	CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W0 -MD /wd4003 /wd4068 /wd4018
    LINK = lib -nologo -verbose
endif

SRC = bdfactor.c \
	bkpfacto.c \
	chfactor.c \
	copy.c \
	err.c \
	fft.c \
	givens.c \
	hessen.c \
	hsehldr.c \
	init.c \
	iter0.c \
	iternsym.c \
	itersym.c \
	ivecop.c \
	lufactor.c \
	machine.c \
	matlab.c \
	matop.c \
	matrixio.c \
	meminfo.c \
	memory.c \
	memstat.c \
	mfunc.c	 \
	norm.c \
	otherio.c \
	pxop.c \
	qrfactor.c \
	schur.c \
	solve.c \
	sparse.c \
	sparseio.c \
	spbkp.c \
	spchfctr.c \
	splufctr.c \
	sprow.c \
	spswap.c \
	submat.c \
	svd.c \
	symmeig.c \
	update.c \
	vecop.c \
	version.c \
	zcopy.c \
	zfunc.c \
	zgivens.c \
	zhessen.c \
	zhsehldr.c \
	zlufctr.c \
	zmachine.c \
	zmatio.c \
	zmatlab.c \
	zmatop.c \
	zmemory.c \
	znorm.c \
	zqrfctr.c \
	zschur.c \
	zsolve.c \
	zvecop.c

ifeq ($(OS), Windows)
  OBJ = $(SRC:.c=.obj)
  LIB = libmeschach.lib
else
  OBJ = $(SRC:.c=.o)
  LIB = libmeschach.a
endif

all: $(LIB)

ifeq ($(OS), Windows)
  $(LIB): $(OBJ)
	$(LINK) -out:$(LIB) -LTCG $(OBJ)
  %.obj: %.c
	$(CC) $(CFLAGS) -c $<
else
  $(LIB): $(OBJ)
	$(AR) $(LIB) $(OBJ)
	$(RANLIB) $(LIB)
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIB)

.PHONY: all clean


