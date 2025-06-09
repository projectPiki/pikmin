#include "jaudio/driverinterface.h"

#include "jaudio/dspinterface.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspdriver.h"
#include "jaudio/ja_calc.h"
#include "jaudio/bankdrv.h"
#include "jaudio/aictrl.h"

#define CHANNEL_SIZE (0x100)

static jcs_ GLOBAL_CHANNEL;
static jc_ CHANNEL[CHANNEL_SIZE];

static u16 MAX_MIXERLEVEL  = 12000;
u32 JAC_SYSTEM_OUTPUT_MODE = 1;

static u32 cur_waits;
static u32 cur_top;
static u32 cur_tail;
static jc_* waitp[0x20] ATTRIBUTE_ALIGN(32);
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
		jc->busRouting[0].whole = 0x150;
		jc->busRouting[1].whole = 0x210;
		jc->busRouting[2].whole = 0x352;
		jc->busRouting[3].whole = 0x412;
		jc->busRouting[4].whole = 0;
		jc->busRouting[5].whole = 0;
		jc->channelPriority     = 0x10101;
		jc->releaseTime         = 0x258;
		jc->panCalcTypes[0]     = 0x1A;
		jc->panCalcTypes[1]     = 1;
		jc->panCalcTypes[2]     = 1;
	} else {
		for (int i = 0; i < 6; i++) {
			jc->busRouting[i].whole = jc->mMgr->busConnect[i];
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
	f32 pan;
	f32 volume;
	f32 fxmix;
	f32 dolby = 0.0f;
	f32 angle;

	f32 tmp;
	if (jc->lastManager == jc->mMgr) {
		jc->managerPitch             = jc->mMgr->pitch;
		jc->managerVolume            = jc->mMgr->volume;
		jc->panMatrices[1].values[2] = jc->mMgr->pan;
		jc->panMatrices[2].values[2] = jc->mMgr->fxmix;
		jc->panMatrices[3].values[2] = jc->mMgr->dolby;

		for (u32 i = 0; i < 3; i++) {
			jc->panCalcTypes[i] = jc->mMgr->panCalcTypes[i];
		}
	}

	switch (JAC_SYSTEM_OUTPUT_MODE) {
	case 0:
		pan   = 0.5f;
		dolby = 0.0f;
		fxmix = PanCalc(&jc->panMatrices[2], &jc->panMatrices[0], jc->panCalcTypes[1]);
		break;

	case 1:
		if (jc->panCalcTypes[0] == 0) {
			pan = 0.5f;
		} else {
			pan = PanCalc(&jc->panMatrices[1], &jc->panMatrices[0], jc->panCalcTypes[0]);
		}
		fxmix = PanCalc(&jc->panMatrices[2], &jc->panMatrices[0], jc->panCalcTypes[1]);
		dolby = PanCalc(&jc->panMatrices[3], &jc->panMatrices[0], jc->panCalcTypes[2]);
		break;
	}

	volume = jc->currentVolume * jc->volumeModifier * jc->managerVolume;

	if (pan < 0.0f) {
		pan = 0.0f;
	} else if (pan > 1.0f) {
		pan = 1.0f;
	}

	if (fxmix < 0.0f) {
		fxmix = 0.0f;
	} else if (fxmix > 1.0f) {
		fxmix = 1.0f;
	}

	if (dolby < 0.0f) {
		dolby = 0.0f;
	} else if (dolby > 1.0f) {
		dolby = 1.0f;
	}

	jc->finalPitch = jc->currentPitch * jc->pitchModifier * jc->managerPitch * 4096.0f;

	for (u32 i = 0; i < 6; i++) {
		f32 tmp          = volume;
		MixConfig config = jc->busRouting[i];

		if (config.parts.upper == 0) {
			jc->mixerLevels[i] = 0;
			continue;
		}

		f32 angle;
		if (config.parts.lower0) {
			switch (config.parts.lower0) {
			case 1:
				angle = pan;
				break;
			case 2:
				angle = fxmix;
				break;
			case 3:
				angle = dolby;
				break;
			case 5:
				angle = 1.0f - pan;
				break;
			case 6:
				angle = 1.0f - fxmix;
				break;
			case 7:
				angle = 1.0f - dolby;
				break;
			}
			tmp *= sinf3(angle);
		}

		if (config.parts.lower1) {
			switch (config.parts.lower1) {
			case 1:
				angle = pan;
				break;
			case 2:
				angle = fxmix;
				break;
			case 3:
				angle = dolby;
				break;
			case 5:
				angle = 1.0f - pan;
				break;
			case 6:
				angle = 1.0f - fxmix;
				break;
			case 7:
				angle = 1.0f - dolby;
				break;
			}
			tmp *= sinf3(angle);
		}

		if (tmp < 0.0f) {
			tmp = 0.0f;
		} else if (tmp > 1.0f) {
			tmp = 1.0f;
		}
		jc->mixerLevels[i] = tmp * (f32)MAX_MIXERLEVEL;
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
	u32 b   = 0;
	jc_* jc = ch->_08;
	u32 i;
	dspch_** REF_ch = &ch;
	jc_** REF_jc    = &jc;
	u32 badCompiler[10];
	if (jc == NULL) {
		ch->_0C = NULL;
		ch->_03 = 0;
		KillBrokenLogicalChannels(ch);
		return FALSE;
	}

	if (jc->dspChannel != ch) {
		if (jc->dspChannel && jc->dspChannel->_08 == jc) {
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
			jc->updateCallback(jc, JCSTAT_Unk1);
		} else {
			StopLogicalChannel(jc);
			if (List_CutChannel(jc) != -1) {
				List_AddChannel(&jc->mMgr->freeChannels, jc);
			}
		}
		return FALSE;
	}

	if (jc->waveData && !*jc->waveData->fileLoadStatus) {
		ForceStopDSPchannel(jc->dspChannel);
		return -1;
	}

	if (a == 4) {
		u8 prio = jc->channelPriority >> 16;
		if (jc->dspChannel && prio < jc->dspChannel->_03) {
			jc->dspChannel->_03 = prio;
		}
		return FALSE;
	}

	if (a == 3) {
		jc->mOscBuffers[0].state = 6;
		if (List_CutChannel(jc) == -1) {
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

		for (i = 0; i < 4; i++) {
			u32* REF_i = &i;
			if (jc->mOscillators[i]) {
				DoEffectOsc(jc, jc->mOscillators[i]->mode, Bank_OscToOfs(jc->mOscillators[i], &jc->mOscBuffers[i]));
				if (jc->mOscBuffers[i].state == 0) {
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
						jc->updateCallback(jc, JCSTAT_Unk2);
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

		if (jc->extraUpdateCallback && (u32)jc->extraUpdateCallback(jc, JCSTAT_Unk0) == TRUE) {
			jc->toFlush++;
		}

		if (jc->updateCallback == NULL) {
			return TRUE;
		}

		if (jc->savedPlayId > 0) {
			jc->savedPlayId--;
		}
	}

	if (jc->savedPlayId == 0) {
		jc->updateCallback(jc, JCSTAT_Unk0);
		jc->savedPlayId = jc->playId;
	}

	if (jc->toFlush) {
		UpdateJcToDSP(jc);
		jc->toFlush = 0;
	}

	return TRUE;
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
		MixConfig bus = jc->busRouting[i];
		if (JAC_SYSTEM_OUTPUT_MODE == 0) {
			switch (bus.parts.upper) {
			case 8:
				bus.parts.upper = 11;
				break;
			case 9:
				bus.parts.upper = 2;
				break;
			}
		}
		DSP_SetBusConnect(jc->dspChannel->buffer_idx, i, bus.parts.upper);
	}

	jc->lastManager = jc->mMgr;
	UpdateEffecterParam(jc);
	__UpdateJcToDSP(jc);
	jc->dspChannel->_03 = jc->channelPriority;
	jc->dspChannel->_04 = jc->releaseTime;
	DSP_PlayStart(jc->dspChannel->buffer_idx);
	DSP_FlushChannel(jc->dspChannel->buffer_idx);
	return TRUE;
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
	u32 badCompiler[2];

	while (cur_waits != 0) {
		jc = waitp[cur_top];
		if (jc) {
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
				break;
			}
		} else {
			cur_top++;
			if (cur_top == 0x20) {
				cur_top = 0;
			}
			cur_waits--;
		}
	}
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
				jc->updateCallback(jc, JCSTAT_Unk6);
				waitp[(cur_top + i) & 0x1f] = NULL;
			}
		}
	}

	u32 badcompiler[2];
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
