include ../Makefile.rules

CFLAGS += -I../include
CCFLAGS += -I../include

ifeq ($(OS), Linux)
  CFLAGS += -fopenmp
  CCFLAGS += -fopenmp
endif

ifeq ($(OS), Darwin)
  CFLAGS += -fopenmp
  CCFLAGS += -fopenmp
endif

ifeq ($(OS), Windows)
  CFLAGS += -openmp -DEXPORT_FFTPACK /wd4244
  CCFLAGS = -openmp -DEXPORT_FFTPACK /wd4244
  LIBRARY_LIBS = ../mdbmth/$(OBJ_DIR)/mdbmth.lib ../mdblib/$(OBJ_DIR)/mdblib.lib
endif

LIBRARY_SRC = cfftb.c cfftb1.c cfftf.c \
		cfftf1.c cffti.c cffti1.c \
		cosqb.c cosqb1.c cosqf.c \
		cosqf1.c cosqi.c cost.c \
		costi.c dfilter.cc ezfft1.c \
		ezfftb.c ezfftf.c ezffti.c \
		fftpackC.c naff.c passb.c \
		passb2.c passb3.c passb4.c \
		passb5.c passf.c passf2.c \
		passf3.c passf4.c passf5.c \
		radb2.c radb3.c radb4.c \
		radb5.c radbg.c radf2.c \
		radf3.c radf4.c radf5.c \
		radfg.c rfftb.c rfftb1.c \
		rfftf.c rfftf1.c rffti.c \
		rffti1.c sinqb.c sinqf.c \
		sinqi.c sint.c sint1.c \
		sinti.c

LIBRARY = fftpack

include ../Makefile.build

$(OBJ_DIR)/cfftb.$(OBJEXT): cfftb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cfftb1.$(OBJEXT): cfftb1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cfftf.$(OBJEXT): cfftf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cfftf1.$(OBJEXT): cfftf1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cffti.$(OBJEXT): cffti.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cffti1.$(OBJEXT): cffti1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cosqb.$(OBJEXT): cosqb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cosqb1.$(OBJEXT): cosqb1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cosqf.$(OBJEXT): cosqf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cosqf1.$(OBJEXT): cosqf1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cosqi.$(OBJEXT): cosqi.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cost.$(OBJEXT): cost.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/costi.$(OBJEXT): costi.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/dfilter.$(OBJEXT): dfilter.cc
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ezfft1.$(OBJEXT): ezfft1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ezfftb.$(OBJEXT): ezfftb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ezfftf.$(OBJEXT): ezfftf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/ezffti.$(OBJEXT): ezffti.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/fftpackC.$(OBJEXT): fftpackC.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/naff.$(OBJEXT): naff.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passb.$(OBJEXT): passb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passb2.$(OBJEXT): passb2.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passb3.$(OBJEXT): passb3.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passb4.$(OBJEXT): passb4.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passb5.$(OBJEXT): passb5.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passf.$(OBJEXT): passf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passf2.$(OBJEXT): passf2.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passf3.$(OBJEXT): passf3.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passf4.$(OBJEXT): passf4.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/passf5.$(OBJEXT): passf5.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radb2.$(OBJEXT): radb2.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radb3.$(OBJEXT): radb3.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radb4.$(OBJEXT): radb4.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radb5.$(OBJEXT): radb5.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radbg.$(OBJEXT): radbg.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radf2.$(OBJEXT): radf2.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radf3.$(OBJEXT): radf3.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radf4.$(OBJEXT): radf4.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radf5.$(OBJEXT): radf5.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/radfg.$(OBJEXT): radfg.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rfftb.$(OBJEXT): rfftb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rfftb1.$(OBJEXT): rfftb1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rfftf.$(OBJEXT): rfftf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rfftf1.$(OBJEXT): rfftf1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rffti.$(OBJEXT): rffti.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/rffti1.$(OBJEXT): rffti1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sinqb.$(OBJEXT): sinqb.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sinqf.$(OBJEXT): sinqf.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sinqi.$(OBJEXT): sinqi.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sint.$(OBJEXT): sint.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sint1.$(OBJEXT): sint1.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sinti.$(OBJEXT): sinti.c
	$(CC) $(CFLAGS) -c $< $(OUTPUT)
