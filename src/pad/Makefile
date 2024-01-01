PAD_FILES:=\
	$(BUILD_DIR)/asm/pad/Padclamp.o\
	$(BUILD_DIR)/asm/pad/Pad.o\

$(PAD_FILES): CFLAGS += -common off
$(PAD_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(PAD_FILES:.o=.d)

$(BUILD_DIR)/src/pad/pad.a: $(PAD_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(PAD_FILES) > build/PAD_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/PAD_ofiles
