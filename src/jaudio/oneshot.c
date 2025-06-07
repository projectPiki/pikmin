#include "jaudio/oneshot.h"
#include "jaudio/bankdrv.h"
#include "jaudio/audiostruct.h"
#include "jaudio/driverinterface.h"
#include "jaudio/tables.h"
#include "jaudio/bankread.h"
#include "jaudio/waveread.h"
#include "jaudio/connect.h"
#include "jaudio/dspdriver.h"
#include "jaudio/rate.h"
#include "jaudio/bx.h"

static int Jesus1Shot_Update(jc_*, JCSTATUS);

Osc_ PERC_ENV    = { 0, 1.0f, 0, 0, 1.0f, 0 };
Osc_ OSC_ENV     = { 0, 1.0f, 0, 0, 1.0f, 0 };
u8 polys_table[] = { 0, 1, 2, 3, 4, 5, 6, 8, 10, 12, 14, 16, 20, 24, 28, 32 };

/*
 * --INFO--
 * Address:	80015140
 * Size:	000034
 */
static u8 __GetTrigger(jc_* jc, u8 n)
{
	switch (n) {
	case 1:
		return jc->velocity;
	case 2:
		return jc->note;
	}

	return 0;
}

/*
 * --INFO--
 * Address:	80015180
 * Size:	000028
 */
static f32 __Clamp01(f32 val)
{
	if (val < 0.0f) {
		return 0.0f;
	}
	if (val > 1.0f) {
		return 1.0f;
	}
	return val;
}

/*
 * --INFO--
 * Address:	800151C0
 * Size:	000054
 */
static void __Clamp01InitPan(jc_* jc)
{
	for (u32 i = 1; i < 3; i++) {
		jc->panMatrices[i].values[0] = __Clamp01(jc->panMatrices[i].values[0]);
	}
}

/*
 * --INFO--
 * Address:	80015220
 * Size:	000068
 */
