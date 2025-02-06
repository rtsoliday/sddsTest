
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

ifeq ($(OS), Windows)

include ../Makefile.rules

  CFLAGS += -DHAVE_CONFIG_H -DTUKLIB_SYMBOL_PREFIX=lzma_ -DHAVE_BSWAP_16 -DHAVE_BSWAP_32 -DHAVE_BSWAP_64 -DHAVE_DECL_PROGRAM_INVOCATION_NAME -DHAVE_VISIBILITY -DSIZEOF_SIZE_T=8 -DTUKLIB_FAST_UNALIGNED_ACCESS -DHAVE_DCGETTEXT -DHAVE_FUTIMENS -DHAVE_GETTEXT -DHAVE_STRUCT_STAT_ST_ATIM_TV_NSEC -DTUKLIB_CPUCORES_SYSCONF -DTUKLIB_PHYSMEM_SYSCONF -DEXPORT_LZMA /TP /wd4003 /wd4200 /wd4244 /wd4267 /wd4996

  LIBRARY_SRC = alone_decoder.c \
	alone_encoder.c \
	arm.c \
	armthumb.c \
	auto_decoder.c \
	block_buffer_decoder.c \
	block_buffer_encoder.c \
	block_decoder.c \
	block_encoder.c \
	block_header_decoder.c \
	block_header_encoder.c \
	block_util.c \
	check.c \
	common.c \
	crc32_fast.c \
	crc32_table.c \
	crc64_fast.c \
	crc64_table.c \
	delta_common.c \
	delta_decoder.c \
	delta_encoder.c \
	easy_buffer_encoder.c \
	easy_decoder_memusage.c \
	easy_encoder.c \
	easy_encoder_memusage.c \
	easy_preset.c \
	fastpos_table.c \
	filter_buffer_decoder.c \
	filter_buffer_encoder.c \
	filter_common.c \
	filter_decoder.c \
	filter_encoder.c \
	filter_flags_decoder.c \
	filter_flags_encoder.c \
	hardware_physmem.c \
	ia64.c \
	index.c \
	index_decoder.c \
	index_encoder.c \
	index_hash.c \
	lz_decoder.c \
	lz_encoder.c \
	lz_encoder_mf.c \
	lzma2_decoder.c \
	lzma2_encoder.c \
	lzma_decoder.c \
	lzma_encoder.c \
	lzma_encoder_optimum_fast.c \
	lzma_encoder_optimum_normal.c \
	lzma_encoder_presets.c \
	powerpc.c \
	price_table.c \
	sha256.c \
	simple_coder.c \
	simple_decoder.c \
	simple_encoder.c \
	sparc.c \
	stream_buffer_decoder.c \
	stream_buffer_encoder.c \
	stream_decoder.c \
	stream_encoder.c \
	stream_flags_common.c \
	stream_flags_decoder.c \
	stream_flags_encoder.c \
	tuklib_physmem.c \
	vli_decoder.c \
	vli_encoder.c \
	vli_size.c \
	x86.c

  LIBRARY = lzma

include ../Makefile.build

else

all:
	@echo Not building zlib on $(OS)

clean:
	@echo Skipping on $(OS)

.PHONY: all clean

endif

$(OBJ_DIR)/alone_decoder.$(OBJEXT): alone_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/alone_encoder.$(OBJEXT): alone_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/arm.$(OBJEXT): arm.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/armthumb.$(OBJEXT): armthumb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/auto_decoder.$(OBJEXT): auto_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_buffer_decoder.$(OBJEXT): block_buffer_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_buffer_encoder.$(OBJEXT): block_buffer_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_decoder.$(OBJEXT): block_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_encoder.$(OBJEXT): block_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_header_decoder.$(OBJEXT): block_header_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_header_encoder.$(OBJEXT): block_header_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/block_util.$(OBJEXT): block_util.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/check.$(OBJEXT): check.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/common.$(OBJEXT): common.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/crc32_fast.$(OBJEXT): crc32_fast.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/crc32_table.$(OBJEXT): crc32_table.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/crc64_fast.$(OBJEXT): crc64_fast.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/crc64_table.$(OBJEXT): crc64_table.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/delta_common.$(OBJEXT): delta_common.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/delta_decoder.$(OBJEXT): delta_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/delta_encoder.$(OBJEXT): delta_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/easy_buffer_encoder.$(OBJEXT): easy_buffer_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/easy_decoder_memusage.$(OBJEXT): easy_decoder_memusage.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/easy_encoder.$(OBJEXT): easy_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/easy_encoder_memusage.$(OBJEXT): easy_encoder_memusage.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/easy_preset.$(OBJEXT): easy_preset.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/fastpos_table.$(OBJEXT): fastpos_table.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_buffer_decoder.$(OBJEXT): filter_buffer_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_buffer_encoder.$(OBJEXT): filter_buffer_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_common.$(OBJEXT): filter_common.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_decoder.$(OBJEXT): filter_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_encoder.$(OBJEXT): filter_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_flags_decoder.$(OBJEXT): filter_flags_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/filter_flags_encoder.$(OBJEXT): filter_flags_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/hardware_physmem.$(OBJEXT): hardware_physmem.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ia64.$(OBJEXT): ia64.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/index.$(OBJEXT): index.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/index_decoder.$(OBJEXT): index_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/index_encoder.$(OBJEXT): index_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/index_hash.$(OBJEXT): index_hash.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lz_decoder.$(OBJEXT): lz_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lz_encoder.$(OBJEXT): lz_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lz_encoder_mf.$(OBJEXT): lz_encoder_mf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma2_decoder.$(OBJEXT): lzma2_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma2_encoder.$(OBJEXT): lzma2_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma_decoder.$(OBJEXT): lzma_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma_encoder.$(OBJEXT): lzma_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma_encoder_optimum_fast.$(OBJEXT): lzma_encoder_optimum_fast.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma_encoder_optimum_normal.$(OBJEXT): lzma_encoder_optimum_normal.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lzma_encoder_presets.$(OBJEXT): lzma_encoder_presets.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/powerpc.$(OBJEXT): powerpc.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/price_table.$(OBJEXT): price_table.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sha256.$(OBJEXT): sha256.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/simple_coder.$(OBJEXT): simple_coder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/simple_decoder.$(OBJEXT): simple_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/simple_encoder.$(OBJEXT): simple_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sparc.$(OBJEXT): sparc.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_buffer_decoder.$(OBJEXT): stream_buffer_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_buffer_encoder.$(OBJEXT): stream_buffer_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_decoder.$(OBJEXT): stream_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_encoder.$(OBJEXT): stream_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_flags_common.$(OBJEXT): stream_flags_common.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_flags_decoder.$(OBJEXT): stream_flags_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/stream_flags_encoder.$(OBJEXT): stream_flags_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/tuklib_physmem.$(OBJEXT): tuklib_physmem.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/vli_decoder.$(OBJEXT): vli_decoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/vli_encoder.$(OBJEXT): vli_encoder.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/vli_size.$(OBJEXT): vli_size.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/x86.$(OBJEXT): x86.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
