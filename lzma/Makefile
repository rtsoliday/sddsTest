
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

ifeq ($(OS), Windows)
  CC = cl  # Use cl from Microsoft Visual Studio
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -DHAVE_CONFIG_H -DTUKLIB_SYMBOL_PREFIX=lzma_ -DHAVE_BSWAP_16 -DHAVE_BSWAP_32 -DHAVE_BSWAP_64 -DHAVE_DECL_PROGRAM_INVOCATION_NAME -DHAVE_VISIBILITY -DSIZEOF_SIZE_T=8 -DTUKLIB_FAST_UNALIGNED_ACCESS -DHAVE_DCGETTEXT -DHAVE_FUTIMENS -DHAVE_GETTEXT -DHAVE_STRUCT_STAT_ST_ATIM_TV_NSEC -DTUKLIB_CPUCORES_SYSCONF -DTUKLIB_PHYSMEM_SYSCONF -DEXPORT_LZMA /TP -MD /wd4003 /wd4200 /wd4244 /wd4267 /wd4996 -I.
  LINK = link -nologo -subsystem:windows -dll -LTCG -incremental:no -opt:ref -release -MACHINE:X64

  SRC = alone_decoder.c \
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

  OBJ = $(SRC:.c=.obj)
  LIBRARY = lzma.lib
  DLL = lzma.dll
  EXP = lzma.exp

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	$(LINK) -out:$(DLL) -implib:$(LIBRARY) $(OBJ)
%.obj: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(LIBRARY) $(DLL) $(EXP)

else

all:
	@echo Not building zlib on $(OS)

clean:
	@echo Skipping on $(OS)

endif

.PHONY: all clean


