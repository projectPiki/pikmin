MTX_FILES:=\
	$(BUILD_DIR)/asm/mtx/mtx.o\
	$(BUILD_DIR)/asm/mtx/mtx44.o\
	$(BUILD_DIR)/asm/mtx/vec.o\

$(MTX_FILES): CFLAGS += -common off
$(MTX_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(MTX_FILES:.o=.d)

$(BUILD_DIR)/src/mtx/mtx.a: $(MTX_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(MTX_FILES) > build/MTX_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/MTX_ofiles
