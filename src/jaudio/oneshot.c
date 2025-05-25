#include "jaudio/oneshot.h"
#include "jaudio/bankdrv.h"
#include "jaudio/audiostruct.h"
#include "jaudio/driverinterface.h"
#include "jaudio/tables.h"
#include "jaudio/bankread.h"
#include "jaudio/waveread.h"
#include "jaudio/connect.h"
#include "jaudio/dspdriver.h"
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
		return jc->_00;
	case 2:
		return jc->_01;
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
		jc->_BC[i]._00[0] = __Clamp01(jc->_BC[i]._00[0]);
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
		jc->_B0 *= val;
		break;
	case 0:
		jc->_B4 *= val;
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
 * Address:	800152A0
 * Size:	000138
 */
static void EffecterInit(jc_* jc, Inst_* inst)
{
	jc->_E8[0]        = 1.0f;
	jc->_E8[1]        = 1.0f;
	jc->_BC[1]._00[1] = 0.5f;
	jc->_BC[2]._00[1] = 0.0f;
	jc->_BC[3]._00[1] = 0.0f;

	for (u32 i = 0; i < 2; i++) {
		Inst_* c = *((Inst_**)inst + i);

		if (c->_20) {
			vf32 sense = Bank_SenseToOfs(c->_20, __GetTrigger(jc, (int)c->_20 + 1));
			__DoEffect(jc, c->_20->_00, sense);
		}

		if (c->_18) {
			f32 r = Bank_RandToOfs(c->_18);
			__DoEffect(jc, c->_18->_00[0], r);
		}

		if (c->_10) {
			Oscbuf_* buf = &jc->_48[i];
			buf->_00     = TRUE;
			Osc_** osc   = &jc->_38[i];
			osc[0]       = (Osc_*)&c->_10;
			f32 offs     = Bank_OscToOfs(osc[0], buf);
			DoEffectOsc(jc, osc[0]->_00, offs);
		} else {
			jc->_38[i] = 0;
		}
	}

	__Clamp01InitPan(jc);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  li        r31, 0
	  li        r28, 0
	  li        r27, 0
	  lfs       f0, -0x7EA4(r2)
	  stfs      f0, 0xEC(r3)
	  stfs      f0, 0xF0(r3)
	  lfs       f0, -0x7EA0(r2)
	  stfs      f0, 0xCC(r3)
	  lfs       f0, -0x7EA8(r2)
	  stfs      f0, 0xD8(r3)
	  stfs      f0, 0xE4(r3)

	.loc_0x44:
	  add       r25, r30, r27
	  addi      r26, r25, 0x20
	  lwz       r4, 0x20(r25)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  mr        r3, r29
	  lbz       r4, 0x1(r4)
	  bl        -0x1C0
	  mr        r0, r3
	  lwz       r3, 0x0(r26)
	  mr        r4, r0
	  bl        -0x8150
	  stfs      f1, 0x1C(r1)
	  mr        r3, r29
	  lwz       r4, 0x0(r26)
	  lfs       f1, 0x1C(r1)
	  lbz       r4, 0x0(r4)
	  bl        -0x108

	.loc_0x8C:
	  addi      r26, r25, 0x18
	  lwz       r3, 0x18(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  bl        -0x805C
	  lwz       r4, 0x0(r26)
	  mr        r3, r29
	  lbz       r4, 0x0(r4)
	  bl        -0x12C

	.loc_0xB0:
	  addi      r3, r25, 0x10
	  lwz       r0, 0x10(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  addi      r4, r28, 0x48
	  addi      r25, r27, 0x38
	  add       r4, r29, r4
	  li        r0, 0x1
	  stb       r0, 0x0(r4)
	  add       r25, r29, r25
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x0(r25)
	  lwz       r3, 0x0(r25)
	  bl        -0x8044
	  lwz       r4, 0x0(r25)
	  mr        r3, r29
	  lbz       r4, 0x0(r4)
	  bl        -0xB1D4
	  b         .loc_0x108

	.loc_0xFC:
	  addi      r0, r27, 0x38
	  li        r3, 0
	  stwx      r3, r29, r0

	.loc_0x108:
	  addi      r31, r31, 0x1
	  addi      r27, r27, 0x4
	  cmplwi    r31, 0x2
	  addi      r28, r28, 0x18
	  blt+      .loc_0x44
	  mr        r3, r29
	  bl        -0x200
	  lmw       r25, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800153E0
 * Size:	0000D0
 */
static void EffecterInit_Perc(jc_* jc, Pmap_* pmap, u16 id)
{
	jc->_E8[0]        = 1.0f;
	jc->_E8[1]        = 1.0f;
	jc->_BC[1]._00[1] = 0.5f;
	jc->_BC[2]._00[1] = 0.0f;
	jc->_BC[3]._00[1] = 0.0f;

	// PERC instruments only have rand and not osc
	for (u32 i = 0; i < 2; i++) {
		Pmap_* map = (Pmap_*)((int*)pmap + i);
		if (map->_00) {
			f32 r      = Bank_RandToOfs(map->_00);
			f32* REF_r = &r;
			__DoEffect(jc, map->_00->_00[0], r);
		}

		jc->_38[i] = nullptr;
	}
	jc->_38[0]     = &PERC_ENV;
	jc->_48[0]._00 = TRUE;
	Bank_OscToOfs(jc->_38[0], &jc->_48[0]);
	jc->_48[0]._14 = id;
	__Clamp01InitPan(jc);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  li        r31, 0
	  addi      r25, r3, 0
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r30, r31, 0
	  li        r28, 0
	  lfs       f0, -0x7EA4(r2)
	  stfs      f0, 0xEC(r3)
	  stfs      f0, 0xF0(r3)
	  lfs       f0, -0x7EA0(r2)
	  stfs      f0, 0xCC(r3)
	  lfs       f0, -0x7EA8(r2)
	  stfs      f0, 0xD8(r3)
	  stfs      f0, 0xE4(r3)

	.loc_0x48:
	  addi      r29, r31, 0x8
	  add       r29, r26, r29
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x78
	  bl        -0x815C
	  stfs      f1, 0x18(r1)
	  mr        r3, r25
	  lwz       r4, 0x0(r29)
	  lfs       f1, 0x18(r1)
	  lbz       r4, 0x0(r4)
	  bl        -0x234

	.loc_0x78:
	  addi      r28, r28, 0x1
	  addi      r0, r31, 0x38
	  cmplwi    r28, 0x2
	  stwx      r30, r25, r0
	  addi      r31, r31, 0x4
	  blt+      .loc_0x48
	  lis       r3, 0x8022
	  li        r0, 0x1
	  addi      r3, r3, 0x5910
	  addi      r4, r25, 0x48
	  stw       r3, 0x38(r25)
	  stb       r0, 0x48(r25)
	  lwz       r3, 0x38(r25)
	  bl        -0x814C
	  sth       r27, 0x5C(r25)
	  mr        r3, r25
	  bl        -0x2D8
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800154C0
 * Size:	00007C
 */
static void EffecterInit_Osc(jc_* jc)
{
	jc->_E8[0]        = 1.0f;
	jc->_E8[1]        = 1.0f;
	jc->_BC[1]._00[1] = 0.5f;
	jc->_BC[2]._00[1] = 0.0f;
	jc->_BC[3]._00[1] = 0.0f;

	for (u32 i = 0; i < 2; i++) {
		jc->_38[i] = nullptr;
	}

	jc->_38[0]     = &OSC_ENV;
	jc->_48[0]._00 = TRUE;
	Bank_OscToOfs(jc->_38[0], &jc->_48[0]);
}

/*
 * --INFO--
 * Address:	80015540
 * Size:	00006C
 */
void Effecter_Overwrite_1ShotD(jc_* jc, Osc_* osc, u32 id)
{
	if (id < 4) {
		jc->_48[id]._00 = TRUE;
		jc->_38[id]     = osc;
		DoEffectOsc(jc, jc->_38[id]->_00, Bank_OscToOfs(jc->_38[id], &jc->_48[id]));
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
	jc->_30 = id;
	jc->_34 = jc->_30;
	jc->_28 = Jesus1Shot_Update;
	jc->_20 = AllocDSPchannel(0, (u32)jc);

	if (jc->_20 == nullptr) {
		play = CheckLogicalChannel(jc);
	} else {
		play = PlayLogicalChannel(jc);
	}

	if (jc->_20 == nullptr && play == TRUE) {
		if (Add_WaitDSPChannel(jc) == TRUE) {
			List_AddChannelTail(&jcs->_14, jc);
			return jc;
		} else {
			List_AddChannelTail(&jcs->_08, jc);
			return nullptr;
		}
	} else if (play == FALSE) {
		DeAllocDSPchannel(jc->_20, (u32)jc);
		jc->_20 = nullptr;
		List_AddChannelTail(&jcs->_08, jc);
		return nullptr;
	} else {
		List_AddChannelTail(&jcs->_0C, jc);
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
	if (wave && wave->_0C == nullptr) {
		return FALSE;
	}

	jc_* chan = List_GetChannel(&jcs->_08);
	if (chan == nullptr) {

		if (FixAllocChannel(jcs, 1) == FALSE) {
			return 0;
		}
		jcs->_04++;
		chan = List_GetChannel(&jcs->_08);
		if (chan == nullptr) {
			return 0;
		}

		if (jcs->_70 == 1) {
			volatile jc_* c;
			c = List_GetChannel(&jcs->_10);
			if (c == nullptr) {
				c = List_GetChannel(&jcs->_0C);
				if (c) {
					List_CountChannel(&jcs->_14);
				}
			}

			if (c) {
				c->_48[0]._00 = 6;
				List_AddChannel(&jcs->_14, c);
				if (c->_20) {
					ForceStopDSPchannel(c->_20);
				}
			}
		}
	}
	Channel_Init(chan);
	if (wave) {
		chan->_10 = wave;
		chan->_0C = 0;
	}
	chan->_18 = 0;
	UpdatePanPower_1Shot(chan, 1.0f, 1.0f, 1.0f, 1.0f);
	return chan;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r28, 0x30(r1)
	  mr.       r29, r4
	  addi      r28, r3, 0
	  beq-      .loc_0x30
	  lwz       r0, 0xC(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x30:
	  addi      r3, r28, 0x8
	  bl        -0xC214
	  mr.       r30, r3
	  bne-      .loc_0xF4
	  addi      r3, r28, 0
	  li        r4, 0x1
	  bl        -0xC168
	  cmpwi     r3, 0
	  bne-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x5C:
	  lwz       r4, 0x4(r28)
	  addi      r3, r28, 0x8
	  addi      r0, r4, 0x1
	  stw       r0, 0x4(r28)
	  bl        -0xC24C
	  mr.       r30, r3
	  bne-      .loc_0x80
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x80:
	  lwz       r0, 0x70(r28)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xF4
	  addi      r3, r28, 0x10
	  bl        -0xC270
	  stw       r3, 0x2C(r1)
	  lwz       r0, 0x2C(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0xC4
	  addi      r3, r28, 0xC
	  bl        -0xC288
	  stw       r3, 0x2C(r1)
	  lwz       r0, 0x2C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xC4
	  addi      r3, r28, 0x14
	  bl        -0xC340

	.loc_0xC4:
	  lwz       r31, 0x2C(r1)
	  cmplwi    r31, 0
	  beq-      .loc_0xF4
	  li        r0, 0x6
	  addi      r4, r31, 0
	  stb       r0, 0x48(r31)
	  addi      r3, r28, 0x14
	  bl        -0xC220
	  lwz       r3, 0x20(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  bl        -0xA670

	.loc_0xF4:
	  mr        r3, r30
	  bl        -0xBD78
	  cmplwi    r29, 0
	  beq-      .loc_0x11C
	  lwz       r3, 0x34(r29)
	  li        r0, 0
	  stw       r3, 0x10(r30)
	  lwz       r3, 0xC(r29)
	  stw       r3, 0x14(r30)
	  stb       r0, 0xC(r30)

	.loc_0x11C:
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r0, 0x18(r30)
	  lfs       f1, -0x7EA4(r2)
	  fmr       f2, f1
	  fmr       f3, f1
	  fmr       f4, f1
	  bl        0x788
	  mr        r3, r30

	.loc_0x140:
	  lmw       r28, 0x30(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015840
 * Size:	000044
 */
Perc_* PercRead(u32 a1, u32 a2)
{
	Bank_* bank = Bank_Get(a1);
	if (bank == nullptr) {
		return nullptr;
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
	if (bank == nullptr) {
		return nullptr;
	}

	return Bank_InstChange(bank, a2);
}

/*
 * --INFO--
 * Address:	80015900
 * Size:	00002C
 */
int VmapRead(Inst_* inst, u8 a1, u8 a2)
{
	u32 a = Bank_GetInstVmap(inst, a1, a2);
	if (a == 0) {
		return 0;
	}
	return a;
}

/*
 * --INFO--
 * Address:	80015940
 * Size:	000010
 */
static void __Oneshot_WavePause(jc_* jc, u8 a)
{
	jc->_02 = a;
	jc->_03 = 1;
}

/*
 * --INFO--
 * Address:	80015960
 * Size:	00014C
 */
static void __Oneshot_StartMonoPolyCheck(jc_* jc, u32 id)
{
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
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r6,r4,8,24,31
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x8022
	  mr.       r31, r4
	  rlwinm    r4,r4,8,28,31
	  addi      r0, r3, 0x5940
	  add       r3, r0, r4
	  lwz       r5, 0x4(r30)
	  lbz       r26, 0x0(r3)
	  lwz       r27, 0xC(r5)
	  beq-      .loc_0xD4
	  cmplwi    r26, 0
	  beq-      .loc_0xD4
	  rlwinm    r29,r6,0,26,26
	  subi      r28, r26, 0x1

	.loc_0x4C:
	  cmplwi    r27, 0
	  beq-      .loc_0xD4
	  lwz       r0, 0x128(r27)
	  cmplw     r0, r31
	  bne-      .loc_0xCC
	  cmpwi     r29, 0
	  beq-      .loc_0x9C
	  lbz       r3, 0x12C(r27)
	  lbz       r0, 0x12C(r30)
	  cmplw     r3, r0
	  ble-      .loc_0xCC
	  subi      r0, r3, 0x1
	  stb       r0, 0x12C(r27)
	  lbz       r0, 0x12C(r27)
	  cmpw      r0, r28
	  bne-      .loc_0xCC
	  addi      r3, r27, 0
	  li        r4, 0
	  bl        -0x214
	  b         .loc_0xCC

	.loc_0x9C:
	  lbz       r3, 0x12C(r27)
	  lbz       r0, 0x12C(r30)
	  cmplw     r3, r0
	  ble-      .loc_0xCC
	  subi      r0, r3, 0x1
	  stb       r0, 0x12C(r27)
	  lbz       r0, 0x12C(r27)
	  cmplw     r0, r26
	  bge-      .loc_0xCC
	  addi      r3, r27, 0
	  li        r4, 0
	  bl        -0x248

	.loc_0xCC:
	  lwz       r27, 0x24(r27)
	  b         .loc_0x4C

	.loc_0xD4:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015BC0
 * Size:	000070
 */
void Init_1shot(jcs_* jcs, u32 id)
{
	if (jcs->_00 != 0) {
		FixReleaseChannelAll(jcs);
	}
	InitJcs(jcs);
	FixAllocChannel(jcs, id);
	if (id == 0) {
		jcs->_70 = 0;
	} else {
		jcs->_70 = 1;
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
	if (jc->_20 == 0) {
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
	if (jc->_20 == 0) {
		Jesus1Shot_Update(jc, (JCSTATUS)6);
	} else {
		jc->_48[0]._14 = id;
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
	List_CountChannel(&jcs->_08);
	List_CountChannel(&jcs->_0C);
	List_CountChannel(&jcs->_10);
	List_CountChannel(&jcs->_14);

	jc_* jc = jcs->_0C;
	while (jc) {
		jc = (jc_*)jc->mNext;
		Stop_1Shot(jc);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x8
	  bl        -0xC878
	  addi      r3, r31, 0xC
	  bl        -0xC880
	  addi      r3, r31, 0x10
	  bl        -0xC888
	  addi      r3, r31, 0x14
	  bl        -0xC890
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x20(r1)
	  b         .loc_0x4C

	.loc_0x40:
	  lwz       r31, 0x24(r3)
	  bl        -0xC4
	  stw       r31, 0x20(r1)

	.loc_0x4C:
	  lwz       r3, 0x20(r1)
	  cmplwi    r3, 0
	  bne+      .loc_0x40
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015D40
 * Size:	00006C
 */
static int Extra_Update(jc_* jc, JCSTATUS status)
{
	if (jc->_FA) {
		jc->_B0 += (jc->_E8[2] - jc->_B0) / (f32)jc->_FA;
		jc->_FA--;

		if (jc->_FA == 0) {
			jc->_2C = nullptr;
		}
	}
	return 0;
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lhz       r0, 0xFA(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  stw       r0, 0x14(r1)
	  lis       r0, 0x4330
	  lfs       f3, 0xF4(r3)
	  stw       r0, 0x10(r1)
	  lfs       f2, 0xB0(r3)
	  lfd       f1, -0x7E98(r2)
	  lfd       f0, 0x10(r1)
	  fsubs     f3, f3, f2
	  fsubs     f0, f0, f1
	  fdivs     f3, f3, f0
	  fadds     f0, f2, f3
	  stfs      f0, 0xB0(r3)
	  lhz       r4, 0xFA(r3)
	  subi      r0, r4, 0x1
	  sth       r0, 0xFA(r3)
	  lhz       r0, 0xFA(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x60
	  li        r0, 0
	  stw       r0, 0x2C(r3)

	.loc_0x60:
	  li        r3, 0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015DC0
 * Size:	000030
 */
void SetPitchTarget_1Shot(jc_* jc, f32 a1, u32 a2)
{
	if (a2 == 0) {
		jc->_B0 = a1;
		jc->_2C = nullptr;
		return;
	}

	jc->_E8[2] = a1;
	jc->_FA    = a2;
	jc->_2C    = Extra_Update;
}

/*
 * --INFO--
 * Address:	80015E00
 * Size:	000090
 */
void SetKeyTarget_1Shot(jc_* jc, u8 a1, u32 a2)
{
	if (jc == 0) {
		return;
	}

	if (jc->_0C == 2 || jc->_10 == nullptr) {
		a1 &= 0xff;
	} else {
		a1 = ((u8)a1 + 0x3c) - ((int)jc->_10 + 2);
	}

	if (a1 < 0) {
		a1 = 0;
	}
	if (a1 >= 0x7f) {
		a1 = 0x7f;
	}

	SetPitchTarget_1Shot(jc, jc->_A8 * C5BASE_PITCHTABLE[a1], a2);

	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x80
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0x2
	  beq-      .loc_0x2C
	  lwz       r6, 0x10(r3)
	  cmplwi    r6, 0
	  bne-      .loc_0x34

	.loc_0x2C:
	  rlwinm    r0,r4,0,24,31
	  b         .loc_0x44

	.loc_0x34:
	  rlwinm    r4,r4,0,24,31
	  lbz       r6, 0x2(r6)
	  addi      r0, r4, 0x3C
	  sub       r0, r0, r6

	.loc_0x44:
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  li        r0, 0

	.loc_0x50:
	  cmpwi     r0, 0x7F
	  ble-      .loc_0x5C
	  li        r0, 0x7F

	.loc_0x5C:
	  lis       r4, 0x8022
	  rlwinm    r6,r0,2,0,29
	  addi      r0, r4, 0x4E18
	  lfs       f0, 0xA8(r3)
	  add       r4, r0, r6
	  lfs       f1, 0x0(r4)
	  mr        r4, r5
	  fmuls     f1, f0, f1
	  bl        -0xBC

	.loc_0x80:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015EA0
 * Size:	0000C8
 */
void Gate_1Shot(jc_* jc, u8 a1, u8 a2, s32 a3)
{
	if (jc->_30 == -1) {
		jc->_30 = a3;
		jc->_34 = jc->_30;
		int val;
		if (jc->_0C == 2) {
			val = a1;
		} else {
			val = a1 + 0x3c;
		}
		if (val < 0) {
			val = 0;
		}
		if (val > 0x7f) {
			val = 0x7f;
		}

		jc->_00 = a2;
		jc->_01 = a1;
		jc->_B0 = jc->_A8 * C5BASE_PITCHTABLE[val];
		jc->_B4 = jc->_00 / 127.0f;
		jc->_B4 *= jc->_AC * jc->_B4;
	}
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  lwz       r0, 0x30(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xC0
	  stw       r6, 0x30(r3)
	  lwz       r0, 0x30(r3)
	  stw       r0, 0x34(r3)
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x30
	  rlwinm    r0,r4,0,24,31
	  b         .loc_0x44

	.loc_0x30:
	  lwz       r7, 0x10(r3)
	  rlwinm    r6,r4,0,24,31
	  addi      r0, r6, 0x3C
	  lbz       r6, 0x2(r7)
	  sub       r0, r0, r6

	.loc_0x44:
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  li        r0, 0

	.loc_0x50:
	  cmpwi     r0, 0x7F
	  ble-      .loc_0x5C
	  li        r0, 0x7F

	.loc_0x5C:
	  lis       r6, 0x8022
	  rlwinm    r7,r0,2,0,29
	  addi      r6, r6, 0x4E18
	  lis       r0, 0x4330
	  add       r6, r6, r7
	  lfs       f1, 0x0(r6)
	  stb       r5, 0x0(r3)
	  stb       r4, 0x1(r3)
	  lfs       f0, 0xA8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB0(r3)
	  lbz       r4, 0x0(r3)
	  lfd       f2, -0x7E98(r2)
	  stw       r4, 0x24(r1)
	  lfs       f0, -0x7E90(r2)
	  stw       r0, 0x20(r1)
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  stfs      f0, 0xB4(r3)
	  lfs       f0, 0xB4(r3)
	  lfs       f1, 0xAC(r3)
	  fmuls     f0, f0, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB4(r3)

	.loc_0xC0:
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015F80
 * Size:	000008
 */
void UpdatePause_1Shot(jc_* jc, u8 a1)
{
	jc->_02 = a1;
}

/*
 * --INFO--
 * Address:	80015FA0
 * Size:	000030
 */
void UpdatePanPower_1Shot(jc_* jc, f32 v1, f32 v2, f32 v3, f32 v4)
{
	f32 val = v1 + v2 + v3;
	if (val == 0.0f) {
		return;
	}

	jc->_BC[0]._00[0] = v1 / val;
	jc->_BC[0]._00[1] = v2 / val;
	jc->_BC[0]._00[2] = v3 / val;
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
	int count = List_CountChannel(&jcs->_10);

	for (u32 i = 0; i < count; i++) {
		jc_* chan = List_GetChannel(&jcs->_10);
		if (chan == nullptr) {
			break;
		}

		for (int j = 0; j < 2; j++) {
			if (chan->_38[j]) {
				if (chan->_48[j]._00 != 6 && chan->_48[j]._00 != 7) {
					chan->_48[j]._00 = 6;
				}
			}
		}

		List_AddChannelTail(&jcs->_10, chan);
	}
}

/*
 * --INFO--
 * Address:	800160A0
 * Size:	0001C4
 */
static int Jesus1Shot_Update(jc_* jc, JCSTATUS status)
{
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
	Inst_* inst = InstRead(sound.value, sound.value);
	if (inst == nullptr) {
		return 1;
	}

	int map = VmapRead(inst, sound.value, sound.value);
	if (map == nullptr) {
		return 2;
	}

	CtrlGroup_* group = WaveidToWavegroup(map, sound.value);
	if (group == nullptr) {
		return 3;
	}

	int handle = GetSoundHandle(group, map);
	if (handle == 0) {
		return 4;
	}

	return 0;

	/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stmw      r30, 0x10(r1)
  mr        r30, r3
  lbz       r3, 0x0(r3)
  lbz       r4, 0x1(r30)
  bl        -0x9FC
  cmplwi    r3, 0
  bne-      .loc_0x30
  li        r3, 0x1
  b         .loc_0x84

.loc_0x30:
  lbz       r4, 0x2(r30)
  lbz       r5, 0x3(r30)
  bl        -0x9B8
  mr.       r31, r3
  bne-      .loc_0x4C
  li        r3, 0x2
  b         .loc_0x84

.loc_0x4C:
  lwz       r3, 0x4(r31)
  lbz       r4, 0x0(r30)
  bl        -0x9D14
  cmplwi    r3, 0
  bne-      .loc_0x68
  li        r3, 0x3
  b         .loc_0x84

.loc_0x68:
  lwz       r4, 0x4(r31)
  bl        -0x94EC
  cmplwi    r3, 0
  bne-      .loc_0x80
  li        r3, 0x4
  b         .loc_0x84

.loc_0x80:
  li        r3, 0

.loc_0x84:
  lwz       r0, 0x1C(r1)
  lmw       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
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
void Play_1shot(jcs_* jcs, SOUNDID_ sound, u32 id)
{
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
void Play_1shot_Perc(jcs_* jcs, SOUNDID_ sound, u32 id)
{
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
void Play_1shot_Osc(jcs_* jcs, SOUNDID_ sound, u32 id)
{
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
