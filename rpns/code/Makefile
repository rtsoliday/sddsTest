.NOTPARALLEL:
DD = ../
include ../../Makefile.rules

CFLAGS += -I../../include

ifeq ($(OS), Linux)
  CFLAGS += -DUSE_GSL
  PROD_SYS_LIBS := $(GSL_LIB) $(GSLCBLAS_LIB) $(Z_LIB) $(PROD_SYS_LIBS)
  PROD_LIBS = -lrpnlib -lmdbmth -lmdblib 
endif

ifeq ($(OS), Darwin)
  CFLAGS += -DUSE_GSL
  PROD_SYS_LIBS := $(GSL_LIB) $(GSLCBLAS_LIB) $(Z_LIB) $(PROD_SYS_LIBS)
  PROD_LIBS = -lrpnlib -lmdbmth -lmdblib 
endif

ifeq ($(OS), Windows)
  CFLAGS += /wd4244 /wd4267
  LIBRARY_CFLAGS = -DEXPORT_RPNLIB
  LIBRARY_LIBS = ../../mdbmth/$(OBJ_DIR)/mdbmth.lib ../../mdblib/$(OBJ_DIR)/mdblib.lib
  PROD_LIBS = $(OBJ_DIR)/rpnlib.lib  ../../mdbmth/$(OBJ_DIR)/mdbmth.lib ../../mdblib/$(OBJ_DIR)/mdblib.lib
endif

LIBRARY_SRC = array.c \
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

LIBRARY = rpnlib

PROD = rpn rpnl if2pf

include ../../Makefile.build

$(OBJ_DIR)/array.$(OBJEXT): array.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/conditional.$(OBJEXT): conditional.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/execute.$(OBJEXT): execute.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/get_token_rpn.$(OBJEXT): get_token_rpn.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/infixtopostfix.$(OBJEXT): infixtopostfix.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/logical.$(OBJEXT): logical.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/math.$(OBJEXT): math.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/memory.$(OBJEXT): memory.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/pcode.$(OBJEXT): pcode.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/pop_push.$(OBJEXT): pop_push.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/prompt.$(OBJEXT): prompt.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpn_csh.$(OBJEXT): rpn_csh.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpn_data.$(OBJEXT): rpn_data.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpn_draw.$(OBJEXT): rpn_draw.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpn_error.$(OBJEXT): rpn_error.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpn_io.$(OBJEXT): rpn_io.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpn_sub.$(OBJEXT): rpn_sub.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stack.$(OBJEXT): stack.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/udf.$(OBJEXT): udf.c
	$(CC) $(CFLAGS) $(LIBRARY_CFLAGS) -c $< $(OUTPUT)

$(OBJ_DIR)/rpn.$(OBJEXT): rpn.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rpnl.$(OBJEXT): rpnl.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/if2pf.$(OBJEXT): if2pf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
