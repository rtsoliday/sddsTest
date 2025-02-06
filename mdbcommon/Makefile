include ../Makefile.rules

CFLAGS += -I../include

ifeq ($(OS), Linux)
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CFLAGS += -DEXPORT_MDBCOMMON /wd4244 /wd4267
  LIBRARY_LIBS = ../matlib/$(OBJ_DIR)/matlib.lib ../fftpack/$(OBJ_DIR)/fftpack.lib ../SDDSlib/$(OBJ_DIR)/SDDS1.lib ../mdbmth/$(OBJ_DIR)/mdbmth.lib ../mdblib/$(OBJ_DIR)/mdblib.lib
endif

LIBRARY_SRC = fixcounts.c find_files.c  \
		lsfg.c lsfn.c \
		lsfp.c savitzkyGolay.c scanargs.c \
		table.c hashtab.c lookupa.c recycle.c rcds_powell.c

LIBRARY = mdbcommon

include ../Makefile.build

$(OBJ_DIR)/fixcounts.$(OBJEXT): fixcounts.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/find_files.$(OBJEXT): find_files.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lsfg.$(OBJEXT): lsfg.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lsfn.$(OBJEXT): lsfn.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lsfp.$(OBJEXT): lsfp.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/savitzkyGolay.$(OBJEXT): savitzkyGolay.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/scanargs.$(OBJEXT): scanargs.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/table.$(OBJEXT): table.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/hashtab.$(OBJEXT): hashtab.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lookupa.$(OBJEXT): lookupa.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/recycle.$(OBJEXT): recycle.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rcds_powell.$(OBJEXT): rcds_powell.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
