#include "jaudio/aictrl.h"
#include "jaudio/audiostruct.h"
#include "jaudio/memory.h"
#include "jaudio/rate.h"
#include "jaudio/sample.h"
#include "jaudio/dummyprobe.h"
#include "jaudio/dspbuf.h"
#include "jaudio/audiocommon.h"
#include "jaudio/streamctrl.h"
#include "jaudio/dspproc.h"
#include "jaudio/driverinterface.h"
#include "Dolphin/os.h"
#include "Dolphin/ai.h"

u32 UNIVERSAL_DACCOUNTER = 0;

static s16* dac[3];
static ALHeap audio_hp;

static BOOL audio_hp_exist           = FALSE;
static s16* last_rsp_madep           = nullptr;
static s16* use_rsp_madep            = nullptr;
static BOOL vframe_work_running      = FALSE;
static DACCallback DAC_CALLBACK_FUNC = nullptr;
u32 JAC_VFRAME_COUNTER               = 0;
static MixCallback ext_mixcallback   = nullptr;
static u8 ext_mixmode                = MixMode_Mono;

/*
 * --INFO--
 * Address:	80005720
 * Size:	00004C
 */
void Jac_HeapSetup(void* heap, s32 size)
{
	if (heap) {
		Nas_HeapInit(&audio_hp, (u8*)heap, size);
		audio_hp_exist = TRUE;
	} else {
		audio_hp_exist = FALSE;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GetAudioHeapRemain(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005780
 * Size:	000080
 */
void* OSAlloc2(u32 size)
{
	u32* REF_size;

	void* alloc;
	BOOL level;

	level    = OSDisableInterrupts();
	REF_size = &size;
	switch (audio_hp_exist) {
	case FALSE:
		alloc = OSAllocFromHeap(__OSCurrHeap, size);
		break;
	case TRUE:
		alloc = Nas_HeapAlloc(&audio_hp, size);
		break;
	}

	OSRestoreInterrupts(level);
	return alloc;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void OSFree2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005800
 * Size:	0000AC
 */
void Jac_Init()
{
	volatile int i;
	for (i = 0; i < 3; i++) {
		void* alloc   = OSAlloc2(DAC_SIZE * 2);
		s16** thisDac = &dac[i];
		*thisDac      = (s16*)alloc;
		Jac_bzero(*thisDac, DAC_SIZE * 2);
		DCStoreRange(*thisDac, DAC_SIZE * 2);
	}

	AIInit(nullptr);
	AIInitDMA((u32)dac[2], DAC_SIZE * 2);
	u32 badCompiler[4];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_GetCurrentVCounter(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void HaltDSPSignal(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void HaltDSP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void RunDSP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void CheckHaltDSP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800058C0
 * Size:	0000DC
 */
static void MixMonoTrack(s16* track, s32 nSamples, MixCallback callback)
{
	u32 badCompiler[2];
	Probe_Start(5, "MONO-MIX");

	s16* monoTrack = (*callback)(nSamples);
	int mix;

	if (monoTrack != nullptr) {
		Probe_Finish(5);

		s16* dst_p = track;
		s16* src_p = monoTrack;

		for (s32 i = nSamples; i > 0; i--) {
			mix = *dst_p + *src_p;
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*dst_p++ = (s16)mix;

			mix = *dst_p + *src_p;
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*dst_p++ = (s16)mix;

			src_p++;
		}
	}
}

/*
 * --INFO--
 * Address:	800059A0
 * Size:	0000DC
 */
static void MixMonoTrackWide(s16* track, s32 nSamples, MixCallback callback)
{
	u32 badCompiler[2];
	Probe_Start(5, "MONO(W)-MIX");

	s16* monoTrack = (*callback)(nSamples);
	int mix;

	if (monoTrack != nullptr) {
		Probe_Finish(5);

		s16* dst_p = track;
		s16* src_p = monoTrack;

		for (s32 i = nSamples; i > 0; i--) {
			mix = *dst_p + *src_p;
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*dst_p++ = (s16)mix;

			mix = *dst_p - *src_p;
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*dst_p++ = (s16)mix;
			src_p++;
		}
	}
}

/*
 * --INFO--
 * Address:	80005A80
 * Size:	0000F8
 */
static void MixExtraTrack(s16* track, s32 nSamples, MixCallback callback)
{
	u32 badCompiler[2];
	Probe_Start(5, "DSPMIX");

	s16* extraTrack = (*callback)(nSamples);
	int mix;

	if (extraTrack != nullptr) {
		Probe_Finish(5);
		Probe_Start(6, "MIXING");

		s16* dst_p  = track;
		s16* src0_p = extraTrack + JAC_FRAMESAMPLES;
		s16* src1_p = extraTrack;

		for (s32 i = nSamples; i > 0; i--) {
			mix = *dst_p + src0_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*dst_p++ = (s16)mix;

			mix = *dst_p + src1_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*dst_p++ = (s16)mix;
			src0_p++;
			src1_p++;
		}

		Probe_Finish(6);
	}
}

/*
 * --INFO--
 * Address:	80005B80
 * Size:	00008C
 */
static void MixInterleaveTrack(s16* track, s32 nSamples, MixCallback callback)
{
	u32 badCompiler[2];
	s16* interleaveTrack = (*callback)(nSamples);
	int mix;

	if (interleaveTrack != nullptr) {
		s16* track_p = track;
		s32 max      = nSamples * 2;

		for (s32 i = 0; i < max; i++) {
			mix = *track_p + *interleaveTrack;
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			*track_p++ = (s16)mix;
			interleaveTrack++;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
MixCallback Jac_GetMixcallback(u8* mixmode)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void Jac_RegisterMixcallback(MixCallback callback, u8 mixmode)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005C20
 * Size:	000188
 */
void Jac_VframeWork()
{
	static u32 dacp = 0;

	JAC_VFRAME_COUNTER++;

	s16* mixedTrack = MixDsp(DAC_SIZE / 2);
	s16* x          = &mixedTrack[JAC_FRAMESAMPLES];
	Jac_imixcopy(x, &mixedTrack[0], dac[dacp], DAC_SIZE / 2);

	if (ext_mixcallback != nullptr) {
		switch (ext_mixmode) {
		case MixMode_Mono:
			MixMonoTrack(dac[dacp], DAC_SIZE / 2, ext_mixcallback);
			break;
		case MixMode_MonoWide:
			MixMonoTrackWide(dac[dacp], DAC_SIZE / 2, ext_mixcallback);
			break;
		case MixMode_Extra:
			MixExtraTrack(dac[dacp], DAC_SIZE / 2, ext_mixcallback);
			break;
		case MixMode_Interleave:
			MixInterleaveTrack(dac[dacp], DAC_SIZE / 2, ext_mixcallback);
			break;
		}
	}

	BOOL enable = OSDisableInterrupts();
	DCStoreRange(dac[dacp], DAC_SIZE * 2);
	OSRestoreInterrupts(enable);

	last_rsp_madep = dac[dacp];
	dacp++;
	if (dacp == 3) {
		dacp = 0;
	}
	vframe_work_running = FALSE;
}

/*
 * --INFO--
 * Address:	80005DC0
 * Size:	0000A8
 */
void Jac_UpdateDAC()
{
	if (use_rsp_madep == nullptr) {
		use_rsp_madep  = last_rsp_madep;
		last_rsp_madep = nullptr;
	}

	if (use_rsp_madep != nullptr) {
		AIInitDMA((u32)use_rsp_madep, DAC_SIZE * 2);
		use_rsp_madep = nullptr;
	} else {
		UNIVERSAL_DACCOUNTER++;
	}

	if (last_rsp_madep == nullptr && vframe_work_running == FALSE) {
		Jac_VframeWork();
	}

	StreamMain();

	if (DAC_CALLBACK_FUNC != nullptr) {
		(*DAC_CALLBACK_FUNC)(last_rsp_madep, DAC_SIZE / 2);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_RegisterDacCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005E80
 * Size:	000008
 */
void Jac_SetOutputMode(int mode)
{
	JAC_SYSTEM_OUTPUT_MODE = mode;
}

/*
 * --INFO--
 * Address:	80005EA0
 * Size:	000008
 */
int Jac_GetOutputMode()
{
	return JAC_SYSTEM_OUTPUT_MODE;
}

/*
 * --INFO--
 * Address:	80005EC0
 * Size:	000034
 */
void Jac_SetMixerLevel(f32 channelLevel, f32 dspLevel)
{
	Channel_SetMixerLevel(channelLevel);
	DsetMixerLevel(dspLevel);
}
