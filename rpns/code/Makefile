
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
CFLAGS = -m64 -O3 -g -Wall -fPIC -DUSE_GSL -I../../include
LDFLAGS = -static-libstdc++ -rdynamic -m64

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
    CC = clang -Wno-deprecated-non-prototype
    AR = libtool -static -o
    RANLIB = ranlib
    CFLAGS += -mmacosx-version-min=10.13
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
	$(CC) -o $@ $@.o $(LDFLAGS) -L. -L../../mdbmth -L../../mdblib -lrpnlib -lmdbmth -lmdblib -lgsl -lgslcblas -lpthread -lm -lrt -ldl -lgcc
  $(LIBRARY): $(OBJ)
	$(AR) $(LIBRARY) $(OBJ)
	$(RANLIB) $(LIBRARY)
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIBRARY) $(DLL) $(EXP)

.PHONY: all clean


