NO_DLL = 1

include ../Makefile.rules

CCFLAGS += -DHAVE_CONFIG_H=1 -DEXPORT_XLS -I../include -I.

ifeq ($(OS), Linux)
endif

ifeq ($(OS), Darwin)
endif

ifeq ($(OS), Windows)
  CCFLAGS += /wd4003 /wd4267 /wd4068 /wd4018 -D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
endif

LIBRARY_SRC = assert_assist.cpp \
	blank.cpp \
	boolean.cpp \
	cbridge.cpp \
	cell.cpp \
	colinfo.cpp \
	colors.cpp \
	continue.cpp \
	datast.cpp \
	docsumminfo.cpp \
	err.cpp \
	extformat.cpp \
	font.cpp \
	format.cpp \
	formula.cpp \
	formula_cell.cpp \
	formula_estimate.cpp \
	formula_expr.cpp \
	globalrec.cpp \
	HPSF.cpp \
	index.cpp \
	label.cpp \
	merged.cpp \
	note.cpp \
	number.cpp \
	range.cpp \
	recdef.cpp \
	record.cpp \
	row.cpp \
	sheetrec.cpp \
	summinfo.cpp \
	unit.cpp \
	workbook.cpp \
	binfile.cpp \
	oledoc.cpp \
	olefs.cpp \
	oleprop.cpp

LIBRARY = xls

include ../Makefile.build

$(OBJ_DIR)/assert_assist.$(OBJEXT): assert_assist.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/blank.$(OBJEXT): blank.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/boolean.$(OBJEXT): boolean.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cbridge.$(OBJEXT): cbridge.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/cell.$(OBJEXT): cell.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/colinfo.$(OBJEXT): colinfo.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/colors.$(OBJEXT): colors.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/continue.$(OBJEXT): continue.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/datast.$(OBJEXT): datast.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/docsumminfo.$(OBJEXT): docsumminfo.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/err.$(OBJEXT): err.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/extformat.$(OBJEXT): extformat.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/font.$(OBJEXT): font.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/format.$(OBJEXT): format.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/formula.$(OBJEXT): formula.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/formula_cell.$(OBJEXT): formula_cell.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/formula_estimate.$(OBJEXT): formula_estimate.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/formula_expr.$(OBJEXT): formula_expr.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/globalrec.$(OBJEXT): globalrec.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/HPSF.$(OBJEXT): HPSF.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/index.$(OBJEXT): index.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/label.$(OBJEXT): label.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/merged.$(OBJEXT): merged.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/note.$(OBJEXT): note.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/number.$(OBJEXT): number.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/range.$(OBJEXT): range.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/recdef.$(OBJEXT): recdef.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/record.$(OBJEXT): record.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/row.$(OBJEXT): row.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/sheetrec.$(OBJEXT): sheetrec.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/summinfo.$(OBJEXT): summinfo.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/unit.$(OBJEXT): unit.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/workbook.$(OBJEXT): workbook.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/binfile.$(OBJEXT): binfile.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/oledoc.$(OBJEXT): oledoc.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/olefs.$(OBJEXT): olefs.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
$(OBJ_DIR)/oleprop.$(OBJEXT): oleprop.cpp
	$(CCC) $(CCFLAGS) -c $< $(OUTPUT)
