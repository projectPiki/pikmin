MSL_C_FILES:=\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/abort_exit.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/errno.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/ansi_fp.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/arith.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/buffer_io.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/critical_regions.ppc_eabi.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/ctype.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/ansi_files.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/locale.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/direct_io.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/mbstring.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/mem.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/mem_funcs.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/misc_io.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/printf.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/rand.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/scanf.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/string.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/strtold.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/strtoul.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/uart_console_io.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/wchar_io.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/float.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/e_asin.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/e_atan2.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/e_pow.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/fminmaxdim.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/s_atan.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/s_copysign.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/s_frexp.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/s_ldexp.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/w_atan2.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/w_pow.o\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/hyperbolicsf.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/inverse_trig.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/trigf.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/math_inlines.o\
	$(BUILD_DIR)/asm/MSL_C/PPCEABI/bare/H/common_float_tables.o\

$(MSL_C_FILES): CFLAGS += -common off -fp_contract on
$(MSL_C_FILES): MWCC_VERSION := 1.2.5

DEPENDS += $(MSL_C_FILES:.o=.d)

$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/MSL_C.PPCEABI.bare.H.a: $(MSL_C_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(MSL_C_FILES) > build/MSL_C_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/MSL_C_ofiles
