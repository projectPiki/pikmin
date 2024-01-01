AI_FILES:=\
	$(BUILD_DIR)/asm/ai/ai.o\

$(AI_FILES): CFLAGS += -common off
$(AI_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(AI_FILES:.o=.d)

$(BUILD_DIR)/src/ai/ai.a: $(AI_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(AI_FILES) > build/AI_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/AI_ofiles
