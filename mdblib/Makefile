
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
CFLAGS = -m64 -O3 -g -Wall -fPIC -I../include

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
    CC = clang
    AR = libtool -static -o
    RANLIB = ranlib
    CFLAGS += -mmacosx-version-min=10.13 -Wno-deprecated-non-prototype
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
    CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD -DEXPORT_MDBLIB -I../include /wd4244 /wd4267
    LINK = link -nologo -subsystem:windows -dll -LTCG -incremental:no -opt:ref -release -MACHINE:X64
endif

SRC = array.c \
    backspace.c \
    binary.c \
    binsert.c \
    bomb.c \
    buffer.c \
    clean_filename.c \
    compress.c \
    cp_str.c \
    data_scan.c \
    delete_bnd.c \
    delete_chars.c \
    edit_string.c \
    fexists.c \
    filestat.c \
    fill_array.c \
    fopen_e.c \
    get_token_tq.c \
    headers.c \
    insert.c \
    interpret_escapes.c \
    is_blank.c \
    match_string.c \
    mkdir.c \
    non_dominated_sort.c \
    pad_with_spaces.c \
    query.c \
    rcdelete.c \
    replace_chars.c \
    replace_string.c \
    replacefile.c \
    report_stats.c \
    scanitemlist.c \
    searchPath.c \
    sortfunctions.c \
    str_copy.c \
    str_in.c \
    str_inn.c \
    str_tolower.c \
    str_toupper.c \
    strslide.c \
    substituteTagValue.c \
    time.c \
    timeconvert.c \
    timer.c \
    tmpname.c \
    trim_spaces.c \
    unpack.c \
    wild_match.c

ifeq ($(OS), Windows)
  OBJ = $(SRC:.c=.obj)
  LIBRARY = mdblib.lib
  DLL = mdblib.dll
  EXP = mdblib.exp
else
  OBJ = $(SRC:.c=.o)
  LIBRARY = libmdblib.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)
  $(LIBRARY): $(OBJ)
	$(LINK) -out:$(DLL) -implib:$(LIBRARY) $(OBJ)
  %.obj: %.c
	$(CC) $(CFLAGS) -c $<
else
  $(LIBRARY): $(OBJ)
	$(AR) $(LIBRARY) $(OBJ)
	$(RANLIB) $(LIBRARY)
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIBRARY) $(DLL) $(EXP)

.PHONY: all clean


