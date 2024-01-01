DVD_FILES:=\
	$(BUILD_DIR)/asm/dvd/dvdlow.o\
	$(BUILD_DIR)/asm/dvd/dvdfs.o\
	$(BUILD_DIR)/asm/dvd/dvd.o\
	$(BUILD_DIR)/asm/dvd/dvdqueue.o\
	$(BUILD_DIR)/asm/dvd/dvderror.o\
	$(BUILD_DIR)/asm/dvd/fstload.o\

$(DVD_FILES): CFLAGS += -common off
$(DVD_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(DVD_FILES:.o=.d)

$(BUILD_DIR)/src/dvd/dvd.a: $(DVD_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(DVD_FILES) > build/DVD_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/DVD_ofiles
