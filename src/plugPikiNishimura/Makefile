NISHIMURA_FILES:=\
	$(BUILD_DIR)/asm/plugPikiNishimura/genBoss.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Boss.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/BossAnimMgr.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/BossCnd.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/BossMgr.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/BossShapeObj.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Spider.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SpiderAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SpiderLeg.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Snake.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SnakeAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SnakeBody.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Slime.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SlimeAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SlimeBody.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/SlimeCreature.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/King.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/KingAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/KingBody.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Kogane.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/KoganeAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Pom.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/PomAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/KingBack.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Nucleus.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/NucleusAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/CoreNucleus.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/CoreNucleusAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/Mizu.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/MizuAi.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/nscalculation.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/RumbleData.o\
	$(BUILD_DIR)/asm/plugPikiNishimura/HmRumbleMgr.o\
	$(BUILD_DIR)/src/plugPikiNishimura/HmRumbleSample.o\

$(NISHIMURA_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(NISHIMURA_FILES:.o=.d)

$(BUILD_DIR)/src/plugPikiNishimura/plugPikiNishimura.a: $(NISHIMURA_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(NISHIMURA_FILES) > build/NISHIMURA_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/NISHIMURA_ofiles
