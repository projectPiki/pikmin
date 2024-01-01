OS_FILES:=\
	$(BUILD_DIR)/asm/os/OS.o\
	$(BUILD_DIR)/asm/os/OSAlarm.o\
	$(BUILD_DIR)/src/os/OSAlloc.o\
	$(BUILD_DIR)/src/os/OSArena.o\
	$(BUILD_DIR)/asm/os/OSAudioSystem.o\
	$(BUILD_DIR)/asm/os/OSCache.o\
	$(BUILD_DIR)/asm/os/OSContext.o\
	$(BUILD_DIR)/src/os/OSError.o\
	$(BUILD_DIR)/asm/os/OSExi.o\
	$(BUILD_DIR)/asm/os/OSFont.o\
	$(BUILD_DIR)/asm/os/OSInterrupt.o\
	$(BUILD_DIR)/src/os/OSLink.o\
	$(BUILD_DIR)/asm/os/OSMessage.o\
	$(BUILD_DIR)/asm/os/OSMutex.o\
	$(BUILD_DIR)/asm/os/OSReboot.o\
	$(BUILD_DIR)/asm/os/OSReset.o\
	$(BUILD_DIR)/asm/os/OSResetSW.o\
	$(BUILD_DIR)/asm/os/OSRtc.o\
	$(BUILD_DIR)/asm/os/OSSerial.o\
	$(BUILD_DIR)/asm/os/OSSync.o\
	$(BUILD_DIR)/asm/os/OSThread.o\
	$(BUILD_DIR)/asm/os/OSTime.o\
	$(BUILD_DIR)/asm/os/OSUartExi.o\
	$(BUILD_DIR)/src/os/__start.o\
	$(BUILD_DIR)/asm/os/__ppc_eabi_init.o\

$(OS_FILES): CFLAGS += -common off
$(OS_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(OS_FILES:.o=.d)

$(BUILD_DIR)/src/os/os.a: $(OS_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(OS_FILES) > build/OS_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/OS_ofiles
