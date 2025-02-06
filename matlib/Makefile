include ../Makefile.rules

CFLAGS += -I../include

ifeq ($(OS), Linux)
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CFLAGS += -DEXPORT_MATLIB /wd4244
  LIBRARY_LIBS = ../mdbmth/$(OBJ_DIR)/mdbmth.lib ../mdblib/$(OBJ_DIR)/mdblib.lib
endif

LIBRARY_SRC = fmat.c m_add.c m_alloc.c \
		m_bench.c m_check.c m_copy.c \
		m_det.c m_error.c m_free.c \
		m_identity.c m_invert.c m_mult.c \
		m_scmul.c m_show.c m_trans.c \
		m_zero.c

LIBRARY = matlib

include ../Makefile.build

$(OBJ_DIR)/fmat.$(OBJEXT):  fmat.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_add.$(OBJEXT): m_add.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_alloc.$(OBJEXT): m_alloc.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_bench.$(OBJEXT): m_bench.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_check.$(OBJEXT): m_check.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_copy.$(OBJEXT): m_copy.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_det.$(OBJEXT): m_det.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_error.$(OBJEXT): m_error.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_free.$(OBJEXT): m_free.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_identity.$(OBJEXT): m_identity.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_invert.$(OBJEXT): m_invert.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_mult.$(OBJEXT): m_mult.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_scmul.$(OBJEXT): m_scmul.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_show.$(OBJEXT): m_show.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_trans.$(OBJEXT): m_trans.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/m_zero.$(OBJEXT): m_zero.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
