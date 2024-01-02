#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void CompleteTransfer(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802207EC
 * Size:	000244
 */
void AmcEXIImm(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r21, 0x24(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r22, r6, 0
	  li        r21, 0x2
	  bl        -0x27894
	  lwz       r4, 0x2AE8(r13)
	  addi      r31, r3, 0
	  lwz       r0, 0xC(r4)
	  addi      r3, r4, 0xC
	  rlwinm.   r0,r0,0,30,31
	  bne-      .loc_0x4C
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x5C

	.loc_0x4C:
	  mr        r3, r31
	  bl        -0x27898
	  li        r3, 0
	  b         .loc_0x230

	.loc_0x5C:
	  stw       r22, 0x4(r4)
	  lwz       r3, 0x2AE8(r13)
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  li        r3, 0
	  li        r4, 0x1
	  bl        0x364
	  mulli     r0, r21, 0x3
	  lis       r3, 0x20
	  srw       r3, r3, r0
	  bl        -0x274D0

	.loc_0x8C:
	  lwz       r3, 0x2AE8(r13)
	  cmplwi    r30, 0
	  lwz       r0, 0xC(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC(r3)
	  beq-      .loc_0x1D8
	  li        r12, 0
	  cmpw      r12, r29
	  li        r11, 0
	  bge-      .loc_0x1D0
	  cmpwi     r29, 0x8
	  subi      r3, r29, 0x8
	  ble-      .loc_0x228
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  addi      r10, r28, 0
	  ble-      .loc_0x228

	.loc_0xD8:
	  subfic    r3, r12, 0x3
	  lbz       r9, 0x0(r10)
	  addi      r0, r12, 0x1
	  lbz       r8, 0x1(r10)
	  rlwinm    r7,r3,3,0,28
	  lbz       r6, 0x2(r10)
	  subfic    r5, r0, 0x3
	  lbz       r4, 0x3(r10)
	  addi      r3, r12, 0x2
	  lbz       r0, 0x4(r10)
	  slw       r9, r9, r7
	  lbz       r22, 0x5(r10)
	  rlwinm    r7,r5,3,0,28
	  lbz       r24, 0x6(r10)
	  subfic    r3, r3, 0x3
	  lbz       r26, 0x7(r10)
	  rlwinm    r5,r3,3,0,28
	  neg       r3, r12
	  addi      r21, r12, 0x4
	  rlwinm    r3,r3,3,0,28
	  subfic    r21, r21, 0x3
	  addi      r23, r12, 0x5
	  rlwinm    r21,r21,3,0,28
	  subfic    r23, r23, 0x3
	  addi      r25, r12, 0x6
	  rlwinm    r23,r23,3,0,28
	  subfic    r25, r25, 0x3
	  addi      r27, r12, 0x7
	  rlwinm    r25,r25,3,0,28
	  subfic    r27, r27, 0x3
	  rlwinm    r27,r27,3,0,28
	  or        r11, r11, r9
	  slw       r7, r8, r7
	  or        r11, r11, r7
	  slw       r5, r6, r5
	  or        r11, r11, r5
	  slw       r3, r4, r3
	  or        r11, r11, r3
	  slw       r0, r0, r21
	  or        r11, r11, r0
	  slw       r0, r22, r23
	  or        r11, r11, r0
	  slw       r0, r24, r25
	  or        r11, r11, r0
	  slw       r0, r26, r27
	  or        r11, r11, r0
	  addi      r10, r10, 0x8
	  addi      r12, r12, 0x8
	  bdnz+     .loc_0xD8
	  b         .loc_0x228

	.loc_0x1A0:
	  sub       r0, r29, r12
	  cmpw      r12, r29
	  mtctr     r0
	  bge-      .loc_0x1D0

	.loc_0x1B0:
	  subfic    r0, r12, 0x3
	  lbz       r3, 0x0(r4)
	  rlwinm    r0,r0,3,0,28
	  slw       r0, r3, r0
	  or        r11, r11, r0
	  addi      r4, r4, 0x1
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0x1B0

	.loc_0x1D0:
	  lis       r3, 0xCC00
	  stw       r11, 0x6838(r3)

	.loc_0x1D8:
	  lwz       r3, 0x2AE8(r13)
	  cmplwi    r30, 0x1
	  stw       r28, 0x14(r3)
	  beq-      .loc_0x1F0
	  mr        r6, r29
	  b         .loc_0x1F4

	.loc_0x1F0:
	  li        r6, 0

	.loc_0x1F4:
	  lwz       r5, 0x2AE8(r13)
	  rlwinm    r4,r30,2,0,29
	  subi      r0, r29, 0x1
	  stw       r6, 0x10(r5)
	  ori       r4, r4, 0x1
	  rlwinm    r0,r0,4,0,27
	  lis       r3, 0xCC00
	  or        r0, r4, r0
	  stw       r0, 0x6834(r3)
	  mr        r3, r31
	  bl        -0x27A64
	  li        r3, 0x1
	  b         .loc_0x230

	.loc_0x228:
	  add       r4, r28, r12
	  b         .loc_0x1A0

	.loc_0x230:
	  lmw       r21, 0x24(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void AmcEXIDma(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80220A30
 * Size:	000198
 */
void AmcEXISync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r4, 0x2AE8(r13)
	  b         .loc_0x170

	.loc_0x18:
	  lwz       r0, 0x34(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x178
	  bl        -0x27AD8
	  lwz       r6, 0x2AE8(r13)
	  lwz       r0, 0xC(r6)
	  addi      r4, r6, 0xC
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x168
	  lwz       r0, 0x0(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x158
	  lwz       r4, 0x10(r6)
	  cmpwi     r4, 0
	  beq-      .loc_0x158
	  lis       r5, 0xCC00
	  lwz       r7, 0x14(r6)
	  lwz       r6, 0x6838(r5)
	  li        r5, 0
	  ble-      .loc_0x158
	  cmpwi     r4, 0x8
	  subi      r8, r4, 0x8
	  ble-      .loc_0x12C
	  addi      r0, r8, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r8, 0
	  mtctr     r0
	  ble-      .loc_0x12C

	.loc_0x88:
	  subfic    r0, r5, 0x3
	  rlwinm    r8,r0,3,0,28
	  addi      r0, r5, 0x1
	  srw       r8, r6, r8
	  subfic    r0, r0, 0x3
	  stb       r8, 0x0(r7)
	  rlwinm    r0,r0,3,0,28
	  addi      r8, r5, 0x2
	  srw       r0, r6, r0
	  subfic    r8, r8, 0x3
	  stb       r0, 0x1(r7)
	  rlwinm    r8,r8,3,0,28
	  srw       r31, r6, r8
	  neg       r8, r5
	  stb       r31, 0x2(r7)
	  rlwinm    r9,r8,3,0,28
	  addi      r8, r5, 0x4
	  srw       r12, r6, r9
	  subfic    r8, r8, 0x3
	  stb       r12, 0x3(r7)
	  rlwinm    r9,r8,3,0,28
	  addi      r8, r5, 0x5
	  srw       r11, r6, r9
	  subfic    r8, r8, 0x3
	  stb       r11, 0x4(r7)
	  rlwinm    r9,r8,3,0,28
	  srw       r10, r6, r9
	  addi      r8, r5, 0x6
	  stb       r10, 0x5(r7)
	  subfic    r9, r8, 0x3
	  addi      r8, r5, 0x7
	  rlwinm    r9,r9,3,0,28
	  srw       r9, r6, r9
	  subfic    r8, r8, 0x3
	  stb       r9, 0x6(r7)
	  rlwinm    r8,r8,3,0,28
	  srw       r8, r6, r8
	  stb       r8, 0x7(r7)
	  addi      r7, r7, 0x8
	  addi      r5, r5, 0x8
	  bdnz+     .loc_0x88

	.loc_0x12C:
	  sub       r0, r4, r5
	  cmpw      r5, r4
	  mtctr     r0
	  bge-      .loc_0x158

	.loc_0x13C:
	  subfic    r0, r5, 0x3
	  rlwinm    r0,r0,3,0,28
	  srw       r0, r6, r0
	  stb       r0, 0x0(r7)
	  addi      r7, r7, 0x1
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x13C

	.loc_0x158:
	  lwz       r4, 0x2AE8(r13)
	  lwz       r0, 0xC(r4)
	  rlwinm    r0,r0,0,0,29
	  stw       r0, 0xC(r4)

	.loc_0x168:
	  bl        -0x27BF4
	  b         .loc_0x184

	.loc_0x170:
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6800

	.loc_0x178:
	  lwz       r0, 0xC(r4)
	  rlwinm.   r0,r0,0,29,29
	  bne+      .loc_0x18

	.loc_0x184:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220BC8
 * Size:	000040
 */
void AmcEXIClearInterrupts(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0
	  beq-      .loc_0x1C
	  lis       r3, 0xCC00
	  lwz       r0, 0x3000(r3)
	  rlwinm    r0,r0,0,19,19
	  ori       r0, r0, 0x1000
	  stw       r0, 0x3000(r3)

	.loc_0x1C:
	  cmpwi     r4, 0
	  beqlr-
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6800
	  lwz       r0, 0x28(r3)
	  andi.     r0, r0, 0x7F5
	  ori       r0, r0, 0x8
	  stw       r0, 0x28(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220C08
 * Size:	00006C
 */
void AmcEXISetExiCallback(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x27CA4
	  cmplwi    r30, 0
	  addi      r31, r3, 0
	  beq-      .loc_0x34
	  li        r3, 0x40
	  bl        -0x27890
	  b         .loc_0x3C

	.loc_0x34:
	  li        r3, 0x40
	  bl        -0x27924

	.loc_0x3C:
	  lwz       r4, 0x2AE8(r13)
	  mr        r3, r31
	  lwz       r31, 0x0(r4)
	  stw       r30, 0x0(r4)
	  bl        -0x27CB0
	  lwz       r0, 0x1C(r1)
	  mr        r3, r31
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void AmcEXIEnable32MHz(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void AmcEXIDisable32MHz(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80220C74
 * Size:	000080
 */
void AmcEXISelect(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x27D0C
	  lwz       r4, 0x2AE8(r13)
	  lwz       r0, 0xC(r4)
	  addi      r5, r4, 0xC
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x38
	  bl        -0x27CFC
	  li        r3, 0
	  b         .loc_0x6C

	.loc_0x38:
	  lwz       r0, 0x0(r5)
	  lis       r4, 0xCC00
	  addi      r4, r4, 0x6800
	  ori       r0, r0, 0x4
	  stw       r0, 0x0(r5)
	  rlwinm    r0,r31,4,0,27
	  ori       r0, r0, 0x80
	  lwz       r5, 0x28(r4)
	  andi.     r5, r5, 0x405
	  or        r5, r5, r0
	  stw       r5, 0x28(r4)
	  bl        -0x27D34
	  li        r3, 0x1

	.loc_0x6C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220CF4
 * Size:	000068
 */
void AmcEXIDeselect(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x27D84
	  lwz       r4, 0x2AE8(r13)
	  lwz       r0, 0xC(r4)
	  addi      r5, r4, 0xC
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x30
	  bl        -0x27D74
	  li        r3, 0
	  b         .loc_0x58

	.loc_0x30:
	  lwz       r0, 0x0(r5)
	  lis       r4, 0xCC00
	  addi      r4, r4, 0x6800
	  rlwinm    r0,r0,0,30,28
	  stw       r0, 0x0(r5)
	  lwz       r0, 0x28(r4)
	  andi.     r0, r0, 0x405
	  stw       r0, 0x28(r4)
	  bl        -0x27DA0
	  li        r3, 0x1

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
void AmcTCIntrruptHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80220D5C
 * Size:	000050
 */
void AmcDebugIntHandler(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0xCC00
	  stw       r0, 0x4(r1)
	  lwz       r0, 0x3000(r5)
	  stwu      r1, -0x8(r1)
	  rlwinm    r0,r0,0,19,19
	  lwz       r3, 0x2AE8(r13)
	  ori       r0, r0, 0x1000
	  stw       r0, 0x3000(r5)
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  mr        r12, r3
	  beq-      .loc_0x40
	  mtlr      r12
	  li        r3, 0x2
	  blrl

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220DAC
 * Size:	000040
 */
void AmcEXIEnableInterrupts(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x1
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x8000
	  stwu      r1, -0x8(r1)
	  bl        -0x27AA4
	  lis       r3, 0x8022
	  addi      r4, r3, 0xD5C
	  li        r3, 0x19
	  bl        -0x27E08
	  li        r3, 0x40
	  bl        -0x27A34
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220DEC
 * Size:	000040
 */
void AmcEXIInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0x6280
	  li        r4, 0
	  stwu      r1, -0x8(r1)
	  li        r5, 0x18
	  bl        -0x21DAE8
	  lis       r4, 0xCC00
	  li        r0, 0
	  stw       r0, 0x6828(r4)
	  stw       r0, 0x643C(r4)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
