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
  CFLAGS = -m64 -O3 -g -Wall -fPIC -DzLib -DALLOW_FILE_LOCKING=1 -DRPN_SUPPORT -I../include
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
  CFLAGS = -Wno-deprecated-non-prototype -m64 -O3 -g -Wall -fPIC -DUSE_GSL -fno-common -mmacosx-version-min=10.13 -DzLib -DALLOW_FILE_LOCKING=1 -DRPN_SUPPORT -I../include
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
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -DzLib -DALLOW_FILE_LOCKING=1 -DRPN_SUPPORT -I../include -I../lzma -I../zlib /wd4244 /wd4267
  LINKDLL = link -nologo -LTCG -incremental:no -opt:ref -release -MACHINE:X64 -subsystem:windows -dll
  OBJEXT = obj
  LIBEXT = lib
  LIBPRE =
  EXEEXT = .exe
endif

SOURCES = SDDS_ascii.c \
          SDDS_binary.c \
          SDDS_copy.c \
          SDDS_data.c \
          SDDS_dataprep.c \
          SDDS_extract.c \
          SDDS_info.c \
          SDDS_input.c \
          SDDS_lzma.c \
          SDDS_mplsupport.c \
          SDDS_output.c \
          SDDS_process.c \
          SDDS_rpn.c \
          SDDS_transfer.c \
          SDDS_utils.c \
          SDDS_write.c

OBJS = $(SOURCES:.c=.$(OBJEXT))

ifeq ($(OS), Windows)
  LIBRARY = SDDS1.lib
  DLL = SDDS1.dll
  EXP = SDDS1.exp
else
  LIBRARY = libSDDS1.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)

$(LIBRARY): $(OBJS)
	$(LINKDLL) -out:$(DLL) -implib:$(LIBRARY) $(OBJS) ../rpns/code/rpnlib.lib ../mdbmth/mdbmth.lib ../mdblib/mdblib.lib ../lzma/lzma.lib ../zlib/z.lib
%.obj: %.c
	$(CC) $(CFLAGS) -DEXPORT_SDDS  -c $<
else
$(LIBRARY): $(OBJS)
	$(AR) $(LIBRARY) $(OBJS)
	$(RANLIB) $(LIBRARY)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJS) $(LIBRARY) $(DLL) $(EXP) $(PROGS:%=%$(EXEEXT)) $(PROGS:%=%.$(OBJEXT))

.PHONY: all clean

