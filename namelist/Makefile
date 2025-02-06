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
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -I../include /wd4267
  LINKLIB = lib -nologo
  LINKDLL = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64 -subsystem:windows -dll
  LINKEXE = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

SOURCES = escape_quotes.c \
          free_namelist.c \
          free_namelist_text.c \
          get_namelist.c \
          namelist_etc.c \
          print_namelist.c \
          process_namelist.c \
          scan_namelist.c \
          show_namelist.c \
          show_namelist_fields.c \
          zero_namelist.c

OBJS = $(SOURCES:.c=.$(OBJEXT))

ifeq ($(OS), Windows)
  LIBRARY = namelist.lib
else
  LIBRARY = libnamelist.a
endif

PROGS = nlpp
nlpp_SRC = namelist_pp.c scanargs.c
PROG_OBJS = $(nlpp_SRC:.c=.$(OBJEXT))

all: $(LIBRARY) $(PROGS:%=%$(EXEEXT))

ifeq ($(OS), Windows)

nlpp.exe: namelist_pp.obj scanargs.obj $(LIBRARY)
	$(LINKEXE) -out:$@ namelist_pp.obj scanargs.obj namelist.lib ../mdblib/mdblib.lib
%$(EXEEXT): %.$(OBJEXT) $(LIBRARY)
	$(LINKEXE) -out:$@ $(@:.exe=.obj) namelist.lib
$(LIBRARY): $(OBJS)
	$(LINKLIB) -out:$(LIBRARY) $(OBJS) 
namelist_pp.obj: namelist_pp.c scanargs.obj
	$(CC) $(CFLAGS) -c $<
scanargs.$(OBJEXT): scanargs.c
	$(CC) $(CFLAGS) -c $<
%.obj: %.c
	$(CC) $(CFLAGS) -c $<
else
nlpp: nlpp.o scanargs.o $(LIBRARY)
	$(CCC) -o $@ nlpp.o scanargs.o $(LDFLAGS) -L. -L../rpns/code -L../mdblib -lnamelist -lrpnlib -lmdblib  $(PROD_SYS_LIBS)
%$(EXEEXT): %.$(OBJEXT) $(LIBRARY)
	$(CCC) -o $@ $@.o $(LDFLAGS) -L../rpns/code -L../mdblib -lrpnlib -lmdblib  $(PROD_SYS_LIBS)
$(LIBRARY): $(OBJS)
	$(AR) $(LIBRARY) $(OBJS)
	$(RANLIB) $(LIBRARY)
nlpp.o: namelist_pp.c scanargs.o
	$(CC) $(CFLAGS) -c $< -o $@
scanargs.o: scanargs.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJS) $(PROG_OBJS) $(LIBRARY) $(PROGS:%=%$(EXEEXT)) $(PROGS:%=%.$(OBJEXT))

.PHONY: all clean

