# Linker order for every file, passed to the Metrowerks linker.

SYSBOOTUP :=\
	$(BUILD_DIR)/src/sysBootup.o\

JAUDIO :=\
	$(BUILD_DIR)/src/jaudio/jaudio.o\

HVQM4DEC :=\
	$(BUILD_DIR)/src/hvqm4dec/hvqm4dec.a\

SYS :=\
	$(BUILD_DIR)/src/sysCommon/sysCommon.a\
	$(BUILD_DIR)/src/sysDolphin/sysDolphin.a\

PLUGPIKI :=\
	$(BUILD_DIR)/src/plugPikiColin/plugPikiColin.a\
	$(BUILD_DIR)/src/plugPikiKando/plugPikiKando.a\
	$(BUILD_DIR)/src/plugPikiNakata/plugPikiNakata.a\
	$(BUILD_DIR)/src/plugPikiNishimura/plugPikiNishimura.a\
	$(BUILD_DIR)/src/plugPikiOgawa/plugPikiOgawa.a\
	$(BUILD_DIR)/src/plugPikiYamashita/plugPikiYamashita.a\

DOLPHIN :=\
	$(BUILD_DIR)/src/base/base.a\
	$(BUILD_DIR)/src/os/os.a\
	$(BUILD_DIR)/src/db/db.a\
	$(BUILD_DIR)/src/mtx/mtx.a\
	$(BUILD_DIR)/src/dvd/dvd.a\
	$(BUILD_DIR)/src/vi/vi.a\
	$(BUILD_DIR)/src/pad/pad.a\
	$(BUILD_DIR)/src/ai/ai.a\
	$(BUILD_DIR)/src/ar/ar.a\
	$(BUILD_DIR)/src/dsp/dsp.a\
	$(BUILD_DIR)/src/card/card.a\
	$(BUILD_DIR)/src/hio/hio.a\
	$(BUILD_DIR)/src/gx/gx.a\
	$(BUILD_DIR)/src/Runtime/PPCEABI/H/Runtime.PPCEABI.H.a\
	$(BUILD_DIR)/src/MSL_C/PPCEABI/bare/H/MSL_C.PPCEABI.bare.H.a\
	$(BUILD_DIR)/src/TRK_MINNOW_DOLPHIN/TRK_MINNOW_DOLPHIN.a\
	$(BUILD_DIR)/src/amcExi2/amcExi2.a\
	$(BUILD_DIR)/src/amcnotstub/amcnotstub.a\
	$(BUILD_DIR)/src/OdemuExi2/OdemuExi2.a\
	$(BUILD_DIR)/src/odenotstub/odenotstub.a\
