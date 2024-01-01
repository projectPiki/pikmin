OGAWA_FILES:=\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogTest.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogSub.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogTitle.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogPause.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogTutorial.o\
	$(BUILD_DIR)/src/plugPikiOgawa/ogTutorialData.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogMap.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogResult.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogRader.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogFileSelect.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogMessage.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogMemChk.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogDiary.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogMenu.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogFileChkSel.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogMakeDefault.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogTotalScore.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogSave.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogNitaku.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogFileCopy.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogFileDelete.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogGraph.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogStart.o\
	$(BUILD_DIR)/asm/plugPikiOgawa/ogCallBack.o\

$(OGAWA_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(OGAWA_FILES:.o=.d)

$(BUILD_DIR)/src/plugPikiOgawa/plugPikiOgawa.a: $(OGAWA_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(OGAWA_FILES) > build/OGAWA_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/OGAWA_ofiles
