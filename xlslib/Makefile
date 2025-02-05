
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
CCFLAGS = -m64 -O3 -g -Wall -fPIC -DHAVE_CONFIG_H=1 -DEXPORT_XLS -I.

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
    CCFLAGS += -mtune=generic
endif

ifeq ($(ARCH), aarch64)
    CCFLAGS += -mcpu=native
endif

ifeq ($(ARCH), arm64)
    CCFLAGS += -mcpu=native
endif

# Adjust for Windows in a cygwin terminal
ifeq ($(OS), Windows)
    CCC = cl  # Use cl from Microsoft Visual Studio
    CCFLAGS = -EHsc -GR -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -MD /wd4003 /wd4267 /wd4068 /wd4018 -D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING -DHAVE_CONFIG_H=1 -DEXPORT_XLS
    LINK = link -nologo -subsystem:windows -dll -LTCG -incremental:no -opt:ref -release -MACHINE:X64
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
  LIBRARY = xls.lib
  DLL = xls.dll
  EXP = xls.exp
else
  OBJ = $(SRC:.cpp=.o)
  LIBRARY = libxls.a
endif

all: $(LIBRARY)

ifeq ($(OS), Windows)
  $(LIBRARY): $(OBJ)
	$(LINK) -out:$(DLL) -implib:$(LIBRARY) $(OBJ)
  %.obj: %.cpp
	$(CCC) $(CCFLAGS) -c $<
else
  $(LIBRARY): $(OBJ)
	$(AR) $(LIBRARY) $(OBJ)
	$(RANLIB) $(LIBRARY)
  %.o: %.cpp
	$(CCC) $(CCFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIBRARY) $(DLL) $(EXP)

.PHONY: all clean


