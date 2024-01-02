#include "types.h"

/*
 * --INFO--
 * Address:	80008BE0
 * Size:	000038
 */
void exnor_1st(u32, u32)
{
	/*
	.loc_0x0:
	  mtctr     r4
	  cmplwi    r4, 0
	  blelr-

	.loc_0xC:
	  rlwinm    r0,r3,25,7,31
	  rlwinm    r4,r3,17,15,31
	  xor       r0, r3, r0
	  rlwinm    r5,r3,9,23,31
	  xor       r0, r4, r0
	  rlwinm    r3,r3,31,1,31
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,30,1,1
	  or        r3, r3, r0
	  bdnz+     .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008C20
 * Size:	000038
 */
void exnor(u32, u32)
{
	/*
	.loc_0x0:
	  mtctr     r4
	  cmplwi    r4, 0
	  blelr-

	.loc_0xC:
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r5,r3,23,0,8
	  xor       r0, r4, r0
	  rlwinm    r3,r3,1,0,30
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,2,30,30
	  or        r3, r3, r0
	  bdnz+     .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008C60
 * Size:	00007C
 */
void bitrev(u32)
{
	/*
	.loc_0x0:
	  li        r0, 0x20
	  rlwinm    r6,r3,1,31,31
	  li        r9, 0
	  li        r10, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r5, 0x1
	  mtctr     r0

	.loc_0x20:
	  cmplwi    r8, 0xF
	  ble-      .loc_0x50
	  cmplwi    r8, 0x1F
	  bne-      .loc_0x38
	  or        r7, r7, r6
	  b         .loc_0x6C

	.loc_0x38:
	  slw       r0, r5, r8
	  and       r0, r3, r0
	  srw       r0, r0, r10
	  addi      r10, r10, 0x2
	  or        r7, r7, r0
	  b         .loc_0x6C

	.loc_0x50:
	  slw       r4, r5, r8
	  subfic    r0, r8, 0x1F
	  sub       r0, r0, r9
	  and       r4, r3, r4
	  slw       r0, r4, r0
	  addi      r9, r9, 0x1
	  or        r7, r7, r0

	.loc_0x6C:
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x20
	  mr        r3, r7
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008CE0
 * Size:	00017C
 */
void ReadArrayUnlock(s32, u32, void*, s32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x40(r1)
	  stmw      r26, 0x28(r1)
	  mr.       r28, r3
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r31, r6, 0
	  addi      r26, r7, 0
	  blt-      .loc_0x38
	  cmpwi     r28, 0x2
	  bge-      .loc_0x38
	  li        r0, 0x1

	.loc_0x38:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x5C
	  lis       r3, 0x8022
	  lis       r4, 0x8022
	  addi      r5, r4, 0x20DC
	  addi      r3, r3, 0x20C8
	  li        r4, 0xD8
	  crclr     6, 0x6
	  bl        0x1EEBD8

	.loc_0x5C:
	  mulli     r4, r28, 0x108
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3420
	  addi      r3, r28, 0
	  add       r27, r0, r4
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x1EF984
	  cmpwi     r3, 0
	  bne-      .loc_0x8C
	  li        r3, -0x3
	  b         .loc_0x168

	.loc_0x8C:
	  rlwinm    r29,r29,0,0,19
	  addi      r3, r1, 0x20
	  li        r4, 0
	  li        r5, 0x5
	  bl        -0x5A5C
	  li        r0, 0x52
	  cmpwi     r26, 0
	  stb       r0, 0x20(r1)
	  bne-      .loc_0xD4
	  rlwinm    r0,r29,3,30,31
	  rlwinm    r4,r29,11,24,31
	  stb       r0, 0x21(r1)
	  rlwinm    r3,r29,13,30,31
	  rlwinm    r0,r29,20,25,31
	  stb       r4, 0x22(r1)
	  stb       r3, 0x23(r1)
	  stb       r0, 0x24(r1)
	  b         .loc_0xE4

	.loc_0xD4:
	  rlwinm    r3,r29,8,24,31
	  rlwinm    r0,r29,16,24,31
	  stb       r3, 0x21(r1)
	  stb       r0, 0x22(r1)

	.loc_0xE4:
	  addi      r3, r28, 0
	  addi      r4, r1, 0x20
	  li        r5, 0x5
	  li        r6, 0x1
	  bl        0x1EF148
	  lwz       r4, 0x80(r27)
	  cntlzw    r0, r3
	  lwz       r5, 0x14(r27)
	  addi      r3, r28, 0
	  rlwinm    r29,r0,27,24,31
	  addi      r4, r4, 0x200
	  li        r6, 0x1
	  bl        0x1EF128
	  cntlzw    r0, r3
	  addi      r3, r28, 0
	  rlwinm    r0,r0,27,24,31
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  or        r27, r29, r0
	  li        r6, 0
	  bl        0x1EF108
	  cntlzw    r0, r3
	  addi      r3, r28, 0
	  rlwinm    r0,r0,27,24,31
	  or        r27, r27, r0
	  bl        0x1EF9E0
	  cntlzw    r0, r3
	  rlwinm    r0,r0,27,24,31
	  or.       r27, r27, r0
	  beq-      .loc_0x164
	  li        r3, -0x3
	  b         .loc_0x168

	.loc_0x164:
	  li        r3, 0

	.loc_0x168:
	  lmw       r26, 0x28(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008E60
 * Size:	000044
 */
void GetInitVal()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        0x1F4548
	  bl        0x20F1F4
	  lis       r3, 0x7FED
	  subi      r31, r3, 0x8000
	  bl        0x20F1F0
	  or        r31, r31, r3
	  rlwinm    r31,r31,0,0,19
	  addi      r3, r31, 0
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008EC0
 * Size:	00008C
 */
void DummyLen()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stmw      r30, 0x8(r1)
	  li        r31, 0x1
	  li        r30, 0
	  bl        0x1F44E0
	  bl        0x20F18C
	  bl        0x20F190
	  rlwinm    r3,r3,0,27,31
	  addi      r3, r3, 0x1
	  b         .loc_0x5C

	.loc_0x30:
	  bl        0x1F44C8
	  slw       r3, r3, r31
	  addi      r31, r31, 0x1
	  cmplwi    r31, 0x10
	  ble-      .loc_0x48
	  li        r31, 0x1

	.loc_0x48:
	  bl        0x20F160
	  bl        0x20F164
	  rlwinm    r3,r3,0,27,31
	  addi      r30, r30, 0x1
	  addi      r3, r3, 0x1

	.loc_0x5C:
	  cmpwi     r3, 0x4
	  bge-      .loc_0x6C
	  cmplwi    r30, 0xA
	  blt+      .loc_0x30

	.loc_0x6C:
	  cmpwi     r3, 0x4
	  bge-      .loc_0x78
	  li        r3, 0x4

	.loc_0x78:
	  lwz       r0, 0x14(r1)
	  lmw       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008F60
 * Size:	0002B0
 */
void __CARDUnlock(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stmw      r20, 0x58(r1)
	  addi      r20, r3, 0
	  lis       r3, 0x803D
	  addi      r27, r4, 0
	  mulli     r5, r20, 0x108
	  addi      r0, r3, 0x3420
	  add       r31, r0, r5
	  addi      r30, r31, 0x30
	  lwz       r3, 0x80(r31)
	  addi      r0, r3, 0x2F
	  addi      r29, r3, 0
	  rlwinm    r25,r0,0,0,26
	  addi      r28, r25, 0x20
	  bl        -0x140
	  mr        r21, r3
	  bl        -0xE8
	  addi      r0, r3, 0
	  addi      r3, r20, 0
	  mr        r22, r0
	  addi      r4, r21, 0
	  addi      r6, r22, 0
	  addi      r5, r1, 0x10
	  li        r7, 0
	  bl        -0x2E8
	  cmpwi     r3, 0
	  bge-      .loc_0x7C
	  li        r3, -0x3
	  b         .loc_0x29C

	.loc_0x7C:
	  rlwinm    r4,r22,3,0,28
	  addi      r3, r21, 0
	  addi      r4, r4, 0x1
	  bl        -0x408
	  rlwinm    r0,r3,25,7,31
	  rlwinm    r4,r3,17,15,31
	  xor       r0, r3, r0
	  rlwinm    r5,r3,9,23,31
	  xor       r0, r4, r0
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,31,0,0
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x28(r31)
	  bl        -0x3B4
	  stw       r3, 0x28(r31)
	  bl        -0x15C
	  addi      r26, r3, 0
	  addi      r3, r20, 0
	  addi      r6, r26, 0x14
	  addi      r5, r1, 0x10
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x358
	  cmpwi     r3, 0
	  bge-      .loc_0xEC
	  li        r3, -0x3
	  b         .loc_0x29C

	.loc_0xEC:
	  lwz       r3, 0x28(r31)
	  li        r4, 0x20
	  lwz       r23, 0x10(r1)
	  lwz       r22, 0x14(r1)
	  lwz       r24, 0x18(r1)
	  xor       r23, r23, r3
	  lwz       r21, 0x1C(r1)
	  lwz       r20, 0x20(r1)
	  bl        -0x44C
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r5,r3,23,0,8
	  xor       r0, r4, r0
	  li        r4, 0x20
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,1,31,31
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x28(r31)
	  xor       r22, r22, r3
	  bl        -0x480
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r5,r3,23,0,8
	  xor       r0, r4, r0
	  li        r4, 0x20
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,1,31,31
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x28(r31)
	  xor       r24, r24, r3
	  bl        -0x4B4
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r5,r3,23,0,8
	  xor       r0, r4, r0
	  li        r4, 0x20
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,1,31,31
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x28(r31)
	  xor       r21, r21, r3
	  bl        -0x4E8
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r5,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r6,r3,23,0,8
	  xor       r0, r5, r0
	  rlwinm    r4,r26,3,0,28
	  eqv       r0, r6, r0
	  rlwinm    r0,r0,1,31,31
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x28(r31)
	  xor       r20, r20, r3
	  bl        -0x51C
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r5,r3,23,0,8
	  xor       r0, r4, r0
	  li        r4, 0x21
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,1,31,31
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x28(r31)
	  bl        -0x54C
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r6,r3,23,0,8
	  xor       r0, r4, r0
	  li        r5, 0x8
	  eqv       r4, r6, r0
	  li        r0, 0
	  rlwinm    r6,r4,1,31,31
	  li        r4, 0x8
	  or        r6, r3, r6
	  addi      r3, r25, 0
	  stw       r6, 0x28(r31)
	  stw       r21, 0x0(r25)
	  stw       r20, 0x4(r25)
	  stw       r25, 0x0(r29)
	  stw       r5, 0x4(r29)
	  stw       r28, 0xC(r29)
	  stw       r0, 0x8(r29)
	  bl        0x1EDA2C
	  addi      r3, r28, 0
	  li        r4, 0x4
	  bl        0x1ED9F0
	  addi      r3, r29, 0
	  li        r4, 0x10
	  bl        0x1EDA14
	  lis       r4, 0x8001
	  addi      r3, r30, 0
	  subi      r5, r4, 0x6DE0
	  addi      r4, r29, 0
	  bl        -0x668
	  stw       r23, 0x0(r27)
	  li        r3, 0
	  stw       r22, 0x4(r27)
	  stw       r24, 0x8(r27)

	.loc_0x29C:
	  lmw       r20, 0x58(r1)
	  lwz       r0, 0x8C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void InitCallback(void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80009220
 * Size:	0001E0
 */
void DoneCallback(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0x3420
	  li        r0, 0x2
	  li        r4, 0
	  stwu      r1, -0x70(r1)
	  stmw      r28, 0x60(r1)
	  li        r29, 0
	  mtctr     r0

	.loc_0x28:
	  add       r31, r5, r4
	  addi      r0, r31, 0x30
	  cmplw     r0, r3
	  beq-      .loc_0x44
	  addi      r29, r29, 0x1
	  addi      r4, r4, 0x108
	  bdnz+     .loc_0x28

	.loc_0x44:
	  cmpwi     r29, 0
	  li        r0, 0x1
	  li        r3, 0
	  blt-      .loc_0x60
	  cmpwi     r29, 0x2
	  bge-      .loc_0x60
	  mr        r3, r0

	.loc_0x60:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x84
	  lis       r3, 0x8022
	  lis       r4, 0x8022
	  addi      r5, r4, 0x20DC
	  addi      r3, r3, 0x20C8
	  li        r4, 0x224
	  crclr     6, 0x6
	  bl        0x1EE670

	.loc_0x84:
	  lwz       r3, 0x80(r31)
	  addi      r0, r3, 0x2F
	  rlwinm    r3,r0,0,0,26
	  lwz       r30, 0x20(r3)
	  bl        -0x3F4
	  lwz       r0, 0x28(r31)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  addi      r6, r28, 0
	  xor       r0, r30, r0
	  addi      r5, r1, 0x20
	  rlwinm    r4,r0,0,0,15
	  li        r7, 0x1
	  bl        -0x5F8
	  cmpwi     r3, 0
	  bge-      .loc_0xDC
	  mr        r3, r29
	  bl        0x1EFB48
	  addi      r3, r29, 0
	  li        r4, -0x3
	  bl        0x201B88
	  b         .loc_0x1CC

	.loc_0xDC:
	  lwz       r0, 0x14(r31)
	  lwz       r3, 0x28(r31)
	  add       r4, r28, r0
	  addi      r0, r4, 0x4
	  rlwinm    r4,r0,3,0,28
	  addi      r4, r4, 0x1
	  bl        -0x6F4
	  rlwinm    r0,r3,7,0,24
	  rlwinm    r4,r3,15,0,16
	  xor       r0, r3, r0
	  rlwinm    r5,r3,23,0,8
	  xor       r0, r4, r0
	  eqv       r0, r5, r0
	  rlwinm    r0,r0,1,31,31
	  or        r0, r3, r0
	  stw       r0, 0x28(r31)
	  bl        -0x47C
	  lwz       r0, 0x28(r31)
	  rlwinm    r4,r30,16,0,15
	  addi      r6, r3, 0
	  addi      r3, r29, 0
	  xor       r0, r4, r0
	  addi      r5, r1, 0x20
	  rlwinm    r4,r0,0,0,15
	  li        r7, 0x1
	  bl        -0x680
	  cmpwi     r3, 0
	  bge-      .loc_0x164
	  mr        r3, r29
	  bl        0x1EFAC0
	  addi      r3, r29, 0
	  li        r4, -0x3
	  bl        0x201B00
	  b         .loc_0x1CC

	.loc_0x164:
	  addi      r3, r29, 0
	  addi      r4, r1, 0x1C
	  bl        0x1FEFE8
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  mr        r28, r0
	  bl        0x1EEFD8
	  cmpwi     r3, 0
	  bne-      .loc_0x1A0
	  mr        r3, r29
	  bl        0x1EFA84
	  addi      r3, r29, 0
	  li        r4, -0x3
	  bl        0x201AC4
	  b         .loc_0x1CC

	.loc_0x1A0:
	  cmpwi     r28, 0
	  bne-      .loc_0x1C0
	  lbz       r0, 0x1C(r1)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x1C0
	  mr        r3, r29
	  bl        0x1EFA58
	  li        r28, -0x5

	.loc_0x1C0:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        0x201A94

	.loc_0x1CC:
	  lmw       r28, 0x60(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}
