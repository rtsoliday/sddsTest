# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

ifeq ($(OS), Windows)
  NO_DLL = 1
include ../Makefile.rules

  CFLAGS += -D_LARGEFILE64_SOURCE=1

  LIBRARY_SRC = adler32.c \
        compress.c \
        crc32.c \
        gzclose.c \
        gzlib.c \
        gzread.c \
        gzwrite.c \
        uncompr.c \
        deflate.c \
        trees.c \
        zutil.c \
        inflate.c \
        infback.c \
        inftrees.c \
        inffast.c

  LIBRARY = z

include ../Makefile.build

else

all:
	@echo Not building zlib on $(OS)

clean:
	@echo Skipping on $(OS)

.PHONY: all clean

endif

$(OBJ_DIR)/adler32.$(OBJEXT): adler32.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/compress.$(OBJEXT): compress.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/crc32.$(OBJEXT): crc32.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gzclose.$(OBJEXT): gzclose.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gzlib.$(OBJEXT): gzlib.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gzread.$(OBJEXT): gzread.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gzwrite.$(OBJEXT): gzwrite.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/uncompr.$(OBJEXT): uncompr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/deflate.$(OBJEXT): deflate.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/trees.$(OBJEXT): trees.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zutil.$(OBJEXT): zutil.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/inflate.$(OBJEXT): inflate.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/infback.$(OBJEXT): infback.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/inftrees.$(OBJEXT): inftrees.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/inffast.$(OBJEXT): inffast.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
