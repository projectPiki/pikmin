COLIN_FILES:=\
	$(BUILD_DIR)/asm/plugPikiColin/cardutil.o\
	$(BUILD_DIR)/asm/plugPikiColin/dynsimulator.o\
	$(BUILD_DIR)/asm/plugPikiColin/animMgr.o\
	$(BUILD_DIR)/asm/plugPikiColin/gameflow.o\
	$(BUILD_DIR)/asm/plugPikiColin/game.o\
	$(BUILD_DIR)/asm/plugPikiColin/gamePrefs.o\
	$(BUILD_DIR)/asm/plugPikiColin/gameSetup.o\
	$(BUILD_DIR)/asm/plugPikiColin/cardSelect.o\
	$(BUILD_DIR)/asm/plugPikiColin/mapSelect.o\
	$(BUILD_DIR)/asm/plugPikiColin/newPikiGame.o\
	$(BUILD_DIR)/asm/plugPikiColin/introGame.o\
	$(BUILD_DIR)/src/plugPikiColin/gameExit.o\
	$(BUILD_DIR)/asm/plugPikiColin/gauges.o\
	$(BUILD_DIR)/asm/plugPikiColin/genMapObject.o\
	$(BUILD_DIR)/asm/plugPikiColin/gui.o\
	$(BUILD_DIR)/asm/plugPikiColin/parameters.o\
	$(BUILD_DIR)/asm/plugPikiColin/plugPiki.o\
	$(BUILD_DIR)/asm/plugPikiColin/titles.o\
	$(BUILD_DIR)/asm/plugPikiColin/ninLogo.o\
	$(BUILD_DIR)/asm/plugPikiColin/mapMgr.o\
	$(BUILD_DIR)/asm/plugPikiColin/dayMgr.o\
	$(BUILD_DIR)/asm/plugPikiColin/cinePlayer.o\
	$(BUILD_DIR)/asm/plugPikiColin/lightPool.o\
	$(BUILD_DIR)/asm/plugPikiColin/memoryCard.o\
	$(BUILD_DIR)/asm/plugPikiColin/moviePlayer.o\
	$(BUILD_DIR)/asm/plugPikiColin/movSample.o\

$(COLIN_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(COLIN_FILES:.o=.d)

$(BUILD_DIR)/src/plugPikiColin/plugPikiColin.a: $(COLIN_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(COLIN_FILES) > build/COLIN_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/COLIN_ofiles
