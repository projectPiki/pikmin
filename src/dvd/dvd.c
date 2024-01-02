#include "types.h"

/*
 * --INFO--
 * Address:	801FF964
 * Size:	0000FC
 */
void DVDInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  subi      r30, r3, 0x77E8
	  lwz       r0, 0x32F8(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xE4
	  bl        -0x98CC
	  li        r31, 0x1
	  stw       r31, 0x32F8(r13)
	  bl        -0xA18
	  bl        0x2568
	  bl        -0x1874
	  lis       r0, 0x8000
	  lis       r3, 0x8020
	  stw       r0, 0x32C0(r13)
	  subi      r4, r3, 0x1E94
	  stw       r0, 0x32BC(r13)
	  li        r3, 0x15
	  bl        -0x69F4
	  li        r3, 0x400
	  bl        -0x6620
	  addi      r3, r13, 0x32B0
	  bl        -0x3EF8
	  lis       r3, 0xCC00
	  li        r0, 0x2A
	  stw       r0, 0x6000(r3)
	  li        r0, 0
	  stw       r0, 0x6004(r3)
	  lwz       r3, 0x32C0(r13)
	  addi      r3, r3, 0x20
	  lwz       r3, 0x0(r3)
	  addis     r0, r3, 0x1AE0
	  cmplwi    r0, 0x7C22
	  bne-      .loc_0xB8
	  addi      r3, r30, 0
	  crclr     6, 0x6
	  bl        -0x8174
	  addi      r3, r30, 0x18
	  crclr     6, 0x6
	  bl        -0x8180
	  bl        0x2918
	  b         .loc_0xE4

	.loc_0xB8:
	  subis     r0, r3, 0xD15
	  cmplwi    r0, 0xEA5E
	  bne-      .loc_0xD4
	  addi      r3, r30, 0x24
	  crclr     6, 0x6
	  bl        -0x81A0
	  b         .loc_0xE4

	.loc_0xD4:
	  stw       r31, 0x32F4(r13)
	  addi      r3, r30, 0x40
	  crclr     6, 0x6
	  bl        -0x81B4

	.loc_0xE4:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  mtlr      r0
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FFA60
 * Size:	000054
 */
void stateReadingFST(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8020
	  stw       r0, 0x4(r1)
	  subi      r0, r3, 0x5A0
	  lis       r3, 0x803D
	  stwu      r1, -0x8(r1)
	  addi      r5, r3, 0x3100
	  lis       r3, 0x8020
	  stw       r0, 0x32FC(r13)
	  subi      r6, r3, 0x54C
	  lwz       r7, 0x32C0(r13)
	  lwz       r4, 0x8(r5)
	  lwz       r3, 0x38(r7)
	  addi      r0, r4, 0x1F
	  lwz       r5, 0x4(r5)
	  rlwinm    r4,r0,0,0,26
	  bl        -0x13BC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FFAB4
 * Size:	000080
 */
void cbForStateReadingFST(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x28
	  lwz       r3, 0x32B8(r13)
	  li        r0, -0x1
	  stw       r0, 0xC(r3)
	  bl        0x108
	  b         .loc_0x70

	.loc_0x28:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x6C
	  lis       r3, 0x803D
	  lwz       r4, 0x32B8(r13)
	  addi      r0, r3, 0x3180
	  li        r3, 0
	  stw       r0, 0x32B8(r13)
	  stw       r3, 0x32EC(r13)
	  stw       r3, 0xC(r4)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x64
	  mtlr      r12
	  li        r3, 0
	  blrl

	.loc_0x64:
	  bl        0xE10
	  b         .loc_0x70

	.loc_0x6C:
	  bl        0x158

	.loc_0x70:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FFB34
 * Size:	0000A8
 */
void cbForStateError(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x2C
	  lwz       r3, 0x32B8(r13)
	  li        r0, -0x1
	  stw       r0, 0xC(r3)
	  bl        .loc_0xA8
	  b         .loc_0x94

	.loc_0x2C:
	  lis       r3, 0x803D
	  lwz       r31, 0x32B8(r13)
	  addi      r0, r3, 0x3180
	  li        r3, 0x1
	  stw       r0, 0x32B8(r13)
	  stw       r3, 0x32D0(r13)
	  lwz       r12, 0x28(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x60
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, -0x1
	  blrl

	.loc_0x60:
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  lwz       r12, 0x32DC(r13)
	  li        r0, 0
	  stw       r0, 0x32D8(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x90
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, 0
	  blrl

	.loc_0x90:
	  bl        0xD64

	.loc_0x94:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0xA8:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void stateError(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FFBDC
 * Size:	00009C
 */
void stateTimeout(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x123
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0x4568
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        0x2508
	  bl        0x1CD4
	  lis       r3, 0x803D
	  lwz       r31, 0x32B8(r13)
	  addi      r0, r3, 0x3180
	  li        r3, 0x1
	  stw       r0, 0x32B8(r13)
	  stw       r3, 0x32D0(r13)
	  lwz       r12, 0x28(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x54
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, -0x1
	  blrl

	.loc_0x54:
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r12, 0x32DC(r13)
	  li        r0, 0
	  stw       r0, 0x32D8(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x84
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, 0
	  blrl

	.loc_0x84:
	  bl        0xCC8
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FFC78
 * Size:	000028
 */
void stateGettingError(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8020
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x2AC
	  stwu      r1, -0x8(r1)
	  bl        -0x1120
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FFCA0
 * Size:	0000B4
 */
void CategorizeError(void)
{
	/*
	.loc_0x0:
	  subis     r0, r3, 0x2
	  cmplwi    r0, 0x400
	  bne-      .loc_0x18
	  stw       r3, 0x32E8(r13)
	  li        r3, 0x1
	  blr

	.loc_0x18:
	  rlwinm    r4,r3,0,8,31
	  subis     r0, r4, 0x6
	  cmplwi    r0, 0x2800
	  beq-      .loc_0x40
	  subis     r0, r4, 0x2
	  cmplwi    r0, 0x3A00
	  beq-      .loc_0x40
	  subis     r0, r4, 0xB
	  cmplwi    r0, 0x5A01
	  bne-      .loc_0x48

	.loc_0x40:
	  li        r3, 0
	  blr

	.loc_0x48:
	  lwz       r3, 0x32EC(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x32EC(r13)
	  lwz       r0, 0x32EC(r13)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x84
	  lwz       r0, 0x32E8(r13)
	  cmplw     r4, r0
	  bne-      .loc_0x78
	  stw       r4, 0x32E8(r13)
	  li        r3, 0x1
	  blr

	.loc_0x78:
	  stw       r4, 0x32E8(r13)
	  li        r3, 0x2
	  blr

	.loc_0x84:
	  subis     r0, r4, 0x3
	  stw       r4, 0x32E8(r13)
	  cmplwi    r0, 0x1100
	  beq-      .loc_0xA4
	  lwz       r3, 0x32B8(r13)
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x5
	  bne-      .loc_0xAC

	.loc_0xA4:
	  li        r3, 0x2
	  blr

	.loc_0xAC:
	  li        r3, 0x3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void CheckCancel(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FFD54
 * Size:	000294
 */
void cbForStateGettingError(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  bne-      .loc_0x4C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x2370
	  bl        0x1B3C
	  li        r3, 0
	  bl        -0x264
	  b         .loc_0x274

	.loc_0x4C:
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x7C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4567
	  bl        0x2340
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x12E8
	  b         .loc_0x274

	.loc_0x7C:
	  lis       r3, 0xCC00
	  lwz       r29, 0x6020(r3)
	  addi      r3, r29, 0
	  rlwinm    r28,r29,0,0,7
	  bl        -0x140
	  addi      r31, r3, 0
	  cmplwi    r31, 0x1
	  bne-      .loc_0xC0
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  addi      r3, r29, 0
	  stw       r0, 0xC(r4)
	  bl        0x22FC
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x132C
	  b         .loc_0x274

	.loc_0xC0:
	  subi      r0, r31, 0x2
	  cmplwi    r0, 0x1
	  bgt-      .loc_0xD4
	  li        r4, 0
	  b         .loc_0x114

	.loc_0xD4:
	  subis     r0, r28, 0x100
	  cmplwi    r0, 0
	  bne-      .loc_0xE8
	  li        r4, 0x4
	  b         .loc_0x114

	.loc_0xE8:
	  subis     r0, r28, 0x200
	  cmplwi    r0, 0
	  bne-      .loc_0xFC
	  li        r4, 0x6
	  b         .loc_0x114

	.loc_0xFC:
	  subis     r0, r28, 0x300
	  cmplwi    r0, 0
	  bne-      .loc_0x110
	  li        r4, 0x3
	  b         .loc_0x114

	.loc_0x110:
	  li        r4, 0x5

	.loc_0x114:
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x188
	  lis       r3, 0x803D
	  stw       r4, 0x32E0(r13)
	  li        r0, 0
	  lwz       r30, 0x32B8(r13)
	  addi      r3, r3, 0x3180
	  stw       r0, 0x32D8(r13)
	  li        r0, 0xA
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r30)
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0x160
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, -0x3
	  blrl

	.loc_0x160:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x17C
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, 0
	  blrl

	.loc_0x17C:
	  bl        0xA58
	  li        r0, 0x1
	  b         .loc_0x18C

	.loc_0x188:
	  li        r0, 0

	.loc_0x18C:
	  cmpwi     r0, 0
	  bne-      .loc_0x274
	  cmplwi    r31, 0x2
	  bne-      .loc_0x1AC
	  mr        r3, r29
	  bl        0x2208
	  bl        0x1F0
	  b         .loc_0x274

	.loc_0x1AC:
	  cmplwi    r31, 0x3
	  bne-      .loc_0x1F0
	  rlwinm    r3,r29,0,8,31
	  subis     r0, r3, 0x3
	  cmplwi    r0, 0x1100
	  bne-      .loc_0x1DC
	  lwz       r5, 0x32B8(r13)
	  lis       r3, 0x8020
	  subi      r4, r3, 0x18
	  lwz       r3, 0x10(r5)
	  bl        -0x15AC
	  b         .loc_0x274

	.loc_0x1DC:
	  lwz       r12, 0x32FC(r13)
	  lwz       r3, 0x32B8(r13)
	  mtlr      r12
	  blrl
	  b         .loc_0x274

	.loc_0x1F0:
	  subis     r0, r28, 0x100
	  cmplwi    r0, 0
	  bne-      .loc_0x210
	  lwz       r3, 0x32B8(r13)
	  li        r0, 0x5
	  stw       r0, 0xC(r3)
	  bl        0x8C0
	  b         .loc_0x274

	.loc_0x210:
	  subis     r0, r28, 0x200
	  cmplwi    r0, 0
	  bne-      .loc_0x230
	  lwz       r3, 0x32B8(r13)
	  li        r0, 0x3
	  stw       r0, 0xC(r3)
	  bl        0x734
	  b         .loc_0x274

	.loc_0x230:
	  subis     r0, r28, 0x300
	  cmplwi    r0, 0
	  bne-      .loc_0x250
	  lwz       r3, 0x32B8(r13)
	  li        r0, 0x4
	  stw       r0, 0xC(r3)
	  bl        0x880
	  b         .loc_0x274

	.loc_0x250:
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4567
	  bl        0x2144
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x14E4

	.loc_0x274:
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
 * Address:	801FFFE8
 * Size:	000068
 */
void cbForUnrecoveredError(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x3C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x20EC
	  bl        0x18B8
	  li        r3, 0
	  bl        -0x4E8
	  b         .loc_0x58

	.loc_0x3C:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x4C
	  bl        0xBC
	  b         .loc_0x58

	.loc_0x4C:
	  lis       r3, 0x8020
	  addi      r3, r3, 0x50
	  bl        -0x14D0

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200050
 * Size:	000098
 */
void cbForUnrecoveredErrorRetry(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x3C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x2084
	  bl        0x1850
	  li        r3, 0
	  bl        -0x550
	  b         .loc_0x88

	.loc_0x3C:
	  rlwinm.   r0,r3,0,30,30
	  lwz       r3, 0x32B8(r13)
	  li        r4, -0x1
	  stw       r4, 0xC(r3)
	  beq-      .loc_0x6C
	  lis       r3, 0x123
	  addi      r3, r3, 0x4567
	  bl        0x2054
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x15D4
	  b         .loc_0x88

	.loc_0x6C:
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6000
	  lwz       r3, 0x20(r3)
	  bl        0x2034
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x15F4

	.loc_0x88:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802000E8
 * Size:	000028
 */
void stateGoToRetry(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0x110
	  stwu      r1, -0x8(r1)
	  bl        -0x161C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200110
 * Size:	000158
 */
void cbForStateGoToRetry(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x40
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x1FC0
	  bl        0x178C
	  li        r3, 0
	  bl        -0x614
	  b         .loc_0x144

	.loc_0x40:
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x70
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4567
	  bl        0x1F90
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x1698
	  b         .loc_0x144

	.loc_0x70:
	  li        r0, 0
	  stw       r0, 0x32EC(r13)
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x4
	  beq-      .loc_0xA8
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x5
	  beq-      .loc_0xA8
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xD
	  beq-      .loc_0xA8
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xF
	  bne-      .loc_0xB0

	.loc_0xA8:
	  li        r0, 0x1
	  stw       r0, 0x32F0(r13)

	.loc_0xB0:
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x128
	  li        r0, 0x2
	  lwz       r31, 0x32B8(r13)
	  lis       r3, 0x803D
	  stw       r0, 0x32E0(r13)
	  addi      r0, r3, 0x3180
	  li        r3, 0
	  stw       r0, 0x32B8(r13)
	  li        r0, 0xA
	  stw       r3, 0x32D8(r13)
	  stw       r0, 0xC(r31)
	  lwz       r12, 0x28(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x100
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, -0x3
	  blrl

	.loc_0x100:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x11C
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, 0
	  blrl

	.loc_0x11C:
	  bl        0x6FC
	  li        r0, 0x1
	  b         .loc_0x12C

	.loc_0x128:
	  li        r0, 0

	.loc_0x12C:
	  cmpwi     r0, 0
	  bne-      .loc_0x144
	  lwz       r3, 0x32B8(r13)
	  li        r0, 0xB
	  stw       r0, 0xC(r3)
	  bl        0x5CC

	.loc_0x144:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200268
 * Size:	0000E4
 */
void stateCheckID(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  addi      r31, r3, 0x3100
	  lwz       r0, 0x32D4(r13)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x28
	  b         .loc_0x94

	.loc_0x28:
	  lwz       r4, 0x32B8(r13)
	  addi      r3, r31, 0
	  li        r5, 0x1C
	  lwz       r4, 0x24(r4)
	  bl        0x15ECC
	  cmpwi     r3, 0
	  beq-      .loc_0x54
	  lis       r3, 0x8020
	  addi      r3, r3, 0x3B8
	  bl        -0x17D4
	  b         .loc_0xD0

	.loc_0x54:
	  lwz       r3, 0x32BC(r13)
	  addi      r4, r31, 0
	  li        r5, 0x20
	  bl        -0x1FCEB4
	  lwz       r4, 0x32B8(r13)
	  li        r0, 0x1
	  addi      r3, r31, 0
	  stw       r0, 0xC(r4)
	  li        r4, 0x20
	  bl        -0x9728
	  lis       r4, 0x8020
	  lwz       r3, 0x32B8(r13)
	  addi      r0, r4, 0x380
	  stw       r0, 0x32FC(r13)
	  bl        0x8C
	  b         .loc_0xD0

	.loc_0x94:
	  lwz       r4, 0x32BC(r13)
	  addi      r3, r31, 0
	  li        r5, 0x20
	  bl        0x15E64
	  cmpwi     r3, 0
	  beq-      .loc_0xBC
	  lis       r3, 0x8020
	  addi      r3, r3, 0x3B8
	  bl        -0x183C
	  b         .loc_0xD0

	.loc_0xBC:
	  lis       r4, 0x8020
	  lwz       r3, 0x32B8(r13)
	  addi      r0, r4, 0x34C
	  stw       r0, 0x32FC(r13)
	  bl        .loc_0xE4

	.loc_0xD0:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr

	.loc_0xE4:
	*/
}

/*
 * --INFO--
 * Address:	8020034C
 * Size:	000034
 */
void stateCheckID3(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r5, r3, 0x570
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x32BC(r13)
	  lbz       r3, 0x8(r4)
	  li        r4, 0xA
	  bl        -0x15B4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200380
 * Size:	000038
 */
void stateCheckID2(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  lis       r4, 0x8020
	  addi      r6, r4, 0x4CC
	  stwu      r1, -0x8(r1)
	  addi      r3, r3, 0x3100
	  li        r4, 0x20
	  li        r5, 0x420
	  bl        -0x1CC0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802003B8
 * Size:	000114
 */
void cbForStateCheckID1(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x40
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x1D18
	  bl        0x14E4
	  li        r3, 0
	  bl        -0x8BC
	  b         .loc_0x100

	.loc_0x40:
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x70
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4567
	  bl        0x1CE8
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x1940
	  b         .loc_0x100

	.loc_0x70:
	  li        r4, 0
	  stw       r4, 0x32EC(r13)
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  li        r0, 0x1
	  lwz       r31, 0x32B8(r13)
	  stw       r0, 0x32E0(r13)
	  lis       r3, 0x803D
	  addi      r3, r3, 0x3180
	  stw       r4, 0x32D8(r13)
	  li        r0, 0xA
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r31)
	  lwz       r12, 0x28(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0xC4
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, -0x3
	  blrl

	.loc_0xC4:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0xE0
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, 0
	  blrl

	.loc_0xE0:
	  bl        0x490
	  li        r4, 0x1

	.loc_0xE8:
	  cmpwi     r4, 0
	  bne-      .loc_0x100
	  lwz       r3, 0x32B8(r13)
	  li        r0, 0x6
	  stw       r0, 0xC(r3)
	  bl        0x368

	.loc_0x100:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802004CC
 * Size:	0000A4
 */
void cbForStateCheckID2(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x3C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x1C08
	  bl        0x13D4
	  li        r3, 0
	  bl        -0x9CC
	  b         .loc_0x94

	.loc_0x3C:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x88
	  lis       r3, 0x8020
	  lwz       r7, 0x32C0(r13)
	  subi      r0, r3, 0x5A0
	  li        r4, 0
	  stw       r0, 0x32FC(r13)
	  lis       r3, 0x803D
	  addi      r5, r3, 0x3100
	  stw       r4, 0x32EC(r13)
	  lis       r3, 0x8020
	  lwz       r4, 0x8(r5)
	  subi      r6, r3, 0x54C
	  lwz       r3, 0x38(r7)
	  addi      r0, r4, 0x1F
	  lwz       r5, 0x4(r5)
	  rlwinm    r4,r0,0,0,26
	  bl        -0x1E68
	  b         .loc_0x94

	.loc_0x88:
	  lis       r3, 0x8020
	  subi      r3, r3, 0x2AC
	  bl        -0x19F0

	.loc_0x94:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200570
 * Size:	0000FC
 */
void cbForStateCheckID3(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x40
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x1B60
	  bl        0x132C
	  li        r3, 0
	  bl        -0xA74
	  b         .loc_0xE8

	.loc_0x40:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0xDC
	  li        r4, 0
	  stw       r4, 0x32EC(r13)
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xBC
	  stw       r4, 0x32E0(r13)
	  lis       r3, 0x803D
	  lwz       r31, 0x32B8(r13)
	  addi      r3, r3, 0x3180
	  stw       r4, 0x32D8(r13)
	  li        r0, 0xA
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r31)
	  lwz       r12, 0x28(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x98
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, -0x3
	  blrl

	.loc_0x98:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0xB4
	  mtlr      r12
	  addi      r4, r31, 0
	  li        r3, 0
	  blrl

	.loc_0xB4:
	  bl        0x304
	  li        r4, 0x1

	.loc_0xBC:
	  cmpwi     r4, 0
	  bne-      .loc_0xE8
	  lwz       r3, 0x32B8(r13)
	  li        r0, 0x1
	  stw       r0, 0xC(r3)
	  lwz       r3, 0x32B8(r13)
	  bl        0x52C
	  b         .loc_0xE8

	.loc_0xDC:
	  lis       r3, 0x8020
	  subi      r3, r3, 0x2AC
	  bl        -0x1AE8

	.loc_0xE8:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020066C
 * Size:	000044
 */
void AlarmHandler(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x1254
	  lis       r3, 0x803D
	  addi      r3, r3, 0x3100
	  li        r4, 0x20
	  bl        -0x9AD0
	  lis       r4, 0x8020
	  lwz       r3, 0x32B8(r13)
	  addi      r0, r4, 0x77C
	  stw       r0, 0x32FC(r13)
	  bl        0xE0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802006B0
 * Size:	0000CC
 */
void stateCoverClosed(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  addi      r31, r3, 0x3100
	  lwz       r0, 0x32D4(r13)
	  cmpwi     r0, 0xD
	  beq-      .loc_0x48
	  bge-      .loc_0x3C
	  cmpwi     r0, 0x6
	  bge-      .loc_0x78
	  cmpwi     r0, 0x4
	  bge-      .loc_0x48
	  b         .loc_0x78

	.loc_0x3C:
	  cmpwi     r0, 0xF
	  beq-      .loc_0x48
	  b         .loc_0x78

	.loc_0x48:
	  bl        0x180C
	  lwz       r4, 0x32B8(r13)
	  addi      r0, r31, 0x80
	  stw       r0, 0x32B8(r13)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x70
	  mtlr      r12
	  li        r3, -0x4
	  blrl

	.loc_0x70:
	  bl        0x208
	  b         .loc_0xB8

	.loc_0x78:
	  bl        0x11A4
	  addi      r3, r31, 0xB0
	  bl        -0xA624
	  lis       r3, 0x8000
	  lwz       r0, 0xF8(r3)
	  lis       r4, 0x1062
	  lis       r3, 0x8020
	  rlwinm    r0,r0,30,2,31
	  addi      r4, r4, 0x4DD3
	  mulhwu    r0, r4, r0
	  rlwinm    r0,r0,26,6,31
	  mulli     r6, r0, 0x47E
	  addi      r7, r3, 0x66C
	  addi      r3, r31, 0xB0
	  li        r5, 0
	  bl        -0xA3FC

	.loc_0xB8:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020077C
 * Size:	000030
 */
void stateCoverClosed_CMD(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  lis       r4, 0x8020
	  addi      r3, r3, 0x3100
	  stwu      r1, -0x8(r1)
	  addi      r4, r4, 0x7AC
	  bl        -0x1D5C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802007AC
 * Size:	000070
 */
void cbForStateCoverClosed(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x3C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x1928
	  bl        0x10F4
	  li        r3, 0
	  bl        -0xCAC
	  b         .loc_0x60

	.loc_0x3C:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x54
	  li        r0, 0
	  stw       r0, 0x32EC(r13)
	  bl        -0x590
	  b         .loc_0x60

	.loc_0x54:
	  lis       r3, 0x8020
	  subi      r3, r3, 0x2AC
	  bl        -0x1C9C

	.loc_0x60:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020081C
 * Size:	000028
 */
void stateMotorStopped(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0x844
	  stwu      r1, -0x8(r1)
	  bl        -0x1E20
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200844
 * Size:	0000E4
 */
void cbForStateMotorStopped(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0xCC00
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  lis       r4, 0x803D
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0x3100
	  stw       r0, 0x6004(r3)
	  li        r0, 0x3
	  lwz       r3, 0x32B8(r13)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x32D4(r13)
	  cmpwi     r0, 0xD
	  beq-      .loc_0x60
	  bge-      .loc_0x54
	  cmpwi     r0, 0x6
	  bge-      .loc_0x90
	  cmpwi     r0, 0x4
	  bge-      .loc_0x60
	  b         .loc_0x90

	.loc_0x54:
	  cmpwi     r0, 0xF
	  beq-      .loc_0x60
	  b         .loc_0x90

	.loc_0x60:
	  bl        0x1660
	  lwz       r4, 0x32B8(r13)
	  addi      r0, r31, 0x80
	  stw       r0, 0x32B8(r13)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x88
	  mtlr      r12
	  li        r3, -0x4
	  blrl

	.loc_0x88:
	  bl        .loc_0xE4
	  b         .loc_0xD0

	.loc_0x90:
	  bl        0xFF8
	  addi      r3, r31, 0xB0
	  bl        -0xA7D0
	  lis       r3, 0x8000
	  lwz       r0, 0xF8(r3)
	  lis       r4, 0x1062
	  lis       r3, 0x8020
	  rlwinm    r0,r0,30,2,31
	  addi      r4, r4, 0x4DD3
	  mulhwu    r0, r4, r0
	  rlwinm    r0,r0,26,6,31
	  mulli     r6, r0, 0x47E
	  addi      r7, r3, 0x66C
	  addi      r3, r31, 0xB0
	  li        r5, 0
	  bl        -0xA5A8

	.loc_0xD0:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0xE4:
	*/
}

/*
 * --INFO--
 * Address:	80200928
 * Size:	000248
 */
void stateReady(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  addi      r31, r3, 0x3100
	  bl        0x1704
	  cmpwi     r3, 0
	  bne-      .loc_0x30
	  li        r0, 0
	  stw       r0, 0x32B8(r13)
	  b         .loc_0x234

	.loc_0x30:
	  lwz       r0, 0x32C4(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x50
	  li        r3, 0x1
	  li        r0, 0
	  stw       r3, 0x32C8(r13)
	  stw       r0, 0x32B8(r13)
	  b         .loc_0x234

	.loc_0x50:
	  bl        0x162C
	  lwz       r0, 0x32D0(r13)
	  stw       r3, 0x32B8(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x9C
	  lwz       r3, 0x32B8(r13)
	  li        r4, -0x1
	  addi      r0, r31, 0x80
	  stw       r4, 0xC(r3)
	  lwz       r4, 0x32B8(r13)
	  stw       r0, 0x32B8(r13)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x94
	  mtlr      r12
	  li        r3, -0x1
	  blrl

	.loc_0x94:
	  bl        .loc_0x0
	  b         .loc_0x234

	.loc_0x9C:
	  lwz       r4, 0x32B8(r13)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x32D4(r13)
	  lwz       r0, 0x32E0(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x224
	  lwz       r0, 0x32E0(r13)
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x218
	  lis       r3, 0x802F
	  subi      r3, r3, 0x779C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r0, 0x6
	  lis       r3, 0x8020
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x844
	  bl        -0x2000
	  b         .loc_0x218
	  li        r0, 0xB
	  lis       r3, 0x8020
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x844
	  bl        -0x2018
	  b         .loc_0x218
	  li        r0, 0x4
	  lis       r3, 0x8020
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x844
	  bl        -0x2030
	  b         .loc_0x218
	  li        r0, 0x7
	  lis       r3, 0x8020
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x844
	  bl        -0x2048
	  b         .loc_0x218
	  li        r0, 0x5
	  lis       r3, 0x8020
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x844
	  bl        -0x2060
	  b         .loc_0x218
	  li        r0, 0x3
	  stw       r0, 0xC(r4)
	  lwz       r0, 0x32D4(r13)
	  cmpwi     r0, 0xD
	  beq-      .loc_0x188
	  bge-      .loc_0x17C
	  cmpwi     r0, 0x6
	  bge-      .loc_0x1B8
	  cmpwi     r0, 0x4
	  bge-      .loc_0x188
	  b         .loc_0x1B8

	.loc_0x17C:
	  cmpwi     r0, 0xF
	  beq-      .loc_0x188
	  b         .loc_0x1B8

	.loc_0x188:
	  bl        0x1454
	  lwz       r4, 0x32B8(r13)
	  addi      r0, r31, 0x80
	  stw       r0, 0x32B8(r13)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x1B0
	  mtlr      r12
	  li        r3, -0x4
	  blrl

	.loc_0x1B0:
	  bl        .loc_0x0
	  b         .loc_0x218

	.loc_0x1B8:
	  bl        0xDEC
	  addi      r3, r31, 0xB0
	  bl        -0xA9DC
	  lis       r3, 0x8000
	  lwz       r0, 0xF8(r3)
	  lis       r4, 0x1062
	  lis       r3, 0x8020
	  rlwinm    r0,r0,30,2,31
	  addi      r4, r4, 0x4DD3
	  mulhwu    r0, r4, r0
	  rlwinm    r0,r0,26,6,31
	  mulli     r6, r0, 0x47E
	  addi      r7, r3, 0x66C
	  addi      r3, r31, 0xB0
	  li        r5, 0
	  bl        -0xA7B4
	  b         .loc_0x218
	  li        r0, -0x1
	  stw       r0, 0xC(r4)
	  lwz       r3, 0x32E4(r13)
	  bl        0x15CC
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x205C

	.loc_0x218:
	  li        r0, 0
	  stw       r0, 0x32E0(r13)
	  b         .loc_0x234

	.loc_0x224:
	  li        r0, 0x1
	  stw       r0, 0xC(r4)
	  lwz       r3, 0x32B8(r13)
	  bl        .loc_0x248

	.loc_0x234:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr

	.loc_0x248:
	*/
}

/*
 * --INFO--
 * Address:	80200B70
 * Size:	0002C0
 */
void stateBusy(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0xB70
	  mr        r7, r3
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x32FC(r13)
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0xF
	  bgt-      .loc_0x2B0
	  lis       r3, 0x802F
	  subi      r3, r3, 0x777C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  li        r0, 0x20
	  addi      r4, r3, 0xE30
	  stw       r0, 0x1C(r7)
	  lwz       r3, 0x18(r7)
	  bl        -0x2198
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6000
	  lwz       r0, 0x4(r3)
	  lis       r4, 0x8
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x20(r7)
	  lwz       r0, 0x14(r7)
	  sub       r0, r0, r3
	  cmplw     r0, r4
	  ble-      .loc_0x98
	  b         .loc_0x9C

	.loc_0x98:
	  mr        r4, r0

	.loc_0x9C:
	  stw       r4, 0x1C(r7)
	  lis       r3, 0x8020
	  addi      r6, r3, 0xE30
	  lwz       r5, 0x20(r7)
	  lwz       r3, 0x18(r7)
	  lwz       r0, 0x10(r7)
	  add       r3, r3, r5
	  lwz       r4, 0x1C(r7)
	  add       r5, r0, r5
	  bl        -0x254C
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  addi      r4, r3, 0xE30
	  lwz       r3, 0x10(r7)
	  bl        -0x22D8
	  b         .loc_0x2B0
	  lis       r3, 0x8020
	  addi      r3, r3, 0xE30
	  bl        -0x2184
	  b         .loc_0x2B0
	  lis       r3, 0x8020
	  addi      r3, r3, 0xE30
	  bl        -0x2194
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6000
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x32CC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x148
	  lwz       r5, 0x32B8(r13)
	  li        r0, 0
	  lis       r3, 0x8020
	  stw       r0, 0x1C(r5)
	  addi      r4, r3, 0xE30
	  li        r3, 0
	  bl        -0x1F84
	  b         .loc_0x2B0

	.loc_0x148:
	  lwz       r4, 0x32B8(r13)
	  li        r0, 0x1
	  lis       r3, 0x8020
	  stw       r0, 0x1C(r4)
	  addi      r6, r3, 0xE30
	  li        r3, 0
	  lwz       r4, 0x14(r7)
	  lwz       r5, 0x10(r7)
	  bl        -0x2044
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r4, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r4)
	  addi      r6, r3, 0xE30
	  lis       r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        -0x2070
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r4, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r4)
	  li        r0, 0x1
	  addi      r6, r3, 0xE30
	  stw       r0, 0x32CC(r13)
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        -0x20A4
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  addi      r4, r3, 0xE30
	  li        r3, 0
	  bl        -0x2030
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  addi      r4, r3, 0xE30
	  lis       r3, 0x1
	  bl        -0x2054
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  addi      r4, r3, 0xE30
	  lis       r3, 0x2
	  bl        -0x2078
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  addi      r4, r3, 0xE30
	  lis       r3, 0x3
	  bl        -0x209C
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r4, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r4)
	  addi      r5, r3, 0xE30
	  lwz       r3, 0x10(r7)
	  lwz       r4, 0x14(r7)
	  bl        -0x2038
	  b         .loc_0x2B0
	  lis       r3, 0xCC00
	  lwz       r0, 0x6004(r3)
	  addi      r5, r3, 0x6000
	  lis       r3, 0x8020
	  stw       r0, 0x4(r5)
	  li        r0, 0x20
	  addi      r4, r3, 0xE30
	  stw       r0, 0x1C(r7)
	  lwz       r3, 0x18(r7)
	  bl        -0x2224

	.loc_0x2B0:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80200E30
 * Size:	0005D4
 */
void cbForStateBusy(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  lis       r4, 0x803D
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0x3100
	  stw       r30, 0x10(r1)
	  bne-      .loc_0x4C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x1294
	  bl        0xA60
	  li        r3, 0
	  bl        -0x1340
	  b         .loc_0x5BC

	.loc_0x4C:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x3
	  beq-      .loc_0x64
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xF
	  bne-      .loc_0x14C

	.loc_0x64:
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x94
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4567
	  bl        0x124C
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x23DC
	  b         .loc_0x5BC

	.loc_0x94:
	  li        r0, 0
	  stw       r0, 0x32EC(r13)
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xF
	  bne-      .loc_0xB0
	  li        r0, 0x1
	  stw       r0, 0x32F0(r13)

	.loc_0xB0:
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  li        r0, 0x7
	  lwz       r30, 0x32B8(r13)
	  stw       r0, 0x32E0(r13)
	  addi      r3, r31, 0x80
	  li        r0, 0
	  stw       r0, 0x32D8(r13)
	  li        r0, 0xA
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r30)
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0xFC
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, -0x3
	  blrl

	.loc_0xFC:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x118
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, 0
	  blrl

	.loc_0x118:
	  bl        -0x620
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r0, 0

	.loc_0x128:
	  cmpwi     r0, 0
	  bne-      .loc_0x5BC
	  lwz       r4, 0x32B8(r13)
	  li        r0, 0x7
	  lis       r3, 0x8020
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x844
	  bl        -0x2564
	  b         .loc_0x5BC

	.loc_0x14C:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x17C
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x4
	  beq-      .loc_0x17C
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x17C
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x1A0

	.loc_0x17C:
	  lwz       r6, 0x32B8(r13)
	  lis       r4, 0xCC00
	  addi      r4, r4, 0x6000
	  lwz       r4, 0x18(r4)
	  lwz       r0, 0x1C(r6)
	  lwz       r5, 0x20(r6)
	  sub       r0, r0, r4
	  add       r0, r5, r0
	  stw       r0, 0x20(r6)

	.loc_0x1A0:
	  rlwinm.   r0,r3,0,28,28
	  beq-      .loc_0x204
	  lwz       r30, 0x32B8(r13)
	  addi      r3, r31, 0x80
	  li        r0, 0
	  stw       r0, 0x32D8(r13)
	  li        r0, 0xA
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r30)
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0x1E0
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, -0x3
	  blrl

	.loc_0x1E0:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x1FC
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, 0
	  blrl

	.loc_0x1FC:
	  bl        -0x704
	  b         .loc_0x5BC

	.loc_0x204:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x48C
	  li        r4, 0
	  stw       r4, 0x32EC(r13)
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x27C
	  stw       r4, 0x32E0(r13)
	  addi      r3, r31, 0x80
	  lwz       r30, 0x32B8(r13)
	  li        r0, 0xA
	  stw       r4, 0x32D8(r13)
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r30)
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0x258
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, -0x3
	  blrl

	.loc_0x258:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x274
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, 0
	  blrl

	.loc_0x274:
	  bl        -0x77C
	  li        r4, 0x1

	.loc_0x27C:
	  cmpwi     r4, 0
	  bne-      .loc_0x5BC
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x2B4
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x4
	  beq-      .loc_0x2B4
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x2B4
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x304

	.loc_0x2B4:
	  lwz       r3, 0x32B8(r13)
	  lwz       r4, 0x20(r3)
	  lwz       r0, 0x14(r3)
	  cmplw     r4, r0
	  beq-      .loc_0x2D0
	  bl        -0x588
	  b         .loc_0x5BC

	.loc_0x2D0:
	  addi      r0, r31, 0x80
	  stw       r0, 0x32B8(r13)
	  li        r0, 0
	  addi      r4, r3, 0
	  stw       r0, 0xC(r3)
	  lwz       r12, 0x28(r3)
	  cmplwi    r12, 0
	  beq-      .loc_0x2FC
	  lwz       r3, 0x20(r4)
	  mtlr      r12
	  blrl

	.loc_0x2FC:
	  bl        -0x804
	  b         .loc_0x5BC

	.loc_0x304:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x9
	  beq-      .loc_0x334
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xA
	  beq-      .loc_0x334
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x334
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xC
	  bne-      .loc_0x398

	.loc_0x334:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x34C
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xA
	  bne-      .loc_0x35C

	.loc_0x34C:
	  lis       r3, 0xCC00
	  lwz       r0, 0x6020(r3)
	  rlwinm    r3,r0,2,0,29
	  b         .loc_0x368

	.loc_0x35C:
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6000
	  lwz       r3, 0x20(r3)

	.loc_0x368:
	  lwz       r4, 0x32B8(r13)
	  addi      r5, r31, 0x80
	  li        r0, 0
	  stw       r5, 0x32B8(r13)
	  stw       r0, 0xC(r4)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x390
	  mtlr      r12
	  blrl

	.loc_0x390:
	  bl        -0x898
	  b         .loc_0x5BC

	.loc_0x398:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x6
	  bne-      .loc_0x458
	  lwz       r4, 0x32B8(r13)
	  addi      r5, r4, 0x1C
	  lwz       r0, 0x1C(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x428
	  lis       r3, 0xCC00
	  lwz       r0, 0x6020(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x3F8
	  addi      r0, r31, 0x80
	  stw       r0, 0x32B8(r13)
	  li        r0, 0x9
	  stw       r0, 0xC(r4)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x3F0
	  mtlr      r12
	  li        r3, -0x2
	  blrl

	.loc_0x3F0:
	  bl        -0x8F8
	  b         .loc_0x5BC

	.loc_0x3F8:
	  li        r0, 0
	  stw       r0, 0x32CC(r13)
	  li        r0, 0x1
	  lis       r3, 0x8020
	  stw       r0, 0x0(r5)
	  addi      r6, r3, 0xE30
	  li        r3, 0
	  lwz       r5, 0x32B8(r13)
	  lwz       r4, 0x14(r5)
	  lwz       r5, 0x10(r5)
	  bl        -0x25BC
	  b         .loc_0x5BC

	.loc_0x428:
	  addi      r0, r31, 0x80
	  stw       r0, 0x32B8(r13)
	  li        r0, 0
	  stw       r0, 0xC(r4)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x450
	  mtlr      r12
	  li        r3, 0
	  blrl

	.loc_0x450:
	  bl        -0x958
	  b         .loc_0x5BC

	.loc_0x458:
	  lwz       r4, 0x32B8(r13)
	  addi      r3, r31, 0x80
	  li        r0, 0
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r4)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x484
	  mtlr      r12
	  li        r3, 0
	  blrl

	.loc_0x484:
	  bl        -0x98C
	  b         .loc_0x5BC

	.loc_0x48C:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x4C0
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4567
	  bl        0xE20
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x2808
	  b         .loc_0x5BC

	.loc_0x4C0:
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x4F0
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x4
	  beq-      .loc_0x4F0
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x4F0
	  lwz       r0, 0x32D4(r13)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x5B0

	.loc_0x4F0:
	  lwz       r30, 0x32B8(r13)
	  lwz       r3, 0x20(r30)
	  lwz       r0, 0x14(r30)
	  cmplw     r3, r0
	  bne-      .loc_0x5B0
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x570
	  li        r4, 0
	  stw       r4, 0x32E0(r13)
	  addi      r3, r31, 0x80
	  li        r0, 0xA
	  stw       r4, 0x32D8(r13)
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r30)
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0x548
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, -0x3
	  blrl

	.loc_0x548:
	  lwz       r12, 0x32DC(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x564
	  mtlr      r12
	  addi      r4, r30, 0
	  li        r3, 0
	  blrl

	.loc_0x564:
	  bl        -0xA6C
	  li        r0, 0x1
	  b         .loc_0x574

	.loc_0x570:
	  li        r0, 0

	.loc_0x574:
	  cmpwi     r0, 0
	  bne-      .loc_0x5BC
	  lwz       r4, 0x32B8(r13)
	  addi      r3, r31, 0x80
	  li        r0, 0
	  stw       r3, 0x32B8(r13)
	  stw       r0, 0xC(r4)
	  lwz       r12, 0x28(r4)
	  cmplwi    r12, 0
	  beq-      .loc_0x5A8
	  lwz       r3, 0x20(r4)
	  mtlr      r12
	  blrl

	.loc_0x5A8:
	  bl        -0xAB0
	  b         .loc_0x5BC

	.loc_0x5B0:
	  lis       r3, 0x8020
	  subi      r3, r3, 0x2AC
	  bl        -0x287C

	.loc_0x5BC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80201404
 * Size:	0000BC
 */
void issueCommand(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x2A18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  lwz       r3, 0x8(r30)
	  cmplwi    r3, 0x1
	  beq-      .loc_0x4C
	  subi      r0, r3, 0x4
	  cmplwi    r0, 0x1
	  ble-      .loc_0x4C
	  cmplwi    r3, 0xE
	  bne-      .loc_0x58

	.loc_0x4C:
	  lwz       r3, 0x18(r30)
	  lwz       r4, 0x14(r30)
	  bl        -0xA8A0

	.loc_0x58:
	  bl        -0x84E0
	  li        r0, 0x2
	  stw       r0, 0xC(r30)
	  addi      r31, r3, 0
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0xAC8
	  lwz       r0, 0x32B8(r13)
	  addi      r30, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  lwz       r0, 0x32C4(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x94
	  bl        -0xB6C

	.loc_0x94:
	  mr        r3, r31
	  bl        -0x84F8
	  lwz       r0, 0x24(r1)
	  mr        r3, r30
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802014C0
 * Size:	0000DC
 */
void DVDReadAbsAsyncPrio(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r8, 0
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r4, 0x18(r3)
	  stw       r5, 0x14(r3)
	  stw       r6, 0x10(r3)
	  stw       r0, 0x20(r3)
	  stw       r7, 0x28(r3)
	  lwz       r0, 0x2A18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x78
	  lwz       r3, 0x8(r29)
	  cmplwi    r3, 0x1
	  beq-      .loc_0x6C
	  subi      r0, r3, 0x4
	  cmplwi    r0, 0x1
	  ble-      .loc_0x6C
	  cmplwi    r3, 0xE
	  bne-      .loc_0x78

	.loc_0x6C:
	  lwz       r3, 0x18(r29)
	  lwz       r4, 0x14(r29)
	  bl        -0xA97C

	.loc_0x78:
	  bl        -0x85BC
	  li        r0, 0x2
	  stw       r0, 0xC(r29)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x9EC
	  lwz       r0, 0x32B8(r13)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0xB4
	  lwz       r0, 0x32C4(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xB4
	  bl        -0xC48

	.loc_0xB4:
	  mr        r3, r30
	  bl        -0x85D4
	  lwz       r0, 0x3C(r1)
	  mr        r3, r31
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  mtlr      r0
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void DVDSeekAbsAsyncPrio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020159C
 * Size:	0000D0
 */
void DVDReadAbsAsyncForBS(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x4
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x28(r1)
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r4, 0x18(r3)
	  stw       r5, 0x14(r3)
	  stw       r6, 0x10(r3)
	  stw       r0, 0x20(r3)
	  stw       r7, 0x28(r3)
	  lwz       r0, 0x2A18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x70
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0x1
	  beq-      .loc_0x64
	  subi      r0, r3, 0x4
	  cmplwi    r0, 0x1
	  ble-      .loc_0x64
	  cmplwi    r3, 0xE
	  bne-      .loc_0x70

	.loc_0x64:
	  lwz       r3, 0x18(r31)
	  lwz       r4, 0x14(r31)
	  bl        -0xAA50

	.loc_0x70:
	  bl        -0x8690
	  li        r0, 0x2
	  stw       r0, 0xC(r31)
	  addi      r30, r3, 0
	  addi      r4, r31, 0
	  li        r3, 0x2
	  bl        0x918
	  lwz       r0, 0x32B8(r13)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0xAC
	  lwz       r0, 0x32C4(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xAC
	  bl        -0xD1C

	.loc_0xAC:
	  mr        r3, r30
	  bl        -0x86A8
	  lwz       r0, 0x34(r1)
	  mr        r3, r31
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  mtlr      r0
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020166C
 * Size:	0000D4
 */
void DVDReadDiskID(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x5
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  stw       r0, 0x8(r3)
	  li        r3, 0x20
	  li        r0, 0
	  stw       r4, 0x18(r31)
	  stw       r3, 0x14(r31)
	  stw       r0, 0x10(r31)
	  stw       r0, 0x20(r31)
	  stw       r5, 0x28(r31)
	  lwz       r0, 0x2A18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x74
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0x1
	  beq-      .loc_0x68
	  subi      r0, r3, 0x4
	  cmplwi    r0, 0x1
	  ble-      .loc_0x68
	  cmplwi    r3, 0xE
	  bne-      .loc_0x74

	.loc_0x68:
	  lwz       r3, 0x18(r31)
	  lwz       r4, 0x14(r31)
	  bl        -0xAB24

	.loc_0x74:
	  bl        -0x8764
	  li        r0, 0x2
	  stw       r0, 0xC(r31)
	  addi      r30, r3, 0
	  addi      r4, r31, 0
	  li        r3, 0x2
	  bl        0x844
	  lwz       r0, 0x32B8(r13)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0xB0
	  lwz       r0, 0x32C4(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xB0
	  bl        -0xDF0

	.loc_0xB0:
	  mr        r3, r30
	  bl        -0x877C
	  lwz       r0, 0x2C(r1)
	  mr        r3, r31
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80201740
 * Size:	0000C4
 */
void DVDPrepareStreamAbsAsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x6
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  stw       r0, 0x8(r3)
	  stw       r4, 0x14(r3)
	  stw       r5, 0x10(r3)
	  stw       r6, 0x28(r3)
	  lwz       r0, 0x2A18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x64
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0x1
	  beq-      .loc_0x58
	  subi      r0, r3, 0x4
	  cmplwi    r0, 0x1
	  ble-      .loc_0x58
	  cmplwi    r3, 0xE
	  bne-      .loc_0x64

	.loc_0x58:
	  lwz       r3, 0x18(r31)
	  lwz       r4, 0x14(r31)
	  bl        -0xABE8

	.loc_0x64:
	  bl        -0x8828
	  li        r0, 0x2
	  stw       r0, 0xC(r31)
	  addi      r30, r3, 0
	  addi      r4, r31, 0
	  li        r3, 0x1
	  bl        0x780
	  lwz       r0, 0x32B8(r13)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0xA0
	  lwz       r0, 0x32C4(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xA0
	  bl        -0xEB4

	.loc_0xA0:
	  mr        r3, r30
	  bl        -0x8840
	  lwz       r0, 0x2C(r1)
	  mr        r3, r31
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDCancelStreamAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201804
 * Size:	0000A0
 */
void DVDCancelStream(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x7
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x8020
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x18A4
	  addi      r4, r30, 0
	  stw       r0, 0x28(r30)
	  li        r3, 0x1
	  bl        -0x434
	  cmpwi     r3, 0
	  bne-      .loc_0x48
	  li        r3, -0x1
	  b         .loc_0x88

	.loc_0x48:
	  bl        -0x88D0
	  mr        r31, r3

	.loc_0x50:
	  lwz       r3, 0xC(r30)
	  addi      r0, r3, 0x1
	  cmplwi    r0, 0x1
	  ble-      .loc_0x68
	  cmpwi     r3, 0xA
	  bne-      .loc_0x70

	.loc_0x68:
	  lwz       r30, 0x20(r30)
	  b         .loc_0x7C

	.loc_0x70:
	  addi      r3, r13, 0x32B0
	  bl        -0x4EBC
	  b         .loc_0x50

	.loc_0x7C:
	  mr        r3, r31
	  bl        -0x88E0
	  mr        r3, r30

	.loc_0x88:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802018A4
 * Size:	000028
 */
void cbForCancelStreamSync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stw       r3, 0x20(r4)
	  addi      r3, r13, 0x32B0
	  bl        -0x4E10
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDStopStreamAtEndAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDStopStreamAtEnd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForStopStreamAtEndSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamErrorStatusAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamErrorStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamErrorStatusSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamPlayAddrAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamPlayAddr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamPlayAddrSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamStartAddrAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamStartAddr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamStartAddrSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamLengthAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamLength(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamLengthSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void __DVDAudioBufferConfig(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDChangeDiskAsyncForBS(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void DVDChangeDiskAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void DVDChangeDisk(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void cbForChangeDiskSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void DVDInquiryAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void DVDInquiry(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void cbForInquirySync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802018CC
 * Size:	000044
 */
void DVDReset(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x2A84
	  lis       r3, 0xCC00
	  li        r0, 0x2A
	  stw       r0, 0x6000(r3)
	  addi      r4, r3, 0x6000
	  li        r0, 0
	  lwz       r3, 0x6004(r3)
	  stw       r3, 0x4(r4)
	  stw       r0, 0x32F0(r13)
	  stw       r0, 0x32E0(r13)
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
void DVDResetRequired(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void DVDGetCommandBlockStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201910
 * Size:	0000AC
 */
void DVDGetDriveStatus(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  bl        -0x89A8
	  lwz       r0, 0x32D0(r13)
	  addi      r30, r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  li        r31, -0x1
	  b         .loc_0x88

	.loc_0x30:
	  lwz       r0, 0x32C8(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x44
	  li        r31, 0x8
	  b         .loc_0x88

	.loc_0x44:
	  lwz       r31, 0x32B8(r13)
	  cmplwi    r31, 0
	  bne-      .loc_0x58
	  li        r31, 0
	  b         .loc_0x88

	.loc_0x58:
	  lis       r3, 0x803D
	  addi      r0, r3, 0x3180
	  cmplw     r31, r0
	  bne-      .loc_0x70
	  li        r31, 0
	  b         .loc_0x88

	.loc_0x70:
	  bl        -0x8A04
	  lwz       r31, 0xC(r31)
	  cmpwi     r31, 0x3
	  bne-      .loc_0x84
	  li        r31, 0x1

	.loc_0x84:
	  bl        -0x89F0

	.loc_0x88:
	  mr        r3, r30
	  bl        -0x89F8
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
void DVDSetAutoInvalidation(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void DVDPause(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void DVDResume(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802019BC
 * Size:	000270
 */
void DVDCancelAsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x8A60
	  lwz       r4, 0xC(r29)
	  addi      r31, r3, 0
	  addi      r0, r4, 0x1
	  cmplwi    r0, 0xC
	  bgt-      .loc_0x248
	  lis       r3, 0x802F
	  subi      r3, r3, 0x773C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  cmplwi    r30, 0
	  beq-      .loc_0x248
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r4, r29, 0
	  li        r3, 0
	  blrl
	  b         .loc_0x248
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  mr        r3, r31
	  bl        -0x8A98
	  li        r3, 0
	  b         .loc_0x254

	.loc_0x8C:
	  li        r0, 0x1
	  stw       r30, 0x32DC(r13)
	  stw       r0, 0x32D8(r13)
	  lwz       r0, 0x8(r29)
	  cmplwi    r0, 0x4
	  beq-      .loc_0xAC
	  cmplwi    r0, 0x1
	  bne-      .loc_0x248

	.loc_0xAC:
	  bl        -0x2B58
	  b         .loc_0x248
	  mr        r3, r29
	  bl        0x628
	  li        r0, 0xA
	  stw       r0, 0xC(r29)
	  lwz       r12, 0x28(r29)
	  cmplwi    r12, 0
	  beq-      .loc_0xE0
	  mtlr      r12
	  addi      r4, r29, 0
	  li        r3, -0x3
	  blrl

	.loc_0xE0:
	  cmplwi    r30, 0
	  beq-      .loc_0x248
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r4, r29, 0
	  li        r3, 0
	  blrl
	  b         .loc_0x248
	  lwz       r0, 0x8(r29)
	  cmpwi     r0, 0xD
	  beq-      .loc_0x130
	  bge-      .loc_0x124
	  cmpwi     r0, 0x6
	  bge-      .loc_0x150
	  cmpwi     r0, 0x4
	  bge-      .loc_0x130
	  b         .loc_0x150

	.loc_0x124:
	  cmpwi     r0, 0xF
	  beq-      .loc_0x130
	  b         .loc_0x150

	.loc_0x130:
	  cmplwi    r30, 0
	  beq-      .loc_0x248
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r4, r29, 0
	  li        r3, 0
	  blrl
	  b         .loc_0x248

	.loc_0x150:
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x16C
	  mr        r3, r31
	  bl        -0x8B78
	  li        r3, 0
	  b         .loc_0x254

	.loc_0x16C:
	  li        r0, 0x1
	  stw       r30, 0x32DC(r13)
	  stw       r0, 0x32D8(r13)
	  b         .loc_0x248
	  bl        -0x2C14
	  lis       r4, 0x8020
	  addi      r0, r4, 0x844
	  cmplw     r3, r0
	  beq-      .loc_0x1A0
	  mr        r3, r31
	  bl        -0x8BAC
	  li        r3, 0
	  b         .loc_0x254

	.loc_0x1A0:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x1B4
	  li        r0, 0x3
	  stw       r0, 0x32E0(r13)

	.loc_0x1B4:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0x5
	  bne-      .loc_0x1C8
	  li        r0, 0x4
	  stw       r0, 0x32E0(r13)

	.loc_0x1C8:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0x6
	  bne-      .loc_0x1DC
	  li        r0, 0x1
	  stw       r0, 0x32E0(r13)

	.loc_0x1DC:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0xB
	  bne-      .loc_0x1F0
	  li        r0, 0x2
	  stw       r0, 0x32E0(r13)

	.loc_0x1F0:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0x7
	  bne-      .loc_0x204
	  li        r0, 0x7
	  stw       r0, 0x32E0(r13)

	.loc_0x204:
	  li        r0, 0xA
	  stw       r0, 0xC(r29)
	  lwz       r12, 0x28(r29)
	  cmplwi    r12, 0
	  beq-      .loc_0x228
	  mtlr      r12
	  addi      r4, r29, 0
	  li        r3, -0x3
	  blrl

	.loc_0x228:
	  cmplwi    r30, 0
	  beq-      .loc_0x244
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r4, r29, 0
	  li        r3, 0
	  blrl

	.loc_0x244:
	  bl        -0x12D8

	.loc_0x248:
	  mr        r3, r31
	  bl        -0x8C64
	  li        r3, 0x1

	.loc_0x254:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80201C2C
 * Size:	0000AC
 */
void DVDCancel(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x1CD8
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x290
	  cmpwi     r3, 0
	  bne-      .loc_0x34
	  li        r3, -0x1
	  b         .loc_0x94

	.loc_0x34:
	  bl        -0x8CE4
	  mr        r31, r3

	.loc_0x3C:
	  lwz       r3, 0xC(r30)
	  addi      r0, r3, 0x1
	  cmplwi    r0, 0x1
	  ble-      .loc_0x88
	  cmpwi     r3, 0xA
	  beq-      .loc_0x88
	  cmpwi     r3, 0x3
	  bne-      .loc_0x7C
	  lwz       r3, 0x8(r30)
	  subi      r0, r3, 0x4
	  cmplwi    r0, 0x1
	  ble-      .loc_0x88
	  cmplwi    r3, 0xD
	  beq-      .loc_0x88
	  cmplwi    r3, 0xF
	  beq-      .loc_0x88

	.loc_0x7C:
	  addi      r3, r13, 0x32B0
	  bl        -0x52F0
	  b         .loc_0x3C

	.loc_0x88:
	  mr        r3, r31
	  bl        -0x8D14
	  li        r3, 0

	.loc_0x94:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80201CD8
 * Size:	000024
 */
void cbForCancelSync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r13, 0x32B0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x5240
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void DVDCancelAllAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void DVDCancelAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void cbForCancelAllSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201CFC
 * Size:	000008
 */
void DVDGetCurrentDiskID(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x8000
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80201D04
 * Size:	0000E4
 */
void DVDCheckDisk(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        -0x8D98
	  lwz       r0, 0x32D0(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  li        r4, -0x1
	  b         .loc_0x6C

	.loc_0x28:
	  lwz       r0, 0x32C8(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x3C
	  li        r4, 0x8
	  b         .loc_0x6C

	.loc_0x3C:
	  lwz       r5, 0x32B8(r13)
	  cmplwi    r5, 0
	  bne-      .loc_0x50
	  li        r4, 0
	  b         .loc_0x6C

	.loc_0x50:
	  lis       r4, 0x803D
	  addi      r0, r4, 0x3180
	  cmplw     r5, r0
	  bne-      .loc_0x68
	  li        r4, 0
	  b         .loc_0x6C

	.loc_0x68:
	  lwz       r4, 0xC(r5)

	.loc_0x6C:
	  addi      r0, r4, 0x1
	  cmplwi    r0, 0xC
	  bgt-      .loc_0xC8
	  lis       r4, 0x802F
	  subi      r4, r4, 0x7708
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  li        r31, 0x1
	  b         .loc_0xC8
	  li        r31, 0
	  b         .loc_0xC8
	  lis       r4, 0xCC00
	  addi      r4, r4, 0x6000
	  lwz       r4, 0x4(r4)
	  rlwinm.   r0,r4,30,31,31
	  bne-      .loc_0xBC
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0xC4

	.loc_0xBC:
	  li        r31, 0
	  b         .loc_0xC8

	.loc_0xC4:
	  li        r31, 0x1

	.loc_0xC8:
	  bl        -0x8E28
	  lwz       r0, 0x14(r1)
	  mr        r3, r31
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80201DE8
 * Size:	00011C
 */
void __DVDPrepareResetAsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  stw       r29, 0x14(r1)
	  bl        -0x8E88
	  mr        r29, r3
	  bl        .loc_0x11C
	  lwz       r0, 0x32D8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  stw       r30, 0x32DC(r13)
	  b         .loc_0xF8

	.loc_0x3C:
	  lwz       r3, 0x32B8(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  li        r0, 0
	  stw       r0, 0x28(r3)

	.loc_0x50:
	  bl        -0x8EBC
	  mr        r31, r3
	  bl        -0x8EC4
	  lwz       r0, 0x32B8(r13)
	  li        r4, 0x1
	  stw       r4, 0x32C4(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x74
	  stw       r4, 0x32C8(r13)

	.loc_0x74:
	  bl        -0x8EB8
	  b         .loc_0x84

	.loc_0x7C:
	  li        r4, 0
	  bl        -0x4AC

	.loc_0x84:
	  bl        0x138
	  cmplwi    r3, 0
	  bne+      .loc_0x7C
	  lwz       r3, 0x32B8(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  mr        r4, r30
	  bl        -0x4CC
	  b         .loc_0xC4

	.loc_0xA8:
	  cmplwi    r30, 0
	  beq-      .loc_0xC4
	  addi      r12, r30, 0
	  mtlr      r12
	  li        r3, 0
	  li        r4, 0
	  blrl

	.loc_0xC4:
	  bl        -0x8F30
	  li        r4, 0
	  stw       r4, 0x32C4(r13)
	  mr        r30, r3
	  lwz       r0, 0x32C8(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xE8
	  stw       r4, 0x32C8(r13)
	  bl        -0x15A4

	.loc_0xE8:
	  mr        r3, r30
	  bl        -0x8F30
	  mr        r3, r31
	  bl        -0x8F38

	.loc_0xF8:
	  mr        r3, r29
	  bl        -0x8F40
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr

	.loc_0x11C:
	*/
}
