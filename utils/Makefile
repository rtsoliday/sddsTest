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
  CFLAGS = -m64 -O3 -g -Wall -fPIC -DH5_USE_16_API -I../include
  LDFLAGS = -static-libstdc++ -rdynamic -m64
  PROD_SYS_LIBS = -lhdf5 -llzma -lgsl -lgslcblas -lz -lpthread -lm -lrt -ldl -lgcc
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
  CFLAGS = -Wno-deprecated-non-prototype -m64 -O3 -g -Wall -fPIC -fno-common -mmacosx-version-min=10.13 -DH5_USE_16_API -I../include -I../../include -I/opt/local/include -I/sw/include -I/usr/sfw/include
  LDFLAGS = -mmacosx-version-min=10.13 -std=c++11
  PROD_SYS_LIBS = -lhdf5 -llzma -lgsl -lgslcblas -lz -lm
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
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -DH5_USE_16_API -I../include -I../lzma
  LINKEXE = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

PROGS = editstring replaceText isFileLocked hdf2sdds sdds2hdf

all: $(PROGS:%=%$(EXEEXT))

ifeq ($(OS), Windows)

%$(EXEEXT): %.$(OBJEXT)
	$(LINKEXE) -out:$@ $(@:.exe=.obj) rpnlib.lib ../../mdblib/mdblib.lib
else
%$(EXEEXT): %.$(OBJEXT)
	$(CCC) -o $@ $@.o $(LDFLAGS) -L. -L../mdbcommon -L../SDDSlib -L../rpns/code -L../mdbmth -L../mdblib -lmdbcommon -lSDDS1 -lrpnlib -lmdbmth -lmdblib $(PROD_SYS_LIBS)
editstring.o: editstring.c
	$(CC) $(CFLAGS) -c $< -o $@
replaceText.o: replaceText.c
	$(CC) $(CFLAGS) -c $< -o $@
isFileLocked.o: isFileLocked.c
	$(CC) $(CFLAGS) -c $< -o $@
hdf2sdds.o: hdf2sdds.c
	$(CC) $(CFLAGS) -c $< -o $@
sdds2hdf.o: sdds2hdf.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(PROGS:%=%$(EXEEXT)) $(PROGS:%=%.$(OBJEXT))

.PHONY: all clean

