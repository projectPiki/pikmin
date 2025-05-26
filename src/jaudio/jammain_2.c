#include "jaudio/jammain_2.h"

#include "jaudio/oneshot.h"
#include "jaudio/jamosc.h"
#include "jaudio/seqsetup.h"
#include "jaudio/fat.h"

// TODO IN THIS FILE: What do the return values for the `Cmd_` functions signify?
// 0 is probably success / "no error".  Return values 1 and 2 have been observed.
// This just breaking: Cmd_LoopE returns 0x80.

typedef struct SEQ_ARG_t SEQ_ARG_t;

struct SEQ_ARG_t {
	u32 _00[5];          // _00 | Most likely unsigned.
	u8 _14[0x20 - 0x14]; // _10 | Is this whole struct actually just a u32[8]?
};

static seqp_* SEQ_P;
static u8 TRACK_LIST[0x100]; // TODO: placeholder
static SEQ_ARG_t SEQ_ARG;
static TrackCallback JAM_CALLBACK_FUNC = NULL;

/*
 * --INFO--
 * Address:	8000F400
 * Size:	000054
 */
void* Jam_OfsToAddr(seqp_* seq, u32 ofs)
{
	// TODO: What do 0, 1, and 2 mean?
	switch (seq->_3D) {
	case 0:
		return seq->_00 + ofs;
	case 1:
	case 2:
		return FAT_GetPointer(seq->_3E, ofs);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	8000F460
 * Size:	000054
 */
static u8 __ByteReadOfs(seqp_* seq, u32 ofs)
{
	// TODO: What do 0, 1, and 2 mean?
	switch (seq->_3D) {
	case 0:
		return seq->_00[ofs];
	case 1:
	case 2:
		return FAT_ReadByte(seq->_3E, ofs);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	8000F4C0
 * Size:	000050
 */
static u16 __WordReadOfs(seqp_* seq, u32 ofs)
{
	// TODO: FIXME
	return __ByteReadOfs(seq, ofs + 1) | (__ByteReadOfs(seq, ofs) << 8);
}

/*
 * --INFO--
 * Address:	8000F520
 * Size:	000068
 */
static u32 __24ReadOfs(seqp_* param_1, u32 param_2)
{
	// TODO: FIXME
	return (__ByteReadOfs(param_1, param_2 + 1) << 8) | (__ByteReadOfs(param_1, param_2 + 2) << 16) | __ByteReadOfs(param_1, param_2);
}

/*
 * --INFO--
 * Address:	8000F5A0
 * Size:	000050
 */
static u32 __LongReadOfs(seqp_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r31, r3, 0
	  addi      r30, r4, 0
	  bl        -0xF8
	  rlwinm    r0,r3,0,16,31
	  addi      r3, r31, 0
	  rlwinm    r31,r0,16,0,15
	  addi      r4, r30, 0x2
	  bl        -0x10C
	  rlwinm    r0,r3,0,16,31
	  or        r31, r31, r0
	  addi      r3, r31, 0
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000F600
 * Size:	000070
 */
static u8 __ByteRead(seqp_* seq)
{
	// TODO: What do 0, 1, and 2 mean?
	switch (seq->_3D) {
	case 0:
		return seq->_00[seq->_04++];
	case 1:
	case 2:
		return FAT_ReadByte(seq->_3E, seq->_04++);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	8000F680
 * Size:	000048
 */
static u16 __WordRead(seqp_* seq)
{
	return __ByteRead(seq) | (__ByteRead(seq) << 8);
}

/*
 * --INFO--
 * Address:	8000F6E0
 * Size:	00005C
 */
static void __24Read(seqp_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0xF4
	  rlwinm    r0,r3,0,24,31
	  addi      r3, r30, 0
	  rlwinm    r31,r0,16,0,15
	  bl        -0x104
	  rlwinm    r0,r3,0,24,31
	  addi      r3, r30, 0
	  rlwinm    r0,r0,8,0,23
	  or        r31, r31, r0
	  bl        -0x118
	  rlwinm    r0,r3,0,24,31
	  or        r31, r31, r0
	  addi      r3, r31, 0
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
 * Size:	000048
 */
static void __32Read(seqp_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000F740
 * Size:	0000D0
 */
static BOOL __ConditionCheck(seqp_* seq, u8 param_2)
{
	BOOL result;
	u16 uVar1;

	uVar1  = Jam_ReadRegDirect(seq, 3);
	result = FALSE;

	switch (param_2 & 0x0f) {
	case 0:
		result = TRUE;
		break;
	case 1:
		if (uVar1 == 0) {
			result = TRUE;
		}
		break;
	case 2:
		if (uVar1 != 0) {
			result = TRUE;
		}
		break;
	case 3:
		if (uVar1 == 1) {
			result = TRUE;
		}
		break;
	case 4:
		if (uVar1 >= 0x8000) {
			result = TRUE;
		}
		break;
	case 5:
		if (uVar1 < 0x8000) {
			result = TRUE;
		}
		break;
	}
	return result;
}

/*
 * --INFO--
 * Address:	8000F820
 * Size:	000090
 */
int Jam_SEQtimeToDSPtime(seqp_* seq, s32 param_2, u8 param_3)
{
	f32 result;

	result = (f32)param_2 * (f32)param_3 / 100.0f;
	if (seq->_33C == 1) {
		result = result / seq->_334;
	} else {
		result = result * 120.0f / seq->_338;
	}
	return result;
}

/*
 * --INFO--
 * Address:	8000F8C0
 * Size:	000020
 */
u16 Extend8to16(u8 value)
{
	if (value & 0x80)
		return value + 0xFF00;
	return value;
}

/*
 * --INFO--
 * Address:	8000F8E0
 * Size:	0001A8
 */
void Jam_WriteTimeParam(seqp_*, u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r26, r4, 0
	  li        r31, 0
	  bl        -0x2FC
	  rlwinm    r28,r26,0,24,31
	  addi      r29, r3, 0
	  rlwinm    r0,r26,0,28,29
	  cmplwi    r0, 0xC
	  bgt-      .loc_0x94
	  lis       r3, 0x8022
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r3, 0x5068
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  mr        r3, r30
	  bl        -0x330
	  rlwinm    r0,r3,1,23,30
	  add       r3, r30, r0
	  lha       r27, 0x26C(r3)
	  b         .loc_0x94
	  mr        r3, r30
	  bl        -0x348
	  rlwinm    r27,r3,0,24,31
	  b         .loc_0x94
	  mr        r3, r30
	  bl        -0x358
	  rlwinm    r0,r3,8,16,23
	  extsh     r27, r0
	  b         .loc_0x94
	  mr        r3, r30
	  bl        -0x2EC
	  mr        r27, r3

	.loc_0x94:
	  rlwinm    r0,r28,0,30,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0xE0
	  bge-      .loc_0xB4
	  cmpwi     r0, 0
	  beq-      .loc_0xC0
	  bge-      .loc_0xC8
	  b         .loc_0xFC

	.loc_0xB4:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xFC
	  b         .loc_0xF0

	.loc_0xC0:
	  li        r31, -0x1
	  b         .loc_0xFC

	.loc_0xC8:
	  mr        r3, r30
	  bl        -0x3AC
	  rlwinm    r0,r3,1,23,30
	  add       r3, r30, r0
	  lhz       r31, 0x26C(r3)
	  b         .loc_0xFC

	.loc_0xE0:
	  mr        r3, r30
	  bl        -0x3C4
	  rlwinm    r31,r3,0,24,31
	  b         .loc_0xFC

	.loc_0xF0:
	  mr        r3, r30
	  bl        -0x354
	  rlwinm    r31,r3,0,16,31

	.loc_0xFC:
	  extsh     r0, r27
	  rlwinm    r4,r29,4,20,27
	  xoris     r0, r0, 0x8000
	  addi      r4, r4, 0x14C
	  stw       r0, 0x1C(r1)
	  lis       r3, 0x4330
	  lfd       f2, -0x7F20(r2)
	  cmpwi     r31, 0
	  stw       r3, 0x18(r1)
	  add       r4, r30, r4
	  lfs       f0, -0x7F10(r2)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  stfs      f0, 0x4(r4)
	  blt-      .loc_0x154
	  xoris     r0, r31, 0x8000
	  stw       r0, 0x1C(r1)
	  stw       r3, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x8(r4)

	.loc_0x154:
	  lfs       f2, 0x8(r4)
	  lfs       f1, -0x7F0C(r2)
	  fcmpo     cr0, f2, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x180
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x0(r4)
	  stfs      f1, 0xC(r4)
	  lfs       f0, -0x7F08(r2)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x194

	.loc_0x180:
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x0(r4)
	  fsubs     f0, f1, f0
	  fdivs     f0, f0, f2
	  stfs      f0, 0xC(r4)

	.loc_0x194:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000FAA0
 * Size:	0000AC
 */
void Jam_WriteRegDirect(seqp_*, u8, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x20
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r29, r3, 0
	  addi      r30, r5, 0
	  bge-      .loc_0x3C
	  cmpwi     r0, 0x3
	  bge-      .loc_0x84
	  cmpwi     r0, 0
	  bge-      .loc_0x4C
	  b         .loc_0x84

	.loc_0x3C:
	  cmpwi     r0, 0x22
	  beq-      .loc_0x60
	  bge-      .loc_0x84
	  b         .loc_0x98

	.loc_0x4C:
	  rlwinm    r30,r30,0,24,31
	  addi      r3, r30, 0
	  bl        -0x234
	  b         .loc_0x88
	  b         .loc_0x98

	.loc_0x60:
	  rlwinm    r31,r30,0,16,31
	  addi      r3, r29, 0
	  li        r4, 0
	  rlwinm    r5,r30,24,24,31
	  bl        .loc_0x0
	  addi      r3, r30, 0
	  rlwinm    r30,r31,0,24,31
	  li        r31, 0x1
	  b         .loc_0x88

	.loc_0x84:
	  mr        r3, r30

	.loc_0x88:
	  rlwinm    r0,r31,1,23,30
	  add       r4, r29, r0
	  sth       r30, 0x26C(r4)
	  sth       r3, 0x272(r29)

	.loc_0x98:
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000FB60
 * Size:	000098
 */
static u32 LoadTbl(seqp_* seq, u32 param_2, u32 param_3, u32 param_4)
{
	// TODO: FIXME
	u32 result;

	switch (param_4) {
	case 2:
		result = __ByteReadOfs(seq, param_2 + param_3 * 1);
		break;
	case 3: // Without this case statement, the compiler-generated conditions look crazy.
	case 4:
		result = __WordReadOfs(seq, param_2 + param_3 * 2);
		break;
	case 6:
		result = __24ReadOfs(seq, param_2 + param_3 * 3);
		break;
	case 8:
		result = __LongReadOfs(seq, param_2 + param_3 * 4);
		break;
	}
	return result;
}

/*
 * --INFO--
 * Address:	8000FC00
 * Size:	000484
 */
void Jam_WriteRegParam(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,28,31
	  cmpwi     r0, 0xB
	  stwu      r1, -0x40(r1)
	  stmw      r23, 0x1C(r1)
	  addi      r31, r3, 0
	  rlwinm    r26,r4,0,28,29
	  rlwinm    r25,r4,0,30,31
	  bne-      .loc_0x30
	  li        r26, 0
	  li        r25, 0xB

	.loc_0x30:
	  cmpwi     r0, 0xA
	  bne-      .loc_0x54
	  mr        r3, r31
	  bl        -0x63C
	  addi      r4, r3, 0
	  rlwinm    r26,r3,0,28,29
	  rlwinm    r3,r3,28,28,31
	  li        r25, 0xA
	  addi      r24, r3, 0x4

	.loc_0x54:
	  rlwinm    r0,r4,0,28,31
	  cmpwi     r0, 0x9
	  bne-      .loc_0x80
	  mr        r3, r31
	  bl        -0x664
	  rlwinm    r0,r3,0,28,29
	  rlwinm    r25,r3,0,24,27
	  cmplwi    r0, 0x8
	  mr        r26, r0
	  bne-      .loc_0x80
	  li        r26, 0x10

	.loc_0x80:
	  mr        r3, r31
	  bl        -0x684
	  cmplwi    r25, 0xA
	  addi      r29, r3, 0
	  bne-      .loc_0xAC
	  mr        r3, r31
	  bl        -0x698
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x5DC
	  mr        r27, r3

	.loc_0xAC:
	  cmplwi    r26, 0x10
	  bgt-      .loc_0x120
	  lis       r3, 0x8022
	  rlwinm    r0,r26,2,0,29
	  addi      r3, r3, 0x509C
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  mr        r3, r31
	  bl        -0x6D0
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x3C4
	  mr        r30, r3
	  b         .loc_0x120
	  mr        r3, r31
	  bl        -0x6EC
	  rlwinm    r30,r3,0,24,31
	  b         .loc_0x120
	  mr        r3, r31
	  bl        -0x6FC
	  rlwinm    r0,r3,8,16,23
	  extsh     r30, r0
	  b         .loc_0x120
	  mr        r3, r31
	  bl        -0x690
	  mr        r30, r3
	  b         .loc_0x120
	  li        r30, -0x1

	.loc_0x120:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x378
	  cmpwi     r25, 0x20
	  addi      r23, r3, 0
	  beq-      .loc_0x258
	  bge-      .loc_0x188
	  cmpwi     r25, 0xA
	  beq-      .loc_0x2E0
	  bge-      .loc_0x170
	  cmpwi     r25, 0x2
	  beq-      .loc_0x1E0
	  bge-      .loc_0x164
	  cmpwi     r25, 0
	  beq-      .loc_0x2FC
	  bge-      .loc_0x1C4
	  b         .loc_0x2FC

	.loc_0x164:
	  cmpwi     r25, 0x4
	  bge-      .loc_0x2FC
	  b         .loc_0x1FC

	.loc_0x170:
	  cmpwi     r25, 0x10
	  beq-      .loc_0x210
	  bge-      .loc_0x2FC
	  cmpwi     r25, 0xC
	  bge-      .loc_0x2FC
	  b         .loc_0x208

	.loc_0x188:
	  cmpwi     r25, 0x50
	  beq-      .loc_0x2B0
	  bge-      .loc_0x1AC
	  cmpwi     r25, 0x40
	  beq-      .loc_0x2A8
	  bge-      .loc_0x2FC
	  cmpwi     r25, 0x30
	  beq-      .loc_0x2A0
	  b         .loc_0x2FC

	.loc_0x1AC:
	  cmpwi     r25, 0x90
	  beq-      .loc_0x2C0
	  bge-      .loc_0x2FC
	  cmpwi     r25, 0x60
	  beq-      .loc_0x2B8
	  b         .loc_0x2FC

	.loc_0x1C4:
	  cmplwi    r26, 0x4
	  bne-      .loc_0x1D8
	  rlwinm    r3,r30,0,24,31
	  bl        -0x510
	  mr        r30, r3

	.loc_0x1D8:
	  add       r30, r23, r30
	  b         .loc_0x2FC

	.loc_0x1E0:
	  extsh     r3, r23
	  extsh     r0, r30
	  mullw     r27, r3, r0
	  addi      r3, r31, 0
	  addi      r4, r27, 0
	  bl        0x4EC
	  b         .loc_0x470

	.loc_0x1FC:
	  sub       r0, r23, r30
	  sth       r0, 0x272(r31)
	  b         .loc_0x470

	.loc_0x208:
	  sub       r30, r23, r30
	  b         .loc_0x2FC

	.loc_0x210:
	  cmplwi    r26, 0x4
	  bne-      .loc_0x224
	  rlwinm    r3,r30,0,24,31
	  bl        -0x55C
	  mr        r30, r3

	.loc_0x224:
	  extsh.    r0, r30
	  bge-      .loc_0x244
	  extsh     r0, r30
	  rlwinm    r3,r23,0,16,31
	  neg       r0, r0
	  sraw      r0, r3, r0
	  extsh     r30, r0
	  b         .loc_0x2FC

	.loc_0x244:
	  rlwinm    r3,r23,0,16,31
	  extsh     r0, r30
	  slw       r0, r3, r0
	  extsh     r30, r0
	  b         .loc_0x2FC

	.loc_0x258:
	  cmplwi    r26, 0x4
	  bne-      .loc_0x26C
	  rlwinm    r3,r30,0,24,31
	  bl        -0x5A4
	  mr        r30, r3

	.loc_0x26C:
	  extsh.    r0, r30
	  bge-      .loc_0x28C
	  extsh     r0, r30
	  extsh     r3, r23
	  neg       r0, r0
	  sraw      r0, r3, r0
	  extsh     r30, r0
	  b         .loc_0x2FC

	.loc_0x28C:
	  extsh     r3, r23
	  extsh     r0, r30
	  slw       r0, r3, r0
	  extsh     r30, r0
	  b         .loc_0x2FC

	.loc_0x2A0:
	  and       r30, r23, r30
	  b         .loc_0x2FC

	.loc_0x2A8:
	  or        r30, r23, r30
	  b         .loc_0x2FC

	.loc_0x2B0:
	  xor       r30, r23, r30
	  b         .loc_0x2FC

	.loc_0x2B8:
	  neg       r30, r23
	  b         .loc_0x2FC

	.loc_0x2C0:
	  bl        -0x2780
	  rlwinm    r4,r30,0,16,31
	  addi      r27, r3, 0
	  divwu     r0, r27, r4
	  mullw     r0, r0, r4
	  sub       r0, r27, r0
	  extsh     r30, r0
	  b         .loc_0x2FC

	.loc_0x2E0:
	  addi      r3, r31, 0
	  addi      r4, r27, 0
	  addi      r6, r24, 0
	  extsh     r5, r30
	  bl        -0x390
	  addi      r27, r3, 0
	  rlwinm    r30,r3,0,16,31

	.loc_0x2FC:
	  rlwinm    r0,r29,0,24,31
	  cmpwi     r0, 0x22
	  beq-      .loc_0x3D4
	  bge-      .loc_0x32C
	  cmpwi     r0, 0x20
	  beq-      .loc_0x384
	  bge-      .loc_0x36C
	  cmpwi     r0, 0x3
	  bge-      .loc_0x410
	  cmpwi     r0, 0
	  bge-      .loc_0x358
	  b         .loc_0x410

	.loc_0x32C:
	  cmpwi     r0, 0x2E
	  beq-      .loc_0x3A0
	  bge-      .loc_0x34C
	  cmpwi     r0, 0x2C
	  bge-      .loc_0x410
	  cmpwi     r0, 0x28
	  bge-      .loc_0x400
	  b         .loc_0x410

	.loc_0x34C:
	  cmpwi     r0, 0x30
	  bge-      .loc_0x410
	  b         .loc_0x3B8

	.loc_0x358:
	  rlwinm    r30,r30,0,24,31
	  addi      r3, r30, 0
	  bl        -0x6A0
	  mr        r28, r3
	  b         .loc_0x414

	.loc_0x36C:
	  lhz       r3, 0x278(r31)
	  rlwinm    r0,r30,0,24,31
	  mr        r30, r0
	  li        r29, 0x6
	  rlwimi    r30,r3,0,16,23
	  b         .loc_0x414

	.loc_0x384:
	  lhz       r3, 0x278(r31)
	  extsh     r0, r30
	  li        r29, 0x6
	  rlwinm    r3,r3,0,24,31
	  addi      r30, r3, 0
	  rlwimi    r30,r0,8,0,23
	  b         .loc_0x414

	.loc_0x3A0:
	  lhz       r3, 0x286(r31)
	  rlwinm    r0,r30,0,24,31
	  mr        r30, r0
	  li        r29, 0xD
	  rlwimi    r30,r3,0,16,23
	  b         .loc_0x414

	.loc_0x3B8:
	  lhz       r3, 0x286(r31)
	  extsh     r0, r30
	  li        r29, 0xD
	  rlwinm    r3,r3,0,24,31
	  addi      r30, r3, 0
	  rlwimi    r30,r0,8,0,23
	  b         .loc_0x414

	.loc_0x3D4:
	  extsh     r23, r30
	  addi      r3, r31, 0
	  srawi     r0, r23, 0x8
	  li        r4, 0
	  rlwinm    r5,r0,0,16,31
	  bl        -0x548
	  rlwinm    r0,r23,0,24,31
	  li        r29, 0x1
	  extsh     r30, r0
	  addi      r28, r30, 0
	  b         .loc_0x414

	.loc_0x400:
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  stw       r27, 0x1EC(r3)
	  b         .loc_0x470

	.loc_0x410:
	  mr        r28, r30

	.loc_0x414:
	  rlwinm    r3,r29,0,24,31
	  rlwinm    r0,r29,1,23,30
	  cmplwi    r3, 0x6
	  add       r3, r31, r0
	  sth       r30, 0x26C(r3)
	  sth       r28, 0x272(r31)
	  bne-      .loc_0x438
	  mr        r3, r31
	  bl        0x4E0C

	.loc_0x438:
	  rlwinm    r0,r29,0,24,31
	  cmplwi    r0, 0x7
	  bne-      .loc_0x450
	  lwz       r0, 0x3D8(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0x3D8(r31)

	.loc_0x450:
	  rlwinm    r0,r29,0,24,31
	  cmplwi    r0, 0xD
	  bne-      .loc_0x470
	  lhz       r3, 0x286(r31)
	  li        r0, 0
	  oris      r3, r3, 0x1
	  stw       r3, 0x140(r31)
	  sth       r0, 0x144(r31)

	.loc_0x470:
	  lmw       r23, 0x1C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800100A0
 * Size:	00016C
 */
u16 Jam_ReadRegDirect(seqp_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  rlwinm    r31,r4,0,24,31
	  subi      r0, r31, 0x20
	  addi      r30, r3, 0
	  cmplwi    r0, 0x10
	  bgt-      .loc_0x10C
	  lis       r3, 0x8022
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r3, 0x50E0
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lha       r28, 0x278(r30)
	  b         .loc_0x118
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        .loc_0x0
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        .loc_0x0
	  rlwinm    r0,r3,8,8,23
	  or        r28, r0, r29
	  b         .loc_0x118
	  li        r0, 0x10
	  li        r28, 0
	  li        r3, 0x3C
	  mtctr     r0

	.loc_0x7C:
	  addi      r0, r3, 0x44
	  extsh     r4, r28
	  lwzx      r5, r30, r0
	  rlwinm    r0,r4,1,0,30
	  extsh     r28, r0
	  cmplwi    r5, 0
	  beq-      .loc_0xA8
	  lbz       r0, 0x3C(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  ori       r28, r28, 0x1

	.loc_0xA8:
	  subi      r3, r3, 0x4
	  bdnz+     .loc_0x7C
	  b         .loc_0x118
	  li        r28, 0
	  li        r29, 0x7

	.loc_0xBC:
	  extsh     r0, r28
	  addi      r3, r30, 0
	  rlwinm    r0,r0,1,0,30
	  addi      r4, r29, 0
	  extsh     r28, r0
	  bl        0x3BB0
	  subic.    r29, r29, 0x1
	  rlwinm    r0,r3,0,24,31
	  or        r28, r28, r0
	  bge+      .loc_0xBC
	  b         .loc_0x118
	  lwz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xFC
	  li        r28, 0
	  b         .loc_0x118

	.loc_0xFC:
	  rlwinm    r0,r0,1,0,30
	  add       r3, r30, r0
	  lha       r28, 0x2A(r3)
	  b         .loc_0x118

	.loc_0x10C:
	  rlwinm    r0,r4,1,23,30
	  add       r3, r30, r0
	  lha       r28, 0x26C(r3)

	.loc_0x118:
	  cmpwi     r31, 0x20
	  beq-      .loc_0x148
	  bge-      .loc_0x138
	  cmpwi     r31, 0x3
	  bge-      .loc_0x154
	  cmpwi     r31, 0
	  bge-      .loc_0x140
	  b         .loc_0x154

	.loc_0x138:
	  cmpwi     r31, 0x22
	  bge-      .loc_0x154

	.loc_0x140:
	  rlwinm    r28,r28,0,24,31
	  b         .loc_0x154

	.loc_0x148:
	  extsh     r0, r28
	  srawi     r0, r0, 0x8
	  extsh     r28, r0

	.loc_0x154:
	  mr        r3, r28
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010220
 * Size:	000048
 */
void Jam_ReadRegXY(seqp_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x198
	  rlwinm    r31,r3,0,16,31
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        -0x1A8
	  rlwinm    r0,r3,16,0,15
	  or        r3, r0, r31
	  lmw       r30, 0x10(r1)
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010280
 * Size:	00005C
 */
u32 Jam_ReadReg32(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x28
	  stwu      r1, -0x8(r1)
	  bge-      .loc_0x24
	  cmpwi     r0, 0x23
	  beq-      .loc_0x3C
	  b         .loc_0x44

	.loc_0x24:
	  cmpwi     r0, 0x2C
	  bge-      .loc_0x44
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0x1EC(r3)
	  b         .loc_0x4C

	.loc_0x3C:
	  bl        -0x9C
	  b         .loc_0x4C

	.loc_0x44:
	  bl        -0x224
	  rlwinm    r3,r3,0,16,31

	.loc_0x4C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800102E0
 * Size:	000048
 */
void Jam_WriteRegXY(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r5,r4,16,16,31
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  li        r4, 0x4
	  bl        -0x860
	  addi      r3, r30, 0
	  rlwinm    r5,r31,0,16,31
	  li        r4, 0x5
	  bl        -0x870
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010340
 * Size:	00003C
 */
u32 __ExchangeRegisterValue(seqp_* param_1, u8 param_2)
{
	// TODO: This used to be able to match, but seqsetup.c's `Init_Track` provided intel about members that conflicts with this function.

	// // TODO: This looks like a bounds-check for the array accessed below.
	// if (param_2 < 0x40) {
	// 	return Jam_ReadReg32();
	// }
	// return param_1->_1F2[param_2 * 2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Jam_WritePortApp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Jam_ReadPortApp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Jam_CheckExportApp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Jam_CheckImportApp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void Jam_WritePortIndirect(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Jam_ReadPortIndirect(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void Jam_CheckPortIndirect(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80010380
 * Size:	000078
 */
s32 Jam_WritePortAppDirect(seqp_*, u8, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r30, 0x18(r1)
	  mr.       r30, r3
	  addi      r31, r4, 0
	  bne-      .loc_0x24
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x24:
	  rlwinm    r0,r31,2,0,29
	  cmplwi    r31, 0
	  add       r3, r30, r0
	  li        r0, 0x1
	  sth       r5, 0x2F2(r3)
	  stb       r0, 0x2F0(r3)
	  bne-      .loc_0x4C
	  addi      r3, r30, 0
	  li        r4, 0x3
	  bl        0x1358

	.loc_0x4C:
	  cmplwi    r31, 0x1
	  bne-      .loc_0x60
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        0x1344

	.loc_0x60:
	  li        r3, 0x1

	.loc_0x64:
	  lwz       r0, 0x24(r1)
	  lmw       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010400
 * Size:	000030
 */
s32 Jam_ReadPortAppDirect(seqp_*, u32, u16*)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0
	  bne-      .loc_0x10
	  li        r3, 0
	  blr

	.loc_0x10:
	  rlwinm    r4,r4,2,0,29
	  li        r0, 0
	  add       r6, r3, r4
	  li        r3, 0x1
	  lhz       r4, 0x2F2(r6)
	  sth       r4, 0x0(r5)
	  stb       r0, 0x2F1(r6)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010440
 * Size:	00006C
 */
s32 Jam_CheckPortAppDirect(seqp_*, u32, u16)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r5,0,24,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x40
	  bge-      .loc_0x64
	  cmpwi     r0, 0
	  bge-      .loc_0x1C
	  b         .loc_0x64

	.loc_0x1C:
	  rlwinm    r0,r4,2,0,29
	  add       r3, r3, r0
	  lbz       r0, 0x2F1(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  li        r3, 0
	  blr

	.loc_0x38:
	  li        r3, 0x1
	  blr

	.loc_0x40:
	  rlwinm    r0,r4,2,0,29
	  add       r3, r3, r0
	  lbz       r0, 0x2F0(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x5C
	  li        r3, 0
	  blr

	.loc_0x5C:
	  li        r3, 0x1
	  blr

	.loc_0x64:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Jam_WritePort(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Jam_ReadPort(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Jam_WritePortChild(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Jam_WritePortBros(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800104C0
 * Size:	000030
 */
void Jam_InitRegistTrack(void)
{
	/*
	.loc_0x0:
	  li        r6, 0
	  lis       r4, 0x8032
	  li        r0, 0x20
	  addi      r3, r6, 0
	  stw       r6, 0x2C2C(r13)
	  subi      r5, r4, 0x680
	  mtctr     r0

	.loc_0x1C:
	  add       r4, r5, r3
	  addi      r3, r3, 0x8
	  stw       r6, 0x0(r4)
	  bdnz+     .loc_0x1C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010500
 * Size:	0000A8
 */
void Jam_RegistTrack(seqp_*, u32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  stw       r4, 0xC(r1)
	  lis       r4, 0x8032
	  lwz       r7, 0x2C2C(r13)
	  subi      r5, r4, 0x680
	  lwz       r6, 0xC(r1)
	  li        r4, 0
	  mtctr     r7
	  cmplwi    r7, 0
	  ble-      .loc_0x40

	.loc_0x28:
	  addi      r0, r4, 0x4
	  lwzx      r0, r5, r0
	  cmplw     r6, r0
	  beq-      .loc_0xA0
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x28

	.loc_0x40:
	  cmplwi    r7, 0x20
	  bne-      .loc_0x7C
	  li        r0, 0x20
	  li        r7, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x58:
	  lwzx      r0, r5, r4
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x58

	.loc_0x70:
	  cmplwi    r7, 0x20
	  bne-      .loc_0x88
	  b         .loc_0xA0

	.loc_0x7C:
	  lwz       r4, 0x2C2C(r13)
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C2C(r13)

	.loc_0x88:
	  rlwinm    r7,r7,3,0,28
	  li        r0, 0x1
	  add       r4, r5, r7
	  stw       r6, 0x4(r4)
	  stwx      r3, r5, r7
	  stb       r0, 0x3E2(r3)

	.loc_0xA0:
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800105C0
 * Size:	00008C
 */
void Jam_UnRegistTrack(seqp_*)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x3E2(r3)
	  cmplwi    r0, 0
	  beqlr-
	  lwz       r7, 0x2C2C(r13)
	  li        r4, 0
	  lis       r5, 0x8032
	  addi      r0, r4, 0
	  subi      r6, r5, 0x680
	  mtctr     r7
	  cmplwi    r7, 0
	  ble-      .loc_0x48

	.loc_0x2C:
	  add       r7, r6, r4
	  lwz       r5, 0x0(r7)
	  cmplw     r3, r5
	  bne-      .loc_0x40
	  stw       r0, 0x0(r7)

	.loc_0x40:
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x2C

	.loc_0x48:
	  li        r0, 0
	  lis       r4, 0x8032
	  stb       r0, 0x3E2(r3)
	  subi      r4, r4, 0x680
	  b         .loc_0x7C

	.loc_0x5C:
	  rlwinm    r0,r0,3,0,28
	  add       r3, r4, r0
	  lwz       r0, -0x8(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lwz       r3, 0x2C2C(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2C2C(r13)

	.loc_0x7C:
	  lwz       r0, 0x2C2C(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x5C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010660
 * Size:	000050
 */
seqp_* Jam_GetTrackHandle(u32)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2C2C(r13)
	  lis       r4, 0x8032
	  subi      r5, r4, 0x680
	  li        r4, 0
	  mtctr     r0
	  cmplwi    r0, 0
	  ble-      .loc_0x48

	.loc_0x1C:
	  add       r6, r5, r4
	  lwz       r0, 0x4(r6)
	  cmplw     r3, r0
	  bne-      .loc_0x40
	  lwz       r0, 0x0(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  mr        r3, r0
	  blr

	.loc_0x40:
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x1C

	.loc_0x48:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800106C0
 * Size:	000018
 */
void Jam_InitExtBuffer(int*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  sth       r0, 0x8(r3)
	  sth       r0, 0xA(r3)
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800106E0
 * Size:	000038
 */
BOOL Jam_AssignExtBuffer(seqp_*, int*)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0
	  bne-      .loc_0x10
	  li        r3, 0
	  blr

	.loc_0x10:
	  cmplwi    r4, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  blr

	.loc_0x20:
	  stw       r4, 0x2AC(r3)
	  li        r3, 0x1
	  lwz       r5, 0x4(r4)
	  addi      r0, r5, 0x1
	  stw       r0, 0x4(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010720
 * Size:	000060
 */
void Jam_AssignExtBufferP(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x1C
	  li        r3, 0
	  b         .loc_0x50

	.loc_0x1C:
	  cmplwi    r5, 0
	  bne-      .loc_0x2C
	  li        r3, 0
	  b         .loc_0x50

	.loc_0x2C:
	  rlwinm    r6,r4,2,22,29
	  li        r0, 0x1
	  add       r3, r3, r6
	  addi      r4, r5, 0
	  stw       r5, 0x2B0(r3)
	  stw       r0, 0x0(r5)
	  lwz       r3, 0x44(r3)
	  bl        -0x88
	  li        r3, 0x1

	.loc_0x50:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010780
 * Size:	000044
 */
void Jam_SetExtFirFilterD(u16*, void*)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0
	  beqlr-
	  lhz       r6, 0xA(r3)
	  li        r0, 0x8
	  li        r5, 0
	  ori       r6, r6, 0x80
	  sth       r6, 0xA(r3)
	  lhz       r6, 0x8(r3)
	  ori       r6, r6, 0x80
	  sth       r6, 0x8(r3)
	  mtctr     r0

	.loc_0x2C:
	  lhax      r6, r4, r5
	  addi      r0, r5, 0x24
	  addi      r5, r5, 0x2
	  sthx      r6, r3, r0
	  bdnz+     .loc_0x2C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800107E0
 * Size:	0000A4
 */
void Jam_SetExtParamD(f32, int*, int)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0
	  beqlr-
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x8
	  beq-      .loc_0x78
	  bge-      .loc_0x40
	  cmpwi     r0, 0x3
	  beqlr-
	  bge-      .loc_0x34
	  cmpwi     r0, 0x1
	  beq-      .loc_0x58
	  bge-      .loc_0x60
	  blr

	.loc_0x34:
	  cmpwi     r0, 0x5
	  bgelr-
	  b         .loc_0x68

	.loc_0x40:
	  cmpwi     r0, 0x40
	  beq-      .loc_0x80
	  bgelr-
	  cmpwi     r0, 0x10
	  beq-      .loc_0x70
	  blr

	.loc_0x58:
	  addi      r5, r3, 0xC
	  b         .loc_0x8C

	.loc_0x60:
	  addi      r5, r3, 0x18
	  b         .loc_0x8C

	.loc_0x68:
	  addi      r5, r3, 0x10
	  b         .loc_0x8C

	.loc_0x70:
	  addi      r5, r3, 0x14
	  b         .loc_0x8C

	.loc_0x78:
	  addi      r5, r3, 0x1C
	  b         .loc_0x8C

	.loc_0x80:
	  addi      r5, r3, 0x20
	  b         .loc_0x8C
	  blr

	.loc_0x8C:
	  stfs      f1, 0x0(r5)
	  rlwinm    r0,r4,0,24,31
	  lhz       r4, 0xA(r3)
	  or        r0, r4, r0
	  sth       r0, 0xA(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800108A0
 * Size:	000024
 */
void Jam_OnExtSwitchD(int*, int)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0
	  beqlr-
	  lhz       r0, 0x8(r3)
	  or        r0, r0, r4
	  sth       r0, 0x8(r3)
	  lhz       r0, 0xA(r3)
	  or        r0, r0, r4
	  sth       r0, 0xA(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800108E0
 * Size:	000028
 */
void Jam_OffExtSwitchD(void)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0
	  beqlr-
	  lhz       r5, 0x8(r3)
	  and       r0, r5, r4
	  xor       r0, r5, r0
	  sth       r0, 0x8(r3)
	  lhz       r0, 0xA(r3)
	  or        r0, r0, r4
	  sth       r0, 0xA(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Jam_SetExtSwitchDirectD(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Jam_SetExtFirFilter(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80010920
 * Size:	00002C
 */
void Jam_SetExtParam(f32, int*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  lwz       r3, 0x2AC(r3)
	  bl        -0x158

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010960
 * Size:	00002C
 */
void Jam_OnExtSwitch(int*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  lwz       r3, 0x2AC(r3)
	  bl        -0xD8

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800109A0
 * Size:	00002C
 */
void Jam_OffExtSwitch(int*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  lwz       r3, 0x2AC(r3)
	  bl        -0xD8

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Jam_SetExtSwitchDirect(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Jam_SetExtFirFilterP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800109E0
 * Size:	000038
 */
void Jam_SetExtParamP(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x28
	  rlwinm    r0,r4,2,22,29
	  addi      r4, r5, 0
	  add       r3, r3, r0
	  lwz       r3, 0x2B0(r3)
	  bl        -0x224

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010A20
 * Size:	00003C
 */
void Jam_OnExtSwitchP(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x2C
	  rlwinm    r0,r4,0,24,31
	  addi      r4, r5, 0
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0x2B0(r3)
	  bl        -0x1A8

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Jam_OffExtSwitchP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Jam_SetExtSwitchDirectP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Jam_CheckRunningCounter(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80010A60
 * Size:	00000C
 */
BOOL Jam_RegisterTrackCallback(TrackCallback callback)
{
	JAM_CALLBACK_FUNC = callback;
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Jam_SetTrackExtPanPower(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80010A80
 * Size:	00004C
 */
static f32 __PanCalc(f32 param_1, f32 param_2, f32 param_3, u8 param_4)
{
	f32 result;

	switch (param_4) {
	case 0:
		return param_1;
	case 1:
		return param_2;
	case 2:
		result = param_1 * (1.0f - param_3) + (param_2 * param_3);
	}
	return result;
}

/*
 * --INFO--
 * Address:	80010AE0
 * Size:	000320
 */
void Jam_UpdateTrackAll(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  addi      r11, r1, 0x60
	  bl        0x204364
	  stmw      r29, 0x24(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x4330
	  lhz       r4, 0x282(r31)
	  lbz       r0, 0x3F(r31)
	  stw       r4, 0x1C(r1)
	  lfd       f2, -0x7F18(r2)
	  cmplwi    r0, 0x4
	  stw       r3, 0x18(r1)
	  lfs       f0, -0x7F04(r2)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f2
	  fdivs     f26, f1, f0
	  beq-      .loc_0x304
	  lhz       r0, 0x286(r31)
	  li        r30, 0
	  addi      r3, r1, 0x10
	  addi      r4, r1, 0xC
	  oris      r0, r0, 0x1
	  li        r29, 0
	  stw       r0, 0x140(r31)
	  sth       r30, 0x144(r31)
	  lfs       f1, -0x7F00(r2)
	  lfs       f0, 0x25C(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x10(r1)
	  bl        .loc_0x320
	  lbz       r3, 0xC(r1)
	  extsb.    r0, r3
	  bge-      .loc_0x94
	  neg       r29, r3
	  stb       r30, 0xC(r1)

	.loc_0x94:
	  li        r0, 0x10
	  stb       r0, 0x138(r31)
	  stb       r29, 0x132(r31)
	  lbz       r0, 0xC(r1)
	  stb       r0, 0x133(r31)
	  lbz       r0, 0x39E(r31)
	  lfs       f30, 0x14C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xBC
	  lfs       f30, -0x7F0C(r2)

	.loc_0xBC:
	  lhz       r3, 0x27A(r31)
	  lis       r0, 0x4330
	  lfd       f2, -0x7F18(r2)
	  stw       r3, 0x1C(r1)
	  lfs       f1, 0x15C(r31)
	  stw       r0, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f2, f0, f2
	  bl        0x4004
	  lwz       r3, 0x2AC(r31)
	  fmr       f31, f1
	  lfs       f29, 0x17C(r31)
	  cmplwi    r3, 0
	  lfs       f28, 0x16C(r31)
	  lfs       f27, 0x18C(r31)
	  beq-      .loc_0x190
	  lhz       r4, 0x8(r3)
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x110
	  lfs       f0, 0xC(r3)
	  fmuls     f30, f30, f0

	.loc_0x110:
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x120
	  lfs       f0, 0x18(r3)
	  fmuls     f31, f31, f0

	.loc_0x120:
	  rlwinm.   r0,r4,0,29,29
	  beq-      .loc_0x140
	  fmr       f1, f28
	  lfs       f2, 0x10(r3)
	  fmr       f3, f26
	  lbz       r3, 0x3DD(r31)
	  bl        -0x198
	  fmr       f28, f1

	.loc_0x140:
	  lwz       r3, 0x2AC(r31)
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x168
	  fmr       f1, f27
	  lfs       f2, 0x14(r3)
	  fmr       f3, f26
	  lbz       r3, 0x3DE(r31)
	  bl        -0x1C0
	  fmr       f27, f1

	.loc_0x168:
	  lwz       r3, 0x2AC(r31)
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x190
	  fmr       f1, f29
	  lfs       f2, 0x1C(r3)
	  fmr       f3, f26
	  lbz       r3, 0x3DC(r31)
	  bl        -0x1E8
	  fmr       f29, f1

	.loc_0x190:
	  lwz       r4, 0x40(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x1A8
	  lbz       r0, 0x3F(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x1C0

	.loc_0x1A8:
	  stfs      f30, 0xF0(r31)
	  stfs      f31, 0xF4(r31)
	  stfs      f29, 0xF8(r31)
	  stfs      f28, 0xFC(r31)
	  stfs      f27, 0x100(r31)
	  b         .loc_0x304

	.loc_0x1C0:
	  lhz       r3, 0x284(r31)
	  lis       r0, 0x4330
	  lfs       f0, 0xF0(r4)
	  fmr       f1, f29
	  stw       r3, 0x1C(r1)
	  lfd       f4, -0x7F18(r2)
	  fmuls     f0, f0, f30
	  stw       r0, 0x18(r1)
	  lfs       f2, -0x7F04(r2)
	  lfd       f3, 0x18(r1)
	  stfs      f0, 0xF0(r31)
	  fsubs     f0, f3, f4
	  lwz       r3, 0x40(r31)
	  fdivs     f26, f0, f2
	  lfs       f0, 0xF4(r3)
	  fmuls     f0, f0, f31
	  fmr       f3, f26
	  stfs      f0, 0xF4(r31)
	  lwz       r4, 0x40(r31)
	  lbz       r3, 0x3DF(r31)
	  lfs       f2, 0xF8(r4)
	  bl        -0x274
	  stfs      f1, 0xF8(r31)
	  fmr       f1, f28
	  fmr       f3, f26
	  lwz       r4, 0x40(r31)
	  lbz       r3, 0x3E0(r31)
	  lfs       f2, 0xFC(r4)
	  bl        -0x290
	  stfs      f1, 0xFC(r31)
	  fmr       f1, f27
	  fmr       f3, f26
	  lwz       r4, 0x40(r31)
	  lbz       r3, 0x3E1(r31)
	  lfs       f2, 0x100(r4)
	  bl        -0x2AC
	  stfs      f1, 0x100(r31)
	  lwz       r3, 0x2AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x29C
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,24,24
	  beq-      .loc_0x29C
	  li        r0, 0x8
	  li        r3, 0
	  mtctr     r0

	.loc_0x278:
	  lwz       r5, 0x2AC(r31)
	  addi      r4, r3, 0x24
	  addi      r0, r3, 0x104
	  addi      r3, r3, 0x2
	  lhax      r4, r5, r4
	  sthx      r4, r31, r0
	  bdnz+     .loc_0x278
	  li        r0, 0x8
	  stb       r0, 0x139(r31)

	.loc_0x29C:
	  li        r0, 0x4
	  lfs       f1, -0x7F04(r2)
	  li        r3, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x2B0:
	  addi      r5, r4, 0x20C
	  addi      r0, r3, 0x114
	  lfsx      f0, r31, r5
	  addi      r3, r3, 0x2
	  addi      r4, r4, 0x10
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r5, 0x1C(r1)
	  sthx      r5, r31, r0
	  bdnz+     .loc_0x2B0
	  lbz       r0, 0x139(r31)
	  ori       r0, r0, 0x20
	  stb       r0, 0x139(r31)
	  lfs       f1, -0x7F04(r2)
	  lfs       f0, 0x19C(r31)
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  sth       r0, 0x124(r31)

	.loc_0x304:
	  lwz       r0, 0x64(r1)
	  addi      r11, r1, 0x60
	  bl        0x2040B4
	  lmw       r29, 0x24(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr

	.loc_0x320:
	*/
}

/*
 * --INFO--
 * Address:	80010E00
 * Size:	00000C
 */
extern "C" static void OSf32tos8(f32* in, s8* out)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x0(r3)
	  psq_st    f1,0x0(r4),0x1,0x4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80010E20
 * Size:	0004A8
 */
void Jam_UpdateTrack(seqp_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  addi      r11, r1, 0x78
	  bl        0x204024
	  stmw      r23, 0x24(r1)
	  addi      r25, r3, 0
	  lis       r3, 0x4330
	  lhz       r5, 0x282(r25)
	  mr        r26, r4
	  lbz       r0, 0x3F(r25)
	  stw       r5, 0x1C(r1)
	  lfd       f2, -0x7F18(r2)
	  cmplwi    r0, 0x4
	  stw       r3, 0x18(r1)
	  lfs       f0, -0x7F04(r2)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f2
	  fdivs     f26, f1, f0
	  beq-      .loc_0x48C
	  rlwinm.   r0,r26,0,14,14
	  beq-      .loc_0x9C
	  lfs       f1, -0x7F00(r2)
	  addi      r3, r1, 0x14
	  lfs       f0, 0x25C(r25)
	  addi      r4, r1, 0x10
	  li        r23, 0
	  fmuls     f0, f1, f0
	  stfs      f0, 0x14(r1)
	  bl        -0x94
	  lbz       r3, 0x10(r1)
	  extsb.    r0, r3
	  bge-      .loc_0x90
	  li        r0, 0
	  neg       r23, r3
	  stb       r0, 0x10(r1)

	.loc_0x90:
	  stb       r23, 0x132(r25)
	  lbz       r0, 0x10(r1)
	  stb       r0, 0x133(r25)

	.loc_0x9C:
	  rlwinm.   r0,r26,0,25,25
	  beq-      .loc_0xB8
	  lwz       r0, 0x40(r25)
	  cmplwi    r0, 0
	  bne-      .loc_0xB8
	  mr        r3, r25
	  bl        0x40C

	.loc_0xB8:
	  rlwinm.   r31,r26,0,31,31
	  beq-      .loc_0x114
	  lbz       r0, 0x39E(r25)
	  lfs       f31, 0x14C(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0xD4
	  lfs       f31, -0x7F0C(r2)

	.loc_0xD4:
	  lwz       r3, 0x2AC(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0xF4
	  lfs       f0, 0xC(r3)
	  fmuls     f31, f31, f0

	.loc_0xF4:
	  lbz       r0, 0x39C(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0x114
	  lbz       r0, 0x39D(r25)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x114
	  lfs       f0, 0x24C(r25)
	  fmuls     f31, f31, f0

	.loc_0x114:
	  rlwinm.   r30,r26,0,30,30
	  beq-      .loc_0x164
	  lhz       r3, 0x27A(r25)
	  lis       r0, 0x4330
	  lfd       f2, -0x7F18(r2)
	  stw       r3, 0x1C(r1)
	  lfs       f1, 0x15C(r25)
	  stw       r0, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f2, f0, f2
	  bl        0x3C64
	  lwz       r3, 0x2AC(r25)
	  fmr       f30, f1
	  cmplwi    r3, 0
	  beq-      .loc_0x164
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x164
	  lfs       f0, 0x18(r3)
	  fmuls     f30, f30, f0

	.loc_0x164:
	  rlwinm.   r29,r26,0,28,28
	  beq-      .loc_0x1A0
	  lwz       r3, 0x2AC(r25)
	  lfs       f29, 0x17C(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A0
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x1A0
	  fmr       f1, f29
	  lfs       f2, 0x1C(r3)
	  fmr       f3, f26
	  lbz       r3, 0x3DC(r25)
	  bl        -0x538
	  fmr       f29, f1

	.loc_0x1A0:
	  rlwinm.   r28,r26,0,29,29
	  beq-      .loc_0x1DC
	  lwz       r3, 0x2AC(r25)
	  lfs       f28, 0x16C(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x1DC
	  fmr       f1, f28
	  lfs       f2, 0x10(r3)
	  fmr       f3, f26
	  lbz       r3, 0x3DD(r25)
	  bl        -0x574
	  fmr       f28, f1

	.loc_0x1DC:
	  rlwinm.   r27,r26,0,27,27
	  beq-      .loc_0x218
	  lwz       r3, 0x2AC(r25)
	  lfs       f27, 0x18C(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x218
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x218
	  fmr       f1, f27
	  lfs       f2, 0x14(r3)
	  fmr       f3, f26
	  lbz       r3, 0x3DE(r25)
	  bl        -0x5B0
	  fmr       f27, f1

	.loc_0x218:
	  rlwinm.   r0,r26,0,16,19
	  beq-      .loc_0x26C
	  li        r0, 0x4
	  lfs       f1, -0x7F04(r2)
	  li        r3, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x234:
	  addi      r5, r4, 0x20C
	  addi      r0, r3, 0x114
	  lfsx      f0, r25, r5
	  addi      r3, r3, 0x2
	  addi      r4, r4, 0x10
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r5, 0x1C(r1)
	  sthx      r5, r25, r0
	  bdnz+     .loc_0x234
	  lbz       r0, 0x139(r25)
	  ori       r0, r0, 0x20
	  stb       r0, 0x139(r25)

	.loc_0x26C:
	  lwz       r3, 0x2AC(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C4
	  rlwinm.   r0,r26,0,24,24
	  beq-      .loc_0x2C4
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,24,24
	  beq-      .loc_0x2C4
	  li        r0, 0x8
	  li        r3, 0
	  mtctr     r0

	.loc_0x298:
	  lwz       r5, 0x2AC(r25)
	  addi      r4, r3, 0x24
	  addi      r0, r3, 0x104
	  addi      r3, r3, 0x2
	  lhax      r4, r5, r4
	  sthx      r4, r25, r0
	  bdnz+     .loc_0x298
	  lbz       r0, 0x139(r25)
	  rlwinm    r3,r0,0,26,26
	  addi      r0, r3, 0x8
	  stb       r0, 0x139(r25)

	.loc_0x2C4:
	  rlwinm.   r0,r26,0,26,26
	  beq-      .loc_0x2E8
	  lfs       f1, -0x7F04(r2)
	  lfs       f0, 0x19C(r25)
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  sth       r0, 0x124(r25)

	.loc_0x2E8:
	  li        r23, 0
	  li        r26, 0

	.loc_0x2F0:
	  addi      r0, r23, 0x370
	  lbzx      r0, r25, r0
	  cmplwi    r0, 0xE
	  bne-      .loc_0x368
	  add       r3, r25, r26
	  addi      r24, r3, 0x340
	  addi      r4, r3, 0x3E8
	  addi      r3, r24, 0
	  bl        -0x3DF0
	  lbz       r0, 0x0(r24)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x354
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  beq-      .loc_0x34C
	  bge-      .loc_0x344
	  b         .loc_0x368

	.loc_0x334:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x364
	  bge-      .loc_0x368
	  b         .loc_0x35C

	.loc_0x344:
	  fmuls     f30, f30, f1
	  b         .loc_0x368

	.loc_0x34C:
	  fmuls     f31, f31, f1
	  b         .loc_0x368

	.loc_0x354:
	  fmuls     f29, f29, f1
	  b         .loc_0x368

	.loc_0x35C:
	  fmuls     f28, f28, f1
	  b         .loc_0x368

	.loc_0x364:
	  fmuls     f27, f27, f1

	.loc_0x368:
	  addi      r23, r23, 0x1
	  addi      r26, r26, 0x18
	  cmplwi    r23, 0x2
	  blt+      .loc_0x2F0
	  lwz       r4, 0x40(r25)
	  cmplwi    r4, 0
	  beq-      .loc_0x390
	  lbz       r0, 0x3F(r25)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x3D0

	.loc_0x390:
	  cmplwi    r31, 0
	  beq-      .loc_0x39C
	  stfs      f31, 0xF0(r25)

	.loc_0x39C:
	  cmplwi    r30, 0
	  beq-      .loc_0x3A8
	  stfs      f30, 0xF4(r25)

	.loc_0x3A8:
	  cmplwi    r29, 0
	  beq-      .loc_0x3B4
	  stfs      f29, 0xF8(r25)

	.loc_0x3B4:
	  cmplwi    r28, 0
	  beq-      .loc_0x3C0
	  stfs      f28, 0xFC(r25)

	.loc_0x3C0:
	  cmplwi    r27, 0
	  beq-      .loc_0x48C
	  stfs      f27, 0x100(r25)
	  b         .loc_0x48C

	.loc_0x3D0:
	  lhz       r3, 0x284(r25)
	  lis       r0, 0x4330
	  lfd       f2, -0x7F18(r2)
	  cmplwi    r31, 0
	  stw       r3, 0x1C(r1)
	  lfs       f0, -0x7F04(r2)
	  stw       r0, 0x18(r1)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f2
	  fdivs     f26, f1, f0
	  beq-      .loc_0x408
	  lfs       f0, 0xF0(r4)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xF0(r25)

	.loc_0x408:
	  cmplwi    r30, 0
	  beq-      .loc_0x420
	  lwz       r3, 0x40(r25)
	  lfs       f0, 0xF4(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0xF4(r25)

	.loc_0x420:
	  cmplwi    r29, 0
	  beq-      .loc_0x444
	  lwz       r4, 0x40(r25)
	  fmr       f1, f29
	  fmr       f3, f26
	  lbz       r3, 0x3DF(r25)
	  lfs       f2, 0xF8(r4)
	  bl        -0x7DC
	  stfs      f1, 0xF8(r25)

	.loc_0x444:
	  cmplwi    r28, 0
	  beq-      .loc_0x468
	  lwz       r4, 0x40(r25)
	  fmr       f1, f28
	  fmr       f3, f26
	  lbz       r3, 0x3E0(r25)
	  lfs       f2, 0xFC(r4)
	  bl        -0x800
	  stfs      f1, 0xFC(r25)

	.loc_0x468:
	  cmplwi    r27, 0
	  beq-      .loc_0x48C
	  lwz       r4, 0x40(r25)
	  fmr       f1, f27
	  fmr       f3, f26
	  lbz       r3, 0x3E1(r25)
	  lfs       f2, 0x100(r4)
	  bl        -0x824
	  stfs      f1, 0x100(r25)

	.loc_0x48C:
	  lwz       r0, 0x7C(r1)
	  addi      r11, r1, 0x78
	  bl        0x203BEC
	  lmw       r23, 0x24(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800112E0
 * Size:	000104
 */
void Jam_UpdateTempo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x40(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x94
	  lfs       f1, -0x7EFC(r2)
	  lis       r3, 0x4330
	  lfs       f0, -0x8000(r13)
	  lhz       r4, 0x338(r31)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x7EF8(r2)
	  lhz       r0, 0x33A(r31)
	  stw       r4, 0x24(r1)
	  fdivs     f0, f1, f0
	  lfd       f3, -0x7F18(r2)
	  stw       r0, 0x1C(r1)
	  stw       r3, 0x20(r1)
	  stw       r3, 0x18(r1)
	  lfd       f2, 0x20(r1)
	  lfd       f1, 0x18(r1)
	  fsubs     f2, f2, f3
	  fsubs     f1, f1, f3
	  fmuls     f1, f2, f1
	  fdivs     f0, f1, f0
	  stfs      f0, 0x334(r31)
	  lwz       r3, 0x2AC(r31)
	  lhz       r0, 0x8(r3)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0xA8
	  lfs       f1, 0x334(r31)
	  lfs       f0, 0x20(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x334(r31)
	  b         .loc_0xA8

	.loc_0x94:
	  lfs       f0, 0x334(r3)
	  stfs      f0, 0x334(r31)
	  lwz       r3, 0x40(r31)
	  lhz       r0, 0x338(r3)
	  sth       r0, 0x338(r31)

	.loc_0xA8:
	  li        r0, 0
	  stw       r0, 0x10(r1)
	  b         .loc_0xE4

	.loc_0xB4:
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x44
	  lwzx      r3, r31, r0
	  cmplwi    r3, 0
	  beq-      .loc_0xD8
	  lbz       r0, 0x3C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8
	  bl        .loc_0x0

	.loc_0xD8:
	  lwz       r3, 0x10(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x10(r1)

	.loc_0xE4:
	  lwz       r0, 0x10(r1)
	  cmplwi    r0, 0x10
	  blt+      .loc_0xB4
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80011400
 * Size:	0000CC
 */
void Jam_MuteTrack(int*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  mr        r31, r3
	  lwz       r3, 0x40(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lbz       r5, 0x39E(r3)
	  rlwinm.   r0,r4,0,24,31
	  li        r3, 0x1
	  or        r0, r5, r4
	  stb       r0, 0x39E(r31)
	  lwz       r0, 0x88(r31)
	  rlwinm    r0,r0,0,28,31
	  slw       r0, r3, r0
	  rlwinm    r4,r0,0,16,31
	  bne-      .loc_0x5C
	  lwz       r3, 0x40(r31)
	  lhz       r0, 0x3A0(r3)
	  andc      r0, r0, r4
	  sth       r0, 0x3A0(r3)
	  b         .loc_0x74

	.loc_0x5C:
	  lwz       r3, 0x40(r31)
	  lhz       r0, 0x3A0(r3)
	  or        r0, r0, r4
	  sth       r0, 0x3A0(r3)
	  b         .loc_0x74

	.loc_0x70:
	  stb       r4, 0x39E(r31)

	.loc_0x74:
	  lwz       r0, 0x3D8(r31)
	  ori       r0, r0, 0x1
	  stw       r0, 0x3D8(r31)
	  lbz       r0, 0x39E(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  lbz       r0, 0x39D(r31)
	  rlwinm.   r0,r0,0,26,26
	  beq-      .loc_0xB8
	  li        r30, 0

	.loc_0x9C:
	  addi      r3, r31, 0
	  rlwinm    r4,r30,0,24,31
	  li        r5, 0xA
	  bl        0x2738
	  addi      r30, r30, 0x1
	  cmplwi    r30, 0x8
	  blt+      .loc_0x9C

	.loc_0xB8:
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
 * Size:	0000B4
 */
void Jam_MuteChildTracks(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800114E0
 * Size:	00013C
 */
void Jam_PauseTrack(seqp_*, u32) // TODO: types uncertain
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r30, r3, 0
	  mr        r31, r4
	  stb       r0, 0x39C(r3)
	  lbz       r0, 0x39D(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x38
	  lwz       r0, 0x3D8(r30)
	  ori       r0, r0, 0x1
	  stw       r0, 0x3D8(r30)

	.loc_0x38:
	  lbz       r0, 0x39D(r30)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x78
	  li        r0, 0
	  stw       r0, 0x14(r1)
	  b         .loc_0x6C

	.loc_0x50:
	  addi      r3, r30, 0
	  rlwinm    r4,r0,0,24,31
	  li        r5, 0xA
	  bl        0x26A4
	  lwz       r3, 0x14(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x14(r1)

	.loc_0x6C:
	  lwz       r0, 0x14(r1)
	  cmplwi    r0, 0x8
	  blt+      .loc_0x50

	.loc_0x78:
	  lbz       r0, 0x39D(r30)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0xD4
	  li        r27, 0
	  li        r29, 0
	  addi      r28, r27, 0

	.loc_0x90:
	  addi      r0, r28, 0x9C
	  lwzx      r0, r30, r0
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0xC0
	  addi      r4, r29, 0xBC
	  lhz       r0, 0x126(r3)
	  lhzx      r4, r30, r4
	  cmplw     r4, r0
	  bne-      .loc_0xC0
	  li        r4, 0x1
	  bl        0x49E4

	.loc_0xC0:
	  addi      r27, r27, 0x1
	  addi      r28, r28, 0x4
	  cmplwi    r27, 0x8
	  addi      r29, r29, 0x2
	  blt+      .loc_0x90

	.loc_0xD4:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x164
	  rlwinm    r0,r31,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x128
	  li        r28, 0
	  li        r31, 0

	.loc_0xF4:
	  addi      r0, r31, 0x44
	  lwzx      r3, r30, r0
	  cmplwi    r3, 0
	  beq-      .loc_0x118
	  lbz       r0, 0x3C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x118
	  li        r4, 0x1
	  bl        .loc_0x0

	.loc_0x118:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x4
	  cmplwi    r28, 0x10
	  blt+      .loc_0xF4

	.loc_0x128:
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80011620
 * Size:	0000EC
 */
void Jam_UnPauseTrack(seqp_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  addi      r31, r3, 0
	  li        r3, 0
	  mr        r29, r4
	  stb       r3, 0x39C(r31)
	  lwz       r0, 0x3D8(r31)
	  ori       r0, r0, 0x1
	  stw       r0, 0x3D8(r31)
	  stw       r3, 0x14(r1)
	  b         .loc_0x78

	.loc_0x34:
	  rlwinm    r3,r4,2,0,29
	  addi      r0, r3, 0x9C
	  lwzx      r0, r31, r0
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x6C
	  rlwinm    r4,r4,1,0,30
	  lhz       r0, 0x126(r3)
	  addi      r4, r4, 0xBC
	  lhzx      r4, r31, r4
	  cmplw     r4, r0
	  bne-      .loc_0x6C
	  li        r4, 0
	  bl        0x48F8

	.loc_0x6C:
	  lwz       r3, 0x14(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x14(r1)

	.loc_0x78:
	  lwz       r4, 0x14(r1)
	  cmplwi    r4, 0x8
	  blt+      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0x74
	  rlwinm    r0,r29,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0xD8
	  li        r29, 0
	  addi      r30, r29, 0

	.loc_0xA4:
	  addi      r0, r30, 0x44
	  lwzx      r3, r31, r0
	  cmplwi    r3, 0
	  beq-      .loc_0xC8
	  lbz       r0, 0x3C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xC8
	  li        r4, 0x1
	  bl        .loc_0x0

	.loc_0xC8:
	  addi      r29, r29, 0x1
	  addi      r30, r30, 0x4
	  cmplwi    r29, 0x10
	  blt+      .loc_0xA4

	.loc_0xD8:
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80011720
 * Size:	000028
 */
void Jam_SetInterrupt(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,16,31
	  li        r4, 0x1
	  lbz       r5, 0x3A6(r3)
	  slw       r4, r4, r0
	  and.      r0, r5, r4
	  beqlr-
	  lbz       r0, 0x3A5(r3)
	  or        r0, r0, r4
	  stb       r0, 0x3A5(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80011760
 * Size:	000090
 */
void Jam_TryInterrupt(seqp_*)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x3A4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  li        r0, 0x8
	  li        r7, 0
	  li        r4, 0x1
	  mtctr     r0

	.loc_0x24:
	  lbz       r0, 0x3A6(r3)
	  slw       r6, r4, r7
	  and.      r0, r0, r6
	  beq-      .loc_0x80
	  lbz       r0, 0x3A5(r3)
	  and.      r0, r0, r6
	  beq-      .loc_0x80
	  lwz       r5, 0x4(r3)
	  rlwinm    r0,r7,2,0,29
	  add       r4, r3, r0
	  li        r0, 0
	  stw       r5, 0x3C8(r3)
	  lwz       r4, 0x3A8(r4)
	  stw       r4, 0x4(r3)
	  stb       r6, 0x3A4(r3)
	  lwz       r4, 0x8C(r3)
	  stw       r4, 0x3CC(r3)
	  stw       r0, 0x8C(r3)
	  lbz       r0, 0x3A5(r3)
	  xor       r0, r0, r6
	  stb       r0, 0x3A5(r3)
	  li        r3, 0x1
	  blr

	.loc_0x80:
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x24
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80011800
 * Size:	000038
 */
static u32 Cmd_OpenTrack()
{
	Jaq_OpenTrack(SEQ_P, SEQ_ARG._00[0], SEQ_ARG._00[1]);
	return 0;
}

/*
 * --INFO--
 * Address:	80011840
 * Size:	000050
 */
static u32 Cmd_OpenTrackBros()
{
	if (SEQ_P->_40) {
		Jaq_OpenTrack(SEQ_P->_40, SEQ_ARG._00[0], SEQ_ARG._00[1]);
		return 0;
	}
	return 0x40;
}

/*
 * --INFO--
 * Address:	800118A0
 * Size:	00003C
 */
static u32 Cmd_Call()
{
	SEQ_P->_0C[SEQ_P->_08++] = SEQ_P->_04;
	SEQ_P->_04               = SEQ_ARG._00[0];
	return 0;
}

/*
 * --INFO--
 * Address:	800118E0
 * Size:	000100
 */
static u32 Cmd_CallF()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stmw      r30, 0x8(r1)
	  lwz       r3, 0x2C30(r13)
	  bl        -0x22F4
	  rlwinm.   r0,r3,0,24,24
	  rlwinm    r31,r3,0,24,31
	  beq-      .loc_0x90
	  lwz       r3, 0x2C30(r13)
	  bl        -0x2308
	  mr        r0, r3
	  lwz       r3, 0x2C30(r13)
	  mr        r4, r0
	  bl        -0x1878
	  rlwinm.   r0,r31,0,25,25
	  rlwinm    r30,r3,0,16,31
	  beq-      .loc_0x9C
	  rlwinm.   r0,r31,0,26,26
	  beq-      .loc_0x6C
	  lwz       r3, 0x2C30(r13)
	  bl        -0x2334
	  mr        r4, r3
	  lwz       r3, 0x2C30(r13)
	  bl        -0x18A0
	  rlwinm    r4,r3,0,16,31
	  b         .loc_0x78

	.loc_0x6C:
	  lwz       r3, 0x2C30(r13)
	  bl        -0x2270
	  mr        r4, r3

	.loc_0x78:
	  mulli     r0, r30, 0x3
	  lwz       r3, 0x2C30(r13)
	  add       r4, r4, r0
	  bl        -0x2444
	  mr        r30, r3
	  b         .loc_0x9C

	.loc_0x90:
	  lwz       r3, 0x2C30(r13)
	  bl        -0x2294
	  mr        r30, r3

	.loc_0x9C:
	  lwz       r3, 0x2C30(r13)
	  rlwinm    r4,r31,0,28,31
	  bl        -0x2244
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0xE8
	  lbz       r0, 0x2C34(r13)
	  cmplwi    r0, 0xC4
	  bne-      .loc_0xE0
	  lwz       r6, 0x2C30(r13)
	  lwz       r4, 0x8(r6)
	  lwz       r5, 0x4(r6)
	  addi      r3, r4, 0x1
	  rlwinm    r0,r4,2,0,29
	  stw       r3, 0x8(r6)
	  add       r3, r6, r0
	  stw       r5, 0xC(r3)

	.loc_0xE0:
	  lwz       r3, 0x2C30(r13)
	  stw       r30, 0x4(r3)

	.loc_0xE8:
	  lmw       r30, 0x8(r1)
	  li        r3, 0
	  lwz       r0, 0x14(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800119E0
 * Size:	000028
 */
static u32 Cmd_Ret()
{
	SEQ_P->_04 = SEQ_P->_0C[--SEQ_P->_08];
	return 0;
}

/*
 * --INFO--
 * Address:	80011A20
 * Size:	000060
 */
static u32 Cmd_RetF()
{
	// But why cast it...?  And why check if it explicitly equals TRUE...?
	if ((u8)__ConditionCheck(SEQ_P, SEQ_ARG._00[0] & 0x0f) == TRUE) {
		SEQ_P->_04 = SEQ_P->_0C[--SEQ_P->_08];
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80011A80
 * Size:	00001C
 */
static u32 Cmd_Jmp()
{
	SEQ_P->_04 = SEQ_ARG._00[1];
	return 0;
}

/*
 * --INFO--
 * Address:	80011AA0
 * Size:	000020
 */
static u32 Cmd_JmpF()
{
	Cmd_CallF();
}

/*
 * --INFO--
 * Address:	80011AC0
 * Size:	000048
 */
static u32 Cmd_LoopS()
{
	SEQ_P->_0C[SEQ_P->_08]   = SEQ_P->_04;
	SEQ_P->_2C[SEQ_P->_08++] = SEQ_ARG._00[0];
	return 0;
}

/*
 * --INFO--
 * Address:	80011B20
 * Size:	000078
 */
static u32 Cmd_LoopE()
{
	u16 uVar1;

	if (SEQ_P->_08 == 0) {
		return 0x80;
	}

	uVar1 = SEQ_P->_2C[SEQ_P->_08 - 1];
	if (uVar1 != 0) {
		uVar1 -= 1;
	}
	if (uVar1 == 0) {
		SEQ_P->_08 -= 1;
		return 0;
	}

	SEQ_P->_2C[SEQ_P->_08 - 1] = uVar1;
	SEQ_P->_04                 = SEQ_P->_0C[SEQ_P->_08 - 1];
	return 0;
}

/*
 * --INFO--
 * Address:	80011BA0
 * Size:	000054
 */
static u32 Cmd_ReadPort()
{
	// TODO: Ghidra really hates the array of struct at _2F0.
	u16 temp;

	SEQ_P->_2F0[SEQ_ARG._00[0]].cmdImport = 0;
	temp                                  = SEQ_P->_2F0[SEQ_ARG._00[0]]._02;
	Jam_WriteRegDirect(SEQ_P, SEQ_ARG._00[1], temp);
	return 0;
}

/*
 * --INFO--
 * Address:	80011C00
 * Size:	000040
 */
static u32 Cmd_WritePort()
{
	/*
	.loc_0x0:
	  lis       r3, 0x8032
	  lwz       r4, 0x2C30(r13)
	  subi      r7, r3, 0x680
	  li        r5, 0x1
	  lwz       r0, 0x100(r7)
	  li        r3, 0
	  lwz       r6, 0x104(r7)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r4, r0
	  sth       r6, 0x2F2(r4)
	  lwz       r0, 0x100(r7)
	  lwz       r4, 0x2C30(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r4, r0
	  stb       r5, 0x2F1(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80011C40
 * Size:	000044
 */
static u32 Cmd_CheckPortImport()
{
	Jam_WriteRegDirect(SEQ_P, 3, SEQ_P->_2F0[SEQ_ARG._00[0]].cmdImport);
	return 0;
}

/*
 * --INFO--
 * Address:	80011CA0
 * Size:	000044
 */
static u32 Cmd_CheckPortExport()
{
	Jam_WriteRegDirect(SEQ_P, 3, SEQ_P->_2F0[SEQ_ARG._00[0]].cmdExport);
	return 0;
}

/*
 * --INFO--
 * Address:	80011D00
 * Size:	00002C
 */
static u32 Cmd_WaitReg()
{
	SEQ_P->_8C = SEQ_ARG._00[0];
	return SEQ_ARG._00[0] ? 1 : 0;
}

/*
 * --INFO--
 * Address:	80011D40
 * Size:	000028
 */
static u32 Cmd_ConnectName()
{
	SEQ_P->_84 = SEQ_ARG._00[0] << 16 | SEQ_ARG._00[1];
	return 0;
}

/*
 * --INFO--
 * Address:	80011D80
 * Size:	000040
 */
static u32 Cmd_ParentWritePort()
{
	Jam_WritePortAppDirect(SEQ_P->_40, SEQ_ARG._00[0] & 0x0f, SEQ_ARG._00[1]);
	return 0;
}

/*
 * --INFO--
 * Address:	80011DC0
 * Size:	000048
 */
static u32 Cmd_ChildWritePort()
{
	Jam_WritePortAppDirect(SEQ_P->_44[(SEQ_ARG._00[0] / 4)], SEQ_ARG._00[0] & 0xf, SEQ_ARG._00[1]);
	return 0;
}

/*
 * --INFO--
 * Address:	80011E20
 * Size:	000030
 */
static u32 Cmd_SetLastNote()
{
	SEQ_P->_D5 = SEQ_ARG._00[0];
	SEQ_P->_D5 += SEQ_P->_397;
	return 0;
}

/*
 * --INFO--
 * Address:	80011E60
 * Size:	00001C
 */
static u32 Cmd_TimeRelate()
{
	SEQ_P->_33C = SEQ_ARG._00[0];
	return 0;
}

/*
 * --INFO--
 * Address:	80011E80
 * Size:	000034
 */
static u32 Cmd_SimpleOsc()
{
	Osc_Setup_Simple(SEQ_P, SEQ_ARG._00[0]);
	return 0;
}

/*
 * --INFO--
 * Address:	80011EC0
 * Size:	000038
 */
static u32 Cmd_SimpleEnv()
{
	Osc_Setup_SimpleEnv(SEQ_P, SEQ_ARG._00[0], SEQ_ARG._00[1]);
	return 0;
}

/*
 * --INFO--
 * Address:	80011F00
 * Size:	000064
 */
static u32 Cmd_SimpleADSR()
{
	int i;
	s16 local_10[5];

	for (i = 0; i < 5; ++i) {
		local_10[i] = SEQ_ARG._00[i];
	}
	Osc_Setup_ADSR(SEQ_P, local_10);
	return 0;
}

/*
 * --INFO--
 * Address:	80011F80
 * Size:	000048
 */
static u32 Cmd_Transpose()
{
	SEQ_P->_396 = SEQ_ARG._00[0];
	if (SEQ_P->_40) {
		SEQ_P->_397 = SEQ_P->_40->_396 + SEQ_P->_396;
	} else {
		SEQ_P->_397 = SEQ_P->_396;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80011FE0
 * Size:	000068
 */
static u32 Cmd_CloseTrack()
{
	u8 index = SEQ_ARG._00[0];
	if (index >= ARRAY_SIZE(SEQ_P->_44)) {
		return 0x80;
	}
	Jaq_CloseTrack(SEQ_P->_44[index]);
	SEQ_P->_44[index] = NULL;
	return 0;
}

/*
 * --INFO--
 * Address:	80012060
 * Size:	000038
 */
static u32 Cmd_OutSwitch()
{
	// TODO: This seems unlikely. Does it actually point to a struct?
	if (SEQ_P->_2AC) {
		SEQ_P->_2AC[4] = SEQ_ARG._00[0];
		SEQ_P->_2AC[5] = 0xffff;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	800120A0
 * Size:	000034
 */
static u32 Cmd_UpdateSync()
{
	Jam_UpdateTrack(SEQ_P, SEQ_ARG._00[0]);
	return 0;
}

/*
 * --INFO--
 * Address:	800120E0
 * Size:	00002C
 */
static u32 Cmd_BusConnect()
{
	if (SEQ_ARG._00[0] < 6) {
		SEQ_P->_D8._4E[SEQ_ARG._00[0]] = SEQ_ARG._00[1];
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80012120
 * Size:	00001C
 */
static u32 Cmd_PauseStatus()
{
	SEQ_P->_39D = SEQ_ARG._00[0];
	return 0;
}

/*
 * --INFO--
 * Address:	80012140
 * Size:	000044
 */
static u32 Cmd_SetInterrupt()
{
	SEQ_P->_3A6 |= (1 << SEQ_ARG._00[0]);
	SEQ_P->_3A8[SEQ_ARG._00[0]] = SEQ_ARG._00[1];
	return 0;
}

/*
 * --INFO--
 * Address:	800121A0
 * Size:	000030
 */
static u32 Cmd_DisInterrupt()
{
	SEQ_P->_3A6 &= ~(u8)(1 << (u8)SEQ_ARG._00[0]);
	return 0;
}

/*
 * --INFO--
 * Address:	800121E0
 * Size:	000014
 */
static u32 Cmd_ClrI()
{
	SEQ_P->_3A4 = 0;
	return 0;
}

/*
 * --INFO--
 * Address:	80012200
 * Size:	000014
 */
static u32 Cmd_SetI()
{
	SEQ_P->_3A4 = 1;
	return 0;
}

/*
 * --INFO--
 * Address:	80012220
 * Size:	00002C
 */
static u32 Cmd_RetI()
{
	SEQ_P->_8C  = SEQ_P->_3CC;
	SEQ_P->_3A4 = 0;
	SEQ_P->_04  = SEQ_P->_3C8;
	return 2;
}

/*
 * --INFO--
 * Address:	80012260
 * Size:	000034
 */
static u32 Cmd_IntTimer()
{
	SEQ_P->_3A7 = SEQ_ARG._00[0];
	SEQ_P->_3D0 = SEQ_ARG._00[1];
	SEQ_P->_3D4 = SEQ_ARG._00[1];
	return 0;
}

/*
 * --INFO--
 * Address:	800122A0
 * Size:	00002C
 */
static u32 Cmd_ConnectOpen()
{
	Jam_RegistTrack(SEQ_P, SEQ_P->_84);
	return 0;
}

/*
 * --INFO--
 * Address:	800122E0
 * Size:	000028
 */
static u32 Cmd_ConnectClose()
{
	Jam_UnRegistTrack(SEQ_P);
	return 0;
}

/*
 * --INFO--
 * Address:	80012320
 * Size:	000060
 */
static u32 Cmd_SyncCPU()
{
	u16 param_3;

	if (JAM_CALLBACK_FUNC) {
		param_3 = JAM_CALLBACK_FUNC(SEQ_P, SEQ_ARG._00[0]);
	} else {
		param_3 = 0xffff;
	}
	Jam_WriteRegDirect(SEQ_P, 3, param_3);
	return 0;
}

/*
 * --INFO--
 * Address:	80012380
 * Size:	000038
 */
static u32 Cmd_FlushAll()
{
	AllStop_1Shot(&SEQ_P->_D8);
	FlushRelease_1Shot(&SEQ_P->_D8);
	return 0;
}

/*
 * --INFO--
 * Address:	800123C0
 * Size:	00002C
 */
static u32 Cmd_FlushRelease()
{
	FlushRelease_1Shot(&SEQ_P->_D8);
	return 0;
}

/*
 * --INFO--
 * Address:	80012400
 * Size:	00002C
 */
static u32 Cmd_Wait3()
{
	SEQ_P->_8C = SEQ_ARG._00[0];
	return SEQ_ARG._00[0] ? 1 : 0;
}

/*
 * --INFO--
 * Address:	80012440
 * Size:	000044
 */
static u32 Cmd_TimeBase()
{
	SEQ_P->_338 = SEQ_ARG._00[0];
	if (!SEQ_P->_40) {
		Jam_UpdateTempo();
	}
	return 0;
}

/*
 * --INFO--
 * Address:	800124A0
 * Size:	000050
 */
static u32 Cmd_Tempo()
{
	SEQ_P->_33A = SEQ_ARG._00[0];
	if (!SEQ_P->_40) {
		Jam_UpdateTempo();
	} else {
		SEQ_P->_3E3 = 1;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80012500
 * Size:	0000CC
 */
static u32 Cmd_Finish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  addi      r11, r1, 0x28
	  bl        0x202954
	  stmw      r29, 0xC(r1)
	  lfs       f31, -0x7F08(r2)
	  li        r29, 0
	  lfs       f30, -0x7F0C(r2)
	  li        r30, 0
	  li        r31, 0

	.loc_0x2C:
	  lwz       r0, 0x2C30(r13)
	  add       r3, r0, r31
	  lfs       f0, 0x154(r3)
	  addi      r5, r3, 0x14C
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0x90
	  lfs       f1, 0x0(r5)
	  cmplwi    r30, 0x5
	  lfs       f0, 0xC(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r5)
	  lfs       f0, 0x8(r5)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x8(r5)
	  ble-      .loc_0x70
	  cmplwi    r30, 0xB
	  blt-      .loc_0x80

	.loc_0x70:
	  li        r0, 0x1
	  slw       r0, r0, r30
	  or        r29, r29, r0
	  b         .loc_0x90

	.loc_0x80:
	  lwz       r3, 0x2C30(r13)
	  rlwinm    r4,r30,0,24,31
	  lfs       f1, 0x0(r5)
	  bl        0x2714

	.loc_0x90:
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x10
	  cmplwi    r30, 0x12
	  blt+      .loc_0x2C
	  lwz       r3, 0x2C30(r13)
	  mr        r4, r29
	  bl        0x11D8
	  li        r3, 0x3
	  lwz       r0, 0x2C(r1)
	  addi      r11, r1, 0x28
	  bl        0x2028F8
	  lmw       r29, 0xC(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800125E0
 * Size:	000008
 */
static u32 Cmd_Nop()
{
	return 0;
}

/*
 * --INFO--
 * Address:	80012600
 * Size:	0000AC
 */
static u32 Cmd_PanPowSet()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r3, 0x8032
	  li        r0, 0x3
	  subi      r7, r3, 0x580
	  lwz       r5, 0x2C30(r13)
	  li        r3, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x20:
	  add       r6, r7, r4
	  addi      r0, r3, 0x27C
	  lwz       r6, 0x0(r6)
	  addi      r3, r3, 0x2
	  addi      r4, r4, 0x4
	  sthx      r6, r5, r0
	  bdnz+     .loc_0x20
	  lis       r3, 0x8032
	  li        r0, 0x2
	  subi      r8, r3, 0x580
	  lfs       f2, -0x7EF4(r2)
	  lfd       f1, -0x7F18(r2)
	  li        r3, 0x6
	  lwz       r5, 0x2C30(r13)
	  li        r4, 0xC
	  lis       r7, 0x4330
	  mtctr     r0

	.loc_0x64:
	  add       r6, r8, r4
	  addi      r0, r3, 0x27C
	  lwz       r6, 0x0(r6)
	  addi      r3, r3, 0x2
	  addi      r4, r4, 0x4
	  stw       r6, 0x14(r1)
	  stw       r7, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x8(r1)
	  lwz       r6, 0xC(r1)
	  sthx      r6, r5, r0
	  bdnz+     .loc_0x64
	  li        r3, 0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800126C0
 * Size:	000094
 */
static u32 Cmd_IIRSet()
{
	int i;
	seqp_* seq;

	seq = SEQ_P;
	for (i = 0; i < 4; ++i) {
		seq->_14C[i]._04 = SEQ_ARG._00[i] / 32768.0f;
		seq->_14C[i]._00 = seq->_14C[i]._04;
		seq->_14C[i]._0C = 0.0f;
		seq->_14C[i]._08 = 1.0f;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80012760
 * Size:	000044
 */
static u32 Cmd_FIRSet()
{
	Jam_SetExtFirFilterD(SEQ_P->_2AC, Jam_OfsToAddr(SEQ_P, SEQ_ARG._00[0]));
	return 0;
}

/*
 * --INFO--
 * Address:	800127C0
 * Size:	000050
 */
static u32 Cmd_EXTSet()
{
	int* buffer; // TODO: No, no, no.  Bad.  What type is this, really?

	buffer = (int*)Jam_OfsToAddr(SEQ_P, SEQ_ARG._00[0]);
	Jam_InitExtBuffer(buffer);
	Jam_AssignExtBuffer(SEQ_P, buffer);
	return 0;
}

/*
 * --INFO--
 * Address:	80012820
 * Size:	0000C4
 */
static u32 Cmd_PanSwSet()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r3, 0x8032
	  subi      r11, r3, 0x580
	  li        r0, 0x3
	  lwz       r5, -0x7EF0(r2)
	  addi      r10, r1, 0x10
	  lwz       r4, -0x7EE8(r2)
	  addi      r8, r1, 0x8
	  stw       r5, 0x10(r1)
	  li        r3, 0
	  lhz       r6, -0x7EEC(r2)
	  stw       r4, 0x8(r1)
	  li        r4, 0
	  lhz       r5, -0x7EE4(r2)
	  sth       r6, 0x14(r1)
	  lbz       r6, -0x7EEA(r2)
	  sth       r5, 0xC(r1)
	  lbz       r5, -0x7EE2(r2)
	  stb       r6, 0x16(r1)
	  stb       r5, 0xE(r1)
	  mtctr     r0

	.loc_0x54:
	  add       r12, r11, r4
	  lwz       r7, 0x2C30(r13)
	  lwz       r9, 0x0(r12)
	  addi      r6, r3, 0x3DC
	  addi      r5, r3, 0x3DF
	  addi      r0, r3, 0x13A
	  rlwinm    r9,r9,27,5,31
	  addi      r3, r3, 0x1
	  lbzx      r9, r10, r9
	  addi      r4, r4, 0x4
	  stbx      r9, r7, r6
	  lwz       r7, 0x0(r12)
	  lwz       r6, 0x2C30(r13)
	  rlwinm    r7,r7,27,5,31
	  lbzx      r7, r8, r7
	  stbx      r7, r6, r5
	  lwz       r6, 0x0(r12)
	  lwz       r5, 0x2C30(r13)
	  rlwinm    r6,r6,0,27,31
	  stbx      r6, r5, r0
	  lwz       r5, 0x2C30(r13)
	  lwz       r0, 0x3D8(r5)
	  ori       r0, r0, 0x8
	  stw       r0, 0x3D8(r5)
	  bdnz+     .loc_0x54
	  li        r3, 0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80012900
 * Size:	000040
 */
static u32 Cmd_OscRoute()
{
	u8 uVar1;
	u8 uVar2;

	uVar1 = SEQ_ARG._00[0] & 0xf;
	uVar2 = SEQ_ARG._00[0] >> 4 & 0xf;

	SEQ_P->_370[uVar2] = uVar1;
	if (uVar1 == 0xe) {
		SEQ_P->_3E8[uVar2 * 0x18] = 1;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80012940
 * Size:	0000A0
 */
static u32 Cmd_IIRCutOff()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r4, 0x8032
	  subi      r4, r4, 0x580
	  lis       r3, 0x8022
	  lwz       r4, 0x0(r4)
	  addi      r3, r3, 0x5328
	  li        r0, 0x4
	  lwz       r6, 0x2C30(r13)
	  rlwinm    r4,r4,3,21,28
	  li        r8, 0
	  add       r7, r3, r4
	  lfd       f4, -0x7F20(r2)
	  lfs       f3, -0x7F04(r2)
	  li        r3, 0
	  lfs       f1, -0x7F0C(r2)
	  lis       r4, 0x4330
	  lfs       f0, -0x7F08(r2)
	  mtctr     r0

	.loc_0x48:
	  lhax      r0, r7, r3
	  addi      r5, r8, 0xC
	  rlwinm    r5,r5,4,0,27
	  addi      r8, r8, 0x1
	  xoris     r0, r0, 0x8000
	  addi      r5, r5, 0x14C
	  stw       r0, 0x14(r1)
	  add       r5, r6, r5
	  addi      r3, r3, 0x2
	  stw       r4, 0x10(r1)
	  lfd       f2, 0x10(r1)
	  fsubs     f2, f2, f4
	  fdivs     f2, f2, f3
	  stfs      f2, 0x4(r5)
	  lfs       f2, 0x4(r5)
	  stfs      f2, 0x0(r5)
	  stfs      f1, 0xC(r5)
	  stfs      f0, 0x8(r5)
	  bdnz+     .loc_0x48
	  li        r3, 0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800129E0
 * Size:	000040
 */
static u32 Cmd_OscFull()
{
	Osc_Setup_Full(SEQ_P, SEQ_ARG._00[0], SEQ_ARG._00[1], SEQ_ARG._00[2]);
	return 0;
}

/*
 * --INFO--
 * Address:	80012A20
 * Size:	000068
 */
static u32 Cmd_CheckWave()
{
	SOUNDID_ soundID;
	u32 uVar2;

	soundID.value = SEQ_ARG._00[0] | (Jam_ReadRegDirect(SEQ_P, 6) << 16);
	uVar2         = One_CheckInstWave(soundID);
	Jam_WriteRegDirect(SEQ_P, 3, (u8)uVar2);
	return 0;
}

/*
 * --INFO--
 * Address:	80012AA0
 * Size:	000204
 */
static u32 Cmd_Printf()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stmw      r27, 0xB4(r1)
	  addi      r29, r1, 0x28
	  li        r31, 0
	  li        r30, 0
	  b         .loc_0x154

	.loc_0x20:
	  lwz       r3, 0x2C30(r13)
	  bl        -0x34C4
	  addi      r28, r1, 0x2C
	  add       r28, r28, r30
	  stb       r3, 0x0(r28)
	  lbz       r3, 0x0(r28)
	  extsb.    r0, r3
	  beq-      .loc_0x15C
	  extsb     r0, r3
	  cmpwi     r0, 0x5C
	  bne-      .loc_0x80
	  lwz       r3, 0x2C30(r13)
	  bl        -0x34F0
	  stb       r3, 0x0(r28)
	  lbz       r3, 0x0(r28)
	  extsb.    r0, r3
	  beq-      .loc_0x15C
	  extsb     r0, r3
	  cmpwi     r0, 0x6E
	  beq-      .loc_0x74
	  b         .loc_0x150

	.loc_0x74:
	  li        r0, 0xD
	  stb       r0, 0x0(r28)
	  b         .loc_0x150

	.loc_0x80:
	  cmpwi     r0, 0x25
	  bne-      .loc_0x150
	  lwz       r3, 0x2C30(r13)
	  addi      r30, r30, 0x1
	  bl        -0x3530
	  addi      r4, r1, 0x2C
	  add       r4, r4, r30
	  stb       r3, 0x0(r4)
	  lbz       r3, 0x0(r4)
	  extsb.    r0, r3
	  beq-      .loc_0x15C
	  extsb     r0, r3
	  cmpwi     r0, 0x72
	  beq-      .loc_0x114
	  bge-      .loc_0xD4
	  cmpwi     r0, 0x64
	  beq-      .loc_0xF0
	  bge-      .loc_0x14C
	  cmpwi     r0, 0x52
	  beq-      .loc_0x128
	  b         .loc_0x14C

	.loc_0xD4:
	  cmpwi     r0, 0x78
	  beq-      .loc_0xFC
	  bge-      .loc_0x14C
	  cmpwi     r0, 0x74
	  beq-      .loc_0x13C
	  bge-      .loc_0x14C
	  b         .loc_0x108

	.loc_0xF0:
	  li        r0, 0
	  stbx      r0, r29, r31
	  b         .loc_0x14C

	.loc_0xFC:
	  li        r0, 0x1
	  stbx      r0, r29, r31
	  b         .loc_0x14C

	.loc_0x108:
	  li        r0, 0x2
	  stbx      r0, r29, r31
	  b         .loc_0x14C

	.loc_0x114:
	  li        r3, 0x3
	  li        r0, 0x64
	  stbx      r3, r29, r31
	  stb       r0, 0x0(r4)
	  b         .loc_0x14C

	.loc_0x128:
	  li        r3, 0x4
	  li        r0, 0x78
	  stbx      r3, r29, r31
	  stb       r0, 0x0(r4)
	  b         .loc_0x14C

	.loc_0x13C:
	  li        r3, 0x5
	  li        r0, 0x78
	  stbx      r3, r29, r31
	  stb       r0, 0x0(r4)

	.loc_0x14C:
	  addi      r31, r31, 0x1

	.loc_0x150:
	  addi      r30, r30, 0x1

	.loc_0x154:
	  cmplwi    r30, 0x80
	  blt+      .loc_0x20

	.loc_0x15C:
	  li        r27, 0
	  addi      r30, r1, 0x28
	  addi      r29, r27, 0
	  b         .loc_0x1E4

	.loc_0x16C:
	  lwz       r3, 0x2C30(r13)
	  bl        -0x3610
	  addi      r28, r1, 0x18
	  rlwinm    r0,r3,0,24,31
	  add       r28, r28, r29
	  stw       r0, 0x0(r28)
	  lbz       r0, 0x0(r30)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x1A4
	  lwz       r3, 0x2C30(r13)
	  lwz       r4, 0x0(r28)
	  bl        -0x3838
	  stw       r3, 0x0(r28)
	  b         .loc_0x1D8

	.loc_0x1A4:
	  cmplwi    r0, 0x5
	  bne-      .loc_0x1BC
	  lwz       r3, 0x2C30(r13)
	  lwz       r0, 0x88(r3)
	  stw       r0, 0x0(r28)
	  b         .loc_0x1D8

	.loc_0x1BC:
	  cmplwi    r0, 0x3
	  blt-      .loc_0x1D8
	  lwz       r0, 0x0(r28)
	  lwz       r3, 0x2C30(r13)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x2930
	  stw       r3, 0x0(r28)

	.loc_0x1D8:
	  addi      r27, r27, 0x1
	  addi      r30, r30, 0x1
	  addi      r29, r29, 0x4

	.loc_0x1E4:
	  cmplw     r27, r31
	  blt+      .loc_0x16C
	  lmw       r27, 0xB4(r1)
	  li        r3, 0
	  lwz       r0, 0xCC(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

#define CMD_COUNT (64)

static u32 Arglist[CMD_COUNT] = {
	0x00000000, 0x00020008, 0x00020008, 0x00010002, 0x00000000, 0x00000000, 0x00010000, 0x00010002, 0x00000000, 0x00010001, 0x00000000,
	0x00020000, 0x0002000c, 0x00010000, 0x00010000, 0x00010003, 0x00020005, 0x0002000c, 0x0002000c, 0x0002000f, 0x00010000, 0x00010000,
	0x00010000, 0x00020008, 0x00050155, 0x00010000, 0x00010000, 0x00010000, 0x00010001, 0x00020004, 0x00010000, 0x00020008, 0x00010000,
	0x00000000, 0x00000000, 0x00000000, 0x00020004, 0x00000000, 0x00000000, 0x00010001, 0x00000000, 0x00000000, 0x00010002, 0x00050000,
	0x00040055, 0x00010002, 0x00010002, 0x00030000, 0x00010000, 0x00010000, 0x00030028, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00010001, 0x00000000, 0x00000000, 0x00010001, 0x00010001, 0x00000000,
};

static CmdFunction CMDP_LIST[CMD_COUNT] = {
	NULL,
	Cmd_OpenTrack,
	Cmd_OpenTrackBros,
	Cmd_Call,
	Cmd_CallF,
	Cmd_Ret,
	Cmd_RetF,
	Cmd_Jmp,
	Cmd_JmpF,
	Cmd_LoopS,
	Cmd_LoopE,
	Cmd_ReadPort,
	Cmd_WritePort,
	Cmd_CheckPortImport,
	Cmd_CheckPortExport,
	Cmd_WaitReg,
	Cmd_ConnectName,
	Cmd_ParentWritePort,
	Cmd_ChildWritePort,
	NULL,
	Cmd_SetLastNote,
	Cmd_TimeRelate,
	Cmd_SimpleOsc,
	Cmd_SimpleEnv,
	Cmd_SimpleADSR,
	Cmd_Transpose,
	Cmd_CloseTrack,
	Cmd_OutSwitch,
	Cmd_UpdateSync,
	Cmd_BusConnect,
	Cmd_PauseStatus,
	Cmd_SetInterrupt,
	Cmd_DisInterrupt,
	Cmd_ClrI,
	Cmd_SetI,
	Cmd_RetI,
	Cmd_IntTimer,
	Cmd_ConnectOpen,
	Cmd_ConnectClose,
	Cmd_SyncCPU,
	Cmd_FlushAll,
	Cmd_FlushRelease,
	Cmd_Wait3,
	Cmd_PanPowSet,
	Cmd_IIRSet,
	Cmd_FIRSet,
	Cmd_EXTSet,
	Cmd_PanSwSet,
	Cmd_OscRoute,
	Cmd_IIRCutOff,
	Cmd_OscFull,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	Cmd_CheckWave,
	Cmd_Printf,
	Cmd_Nop,
	Cmd_Tempo,
	Cmd_TimeBase,
	Cmd_Finish,
};

/*
 * --INFO--
 * Address:	80012CC0
 * Size:	000130
 */
u32 Cmd_Process(seqp_*, u8, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x5124
	  stwu      r1, -0x40(r1)
	  stmw      r24, 0x20(r1)
	  li        r28, 0
	  li        r27, 0
	  stb       r4, 0xC(r1)
	  lis       r4, 0x8032
	  subi      r26, r4, 0x580
	  lbz       r31, 0xC(r1)
	  stw       r3, 0x8(r1)
	  rlwinm    r29,r31,2,0,29
	  add       r4, r0, r29
	  lwz       r30, 0x8(r1)
	  lwz       r0, -0x300(r4)
	  stw       r0, 0x1C(r1)
	  lhz       r0, 0x1E(r1)
	  lhz       r25, 0x1C(r1)
	  or        r0, r0, r5
	  b         .loc_0xE0

	.loc_0x58:
	  rlwinm    r24,r0,0,16,31
	  rlwinm    r0,r0,0,30,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0xA8
	  bge-      .loc_0x7C
	  cmpwi     r0, 0
	  beq-      .loc_0x88
	  bge-      .loc_0x98
	  b         .loc_0xC8

	.loc_0x7C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xC8
	  b         .loc_0xB4

	.loc_0x88:
	  mr        r3, r30
	  bl        -0x374C
	  rlwinm    r3,r3,0,24,31
	  b         .loc_0xC8

	.loc_0x98:
	  mr        r3, r30
	  bl        -0x36DC
	  rlwinm    r3,r3,0,16,31
	  b         .loc_0xC8

	.loc_0xA8:
	  mr        r3, r30
	  bl        -0x368C
	  b         .loc_0xC8

	.loc_0xB4:
	  mr        r3, r30
	  bl        -0x3778
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  bl        -0x2A44

	.loc_0xC8:
	  add       r4, r26, r27
	  srawi     r0, r24, 0x2
	  stw       r3, 0x0(r4)
	  rlwinm    r0,r0,0,16,31
	  addi      r28, r28, 0x1
	  addi      r27, r27, 0x4

	.loc_0xE0:
	  cmplw     r28, r25
	  blt+      .loc_0x58
	  lis       r3, 0x8022
	  stb       r31, 0x2C34(r13)
	  addi      r0, r3, 0x5224
	  stw       r30, 0x2C30(r13)
	  add       r3, r0, r29
	  lwz       r0, -0x300(r3)
	  cmplwi    r0, 0
	  mr        r12, r0
	  bne-      .loc_0x114
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x114:
	  mtlr      r12
	  blrl

	.loc_0x11C:
	  lmw       r24, 0x20(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80012E00
 * Size:	0000A8
 */
void RegCmd_Process(seqp_*, int, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  bl        -0x381C
	  cmpwi     r28, 0x1
	  addi      r31, r3, 0
	  bne-      .loc_0x3C
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        -0x2AF4
	  rlwinm    r31,r3,0,24,31

	.loc_0x3C:
	  cmpwi     r28, 0x1
	  bne-      .loc_0x4C
	  cmplwi    r29, 0
	  beq-      .loc_0x84

	.loc_0x4C:
	  mr        r3, r27
	  bl        -0x3850
	  addi      r0, r29, 0x1
	  li        r5, 0x3
	  mtctr     r0
	  cmplwi    r0, 0
	  ble-      .loc_0x84

	.loc_0x68:
	  rlwinm.   r0,r3,0,24,24
	  rlwinm    r4,r3,0,24,31
	  beq-      .loc_0x78
	  or        r30, r30, r5

	.loc_0x78:
	  rlwinm    r3,r4,1,24,30
	  rlwinm    r5,r5,2,16,29
	  bdnz+     .loc_0x68

	.loc_0x84:
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  bl        -0x1D0
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80012EC0
 * Size:	0008C0
 */
void Jam_SeqmainNote(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  addi      r11, r1, 0x90
	  bl        0x201F94
	  stmw      r21, 0x54(r1)
	  addi      r31, r3, 0
	  li        r30, 0
	  lwz       r6, 0x40(r3)
	  cmplwi    r6, 0
	  beq-      .loc_0xA8
	  lbz       r0, 0x3E3(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xA8
	  lhz       r5, 0x33A(r31)
	  lis       r3, 0x4330
	  lhz       r0, 0x33A(r6)
	  stw       r5, 0x4C(r1)
	  lfd       f3, -0x7F18(r2)
	  stw       r0, 0x44(r1)
	  lfs       f0, -0x7F08(r2)
	  stw       r3, 0x48(r1)
	  stw       r3, 0x40(r1)
	  lfd       f2, 0x48(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f2, f2, f3
	  fsubs     f1, f1, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  fmr       f1, f0

	.loc_0x7C:
	  lfs       f0, 0x330(r31)
	  fadds     f0, f0, f1
	  stfs      f0, 0x330(r31)
	  lfs       f1, 0x330(r31)
	  lfs       f0, -0x7F08(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xA0
	  li        r3, 0
	  b         .loc_0x8A4

	.loc_0xA0:
	  fsubs     f0, f1, f0
	  stfs      f0, 0x330(r31)

	.loc_0xA8:
	  lwz       r0, 0x40(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  stb       r4, 0x39E(r31)

	.loc_0xB8:
	  lwz       r0, 0x40(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x118
	  lwz       r0, 0xD8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x118
	  addi      r3, r31, 0xE0
	  bl        -0x9A94
	  mr.       r21, r3
	  beq-      .loc_0x118
	  lwz       r3, 0x40(r31)
	  addi      r4, r21, 0
	  addi      r3, r3, 0xE0
	  bl        -0x9A0C
	  lwz       r3, 0x40(r31)
	  addi      r0, r3, 0xD8
	  stw       r0, 0x4(r21)
	  lwz       r3, 0xD8(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0xD8(r31)
	  lwz       r4, 0x40(r31)
	  lwz       r3, 0xD8(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0xD8(r4)

	.loc_0x118:
	  lwz       r4, 0x40(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x138
	  lbz       r3, 0x396(r31)
	  lbz       r0, 0x397(r4)
	  add       r0, r3, r0
	  stb       r0, 0x397(r31)
	  b         .loc_0x140

	.loc_0x138:
	  lbz       r0, 0x396(r31)
	  stb       r0, 0x397(r31)

	.loc_0x140:
	  addi      r3, r31, 0
	  li        r4, 0x7
	  bl        -0x18E8
	  lwz       r3, 0x3D0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A0
	  subic.    r0, r3, 0x1
	  stw       r0, 0x3D0(r31)
	  bne-      .loc_0x1A0
	  addi      r3, r31, 0
	  li        r4, 0x6
	  bl        -0x190C
	  lbz       r3, 0x3A7(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x198
	  subi      r3, r3, 0x1
	  rlwinm.   r0,r3,0,24,31
	  stb       r3, 0x3A7(r31)
	  beq-      .loc_0x1A0
	  lwz       r0, 0x3D4(r31)
	  stw       r0, 0x3D0(r31)
	  b         .loc_0x1A0

	.loc_0x198:
	  lwz       r0, 0x3D4(r31)
	  stw       r0, 0x3D0(r31)

	.loc_0x1A0:
	  mr        r3, r31
	  bl        -0x1904
	  lbz       r0, 0x39C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  lbz       r0, 0x39D(r31)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x820

	.loc_0x1C0:
	  lwz       r3, 0x398(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x398(r31)
	  lwz       r0, 0x8C(r31)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x1F4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0xC80
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x768
	  li        r0, 0
	  stw       r0, 0x8C(r31)

	.loc_0x1F4:
	  lwz       r3, 0x8C(r31)
	  cmpwi     r3, 0
	  ble-      .loc_0x270
	  subi      r0, r3, 0x1
	  stw       r0, 0x8C(r31)
	  lwz       r0, 0x8C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x768
	  lwz       r3, 0xD0(r31)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0x270
	  lbz       r0, 0xD4(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x270
	  li        r5, 0
	  li        r4, 0xFF
	  stw       r5, 0x2C(r1)
	  b         .loc_0x260

	.loc_0x240:
	  addi      r0, r3, 0x94
	  rlwinm    r3,r3,2,0,29
	  stbx      r4, r31, r0
	  addi      r0, r3, 0x9C
	  stwx      r5, r31, r0
	  lwz       r3, 0x2C(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2C(r1)

	.loc_0x260:
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x90(r31)
	  cmpw      r3, r0
	  blt+      .loc_0x240

	.loc_0x270:
	  mr        r3, r31
	  bl        -0x3B34
	  rlwinm.   r0,r3,0,24,24
	  addi      r4, r3, 0
	  rlwinm    r5,r3,0,24,31
	  bne-      .loc_0x598
	  stb       r4, 0x3C(r1)
	  mr        r3, r31
	  lbz       r4, 0x3C(r1)
	  lbz       r0, 0x397(r31)
	  add       r0, r4, r0
	  stb       r0, 0x3C(r1)
	  bl        -0x3B60
	  rlwinm.   r0,r3,0,24,24
	  stb       r3, 0x34(r1)
	  beq-      .loc_0x2D0
	  mr        r3, r31
	  lbz       r4, 0x3C(r1)
	  bl        -0x2E38
	  stb       r3, 0x3C(r1)
	  lbz       r3, 0x3C(r1)
	  lbz       r0, 0x397(r31)
	  add       r0, r3, r0
	  stb       r0, 0x3C(r1)

	.loc_0x2D0:
	  lbz       r0, 0x34(r1)
	  lbz       r3, 0x3C(r1)
	  rlwinm.   r0,r0,27,30,30
	  beq-      .loc_0x2EC
	  stb       r3, 0x3D(r1)
	  lbz       r0, 0xD5(r31)
	  stb       r0, 0x3C(r1)

	.loc_0x2EC:
	  mr        r3, r31
	  bl        -0x3BB0
	  rlwinm    r0,r3,0,24,31
	  addi      r24, r3, 0
	  cmplwi    r0, 0x80
	  blt-      .loc_0x314
	  addi      r3, r31, 0
	  subi      r4, r24, 0x80
	  bl        -0x2E8C
	  rlwinm    r24,r3,0,24,31

	.loc_0x314:
	  lbz       r3, 0x34(r1)
	  rlwinm.   r3,r3,0,29,31
	  bne-      .loc_0x3A4
	  li        r22, 0
	  addi      r3, r31, 0
	  bl        -0x3BE8
	  rlwinm    r0,r3,0,24,31
	  addi      r25, r3, 0
	  cmplwi    r0, 0x80
	  blt-      .loc_0x34C
	  addi      r3, r31, 0
	  subi      r4, r25, 0x80
	  bl        -0x2EC4
	  rlwinm    r25,r3,0,24,31

	.loc_0x34C:
	  li        r23, 0
	  li        r21, 0
	  b         .loc_0x370

	.loc_0x358:
	  mr        r3, r31
	  bl        -0x3C1C
	  rlwinm    r0,r23,8,0,23
	  addi      r21, r21, 0x1
	  mr        r23, r0
	  rlwimi    r23,r3,0,24,31

	.loc_0x370:
	  lbz       r0, 0x34(r1)
	  rlwinm    r0,r0,29,30,31
	  cmpw      r21, r0
	  blt+      .loc_0x358
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3D4
	  cmplwi    r23, 0x80
	  blt-      .loc_0x3D4
	  addi      r3, r31, 0
	  subi      r4, r23, 0x80
	  bl        -0x2F18
	  mr        r23, r3
	  b         .loc_0x3D4

	.loc_0x3A4:
	  lbz       r0, 0x34(r1)
	  addi      r22, r3, 0
	  rlwinm.   r0,r0,29,30,31
	  beq-      .loc_0x3CC
	  addi      r3, r31, 0
	  subi      r4, r22, 0x1
	  bl        -0x2F3C
	  rlwinm    r22,r3,0,24,31
	  cmplwi    r22, 0x8
	  bge-      .loc_0x768

	.loc_0x3CC:
	  li        r23, -0x1
	  li        r25, 0x64

	.loc_0x3D4:
	  lbz       r0, 0x34(r1)
	  rlwinm    r0,r0,27,30,31
	  stb       r0, 0xD4(r31)
	  lbz       r0, 0xD6(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3F4
	  li        r0, 0x1
	  b         .loc_0x3F8

	.loc_0x3F4:
	  li        r0, 0

	.loc_0x3F8:
	  cmpwi     r0, 0
	  rlwinm    r27,r22,0,24,31
	  rlwinm    r29,r24,0,24,31
	  add       r28, r31, r27
	  li        r26, 0
	  beq-      .loc_0x47C
	  lbz       r0, 0xD4(r31)
	  addi      r22, r23, 0
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x424
	  li        r22, -0x1

	.loc_0x424:
	  cmpwi     r22, -0x1
	  beq-      .loc_0x440
	  addi      r3, r31, 0
	  addi      r4, r22, 0
	  addi      r5, r25, 0
	  bl        -0x3AD8
	  mr        r22, r3

	.loc_0x440:
	  lbz       r0, 0x39C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  lbz       r0, 0x39D(r31)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x460
	  li        r3, -0x1
	  b         .loc_0x4E4

	.loc_0x460:
	  lbz       r5, 0x3C(r1)
	  addi      r3, r31, 0
	  addi      r4, r27, 0
	  addi      r6, r29, 0
	  addi      r7, r22, 0
	  bl        0x98C
	  b         .loc_0x4E4

	.loc_0x47C:
	  addi      r22, r23, 0
	  cmpwi     r22, -0x1
	  beq-      .loc_0x49C
	  addi      r3, r31, 0
	  addi      r4, r22, 0
	  addi      r5, r25, 0
	  bl        -0x3B34
	  mr        r22, r3

	.loc_0x49C:
	  lbz       r0, 0xD4(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x4AC
	  li        r22, -0x1

	.loc_0x4AC:
	  lbz       r0, 0x39C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x4CC
	  lbz       r0, 0x39D(r31)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x4CC
	  li        r3, -0x1
	  b         .loc_0x4E4

	.loc_0x4CC:
	  lbz       r5, 0x3C(r1)
	  addi      r3, r31, 0
	  addi      r4, r27, 0
	  addi      r6, r29, 0
	  addi      r7, r22, 0
	  bl        0x4A0

	.loc_0x4E4:
	  cmpwi     r3, -0x1
	  beq-      .loc_0x4F8
	  lbz       r0, 0x3C(r1)
	  li        r26, 0x1
	  stb       r0, 0x94(r28)

	.loc_0x4F8:
	  stw       r26, 0x90(r31)
	  stb       r25, 0xCC(r31)
	  stb       r24, 0xCD(r31)
	  stw       r23, 0xD0(r31)
	  lbz       r0, 0xD4(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x520
	  li        r0, 0x1
	  stb       r0, 0xD6(r31)
	  b         .loc_0x528

	.loc_0x520:
	  li        r0, 0
	  stb       r0, 0xD6(r31)

	.loc_0x528:
	  lbz       r0, 0xD4(r31)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x56C
	  addi      r3, r22, 0
	  cmpwi     r3, -0x1
	  bne-      .loc_0x550
	  lbz       r5, 0xCC(r31)
	  addi      r3, r31, 0
	  addi      r4, r23, 0
	  bl        -0x3BEC

	.loc_0x550:
	  lbz       r21, 0x3D(r1)
	  mr        r5, r3
	  lbz       r0, 0x397(r31)
	  lwz       r3, 0x9C(r31)
	  add       r4, r21, r0
	  bl        0x29DC
	  stb       r21, 0x3C(r1)

	.loc_0x56C:
	  addis     r0, r23, 0x1
	  lbz       r3, 0x3C(r1)
	  cmplwi    r0, 0xFFFF
	  stb       r3, 0xD5(r31)
	  beq+      .loc_0x270
	  cmplwi    r23, 0
	  stw       r23, 0x8C(r31)
	  bne-      .loc_0x768
	  li        r0, -0x1
	  stw       r0, 0x8C(r31)
	  b         .loc_0x768

	.loc_0x598:
	  rlwinm    r0,r5,0,24,27
	  cmpwi     r0, 0x80
	  beq-      .loc_0x5AC
	  cmplwi    r5, 0xF9
	  bne-      .loc_0x6CC

	.loc_0x5AC:
	  rlwinm    r0,r4,0,24,31
	  li        r22, 0x1
	  cmplwi    r0, 0xF9
	  li        r23, 0
	  bne-      .loc_0x614
	  mr        r3, r31
	  bl        -0x3E84
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  rlwinm    r21,r0,0,24,31
	  rlwinm    r4,r0,0,29,31
	  bl        -0x3158
	  rlwinm    r3,r3,0,24,31
	  cmplwi    r3, 0x7
	  bgt-      .loc_0x5F0
	  cmplwi    r3, 0
	  bne-      .loc_0x604

	.loc_0x5F0:
	  rlwinm.   r0,r21,0,24,24
	  beq+      .loc_0x270
	  mr        r3, r31
	  bl        -0x3EBC
	  b         .loc_0x270

	.loc_0x604:
	  rlwinm.   r0,r21,0,24,24
	  addi      r4, r3, 0x80
	  beq-      .loc_0x614
	  addi      r4, r4, 0x8

	.loc_0x614:
	  rlwinm    r0,r4,0,28,31
	  rlwinm    r21,r4,0,28,31
	  cmplwi    r0, 0x8
	  bne-      .loc_0x62C
	  li        r22, 0x2
	  subi      r21, r21, 0x8

	.loc_0x62C:
	  rlwinm    r0,r21,0,24,31
	  cmplwi    r0, 0x8
	  ble-      .loc_0x658
	  addi      r3, r31, 0
	  subi      r21, r21, 0x8
	  bl        -0x3F00
	  rlwinm    r23,r3,0,24,31
	  cmpwi     r23, 0x64
	  ble-      .loc_0x658
	  subi      r0, r23, 0x62
	  mulli     r23, r0, 0x14

	.loc_0x658:
	  rlwinm.   r0,r21,0,24,31
	  bne-      .loc_0x6A0
	  li        r21, 0
	  stw       r21, 0x8C(r31)
	  b         .loc_0x688

	.loc_0x66C:
	  mr        r3, r31
	  bl        -0x3F30
	  lwz       r0, 0x8C(r31)
	  addi      r21, r21, 0x1
	  rlwinm    r0,r0,8,0,23
	  rlwimi    r0,r3,0,24,31
	  stw       r0, 0x8C(r31)

	.loc_0x688:
	  cmpw      r21, r22
	  blt+      .loc_0x66C
	  lwz       r0, 0x8C(r31)
	  cmpwi     r0, 0
	  beq+      .loc_0x270
	  b         .loc_0x768

	.loc_0x6A0:
	  cmpwi     r23, 0
	  bne-      .loc_0x6B8
	  addi      r3, r31, 0
	  addi      r4, r21, 0
	  bl        0x710
	  b         .loc_0x270

	.loc_0x6B8:
	  addi      r3, r31, 0
	  addi      r4, r21, 0
	  rlwinm    r5,r23,0,16,31
	  bl        0x65C
	  b         .loc_0x270

	.loc_0x6CC:
	  cmpwi     r0, 0x90
	  li        r21, 0
	  bne-      .loc_0x6E8
	  addi      r3, r31, 0
	  rlwinm    r4,r5,0,28,31
	  bl        -0x3CC0
	  b         .loc_0x740

	.loc_0x6E8:
	  cmpwi     r0, 0xA0
	  bne-      .loc_0x700
	  addi      r3, r31, 0
	  rlwinm    r4,r5,0,28,31
	  bl        -0x39B8
	  b         .loc_0x740

	.loc_0x700:
	  cmpwi     r0, 0xB0
	  bne-      .loc_0x730
	  rlwinm.   r0,r5,0,28,28
	  rlwinm    r5,r5,0,29,31
	  beq-      .loc_0x71C
	  li        r4, 0x1
	  b         .loc_0x720

	.loc_0x71C:
	  li        r4, 0

	.loc_0x720:
	  mr        r3, r31
	  bl        -0x7E4
	  mr        r21, r3
	  b         .loc_0x740

	.loc_0x730:
	  addi      r3, r31, 0
	  li        r5, 0
	  bl        -0x938
	  mr        r21, r3

	.loc_0x740:
	  cmplwi    r21, 0
	  beq+      .loc_0x270
	  cmplwi    r21, 0x1
	  beq-      .loc_0x768
	  cmplwi    r21, 0x2
	  beq+      .loc_0x1A0
	  cmplwi    r21, 0x3
	  bne+      .loc_0x270
	  li        r3, -0x1
	  b         .loc_0x8A4

	.loc_0x768:
	  lfs       f31, -0x7F08(r2)
	  li        r21, 0
	  lfs       f30, -0x7F0C(r2)
	  li        r22, 0

	.loc_0x778:
	  add       r3, r31, r22
	  lfs       f0, 0x154(r3)
	  addi      r3, r3, 0x14C
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0x7D8
	  lfs       f1, 0x0(r3)
	  cmpwi     r21, 0x5
	  lfs       f0, 0xC(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x8(r3)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x8(r3)
	  ble-      .loc_0x7B8
	  cmpwi     r21, 0xB
	  blt-      .loc_0x7C8

	.loc_0x7B8:
	  li        r0, 0x1
	  slw       r0, r0, r21
	  or        r30, r30, r0
	  b         .loc_0x7D8

	.loc_0x7C8:
	  lfs       f1, 0x0(r3)
	  addi      r3, r31, 0
	  rlwinm    r4,r21,0,24,31
	  bl        0x160C

	.loc_0x7D8:
	  addi      r21, r21, 0x1
	  addi      r22, r22, 0x10
	  cmpwi     r21, 0x12
	  blt+      .loc_0x778
	  lbz       r0, 0x370(r31)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x804
	  lbz       r0, 0x340(r31)
	  subi      r3, r13, 0x7FC0
	  lbzx      r0, r3, r0
	  or        r30, r30, r0

	.loc_0x804:
	  lbz       r0, 0x371(r31)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x820
	  lbz       r0, 0x358(r31)
	  subi      r3, r13, 0x7FC0
	  lbzx      r0, r3, r0
	  or        r30, r30, r0

	.loc_0x820:
	  lwz       r0, 0x3D8(r31)
	  li        r23, 0
	  li        r22, 0
	  or        r0, r0, r30
	  stw       r0, 0x3D8(r31)

	.loc_0x834:
	  addi      r21, r22, 0x44
	  add       r21, r31, r21
	  lwz       r3, 0x0(r21)
	  cmplwi    r3, 0
	  beq-      .loc_0x890
	  lbz       r0, 0x3C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x890
	  li        r0, 0x1
	  lhz       r4, 0x3A0(r31)
	  slw       r0, r0, r23
	  lbz       r5, 0x39E(r31)
	  and       r0, r4, r0
	  sraw      r0, r0, r23
	  or        r0, r5, r0
	  rlwinm    r4,r0,0,24,31
	  bl        .loc_0x0
	  cmpwi     r3, -0x1
	  bne-      .loc_0x890
	  lwz       r3, 0x0(r21)
	  bl        0x125C
	  li        r0, 0
	  stw       r0, 0x0(r21)

	.loc_0x890:
	  addi      r23, r23, 0x1
	  addi      r22, r22, 0x4
	  cmpwi     r23, 0x10
	  blt+      .loc_0x834
	  li        r3, 0

	.loc_0x8A4:
	  lwz       r0, 0x94(r1)
	  addi      r11, r1, 0x90
	  bl        0x201744
	  lmw       r21, 0x54(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80013780
 * Size:	0000A8
 */
void SeqUpdate(seqp_*, unknown)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x2AC(r3)
	  lwz       r0, 0x3D8(r28)
	  cmplwi    r3, 0
	  or        r30, r4, r0
	  beq-      .loc_0x3C
	  addi      r4, r3, 0xA
	  li        r0, 0
	  lhz       r3, 0xA(r3)
	  sth       r0, 0x0(r4)
	  or        r30, r30, r3

	.loc_0x3C:
	  li        r0, 0
	  cmplwi    r30, 0
	  stw       r0, 0x3D8(r28)
	  beq-      .loc_0x58
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x29B4

	.loc_0x58:
	  li        r29, 0
	  li        r31, 0

	.loc_0x60:
	  addi      r0, r31, 0x44
	  lwzx      r3, r28, r0
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  lbz       r0, 0x3C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  mr        r4, r30
	  bl        .loc_0x0

	.loc_0x84:
	  addi      r29, r29, 0x1
	  addi      r31, r31, 0x4
	  cmplwi    r29, 0x10
	  blt+      .loc_0x60
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
