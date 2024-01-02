#include "types.h"

/*
 * --INFO--
 * Address:	8020AAA4
 * Size:	000020
 */
void CARDProbe(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1273C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void CARDProbeEx(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020AAC4
 * Size:	0003B8
 */
void DoMount(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  mulli     r4, r29, 0x108
	  stw       r28, 0x20(r1)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3420
	  add       r3, r0, r4
	  lwz       r0, 0x24(r3)
	  addi      r31, r3, 0
	  cmpwi     r0, 0
	  bne-      .loc_0x2D0
	  addi      r3, r29, 0
	  addi      r4, r1, 0x18
	  bl        -0x2964
	  mr.       r30, r3
	  blt-      .loc_0x36C
	  lwz       r0, 0x18(r1)
	  lis       r4, 0x802F
	  lis       r3, 0x802F
	  rlwinm    r0,r0,0,24,29
	  sth       r0, 0x8(r31)
	  subi      r0, r3, 0x7420
	  subi      r4, r4, 0x7440
	  lwz       r3, 0x18(r1)
	  rlwinm    r3,r3,23,27,29
	  add       r3, r4, r3
	  lwz       r3, 0x0(r3)
	  stw       r3, 0xC(r31)
	  lhz       r4, 0x8(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r4,r4,20,0,11
	  srawi     r4, r4, 0x3
	  addze     r4, r4
	  divw      r3, r4, r3
	  sth       r3, 0x10(r31)
	  lwz       r3, 0x18(r1)
	  rlwinm    r3,r3,26,27,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x14(r31)
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0xCC
	  lhz       r0, 0x10(r31)
	  cmplwi    r0, 0x8
	  bge-      .loc_0xD4

	.loc_0xCC:
	  li        r30, -0x2
	  b         .loc_0x36C

	.loc_0xD4:
	  mr        r3, r29
	  bl        -0x2738
	  mr.       r30, r3
	  blt-      .loc_0x36C
	  addi      r3, r29, 0
	  addi      r4, r1, 0x14
	  bl        -0x283C
	  mr.       r30, r3
	  blt-      .loc_0x36C
	  mr        r3, r29
	  bl        -0x1284C
	  cmpwi     r3, 0
	  bne-      .loc_0x110
	  li        r30, -0x3
	  b         .loc_0x36C

	.loc_0x110:
	  lbz       r0, 0x14(r1)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x22C
	  addi      r3, r29, 0
	  addi      r4, r31, 0x18
	  bl        -0x201C88
	  mr.       r30, r3
	  blt-      .loc_0x36C
	  bl        -0x10250
	  mulli     r0, r29, 0xC
	  add       r4, r3, r0
	  lbz       r0, 0x18(r31)
	  addi      r5, r31, 0x18
	  stb       r0, 0x0(r4)
	  addi      r8, r5, 0x2
	  addi      r9, r5, 0x3
	  lbz       r7, 0x18(r31)
	  addi      r10, r5, 0x4
	  lbz       r0, 0x19(r31)
	  addi      r11, r5, 0x5
	  addi      r12, r5, 0x6
	  stb       r0, 0x1(r4)
	  addi      r28, r5, 0x7
	  li        r5, 0x8
	  lbz       r0, 0x19(r31)
	  lbz       r6, 0x0(r8)
	  add       r0, r7, r0
	  stb       r6, 0x2(r4)
	  lbz       r7, 0x0(r8)
	  lbz       r6, 0x0(r9)
	  add       r0, r0, r7
	  stb       r6, 0x3(r4)
	  lbz       r7, 0x0(r9)
	  lbz       r6, 0x0(r10)
	  add       r0, r0, r7
	  stb       r6, 0x4(r4)
	  lbz       r7, 0x0(r10)
	  lbz       r6, 0x0(r11)
	  add       r0, r0, r7
	  stb       r6, 0x5(r4)
	  lbz       r7, 0x0(r11)
	  lbz       r6, 0x0(r12)
	  add       r0, r0, r7
	  stb       r6, 0x6(r4)
	  lbz       r7, 0x0(r12)
	  lbz       r6, 0x0(r28)
	  add       r0, r0, r7
	  stb       r6, 0x7(r4)
	  lbz       r6, 0x0(r28)
	  add       r0, r0, r6
	  b         .loc_0x388

	.loc_0x1DC:
	  subfic    r4, r5, 0xC
	  cmpwi     r5, 0xC
	  mtctr     r4
	  bge-      .loc_0x210

	.loc_0x1EC:
	  addi      r7, r5, 0x18
	  add       r7, r31, r7
	  lbz       r4, 0x0(r7)
	  addi      r5, r5, 0x1
	  stb       r4, 0x0(r6)
	  addi      r6, r6, 0x1
	  lbz       r4, 0x0(r7)
	  add       r0, r0, r4
	  bdnz+     .loc_0x1EC

	.loc_0x210:
	  add       r3, r3, r29
	  not       r0, r0
	  stb       r0, 0x26(r3)
	  li        r3, 0x1
	  bl        -0xFFB8
	  mr        r3, r30
	  b         .loc_0x398

	.loc_0x22C:
	  li        r0, 0x1
	  stw       r0, 0x24(r31)
	  bl        -0x10354
	  mulli     r0, r29, 0xC
	  addi      r30, r3, 0
	  add       r5, r30, r0
	  lbz       r4, 0x0(r5)
	  li        r6, 0x8
	  lbz       r0, 0x1(r5)
	  lbz       r3, 0x2(r5)
	  add       r28, r4, r0
	  lbz       r0, 0x3(r5)
	  add       r28, r28, r3
	  lbz       r3, 0x4(r5)
	  add       r28, r28, r0
	  lbz       r0, 0x5(r5)
	  add       r28, r28, r3
	  lbz       r3, 0x6(r5)
	  add       r28, r28, r0
	  lbz       r0, 0x7(r5)
	  add       r28, r28, r3
	  add       r28, r28, r0
	  b         .loc_0x390

	.loc_0x288:
	  subfic    r0, r6, 0xC
	  cmpwi     r6, 0xC
	  mtctr     r0
	  bge-      .loc_0x2A8

	.loc_0x298:
	  lbz       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  add       r28, r28, r0
	  bdnz+     .loc_0x298

	.loc_0x2A8:
	  li        r3, 0
	  bl        -0x10044
	  add       r3, r30, r29
	  not       r0, r28
	  lbz       r3, 0x26(r3)
	  rlwinm    r0,r0,0,24,31
	  cmplw     r3, r0
	  beq-      .loc_0x2D0
	  li        r30, -0x5
	  b         .loc_0x36C

	.loc_0x2D0:
	  lwz       r0, 0x24(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x320
	  li        r0, 0x2
	  stw       r0, 0x24(r31)
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x2AFC
	  mr.       r30, r3
	  blt-      .loc_0x36C
	  lis       r3, 0x8020
	  addi      r4, r3, 0x7F64
	  addi      r3, r29, 0
	  bl        -0x12AD0
	  mr        r3, r29
	  bl        -0x11FA0
	  lis       r4, 0x1
	  lwz       r3, 0x80(r31)
	  subi      r4, r4, 0x6000
	  bl        -0x14228

	.loc_0x320:
	  lwz       r4, 0x24(r31)
	  lis       r3, 0x8021
	  lwz       r0, 0xC(r31)
	  subi      r7, r3, 0x5184
	  subi      r3, r4, 0x2
	  mullw     r4, r0, r3
	  lwz       r5, 0x80(r31)
	  rlwinm    r0,r3,13,0,18
	  add       r6, r5, r0
	  addi      r3, r29, 0
	  li        r5, 0x2000
	  bl        -0x1B20
	  mr.       r28, r3
	  bge-      .loc_0x364
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        -0x1F04

	.loc_0x364:
	  mr        r3, r28
	  b         .loc_0x398

	.loc_0x36C:
	  mr        r3, r29
	  bl        -0x12004
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x314
	  mr        r3, r30
	  b         .loc_0x398

	.loc_0x388:
	  addi      r6, r4, 0x8
	  b         .loc_0x1DC

	.loc_0x390:
	  addi      r3, r5, 0x8
	  b         .loc_0x288

	.loc_0x398:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  mtlr      r0
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020AE7C
 * Size:	000108
 */
void __CARDMountCallback(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  cmpwi     r29, -0x3
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  mulli     r5, r28, 0x108
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3420
	  add       r31, r0, r5
	  beq-      .loc_0xB0
	  bge-      .loc_0x4C
	  cmpwi     r29, -0x5
	  beq-      .loc_0xB0
	  b         .loc_0xBC

	.loc_0x4C:
	  cmpwi     r29, 0x1
	  beq-      .loc_0x9C
	  bge-      .loc_0xBC
	  cmpwi     r29, 0
	  bge-      .loc_0x64
	  b         .loc_0xBC

	.loc_0x64:
	  lwz       r3, 0x24(r31)
	  addi      r0, r3, 0x1
	  cmpwi     r0, 0x7
	  stw       r0, 0x24(r31)
	  bge-      .loc_0x8C
	  mr        r3, r28
	  bl        -0x434
	  mr.       r29, r3
	  blt-      .loc_0xBC
	  b         .loc_0xE8

	.loc_0x8C:
	  mr        r3, r31
	  bl        -0xB00
	  mr        r29, r3
	  b         .loc_0xBC

	.loc_0x9C:
	  mr        r3, r28
	  bl        -0x458
	  mr.       r29, r3
	  blt-      .loc_0xBC
	  b         .loc_0xE8

	.loc_0xB0:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0x220

	.loc_0xBC:
	  lwz       r30, 0xD0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0xD0(r31)
	  mr        r4, r29
	  bl        -0x202C
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  blrl

	.loc_0xE8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020AF84
 * Size:	000188
 */
void CARDMountAsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  mr.       r30, r3
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r29, r6, 0
	  blt-      .loc_0x2C
	  cmpwi     r30, 0x2
	  blt-      .loc_0x34

	.loc_0x2C:
	  li        r3, -0x80
	  b         .loc_0x174

	.loc_0x34:
	  mulli     r4, r30, 0x108
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3420
	  add       r31, r0, r4
	  bl        -0x1204C
	  lwz       r0, 0x4(r31)
	  addi      r28, r3, 0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x68
	  mr        r3, r28
	  bl        -0x1203C
	  li        r3, -0x1
	  b         .loc_0x174

	.loc_0x68:
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x94
	  mr        r3, r30
	  bl        -0x120F0
	  rlwinm.   r0,r3,0,28,28
	  beq-      .loc_0x94
	  mr        r3, r28
	  bl        -0x12068
	  li        r3, -0x2
	  b         .loc_0x174

	.loc_0x94:
	  li        r0, -0x1
	  stw       r0, 0x4(r31)
	  cmplwi    r29, 0
	  stw       r26, 0x80(r31)
	  stw       r27, 0xC4(r31)
	  beq-      .loc_0xB4
	  mr        r0, r29
	  b         .loc_0xBC

	.loc_0xB4:
	  lis       r3, 0x8020
	  addi      r0, r3, 0x7E60

	.loc_0xBC:
	  stw       r0, 0xD0(r31)
	  li        r0, 0
	  stw       r0, 0xCC(r31)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x104
	  lis       r3, 0x8020
	  addi      r4, r3, 0x7E98
	  addi      r3, r30, 0
	  bl        -0x12B28
	  cmpwi     r3, 0
	  bne-      .loc_0x104
	  li        r0, -0x3
	  stw       r0, 0x4(r31)
	  mr        r3, r28
	  bl        -0x120D8
	  li        r3, -0x3
	  b         .loc_0x174

	.loc_0x104:
	  li        r29, 0
	  stw       r29, 0x24(r31)
	  li        r0, 0x1
	  addi      r3, r30, 0
	  stw       r0, 0x0(r31)
	  li        r4, 0
	  bl        -0x12DA8
	  addi      r3, r31, 0xE0
	  bl        -0x14C74
	  stw       r29, 0x84(r31)
	  mr        r3, r28
	  stw       r29, 0x88(r31)
	  bl        -0x12114
	  lis       r3, 0x8021
	  subi      r0, r3, 0x5184
	  lis       r3, 0x8021
	  stw       r0, 0xDC(r31)
	  subi      r5, r3, 0x7EDC
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x1239C
	  cmpwi     r3, 0
	  bne-      .loc_0x168
	  li        r3, 0
	  b         .loc_0x174

	.loc_0x168:
	  stw       r29, 0xDC(r31)
	  mr        r3, r30
	  bl        -0x630

	.loc_0x174:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020B10C
 * Size:	000048
 */
void CARDMount(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r6, r6, 0x7E64
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  bl        -0x1A4
	  cmpwi     r3, 0
	  bge-      .loc_0x2C
	  b         .loc_0x34

	.loc_0x2C:
	  mr        r3, r31
	  bl        -0x2010

	.loc_0x34:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020B154
 * Size:	00009C
 */
void DoUnmount(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  mulli     r5, r28, 0x108
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3420
	  add       r31, r0, r5
	  bl        -0x1220C
	  lwz       r0, 0x0(r31)
	  addi      r30, r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x74
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0x12EAC
	  mr        r3, r28
	  bl        -0x12B8C
	  addi      r3, r31, 0xE0
	  bl        -0x14D80
	  li        r0, 0
	  stw       r0, 0x0(r31)
	  stw       r29, 0x4(r31)
	  stw       r0, 0x24(r31)

	.loc_0x74:
	  mr        r3, r30
	  bl        -0x12228
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020B1F0
 * Size:	0000AC
 */
void CARDUnmount(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r4, r1, 0xC
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x23A0
	  cmpwi     r3, 0
	  bge-      .loc_0x30
	  b         .loc_0x90

	.loc_0x30:
	  mulli     r4, r29, 0x108
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3420
	  add       r30, r0, r4
	  bl        -0x122B4
	  lwz       r0, 0x0(r30)
	  addi      r31, r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x84
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0x12F54
	  mr        r3, r29
	  bl        -0x12C34
	  addi      r3, r30, 0xE0
	  bl        -0x14E28
	  li        r3, 0
	  stw       r3, 0x0(r30)
	  li        r0, -0x3
	  stw       r0, 0x4(r30)
	  stw       r3, 0x24(r30)

	.loc_0x84:
	  mr        r3, r31
	  bl        -0x122D4
	  li        r3, 0

	.loc_0x90:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}
