# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

ifeq ($(OS), Linux)
  CC = gcc
  CCC = g++
  AR = ar rcs
  RANLIB = ranlib
  CFLAGS = -m64 -O3 -g -Wall -fPIC -I../include
  LDFLAGS = -static-libstdc++ -rdynamic -m64
  PROD_SYS_LIBS = -lpthread -lm -lrt -ldl -lgcc
  OBJEXT = o
  LIBEXT = a
  LIBPRE = lib
  EXEEXT =

  CUSTOM_GCC_PATH = /usr/local/oag/3rdParty/gcc-11.3.0
  ifneq ($(wildcard $(CUSTOM_GCC_PATH)),)
    CC = $(CUSTOM_GCC_PATH)/bin/gcc
    CCC = $(CUSTOM_GCC_PATH)/bin/g++
    AR = $(CUSTOM_GCC_PATH)/bin/gcc-ar -rc
    RANLIB = $(CUSTOM_GCC_PATH)/bin/gcc-ranlib
  endif
endif

ifeq ($(OS), Darwin)
  CC = clang
  CCC = clang++
  AR = libtool -static -o
  RANLIB = ranlib
  CFLAGS = -Wno-deprecated-non-prototype -m64 -O3 -g -Wall -fPIC -fno-common -mmacosx-version-min=10.13 -I../include
  LDFLAGS = -mmacosx-version-min=10.13 -std=c++11
  PROD_SYS_LIBS = -lm
  OBJEXT = o
  LIBEXT = a
  LIBPRE = lib
  EXEEXT =
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
  CC = cl
  CCC = cl
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -I../include /wd4244
  LINKDLL = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64 -subsystem:windows -dll
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

SOURCES = fmat.c m_add.c m_alloc.c \
		m_bench.c m_check.c m_copy.c \
		m_det.c m_error.c m_free.c \
		m_identity.c m_invert.c m_mult.c \
		m_scmul.c m_show.c m_trans.c \
		m_zero.c

OBJS = $(SOURCES:.c=.$(OBJEXT))
ifeq ($(OS), Windows)
  LIBRARY = matlib.lib
  DLL = matlib.dll
  EXP = matlib.exp
else
  LIBRARY = libmatlib.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)

$(LIBRARY): $(OBJS)
	$(LINKDLL) -out:$(DLL) -implib:$(LIBRARY) $(OBJS) ../mdbmth/mdbmth.lib ../mdblib/mdblib.lib
%.obj: %.c
	$(CC) $(CFLAGS) -DEXPORT_MATLIB  -c $<
else
$(LIBRARY): $(OBJS)
	$(AR) $(LIBRARY) $(OBJS)
	$(RANLIB) $(LIBRARY)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJS) $(LIBRARY) $(DLL) $(EXP)

.PHONY: all clean

