# Linker order for every file, passed to the Metrowerks linker.

<<<<<<< HEAD
INIT_O_FILES :=								\
	$(BUILD_DIR)/asm/init.o						\

EXTAB_O_FILES :=							\
=======
INIT_O_FILES :=									\
	$(BUILD_DIR)/asm/init.o						\

EXTAB_O_FILES :=								\
>>>>>>> 115bf2a66f4e0062c62b736007922190a62b9bf7
	$(BUILD_DIR)/asm/extab.o					\

EXTABINDEX_O_FILES :=							\
	$(BUILD_DIR)/asm/exidx.o					\

<<<<<<< HEAD
TEXT_O_FILES :=								\
	$(BUILD_DIR)/asm/text.o						\

CTORS_O_FILES :=							\
	$(BUILD_DIR)/asm/ctors.o					\

DTORS_O_FILES :=							\
	$(BUILD_DIR)/asm/dtors.o					\

RODATA_O_FILES :=							\
	$(BUILD_DIR)/asm/rodata.o					\

DATA_O_FILES :=								\
	$(BUILD_DIR)/asm/data.o						\

BSS_O_FILES :=								\
	$(BUILD_DIR)/asm/bss.o						\

SDATA_O_FILES :=							\
	$(BUILD_DIR)/asm/sdata.o					\

SBSS_O_FILES :=								\
	$(BUILD_DIR)/asm/sbss.o						\

SDATA2_O_FILES :=							\
	$(BUILD_DIR)/asm/sdata2.o					\
	
SBSS2_O_FILES :=							\
=======
TEXT_O_FILES :=									\
	$(BUILD_DIR)/asm/text.o						\

CTORS_O_FILES :=								\
	$(BUILD_DIR)/asm/ctors.o					\

DTORS_O_FILES :=								\
	$(BUILD_DIR)/asm/dtors.o					\

RODATA_O_FILES :=								\
	$(BUILD_DIR)/asm/rodata.o					\

DATA_O_FILES :=									\
	$(BUILD_DIR)/asm/data.o						\

BSS_O_FILES :=									\
	$(BUILD_DIR)/asm/bss.o						\

SDATA_O_FILES :=								\
	$(BUILD_DIR)/asm/sdata.o					\

SBSS_O_FILES :=									\
	$(BUILD_DIR)/asm/sbss.o						\

SDATA2_O_FILES :=								\
	$(BUILD_DIR)/asm/sdata2.o					\
	
SBSS2_O_FILES :=								\
>>>>>>> 115bf2a66f4e0062c62b736007922190a62b9bf7
#	$(BUILD_DIR)/asm/sbss2.o					\
