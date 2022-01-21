#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80197F28
 * Size:	0000C4
 */
zen::ogGraphMgr::ogGraphMgr(P2DScreen*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x0(r4)
	  lis       r4, 0x675F
	  addi      r4, r4, 0x7370
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x803D
	  stw       r3, 0x0(r31)
	  lis       r3, 0x803D
	  addi      r4, r4, 0x1EA0
	  addi      r3, r3, 0x1E70
	  lwz       r4, 0x4(r4)
	  lwz       r0, 0x4(r3)
	  add       r0, r4, r0
	  stw       r0, 0xC(r31)
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  bne-      .loc_0x78
	  li        r0, 0x1
	  stb       r0, 0x10(r31)
	  stb       r0, 0x11(r31)
	  stb       r0, 0x12(r31)
	  b         .loc_0xA4

	.loc_0x78:
	  li        r4, 0
	  bl        -0x1179D8
	  stb       r3, 0x10(r31)
	  li        r4, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x1179E8
	  stb       r3, 0x11(r31)
	  li        r4, 0x2
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x1179F8
	  stb       r3, 0x12(r31)

	.loc_0xA4:
	  mr        r3, r31
	  bl        0x320
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80197FEC
 * Size:	000304
 */
void zen::ogGraphMgr::SetDummyLineData()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x58(r1)
	  lis       r4, 0x802D
	  addi      r4, r4, 0x6120
	  stw       r31, 0x54(r1)
	  li        r0, 0x4
	  mtctr     r0
	  addi      r5, r4, 0x20
	  stw       r30, 0x50(r1)
	  addi      r6, r4, 0x60
	  addi      r7, r4, 0xA0

	.loc_0x28:
	  li        r0, 0
	  sth       r0, 0x0(r5)
	  sth       r0, 0x0(r6)
	  sth       r0, 0x0(r7)
	  sth       r0, 0x2(r5)
	  sth       r0, 0x2(r6)
	  sth       r0, 0x2(r7)
	  sth       r0, 0x4(r5)
	  sth       r0, 0x4(r6)
	  sth       r0, 0x4(r7)
	  sth       r0, 0x6(r5)
	  sth       r0, 0x6(r6)
	  sth       r0, 0x6(r7)
	  sth       r0, 0x8(r5)
	  sth       r0, 0x8(r6)
	  sth       r0, 0x8(r7)
	  sth       r0, 0xA(r5)
	  sth       r0, 0xA(r6)
	  sth       r0, 0xA(r7)
	  sth       r0, 0xC(r5)
	  sth       r0, 0xC(r6)
	  sth       r0, 0xC(r7)
	  sth       r0, 0xE(r5)
	  addi      r5, r5, 0x10
	  sth       r0, 0xE(r6)
	  addi      r6, r6, 0x10
	  sth       r0, 0xE(r7)
	  addi      r7, r7, 0x10
	  bdnz+     .loc_0x28
	  lwz       r7, 0x0(r3)
	  lis       r3, 0x2AAB
	  subi      r6, r3, 0x5555
	  lha       r5, 0x18(r7)
	  lis       r10, 0x51EC
	  lha       r0, 0x1C(r7)
	  addi      r9, r4, 0x60
	  lha       r11, 0x1A(r7)
	  sub       r3, r0, r5
	  lha       r0, 0x1E(r7)
	  mulhw     r3, r6, r3
	  lha       r6, 0x18(r7)
	  srawi     r3, r3, 0x1
	  rlwinm    r5,r3,1,31,31
	  add       r3, r3, r5
	  sub       r0, r0, r11
	  extsh     r7, r3
	  extsh     r8, r0
	  addi      r3, r4, 0xE0
	  extsh     r5, r11
	  subi      r0, r10, 0x7AE1
	  lha       r11, 0x0(r3)
	  li        r10, 0x1
	  mullw     r12, r10, r7
	  sth       r6, 0x0(r9)
	  subfic    r10, r11, 0x64
	  mullw     r10, r10, r8
	  mulhw     r10, r0, r10
	  srawi     r10, r10, 0x5
	  rlwinm    r11,r10,1,31,31
	  add       r10, r10, r11
	  add       r10, r5, r10
	  sth       r10, 0x2(r9)
	  li        r10, 0x2
	  mullw     r11, r10, r7
	  lha       r10, 0x2(r3)
	  subfic    r10, r10, 0x64
	  mullw     r10, r10, r8
	  mulhw     r10, r0, r10
	  srawi     r30, r10, 0x5
	  rlwinm    r31,r30,1,31,31
	  add       r10, r6, r12
	  add       r12, r30, r31
	  sth       r10, 0x4(r9)
	  add       r10, r5, r12
	  sth       r10, 0x6(r9)
	  li        r10, 0x3
	  mullw     r12, r10, r7
	  lha       r10, 0x4(r3)
	  subfic    r10, r10, 0x64
	  mullw     r10, r10, r8
	  mulhw     r10, r0, r10
	  srawi     r30, r10, 0x5
	  rlwinm    r31,r30,1,31,31
	  add       r10, r6, r11
	  add       r11, r30, r31
	  sth       r10, 0x8(r9)
	  add       r10, r5, r11
	  sth       r10, 0xA(r9)
	  li        r10, 0x4
	  mullw     r11, r10, r7
	  lha       r10, 0x6(r3)
	  subfic    r10, r10, 0x64
	  mullw     r10, r10, r8
	  mulhw     r10, r0, r10
	  srawi     r31, r10, 0x5
	  rlwinm    r30,r31,1,31,31
	  add       r10, r6, r12
	  add       r12, r31, r30
	  sth       r10, 0xC(r9)
	  add       r10, r5, r12
	  sth       r10, 0xE(r9)
	  li        r10, 0x5
	  mullw     r10, r10, r7
	  lha       r12, 0x8(r3)
	  subfic    r12, r12, 0x64
	  mullw     r12, r12, r8
	  mulhw     r12, r0, r12
	  srawi     r12, r12, 0x5
	  rlwinm    r31,r12,1,31,31
	  add       r11, r6, r11
	  add       r12, r12, r31
	  sth       r11, 0x10(r9)
	  add       r11, r5, r12
	  sth       r11, 0x12(r9)
	  add       r11, r6, r10
	  li        r10, 0x6
	  lha       r12, 0xA(r3)
	  mullw     r10, r10, r7
	  sth       r11, 0x14(r9)
	  subfic    r11, r12, 0x64
	  mullw     r11, r11, r8
	  mulhw     r11, r0, r11
	  srawi     r11, r11, 0x5
	  rlwinm    r12,r11,1,31,31
	  add       r11, r11, r12
	  add       r11, r5, r11
	  sth       r11, 0x16(r9)
	  add       r10, r6, r10
	  lha       r11, 0xC(r3)
	  subfic    r11, r11, 0x64
	  sth       r10, 0x18(r9)
	  mullw     r10, r11, r8
	  mulhw     r10, r0, r10
	  srawi     r10, r10, 0x5
	  rlwinm    r11,r10,1,31,31
	  add       r10, r10, r11
	  add       r10, r5, r10
	  sth       r10, 0x1A(r9)
	  li        r10, 0x7
	  mullw     r10, r10, r7
	  lha       r3, 0xE(r3)
	  subfic    r3, r3, 0x64
	  mullw     r3, r3, r8
	  mulhw     r3, r0, r3
	  srawi     r11, r3, 0x5
	  add       r3, r6, r10
	  rlwinm    r12,r11,1,31,31
	  sth       r3, 0x1C(r9)
	  add       r10, r11, r12
	  add       r3, r5, r10
	  sth       r3, 0x1E(r9)
	  li        r12, 0x8
	  addi      r9, r9, 0x20
	  b         .loc_0x2E0

	.loc_0x290:
	  subfic    r3, r12, 0xE
	  cmpwi     r12, 0xD
	  mtctr     r3
	  bgt-      .loc_0x2F4

	.loc_0x2A0:
	  lha       r4, 0x0(r10)
	  add       r3, r6, r11
	  add       r11, r11, r7
	  subfic    r4, r4, 0x64
	  sth       r3, 0x0(r9)
	  mullw     r3, r4, r8
	  mulhw     r3, r0, r3
	  srawi     r3, r3, 0x5
	  rlwinm    r4,r3,1,31,31
	  add       r3, r3, r4
	  add       r3, r5, r3
	  sth       r3, 0x2(r9)
	  addi      r10, r10, 0x2
	  addi      r9, r9, 0x4
	  bdnz+     .loc_0x2A0
	  b         .loc_0x2F4

	.loc_0x2E0:
	  mullw     r11, r12, r7
	  rlwinm    r3,r12,1,0,30
	  add       r10, r4, r3
	  addi      r10, r10, 0xE0
	  b         .loc_0x290

	.loc_0x2F4:
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801982F0
 * Size:	000320
 */
void zen::ogGraphMgr::MakeData()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stmw      r18, 0x48(r1)
	  addi      r31, r3, 0
	  addi      r28, r4, 0x6120
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x44
	  mr        r3, r31
	  bl        -0x330
	  lwz       r3, 0xC(r31)
	  li        r0, 0
	  stw       r3, 0x4(r31)
	  stw       r0, 0x8(r31)
	  b         .loc_0x30C

	.loc_0x44:
	  mr        r3, r0
	  bl        -0x117EC4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  mr        r3, r31
	  bl        -0x35C
	  lwz       r3, 0xC(r31)
	  li        r0, 0
	  stw       r3, 0x4(r31)
	  stw       r0, 0x8(r31)
	  b         .loc_0x30C

	.loc_0x70:
	  lwz       r3, 0x2F6C(r13)
	  li        r18, 0
	  li        r21, 0x2710
	  bl        -0x1177A0
	  mr        r0, r3
	  lwz       r3, 0x2F6C(r13)
	  mr        r20, r0
	  bl        -0x117788
	  addi      r29, r3, 0
	  li        r23, 0

	.loc_0x98:
	  addi      r0, r23, 0x10
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  mr        r19, r20
	  b         .loc_0xE4

	.loc_0xB0:
	  lwz       r3, 0x2F6C(r13)
	  addi      r4, r19, 0
	  addi      r5, r23, 0
	  bl        -0x117790
	  cmpwi     r3, 0
	  blt-      .loc_0xE0
	  cmpw      r3, r18
	  ble-      .loc_0xD4
	  mr        r18, r3

	.loc_0xD4:
	  cmpw      r3, r21
	  bge-      .loc_0xE0
	  mr        r21, r3

	.loc_0xE0:
	  addi      r19, r19, 0x1

	.loc_0xE4:
	  cmpw      r19, r29
	  ble+      .loc_0xB0

	.loc_0xEC:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x3
	  blt+      .loc_0x98
	  extsh     r0, r18
	  stw       r0, 0x4(r31)
	  extsh     r0, r21
	  lis       r3, 0x2AAB
	  stw       r0, 0x8(r31)
	  sub       r26, r18, r21
	  subi      r4, r3, 0x5555
	  lwz       r5, 0x0(r31)
	  cmpwi     r26, 0x64
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r25, 0x1A(r5)
	  sub       r3, r0, r3
	  lha       r0, 0x1E(r5)
	  mulhw     r3, r4, r3
	  lha       r27, 0x18(r5)
	  srawi     r3, r3, 0x1
	  rlwinm    r4,r3,1,31,31
	  add       r19, r3, r4
	  sub       r18, r0, r25
	  blt-      .loc_0x228
	  lis       r3, 0x51EC
	  subi      r30, r3, 0x7AE1
	  li        r24, 0

	.loc_0x158:
	  addi      r0, r24, 0x10
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x218
	  cmpwi     r24, 0x1
	  beq-      .loc_0x194
	  bge-      .loc_0x180
	  cmpwi     r24, 0
	  bge-      .loc_0x18C
	  b         .loc_0x1A0

	.loc_0x180:
	  cmpwi     r24, 0x3
	  bge-      .loc_0x1A0
	  b         .loc_0x19C

	.loc_0x18C:
	  addi      r22, r28, 0x20
	  b         .loc_0x1A0

	.loc_0x194:
	  addi      r22, r28, 0x60
	  b         .loc_0x1A0

	.loc_0x19C:
	  addi      r22, r28, 0xA0

	.loc_0x1A0:
	  mr        r23, r20
	  b         .loc_0x210

	.loc_0x1A8:
	  lwz       r3, 0x2F6C(r13)
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  bl        -0x117888
	  cmpwi     r3, 0
	  li        r0, -0xA
	  blt-      .loc_0x1D4
	  sub       r0, r3, r21
	  mulli     r0, r0, 0x64
	  divw      r0, r0, r26
	  extsh     r0, r0

	.loc_0x1D4:
	  extsh     r0, r0
	  subfic    r0, r0, 0x64
	  mullw     r0, r0, r18
	  subi      r3, r23, 0x7
	  mulhw     r0, r30, r0
	  mullw     r3, r3, r19
	  srawi     r0, r0, 0x5
	  add       r4, r27, r3
	  rlwinm    r3,r0,1,31,31
	  sth       r4, 0x0(r22)
	  add       r0, r0, r3
	  add       r0, r25, r0
	  sth       r0, 0x2(r22)
	  addi      r22, r22, 0x4
	  addi      r23, r23, 0x1

	.loc_0x210:
	  cmpw      r23, r29
	  ble+      .loc_0x1A8

	.loc_0x218:
	  addi      r24, r24, 0x1
	  cmpwi     r24, 0x3
	  blt+      .loc_0x158
	  b         .loc_0x30C

	.loc_0x228:
	  lis       r3, 0x51EC
	  subi      r30, r3, 0x7AE1
	  li        r26, 0

	.loc_0x234:
	  addi      r0, r26, 0x10
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x300
	  cmpwi     r26, 0x1
	  beq-      .loc_0x270
	  bge-      .loc_0x25C
	  cmpwi     r26, 0
	  bge-      .loc_0x268
	  b         .loc_0x27C

	.loc_0x25C:
	  cmpwi     r26, 0x3
	  bge-      .loc_0x27C
	  b         .loc_0x278

	.loc_0x268:
	  addi      r22, r28, 0x20
	  b         .loc_0x27C

	.loc_0x270:
	  addi      r22, r28, 0x60
	  b         .loc_0x27C

	.loc_0x278:
	  addi      r22, r28, 0xA0

	.loc_0x27C:
	  mr        r24, r20
	  b         .loc_0x2F8

	.loc_0x284:
	  lwz       r3, 0x2F6C(r13)
	  addi      r4, r24, 0
	  addi      r5, r26, 0
	  bl        -0x117964
	  cmpwi     r3, 0
	  li        r0, -0xA
	  blt-      .loc_0x2BC
	  sub       r0, r3, r21
	  mulli     r0, r0, 0x64
	  mulhw     r0, r30, r0
	  srawi     r0, r0, 0x5
	  rlwinm    r3,r0,1,31,31
	  add       r0, r0, r3
	  extsh     r0, r0

	.loc_0x2BC:
	  extsh     r0, r0
	  subfic    r0, r0, 0x64
	  mullw     r0, r0, r18
	  subi      r3, r24, 0x7
	  mulhw     r0, r30, r0
	  mullw     r3, r3, r19
	  srawi     r0, r0, 0x5
	  add       r4, r27, r3
	  rlwinm    r3,r0,1,31,31
	  sth       r4, 0x0(r22)
	  add       r0, r0, r3
	  add       r0, r25, r0
	  sth       r0, 0x2(r22)
	  addi      r22, r22, 0x4
	  addi      r24, r24, 0x1

	.loc_0x2F8:
	  cmpw      r24, r29
	  ble+      .loc_0x284

	.loc_0x300:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  blt+      .loc_0x234

	.loc_0x30C:
	  lmw       r18, 0x48(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80198610
 * Size:	00029C
 */
void zen::setGraphGX(void*, int, unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r26, r4
	  lis       r4, 0x802D
	  rlwinm    r6,r26,2,0,29
	  addi      r0, r4, 0x6220
	  add       r4, r0, r6
	  rlwinm    r0,r5,0,24,31
	  addi      r29, r3, 0
	  lwz       r7, 0x2F6C(r13)
	  lwz       r31, 0x0(r4)
	  cmplwi    r7, 0
	  rlwinm    r31,r31,0,0,23
	  or        r31, r31, r0
	  bne-      .loc_0x50
	  li        r28, 0x7
	  li        r3, 0x13
	  b         .loc_0x68

	.loc_0x50:
	  mr        r3, r7
	  bl        -0x117A98
	  mr        r0, r3
	  lwz       r3, 0x2F6C(r13)
	  mr        r28, r0
	  bl        -0x117A80

	.loc_0x68:
	  lwz       r0, 0x2F6C(r13)
	  sub       r3, r3, r28
	  addi      r30, r3, 0x1
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  mr        r3, r0
	  bl        -0x11821C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94

	.loc_0x8C:
	  li        r30, 0xD
	  b         .loc_0xC8

	.loc_0x94:
	  li        r27, 0
	  b         .loc_0xC0

	.loc_0x9C:
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r26, 0
	  add       r4, r28, r27
	  bl        -0x117A9C
	  cmpwi     r3, 0
	  bge-      .loc_0xBC
	  mr        r30, r27
	  b         .loc_0xC8

	.loc_0xBC:
	  addi      r27, r27, 0x1

	.loc_0xC0:
	  cmpw      r27, r30
	  blt+      .loc_0x9C

	.loc_0xC8:
	  cmpwi     r30, 0x2
	  blt-      .loc_0x288
	  bl        0x7751C
	  li        r3, 0x1
	  bl        0x7B6A8
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x76D0C
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x76D00
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x77530
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x77518
	  addi      r4, r29, 0
	  li        r3, 0x9
	  li        r5, 0x4
	  bl        0x77C7C
	  lis       r3, 0x802D
	  addi      r4, r3, 0x6220
	  li        r3, 0xB
	  li        r5, 0x4
	  bl        0x77C68
	  li        r3, 0x12
	  li        r4, 0
	  bl        0x785D8
	  rlwinm    r5,r30,0,16,31
	  li        r3, 0xB0
	  li        r4, 0
	  bl        0x78464
	  cmpwi     r30, 0
	  li        r5, 0
	  ble-      .loc_0x288
	  cmpwi     r30, 0x8
	  subi      r3, r30, 0x8
	  ble-      .loc_0x27C
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  addi      r4, r29, 0
	  lis       r3, 0xCC01
	  ble-      .loc_0x27C

	.loc_0x198:
	  lha       r6, 0x2(r4)
	  addi      r5, r5, 0x8
	  lha       r0, 0x0(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0x6(r4)
	  lha       r0, 0x4(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0xA(r4)
	  lha       r0, 0x8(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0xE(r4)
	  lha       r0, 0xC(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0x12(r4)
	  lha       r0, 0x10(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0x16(r4)
	  lha       r0, 0x14(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0x1A(r4)
	  lha       r0, 0x18(r4)
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lha       r6, 0x1E(r4)
	  lha       r0, 0x1C(r4)
	  addi      r4, r4, 0x20
	  sth       r0, -0x8000(r3)
	  sth       r6, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  bdnz+     .loc_0x198
	  b         .loc_0x27C

	.loc_0x248:
	  sub       r0, r30, r5
	  cmpw      r5, r30
	  mtctr     r0
	  lis       r3, 0xCC01
	  bge-      .loc_0x288

	.loc_0x25C:
	  lha       r5, 0x2(r4)
	  lha       r0, 0x0(r4)
	  addi      r4, r4, 0x4
	  sth       r0, -0x8000(r3)
	  sth       r5, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  bdnz+     .loc_0x25C
	  b         .loc_0x288

	.loc_0x27C:
	  rlwinm    r0,r5,2,0,29
	  add       r4, r29, r0
	  b         .loc_0x248

	.loc_0x288:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801988AC
 * Size:	0000DC
 */
void zen::ogGraphMgr::draw(unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802D
	  stw       r0, 0x4(r1)
	  li        r6, 0x280
	  li        r7, 0x1E0
	  stwu      r1, -0x108(r1)
	  stw       r31, 0x104(r1)
	  addi      r31, r5, 0x6120
	  li        r5, 0
	  stw       r30, 0x100(r1)
	  mr        r30, r4
	  li        r4, 0
	  stw       r29, 0xFC(r1)
	  mr        r29, r3
	  addi      r3, r1, 0x10
	  lfs       f1, -0x4D20(r2)
	  lfs       f2, -0x4D1C(r2)
	  lfs       f3, -0x4D18(r2)
	  bl        0x1789C
	  addi      r3, r1, 0x10
	  bl        0x179A4
	  lbz       r0, 0x10(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  addi      r5, r30, 0
	  addi      r3, r31, 0x20
	  li        r4, 0
	  bl        -0x308

	.loc_0x70:
	  lbz       r0, 0x11(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  addi      r5, r30, 0
	  addi      r3, r31, 0x60
	  li        r4, 0x1
	  bl        -0x324

	.loc_0x8C:
	  lbz       r0, 0x12(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  addi      r5, r30, 0
	  addi      r3, r31, 0xA0
	  li        r4, 0x2
	  bl        -0x340

	.loc_0xA8:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)
	  lwz       r0, 0x10C(r1)
	  lwz       r31, 0x104(r1)
	  lwz       r30, 0x100(r1)
	  lwz       r29, 0xFC(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}
