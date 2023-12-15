#include "serpoll.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void TRKDiscardFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void TRKRejectFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CD14
 * Size:	0000D0
 */
void TRKTestForPacket(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  bl        0x3954
	  mr.       r30, r3
	  ble-      .loc_0xA4
	  addi      r3, r1, 0x8
	  addi      r4, r1, 0xC
	  bl        -0x7F0
	  cmpwi     r30, 0x880
	  ble-      .loc_0x7C
	  b         .loc_0x60

	.loc_0x38:
	  cmpwi     r30, 0x880
	  ble-      .loc_0x48
	  li        r31, 0x880
	  b         .loc_0x4C

	.loc_0x48:
	  mr        r31, r30

	.loc_0x4C:
	  lwz       r3, 0xC(r1)
	  addi      r4, r31, 0
	  addi      r3, r3, 0x10
	  bl        0x3940
	  sub       r30, r30, r31

	.loc_0x60:
	  cmpwi     r30, 0
	  bgt+      .loc_0x38
	  lwz       r3, 0xC(r1)
	  li        r4, 0xFF
	  li        r5, 0x6
	  bl        0x2D8
	  b         .loc_0xA4

	.loc_0x7C:
	  lwz       r3, 0xC(r1)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x10
	  bl        0x3910
	  cmpwi     r3, 0
	  bne-      .loc_0xA4
	  lwz       r3, 0xC(r1)
	  stw       r30, 0x8(r3)
	  lwz       r3, 0x8(r1)
	  b         .loc_0xB8

	.loc_0xA4:
	  lwz       r3, 0x8(r1)
	  cmpwi     r3, -0x1
	  beq-      .loc_0xB4
	  bl        -0x7B0

	.loc_0xB4:
	  li        r3, -0x1

	.loc_0xB8:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void TRKProcessFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CDE4
 * Size:	00007C
 */
void TRKGetInput(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  bl        -0xE4
	  addi      r30, r3, 0
	  cmpwi     r30, -0x1
	  beq-      .loc_0x64
	  mr        r3, r30
	  bl        -0x824
	  addi      r31, r3, 0
	  li        r4, 0
	  bl        -0x75C
	  addi      r3, r31, 0
	  addi      r4, r1, 0x8
	  bl        -0x3E4
	  lbz       r0, 0x8(r1)
	  cmplwi    r0, 0x80
	  bge-      .loc_0x5C
	  mr        r3, r30
	  bl        .loc_0x7C
	  b         .loc_0x64

	.loc_0x5C:
	  mr        r3, r30
	  bl        -0x830

	.loc_0x64:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr

	.loc_0x7C:
	*/
}

/*
 * --INFO--
 * Address:	8021CE60
 * Size:	000050
 */
void TRKProcessInput(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x8
	  bl        -0xBA8
	  lis       r3, 0x803D
	  stw       r31, 0x10(r1)
	  addi      r4, r3, 0x5CD0
	  addi      r3, r1, 0x8
	  li        r0, -0x1
	  stw       r0, 0x0(r4)
	  bl        -0xCA4
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021CEB0
 * Size:	000024
 */
u32 TRKInitializeSerialHandler(void)
{
	gTRKFramingState.field0_0x0 = -1;
	gTRKFramingState.field2_0x8 = 0;
	gTRKFramingState.field3_0xc = 0;
	return 0;
}

/*
 * --INFO--
 * Address:	8021CED4
 * Size:	000008
 */
s32 TRKTerminateSerialHandler(void) { return 0; }
