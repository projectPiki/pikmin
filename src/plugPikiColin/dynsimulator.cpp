#include "DynSimulator.h"
#include "Collision.h"
#include "Matrix3f.h"

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
 * Address:	........
 * Size:	000024
 */
void CollState::resetCollisions(Shape*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void CollState::add(Vector3f&, Vector3f&, RigidBody*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004DC00
 * Size:	00030C
 */
void RigidBody::initializeBody()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stfd      f31, 0xA8(r1)
	  stfd      f30, 0xA0(r1)
	  stw       r31, 0x9C(r1)
	  mr        r31, r3
	  stw       r30, 0x98(r1)
	  stw       r29, 0x94(r1)
	  stw       r28, 0x90(r1)
	  lfs       f1, -0x7B34(r2)
	  lfs       f0, 0x5C(r3)
	  lfs       f4, 0x58(r3)
	  li        r3, 0x8
	  fdivs     f0, f1, f0
	  lfs       f3, -0x7B38(r2)
	  lfs       f2, 0x54(r31)
	  lfs       f1, 0x50(r31)
	  stfs      f0, 0x60(r31)
	  fmuls     f4, f4, f3
	  lfs       f0, -0x7B30(r2)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x64(r31)
	  stfs      f0, 0x68(r31)
	  stfs      f0, 0x6C(r31)
	  stfs      f0, 0x70(r31)
	  stfs      f0, 0x74(r31)
	  stfs      f0, 0x78(r31)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  b         .loc_0x2CC

	.loc_0x80:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x9C

	.loc_0x90:
	  stfs      f0, 0x64(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x90

	.loc_0x9C:
	  lfs       f30, -0x7B34(r2)
	  fmuls     f5, f2, f2
	  fmuls     f0, f4, f4
	  mr        r30, r31
	  stfs      f30, 0x84(r31)
	  fmuls     f4, f1, f1
	  stfs      f30, 0x74(r31)
	  fadds     f2, f5, f0
	  li        r28, 0
	  stfs      f30, 0x64(r31)
	  fadds     f1, f4, f0
	  li        r29, 0x9
	  lfs       f3, 0x5C(r31)
	  fadds     f0, f4, f5
	  lfs       f4, -0x7B2C(r2)
	  fmuls     f2, f3, f2
	  fdivs     f2, f4, f2
	  stfs      f2, 0x64(r31)
	  lfs       f2, 0x5C(r31)
	  fmuls     f1, f2, f1
	  fdivs     f1, f4, f1
	  stfs      f1, 0x74(r31)
	  lfs       f1, 0x5C(r31)
	  fmuls     f0, f1, f0
	  fdivs     f0, f4, f0
	  stfs      f0, 0x84(r31)
	  lfs       f0, -0x7B28(r2)
	  stfs      f0, 0x88(r31)
	  lfs       f31, -0x7B30(r2)

	.loc_0x110:
	  li        r3, 0
	  cmpwi     r29, 0x8
	  stw       r3, 0x41A0(r30)
	  ble-      .loc_0x2D8
	  stfs      f31, 0x4118(r30)
	  li        r3, 0x8
	  stfs      f31, 0x411C(r30)
	  stfs      f31, 0x4120(r30)
	  stfs      f31, 0x4124(r30)
	  stfs      f31, 0x4128(r30)
	  stfs      f31, 0x412C(r30)
	  stfs      f31, 0x4130(r30)
	  stfs      f31, 0x4134(r30)
	  b         .loc_0x2D8

	.loc_0x148:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x164

	.loc_0x158:
	  stfs      f31, 0x4118(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x158

	.loc_0x164:
	  stfs      f30, 0x4138(r30)
	  addi      r3, r30, 0x413C
	  addi      r4, r30, 0x4118
	  stfs      f30, 0x4128(r30)
	  stfs      f30, 0x4118(r30)
	  lfs       f0, -0x76AC(r13)
	  stfs      f0, 0x4158(r30)
	  lfs       f0, -0x76A8(r13)
	  stfs      f0, 0x415C(r30)
	  lfs       f0, -0x76A4(r13)
	  stfs      f0, 0x4160(r30)
	  lfs       f0, -0x76A0(r13)
	  stfs      f0, 0x4164(r30)
	  lfs       f0, -0x769C(r13)
	  stfs      f0, 0x4168(r30)
	  lfs       f0, -0x7698(r13)
	  stfs      f0, 0x416C(r30)
	  lfs       f0, -0x7694(r13)
	  stfs      f0, 0x4170(r30)
	  lfs       f0, -0x7690(r13)
	  stfs      f0, 0x4174(r30)
	  lfs       f0, -0x768C(r13)
	  stfs      f0, 0x4178(r30)
	  lwz       r5, 0x20(r31)
	  lwz       r0, 0x24(r31)
	  stw       r5, 0x414C(r30)
	  stw       r0, 0x4150(r30)
	  lwz       r0, 0x28(r31)
	  stw       r0, 0x4154(r30)
	  lfs       f0, 0x2C(r31)
	  stfs      f0, 0x4118(r30)
	  lfs       f0, 0x30(r31)
	  stfs      f0, 0x411C(r30)
	  lfs       f0, 0x34(r31)
	  stfs      f0, 0x4120(r30)
	  lfs       f0, 0x38(r31)
	  stfs      f0, 0x4124(r30)
	  lfs       f0, 0x3C(r31)
	  stfs      f0, 0x4128(r30)
	  lfs       f0, 0x40(r31)
	  stfs      f0, 0x412C(r30)
	  lfs       f0, 0x44(r31)
	  stfs      f0, 0x4130(r30)
	  lfs       f0, 0x48(r31)
	  stfs      f0, 0x4134(r30)
	  lfs       f0, 0x4C(r31)
	  stfs      f0, 0x4138(r30)
	  bl        -0x16564
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r4, r28, 0
	  addi      r5, r28, 0
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x2
	  addi      r30, r30, 0x308C
	  blt+      .loc_0x110
	  addi      r4, r31, 0
	  li        r5, 0
	  b         .loc_0x2BC

	.loc_0x25C:
	  lwz       r0, 0x4098(r4)
	  addi      r5, r5, 0x1
	  lfs       f0, 0x20(r31)
	  mulli     r3, r0, 0xC
	  lfs       f2, 0x409C(r4)
	  lfs       f4, 0x28(r31)
	  lfs       f3, 0x24(r31)
	  addi      r3, r3, 0x94
	  add       r3, r31, r3
	  lfs       f1, 0x0(r3)
	  lfs       f5, 0x8(r3)
	  fadds     f0, f1, f0
	  lfs       f1, 0x4(r3)
	  fadds     f4, f5, f4
	  fadds     f1, f1, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x409C(r4)
	  lfs       f0, 0x40A0(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0x40A0(r4)
	  lfs       f0, 0x40A4(r4)
	  fadds     f0, f0, f4
	  stfs      f0, 0x40A4(r4)
	  addi      r4, r4, 0x10

	.loc_0x2BC:
	  lwz       r0, 0x4094(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x25C
	  b         .loc_0x2E4

	.loc_0x2CC:
	  rlwinm    r0,r3,2,0,29
	  add       r4, r31, r0
	  b         .loc_0x80

	.loc_0x2D8:
	  rlwinm    r0,r3,2,0,29
	  add       r4, r30, r0
	  b         .loc_0x148

	.loc_0x2E4:
	  lwz       r0, 0xB4(r1)
	  lfd       f31, 0xA8(r1)
	  lfd       f30, 0xA0(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  lwz       r28, 0x90(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004DF0C
 * Size:	000004
 */
void RigidBody::initRender(int) { }

/*
 * --INFO--
 * Address:	8004DF10
 * Size:	0001BC
 */
void RigidBody::render(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  li        r0, 0xC
	  addi      r5, r5, 0x2318
	  mtctr     r0
	  stwu      r1, -0x118(r1)
	  stmw      r27, 0x104(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addi      r6, r1, 0x98
	  subi      r4, r5, 0x8

	.loc_0x30:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x30
	  lfs       f0, -0x7688(r13)
	  addis     r4, r30, 0x1
	  addis     r5, r30, 0x1
	  lfs       f1, -0x7684(r13)
	  stfs      f0, 0x14(r1)
	  lfs       f0, -0x7680(r13)
	  addi      r6, r1, 0x14
	  stfs      f1, 0x18(r1)
	  addi      r3, r1, 0x60
	  addi      r4, r4, 0x3260
	  stfs      f0, 0x1C(r1)
	  addi      r5, r5, 0x328C
	  bl        -0xF280
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x60
	  addi      r5, r1, 0x20
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x20
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r31, 0
	  stb       r0, 0x11(r1)
	  li        r5, 0x1
	  stb       r0, 0x12(r1)
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  li        r27, 0
	  rlwinm    r0,r27,2,0,29
	  addi      r29, r1, 0xA0
	  addi      r28, r3, 0
	  add       r29, r29, r0

	.loc_0x12C:
	  mr        r3, r31
	  lwz       r4, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  lwz       r12, 0x3B4(r31)
	  mulli     r4, r4, 0xC
	  lwz       r12, 0x98(r12)
	  mulli     r5, r0, 0xC
	  mtlr      r12
	  addi      r4, r4, 0x94
	  addi      r5, r5, 0x94
	  add       r4, r30, r4
	  add       r5, r30, r5
	  blrl
	  addi      r27, r27, 0x2
	  cmpwi     r27, 0x18
	  addi      r29, r29, 0x8
	  blt+      .loc_0x12C
	  mr        r3, r31
	  lwz       r5, 0x8C(r30)
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x94
	  lwz       r12, 0x9C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lmw       r27, 0x104(r1)
	  lwz       r0, 0x11C(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004E0CC
 * Size:	000050
 */
void RigidBody::applyCMForce(Vector3f&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x0(r4)
	  addis     r5, r3, 0x1
	  lfs       f0, 0x5C(r3)
	  lfs       f2, -0x5DD0(r5)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, -0x5DD0(r5)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x5C(r3)
	  lfs       f2, -0x5DCC(r5)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, -0x5DCC(r5)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x5C(r3)
	  lfs       f2, -0x5DC8(r5)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, -0x5DC8(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004E11C
 * Size:	000D90
 */
void RigidBody::integrate(int, int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r4, r4, 0x308C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x5C8(r1)
	  stfd      f31, 0x5C0(r1)
	  stfd      f30, 0x5B8(r1)
	  stfd      f29, 0x5B0(r1)
	  stfd      f28, 0x5A8(r1)
	  stfd      f27, 0x5A0(r1)
	  stfd      f26, 0x598(r1)
	  fmr       f26, f1
	  stfd      f25, 0x590(r1)
	  stfd      f24, 0x588(r1)
	  stfd      f23, 0x580(r1)
	  stmw      r26, 0x568(r1)
	  addi      r26, r3, 0
	  addi      r28, r4, 0x4118
	  add       r28, r26, r28
	  mulli     r3, r5, 0x308C
	  addi      r5, r3, 0x4118
	  add       r5, r26, r5
	  lfs       f0, 0x40(r28)
	  addi      r27, r5, 0
	  addi      r29, r1, 0x4C8
	  fmuls     f0, f0, f26
	  addi      r30, r1, 0x4D4
	  addi      r3, r1, 0x408
	  stfs      f0, 0x2F4(r1)
	  lfs       f1, 0x34(r28)
	  lfs       f0, 0x2F4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x438(r1)
	  lfs       f0, 0x438(r1)
	  stfs      f0, 0x558(r1)
	  lfs       f0, 0x44(r28)
	  lfs       f1, 0x38(r28)
	  fmuls     f0, f0, f26
	  fadds     f0, f1, f0
	  stfs      f0, 0x55C(r1)
	  lfs       f0, 0x48(r28)
	  lfs       f1, 0x3C(r28)
	  fmuls     f0, f0, f26
	  fadds     f0, f1, f0
	  stfs      f0, 0x560(r1)
	  lwz       r4, 0x558(r1)
	  lwz       r0, 0x55C(r1)
	  stw       r4, 0x34(r5)
	  stw       r0, 0x38(r5)
	  lwz       r0, 0x560(r1)
	  stw       r0, 0x3C(r5)
	  lfs       f1, -0x7B30(r2)
	  stfs      f1, 0x4BC(r1)
	  lfs       f0, 0x54(r28)
	  fneg      f0, f0
	  stfs      f0, 0x4C0(r1)
	  lfs       f0, 0x50(r28)
	  stfs      f0, 0x4C4(r1)
	  lfs       f0, 0x54(r28)
	  stfs      f0, 0x4C8(r1)
	  stfs      f1, 0x4CC(r1)
	  lfs       f0, 0x4C(r28)
	  fneg      f0, f0
	  stfs      f0, 0x4D0(r1)
	  lfs       f0, 0x50(r28)
	  fneg      f0, f0
	  stfs      f0, 0x4D4(r1)
	  lfs       f0, 0x4C(r28)
	  stfs      f0, 0x4D8(r1)
	  stfs      f1, 0x4DC(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x4BC(r1)
	  addi      r3, r1, 0x3D8
	  fmuls     f0, f26, f0
	  stfs      f0, 0x408(r1)
	  lfs       f0, 0x4C8(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x414(r1)
	  lfs       f0, 0x4D4(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x420(r1)
	  lfs       f0, 0x4C0(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x40C(r1)
	  lfs       f0, 0x4(r29)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x418(r1)
	  lfs       f0, 0x4(r30)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x424(r1)
	  lfs       f0, 0x4C4(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x410(r1)
	  lfs       f0, 0x8(r29)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x41C(r1)
	  lfs       f0, 0x8(r30)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x428(r1)
	  lwz       r0, 0x408(r1)
	  lwz       r4, 0x40C(r1)
	  stw       r0, 0x4E0(r1)
	  lwz       r0, 0x410(r1)
	  stw       r4, 0x4E4(r1)
	  lwz       r4, 0x414(r1)
	  stw       r0, 0x4E8(r1)
	  lwz       r0, 0x418(r1)
	  stw       r4, 0x4EC(r1)
	  lwz       r4, 0x41C(r1)
	  stw       r0, 0x4F0(r1)
	  lwz       r0, 0x420(r1)
	  stw       r4, 0x4F4(r1)
	  lwz       r4, 0x424(r1)
	  stw       r0, 0x4F8(r1)
	  lwz       r0, 0x428(r1)
	  stw       r4, 0x4FC(r1)
	  stw       r0, 0x500(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x0(r28)
	  addi      r5, r1, 0x3D8
	  lfs       f1, 0x4E0(r1)
	  addi      r6, r1, 0x4E0
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0xC(r28)
	  lfs       f5, 0x4E4(r1)
	  addi      r5, r5, 0xC
	  lfs       f1, 0x4E8(r1)
	  fadds     f3, f3, f2
	  lfs       f0, 0x18(r28)
	  fmuls     f2, f5, f4
	  addi      r6, r6, 0xC
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x3D8(r1)
	  lfs       f0, 0x4(r28)
	  lfs       f1, 0x4E0(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x10(r28)
	  lfs       f5, 0x4E4(r1)
	  lfs       f0, 0x1C(r28)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x4E8(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x3DC(r1)
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x4E0(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x14(r28)
	  lfs       f5, 0x4E4(r1)
	  lfs       f1, 0x4E8(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x20(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x3E0(r1)
	  lfs       f0, 0x0(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0xC(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x18(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x4(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x10(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x1C(r28)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x14(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  addi      r6, r6, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x20(r28)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  addi      r5, r5, 0xC
	  lfs       f0, 0x0(r28)
	  addi      r3, r1, 0x3B0
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0xC(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x18(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x4(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x10(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x1C(r28)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x14(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x20(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  lwz       r0, 0x3D8(r1)
	  lwz       r4, 0x3DC(r1)
	  stw       r0, 0x504(r1)
	  lwz       r0, 0x3E0(r1)
	  stw       r4, 0x508(r1)
	  lwz       r4, 0x3E4(r1)
	  stw       r0, 0x50C(r1)
	  lwz       r0, 0x3E8(r1)
	  stw       r4, 0x510(r1)
	  lwz       r4, 0x3EC(r1)
	  stw       r0, 0x514(r1)
	  lwz       r0, 0x3F0(r1)
	  stw       r4, 0x518(r1)
	  lwz       r4, 0x3F4(r1)
	  stw       r0, 0x51C(r1)
	  lwz       r0, 0x3F8(r1)
	  stw       r4, 0x520(r1)
	  stw       r0, 0x524(r1)
	  bl        .loc_0xD90
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x504(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3B0(r1)
	  lfs       f1, 0xC(r28)
	  lfs       f0, 0x510(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3BC(r1)
	  lfs       f1, 0x18(r28)
	  lfs       f0, 0x51C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C8(r1)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x508(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3B4(r1)
	  lfs       f1, 0x10(r28)
	  lfs       f0, 0x514(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C0(r1)
	  lfs       f1, 0x1C(r28)
	  lfs       f0, 0x520(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3CC(r1)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x50C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3B8(r1)
	  lfs       f1, 0x14(r28)
	  lfs       f0, 0x518(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C4(r1)
	  lfs       f1, 0x20(r28)
	  lfs       f0, 0x524(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3D0(r1)
	  lwz       r0, 0x3B0(r1)
	  addis     r3, r26, 0x1
	  lwz       r4, 0x3B4(r1)
	  addi      r29, r27, 0x1C
	  stw       r0, 0x528(r1)
	  lwz       r0, 0x3B8(r1)
	  addi      r30, r27, 0x10
	  stw       r4, 0x52C(r1)
	  addi      r31, r27, 0x4
	  lwz       r4, 0x3BC(r1)
	  stw       r0, 0x530(r1)
	  lwz       r0, 0x3C0(r1)
	  stw       r4, 0x534(r1)
	  lwz       r4, 0x3C4(r1)
	  stw       r0, 0x538(r1)
	  lwz       r0, 0x3C8(r1)
	  stw       r4, 0x53C(r1)
	  lwz       r4, 0x3CC(r1)
	  stw       r0, 0x540(r1)
	  lwz       r0, 0x3D0(r1)
	  stw       r4, 0x544(r1)
	  stw       r0, 0x548(r1)
	  lwz       r4, 0x528(r1)
	  lwz       r0, 0x52C(r1)
	  stw       r4, 0x0(r27)
	  stw       r0, 0x4(r27)
	  lwz       r4, 0x530(r1)
	  lwz       r0, 0x534(r1)
	  stw       r4, 0x8(r27)
	  stw       r0, 0xC(r27)
	  lwz       r4, 0x538(r1)
	  lwz       r0, 0x53C(r1)
	  stw       r4, 0x10(r27)
	  stw       r0, 0x14(r27)
	  lwz       r4, 0x540(r1)
	  lwz       r0, 0x544(r1)
	  stw       r4, 0x18(r27)
	  stw       r0, 0x1C(r27)
	  lwz       r0, 0x548(r1)
	  stw       r0, 0x20(r27)
	  lfs       f1, 0x60(r26)
	  lfs       f0, -0x5DD0(r3)
	  fmuls     f2, f26, f1
	  lfs       f1, 0x40(r28)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r27)
	  lfs       f0, -0x5DCC(r3)
	  lfs       f1, 0x44(r28)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x44(r27)
	  lfs       f0, -0x5DC8(r3)
	  lfs       f1, 0x48(r28)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r27)
	  lfs       f0, -0x5DC4(r3)
	  lfs       f1, 0x58(r28)
	  fmuls     f0, f26, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r27)
	  lfs       f0, -0x5DC0(r3)
	  lfs       f1, 0x5C(r28)
	  fmuls     f0, f26, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r27)
	  lfs       f0, -0x5DBC(r3)
	  lfs       f1, 0x60(r28)
	  fmuls     f0, f26, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x60(r27)
	  lfs       f31, 0x0(r27)
	  lfs       f30, 0xC(r27)
	  lfs       f29, 0x18(r27)
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  lfs       f28, 0x4(r27)
	  fmuls     f2, f29, f29
	  lfs       f27, 0x10(r27)
	  fadds     f0, f1, f0
	  lfs       f26, 0x1C(r27)
	  fadds     f1, f2, f0
	  bl        -0x40AEC
	  lfs       f0, -0x7B30(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x62C
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x62C:
	  fmuls     f3, f30, f26
	  fmuls     f2, f29, f27
	  fmuls     f1, f29, f28
	  fmuls     f0, f31, f26
	  fsubs     f26, f3, f2
	  fmuls     f3, f31, f27
	  fsubs     f27, f1, f0
	  fmuls     f2, f30, f28
	  fmuls     f1, f26, f26
	  fmuls     f0, f27, f27
	  fsubs     f28, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f28, f28
	  fadds     f1, f1, f0
	  bl        -0x40B40
	  lfs       f0, -0x7B30(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x680
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x680:
	  fmuls     f3, f27, f29
	  fmuls     f2, f28, f30
	  fmuls     f1, f28, f31
	  fmuls     f0, f26, f29
	  fsubs     f25, f3, f2
	  fmuls     f3, f26, f30
	  fsubs     f24, f1, f0
	  fmuls     f2, f27, f31
	  fmuls     f1, f25, f25
	  fmuls     f0, f24, f24
	  fsubs     f23, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f23, f23
	  fadds     f1, f1, f0
	  bl        -0x40B94
	  lfs       f0, -0x7B30(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x6D4
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x6D4:
	  stfs      f31, 0x0(r27)
	  addi      r4, r27, 0
	  addi      r3, r27, 0x24
	  stfs      f25, 0x0(r31)
	  stfs      f26, 0x8(r27)
	  stfs      f30, 0xC(r27)
	  stfs      f24, 0x0(r30)
	  stfs      f27, 0x14(r27)
	  stfs      f29, 0x18(r27)
	  stfs      f23, 0x0(r29)
	  stfs      f28, 0x20(r27)
	  bl        -0x16F60
	  addi      r3, r1, 0x360
	  bl        .loc_0xD90
	  lfs       f1, 0x0(r27)
	  addi      r5, r1, 0x360
	  lfs       f0, 0x64(r26)
	  addi      r6, r27, 0xC
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r26)
	  lfs       f5, 0x4(r27)
	  addi      r5, r5, 0xC
	  lfs       f0, 0x7C(r26)
	  fadds     f3, f3, f2
	  lfs       f1, 0x8(r27)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x360(r1)
	  lfs       f0, 0x68(r26)
	  lfs       f1, 0x0(r27)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r26)
	  lfs       f5, 0x4(r27)
	  lfs       f0, 0x80(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r27)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x364(r1)
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0x0(r27)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r26)
	  lfs       f5, 0x4(r27)
	  lfs       f1, 0x8(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r26)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x368(r1)
	  lfs       f1, 0x0(r6)
	  lfs       f0, 0x64(r26)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  addi      r6, r6, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x84(r26)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  addi      r5, r5, 0xC
	  lfs       f1, 0x0(r6)
	  addi      r31, r1, 0x474
	  lfs       f0, 0x64(r26)
	  addi      r3, r1, 0x338
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r26)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  lwz       r0, 0x360(r1)
	  lwz       r4, 0x364(r1)
	  stw       r0, 0x474(r1)
	  lwz       r0, 0x368(r1)
	  stw       r4, 0x478(r1)
	  lwz       r4, 0x36C(r1)
	  stw       r0, 0x47C(r1)
	  lwz       r0, 0x370(r1)
	  stw       r4, 0x480(r1)
	  lwz       r4, 0x374(r1)
	  stw       r0, 0x484(r1)
	  lwz       r0, 0x378(r1)
	  stw       r4, 0x488(r1)
	  lwz       r4, 0x37C(r1)
	  stw       r0, 0x48C(r1)
	  lwz       r0, 0x380(r1)
	  stw       r4, 0x490(r1)
	  stw       r0, 0x494(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x0(r27)
	  addi      r3, r1, 0x30C
	  stfs      f0, 0x338(r1)
	  lfs       f0, 0x4(r27)
	  stfs      f0, 0x344(r1)
	  lfs       f0, 0x8(r27)
	  stfs      f0, 0x350(r1)
	  lfs       f0, 0xC(r27)
	  stfs      f0, 0x33C(r1)
	  lfs       f0, 0x10(r27)
	  stfs      f0, 0x348(r1)
	  lfs       f0, 0x14(r27)
	  stfs      f0, 0x354(r1)
	  lfs       f0, 0x18(r27)
	  stfs      f0, 0x340(r1)
	  lfs       f0, 0x1C(r27)
	  stfs      f0, 0x34C(r1)
	  lfs       f0, 0x20(r27)
	  stfs      f0, 0x358(r1)
	  lwz       r0, 0x338(r1)
	  lwz       r4, 0x33C(r1)
	  stw       r0, 0x450(r1)
	  lwz       r0, 0x340(r1)
	  stw       r4, 0x454(r1)
	  lwz       r4, 0x344(r1)
	  stw       r0, 0x458(r1)
	  lwz       r0, 0x348(r1)
	  stw       r4, 0x45C(r1)
	  lwz       r4, 0x34C(r1)
	  stw       r0, 0x460(r1)
	  lwz       r0, 0x350(r1)
	  stw       r4, 0x464(r1)
	  lwz       r4, 0x354(r1)
	  stw       r0, 0x468(r1)
	  lwz       r0, 0x358(r1)
	  stw       r4, 0x46C(r1)
	  stw       r0, 0x470(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x450(r1)
	  addi      r4, r1, 0x30C
	  lfs       f1, 0x474(r1)
	  addi      r5, r31, 0xC
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x45C(r1)
	  lfs       f5, 0x478(r1)
	  addi      r4, r4, 0xC
	  lfs       f1, 0x47C(r1)
	  fadds     f3, f3, f2
	  lfs       f0, 0x468(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x30C(r1)
	  lfs       f0, 0x454(r1)
	  lfs       f1, 0x474(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x460(r1)
	  lfs       f5, 0x478(r1)
	  lfs       f1, 0x47C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x46C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x310(r1)
	  lfs       f0, 0x458(r1)
	  lfs       f1, 0x474(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x464(r1)
	  lfs       f5, 0x478(r1)
	  lfs       f1, 0x47C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x470(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x314(r1)
	  lfs       f0, 0x450(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x45C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x468(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x454(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x460(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x46C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x458(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x464(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  addi      r5, r5, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x470(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  addi      r4, r4, 0xC
	  lfs       f0, 0x450(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x45C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x468(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x454(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x460(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x46C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x458(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x464(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x470(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  lwz       r0, 0x30C(r1)
	  lwz       r3, 0x310(r1)
	  stw       r0, 0x498(r1)
	  lwz       r0, 0x314(r1)
	  stw       r3, 0x49C(r1)
	  lwz       r3, 0x318(r1)
	  stw       r0, 0x4A0(r1)
	  lwz       r0, 0x31C(r1)
	  stw       r3, 0x4A4(r1)
	  lwz       r3, 0x320(r1)
	  stw       r0, 0x4A8(r1)
	  lwz       r0, 0x324(r1)
	  stw       r3, 0x4AC(r1)
	  lwz       r3, 0x328(r1)
	  stw       r0, 0x4B0(r1)
	  lwz       r0, 0x32C(r1)
	  stw       r3, 0x4B4(r1)
	  stw       r0, 0x4B8(r1)
	  lwz       r3, 0x498(r1)
	  lwz       r0, 0x49C(r1)
	  stw       r3, 0x64(r27)
	  stw       r0, 0x68(r27)
	  lwz       r3, 0x4A0(r1)
	  lwz       r0, 0x4A4(r1)
	  stw       r3, 0x6C(r27)
	  stw       r0, 0x70(r27)
	  lwz       r3, 0x4A8(r1)
	  lwz       r0, 0x4AC(r1)
	  stw       r3, 0x74(r27)
	  stw       r0, 0x78(r27)
	  lwz       r3, 0x4B0(r1)
	  lwz       r0, 0x4B4(r1)
	  stw       r3, 0x7C(r27)
	  stw       r0, 0x80(r27)
	  lwz       r0, 0x4B8(r1)
	  stw       r0, 0x84(r27)
	  lfs       f0, -0x7B30(r2)
	  stfs      f0, 0x308(r1)
	  stfs      f0, 0x304(r1)
	  stfs      f0, 0x300(r1)
	  lfs       f4, 0x58(r27)
	  lfs       f1, 0x64(r27)
	  lfs       f3, 0x5C(r27)
	  lfs       f0, 0x68(r27)
	  fmuls     f1, f4, f1
	  lfs       f5, 0x60(r27)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x6C(r27)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x300(r1)
	  lfs       f1, 0x70(r27)
	  lfs       f0, 0x74(r27)
	  lfs       f2, 0x78(r27)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x304(r1)
	  lfs       f1, 0x7C(r27)
	  lfs       f0, 0x80(r27)
	  lfs       f2, 0x84(r27)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x308(r1)
	  lfs       f0, 0x300(r1)
	  stfs      f0, 0x444(r1)
	  lfs       f0, 0x304(r1)
	  stfs      f0, 0x448(r1)
	  lfs       f0, 0x308(r1)
	  stfs      f0, 0x44C(r1)
	  lwz       r3, 0x444(r1)
	  lwz       r0, 0x448(r1)
	  stw       r3, 0x4C(r27)
	  stw       r0, 0x50(r27)
	  lwz       r0, 0x44C(r1)
	  stw       r0, 0x54(r27)
	  lmw       r26, 0x568(r1)
	  lwz       r0, 0x5CC(r1)
	  lfd       f31, 0x5C0(r1)
	  lfd       f30, 0x5B8(r1)
	  lfd       f29, 0x5B0(r1)
	  lfd       f28, 0x5A8(r1)
	  lfd       f27, 0x5A0(r1)
	  lfd       f26, 0x598(r1)
	  lfd       f25, 0x590(r1)
	  lfd       f24, 0x588(r1)
	  lfd       f23, 0x580(r1)
	  addi      r1, r1, 0x5C8
	  mtlr      r0
	  blr

	.loc_0xD90:
	*/
}

/*
 * --INFO--
 * Address:	8004EEAC
 * Size:	00006C
 */
void Matrix3f::identity()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7B30(r2)
	  li        r5, 0x8
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  b         .loc_0x5C

	.loc_0x2C:
	  subfic    r0, r5, 0x9
	  cmpwi     r5, 0x9
	  mtctr     r0
	  bge-      .loc_0x48

	.loc_0x3C:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x3C

	.loc_0x48:
	  lfs       f0, -0x7B34(r2)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0x0(r3)
	  blr

	.loc_0x5C:
	  rlwinm    r0,r5,2,0,29
	  add       r4, r3, r0
	  b         .loc_0x2C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004EF18
 * Size:	00034C
 */
void RigidBody::resolveCollisions(int, Collision&)
{
	/*
	.loc_0x0:
	  mulli     r4, r4, 0x308C
	  stwu      r1, -0x1C0(r1)
	  stfd      f31, 0x1B8(r1)
	  addi      r6, r4, 0x4118
	  add       r6, r3, r6
	  lfs       f6, 0x18(r5)
	  lfs       f3, 0x3C(r6)
	  lfs       f4, 0x14(r5)
	  lfs       f2, 0x38(r6)
	  fsubs     f3, f6, f3
	  lfs       f13, 0x50(r6)
	  lfs       f9, 0x4C(r6)
	  fsubs     f2, f4, f2
	  lfs       f8, 0x54(r6)
	  fmuls     f6, f9, f3
	  lfs       f1, 0x10(r5)
	  lfs       f0, 0x34(r6)
	  fmuls     f11, f13, f3
	  lfs       f7, 0x40(r6)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x44(r6)
	  fmuls     f4, f8, f2
	  fmuls     f9, f9, f2
	  lfs       f5, 0x4(r5)
	  fsubs     f12, f11, f4
	  lfs       f10, 0x48(r6)
	  fmuls     f8, f8, f1
	  lfs       f4, 0x8(r5)
	  fsubs     f11, f8, f6
	  lfs       f6, 0xC(r5)
	  fmuls     f8, f13, f1
	  fadds     f11, f0, f11
	  lfs       f0, -0x7B30(r2)
	  fsubs     f8, f9, f8
	  fadds     f9, f7, f12
	  fmuls     f7, f4, f11
	  fadds     f10, f10, f8
	  fmuls     f8, f5, f9
	  fmuls     f9, f6, f10
	  fadds     f7, f8, f7
	  fadds     f31, f9, f7
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x33C
	  fmuls     f8, f2, f6
	  lfs       f12, 0x88(r3)
	  fmuls     f7, f3, f4
	  lfs       f13, -0x7B34(r2)
	  fmuls     f10, f3, f5
	  fsubs     f11, f8, f7
	  fmuls     f9, f1, f6
	  fmuls     f8, f1, f4
	  fmuls     f7, f2, f5
	  stfs      f11, 0x148(r1)
	  fsubs     f9, f10, f9
	  fadds     f10, f13, f12
	  fsubs     f7, f8, f7
	  stfs      f9, 0x14C(r1)
	  fneg      f8, f10
	  stfs      f7, 0x150(r1)
	  stfs      f0, 0x120(r1)
	  fmuls     f7, f8, f31
	  stfs      f0, 0x11C(r1)
	  stfs      f0, 0x118(r1)
	  lfs       f12, 0x148(r1)
	  lfs       f9, 0x64(r6)
	  lfs       f11, 0x14C(r1)
	  lfs       f8, 0x68(r6)
	  fmuls     f9, f12, f9
	  lfs       f13, 0x150(r1)
	  fmuls     f8, f11, f8
	  lfs       f10, 0x6C(r6)
	  fmuls     f10, f13, f10
	  fadds     f8, f9, f8
	  fadds     f8, f10, f8
	  stfs      f8, 0x118(r1)
	  lfs       f9, 0x70(r6)
	  lfs       f8, 0x74(r6)
	  lfs       f10, 0x78(r6)
	  fmuls     f9, f12, f9
	  fmuls     f8, f11, f8
	  fmuls     f10, f13, f10
	  fadds     f8, f9, f8
	  fadds     f8, f10, f8
	  stfs      f8, 0x11C(r1)
	  lfs       f9, 0x7C(r6)
	  lfs       f8, 0x80(r6)
	  lfs       f10, 0x84(r6)
	  fmuls     f9, f12, f9
	  fmuls     f8, f11, f8
	  fmuls     f10, f13, f10
	  fadds     f8, f9, f8
	  fadds     f8, f10, f8
	  stfs      f8, 0x120(r1)
	  lfs       f8, 0x118(r1)
	  stfs      f8, 0x154(r1)
	  lfs       f8, 0x11C(r1)
	  stfs      f8, 0x158(r1)
	  lfs       f8, 0x120(r1)
	  stfs      f8, 0x15C(r1)
	  lfs       f10, 0x15C(r1)
	  lfs       f13, 0x158(r1)
	  lfs       f31, 0x154(r1)
	  fmuls     f8, f10, f2
	  fmuls     f9, f13, f3
	  fmuls     f11, f10, f1
	  fmuls     f10, f31, f3
	  fsubs     f12, f9, f8
	  fmuls     f9, f31, f2
	  fmuls     f8, f13, f1
	  fsubs     f10, f11, f10
	  stfs      f12, 0x160(r1)
	  fsubs     f8, f9, f8
	  stfs      f10, 0x164(r1)
	  stfs      f8, 0x168(r1)
	  lfs       f9, 0x160(r1)
	  lfs       f11, 0x168(r1)
	  lfs       f8, 0x164(r1)
	  fmuls     f10, f9, f5
	  fmuls     f11, f11, f6
	  lfs       f12, 0x60(r3)
	  fmuls     f9, f8, f4
	  lfs       f8, 0x40(r6)
	  fadds     f9, f10, f9
	  fadds     f9, f11, f9
	  fadds     f9, f12, f9
	  fdivs     f7, f7, f9
	  fmuls     f9, f7, f5
	  fmuls     f10, f7, f4
	  fmuls     f11, f7, f6
	  fmuls     f4, f12, f9
	  fadds     f4, f8, f4
	  stfs      f4, 0x40(r6)
	  lfs       f4, 0x60(r3)
	  fmuls     f6, f2, f11
	  fmuls     f5, f3, f10
	  lfs       f8, 0x44(r6)
	  fmuls     f7, f4, f10
	  fmuls     f4, f3, f9
	  fmuls     f3, f1, f11
	  fadds     f7, f8, f7
	  fsubs     f5, f6, f5
	  fsubs     f4, f4, f3
	  stfs      f7, 0x44(r6)
	  fmuls     f3, f1, f10
	  fmuls     f1, f2, f9
	  lfs       f6, 0x60(r3)
	  lfs       f7, 0x48(r6)
	  li        r3, 0x1
	  fmuls     f2, f6, f11
	  fsubs     f1, f3, f1
	  fadds     f2, f7, f2
	  stfs      f2, 0x48(r6)
	  lfs       f2, 0x58(r6)
	  fadds     f2, f2, f5
	  stfs      f2, 0x58(r6)
	  lfs       f2, 0x5C(r6)
	  fadds     f2, f2, f4
	  stfs      f2, 0x5C(r6)
	  lfs       f2, 0x60(r6)
	  fadds     f1, f2, f1
	  stfs      f1, 0x60(r6)
	  stfs      f0, 0x104(r1)
	  stfs      f0, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f4, 0x58(r6)
	  lfs       f1, 0x64(r6)
	  lfs       f3, 0x5C(r6)
	  lfs       f0, 0x68(r6)
	  fmuls     f1, f4, f1
	  lfs       f5, 0x60(r6)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x6C(r6)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xFC(r1)
	  lfs       f1, 0x70(r6)
	  lfs       f0, 0x74(r6)
	  lfs       f2, 0x78(r6)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x100(r1)
	  lfs       f1, 0x7C(r6)
	  lfs       f0, 0x80(r6)
	  lfs       f2, 0x84(r6)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x104(r1)
	  lfs       f0, 0xFC(r1)
	  stfs      f0, 0x130(r1)
	  lfs       f0, 0x100(r1)
	  stfs      f0, 0x134(r1)
	  lfs       f0, 0x104(r1)
	  stfs      f0, 0x138(r1)
	  lwz       r4, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stw       r4, 0x4C(r6)
	  stw       r0, 0x50(r6)
	  lwz       r0, 0x138(r1)
	  stw       r0, 0x54(r6)
	  b         .loc_0x340

	.loc_0x33C:
	  li        r3, 0

	.loc_0x340:
	  lfd       f31, 0x1B8(r1)
	  addi      r1, r1, 0x1C0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004F264
 * Size:	000398
 */
void RigidBody::applyGroundForces(int, CollGroup*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stmw      r20, 0xC0(r1)
	  addi      r22, r4, 0
	  mulli     r4, r22, 0x308C
	  addi      r21, r3, 0
	  addi      r29, r4, 0x4118
	  addi      r23, r5, 0
	  addi      r4, r21, 0
	  add       r29, r21, r29
	  li        r5, 0
	  li        r3, 0
	  b         .loc_0x48

	.loc_0x3C:
	  stw       r3, 0x3094(r4)
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0x1

	.loc_0x48:
	  lwz       r0, 0x8C(r21)
	  cmpw      r5, r0
	  blt+      .loc_0x3C
	  lfs       f31, -0x7B30(r2)
	  addi      r30, r21, 0
	  addi      r24, r29, 0x34
	  li        r28, 0
	  b         .loc_0x354

	.loc_0x68:
	  lwz       r0, 0x90(r21)
	  cmplwi    r23, 0
	  add       r0, r28, r0
	  mulli     r3, r0, 0xC
	  addi      r27, r3, 0x8C
	  add       r27, r29, r27
	  beq-      .loc_0x8C
	  li        r0, 0
	  b         .loc_0x90

	.loc_0x8C:
	  li        r0, 0x1

	.loc_0x90:
	  rlwinm    r20,r0,0,24,31
	  li        r26, 0
	  li        r31, 0
	  b         .loc_0x338

	.loc_0xA0:
	  lwz       r3, 0x8(r23)
	  lfs       f12, 0x0(r27)
	  lwzx      r3, r3, r31
	  lfs       f10, 0x4(r27)
	  addi      r25, r3, 0x18
	  lfs       f8, 0x8(r27)
	  lfs       f5, 0x18(r3)
	  mr        r0, r3
	  lfs       f4, 0x1C(r3)
	  fmuls     f1, f5, f12
	  lfs       f6, 0x20(r3)
	  fmuls     f0, f4, f10
	  lfs       f13, 0x0(r24)
	  lfs       f11, 0x4(r24)
	  fmuls     f3, f6, f8
	  lfs       f9, 0x8(r24)
	  fadds     f2, f1, f0
	  lfs       f7, 0x24(r3)
	  fmuls     f1, f5, f13
	  fmuls     f0, f4, f11
	  fadds     f3, f3, f2
	  fmuls     f2, f6, f9
	  fadds     f0, f1, f0
	  fsubs     f3, f3, f7
	  fadds     f0, f2, f0
	  fcmpo     cr0, f3, f31
	  fsubs     f0, f0, f7
	  bge-      .loc_0x330
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x330
	  fsubs     f2, f3, f0
	  mr        r3, r0
	  fsubs     f0, f13, f12
	  li        r4, 0x1
	  fsubs     f1, f11, f10
	  fdivs     f3, f3, f2
	  li        r5, 0
	  fmuls     f2, f3, f0
	  fsubs     f0, f9, f8
	  fmuls     f1, f3, f1
	  fadds     f2, f12, f2
	  fmuls     f0, f3, f0
	  fadds     f1, f10, f1
	  stfs      f2, 0xA8(r1)
	  fadds     f0, f8, f0
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f4, 0xAC(r1)
	  lfs       f5, 0xA8(r1)
	  lfs       f6, 0xB0(r1)
	  b         .loc_0x1A8

	.loc_0x16C:
	  lfs       f1, 0x28(r3)
	  lfs       f0, 0x2C(r3)
	  fmuls     f2, f1, f5
	  lfs       f3, 0x30(r3)
	  fmuls     f1, f0, f4
	  lfs       f0, 0x34(r3)
	  fmuls     f3, f3, f6
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x1A0
	  li        r4, 0

	.loc_0x1A0:
	  addi      r3, r3, 0x10
	  addi      r5, r5, 0x1

	.loc_0x1A8:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x1B8
	  cmpwi     r5, 0x3
	  blt+      .loc_0x16C

	.loc_0x1B8:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x330
	  lfs       f2, 0x8(r27)
	  lfs       f1, 0x3C(r29)
	  lfs       f3, 0x4(r27)
	  lfs       f0, 0x38(r29)
	  fsubs     f5, f2, f1
	  lfs       f2, 0x0(r27)
	  lfs       f1, 0x34(r29)
	  fsubs     f6, f3, f0
	  lfs       f0, 0x4C(r29)
	  fsubs     f7, f2, f1
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x50(r29)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x54(r29)
	  stfs      f0, 0x94(r1)
	  lfs       f3, 0x94(r1)
	  lfs       f8, 0x90(r1)
	  lfs       f2, 0x8C(r1)
	  fmuls     f0, f3, f6
	  fmuls     f1, f8, f5
	  fmuls     f4, f3, f7
	  fmuls     f3, f2, f5
	  fsubs     f0, f1, f0
	  fmuls     f2, f2, f6
	  fmuls     f1, f8, f7
	  fsubs     f3, f4, f3
	  stfs      f0, 0x8C(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x90(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x40(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8C(r1)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x44(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r1)
	  lfs       f1, 0x94(r1)
	  lfs       f0, 0x48(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  lfs       f3, 0x8C(r1)
	  lfs       f2, 0x0(r25)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x4(r25)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x94(r1)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r25)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x330
	  lwz       r5, 0x3094(r30)
	  addi      r3, r21, 0
	  addi      r4, r22, 0
	  addi      r0, r5, 0x1
	  stw       r0, 0x3094(r30)
	  addi      r5, r1, 0x68
	  stfs      f31, 0x74(r1)
	  stfs      f31, 0x70(r1)
	  stfs      f31, 0x6C(r1)
	  stfs      f31, 0x80(r1)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x78(r1)
	  lwz       r6, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r6, 0x78(r1)
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x80(r1)
	  lwz       r6, 0x0(r25)
	  lwz       r0, 0x4(r25)
	  stw       r6, 0x6C(r1)
	  stw       r0, 0x70(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x74(r1)
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  addi      r4, r22, 0
	  addi      r5, r25, 0
	  lwz       r12, 0x54(r12)
	  addi      r6, r1, 0xA8
	  addi      r7, r1, 0x8C
	  mtlr      r12
	  blrl

	.loc_0x330:
	  addi      r31, r31, 0x4
	  addi      r26, r26, 0x1

	.loc_0x338:
	  cmplwi    r20, 0
	  bne-      .loc_0x34C
	  lha       r0, 0x4(r23)
	  cmpw      r26, r0
	  blt+      .loc_0xA0

	.loc_0x34C:
	  addi      r30, r30, 0x4
	  addi      r28, r28, 0x1

	.loc_0x354:
	  lwz       r0, 0x8C(r21)
	  cmpw      r28, r0
	  blt+      .loc_0x68
	  cmpwi     r0, 0
	  mtctr     r0
	  addi      r3, r21, 0
	  ble-      .loc_0x380

	.loc_0x370:
	  lwz       r0, 0x3094(r3)
	  cmpwi     r0, 0x1
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x370

	.loc_0x380:
	  lmw       r20, 0xC0(r1)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004F5FC
 * Size:	0001B8
 */
void RigidBody::applyBodyFriction(int, Vector3f&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stfd      f29, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r6
	  stw       r30, 0x88(r1)
	  mr        r30, r4
	  stw       r29, 0x84(r1)
	  mr        r29, r3
	  lfs       f9, 0x0(r7)
	  lfs       f8, 0x4(r7)
	  lfs       f5, 0x0(r5)
	  fmuls     f1, f9, f9
	  lfs       f6, 0x4(r5)
	  fmuls     f0, f8, f8
	  fmuls     f3, f9, f5
	  fmuls     f2, f8, f6
	  lfs       f10, 0x8(r7)
	  fadds     f0, f1, f0
	  lfs       f7, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f4, f10, f7
	  fmuls     f2, f10, f10
	  fadds     f4, f4, f3
	  fadds     f1, f2, f0
	  fmuls     f3, f4, f5
	  fmuls     f2, f4, f6
	  fmuls     f0, f4, f7
	  fsubs     f3, f3, f9
	  fsubs     f2, f2, f8
	  fsubs     f0, f0, f10
	  fneg      f31, f3
	  fneg      f30, f2
	  fneg      f29, f0
	  bl        -0x41A50
	  mulli     r0, r30, 0x308C
	  lfs       f2, 0x8(r31)
	  fneg      f1, f1
	  lfs       f3, -0x7B24(r2)
	  add       r7, r29, r0
	  lfs       f0, 0x4154(r7)
	  fmuls     f1, f3, f1
	  addi      r6, r1, 0x3C
	  fsubs     f0, f2, f0
	  addi      r5, r1, 0x38
	  fmuls     f31, f31, f1
	  fmuls     f30, f30, f1
	  addi      r4, r1, 0x34
	  stfs      f0, 0x3C(r1)
	  fmuls     f29, f29, f1
	  addi      r3, r1, 0x58
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x4150(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x414C(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x34(r1)
	  bl        -0x185D8
	  lfs       f0, 0x5C(r29)
	  addis     r3, r29, 0x1
	  lfs       f6, 0x58(r1)
	  fmuls     f1, f31, f0
	  lfs       f7, 0x5C(r1)
	  lfs       f2, -0x5DD0(r3)
	  fmuls     f0, f6, f29
	  lfs       f3, 0x60(r1)
	  fadds     f2, f2, f1
	  fmuls     f1, f3, f31
	  fmuls     f4, f7, f29
	  stfs      f2, -0x5DD0(r3)
	  fmuls     f3, f3, f30
	  fsubs     f2, f1, f0
	  lfs       f0, 0x5C(r29)
	  lfs       f5, -0x5DCC(r3)
	  fsubs     f3, f4, f3
	  fmuls     f4, f30, f0
	  fmuls     f1, f6, f30
	  fmuls     f0, f7, f31
	  fadds     f4, f5, f4
	  fsubs     f0, f1, f0
	  stfs      f4, -0x5DCC(r3)
	  lfs       f1, 0x5C(r29)
	  lfs       f4, -0x5DC8(r3)
	  fmuls     f1, f29, f1
	  fadds     f1, f4, f1
	  stfs      f1, -0x5DC8(r3)
	  lfs       f1, -0x5DC4(r3)
	  fadds     f1, f1, f3
	  stfs      f1, -0x5DC4(r3)
	  lfs       f1, -0x5DC0(r3)
	  fadds     f1, f1, f2
	  stfs      f1, -0x5DC0(r3)
	  lfs       f1, -0x5DBC(r3)
	  fadds     f0, f1, f0
	  stfs      f0, -0x5DBC(r3)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  lfd       f29, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004F7B4
 * Size:	0000E0
 */
void RigidBody::updateViewInfo(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r9, r5, 0x308C
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x3000
	  stwu      r1, -0x8(r1)
	  addi      r7, r9, 0
	  add       r7, r3, r7
	  add       r8, r3, r0
	  li        r10, 0
	  b         .loc_0x50

	.loc_0x28:
	  lwz       r5, 0x41A4(r7)
	  addis     r6, r8, 0x1
	  lwz       r0, 0x41A8(r7)
	  addi      r8, r8, 0xC
	  addi      r10, r10, 0x1
	  stw       r5, -0x5DB8(r6)
	  stw       r0, -0x5DB4(r6)
	  lwz       r0, 0x41AC(r7)
	  addi      r7, r7, 0xC
	  stw       r0, -0x5DB0(r6)

	.loc_0x50:
	  lwz       r5, 0x8C(r3)
	  lwz       r0, 0x90(r3)
	  add       r0, r5, r0
	  cmpw      r10, r0
	  blt+      .loc_0x28
	  mulli     r6, r4, 0xC
	  add       r9, r3, r9
	  addis     r8, r3, 0x1
	  lwz       r5, 0x414C(r9)
	  add       r7, r8, r6
	  lwz       r0, 0x4150(r9)
	  rlwinm    r6,r4,4,0,27
	  stw       r5, 0x3248(r7)
	  addis     r4, r6, 0x1
	  addi      r4, r4, 0x326C
	  stw       r0, 0x324C(r7)
	  add       r6, r8, r6
	  add       r4, r3, r4
	  lwz       r0, 0x4154(r9)
	  stw       r0, 0x3250(r7)
	  lwz       r5, 0x413C(r9)
	  lwz       r0, 0x4140(r9)
	  stw       r5, 0x326C(r6)
	  stw       r0, 0x3270(r6)
	  lwz       r5, 0x4144(r9)
	  lwz       r0, 0x4148(r9)
	  stw       r5, 0x3274(r6)
	  stw       r0, 0x3278(r6)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004F894
 * Size:	000004
 */
void RigidBody::makeBodyQuat(Quat&) { }

/*
 * --INFO--
 * Address:	8004F898
 * Size:	0001E8
 */
void RigidBody::updateVecQuats(int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  xori      r10, r4, 0x1
	  stw       r0, 0x4(r1)
	  mulli     r5, r4, 0x3000
	  stwu      r1, -0xF8(r1)
	  addi      r12, r3, 0
	  mulli     r0, r10, 0x3000
	  addi      r9, r12, 0
	  add       r7, r12, r5
	  add       r8, r12, r0
	  li        r11, 0
	  b         .loc_0xDC

	.loc_0x30:
	  addis     r6, r8, 0x1
	  addis     r3, r7, 0x1
	  lfs       f0, -0x5DB8(r6)
	  lfs       f6, -0x5DB8(r3)
	  addis     r5, r9, 0x1
	  lfs       f3, -0x5DB0(r6)
	  addi      r7, r7, 0xC
	  lfs       f4, -0x5DB0(r3)
	  fsubs     f0, f0, f6
	  lfs       f2, -0x5DB4(r6)
	  lfs       f5, -0x5DB4(r3)
	  fsubs     f3, f3, f4
	  addi      r8, r8, 0xC
	  stfs      f0, 0xA8(r1)
	  fmuls     f0, f3, f1
	  fsubs     f2, f2, f5
	  addi      r9, r9, 0xC
	  lfs       f3, 0xA8(r1)
	  addi      r11, r11, 0x1
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f1
	  stfs      f3, 0x9C(r1)
	  lfs       f3, 0x9C(r1)
	  stfs      f3, 0xDC(r1)
	  stfs      f2, 0xE0(r1)
	  stfs      f0, 0xE4(r1)
	  lfs       f0, 0xDC(r1)
	  fadds     f0, f6, f0
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0xE8(r1)
	  lfs       f0, 0xE0(r1)
	  fadds     f0, f5, f0
	  stfs      f0, 0xEC(r1)
	  lfs       f0, 0xE4(r1)
	  fadds     f0, f4, f0
	  stfs      f0, 0xF0(r1)
	  lwz       r3, 0xE8(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r3, 0x248(r5)
	  stw       r0, 0x24C(r5)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0x250(r5)

	.loc_0xDC:
	  lwz       r3, 0x8C(r12)
	  lwz       r0, 0x90(r12)
	  add       r0, r3, r0
	  cmpw      r11, r0
	  blt+      .loc_0x30
	  mulli     r0, r10, 0xC
	  addis     r3, r12, 0x1
	  add       r5, r3, r0
	  mulli     r0, r4, 0xC
	  lfs       f0, 0x3248(r5)
	  lfs       f3, 0x3250(r5)
	  lfs       f2, 0x324C(r5)
	  add       r5, r3, r0
	  lfs       f7, 0x3248(r5)
	  rlwinm    r0,r4,4,0,27
	  lfs       f5, 0x3250(r5)
	  rlwinm    r4,r10,4,0,27
	  lfs       f6, 0x324C(r5)
	  fsubs     f0, f0, f7
	  addis     r4, r4, 0x1
	  fsubs     f2, f2, f6
	  addi      r4, r4, 0x326C
	  fsubs     f4, f3, f5
	  stfs      f0, 0x8C(r1)
	  fmuls     f2, f2, f1
	  fmuls     f0, f4, f1
	  add       r7, r3, r0
	  lfs       f3, 0x8C(r1)
	  add       r4, r12, r4
	  fmuls     f3, f3, f1
	  li        r5, 0x1
	  stfs      f3, 0x80(r1)
	  lfs       f3, 0x80(r1)
	  stfs      f3, 0xB8(r1)
	  stfs      f2, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xB8(r1)
	  fadds     f0, f7, f0
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xBC(r1)
	  fadds     f0, f6, f0
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xC0(r1)
	  fadds     f0, f5, f0
	  stfs      f0, 0xCC(r1)
	  lwz       r6, 0xC4(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r6, 0x3260(r3)
	  stw       r0, 0x3264(r3)
	  lwz       r0, 0xCC(r1)
	  stw       r0, 0x3268(r3)
	  lwz       r6, 0x326C(r7)
	  lwz       r0, 0x3270(r7)
	  stw       r6, 0x328C(r3)
	  stw       r0, 0x3290(r3)
	  lwz       r6, 0x3274(r7)
	  lwz       r0, 0x3278(r7)
	  stw       r6, 0x3294(r3)
	  stw       r0, 0x3298(r3)
	  addi      r3, r3, 0x328C
	  bl        -0x178E8
	  lwz       r0, 0xFC(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004FA80
 * Size:	00013C
 */
void RigidBody::calculateVertices(int)
{
	/*
	.loc_0x0:
	  mulli     r4, r4, 0x308C
	  stwu      r1, -0x88(r1)
	  lfs       f0, -0x7B30(r2)
	  addi      r7, r4, 0x4118
	  add       r7, r3, r7
	  addi      r5, r3, 0
	  addi      r6, r7, 0
	  addi      r8, r7, 0x34
	  li        r9, 0
	  b         .loc_0x120

	.loc_0x28:
	  stfs      f0, 0x64(r1)
	  addi      r9, r9, 0x1
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  lfs       f5, 0x94(r5)
	  lfs       f2, 0x0(r7)
	  lfs       f4, 0x98(r5)
	  lfs       f1, 0x4(r7)
	  fmuls     f2, f5, f2
	  lfs       f6, 0x9C(r5)
	  addi      r5, r5, 0xC
	  fmuls     f1, f4, f1
	  lfs       f3, 0x8(r7)
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0x5C(r1)
	  lfs       f2, 0xC(r7)
	  lfs       f1, 0x10(r7)
	  lfs       f3, 0x14(r7)
	  fmuls     f2, f5, f2
	  fmuls     f1, f4, f1
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0x60(r1)
	  lfs       f2, 0x18(r7)
	  lfs       f1, 0x1C(r7)
	  lfs       f3, 0x20(r7)
	  fmuls     f2, f5, f2
	  fmuls     f1, f4, f1
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0x64(r1)
	  lfs       f1, 0x5C(r1)
	  stfs      f1, 0x68(r1)
	  lfs       f1, 0x60(r1)
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x64(r1)
	  stfs      f1, 0x70(r1)
	  lfs       f2, 0x0(r8)
	  lfs       f1, 0x68(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x50(r1)
	  lfs       f1, 0x50(r1)
	  stfs      f1, 0x74(r1)
	  lfs       f2, 0x4(r8)
	  lfs       f1, 0x6C(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x78(r1)
	  lfs       f2, 0x8(r8)
	  lfs       f1, 0x70(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x7C(r1)
	  lwz       r4, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r4, 0x8C(r6)
	  stw       r0, 0x90(r6)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x94(r6)
	  addi      r6, r6, 0xC

	.loc_0x120:
	  lwz       r4, 0x8C(r3)
	  lwz       r0, 0x90(r3)
	  add       r0, r4, r0
	  cmpw      r9, r0
	  blt+      .loc_0x28
	  addi      r1, r1, 0x88
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004FBBC
 * Size:	000008
 */
bool RigidBody::checkForCollisions(int, CollState&) { return false; }

/*
 * --INFO--
 * Address:	8004FBC4
 * Size:	0000B8
 */
void DynSimulator::resetWorld()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x28(r3)
	  lwz       r31, 0x10(r3)
	  b         .loc_0x8C

	.loc_0x2C:
	  mr        r3, r31
	  bl        -0x1FF4
	  li        r30, 0

	.loc_0x38:
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r4, 0x28(r29)
	  lwz       r12, 0x38(r12)
	  lfs       f1, -0x7B30(r2)
	  xori      r5, r4, 0x1
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x28(r29)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x28(r29)
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x2
	  xori      r0, r0, 0x1
	  stw       r0, 0x28(r29)
	  blt+      .loc_0x38
	  lwz       r31, 0xC(r31)

	.loc_0x8C:
	  cmplwi    r31, 0
	  bne+      .loc_0x2C
	  li        r0, 0x2
	  stw       r0, 0x30(r29)
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
 * Address:	8004FC7C
 * Size:	0001B4
 */
void DynSimulator::doSimulation(f32, f32, Shape*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stfd      f30, 0x30(r1)
	  fmr       f30, f1
	  stfd      f29, 0x28(r1)
	  stfd      f28, 0x20(r1)
	  fmr       f28, f2
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lfs       f31, -0x7B30(r2)
	  b         .loc_0x144

	.loc_0x38:
	  fcmpo     cr0, f30, f28
	  fmr       f29, f30
	  ble-      .loc_0x48
	  fmr       f29, f28

	.loc_0x48:
	  lwz       r0, 0x20(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x140
	  lwz       r31, 0x10(r30)
	  b         .loc_0x78

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r4, 0x28(r30)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x78:
	  cmplwi    r31, 0
	  bne+      .loc_0x5C
	  lwz       r31, 0x10(r30)
	  b         .loc_0xA8

	.loc_0x88:
	  mr        r3, r31
	  fmr       f1, f29
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x28(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0xA8:
	  cmplwi    r31, 0
	  bne+      .loc_0x88
	  lwz       r31, 0x10(r30)
	  b         .loc_0x12C

	.loc_0xB8:
	  lwz       r12, 0x0(r31)
	  fmr       f1, f29
	  lwz       r4, 0x28(r30)
	  mr        r3, r31
	  lwz       r12, 0x38(r12)
	  xori      r5, r4, 0x1
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x28(r30)
	  lwz       r12, 0x0(r31)
	  xori      r4, r0, 0x1
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x767C(r13)
	  addis     r3, r31, 0x1
	  stfs      f0, -0x5DD0(r3)
	  lfs       f0, -0x7678(r13)
	  stfs      f0, -0x5DCC(r3)
	  lfs       f0, -0x7674(r13)
	  stfs      f0, -0x5DC8(r3)
	  lfs       f0, -0x7670(r13)
	  stfs      f0, -0x5DC4(r3)
	  lfs       f0, -0x766C(r13)
	  stfs      f0, -0x5DC0(r3)
	  lfs       f0, -0x7668(r13)
	  stfs      f0, -0x5DBC(r3)
	  lwz       r31, 0xC(r31)

	.loc_0x12C:
	  cmplwi    r31, 0
	  bne+      .loc_0xB8
	  lwz       r0, 0x28(r30)
	  xori      r0, r0, 0x1
	  stw       r0, 0x28(r30)

	.loc_0x140:
	  fsubs     f30, f30, f29

	.loc_0x144:
	  fcmpo     cr0, f30, f31
	  bgt+      .loc_0x38
	  lwz       r31, 0x10(r30)
	  b         .loc_0x178

	.loc_0x154:
	  mr        r3, r31
	  lwz       r0, 0x28(r30)
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x24(r30)
	  xori      r5, r0, 0x1
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x178:
	  cmplwi    r31, 0
	  bne+      .loc_0x154
	  lwz       r0, 0x24(r30)
	  xori      r0, r0, 0x1
	  stw       r0, 0x24(r30)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lfd       f29, 0x28(r1)
	  lfd       f28, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004FE30
 * Size:	000080
 */
void RigidBody::computeForces(int, f32)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76D0(r13)
	  addis     r4, r3, 0x1
	  stfs      f0, -0x5DD0(r4)
	  lfs       f0, -0x76CC(r13)
	  stfs      f0, -0x5DCC(r4)
	  lfs       f0, -0x76C8(r13)
	  stfs      f0, -0x5DC8(r4)
	  lfs       f0, -0x76C4(r13)
	  stfs      f0, -0x5DC4(r4)
	  lfs       f0, -0x76C0(r13)
	  stfs      f0, -0x5DC0(r4)
	  lfs       f0, -0x76BC(r13)
	  stfs      f0, -0x5DBC(r4)
	  lfs       f1, -0x76B8(r13)
	  lfs       f0, 0x5C(r3)
	  lfs       f2, -0x5DD0(r4)
	  fmuls     f0, f1, f0
	  lfs       f3, -0x76B4(r13)
	  lfs       f4, -0x76B0(r13)
	  fadds     f0, f2, f0
	  stfs      f0, -0x5DD0(r4)
	  lfs       f0, 0x5C(r3)
	  lfs       f1, -0x5DCC(r4)
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  stfs      f0, -0x5DCC(r4)
	  lfs       f0, 0x5C(r3)
	  lfs       f1, -0x5DC8(r4)
	  fmuls     f0, f4, f0
	  fadds     f0, f1, f0
	  stfs      f0, -0x5DC8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004FEB0
 * Size:	0000E8
 */
void RigidBody::initCollisions(int)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76E8(r13)
	  addis     r5, r3, 0x1
	  mulli     r4, r4, 0x308C
	  stfs      f0, 0x329C(r5)
	  lfs       f0, -0x76E4(r13)
	  addi      r6, r4, 0x4118
	  add       r6, r3, r6
	  stfs      f0, 0x32A0(r5)
	  li        r7, 0
	  lfs       f0, -0x76E0(r13)
	  stfs      f0, 0x32A4(r5)
	  lfs       f0, -0x76DC(r13)
	  stfs      f0, 0x32A8(r5)
	  lfs       f0, -0x76D8(r13)
	  stfs      f0, 0x32AC(r5)
	  lfs       f0, -0x76D4(r13)
	  stfs      f0, 0x32B0(r5)
	  b         .loc_0xD8

	.loc_0x48:
	  lwz       r0, 0x90(r3)
	  lfs       f0, 0x329C(r5)
	  add       r0, r7, r0
	  mulli     r4, r0, 0xC
	  addi      r4, r4, 0x8C
	  add       r4, r6, r4
	  lfs       f1, 0x0(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x70
	  stfs      f1, 0x329C(r5)

	.loc_0x70:
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x32A0(r5)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x84
	  stfs      f1, 0x32A0(r5)

	.loc_0x84:
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x32A4(r5)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x98
	  stfs      f1, 0x32A4(r5)

	.loc_0x98:
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x32A8(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xAC
	  stfs      f1, 0x32A8(r5)

	.loc_0xAC:
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x32AC(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC0
	  stfs      f1, 0x32AC(r5)

	.loc_0xC0:
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x32B0(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xD4
	  stfs      f1, 0x32B0(r5)

	.loc_0xD4:
	  addi      r7, r7, 0x1

	.loc_0xD8:
	  lwz       r0, 0x8C(r3)
	  cmpw      r7, r0
	  blt+      .loc_0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void DynSimulator::evolveSimulation(f32, Shape*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void DynSimulator::Integrate(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void DynSimulator::CalculateVertices(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004FF98
 * Size:	00006C
 */
void DynSimulator::updateVecQuats(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  fmr       f31, f1
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r31, 0x10(r3)
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r31
	  fmr       f1, f31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x24(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x48:
	  cmplwi    r31, 0
	  bne+      .loc_0x28
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void DynSimulator::CheckForCollisions(int, Shape*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void DynSimulator::ResolveCollisions(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80050004
 * Size:	000010
 */
void RigidBody::initDimensions(f32, f32, f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x50(r3)
	  stfs      f2, 0x54(r3)
	  stfs      f3, 0x58(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050014
 * Size:	000004
 */
void RigidBody::shadrender(Graphics&, LightCamera*) { }

/*
 * --INFO--
 * Address:	80050018
 * Size:	000008
 */
void RigidBody::getViewScale()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x7B34(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050020
 * Size:	000004
 */
void RigidBody::updateCont() { }
