HIO_FILES:=\
	$(BUILD_DIR)/asm/hio/hio.o\

$(HIO_FILES): CFLAGS += -common off
$(HIO_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(HIO_FILES:.o=.d)

$(BUILD_DIR)/src/hio/hio.a: $(HIO_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(HIO_FILES) > build/HIO_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/HIO_ofiles
