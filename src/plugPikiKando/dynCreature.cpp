#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void printMatrix(char *, Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80092808
 * Size:	0000D8
 */
DynParticle::DynParticle()
{
/*
.loc_0x0:
  lis       r4, 0x8022
  addi      r0, r4, 0x738C
  lis       r4, 0x8022
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x737C
  stw       r0, 0x0(r3)
  li        r7, 0
  lis       r6, 0x802B
  stw       r7, 0x10(r3)
  lis       r5, 0x802B
  lis       r4, 0x802B
  stw       r7, 0xC(r3)
  subi      r6, r6, 0x8C0
  subi      r5, r5, 0x690
  stw       r7, 0x8(r3)
  subi      r0, r4, 0x8B4
  stw       r6, 0x4(r3)
  stw       r5, 0x0(r3)
  lfs       f0, -0x7470(r2)
  stfs      f0, 0x20(r3)
  stfs      f0, 0x1C(r3)
  stfs      f0, 0x18(r3)
  stfs      f0, 0x2C(r3)
  stfs      f0, 0x28(r3)
  stfs      f0, 0x24(r3)
  stfs      f0, 0x38(r3)
  stfs      f0, 0x34(r3)
  stfs      f0, 0x30(r3)
  stfs      f0, 0x44(r3)
  stfs      f0, 0x40(r3)
  stfs      f0, 0x3C(r3)
  stfs      f0, 0x9C(r3)
  stfs      f0, 0x98(r3)
  stfs      f0, 0x94(r3)
  stfs      f0, 0xA8(r3)
  stfs      f0, 0xA4(r3)
  stfs      f0, 0xA0(r3)
  stw       r7, 0x10(r3)
  stw       r7, 0xC(r3)
  stw       r7, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r7, 0x48(r3)
  lfs       f0, -0x746C(r2)
  stfs      f0, 0x14(r3)
  lfs       f0, -0x5B30(r13)
  stfs      f0, 0x24(r3)
  lfs       f0, -0x5B2C(r13)
  stfs      f0, 0x28(r3)
  lfs       f0, -0x5B28(r13)
  stfs      f0, 0x2C(r3)
  stw       r7, 0x4C(r3)
  lfs       f0, -0x7468(r2)
  stfs      f0, 0x90(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800928E0
 * Size:	000010
 */
void DynParticle::getSize()
{
/*
.loc_0x0:
  lfs       f1, -0x7464(r2)
  lfs       f0, 0x90(r3)
  fmuls     f1, f1, f0
  blr
*/
}

/*
 * --INFO--
 * Address:	800928F0
 * Size:	000004
 */
void DynParticle::refresh(Graphics &)
{
}

/*
 * --INFO--
 * Address:	800928F4
 * Size:	000004
 */
void DynParticle::doKill()
{
}

/*
 * --INFO--
 * Address:	800928F8
 * Size:	0001F4
 */
DynParticleHeap::DynParticleHeap(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stmw      r27, 0x74(r1)
  addi      r29, r3, 0
  addi      r30, r4, 0
  bl        -0x108
  addi      r3, r29, 0xAC
  bl        -0x110
  li        r3, 0x58
  bl        -0x4B91C
  mr.       r31, r3
  beq-      .loc_0x140
  lis       r3, 0x802B
  subi      r0, r3, 0x6C8
  stw       r0, 0x54(r31)
  li        r0, 0
  addi      r3, r1, 0x44
  stw       r0, 0x0(r31)
  subi      r4, r13, 0x5B24
  bl        -0x41E70
  lwz       r0, 0x44(r1)
  addi      r5, r1, 0x3C
  addi      r4, r31, 0
  stw       r0, 0x3C(r1)
  addi      r3, r31, 0x4
  bl        -0x33EE0
  lis       r3, 0x802A
  addi      r28, r3, 0x6098
  stw       r28, 0xC(r31)
  addi      r3, r1, 0x4C
  subi      r4, r13, 0x5B20
  lfs       f0, -0x7460(r2)
  stfs      f0, 0x10(r31)
  bl        -0x41EA8
  lwz       r0, 0x4C(r1)
  addi      r5, r1, 0x38
  addi      r4, r31, 0
  stw       r0, 0x38(r1)
  addi      r3, r31, 0x14
  bl        -0x33F18
  stw       r28, 0x1C(r31)
  addi      r3, r1, 0x54
  subi      r4, r13, 0x5B1C
  lfs       f0, -0x7460(r2)
  stfs      f0, 0x20(r31)
  bl        -0x41ED8
  lwz       r0, 0x54(r1)
  addi      r5, r1, 0x34
  addi      r4, r31, 0
  stw       r0, 0x34(r1)
  addi      r3, r31, 0x24
  bl        -0x33F48
  stw       r28, 0x2C(r31)
  addi      r3, r1, 0x5C
  subi      r4, r13, 0x5B18
  lfs       f0, -0x745C(r2)
  stfs      f0, 0x30(r31)
  bl        -0x41F08
  lwz       r0, 0x5C(r1)
  addi      r5, r1, 0x30
  addi      r4, r31, 0
  stw       r0, 0x30(r1)
  addi      r3, r31, 0x34
  bl        -0x33F78
  stw       r28, 0x3C(r31)
  addi      r3, r1, 0x64
  subi      r4, r13, 0x5B14
  lfs       f0, -0x7458(r2)
  stfs      f0, 0x40(r31)
  bl        -0x41F38
  lwz       r0, 0x64(r1)
  addi      r5, r1, 0x2C
  addi      r4, r31, 0
  stw       r0, 0x2C(r1)
  addi      r3, r31, 0x44
  bl        -0x33FA8
  stw       r28, 0x4C(r31)
  lfs       f0, -0x7454(r2)
  stfs      f0, 0x50(r31)

.loc_0x140:
  addi      r28, r30, 0
  mulli     r3, r28, 0xAC
  addi      r3, r3, 0x8
  bl        -0x4BA40
  lis       r4, 0x8009
  addi      r4, r4, 0x2808
  addi      r7, r28, 0
  li        r5, 0
  li        r6, 0xAC
  bl        0x1821CC
  stw       r3, 0x15C(r29)
  li        r31, 0
  lis       r4, 0x802B
  stw       r30, 0x158(r29)
  lis       r3, 0x802B
  subi      r4, r4, 0x8A8
  stw       r31, 0x10(r29)
  subi      r0, r3, 0x898
  addi      r28, r31, 0
  stw       r31, 0xC(r29)
  li        r27, 0
  stw       r31, 0x8(r29)
  stw       r4, 0x4(r29)
  stw       r31, 0xBC(r29)
  stw       r31, 0xB8(r29)
  stw       r31, 0xB4(r29)
  stw       r0, 0xB0(r29)
  b         .loc_0x1D4

.loc_0x1B0:
  lwz       r4, 0x15C(r29)
  addi      r0, r28, 0x4C
  addi      r3, r29, 0
  stwx      r31, r4, r0
  lwz       r0, 0x15C(r29)
  add       r4, r0, r28
  bl        -0x524E8
  addi      r28, r28, 0xAC
  addi      r27, r27, 0x1

.loc_0x1D4:
  cmpw      r27, r30
  blt+      .loc_0x1B0
  mr        r3, r29
  lmw       r27, 0x74(r1)
  lwz       r0, 0x8C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void DynParticleHeap::getFreeOne()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void DynParticleHeap::releaseOne(DynParticle *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80092AEC
 * Size:	0000F4
 */
DynCreature::DynCreature()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        -0x7C2C
  lis       r3, 0x802B
  subi      r0, r3, 0x824
  stw       r0, 0x0(r31)
  li        r0, 0
  addi      r3, r31, 0
  lfs       f0, -0x7470(r2)
  stfs      f0, 0x2C0(r31)
  stfs      f0, 0x2BC(r31)
  stfs      f0, 0x2B8(r31)
  stfs      f0, 0x2CC(r31)
  stfs      f0, 0x2C8(r31)
  stfs      f0, 0x2C4(r31)
  stfs      f0, 0x2E4(r31)
  stfs      f0, 0x2E0(r31)
  stfs      f0, 0x2DC(r31)
  stfs      f0, 0x2F0(r31)
  stfs      f0, 0x2EC(r31)
  stfs      f0, 0x2E8(r31)
  stw       r0, 0x2D8(r31)
  sth       r0, 0x2D4(r31)
  stfs      f0, 0x2F4(r31)
  stfs      f0, 0x2D0(r31)
  lfs       f0, -0x5B10(r13)
  stfs      f0, 0x2DC(r31)
  lfs       f0, -0x5B0C(r13)
  stfs      f0, 0x2E0(r31)
  lfs       f0, -0x5B08(r13)
  stfs      f0, 0x2E4(r31)
  lfs       f0, -0x5B04(r13)
  stfs      f0, 0x2B8(r31)
  lfs       f0, -0x5B00(r13)
  stfs      f0, 0x2BC(r31)
  lfs       f0, -0x5AFC(r13)
  stfs      f0, 0x2C0(r31)
  lfs       f0, -0x5AF8(r13)
  stfs      f0, 0x2C4(r31)
  lfs       f0, -0x5AF4(r13)
  stfs      f0, 0x2C8(r31)
  lfs       f0, -0x5AF0(r13)
  stfs      f0, 0x2CC(r31)
  lfs       f0, -0x5AEC(r13)
  stfs      f0, 0x70(r31)
  lfs       f0, -0x5AE8(r13)
  stfs      f0, 0x74(r31)
  lfs       f0, -0x5AE4(r13)
  stfs      f0, 0x78(r31)
  lbz       r0, 0x438(r31)
  ori       r0, r0, 0x1
  stb       r0, 0x438(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092BE0
 * Size:	00001C
 */
void DynCreature::enablePickOffset(float)
{
/*
.loc_0x0:
  lwz       r0, 0xC8(r3)
  fneg      f0, f1
  ori       r0, r0, 0x100
  stw       r0, 0xC8(r3)
  stfs      f1, 0xD0(r3)
  stfs      f0, 0x2D0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80092BFC
 * Size:	000018
 */
void DynCreature::disablePickOffset()
{
/*
.loc_0x0:
  lwz       r0, 0xC8(r3)
  rlwinm    r0,r0,0,24,22
  stw       r0, 0xC8(r3)
  lfs       f0, -0x7470(r2)
  stfs      f0, 0x2D0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80092C14
 * Size:	000100
 */
void DynCreature::addParticle(float, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stfd      f31, 0x30(r1)
  fmr       f31, f1
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  stw       r28, 0x20(r1)
  mr        r28, r3
  lwz       r31, 0x3000(r13)
  lwz       r30, 0x10(r31)
  cmplwi    r30, 0
  beq-      .loc_0x58
  mr        r3, r30
  bl        -0x52644
  li        r0, 0
  stw       r0, 0x4C(r30)
  addi      r4, r30, 0
  addi      r3, r31, 0xAC
  bl        -0x52690

.loc_0x58:
  cmplwi    r30, 0
  beq-      .loc_0xDC
  stfs      f31, 0x14(r30)
  lwz       r3, 0x0(r29)
  lwz       r0, 0x4(r29)
  stw       r3, 0x24(r30)
  stw       r0, 0x28(r30)
  lwz       r0, 0x8(r29)
  stw       r0, 0x2C(r30)
  lwz       r3, 0x0(r29)
  lwz       r0, 0x4(r29)
  stw       r3, 0x18(r30)
  stw       r0, 0x1C(r30)
  lwz       r0, 0x8(r29)
  stw       r0, 0x20(r30)
  lwz       r0, 0x2D8(r28)
  cmplwi    r0, 0
  bne-      .loc_0xA8
  stw       r30, 0x2D8(r28)
  b         .loc_0xC4

.loc_0xA8:
  mr        r3, r0
  b         .loc_0xB4

.loc_0xB0:
  mr        r3, r0

.loc_0xB4:
  lwz       r0, 0x4C(r3)
  cmplwi    r0, 0
  bne+      .loc_0xB0
  stw       r30, 0x4C(r3)

.loc_0xC4:
  lfs       f0, 0x2F4(r28)
  fadds     f0, f0, f31
  stfs      f0, 0x2F4(r28)
  lhz       r3, 0x2D4(r28)
  addi      r0, r3, 0x1
  sth       r0, 0x2D4(r28)

.loc_0xDC:
  lwz       r0, 0x3C(r1)
  lfd       f31, 0x30(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092D14
 * Size:	000068
 */
void DynCreature::releaseAllParticles()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  mr        r27, r3
  li        r31, 0
  lwz       r29, 0x2D8(r3)
  b         .loc_0x44

.loc_0x20:
  lwz       r28, 0x4C(r29)
  mr        r3, r29
  lwz       r30, 0x3000(r13)
  bl        -0x52730
  stw       r31, 0x4C(r29)
  addi      r3, r30, 0
  addi      r4, r29, 0
  bl        -0x52778
  mr        r29, r28

.loc_0x44:
  cmplwi    r29, 0
  bne+      .loc_0x20
  li        r0, 0
  stw       r0, 0x2D8(r27)
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092D7C
 * Size:	00018C
 */
void DynCreature::initialiseSystem()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA8(r1)
  lwz       r0, 0xC8(r3)
  ori       r0, r0, 0x201
  stw       r0, 0xC8(r3)
  lfs       f0, -0x5AE0(r13)
  stfs      f0, 0x2E8(r3)
  lfs       f0, -0x5ADC(r13)
  stfs      f0, 0x2EC(r3)
  lfs       f0, -0x5AD8(r13)
  stfs      f0, 0x2F0(r3)
  lfs       f0, -0x7470(r2)
  stfs      f0, 0x2F4(r3)
  lwz       r5, 0x2D8(r3)
  b         .loc_0xBC

.loc_0x40:
  lfs       f3, 0x14(r5)
  lfs       f0, 0x18(r5)
  lfs       f1, 0x20(r5)
  fmuls     f0, f0, f3
  fmuls     f2, f1, f3
  stfs      f0, 0x4C(r1)
  lfs       f1, 0x2E8(r3)
  lfs       f0, 0x4C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x6C(r1)
  stfs      f0, 0x9C(r1)
  lfs       f0, 0x1C(r5)
  lfs       f1, 0x2EC(r3)
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0xA0(r1)
  lfs       f0, 0x2F0(r3)
  fadds     f0, f0, f2
  stfs      f0, 0xA4(r1)
  lwz       r4, 0x9C(r1)
  lwz       r0, 0xA0(r1)
  stw       r4, 0x2E8(r3)
  stw       r0, 0x2EC(r3)
  lwz       r0, 0xA4(r1)
  stw       r0, 0x2F0(r3)
  lfs       f1, 0x2F4(r3)
  lfs       f0, 0x14(r5)
  fadds     f0, f1, f0
  stfs      f0, 0x2F4(r3)
  lwz       r5, 0x4C(r5)

.loc_0xBC:
  cmplwi    r5, 0
  bne+      .loc_0x40
  lfs       f2, -0x7450(r2)
  lfs       f1, 0x2F4(r3)
  lfs       f0, 0x2E8(r3)
  fdivs     f1, f2, f1
  fmuls     f0, f0, f1
  stfs      f0, 0x60(r1)
  lfs       f0, 0x60(r1)
  stfs      f0, 0x84(r1)
  lfs       f0, 0x2EC(r3)
  fmuls     f0, f0, f1
  stfs      f0, 0x88(r1)
  lfs       f0, 0x2F0(r3)
  fmuls     f0, f0, f1
  stfs      f0, 0x8C(r1)
  lwz       r4, 0x84(r1)
  lwz       r0, 0x88(r1)
  stw       r4, 0x2E8(r3)
  stw       r0, 0x2EC(r3)
  lwz       r0, 0x8C(r1)
  stw       r0, 0x2F0(r3)
  lwz       r5, 0x2D8(r3)
  b         .loc_0x170

.loc_0x11C:
  lfs       f1, 0x18(r5)
  lfs       f0, 0x2E8(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x54(r1)
  lfs       f0, 0x54(r1)
  stfs      f0, 0x78(r1)
  lfs       f1, 0x1C(r5)
  lfs       f0, 0x2EC(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x7C(r1)
  lfs       f1, 0x20(r5)
  lfs       f0, 0x2F0(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x80(r1)
  lwz       r4, 0x78(r1)
  lwz       r0, 0x7C(r1)
  stw       r4, 0x24(r5)
  stw       r0, 0x28(r5)
  lwz       r0, 0x80(r1)
  stw       r0, 0x2C(r5)
  lwz       r5, 0x4C(r5)

.loc_0x170:
  cmplwi    r5, 0
  bne+      .loc_0x11C
  bl        0xBB4
  lwz       r0, 0xAC(r1)
  addi      r1, r1, 0xA8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092F08
 * Size:	00003C
 */
void DynCreature::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x28C(r4)
  bl        .loc_0x3C
  mr        r3, r31
  bl        -0x7D24
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0x3C:
*/
}

/*
 * --INFO--
 * Address:	80092F44
 * Size:	000B64
 */
void DynCreature::simulate(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x4A8(r1)
  stfd      f31, 0x4A0(r1)
  fmr       f31, f1
  addi      r6, r1, 0x2C0
  stfd      f30, 0x498(r1)
  addi      r4, r1, 0x2CC
  stfd      f29, 0x490(r1)
  stfd      f28, 0x488(r1)
  stfd      f27, 0x480(r1)
  stfd      f26, 0x478(r1)
  stfd      f25, 0x470(r1)
  stfd      f24, 0x468(r1)
  stfd      f23, 0x460(r1)
  stfd      f22, 0x458(r1)
  stfd      f21, 0x450(r1)
  stfd      f20, 0x448(r1)
  stfd      f19, 0x440(r1)
  stmw      r21, 0x414(r1)
  addi      r21, r3, 0
  addi      r5, r21, 0xE0
  lfs       f0, -0x5AD4(r13)
  stfs      f0, 0x2DC(r3)
  lfs       f0, -0x5AD0(r13)
  stfs      f0, 0x2E0(r3)
  addi      r3, r1, 0x3D0
  lfs       f0, -0x5ACC(r13)
  stfs      f0, 0x2E4(r21)
  stb       r0, 0x439(r21)
  lfs       f1, -0x5ABC(r13)
  lfs       f0, -0x5AC8(r13)
  stfs      f1, 0x2C0(r1)
  lfs       f1, -0x5AB8(r13)
  stfs      f0, 0x2CC(r1)
  lfs       f0, -0x5AC4(r13)
  stfs      f1, 0x2C4(r1)
  lfs       f1, -0x5AB4(r13)
  stfs      f0, 0x2D0(r1)
  lfs       f0, -0x5AC0(r13)
  stfs      f1, 0x2C8(r1)
  stfs      f0, 0x2D4(r1)
  bl        -0x542EC
  addi      r3, r1, 0x3D0
  addi      r4, r1, 0x350
  bl        -0x5437C
  addi      r3, r1, 0x3D0
  addi      r4, r21, 0x3B8
  addi      r5, r1, 0x390
  bl        -0x54F38
  addi      r3, r1, 0x390
  addi      r4, r1, 0x350
  addi      r5, r21, 0x338
  bl        -0x54F48
  addi      r3, r1, 0x3D0
  addi      r4, r21, 0x378
  addi      r5, r1, 0x390
  bl        -0x54F58
  addi      r3, r1, 0x390
  addi      r4, r1, 0x350
  addi      r5, r21, 0x2F8
  bl        -0x54F68
  lfs       f1, 0x74(r21)
  li        r0, 0
  lfs       f0, -0x744C(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x124
  lfs       f0, -0x7470(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x124
  li        r0, 0x1

.loc_0x124:
  lfs       f0, -0x5AB0(r13)
  addi      r27, r1, 0x110
  lfs       f19, -0x7470(r2)
  addi      r26, r1, 0x10C
  stfs      f0, 0x340(r1)
  lfs       f0, -0x5AAC(r13)
  fmr       f23, f19
  fmr       f24, f19
  addi      r25, r1, 0x108
  stfs      f0, 0x344(r1)
  fmr       f26, f19
  lfs       f0, -0x5AA8(r13)
  fmr       f28, f19
  addi      r30, r1, 0x11C
  stfs      f0, 0x348(r1)
  fmr       f29, f19
  addi      r29, r1, 0x118
  lwz       r24, 0x2D8(r21)
  addi      r28, r1, 0x114
  lfs       f30, -0x7450(r2)
  lfs       f25, -0x7460(r2)
  rlwinm    r31,r0,0,24,31
  lfs       f27, -0x7448(r2)
  li        r23, 0
  li        r22, 0
  b         .loc_0x880

.loc_0x18C:
  lfs       f0, 0x24(r24)
  addi      r3, r24, 0x94
  addi      r4, r1, 0x3D0
  stfs      f0, 0x334(r1)
  lfs       f0, 0x28(r24)
  stfs      f0, 0x338(r1)
  lfs       f0, 0x2C(r24)
  stfs      f0, 0x33C(r1)
  lfs       f1, 0x338(r1)
  lfs       f0, 0x2D0(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x338(r1)
  lwz       r5, 0x334(r1)
  lwz       r0, 0x338(r1)
  stw       r5, 0x94(r24)
  stw       r0, 0x98(r24)
  lwz       r0, 0x33C(r1)
  stw       r0, 0x9C(r24)
  bl        -0x5B9CC
  lfs       f1, 0x94(r24)
  addi      r3, r1, 0x328
  lfs       f0, 0x2E8(r21)
  addi      r4, r1, 0x3D0
  fadds     f0, f1, f0
  stfs      f0, 0x94(r24)
  lfs       f1, 0x98(r24)
  lfs       f0, 0x2EC(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x98(r24)
  lfs       f1, 0x9C(r24)
  lfs       f0, 0x2F0(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x9C(r24)
  lfs       f1, 0x94(r24)
  lfs       f0, 0x94(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x94(r24)
  lfs       f1, 0x98(r24)
  lfs       f0, 0x98(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x98(r24)
  lfs       f1, 0x9C(r24)
  lfs       f0, 0x9C(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x9C(r24)
  lwz       r5, 0x2C4(r21)
  lwz       r0, 0x2C8(r21)
  stw       r5, 0xA0(r24)
  stw       r0, 0xA4(r24)
  lwz       r0, 0x2CC(r21)
  stw       r0, 0xA8(r24)
  lfs       f0, 0x24(r24)
  stfs      f0, 0x328(r1)
  lfs       f0, 0x28(r24)
  stfs      f0, 0x32C(r1)
  lfs       f0, 0x2C(r24)
  stfs      f0, 0x330(r1)
  bl        -0x5BA68
  lfs       f1, 0xA8(r24)
  cmplwi    r31, 0
  lfs       f6, 0x32C(r1)
  lfs       f5, 0x328(r1)
  lfs       f7, 0xA4(r24)
  fmuls     f0, f1, f6
  lfs       f3, 0x330(r1)
  fmuls     f4, f1, f5
  lfs       f2, 0xA0(r24)
  fmuls     f1, f7, f3
  fmuls     f3, f2, f3
  fmuls     f2, f2, f6
  fsubs     f0, f1, f0
  fmuls     f1, f7, f5
  fsubs     f3, f4, f3
  stfs      f0, 0xA0(r24)
  fsubs     f0, f2, f1
  stfs      f3, 0xA4(r24)
  stfs      f0, 0xA8(r24)
  bne-      .loc_0x318
  lfs       f1, 0xA0(r24)
  lfs       f0, 0x70(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x1E4(r1)
  lfs       f0, 0x1E4(r1)
  stfs      f0, 0x2B4(r1)
  lfs       f1, 0xA4(r24)
  lfs       f0, 0x74(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x2B8(r1)
  lfs       f1, 0xA8(r24)
  lfs       f0, 0x78(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x2BC(r1)
  lwz       r3, 0x2B4(r1)
  lwz       r0, 0x2B8(r1)
  stw       r3, 0xA0(r24)
  stw       r0, 0xA4(r24)
  lwz       r0, 0x2BC(r1)
  stw       r0, 0xA8(r24)
  b         .loc_0x338

.loc_0x318:
  lfs       f1, 0xA0(r24)
  lfs       f0, 0x70(r21)
  fadds     f0, f1, f0
  stfs      f0, 0xA0(r24)
  lfs       f1, 0xA8(r24)
  lfs       f0, 0x78(r21)
  fadds     f0, f1, f0
  stfs      f0, 0xA8(r24)

.loc_0x338:
  lwz       r3, 0xA0(r24)
  li        r4, 0x1
  lwz       r0, 0xA4(r24)
  stw       r3, 0x3C(r24)
  stw       r0, 0x40(r24)
  lwz       r0, 0xA8(r24)
  stw       r0, 0x44(r24)
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x94(r24)
  lfs       f2, 0x9C(r24)
  bl        -0x2B3A0
  fmr       f22, f1
  lfs       f1, 0x98(r24)
  lfs       f2, 0x90(r24)
  fsubs     f0, f1, f22
  fsubs     f1, f1, f2
  fcmpo     cr0, f0, f2
  fsubs     f20, f22, f1
  bge-      .loc_0x878
  li        r0, 0x1
  lbz       r3, 0x439(r21)
  slw       r0, r0, r22
  or        r0, r3, r0
  stb       r0, 0x439(r21)
  li        r4, 0x1
  addi      r23, r23, 0x1
  stfs      f23, 0x318(r1)
  stfs      f23, 0x314(r1)
  stfs      f23, 0x310(r1)
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x94(r24)
  lfs       f2, 0x9C(r24)
  bl        -0x2B124
  cmplwi    r3, 0
  beq-      .loc_0x430
  lwz       r4, 0x18(r3)
  lwz       r0, 0x1C(r3)
  stw       r4, 0x310(r1)
  stw       r0, 0x314(r1)
  lwz       r0, 0x20(r3)
  stw       r0, 0x318(r1)
  lfs       f1, 0x310(r1)
  lfs       f0, 0x314(r1)
  lfs       f2, 0x318(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x85700
  fcmpu     cr0, f24, f1
  beq-      .loc_0x448
  lfs       f0, 0x310(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x310(r1)
  lfs       f0, 0x314(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x314(r1)
  lfs       f0, 0x318(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x318(r1)
  b         .loc_0x448

.loc_0x430:
  lfs       f1, -0x5AA4(r13)
  lfs       f0, -0x5AA0(r13)
  stfs      f1, 0x310(r1)
  stfs      f0, 0x314(r1)
  lfs       f0, -0x5A9C(r13)
  stfs      f0, 0x318(r1)

.loc_0x448:
  mr        r3, r21
  lwz       r12, 0x0(r21)
  lwz       r12, 0x44(r12)
  mtlr      r12
  blrl      
  fmuls     f0, f25, f1
  lfs       f4, 0x98(r21)
  fadds     f0, f4, f0
  fcmpo     cr0, f0, f22
  bge-      .loc_0x4EC
  lfs       f1, 0x94(r21)
  lfs       f0, 0x94(r24)
  lfs       f2, 0x98(r24)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r21)
  lfs       f1, 0x9C(r24)
  fsubs     f2, f4, f2
  stfs      f0, 0x310(r1)
  fsubs     f0, f3, f1
  stfs      f2, 0x314(r1)
  stfs      f0, 0x318(r1)
  lfs       f1, 0x310(r1)
  lfs       f0, 0x314(r1)
  lfs       f2, 0x318(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x857C0
  fcmpu     cr0, f26, f1
  beq-      .loc_0x4EC
  lfs       f0, 0x310(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x310(r1)
  lfs       f0, 0x314(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x314(r1)
  lfs       f0, 0x318(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x318(r1)

.loc_0x4EC:
  fcmpo     cr0, f19, f20
  bge-      .loc_0x510
  lwz       r0, 0x310(r1)
  fmr       f19, f20
  lwz       r3, 0x314(r1)
  stw       r0, 0x340(r1)
  lwz       r0, 0x318(r1)
  stw       r3, 0x344(r1)
  stw       r0, 0x348(r1)

.loc_0x510:
  lfs       f8, 0x3C(r24)
  addi      r3, r1, 0x300
  lfs       f3, 0x310(r1)
  addi      r4, r1, 0x3D0
  lfs       f7, 0x40(r24)
  lfs       f4, 0x314(r1)
  fmuls     f1, f8, f3
  lfs       f6, 0x44(r24)
  fmuls     f0, f7, f4
  lfs       f5, 0x318(r1)
  fmuls     f2, f6, f5
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  fmuls     f0, f27, f0
  fmuls     f2, f3, f0
  fmuls     f1, f4, f0
  fmuls     f0, f5, f0
  stfs      f2, 0x138(r1)
  lfs       f2, 0x138(r1)
  stfs      f2, 0x29C(r1)
  stfs      f1, 0x2A0(r1)
  stfs      f0, 0x2A4(r1)
  lfs       f0, 0x29C(r1)
  fsubs     f0, f8, f0
  stfs      f0, 0x1CC(r1)
  lfs       f0, 0x1CC(r1)
  stfs      f0, 0x2A8(r1)
  lfs       f0, 0x2A0(r1)
  fsubs     f0, f7, f0
  stfs      f0, 0x2AC(r1)
  lfs       f0, 0x2A4(r1)
  fsubs     f0, f6, f0
  stfs      f0, 0x2B0(r1)
  lwz       r5, 0x2A8(r1)
  lwz       r0, 0x2AC(r1)
  stw       r5, 0xA0(r24)
  stw       r0, 0xA4(r24)
  lwz       r0, 0x2B0(r1)
  stw       r0, 0xA8(r24)
  lfs       f0, 0x24(r24)
  stfs      f0, 0x300(r1)
  lfs       f0, 0x28(r24)
  stfs      f0, 0x304(r1)
  lfs       f0, 0x2C(r24)
  stfs      f0, 0x308(r1)
  bl        -0x5BDBC
  lfs       f1, 0x2F4(r21)
  addi      r3, r1, 0x300
  addi      r4, r1, 0x310
  addi      r5, r21, 0x338
  addi      r6, r24, 0x3C
  addi      r7, r24, 0xA0
  bl        0x7F298
  fcmpo     cr0, f1, f28
  cror      2, 0, 0x2
  bne-      .loc_0x5F4
  lfs       f1, -0x7444(r2)

.loc_0x5F4:
  fcmpo     cr0, f1, f29
  ble-      .loc_0x878
  lfs       f2, 0x318(r1)
  mr        r4, r28
  lfs       f0, 0x310(r1)
  mr        r5, r29
  fmuls     f2, f2, f1
  fmuls     f0, f0, f1
  addi      r6, r30, 0
  addi      r3, r1, 0x290
  stfs      f2, 0x11C(r1)
  lfs       f2, 0x314(r1)
  fmuls     f1, f2, f1
  stfs      f0, 0x114(r1)
  stfs      f1, 0x118(r1)
  bl        -0x5C458
  lfs       f0, 0x2F4(r21)
  addi      r3, r1, 0x2E8
  lfs       f20, 0x290(r1)
  addi      r4, r1, 0x3D0
  fdivs     f0, f30, f0
  lfs       f22, 0x294(r1)
  lfs       f21, 0x298(r1)
  fmuls     f2, f20, f0
  fmuls     f1, f22, f0
  fmuls     f0, f21, f0
  stfs      f2, 0x1C0(r1)
  lfs       f2, 0x1C0(r1)
  stfs      f2, 0x278(r1)
  stfs      f1, 0x27C(r1)
  stfs      f0, 0x280(r1)
  lfs       f1, 0x70(r21)
  lfs       f0, 0x278(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x1B4(r1)
  lfs       f0, 0x1B4(r1)
  stfs      f0, 0x284(r1)
  lfs       f1, 0x74(r21)
  lfs       f0, 0x27C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x288(r1)
  lfs       f1, 0x78(r21)
  lfs       f0, 0x280(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x28C(r1)
  lwz       r5, 0x284(r1)
  lwz       r0, 0x288(r1)
  stw       r5, 0x70(r21)
  stw       r0, 0x74(r21)
  lwz       r0, 0x28C(r1)
  stw       r0, 0x78(r21)
  lfs       f0, 0x24(r24)
  stfs      f0, 0x2E8(r1)
  lfs       f0, 0x28(r24)
  stfs      f0, 0x2EC(r1)
  lfs       f0, 0x2C(r24)
  stfs      f0, 0x2F0(r1)
  bl        -0x5BED0
  lfs       f3, 0x2F0(r1)
  lfs       f5, 0x2EC(r1)
  lfs       f2, 0x2E8(r1)
  fmuls     f0, f3, f22
  fmuls     f1, f5, f21
  fmuls     f4, f3, f20
  fmuls     f3, f2, f21
  fsubs     f0, f1, f0
  fmuls     f2, f2, f22
  fmuls     f1, f5, f20
  stfs      f0, 0x2E8(r1)
  fsubs     f3, f4, f3
  fsubs     f0, f2, f1
  stfs      f3, 0x2EC(r1)
  stfs      f0, 0x2F0(r1)
  lfs       f1, 0x2DC(r21)
  lfs       f0, 0x2E8(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x19C(r1)
  lfs       f0, 0x19C(r1)
  stfs      f0, 0x26C(r1)
  lfs       f1, 0x2E0(r21)
  lfs       f0, 0x2EC(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x270(r1)
  lfs       f1, 0x2E4(r21)
  lfs       f0, 0x2F0(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x274(r1)
  lwz       r3, 0x26C(r1)
  lwz       r0, 0x270(r1)
  stw       r3, 0x2DC(r21)
  stw       r0, 0x2E0(r21)
  lwz       r0, 0x274(r1)
  stw       r0, 0x2E4(r21)
  lbz       r0, 0x438(r21)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x878
  lfs       f1, 0xA0(r24)
  mr        r4, r25
  lfs       f5, 0x310(r1)
  mr        r5, r26
  lfs       f0, 0xA4(r24)
  lfs       f4, 0x314(r1)
  fmuls     f1, f1, f5
  lfs       f2, 0xA8(r24)
  mr        r6, r27
  fmuls     f0, f0, f4
  lfs       f3, 0x318(r1)
  addi      r3, r1, 0x254
  fmuls     f2, f2, f3
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  fmuls     f2, f3, f0
  fmuls     f1, f4, f0
  fmuls     f0, f5, f0
  stfs      f2, 0x110(r1)
  stfs      f1, 0x10C(r1)
  stfs      f0, 0x108(r1)
  bl        -0x5C5F0
  lfs       f0, 0x2F4(r21)
  lfs       f1, 0xA0(r24)
  fdivs     f5, f30, f0
  lfs       f0, 0x254(r1)
  lfs       f6, -0x5A98(r13)
  lfs       f3, 0xA4(r24)
  lfs       f2, 0x258(r1)
  fsubs     f0, f1, f0
  lfs       f4, 0xA8(r24)
  fsubs     f1, f3, f2
  lfs       f2, 0x25C(r1)
  fmuls     f0, f0, f6
  fsubs     f2, f4, f2
  fmuls     f1, f1, f6
  fmuls     f0, f0, f5
  fmuls     f2, f2, f6
  fmuls     f1, f1, f5
  stfs      f0, 0x18C(r1)
  fmuls     f0, f2, f5
  lfs       f2, 0x18C(r1)
  stfs      f2, 0x238(r1)
  stfs      f1, 0x23C(r1)
  stfs      f0, 0x240(r1)
  lfs       f1, 0x70(r21)
  lfs       f0, 0x238(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x180(r1)
  lfs       f0, 0x180(r1)
  stfs      f0, 0x244(r1)
  lfs       f1, 0x74(r21)
  lfs       f0, 0x23C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x248(r1)
  lfs       f1, 0x78(r21)
  lfs       f0, 0x240(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x24C(r1)
  lwz       r3, 0x244(r1)
  lwz       r0, 0x248(r1)
  stw       r3, 0x70(r21)
  stw       r0, 0x74(r21)
  lwz       r0, 0x24C(r1)
  stw       r0, 0x78(r21)

.loc_0x878:
  lwz       r24, 0x4C(r24)
  addi      r22, r22, 0x1

.loc_0x880:
  cmplwi    r24, 0
  bne+      .loc_0x18C
  lfs       f0, -0x7470(r2)
  fcmpo     cr0, f19, f0
  ble-      .loc_0x918
  fmuls     f1, f19, f31
  lfs       f2, -0x7440(r2)
  lfs       f0, -0x743C(r2)
  fmuls     f1, f2, f1
  fcmpo     cr0, f1, f0
  fmr       f2, f1
  ble-      .loc_0x8B4
  fmr       f2, f0

.loc_0x8B4:
  lfs       f0, 0x340(r1)
  fmuls     f0, f0, f2
  stfs      f0, 0x174(r1)
  lfs       f1, 0x94(r21)
  lfs       f0, 0x174(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x168(r1)
  lfs       f0, 0x168(r1)
  stfs      f0, 0x22C(r1)
  lfs       f0, 0x344(r1)
  lfs       f1, 0x98(r21)
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x230(r1)
  lfs       f0, 0x348(r1)
  lfs       f1, 0x9C(r21)
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x234(r1)
  lwz       r3, 0x22C(r1)
  lwz       r0, 0x230(r1)
  stw       r3, 0x94(r21)
  stw       r0, 0x98(r21)
  lwz       r0, 0x234(r1)
  stw       r0, 0x9C(r21)

.loc_0x918:
  lfs       f1, 0x2B8(r21)
  lfs       f0, 0x2DC(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x15C(r1)
  lfs       f0, 0x15C(r1)
  stfs      f0, 0x214(r1)
  lfs       f1, 0x2BC(r21)
  lfs       f0, 0x2E0(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x218(r1)
  lfs       f1, 0x2C0(r21)
  lfs       f0, 0x2E4(r21)
  fadds     f0, f1, f0
  stfs      f0, 0x21C(r1)
  lwz       r3, 0x214(r1)
  lwz       r0, 0x218(r1)
  stw       r3, 0x2B8(r21)
  stw       r0, 0x2BC(r21)
  lwz       r0, 0x21C(r1)
  stw       r0, 0x2C0(r21)
  lfs       f1, 0x2B8(r21)
  lfs       f3, 0x2C0(r21)
  lfs       f0, 0x2BC(r21)
  fmuls     f2, f1, f1
  fmuls     f3, f3, f3
  fmuls     f1, f0, f0
  lfs       f0, -0x7470(r2)
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x9EC
  fsqrte    f1, f4
  lfd       f3, -0x7438(r2)
  lfd       f2, -0x7430(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x128(r1)
  lfs       f4, 0x128(r1)

.loc_0x9EC:
  lfs       f0, -0x7428(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0xA74
  lfs       f1, 0x2B8(r21)
  lfs       f0, 0x2BC(r21)
  fmuls     f1, f1, f1
  lfs       f2, 0x2C0(r21)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x85D1C
  lfs       f0, -0x7470(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xA4C
  lfs       f0, 0x2B8(r21)
  fdivs     f0, f0, f1
  stfs      f0, 0x2B8(r21)
  lfs       f0, 0x2BC(r21)
  fdivs     f0, f0, f1
  stfs      f0, 0x2BC(r21)
  lfs       f0, 0x2C0(r21)
  fdivs     f0, f0, f1
  stfs      f0, 0x2C0(r21)

.loc_0xA4C:
  lfs       f0, 0x2B8(r21)
  lfs       f1, -0x7428(r2)
  fmuls     f0, f0, f1
  stfs      f0, 0x2B8(r21)
  lfs       f0, 0x2BC(r21)
  fmuls     f0, f0, f1
  stfs      f0, 0x2BC(r21)
  lfs       f0, 0x2C0(r21)
  fmuls     f0, f0, f1
  stfs      f0, 0x2C0(r21)

.loc_0xA74:
  lwz       r5, 0x2B8(r21)
  addi      r3, r21, 0x2C4
  lwz       r0, 0x2BC(r21)
  addi      r4, r21, 0x338
  stw       r5, 0x2C4(r21)
  stw       r0, 0x2C8(r21)
  lwz       r0, 0x2C0(r21)
  stw       r0, 0x2CC(r21)
  bl        -0x5C28C
  lwz       r3, 0x2C4(r21)
  fmr       f3, f31
  lwz       r0, 0x2C8(r21)
  cmpwi     r23, 0
  stw       r3, 0xD4(r21)
  stw       r0, 0xD8(r21)
  lwz       r0, 0x2CC(r21)
  stw       r0, 0xDC(r21)
  bgt-      .loc_0xAC4
  lfs       f0, -0x7458(r2)
  fmuls     f3, f3, f0

.loc_0xAC4:
  lfs       f5, 0x2B8(r21)
  lfs       f2, 0x2C0(r21)
  fmuls     f0, f5, f3
  lfs       f4, 0x2BC(r21)
  fmuls     f1, f2, f3
  fmuls     f3, f4, f3
  stfs      f0, 0x120(r1)
  fsubs     f0, f2, f1
  lfs       f2, 0x120(r1)
  fsubs     f1, f4, f3
  fsubs     f2, f5, f2
  stfs      f2, 0x14C(r1)
  lfs       f2, 0x14C(r1)
  stfs      f2, 0x208(r1)
  stfs      f1, 0x20C(r1)
  stfs      f0, 0x210(r1)
  lwz       r3, 0x208(r1)
  lwz       r0, 0x20C(r1)
  stw       r3, 0x2B8(r21)
  stw       r0, 0x2BC(r21)
  lwz       r0, 0x210(r1)
  stw       r0, 0x2C0(r21)
  lwz       r0, 0x4AC(r1)
  lfd       f31, 0x4A0(r1)
  lfd       f30, 0x498(r1)
  lfd       f29, 0x490(r1)
  lfd       f28, 0x488(r1)
  lfd       f27, 0x480(r1)
  lfd       f26, 0x478(r1)
  lfd       f25, 0x470(r1)
  lfd       f24, 0x468(r1)
  lfd       f23, 0x460(r1)
  lfd       f22, 0x458(r1)
  lfd       f21, 0x450(r1)
  lfd       f20, 0x448(r1)
  lfd       f19, 0x440(r1)
  lmw       r21, 0x414(r1)
  addi      r1, r1, 0x4A8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000254
 */
void DynCreature::applyTorque(int, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80093AA8
 * Size:	0001B0
 */
void DynCreature::createInvInertiaTensor()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x98(r1)
  stfd      f31, 0x90(r1)
  stfd      f30, 0x88(r1)
  stfd      f29, 0x80(r1)
  stfd      f28, 0x78(r1)
  stfd      f27, 0x70(r1)
  stfd      f26, 0x68(r1)
  stfd      f25, 0x60(r1)
  stfd      f24, 0x58(r1)
  stw       r31, 0x54(r1)
  stw       r30, 0x50(r1)
  addi      r30, r3, 0
  addi      r3, r30, 0x378
  bl        -0x55D28
  lfs       f31, -0x7470(r2)
  lwz       r31, 0x2D8(r30)
  fmr       f30, f31
  fmr       f29, f31
  fmr       f28, f31
  fmr       f27, f31
  fmr       f26, f31
  fmr       f25, f31
  fmr       f24, f31
  b         .loc_0x128

.loc_0x68:
  lfs       f5, 0x2C(r31)
  addi      r3, r1, 0xC
  lfs       f2, 0x24(r31)
  addi      r4, r31, 0x50
  lfs       f1, 0x28(r31)
  lfs       f8, 0x14(r31)
  fmuls     f6, f2, f2
  fmuls     f9, f1, f1
  stfs      f24, 0xC(r1)
  fmuls     f10, f5, f5
  fmuls     f3, f2, f1
  lfs       f0, 0x2C(r31)
  fadds     f4, f6, f9
  stfs      f0, 0x10(r1)
  fmuls     f2, f2, f5
  fmuls     f1, f1, f5
  lfs       f0, 0x28(r31)
  fadds     f4, f10, f4
  stfs      f0, 0x14(r1)
  fmuls     f6, f8, f6
  fmuls     f5, f8, f3
  lfs       f0, 0x2C(r31)
  fmuls     f7, f8, f4
  fneg      f0, f0
  fmuls     f4, f8, f2
  fmuls     f3, f8, f9
  stfs      f0, 0x1C(r1)
  fmuls     f2, f8, f1
  fmuls     f1, f8, f10
  stfs      f24, 0x20(r1)
  fadds     f31, f31, f7
  lfs       f0, 0x24(r31)
  fadds     f30, f30, f6
  fadds     f29, f29, f5
  stfs      f0, 0x24(r1)
  fadds     f28, f28, f4
  lfs       f0, 0x28(r31)
  fadds     f27, f27, f3
  fadds     f26, f26, f2
  fneg      f0, f0
  fadds     f25, f25, f1
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x24(r31)
  fneg      f0, f0
  stfs      f0, 0x30(r1)
  stfs      f24, 0x34(r1)
  bl        -0x5578C
  lwz       r31, 0x4C(r31)

.loc_0x128:
  cmplwi    r31, 0
  bne+      .loc_0x68
  fsubs     f0, f31, f30
  addi      r3, r30, 0x378
  fneg      f2, f29
  addi      r4, r30, 0x3B8
  fneg      f3, f28
  stfs      f0, 0x378(r30)
  fsubs     f1, f31, f27
  fneg      f4, f26
  stfs      f2, 0x37C(r30)
  fsubs     f0, f31, f25
  stfs      f3, 0x380(r30)
  stfs      f2, 0x388(r30)
  stfs      f1, 0x38C(r30)
  stfs      f4, 0x390(r30)
  stfs      f3, 0x398(r30)
  stfs      f4, 0x39C(r30)
  stfs      f0, 0x3A0(r30)
  bl        -0x557E0
  lwz       r0, 0x9C(r1)
  lfd       f31, 0x90(r1)
  lfd       f30, 0x88(r1)
  lfd       f29, 0x80(r1)
  lfd       f28, 0x78(r1)
  lfd       f27, 0x70(r1)
  lfd       f26, 0x68(r1)
  lfd       f25, 0x60(r1)
  lfd       f24, 0x58(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  addi      r1, r1, 0x98
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void DynCreature::calcModelMatrix(Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80093C58
 * Size:	0002B4
 */
void DynCreature::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x148(r1)
  stw       r31, 0x144(r1)
  addi      r31, r4, 0
  stw       r30, 0x140(r1)
  stw       r29, 0x13C(r1)
  stw       r28, 0x138(r1)
  mr        r28, r3
  lfs       f1, 0x7C(r3)
  addi      r3, r1, 0x50
  lfs       f0, -0x5A94(r13)
  stfs      f1, 0xA8(r1)
  lfs       f1, 0x80(r28)
  stfs      f1, 0xAC(r1)
  lfs       f1, 0x84(r28)
  stfs      f1, 0xB0(r1)
  stfs      f0, 0x7C(r28)
  lfs       f0, -0x5A90(r13)
  stfs      f0, 0x80(r28)
  lfs       f0, -0x5A8C(r13)
  stfs      f0, 0x84(r28)
  bl        -0x55EF4
  lfs       f0, 0x2E8(r28)
  addi      r3, r1, 0x10
  addi      r4, r28, 0x94
  stfs      f0, 0x5C(r1)
  addi      r5, r28, 0xE0
  addi      r6, r28, 0x7C
  lfs       f0, 0x2EC(r28)
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x2F0(r28)
  stfs      f0, 0x7C(r1)
  bl        -0x54FD8
  addi      r3, r1, 0x10
  addi      r4, r1, 0x50
  addi      r5, r1, 0xF4
  bl        -0x55C18
  lwz       r5, 0xA8(r1)
  lis       r3, 0x803A
  lwz       r0, 0xAC(r1)
  subi      r4, r3, 0x77C0
  addi      r3, r31, 0
  stw       r5, 0x7C(r28)
  li        r5, 0
  stw       r0, 0x80(r28)
  lwz       r0, 0xB0(r1)
  stw       r0, 0x84(r28)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2E4(r31)
  addi      r4, r1, 0xF4
  addi      r5, r1, 0xB4
  addi      r3, r3, 0x1E0
  bl        -0x55C64
  mr        r3, r31
  lwz       r4, 0x2E4(r31)
  lwz       r12, 0x3B4(r31)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0xB4
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0xCC(r12)
  mtlr      r12
  blrl      
  li        r5, 0
  stb       r5, 0xA4(r1)
  li        r0, 0xFF
  addi      r4, r1, 0xA4
  stb       r0, 0xA5(r1)
  mr        r3, r31
  stb       r5, 0xA6(r1)
  li        r5, 0x1
  stb       r0, 0xA7(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lwz       r29, 0x2D8(r28)
  addi      r30, r1, 0xA0
  b         .loc_0x208

.loc_0x17C:
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  li        r0, 0
  stb       r0, 0xA0(r1)
  addi      r4, r3, 0
  li        r5, 0xFF
  stb       r5, 0xA1(r1)
  li        r0, 0x64
  addi      r3, r31, 0
  stb       r0, 0xA2(r1)
  addi      r28, r4, 0
  addi      r4, r30, 0
  stb       r5, 0xA3(r1)
  li        r5, 0x1
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lfs       f1, -0x7424(r2)
  addi      r3, r31, 0
  addi      r4, r29, 0x94
  bl        0x82FC8
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r28, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r29, 0x4C(r29)

.loc_0x208:
  cmplwi    r29, 0
  bne+      .loc_0x17C
  li        r6, 0xFF
  stb       r6, 0x9C(r1)
  li        r0, 0x64
  addi      r4, r1, 0x9C
  stb       r0, 0x9D(r1)
  li        r0, 0
  addi      r3, r31, 0
  stb       r0, 0x9E(r1)
  li        r5, 0x1
  stb       r6, 0x9F(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x5A88(r13)
  addi      r4, r1, 0x90
  lfs       f1, -0x5A84(r13)
  mr        r3, r31
  stfs      f0, 0x90(r1)
  lfs       f0, -0x5A80(r13)
  addi      r5, r1, 0xB4
  stfs      f1, 0x94(r1)
  lfs       f1, -0x7420(r2)
  stfs      f0, 0x98(r1)
  bl        -0x6AA58
  lwz       r12, 0x3B4(r31)
  lis       r4, 0x803A
  mr        r3, r31
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  lwz       r0, 0x14C(r1)
  lwz       r31, 0x144(r1)
  lwz       r30, 0x140(r1)
  lwz       r29, 0x13C(r1)
  lwz       r28, 0x138(r1)
  addi      r1, r1, 0x148
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80093F0C
 * Size:	000068
 */
void DynCreature::doKill()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  mr        r27, r3
  li        r31, 0
  lwz       r28, 0x2D8(r3)
  b         .loc_0x44

.loc_0x20:
  lwz       r30, 0x4C(r28)
  mr        r3, r28
  lwz       r29, 0x3000(r13)
  bl        -0x53928
  stw       r31, 0x4C(r28)
  addi      r3, r29, 0
  addi      r4, r28, 0
  bl        -0x53970
  mr        r28, r30

.loc_0x44:
  cmplwi    r28, 0
  bne+      .loc_0x20
  li        r0, 0
  stw       r0, 0x2D8(r27)
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000928
 */
void DynCreature::simulate2(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80093F74
 * Size:	000020
 */
void CreatureProp::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x353E8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80093F94
 * Size:	000014
 */
void DynParticle::isFree()
{
/*
.loc_0x0:
  lwz       r0, 0x48(r3)
  neg       r0, r0
  cntlzw    r0, r0
  rlwinm    r3,r0,27,5,31
  blr
*/
}
