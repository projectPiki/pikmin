#include "jaudio/seqsetup.h"

/*
 * --INFO--
 * Address:	80013DA0
 * Size:	0000A0
 */
void Jaq_Reset(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  lis       r3, 0x8032
	  subi      r10, r3, 0x560
	  li        r0, 0x100
	  stwu      r1, -0x8(r1)
	  addi      r9, r4, 0
	  addi      r8, r4, 0
	  addi      r7, r4, 0
	  addis     r6, r10, 0x4
	  li        r3, 0
	  mtctr     r0

	.loc_0x34:
	  add       r11, r10, r4
	  add       r5, r6, r3
	  stb       r9, 0x3C(r11)
	  addi      r3, r3, 0x4
	  addi      r4, r4, 0x434
	  sth       r8, 0x3A0(r11)
	  stb       r7, 0x39E(r11)
	  stw       r11, 0x3840(r5)
	  bdnz+     .loc_0x34
	  li        r6, 0
	  li        r4, 0x100
	  li        r0, 0x10
	  stw       r6, 0x2C38(r13)
	  addis     r5, r10, 0x4
	  li        r3, 0
	  stw       r6, 0x2C3C(r13)
	  stw       r4, 0x2C40(r13)
	  mtctr     r0

	.loc_0x7C:
	  add       r4, r5, r3
	  addi      r3, r3, 0x4
	  stw       r6, 0x3800(r4)
	  bdnz+     .loc_0x7C
	  bl        -0x396C
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
void Jaq_GetRemainFreeTracks(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80013E40
 * Size:	000088
 */
static void BackTrack(seqp_*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  li        r5, 0
	  stw       r3, 0x8(r1)
	  lwz       r6, 0x8(r1)
	  stb       r5, 0x3C(r6)
	  lbz       r0, 0x3E4(r6)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x7C
	  lwz       r0, 0x2C40(r13)
	  cmplwi    r0, 0x100
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x80

	.loc_0x34:
	  lwz       r4, 0x2C38(r13)
	  lis       r3, 0x8036
	  addi      r0, r3, 0x32E0
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  stw       r6, 0x0(r3)
	  lwz       r3, 0x2C38(r13)
	  lwz       r4, 0x2C40(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2C38(r13)
	  addi      r3, r4, 0x1
	  lwz       r0, 0x2C38(r13)
	  stw       r3, 0x2C40(r13)
	  cmplwi    r0, 0x100
	  bne-      .loc_0x74
	  stw       r5, 0x2C38(r13)

	.loc_0x74:
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x7C:
	  li        r3, 0

	.loc_0x80:
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80013EE0
 * Size:	000064
 */
static void GetNewTrack()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2C40(r13)
	  cmplwi    r4, 0
	  bne-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r6, 0x2C3C(r13)
	  lis       r3, 0x8036
	  addi      r3, r3, 0x32E0
	  subi      r4, r4, 0x1
	  rlwinm    r5,r6,2,0,29
	  addi      r0, r6, 0x1
	  add       r3, r3, r5
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x2C3C(r13)
	  lwz       r0, 0x2C3C(r13)
	  stw       r4, 0x2C40(r13)
	  cmplwi    r0, 0x100
	  bne-      .loc_0x50
	  li        r0, 0
	  stw       r0, 0x2C3C(r13)

	.loc_0x50:
	  li        r4, 0x2
	  li        r0, 0x1
	  stb       r4, 0x3C(r3)
	  stb       r0, 0x3E4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80013F60
 * Size:	000048
 */
void AllocNewRoot(seqp_*)
{
	/*
	.loc_0x0:
	  lis       r4, 0x8036
	  li        r0, 0x10
	  addi      r5, r4, 0x32A0
	  li        r7, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x18:
	  add       r6, r5, r4
	  lwz       r0, 0x0(r6)
	  cmplwi    r0, 0
	  bne-      .loc_0x34
	  stw       r3, 0x0(r6)
	  mr        r3, r7
	  blr

	.loc_0x34:
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x18
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80013FC0
 * Size:	00004C
 */
void DeAllocRoot(seqp_*)
{
	/*
	.loc_0x0:
	  lis       r4, 0x8036
	  li        r0, 0x10
	  addi      r5, r4, 0x32A0
	  li        r7, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x18:
	  add       r6, r5, r4
	  lwz       r0, 0x0(r6)
	  cmplw     r0, r3
	  bne-      .loc_0x38
	  li        r0, 0
	  addi      r3, r7, 0
	  stw       r0, 0x0(r6)
	  blr

	.loc_0x38:
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x18
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014020
 * Size:	000018
 */
unknown Jaq_HandleToSeq(u32 handle)
{
	/*
	.loc_0x0:
	  lis       r4, 0x8036
	  rlwinm    r3,r3,2,0,29
	  addi      r0, r4, 0x32A0
	  add       r3, r0, r3
	  lwz       r3, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014040
 * Size:	000368
 */
static void Init_Track(seqp_*, u32, seqp_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r30, 0x18(r1)
	  addi      r31, r3, 0
	  bne-      .loc_0x58
	  stw       r4, 0x0(r31)
	  li        r7, 0
	  li        r6, 0x78
	  li        r4, 0x30
	  stw       r7, 0x4(r31)
	  li        r3, 0x1
	  li        r0, 0xA
	  sth       r6, 0x33A(r31)
	  sth       r4, 0x338(r31)
	  stb       r3, 0x33C(r31)
	  stb       r7, 0x39C(r31)
	  stb       r0, 0x39D(r31)
	  sth       r7, 0x3A0(r31)
	  stb       r7, 0x39E(r31)
	  b         .loc_0xA8

	.loc_0x58:
	  lwz       r0, 0x0(r5)
	  li        r3, 0
	  stw       r0, 0x0(r31)
	  stw       r4, 0x4(r31)
	  lbz       r0, 0x3E(r5)
	  stb       r0, 0x3E(r31)
	  lhz       r0, 0x33A(r5)
	  sth       r0, 0x33A(r31)
	  stb       r3, 0x3E3(r31)
	  lfs       f0, 0x334(r5)
	  stfs      f0, 0x334(r31)
	  lhz       r0, 0x338(r5)
	  sth       r0, 0x338(r31)
	  lbz       r0, 0x33C(r5)
	  stb       r0, 0x33C(r31)
	  lbz       r0, 0x39C(r5)
	  stb       r0, 0x39C(r31)
	  lbz       r0, 0x39D(r5)
	  stb       r0, 0x39D(r31)
	  sth       r3, 0x3A0(r31)

	.loc_0xA8:
	  li        r4, 0
	  li        r3, 0x1
	  stw       r4, 0x8(r31)
	  li        r0, 0x12
	  stw       r4, 0xD0(r31)
	  stw       r4, 0x8C(r31)
	  stb       r3, 0x3C(r31)
	  stw       r5, 0x40(r31)
	  stb       r4, 0x3A6(r31)
	  stb       r4, 0x3A4(r31)
	  stw       r4, 0x3D0(r31)
	  lfs       f1, -0x7ED8(r2)
	  lfs       f0, -0x7ED4(r2)
	  mtctr     r0

	.loc_0xE0:
	  add       r3, r31, r4
	  addi      r4, r4, 0x10
	  stfs      f1, 0x154(r3)
	  stfs      f0, 0x14C(r3)
	  stfs      f0, 0x150(r3)
	  bdnz+     .loc_0xE0
	  lfs       f1, -0x7ED8(r2)
	  li        r0, 0x3
	  li        r3, 0x10
	  stfs      f1, 0x15C(r31)
	  stfs      f1, 0x160(r31)
	  stfs      f1, 0x15C(r31)
	  stfs      f1, 0x160(r31)
	  lfs       f0, -0x7ED0(r2)
	  stfs      f0, 0x17C(r31)
	  stfs      f0, 0x180(r31)
	  stfs      f0, 0x24C(r31)
	  stfs      f0, 0x250(r31)
	  stfs      f1, 0x25C(r31)
	  stfs      f1, 0x260(r31)
	  stfs      f1, 0x16C(r31)
	  stfs      f1, 0x170(r31)
	  stfs      f1, 0x18C(r31)
	  stfs      f1, 0x190(r31)
	  mtctr     r0

	.loc_0x144:
	  add       r4, r31, r3
	  addi      r3, r3, 0x10
	  stfs      f1, 0x20C(r4)
	  stfs      f1, 0x210(r4)
	  bdnz+     .loc_0x144
	  lfs       f0, -0x7ED8(r2)
	  li        r0, 0x20
	  li        r4, 0
	  li        r3, 0
	  stfs      f0, 0x19C(r31)
	  stfs      f0, 0x1A0(r31)
	  mtctr     r0

	.loc_0x174:
	  addi      r0, r3, 0x26C
	  addi      r3, r3, 0x2
	  sthx      r4, r31, r0
	  bdnz+     .loc_0x174
	  lbz       r0, 0x3F(r31)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x19C
	  lwz       r0, 0x40(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x204

	.loc_0x19C:
	  li        r8, 0
	  li        r7, 0x1
	  sth       r8, 0x27C(r31)
	  li        r6, 0x7FFF
	  li        r5, 0x4000
	  li        r0, 0x3
	  sth       r7, 0x27E(r31)
	  li        r4, 0x2
	  li        r3, 0x1A
	  sth       r7, 0x280(r31)
	  sth       r6, 0x282(r31)
	  sth       r5, 0x284(r31)
	  mtctr     r0

	.loc_0x1D0:
	  add       r5, r31, r8
	  addi      r8, r8, 0x1
	  stb       r4, 0x3DC(r5)
	  stb       r4, 0x3DF(r5)
	  stb       r3, 0x13A(r5)
	  bdnz+     .loc_0x1D0
	  li        r0, 0xF0
	  li        r3, 0xC
	  sth       r0, 0x278(r31)
	  li        r0, 0x40
	  sth       r3, 0x27A(r31)
	  sth       r0, 0x286(r31)
	  b         .loc_0x294

	.loc_0x204:
	  li        r0, 0x5
	  li        r3, 0
	  mtctr     r0

	.loc_0x210:
	  lwz       r5, 0x40(r31)
	  addi      r4, r3, 0x27C
	  addi      r3, r3, 0x2
	  lhzx      r0, r5, r4
	  sthx      r0, r31, r4
	  bdnz+     .loc_0x210
	  lwz       r3, 0x40(r31)
	  li        r0, 0x3
	  li        r6, 0
	  lhz       r3, 0x278(r3)
	  sth       r3, 0x278(r31)
	  lwz       r3, 0x40(r31)
	  lhz       r3, 0x27A(r3)
	  sth       r3, 0x27A(r31)
	  lwz       r3, 0x40(r31)
	  lhz       r3, 0x286(r3)
	  sth       r3, 0x286(r31)
	  mtctr     r0

	.loc_0x258:
	  lwz       r4, 0x40(r31)
	  addi      r0, r6, 0x3DC
	  add       r5, r31, r6
	  addi      r3, r6, 0x3DF
	  lbzx      r4, r4, r0
	  addi      r0, r6, 0x13A
	  addi      r6, r6, 0x1
	  stb       r4, 0x3DC(r5)
	  lwz       r4, 0x40(r31)
	  lbzx      r3, r4, r3
	  stb       r3, 0x3DF(r5)
	  lwz       r3, 0x40(r31)
	  lbzx      r0, r3, r0
	  stb       r0, 0x13A(r5)
	  bdnz+     .loc_0x258

	.loc_0x294:
	  li        r0, 0x10
	  li        r5, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x2A4:
	  add       r4, r31, r3
	  addi      r3, r3, 0x4
	  stw       r5, 0x2B0(r4)
	  stw       r5, 0x44(r4)
	  bdnz+     .loc_0x2A4
	  li        r9, 0
	  li        r0, 0x8
	  addi      r7, r9, 0
	  addi      r5, r9, 0
	  li        r3, 0
	  li        r4, 0
	  li        r8, 0xFF
	  mtctr     r0

	.loc_0x2D8:
	  addi      r0, r9, 0x94
	  addi      r6, r4, 0x9C
	  stbx      r8, r31, r0
	  addi      r0, r3, 0xBC
	  addi      r9, r9, 0x1
	  addi      r3, r3, 0x2
	  stwx      r7, r31, r6
	  addi      r4, r4, 0x4
	  sthx      r5, r31, r0
	  bdnz+     .loc_0x2D8
	  li        r30, 0
	  addi      r3, r31, 0
	  stb       r30, 0xD4(r31)
	  stb       r30, 0xD5(r31)
	  stw       r30, 0x90(r31)
	  stb       r30, 0xD6(r31)
	  bl        0xB08
	  stb       r30, 0x396(r31)
	  li        r4, -0x1
	  li        r0, 0x10
	  li        r3, 0
	  stb       r30, 0x397(r31)
	  stw       r4, 0x398(r31)
	  mtctr     r0

	.loc_0x338:
	  add       r4, r31, r3
	  addi      r3, r3, 0x4
	  stb       r30, 0x2F0(r4)
	  stb       r30, 0x2F1(r4)
	  bdnz+     .loc_0x338
	  li        r0, 0
	  stb       r0, 0x3E2(r31)
	  lmw       r30, 0x18(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800143C0
 * Size:	0000A0
 */
BOOL Jaq_StopSeq(u32 index)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r3, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x8C

	.loc_0x20:
	  lis       r4, 0x8036
	  rlwinm    r3,r3,2,0,29
	  addi      r0, r4, 0x32A0
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r31, r0
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x8C

	.loc_0x48:
	  lbz       r0, 0x3C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x80
	  bge-      .loc_0x64
	  cmpwi     r0, 0
	  bge-      .loc_0x88
	  b         .loc_0x80

	.loc_0x64:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x80
	  mr        r3, r31
	  bl        -0x5F0
	  mr        r3, r31
	  bl        -0x478
	  b         .loc_0x88

	.loc_0x80:
	  li        r0, 0x3
	  stb       r0, 0x3C(r31)

	.loc_0x88:
	  li        r3, 0x1

	.loc_0x8C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014460
 * Size:	000054
 */
static void __StopSeq(seqp_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0xCF8
	  mr        r3, r31
	  bl        0x520
	  mr        r3, r31
	  bl        -0x4C8
	  lbz       r0, 0x3D(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x40
	  lbz       r3, 0x3E(r31)
	  bl        -0x64BC

	.loc_0x40:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800144C0
 * Size:	000024
 */
unknown Jaq_SetSeqData(unknown param_1, u8* param_2, u32 param_3, unknown param_4)
{
	return Jaq_SetSeqData_Limit(param_1, param_2, param_3, param_4, 0);
}

/*
 * --INFO--
 * Address:	80014500
 * Size:	000170
 */
unknown Jaq_SetSeqData_Limit(unknown, u8*, u32, unknown, unknown)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  mr.       r25, r3
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  addi      r29, r7, 0
	  bne-      .loc_0x54
	  bl        0x1E4A54
	  mr        r30, r3
	  bl        -0x650
	  addi      r0, r3, 0
	  addi      r3, r30, 0
	  mr        r25, r0
	  bl        0x1E4A64
	  cmplwi    r25, 0
	  bne-      .loc_0x5C
	  li        r3, -0x1
	  b         .loc_0x15C

	.loc_0x54:
	  li        r0, 0
	  stb       r0, 0x3E4(r25)

	.loc_0x5C:
	  mr        r3, r25
	  bl        -0x600
	  addi      r30, r3, 0
	  cmpwi     r30, -0x1
	  bne-      .loc_0x78
	  li        r3, -0x1
	  b         .loc_0x15C

	.loc_0x78:
	  cmpwi     r28, 0x1
	  stb       r28, 0x3D(r25)
	  beq-      .loc_0xA8
	  bge-      .loc_0x94
	  cmpwi     r28, 0
	  bge-      .loc_0xA0
	  b         .loc_0xEC

	.loc_0x94:
	  cmpwi     r28, 0x3
	  bge-      .loc_0xEC
	  b         .loc_0xE4

	.loc_0xA0:
	  mr        r31, r26
	  b         .loc_0xEC

	.loc_0xA8:
	  mr        r3, r27
	  bl        -0x66AC
	  stb       r3, 0x3E(r25)
	  lbz       r4, 0x3E(r25)
	  addis     r0, r4, 0
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0xCC
	  li        r3, -0x1
	  b         .loc_0x15C

	.loc_0xCC:
	  addi      r3, r26, 0
	  addi      r6, r27, 0
	  li        r5, 0
	  bl        -0x63B8
	  li        r31, 0
	  b         .loc_0xEC

	.loc_0xE4:
	  li        r31, 0
	  stb       r26, 0x3E(r25)

	.loc_0xEC:
	  stw       r30, 0x88(r25)
	  li        r0, 0x3
	  addi      r3, r25, 0
	  addi      r4, r31, 0
	  stb       r0, 0x3F(r25)
	  li        r5, 0
	  bl        -0x5C4
	  lis       r3, 0x8036
	  rlwinm    r4,r30,6,0,25
	  addi      r0, r3, 0x2EA0
	  add       r31, r0, r4
	  addi      r3, r31, 0
	  bl        -0x3F5C
	  addi      r3, r25, 0
	  addi      r4, r31, 0
	  bl        -0x3F48
	  addi      r3, r25, 0xD8
	  rlwinm    r4,r29,0,24,31
	  bl        0x158C
	  lfs       f0, -0x7ED8(r2)
	  mr        r3, r25
	  stfs      f0, 0x330(r25)
	  lfs       f0, -0x7ED4(r2)
	  stfs      f0, 0x334(r25)
	  bl        -0x3B6C
	  li        r0, 0x2
	  addi      r3, r30, 0
	  stb       r0, 0x3C(r25)

	.loc_0x15C:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014680
 * Size:	00002C
 */
void Jaq_SetBankNumber(void)
{
	/*
	.loc_0x0:
	  lhz       r0, 0x278(r3)
	  cmplwi    r3, 0
	  rlwinm    r5,r0,0,24,31
	  bne-      .loc_0x18
	  li        r3, 0
	  blr

	.loc_0x18:
	  rlwinm    r0,r4,8,16,23
	  or        r0, r0, r5
	  sth       r0, 0x278(r3)
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800146C0
 * Size:	0000B4
 */
void Jaq_StartSeq(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x20:
	  lis       r4, 0x8036
	  rlwinm    r3,r3,2,0,29
	  addi      r0, r4, 0x32A0
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x44:
	  lbzu      r0, 0x3C(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x88
	  bge-      .loc_0x64
	  cmpwi     r0, 0
	  beq-      .loc_0x70
	  bge-      .loc_0x78
	  b         .loc_0x90

	.loc_0x64:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x90
	  b         .loc_0x80

	.loc_0x70:
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x78:
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x80:
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x88:
	  li        r0, 0x1
	  stb       r0, 0x0(r3)

	.loc_0x90:
	  lis       r3, 0x8001
	  lwz       r4, 0x0(r4)
	  addi      r3, r3, 0x4AC0
	  bl        -0xD59C
	  li        r3, 0x1

	.loc_0xA4:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014780
 * Size:	00014C
 */
void Jaq_OpenTrack(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm.   r6,r4,0,26,26
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,28,31
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  addi      r27, r3, 0
	  addi      r25, r5, 0
	  rlwinm    r28,r4,26,30,31
	  stb       r0, 0x18(r1)
	  beq-      .loc_0x30
	  li        r28, 0x4

	.loc_0x30:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x48
	  mr        r3, r27
	  lbz       r4, 0x18(r1)
	  bl        -0x4720
	  stb       r3, 0x18(r1)

	.loc_0x48:
	  lbz       r31, 0x18(r1)
	  cmplwi    r31, 0x10
	  blt-      .loc_0x5C
	  li        r3, -0x1
	  b         .loc_0x138

	.loc_0x5C:
	  rlwinm    r30,r31,2,0,29
	  add       r26, r27, r30
	  lwzu      r0, 0x44(r26)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x78
	  bl        0x1AC

	.loc_0x78:
	  bl        -0x918
	  mr.       r29, r3
	  bne-      .loc_0x8C
	  li        r3, -0x1
	  b         .loc_0x138

	.loc_0x8C:
	  stw       r29, 0x0(r26)
	  li        r0, 0
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  lwz       r7, 0x88(r27)
	  addi      r5, r27, 0
	  rlwinm    r6,r7,4,0,27
	  rlwinm    r7,r7,0,0,3
	  or        r6, r6, r31
	  addis     r7, r7, 0x1000
	  rlwinm    r6,r6,0,4,31
	  or        r6, r7, r6
	  stw       r6, 0x88(r29)
	  stw       r0, 0x84(r29)
	  lbz       r0, 0x3D(r27)
	  stb       r0, 0x3D(r29)
	  stb       r28, 0x3F(r29)
	  bl        -0x810
	  lwz       r4, 0x40(r29)
	  li        r0, 0x1
	  slw       r0, r0, r31
	  lhz       r3, 0x3A0(r4)
	  lbz       r4, 0x39E(r4)
	  and       r0, r3, r0
	  sraw      r0, r0, r31
	  or        r0, r4, r0
	  stb       r0, 0x39E(r29)
	  lwz       r0, 0x40(r29)
	  add       r3, r0, r30
	  lwz       r0, 0x2B0(r3)
	  stw       r0, 0x2AC(r29)
	  lwz       r4, 0x2AC(r29)
	  cmplwi    r4, 0
	  beq-      .loc_0x120
	  lwz       r3, 0x4(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x4(r4)

	.loc_0x120:
	  addi      r3, r29, 0xD8
	  li        r4, 0
	  bl        0x1318
	  mr        r3, r29
	  bl        -0x3DD0
	  li        r3, 0

	.loc_0x138:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800148E0
 * Size:	0000B4
 */
void __AllNoteOff(seqp_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  mr        r27, r3
	  lwz       r0, 0x40(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x64
	  li        r31, 0
	  li        r28, 0
	  addi      r29, r31, 0
	  li        r30, 0xFF

	.loc_0x30:
	  addi      r3, r27, 0
	  rlwinm    r4,r28,0,24,31
	  li        r5, 0xA
	  bl        -0xD3C
	  addi      r0, r28, 0x94
	  addi      r28, r28, 0x1
	  stbx      r30, r27, r0
	  addi      r0, r31, 0x9C
	  cmplwi    r28, 0x8
	  addi      r31, r31, 0x4
	  stwx      r29, r27, r0
	  blt+      .loc_0x30
	  b         .loc_0xA0

	.loc_0x64:
	  li        r28, 0
	  li        r31, 0
	  addi      r30, r28, 0
	  li        r29, 0xFF

	.loc_0x74:
	  addi      r3, r27, 0
	  rlwinm    r4,r28,0,24,31
	  bl        -0xCDC
	  addi      r0, r28, 0x94
	  addi      r28, r28, 0x1
	  stbx      r29, r27, r0
	  addi      r0, r31, 0x9C
	  cmplwi    r28, 0x8
	  addi      r31, r31, 0x4
	  stwx      r30, r27, r0
	  blt+      .loc_0x74

	.loc_0xA0:
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800149A0
 * Size:	000120
 */
void Jaq_CloseTrack(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  mr.       r27, r3
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x10C

	.loc_0x20:
	  lbz       r0, 0x3C(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x10C

	.loc_0x34:
	  mr        r3, r27
	  bl        -0xF8
	  mr        r3, r27
	  bl        -0xBA0
	  li        r31, 0
	  li        r28, 0
	  addi      r30, r31, 0

	.loc_0x50:
	  addi      r29, r31, 0x44
	  add       r29, r27, r29
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  bl        .loc_0x0
	  stw       r30, 0x0(r29)

	.loc_0x6C:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x4
	  cmplwi    r28, 0x10
	  blt+      .loc_0x50
	  lwz       r4, 0x2AC(r27)
	  cmplwi    r4, 0
	  beq-      .loc_0x9C
	  lwz       r3, 0x4(r4)
	  li        r0, 0
	  subi      r3, r3, 0x1
	  stw       r3, 0x4(r4)
	  stw       r0, 0x2AC(r27)

	.loc_0x9C:
	  li        r0, 0x10
	  li        r6, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0xAC:
	  addi      r5, r3, 0x2B0
	  add       r5, r27, r5
	  lwz       r4, 0x0(r5)
	  cmplwi    r4, 0
	  beq-      .loc_0xC8
	  stw       r6, 0x0(r4)
	  stw       r6, 0x0(r5)

	.loc_0xC8:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0xAC
	  li        r0, 0
	  stb       r0, 0x39E(r27)
	  sth       r0, 0x3A0(r27)
	  lwz       r4, 0x40(r27)
	  cmplwi    r4, 0
	  beq-      .loc_0xF8
	  addi      r3, r27, 0xD8
	  addi      r4, r4, 0xD8
	  bl        -0xB2D0
	  b         .loc_0x100

	.loc_0xF8:
	  addi      r3, r27, 0xD8
	  bl        -0xB3DC

	.loc_0x100:
	  mr        r3, r27
	  bl        -0x44E4
	  li        r3, 0

	.loc_0x10C:
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014AC0
 * Size:	0000E8
 */
static void Jaq_RootCallback(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stfd      f31, 0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0xC4
	  lbz       r0, 0x3C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xC4
	  cmplwi    r0, 0x3
	  bne-      .loc_0x44
	  mr        r3, r31
	  bl        -0x698
	  li        r3, -0x1
	  b         .loc_0xD0

	.loc_0x44:
	  lfs       f1, 0x330(r31)
	  lfs       f0, 0x334(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x330(r31)
	  lfs       f0, 0x330(r31)
	  lfs       f31, -0x7ED4(r2)
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0xA4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x13AC
	  b         .loc_0xCC

	.loc_0x74:
	  lfs       f0, 0x330(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  fsubs     f0, f0, f31
	  stfs      f0, 0x330(r31)
	  bl        -0x1C88
	  cmpwi     r3, -0x1
	  bne-      .loc_0xA4
	  mr        r3, r31
	  bl        -0x6F8
	  li        r3, -0x1
	  b         .loc_0xD0

	.loc_0xA4:
	  lfs       f0, 0x330(r31)
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  beq+      .loc_0x74
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x13FC
	  b         .loc_0xCC

	.loc_0xC4:
	  li        r3, -0x1
	  b         .loc_0xD0

	.loc_0xCC:
	  li        r3, 0

	.loc_0xD0:
	  lwz       r0, 0x24(r1)
	  lfd       f31, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
