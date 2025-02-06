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
  CFLAGS = -m64 -O3 -g -Wall -fPIC -fopenmp -I../include
  CCFLAGS = -m64 -O3 -g -Wall -fPIC -fopenmp -I../include
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
  CCFLAGS = -Wno-deprecated-non-prototype -m64 -O3 -g -Wall -fPIC -fno-common -mmacosx-version-min=10.13 -I../include -std=c++11
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
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -openmp -I../include /wd4244
  CCFLAGS = -EHsc -GR -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -openmp -I../include /wd4244
  LINKDLL = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64 -subsystem:windows -dll
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

SOURCES = cfftb.c cfftb1.c cfftf.c \
		cfftf1.c cffti.c cffti1.c \
		cosqb.c cosqb1.c cosqf.c \
		cosqf1.c cosqi.c cost.c \
		costi.c dfilter.cc ezfft1.c \
		ezfftb.c ezfftf.c ezffti.c \
		fftpackC.c naff.c passb.c \
		passb2.c passb3.c passb4.c \
		passb5.c passf.c passf2.c \
		passf3.c passf4.c passf5.c \
		radb2.c radb3.c radb4.c \
		radb5.c radbg.c radf2.c \
		radf3.c radf4.c radf5.c \
		radfg.c rfftb.c rfftb1.c \
		rfftf.c rfftf1.c rffti.c \
		rffti1.c sinqb.c sinqf.c \
		sinqi.c sint.c sint1.c \
		sinti.c

ifeq ($(OS), Windows)
  OBJS = $(SOURCES:.c=.obj)
  OBJS := $(OBJS:.cc=.obj)
  LIBRARY = fftpack.lib
  DLL = fftpack.dll
  EXP = fftpack.exp
else
  OBJS = $(SOURCES:.c=.o)
  OBJS := $(OBJS:.cc=.o)
  LIBRARY = libfftpack.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)

$(LIBRARY): $(OBJS)
	$(LINKDLL) -out:$(DLL) -implib:$(LIBRARY) $(OBJS) ../mdbmth/mdbmth.lib ../mdblib/mdblib.lib
%.obj: %.c
	$(CC) $(CFLAGS) -DEXPORT_FFTPACK  -c $<
%.obj: %.cc
	$(CCC) $(CCFLAGS) -DEXPORT_FFTPACK  -c $<
else
$(LIBRARY): $(OBJS)
	$(AR) $(LIBRARY) $(OBJS)
	$(RANLIB) $(LIBRARY)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.cc
	$(CCC) $(CCFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJS) $(LIBRARY) $(DLL) $(EXP) $(PROGS:%=%$(EXEEXT)) $(PROGS:%=%.$(OBJEXT))

.PHONY: all clean

