#include "jaudio/driverinterface.h"

#include "jaudio/dspinterface.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspdriver.h"

static jcs_ GLOBAL_CHANNEL;
static jc_ CHANNEL[0x100];

static u16 MAX_MIXERLEVEL         = 12000;
static int JAC_SYSTEM_OUTPUT_MODE = 1;

static u32 cur_waits;
static u32 cur_top;
static u32 cur_tail;
static jc_* waitp[0x20];
static int waittime[0x20];

static u8 calc_sw_table[]
    = { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 2, 0, 1, 0, 0, 2, 1, 0, 2, 2, 1, 0, 0, 1, 0, 1, 1, 0, 2, 1, 1, 0, 1, 1,
	    1, 1, 1, 2, 1, 2, 0, 1, 2, 1, 1, 2, 2, 1, 0, 0, 2, 0, 1, 2, 0, 2, 2, 1, 0, 2, 1, 1, 2, 1, 2, 2, 2, 0, 2, 2, 1, 2, 2, 2 };

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
	jc_* chan = (jc_*)*jc->_08;
	int num   = 0;

	if (chan == jc) {
		*jc->_08 = jc->mNext;
		jc->_08  = NULL;
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

	chan->mNext = jc->mNext;
	jc->_08     = NULL;

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

	*jc       = (jc_*)chan->mNext;
	chan->_08 = NULL;
	return chan;
}

/*
 * --INFO--
 * Address:	80009540
 * Size:	000048
 */
void List_AddChannelTail(jc_** jc, jc_* in)
{
	jc_* chan = *jc;
	in->_08   = jc;

	if (chan == NULL) {
		*jc       = in;
		in->mNext = NULL;
		return;
	}

	jc_* temp;
	while (TRUE) {
		chan = (jc_*)chan->mNext;
		if (chan == NULL) {
			temp = chan;
			break;
		}
	}
	temp->mNext = in;
	in->mNext   = NULL;

	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  cmplwi    r5, 0
	  stw       r3, 0x8(r4)
	  bne-      .loc_0x20
	  stw       r4, 0x0(r3)
	  li        r0, 0
	  stw       r0, 0x24(r4)
	  blr

	.loc_0x20:
	  lwz       r0, 0x24(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  stw       r4, 0x24(r5)
	  li        r0, 0
	  stw       r0, 0x24(r4)
	  blr

	.loc_0x3C:
	  mr        r5, r0
	  b         .loc_0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800095A0
 * Size:	000014
 */
void List_AddChannel(jc_** jc, jc_* in)
{
	jc_* chan = *jc;
	in->_08   = jc;
	*jc       = in;
	in->mNext = chan;
}

/*
 * --INFO--
 * Address:	800095C0
 * Size:	00009C
 */
int FixAllocChannel(jcs_* sys, u32 size)
{
	int num = 0;
	while (num < size) {
		jc_* chan = List_GetChannel(&GLOBAL_CHANNEL._08);
		if (chan == NULL) {
			break;
		}

		List_AddChannel(&sys->_08, chan);
		chan->mMgr = sys;
		Channel_Init(chan);
		num++;
	}

	sys->_00 += num;
	GLOBAL_CHANNEL._00 -= num;
	return num;

	f32 badcompiler[4];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r25, 0x1C(r1)
	  li        r26, 0
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802F
	  addi      r31, r3, 0x24E0
	  stw       r4, 0xC(r1)
	  addi      r30, r31, 0x8
	  lwz       r27, 0x8(r1)
	  lwz       r28, 0xC(r1)
	  addi      r29, r27, 0x8
	  b         .loc_0x64

	.loc_0x38:
	  mr        r3, r30
	  bl        -0xFC
	  mr.       r25, r3
	  beq-      .loc_0x6C
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  bl        -0x70
	  stw       r27, 0x4(r25)
	  mr        r3, r25
	  bl        0x444
	  addi      r26, r26, 0x1

	.loc_0x64:
	  cmplw     r26, r28
	  blt+      .loc_0x38

	.loc_0x6C:
	  lwz       r0, 0x0(r27)
	  addi      r3, r26, 0
	  add       r0, r0, r26
	  stw       r0, 0x0(r27)
	  lwz       r0, 0x0(r31)
	  sub       r0, r0, r26
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x3C(r1)
	  lmw       r25, 0x1C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009660
 * Size:	000060
 */
int FixReleaseChannel(jc_* chan)
{
	List_AddChannel(&GLOBAL_CHANNEL._08, chan);
	chan->mMgr->_00--;
	GLOBAL_CHANNEL._00++;
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
		chan = List_GetChannel(&sys->_08);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&GLOBAL_CHANNEL._08, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->_0C);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&GLOBAL_CHANNEL._0C, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->_10);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&GLOBAL_CHANNEL._10, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->_14);
		if (chan == NULL) {
			break;
		}
		Cancel_WaitDSPChannel(chan);
		List_AddChannel(&GLOBAL_CHANNEL._08, chan);
		chan->mMgr = &GLOBAL_CHANNEL;
	}

	GLOBAL_CHANNEL._00 += sys->_00;
	sys->_00 = 0;
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
		chan = List_GetChannel(&sys->_08);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->_08, chan);
		chan->mMgr = sys2;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->_0C);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->_0C, chan);
		chan->mMgr = sys2;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->_10);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->_10, chan);
		chan->mMgr = sys2;
	}

	while (TRUE) {
		chan = List_GetChannel(&sys->_14);
		if (chan == NULL) {
			break;
		}
		List_AddChannel(&sys2->_14, chan);
		chan->mMgr = sys2;
	}

	sys2->_00 += sys->_00;
	sys->_00 = 0;
	sys2->_04 += sys->_04;
	sys->_04 = 0;
	return 0;

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800098C0
 * Size:	000070
 */
