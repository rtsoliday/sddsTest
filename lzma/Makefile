
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

# Default Compiler and Flags
CC = gcc
AR = ar rcs
RANLIB = ranlib
CFLAGS = -m64 -O3 -g -Wall -fPIC -I.

ifeq ($(OS), Linux)
   CFLAGS += -std=gnu99 -DHAVE_CONFIG_H -DTUKLIB_SYMBOL_PREFIX=lzma_ -DHAVE_BSWAP_16 -DHAVE_BSWAP_32 -DHAVE_BSWAP_64 -DHAVE_BYTESWAP_H -DHAVE_DECL_PROGRAM_INVOCATION_NAME -DHAVE_VISIBILITY -DSIZEOF_SIZE_T=8 -DTUKLIB_FAST_UNALIGNED_ACCESS -DHAVE_DCGETTEXT -DHAVE_FUTIMENS -DHAVE_GETTEXT -DHAVE_STRUCT_STAT_ST_ATIM_TV_NSEC -DTUKLIB_CPUCORES_SYSCONF -DTUKLIB_PHYSMEM_SYSCONF -DHAVE_INTTYPES_H -DHAVE_STDBOOL_H -DHAVE_STRINGS_H -DHAVE_PTHREAD -DHAVE__BOOL
   CUSTOM_GCC_PATH = /usr/local/oag/3rdParty/gcc-11.3.0
   ifneq ($(wildcard $(CUSTOM_GCC_PATH)),)
      CC = $(CUSTOM_GCC_PATH)/bin/gcc
      AR = $(CUSTOM_GCC_PATH)/bin/gcc-ar -rc
      RANLIB = $(CUSTOM_GCC_PATH)/bin/gcc-ranlib
   endif
endif

# Adjust for macOS
ifeq ($(OS), Darwin)
    CC = clang
    AR = libtool -static -o
    RANLIB = ranlib
    CFLAGS += -mmacosx-version-min=10.13 -Wno-deprecated-non-prototype
    ifeq ($(ARCH), x86_64)
        CFLAGS += -std=gnu99 -DHAVE_CONFIG_H -DTUKLIB_SYMBOL_PREFIX=lzma_ -DHAVE_CFLOCALECOPYCURRENT -DHAVE_CFPREFERENCESCOPYAPPVALUE -DHAVE_DECL_PROGRAM_INVOCATION_NAME=0 -DHAVE_ICONV -DHAVE_VISIBILITY -DSIZEOF_SIZE_T=8 -DTUKLIB_FAST_UNALIGNED_ACCESS -DHAVE_FUTIMES -DHAVE_OPTRESET -DHAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC -DTUKLIB_CPUCORES_SYSCTL -DTUKLIB_PHYSMEM_SYSCTL -DHAVE_INTTYPES_H -DHAVE_STDBOOL_H -DHAVE_STRINGS_H -DHAVE_PTHREAD -DHAVE__BOOL
    endif
    ifeq ($(ARCH), arm64)
        CFLAGS += -std=gnu99 -DHAVE_CONFIG_H -DTUKLIB_SYMBOL_PREFIX=lzma_ -DHAVE_CFLOCALECOPYCURRENT -DHAVE_CFPREFERENCESCOPYAPPVALUE -DHAVE_DECL_PROGRAM_INVOCATION_NAME=0 -DHAVE_DECODER_ARM -DHAVE_DECODER_ARMTHUMB -DHAVE_DECODER_DELTA -DHAVE_DECODER_IA64 -DHAVE_DECODER_LZMA1 -DHAVE_DECODER_POWERPC -DHAVE_DECODER_SPARC -DHAVE_DECODER_X86 -DHAVE_ENCODER_ARM -DHAVE_ENCODER_ARMTHUMB -DHAVE_ENCODER_DELTA -DHAVE_ENCODER_IA64 -DHAVE_ENCODER_LZMA1 -DHAVE_ENCODER_POWERPC -DHAVE_ENCODER_SPARC -DHAVE_ENCODER_X86 -DHAVE_FUTIMENS -DHAVE_ICONV -DHAVE_INTTYPES_H -DHAVE_OPTRESET -DHAVE_STDBOOL_H -DHAVE_STRINGS_H -DHAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC -DHAVE_VISIBILITY -DHAVE__BOOL -DSIZEOF_SIZE_T=8 -DTUKLIB_CPUCORES_SYSCTL -DTUKLIB_PHYSMEM_SYSCTL -DHAVE_PTHREAD
    endif

endif

# Adjust for Architecture
ifeq ($(ARCH), x86_64)
    CFLAGS += -mtune=generic
endif

ifeq ($(ARCH), aarch64)
    CFLAGS += -mcpu=native
endif

ifeq ($(ARCH), arm64)
    CFLAGS += -mcpu=native
endif

# Adjust for Windows in a cygwin terminal
ifeq ($(OS), Windows)
    CC = cl  # Use cl from Microsoft Visual Studio
    CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -MD
    LINK = lib -nologo -verbose
endif

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

ifeq ($(OS), Windows)
  OBJ = $(SRC:.c=.obj)
  LIB = lzma.lib
else
  OBJ = $(SRC:.c=.o)
  LIB = liblzma.a
endif

all: $(LIB)

ifeq ($(OS), Windows)
  $(LIB): $(OBJ)
	$(LINK) -out:$(LIB) -LTCG $(OBJ)
  %.obj: %.c
	$(CC) $(CFLAGS) -c $<
else
  $(LIB): $(OBJ)
	$(AR) $(LIB) $(OBJ)
	$(RANLIB) $(LIB)
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	rm -f $(OBJ) $(LIB)

.PHONY: all clean


