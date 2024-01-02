#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GXOverflowHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GXUnderflowHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void GXBreakPointHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020EB40
 * Size:	00013C
 */
void GXCPInterruptHandler(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2E0(r1)
	  stw       r31, 0x2DC(r1)
	  mr        r31, r4
	  lwz       r5, 0x3424(r13)
	  lwz       r3, 0x2A68(r13)
	  lhz       r0, 0x0(r5)
	  stw       r0, 0xC(r3)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x8(r3)
	  rlwinm.   r0,r0,29,31,31
	  beq-      .loc_0x68
	  lwz       r0, 0xC(r3)
	  rlwinm.   r0,r0,31,31,31
	  beq-      .loc_0x68
	  lwz       r3, 0x3430(r13)
	  bl        -0x125C0
	  li        r0, 0
	  stw       r0, 0x3438(r13)
	  li        r3, 0x1
	  li        r4, 0x1
	  bl        0x670
	  li        r3, 0x1
	  li        r4, 0
	  bl        0x618

	.loc_0x68:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x8(r3)
	  rlwinm.   r0,r0,30,31,31
	  beq-      .loc_0xB8
	  lwz       r0, 0xC(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0xB8
	  lwz       r5, 0x3440(r13)
	  li        r3, 0
	  li        r4, 0x1
	  addi      r0, r5, 0x1
	  stw       r0, 0x3440(r13)
	  bl        0x5E4
	  li        r3, 0x1
	  li        r4, 0
	  bl        0x624
	  li        r0, 0x1
	  lwz       r3, 0x3430(r13)
	  stw       r0, 0x3438(r13)
	  bl        -0x123A8

	.loc_0xB8:
	  lwz       r3, 0x2A68(r13)
	  lwz       r4, 0x8(r3)
	  addi      r5, r3, 0x8
	  rlwinm.   r0,r4,27,31,31
	  beq-      .loc_0x128
	  lwz       r0, 0xC(r3)
	  rlwinm.   r0,r0,28,31,31
	  beq-      .loc_0x128
	  rlwinm    r0,r4,0,27,25
	  stw       r0, 0x0(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x8(r4)
	  sth       r0, 0x2(r3)
	  lwz       r0, 0x343C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x128
	  addi      r3, r1, 0x10
	  bl        -0x17804
	  addi      r3, r1, 0x10
	  bl        -0x179D4
	  lwz       r12, 0x343C(r13)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x10
	  bl        -0x17820
	  mr        r3, r31
	  bl        -0x179F0

	.loc_0x128:
	  lwz       r0, 0x2E4(r1)
	  lwz       r31, 0x2DC(r1)
	  addi      r1, r1, 0x2E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020EC7C
 * Size:	00006C
 */
void GXInitFifoBase(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  add       r0, r31, r0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  subi      r4, r5, 0x4000
	  stw       r31, 0x0(r3)
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  stw       r5, 0x8(r3)
	  rlwinm    r5,r5,31,1,26
	  stw       r0, 0x1C(r30)
	  bl        0x9C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r5, r31, 0
	  bl        .loc_0x6C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  addi      r1, r1, 0x20
	  blr

	.loc_0x6C:
	*/
}

/*
 * --INFO--
 * Address:	8020ECE8
 * Size:	000070
 */
void GXInitFifoPtrs(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  bl        -0x15D90
	  stw       r30, 0x14(r29)
	  sub       r0, r31, r30
	  stw       r31, 0x18(r29)
	  stw       r0, 0x1C(r29)
	  lwz       r4, 0x1C(r29)
	  cmpwi     r4, 0
	  bge-      .loc_0x50
	  lwz       r0, 0x8(r29)
	  add       r0, r4, r0
	  stw       r0, 0x1C(r29)

	.loc_0x50:
	  bl        -0x15D94
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020ED58
 * Size:	00000C
 */
void GXInitFifoLimits(void)
{
	/*
	.loc_0x0:
	  stw       r4, 0xC(r3)
	  stw       r5, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020ED64
 * Size:	000110
 */
void GXSetCPUFifo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x15E00
	  lwz       r0, 0x3444(r13)
	  addi      r31, r3, 0
	  stw       r30, 0x3448(r13)
	  cmplw     r30, r0
	  bne-      .loc_0x90
	  lwz       r5, 0x0(r30)
	  li        r0, 0x1
	  lwz       r4, 0x3420(r13)
	  li        r3, 0x1
	  rlwinm    r5,r5,0,2,31
	  stw       r5, 0xC(r4)
	  li        r4, 0x1
	  lwz       r6, 0x4(r30)
	  lwz       r5, 0x3420(r13)
	  rlwinm    r6,r6,0,2,31
	  stw       r6, 0x10(r5)
	  lwz       r6, 0x18(r30)
	  lwz       r5, 0x3420(r13)
	  rlwinm    r6,r6,0,2,26
	  rlwinm    r6,r6,0,6,4
	  stw       r6, 0x14(r5)
	  stb       r0, 0x3434(r13)
	  bl        0x430
	  li        r3, 0x1
	  li        r4, 0
	  bl        0x3D8
	  li        r3, 0x1
	  bl        0x38C
	  b         .loc_0xEC

	.loc_0x90:
	  lbz       r0, 0x3434(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  li        r3, 0
	  bl        0x374
	  li        r0, 0
	  stb       r0, 0x3434(r13)

	.loc_0xAC:
	  li        r3, 0
	  li        r4, 0
	  bl        0x3A4
	  lwz       r0, 0x0(r30)
	  lwz       r3, 0x3420(r13)
	  rlwinm    r0,r0,0,2,31
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x4(r30)
	  lwz       r3, 0x3420(r13)
	  rlwinm    r0,r0,0,2,31
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x18(r30)
	  lwz       r3, 0x3420(r13)
	  rlwinm    r0,r0,0,2,26
	  rlwinm    r0,r0,0,6,4
	  stw       r0, 0x14(r3)

	.loc_0xEC:
	  sync
	  mr        r3, r31
	  bl        -0x15EB4
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
 * Address:	8020EE74
 * Size:	000178
 */
void GXSetGPFifo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x15F10
	  mr        r31, r3
	  bl        0x2C0
	  li        r3, 0
	  li        r4, 0
	  bl        0x31C
	  stw       r30, 0x3444(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x0(r30)
	  sth       r0, 0x20(r3)
	  lwz       r0, 0x4(r30)
	  lwz       r3, 0x3424(r13)
	  sth       r0, 0x24(r3)
	  lwz       r0, 0x1C(r30)
	  lwz       r3, 0x3424(r13)
	  sth       r0, 0x30(r3)
	  lwz       r0, 0x18(r30)
	  lwz       r3, 0x3424(r13)
	  sth       r0, 0x34(r3)
	  lwz       r0, 0x14(r30)
	  lwz       r3, 0x3424(r13)
	  sth       r0, 0x38(r3)
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x3424(r13)
	  sth       r0, 0x28(r3)
	  lwz       r0, 0x10(r30)
	  lwz       r3, 0x3424(r13)
	  sth       r0, 0x2C(r3)
	  lwz       r0, 0x0(r30)
	  lwz       r3, 0x3424(r13)
	  rlwinm    r0,r0,16,18,31
	  sth       r0, 0x22(r3)
	  lwz       r0, 0x4(r30)
	  lwz       r3, 0x3424(r13)
	  rlwinm    r0,r0,16,18,31
	  sth       r0, 0x26(r3)
	  lwz       r0, 0x1C(r30)
	  lwz       r3, 0x3424(r13)
	  srawi     r0, r0, 0x10
	  sth       r0, 0x32(r3)
	  lwz       r0, 0x18(r30)
	  lwz       r3, 0x3424(r13)
	  rlwinm    r0,r0,16,18,31
	  sth       r0, 0x36(r3)
	  lwz       r0, 0x14(r30)
	  lwz       r3, 0x3424(r13)
	  rlwinm    r0,r0,16,18,31
	  sth       r0, 0x3A(r3)
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x3424(r13)
	  rlwinm    r0,r0,16,16,31
	  sth       r0, 0x2A(r3)
	  lwz       r0, 0x10(r30)
	  lwz       r3, 0x3424(r13)
	  rlwinm    r0,r0,16,16,31
	  sth       r0, 0x2E(r3)
	  sync
	  lwz       r3, 0x3448(r13)
	  lwz       r0, 0x3444(r13)
	  cmplw     r3, r0
	  bne-      .loc_0x12C
	  li        r0, 0x1
	  stb       r0, 0x3434(r13)
	  li        r3, 0x1
	  li        r4, 0
	  bl        0x22C
	  li        r3, 0x1
	  bl        0x1E0
	  b         .loc_0x148

	.loc_0x12C:
	  li        r0, 0
	  stb       r0, 0x3434(r13)
	  li        r3, 0
	  li        r4, 0
	  bl        0x20C
	  li        r3, 0
	  bl        0x1C0

	.loc_0x148:
	  li        r3, 0x1
	  li        r4, 0x1
	  bl        0x244
	  bl        0x164
	  mr        r3, r31
	  bl        -0x1602C
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
 * Address:	8020EFEC
 * Size:	000020
 */
void GXSaveCPUFifo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x20
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x20:
	*/
}

/*
 * --INFO--
 * Address:	8020F00C
 * Size:	0000DC
 */
void __GXSaveCPUFifoAux(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x160A8
	  mr        r31, r3
	  bl        0x1744
	  lwz       r3, 0x3420(r13)
	  lwz       r3, 0xC(r3)
	  subis     r0, r3, 0x8000
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x3420(r13)
	  lwz       r3, 0x10(r3)
	  subis     r0, r3, 0x8000
	  stw       r0, 0x4(r30)
	  lwz       r3, 0x3420(r13)
	  lwz       r0, 0x14(r3)
	  rlwinm    r3,r0,0,6,4
	  subis     r0, r3, 0x8000
	  stw       r0, 0x18(r30)
	  lbz       r0, 0x3434(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x94
	  lwz       r4, 0x3424(r13)
	  lhz       r3, 0x3A(r4)
	  lhz       r4, 0x38(r4)
	  rlwimi    r4,r3,16,0,15
	  subis     r0, r4, 0x8000
	  stw       r0, 0x14(r30)
	  lwz       r4, 0x3424(r13)
	  lhz       r3, 0x32(r4)
	  lhz       r0, 0x30(r4)
	  rlwimi    r0,r3,16,0,15
	  stw       r0, 0x1C(r30)
	  b         .loc_0xBC

	.loc_0x94:
	  lwz       r3, 0x14(r30)
	  lwz       r0, 0x18(r30)
	  sub       r0, r0, r3
	  stw       r0, 0x1C(r30)
	  lwz       r3, 0x1C(r30)
	  cmpwi     r3, 0
	  bge-      .loc_0xBC
	  lwz       r0, 0x8(r30)
	  add       r0, r3, r0
	  stw       r0, 0x1C(r30)

	.loc_0xBC:
	  mr        r3, r31
	  bl        -0x16128
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
 * Address:	........
 * Size:	000030
 */
void GXSaveGPFifo(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GXGetGPStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void GXGetFifoStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void GXGetFifoPtrs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetFifoBase(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetFifoSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GXGetFifoLimits(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GXSetBreakPtCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void GXEnableBreakPt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GXDisableBreakPt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020F0E8
 * Size:	000044
 */
void __GXFifoInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8021
	  stw       r0, 0x4(r1)
	  subi      r4, r3, 0x14C0
	  li        r3, 0x11
	  stwu      r1, -0x8(r1)
	  bl        -0x16138
	  li        r3, 0x4000
	  bl        -0x15D64
	  bl        -0x13628
	  li        r0, 0
	  stw       r3, 0x3430(r13)
	  stw       r0, 0x3438(r13)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F12C
 * Size:	000028
 */
void __GXFifoReadEnable(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x8(r3)
	  rlwinm    r0,r0,0,0,30
	  ori       r0, r0, 0x1
	  stw       r0, 0x0(r3)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x8(r4)
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F154
 * Size:	000024
 */
void __GXFifoReadDisable(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x8(r3)
	  rlwinm    r0,r0,0,0,30
	  stw       r0, 0x0(r3)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x8(r4)
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F178
 * Size:	000044
 */
void __GXFifoLink(void)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10
	  li        r0, 0x1
	  b         .loc_0x14

	.loc_0x10:
	  li        r0, 0

	.loc_0x14:
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r0,4,0,27
	  addi      r4, r3, 0x8
	  lwz       r3, 0x8(r3)
	  rlwinm    r3,r3,0,28,26
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x8(r4)
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F1BC
 * Size:	00004C
 */
void __GXWriteFifoIntEnable(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r3,r3,2,22,29
	  rlwinm    r0,r4,3,21,28
	  addi      r6, r5, 0x8
	  lwz       r5, 0x8(r5)
	  rlwinm    r4,r5,0,30,28
	  or        r3, r4, r3
	  stw       r3, 0x0(r6)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x8
	  lwz       r3, 0x8(r3)
	  rlwinm    r3,r3,0,29,27
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x8(r4)
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F208
 * Size:	00004C
 */
void __GXWriteFifoIntReset(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r3,r3,0,24,31
	  rlwinm    r0,r4,1,23,30
	  addi      r6, r5, 0x10
	  lwz       r5, 0x10(r5)
	  rlwinm    r4,r5,0,0,30
	  or        r3, r4, r3
	  stw       r3, 0x0(r6)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x10
	  lwz       r3, 0x10(r3)
	  rlwinm    r3,r3,0,31,29
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x3424(r13)
	  lwz       r0, 0x10(r4)
	  sth       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void __GXInsaneWatermark(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void __GXCleanGPFifo(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020F254
 * Size:	00004C
 */
void GXSetCurrentGXThread(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  bl        -0x162EC
	  lwz       r30, 0x3430(r13)
	  mr        r31, r3
	  bl        -0x13790
	  stw       r3, 0x3430(r13)
	  mr        r3, r31
	  bl        -0x162DC
	  lwz       r0, 0x14(r1)
	  mr        r3, r30
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  mtlr      r0
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetCurrentGXThread(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020F2A0
 * Size:	000008
 */
void GXGetCPUFifo(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3448(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetGPFifo(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetOverflowCount(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void GXResetOverflowCount(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void GXRedirectWriteGatherPipe(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001B4
 */
void GXRestoreWriteGatherPipe(void)
{
	// UNUSED FUNCTION
}
