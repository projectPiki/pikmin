HVQM4DEC_FILES:=\
	$(BUILD_DIR)/asm/hvqm4dec/hvqm4dec.o\

$(HVQM4DEC_FILES): CFLAGS += -common off
$(HVQM4DEC_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(HVQM4DEC_FILES:.o=.d)

$(BUILD_DIR)/src/hvqm4dec/hvqm4dec.a: $(HVQM4DEC_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(HVQM4DEC_FILES) > build/HVQM4DEC_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/HVQM4DEC_ofiles
