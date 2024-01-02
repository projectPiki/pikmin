#include "types.h"

/*
 * --INFO--
 * Address:	800086C0
 * Size:	0000A8
 */
void DSPSendCommands(u32*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  bl        0x1FF73C
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lis       r3, 0x8022
	  addi      r3, r3, 0x2040
	  crclr     6, 0x6
	  bl        0x1EF1A0
	  li        r3, -0x1
	  b         .loc_0x94

	.loc_0x3C:
	  bl        0x1FF728
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lis       r3, 0x8022
	  addi      r3, r3, 0x2074
	  crclr     6, 0x6
	  bl        0x1EF17C
	  li        r3, -0x1
	  b         .loc_0x94

	.loc_0x60:
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x88

	.loc_0x6C:
	  lwzx      r3, r28, r31
	  bl        0x1FF71C

	.loc_0x74:
	  bl        0x1FF6E0
	  cmplwi    r3, 0
	  bne+      .loc_0x74
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x4

	.loc_0x88:
	  cmplw     r30, r29
	  blt+      .loc_0x6C
	  li        r3, 0

	.loc_0x94:
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008780
 * Size:	000048
 */
void DSPReleaseHalt()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)

	.loc_0xC:
	  bl        0x1FF688
	  cmplwi    r3, 0
	  bne+      .loc_0xC
	  li        r3, 0
	  bl        0x1FF6B0
	  bl        0x1FF684
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  bl        0x1FF688

	.loc_0x30:
	  lis       r3, 0x8888
	  lwz       r0, 0xC(r1)
	  addi      r3, r3, 0x1357
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800087E0
 * Size:	000058
 */
void DSPWaitFinish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  addi      r31, r3, 0x20A8

	.loc_0x18:
	  bl        0x1FF62C
	  cmplwi    r3, 0
	  beq+      .loc_0x18
	  bl        0x1FF630
	  addis     r0, r3, 0x7778
	  cmplwi    r0, 0x1357
	  bne-      .loc_0x44
	  addi      r3, r31, 0
	  crclr     6, 0x6
	  bl        0x1EF074
	  b         .loc_0x18

	.loc_0x44:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Dswap(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Dmix(u32, u32, u32, s16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Dcopy(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DloadBuffer1(u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DloadBuffer(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DsaveBuffer(u16, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DsetLoopState(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void DadpcmDec(u32, u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void DloadFilter(u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DcopyfromARAM(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DoscStart(u8, u16, u16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void DoscStop(u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DoscStore(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Dmixer(u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Dresampletest()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Dadpcmtest(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80008840
 * Size:	000048
 */
void DsetupTable(u32, u32, u32, u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,0,16,31
	  oris      r0, r0, 0x8100
	  stwu      r1, -0x30(r1)
	  stw       r0, 0x1C(r1)
	  addi      r3, r1, 0x1C
	  stw       r4, 0x20(r1)
	  li        r4, 0x5
	  stw       r5, 0x24(r1)
	  stw       r6, 0x28(r1)
	  stw       r7, 0x2C(r1)
	  bl        -0x1B0
	  bl        -0x94
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800088A0
 * Size:	000024
 */
void DsetMixerLevel(f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lfs       f0, -0x7FD0(r2)
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  sth       r0, -0x7FF0(r13)
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800088E0
 * Size:	000048
 */
void DsyncFrame(u32, u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r6,r3,16,8,15
	  stw       r0, 0x4(r1)
	  oris      r6, r6, 0x8200
	  stwu      r1, -0x20(r1)
	  lhz       r0, -0x7FF0(r13)
	  addi      r3, r1, 0x14
	  or        r0, r6, r0
	  stw       r0, 0x14(r1)
	  stw       r4, 0x18(r1)
	  li        r4, 0x3
	  stw       r5, 0x1C(r1)
	  bl        -0x250
	  bl        -0x134
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008940
 * Size:	000034
 */
void DwaitFrame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  lis       r0, 0x8000
	  stwu      r1, -0x10(r1)
	  stw       r0, 0x8(r1)
	  addi      r3, r1, 0x8
	  bl        -0x29C
	  bl        -0x180
	  lwz       r0, 0x14(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008980
 * Size:	00003C
 */
void DiplSec(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8B00
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0x8
	  li        r4, 0x2
	  stwu      r1, -0x18(r1)
	  stw       r0, 0x10(r1)
	  stw       r3, 0x14(r1)
	  addi      r3, r1, 0x10
	  bl        -0x2E4
	  bl        -0x1C8
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800089C0
 * Size:	00003C
 */
void DagbSec(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8C00
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0x8
	  li        r4, 0x2
	  stwu      r1, -0x20(r1)
	  stw       r0, 0x18(r1)
	  stw       r3, 0x1C(r1)
	  addi      r3, r1, 0x18
	  bl        -0x324
	  bl        -0x208
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
