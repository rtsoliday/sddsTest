
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

# Default Compiler and Flags
CCC = g++
AR = ar rcs
RANLIB = ranlib
CFLAGS = -m64 -O3 -g -Wall -fPIC -DHAVE_CONFIG_H=1 -DEXPORT_XLS -I.

ifeq ($(OS), Linux)
   CUSTOM_GCC_PATH = /usr/local/oag/3rdParty/gcc-11.3.0
   ifneq ($(wildcard $(CUSTOM_GCC_PATH)),)
      CCC = $(CUSTOM_GCC_PATH)/bin/g++
      AR = $(CUSTOM_GCC_PATH)/bin/gcc-ar -rc
      RANLIB = $(CUSTOM_GCC_PATH)/bin/gcc-ranlib
   endif
endif

# Adjust for macOS
ifeq ($(OS), Darwin)
    CCC = clang++
    AR = libtool -static -o
    RANLIB = ranlib
    CCFLAGS += -mmacosx-version-min=10.13 -std=c++11 -m64 
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
    CCC = cl  # Use cl from Microsoft Visual Studio
    CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W0 -MD /wd4003 /wd4068 /wd4018
    LINK = lib -nologo -verbose
endif

SRC = assert_assist.cpp \
	blank.cpp \
	boolean.cpp \
	cbridge.cpp \
	cell.cpp \
	colinfo.cpp \
	colors.cpp \
	continue.cpp \
	datast.cpp \
	docsumminfo.cpp \
	err.cpp \
	extformat.cpp \
	font.cpp \
	format.cpp \
	formula.cpp \
	formula_cell.cpp \
	formula_estimate.cpp \
	formula_expr.cpp \
	globalrec.cpp \
	HPSF.cpp \
	index.cpp \
	label.cpp \
	merged.cpp \
	note.cpp \
	number.cpp \
	range.cpp \
	recdef.cpp \
	record.cpp \
	row.cpp \
	sheetrec.cpp \
	summinfo.cpp \
	unit.cpp \
	workbook.cpp \
	binfile.cpp \
	oledoc.cpp \
	olefs.cpp \
	oleprop.cpp

ifeq ($(OS), Windows)
  OBJ = $(SRC:.cpp=.obj)
  LIB = xls.lib
else
  OBJ = $(SRC:.cpp=.o)
  LIB = libxls.a
endif

all: $(LIB)

ifeq ($(OS), Windows)
  $(LIB): $(OBJ)
	$(LINK) -out:$(LIB) -LTCG $(OBJ)
  %.obj: %.cpp
	$(CCC) $(CFLAGS) -c $<
else
  $(LIB): $(OBJ)
	$(AR) $(LIB) $(OBJ)
	$(RANLIB) $(LIB)
  %.o: %.cpp
	$(CCC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIB)

.PHONY: all clean


