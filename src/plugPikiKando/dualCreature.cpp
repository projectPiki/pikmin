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
 * Address:	80091EC0
 * Size:	000094
 */
DualCreature::DualCreature()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  bl        0xC14
  lis       r3, 0x802B
  subi      r0, r3, 0x9F4
  stw       r0, 0x0(r30)
  li        r31, 0
  addi      r3, r30, 0
  stb       r31, 0x43D(r30)
  lwz       r0, 0xC8(r30)
  ori       r0, r0, 0x201
  stw       r0, 0xC8(r30)
  lfs       f0, -0x5BB8(r13)
  stfs      f0, 0xD4(r30)
  lfs       f0, -0x5BB4(r13)
  stfs      f0, 0xD8(r30)
  lfs       f0, -0x5BB0(r13)
  stfs      f0, 0xDC(r30)
  lfs       f0, -0x5BAC(r13)
  stfs      f0, 0x2B8(r30)
  lfs       f0, -0x5BA8(r13)
  stfs      f0, 0x2BC(r30)
  lfs       f0, -0x5BA4(r13)
  stfs      f0, 0x2C0(r30)
  bl        0x15C
  stb       r31, 0x43F(r30)
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
 * Address:	80091F54
 * Size:	000034
 */
void DualCreature::doKill()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x1FA4
  li        r0, 0
  stb       r0, 0x43D(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80091F88
 * Size:	000060
 */
void DualCreature::isFrontFace()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  lbz       r0, 0x43C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x4C
  lfs       f0, -0x74A0(r2)
  addi      r3, r3, 0xE0
  addi      r4, r1, 0xC
  stfs      f0, 0x14(r1)
  stfs      f0, 0x10(r1)
  stfs      f0, 0xC(r1)
  bl        -0x59F34
  lfs       f1, 0x10(r1)
  lfs       f0, -0x749C(r2)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm    r3,r0,2,31,31
  b         .loc_0x50

.loc_0x4C:
  li        r3, 0x1

.loc_0x50:
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80091FE8
 * Size:	000050
 */
void DualCreature::getY()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  lbz       r0, 0x43C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  lfs       f0, -0x74A0(r2)
  addi      r3, r3, 0xE0
  addi      r4, r1, 0xC
  stfs      f0, 0x14(r1)
  stfs      f0, 0x10(r1)
  stfs      f0, 0xC(r1)
  bl        -0x59F94
  lfs       f1, 0x10(r1)
  b         .loc_0x40

.loc_0x3C:
  lfs       f1, -0x7498(r2)

.loc_0x40:
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092038
 * Size:	000054
 */
void DualCreature::onGround()
{
/*
.loc_0x0:
  lbz       r0, 0x43C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,29,29
  beq-      .loc_0x20
  li        r3, 0x1
  blr       

.loc_0x20:
  lbz       r0, 0x439(r3)
  cmplwi    r0, 0
  beq-      .loc_0x34
  li        r3, 0x1
  blr       

.loc_0x34:
  li        r3, 0
  blr       

.loc_0x3C:
  lwz       r0, 0xC8(r3)
  rlwinm    r0,r0,0,29,29
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void DualCreature::createCollisions(Graphics &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009208C
 * Size:	000050
 */
void DualCreature::useRealDynamics()
{
/*
.loc_0x0:
  mflr      r0
  mr        r5, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lbz       r0, 0x43F(r3)
  cmplwi    r0, 0
  bne-      .loc_0x38
  li        r0, 0x1
  stb       r0, 0x43E(r5)
  addi      r3, r5, 0xE0
  addi      r4, r5, 0x88
  stb       r0, 0x43C(r5)
  bl        -0x59DD4
  b         .loc_0x40

.loc_0x38:
  mr        r3, r5
  bl        .loc_0x50

.loc_0x40:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x50:
*/
}

/*
 * --INFO--
 * Address:	800920DC
 * Size:	000044
 */
void DualCreature::useSimpleDynamics()
{
/*
.loc_0x0:
  li        r0, 0x1
  stb       r0, 0x43E(r3)
  li        r0, 0
  stb       r0, 0x43C(r3)
  lfs       f0, -0x5BA0(r13)
  stfs      f0, 0xD4(r3)
  lfs       f0, -0x5B9C(r13)
  stfs      f0, 0xD8(r3)
  lfs       f0, -0x5B98(r13)
  stfs      f0, 0xDC(r3)
  lfs       f0, -0x5B94(r13)
  stfs      f0, 0x2B8(r3)
  lfs       f0, -0x5B90(r13)
  stfs      f0, 0x2BC(r3)
  lfs       f0, -0x5B8C(r13)
  stfs      f0, 0x2C0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80092120
 * Size:	0000C4
 */
void DualCreature::rotateY(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  lbz       r0, 0x43C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x88
  lfs       f3, -0x74A0(r2)
  addi      r4, r1, 0x10
  lfs       f2, -0x5B88(r13)
  addi      r3, r1, 0x1C
  stfs      f3, 0x24(r1)
  lfs       f0, -0x5B84(r13)
  stfs      f2, 0x10(r1)
  stfs      f3, 0x20(r1)
  stfs      f1, 0x14(r1)
  stfs      f3, 0x1C(r1)
  stfs      f0, 0x18(r1)
  bl        -0x59E84
  addi      r3, r1, 0x1C
  addi      r4, r31, 0xE0
  bl        -0x5A334
  lwz       r4, 0x1C(r1)
  addi      r3, r31, 0xE0
  lwz       r0, 0x20(r1)
  stw       r4, 0xE0(r31)
  stw       r0, 0xE4(r31)
  lwz       r4, 0x24(r1)
  lwz       r0, 0x28(r1)
  stw       r4, 0xE8(r31)
  stw       r0, 0xEC(r31)
  bl        -0x5A270
  b         .loc_0xB0

.loc_0x88:
  lfs       f0, 0xA0(r31)
  fadds     f1, f0, f1
  bl        -0x59C28
  stfs      f1, 0xA0(r31)
  lfs       f0, -0x5B80(r13)
  stfs      f0, 0x88(r31)
  lfs       f0, 0xA0(r31)
  stfs      f0, 0x8C(r31)
  lfs       f0, -0x5B7C(r13)
  stfs      f0, 0x90(r31)

.loc_0xB0:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800921E4
 * Size:	000034
 */
void DualCreature::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lbz       r0, 0x43C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x20
  bl        0xD0C
  b         .loc_0x24

.loc_0x20:
  bl        -0x6FFC

.loc_0x24:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092218
 * Size:	00021C
 */
void DualCreature::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  mr        r31, r4
  stw       r30, 0x50(r1)
  mr        r30, r3
  lwz       r12, 0x0(r30)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x7494(r2)
  addi      r4, r30, 0x94
  lwz       r3, 0x2E4(r31)
  fmuls     f1, f0, f1
  bl        -0x50CD0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x58
  lwz       r0, 0xC8(r30)
  rlwinm    r0,r0,0,13,11
  stw       r0, 0xC8(r30)
  b         .loc_0x64

.loc_0x58:
  lwz       r0, 0xC8(r30)
  oris      r0, r0, 0x8
  stw       r0, 0xC8(r30)

.loc_0x64:
  lbz       r0, 0x43E(r30)
  cmplwi    r0, 0
  bne-      .loc_0x144
  lbz       r4, 0x43F(r30)
  cmplwi    r4, 0
  bne-      .loc_0xF8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xF8
  lbz       r0, 0x43C(r30)
  cmplwi    r0, 0
  bne-      .loc_0x144
  cmplwi    r4, 0
  bne-      .loc_0xB4
  li        r0, 0x1
  stb       r0, 0x43E(r30)
  addi      r3, r30, 0xE0
  addi      r4, r30, 0x88
  stb       r0, 0x43C(r30)
  bl        -0x59FDC
  b         .loc_0x144

.loc_0xB4:
  li        r0, 0x1
  stb       r0, 0x43E(r30)
  li        r0, 0
  stb       r0, 0x43C(r30)
  lfs       f0, -0x5BA0(r13)
  stfs      f0, 0xD4(r30)
  lfs       f0, -0x5B9C(r13)
  stfs      f0, 0xD8(r30)
  lfs       f0, -0x5B98(r13)
  stfs      f0, 0xDC(r30)
  lfs       f0, -0x5B94(r13)
  stfs      f0, 0x2B8(r30)
  lfs       f0, -0x5B90(r13)
  stfs      f0, 0x2BC(r30)
  lfs       f0, -0x5B8C(r13)
  stfs      f0, 0x2C0(r30)
  b         .loc_0x144

.loc_0xF8:
  lbz       r0, 0x43C(r30)
  cmplwi    r0, 0
  beq-      .loc_0x144
  li        r0, 0x1
  stb       r0, 0x43E(r30)
  li        r0, 0
  stb       r0, 0x43C(r30)
  lfs       f0, -0x5BA0(r13)
  stfs      f0, 0xD4(r30)
  lfs       f0, -0x5B9C(r13)
  stfs      f0, 0xD8(r30)
  lfs       f0, -0x5B98(r13)
  stfs      f0, 0xDC(r30)
  lfs       f0, -0x5B94(r13)
  stfs      f0, 0x2B8(r30)
  lfs       f0, -0x5B90(r13)
  stfs      f0, 0x2BC(r30)
  lfs       f0, -0x5B8C(r13)
  stfs      f0, 0x2C0(r30)

.loc_0x144:
  lbz       r0, 0x43C(r30)
  cmplwi    r0, 0
  beq-      .loc_0x168
  addi      r3, r30, 0x228
  addi      r4, r30, 0x94
  addi      r5, r30, 0xE0
  addi      r6, r30, 0x7C
  bl        -0x53674
  b         .loc_0x17C

.loc_0x168:
  addi      r3, r30, 0x228
  addi      r4, r30, 0x7C
  addi      r5, r30, 0x88
  addi      r6, r30, 0x94
  bl        -0x5429C

.loc_0x17C:
  lwz       r3, 0x2E4(r31)
  addi      r4, r30, 0x228
  addi      r5, r1, 0x10
  addi      r3, r3, 0x1E0
  bl        -0x542D0
  mr        r3, r30
  lwz       r12, 0x0(r30)
  addi      r4, r31, 0
  addi      r5, r1, 0x10
  lwz       r12, 0x118(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x43C(r30)
  cmplwi    r0, 0
  beq-      .loc_0x1FC
  lbz       r0, 0x43D(r30)
  cmplwi    r0, 0
  bne-      .loc_0x1FC
  mr        r3, r30
  bl        0x934
  li        r0, 0x1
  stb       r0, 0x43D(r30)
  addi      r3, r30, 0
  addi      r4, r31, 0
  lfs       f0, -0x74A0(r2)
  stfs      f0, 0x2F4(r30)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x11C(r12)
  mtlr      r12
  blrl      
  mr        r3, r30
  bl        0x96C

.loc_0x1FC:
  li        r0, 0
  stb       r0, 0x43E(r30)
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
PelCreature::PelCreature(int, ItemShapeObject *, CreatureProp *, MapMgr *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80092434
 * Size:	000050
 */
void PelCreature::init(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0x7844
  lwz       r4, 0x494(r31)
  cmplwi    r4, 0
  beq-      .loc_0x3C
  lwz       r6, 0x30AC(r13)
  addi      r3, r31, 0x440
  lwz       r5, 0x4(r4)
  addi      r4, r4, 0x8
  lwz       r6, 0x90(r6)
  bl        0x8CCB8

.loc_0x3C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80092484
 * Size:	000008
 */
void PelCreature::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x7490(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	8009248C
 * Size:	000008
 */
u32  PelCreature::isAlive()
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	80092494
 * Size:	000060
 */
void PelCreature::startAI(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  addi      r0, r31, 0x498
  stw       r0, 0x220(r3)
  addi      r5, r31, 0x4AC
  addi      r6, r31, 0x8BC
  lwz       r4, 0x494(r3)
  lwz       r3, 0x220(r3)
  lwz       r4, 0x0(r4)
  bl        -0x8960
  addi      r3, r1, 0x10
  li        r4, 0
  bl        0x8CA88
  addi      r4, r3, 0
  addi      r3, r31, 0x440
  bl        0x8CCE4
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800924F4
 * Size:	0001C8
 */
void PelCreature::doRender(Graphics &, Matrix4f &)
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
  mr        r29, r3
  lwz       r3, 0x3120(r13)
  bl        0x84EA8
  lwz       r3, 0x2E4(r3)
  lwz       r0, 0x28(r3)
  rlwinm.   r0,r0,0,18,18
  beq-      .loc_0x11C
  lfs       f1, 0x74(r29)
  lfs       f0, -0x748C(r2)
  fadds     f0, f1, f0
  stfs      f0, 0x74(r29)
  lbz       r0, 0x43C(r29)
  cmplwi    r0, 0
  beq-      .loc_0x9C
  li        r0, 0x1
  stb       r0, 0x43E(r29)
  li        r0, 0
  stb       r0, 0x43C(r29)
  lfs       f0, -0x5BA0(r13)
  stfs      f0, 0xD4(r29)
  lfs       f0, -0x5B9C(r13)
  stfs      f0, 0xD8(r29)
  lfs       f0, -0x5B98(r13)
  stfs      f0, 0xDC(r29)
  lfs       f0, -0x5B94(r13)
  stfs      f0, 0x2B8(r29)
  lfs       f0, -0x5B90(r13)
  stfs      f0, 0x2BC(r29)
  lfs       f0, -0x5B8C(r13)
  stfs      f0, 0x2C0(r29)
  b         .loc_0x11C

.loc_0x9C:
  lfs       f0, -0x5B78(r13)
  stfs      f0, 0x88(r29)
  lfs       f0, -0x5B74(r13)
  stfs      f0, 0x8C(r29)
  lfs       f0, -0x5B70(r13)
  stfs      f0, 0x90(r29)
  lbz       r0, 0x43F(r29)
  cmplwi    r0, 0
  bne-      .loc_0xDC
  li        r0, 0x1
  stb       r0, 0x43E(r29)
  addi      r3, r29, 0xE0
  addi      r4, r29, 0x88
  stb       r0, 0x43C(r29)
  bl        -0x5A2E0
  b         .loc_0x11C

.loc_0xDC:
  li        r0, 0x1
  stb       r0, 0x43E(r29)
  li        r0, 0
  stb       r0, 0x43C(r29)
  lfs       f0, -0x5BA0(r13)
  stfs      f0, 0xD4(r29)
  lfs       f0, -0x5B9C(r13)
  stfs      f0, 0xD8(r29)
  lfs       f0, -0x5B98(r13)
  stfs      f0, 0xDC(r29)
  lfs       f0, -0x5B94(r13)
  stfs      f0, 0x2B8(r29)
  lfs       f0, -0x5B90(r13)
  stfs      f0, 0x2BC(r29)
  lfs       f0, -0x5B8C(r13)
  stfs      f0, 0x2C0(r29)

.loc_0x11C:
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  li        r4, 0x1
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x3B4(r30)
  lis       r4, 0x803A
  mr        r3, r30
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  addi      r3, r29, 0x440
  lwz       r12, 0x470(r29)
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x494(r29)
  addi      r4, r30, 0
  addi      r5, r31, 0
  lwz       r3, 0x0(r3)
  li        r6, 0
  bl        -0x5D360
  lwz       r3, 0x494(r29)
  mr        r4, r30
  lwz       r5, 0x2E4(r30)
  li        r6, 0
  lwz       r3, 0x0(r3)
  bl        -0x62220
  lwz       r3, 0x220(r29)
  addi      r4, r30, 0
  li        r5, 0
  bl        -0x8BB0
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800926BC
 * Size:	00014C
 */
void PelCreature::doCreateColls(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stfd      f31, 0x70(r1)
  stfd      f30, 0x68(r1)
  stfd      f29, 0x60(r1)
  stfd      f28, 0x58(r1)
  stfd      f27, 0x50(r1)
  stfd      f26, 0x48(r1)
  stfd      f25, 0x40(r1)
  stfd      f24, 0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r3
  lwz       r12, 0x0(r29)
  lwz       r12, 0x5C(r12)
  mtlr      r12
  blrl      
  fmr       f27, f1
  lfs       f24, -0x7488(r2)
  lfs       f28, -0x7484(r2)
  li        r30, 0
  lfd       f29, -0x7478(r2)
  lfs       f30, -0x7480(r2)
  lis       r31, 0x4330
  lfs       f31, -0x747C(r2)

.loc_0x6C:
  xoris     r0, r30, 0x8000
  stw       r0, 0x24(r1)
  stw       r31, 0x20(r1)
  lfd       f0, 0x20(r1)
  fsubs     f0, f0, f29
  fmuls     f25, f28, f0
  fmr       f1, f25
  bl        0x1895A4
  fmuls     f26, f27, f1
  fmr       f1, f25
  bl        0x189404
  fmuls     f2, f27, f1
  lfs       f0, -0x5B6C(r13)
  fmr       f1, f24
  addi      r3, r29, 0
  addi      r4, r1, 0x10
  stfs      f2, 0x10(r1)
  stfs      f0, 0x14(r1)
  stfs      f26, 0x18(r1)
  bl        0x4A0
  fadds     f25, f30, f25
  fmr       f1, f25
  bl        0x189568
  fmuls     f26, f27, f1
  fmr       f1, f25
  bl        0x1893C8
  fmuls     f1, f27, f1
  lfs       f0, -0x5B68(r13)
  addi      r3, r29, 0
  addi      r4, r1, 0x10
  stfs      f1, 0x10(r1)
  stfs      f0, 0x14(r1)
  stfs      f26, 0x18(r1)
  lfs       f0, 0x14(r1)
  fadds     f0, f0, f31
  stfs      f0, 0x14(r1)
  lfs       f1, -0x7494(r2)
  bl        0x458
  addi      r30, r30, 0x1
  cmpwi     r30, 0x4
  blt+      .loc_0x6C
  lwz       r0, 0x7C(r1)
  lfd       f31, 0x70(r1)
  lfd       f30, 0x68(r1)
  lfd       f29, 0x60(r1)
  lfd       f28, 0x58(r1)
  lfd       f27, 0x50(r1)
  lfd       f26, 0x48(r1)
  lfd       f25, 0x40(r1)
  lfd       f24, 0x38(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}
