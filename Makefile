DIRS = meschach
DIRS += xlslib
DIRS += zlib
DIRS += lzma
DIRS += mdblib
DIRS += mdbmth
DIRS += rpns/code
DIRS += namelist
DIRS += SDDSlib
DIRS += fftpack
DIRS += matlib
DIRS += mdbcommon
DIRS += utils

.PHONY: all $(DIRS) clean

all: $(DIRS)

meschach:
	$(MAKE) -C $@
xlslib:
	$(MAKE) -C $@
zlib:
	$(MAKE) -C $@
lzma:
	$(MAKE) -C $@
mdblib: zlib
	$(MAKE) -C $@
mdbmth: mdblib
	$(MAKE) -C $@
rpns/code: mdbmth
	$(MAKE) -C $@
namelist: mdblib
	$(MAKE) -C $@
SDDSlib: rpns/code
	$(MAKE) -C $@
fftpack: mdbmth
	$(MAKE) -C $@
matlib: mdbmth
	$(MAKE) -C $@
mdbcommon: SDDSlib fftpack matlib
	$(MAKE) -C $@
utils: mdbcommon
	$(MAKE) -C $@

clean:
	$(MAKE) -C meschach clean
	$(MAKE) -C xlslib clean
	$(MAKE) -C zlib clean
	$(MAKE) -C lzma clean
	$(MAKE) -C mdblib clean
	$(MAKE) -C mdbmth clean
	$(MAKE) -C rpns/code clean
	$(MAKE) -C namelist clean
	$(MAKE) -C SDDSlib clean
	$(MAKE) -C fftpack clean
	$(MAKE) -C matlib clean
	$(MAKE) -C mdbcommon clean
	$(MAKE) -C utils clean

