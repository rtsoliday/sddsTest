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
  CFLAGS += -I$(HDF_DIR)/include -DEXPORT_MDBCOMMON
  PROD_LIBS = ../SDDSlib/$(OBJ_DIR)/SDDS1.lib ../mdbcommon/$(OBJ_DIR)/mdbcommon.lib ../mdbmth/$(OBJ_DIR)/mdbmth.lib ../mdblib/$(OBJ_DIR)/mdblib.lib ../zlib/$(OBJ_DIR)/z.lib $(HDF_DIR)/lib/libhdf5.lib $(HDF_DIR)/lib/libsz.lib $(HDF_DIR)/lib/libaec.lib 
endif

PROD = editstring replaceText isFileLocked hdf2sdds sdds2hdf

include ../Makefile.build

$(OBJ_DIR)/editstring.$(OBJEXT): editstring.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/replaceText.$(OBJEXT): replaceText.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/isFileLocked.$(OBJEXT): isFileLocked.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/hdf2sdds.$(OBJEXT): hdf2sdds.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sdds2hdf.$(OBJEXT): sdds2hdf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)

