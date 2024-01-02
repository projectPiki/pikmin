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
 * Address:	8005D0E8
 * Size:	000040
 */
void makeObjectMapObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x1C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        -0x160F8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x28
	  bl        .loc_0x40

	.loc_0x28:
	  mr        r3, r31
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr

	.loc_0x40:
	*/
}

/*
 * --INFO--
 * Address:	8005D128
 * Size:	000068
 */
GenObjectMapObject::GenObjectMapObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  subi      r6, r4, 0x7CD8
	  stwu      r1, -0x18(r1)
	  lis       r4, 0x6D6F
	  subi      r5, r5, 0x7CE4
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r4, r4, 0x626A
	  bl        0x7DB60
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802B
	  stw       r0, 0x4(r31)
	  subi      r0, r3, 0x7AFC
	  stw       r0, 0x4(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D190
 * Size:	000090
 */
void GenObjectMapObject::initialise(MapMgr*)
{
	/*
	.loc_0x0:
	  stw       r3, 0x2EB0(r13)
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x6D6F
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x626A
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x8006
	  lis       r4, 0x802B
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  subi      r6, r6, 0x2F18
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  subi      r5, r4, 0x7CD8
	  addi      r4, r3, 0x2E30
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D220
 * Size:	000040
 */
void GenObjectMapObject::doRead(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D260
 * Size:	000004
 */
void GenObjectMapObject::render(Graphics&, Generator*) { }

/*
 * --INFO--
 * Address:	8005D264
 * Size:	000008
 */
u32 GenObjectMapObject::birth(BirthInfo&) { return 0x0; }

/*
 * --INFO--
 * Address:	8005D26C
 * Size:	0002A8
 */
RigidBody::RigidBody()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  li        r4, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r31)
	  subi      r5, r3, 0x7CC4
	  lis       r3, 0x8023
	  stw       r4, 0x10(r31)
	  subi      r0, r3, 0x71E0
	  addi      r3, r31, 0
	  stw       r4, 0xC(r31)
	  stw       r4, 0x8(r31)
	  addi      r4, r5, 0
	  stw       r5, 0x4(r31)
	  stw       r0, 0x0(r31)
	  bl        -0x1CB94
	  lis       r3, 0x802A
	  addi      r0, r3, 0x5F50
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  lfs       f0, -0x7980(r2)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x20(r31)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)
	  stfs      f0, 0x2C(r31)
	  stfs      f0, 0x40(r31)
	  stfs      f0, 0x3C(r31)
	  stfs      f0, 0x38(r31)
	  stfs      f0, 0x4C(r31)
	  stfs      f0, 0x48(r31)
	  stfs      f0, 0x44(r31)
	  stfs      f0, 0x58(r31)
	  stfs      f0, 0x54(r31)
	  stfs      f0, 0x50(r31)
	  stfs      f0, 0x64(r31)
	  stfs      f0, 0x68(r31)
	  stfs      f0, 0x6C(r31)
	  stfs      f0, 0x70(r31)
	  stfs      f0, 0x74(r31)
	  stfs      f0, 0x78(r31)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  b         .loc_0x280

	.loc_0xDC:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0xF8

	.loc_0xEC:
	  stfs      f0, 0x64(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0xEC

	.loc_0xF8:
	  lfs       f0, -0x797C(r2)
	  lis       r3, 0x8003
	  addi      r29, r3, 0x5B24
	  stfs      f0, 0x84(r31)
	  addi      r4, r29, 0
	  addi      r3, r31, 0x94
	  stfs      f0, 0x74(r31)
	  li        r5, 0
	  li        r6, 0xC
	  stfs      f0, 0x64(r31)
	  li        r7, 0x400
	  bl        0x1B76E0
	  lis       r3, 0x8006
	  subi      r4, r3, 0x2988
	  addi      r3, r31, 0x4098
	  li        r5, 0
	  li        r6, 0x10
	  li        r7, 0x8
	  bl        0x1B76C4
	  lis       r3, 0x8006
	  subi      r4, r3, 0x2AD8
	  addi      r3, r31, 0x4118
	  li        r5, 0
	  li        r6, 0x308C
	  li        r7, 0x2
	  bl        0x1B76A8
	  lfs       f0, -0x7980(r2)
	  addis     r30, r31, 0x1
	  addi      r3, r30, 0
	  stfs      f0, -0x5DC8(r30)
	  mr        r4, r29
	  li        r5, 0
	  stfs      f0, -0x5DCC(r30)
	  li        r6, 0xC
	  li        r7, 0x800
	  stfs      f0, -0x5DD0(r30)
	  subi      r3, r3, 0x5DB8
	  stfs      f0, -0x5DBC(r30)
	  stfs      f0, -0x5DC0(r30)
	  stfs      f0, -0x5DC4(r30)
	  bl        0x1B766C
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x400
	  addi      r3, r3, 0x248
	  bl        0x1B7650
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x2
	  addi      r3, r3, 0x3248
	  bl        0x1B7634
	  lfs       f0, -0x7980(r2)
	  lis       r4, 0x8006
	  addi      r3, r30, 0
	  stfs      f0, 0x3268(r30)
	  subi      r4, r4, 0x2AEC
	  li        r5, 0
	  stfs      f0, 0x3264(r30)
	  li        r6, 0x10
	  li        r7, 0x2
	  stfs      f0, 0x3260(r30)
	  addi      r3, r3, 0x326C
	  bl        0x1B7604
	  lfs       f1, -0x7980(r2)
	  li        r0, 0
	  addi      r3, r31, 0
	  stfs      f1, 0x3294(r30)
	  stfs      f1, 0x3290(r30)
	  stfs      f1, 0x328C(r30)
	  stfs      f1, 0x32A4(r30)
	  stfs      f1, 0x32A0(r30)
	  stfs      f1, 0x329C(r30)
	  stfs      f1, 0x32B0(r30)
	  stfs      f1, 0x32AC(r30)
	  stfs      f1, 0x32A8(r30)
	  lfs       f0, -0x6FC0(r13)
	  stfs      f0, 0x329C(r30)
	  lfs       f0, -0x6FBC(r13)
	  stfs      f0, 0x32A0(r30)
	  lfs       f0, -0x6FB8(r13)
	  stfs      f0, 0x32A4(r30)
	  lfs       f0, -0x6FB4(r13)
	  stfs      f0, 0x32A8(r30)
	  lfs       f0, -0x6FB0(r13)
	  stfs      f0, 0x32AC(r30)
	  lfs       f0, -0x6FAC(r13)
	  stfs      f0, 0x32B0(r30)
	  stw       r0, 0x722C(r31)
	  stw       r0, 0x41A0(r31)
	  stfs      f1, 0x5C(r31)
	  stw       r0, 0x90(r31)
	  stw       r0, 0x8C(r31)
	  stw       r0, 0x4094(r31)
	  b         .loc_0x28C

	.loc_0x280:
	  rlwinm    r0,r3,2,0,29
	  add       r4, r31, r0
	  b         .loc_0xDC

	.loc_0x28C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D514
 * Size:	000014
 */
Quat::Quat()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7980(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D528
 * Size:	000150
 */
RigidBody::configuration::configuration()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lfs       f0, -0x7980(r2)
	  stfs      f0, 0x0(r3)
	  li        r3, 0x8
	  stfs      f0, 0x4(r31)
	  stfs      f0, 0x8(r31)
	  stfs      f0, 0xC(r31)
	  stfs      f0, 0x10(r31)
	  stfs      f0, 0x14(r31)
	  stfs      f0, 0x18(r31)
	  stfs      f0, 0x1C(r31)
	  b         .loc_0x124

	.loc_0x40:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x5C

	.loc_0x50:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x50

	.loc_0x5C:
	  lfs       f0, -0x797C(r2)
	  li        r3, 0x8
	  stfs      f0, 0x20(r31)
	  stfs      f0, 0x10(r31)
	  stfs      f0, 0x0(r31)
	  lfs       f0, -0x7980(r2)
	  stfs      f0, 0x2C(r31)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x3C(r31)
	  stfs      f0, 0x38(r31)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x48(r31)
	  stfs      f0, 0x44(r31)
	  stfs      f0, 0x40(r31)
	  stfs      f0, 0x54(r31)
	  stfs      f0, 0x50(r31)
	  stfs      f0, 0x4C(r31)
	  stfs      f0, 0x60(r31)
	  stfs      f0, 0x5C(r31)
	  stfs      f0, 0x58(r31)
	  stfs      f0, 0x64(r31)
	  stfs      f0, 0x68(r31)
	  stfs      f0, 0x6C(r31)
	  stfs      f0, 0x70(r31)
	  stfs      f0, 0x74(r31)
	  stfs      f0, 0x78(r31)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  b         .loc_0x130

	.loc_0xD4:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0xF0

	.loc_0xE4:
	  stfs      f0, 0x64(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0xE4

	.loc_0xF0:
	  lfs       f0, -0x797C(r2)
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  stfs      f0, 0x84(r31)
	  addi      r3, r31, 0x8C
	  li        r5, 0
	  stfs      f0, 0x74(r31)
	  li        r6, 0xC
	  li        r7, 0x400
	  stfs      f0, 0x64(r31)
	  bl        0x1B7430
	  mr        r3, r31
	  b         .loc_0x13C

	.loc_0x124:
	  rlwinm    r0,r3,2,0,29
	  add       r4, r31, r0
	  b         .loc_0x40

	.loc_0x130:
	  rlwinm    r0,r3,2,0,29
	  add       r4, r31, r0
	  b         .loc_0xD4

	.loc_0x13C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D678
 * Size:	000014
 */
WorldSpring::WorldSpring()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7980(r2)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C0
 */
DynObjBody::DynObjBody()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005D68C
 * Size:	00001C
 */
void Vector3f::set(const f32&, const f32&, const f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D6A8
 * Size:	000004
 */
void DynObjBridge::applyGroundForces(int, CollGroup*) { }

/*
 * --INFO--
 * Address:	8005D6AC
 * Size:	000034
 */
void DynObjBody::initDimensions(f32, f32, f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x50(r3)
	  stfs      f2, 0x54(r3)
	  stfs      f3, 0x58(r3)
	  lfs       f4, -0x7974(r2)
	  lfs       f5, -0x7978(r2)
	  fmuls     f1, f1, f4
	  fmuls     f0, f2, f4
	  fmuls     f2, f3, f4
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f0, f5, f0
	  stfs      f0, 0x5C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D6E0
 * Size:	000004
 */
void GenObject::updateUseList(Generator*, int) { }

/*
 * --INFO--
 * Address:	8005D6E4
 * Size:	000004
 */
void GenObject::init(Generator*) { }

/*
 * --INFO--
 * Address:	8005D6E8
 * Size:	000004
 */
void GenObject::update(Generator*) { }

/*
 * --INFO--
 * Address:	8005D6EC
 * Size:	000004
 */
void GenBase::doWrite(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	8005D6F0
 * Size:	000004
 */
void GenBase::update() { }

/*
 * --INFO--
 * Address:	8005D6F4
 * Size:	000004
 */
void GenBase::render(Graphics&) { }
