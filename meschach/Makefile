NO_DLL = 1
include ../Makefile.rules

CFLAGS += -I../include

ifeq ($(OS), Linux)
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CFLAGS += /wd4003 /wd4068 /wd4018
endif

LIBRARY_SRC = bdfactor.c \
	bkpfacto.c \
	chfactor.c \
	copy.c \
	err.c \
	fft.c \
	givens.c \
	hessen.c \
	hsehldr.c \
	init.c \
	iter0.c \
	iternsym.c \
	itersym.c \
	ivecop.c \
	lufactor.c \
	machine.c \
	matlab.c \
	matop.c \
	matrixio.c \
	meminfo.c \
	memory.c \
	memstat.c \
	mfunc.c	 \
	norm.c \
	otherio.c \
	pxop.c \
	qrfactor.c \
	schur.c \
	solve.c \
	sparse.c \
	sparseio.c \
	spbkp.c \
	spchfctr.c \
	splufctr.c \
	sprow.c \
	spswap.c \
	submat.c \
	svd.c \
	symmeig.c \
	update.c \
	vecop.c \
	version.c \
	zcopy.c \
	zfunc.c \
	zgivens.c \
	zhessen.c \
	zhsehldr.c \
	zlufctr.c \
	zmachine.c \
	zmatio.c \
	zmatlab.c \
	zmatop.c \
	zmemory.c \
	znorm.c \
	zqrfctr.c \
	zschur.c \
	zsolve.c \
	zvecop.c

LIBRARY = mdbmth

include ../Makefile.build

$(OBJ_DIR)/bdfactor.$(OBJEXT): bdfactor.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/bkpfacto.$(OBJEXT): bkpfacto.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/chfactor.$(OBJEXT): chfactor.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/copy.$(OBJEXT): copy.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/err.$(OBJEXT): err.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/fft.$(OBJEXT): fft.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/givens.$(OBJEXT): givens.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/hessen.$(OBJEXT): hessen.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/hsehldr.$(OBJEXT): hsehldr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/init.$(OBJEXT): init.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/iter0.$(OBJEXT): iter0.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/iternsym.$(OBJEXT): iternsym.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/itersym.$(OBJEXT): itersym.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ivecop.$(OBJEXT): ivecop.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lufactor.$(OBJEXT): lufactor.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/machine.$(OBJEXT): machine.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/matlab.$(OBJEXT): matlab.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/matop.$(OBJEXT): matop.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/matrixio.$(OBJEXT): matrixio.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/meminfo.$(OBJEXT): meminfo.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/memory.$(OBJEXT): memory.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/memstat.$(OBJEXT): memstat.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/mfunc.$(OBJEXT): mfunc.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/norm.$(OBJEXT): norm.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/otherio.$(OBJEXT): otherio.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/pxop.$(OBJEXT): pxop.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/qrfactor.$(OBJEXT): qrfactor.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/schur.$(OBJEXT): schur.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/solve.$(OBJEXT): solve.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sparse.$(OBJEXT): sparse.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sparseio.$(OBJEXT): sparseio.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/spbkp.$(OBJEXT): spbkp.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/spchfctr.$(OBJEXT): spchfctr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/splufctr.$(OBJEXT): splufctr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sprow.$(OBJEXT): sprow.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/spswap.$(OBJEXT): spswap.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/submat.$(OBJEXT): submat.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/svd.$(OBJEXT): svd.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/symmeig.$(OBJEXT): symmeig.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/update.$(OBJEXT): update.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/vecop.$(OBJEXT): vecop.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/version.$(OBJEXT): version.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zcopy.$(OBJEXT): zcopy.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zfunc.$(OBJEXT): zfunc.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zgivens.$(OBJEXT): zgivens.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zhessen.$(OBJEXT): zhessen.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zhsehldr.$(OBJEXT): zhsehldr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zlufctr.$(OBJEXT): zlufctr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zmachine.$(OBJEXT): zmachine.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zmatio.$(OBJEXT): zmatio.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zmatlab.$(OBJEXT): zmatlab.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zmatop.$(OBJEXT): zmatop.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zmemory.$(OBJEXT): zmemory.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/znorm.$(OBJEXT): znorm.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zqrfctr.$(OBJEXT): zqrfctr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zschur.$(OBJEXT): zschur.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zsolve.$(OBJEXT): zsolve.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zvecop.$(OBJEXT): zvecop.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
