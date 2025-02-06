include ../Makefile.rules

CFLAGS += -DzLib -DALLOW_FILE_LOCKING=1 -DRPN_SUPPORT -I../include

ifeq ($(OS), Linux)
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CFLAGS += -DEXPORT_SDDS /wd4244 /wd4267
  LIBRARY_LIBS = ../rpns/code/$(OBJ_DIR)/rpnlib.lib ../mdbmth/$(OBJ_DIR)/mdbmth.lib ../mdblib/$(OBJ_DIR)/mdblib.lib ../lzma/$(OBJ_DIR)/lzma.lib ../zlib/$(OBJ_DIR)/z.lib
endif

LIBRARY_SRC = SDDS_ascii.c \
          SDDS_binary.c \
          SDDS_copy.c \
          SDDS_data.c \
          SDDS_dataprep.c \
          SDDS_extract.c \
          SDDS_info.c \
          SDDS_input.c \
          SDDS_lzma.c \
          SDDS_mplsupport.c \
          SDDS_output.c \
          SDDS_process.c \
          SDDS_rpn.c \
          SDDS_transfer.c \
          SDDS_utils.c \
          SDDS_write.c

LIBRARY = SDDS1

include ../Makefile.build

$(OBJ_DIR)/SDDS_ascii.$(OBJEXT): SDDS_ascii.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_binary.$(OBJEXT): SDDS_binary.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_copy.$(OBJEXT): SDDS_copy.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_data.$(OBJEXT): SDDS_data.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_dataprep.$(OBJEXT): SDDS_dataprep.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_extract.$(OBJEXT): SDDS_extract.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_info.$(OBJEXT): SDDS_info.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_input.$(OBJEXT): SDDS_input.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_lzma.$(OBJEXT): SDDS_lzma.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_mplsupport.$(OBJEXT): SDDS_mplsupport.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_output.$(OBJEXT): SDDS_output.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_process.$(OBJEXT): SDDS_process.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_rpn.$(OBJEXT): SDDS_rpn.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_transfer.$(OBJEXT): SDDS_transfer.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_utils.$(OBJEXT): SDDS_utils.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/SDDS_write.$(OBJEXT): SDDS_write.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
