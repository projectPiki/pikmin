#include "jaudio/driverinterface.h"

#include "jaudio/dspinterface.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspdriver.h"
#include "jaudio/ja_calc.h"
#include "jaudio/bankdrv.h"

#define CHANNEL_SIZE (0x100)

static jcs_ GLOBAL_CHANNEL;
static jc_ CHANNEL[CHANNEL_SIZE];

static u16 MAX_MIXERLEVEL         = 12000;
static u32 JAC_SYSTEM_OUTPUT_MODE = 1;

static u32 cur_waits;
static u32 cur_top;
static u32 cur_tail;
static jc_* waitp[0x20];
static int waittime[0x20];

static u8 calc_sw_table[]
    = { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 2, 0, 1, 0, 0, 2, 1, 0, 2, 2, 1, 0, 0, 1, 0, 1, 1, 0, 2, 1, 1, 0, 1, 1,
	    1, 1, 1, 2, 1, 2, 0, 1, 2, 1, 1, 2, 2, 1, 0, 0, 2, 0, 1, 2, 0, 2, 2, 1, 0, 2, 1, 1, 2, 1, 2, 2, 2, 0, 2, 2, 1, 2, 2, 2 };

// forward declarations
static void Cancel_WaitDSPChannel(jc_* jc);

/*
 * --INFO--
 * Address:	80009400
 * Size:	000024
 */
void Channel_SetMixerLevel(f32 mix)
{
	MAX_MIXERLEVEL = mix * 16384.0f;
}

/*
 * --INFO--
 * Address:	80009440
 * Size:	00000C
 */
jcs_* Get_GlobalHandle()
{
	return &GLOBAL_CHANNEL;
}

/*
 * --INFO--
 * Address:	80009460
 * Size:	000020
 */
