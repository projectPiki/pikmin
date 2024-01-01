CARD_FILES:=\
	$(BUILD_DIR)/asm/card/CARDBios.o\
	$(BUILD_DIR)/asm/card/CARDRdwr.o\
	$(BUILD_DIR)/asm/card/CARDBlock.o\
	$(BUILD_DIR)/asm/card/CARDDir.o\
	$(BUILD_DIR)/asm/card/CARDCheck.o\
	$(BUILD_DIR)/asm/card/CARDMount.o\
	$(BUILD_DIR)/asm/card/CARDFormat.o\
	$(BUILD_DIR)/asm/card/CARDOpen.o\
	$(BUILD_DIR)/asm/card/CARDCreate.o\
	$(BUILD_DIR)/asm/card/CARDRead.o\
	$(BUILD_DIR)/asm/card/CARDWrite.o\
	$(BUILD_DIR)/asm/card/CARDDelete.o\
	$(BUILD_DIR)/asm/card/CARDStat.o\
	$(BUILD_DIR)/asm/card/CARDRename.o\

$(CARD_FILES): CFLAGS += -common off
$(CARD_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(CARD_FILES:.o=.d)

$(BUILD_DIR)/src/card/card.a: $(CARD_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(CARD_FILES) > build/CARD_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/CARD_ofiles
