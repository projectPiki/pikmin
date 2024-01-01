JAUDIO_FILES:=\
	$(BUILD_DIR)/src/jaudio/dummyprobe.o\
	$(BUILD_DIR)/asm/jaudio/memory.o\
	$(BUILD_DIR)/asm/jaudio/aictrl.o\
	$(BUILD_DIR)/asm/jaudio/sample.o\
	$(BUILD_DIR)/asm/jaudio/dummyrom.o\
	$(BUILD_DIR)/asm/jaudio/audiothread.o\
	$(BUILD_DIR)/asm/jaudio/audiothread_fakebss.o\
	$(BUILD_DIR)/asm/jaudio/streamctrl.o\
	$(BUILD_DIR)/asm/jaudio/dspbuf.o\
	$(BUILD_DIR)/asm/jaudio/cpubuf.o\
	$(BUILD_DIR)/asm/jaudio/playercall.o\
	$(BUILD_DIR)/asm/jaudio/dvdthread.o\
	$(BUILD_DIR)/asm/jaudio/audiomesg.o\
	$(BUILD_DIR)/asm/jaudio/rate.o\
	$(BUILD_DIR)/asm/jaudio/stackchecker.o\
	$(BUILD_DIR)/asm/jaudio/dspboot.o\
	$(BUILD_DIR)/asm/jaudio/dspproc.o\
	$(BUILD_DIR)/asm/jaudio/ipldec.o\
	$(BUILD_DIR)/asm/jaudio/dsp_cardunlock.o\
	$(BUILD_DIR)/asm/jaudio/driverinterface.o\
	$(BUILD_DIR)/asm/jaudio/dspdriver.o\
	$(BUILD_DIR)/asm/jaudio/dspinterface.o\
	$(BUILD_DIR)/asm/jaudio/fxinterface.o\
	$(BUILD_DIR)/asm/jaudio/bankread.o\
	$(BUILD_DIR)/asm/jaudio/waveread.o\
	$(BUILD_DIR)/asm/jaudio/connect.o\
	$(BUILD_DIR)/asm/jaudio/tables.o\
	$(BUILD_DIR)/asm/jaudio/bankdrv.o\
	$(BUILD_DIR)/asm/jaudio/random.o\
	$(BUILD_DIR)/asm/jaudio/aramcall.o\
	$(BUILD_DIR)/asm/jaudio/ja_calc.o\
	$(BUILD_DIR)/asm/jaudio/fat.o\
	$(BUILD_DIR)/asm/jaudio/cmdstack.o\
	$(BUILD_DIR)/asm/jaudio/virload.o\
	$(BUILD_DIR)/asm/jaudio/heapctrl.o\
	$(BUILD_DIR)/asm/jaudio/jammain_2.o\
	$(BUILD_DIR)/asm/jaudio/midplay.o\
	$(BUILD_DIR)/asm/jaudio/noteon.o\
	$(BUILD_DIR)/asm/jaudio/seqsetup.o\
	$(BUILD_DIR)/asm/jaudio/centcalc.o\
	$(BUILD_DIR)/asm/jaudio/jamosc.o\
	$(BUILD_DIR)/asm/jaudio/oneshot.o\
	$(BUILD_DIR)/asm/jaudio/interface.o\
	$(BUILD_DIR)/asm/jaudio/verysimple.o\
	$(BUILD_DIR)/asm/jaudio/app_inter.o\
	$(BUILD_DIR)/asm/jaudio/pikiinter.o\
	$(BUILD_DIR)/asm/jaudio/piki_player.o\
	$(BUILD_DIR)/asm/jaudio/piki_bgm.o\
	$(BUILD_DIR)/asm/jaudio/piki_scene.o\
	$(BUILD_DIR)/asm/jaudio/pikidemo.o\
	$(BUILD_DIR)/asm/jaudio/file_seq.o\
	$(BUILD_DIR)/asm/jaudio/cmdqueue.o\
	$(BUILD_DIR)/src/jaudio/filter3d.o\
	$(BUILD_DIR)/asm/jaudio/syncstream.o\
	$(BUILD_DIR)/asm/jaudio/bankloader.o\
	$(BUILD_DIR)/asm/jaudio/interleave.o\
	$(BUILD_DIR)/asm/jaudio/pikiseq.o\
	$(BUILD_DIR)/asm/jaudio/hplaybss.o\
	$(BUILD_DIR)/asm/jaudio/hplaybss2.o\
	$(BUILD_DIR)/asm/jaudio/hvqm_play.o\

$(JAUDIO_FILES): CFLAGS += -common off -func_align 32 -lang c++
$(JAUDIO_FILES): MWCC_VERSION := 1.2.5n

DEPENDS += $(JAUDIO_FILES:.o=.d)

$(BUILD_DIR)/src/jaudio/jaudio.o: $(JAUDIO_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(JAUDIO_FILES) > build/JAUDIO_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/JAUDIO_ofiles
