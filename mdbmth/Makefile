include ../Makefile.rules

CFLAGS += -I../include
CCFLAGS += -I../include

ifeq ($(OS), Linux)
  CFLAGS += -fopenmp
  CCFLAGS += -fopenmp
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CFLAGS += -DEXPORT_MDBMTH -openmp /wd4244
  CCFLAGS += -DEXPORT_MDBMTH -openmp /wd4244
  LIBRARY_LIBS = ../mdblib/$(OBJ_DIR)/mdblib.lib
endif

LIBRARY_SRC = betai.c \
          bsODEp.c \
          complex.cc \
          counter.c \
          dbessel.c \
          diffeqResDescrip.c \
          dlaran.c \
          drand.c \
          elliptic.c \
          factorial.c \
          factorize.c \
          findMinMax.c \
          gammai.c \
          gaussQuad.c \
          GillMillerIntegration.c \
          gridopt.c \
          gy.c \
          halton.c \
          interp.c \
          ipow.c \
          kstests.c \
          k13.c \
          k23.c \
          lincorr.c \
          linfit.c \
          logfile_gener.c \
          lsfBasisFns.c \
          makeHistogram.c \
          mcTable.c \
          median.c \
          mmid.c \
          moments.c \
          onedoptimize.c \
          poly.c \
          powellMin.c \
          qromb.c \
          rkODE.c \
          rowmedian.c \
          sigLevel.c \
          simplex.c \
          smooth.c \
          topbase.c \
          trapInteg.c \
          wofz.c \
          zeroIH.c \
          zeroInterp.c \
          zeroNewton.c \
          medianfilter.c \
          pointInsideContour.c

LIBRARY = mdbmth

include ../Makefile.build

$(OBJ_DIR)/betai.$(OBJEXT): betai.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/bsODEp.$(OBJEXT): bsODEp.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/complex.$(OBJEXT): complex.cc
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/counter.$(OBJEXT): counter.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/dbessel.$(OBJEXT): dbessel.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/diffeqResDescrip.$(OBJEXT): diffeqResDescrip.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/dlaran.$(OBJEXT): dlaran.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/drand.$(OBJEXT): drand.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/elliptic.$(OBJEXT): elliptic.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/factorial.$(OBJEXT): factorial.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/factorize.$(OBJEXT): factorize.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/findMinMax.$(OBJEXT): findMinMax.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gammai.$(OBJEXT): gammai.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gaussQuad.$(OBJEXT): gaussQuad.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/GillMillerIntegration.$(OBJEXT): GillMillerIntegration.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gridopt.$(OBJEXT): gridopt.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/gy.$(OBJEXT): gy.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/halton.$(OBJEXT): halton.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/interp.$(OBJEXT): interp.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ipow.$(OBJEXT): ipow.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/kstests.$(OBJEXT): kstests.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/k13.$(OBJEXT): k13.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/k23.$(OBJEXT): k23.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lincorr.$(OBJEXT): lincorr.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/linfit.$(OBJEXT): linfit.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/logfile_gener.$(OBJEXT): logfile_gener.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/lsfBasisFns.$(OBJEXT): lsfBasisFns.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/makeHistogram.$(OBJEXT): makeHistogram.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/mcTable.$(OBJEXT): mcTable.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/median.$(OBJEXT): median.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/mmid.$(OBJEXT): mmid.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/moments.$(OBJEXT): moments.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/onedoptimize.$(OBJEXT): onedoptimize.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/poly.$(OBJEXT): poly.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/powellMin.$(OBJEXT): powellMin.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/qromb.$(OBJEXT): qromb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rkODE.$(OBJEXT): rkODE.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rowmedian.$(OBJEXT): rowmedian.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sigLevel.$(OBJEXT): sigLevel.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/simplex.$(OBJEXT): simplex.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/smooth.$(OBJEXT): smooth.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/topbase.$(OBJEXT): topbase.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/trapInteg.$(OBJEXT): trapInteg.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/wofz.$(OBJEXT): wofz.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zeroIH.$(OBJEXT): zeroIH.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zeroInterp.$(OBJEXT): zeroInterp.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/zeroNewton.$(OBJEXT): zeroNewton.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/medianfilter.$(OBJEXT): medianfilter.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/pointInsideContour.$(OBJEXT): pointInsideContour.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
