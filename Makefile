ifneq ($(findstring MINGW,$(shell uname)),)
  WINDOWS := 1
endif
ifneq ($(findstring MSYS,$(shell uname)),)
  WINDOWS := 1
endif

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

NAME := pikmin
VERSION := usa.1
#VERSION := usa.0

BUILD_DIR := build/$(NAME).$(VERSION)

SRC_DIRS := src src/sysCommon src/amcnotstub src/gx src/odenotstub \
			src/TRK_MINNOW_DOLPHIN src/plugPikiNishimura src/plugPikiColin \
			src/amcExi2 src/jaudio src/mtx src/os src/plugPikiKando \
			src/plugPikiNakata src/plugPikiOgawa src/plugPikiYamashita \
			src/dvd src/vi src/pad src/ai src/ar src/dsp src/OdemuExi2 \
			src/MSL_C/PPCEABI/bare/H src/Runtime/PPCEABI/H src/hio src/card \
			src/db src/base
ASM_DIRS := asm asm/sysCommon asm/amcnotstub asm/gx asm/odenotstub \
            asm/TRK_MINNOW_DOLPHIN asm/plugPikiNishimura asm/plugPikiColin \
            asm/amcExi2 asm/jaudio asm/mtx asm/os asm/plugPikiKando \
            asm/plugPikiNakata asm/plugPikiOgawa asm/plugPikiYamashita \
            asm/dvd asm/vi asm/pad asm/ai asm/ar asm/dsp asm/OdemuExi2 \
			asm/MSL_C/PPCEABI/bare/H asm/Runtime/PPCEABI/H asm/hio asm/card \
			asm/db asm/base
# Inputs
S_FILES := $(wildcard asm/*.s)
C_FILES := $(wildcard src/*.c)
CPP_FILES := $(wildcard src/*.cpp)
LDSCRIPT := $(BUILD_DIR)/ldscript.lcf

# Outputs
DOL     := $(BUILD_DIR)/main.dol
ELF     := $(DOL:.dol=.elf)
MAP     := $(BUILD_DIR)/pikmin1.map

include obj_files.mk

O_FILES := $(GROUP_0_FILES) $(TEXT_O_FILES)\

#-------------------------------------------------------------------------------
# Tools
#-------------------------------------------------------------------------------

MWCC_VERSION := 1.0
MWLD_VERSION := 1.1

# Programs
ifeq ($(WINDOWS),1)
  WINE :=
  AS      := $(DEVKITPPC)/bin/powerpc-eabi-as.exe
  CPP     := $(DEVKITPPC)/bin/powerpc-eabi-cpp.exe -P
else
  WINE := wine
  AS      := $(DEVKITPPC)/bin/powerpc-eabi-as
  CPP     := $(DEVKITPPC)/bin/powerpc-eabi-cpp -P
endif
CC      = $(WINE) tools/mwcc_compiler/$(MWCC_VERSION)/mwcceppc.exe
LD      := $(WINE) tools/mwcc_compiler/$(MWLD_VERSION)/mwldeppc.exe
ELF2DOL := tools/elf2dol
SHA1SUM := sha1sum
PYTHON  := python3

POSTPROC := tools/postprocess.py

# Options
INCLUDES := -i include/

ASFLAGS := -mgekko -I include/ 
LDFLAGS := -map $(MAP) -fp hard -nodefaults
CFLAGS  := -Cpp_exceptions off -O4,p -fp hard -proc gekko -nodefaults -RTTI on -msgstyle gcc $(INCLUDES)

# for postprocess.py
PROCFLAGS := -fprologue-fixup=old_stack

#-------------------------------------------------------------------------------
# Recipes
#-------------------------------------------------------------------------------

### Default target ###

default: all

all: $(DOL)

ALL_DIRS := build $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(SRC_DIRS) $(ASM_DIRS))

# Make sure build directory exists before compiling anything
DUMMY != mkdir -p $(ALL_DIRS)

.PHONY: tools

$(LDSCRIPT): ldscript.lcf
	$(CPP) -MMD -MP -MT $@ -MF $@.d -I include/ -I . -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(DOL): $(ELF) | tools
	$(ELF2DOL) $< $@
	$(SHA1SUM) -c sha1/$(NAME).$(VERSION).sha1
	$(PYTHON) calcprogress.py $@

clean:
	rm -f -d -r build
	$(MAKE) -C tools clean
tools:
	$(MAKE) -C tools

$(ELF): $(O_FILES) $(LDSCRIPT)
	@echo $(O_FILES) > build/o_files
	$(LD) $(LDFLAGS) -o $@ -lcf $(LDSCRIPT) @build/o_files

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	#$(PYTHON) $(POSTPROC) $(PROCFLAGS) $@

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	#$(PYTHON) $(POSTPROC) $(PROCFLAGS) $@

### Debug Print ###

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