f32 PanCalc(const PanMatrix_* mtx1, const PanMatrix_* mtx2, u8 a)
{
	f32 calc = 0.0f;

	u8* vals = calc_sw_table + (a * 3);

	for (int i = 0; i < 3; i++) {
		switch (vals[i]) {
		case 0:
			break;
		case 1:
			calc += mtx1->_00[i];
			break;
		case 2:
			calc += (mtx1->_00[i] * mtx2->_00[i]);
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
	sys->_08 = NULL;
	sys->_0C = NULL;
	sys->_10 = NULL;
	sys->_14 = NULL;
	sys->_04 = 0;
	sys->_00 = 0;
	sys->_70 = 1;
	sys->_18 = 1.0f;
	sys->_1C = 1.0f;
	sys->_20 = 0.5f;
	sys->_24 = 0.0f;
	sys->_28 = 0.0f;

	int i;

	for (i = 0; i < 8; i++) {
		sys->_2C[i] = 0;
	}

	sys->_2C[0] = 0x7fff;
	sys->_4C    = 0;

	for (i = 0; i < 4; i++) {
		sys->_3C[i] = 0;
		sys->_5A[i] = 0;
	}

	sys->_60    = 0;
	sys->_3C[0] = 0x7fff;
	sys->_61    = 0;
	sys->_4E[0] = 0x150;
	sys->_4E[1] = 0x210;
	sys->_4E[2] = 0x352;
	sys->_4E[3] = 0x412;
	sys->_4E[4] = 0;
	sys->_4E[5] = 0;
	sys->_68    = 0x20103;
	sys->_6C    = 600;
	sys->_62[0] = 26;
	sys->_62[1] = 1;
	sys->_62[2] = 1;
}

/*
 * --INFO--
 * Address:	80009A60
 * Size:	000138
 */
void Channel_Init(jc_* jc)
{
	jc->_28 = NULL;
	jc->_2C = NULL;
	jc->_30 = 0;
	jc->_34 = 0;
	jc->_10 = NULL;
	jc->_0C = 0;
	jc->_14 = 0;
	jc->_18 = 0;
	jc->_1C = 0;

	if (jc->mMgr == NULL) {
		jc;
	} else {
		jc;

		for (int i = 0; i < 3; i++) {
			jc->_B8;
		}
	}

	for (int i = 0; i < 4; i++) {
		jc->mOscillators[i] = NULL;
	}
	jc->_02 = 0;
	jc->_126++;
	if ((int)jc->_126 == 0) {
		jc->_126 = 1;
	}
	/*
	.loc_0x0:
	  li        r8, 0
	  stw       r8, 0x28(r3)
	  stw       r8, 0x2C(r3)
	  stw       r8, 0x30(r3)
	  stw       r8, 0x34(r3)
	  stw       r8, 0x10(r3)
	  stb       r8, 0xC(r3)
	  stw       r8, 0x14(r3)
	  stw       r8, 0x18(r3)
	  stw       r8, 0x1C(r3)
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x88
	  li        r0, 0x150
	  lis       r4, 0x1
	  sth       r0, 0x108(r3)
	  li        r5, 0x210
	  li        r0, 0x352
	  li        r7, 0x412
	  sth       r5, 0x10A(r3)
	  addi      r6, r4, 0x101
	  li        r5, 0x258
	  li        r4, 0x1A
	  sth       r0, 0x10C(r3)
	  li        r0, 0x1
	  sth       r7, 0x10E(r3)
	  sth       r8, 0x110(r3)
	  sth       r8, 0x112(r3)
	  stw       r6, 0x120(r3)
	  sth       r5, 0x124(r3)
	  stb       r4, 0xB8(r3)
	  stb       r0, 0xB9(r3)
	  stb       r0, 0xBA(r3)
	  b         .loc_0xEC

	.loc_0x88:
	  li        r0, 0x6
	  mtctr     r0

	.loc_0x90:
	  lwz       r5, 0x4(r3)
	  addi      r4, r8, 0x4E
	  addi      r0, r8, 0x108
	  addi      r8, r8, 0x2
	  lhzx      r4, r5, r4
	  sthx      r4, r3, r0
	  bdnz+     .loc_0x90
	  lwz       r4, 0x4(r3)
	  li        r0, 0x3
	  li        r6, 0
	  lwz       r4, 0x68(r4)
	  stw       r4, 0x120(r3)
	  lwz       r4, 0x4(r3)
	  lhz       r4, 0x6C(r4)
	  sth       r4, 0x124(r3)
	  mtctr     r0

	.loc_0xD0:
	  lwz       r5, 0x4(r3)
	  addi      r4, r6, 0x62
	  addi      r0, r6, 0xB8
	  addi      r6, r6, 0x1
	  lbzx      r4, r5, r4
	  stbx      r4, r3, r0
	  bdnz+     .loc_0xD0

	.loc_0xEC:
	  li        r0, 0x4
	  li        r4, 0
	  li        r5, 0
	  mtctr     r0

	.loc_0xFC:
	  addi      r0, r4, 0x38
	  addi      r4, r4, 0x4
	  stwx      r5, r3, r0
	  bdnz+     .loc_0xFC
	  li        r0, 0
	  stb       r0, 0x2(r3)
	  lhz       r4, 0x126(r3)
	  addi      r0, r4, 0x1
	  sth       r0, 0x126(r3)
	  lhz       r0, 0x126(r3)
	  cmpwi     r0, 0
	  bnelr-
	  li        r0, 0x1
	  sth       r0, 0x126(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009BA0
 * Size:	000030
 */
void Channel_FirstInit(jc_* jc)
{
	jc->_20   = NULL;
	jc->mNext = NULL;
	jc->mMgr  = NULL;
	Channel_Init(jc);
}

/*
 * --INFO--
 * Address:	80009BE0
 * Size:	00007C
 */
void InitGlobalChannel()
{
	InitJcs(&GLOBAL_CHANNEL);

	for (int i = 0; i < 0x100; i++) {
		Channel_FirstInit(&CHANNEL[i]);
		List_AddChannel(&GLOBAL_CHANNEL._08, &CHANNEL[i]);
		CHANNEL[i].mMgr = &GLOBAL_CHANNEL;
	}

	GLOBAL_CHANNEL._00 = 0x100;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x24E0
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  mr        r28, r0
	  addi      r3, r28, 0
	  bl        -0x2C0
	  lis       r3, 0x802F
	  li        r27, 0
	  addi      r30, r3, 0x2560
	  li        r31, 0

	.loc_0x34:
	  add       r29, r30, r31
	  addi      r3, r29, 0
	  bl        -0x7C
	  addi      r3, r28, 0x8
	  addi      r4, r29, 0
	  bl        -0x688
	  addi      r27, r27, 0x1
	  stw       r28, 0x4(r29)
	  cmpwi     r27, 0x100
	  addi      r31, r31, 0x140
	  blt+      .loc_0x34
	  li        r0, 0x100
	  stw       r0, 0x0(r28)
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009C60
 * Size:	0000D8
 */
void __UpdateJcToDSPInit(jc_* jc)
{
	int buf = jc->_20->buffer_idx;
	DSP_SetMixerInitDelayMax(buf, jc->mMgr->_60);

	for (u32 i = 0; i < 6; i++) {
		DSP_SetMixerInitVolume(buf, i, jc->_114[i], jc->mMgr->_5A[i]);
	}

	DSP_SetPitch(buf, jc->_F8);

	if (jc->mMgr->_61 & 0x20) {
		DSP_SetIIRFilterParam(buf, jc->mMgr->_3C);
	}

	if (jc->mMgr->_61 & 0x1f) {
		DSP_SetFIR8FilterParam(buf, jc->mMgr->_2C);
	}

	DSP_SetFilterMode(buf, jc->mMgr->_61);
	DSP_SetPauseFlag(buf, jc->_02);
}

/*
 * --INFO--
 * Address:	80009D40
 * Size:	0000D8
 */
static void __UpdateJcToDSP(jc_* jc)
{
	u8 uVar1;

	uVar1 = jc->_20->buffer_idx;
	for (u32 i = 0; i < 6; ++i) {
		DSP_SetMixerVolume(uVar1, i, jc->_114[i], jc->mMgr->_5A[i]);
	}
	DSP_SetPitch(uVar1, jc->_F8);
	if ((jc->mMgr->_61 & 0x20) != 0)
		DSP_SetIIRFilterParam(uVar1, jc->mMgr->_3C);
	if ((jc->mMgr->_61 & 0x1f) != 0)
		DSP_SetFIR8FilterParam(uVar1, jc->mMgr->_2C);
	DSP_SetFilterMode(uVar1, jc->mMgr->_61);
	DSP_SetDistFilter(uVar1, jc->mMgr->_4C);
	DSP_SetPauseFlag(uVar1, jc->_02);
}

/*
 * --INFO--
 * Address:	80009E20
 * Size:	000038
 */
void UpdateJcToDSP(jc_* jc)
{
	__UpdateJcToDSP(jc);
	DSP_FlushChannel(jc->_20->buffer_idx);
}

/*
 * --INFO--
 * Address:	80009E60
 * Size:	000348
 */
void UpdateEffecterParam(jc_* jc)
{
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
		jc->_E8[0] *= val;
		break;
	case 0:
		jc->_E8[1] *= val;
		break;
	case 2:
		jc->_BC[1]._00[1] = val;
		break;
	case 3:
		jc->_BC[2]._00[1] = val;
		break;
	case 4:
		jc->_BC[3]._00[1] = val;
		break;
	}
}

/*
 * --INFO--
 * Address:	8000A240
 * Size:	000084
 */
void KillBrokenLogicalChannels(dspch_* ch)
{
	for (u32 i = 0; i < 0x100; i++) {
		jc_* chan = &CHANNEL[i];
		if (chan->_20 == ch) {
			StopLogicalChannel(chan);
			if (List_CutChannel(chan) != -1) {
				List_AddChannel(&chan->mMgr->_08, chan);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8000A2E0
 * Size:	000384
 */
void CommonCallbackLogicalChannel(dspch_* ch, u32 a)
{
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
	dspch_* ch = jc->_20;
	if (ch == NULL) {
		return FALSE;
	}

	ch->_0C      = NULL;
	jc->_20->_06 = 0;
	DSP_PlayStop(jc->_20->buffer_idx);
	DSP_FlushChannel(jc->_20->buffer_idx);
	DeAllocDSPchannel(jc->_20, (u32)jc);
	jc->_20 = NULL;
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000A700
 * Size:	000028
 */
BOOL CheckLogicalChannel(jc_* jc)
{
	if (jc->_10 == NULL && jc->_0C == 0) {
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
	if (jc->_20 == NULL) {
		return FALSE;
	}

	if (CheckLogicalChannel(jc) == FALSE) {
		return FALSE;
	}

	UpdateEffecterParam(jc);
	__UpdateJcToDSPInit(jc);
	DSP_FlushChannel(jc->_20->buffer_idx);
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

	if (BreakLowerDSPchannel(jc->_120) == FALSE) {
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
		u32 a = (cur_top + i) & 0x7c;
		if (waitp[a] == jc) {
			waitp[a] = NULL;
			return TRUE;
		}
	}
	return FALSE;

	/*
	.loc_0x0:
	  lwz       r0, 0x2BD0(r13)
	  lis       r4, 0x8030
	  addi      r5, r4, 0x6560
	  lwz       r7, 0x2BD4(r13)
	  li        r8, 0
	  mtctr     r0
	  cmplwi    r0, 0
	  ble-      .loc_0x5C

	.loc_0x20:
	  add       r0, r7, r8
	  rlwinm    r6,r0,2,25,29
	  add       r4, r5, r6
	  lwz       r0, 0x0(r4)
	  cmplw     r0, r3
	  bne-      .loc_0x54
	  lis       r3, 0x8030
	  li        r5, 0
	  addi      r0, r3, 0x6560
	  li        r3, 0x1
	  add       r4, r0, r6
	  stw       r5, 0x0(r4)
	  blr

	.loc_0x54:
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x20

	.loc_0x5C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AA80
 * Size:	0000FC
 */
void __Entry_WaitChannel(u8 a)
{
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

	for (int i = 0; i < cur_waits; i++) { }
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
void Cancel_WaitDSPChannel(jc_* jc)
{
	for (u32 i = 0; i < cur_waits; i++) {
		if (waitp[(cur_top + i)] == jc) {
			waitp[(cur_top + i)] = NULL;
		}
	}
	/*
	.loc_0x0:
	  lwz       r7, 0x2BD0(r13)
	  lis       r4, 0x8030
	  addi      r5, r4, 0x6560
	  lwz       r6, 0x2BD4(r13)
	  li        r8, 0
	  li        r0, 0
	  mtctr     r7
	  cmplwi    r7, 0
	  blelr-

	.loc_0x24:
	  add       r4, r6, r8
	  rlwinm    r4,r4,2,25,29
	  add       r7, r5, r4
	  lwz       r4, 0x0(r7)
	  cmplw     r4, r3
	  bne-      .loc_0x40
	  stw       r0, 0x0(r7)

	.loc_0x40:
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000ACC0
 * Size:	000038
 */
BOOL ForceStopLogicalChannel(jc_* jc)
{
	if (jc->_20 == NULL) {
		return FALSE;
	}

	ForceStopDSPchannel(jc->_20);
	return TRUE;
}
