include ../Makefile.rules

CFLAGS += -DH5_USE_16_API -I../include

ifeq ($(OS), Linux)
  PROD_SYS_LIBS := $(HDF5_LIB) $(LZMA_LIB) $(GSL_LIB) $(GSLCBLAS_LIB) $(Z_LIB) $(PROD_SYS_LIBS)
  PROD_LIBS = -lmdbcommon -lSDDS1 -lrpnlib -lmdbmth -lmdblib
endif

ifeq ($(OS), Darwin)
  PROD_SYS_LIBS := $(HDF5_LIB) $(SZ_LIB) $(LZMA_LIB) $(GSL_LIB) $(GSLCBLAS_LIB) $(Z_LIB) $(PROD_SYS_LIBS)
  PROD_LIBS = -lmdbcommon -lSDDS1 -lrpnlib -lmdbmth -lmdblib
endif

ifeq ($(OS), Windows)
  CFLAGS += -I$(HDF_DIR)/include
  PROD_LIBS = ../SDDSlib/SDDS1.lib ../mdbcommon/mdbcommon.lib ../mdbmth/mdbmth.lib ../mdblib/mdblib.lib ../zlib/z.lib $(HDF_DIR)/lib/libhdf5.lib $(HDF_DIR)/lib/libsz.lib $(HDF_DIR)/lib/libaec.lib 
endif

PROGS = editstring replaceText isFileLocked hdf2sdds sdds2hdf

include ../Makefile.build

editstring.$(OBJEXT): editstring.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
replaceText.$(OBJEXT): replaceText.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
isFileLocked.$(OBJEXT): isFileLocked.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
hdf2sdds.$(OBJEXT): hdf2sdds.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
sdds2hdf.$(OBJEXT): sdds2hdf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)

