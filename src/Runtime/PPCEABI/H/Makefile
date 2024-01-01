RUNTIME_FILES:=\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/__mem.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/__va_arg.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/global_destructor_chain.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/CPlusLibPPC.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/NMWException.o\
	$(BUILD_DIR)/src/Runtime/PPCEABI/H/ptmf.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/ExceptionPPC.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/runtime.o\
	$(BUILD_DIR)/asm/Runtime/PPCEABI/H/__init_cpp_exceptions.o\

$(RUNTIME_FILES): CFLAGS += -common off
$(RUNTIME_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(RUNTIME_FILES:.o=.d)

$(BUILD_DIR)/src/Runtime/PPCEABI/H/Runtime.PPCEABI.H.a: $(RUNTIME_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(RUNTIME_FILES) > build/RUNTIME_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/RUNTIME_ofiles
