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
 * Address:	80198988
 * Size:	0000F8
 */
zen::ogScrStartMgr::ogScrStartMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  li        r3, 0xF8
	  bl        -0x1519A0
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x80
	  addi      r3, r1, 0xC
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1AC60
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0xC
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x17FE4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stb       r0, 0xEC(r31)
	  stw       r0, 0xF0(r31)
	  stw       r0, 0xF4(r31)

	.loc_0x80:
	  stw       r31, 0x8(r30)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x6230
	  lwz       r3, 0x8(r30)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x1A1DC
	  lwz       r3, 0x8(r30)
	  lis       r4, 0x726F
	  addi      r4, r4, 0x6F74
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r30)
	  li        r4, -0x1
	  li        r0, 0x3
	  lfs       f0, -0x4D10(r2)
	  mr        r3, r30
	  stfs      f0, 0x10(r30)
	  stw       r4, 0x0(r30)
	  stw       r0, 0x4(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80198A80
 * Size:	000038
 */
void zen::ogScrStartMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x4D10(r2)
	  stfs      f0, 0x10(r3)
	  lwz       r3, 0x8(r3)
	  bl        0x26E34
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80198AB8
 * Size:	000028
 */
void zen::ogScrStartMgr::stop()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bnelr-
	  li        r0, 0x3
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x4D10(r2)
	  stfs      f0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80198AE0
 * Size:	0001C0
 */
void zen::ogScrStartMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x1A8

	.loc_0x2C:
	  lwz       r3, 0x8(r30)
	  bl        0x1A040
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xAC
	  lfs       f2, 0x10(r30)
	  lfs       f1, -0x4D0C(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x88
	  lfs       f0, -0x4D08(r2)
	  lwz       r3, 0x8(r30)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r4, 0x24(r1)
	  bl        0x26D78
	  b         .loc_0xA4

	.loc_0x88:
	  lwz       r3, 0x8(r30)
	  li        r4, 0xFF
	  bl        0x26D68
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4D10(r2)
	  stfs      f0, 0x10(r30)

	.loc_0xA4:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x1A8

	.loc_0xAC:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x110
	  lfs       f2, 0x10(r30)
	  lfs       f1, -0x4D0C(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0xEC
	  lfs       f0, -0x4D08(r2)
	  lwz       r3, 0x8(r30)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  subfic    r4, r0, 0xFF
	  bl        0x26D14
	  b         .loc_0x108

	.loc_0xEC:
	  lwz       r3, 0x8(r30)
	  li        r4, 0
	  bl        0x26D04
	  lwz       r0, 0x4(r30)
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4D10(r2)
	  stfs      f0, 0x10(r30)

	.loc_0x108:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x1A8

	.loc_0x110:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x128
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x1A8

	.loc_0x128:
	  cmpwi     r0, 0
	  bne-      .loc_0x1A4
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4D04(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x148
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)

	.loc_0x148:
	  lfs       f1, -0x4CFC(r2)
	  lfs       f0, 0x10(r30)
	  fmuls     f1, f1, f0
	  bl        0x82F20
	  lfs       f2, -0x4D00(r2)
	  lfs       f0, -0x4D08(r2)
	  fmuls     f1, f2, f1
	  lwz       r3, 0x8(r30)
	  fsubs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r4, 0x24(r1)
	  bl        0x26C7C
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,7,7
	  beq-      .loc_0x1A4
	  li        r0, 0x3
	  stw       r0, 0x4(r30)
	  li        r0, 0x2
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4D10(r2)
	  stfs      f0, 0x10(r30)

	.loc_0x1A4:
	  lwz       r3, 0x0(r30)

	.loc_0x1A8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80198CA0
 * Size:	00008C
 */
void zen::ogScrStartMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  mr        r31, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x78
	  lfs       f1, -0x4CF8(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x4D04(r2)
	  li        r4, 0
	  lfs       f3, -0x4CF4(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x174B0
	  addi      r3, r1, 0x10
	  bl        0x175B8
	  lwz       r3, 0x8(r31)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x1A1D8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0x78:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}
