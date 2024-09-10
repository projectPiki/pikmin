#include "types.h"

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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800ACEA0
 * Size:	0000AC
 */
ActBridge::ActBridge(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh.    r0, r4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x30
	  addi      r0, r31, 0x50
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x50(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  li        r5, 0x1
	  bl        0x16EF4
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5C98
	  stw       r3, 0x0(r31)
	  addi      r6, r3, 0x68
	  addi      r5, r31, 0x50
	  lwz       r3, 0x14(r31)
	  subi      r4, r13, 0x4E78
	  li        r0, 0
	  stw       r6, 0x0(r3)
	  mr        r3, r31
	  lwz       r6, 0x14(r31)
	  sub       r5, r5, r6
	  stw       r5, 0x4(r6)
	  lfs       f0, -0x7098(r2)
	  stfs      f0, 0x3C(r31)
	  stfs      f0, 0x38(r31)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x48(r31)
	  stfs      f0, 0x44(r31)
	  stfs      f0, 0x40(r31)
	  stw       r4, 0x10(r31)
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ACF4C
 * Size:	0000DC
 */
void ActBridge::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  cmplwi    r4, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  stb       r5, 0x33(r3)
	  stb       r5, 0x32(r3)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)
	  lwz       r3, 0xC(r30)
	  stb       r5, 0x400(r3)
	  stw       r5, 0x18(r30)
	  beq-      .loc_0x74
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x26
	  bne-      .loc_0x74
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  stw       r31, 0x18(r30)

	.loc_0x74:
	  li        r0, 0
	  sth       r0, 0x1C(r30)
	  bl        0x16B0A8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7088(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7090(r2)
	  stw       r0, 0x20(r1)
	  lfs       f1, -0x7094(r2)
	  lfd       f3, 0x20(r1)
	  lfs       f0, -0x708C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stb       r0, 0x4C(r30)
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
 * Address:	800AD028
 * Size:	00006C
 */
void ActBridge::dump()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0x24A0
	  stwu      r1, -0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  addi      r3, r1, 0x68
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r4, 0x8(r5)
	  lwz       r0, 0xC(r5)
	  stw       r4, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r4, 0x18(r31)
	  lha       r5, 0x30(r31)
	  bl        -0xE728
	  addi      r3, r1, 0x50
	  lwz       r4, 0x18(r31)
	  bl        -0xE520
	  lwz       r0, 0xBC(r1)
	  lwz       r31, 0xB4(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void ActBridge::collideBridgeSurface()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void ActBridge::collideBridgeBlocker()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AD094
 * Size:	000094
 */
void ActBridge::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x18(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x2C
	  lwz       r4, 0xC(r3)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x84

	.loc_0x2C:
	  lbz       r0, 0x3C8(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  lhz       r0, 0x1C(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x68
	  bge-      .loc_0x54
	  cmpwi     r0, 0
	  beq-      .loc_0x60
	  b         .loc_0x78

	.loc_0x54:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x70
	  b         .loc_0x78

	.loc_0x60:
	  bl        0x130
	  b         .loc_0x84

	.loc_0x68:
	  bl        0x568
	  b         .loc_0x84

	.loc_0x70:
	  bl        0x93C
	  b         .loc_0x84

	.loc_0x78:
	  li        r3, 0
	  b         .loc_0x84

	.loc_0x80:
	  li        r3, 0

	.loc_0x84:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void ActBridge::initDetour()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void ActBridge::exeDetour()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AD128
 * Size:	000028
 */
void ActBridge::procWallMsg(Piki*, MsgWall*)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x4(r5)
	  li        r0, 0x8
	  lwz       r5, 0x0(r6)
	  lwz       r4, 0x4(r6)
	  stw       r5, 0x34(r3)
	  stw       r4, 0x38(r3)
	  lwz       r4, 0x8(r6)
	  stw       r4, 0x3C(r3)
	  stb       r0, 0x33(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void ActBridge::initClimb()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void ActBridge::exeClimb()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void ActBridge::initApproach()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000328
 */
void ActBridge::exeApproach()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void ActBridge::initGo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003F0
 */
void ActBridge::exeGo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void ActBridge::initWork()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000414
 */
void ActBridge::exeWork()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void ActBridge::doWork(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AD150
 * Size:	0000B0
 */
void ActBridge::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x3C
	  bge-      .loc_0x30
	  cmpwi     r0, 0
	  beq-      .loc_0x94
	  b         .loc_0x9C

	.loc_0x30:
	  cmpwi     r0, 0x8
	  beq-      .loc_0x48
	  b         .loc_0x9C

	.loc_0x3C:
	  li        r0, 0x1
	  stw       r0, 0x24(r31)
	  b         .loc_0x9C

	.loc_0x48:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x9C
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0
	  ble-      .loc_0x74
	  addi      r3, r3, 0x174
	  bl        -0x7D60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C

	.loc_0x74:
	  lwz       r5, 0xC(r31)
	  li        r4, 0x27
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x464
	  li        r7, 0
	  bl        0xEF95C
	  b         .loc_0x9C

	.loc_0x94:
	  li        r0, 0x1
	  stb       r0, 0x4D(r31)

	.loc_0x9C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AD200
 * Size:	000024
 */
void ActBridge::cleanup()
{
	/*
	.loc_0x0:
	  lwz       r4, 0xC(r3)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,25,23
	  stw       r0, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ActBridge::newInitApproach()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AD224
 * Size:	000360
 */
void ActBridge::newExeApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stw       r31, 0xF4(r1)
	  stw       r30, 0xF0(r1)
	  mr        r30, r3
	  lwz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x44
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x33C

	.loc_0x44:
	  lwz       r3, 0xC(r30)
	  bl        -0x23024
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  lwz       r0, 0x18(r30)
	  cmplw     r3, r0
	  bne-      .loc_0xB8
	  addi      r3, r1, 0x64
	  lwz       r4, 0xC(r30)
	  bl        -0x23028
	  lfs       f31, 0x64(r1)
	  addi      r3, r1, 0x70
	  lfs       f30, 0x68(r1)
	  lfs       f29, 0x6C(r1)
	  lwz       r4, 0x18(r30)
	  bl        -0xE748
	  lfs       f1, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f2, f31, f1
	  lfs       f3, 0x78(r1)
	  fmuls     f1, f30, f0
	  lfs       f0, -0x707C(r2)
	  fmuls     f3, f29, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB8
	  li        r0, 0x1
	  b         .loc_0xBC

	.loc_0xB8:
	  li        r0, 0

	.loc_0xBC:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xD4
	  mr        r3, r30
	  bl        .loc_0x360
	  li        r3, 0
	  b         .loc_0x33C

	.loc_0xD4:
	  lwz       r5, 0xC(r30)
	  addi      r3, r1, 0x94
	  lwz       r4, 0x18(r30)
	  addi      r31, r5, 0x94
	  bl        -0xE6EC
	  lfs       f1, 0x94(r1)
	  lfs       f0, 0x0(r31)
	  lfs       f3, 0x98(r1)
	  lfs       f2, 0x4(r31)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r31)
	  lfs       f4, 0x9C(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0xE0(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xE4(r1)
	  stfs      f0, 0xE8(r1)
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  lfs       f2, 0xE8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9F71C
	  lfs       f0, -0x7098(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x16C
	  lfs       f0, 0xE0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE4(r1)
	  lfs       f0, 0xE8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE8(r1)

	.loc_0x16C:
	  lfs       f0, -0x706C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x328
	  lwz       r4, 0xC(r30)
	  addi      r5, r1, 0xD4
	  lwz       r3, 0x18(r30)
	  addi      r6, r1, 0xD8
	  addi      r4, r4, 0x94
	  bl        -0xE93C
	  lwz       r3, 0x18(r30)
	  bl        -0xF17C
	  addi      r4, r3, 0
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1AC
	  li        r3, 0x2
	  b         .loc_0x33C

	.loc_0x1AC:
	  lwz       r3, 0x18(r30)
	  bl        -0xE9C4
	  lfs       f0, -0x7060(r2)
	  lfs       f2, 0xD4(r1)
	  fadds     f0, f0, f1
	  lfs       f1, 0xD8(r1)
	  fabs      f31, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0xD8(r1)
	  lwz       r3, 0x18(r30)
	  bl        -0xE6D8
	  lfs       f2, -0x7078(r2)
	  lfs       f0, -0x7080(r2)
	  fmuls     f1, f2, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x278
	  lfs       f1, 0xD8(r1)
	  lfs       f0, -0x7098(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x264
	  lwz       r4, 0x18(r30)
	  addi      r3, r1, 0x88
	  lha       r5, 0x30(r30)
	  bl        -0xEAEC
	  addi      r3, r1, 0x7C
	  lwz       r4, 0x18(r30)
	  bl        -0xE8E4
	  lfs       f0, 0x7C(r1)
	  addi      r4, r1, 0xE0
	  lfs       f1, 0x80(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0x84(r1)
	  stfs      f1, 0xC0(r1)
	  lfs       f1, -0x7070(r2)
	  stfs      f0, 0xC4(r1)
	  lwz       r0, 0xBC(r1)
	  lwz       r3, 0xC0(r1)
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r3, 0xE4(r1)
	  stw       r0, 0xE8(r1)
	  lwz       r3, 0xC(r30)
	  bl        0x1E958
	  b         .loc_0x338

	.loc_0x264:
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x33C

	.loc_0x278:
	  lfs       f2, -0x7098(r2)
	  stfs      f2, 0xB4(r1)
	  stfs      f2, 0xB0(r1)
	  lfs       f1, 0xD8(r1)
	  lfs       f0, -0x7068(r2)
	  stfs      f2, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2D0
	  addi      r3, r1, 0xAC
	  lwz       r4, 0x18(r30)
	  bl        -0xE968
	  lfs       f0, 0xAC(r1)
	  lfs       f1, -0x7074(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xAC(r1)
	  lfs       f0, 0xB0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB4(r1)
	  b         .loc_0x314

	.loc_0x2D0:
	  addi      r3, r1, 0xAC
	  lwz       r4, 0x18(r30)
	  bl        -0xE940
	  lfs       f1, 0xD4(r1)
	  lfs       f0, -0x7098(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x314
	  lfs       f0, 0xAC(r1)
	  lfs       f1, -0x7074(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xAC(r1)
	  lfs       f0, 0xB0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB4(r1)

	.loc_0x314:
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0xAC
	  lfs       f1, -0x7070(r2)
	  bl        0x1E894
	  b         .loc_0x338

	.loc_0x328:
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0xE0
	  lfs       f1, -0x7070(r2)
	  bl        0x1E880

	.loc_0x338:
	  li        r3, 0

	.loc_0x33C:
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lwz       r31, 0xF4(r1)
	  lwz       r30, 0xF0(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr

	.loc_0x360:
	*/
}

/*
 * --INFO--
 * Address:	800AD584
 * Size:	0000E0
 */
void ActBridge::newInitGo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  sth       r0, 0x1C(r3)
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  bl        -0xF378
	  extsh     r0, r3
	  sth       r0, 0x30(r29)
	  bl        0x16AAB0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7088(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7090(r2)
	  stw       r0, 0x20(r1)
	  lfs       f1, -0x7094(r2)
	  lfd       f3, 0x20(r1)
	  lfs       f0, -0x7078(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r29)
	  b         .loc_0x84

	.loc_0x7C:
	  li        r0, -0x1
	  sth       r0, 0x30(r29)

	.loc_0x84:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x94
	  lwz       r30, 0x14(r29)

	.loc_0x94:
	  addi      r3, r1, 0x10
	  li        r4, 0x2
	  bl        0x71938
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x2
	  bl        0x71958
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1D394
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AD664
 * Size:	00030C
 */
void ActBridge::newExeGo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x150(r1)
	  stfd      f31, 0x148(r1)
	  stfd      f30, 0x140(r1)
	  stfd      f29, 0x138(r1)
	  stfd      f28, 0x130(r1)
	  stfd      f27, 0x128(r1)
	  stfd      f26, 0x120(r1)
	  stw       r31, 0x11C(r1)
	  mr        r31, r3
	  stw       r30, 0x118(r1)
	  stw       r29, 0x114(r1)
	  lha       r4, 0x30(r3)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x48
	  li        r3, 0x2
	  b         .loc_0x2D8

	.loc_0x48:
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x68
	  lwz       r4, 0xC(r31)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x2D8

	.loc_0x68:
	  bl        -0xF380
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  li        r0, 0x2
	  sth       r0, 0x1C(r31)
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xD4
	  bl        -0xF4B0
	  extsh     r0, r3
	  sth       r0, 0x30(r31)
	  bl        0x16A978
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7088(r2)
	  stw       r0, 0x10C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7090(r2)
	  stw       r0, 0x108(r1)
	  lfs       f1, -0x7094(r2)
	  lfd       f3, 0x108(r1)
	  lfs       f0, -0x7078(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  b         .loc_0xDC

	.loc_0xD4:
	  li        r0, -0x1
	  sth       r0, 0x30(r31)

	.loc_0xDC:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0xEC
	  lwz       r29, 0x14(r31)

	.loc_0xEC:
	  addi      r3, r1, 0x98
	  li        r4, 0x2
	  bl        0x71800
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x90
	  li        r4, 0x2
	  bl        0x71820
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1D25C
	  li        r3, 0
	  b         .loc_0x2D8

	.loc_0x124:
	  lwz       r3, 0xC(r31)
	  bl        -0x23544
	  cmplwi    r3, 0
	  beq-      .loc_0x198
	  lwz       r0, 0x18(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x198
	  addi      r3, r1, 0x78
	  lwz       r4, 0xC(r31)
	  bl        -0x23548
	  lfs       f31, 0x78(r1)
	  addi      r3, r1, 0x84
	  lfs       f30, 0x7C(r1)
	  lfs       f29, 0x80(r1)
	  lwz       r4, 0x18(r31)
	  bl        -0xEC68
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f2, f31, f1
	  lfs       f3, 0x8C(r1)
	  fmuls     f1, f30, f0
	  lfs       f0, -0x707C(r2)
	  fmuls     f3, f29, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x198
	  li        r0, 0x1
	  b         .loc_0x19C

	.loc_0x198:
	  li        r0, 0

	.loc_0x19C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1B4
	  mr        r3, r31
	  bl        .loc_0x30C
	  li        r3, 0
	  b         .loc_0x2D8

	.loc_0x1B4:
	  lwz       r3, 0xC(r31)
	  bl        -0x235D4
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  lwz       r0, 0x18(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x1DC
	  addi      r3, r1, 0x58
	  lwz       r4, 0xC(r31)
	  bl        -0x235D8

	.loc_0x1DC:
	  lwz       r4, 0x18(r31)
	  addi      r3, r1, 0xC4
	  lha       r5, 0x30(r31)
	  bl        -0xEF04
	  lfs       f29, 0xC4(r1)
	  addi      r3, r1, 0xB8
	  lfs       f30, 0xC8(r1)
	  lfs       f31, 0xCC(r1)
	  lwz       r4, 0x18(r31)
	  bl        -0xECA8
	  lfs       f28, 0xB8(r1)
	  lfs       f27, 0xBC(r1)
	  lfs       f26, 0xC0(r1)
	  lwz       r3, 0x18(r31)
	  bl        -0xEB58
	  lfs       f0, 0x2C(r31)
	  lwz       r3, 0xC(r31)
	  fmuls     f2, f0, f1
	  addi      r4, r3, 0x94
	  lfs       f0, 0x94(r3)
	  lfs       f1, 0x4(r4)
	  addi      r3, r1, 0xA0
	  fmuls     f28, f28, f2
	  fmuls     f27, f27, f2
	  fmuls     f26, f26, f2
	  lfs       f2, 0x8(r4)
	  fadds     f29, f29, f28
	  fadds     f30, f30, f27
	  fadds     f31, f31, f26
	  fsubs     f0, f29, f0
	  fsubs     f3, f30, f1
	  fsubs     f1, f31, f2
	  stfs      f0, 0xE0(r1)
	  stfs      f3, 0xE4(r1)
	  stfs      f1, 0xE8(r1)
	  lwz       r4, 0x18(r31)
	  bl        -0xED74
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xE8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9FCB4
	  lfs       f0, -0x7098(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2C4
	  lfs       f0, 0xE0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE4(r1)
	  lfs       f0, 0xE8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE8(r1)

	.loc_0x2C4:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0xE0
	  lfs       f1, -0x7070(r2)
	  bl        0x1E4A4
	  li        r3, 0

	.loc_0x2D8:
	  lwz       r0, 0x154(r1)
	  lfd       f31, 0x148(r1)
	  lfd       f30, 0x140(r1)
	  lfd       f29, 0x138(r1)
	  lfd       f28, 0x130(r1)
	  lfd       f27, 0x128(r1)
	  lfd       f26, 0x120(r1)
	  lwz       r31, 0x11C(r1)
	  lwz       r30, 0x118(r1)
	  lwz       r29, 0x114(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr

	.loc_0x30C:
	*/
}

/*
 * --INFO--
 * Address:	800AD970
 * Size:	0000D0
 */
void ActBridge::newInitWork()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x4
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  lis       r3, 0x803A
	  sth       r0, 0x1C(r29)
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  lwz       r3, 0x300(r3)
	  stw       r3, 0x20(r29)
	  stw       r0, 0x24(r29)
	  sth       r0, 0x28(r29)
	  sth       r0, 0x2A(r29)
	  lbz       r0, 0x4C(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xB4
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x60
	  lwz       r30, 0x14(r29)

	.loc_0x60:
	  addi      r3, r1, 0x10
	  li        r4, 0x30
	  bl        0x71580
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x30
	  bl        0x715A0
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1CFDC
	  li        r0, 0
	  stb       r0, 0x4D(r29)
	  lbz       r0, -0x5F15(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  lwz       r3, 0xC(r29)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0xC8(r3)

	.loc_0xB4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ADA40
 * Size:	000668
 */
void ActBridge::newExeWork()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x190(r1)
	  stfd      f31, 0x188(r1)
	  stfd      f30, 0x180(r1)
	  stfd      f29, 0x178(r1)
	  stfd      f28, 0x170(r1)
	  stfd      f27, 0x168(r1)
	  stfd      f26, 0x160(r1)
	  stw       r31, 0x15C(r1)
	  stw       r30, 0x158(r1)
	  mr        r30, r3
	  stw       r29, 0x154(r1)
	  lwz       r3, 0x18(r3)
	  lha       r4, 0x30(r30)
	  bl        -0xF730
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x108
	  li        r0, 0x2
	  sth       r0, 0x1C(r30)
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  bl        -0xF860
	  extsh     r0, r3
	  sth       r0, 0x30(r30)
	  bl        0x16A5C8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7088(r2)
	  stw       r0, 0x14C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7090(r2)
	  stw       r0, 0x148(r1)
	  lfs       f1, -0x7094(r2)
	  lfd       f3, 0x148(r1)
	  lfs       f0, -0x7078(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r30)
	  b         .loc_0xB0

	.loc_0xA8:
	  li        r0, -0x1
	  sth       r0, 0x30(r30)

	.loc_0xB0:
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0xC0
	  lwz       r29, 0x14(r30)

	.loc_0xC0:
	  addi      r3, r1, 0xD0
	  li        r4, 0x2
	  bl        0x71450
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0xC8
	  li        r4, 0x2
	  bl        0x71470
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CEAC
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  b         .loc_0x634

	.loc_0x108:
	  lwz       r3, 0xC(r30)
	  bl        -0x23904
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  lwz       r0, 0x18(r30)
	  cmplw     r3, r0
	  bne-      .loc_0x17C
	  addi      r3, r1, 0xB0
	  lwz       r4, 0xC(r30)
	  bl        -0x23908
	  lfs       f26, 0xB0(r1)
	  addi      r3, r1, 0xBC
	  lfs       f27, 0xB4(r1)
	  lfs       f28, 0xB8(r1)
	  lwz       r4, 0x18(r30)
	  bl        -0xF028
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fmuls     f2, f26, f1
	  lfs       f3, 0xC4(r1)
	  fmuls     f1, f27, f0
	  lfs       f0, -0x707C(r2)
	  fmuls     f3, f28, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x17C
	  li        r0, 0x1
	  b         .loc_0x180

	.loc_0x17C:
	  li        r0, 0

	.loc_0x180:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x194
	  li        r0, 0
	  sth       r0, 0x28(r30)
	  b         .loc_0x250

	.loc_0x194:
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x4E5C(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4E58(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4E54(r13)
	  stfs      f0, 0x8(r3)
	  lhz       r3, 0x28(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x28(r30)
	  lhz       r0, 0x28(r30)
	  cmplwi    r0, 0x3
	  ble-      .loc_0x1D8
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r3)

	.loc_0x1D8:
	  lhz       r0, 0x28(r30)
	  cmplwi    r0, 0xF
	  ble-      .loc_0x250
	  lbz       r0, 0x4D(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x250
	  li        r0, 0
	  cmplwi    r30, 0
	  sth       r0, 0x1C(r30)
	  mr        r29, r30
	  beq-      .loc_0x208
	  lwz       r29, 0x14(r30)

	.loc_0x208:
	  addi      r3, r1, 0x98
	  li        r4, 0x2
	  bl        0x71308
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x90
	  li        r4, 0x2
	  bl        0x71328
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CD64
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  b         .loc_0x634

	.loc_0x250:
	  lwz       r3, 0x18(r30)
	  lwz       r4, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x298
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  lwz       r4, 0xC(r30)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  b         .loc_0x634

	.loc_0x298:
	  lbz       r3, 0x4C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x358
	  subi      r0, r3, 0x1
	  stb       r0, 0x4C(r30)
	  lbz       r0, 0x4C(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x350
	  li        r0, 0x4
	  lis       r3, 0x803A
	  sth       r0, 0x1C(r30)
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x300(r3)
	  li        r0, 0
	  stw       r3, 0x20(r30)
	  stw       r0, 0x24(r30)
	  sth       r0, 0x28(r30)
	  sth       r0, 0x2A(r30)
	  lbz       r0, 0x4C(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x350
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0x2FC
	  lwz       r29, 0x14(r30)

	.loc_0x2FC:
	  addi      r3, r1, 0x88
	  li        r4, 0x30
	  bl        0x71214
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x80
	  li        r4, 0x30
	  bl        0x71234
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CC70
	  li        r0, 0
	  stb       r0, 0x4D(r30)
	  lbz       r0, -0x5F15(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x350
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0xC8(r3)

	.loc_0x350:
	  li        r3, 0
	  b         .loc_0x634

	.loc_0x358:
	  lis       r3, 0x803A
	  lwz       r5, 0x20(r30)
	  subi      r3, r3, 0x2848
	  lwz       r4, 0x300(r3)
	  addi      r31, r3, 0x300
	  lis       r3, 0x8889
	  subi      r0, r3, 0x7777
	  sub       r3, r4, r5
	  addi      r4, r3, 0x3C
	  mulhw     r0, r0, r4
	  add       r0, r0, r4
	  srawi     r0, r0, 0x5
	  rlwinm    r3,r0,1,31,31
	  add       r0, r0, r3
	  mulli     r0, r0, 0x3C
	  sub.      r3, r4, r0
	  ble-      .loc_0x420
	  lwz       r0, 0x24(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x420
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x7088(r2)
	  stw       r0, 0x14C(r1)
	  lis       r0, 0x4330
	  lis       r4, 0x802B
	  lfs       f0, -0x7064(r2)
	  stw       r0, 0x148(r1)
	  lis       r3, 0x802B
	  lha       r6, 0x30(r30)
	  lfd       f1, 0x148(r1)
	  subi      r4, r4, 0x3064
	  lwz       r5, 0xC(r30)
	  addi      r0, r3, 0x10D8
	  fsubs     f1, f1, f2
	  stw       r4, 0x70(r1)
	  addi      r4, r1, 0x70
	  fdivs     f0, f1, f0
	  stw       r5, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stw       r6, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  li        r0, 0
	  stw       r3, 0x20(r30)
	  stw       r0, 0x24(r30)

	.loc_0x420:
	  lwz       r4, 0x18(r30)
	  addi      r3, r1, 0xFC
	  lha       r5, 0x30(r30)
	  bl        -0xF524
	  lwz       r4, 0xC(r30)
	  addi      r3, r1, 0xE4
	  lfs       f4, 0x104(r1)
	  addi      r4, r4, 0x94
	  lfs       f3, 0x100(r1)
	  lfs       f0, 0x8(r4)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0xFC(r1)
	  fsubs     f31, f4, f0
	  lfs       f0, 0x0(r4)
	  fsubs     f30, f3, f2
	  lwz       r4, 0x18(r30)
	  fsubs     f26, f1, f0
	  bl        -0xF348
	  lfs       f1, 0xE4(r1)
	  addi      r3, r1, 0xD8
	  lfs       f0, 0xE8(r1)
	  stfs      f1, 0x124(r1)
	  stfs      f0, 0x128(r1)
	  lfs       f0, 0xEC(r1)
	  stfs      f0, 0x12C(r1)
	  lwz       r4, 0x18(r30)
	  bl        -0xF30C
	  lfs       f1, 0x124(r1)
	  lfs       f0, 0x128(r1)
	  fmuls     f1, f26, f1
	  lfs       f2, 0x12C(r1)
	  fmuls     f0, f30, f0
	  lfs       f28, 0xD8(r1)
	  fmuls     f3, f31, f2
	  fadds     f1, f1, f0
	  lfs       f29, 0xDC(r1)
	  fmuls     f2, f26, f28
	  lfs       f27, 0xE0(r1)
	  lfs       f0, -0x705C(r2)
	  fadds     f4, f3, f1
	  fmuls     f1, f30, f29
	  fmuls     f3, f31, f27
	  fabs      f4, f4
	  fadds     f1, f2, f1
	  fcmpo     cr0, f4, f0
	  fadds     f30, f3, f1
	  ble-      .loc_0x4F0
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r3)
	  b         .loc_0x500

	.loc_0x4F0:
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0xC8(r3)

	.loc_0x500:
	  fabs      f26, f30
	  lwz       r3, 0x18(r30)
	  bl        -0xF228
	  lfs       f0, -0x7078(r2)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x56C
	  li        r0, 0
	  cmplwi    r30, 0
	  sth       r0, 0x1C(r30)
	  mr        r29, r30
	  beq-      .loc_0x534
	  lwz       r29, 0x14(r30)

	.loc_0x534:
	  addi      r3, r1, 0x64
	  li        r4, 0x2
	  bl        0x70FDC
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x5C
	  li        r4, 0x2
	  bl        0x70FFC
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CA38
	  li        r3, 0
	  b         .loc_0x634

	.loc_0x56C:
	  lwz       r3, 0x18(r30)
	  bl        -0xF290
	  lfs       f0, -0x7058(r2)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x618
	  lfs       f0, -0x7098(r2)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x5A0
	  lfs       f0, -0x7074(r2)
	  fmuls     f28, f28, f0
	  fmuls     f29, f29, f0
	  fmuls     f27, f27, f0

	.loc_0x5A0:
	  lfs       f0, 0x124(r1)
	  lfs       f1, 0x128(r1)
	  fadds     f0, f0, f28
	  lfs       f2, 0x12C(r1)
	  fadds     f3, f1, f29
	  fadds     f1, f2, f27
	  stfs      f0, 0x124(r1)
	  stfs      f3, 0x128(r1)
	  stfs      f1, 0x12C(r1)
	  lfs       f1, 0x124(r1)
	  lfs       f0, 0x128(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x12C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA03E4
	  lfs       f0, -0x7098(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x618
	  lfs       f0, 0x124(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x124(r1)
	  lfs       f0, 0x128(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x128(r1)
	  lfs       f0, 0x12C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x12C(r1)

	.loc_0x618:
	  lwz       r3, 0x18(r30)
	  bl        -0xF344
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0x124
	  lfs       f1, -0x7078(r2)
	  bl        0x1DD6C
	  li        r3, 0

	.loc_0x634:
	  lwz       r0, 0x194(r1)
	  lfd       f31, 0x188(r1)
	  lfd       f30, 0x180(r1)
	  lfd       f29, 0x178(r1)
	  lfd       f28, 0x170(r1)
	  lfd       f27, 0x168(r1)
	  lfd       f26, 0x160(r1)
	  lwz       r31, 0x15C(r1)
	  lwz       r30, 0x158(r1)
	  lwz       r29, 0x154(r1)
	  addi      r1, r1, 0x190
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE0A8
 * Size:	000080
 */
ActBridge::~ActBridge()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x64
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5C98
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x50
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x15D10
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x66F5C

	.loc_0x64:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE128
 * Size:	000014
 */
void ActBridge::@80 @4 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  li        r11, 0x4
	  lwzx      r11, r3, r11
	  add       r3, r3, r11
	  subi      r3, r3, 0x50
	  b         -0xFE8
	*/
}
