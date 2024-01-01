AMCEXI2_FILES:=\
	$(BUILD_DIR)/asm/amcExi2/AmcExi.o\
	$(BUILD_DIR)/asm/amcExi2/AmcExi2Comm.o\

$(AMCEXI2_FILES): CFLAGS += -common off
$(AMCEXI2_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(AMCEXI2_FILES:.o=.d)

$(BUILD_DIR)/src/amcExi2/amcExi2.a: $(AMCEXI2_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(AMCEXI2_FILES) > build/AMCEXI2_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/AMCEXI2_ofiles
