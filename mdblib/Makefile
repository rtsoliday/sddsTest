include ../Makefile.rules

CFLAGS += -I../include

ifeq ($(OS), Linux)
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CFLAGS += -DEXPORT_MDBLIB /wd4244 /wd4267
endif

LIBRARY_SRC = array.c \
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

LIBRARY = mdblib

include ../Makefile.build

$(OBJ_DIR)/array.$(OBJEXT): array.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/backspace.$(OBJEXT): backspace.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/binary.$(OBJEXT): binary.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/binsert.$(OBJEXT): binsert.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/bomb.$(OBJEXT): bomb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/buffer.$(OBJEXT): buffer.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/clean_filename.$(OBJEXT): clean_filename.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/compress.$(OBJEXT): compress.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cp_str.$(OBJEXT): cp_str.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/data_scan.$(OBJEXT): data_scan.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/delete_bnd.$(OBJEXT): delete_bnd.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/delete_chars.$(OBJEXT): delete_chars.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/edit_string.$(OBJEXT): edit_string.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/fexists.$(OBJEXT): fexists.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filestat.$(OBJEXT): filestat.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/fill_array.$(OBJEXT): fill_array.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/fopen_e.$(OBJEXT): fopen_e.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/get_token_tq.$(OBJEXT): get_token_tq.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/headers.$(OBJEXT): headers.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/insert.$(OBJEXT): insert.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/interpret_escapes.$(OBJEXT): interpret_escapes.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/is_blank.$(OBJEXT): is_blank.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/match_string.$(OBJEXT): match_string.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/mkdir.$(OBJEXT): mkdir.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/non_dominated_sort.$(OBJEXT): non_dominated_sort.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/pad_with_spaces.$(OBJEXT): pad_with_spaces.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/query.$(OBJEXT): query.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rcdelete.$(OBJEXT): rcdelete.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/replace_chars.$(OBJEXT): replace_chars.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/replace_string.$(OBJEXT): replace_string.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/replacefile.$(OBJEXT): replacefile.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/report_stats.$(OBJEXT): report_stats.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/scanitemlist.$(OBJEXT): scanitemlist.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/searchPath.$(OBJEXT): searchPath.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sortfunctions.$(OBJEXT): sortfunctions.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/str_copy.$(OBJEXT): str_copy.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/str_in.$(OBJEXT): str_in.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/str_inn.$(OBJEXT): str_inn.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/str_tolower.$(OBJEXT): str_tolower.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/str_toupper.$(OBJEXT): str_toupper.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/strslide.$(OBJEXT): strslide.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/substituteTagValue.$(OBJEXT): substituteTagValue.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/time.$(OBJEXT): time.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/timeconvert.$(OBJEXT): timeconvert.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/timer.$(OBJEXT): timer.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/tmpname.$(OBJEXT): tmpname.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/trim_spaces.$(OBJEXT): trim_spaces.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/unpack.$(OBJEXT): unpack.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/wild_match.$(OBJEXT): wild_match.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
