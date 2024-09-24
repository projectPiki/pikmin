#include "zen/Sys.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F2424
 * Size:	0001BC
 */
void zen::makePathName(const char*, const char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stmw      r27, 0x11C(r1)
	  addi      r30, r4, 0
	  addi      r27, r3, 0
	  addi      r28, r5, 0
	  addi      r3, r30, 0
	  bl        0x26FC8
	  addi      r4, r1, 0x18
	  li        r29, 0
	  b         .loc_0x3C

	.loc_0x30:
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  addi      r29, r29, 0x1

	.loc_0x3C:
	  sub       r5, r3, r29
	  subic.    r0, r5, 0x1
	  blt-      .loc_0x58
	  subi      r0, r5, 0x1
	  lbzx      r0, r30, r0
	  cmplwi    r0, 0x2F
	  bne+      .loc_0x30

	.loc_0x58:
	  addi      r30, r1, 0x18
	  li        r0, 0
	  stbx      r0, r30, r29
	  mr        r3, r27
	  stb       r0, 0x0(r28)
	  bl        0x26F7C
	  addi      r31, r3, 0
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        0x26E48
	  cmpwi     r29, 0
	  li        r4, 0
	  ble-      .loc_0x18C
	  cmpwi     r29, 0x8
	  subi      r3, r29, 0x8
	  ble-      .loc_0x19C
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  add       r3, r28, r31
	  ble-      .loc_0x19C

	.loc_0xB0:
	  sub       r5, r29, r4
	  subi      r0, r5, 0x1
	  lbzx      r6, r30, r0
	  addi      r0, r4, 0x1
	  sub       r5, r29, r0
	  stb       r6, 0x0(r3)
	  subi      r5, r5, 0x1
	  addi      r0, r4, 0x2
	  lbzx      r6, r30, r5
	  sub       r5, r29, r0
	  addi      r0, r4, 0x3
	  stb       r6, 0x1(r3)
	  subi      r6, r5, 0x1
	  sub       r5, r29, r0
	  lbzx      r7, r30, r6
	  addi      r0, r4, 0x4
	  sub       r6, r29, r0
	  stb       r7, 0x2(r3)
	  subi      r5, r5, 0x1
	  addi      r0, r4, 0x5
	  lbzx      r8, r30, r5
	  sub       r7, r29, r0
	  subi      r6, r6, 0x1
	  stb       r8, 0x3(r3)
	  addi      r5, r4, 0x6
	  addi      r0, r4, 0x7
	  lbzx      r8, r30, r6
	  sub       r6, r29, r5
	  sub       r5, r29, r0
	  stb       r8, 0x4(r3)
	  subi      r0, r7, 0x1
	  subi      r6, r6, 0x1
	  lbzx      r7, r30, r0
	  subi      r0, r5, 0x1
	  addi      r4, r4, 0x8
	  stb       r7, 0x5(r3)
	  lbzx      r5, r30, r6
	  stb       r5, 0x6(r3)
	  lbzx      r0, r30, r0
	  stb       r0, 0x7(r3)
	  addi      r3, r3, 0x8
	  bdnz+     .loc_0xB0
	  b         .loc_0x19C

	.loc_0x15C:
	  sub       r0, r29, r4
	  cmpw      r4, r29
	  mtctr     r0
	  addi      r3, r1, 0x18
	  bge-      .loc_0x18C

	.loc_0x170:
	  sub       r5, r29, r4
	  subi      r0, r5, 0x1
	  lbzx      r0, r3, r0
	  addi      r4, r4, 0x1
	  stb       r0, 0x0(r6)
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x170

	.loc_0x18C:
	  add       r0, r31, r29
	  li        r3, 0
	  stbx      r3, r28, r0
	  b         .loc_0x1A8

	.loc_0x19C:
	  add       r6, r31, r4
	  add       r6, r28, r6
	  b         .loc_0x15C

	.loc_0x1A8:
	  lmw       r27, 0x11C(r1)
	  lwz       r0, 0x134(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F25E0
 * Size:	00007C
 */
void zen::loadTexExp(const char*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  addi      r4, r3, 0
	  stwu      r1, -0x110(r1)
	  beq-      .loc_0x60
	  lwz       r3, 0x2DEC(r13)
	  rlwinm.   r0,r5,0,24,31
	  lwz       r3, 0x48(r3)
	  beq-      .loc_0x34
	  addi      r5, r1, 0x10
	  bl        -0x1E8
	  b         .loc_0x4C

	.loc_0x34:
	  addi      r5, r3, 0
	  crclr     6, 0x6
	  addi      r6, r4, 0
	  addi      r3, r1, 0x10
	  addi      r4, r13, 0x29A8
	  bl        0x23F70

	.loc_0x4C:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x10
	  li        r5, 0x1
	  bl        -0x1B3530
	  b         .loc_0x6C

	.loc_0x60:
	  lwz       r3, 0x2DEC(r13)
	  li        r5, 0x1
	  bl        -0x1B3540

	.loc_0x6C:
	  lwz       r0, 0x114(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}
