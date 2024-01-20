SYSCOMMON_FILES:=\
	$(BUILD_DIR)/asm/sysCommon/ayuStack.o\
	$(BUILD_DIR)/asm/sysCommon/baseApp.o\
	$(BUILD_DIR)/src/sysCommon/stream.o\
	$(BUILD_DIR)/asm/sysCommon/streamBufferedInput.o\
	$(BUILD_DIR)/src/sysCommon/string.o\
	$(BUILD_DIR)/asm/sysCommon/graphics.o\
	$(BUILD_DIR)/asm/sysCommon/grLight.o\
	$(BUILD_DIR)/asm/sysCommon/shapeBase.o\
	$(BUILD_DIR)/asm/sysCommon/shpLightFlares.o\
	$(BUILD_DIR)/asm/sysCommon/shpObjColl.o\
	$(BUILD_DIR)/asm/sysCommon/shpRoutes.o\
	$(BUILD_DIR)/asm/sysCommon/sysMath.o\
	$(BUILD_DIR)/asm/sysCommon/matMath.o\
	$(BUILD_DIR)/asm/sysCommon/stdSystem.o\
	$(BUILD_DIR)/asm/sysCommon/node.o\
	$(BUILD_DIR)/src/sysCommon/timers.o\
	$(BUILD_DIR)/src/sysCommon/controller.o\
	$(BUILD_DIR)/src/sysCommon/cmdStream.o\
	$(BUILD_DIR)/asm/sysCommon/camera.o\
	$(BUILD_DIR)/src/sysCommon/atx.o\
	$(BUILD_DIR)/asm/sysCommon/id32.o\

$(SYSCOMMON_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(SYSCOMMON_FILES:.o=.d)

$(BUILD_DIR)/src/sysCommon/sysCommon.a: $(SYSCOMMON_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(SYSCOMMON_FILES) > build/SYSCOMMON_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/SYSCOMMON_ofiles
