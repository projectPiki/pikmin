#include "Camera.h"

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
 * Address:	........
 * Size:	0000C4
 */
void CullFrustum::vectorToWorldPlane(Vector3f&, CullingPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80041584
 * Size:	00006C
 */
void CullFrustum::isPointVisible(Vector3f&, f32)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r3)
	  fneg      f5, f1
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x64

	.loc_0x14:
	  lwz       r5, 0x114(r3)
	  lfs       f3, 0x0(r4)
	  lfs       f2, 0x0(r5)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x4(r5)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x8(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x8(r5)
	  lfs       f0, 0xC(r5)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  bge-      .loc_0x5C
	  li        r3, 0
	  blr

	.loc_0x5C:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x14

	.loc_0x64:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800415F0
 * Size:	000FBC
 */
void CullFrustum::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x430(r1)
	  stfd      f31, 0x428(r1)
	  stfd      f30, 0x420(r1)
	  stfd      f29, 0x418(r1)
	  stfd      f28, 0x410(r1)
	  stfd      f27, 0x408(r1)
	  stfd      f26, 0x400(r1)
	  stmw      r26, 0x3E8(r1)
	  addi      r26, r4, 0
	  addi      r31, r3, 0
	  mr        r3, r26
	  stw       r0, 0x324(r4)
	  li        r4, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r4, 0x2E4(r26)
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  mr        r27, r0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0xFF
	  stb       r28, 0x258(r1)
	  addi      r4, r1, 0x258
	  addi      r3, r26, 0
	  stb       r28, 0x259(r1)
	  li        r5, 0x1
	  stb       r28, 0x25A(r1)
	  stb       r28, 0x25B(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x254(r1)
	  addi      r4, r1, 0x254
	  addi      r3, r26, 0
	  stb       r28, 0x255(r1)
	  stb       r28, 0x256(r1)
	  stb       r28, 0x257(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r31, 0x164
	  addi      r5, r31, 0x170
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7BF8(r2)
	  stfs      f0, 0x1D8(r1)
	  stfs      f0, 0x1D4(r1)
	  stfs      f0, 0x1D0(r1)
	  lfs       f1, 0x170(r31)
	  lfs       f0, 0x164(r31)
	  lfs       f4, 0x178(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x16C(r31)
	  lfs       f2, 0x174(r31)
	  lfs       f1, 0x168(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x1AC(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x1AC(r1)
	  stfs      f0, 0x1D0(r1)
	  stfs      f1, 0x1D4(r1)
	  stfs      f3, 0x1D8(r1)
	  lfs       f1, 0x1D0(r1)
	  lfs       f0, 0x1D4(r1)
	  lfs       f2, 0x1D8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x33B24
	  lfs       f2, 0x1CC(r31)
	  fmr       f27, f1
	  lfs       f0, -0x7BF0(r2)
	  lfs       f3, -0x7BF4(r2)
	  fmuls     f1, f2, f0
	  lfs       f0, -0x7BEC(r2)
	  fmuls     f1, f3, f1
	  fdivs     f1, f1, f0
	  bl        0x1DA3CC
	  lfs       f2, 0x1CC(r31)
	  fmr       f26, f1
	  lfs       f0, -0x7BF0(r2)
	  lfs       f3, -0x7BF4(r2)
	  fmuls     f1, f2, f0
	  lfs       f0, -0x7BEC(r2)
	  fmuls     f1, f3, f1
	  fdivs     f1, f1, f0
	  bl        0x1DA53C
	  fmuls     f1, f27, f1
	  lfs       f6, 0x1C4(r31)
	  lfs       f4, 0x17C(r31)
	  lfs       f0, 0x180(r31)
	  fdivs     f31, f1, f26
	  lfs       f2, 0x18C(r31)
	  lfs       f5, 0x198(r31)
	  lfs       f9, 0x188(r31)
	  lfs       f28, -0x7924(r13)
	  fdivs     f26, f31, f6
	  lfs       f3, 0x184(r31)
	  lfs       f10, 0x190(r31)
	  lfs       f27, 0x19C(r31)
	  lfs       f13, 0x194(r31)
	  fmuls     f30, f26, f6
	  lfs       f7, 0x170(r31)
	  fmuls     f1, f31, f0
	  lfs       f11, 0x174(r31)
	  fmuls     f8, f31, f2
	  fneg      f2, f30
	  lfs       f0, 0x178(r31)
	  fmuls     f6, f28, f3
	  lfs       f3, -0x7920(r13)
	  fmuls     f12, f31, f5
	  fmuls     f5, f2, f4
	  lfs       f4, -0x791C(r13)
	  fmuls     f9, f2, f9
	  fmuls     f13, f2, f13
	  fadds     f1, f5, f1
	  fmuls     f10, f28, f10
	  fadds     f5, f9, f8
	  fadds     f1, f6, f1
	  fmuls     f8, f28, f27
	  fadds     f6, f13, f12
	  fadds     f5, f10, f5
	  fadds     f1, f7, f1
	  fadds     f6, f8, f6
	  fadds     f5, f11, f5
	  stfs      f1, 0x3A8(r1)
	  fneg      f1, f31
	  fadds     f0, f0, f6
	  stfs      f5, 0x3AC(r1)
	  stfs      f0, 0x3B0(r1)
	  lfs       f5, 0x17C(r31)
	  lfs       f0, 0x180(r31)
	  lfs       f8, 0x188(r31)
	  fmuls     f5, f30, f5
	  fmuls     f0, f31, f0
	  lfs       f7, 0x18C(r31)
	  lfs       f6, 0x184(r31)
	  lfs       f11, 0x194(r31)
	  lfs       f10, 0x198(r31)
	  lfs       f9, 0x190(r31)
	  fmuls     f8, f30, f8
	  fmuls     f7, f31, f7
	  lfs       f12, 0x19C(r31)
	  fmuls     f6, f3, f6
	  fadds     f0, f5, f0
	  fmuls     f11, f30, f11
	  fmuls     f10, f31, f10
	  lfs       f5, 0x170(r31)
	  fadds     f0, f6, f0
	  fmuls     f9, f3, f9
	  fadds     f6, f8, f7
	  fmuls     f12, f3, f12
	  lfs       f7, 0x174(r31)
	  fadds     f8, f11, f10
	  fadds     f3, f9, f6
	  fadds     f0, f5, f0
	  lfs       f6, 0x178(r31)
	  fadds     f5, f12, f8
	  fadds     f3, f7, f3
	  stfs      f0, 0x39C(r1)
	  fadds     f0, f6, f5
	  stfs      f3, 0x3A0(r1)
	  stfs      f0, 0x3A4(r1)
	  lfs       f0, 0x194(r31)
	  lfs       f5, 0x198(r31)
	  lfs       f3, 0x188(r31)
	  fmuls     f8, f30, f0
	  lfs       f0, 0x18C(r31)
	  fmuls     f7, f1, f5
	  lfs       f9, 0x19C(r31)
	  lfs       f5, 0x190(r31)
	  fmuls     f3, f30, f3
	  lfs       f10, 0x178(r31)
	  fmuls     f0, f1, f0
	  lfs       f6, 0x174(r31)
	  fmuls     f9, f4, f9
	  fadds     f7, f8, f7
	  fmuls     f5, f4, f5
	  fadds     f0, f3, f0
	  fadds     f3, f9, f7
	  fadds     f0, f5, f0
	  fadds     f8, f10, f3
	  fadds     f7, f6, f0
	  lfs       f3, 0x17C(r31)
	  lfs       f0, 0x180(r31)
	  fmuls     f3, f30, f3
	  lfs       f5, 0x184(r31)
	  fmuls     f0, f1, f0
	  lfs       f6, 0x170(r31)
	  fmuls     f4, f4, f5
	  fadds     f3, f3, f0
	  lfs       f0, -0x7918(r13)
	  fadds     f3, f4, f3
	  fadds     f3, f6, f3
	  stfs      f3, 0x390(r1)
	  stfs      f7, 0x394(r1)
	  stfs      f8, 0x398(r1)
	  lfs       f4, 0x17C(r31)
	  lfs       f3, 0x180(r31)
	  lfs       f7, 0x188(r31)
	  fmuls     f4, f2, f4
	  fmuls     f3, f1, f3
	  lfs       f6, 0x18C(r31)
	  lfs       f5, 0x184(r31)
	  lfs       f10, 0x194(r31)
	  lfs       f9, 0x198(r31)
	  lfs       f8, 0x190(r31)
	  fmuls     f7, f2, f7
	  fmuls     f6, f1, f6
	  lfs       f11, 0x19C(r31)
	  fmuls     f5, f0, f5
	  fadds     f3, f4, f3
	  fmuls     f10, f2, f10
	  fmuls     f9, f1, f9
	  lfs       f2, 0x170(r31)
	  fadds     f1, f5, f3
	  fmuls     f4, f0, f8
	  fadds     f3, f7, f6
	  fmuls     f7, f0, f11
	  lfs       f5, 0x174(r31)
	  fadds     f6, f10, f9
	  fadds     f3, f4, f3
	  fadds     f0, f2, f1
	  lfs       f2, 0x178(r31)
	  fadds     f1, f7, f6
	  fadds     f3, f5, f3
	  stfs      f0, 0x384(r1)
	  fadds     f0, f2, f1
	  stfs      f3, 0x388(r1)
	  stfs      f0, 0x38C(r1)
	  lfs       f3, 0x170(r31)
	  lfs       f2, 0x164(r31)
	  lfs       f1, 0x174(r31)
	  lfs       f0, 0x168(r31)
	  fsubs     f29, f3, f2
	  lfs       f2, 0x178(r31)
	  fsubs     f28, f1, f0
	  lfs       f0, 0x16C(r31)
	  fmuls     f1, f29, f29
	  fsubs     f27, f2, f0
	  fmuls     f0, f28, f28
	  fmuls     f2, f27, f27
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x33DE4
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x450
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1

	.loc_0x450:
	  lfs       f1, 0x1D0(r31)
	  lfs       f5, 0x164(r31)
	  lfs       f4, 0x168(r31)
	  fmuls     f29, f29, f1
	  lfs       f3, 0x16C(r31)
	  fmuls     f28, f28, f1
	  lfs       f0, -0x7BF8(r2)
	  fmuls     f27, f27, f1
	  stfs      f0, 0x1C8(r1)
	  fadds     f29, f29, f5
	  fadds     f28, f28, f4
	  stfs      f0, 0x1C4(r1)
	  fadds     f27, f27, f3
	  stfs      f0, 0x1C0(r1)
	  lfs       f0, 0x170(r31)
	  lfs       f2, 0x178(r31)
	  lfs       f1, 0x174(r31)
	  fsubs     f0, f5, f0
	  fsubs     f2, f3, f2
	  fsubs     f1, f4, f1
	  stfs      f0, 0x198(r1)
	  lfs       f0, 0x198(r1)
	  stfs      f0, 0x1C0(r1)
	  stfs      f1, 0x1C4(r1)
	  stfs      f2, 0x1C8(r1)
	  lfs       f1, 0x1C0(r1)
	  lfs       f0, 0x1C4(r1)
	  lfs       f2, 0x1C8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x33E84
	  lfs       f0, 0x1D0(r31)
	  lfs       f3, 0x17C(r31)
	  fdivs     f1, f0, f1
	  lfs       f2, 0x180(r31)
	  lfs       f10, 0x188(r31)
	  lfs       f7, 0x18C(r31)
	  lfs       f0, -0x7914(r13)
	  fmuls     f4, f26, f1
	  lfs       f8, 0x184(r31)
	  fmuls     f5, f31, f1
	  lfs       f12, 0x198(r31)
	  lfs       f11, 0x190(r31)
	  fneg      f1, f4
	  lfs       f13, 0x194(r31)
	  fmuls     f6, f5, f2
	  lfs       f26, 0x19C(r31)
	  fmuls     f9, f5, f7
	  fmuls     f7, f1, f3
	  lfs       f2, -0x7910(r13)
	  fmuls     f10, f1, f10
	  lfs       f3, -0x790C(r13)
	  fmuls     f8, f0, f8
	  fadds     f6, f7, f6
	  fmuls     f13, f1, f13
	  fmuls     f12, f5, f12
	  fadds     f6, f8, f6
	  fmuls     f8, f0, f11
	  fadds     f7, f10, f9
	  fadds     f6, f29, f6
	  fmuls     f10, f0, f26
	  fadds     f9, f13, f12
	  fadds     f7, f8, f7
	  stfs      f6, 0x33C(r1)
	  fneg      f0, f5
	  fadds     f6, f10, f9
	  fadds     f7, f28, f7
	  fadds     f6, f27, f6
	  stfs      f7, 0x340(r1)
	  stfs      f6, 0x344(r1)
	  lfs       f7, 0x17C(r31)
	  lfs       f6, 0x180(r31)
	  lfs       f10, 0x188(r31)
	  fmuls     f7, f4, f7
	  fmuls     f6, f5, f6
	  lfs       f9, 0x18C(r31)
	  lfs       f8, 0x184(r31)
	  lfs       f13, 0x194(r31)
	  lfs       f12, 0x198(r31)
	  lfs       f11, 0x190(r31)
	  fmuls     f10, f4, f10
	  fmuls     f9, f5, f9
	  lfs       f26, 0x19C(r31)
	  fmuls     f8, f2, f8
	  fadds     f6, f7, f6
	  fmuls     f13, f4, f13
	  fmuls     f12, f5, f12
	  fadds     f5, f8, f6
	  fmuls     f7, f2, f11
	  fadds     f6, f10, f9
	  fadds     f5, f29, f5
	  fmuls     f9, f2, f26
	  fadds     f8, f13, f12
	  fadds     f2, f7, f6
	  stfs      f5, 0x330(r1)
	  fadds     f5, f9, f8
	  fadds     f2, f28, f2
	  fadds     f5, f27, f5
	  stfs      f2, 0x334(r1)
	  stfs      f5, 0x338(r1)
	  lfs       f5, 0x17C(r31)
	  lfs       f2, 0x180(r31)
	  lfs       f10, 0x194(r31)
	  fmuls     f5, f4, f5
	  fmuls     f2, f0, f2
	  lfs       f9, 0x198(r31)
	  lfs       f8, 0x188(r31)
	  lfs       f7, 0x18C(r31)
	  lfs       f6, 0x184(r31)
	  lfs       f12, 0x19C(r31)
	  fmuls     f11, f4, f10
	  fmuls     f10, f0, f9
	  lfs       f9, 0x190(r31)
	  fmuls     f8, f4, f8
	  fmuls     f7, f0, f7
	  fmuls     f4, f3, f6
	  fadds     f2, f5, f2
	  fmuls     f6, f3, f12
	  fadds     f5, f11, f10
	  fadds     f2, f4, f2
	  fmuls     f4, f3, f9
	  fadds     f3, f8, f7
	  fadds     f5, f6, f5
	  fadds     f2, f29, f2
	  fadds     f3, f4, f3
	  fadds     f4, f27, f5
	  stfs      f2, 0x324(r1)
	  fadds     f2, f28, f3
	  stfs      f2, 0x328(r1)
	  lfs       f11, -0x7908(r13)
	  stfs      f4, 0x32C(r1)
	  lfs       f3, 0x17C(r31)
	  lfs       f2, 0x180(r31)
	  lfs       f6, 0x188(r31)
	  fmuls     f3, f1, f3
	  fmuls     f2, f0, f2
	  lfs       f5, 0x18C(r31)
	  lfs       f4, 0x184(r31)
	  lfs       f9, 0x194(r31)
	  lfs       f8, 0x198(r31)
	  lfs       f7, 0x190(r31)
	  fmuls     f6, f1, f6
	  fmuls     f5, f0, f5
	  lfs       f10, 0x19C(r31)
	  fmuls     f4, f11, f4
	  fadds     f2, f3, f2
	  fmuls     f9, f1, f9
	  fmuls     f3, f0, f8
	  fadds     f0, f4, f2
	  fmuls     f2, f11, f7
	  fadds     f1, f6, f5
	  fadds     f0, f29, f0
	  fmuls     f4, f11, f10
	  fadds     f3, f9, f3
	  fadds     f1, f2, f1
	  stfs      f0, 0x318(r1)
	  fadds     f0, f4, f3
	  fadds     f1, f28, f1
	  fadds     f0, f27, f0
	  stfs      f1, 0x31C(r1)
	  stfs      f0, 0x320(r1)
	  lfs       f3, 0x170(r31)
	  lfs       f2, 0x164(r31)
	  lfs       f1, 0x174(r31)
	  lfs       f0, 0x168(r31)
	  fsubs     f27, f3, f2
	  lfs       f2, 0x178(r31)
	  fsubs     f28, f1, f0
	  lfs       f0, 0x16C(r31)
	  fmuls     f1, f27, f27
	  fsubs     f29, f2, f0
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x340C8
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x734
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x734:
	  lfs       f1, 0x1D4(r31)
	  lfs       f5, 0x164(r31)
	  lfs       f4, 0x168(r31)
	  fmuls     f27, f27, f1
	  lfs       f3, 0x16C(r31)
	  fmuls     f28, f28, f1
	  lfs       f0, -0x7BF8(r2)
	  fmuls     f29, f29, f1
	  stfs      f0, 0x1B8(r1)
	  fadds     f27, f27, f5
	  fadds     f28, f28, f4
	  stfs      f0, 0x1B4(r1)
	  fadds     f29, f29, f3
	  stfs      f0, 0x1B0(r1)
	  lfs       f0, 0x170(r31)
	  lfs       f2, 0x178(r31)
	  lfs       f1, 0x174(r31)
	  fsubs     f0, f5, f0
	  fsubs     f2, f3, f2
	  fsubs     f1, f4, f1
	  stfs      f0, 0x184(r1)
	  lfs       f0, 0x184(r1)
	  stfs      f0, 0x1B0(r1)
	  stfs      f1, 0x1B4(r1)
	  stfs      f2, 0x1B8(r1)
	  lfs       f1, 0x1B0(r1)
	  lfs       f0, 0x1B4(r1)
	  lfs       f2, 0x1B8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x34168
	  lfs       f0, 0x1D4(r31)
	  lfs       f2, 0x17C(r31)
	  fdivs     f1, f0, f1
	  lfs       f0, 0x180(r31)
	  lfs       f8, 0x188(r31)
	  lfs       f3, 0x18C(r31)
	  lfs       f13, -0x7904(r13)
	  fmuls     f30, f30, f1
	  lfs       f6, 0x184(r31)
	  fmuls     f4, f31, f1
	  lfs       f10, 0x198(r31)
	  lfs       f9, 0x190(r31)
	  fneg      f1, f30
	  lfs       f11, 0x194(r31)
	  fmuls     f0, f4, f0
	  lfs       f12, 0x19C(r31)
	  fmuls     f7, f4, f3
	  fmuls     f5, f1, f2
	  lfs       f2, -0x7900(r13)
	  fmuls     f8, f1, f8
	  lfs       f3, -0x78FC(r13)
	  fmuls     f6, f13, f6
	  fadds     f0, f5, f0
	  fmuls     f11, f1, f11
	  fmuls     f10, f4, f10
	  fadds     f0, f6, f0
	  fmuls     f6, f13, f9
	  fadds     f5, f8, f7
	  fadds     f0, f27, f0
	  fmuls     f8, f13, f12
	  fadds     f7, f11, f10
	  fadds     f5, f6, f5
	  stfs      f0, 0x2D0(r1)
	  fneg      f0, f4
	  fadds     f6, f8, f7
	  fadds     f5, f28, f5
	  fadds     f6, f29, f6
	  stfs      f5, 0x2D4(r1)
	  stfs      f6, 0x2D8(r1)
	  lfs       f6, 0x17C(r31)
	  lfs       f5, 0x180(r31)
	  lfs       f9, 0x188(r31)
	  fmuls     f6, f30, f6
	  fmuls     f5, f4, f5
	  lfs       f8, 0x18C(r31)
	  lfs       f7, 0x184(r31)
	  lfs       f12, 0x194(r31)
	  lfs       f11, 0x198(r31)
	  lfs       f10, 0x190(r31)
	  fmuls     f9, f30, f9
	  fmuls     f8, f4, f8
	  lfs       f13, 0x19C(r31)
	  fmuls     f7, f2, f7
	  fadds     f5, f6, f5
	  fmuls     f12, f30, f12
	  fmuls     f11, f4, f11
	  fadds     f4, f7, f5
	  fmuls     f6, f2, f10
	  fadds     f5, f9, f8
	  fadds     f4, f27, f4
	  fmuls     f8, f2, f13
	  fadds     f7, f12, f11
	  fadds     f2, f6, f5
	  stfs      f4, 0x2C4(r1)
	  fadds     f4, f8, f7
	  fadds     f2, f28, f2
	  fadds     f4, f29, f4
	  stfs      f2, 0x2C8(r1)
	  stfs      f4, 0x2CC(r1)
	  lfs       f4, 0x17C(r31)
	  lfs       f2, 0x180(r31)
	  lfs       f9, 0x194(r31)
	  fmuls     f4, f30, f4
	  fmuls     f2, f0, f2
	  lfs       f8, 0x198(r31)
	  lfs       f7, 0x188(r31)
	  lfs       f6, 0x18C(r31)
	  lfs       f5, 0x184(r31)
	  lfs       f11, 0x19C(r31)
	  fmuls     f10, f30, f9
	  fmuls     f9, f0, f8
	  lfs       f8, 0x190(r31)
	  fmuls     f7, f30, f7
	  fmuls     f6, f0, f6
	  fmuls     f5, f3, f5
	  fadds     f2, f4, f2
	  fmuls     f11, f3, f11
	  fadds     f9, f10, f9
	  fadds     f2, f5, f2
	  fmuls     f4, f3, f8
	  fadds     f3, f7, f6
	  fadds     f5, f11, f9
	  fadds     f2, f27, f2
	  fadds     f3, f4, f3
	  fadds     f4, f29, f5
	  stfs      f2, 0x2B8(r1)
	  fadds     f2, f28, f3
	  stfs      f2, 0x2BC(r1)
	  li        r28, 0x20
	  lfs       f11, -0x78F8(r13)
	  li        r29, 0xFF
	  stfs      f4, 0x2C0(r1)
	  li        r30, 0x80
	  lfs       f3, 0x17C(r31)
	  addi      r4, r1, 0x1F0
	  lfs       f2, 0x180(r31)
	  mr        r3, r26
	  fmuls     f3, f1, f3
	  fmuls     f2, f0, f2
	  lfs       f4, 0x184(r31)
	  lfs       f6, 0x188(r31)
	  li        r5, 0x1
	  lfs       f5, 0x18C(r31)
	  lfs       f9, 0x194(r31)
	  fmuls     f4, f11, f4
	  fadds     f2, f3, f2
	  lfs       f8, 0x198(r31)
	  fmuls     f6, f1, f6
	  fmuls     f5, f0, f5
	  fmuls     f9, f1, f9
	  fmuls     f3, f0, f8
	  lfs       f7, 0x190(r31)
	  fadds     f0, f4, f2
	  lfs       f10, 0x19C(r31)
	  fmuls     f2, f11, f7
	  fadds     f1, f6, f5
	  stb       r28, 0x1F0(r1)
	  fadds     f0, f27, f0
	  stb       r29, 0x1F1(r1)
	  fadds     f1, f2, f1
	  stb       r28, 0x1F2(r1)
	  fmuls     f4, f11, f10
	  fadds     f3, f9, f3
	  stfs      f0, 0x2AC(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f4, f3
	  stb       r30, 0x1F3(r1)
	  stfs      f1, 0x2B0(r1)
	  fadds     f0, f29, f0
	  stfs      f0, 0x2B4(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x33C
	  addi      r5, r1, 0x330
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x330
	  addi      r5, r1, 0x324
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x324
	  addi      r5, r1, 0x318
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x318
	  addi      r5, r1, 0x33C
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x33C
	  addi      r5, r1, 0x3A8
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x330
	  addi      r5, r1, 0x39C
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x324
	  addi      r5, r1, 0x390
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x318
	  addi      r5, r1, 0x384
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x3A8
	  addi      r5, r1, 0x39C
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x39C
	  addi      r5, r1, 0x390
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x390
	  addi      r5, r1, 0x384
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x384
	  addi      r5, r1, 0x3A8
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x1EC(r1)
	  addi      r4, r1, 0x1EC
	  addi      r3, r26, 0
	  stb       r28, 0x1ED(r1)
	  li        r5, 0x1
	  stb       r28, 0x1EE(r1)
	  stb       r30, 0x1EF(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2D0
	  addi      r5, r1, 0x2C4
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2C4
	  addi      r5, r1, 0x2B8
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2B8
	  addi      r5, r1, 0x2AC
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2AC
	  addi      r5, r1, 0x2D0
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2D0
	  addi      r5, r1, 0x3A8
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2C4
	  addi      r5, r1, 0x39C
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2B8
	  addi      r5, r1, 0x390
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r1, 0x2AC
	  addi      r5, r1, 0x384
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x1E8(r1)
	  li        r30, 0
	  li        r31, 0x10
	  stb       r30, 0x1E9(r1)
	  addi      r4, r1, 0x1E8
	  addi      r3, r26, 0
	  stb       r30, 0x1EA(r1)
	  li        r5, 0x1
	  stb       r31, 0x1EB(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7BF8(r2)
	  mr        r3, r26
	  lwz       r11, 0x330(r1)
	  addi      r4, r1, 0x27C
	  stfs      f0, 0x284(r1)
	  lwz       r10, 0x334(r1)
	  addi      r6, r1, 0x25C
	  stfs      f0, 0x280(r1)
	  li        r5, 0
	  lwz       r9, 0x338(r1)
	  stfs      f0, 0x27C(r1)
	  li        r7, 0x4
	  lwz       r8, 0x33C(r1)
	  stfs      f0, 0x290(r1)
	  lwz       r0, 0x340(r1)
	  stfs      f0, 0x28C(r1)
	  stfs      f0, 0x288(r1)
	  stfs      f0, 0x29C(r1)
	  stfs      f0, 0x298(r1)
	  stfs      f0, 0x25C(r1)
	  stfs      f0, 0x294(r1)
	  stfs      f0, 0x260(r1)
	  stfs      f0, 0x2A8(r1)
	  stfs      f0, 0x264(r1)
	  stfs      f0, 0x2A4(r1)
	  stfs      f0, 0x268(r1)
	  stfs      f0, 0x2A0(r1)
	  stfs      f0, 0x26C(r1)
	  stfs      f0, 0x270(r1)
	  stw       r11, 0x27C(r1)
	  stfs      f0, 0x274(r1)
	  stw       r10, 0x280(r1)
	  stfs      f0, 0x278(r1)
	  stw       r9, 0x284(r1)
	  stw       r8, 0x288(r1)
	  stw       r0, 0x28C(r1)
	  lwz       r0, 0x344(r1)
	  stw       r0, 0x290(r1)
	  lwz       r8, 0x2D0(r1)
	  lwz       r0, 0x2D4(r1)
	  stw       r8, 0x294(r1)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x2D8(r1)
	  stw       r0, 0x29C(r1)
	  lwz       r8, 0x2C4(r1)
	  lwz       r0, 0x2C8(r1)
	  stw       r8, 0x2A0(r1)
	  stw       r0, 0x2A4(r1)
	  lwz       r0, 0x2CC(r1)
	  stw       r0, 0x2A8(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x1E4(r1)
	  addi      r4, r1, 0x1E4
	  addi      r3, r26, 0
	  stb       r30, 0x1E5(r1)
	  li        r5, 0x1
	  stb       r28, 0x1E6(r1)
	  stb       r31, 0x1E7(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x324(r1)
	  mr        r3, r26
	  lwz       r5, 0x328(r1)
	  addi      r4, r1, 0x27C
	  stw       r0, 0x27C(r1)
	  lwz       r0, 0x32C(r1)
	  addi      r6, r1, 0x25C
	  stw       r5, 0x280(r1)
	  li        r5, 0
	  lwz       r8, 0x330(r1)
	  stw       r0, 0x284(r1)
	  li        r7, 0x4
	  lwz       r0, 0x334(r1)
	  stw       r8, 0x288(r1)
	  stw       r0, 0x28C(r1)
	  lwz       r0, 0x338(r1)
	  stw       r0, 0x290(r1)
	  lwz       r8, 0x2C4(r1)
	  lwz       r0, 0x2C8(r1)
	  stw       r8, 0x294(r1)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x2CC(r1)
	  stw       r0, 0x29C(r1)
	  lwz       r8, 0x2B8(r1)
	  lwz       r0, 0x2BC(r1)
	  stw       r8, 0x2A0(r1)
	  stw       r0, 0x2A4(r1)
	  lwz       r0, 0x2C0(r1)
	  stw       r0, 0x2A8(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x1E0(r1)
	  addi      r4, r1, 0x1E0
	  addi      r3, r26, 0
	  stb       r30, 0x1E1(r1)
	  li        r5, 0x1
	  stb       r30, 0x1E2(r1)
	  stb       r31, 0x1E3(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x318(r1)
	  mr        r3, r26
	  lwz       r5, 0x31C(r1)
	  addi      r4, r1, 0x27C
	  stw       r0, 0x27C(r1)
	  lwz       r0, 0x320(r1)
	  addi      r6, r1, 0x25C
	  stw       r5, 0x280(r1)
	  li        r5, 0
	  lwz       r8, 0x324(r1)
	  stw       r0, 0x284(r1)
	  li        r7, 0x4
	  lwz       r0, 0x328(r1)
	  stw       r8, 0x288(r1)
	  stw       r0, 0x28C(r1)
	  lwz       r0, 0x32C(r1)
	  stw       r0, 0x290(r1)
	  lwz       r8, 0x2B8(r1)
	  lwz       r0, 0x2BC(r1)
	  stw       r8, 0x294(r1)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x2C0(r1)
	  stw       r0, 0x29C(r1)
	  lwz       r8, 0x2AC(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r8, 0x2A0(r1)
	  stw       r0, 0x2A4(r1)
	  lwz       r0, 0x2B4(r1)
	  stw       r0, 0x2A8(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x1DC(r1)
	  addi      r4, r1, 0x1DC
	  addi      r3, r26, 0
	  stb       r30, 0x1DD(r1)
	  li        r5, 0x1
	  stb       r28, 0x1DE(r1)
	  stb       r31, 0x1DF(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x33C(r1)
	  mr        r3, r26
	  lwz       r5, 0x340(r1)
	  addi      r4, r1, 0x27C
	  stw       r0, 0x27C(r1)
	  lwz       r0, 0x344(r1)
	  addi      r6, r1, 0x25C
	  stw       r5, 0x280(r1)
	  li        r5, 0
	  lwz       r8, 0x318(r1)
	  stw       r0, 0x284(r1)
	  li        r7, 0x4
	  lwz       r0, 0x31C(r1)
	  stw       r8, 0x288(r1)
	  stw       r0, 0x28C(r1)
	  lwz       r0, 0x320(r1)
	  stw       r0, 0x290(r1)
	  lwz       r8, 0x2AC(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r8, 0x294(r1)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x2B4(r1)
	  stw       r0, 0x29C(r1)
	  lwz       r8, 0x2D0(r1)
	  lwz       r0, 0x2D4(r1)
	  stw       r8, 0x2A0(r1)
	  stw       r0, 0x2A4(r1)
	  lwz       r0, 0x2D8(r1)
	  stw       r0, 0x2A8(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lmw       r26, 0x3E8(r1)
	  lwz       r0, 0x434(r1)
	  lfd       f31, 0x428(r1)
	  lfd       f30, 0x420(r1)
	  lfd       f29, 0x418(r1)
	  lfd       f28, 0x410(r1)
	  lfd       f27, 0x408(r1)
	  lfd       f26, 0x400(r1)
	  addi      r1, r1, 0x430
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800425AC
 * Size:	00046C
 */
void CullFrustum::updateViewPlanes(f32, f32, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  fabs      f1, f1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stfd      f28, 0xA0(r1)
	  fmr       f28, f4
	  stfd      f27, 0x98(r1)
	  fmr       f27, f3
	  stfd      f26, 0x90(r1)
	  fmr       f26, f2
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lfs       f0, 0x1DC(r3)
	  lfs       f31, 0x1D8(r3)
	  fdivs     f29, f0, f1
	  lfs       f30, -0x7BF8(r2)
	  lwz       r0, 0x8(r3)
	  mulli     r3, r0, 0x2C
	  addi      r31, r3, 0xC
	  fmuls     f1, f29, f29
	  add       r31, r30, r31
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x349E0
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x90
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1

	.loc_0x90:
	  lfs       f1, 0x17C(r30)
	  mr        r3, r31
	  lfs       f0, 0x180(r30)
	  fmuls     f1, f29, f1
	  lfs       f2, 0x184(r30)
	  fmuls     f0, f30, f0
	  fmuls     f2, f31, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r31)
	  lfs       f1, 0x188(r30)
	  lfs       f0, 0x18C(r30)
	  lfs       f2, 0x190(r30)
	  fmuls     f1, f29, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f31, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x194(r30)
	  lfs       f0, 0x198(r30)
	  lfs       f2, 0x19C(r30)
	  fmuls     f1, f29, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f31, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x8(r31)
	  lfs       f3, 0x0(r31)
	  lfs       f2, 0x164(r30)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x168(r30)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r31)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x16C(r30)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)
	  bl        -0xB170
	  li        r0, 0x1
	  fabs      f3, f26
	  stb       r0, 0x28(r31)
	  lfs       f0, 0x1DC(r30)
	  lfs       f30, -0x7BF8(r2)
	  fneg      f1, f0
	  lfs       f29, 0x1D8(r30)
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fdivs     f31, f1, f3
	  fmuls     f1, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x34AD4
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x184
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x184:
	  lfs       f1, 0x17C(r30)
	  addi      r3, r31, 0x2C
	  lfs       f0, 0x180(r30)
	  fmuls     f1, f31, f1
	  lfs       f2, 0x184(r30)
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f1, 0x188(r30)
	  lfs       f0, 0x18C(r30)
	  lfs       f2, 0x190(r30)
	  fmuls     f1, f31, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x30(r31)
	  lfs       f1, 0x194(r30)
	  lfs       f0, 0x198(r30)
	  lfs       f2, 0x19C(r30)
	  fmuls     f1, f31, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x34(r31)
	  lfs       f3, 0x2C(r31)
	  lfs       f2, 0x164(r30)
	  lfs       f1, 0x30(r31)
	  lfs       f0, 0x168(r30)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x34(r31)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x16C(r30)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r31)
	  bl        -0xB264
	  li        r0, 0x1
	  fabs      f3, f27
	  stb       r0, 0x54(r31)
	  lfs       f0, 0x1DC(r30)
	  lfs       f31, -0x7BF8(r2)
	  fneg      f0, f0
	  lfs       f29, 0x1D8(r30)
	  fmuls     f1, f31, f31
	  fmuls     f2, f29, f29
	  fmuls     f30, f0, f3
	  fmuls     f0, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x34BC8
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x278
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x278:
	  lfs       f1, 0x17C(r30)
	  addi      r3, r31, 0x58
	  lfs       f0, 0x180(r30)
	  fmuls     f1, f31, f1
	  lfs       f2, 0x184(r30)
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x58(r31)
	  lfs       f1, 0x188(r30)
	  lfs       f0, 0x18C(r30)
	  lfs       f2, 0x190(r30)
	  fmuls     f1, f31, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x5C(r31)
	  lfs       f1, 0x194(r30)
	  lfs       f0, 0x198(r30)
	  lfs       f2, 0x19C(r30)
	  fmuls     f1, f31, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x60(r31)
	  lfs       f3, 0x58(r31)
	  lfs       f2, 0x164(r30)
	  lfs       f1, 0x5C(r31)
	  lfs       f0, 0x168(r30)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x60(r31)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x16C(r30)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x64(r31)
	  bl        -0xB358
	  li        r0, 0x1
	  fabs      f1, f28
	  stb       r0, 0x80(r31)
	  lfs       f0, 0x1DC(r30)
	  lfs       f31, -0x7BF8(r2)
	  fmuls     f30, f0, f1
	  lfs       f29, 0x1D8(r30)
	  fmuls     f1, f31, f31
	  fmuls     f2, f29, f29
	  fmuls     f0, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x34CB8
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x368
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x368:
	  lfs       f1, 0x17C(r30)
	  addi      r3, r31, 0x84
	  lfs       f0, 0x180(r30)
	  fmuls     f1, f31, f1
	  lfs       f2, 0x184(r30)
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x84(r31)
	  lfs       f1, 0x188(r30)
	  lfs       f0, 0x18C(r30)
	  lfs       f2, 0x190(r30)
	  fmuls     f1, f31, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x88(r31)
	  lfs       f1, 0x194(r30)
	  lfs       f0, 0x198(r30)
	  lfs       f2, 0x19C(r30)
	  fmuls     f1, f31, f1
	  fmuls     f0, f30, f0
	  fmuls     f2, f29, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x8C(r31)
	  lfs       f3, 0x84(r31)
	  lfs       f2, 0x164(r30)
	  lfs       f1, 0x88(r31)
	  lfs       f0, 0x168(r30)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8C(r31)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x16C(r30)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r31)
	  bl        -0xB448
	  lis       r3, 0x2E8C
	  addi      r4, r30, 0xC
	  addi      r0, r31, 0xB0
	  sub       r0, r0, r4
	  subi      r3, r3, 0x5D17
	  mulhw     r0, r3, r0
	  srawi     r0, r0, 0x3
	  li        r4, 0x1
	  rlwinm    r3,r0,1,31,31
	  stb       r4, 0xAC(r31)
	  add       r0, r0, r3
	  stw       r0, 0x0(r30)
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lfd       f28, 0xA0(r1)
	  lfd       f27, 0x98(r1)
	  lfd       f26, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80042A18
 * Size:	00023C
 */
void CullFrustum::createViewPlanes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  addi      r29, r3, 0
	  addi      r30, r29, 0xC
	  stw       r0, 0x0(r3)
	  lfs       f1, -0x7BF0(r2)
	  lfs       f0, 0x1CC(r3)
	  lfs       f2, -0x7BF4(r2)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x7BEC(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x1D928C
	  stfs      f1, 0x1D8(r29)
	  lfs       f1, -0x7BF0(r2)
	  lfs       f0, 0x1CC(r29)
	  lfs       f2, -0x7BF4(r2)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x7BEC(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x1D90D4
	  stfs      f1, 0x1DC(r29)
	  mr        r3, r30
	  lfs       f4, -0x78F4(r13)
	  lfs       f1, 0x17C(r29)
	  lfs       f3, -0x78F0(r13)
	  lfs       f0, 0x180(r29)
	  fmuls     f1, f4, f1
	  lfs       f5, -0x78EC(r13)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x184(r29)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r30)
	  lfs       f1, 0x188(r29)
	  lfs       f0, 0x18C(r29)
	  lfs       f2, 0x190(r29)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x194(r29)
	  lfs       f0, 0x198(r29)
	  lfs       f2, 0x19C(r29)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x8(r30)
	  lfs       f3, 0x0(r30)
	  lfs       f2, 0x164(r29)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x168(r29)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r30)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x16C(r29)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, 0x1D0(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r30)
	  bl        -0xB5D8
	  li        r31, 0x1
	  stb       r31, 0x28(r30)
	  addi      r3, r30, 0x2C
	  lfs       f4, -0x78E8(r13)
	  lfs       f1, 0x17C(r29)
	  lfs       f3, -0x78E4(r13)
	  lfs       f0, 0x180(r29)
	  fmuls     f1, f4, f1
	  lfs       f5, -0x78E0(r13)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x184(r29)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2C(r30)
	  lfs       f1, 0x188(r29)
	  lfs       f0, 0x18C(r29)
	  lfs       f2, 0x190(r29)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x30(r30)
	  lfs       f1, 0x194(r29)
	  lfs       f0, 0x198(r29)
	  lfs       f2, 0x19C(r29)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x34(r30)
	  lfs       f3, 0x2C(r30)
	  lfs       f2, 0x164(r29)
	  lfs       f1, 0x30(r30)
	  lfs       f0, 0x168(r29)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x34(r30)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x16C(r29)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r30)
	  lfs       f1, 0x38(r30)
	  lfs       f0, -0x7BD8(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r30)
	  bl        -0xB6A0
	  addi      r0, r30, 0x58
	  stb       r31, 0x54(r30)
	  lis       r3, 0x2E8C
	  sub       r0, r0, r30
	  subi      r3, r3, 0x5D17
	  mulhw     r0, r3, r0
	  srawi     r0, r0, 0x3
	  rlwinm    r3,r0,1,31,31
	  add       r0, r0, r3
	  stw       r0, 0x8(r29)
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void CullFrustum::additionalPlanes(CullFrustum*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void CullFrustum::createVecs()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void CullFrustum::createInvVecs()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80042C54
 * Size:	000150
 */
void CullFrustum::update(f32, f32, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stfs      f1, 0x1C4(r3)
	  lfs       f0, -0x7BD4(r2)
	  stfs      f0, 0x1C8(r31)
	  stfs      f2, 0x1CC(r31)
	  stfs      f3, 0x1D0(r31)
	  stfs      f4, 0x1D4(r31)
	  lfs       f0, 0x1E0(r31)
	  stfs      f0, 0x17C(r31)
	  lfs       f0, 0x1F0(r31)
	  stfs      f0, 0x180(r31)
	  lfs       f0, 0x200(r31)
	  fneg      f0, f0
	  stfs      f0, 0x184(r31)
	  lfs       f0, 0x1E4(r31)
	  stfs      f0, 0x188(r31)
	  lfs       f0, 0x1F4(r31)
	  stfs      f0, 0x18C(r31)
	  lfs       f0, 0x204(r31)
	  fneg      f0, f0
	  stfs      f0, 0x190(r31)
	  lfs       f0, 0x1E8(r31)
	  stfs      f0, 0x194(r31)
	  lfs       f0, 0x1F8(r31)
	  stfs      f0, 0x198(r31)
	  lfs       f0, 0x208(r31)
	  fneg      f0, f0
	  stfs      f0, 0x19C(r31)
	  lfs       f0, 0x1E0(r31)
	  stfs      f0, 0x1A0(r31)
	  lfs       f0, 0x1E4(r31)
	  stfs      f0, 0x1A4(r31)
	  lfs       f0, 0x1E8(r31)
	  stfs      f0, 0x1A8(r31)
	  lfs       f0, 0x1F0(r31)
	  stfs      f0, 0x1AC(r31)
	  lfs       f0, 0x1F4(r31)
	  stfs      f0, 0x1B0(r31)
	  lfs       f0, 0x1F8(r31)
	  stfs      f0, 0x1B4(r31)
	  lfs       f0, 0x200(r31)
	  fneg      f0, f0
	  stfs      f0, 0x1B8(r31)
	  lfs       f0, 0x204(r31)
	  fneg      f0, f0
	  stfs      f0, 0x1BC(r31)
	  lfs       f0, 0x208(r31)
	  fneg      f0, f0
	  stfs      f0, 0x1C0(r31)
	  bl        -0x310
	  lfs       f4, 0x1C8(r31)
	  mr        r3, r31
	  lfs       f1, 0x1C4(r31)
	  fneg      f3, f4
	  fneg      f2, f1
	  bl        -0x794
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0
	  b         .loc_0x114

	.loc_0x100:
	  addi      r0, r3, 0xC
	  stw       r0, 0x114(r4)
	  addi      r3, r3, 0x2C
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0x1

	.loc_0x114:
	  lwz       r0, 0x0(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x100
	  stw       r0, 0x4(r31)
	  lfs       f0, -0x78DC(r13)
	  stfs      f0, 0x158(r31)
	  lfs       f0, -0x78D8(r13)
	  stfs      f0, 0x15C(r31)
	  lfs       f0, -0x78D4(r13)
	  stfs      f0, 0x160(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80042DA4
 * Size:	000268
 */
void CullFrustum::calcVectors(Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  lwz       r6, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r6, 0x164(r3)
	  stw       r0, 0x168(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x16C(r3)
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r3, 0x170(r31)
	  stw       r0, 0x174(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x178(r31)
	  lfs       f1, 0x164(r31)
	  lfs       f0, 0x170(r31)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x70
	  lfs       f0, 0x16C(r31)
	  lfs       f1, 0x178(r31)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x70
	  lfs       f0, -0x7BD0(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x178(r31)

	.loc_0x70:
	  lfs       f1, 0x164(r31)
	  lfs       f0, 0x170(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x194(r31)
	  lfs       f1, 0x168(r31)
	  lfs       f0, 0x174(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x198(r31)
	  lfs       f1, 0x16C(r31)
	  lfs       f0, 0x178(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x19C(r31)
	  lfs       f1, 0x194(r31)
	  lfs       f0, 0x198(r31)
	  lfs       f2, 0x19C(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x35224
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xF4
	  lfs       f0, 0x194(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x194(r31)
	  lfs       f0, 0x198(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x198(r31)
	  lfs       f0, 0x19C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x19C(r31)

	.loc_0xF4:
	  lfs       f1, 0x194(r31)
	  lfs       f0, 0x19C(r31)
	  fneg      f1, f1
	  stfs      f0, 0x17C(r31)
	  lfs       f0, -0x78D0(r13)
	  stfs      f0, 0x180(r31)
	  stfs      f1, 0x184(r31)
	  lfs       f1, 0x17C(r31)
	  lfs       f0, 0x180(r31)
	  lfs       f2, 0x184(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x35294
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x164
	  lfs       f0, 0x17C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x17C(r31)
	  lfs       f0, 0x180(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x180(r31)
	  lfs       f0, 0x184(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x184(r31)

	.loc_0x164:
	  lwz       r3, 0x194(r31)
	  lwz       r0, 0x198(r31)
	  stw       r3, 0x188(r31)
	  stw       r0, 0x18C(r31)
	  lwz       r0, 0x19C(r31)
	  stw       r0, 0x190(r31)
	  lfs       f1, 0x190(r31)
	  lfs       f6, 0x180(r31)
	  lfs       f5, 0x17C(r31)
	  lfs       f7, 0x18C(r31)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x184(r31)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x188(r31)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x188(r31)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x18C(r31)
	  stfs      f0, 0x190(r31)
	  lfs       f1, 0x188(r31)
	  lfs       f0, 0x18C(r31)
	  lfs       f2, 0x190(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x35348
	  lfs       f0, -0x7BF8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x218
	  lfs       f0, 0x188(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x188(r31)
	  lfs       f0, 0x18C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x18C(r31)
	  lfs       f0, 0x190(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x190(r31)

	.loc_0x218:
	  addi      r3, r31, 0x1E0
	  addi      r4, r31, 0x164
	  addi      r5, r31, 0x17C
	  addi      r6, r31, 0x188
	  addi      r7, r31, 0x194
	  bl        -0x4450
	  addi      r3, r31, 0x1E0
	  addi      r4, r31, 0x220
	  bl        -0x4BA0
	  lfs       f1, -0x7BD4(r2)
	  mr        r3, r31
	  lfs       f2, 0x1CC(r31)
	  lfs       f3, 0x1D0(r31)
	  lfs       f4, 0x1D4(r31)
	  bl        -0x3A0
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004300C
 * Size:	00003C
 */
void CullFrustum::calcLookAt(Vector3f&, Vector3f&, Vector3f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x1E0
	  bl        -0x47A4
	  addi      r3, r31, 0x1E0
	  addi      r4, r31, 0x220
	  bl        -0x4BF4
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void CullFrustum::calcLookFrom(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
void Camera::camReflect(Camera&, Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80043048
 * Size:	00017C
 */
void Camera::projectWorldPoint(Graphics&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r5
	  stw       r30, 0x38(r1)
	  mr        r30, r4
	  lfs       f4, 0x2D0(r3)
	  lfs       f3, 0x0(r5)
	  lfs       f2, 0x2D4(r3)
	  lfs       f1, 0x4(r5)
	  fmuls     f3, f4, f3
	  lfs       f4, 0x2D8(r3)
	  fmuls     f1, f2, f1
	  lfs       f2, 0x8(r5)
	  lfs       f5, 0x2DC(r3)
	  fmuls     f2, f4, f2
	  lfs       f0, -0x7BF8(r2)
	  fadds     f1, f3, f1
	  fadds     f1, f2, f1
	  fadds     f1, f5, f1
	  fcmpo     cr0, f1, f0
	  fmr       f31, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x74
	  fmr       f1, f31
	  b         .loc_0x160

	.loc_0x74:
	  addi      r3, r31, 0
	  addi      r4, r6, 0x2A0
	  bl        -0xB978
	  lfs       f1, -0x7BD4(r2)
	  lis       r3, 0x4330
	  lfs       f0, 0x0(r31)
	  fdivs     f1, f1, f31
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r31)
	  lwz       r0, 0x30C(r30)
	  lfd       f3, -0x7BC8(r2)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x7BF0(r2)
	  stw       r0, 0x34(r1)
	  lfs       f1, 0x0(r31)
	  stw       r3, 0x30(r1)
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lwz       r0, 0x310(r30)
	  lfs       f1, 0x4(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x2C(r1)
	  stw       r3, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f2
	  fneg      f0, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lwz       r0, 0x30C(r30)
	  lfs       f1, 0x0(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x24(r1)
	  stw       r3, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lwz       r0, 0x310(r30)
	  lfs       f1, 0x4(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1C(r1)
	  stw       r3, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x8(r31)

	.loc_0x160:
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
void Camera::projectCamPoint(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800431C4
 * Size:	000150
 */
Camera::Camera()
{
	_155 = 0;
	_164.set(0.0f, 0.0f, 0.0f);
	_1CC = 60.0f;
	_1D0 = 1.0f;
	_1D4 = 1000.0f;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8003
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x63B8
	  li        r5, 0
	  stwu      r1, -0x18(r1)
	  li        r6, 0x2C
	  li        r7, 0x6
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0xC
	  bl        0x1D1880
	  lfs       f2, -0x7BF8(r2)
	  li        r0, 0
	  addi      r3, r31, 0
	  stfs      f2, 0x160(r31)
	  stfs      f2, 0x15C(r31)
	  stfs      f2, 0x158(r31)
	  stfs      f2, 0x16C(r31)
	  stfs      f2, 0x168(r31)
	  stfs      f2, 0x164(r31)
	  stfs      f2, 0x178(r31)
	  stfs      f2, 0x174(r31)
	  stfs      f2, 0x170(r31)
	  stfs      f2, 0x184(r31)
	  stfs      f2, 0x180(r31)
	  stfs      f2, 0x17C(r31)
	  stfs      f2, 0x190(r31)
	  stfs      f2, 0x18C(r31)
	  stfs      f2, 0x188(r31)
	  stfs      f2, 0x19C(r31)
	  stfs      f2, 0x198(r31)
	  stfs      f2, 0x194(r31)
	  stfs      f2, 0x1A8(r31)
	  stfs      f2, 0x1A4(r31)
	  stfs      f2, 0x1A0(r31)
	  stfs      f2, 0x1B4(r31)
	  stfs      f2, 0x1B0(r31)
	  stfs      f2, 0x1AC(r31)
	  stfs      f2, 0x1C0(r31)
	  stfs      f2, 0x1BC(r31)
	  stfs      f2, 0x1B8(r31)
	  stb       r0, 0x155(r31)
	  lfs       f0, -0x7930(r13)
	  stfs      f0, 0x164(r31)
	  lfs       f0, -0x792C(r13)
	  stfs      f0, 0x168(r31)
	  lfs       f0, -0x7928(r13)
	  stfs      f0, 0x16C(r31)
	  lfs       f0, -0x7BC0(r2)
	  stfs      f0, 0x1CC(r31)
	  lfs       f1, -0x7BD4(r2)
	  stfs      f1, 0x1D0(r31)
	  lfs       f0, -0x7BBC(r2)
	  stfs      f0, 0x1D4(r31)
	  stfs      f2, 0x328(r31)
	  stfs      f2, 0x324(r31)
	  stfs      f2, 0x320(r31)
	  stfs      f2, 0x334(r31)
	  stfs      f2, 0x330(r31)
	  stfs      f2, 0x32C(r31)
	  stfs      f2, 0x340(r31)
	  stfs      f2, 0x33C(r31)
	  stfs      f2, 0x338(r31)
	  lfs       f0, -0x78CC(r13)
	  stfs      f0, 0x320(r31)
	  lfs       f0, -0x78C8(r13)
	  stfs      f0, 0x324(r31)
	  lfs       f0, -0x78C4(r13)
	  stfs      f0, 0x328(r31)
	  lfs       f0, -0x78C0(r13)
	  stfs      f0, 0x32C(r31)
	  lfs       f0, -0x78BC(r13)
	  stfs      f0, 0x330(r31)
	  lfs       f0, -0x78B8(r13)
	  stfs      f0, 0x334(r31)
	  stfs      f1, 0x1C4(r31)
	  lfs       f0, -0x7BB8(r2)
	  stfs      f0, 0x344(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80043314
 * Size:	0000D0
 */
void LightCamera::initLightmap(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  li        r3, 0x3C
	  bl        0x3CC4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x40
	  bl        0xE44

	.loc_0x40:
	  xoris     r0, r29, 0x8000
	  stw       r31, 0x358(r28)
	  lis       r3, 0x4330
	  stw       r0, 0x1C(r1)
	  li        r0, 0x105
	  lfd       f1, -0x7BC8(r2)
	  mr        r4, r29
	  stw       r3, 0x18(r1)
	  lfs       f2, -0x7BD4(r2)
	  mr        r5, r29
	  lfd       f0, 0x18(r1)
	  mr        r6, r30
	  lwz       r3, 0x358(r28)
	  fsubs     f0, f0, f1
	  li        r7, 0
	  fdivs     f0, f2, f0
	  stfs      f0, 0x28(r3)
	  lwz       r3, 0x358(r28)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x358(r28)
	  sth       r0, 0x6(r3)
	  lwz       r3, 0x358(r28)
	  bl        0x11B8
	  lis       r4, 0x8023
	  lwz       r3, 0x2DEC(r13)
	  subi      r5, r4, 0x7118
	  lwz       r4, 0x358(r28)
	  bl        -0x3BC8
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800433E4
 * Size:	000508
 */
void LightCamera::calcProjection(Graphics&, bool, Node*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x150(r1)
	  stfd      f31, 0x148(r1)
	  stfd      f30, 0x140(r1)
	  stw       r31, 0x13C(r1)
	  mr        r31, r6
	  stw       r30, 0x138(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x134(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x130(r1)
	  lfs       f0, -0x7BF8(r2)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x170(r3)
	  lfs       f0, 0x164(r3)
	  lfs       f4, 0x178(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x16C(r3)
	  lfs       f2, 0x174(r3)
	  lfs       f1, 0x168(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x68(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f1, 0x78(r1)
	  stfs      f3, 0x7C(r1)
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  lfs       f2, 0x7C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x3583C
	  lfs       f2, -0x7BF4(r2)
	  fmr       f31, f1
	  lfs       f1, 0x1CC(r29)
	  lfs       f0, -0x7BEC(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x1D86BC
	  lfs       f2, -0x7BF4(r2)
	  fmr       f30, f1
	  lfs       f1, 0x1CC(r29)
	  lfs       f0, -0x7BEC(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x1D8834
	  fdivs     f1, f1, f30
	  fmuls     f0, f1, f31
	  stfs      f0, 0x354(r29)
	  lfs       f0, 0x354(r29)
	  stfs      f0, 0x350(r29)
	  lfs       f0, -0x7BD4(r2)
	  lfs       f3, 0x168(r29)
	  fdivs     f7, f0, f1
	  lfs       f2, 0x174(r29)
	  lfs       f1, 0x164(r29)
	  lfs       f0, 0x170(r29)
	  lfs       f6, 0x354(r29)
	  fsubs     f4, f3, f2
	  lfs       f2, -0x7BF8(r2)
	  fsubs     f3, f1, f0
	  lfs       f1, 0x16C(r29)
	  lfs       f0, 0x178(r29)
	  fsubs     f0, f1, f0
	  lfs       f5, 0x350(r29)
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fmuls     f4, f0, f0
	  fmuls     f0, f6, f7
	  fadds     f1, f3, f1
	  fmuls     f6, f5, f7
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f2
	  ble-      .loc_0x1A0
	  fsqrte    f3, f1
	  lfd       f5, -0x7BE8(r2)
	  lfd       f4, -0x7BE0(r2)
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f1, f2
	  fsub      f2, f4, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f1, f2
	  fsub      f2, f4, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f1, f2
	  fsub      f2, f4, f2
	  fmul      f2, f3, f2
	  fmul      f2, f1, f2
	  frsp      f2, f2
	  stfs      f2, 0x64(r1)
	  lfs       f2, 0x64(r1)
	  b         .loc_0x1A4

	.loc_0x1A0:
	  fmr       f2, f1

	.loc_0x1A4:
	  fdivs     f2, f2, f6
	  stfs      f2, 0x348(r29)
	  lfs       f2, -0x7BF8(r2)
	  fcmpo     cr0, f1, f2
	  ble-      .loc_0x210
	  fsqrte    f3, f1
	  lfd       f5, -0x7BE8(r2)
	  lfd       f4, -0x7BE0(r2)
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f1, f2
	  fsub      f2, f4, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f1, f2
	  fsub      f2, f4, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f1, f2
	  fsub      f2, f4, f2
	  fmul      f2, f3, f2
	  fmul      f1, f1, f2
	  frsp      f1, f1
	  stfs      f1, 0x60(r1)
	  lfs       f1, 0x60(r1)

	.loc_0x210:
	  fdivs     f0, f1, f0
	  stfs      f0, 0x34C(r29)
	  lfs       f2, -0x7BF0(r2)
	  lfs       f0, 0x348(r29)
	  lfs       f1, 0x34C(r29)
	  fmuls     f0, f2, f0
	  fmuls     f1, f2, f1
	  stfs      f0, 0x35C(r29)
	  stfs      f1, 0x360(r29)
	  lfs       f0, -0x78B4(r13)
	  stfs      f0, 0x364(r29)
	  lwz       r0, 0x358(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x4E0
	  cmplwi    r31, 0
	  beq-      .loc_0x4E0
	  lfs       f5, -0x7BD4(r2)
	  lis       r28, 0x4330
	  lfs       f0, 0x348(r29)
	  mr        r3, r30
	  addi      r4, r29, 0x260
	  fsubs     f0, f0, f5
	  fmuls     f0, f2, f0
	  stfs      f0, 0x348(r29)
	  lfs       f0, 0x34C(r29)
	  fsubs     f0, f0, f5
	  fmuls     f0, f2, f0
	  stfs      f0, 0x34C(r29)
	  lwz       r6, 0x358(r29)
	  lwz       r12, 0x3B4(r30)
	  lhz       r5, 0x8(r6)
	  lhz       r0, 0xA(r6)
	  stw       r5, 0x12C(r1)
	  lwz       r12, 0x3C(r12)
	  stw       r0, 0x124(r1)
	  lfd       f2, -0x7BA8(r2)
	  mtlr      r12
	  stw       r28, 0x128(r1)
	  lfs       f6, -0x7BB4(r2)
	  stw       r28, 0x120(r1)
	  lfd       f1, 0x128(r1)
	  lfd       f0, 0x120(r1)
	  fsubs     f4, f1, f2
	  lfs       f1, 0x1CC(r29)
	  fsubs     f0, f0, f2
	  lfs       f2, 0x1C4(r29)
	  lfs       f3, -0x7BB0(r2)
	  fmuls     f31, f6, f4
	  lfs       f4, 0x1D4(r29)
	  fmuls     f30, f6, f0
	  blrl
	  lfs       f1, 0x348(r29)
	  addi      r4, r1, 0x94
	  lfs       f0, 0x34C(r29)
	  mr        r3, r30
	  fmuls     f1, f31, f1
	  fmuls     f3, f30, f0
	  lfd       f4, -0x7BC8(r2)
	  fctiwz    f0, f1
	  fctiwz    f2, f3
	  fneg      f1, f1
	  stfd      f0, 0x100(r1)
	  fneg      f0, f3
	  stfd      f2, 0x118(r1)
	  fctiwz    f1, f1
	  lwz       r0, 0x104(r1)
	  fctiwz    f0, f0
	  lwz       r5, 0x11C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xFC(r1)
	  xoris     r0, r5, 0x8000
	  stw       r0, 0x114(r1)
	  stw       r28, 0xF8(r1)
	  stw       r28, 0x110(r1)
	  lfd       f2, 0xF8(r1)
	  stfd      f1, 0xE8(r1)
	  lfd       f3, 0x110(r1)
	  fsubs     f2, f2, f4
	  stfd      f0, 0xE0(r1)
	  fsubs     f1, f3, f4
	  lwz       r5, 0xEC(r1)
	  fadds     f0, f31, f2
	  lwz       r0, 0xE4(r1)
	  fadds     f1, f30, f1
	  fctiwz    f0, f0
	  stw       r5, 0x94(r1)
	  fctiwz    f1, f1
	  stw       r0, 0x98(r1)
	  stfd      f0, 0xF0(r1)
	  stfd      f1, 0x108(r1)
	  lwz       r5, 0xF4(r1)
	  lwz       r0, 0x10C(r1)
	  stw       r5, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0x2E4(r30)
	  li        r0, 0
	  addi      r4, r1, 0x90
	  stb       r0, 0x90(r1)
	  mr        r3, r30
	  stb       r0, 0x91(r1)
	  stb       r0, 0x92(r1)
	  stb       r0, 0x93(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  fctiwz    f1, f31
	  li        r0, 0x4
	  fctiwz    f0, f30
	  stw       r0, 0x80(r1)
	  addi      r4, r1, 0x80
	  stfd      f1, 0xD8(r1)
	  mr        r3, r30
	  stfd      f0, 0xD0(r1)
	  lwz       r6, 0xDC(r1)
	  stw       r0, 0x84(r1)
	  lwz       r5, 0xD4(r1)
	  subi      r6, r6, 0x4
	  stw       r6, 0x88(r1)
	  subi      r0, r5, 0x4
	  stw       r0, 0x8C(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  mr        r4, r29
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x358(r29)
	  li        r6, 0x1
	  li        r7, 0x1
	  lhz       r4, 0x8(r3)
	  lhz       r5, 0xA(r3)
	  bl        0xDA0
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  mr        r4, r28
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl

	.loc_0x4E0:
	  lwz       r0, 0x154(r1)
	  lfd       f31, 0x148(r1)
	  lfd       f30, 0x140(r1)
	  lwz       r31, 0x13C(r1)
	  lwz       r30, 0x138(r1)
	  lwz       r29, 0x134(r1)
	  lwz       r28, 0x130(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}
