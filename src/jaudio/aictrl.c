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
	Probe_Start(5, "MONO-MIX");

	s16* monoTrack = (*callback)(nSamples);
	int mix;

	if (monoTrack != nullptr) {
		Probe_Finish(5);

		s16* dst_p = track;
		s16* src_p = monoTrack;

		for (s32 i = 0; i < nSamples; i++) {
			mix = dst_p[0] + src_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			dst_p[0] = (s16)mix;

			mix = dst_p[1] + src_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			dst_p[1] = (s16)mix;

			dst_p += 2;
			src_p++;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x1FE0
	  stwu      r1, -0x30(r1)
	  stmw      r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  addi      r31, r5, 0
	  mr        r4, r0
	  li        r3, 0x5
	  bl        -0x2EC
	  addi      r12, r31, 0
	  addi      r3, r30, 0
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0xC8
	  li        r3, 0x5
	  bl        -0x2EC
	  mr.       r0, r30
	  addi      r4, r29, 0
	  addi      r5, r31, 0
	  mtctr     r0
	  ble-      .loc_0xC8

	.loc_0x64:
	  lha       r3, 0x0(r4)
	  lha       r0, 0x0(r5)
	  add       r0, r3, r0
	  cmpwi     r0, -0x8000
	  bge-      .loc_0x7C
	  li        r0, -0x7FFF

	.loc_0x7C:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0x88
	  li        r0, 0x7FFF

	.loc_0x88:
	  extsh     r0, r0
	  sth       r0, 0x0(r4)
	  lhau      r3, 0x2(r4)
	  lha       r0, 0x0(r5)
	  add       r0, r3, r0
	  cmpwi     r0, -0x8000
	  bge-      .loc_0xA8
	  li        r0, -0x7FFF

	.loc_0xA8:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0xB4
	  li        r0, 0x7FFF

	.loc_0xB4:
	  extsh     r0, r0
	  addi      r5, r5, 0x2
	  sth       r0, 0x0(r4)
	  addi      r4, r4, 0x2
	  bdnz+     .loc_0x64

	.loc_0xC8:
	  lmw       r29, 0x24(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800059A0
 * Size:	0000DC
 */
static void MixMonoTrackWide(s16* track, s32 nSamples, MixCallback callback)
{
	Probe_Start(5, "MONO(W)-MIX");

	s16* monoTrack = (*callback)(nSamples);
	int mix;

	if (monoTrack != nullptr) {
		Probe_Finish(5);

		s16* dst_p = track;
		s16* src_p = monoTrack;

		for (s32 i = 0; i < nSamples; i++) {
			mix = dst_p[0] + src_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			dst_p[0] = (s16)mix;

			mix = dst_p[1] - src_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			dst_p[1] = (s16)mix;

			dst_p += 2;
			src_p++;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x1FEC
	  stwu      r1, -0x30(r1)
	  stmw      r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  addi      r31, r5, 0
	  mr        r4, r0
	  li        r3, 0x5
	  bl        -0x3CC
	  addi      r12, r31, 0
	  addi      r3, r30, 0
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0xC8
	  li        r3, 0x5
	  bl        -0x3CC
	  mr.       r0, r30
	  addi      r4, r29, 0
	  addi      r5, r31, 0
	  mtctr     r0
	  ble-      .loc_0xC8

	.loc_0x64:
	  lha       r3, 0x0(r4)
	  lha       r0, 0x0(r5)
	  add       r0, r3, r0
	  cmpwi     r0, -0x8000
	  bge-      .loc_0x7C
	  li        r0, -0x7FFF

	.loc_0x7C:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0x88
	  li        r0, 0x7FFF

	.loc_0x88:
	  extsh     r0, r0
	  sth       r0, 0x0(r4)
	  lha       r3, 0x0(r5)
	  lhau      r0, 0x2(r4)
	  sub       r0, r0, r3
	  cmpwi     r0, -0x8000
	  bge-      .loc_0xA8
	  li        r0, -0x7FFF

	.loc_0xA8:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0xB4
	  li        r0, 0x7FFF

	.loc_0xB4:
	  extsh     r0, r0
	  addi      r5, r5, 0x2
	  sth       r0, 0x0(r4)
	  addi      r4, r4, 0x2
	  bdnz+     .loc_0x64

	.loc_0xC8:
	  lmw       r29, 0x24(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80005A80
 * Size:	0000F8
 */
static void MixExtraTrack(s16* track, s32 nSamples, MixCallback callback)
{
	Probe_Start(5, "DSPMIX");

	s16* extraTrack = (*callback)(nSamples);
	int mix;

	if (extraTrack != nullptr) {
		Probe_Finish(5);
		Probe_Start(6, "MIXING");

		s16* dst_p  = track;
		s16* src0_p = extraTrack + JAC_FRAMESAMPLES;
		s16* src1_p = extraTrack;

		for (s32 i = 0; i < nSamples; i++) {
			mix = dst_p[0] + src0_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			dst_p[0] = (s16)mix;

			mix = dst_p[1] + src1_p[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			dst_p[1] = (s16)mix;

			dst_p += 2;
			src0_p++;
			src1_p++;
		}

		Probe_Finish(6);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  addi      r31, r5, 0
	  li        r3, 0x5
	  subi      r4, r2, 0x8000
	  bl        -0x4A4
	  addi      r12, r31, 0
	  addi      r3, r30, 0
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0xE4
	  li        r3, 0x5
	  bl        -0x4A4
	  li        r3, 0x6
	  subi      r4, r2, 0x7FF8
	  bl        -0x4D0
	  lwz       r0, -0x7FF8(r13)
	  mr.       r3, r30
	  addi      r4, r29, 0
	  addi      r6, r31, 0
	  rlwinm    r0,r0,1,0,30
	  add       r5, r31, r0
	  mtctr     r3
	  ble-      .loc_0xDC

	.loc_0x74:
	  lha       r3, 0x0(r4)
	  lha       r0, 0x0(r5)
	  add       r0, r3, r0
	  cmpwi     r0, -0x8000
	  bge-      .loc_0x8C
	  li        r0, -0x7FFF

	.loc_0x8C:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0x98
	  li        r0, 0x7FFF

	.loc_0x98:
	  extsh     r0, r0
	  sth       r0, 0x0(r4)
	  lhau      r3, 0x2(r4)
	  lha       r0, 0x0(r6)
	  add       r0, r3, r0
	  cmpwi     r0, -0x8000
	  bge-      .loc_0xB8
	  li        r0, -0x7FFF

	.loc_0xB8:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0xC4
	  li        r0, 0x7FFF

	.loc_0xC4:
	  extsh     r0, r0
	  addi      r6, r6, 0x2
	  sth       r0, 0x0(r4)
	  addi      r4, r4, 0x2
	  addi      r5, r5, 0x2
	  bdnz+     .loc_0x74

	.loc_0xDC:
	  li        r3, 0x6
	  bl        -0x540

	.loc_0xE4:
	  lmw       r29, 0x24(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80005B80
 * Size:	00008C
 */
static void MixInterleaveTrack(s16* track, s32 nSamples, MixCallback callback)
{
	s16* interleaveTrack = (*callback)(nSamples);
	int mix;

	if (interleaveTrack != nullptr) {
		s16* track_p = track;
		s32 max      = nSamples * 2;

		for (s32 i = 0; i < max; i++) {
			mix = track_p[0] + interleaveTrack[0];
			if (mix < S16_MIN) {
				mix = S16_MIN + 1;
			}

			if (mix > S16_MAX) {
				mix = S16_MAX;
			}

			track_p[0] = (s16)mix;

			track_p++;
			interleaveTrack++;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r12, r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r30, 0x20(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x78
	  rlwinm.   r0,r31,1,0,30
	  addi      r5, r30, 0
	  mtctr     r0
	  ble-      .loc_0x78

	.loc_0x40:
	  lha       r4, 0x0(r5)
	  lha       r0, 0x0(r3)
	  add       r0, r4, r0
	  cmpwi     r0, -0x8000
	  bge-      .loc_0x58
	  li        r0, -0x7FFF

	.loc_0x58:
	  cmpwi     r0, 0x7FFF
	  ble-      .loc_0x64
	  li        r0, 0x7FFF

	.loc_0x64:
	  extsh     r0, r0
	  addi      r3, r3, 0x2
	  sth       r0, 0x0(r5)
	  addi      r5, r5, 0x2
	  bdnz+     .loc_0x40

	.loc_0x78:
	  lwz       r0, 0x2C(r1)
	  lmw       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
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
	Jac_imixcopy(&mixedTrack[JAC_FRAMESAMPLES], &mixedTrack[0], dac[dacp], DAC_SIZE / 2);

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
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stmw      r30, 0x8(r1)
	  subi      r31, r3, 0x69C0
	  lbz       r0, 0x2B28(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x34
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x2B24(r13)
	  stb       r0, 0x2B28(r13)

	.loc_0x34:
	  lwz       r3, 0x2B18(r13)
	  lwz       r0, -0x7FF4(r13)
	  addi      r3, r3, 0x1
	  stw       r3, 0x2B18(r13)
	  rlwinm    r3,r0,31,1,31
	  bl        0x11F8
	  lwz       r5, 0x2B24(r13)
	  addi      r4, r3, 0
	  lwz       r0, -0x7FF8(r13)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r3,r0,1,0,30
	  lwz       r0, -0x7FF4(r13)
	  lwzx      r5, r31, r5
	  add       r3, r4, r3
	  rlwinm    r6,r0,31,1,31
	  bl        0x270
	  lwz       r5, 0x2B1C(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x118
	  lbz       r0, 0x2B20(r13)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xE4
	  bge-      .loc_0xA0
	  cmpwi     r0, 0
	  beq-      .loc_0xAC
	  bge-      .loc_0xC8
	  b         .loc_0x118

	.loc_0xA0:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x118
	  b         .loc_0x100

	.loc_0xAC:
	  lwz       r3, 0x2B24(r13)
	  lwz       r0, -0x7FF4(r13)
	  rlwinm    r3,r3,2,0,29
	  lwzx      r3, r31, r3
	  rlwinm    r4,r0,31,1,31
	  bl        -0x420
	  b         .loc_0x118

	.loc_0xC8:
	  lwz       r3, 0x2B24(r13)
	  lwz       r0, -0x7FF4(r13)
	  rlwinm    r3,r3,2,0,29
	  lwzx      r3, r31, r3
	  rlwinm    r4,r0,31,1,31
	  bl        -0x35C
	  b         .loc_0x118

	.loc_0xE4:
	  lwz       r3, 0x2B24(r13)
	  lwz       r0, -0x7FF4(r13)
	  rlwinm    r3,r3,2,0,29
	  lwzx      r3, r31, r3
	  rlwinm    r4,r0,31,1,31
	  bl        -0x298
	  b         .loc_0x118

	.loc_0x100:
	  lwz       r3, 0x2B24(r13)
	  lwz       r0, -0x7FF4(r13)
	  rlwinm    r3,r3,2,0,29
	  lwzx      r3, r31, r3
	  rlwinm    r4,r0,31,1,31
	  bl        -0x1B4

	.loc_0x118:
	  bl        0x1F3244
	  lwz       r4, 0x2B24(r13)
	  addi      r30, r3, 0
	  lwz       r0, -0x7FF4(r13)
	  rlwinm    r3,r4,2,0,29
	  lwzx      r3, r31, r3
	  rlwinm    r4,r0,1,0,30
	  bl        0x1F0EC8
	  mr        r3, r30
	  bl        0x1F3248
	  lwz       r4, 0x2B24(r13)
	  rlwinm    r3,r4,2,0,29
	  addi      r0, r4, 0x1
	  lwzx      r3, r31, r3
	  stw       r0, 0x2B24(r13)
	  lwz       r0, 0x2B24(r13)
	  stw       r3, 0x2B08(r13)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x16C
	  li        r0, 0
	  stw       r0, 0x2B24(r13)

	.loc_0x16C:
	  li        r0, 0
	  stw       r0, 0x2B10(r13)
	  lmw       r30, 0x8(r1)
	  lwz       r0, 0x14(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2B0C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  lwz       r3, 0x2B08(r13)
	  li        r0, 0
	  stw       r3, 0x2B0C(r13)
	  stw       r0, 0x2B08(r13)

	.loc_0x28:
	  lwz       r3, 0x2B0C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  lwz       r0, -0x7FF4(r13)
	  rlwinm    r4,r0,1,0,30
	  bl        0x20024C
	  li        r0, 0
	  stw       r0, 0x2B0C(r13)
	  b         .loc_0x58

	.loc_0x4C:
	  lwz       r3, 0x2B00(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2B00(r13)

	.loc_0x58:
	  lwz       r0, 0x2B08(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x74
	  lwz       r0, 0x2B10(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x74
	  bl        -0x210

	.loc_0x74:
	  bl        0x9AC
	  lwz       r12, 0x2B14(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x98
	  lwz       r0, -0x7FF4(r13)
	  lwz       r3, 0x2B08(r13)
	  rlwinm    r4,r0,31,1,31
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
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
