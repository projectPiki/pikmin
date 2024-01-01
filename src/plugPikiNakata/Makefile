NAKATA_FILES:=\
	$(BUILD_DIR)/asm/plugPikiNakata/genteki.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nakatacode.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibfunction.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibgeometry.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibgeometry3d.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibgraphics.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibmath.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibspline.o\
	$(BUILD_DIR)/asm/plugPikiNakata/nlibsystem.o\
	$(BUILD_DIR)/asm/plugPikiNakata/panianimator.o\
	$(BUILD_DIR)/asm/plugPikiNakata/panipikianimmgr.o\
	$(BUILD_DIR)/asm/plugPikiNakata/panitekianimator.o\
	$(BUILD_DIR)/asm/plugPikiNakata/panitestsection.o\
	$(BUILD_DIR)/asm/plugPikiNakata/paraparameters.o\
	$(BUILD_DIR)/asm/plugPikiNakata/pcamcamera.o\
	$(BUILD_DIR)/asm/plugPikiNakata/pcamcameramanager.o\
	$(BUILD_DIR)/asm/plugPikiNakata/pcammotionevents.o\
	$(BUILD_DIR)/asm/plugPikiNakata/pcamcameraparameters.o\
	$(BUILD_DIR)/asm/plugPikiNakata/peve.o\
	$(BUILD_DIR)/asm/plugPikiNakata/peveconditions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/pevemotionevents.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tai.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taiattackactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taibasicactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taichappy.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taicollec.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taicollisionactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taieffectactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taiiwagen.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taijudgementactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taikinoko.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taimessageactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taimizinko.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taimotionactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taimoveactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tainapkid.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taiotimoti.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taipalm.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taireactionactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taiswallow.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taishell.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taitimeractions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/taiwaitactions.o\
	$(BUILD_DIR)/asm/plugPikiNakata/teki.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekianimationmanager.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekibteki.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekiconditions.o\
	$(BUILD_DIR)/src/plugPikiNakata/tekievent.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekiinteraction.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekimgr.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekinakata.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekinteki.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekiparameters.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekipersonality.o\
	$(BUILD_DIR)/asm/plugPikiNakata/tekistrategy.o\

$(NAKATA_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(NAKATA_FILES:.o=.d)

$(BUILD_DIR)/src/plugPikiNakata/plugPikiNakata.a: $(NAKATA_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(NAKATA_FILES) > build/NAKATA_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/NAKATA_ofiles
