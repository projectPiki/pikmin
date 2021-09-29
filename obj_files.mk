# Linker order for every file, passed to the Metrowerks linker.

INIT_O_FILES :=									\
    $(BUILD_DIR)/asm/init.o						\

EXTAB_O_FILES :=								\
    $(BUILD_DIR)/asm/extab.o					\

EXTABINDEX_O_FILES :=							\
    $(BUILD_DIR)/asm/exidx.o					\

TEXT_O_FILES :=									\
    $(BUILD_DIR)/asm/sysBootup.o				\
    $(BUILD_DIR)/asm/text_0.o					\
    $(BUILD_DIR)/asm/string.o					\
    $(BUILD_DIR)/asm/text_80025914.o			\
    $(BUILD_DIR)/src/sysCommon/shpRoutes.o		\
    $(BUILD_DIR)/asm/text_1.o					\
    $(BUILD_DIR)/src/sysCommon/matMath.o		\
    $(BUILD_DIR)/asm/matMath_Partial.o			\
    $(BUILD_DIR)/asm/stdSystem.o				\
    $(BUILD_DIR)/asm/node.o						\
    $(BUILD_DIR)/src/sysCommon/timers.o	    	\
    $(BUILD_DIR)/asm/controller.o				\
    $(BUILD_DIR)/asm/cmdStream.o				\
    $(BUILD_DIR)/asm/camera.o					\
    $(BUILD_DIR)/asm/atx.o						\
    $(BUILD_DIR)/asm/id32.o						\
    $(BUILD_DIR)/asm/text_80044194.o			\
    $(BUILD_DIR)/asm/genBoss.o					\
    $(BUILD_DIR)/asm/Boss.o						\
    $(BUILD_DIR)/asm/BossAnimMgr.o				\
    $(BUILD_DIR)/asm/BossCnd.o					\
    $(BUILD_DIR)/asm/BossMgr.o					\
    $(BUILD_DIR)/asm/BossShapeObj.o				\
    $(BUILD_DIR)/asm/Spider.o					\
    $(BUILD_DIR)/asm/SpiderAi.o					\
    $(BUILD_DIR)/asm/SpiderLeg.o				\
    $(BUILD_DIR)/asm/text_Nishimura.o			\
    $(BUILD_DIR)/src/gx/GXStubs.o				\
    $(BUILD_DIR)/asm/text_802140E8.o			\
    $(BUILD_DIR)/asm/text_8021C4CC.o			\
    $(BUILD_DIR)/src/amcnotstub/amcnotstub.o	\
    $(BUILD_DIR)/asm/DebuggerDriver.o			\
    $(BUILD_DIR)/src/odenotstub/odenotstub.o	\

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
	
