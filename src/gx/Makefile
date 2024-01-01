GX_FILES:=\
	$(BUILD_DIR)/asm/gx/GXInit.o\
	$(BUILD_DIR)/asm/gx/GXFifo.o\
	$(BUILD_DIR)/asm/gx/GXAttr.o\
	$(BUILD_DIR)/asm/gx/GXMisc.o\
	$(BUILD_DIR)/asm/gx/GXGeometry.o\
	$(BUILD_DIR)/asm/gx/GXFrameBuf.o\
	$(BUILD_DIR)/asm/gx/GXLight.o\
	$(BUILD_DIR)/asm/gx/GXTexture.o\
	$(BUILD_DIR)/asm/gx/GXBump.o\
	$(BUILD_DIR)/asm/gx/GXTev.o\
	$(BUILD_DIR)/asm/gx/GXPixel.o\
	$(BUILD_DIR)/src/gx/GXStubs.o\
	$(BUILD_DIR)/asm/gx/GXDisplayList.o\
	$(BUILD_DIR)/asm/gx/GXTransform.o\

$(GX_FILES): CFLAGS += -common off
$(GX_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(GX_FILES:.o=.d)

$(BUILD_DIR)/src/gx/gx.a: $(GX_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(GX_FILES) > build/GX_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/GX_ofiles
