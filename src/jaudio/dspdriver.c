#include "jaudio/dspdriver.h"

#include "jaudio/dspinterface.h"

#define DSPCH_LENGTH (64)
static dspch_ DSPCH[DSPCH_LENGTH] ATTRIBUTE_ALIGN(32);

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
dspch_* GetDSPchannelHandle(u32 idx)
{
	return &DSPCH[idx];
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000AD00
 * Size:	000060
 */
void InitDSPchannel()
{
	dspch_* chan;
	int i;

	for (i = 0; i < DSPCH_LENGTH; ++i) {
		chan = &DSPCH[i];

		chan->buffer_idx = i;
		chan->_01        = 0;
		chan->_08        = 0;
		chan->_06        = 0;
		chan->_0C        = NULL;
		chan->_03        = 0;
		chan->_04        = 0;
	}
}

/*
 * --INFO--
 * Address:	8000AD60
 * Size:	000114
 */
dspch_* AllocDSPchannel(u32 param_1, u32 param_2)
{

	int i;
	dspch_* chan;
	if (param_1)
		return NULL;

	if (!param_1) {
		for (i = 0; i < DSPCH_LENGTH; ++i) {
			chan = &DSPCH[i];
			if (chan->_01 != 1)
				continue;
			chan->_01 = TRUE;
			chan->_08 = param_2;
			chan->_03 = 1;
			DSP_AllocInit(i);
			return chan;
		}
	} else {
		for (i = 0; i < DSPCH_LENGTH / 2; ++i) {
			chan = &DSPCH[i];

			if (chan->_01)
				continue;

			DSP_AllocInit(i);
			DSP_AllocInit(i - 1);
			return chan - 1;
		}
	}
	return NULL;
}

/*
 * --INFO--
 * Address:	8000AE80
 * Size:	0000DC
 */
void DeAllocDSPchannel(dspch_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr.       r31, r3
	  bne-      .loc_0x20
	  li        r3, -0x1
	  b         .loc_0xC8

	.loc_0x20:
	  lwz       r0, 0x8(r31)
	  cmplw     r0, r4
	  beq-      .loc_0x34
	  li        r3, -0x2
	  b         .loc_0xC8

	.loc_0x34:
	  lbz       r0, 0x1(r31)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x90
	  bge-      .loc_0x54
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5C
	  bge-      .loc_0x68
	  b         .loc_0xB4

	.loc_0x54:
	  cmpwi     r0, 0x5
	  bge-      .loc_0xB4

	.loc_0x5C:
	  li        r0, 0
	  stb       r0, 0x1(r31)
	  b         .loc_0xB4

	.loc_0x68:
	  li        r0, 0
	  lis       r3, 0x8030
	  stb       r0, 0x1(r31)
	  addi      r0, r3, 0x6660
	  lbz       r3, 0x0(r31)
	  addi      r3, r3, 0x1
	  rlwinm    r3,r3,4,0,27
	  add       r3, r0, r3
	  bl        .loc_0x0
	  b         .loc_0xB4

	.loc_0x90:
	  li        r0, 0
	  lis       r3, 0x8030
	  stb       r0, 0x1(r31)
	  addi      r0, r3, 0x6660
	  lbz       r3, 0x0(r31)
	  subi      r3, r3, 0x1
	  rlwinm    r3,r3,4,0,27
	  add       r3, r0, r3
	  bl        .loc_0x0

	.loc_0xB4:
	  li        r0, 0
	  li        r3, 0
	  stb       r0, 0x3(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)

	.loc_0xC8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AF60
 * Size:	000104
 */
dspch_* GetLowerDSPchannel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0xFF
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  lis       r4, 0x8030
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  addi      r31, r4, 0x6660
	  stb       r3, 0x2C(r1)
	  stw       r0, 0x28(r1)
	  stw       r0, 0x24(r1)
	  stw       r0, 0x20(r1)
	  b         .loc_0xD8

	.loc_0x34:
	  rlwinm    r0,r30,4,0,27
	  add       r29, r31, r0
	  lbz       r0, 0x1(r29)
	  cmplwi    r0, 0x4
	  beq-      .loc_0xCC
	  cmplwi    r0, 0
	  bne-      .loc_0x60
	  li        r0, 0
	  stb       r0, 0x3(r29)
	  stw       r30, 0x28(r1)
	  b         .loc_0xE4

	.loc_0x60:
	  lwz       r0, 0xC(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  lbz       r3, 0x0(r29)
	  bl        0x590
	  addi      r28, r29, 0x3
	  lbz       r27, 0x2C(r1)
	  lbz       r0, 0x3(r29)
	  cmplw     r0, r27
	  bgt-      .loc_0xCC
	  lbz       r3, 0x0(r29)
	  bl        0x574
	  lbz       r5, 0x0(r28)
	  cmplw     r27, r5
	  bne-      .loc_0xBC
	  lwz       r0, 0x24(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  lwz       r4, 0x10C(r3)
	  cmplw     r4, r0
	  bge-      .loc_0xBC
	  cmplwi    r4, 0
	  bne-      .loc_0xCC

	.loc_0xBC:
	  lwz       r0, 0x10C(r3)
	  stw       r0, 0x24(r1)
	  stw       r30, 0x28(r1)
	  stb       r5, 0x2C(r1)

	.loc_0xCC:
	  lwz       r3, 0x20(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x20(r1)

	.loc_0xD8:
	  lwz       r30, 0x20(r1)
	  cmplwi    r30, 0x40
	  blt+      .loc_0x34

	.loc_0xE4:
	  lwz       r0, 0x28(r1)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r31, r0
	  lwz       r0, 0x4C(r1)
	  lmw       r27, 0x34(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B080
 * Size:	0000D8
 */
dspch_* GetLowerActiveDSPchannel() // regswaps and volatile memes... argh!
{
	volatile u8 local_1c;
	volatile u32 local_20;
	volatile u32 local_24;

	u8 local_1c_nonv;
	u32 local_24_nonv;
	u32 member_10c_nonv;

	u32 i;
	DSPBuffer* buf;
	dspch_* chan;

	u32 badCompiler[3];

	local_1c = 0xff;
	local_20 = 0;
	local_24 = 0;
	for (i = 0; i < DSPCH_LENGTH; ++i) {
		chan = &DSPCH[i];
		if (chan->_01 == 4 || chan->_01 == 0)
			continue;

		local_1c_nonv = local_1c;
		if (DSPCH[i]._03 > local_1c_nonv)
			continue;

		buf = GetDspHandle(DSPCH[i].buffer_idx);
		if (local_1c_nonv == DSPCH[i]._03) {
			local_24_nonv = local_24;
			if (local_24_nonv == 0)
				continue;
			member_10c_nonv = buf->_10C;
			if (member_10c_nonv < local_24_nonv && member_10c_nonv != 0)
				continue;
		}
		local_24 = buf->_10C;
		local_20 = i;
		local_1c = DSPCH[i]._03;
	}

	return &DSPCH[local_20];
}

/*
 * --INFO--
 * Address:	8000B160
 * Size:	00007C
 */
BOOL ForceStopDSPchannel(dspch_* chan)
{
	dspch_** REF_chan;

	DSPBuffer* buf;

	REF_chan = &chan;
	if (chan->_01 == 4)
		return FALSE;
	buf = GetDspHandle(chan->buffer_idx);
	if (!buf->enabled)
		return FALSE;
	buf->endRequested = DSP_TRUE;
	chan->_01         = 4;
	DSP_FlushChannel(chan->buffer_idx);
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000B1E0
 * Size:	0000AC
 */
BOOL BreakLowerDSPchannel(u8 param_1)
{
	u8* REF_param_1;

	dspch_* chan;
	DSPBuffer* buf;

	chan    = GetLowerDSPchannel();
	REF_param_1 = &param_1;
	if (chan->_03 > param_1)
		return FALSE;
	if (chan->_03 == param_1) {
		buf = GetDspHandle(chan->buffer_idx); // UNUSED??
	}
	if (chan->_01) {
		if (chan->_0C) {
			chan->_06 = chan->_0C(chan, 3);
			ForceStopDSPchannel(chan);
			chan->_01 = 4;
		}
		ForceStopDSPchannel(chan);
	} else {
		return FALSE;
	}
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000B2A0
 * Size:	0000AC
 */
void BreakLowerActiveDSPchannel(u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stb       r3, 0x8(r1)
	  bl        -0x234
	  mr        r31, r3
	  lbz       r0, 0x8(r1)
	  lbz       r3, 0x3(r3)
	  cmplw     r3, r0
	  ble-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x34:
	  bne-      .loc_0x40
	  lbz       r3, 0x0(r31)
	  bl        0x284

	.loc_0x40:
	  lbz       r0, 0x1(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  lwz       r12, 0xC(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x80
	  addi      r3, r31, 0
	  li        r4, 0x3
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,16,31
	  addi      r3, r31, 0
	  sth       r0, 0x6(r31)
	  bl        -0x1B4
	  li        r0, 0x4
	  stb       r0, 0x1(r31)

	.loc_0x80:
	  mr        r3, r31
	  bl        -0x1C4
	  b         .loc_0x94

	.loc_0x8C:
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x94:
	  li        r3, 0x1

	.loc_0x98:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void UpdateDSPchannel(dspch_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000B360
 * Size:	0001F4
 */
void UpdateDSPchannelAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r26, 0x48(r1)
	  bl        0x1F2048
	  lwz       r0, 0x2BE0(r13)
	  stw       r3, 0x2BE0(r13)
	  sub       r26, r3, r0
	  bl        -0x50A0
	  lwz       r0, -0x7FFC(r13)
	  lis       r4, 0x8022
	  addi      r4, r4, 0x4978
	  sub.      r3, r0, r3
	  rlwinm    r0,r3,2,0,29
	  add       r3, r4, r0
	  stw       r26, 0x0(r3)
	  beq-      .loc_0x88
	  lwz       r3, 0x0(r4)
	  lis       r0, 0x4330
	  stw       r26, 0x3C(r1)
	  lfd       f3, -0x7FA0(r2)
	  stw       r3, 0x44(r1)
	  lfs       f0, -0x7FA8(r2)
	  stw       r0, 0x40(r1)
	  stw       r0, 0x38(r1)
	  lfd       f2, 0x40(r1)
	  lfd       f1, 0x38(r1)
	  fsubs     f2, f2, f3
	  fsubs     f1, f1, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x88
	  li        r3, 0x7E
	  bl        -0x144

	.loc_0x88:
	  lis       r3, 0x8030
	  li        r28, 0
	  addi      r30, r3, 0x6660
	  li        r27, 0

	.loc_0x98:
	  add       r0, r30, r27
	  stw       r0, 0x30(r1)
	  lwz       r29, 0x30(r1)
	  addi      r26, r29, 0x1
	  lbz       r0, 0x1(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C8
	  lbz       r3, 0x0(r29)
	  bl        0x148
	  mr        r31, r3
	  lhz       r0, 0x2(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r12, 0xC(r29)
	  cmplwi    r12, 0
	  beq-      .loc_0xEC
	  addi      r3, r29, 0
	  li        r4, 0x2
	  mtlr      r12
	  blrl
	  sth       r3, 0x6(r29)

	.loc_0xEC:
	  li        r0, 0
	  sth       r0, 0x2(r31)
	  sth       r0, 0x0(r31)
	  lbz       r3, 0x0(r29)
	  bl        0x6C4
	  lbz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C8

	.loc_0x10C:
	  lhz       r0, 0x10A(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x154
	  lwz       r3, 0x10C(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x10C(r31)
	  lwz       r3, 0x10C(r31)
	  lhz       r0, 0x4(r29)
	  cmplw     r3, r0
	  bne-      .loc_0x154
	  lwz       r12, 0xC(r29)
	  cmplwi    r12, 0
	  beq-      .loc_0x154
	  addi      r3, r29, 0
	  li        r4, 0x4
	  mtlr      r12
	  blrl
	  sth       r3, 0x6(r29)

	.loc_0x154:
	  addi      r4, r29, 0xC
	  lwz       r0, 0xC(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C8
	  addi      r26, r29, 0x6
	  lhz       r3, 0x6(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  subi      r0, r3, 0x1
	  sth       r0, 0x0(r26)

	.loc_0x17C:
	  lhz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C8
	  lwz       r12, 0x0(r4)
	  addi      r3, r29, 0
	  li        r4, 0
	  mtlr      r12
	  blrl
	  sth       r3, 0x0(r26)
	  lhz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C8
	  li        r0, 0
	  li        r3, 0x1
	  sth       r0, 0x2(r31)
	  sth       r0, 0x0(r31)
	  bl        -0xA9C
	  lbz       r3, 0x0(r29)
	  bl        0x5FC

	.loc_0x1C8:
	  addi      r28, r28, 0x1
	  addi      r27, r27, 0x10
	  cmplwi    r28, 0x40
	  blt+      .loc_0x98
	  bl        -0x9B8
	  bl        0x1EA438
	  lmw       r26, 0x48(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}
