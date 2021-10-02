# Linker order for every file, passed to the Metrowerks linker.

INIT_O_FILES :=											\
    $(BUILD_DIR)/asm/init.o								\

EXTAB_O_FILES :=										\
    $(BUILD_DIR)/asm/extab.o							\

EXTABINDEX_O_FILES :=									\
    $(BUILD_DIR)/asm/exidx.o							\

TEXT_O_FILES :=											\
    $(BUILD_DIR)/asm/sysBootup.o						\
    $(BUILD_DIR)/asm/text_0.o							\
    $(BUILD_DIR)/asm/sysCommon/string.o					\
    $(BUILD_DIR)/asm/text_80025914.o					\
    $(BUILD_DIR)/src/sysCommon/shpRoutes.o				\
    $(BUILD_DIR)/asm/text_1.o							\
    $(BUILD_DIR)/src/sysCommon/matMath.o				\
    $(BUILD_DIR)/asm/sysCommon/matMath.o				\
    $(BUILD_DIR)/asm/sysCommon/stdSystem.o				\
    $(BUILD_DIR)/asm/sysCommon/node.o					\
    $(BUILD_DIR)/src/sysCommon/timers.o	    			\
    $(BUILD_DIR)/asm/sysCommon/controller.o				\
    $(BUILD_DIR)/asm/sysCommon/cmdStream.o				\
    $(BUILD_DIR)/asm/sysCommon/camera.o					\
    $(BUILD_DIR)/asm/sysCommon/atx.o					\
    $(BUILD_DIR)/asm/sysCommon/id32.o					\
    $(BUILD_DIR)/asm/text_80044194.o					\
    $(BUILD_DIR)/asm/plugPikiNishimura/genBoss.o		\
    $(BUILD_DIR)/asm/plugPikiNishimura/Boss.o			\
    $(BUILD_DIR)/asm/plugPikiNishimura/BossAnimMgr.o	\
    $(BUILD_DIR)/asm/plugPikiNishimura/BossCnd.o		\
    $(BUILD_DIR)/asm/plugPikiNishimura/BossMgr.o		\
    $(BUILD_DIR)/asm/plugPikiNishimura/BossShapeObj.o	\
    $(BUILD_DIR)/asm/plugPikiNishimura/Spider.o			\
    $(BUILD_DIR)/asm/plugPikiNishimura/SpiderAi.o		\
    $(BUILD_DIR)/asm/plugPikiNishimura/SpiderLeg.o		\
    $(BUILD_DIR)/asm/text_Nishimura.o					\
    $(BUILD_DIR)/asm/mtx/mtx.o							\
    $(BUILD_DIR)/asm/mtx/mtx44.o						\
    $(BUILD_DIR)/asm/mtx/vec.o							\
    $(BUILD_DIR)/asm/dvd/dvdlow.o						\
    $(BUILD_DIR)/asm/dvd/dvdfs.o						\
    $(BUILD_DIR)/asm/dvd/dvd.o							\
    $(BUILD_DIR)/asm/dvd/dvdqueue.o						\
    $(BUILD_DIR)/asm/dvd/dvderror.o						\
    $(BUILD_DIR)/asm/dvd/fstload.o						\
    $(BUILD_DIR)/asm/vi/vi.o							\
    $(BUILD_DIR)/asm/pad/Padclamp.o						\
    $(BUILD_DIR)/asm/pad/Pad.o							\
    $(BUILD_DIR)/asm/ai/ai.o							\
    $(BUILD_DIR)/asm/ar/ar.o							\
    $(BUILD_DIR)/asm/ar/arq.o							\
    $(BUILD_DIR)/asm/dsp/dsp.o							\
    $(BUILD_DIR)/asm/text_CardGX.o						\
    $(BUILD_DIR)/src/gx/GXStubs.o						\
    $(BUILD_DIR)/asm/text_802140E8.o					\
    $(BUILD_DIR)/asm/text_8021C4CC.o					\
    $(BUILD_DIR)/src/amcnotstub/amcnotstub.o			\
    $(BUILD_DIR)/asm/OdemuExi2/DebuggerDriver.o			\
    $(BUILD_DIR)/src/odenotstub/odenotstub.o			\

CTORS_O_FILES :=										\
    $(BUILD_DIR)/asm/ctors.o							\

DTORS_O_FILES :=										\
    $(BUILD_DIR)/asm/dtors.o							\

RODATA_O_FILES :=										\
    $(BUILD_DIR)/asm/rodata.o							\

DATA_O_FILES :=											\
    $(BUILD_DIR)/asm/data.o								\

BSS_O_FILES :=											\
    $(BUILD_DIR)/asm/bss.o								\

SDATA_O_FILES :=										\
    $(BUILD_DIR)/asm/sdata.o							\

SBSS_O_FILES :=											\
    $(BUILD_DIR)/asm/sbss.o								\

SDATA2_O_FILES :=										\
    $(BUILD_DIR)/asm/sdata2.o							\
    $(BUILD_DIR)/asm/sdata2_1.o							\
    $(BUILD_DIR)/asm/sdata2_1a.o						\
    $(BUILD_DIR)/asm/sdata2_2.o							\
