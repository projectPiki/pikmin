SYSDOLPHIN_FILES:=\
	$(BUILD_DIR)/asm/sysDolphin/texture.o\
	$(BUILD_DIR)/asm/sysDolphin/system.o\
	$(BUILD_DIR)/asm/sysDolphin/sysNew.o\
	$(BUILD_DIR)/asm/sysDolphin/controllerMgr.o\
	$(BUILD_DIR)/asm/sysDolphin/dgxGraphics.o\
	$(BUILD_DIR)/src/sysDolphin/gameApp.o\

$(SYSDOLPHIN_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(SYSDOLPHIN_FILES:.o=.d)

$(BUILD_DIR)/src/sysDolphin/sysDolphin.a: $(SYSDOLPHIN_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(SYSDOLPHIN_FILES) > build/SYSDOLPHIN_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/SYSDOLPHIN_ofiles
