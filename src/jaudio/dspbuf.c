#include "jaudio/dspbuf.h"
#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/audiothread.h"
#include "jaudio/dspdriver.h"
#include "jaudio/dspinterface.h"
#include "jaudio/dspproc.h"
#include "jaudio/dummyprobe.h"
#include "jaudio/ipldec.h"
#include "jaudio/playercall.h"
#include "jaudio/rate.h"

static u8 write_buffer      = 0;
static u8 read_buffer       = 0;
static u8 dspstatus         = 0;
static u32 dac_sync_counter = 0;

static s16* dsp_buf[DSPBUF_NUM];

/**
 * @TODO: Documentation
 */
u32 Jac_GetCurrentSCounter()
{
	return dac_sync_counter;
}

/**
 * @TODO: Documentation
 */
s16* DspbufProcess(DSPBUF_EVENTS event)
{
	u32 i;
	u32 j;

	switch (event) {
	case DSPBUF_EVENT_INIT:
		write_buffer = 2;
		read_buffer  = 0;
		for (i = 0; i < DSPBUF_NUM; i++) {
			dsp_buf[i] = (s16*)OSAlloc2(JAC_FRAMESAMPLES << 2);
			for (j = 0; j < (JAC_FRAMESAMPLES << 1); j++) {
				dsp_buf[i][j] = 0;
			}

			DCStoreRange(dsp_buf[i], JAC_FRAMESAMPLES << 2);
		}

		dspstatus = 0;
		break;
	case DSPBUF_EVENT_FRAME_END:
#if defined(VERSION_GPIP01_00)
#else
		DspExtraTaskCheck();
#endif
		u8 write = write_buffer + 1;

		if (write == DSPBUF_NUM) {
			write = 0;
		}

		if (write == read_buffer) {
			dspstatus = 0;
		} else {
			write_buffer = write;
			DspSyncCountClear(JAC_SUBFRAMES);
			Probe_Start(7, "DSP-MAIN");
#if defined(VERSION_GPIP01_00)
			DsyncFrame2(JAC_SUBFRAMES, (u32)dsp_buf[write_buffer], (u32)&dsp_buf[write_buffer][JAC_FRAMESAMPLES]);
#else
			DsyncFrame(JAC_SUBFRAMES, (u32)dsp_buf[write_buffer], (u32)&dsp_buf[write_buffer][JAC_FRAMESAMPLES]);
#endif
			dspstatus = 1;
			UpdateDSP();
		}
		break;
	case DSPBUF_EVENT_MIX:
		u8 read = read_buffer + 1;
		if (read == DSPBUF_NUM) {
			read = 0;
		}

		if (read == write_buffer) {
			s16 left  = dsp_buf[read_buffer][(JAC_FRAMESAMPLES / 2) - 1];
			s16 right = dsp_buf[read_buffer][JAC_FRAMESAMPLES - 1];

			for (i = 0; i < JAC_FRAMESAMPLES; i++) {
				dsp_buf[read_buffer][i] = left;
			}

			for (i = JAC_FRAMESAMPLES; i < (JAC_FRAMESAMPLES << 1); i++) {
				dsp_buf[read_buffer][i] = right;
			}

			if (dspstatus == 0) {
				DspbufProcess(DSPBUF_EVENT_FRAME_END);
			}
		} else {
			read_buffer = read;
			DCInvalidateRange(dsp_buf[read_buffer], JAC_FRAMESAMPLES << 2);
			if (dspstatus == 0) {
				DspbufProcess(DSPBUF_EVENT_FRAME_END);
			}
		}

		return dsp_buf[read_buffer];
	}

	return NULL;
}

/**
 * @TODO: Documentation
 */
void UpdateDSP()
{
	dac_sync_counter++;
	Probe_Start(3, "SFR-UPDATE");
	DSP_InvalChannelAll();
	DspPlayerCallback();
	UpdateDSPchannelAll();
	DSPReleaseHalt();
	PlayerCallback();
	Probe_Finish(3);
}

/**
 * @TODO: Documentation
 */
s16* MixDsp(s32 numSamples)
{
	static s32 cur = 0;
	return DspbufProcess(DSPBUF_EVENT_MIX);
}

/**
 * @TODO: Documentation
 */
void DspFrameEnd()
{
	DspbufProcess(DSPBUF_EVENT_FRAME_END);
}
