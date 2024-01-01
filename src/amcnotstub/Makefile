AMCNOTSTUB_FILES:=\
	$(BUILD_DIR)/src/amcnotstub/amcnotstub.o\

$(AMCNOTSTUB_FILES): CFLAGS += -common off
$(AMCNOTSTUB_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(AMCNOTSTUB_FILES:.o=.d)

$(BUILD_DIR)/src/amcnotstub/amcnotstub.a: $(AMCNOTSTUB_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(AMCNOTSTUB_FILES) > build/AMCNOTSTUB_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/AMCNOTSTUB_ofiles
