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
  OBJEXT = o
  LIBEXT = a
  LIBPRE = lib
  EXEEXT =

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
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -I../../include /wd4244 /wd4267
  LINKDLL = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64 -subsystem:windows -dll
  LINKEXE = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

SOURCES = array.c \
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

OBJS = $(SOURCES:.c=.$(OBJEXT))

ifeq ($(OS), Windows)
  LIBRARY = rpnlib.lib
  DLL = rpnlib.dll
  EXP = rpnlib.exp
else
  LIBRARY = librpnlib.a
endif

PROGS = rpn rpnl if2pf

all: $(LIBRARY) $(PROGS:%=%$(EXEEXT))

ifeq ($(OS), Windows)

%$(EXEEXT): %.$(OBJEXT) $(LIBRARY)
	$(LINKEXE) -out:$@ $(@:.exe=.obj) rpnlib.lib ../../mdblib/mdblib.lib netapi32.lib
$(LIBRARY): $(OBJS)
	$(LINKDLL) -out:$(DLL) -implib:$(LIBRARY) $(OBJS) ../../mdbmth/mdbmth.lib ../../mdblib/mdblib.lib
rpn.obj: rpn.c
	$(CC) $(CFLAGS) -c $<
rpnl.obj: rpnl.c
	$(CC) $(CFLAGS) -c $<
if2pf.obj: if2pf.c
	$(CC) $(CFLAGS) -c $<
%.obj: %.c
	$(CC) $(CFLAGS) -DEXPORT_RPNLIB  -c $<
else
%$(EXEEXT): %.$(OBJEXT) $(LIBRARY)
	$(CC) -o $@ $@.o $(LDFLAGS) -L. -L../../mdbmth -L../../mdblib -lrpnlib -lmdbmth -lmdblib $(PROD_SYS_LIBS)
$(LIBRARY): $(OBJS)
	$(AR) $(LIBRARY) $(OBJS)
	$(RANLIB) $(LIBRARY)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJS) $(LIBRARY) $(DLL) $(EXP) $(PROGS:%=%$(EXEEXT))

.PHONY: all clean

