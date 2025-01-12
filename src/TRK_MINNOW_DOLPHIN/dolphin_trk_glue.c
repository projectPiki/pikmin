#include "types.h"

/*
 * --INFO--
 * Address:	80220460
 * Size:	000088
 */
void TRKLoadContext(void)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  lwz       r1, 0x4(r3)
	  lwz       r2, 0x8(r3)
	  lhz       r5, 0x1A2(r3)
	  rlwinm.   r6,r5,0,30,30
	  beq-      .loc_0x28
	  rlwinm    r5,r5,0,31,29
	  sth       r5, 0x1A2(r3)
	  lmw       r5, 0x14(r3)
	  b         .loc_0x2C

	.loc_0x28:
	  lmw       r13, 0x34(r3)

	.loc_0x2C:
	  mr        r31, r3
	  mr        r3, r4
	  lwz       r4, 0x80(r31)
	  mtcr      r4
	  lwz       r4, 0x84(r31)
	  mtlr      r4
	  lwz       r4, 0x88(r31)
	  mtctr     r4
	  lwz       r4, 0x8C(r31)
	  mtxer     r4
	  mfmsr     r4
	  rlwinm    r4,r4,0,17,15
	  rlwinm    r4,r4,0,31,29
	  mtmsr     r4
	  mtsprg    1, r2
	  lwz       r4, 0xC(r31)
	  mtsprg    2, r4
	  lwz       r4, 0x10(r31)
	  mtsprg    3, r4
	  lwz       r2, 0x198(r31)
	  lwz       r4, 0x19C(r31)
	  lwz       r31, 0x7C(r31)
	  b         -0x12C0
	*/
}

/*
 * --INFO--
 * Address:	802204E8
 * Size:	000038
 */
void TRKEXICallBack(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  mr        r31, r4
	  bl        -0x24998
	  mr        r3, r31
	  li        r4, 0x500
	  bl        -0xA8
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220520
 * Size:	0000E8
 */
void InitMetroTRKCommTable(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  cmpwi     r3, 0x1
	  bne-      .loc_0x78
	  bl        0x1A24
	  lis       r5, 0x8022
	  lis       r4, 0x802F
	  addi      r0, r5, 0x1AFC
	  subi      r5, r4, 0x6A10
	  lis       r4, 0x8022
	  stw       r0, 0x0(r5)
	  addi      r0, r4, 0x1B74
	  lis       r4, 0x8022
	  stw       r0, 0x4(r5)
	  addi      r0, r4, 0x1BC8
	  lis       r4, 0x8022
	  stw       r0, 0x8(r5)
	  addi      r0, r4, 0x1C64
	  lis       r4, 0x8022
	  stw       r0, 0xC(r5)
	  addi      r0, r4, 0x1CF0
	  lis       r4, 0x8022
	  stw       r0, 0x10(r5)
	  addi      r0, r4, 0x1F50
	  lis       r4, 0x8022
	  stw       r0, 0x14(r5)
	  addi      r0, r4, 0x1F54
	  stw       r0, 0x18(r5)
	  b         .loc_0xD8

	.loc_0x78:
	  bl        0xF38
	  lis       r5, 0x8022
	  lis       r4, 0x802F
	  addi      r0, r5, 0xE6C
	  subi      r5, r4, 0x6A10
	  lis       r4, 0x8022
	  stw       r0, 0x0(r5)
	  addi      r0, r4, 0xF28
	  lis       r4, 0x8022
	  stw       r0, 0x4(r5)
	  addi      r0, r4, 0xF54
	  lis       r4, 0x8022
	  stw       r0, 0x8(r5)
	  addi      r0, r4, 0x105C
	  lis       r4, 0x8022
	  stw       r0, 0xC(r5)
	  addi      r0, r4, 0x1318
	  lis       r4, 0x8022
	  stw       r0, 0x10(r5)
	  addi      r0, r4, 0x14C8
	  lis       r4, 0x8022
	  stw       r0, 0x14(r5)
	  addi      r0, r4, 0x14CC
	  stw       r0, 0x18(r5)

	.loc_0xD8:
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220608
 * Size:	000004
 */
void TRKUARTInterruptHandler(void)
{
}

/*
 * --INFO--
 * Address:	8022060C
 * Size:	000040
 */
void TRKInitializeIntDrivenUART(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6A10
	  lis       r4, 0x8022
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x4E8
	  mr        r3, r6
	  mtlr      r12
	  blrl
	  li        r3, 0
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8022064C
 * Size:	000030
 */
void EnableEXI2Interrupts(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6A10
	  lwz       r12, 0x4(r3)
	  mtlr      r12
	  blrl
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8022067C
 * Size:	000030
 */
void TRKPollUART(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6A10
	  lwz       r12, 0x8(r3)
	  mtlr      r12
	  blrl
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802206AC
 * Size:	000044
 */
void TRKReadUARTN(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r5, 0x802F
	  subi      r5, r5, 0x6A10
	  lwz       r12, 0xC(r5)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x34

	.loc_0x30:
	  li        r3, -0x1

	.loc_0x34:
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802206F0
 * Size:	000044
 */
void TRKWriteUARTN(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r5, 0x802F
	  subi      r5, r5, 0x6A10
	  lwz       r12, 0x10(r5)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x34

	.loc_0x30:
	  li        r3, -0x1

	.loc_0x34:
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void WriteUARTFlush(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void WriteUART1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void TRKReadUARTPoll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80220734
 * Size:	000030
 */
void ReserveEXI2Port(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6A10
	  lwz       r12, 0x14(r3)
	  mtlr      r12
	  blrl
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220764
 * Size:	000030
 */
void UnreserveEXI2Port(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6A10
	  lwz       r12, 0x18(r3)
	  mtlr      r12
	  blrl
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220794
 * Size:	000024
 */
void TRK_board_display(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  crclr     6, 0x6
	  bl        -0x28F14
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
