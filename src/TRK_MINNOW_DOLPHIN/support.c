#include "types.h"

/*
 * --INFO--
 * Address:	8021E21C
 * Size:	0002D8
 */
void TRKSuppAccessFile(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r21, 0x1C(r1)
	  mr.       r27, r4
	  addi      r25, r3, 0
	  addi      r23, r5, 0
	  addi      r26, r6, 0
	  addi      r22, r7, 0
	  addi      r30, r8, 0
	  beq-      .loc_0x38
	  lwz       r0, 0x0(r23)
	  cmplwi    r0, 0
	  bne-      .loc_0x40

	.loc_0x38:
	  li        r3, 0x2
	  b         .loc_0x2C4

	.loc_0x40:
	  li        r0, 0
	  stb       r0, 0x0(r26)
	  li        r24, 0
	  li        r28, 0
	  li        r21, 0
	  b         .loc_0x294

	.loc_0x58:
	  sub       r0, r3, r28
	  cmplwi    r0, 0x800
	  ble-      .loc_0x6C
	  li        r31, 0x800
	  b         .loc_0x70

	.loc_0x6C:
	  mr        r31, r0

	.loc_0x70:
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x10
	  bl        -0x1D48
	  mr.       r21, r3
	  bne-      .loc_0xD8
	  lwz       r7, 0x10(r1)
	  lwz       r0, 0xC(r7)
	  cmplwi    r0, 0x880
	  blt-      .loc_0x9C
	  li        r5, 0x301
	  b         .loc_0xD4

	.loc_0x9C:
	  cmpwi     r30, 0
	  beq-      .loc_0xAC
	  li        r6, 0xD1
	  b         .loc_0xB0

	.loc_0xAC:
	  li        r6, 0xD0

	.loc_0xB0:
	  lwz       r4, 0xC(r7)
	  li        r5, 0
	  addi      r3, r4, 0x1
	  addi      r0, r4, 0x10
	  stw       r3, 0xC(r7)
	  stbx      r6, r7, r0
	  lwz       r3, 0x8(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r7)

	.loc_0xD4:
	  mr        r21, r5

	.loc_0xD8:
	  cmpwi     r21, 0
	  bne-      .loc_0xF0
	  lwz       r3, 0x10(r1)
	  mr        r4, r25
	  bl        -0x1A94
	  mr        r21, r3

	.loc_0xF0:
	  cmpwi     r21, 0
	  bne-      .loc_0x108
	  lwz       r3, 0x10(r1)
	  rlwinm    r4,r31,0,16,31
	  bl        -0x1B00
	  mr        r21, r3

	.loc_0x108:
	  cmpwi     r30, 0
	  bne-      .loc_0x12C
	  cmpwi     r21, 0
	  bne-      .loc_0x12C
	  lwz       r3, 0x10(r1)
	  addi      r5, r31, 0
	  add       r4, r27, r28
	  bl        -0x19E4
	  mr        r21, r3

	.loc_0x12C:
	  cmpwi     r21, 0
	  bne-      .loc_0x288
	  cmpwi     r22, 0
	  beq-      .loc_0x27C
	  li        r0, 0
	  cmpwi     r30, 0
	  sth       r0, 0xA(r1)
	  stb       r0, 0x8(r1)
	  beq-      .loc_0x15C
	  cmplwi    r25, 0
	  bne-      .loc_0x15C
	  li        r0, 0x1

	.loc_0x15C:
	  cmpwi     r30, 0
	  beq-      .loc_0x16C
	  li        r5, 0x5
	  b         .loc_0x170

	.loc_0x16C:
	  li        r5, 0x5

	.loc_0x170:
	  cntlzw    r0, r0
	  lwz       r3, 0x10(r1)
	  rlwinm    r7,r0,27,5,31
	  addi      r4, r1, 0x14
	  li        r6, 0x3
	  bl        .loc_0x2D8
	  mr.       r21, r3
	  bne-      .loc_0x1A4
	  lwz       r3, 0x14(r1)
	  bl        -0x1DC8
	  addi      r29, r3, 0
	  li        r4, 0x2
	  bl        -0x1D00

	.loc_0x1A4:
	  cmpwi     r21, 0
	  bne-      .loc_0x1BC
	  addi      r3, r29, 0
	  addi      r4, r1, 0x8
	  bl        -0x1990
	  mr        r21, r3

	.loc_0x1BC:
	  cmpwi     r21, 0
	  bne-      .loc_0x1D4
	  addi      r3, r29, 0
	  addi      r4, r1, 0xA
	  bl        -0x1984
	  mr        r21, r3

	.loc_0x1D4:
	  cmpwi     r30, 0
	  beq-      .loc_0x230
	  cmpwi     r21, 0
	  bne-      .loc_0x230
	  lhz       r3, 0xA(r1)
	  lwz       r4, 0x8(r29)
	  addi      r0, r3, 0x5
	  cmplw     r4, r0
	  beq-      .loc_0x214
	  lbz       r0, 0x8(r1)
	  subi      r3, r4, 0x5
	  sth       r3, 0xA(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x214
	  li        r0, 0x1
	  stb       r0, 0x8(r1)

	.loc_0x214:
	  lhz       r5, 0xA(r1)
	  cmplw     r5, r31
	  bgt-      .loc_0x230
	  addi      r3, r29, 0
	  add       r4, r27, r28
	  bl        -0x1820
	  mr        r21, r3

	.loc_0x230:
	  lhz       r3, 0xA(r1)
	  cmplw     r3, r31
	  beq-      .loc_0x268
	  cmpwi     r30, 0
	  beq-      .loc_0x24C
	  cmplw     r3, r31
	  blt-      .loc_0x260

	.loc_0x24C:
	  lbz       r0, 0x8(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x260
	  li        r0, 0x1
	  stb       r0, 0x8(r1)

	.loc_0x260:
	  addi      r31, r3, 0
	  li        r24, 0x1

	.loc_0x268:
	  lbz       r0, 0x8(r1)
	  stb       r0, 0x0(r26)
	  lwz       r3, 0x14(r1)
	  bl        -0x1E7C
	  b         .loc_0x288

	.loc_0x27C:
	  lwz       r3, 0x10(r1)
	  bl        -0x1FF8
	  mr        r21, r3

	.loc_0x288:
	  lwz       r3, 0xC(r1)
	  bl        -0x1E94
	  add       r28, r28, r31

	.loc_0x294:
	  cmpwi     r24, 0
	  bne-      .loc_0x2BC
	  lwz       r3, 0x0(r23)
	  cmplw     r28, r3
	  bge-      .loc_0x2BC
	  cmpwi     r21, 0
	  bne-      .loc_0x2BC
	  lbz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  beq+      .loc_0x58

	.loc_0x2BC:
	  stw       r28, 0x0(r23)
	  mr        r3, r21

	.loc_0x2C4:
	  lmw       r21, 0x1C(r1)
	  addi      r1, r1, 0x48
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr

	.loc_0x2D8:
	*/
}

/*
 * --INFO--
 * Address:	8021E4F4
 * Size:	0001A4
 */
void TRKRequestSend(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, -0x1
	  stwu      r1, -0x38(r1)
	  stmw      r22, 0x10(r1)
	  addi      r23, r4, 0
	  lis       r4, 0x4C5
	  addi      r27, r6, 0x1
	  addi      r22, r3, 0
	  subi      r31, r4, 0x4C14
	  addi      r24, r5, 0
	  addi      r25, r7, 0
	  li        r30, 0
	  li        r26, 0x1
	  stw       r0, 0x0(r23)
	  b         .loc_0x160

	.loc_0x40:
	  mr        r3, r22
	  bl        -0x2094
	  mr.       r30, r3
	  bne-      .loc_0x15C
	  cmpwi     r25, 0
	  beq-      .loc_0x5C
	  li        r28, 0

	.loc_0x5C:
	  bl        -0x183C
	  stw       r3, 0x0(r23)
	  lwz       r3, 0x0(r23)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x84
	  cmpwi     r25, 0
	  beq+      .loc_0x5C
	  addi      r28, r28, 0x1
	  cmplw     r28, r31
	  blt+      .loc_0x5C

	.loc_0x84:
	  cmpwi     r3, -0x1
	  beq-      .loc_0xD4
	  li        r26, 0
	  bl        -0x1F9C
	  addi      r29, r3, 0
	  li        r4, 0
	  bl        -0x1ED4
	  addi      r3, r29, 0
	  addi      r4, r1, 0x8
	  bl        -0x1B5C
	  mr.       r30, r3
	  bne-      .loc_0xD4
	  lbz       r0, 0x8(r1)
	  cmplwi    r0, 0x80
	  bge-      .loc_0xD4
	  lwz       r3, 0x0(r23)
	  bl        -0x1758
	  li        r0, -0x1
	  stw       r0, 0x0(r23)
	  b         .loc_0x5C

	.loc_0xD4:
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x15C
	  lwz       r0, 0x8(r29)
	  cmplw     r0, r24
	  bge-      .loc_0xF0
	  li        r26, 0x1

	.loc_0xF0:
	  cmpwi     r30, 0
	  bne-      .loc_0x110
	  cmpwi     r26, 0
	  bne-      .loc_0x110
	  addi      r3, r29, 0
	  addi      r4, r1, 0x9
	  bl        -0x1BBC
	  mr        r30, r3

	.loc_0x110:
	  cmpwi     r30, 0
	  bne-      .loc_0x13C
	  cmpwi     r26, 0
	  bne-      .loc_0x13C
	  lbz       r0, 0x8(r1)
	  cmplwi    r0, 0x80
	  bne-      .loc_0x138
	  lbz       r0, 0x9(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x13C

	.loc_0x138:
	  li        r26, 0x1

	.loc_0x13C:
	  cmpwi     r30, 0
	  bne-      .loc_0x14C
	  cmpwi     r26, 0
	  beq-      .loc_0x15C

	.loc_0x14C:
	  lwz       r3, 0x0(r23)
	  bl        -0x2030
	  li        r0, -0x1
	  stw       r0, 0x0(r23)

	.loc_0x15C:
	  subi      r27, r27, 0x1

	.loc_0x160:
	  cmpwi     r27, 0
	  beq-      .loc_0x17C
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x17C
	  cmpwi     r30, 0
	  beq+      .loc_0x40

	.loc_0x17C:
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x18C
	  li        r30, 0x800

	.loc_0x18C:
	  mr        r3, r30
	  lmw       r22, 0x10(r1)
	  addi      r1, r1, 0x38
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
