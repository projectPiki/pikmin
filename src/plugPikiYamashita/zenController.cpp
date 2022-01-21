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
 * Address:	........
 * Size:	0000AC
 */
void zen::KeyRepeat::update(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C0310
 * Size:	000094
 */
zen::ZenController::ZenController(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stmw      r27, 0x14(r1)
	  mr        r27, r3
	  li        r30, 0
	  addi      r29, r27, 0
	  li        r28, 0
	  li        r31, 0x1
	  stw       r4, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lfs       f31, -0x4710(r2)

	.loc_0x34:
	  li        r3, 0x10
	  bl        -0x179344
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  slw       r0, r31, r28
	  stw       r0, 0x0(r3)
	  stfs      f31, 0x4(r3)
	  lfs       f0, 0x31B0(r13)
	  stfs      f0, 0x8(r3)
	  stb       r30, 0xC(r3)

	.loc_0x5C:
	  addi      r28, r28, 0x1
	  stw       r3, 0x8(r29)
	  cmpwi     r28, 0x19
	  addi      r29, r29, 0x4
	  blt+      .loc_0x34
	  lfs       f0, -0x4708(r2)
	  mr        r3, r27
	  stfs      f0, 0x31B0(r13)
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lmw       r27, 0x14(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C03A4
 * Size:	0000F8
 */
void zen::ZenController::update()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beqlr-
	  li        r0, 0x19
	  lfs       f3, -0x4710(r2)
	  mtctr     r0
	  lfs       f1, -0x470C(r2)
	  addi      r6, r3, 0
	  li        r9, 0

	.loc_0x2C:
	  lwz       r8, 0x0(r3)
	  li        r5, 0
	  lwz       r7, 0x8(r6)
	  lwz       r4, 0x20(r8)
	  lwz       r0, 0x0(r7)
	  and.      r0, r4, r0
	  beq-      .loc_0x6C
	  lbz       r0, 0xC(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  lwz       r4, 0x2DEC(r13)
	  lfs       f2, 0x4(r7)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f2, f0
	  stfs      f0, 0x4(r7)
	  b         .loc_0x78

	.loc_0x6C:
	  stfs      f3, 0x4(r7)
	  lfs       f0, 0x31B0(r13)
	  stfs      f0, 0x8(r7)

	.loc_0x78:
	  lwz       r4, 0x20(r8)
	  lwz       r0, 0x0(r7)
	  and       r0, r4, r0
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r0, r0, r4
	  stb       r0, 0xC(r7)
	  lfs       f2, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xB8
	  stfs      f3, 0x4(r7)
	  li        r5, 0x1
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)

	.loc_0xB8:
	  lwz       r4, 0x28(r8)
	  lwz       r0, 0x0(r7)
	  and.      r0, r4, r0
	  beq-      .loc_0xCC
	  li        r5, 0x1

	.loc_0xCC:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE8
	  li        r0, 0x1
	  lwz       r4, 0x4(r3)
	  slw       r0, r0, r9
	  or        r0, r4, r0
	  stw       r0, 0x4(r3)

	.loc_0xE8:
	  addi      r6, r6, 0x4
	  addi      r9, r9, 0x1
	  bdnz+     .loc_0x2C
	  blr
	*/
}
