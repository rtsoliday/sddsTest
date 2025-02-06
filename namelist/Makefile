.NOTPARALLEL:
NO_DLL = 1
include ../Makefile.rules

CFLAGS += -I../include

ifeq ($(OS), Linux)
  PROD_LIBS = -lnamelist -lrpnlib -lmdblib
endif

ifeq ($(OS), Darwin)
  PROD_LIBS = -lnamelist -lrpnlib -lmdblib
endif

ifeq ($(OS), Windows)
  CFLAGS += /wd4267
  LIBRARY_LIBS =
  PROD_LIBS = $(OBJ_DIR)/namelist.lib ../mdblib/$(OBJ_DIR)/mdblib.lib
  NO_DLL = 1
endif

LIRBRARY_SRC = escape_quotes.c \
          free_namelist.c \
          free_namelist_text.c \
          get_namelist.c \
          namelist_etc.c \
          print_namelist.c \
          process_namelist.c \
          scan_namelist.c \
          show_namelist.c \
          show_namelist_fields.c \
          zero_namelist.c

LIBRARY = namelist

PROD = nlpp

include ../Makefile.build

$(OBJ_DIR)/escape_quotes.$(OBJEXT): escape_quotes.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/free_namelist.$(OBJEXT): free_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/free_namelist_text.$(OBJEXT): free_namelist_text.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/get_namelist.$(OBJEXT): get_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/namelist_etc.$(OBJEXT): namelist_etc.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/print_namelist.$(OBJEXT): print_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/process_namelist.$(OBJEXT): process_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/scan_namelist.$(OBJEXT): scan_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/show_namelist.$(OBJEXT): show_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/show_namelist_fields.$(OBJEXT): show_namelist_fields.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zero_namelist.$(OBJEXT): zero_namelist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)

$(OBJ_DIR)/namelist_pp.$(OBJEXT): namelist_pp.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/scanargs.$(OBJEXT): scanargs.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)

$(OBJ_DIR)/nlpp: $(OBJ_DIR)/namelist_pp.o $(OBJ_DIR)/scanargs.o $(LIBRARY)
	$(CCC) -o $@ $(OBJ_DIR)/namelist_pp.o $(OBJ_DIR)/scanargs.o $(LDFLAGS) $(LIB_LINK_DIRS) $(PROD_LIBS) $(PROD_SYS_LIBS)
	cp -f $@ $(BIN_DIR)/