static void __DoEffect(jc_* jc, u8 id, f32 val)
{
	switch (id) {
	case 1:
		jc->currentPitch *= val;
		break;
	case 0:
		jc->currentVolume *= val;
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
 * Address:	800152A0
 * Size:	000138
 */
static void EffecterInit(jc_* jc, Inst_* inst)
{
	jc->pitchModifier            = 1.0f;
	jc->volumeModifier           = 1.0f;
	jc->panMatrices[1].values[1] = 0.5f;
	jc->panMatrices[2].values[1] = 0.0f;
	jc->panMatrices[3].values[1] = 0.0f;

	u32 badCompiler[2];
	for (u32 i = 0; i < 2; i++) {
		if (inst->mSensors[i]) {
			u8 trigger     = __GetTrigger(jc, inst->mSensors[i]->type);
			f32 sense      = Bank_SenseToOfs(inst->mSensors[i], trigger);
			f32* REF_sense = &sense;
			__DoEffect(jc, inst->mSensors[i]->id, sense);
		}

		if (inst->mEffects[i]) {
			f32 r = Bank_RandToOfs(inst->mEffects[i]);
			__DoEffect(jc, inst->mEffects[i]->id, r);
		}

		if (inst->mOscillators[i]) {
			jc->mOscBuffers[i].state = 1;
			jc->mOscillators[i]      = inst->mOscillators[i];
			f32 ofs                  = Bank_OscToOfs(jc->mOscillators[i], &jc->mOscBuffers[i]);
			DoEffectOsc(jc, jc->mOscillators[i]->mode, ofs);
		} else {
			jc->mOscillators[i] = NULL;
		}
	}

	u32 badCompiler2[2];
	__Clamp01InitPan(jc);
}

/*
 * --INFO--
 * Address:	800153E0
 * Size:	0000D0
 */
static void EffecterInit_Perc(jc_* jc, Pmap_* pmap, u16 id)
{
	jc->pitchModifier            = 1.0f;
	jc->volumeModifier           = 1.0f;
	jc->panMatrices[1].values[1] = 0.5f;
	jc->panMatrices[2].values[1] = 0.0f;
	jc->panMatrices[3].values[1] = 0.0f;

	// PERC instruments only have rand and not osc
	for (u32 i = 0; i < 2; i++) {
		Pmap_* map = (Pmap_*)((int*)pmap + i + 2);
		if (map->_00) {
			f32 r      = Bank_RandToOfs(map->_00);
			f32* REF_r = &r;
			__DoEffect(jc, map->_00->id, r);
		}

		jc->mOscillators[i] = NULL;
	}
	jc->mOscillators[0]      = &PERC_ENV;
	jc->mOscBuffers[0].state = TRUE;
	Bank_OscToOfs(jc->mOscillators[0], &jc->mOscBuffers[0]);
	jc->mOscBuffers[0].releaseParam = id;
	__Clamp01InitPan(jc);
}

/*
 * --INFO--
 * Address:	800154C0
 * Size:	00007C
 */
static void EffecterInit_Osc(jc_* jc)
{
	jc->pitchModifier            = 1.0f;
	jc->volumeModifier           = 1.0f;
	jc->panMatrices[1].values[1] = 0.5f;
	jc->panMatrices[2].values[1] = 0.0f;
	jc->panMatrices[3].values[1] = 0.0f;

	for (u32 i = 0; i < 2; i++) {
		jc->mOscillators[i] = NULL;
	}

	jc->mOscillators[0]      = &OSC_ENV;
	jc->mOscBuffers[0].state = TRUE;
	Bank_OscToOfs(jc->mOscillators[0], &jc->mOscBuffers[0]);
}

/*
 * --INFO--
 * Address:	80015540
 * Size:	00006C
 */
void Effecter_Overwrite_1ShotD(jc_* jc, Osc_* osc, u32 id)
{
	if (id < 4) {
		jc->mOscBuffers[id].state = TRUE;
		jc->mOscillators[id]      = osc;
		DoEffectOsc(jc, jc->mOscillators[id]->mode, Bank_OscToOfs(jc->mOscillators[id], &jc->mOscBuffers[id]));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void Effecter_Overwrite_1Shot(jc_* jc, Osc_* osc1, Osc_* osc2)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800155C0
 * Size:	00010C
 */
static jc_* __Oneshot_Play_Start(jcs_* jcs, jc_* jc, u32 id)
{
	BOOL play;

	if (id == 0) {
		id = -1;
	}
	jc->playId         = id;
	jc->savedPlayId    = jc->playId;
	jc->updateCallback = Jesus1Shot_Update;
	jc->dspChannel     = AllocDSPchannel(0, (u32)jc);

	if (jc->dspChannel == NULL) {
		play = CheckLogicalChannel(jc);
	} else {
		play = PlayLogicalChannel(jc);
	}

	if (jc->dspChannel == NULL && play == TRUE) {
		if (Add_WaitDSPChannel(jc) == TRUE) {
			List_AddChannelTail(&jcs->waitingChannels, jc);
			return jc;
		} else {
			List_AddChannelTail(&jcs->freeChannels, jc);
			return NULL;
		}
	} else if (play == FALSE) {
		DeAllocDSPchannel(jc->dspChannel, (u32)jc);
		jc->dspChannel = NULL;
		List_AddChannelTail(&jcs->freeChannels, jc);
		return NULL;
	} else {
		List_AddChannelTail(&jcs->activeChannels, jc);
	}
	return jc;
}

/*
 * --INFO--
 * Address:	800156E0
 * Size:	000154
 */
static jc_* __Oneshot_GetLogicalChannel(jcs_* jcs, CtrlWave_* wave)
{
	if (wave && wave->_0C == NULL) {
		return FALSE;
	}

	jc_* chan = List_GetChannel(&jcs->freeChannels);
	jc_* chan2;
	jc_** REF_chan2 = &chan2;
	u32 badCompiler[6];
	if (chan == NULL) {

		if (FixAllocChannel(jcs, 1) == FALSE) {
			return 0;
		}
		jcs->chanAllocCount++;
		chan = List_GetChannel(&jcs->freeChannels);
		if (chan == NULL) {
			return 0;
		}

		if (jcs->voiceStealingMode == 1) {
			chan2 = List_GetChannel(&jcs->releasingChannels);
			if (chan2 == NULL) {
				chan2 = List_GetChannel(&jcs->activeChannels);
				if (chan2) {
					List_CountChannel(&jcs->waitingChannels);
				}
			}

			if (chan2) {
				chan2->mOscBuffers[0].state = 6;
				List_AddChannel(&jcs->waitingChannels, chan2);
				if (chan2->dspChannel) {
					ForceStopDSPchannel(chan2->dspChannel);
				}
			}
		}
	}
	Channel_Init(chan);
	if (wave) {
		chan->waveData        = (Wave_*)wave->_34;
		chan->_14             = wave->_0C;
		chan->logicalChanType = 0;
	}
	chan->_18 = 0;
	UpdatePanPower_1Shot(chan, 1.0f, 1.0f, 1.0f, 1.0f);
	return chan;
}

/*
 * --INFO--
 * Address:	80015840
 * Size:	000044
 */
Perc_* PercRead(u32 a1, u32 a2)
{
	Bank_* bank = Bank_Get(a1);
	if (bank == NULL) {
		return NULL;
	}

	return Bank_PercChange(bank, a2);
}

/*
 * --INFO--
 * Address:	800158A0
 * Size:	000044
 */
Inst_* InstRead(u32 a1, u32 a2)
{

	Bank_* bank = Bank_Get(a1);
	if (bank == NULL) {
		return NULL;
	}

	return Bank_InstChange(bank, a2);
}

/*
 * --INFO--
 * Address:	80015900
 * Size:	00002C
 */
Vmap_* VmapRead(Inst_* inst, u8 a1, u8 a2)
{
	Vmap_* map = (Vmap_*)Bank_GetInstVmap(inst, a1, a2);
	return !map ? NULL : map;
}

/*
 * --INFO--
 * Address:	80015940
 * Size:	000010
 */
static void __Oneshot_WavePause(jc_* jc, u8 a)
{
	jc->pauseFlag = a;
	jc->toFlush   = 1;
}

/*
 * --INFO--
 * Address:	80015960
 * Size:	00014C
 */
static BOOL __Oneshot_StartMonoPolyCheck(jc_* jc, u32 id)
{
	u32 index = 0;
	jcs_* mgr;
	jc_* chan;
	u8 poly;
	int flag1, flag2;

	mgr  = jc->mMgr;
	chan = mgr->activeChannels;
	poly = polys_table[id >> 0x18 & 0xf];

	if (poly == 0) {
		return TRUE;
	}

	flag1 = id >> 0x18 & 0x20;
	flag2 = id >> 0x18 & 0x10;

	while (TRUE) {
		if (chan == NULL) {
			break;
		}

		if (chan->soundId != id) {
			index++;
		} else {
			chan->polyphonyCounter++;
			if (chan->polyphonyCounter == poly) {
				if (flag2) {
					ForceStopLogicalChannel(chan);
				} else {
					__Oneshot_WavePause(chan, 1);
				}
			}
		}
		chan = (jc_*)chan->mNext;
	}

	chan = mgr->releasingChannels;
	while (TRUE) {
		if (chan == NULL) {
			break;
		}

		if (chan->soundId != id) {
			index++;
		} else {
			if (flag1 == 0) {
				chan->polyphonyCounter++;
				if (chan->polyphonyCounter == poly) {
					ForceStopLogicalChannel(chan);
				}
			}
		}
		chan = (jc_*)chan->mNext;
	}

	if (flag1) {
		jc->polyphonyCounter = index;
		if (index < poly) {
			return TRUE;
		}
		return FALSE;
	}

	jc->polyphonyCounter = 0;
	return TRUE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r24, 0x10(r1)
	  addi      r30, r4, 0
	  lis       r4, 0x8022
	  addi      r29, r3, 0
	  addi      r0, r4, 0x5940
	  rlwinm    r5,r30,8,24,31
	  li        r31, 0
	  lwz       r27, 0x4(r3)
	  rlwinm    r3,r30,8,28,31
	  add       r3, r0, r3
	  lbz       r26, 0x0(r3)
	  lwz       r24, 0xC(r27)
	  cmplwi    r26, 0
	  bne-      .loc_0x4C
	  li        r3, 0x1
	  b         .loc_0x138

	.loc_0x4C:
	  rlwinm    r25,r5,0,26,26
	  rlwinm    r28,r5,0,27,27

	.loc_0x54:
	  cmplwi    r24, 0
	  beq-      .loc_0xB8
	  lwz       r0, 0x128(r24)
	  cmplw     r0, r30
	  bne-      .loc_0xB0
	  cmpwi     r25, 0
	  beq-      .loc_0x78
	  addi      r31, r31, 0x1
	  b         .loc_0xB0

	.loc_0x78:
	  lbz       r3, 0x12C(r24)
	  addi      r0, r3, 0x1
	  stb       r0, 0x12C(r24)
	  lbz       r0, 0x12C(r24)
	  cmplw     r0, r26
	  bne-      .loc_0xB0
	  cmpwi     r28, 0
	  beq-      .loc_0xA4
	  mr        r3, r24
	  bl        -0xAD3C
	  b         .loc_0xB0

	.loc_0xA4:
	  addi      r3, r24, 0
	  li        r4, 0x1
	  bl        -0xCC

	.loc_0xB0:
	  lwz       r24, 0x24(r24)
	  b         .loc_0x54

	.loc_0xB8:
	  lwz       r27, 0x10(r27)

	.loc_0xBC:
	  cmplwi    r27, 0
	  beq-      .loc_0x108
	  lwz       r0, 0x128(r27)
	  cmplw     r0, r30
	  bne-      .loc_0x100
	  cmpwi     r25, 0
	  beq-      .loc_0xE0
	  addi      r31, r31, 0x1
	  b         .loc_0x100

	.loc_0xE0:
	  lbz       r3, 0x12C(r27)
	  addi      r0, r3, 0x1
	  stb       r0, 0x12C(r27)
	  lbz       r0, 0x12C(r27)
	  cmplw     r0, r26
	  bne-      .loc_0x100
	  mr        r3, r27
	  bl        -0xAD9C

	.loc_0x100:
	  lwz       r27, 0x24(r27)
	  b         .loc_0xBC

	.loc_0x108:
	  cmpwi     r25, 0
	  beq-      .loc_0x12C
	  cmplw     r31, r26
	  stb       r31, 0x12C(r29)
	  bge-      .loc_0x124
	  li        r3, 0x1
	  b         .loc_0x138

	.loc_0x124:
	  li        r3, 0
	  b         .loc_0x138

	.loc_0x12C:
	  li        r0, 0
	  li        r3, 0x1
	  stb       r0, 0x12C(r29)

	.loc_0x138:
	  lmw       r24, 0x10(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015AC0
 * Size:	0000E8
 */
static void __Oneshot_StopMonoPolyCheck(jc_* jc, u32 id)
{
	jc_* chan;
	u8 poly;

	chan = jc->mMgr->activeChannels;
	poly = polys_table[id >> 0x18 & 0xf];

	if (id && poly) {

		while (TRUE) {
			if (chan == NULL) {
				break;
			}

			int flag = id >> 0x18 & 0x20;
			if (chan->soundId == id) {
				if (flag) {
					if (chan->polyphonyCounter > jc->polyphonyCounter) {
						chan->polyphonyCounter--;
						if (chan->polyphonyCounter == poly - 1) {
							__Oneshot_WavePause(chan, 0);
						}
					}
				} else {
					if (chan->polyphonyCounter > jc->polyphonyCounter) {
						chan->polyphonyCounter--;
						if (chan->polyphonyCounter < poly) {
							__Oneshot_WavePause(chan, 0);
						}
					}
				}
			}

			chan = (jc_*)chan->mNext;
		}
	}

	u32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	80015BC0
 * Size:	000070
 */
void Init_1shot(jcs_* jcs, u32 id)
{
	if (jcs->chanCount != 0) {
		FixReleaseChannelAll(jcs);
	}
	InitJcs(jcs);
	FixAllocChannel(jcs, id);
	if (id == 0) {
		jcs->voiceStealingMode = 0;
	} else {
		jcs->voiceStealingMode = 1;
	}

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	80015C40
 * Size:	00003C
 */
void Stop_1Shot(jc_* jc)
{
	if (jc->dspChannel == 0) {
		Jesus1Shot_Update(jc, (JCSTATUS)6);
	} else {
		Jesus1Shot_Update(jc, (JCSTATUS)0);
	}
}

/*
 * --INFO--
 * Address:	80015C80
 * Size:	000040
 */
void Stop_1Shot_R(jc_* jc, u16 id)
{
	if (jc->dspChannel == 0) {
		Jesus1Shot_Update(jc, (JCSTATUS)6);
	} else {
		jc->mOscBuffers[0].releaseParam = id;
		Jesus1Shot_Update(jc, (JCSTATUS)0);
	}
}

/*
 * --INFO--
 * Address:	80015CC0
 * Size:	00006C
 */
void AllStop_1Shot(jcs_* jcs)
{
	List_CountChannel(&jcs->freeChannels);
	List_CountChannel(&jcs->activeChannels);
	List_CountChannel(&jcs->releasingChannels);
	List_CountChannel(&jcs->waitingChannels);

	jc_* jc = jcs->activeChannels;
	jc_* next;
	jc_** REF_jc = &jc;
	u32 badCompiler[4];
	while (jc) {
		next = (jc_*)jc->mNext;
		Stop_1Shot(jc);
		jc = next;
	}
}

/*
 * --INFO--
 * Address:	80015D40
 * Size:	00006C
 */
static int Extra_Update(jc_* jc, JCSTATUS status)
{
	if (jc->pitchSlideCounter) {
		f32 a = jc->targetPitch - jc->currentPitch;
		a /= jc->pitchSlideCounter;
		jc->currentPitch += a;
		jc->pitchSlideCounter--;

		if (jc->pitchSlideCounter == 0) {
			jc->extraUpdateCallback = NULL;
		}
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80015DC0
 * Size:	000030
 */
void SetPitchTarget_1Shot(jc_* jc, f32 a1, u32 a2)
{
	if (a2 == 0) {
		jc->currentPitch        = a1;
		jc->extraUpdateCallback = NULL;
		return;
	}

	jc->targetPitch         = a1;
	jc->pitchSlideCounter   = a2;
	jc->extraUpdateCallback = Extra_Update;
}

/*
 * --INFO--
 * Address:	80015E00
 * Size:	000090
 */
void SetKeyTarget_1Shot(jc_* jc, u8 a1, u32 a2)
{
	int id;
	if (jc == 0) {
		return;
	}

	if (jc->logicalChanType == 2 || jc->waveData == NULL) {
		id = a1;
	} else {
		id = (a1 + 60) - jc->waveData->_02;
	}

	if (id < 0) {
		id = 0;
	}
	if (id > 0x7f) {
		id = 0x7f;
	}

	f32 pitch = C5BASE_PITCHTABLE[id];
	SetPitchTarget_1Shot(jc, jc->basePitch * pitch, a2);
}

/*
 * --INFO--
 * Address:	80015EA0
 * Size:	0000C8
 */
void Gate_1Shot(jc_* jc, u8 a1, u8 a2, s32 a3)
{
	u32 badCompiler[2];
	if (jc->playId == -1) {
		jc->playId      = a3;
		jc->savedPlayId = jc->playId;
		int idx;
		if (jc->logicalChanType == 2) {
			idx = a1;
		} else {
			idx = (a1 + 60) - jc->waveData->_02;
		}
		if (idx < 0) {
			idx = 0;
		}
		if (idx > 0x7f) {
			idx = 0x7f;
		}

		f32 pitch         = C5BASE_PITCHTABLE[idx];
		jc->velocity      = a2;
		jc->note          = a1;
		jc->currentPitch  = jc->basePitch * pitch;
		jc->currentVolume = jc->velocity / 127.0f;
		jc->currentVolume = jc->currentVolume * jc->currentVolume * jc->baseVolume;
	}
}

/*
 * --INFO--
 * Address:	80015F80
 * Size:	000008
 */
void UpdatePause_1Shot(jc_* jc, u8 a1)
{
	jc->pauseFlag = a1;
}

/*
 * --INFO--
 * Address:	80015FA0
 * Size:	000030
 */
void UpdatePanPower_1Shot(jc_* channel, f32 leftPower, f32 rightPower, f32 centerPower, f32 v4)
{
	f32 val = leftPower + rightPower + centerPower;
	if (val == 0.0f) {
		return;
	}

	channel->panMatrices[0].values[0] = leftPower / val;
	channel->panMatrices[0].values[1] = rightPower / val;
	channel->panMatrices[0].values[2] = centerPower / val;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void CountChan(jc_* jc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void CountChanD(jc_* jc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void CheckChan(jc_* jc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void PrintChan(char* str, jc_* jc, u32 id)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80015FE0
 * Size:	0000B0
 */
void FlushRelease_1Shot(jcs_* jcs)
{
	int count = List_CountChannel(&jcs->releasingChannels);

	for (u32 i = 0; i < count; i++) {
		jc_* chan = List_GetChannel(&jcs->releasingChannels);
		if (chan == NULL) {
			break;
		}

		for (int j = 0; j < 2; j++) {
			if (chan->mOscillators[j]) {
				if (chan->mOscBuffers[j].state != 6 && chan->mOscBuffers[j].state != 7) {
					chan->mOscBuffers[j].state = 6;
				}
			}
		}

		List_AddChannelTail(&jcs->releasingChannels, chan);
	}
}

/*
 * --INFO--
 * Address:	800160A0
 * Size:	0001C4
 */
static int Jesus1Shot_Update(jc_* jc, JCSTATUS jstatus)
{
	u32 test = FALSE;
	// jc_** jcptr = &jc;
	jcs_** chan = &jc->mMgr;
	s32 status  = jstatus;

	if (status == 0) {
		for (u32 i = 0; i < 2; i++) {
			if (jc->mOscillators[i]) {
				Oscbuf_* buf = &jc->mOscBuffers[i];
				if (buf->state != 6 && buf->state != 7) {
					buf->state = 4;
					test       = TRUE;
				}
			}
		}

		if (test && List_CutChannel(jc) != -1) {
			List_AddChannelTail(&jc->mMgr->releasingChannels, jc);
			if (jc->dspChannel) {
				u32 test2 = jc->channelPriority >> 8;
				u8 a      = test2;
				if (a == 0) {
					test2 = TRUE;
				}
				jc->dspChannel->_03 = test2;
			}
		}
		jc->playId = -1;
		return FALSE;
	} else if (status == 1 || status == 2 || status == 6) {
		if (jc->mMgr->chanAllocCount) {
			if (List_CutChannel(jc) != -1) {
				(*chan)->chanAllocCount--;
				int id      = jc->soundId;
				jc->soundId = 0;
				__Oneshot_StopMonoPolyCheck(jc, id);
				FixReleaseChannel(jc);
			}
		} else {
			if (List_CutChannel(jc) != -1) {
				int id      = jc->soundId;
				jc->soundId = 0;
				__Oneshot_StopMonoPolyCheck(jc, id);
				List_AddChannel(&(*chan)->freeChannels, jc);
			}
		}
		if (status != 6) {
			StopLogicalChannel(jc);
		} else {
			Del_WaitDSPChannel(jc);
		}
		jc->note           = -1;
		jc->playId         = -1;
		jc->updateCallback = NULL;
	}
	return 0;
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r29, 0x2C(r1)
	  mr.       r29, r4
	  stw       r3, 0x8(r1)
	  bne-      .loc_0xD8
	  li        r0, 0x2
	  lwz       r31, 0x8(r1)
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x4
	  mtctr     r0

	.loc_0x38:
	  addi      r0, r4, 0x38
	  lwzx      r0, r31, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  addi      r6, r3, 0x48
	  add       r6, r31, r6
	  lbz       r0, 0x0(r6)
	  cmplwi    r0, 0x6
	  beq-      .loc_0x6C
	  cmplwi    r0, 0x7
	  beq-      .loc_0x6C
	  stb       r5, 0x0(r6)
	  li        r7, 0x1

	.loc_0x6C:
	  addi      r3, r3, 0x18
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x38
	  cmplwi    r7, 0
	  beq-      .loc_0xC8
	  mr        r3, r31
	  bl        -0xCCA4
	  cmpwi     r3, -0x1
	  beq-      .loc_0xC8
	  lwz       r3, 0x4(r31)
	  addi      r4, r31, 0
	  addi      r3, r3, 0x10
	  bl        -0xCBFC
	  lwz       r3, 0x20(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xC8
	  lwz       r0, 0x120(r31)
	  rlwinm    r0,r0,24,24,31
	  mr        r4, r0
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xC4
	  li        r4, 0x1

	.loc_0xC4:
	  stb       r4, 0x3(r3)

	.loc_0xC8:
	  li        r0, -0x1
	  li        r3, 0
	  stw       r0, 0x30(r31)
	  b         .loc_0x1B0

	.loc_0xD8:
	  subi      r0, r29, 0x1
	  cmplwi    r0, 0x1
	  ble-      .loc_0xEC
	  cmpwi     r29, 0x6
	  bne-      .loc_0x1AC

	.loc_0xEC:
	  lwz       r31, 0x8(r1)
	  addi      r30, r31, 0x4
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x144
	  mr        r3, r31
	  bl        -0xCD28
	  cmpwi     r3, -0x1
	  beq-      .loc_0x178
	  lwz       r5, 0x0(r30)
	  li        r0, 0
	  addi      r3, r31, 0
	  lwz       r4, 0x4(r5)
	  subi      r4, r4, 0x1
	  stw       r4, 0x4(r5)
	  lwz       r4, 0x128(r31)
	  stw       r0, 0x128(r31)
	  bl        -0x714
	  mr        r3, r31
	  bl        -0xCB7C
	  b         .loc_0x178

	.loc_0x144:
	  mr        r3, r31
	  bl        -0xCD68
	  cmpwi     r3, -0x1
	  beq-      .loc_0x178
	  lwz       r4, 0x128(r31)
	  li        r0, 0
	  mr        r3, r31
	  stw       r0, 0x128(r31)
	  bl        -0x744
	  lwz       r3, 0x0(r30)
	  addi      r4, r31, 0
	  addi      r3, r3, 0x8
	  bl        -0xCC74

	.loc_0x178:
	  cmpwi     r29, 0x6
	  beq-      .loc_0x18C
	  mr        r3, r31
	  bl        -0xBBA4
	  b         .loc_0x194

	.loc_0x18C:
	  mr        r3, r31
	  bl        -0xB830

	.loc_0x194:
	  li        r0, 0xFF
	  li        r3, -0x1
	  stb       r0, 0x1(r31)
	  li        r0, 0
	  stw       r3, 0x30(r31)
	  stw       r0, 0x28(r31)

	.loc_0x1AC:
	  li        r3, 0

	.loc_0x1B0:
	  lmw       r29, 0x2C(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80016280
 * Size:	000098
 */
u32 One_CheckInstWave(SOUNDID_ sound)
{
	Inst_* inst = InstRead(sound.bytes[0], sound.bytes[1]);
	if (inst == NULL) {
		return 1;
	}

	// TODO: fix this conversion to something wave-related once we've sorted that out
	int* map = (int*)VmapRead(inst, sound.bytes[2], sound.bytes[3]);
	if (map == NULL) {
		return 2;
	}

	// clearly need something better than map[1]
	CtrlGroup_* group = WaveidToWavegroup(map[1], sound.bytes[0]);
	if (group == NULL) {
		return 3;
	}

	WaveID_* handle = GetSoundHandle(group, map[1]);
	if (handle == 0) {
		return 4;
	}

	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void Get_CtrlWave(SOUNDID_ sound)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80016320
 * Size:	00027C
 */
jc_* Play_1shot(jcs_* jcs, SOUNDID_ sound, u32 id)
{
	BOOL test = FALSE;

	Inst_* inst = InstRead(sound.bytes[0], sound.bytes[1]);
	if (inst == NULL) {
		return NULL;
	}

	Vmap_* map = VmapRead(inst, sound.bytes[2], sound.bytes[3]);
	if (map == NULL) {
		return NULL;
	}

	CtrlGroup_* group = WaveidToWavegroup(map->mWsysID, sound.bytes[2]);
	if (group == NULL) {
		return NULL;
	}

	WaveID_* wave = GetSoundHandle(group, map->mWsysID);
	if (wave == NULL) {
		return NULL;
	}

	jc_* chan = __Oneshot_GetLogicalChannel(jcs, (CtrlWave_*)wave);
	if (chan == NULL) {
		return NULL;
	}

	int val = sound.bytes[2] + 60 - wave->data->_02;
	if (val < 0) {
		val = 0;
	}
	if (val > 127) {
		val = 127;
	}
	f32 pitch                      = C5BASE_PITCHTABLE[val];
	chan->velocity                 = sound.bytes[3];
	chan->note                     = sound.bytes[2];
	chan->basePitch                = inst->mGainMultiplier * map->mPitch * wave->data->_04 / JAC_DAC_RATE;
	chan->currentPitch             = chan->basePitch * pitch;
	chan->baseVolume               = map->mVolume * inst->mFreqMultiplier;
	chan->currentVolume            = chan->velocity / 127.0f;
	chan->currentVolume            = chan->baseVolume * chan->currentVolume * chan->currentVolume;
	chan->panMatrices[1].values[0] = 0.5f;
	chan->panMatrices[2].values[0] = 0.0f;
	chan->panMatrices[3].values[0] = 0.0f;
	EffecterInit(chan, inst);

	int f    = sound.bytes[0] >> 0x10;
	int flag = inst->mFlag << 0x18 | f;
	switch (inst->mFlag & 0xc0) {
	case 0xc0:
		flag |= 0xffffff;
		break;
	case 0x80:
		flag |= 0xff;
		break;
	case 0x40:
		flag |= Bank_GetInstKeymap(inst, sound.bytes[2]) << 0x10;
		break;
	}

	chan->soundId = 0;
	if (__Oneshot_StartMonoPolyCheck(chan, flag) == FALSE) {
		if (inst->mFlag & 0x10) {
			List_AddChannelTail(&jcs->freeChannels, chan);
			return FALSE;
		}
		test = TRUE;
	}
	chan->soundId = flag;

	jc_* newjc = __Oneshot_Play_Start(jcs, chan, id);
	if (test) {
		__Oneshot_WavePause(newjc, 1);
	}
	return newjc;

	u32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r24, 0x28(r1)
	  addi      r24, r3, 0
	  addi      r25, r4, 0
	  mr        r26, r5
	  li        r27, 0
	  lbz       r3, 0x0(r4)
	  lbz       r4, 0x1(r4)
	  bl        -0xAA8
	  mr.       r29, r3
	  bne-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x268

	.loc_0x3C:
	  lbz       r4, 0x2(r25)
	  mr        r3, r29
	  lbz       r5, 0x3(r25)
	  bl        -0xA68
	  mr.       r31, r3
	  bne-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x268

	.loc_0x5C:
	  lwz       r3, 0x4(r31)
	  lbz       r4, 0x0(r25)
	  bl        -0x9DC4
	  cmplwi    r3, 0
	  bne-      .loc_0x78
	  li        r3, 0
	  b         .loc_0x268

	.loc_0x78:
	  lwz       r4, 0x4(r31)
	  bl        -0x959C
	  mr.       r28, r3
	  bne-      .loc_0x90
	  li        r3, 0
	  b         .loc_0x268

	.loc_0x90:
	  addi      r3, r24, 0
	  addi      r4, r28, 0
	  bl        -0xCD8
	  mr.       r30, r3
	  bne-      .loc_0xAC
	  li        r3, 0
	  b         .loc_0x268

	.loc_0xAC:
	  lwz       r4, 0x34(r28)
	  lbz       r3, 0x2(r25)
	  lbz       r4, 0x2(r4)
	  addi      r0, r3, 0x3C
	  sub.      r0, r0, r4
	  bge-      .loc_0xC8
	  li        r0, 0

	.loc_0xC8:
	  cmpwi     r0, 0x7F
	  ble-      .loc_0xD4
	  li        r0, 0x7F

	.loc_0xD4:
	  lis       r3, 0x8022
	  rlwinm    r4,r0,2,0,29
	  addi      r0, r3, 0x4E18
	  lbz       r5, 0x3(r25)
	  add       r3, r0, r4
	  lis       r0, 0x4330
	  lfs       f3, 0x0(r3)
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  stb       r5, 0x0(r30)
	  lbz       r5, 0x2(r25)
	  stb       r5, 0x1(r30)
	  lwz       r5, 0x34(r28)
	  lfs       f0, -0x8000(r13)
	  lfs       f1, 0x4(r5)
	  lfs       f2, 0xC(r31)
	  fdivs     f0, f1, f0
	  lfs       f1, 0xC(r29)
	  fmuls     f0, f2, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0xA8(r30)
	  fmuls     f0, f0, f3
	  stfs      f0, 0xB0(r30)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x8(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xAC(r30)
	  lbz       r5, 0x0(r30)
	  lfd       f2, -0x7E98(r2)
	  stw       r5, 0x24(r1)
	  lfs       f0, -0x7E90(r2)
	  stw       r0, 0x20(r1)
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  stfs      f0, 0xB4(r30)
	  lfs       f0, 0xB4(r30)
	  lfs       f1, 0xAC(r30)
	  fmuls     f0, f0, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB4(r30)
	  lfs       f0, -0x7EA0(r2)
	  stfs      f0, 0xC8(r30)
	  lfs       f0, -0x7EA8(r2)
	  stfs      f0, 0xD4(r30)
	  stfs      f0, 0xE0(r30)
	  bl        -0x1210
	  lwz       r4, 0x4(r29)
	  lwz       r3, 0x0(r25)
	  rlwinm    r0,r4,0,24,25
	  cmpwi     r0, 0x80
	  rlwinm    r3,r3,16,16,31
	  addi      r28, r3, 0
	  rlwimi    r28,r4,24,0,7
	  beq-      .loc_0x1DC
	  bge-      .loc_0x1C4
	  cmpwi     r0, 0x40
	  beq-      .loc_0x1E4
	  b         .loc_0x1F8

	.loc_0x1C4:
	  cmpwi     r0, 0xC0
	  beq-      .loc_0x1D0
	  b         .loc_0x1F8

	.loc_0x1D0:
	  oris      r28, r28, 0xFF
	  ori       r28, r28, 0xFFFF
	  b         .loc_0x1F8

	.loc_0x1DC:
	  ori       r28, r28, 0xFF
	  b         .loc_0x1F8

	.loc_0x1E4:
	  mr        r3, r29
	  lbz       r4, 0x2(r25)
	  bl        -0x94CC
	  rlwinm    r0,r3,16,0,15
	  or        r28, r28, r0

	.loc_0x1F8:
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r0, 0x128(r30)
	  mr        r4, r28
	  bl        -0xBC8
	  cmpwi     r3, 0
	  bne-      .loc_0x238
	  lwz       r0, 0x4(r29)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x234
	  addi      r3, r24, 0x8
	  addi      r4, r30, 0
	  bl        -0xD008
	  li        r3, 0
	  b         .loc_0x268

	.loc_0x234:
	  li        r27, 0x1

	.loc_0x238:
	  stw       r28, 0x128(r30)
	  addi      r3, r24, 0
	  addi      r4, r30, 0
	  addi      r5, r26, 0
	  bl        -0xFA8
	  cmpwi     r27, 0
	  addi      r24, r3, 0
	  beq-      .loc_0x264
	  addi      r3, r24, 0
	  li        r4, 0x1
	  bl        -0xC40

	.loc_0x264:
	  mr        r3, r24

	.loc_0x268:
	  lmw       r24, 0x28(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800165A0
 * Size:	00020C
 */
jc_* Play_1shot_Perc(jcs_* jcs, SOUNDID_ sound, u32 id)
{
	Perc_* perc = PercRead(sound.bytes[0], sound.bytes[1]);
	if (perc == NULL) {
		return NULL;
	}

	Vmap_* map = Bank_GetPercVmap(perc, sound.bytes[2], sound.bytes[3]);
	if (map == NULL) {
		return NULL;
	}

	CtrlGroup_* group = WaveidToWavegroup(map->mWsysID, sound.bytes[2]);
	if (group == NULL) {
		return NULL;
	}

	WaveID_* wave = GetSoundHandle(group, map->mWsysID);
	if (wave == NULL) {
		return NULL;
	}

	jc_* chan = __Oneshot_GetLogicalChannel(jcs, (CtrlWave_*)wave);
	if (chan == NULL) {
		return NULL;
	}

	chan->velocity                 = sound.bytes[3];
	chan->note                     = sound.bytes[2];
	chan->basePitch                = perc->mKeyRegions[sound.bytes[2]]->mPitch * map->mPitch * wave->data->_04 / JAC_DAC_RATE;
	chan->currentPitch             = chan->basePitch;
	chan->baseVolume               = map->mVolume * perc->mKeyRegions[sound.bytes[2]]->mVolume;
	chan->currentVolume            = chan->velocity / 127.0f;
	chan->currentVolume            = chan->baseVolume * chan->currentVolume * chan->currentVolume;
	chan->panMatrices[1].values[0] = 0.5f;
	chan->panMatrices[2].values[0] = 0.0f;
	chan->panMatrices[3].values[0] = 0.0f;

	u16 flag;
	if (perc->mMagic == 'PER2') {
		chan->panMatrices[0].values[0] = perc->mKeyRegions[sound.bytes[2]]->mPitch / 127.0f;
		flag                           = perc->mKeyRegions[sound.bytes[2]]->mVelocityCount;
	} else {
		flag                           = 1000;
		chan->panMatrices[0].values[0] = 0.5f;
	}
	chan->panMatrices[2].values[0] = 0.0f;
	chan->panMatrices[3].values[0] = 0.0f;
	EffecterInit_Perc(chan, (Pmap_*)perc->mKeyRegions[sound.bytes[2]], flag);
	chan->soundId = 0;

	return __Oneshot_Play_Start(jcs, chan, id);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stmw      r26, 0x58(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  stw       r5, 0x10(r1)
	  lbz       r3, 0x0(r4)
	  lbz       r4, 0x1(r4)
	  bl        -0xD84
	  mr.       r29, r3
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0x38:
	  lbz       r4, 0x2(r28)
	  mr        r3, r29
	  lbz       r5, 0x3(r28)
	  bl        -0x94A4
	  stw       r3, 0x44(r1)
	  lwz       r31, 0x44(r1)
	  cmplwi    r31, 0
	  bne-      .loc_0x60
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0x60:
	  addi      r30, r31, 0x4
	  lbz       r4, 0x0(r28)
	  lwz       r3, 0x4(r31)
	  bl        -0xA04C
	  cmplwi    r3, 0
	  bne-      .loc_0x80
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0x80:
	  lwz       r4, 0x0(r30)
	  bl        -0x9824
	  mr.       r26, r3
	  bne-      .loc_0x98
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0x98:
	  addi      r3, r27, 0
	  addi      r4, r26, 0
	  bl        -0xF60
	  mr.       r30, r3
	  bne-      .loc_0xB4
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0xB4:
	  lbz       r0, 0x3(r28)
	  lis       r4, 0x4330
	  stb       r0, 0x0(r30)
	  lbz       r0, 0x2(r28)
	  stb       r0, 0x1(r30)
	  lwz       r3, 0x34(r26)
	  lbz       r0, 0x2(r28)
	  lfs       f1, 0x4(r3)
	  lfs       f0, -0x8000(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r29, r0
	  lfs       f2, 0xC(r31)
	  fdivs     f0, f1, f0
	  lwz       r3, 0x88(r3)
	  lfs       f1, 0x4(r3)
	  fmuls     f0, f2, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0xA8(r30)
	  stfs      f0, 0xB0(r30)
	  lbz       r0, 0x2(r28)
	  lfs       f1, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r29, r0
	  lwz       r3, 0x88(r3)
	  lfs       f0, 0x0(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xAC(r30)
	  lbz       r0, 0x0(r30)
	  lfd       f1, -0x7E98(r2)
	  stw       r0, 0x54(r1)
	  lfs       f2, -0x7E90(r2)
	  stw       r4, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f1
	  fdivs     f0, f0, f2
	  stfs      f0, 0xB4(r30)
	  lfs       f0, 0xB4(r30)
	  lfs       f1, 0xAC(r30)
	  fmuls     f0, f0, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB4(r30)
	  lwz       r3, 0x0(r29)
	  subis     r0, r3, 0x5045
	  cmplwi    r0, 0x5232
	  bne-      .loc_0x1B0
	  lbz       r0, 0x2(r28)
	  lfd       f1, -0x7E88(r2)
	  add       r3, r29, r0
	  lbz       r0, 0x288(r3)
	  extsb     r0, r0
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r4, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f1
	  fdivs     f0, f0, f2
	  stfs      f0, 0xC8(r30)
	  lbz       r0, 0x2(r28)
	  rlwinm    r0,r0,1,0,30
	  add       r3, r29, r0
	  lhz       r5, 0x308(r3)
	  b         .loc_0x1BC

	.loc_0x1B0:
	  lfs       f0, -0x7EA0(r2)
	  li        r5, 0x3E8
	  stfs      f0, 0xC8(r30)

	.loc_0x1BC:
	  lfs       f0, -0x7EA8(r2)
	  mr        r3, r30
	  stfs      f0, 0xD4(r30)
	  stfs      f0, 0xE0(r30)
	  lbz       r0, 0x2(r28)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r29, r0
	  lwz       r4, 0x88(r4)
	  bl        -0x139C
	  li        r0, 0
	  addi      r3, r27, 0
	  stw       r0, 0x128(r30)
	  mr        r4, r30
	  lwz       r5, 0x10(r1)
	  bl        -0x11D4

	.loc_0x1F8:
	  lmw       r26, 0x58(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800167C0
 * Size:	000128
 */
jc_* Play_1shot_Osc(jcs_* jcs, SOUNDID_ sound, u32 id)
{
	int pit;
	jc_* chan;

	chan = __Oneshot_GetLogicalChannel(jcs, NULL);
	if (chan == NULL) {
		return NULL;
	}

	chan->_14             = sound.bytes[1] - 0xf0;
	chan->logicalChanType = 2;

	pit = sound.bytes[2];
	if (pit < 0) {
		pit = 0;
	}
	if (pit > 127) {
		pit = 127;
	}
	f32 pitch                      = C5BASE_PITCHTABLE[pit];
	chan->velocity                 = sound.bytes[3];
	chan->note                     = sound.bytes[2];
	chan->basePitch                = 16736.016f / JAC_DAC_RATE;
	chan->currentPitch             = chan->basePitch * pitch;
	chan->baseVolume               = 1.0f;
	chan->currentVolume            = chan->velocity / 127.0f;
	chan->currentVolume            = chan->currentVolume * chan->currentVolume;
	chan->panMatrices[1].values[0] = 0.5f;
	chan->panMatrices[2].values[0] = 0.0f;
	chan->panMatrices[3].values[0] = 0.0f;
	EffecterInit_Osc(chan);
	chan->soundId = 0;
	return __Oneshot_Play_Start(jcs, chan, id);

	u32 badcompiler[6];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r28, 0x38(r1)
	  addi      r28, r4, 0
	  addi      r31, r3, 0
	  addi      r29, r5, 0
	  li        r4, 0
	  bl        -0x1100
	  mr.       r30, r3
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x114

	.loc_0x34:
	  lbz       r3, 0x1(r28)
	  li        r0, 0x2
	  subi      r3, r3, 0xF0
	  stw       r3, 0x14(r30)
	  stb       r0, 0xC(r30)
	  lbz       r0, 0x2(r28)
	  cmpwi     r0, 0
	  bge-      .loc_0x58
	  li        r0, 0

	.loc_0x58:
	  cmpwi     r0, 0x7F
	  ble-      .loc_0x64
	  li        r0, 0x7F

	.loc_0x64:
	  lis       r3, 0x8022
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r3, 0x4E18
	  lbz       r4, 0x3(r28)
	  add       r3, r0, r5
	  lis       r0, 0x4330
	  lfs       f2, 0x0(r3)
	  mr        r3, r30
	  stb       r4, 0x0(r30)
	  lbz       r4, 0x2(r28)
	  stb       r4, 0x1(r30)
	  lfs       f1, -0x7E80(r2)
	  lfs       f0, -0x8000(r13)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0xA8(r30)
	  fmuls     f0, f0, f2
	  stfs      f0, 0xB0(r30)
	  lfs       f0, -0x7EA4(r2)
	  stfs      f0, 0xAC(r30)
	  lbz       r4, 0x0(r30)
	  lfd       f2, -0x7E98(r2)
	  stw       r4, 0x34(r1)
	  lfs       f0, -0x7E90(r2)
	  stw       r0, 0x30(r1)
	  lfd       f1, 0x30(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  stfs      f0, 0xB4(r30)
	  lfs       f0, 0xB4(r30)
	  fmuls     f0, f0, f0
	  stfs      f0, 0xB4(r30)
	  lfs       f0, -0x7EA0(r2)
	  stfs      f0, 0xC8(r30)
	  lfs       f0, -0x7EA8(r2)
	  stfs      f0, 0xD4(r30)
	  stfs      f0, 0xE0(r30)
	  bl        -0x13F8
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x128(r30)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  bl        -0x1310

	.loc_0x114:
	  lmw       r28, 0x38(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}
