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
  CFLAGS = -Wno-deprecated-non-prototype -m64 -O3 -g -Wall -fPIC -fno-common -mmacosx-version-min=10.13 -I../include -I../../include -I/opt/local/include -I/sw/include -I/usr/sfw/include
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
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -I../include -I../lzma /wd4244 /wd4267
  LINKDLL = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64 -subsystem:windows -dll
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

SOURCES = fixcounts.c find_files.c  \
		lsfg.c lsfn.c \
		lsfp.c savitzkyGolay.c scanargs.c \
		table.c hashtab.c lookupa.c recycle.c rcds_powell.c

OBJS = $(SOURCES:.c=.$(OBJEXT))
ifeq ($(OS), Windows)
  LIBRARY = mdbcommon.lib
  DLL = mdbcommon.dll
  EXP = mdbcommon.exp
else
  LIBRARY = libmdbcommon.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)

$(LIBRARY): $(OBJS)
	$(LINKDLL) -out:$(DLL) -implib:$(LIBRARY) $(OBJS) ../matlib/matlib.lib ../fftpack/fftpack.lib ../SDDSlib/SDDS1.lib ../mdbmth/mdbmth.lib ../mdblib/mdblib.lib
%.obj: %.c
	$(CC) $(CFLAGS) -DEXPORT_MDBCOMMON  -c $<
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

