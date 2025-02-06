
# Detect OS and Architecture
OS := $(shell uname -s)
ARCH := $(shell uname -m)
ifeq ($(findstring CYGWIN, $(OS)),CYGWIN)
    OS := Windows
endif

ifeq ($(OS), Windows)
  CC = cl  # Use cl from Microsoft Visual Studio
  CFLAGS = -nologo -FC -D__STDC__=0 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -Ox -GL -Oy- -W3 -D_LARGEFILE64_SOURCE=1 -MD
  LINK = lib -nologo -verbose

  SRC = adler32.c \
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

  OBJ = $(SRC:.c=.obj)
  LIB = z.lib

all: $(LIB)

$(LIB): $(OBJ)
	$(LINK) -out:$(LIB) -LTCG $(OBJ)
%.obj: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(LIB)

else

all:
	@echo Not building zlib on $(OS)

clean:
	@echo Skipping on $(OS)

endif

.PHONY: all clean
