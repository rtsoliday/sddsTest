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

.PHONY: all $(DIRS) clean

all: $(DIRS)

mdblib: zlib
	$(MAKE) -C $@
mdbmth: mdblib
	$(MAKE) -C $@
rpns/code: mdbmth
	$(MAKE) -C $@
namelist: rpns/code
	$(MAKE) -C $@
SDDSlib: rpns/code
	$(MAKE) -C $@
fftpack: mdbmth
	$(MAKE) -C $@
matlib: mdbmth
	$(MAKE) -C $@
mdbcommon: SDDSlib fftpack matlib
	$(MAKE) -C $@
$(DIRS):
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