int List_CountChannel(jc_** jc)
{
	jc_* chan = *jc;
	int num   = 0;

	while (TRUE) {
		if (chan == NULL) {
			break;
		}
		chan = (jc_*)chan->mNext;
		num++;
	}

	return num;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void Check_GlobalActiveChannel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Check_GlobalRelease(jc_** jc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void List_GlobalChannel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80009480
 * Size:	000070
 */
int List_CutChannel(jc_* jc)
{
	jc_* chan = (jc_*)*jc->chanListHead;
	int num   = 0;

	if (chan == jc) {
		*jc->chanListHead = jc->mNext;
		jc->chanListHead  = NULL;
		return 0;
	}

	while (TRUE) {
		num++;
		if (chan == NULL) {
			return -1;
		}

		if (chan->mNext == jc) {
			break;
		}

		chan = (jc_*)chan->mNext;
	}

	chan->mNext      = jc->mNext;
	jc->chanListHead = NULL;

	return num;
}

/*
 * --INFO--
 * Address:	80009500
 * Size:	000030
 */
jc_* List_GetChannel(jc_** jc)
{
	jc_* chan = *jc;

	if (chan == NULL) {
		return NULL;
	}

	*jc                = (jc_*)chan->mNext;
	chan->chanListHead = NULL;
	return chan;
}

/*
 * --INFO--
 * Address:	80009540
 * Size:	000048
 */
void List_AddChannelTail(jc_** jc, jc_* in)
{
	jc_* chan        = *jc;
	in->chanListHead = jc;

	if (chan == NULL) {
		*jc       = in;
		in->mNext = NULL;
		return;
	}

	jc_* next;
	while (TRUE) {
		next = (jc_*)chan->mNext;
		if (next == NULL) {
			chan->mNext = in;
			in->mNext   = NULL;
			return;
		}
		chan = next;
	}
}

/*
 * --INFO--
 * Address:	800095A0
 * Size:	000014
 */
void List_AddChannel(jc_** jc, jc_* in)
{
	jc_* chan        = *jc;
	in->chanListHead = jc;
	*jc              = in;
	in->mNext        = chan;
}

/*
 * --INFO--
 * Address:	800095C0
 * Size:	00009C
 */
int FixAllocChannel(jcs_* sys, u32 size)
{
	jcs_** REF_sys = &sys;
	u32* REF_size  = &size;
	int num        = 0;
	while (num < size) {
		jc_* chan = List_GetChannel(&GLOBAL_CHANNEL.freeChannels);
		if (chan == NULL) {
			break;
		}

		List_AddChannel(&sys->freeChannels, chan);
		chan->mMgr = sys;
		Channel_Init(chan);
		num++;
	}

	sys->chanCount += num;
	GLOBAL_CHANNEL.chanCount -= num;
	return num;
}

/*
 * --INFO--
 * Address:	80009660
 * Size:	000060
 */
int FixReleaseChannel(jc_* chan)
{
	List_AddChannel(&GLOBAL_CHANNEL.freeChannels, chan);
	chan->mMgr->chanCount--;
	GLOBAL_CHANNEL.chanCount++;
	chan->mMgr = &GLOBAL_CHANNEL;
	return 0;
}

/*
 * --INFO--
 * Address:	800096C0
 * Size:	0000F0
 */
int FixReleaseChannelAll(jcs_* sys)
{
	jc_* chan;

	while (TRUE) {
		chan = List_GetChannel(&sys->freeChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&GLOBAL_CHANNEL.freeChannels, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->activeChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&GLOBAL_CHANNEL.activeChannels, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->releasingChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&GLOBAL_CHANNEL.releasingChannels, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->waitingChannels);
		if (chan == NULL) {
			break;
		}
		Cancel_WaitDSPChannel(chan);
		List_AddChannel(&GLOBAL_CHANNEL.freeChannels, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	GLOBAL_CHANNEL.chanCount += sys->chanCount;
	sys->chanCount = 0;
	return 0;
}

/*
 * --INFO--
 * Address:	800097C0
 * Size:	0000EC
 */
int FixMoveChannelAll(jcs_* sys, jcs_* sys2)
{
	jc_* chan;

	while (TRUE) {
		chan = List_GetChannel(&sys->freeChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->freeChannels, chan);
		chan->mMgr = sys2;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->activeChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->activeChannels, chan);
		chan->mMgr = sys2;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->releasingChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->releasingChannels, chan);
		chan->mMgr = sys2;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->waitingChannels);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->waitingChannels, chan);
		chan->mMgr = sys2;
	}

	sys2->chanCount += sys->chanCount;
	sys->chanCount = 0;
	sys2->chanAllocCount += sys->chanAllocCount;
	sys->chanAllocCount = 0;
	return 0;

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800098C0
 * Size:	000070
 */
static f32 PanCalc(const PanMatrix_* mtx1, const PanMatrix_* mtx2, u8 a)
{
	f32 calc = 0.0f;

	u8* vals = calc_sw_table + (a * 3);

	for (int i = 0; i < 3; i++) {
		switch (vals[i]) {
		case 0:
			break;
		case 1:
			calc += mtx1->values[i];
			break;
		case 2:
			calc += (mtx1->values[i] * mtx2->values[i]);
			break;
		}
	}
	return calc;
}

/*
 * --INFO--
 * Address:	80009940
 * Size:	000104
 */
void InitJcs(jcs_* sys)
{
	sys->freeChannels      = NULL;
	sys->activeChannels    = NULL;
	sys->releasingChannels = NULL;
	sys->waitingChannels   = NULL;
	sys->chanAllocCount    = 0;
	sys->chanCount         = 0;
	sys->voiceStealingMode = 1;
	sys->volume            = 1.0f;
	sys->pitch             = 1.0f;
	sys->pan               = 0.5f;
	sys->fxmix             = 0.0f;
	sys->dolby             = 0.0f;

	int i;

	for (i = 0; i < 8; i++) {
		sys->firCoefficients[i] = 0;
	}

	sys->firCoefficients[0] = 0x7fff;
	sys->distFilter         = 0;

	for (i = 0; i < 4; i++) {
		sys->iirCoefficients[i] = 0;
		sys->masterLevels[i]    = 0;
	}

	sys->maxDelay           = 0;
	sys->iirCoefficients[0] = 0x7fff;
	sys->filterMode         = 0;
	sys->busConnect[0]      = 0x150;
	sys->busConnect[1]      = 0x210;
	sys->busConnect[2]      = 0x352;
	sys->busConnect[3]      = 0x412;
	sys->busConnect[4]      = 0;
	sys->busConnect[5]      = 0;
	sys->channelPriority    = 0x20103;
	sys->releaseTime        = 600;
	sys->panCalcTypes[0]    = 26;
	sys->panCalcTypes[1]    = 1;
	sys->panCalcTypes[2]    = 1;
}

/*
 * --INFO--
 * Address:	80009A60
 * Size:	000138
 */
void Channel_Init(jc_* jc)
{
	jc->updateCallback      = NULL;
	jc->extraUpdateCallback = NULL;
	jc->playId              = 0;
	jc->savedPlayId         = 0;
	jc->waveData            = NULL;
	jc->logicalChanType     = 0;
	jc->_14                 = 0;
	jc->_18                 = 0;
	jc->_1C                 = 0;

	if (jc->mMgr == NULL) {
		jc->busRouting[0]   = 0x150;
		jc->busRouting[1]   = 0x210;
		jc->busRouting[2]   = 0x352;
		jc->busRouting[3]   = 0x412;
		jc->busRouting[4]   = 0;
		jc->busRouting[5]   = 0;
		jc->channelPriority = 0x10101;
		jc->releaseTime     = 0x258;
		jc->panCalcTypes[0] = 0x1A;
		jc->panCalcTypes[1] = 1;
		jc->panCalcTypes[2] = 1;
	} else {
		for (int i = 0; i < 6; i++) {
			jc->busRouting[i] = jc->mMgr->busConnect[i];
		}

		jc->channelPriority = jc->mMgr->channelPriority;
		jc->releaseTime     = jc->mMgr->releaseTime;

		for (int i = 0; i < 3; i++) {
			jc->panCalcTypes[i] = jc->mMgr->panCalcTypes[i];
		}
	}

	for (int i = 0; i < 4; i++) {
		jc->mOscillators[i] = NULL;
	}

	jc->pauseFlag = 0;
	jc->channelId++;
	if ((int)jc->channelId == 0) {
		jc->channelId = 1;
	}
}

/*
 * --INFO--
 * Address:	80009BA0
 * Size:	000030
 */
static void Channel_FirstInit(jc_* jc)
{
	jc->dspChannel = NULL;
	jc->mNext      = NULL;
	jc->mMgr       = NULL;
	Channel_Init(jc);
}

/*
 * --INFO--
 * Address:	80009BE0
 * Size:	00007C
 */
void InitGlobalChannel()
{
	jcs_* global_channel;
	int i;

	global_channel = &GLOBAL_CHANNEL;
	InitJcs(global_channel);

	for (i = 0; i < CHANNEL_SIZE; i++) {
		Channel_FirstInit(&CHANNEL[i]);
		List_AddChannel(&global_channel->freeChannels, &CHANNEL[i]);
		CHANNEL[i].mMgr = global_channel;
	}

	global_channel->chanCount = CHANNEL_SIZE;
}

/*
 * --INFO--
 * Address:	80009C60
 * Size:	0000D8
 */
static void __UpdateJcToDSPInit(jc_* jc)
{
	int buf = jc->dspChannel->buffer_idx;
	DSP_SetMixerInitDelayMax(buf, jc->mMgr->maxDelay);

	for (u32 i = 0; i < 6; i++) {
		DSP_SetMixerInitVolume(buf, i, jc->mixerLevels[i], jc->mMgr->masterLevels[i]);
	}

	DSP_SetPitch(buf, jc->finalPitch);

	if (jc->mMgr->filterMode & 0x20) {
		DSP_SetIIRFilterParam(buf, jc->mMgr->iirCoefficients);
	}

	if (jc->mMgr->filterMode & 0x1f) {
		DSP_SetFIR8FilterParam(buf, jc->mMgr->firCoefficients);
	}

	DSP_SetFilterMode(buf, jc->mMgr->filterMode);
	DSP_SetPauseFlag(buf, jc->pauseFlag);
}

/*
 * --INFO--
 * Address:	80009D40
 * Size:	0000D8
 */
static void __UpdateJcToDSP(jc_* jc)
{
	u8 uVar1;

	uVar1 = jc->dspChannel->buffer_idx;
	for (u32 i = 0; i < 6; ++i) {
		DSP_SetMixerVolume(uVar1, i, jc->mixerLevels[i], jc->mMgr->masterLevels[i]);
	}

	DSP_SetPitch(uVar1, jc->finalPitch);

	if ((jc->mMgr->filterMode & 0x20) != 0) {
		DSP_SetIIRFilterParam(uVar1, jc->mMgr->iirCoefficients);
	}

	if ((jc->mMgr->filterMode & 0x1f) != 0) {
		DSP_SetFIR8FilterParam(uVar1, jc->mMgr->firCoefficients);
	}

	DSP_SetFilterMode(uVar1, jc->mMgr->filterMode);
	DSP_SetDistFilter(uVar1, jc->mMgr->distFilter);
	DSP_SetPauseFlag(uVar1, jc->pauseFlag);
}

/*
 * --INFO--
 * Address:	80009E20
 * Size:	000038
 */
void UpdateJcToDSP(jc_* jc)
{
	__UpdateJcToDSP(jc);
	DSP_FlushChannel(jc->dspChannel->buffer_idx);
}

/*
 * --INFO--
 * Address:	80009E60
 * Size:	000348
 */
void UpdateEffecterParam(jc_* jc)
{
	f32 mod1, mod2;
	f32 mod3 = 0.0f;
	if (jc->lastManager == jc->mMgr) {
		jc->managerPitch             = jc->mMgr->pitch;
		jc->managerVolume            = jc->mMgr->volume;
		jc->panMatrices[1].values[2] = jc->mMgr->pan;
		jc->panMatrices[2].values[2] = jc->mMgr->fxmix;
		jc->panMatrices[3].values[2] = jc->mMgr->dolby;

		for (int i = 0; i < 3; i++) {
			jc->panCalcTypes[i] = jc->mMgr->panCalcTypes[i];
		}
	}

	switch (JAC_SYSTEM_OUTPUT_MODE) {
	case 0:
		mod1 = 0.5f;
		mod3 = 0.0f;
		mod2 = PanCalc(&jc->panMatrices[2], &jc->panMatrices[0], jc->panCalcTypes[1]);
		break;

	case 1:
		if (jc->panCalcTypes[0] == 0) {
			mod1 = 0.5f;
		} else {
			mod1 = PanCalc(&jc->panMatrices[1], &jc->panMatrices[0], jc->panCalcTypes[0]);
		}
		mod2 = PanCalc(&jc->panMatrices[2], &jc->panMatrices[0], jc->panCalcTypes[1]);
		mod3 = PanCalc(&jc->panMatrices[3], &jc->panMatrices[0], jc->panCalcTypes[2]);
		break;
	}

	mod1 = mod1 > 0.0f ? (mod1 < 1.0f) ? mod1 : 1.0f : 0.0f;
	mod2 = mod2 > 0.0f ? (mod2 < 1.0f) ? mod2 : 1.0f : 0.0f;
	mod3 = mod3 > 0.0f ? (mod3 < 1.0f) ? mod3 : 1.0f : 0.0f;

	jc->finalPitch = jc->currentPitch * jc->pitchModifier * jc->managerPitch * 4096.0f;

	f32 calc = jc->managerVolume * jc->currentVolume * jc->volumeModifier;
	f32 calc2, calc3;
	for (u32 i = 0; i < 6; i++) {

		u16 flag = jc->busRouting[i];
		u16* ptr = &flag;

		if ((u8)flag == 0) {
			jc->mixerLevels[i] = 0;
			continue;
		}

		if (flag >> 4) {
			switch (flag >> 4) {
			case 1:
				calc2 = mod1;
				break;
			case 2:
				calc2 = mod2;
				break;
			case 3:
				calc2 = mod3;
				break;
			case 5:
				calc2 = 1.0f - mod1;
				break;
			case 6:
				calc2 = 1.0f - mod2;
				break;
			case 7:
				calc2 = 1.0f - mod3;
				break;
			}
			calc *= sinf3(calc2);
		}

		if (flag & 0xf) {
			switch (flag & 0xf) {
			case 1:
				calc2 = mod1;
				break;
			case 2:
				calc2 = mod2;
				break;
			case 3:
				calc2 = mod3;
				break;
			case 5:
				calc2 = 1.0f - mod1;
				break;
			case 6:
				calc2 = 1.0f - mod2;
				break;
			case 7:
				calc2 = 1.0f - mod3;
				break;
			}
			calc *= sinf3(calc2);
		}

		calc3              = calc3 > 0.0f ? (calc3 < 1.0f) ? calc3 : 1.0f : calc;
		jc->mixerLevels[i] = calc3 * (f32)MAX_MIXERLEVEL;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  addi      r11, r1, 0xA8
	  bl        0x20AFCC
	  stmw      r25, 0x2C(r1)
	  mr        r30, r3
	  lfs       f28, -0x7FC4(r2)
	  lwz       r0, 0xFC(r3)
	  lwz       r3, 0x4(r3)
	  cmplw     r0, r3
	  bne-      .loc_0x90
	  lfs       f0, 0x1C(r3)
	  li        r0, 0x3
	  li        r5, 0
	  stfs      f0, 0x100(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x104(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0xD0(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0xDC(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0xE8(r30)
	  mtctr     r0

	.loc_0x74:
	  lwz       r4, 0x4(r30)
	  addi      r3, r5, 0x62
	  addi      r0, r5, 0xB8
	  addi      r5, r5, 0x1
	  lbzx      r3, r4, r3
	  stbx      r3, r30, r0
	  bdnz+     .loc_0x74

	.loc_0x90:
	  lwz       r0, -0x7FE4(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xCC
	  bge-      .loc_0x118
	  cmpwi     r0, 0
	  bge-      .loc_0xAC
	  b         .loc_0x118

	.loc_0xAC:
	  lfs       f31, -0x7FBC(r2)
	  addi      r3, r30, 0xD4
	  lfs       f28, -0x7FC4(r2)
	  addi      r4, r30, 0xBC
	  lbz       r5, 0xB9(r30)
	  bl        -0x660
	  fmr       f29, f1
	  b         .loc_0x118

	.loc_0xCC:
	  lbz       r5, 0xB8(r30)
	  cmplwi    r5, 0
	  bne-      .loc_0xE0
	  lfs       f31, -0x7FBC(r2)
	  b         .loc_0xF0

	.loc_0xE0:
	  addi      r3, r30, 0xC8
	  addi      r4, r30, 0xBC
	  bl        -0x688
	  fmr       f31, f1

	.loc_0xF0:
	  lbz       r5, 0xB9(r30)
	  addi      r3, r30, 0xD4
	  addi      r4, r30, 0xBC
	  bl        -0x69C
	  fmr       f29, f1
	  lbz       r5, 0xBA(r30)
	  addi      r3, r30, 0xE0
	  addi      r4, r30, 0xBC
	  bl        -0x6B0
	  fmr       f28, f1

	.loc_0x118:
	  lfs       f2, 0xB4(r30)
	  lfs       f1, 0xF0(r30)
	  lfs       f0, -0x7FC4(r2)
	  fmuls     f1, f2, f1
	  lfs       f2, 0x104(r30)
	  fcmpo     cr0, f31, f0
	  fmuls     f30, f2, f1
	  bge-      .loc_0x140
	  fmr       f31, f0
	  b         .loc_0x150

	.loc_0x140:
	  lfs       f0, -0x7FC0(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x150
	  fmr       f31, f0

	.loc_0x150:
	  lfs       f0, -0x7FC4(r2)
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x164
	  fmr       f29, f0
	  b         .loc_0x174

	.loc_0x164:
	  lfs       f0, -0x7FC0(r2)
	  fcmpo     cr0, f29, f0
	  ble-      .loc_0x174
	  fmr       f29, f0

	.loc_0x174:
	  lfs       f0, -0x7FC4(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x188
	  fmr       f28, f0
	  b         .loc_0x198

	.loc_0x188:
	  lfs       f0, -0x7FC0(r2)
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x198
	  fmr       f28, f0

	.loc_0x198:
	  lfs       f1, 0xB0(r30)
	  lis       r3, 0x8022
	  lfs       f0, 0xEC(r30)
	  lis       r4, 0x8022
	  lfs       f2, 0x100(r30)
	  addi      r27, r3, 0x4934
	  fmuls     f0, f1, f0
	  lfs       f1, -0x7FB8(r2)
	  addi      r26, r4, 0x4954
	  li        r31, 0
	  li        r29, 0
	  lis       r28, 0x4330
	  fmuls     f0, f2, f0
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  sth       r0, 0xF8(r30)
	  lfs       f24, -0x7FC0(r2)
	  lfs       f25, -0x7FC4(r2)
	  fsubs     f23, f24, f31
	  lfd       f26, -0x7FB0(r2)
	  fsubs     f22, f24, f29
	  fsubs     f21, f24, f28

	.loc_0x1F8:
	  add       r25, r30, r29
	  fmr       f20, f30
	  lhz       r0, 0x108(r25)
	  sth       r0, 0xC(r1)
	  lbz       r0, 0xC(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x220
	  li        r0, 0
	  sth       r0, 0x114(r25)
	  b         .loc_0x31C

	.loc_0x220:
	  lbz       r0, 0xD(r1)
	  rlwinm.   r0,r0,28,28,31
	  beq-      .loc_0x27C
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x270
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r26, r0
	  mtctr     r0
	  bctr
	  fmr       f27, f31
	  b         .loc_0x270
	  fmr       f27, f29
	  b         .loc_0x270
	  fmr       f27, f28
	  b         .loc_0x270
	  fmr       f27, f23
	  b         .loc_0x270
	  fmr       f27, f22
	  b         .loc_0x270
	  fmr       f27, f21

	.loc_0x270:
	  fmr       f1, f27
	  bl        0x3CCC
	  fmuls     f20, f20, f1

	.loc_0x27C:
	  lbz       r0, 0xD(r1)
	  rlwinm.   r0,r0,0,28,31
	  beq-      .loc_0x2D8
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x2CC
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r27, r0
	  mtctr     r0
	  bctr
	  fmr       f27, f31
	  b         .loc_0x2CC
	  fmr       f27, f29
	  b         .loc_0x2CC
	  fmr       f27, f28
	  b         .loc_0x2CC
	  fmr       f27, f23
	  b         .loc_0x2CC
	  fmr       f27, f22
	  b         .loc_0x2CC
	  fmr       f27, f21

	.loc_0x2CC:
	  fmr       f1, f27
	  bl        0x3C70
	  fmuls     f20, f20, f1

	.loc_0x2D8:
	  fcmpo     cr0, f20, f25
	  bge-      .loc_0x2E8
	  fmr       f20, f25
	  b         .loc_0x2F4

	.loc_0x2E8:
	  fcmpo     cr0, f20, f24
	  ble-      .loc_0x2F4
	  fmr       f20, f24

	.loc_0x2F4:
	  lhz       r0, -0x7FE8(r13)
	  stw       r0, 0x24(r1)
	  stw       r28, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f0, f0, f26
	  fmuls     f0, f20, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  sth       r0, 0x114(r25)

	.loc_0x31C:
	  addi      r31, r31, 0x1
	  addi      r29, r29, 0x2
	  cmplwi    r31, 0x6
	  blt+      .loc_0x1F8
	  lwz       r0, 0xAC(r1)
	  addi      r11, r1, 0xA8
	  bl        0x20ACF4
	  lmw       r25, 0x2C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A1C0
 * Size:	000068
 */
void DoEffectOsc(jc_* jc, u8 id, f32 val)
{
	switch (id) {
	case 1:
		jc->pitchModifier *= val;
		break;
	case 0:
		jc->volumeModifier *= val;
		break;
	case 2:
		jc->panMatrices[1].values[1] = val;
		break;
	case 3:
		jc->panMatrices[2].values[1] = val;
		break;
	case 4:
		jc->panMatrices[3].values[1] = val;
		break;
	}
}

/*
 * --INFO--
 * Address:	8000A240
 * Size:	000084
 */
static void KillBrokenLogicalChannels(dspch_* ch)
{
	size_t i;
	jc_* chan;

	for (i = 0; i < CHANNEL_SIZE; i++) {
		chan = &CHANNEL[i];
		if (chan->dspChannel == ch) {
			StopLogicalChannel(chan);
			if (List_CutChannel(chan) != -1) {
				List_AddChannel(&chan->mMgr->freeChannels, chan);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8000A2E0
 * Size:	000384
 */
static int CommonCallbackLogicalChannel(dspch_* ch, u32 a)
{
	u32 b    = 0;
	u32* ptr = &a;
	jc_* jc  = ch->_08;
	if (jc == NULL) {
		ch->_0C = nullptr;
		ch->_03 = 0;
		KillBrokenLogicalChannels(ch);
		return FALSE;
	}

	dspch_* ch2 = jc->dspChannel;
	if (ch != ch2) {
		if (ch2 && ch2->_08 == jc) {
			KillBrokenLogicalChannels(ch);
		} else {
			StopLogicalChannel(jc);
			if (List_CutChannel(jc) != -1) {
				List_AddChannel(&jc->mMgr->freeChannels, jc);
			}
		}
		ch->_08 = 0;
		ch->_03 = 0;
		ch->_0C = nullptr;
		return FALSE;
	}

	if (a == 2) {
		if (jc->updateCallback) {
			jc->updateCallback(jc, (JCSTATUS)1);
		} else {
			StopLogicalChannel(jc);
			if (List_CutChannel(jc) != -1) {
				List_AddChannel(&jc->mMgr->freeChannels, jc);
			}
		}
		return FALSE;
	}

	if (jc->waveData && jc->waveData->_0C) {
		ForceStopDSPchannel(ch2);
		return -1;
	}

	if (a == 4) {
		if (ch2 && (u8)(jc->channelPriority >> 0x10) < ch2->_03) {
			ch2->_03 = jc->channelPriority >> 0x10;
		}
		return FALSE;
	}

	if (a == 3) {
		jc->mOscillators[0]->mMode = 0;
		if (List_CutChannel(jc) != -1) {
			return TRUE;
		}
		List_AddChannel(&jc->mMgr->waitingChannels, jc);
		a = 0;
	}

	if (a == 0) {
		jc->pitchModifier            = 1.0f;
		jc->volumeModifier           = 1.0f;
		jc->panMatrices[1].values[1] = 0.5f;
		jc->panMatrices[2].values[1] = 0.0f;
		jc->panMatrices[3].values[1] = 0.0f;

		for (u32 i = 0; i < 4; i++) {
			Osc_* osc = jc->mOscillators[i];
			if (osc->mMode) {
				Oscbuf_* buf = &jc->mOscBuffers[i];
				DoEffectOsc(jc, osc->mMode, Bank_OscToOfs(osc, buf));
				if (buf->_00 == 0) {
					if (jc->updateCallback == NULL) {
						if (StopLogicalChannel(jc) == FALSE) {
							DSP_PlayStop(ch->buffer_idx);
							DSP_FlushChannel(ch->buffer_idx);
						}
						if (List_CutChannel(jc) != -1) {
							List_AddChannel(&jc->mMgr->freeChannels, jc);
						}
						return FALSE;
					} else {
						jc->updateCallback(jc, (JCSTATUS)1);
						return FALSE;
					}
				}
				b++;
			}
		}

		if (b) {
			UpdateEffecterParam(jc);
			jc->toFlush = 1;
		}

		if (jc->extraUpdateCallback && jc->extraUpdateCallback(jc, (JCSTATUS)0) == TRUE) {
			jc->toFlush++;
		}

		if (jc->updateCallback == NULL) {
			return TRUE;
		}

		if (jc->savedPlayId > 0) {
			jc->savedPlayId--;
		}

		if (jc->savedPlayId == 0) {
			jc->updateCallback(jc, (JCSTATUS)0);
			jc->savedPlayId = jc->playId;
		}

		if (jc->toFlush) {
			UpdateJcToDSP(jc);
			jc->toFlush = 0;
		}

		return TRUE;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stmw      r27, 0x54(r1)
	  li        r29, 0
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  lwz       r0, 0x8(r31)
	  addi      r28, r31, 0x8
	  stw       r0, 0x48(r1)
	  lwz       r30, 0x48(r1)
	  cmplwi    r30, 0
	  bne-      .loc_0x50
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0xC(r31)
	  stb       r0, 0x3(r31)
	  bl        -0xE4
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x50:
	  lwz       r3, 0x20(r30)
	  cmplw     r3, r31
	  beq-      .loc_0xBC
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lwz       r0, 0x8(r3)
	  cmplw     r0, r30
	  bne-      .loc_0x7C
	  mr        r3, r31
	  bl        -0x114
	  b         .loc_0xA4

	.loc_0x7C:
	  mr        r3, r30
	  bl        0x320
	  mr        r3, r30
	  bl        -0xEE8
	  cmpwi     r3, -0x1
	  beq-      .loc_0xA4
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x8
	  bl        -0xDE0

	.loc_0xA4:
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r28)
	  stb       r0, 0x3(r31)
	  stw       r0, 0xC(r31)
	  b         .loc_0x370

	.loc_0xBC:
	  cmplwi    r4, 0x2
	  bne-      .loc_0x114
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0xE4
	  addi      r3, r30, 0
	  li        r4, 0x1
	  mtlr      r12
	  blrl
	  b         .loc_0x10C

	.loc_0xE4:
	  mr        r3, r30
	  bl        0x2B8
	  mr        r3, r30
	  bl        -0xF50
	  cmpwi     r3, -0x1
	  beq-      .loc_0x10C
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x8
	  bl        -0xE48

	.loc_0x10C:
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x114:
	  lwz       r5, 0x10(r30)
	  cmplwi    r5, 0
	  beq-      .loc_0x13C
	  lwz       r5, 0x24(r5)
	  lwz       r0, 0x0(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x13C
	  bl        0xD50
	  li        r3, -0x1
	  b         .loc_0x370

	.loc_0x13C:
	  cmplwi    r4, 0x4
	  bne-      .loc_0x16C
	  lwz       r0, 0x120(r30)
	  cmplwi    r3, 0
	  rlwinm    r4,r0,16,24,31
	  beq-      .loc_0x164
	  lbzu      r0, 0x3(r3)
	  cmplw     r4, r0
	  bge-      .loc_0x164
	  stb       r4, 0x0(r3)

	.loc_0x164:
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x16C:
	  cmplwi    r4, 0x3
	  bne-      .loc_0x1A8
	  li        r0, 0x6
	  addi      r3, r30, 0
	  stb       r0, 0x48(r30)
	  bl        -0xFE0
	  cmpwi     r3, -0x1
	  bne-      .loc_0x194
	  li        r3, 0x1
	  b         .loc_0x370

	.loc_0x194:
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x14
	  bl        -0xEE0
	  li        r4, 0

	.loc_0x1A8:
	  cmplwi    r4, 0
	  bne-      .loc_0x320
	  lfs       f0, -0x7FC0(r2)
	  li        r0, 0
	  stfs      f0, 0xEC(r30)
	  stfs      f0, 0xF0(r30)
	  lfs       f0, -0x7FBC(r2)
	  stfs      f0, 0xCC(r30)
	  lfs       f0, -0x7FC4(r2)
	  stfs      f0, 0xD8(r30)
	  stfs      f0, 0xE4(r30)
	  stw       r0, 0x44(r1)
	  b         .loc_0x2A0

	.loc_0x1DC:
	  rlwinm    r3,r0,2,0,29
	  addi      r28, r3, 0x38
	  add       r28, r30, r28
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x294
	  mulli     r4, r0, 0x18
	  addi      r27, r4, 0x48
	  add       r27, r30, r27
	  addi      r4, r27, 0
	  bl        0x2E5C
	  lwz       r4, 0x0(r28)
	  mr        r3, r30
	  lbz       r4, 0x0(r4)
	  bl        -0x334
	  lbz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x290
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  bne-      .loc_0x278
	  mr        r3, r30
	  bl        0x16C
	  cmpwi     r3, 0
	  bne-      .loc_0x250
	  lbz       r3, 0x0(r31)
	  bl        0x12FC
	  lbz       r3, 0x0(r31)
	  bl        0x15F4

	.loc_0x250:
	  mr        r3, r30
	  bl        -0x10B4
	  cmpwi     r3, -0x1
	  beq-      .loc_0x270
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x8
	  bl        -0xFAC

	.loc_0x270:
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x278:
	  addi      r3, r30, 0
	  li        r4, 0x2
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x290:
	  addi      r29, r29, 0x1

	.loc_0x294:
	  lwz       r3, 0x44(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x44(r1)

	.loc_0x2A0:
	  lwz       r0, 0x44(r1)
	  cmplwi    r0, 0x4
	  blt+      .loc_0x1DC
	  cmplwi    r29, 0
	  beq-      .loc_0x2C4
	  mr        r3, r30
	  bl        -0x738
	  li        r0, 0x1
	  stb       r0, 0x3(r30)

	.loc_0x2C4:
	  lwz       r12, 0x2C(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0x2F4
	  addi      r3, r30, 0
	  li        r4, 0
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0x1
	  bne-      .loc_0x2F4
	  lbz       r3, 0x3(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x3(r30)

	.loc_0x2F4:
	  lwz       r0, 0x28(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x308
	  li        r3, 0x1
	  b         .loc_0x370

	.loc_0x308:
	  addi      r4, r30, 0x34
	  lwz       r3, 0x34(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x320
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)

	.loc_0x320:
	  addi      r27, r30, 0x34
	  lwz       r0, 0x34(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x34C
	  lwz       r12, 0x28(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  mtlr      r12
	  blrl
	  lwz       r0, 0x30(r30)
	  stw       r0, 0x0(r27)

	.loc_0x34C:
	  addi      r27, r30, 0x3
	  lbz       r0, 0x3(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x36C
	  mr        r3, r30
	  bl        -0x820
	  li        r0, 0
	  stb       r0, 0x0(r27)

	.loc_0x36C:
	  li        r3, 0x1

	.loc_0x370:
	  lmw       r27, 0x54(r1)
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A680
 * Size:	000078
 */
BOOL StopLogicalChannel(jc_* jc)
{
	dspch_* ch = jc->dspChannel;
	if (ch == NULL) {
		return FALSE;
	}

	ch->_0C             = NULL;
	jc->dspChannel->_06 = 0;
	DSP_PlayStop(jc->dspChannel->buffer_idx);
	DSP_FlushChannel(jc->dspChannel->buffer_idx);
	DeAllocDSPchannel(jc->dspChannel, (u32)jc);
	jc->dspChannel = NULL;
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000A700
 * Size:	000028
 */
BOOL CheckLogicalChannel(jc_* jc)
{
	if (jc->waveData == NULL && jc->logicalChanType == 0) {
		return FALSE;
	}
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000A740
 * Size:	000180
 */
BOOL PlayLogicalChannel(jc_* jc)
{
	if (jc->dspChannel == NULL) {
		return FALSE;
	}
	if (CheckLogicalChannel(jc) == FALSE) {
		return FALSE;
	}

	jc->dspChannel->_0C = CommonCallbackLogicalChannel;
	jc->dspChannel->_06 = 1;

	switch (jc->logicalChanType) {
	case 0:
		DSP_SetWaveInfo(jc->dspChannel->buffer_idx, jc->waveData, jc->_14);
		break;
	case 1:
		break;
	case 2:
		DSP_SetOscInfo(jc->dspChannel->buffer_idx, jc->_14);
		break;
	}

	for (u32 i = 0; i < 6; i++) {
		u16 bus0 = jc->busRouting[i];
		u8 bus   = bus0;
		u8* busp = &bus;
		if (JAC_SYSTEM_OUTPUT_MODE == 0) {
			switch (bus) {
			case 8:
				bus = 11;
				break;
			case 9:
				bus = 2;
				break;
			}
		}
		DSP_SetBusConnect(jc->dspChannel->buffer_idx, i, bus);
	}

	jc->lastManager = jc->mMgr;
	UpdateEffecterParam(jc);
	__UpdateJcToDSP(jc);
	jc->dspChannel->_03 = jc->channelPriority;
	jc->dspChannel->_04 = jc->releaseTime;
	DSP_PlayStart(jc->dspChannel->buffer_idx);
	DSP_FlushChannel(jc->dspChannel->buffer_idx);
	return TRUE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r29, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x16C

	.loc_0x28:
	  mr        r3, r31
	  bl        -0x6C
	  cmpwi     r3, 0
	  bne-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x16C

	.loc_0x40:
	  lis       r4, 0x8001
	  lwz       r3, 0x20(r31)
	  subi      r4, r4, 0x5D20
	  li        r0, 0x1
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x20(r31)
	  sth       r0, 0x6(r3)
	  lbz       r0, 0xC(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xAC
	  bge-      .loc_0x78
	  cmpwi     r0, 0
	  bge-      .loc_0x84
	  b         .loc_0xAC

	.loc_0x78:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xAC
	  b         .loc_0x9C

	.loc_0x84:
	  lwz       r3, 0x20(r31)
	  lwz       r4, 0x10(r31)
	  lbz       r3, 0x0(r3)
	  lwz       r5, 0x14(r31)
	  bl        0xF4C
	  b         .loc_0xAC

	.loc_0x9C:
	  lwz       r3, 0x20(r31)
	  lwz       r4, 0x14(r31)
	  lbz       r3, 0x0(r3)
	  bl        0xED8

	.loc_0xAC:
	  li        r29, 0
	  li        r30, 0

	.loc_0xB4:
	  addi      r3, r30, 0x108
	  lwz       r0, -0x7FE4(r13)
	  lhzx      r3, r31, r3
	  cmplwi    r0, 0
	  sth       r3, 0xC(r1)
	  bne-      .loc_0xFC
	  lbz       r0, 0xC(r1)
	  cmpwi     r0, 0x9
	  beq-      .loc_0xF4
	  bge-      .loc_0xFC
	  cmpwi     r0, 0x8
	  bge-      .loc_0xE8
	  b         .loc_0xFC

	.loc_0xE8:
	  li        r0, 0xB
	  stb       r0, 0xC(r1)
	  b         .loc_0xFC

	.loc_0xF4:
	  li        r0, 0x2
	  stb       r0, 0xC(r1)

	.loc_0xFC:
	  lwz       r3, 0x20(r31)
	  rlwinm    r4,r29,0,24,31
	  lbz       r5, 0xC(r1)
	  lbz       r3, 0x0(r3)
	  bl        0xF94
	  addi      r29, r29, 0x1
	  addi      r30, r30, 0x2
	  cmplwi    r29, 0x6
	  blt+      .loc_0xB4
	  lwz       r0, 0x4(r31)
	  mr        r3, r31
	  stw       r0, 0xFC(r31)
	  bl        -0xA0C
	  mr        r3, r31
	  bl        -0xC14
	  lwz       r0, 0x120(r31)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x3(r3)
	  lhz       r0, 0x124(r31)
	  lwz       r3, 0x20(r31)
	  sth       r0, 0x4(r3)
	  lwz       r3, 0x20(r31)
	  lbz       r3, 0x0(r3)
	  bl        0x1008
	  lwz       r3, 0x20(r31)
	  lbz       r3, 0x0(r3)
	  bl        0x127C
	  li        r3, 0x1

	.loc_0x16C:
	  lmw       r29, 0x14(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A8C0
 * Size:	000074
 */
BOOL ResetInitialVolume(jc_* jc)
{
	if (jc->dspChannel == NULL) {
		return FALSE;
	}

	if (CheckLogicalChannel(jc) == FALSE) {
		return FALSE;
	}

	UpdateEffecterParam(jc);
	__UpdateJcToDSPInit(jc);
	DSP_FlushChannel(jc->dspChannel->buffer_idx);
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000A940
 * Size:	0000B0
 */
BOOL Add_WaitDSPChannel(jc_* jc)
{
	if (cur_waits == 32) {
		return FALSE;
	}

	if (BreakLowerDSPchannel(jc->channelPriority) == FALSE) {
		return FALSE;
	}

	waittime[cur_tail] = 0;
	waitp[cur_tail]    = jc;
	cur_tail++;
	cur_waits++;

	if (cur_tail == 32) {
		cur_tail = 0;
	}
	return TRUE;

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	8000AA00
 * Size:	000064
 */
BOOL Del_WaitDSPChannel(jc_* jc)
{
	for (u32 i = 0; i < cur_waits; i++) {
		u32 a = (cur_top + i) & 0x1F;
		if (waitp[a] == jc) {
			waitp[a] = NULL;
			return TRUE;
		}
	}
	return FALSE;
}

/*
 * --INFO--
 * Address:	8000AA80
 * Size:	0000FC
 */
void __Entry_WaitChannel(u8 a)
{
	jc_* jc;
	dspch_* ch;

	while (cur_waits != 0) {
		while (TRUE) {
			jc_* temp = waitp[cur_top];
			if (temp) {
				jc = temp;
				break;
			}
		}

		ch = AllocDSPchannel(0, (u32)jc);
		if (ch == NULL) {
			break;
		}
		jc->dspChannel = ch;
		PlayLogicalChannel(jc);
		if (List_CutChannel(jc) != -1) {
			List_AddChannel(&jc->mMgr->activeChannels, jc);
		}
		cur_top++;
		if (cur_top == 0x20) {
			cur_top = 0;
		}
		cur_waits--;
		if (a == 1) {
			return;
		}

		cur_top++;
		if (cur_top == 0x20) {
			cur_top = 0;
		}
		cur_waits--;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8030
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  rlwinm    r31,r3,0,24,31
	  addi      r30, r4, 0x6560
	  b         .loc_0xDC

	.loc_0x20:
	  lwz       r4, 0x2BD4(r13)
	  rlwinm    r0,r4,2,0,29
	  add       r3, r30, r0
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r29, r0
	  beq-      .loc_0xB4
	  li        r3, 0
	  addi      r4, r29, 0
	  bl        0x29C
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  stw       r3, 0x20(r29)
	  mr        r3, r29
	  bl        -0x398
	  mr        r3, r29
	  bl        -0x1660
	  cmpwi     r3, -0x1
	  beq-      .loc_0x7C
	  lwz       r3, 0x4(r29)
	  addi      r4, r29, 0
	  addi      r3, r3, 0xC
	  bl        -0x15B8

	.loc_0x7C:
	  lwz       r3, 0x2BD4(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2BD4(r13)
	  lwz       r0, 0x2BD4(r13)
	  cmplwi    r0, 0x20
	  bne-      .loc_0x9C
	  li        r0, 0
	  stw       r0, 0x2BD4(r13)

	.loc_0x9C:
	  lwz       r3, 0x2BD0(r13)
	  cmplwi    r31, 0x1
	  subi      r0, r3, 0x1
	  stw       r0, 0x2BD0(r13)
	  beq-      .loc_0xE8
	  b         .loc_0xDC

	.loc_0xB4:
	  addi      r0, r4, 0x1
	  stw       r0, 0x2BD4(r13)
	  lwz       r0, 0x2BD4(r13)
	  cmplwi    r0, 0x20
	  bne-      .loc_0xD0
	  li        r0, 0
	  stw       r0, 0x2BD4(r13)

	.loc_0xD0:
	  lwz       r3, 0x2BD0(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2BD0(r13)

	.loc_0xDC:
	  lwz       r0, 0x2BD0(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x20

	.loc_0xE8:
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AB80
 * Size:	0000C4
 */
void EntryCheck_WaitDSPChannel()
{
	__Entry_WaitChannel(0);

	for (u32 i = 0; i < cur_waits; i++) {
		jc_* jc = waitp[(cur_top + i) & 0x1f];
		if (jc) {
			waittime[(cur_top + i) & 0x1f]++;
			if (jc->playId > 0) {
				jc->playId--;
			}
			if (jc->playId == 0) {
				jc->updateCallback(jc, (JCSTATUS)6);
				waitp[(cur_top + i) & 0x1f] = NULL;
			}
		}
	}

	u32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802F
	  stw       r0, 0x4(r1)
	  li        r3, 0
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r30, r4, 0x24E0
	  bl        -0x11C
	  addis     r30, r30, 0x1
	  li        r31, 0
	  b         .loc_0xA4

	.loc_0x2C:
	  lwz       r0, 0x2BD4(r13)
	  add       r0, r0, r31
	  rlwinm    r0,r0,2,25,29
	  add       r5, r30, r0
	  lwz       r0, 0x4080(r5)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0xA0
	  lwz       r4, 0x4100(r5)
	  addi      r0, r4, 0x1
	  stw       r0, 0x4100(r5)
	  lwz       r4, 0x30(r3)
	  cmpwi     r4, 0
	  ble-      .loc_0x6C
	  subi      r0, r4, 0x1
	  stw       r0, 0x30(r3)

	.loc_0x6C:
	  lwz       r0, 0x30(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xA0
	  lwz       r12, 0x28(r3)
	  li        r4, 0x6
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2BD4(r13)
	  li        r4, 0
	  add       r0, r0, r31
	  rlwinm    r0,r0,2,25,29
	  add       r3, r30, r0
	  stw       r4, 0x4080(r3)

	.loc_0xA0:
	  addi      r31, r31, 0x1

	.loc_0xA4:
	  lwz       r0, 0x2BD0(r13)
	  cmplw     r31, r0
	  blt+      .loc_0x2C
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AC60
 * Size:	00004C
 */
static void Cancel_WaitDSPChannel(jc_* jc)
{
	for (u32 i = 0; i < cur_waits; i++) {
		if (waitp[(cur_top + i) & 0x1F] == jc) {
			waitp[(cur_top + i) & 0x1F] = NULL;
		}
	}
}

/*
 * --INFO--
 * Address:	8000ACC0
 * Size:	000038
 */
BOOL ForceStopLogicalChannel(jc_* jc)
{
	if (jc->dspChannel == NULL) {
		return FALSE;
	}

	ForceStopDSPchannel(jc->dspChannel);
	return TRUE;
}
