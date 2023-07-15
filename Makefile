ifneq ($(findstring MINGW,$(shell uname)),)
  WINDOWS := 1
endif
ifneq ($(findstring MSYS,$(shell uname)),)
  WINDOWS := 1
endif

VERBOSE ?= 0

ifeq ($(VERBOSE),0)
  QUIET := @
endif

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

NAME := pikmin
VERSION := usa.1
#VERSION := usa.0

BUILD_DIR := build/$(NAME).$(VERSION)

# Inputs
S_FILES := $(wildcard asm/*.s)
C_FILES := $(wildcard src/*.c)
CPP_FILES := $(wildcard src/*.cpp)
CPP_FILES += $(wildcard src/*.cp)
LDSCRIPT := ldscript.lcf

# Outputs
DOL     := $(BUILD_DIR)/main.dol
ELF     := $(DOL:.dol=.elf)
MAP     := $(BUILD_DIR)/build.map

include obj_files.mk

O_FILES :=	$(GROUP_0_FILES) $(SYSBOOTUP) $(JAUDIO) $(HVQM4DEC) $(SYSCOMMON) $(SYSDOLPHIN)\
			$(COLIN) $(KANDO) $(NAKATA) $(NISHIMURA) $(OGAWA) $(YAMASHITA)\
			$(BASE) $(OS) $(DB) $(MTX) $(DVD) $(VI) $(PAD) $(AI) $(AR) $(DSP)\
			$(CARD) $(HIO) $(GX) $(RUNTIME) $(MSL_C) $(TRK_MINNOW_DOLPHIN)\
			$(AMCEXI2) $(AMCNOTSTUB) $(ODEMUEXI2) $(ODENOTSTUB)
#-------------------------------------------------------------------------------
# Tools
#-------------------------------------------------------------------------------

MWCC_VERSION := 1.2.5
MWLD_VERSION := 1.1

# Compiler versions and flags
$(COLIN): MWCC_VERSION := 1.2.5n
$(KANDO): MWCC_VERSION := 1.2.5n
$(NAKATA): MWCC_VERSION := 1.2.5n
$(NISHIMURA): MWCC_VERSION := 1.2.5n
$(OGAWA): MWCC_VERSION := 1.2.5n
$(YAMASHITA): MWCC_VERSION := 1.2.5n

# Programs
ifeq ($(WINDOWS),1)
  WINE :=
  AS      := $(DEVKITPPC)/bin/powerpc-eabi-as.exe
  PYTHON  := python
else
  WIBO   := $(shell command -v wibo 2> /dev/null)
  ifdef WIBO
    WINE ?= wibo
  else
    WINE ?= wine
  endif
  AS      := $(DEVKITPPC)/bin/powerpc-eabi-as
  PYTHON  := python3
endif
COMPILERS ?= tools/mwcc_compiler
CC      = $(WINE) $(COMPILERS)/$(MWCC_VERSION)/mwcceppc.exe
LD      := $(WINE) $(COMPILERS)/$(MWLD_VERSION)/mwldeppc.exe
DTK     := tools/dtk
ELF2DOL := $(DTK) elf2dol
SHASUM  := $(DTK) shasum

# Options
INCLUDES := -i include/
ASM_INCLUDES := -I include/

ASFLAGS := -mgekko $(ASM_INCLUDES)
LDFLAGS := -map $(MAP) -fp hard -nodefaults
CFLAGS   = -Cpp_exceptions off -O4,p -fp hard -proc gekko -nodefaults -RTTI on $(INCLUDES)

$(JAUDIO): CFLAGS += -func_align 32
$(MSL_C): CFLAGS += -fp_contract on

#-------------------------------------------------------------------------------
# Recipes
#-------------------------------------------------------------------------------

### Default target ###

default: all

all: $(DOL)

ALL_DIRS := $(sort $(dir $(O_FILES)))

# Make sure build directory exists before compiling anything
DUMMY != mkdir -p $(ALL_DIRS)

.PHONY: tools

# DOL creation makefile instructions
$(DOL): $(ELF) | $(DTK)
	@echo Converting $< to $@
	$(QUIET) $(ELF2DOL) $< $@
	$(QUIET) $(SHASUM) -c sha1/$(NAME).$(VERSION).sha1
	$(QUIET) $(PYTHON) tools/calcprogress.py $(DOL) $(MAP)

clean:
	rm -f -d -r build

$(DTK): tools/dtk_version
	@echo "Downloading $@"
	$(QUIET) $(PYTHON) tools/download_dtk.py $< $@

# ELF creation makefile instructions
$(ELF): $(O_FILES) $(LDSCRIPT)
	@echo Linking ELF $@
	$(QUIET) @echo $(O_FILES) > build/o_files
	$(QUIET) $(LD) $(LDFLAGS) -o $@ -lcf $(LDSCRIPT) @build/o_files

$(BUILD_DIR)/%.o: %.s
	@echo Assembling $<
	$(QUIET) $(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c
	@echo "Compiling " $<
	$(QUIET) $(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.cp
	@echo "Compiling " $<
	$(QUIET) $(CC) $(CFLAGS) -c -o $@ $<
	
$(BUILD_DIR)/%.o: %.cpp
	@echo "Compiling " $<
	$(QUIET) $(CC) $(CFLAGS) -c -o $@ $<

### Debug Print ###

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
