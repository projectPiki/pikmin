#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::zenGraphics::drawOneTri(Vector3f*, Colour&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void zen::zenGraphics::setTevFillPolygon()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801BA13C
 * Size:	000458
 */
void zen::DrawLifeCircle::drawLifeCircle(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stfd      f29, 0xB0(r1)
	  stfd      f28, 0xA8(r1)
	  fmr       f28, f1
	  stfd      f27, 0xA0(r1)
	  stmw      r27, 0x8C(r1)
	  mr        r31, r3
	  li        r3, 0x1
	  lfs       f0, -0x4810(r2)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x6C(r1)
	  bl        0x597D0
	  li        r3, 0
	  li        r4, 0x4
	  bl        0x58DFC
	  li        r3, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x59610
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x57D4C
	  bl        0x55A24
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x5521C
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x55210
	  li        r3, 0xD
	  li        r4, 0
	  bl        0x55204
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x55A34
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x55A1C
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x59A0C
	  lfs       f1, -0x480C(r2)
	  lfs       f0, -0x4810(r2)
	  fmuls     f1, f1, f28
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x12C
	  lfs       f0, -0x4808(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x134

	.loc_0x12C:
	  lfs       f0, -0x4808(r2)
	  fsubs     f0, f1, f0

	.loc_0x134:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r31)
	  stfd      f0, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stfd      f0, 0x80(r1)
	  cmpw      r3, r0
	  lwz       r0, 0x84(r1)
	  beq-      .loc_0x250
	  cmpw      r0, r3
	  bge-      .loc_0x164
	  lfs       f3, -0x4804(r2)
	  b         .loc_0x168

	.loc_0x164:
	  lfs       f3, -0x4800(r2)

	.loc_0x168:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x4(r31)
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x250
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, -0x47FC(r2)
	  lfs       f1, 0x28C(r3)
	  lfs       f0, -0x4810(r2)
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1B4
	  lfs       f0, -0x4808(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x1BC

	.loc_0x1B4:
	  lfs       f0, -0x4808(r2)
	  fsubs     f0, f1, f0

	.loc_0x1BC:
	  fctiwz    f0, f0
	  lwz       r5, 0x0(r31)
	  cmpw      r5, r0
	  stfd      f0, 0x78(r1)
	  lwz       r3, 0x7C(r1)
	  bge-      .loc_0x1DC
	  li        r4, 0x1
	  b         .loc_0x1E0

	.loc_0x1DC:
	  li        r4, -0x1

	.loc_0x1E0:
	  mullw.    r3, r4, r3
	  addi      r7, r3, 0
	  bge-      .loc_0x1F4
	  neg       r3, r7
	  b         .loc_0x1F8

	.loc_0x1F4:
	  mr        r3, r7

	.loc_0x1F8:
	  sub.      r6, r5, r0
	  bge-      .loc_0x208
	  neg       r4, r6
	  b         .loc_0x20C

	.loc_0x208:
	  mr        r4, r6

	.loc_0x20C:
	  cmpw      r4, r3
	  bge-      .loc_0x238
	  cmpwi     r6, 0
	  bge-      .loc_0x220
	  neg       r6, r6

	.loc_0x220:
	  cmpw      r5, r0
	  bge-      .loc_0x230
	  li        r0, 0x1
	  b         .loc_0x234

	.loc_0x230:
	  li        r0, -0x1

	.loc_0x234:
	  mullw     r7, r0, r6

	.loc_0x238:
	  lwz       r0, 0x0(r31)
	  add       r0, r0, r7
	  stw       r0, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x4(r31)

	.loc_0x250:
	  lfs       f0, -0x47F8(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x278
	  li        r3, 0xFF
	  stb       r3, 0x50(r1)
	  li        r0, 0
	  stb       r0, 0x51(r1)
	  stb       r0, 0x52(r1)
	  stb       r3, 0x53(r1)
	  b         .loc_0x2B8

	.loc_0x278:
	  lfs       f0, -0x4808(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x2A0
	  li        r3, 0xFF
	  stb       r3, 0x50(r1)
	  li        r0, 0
	  stb       r3, 0x51(r1)
	  stb       r0, 0x52(r1)
	  stb       r3, 0x53(r1)
	  b         .loc_0x2B8

	.loc_0x2A0:
	  li        r3, 0
	  stb       r3, 0x50(r1)
	  li        r0, 0xFF
	  stb       r0, 0x51(r1)
	  stb       r3, 0x52(r1)
	  stb       r0, 0x53(r1)

	.loc_0x2B8:
	  lfs       f0, 0x14(r31)
	  li        r27, 0
	  lis       r30, 0xCC01
	  stfs      f0, 0x54(r1)
	  lis       r29, 0x4330
	  lfs       f0, 0x14(r31)
	  stfs      f0, 0x58(r1)
	  lfs       f0, -0x4810(r2)
	  stfs      f0, 0x5C(r1)
	  lfs       f28, -0x47F4(r2)
	  lfs       f29, -0x47F0(r2)
	  lfs       f30, -0x47EC(r2)
	  lfd       f31, -0x47E8(r2)
	  b         .loc_0x424

	.loc_0x2F0:
	  xoris     r0, r27, 0x8000
	  stw       r0, 0x7C(r1)
	  stw       r29, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f31
	  fmuls     f0, f30, f0
	  fmuls     f0, f29, f0
	  fsubs     f27, f28, f0
	  fmr       f1, f27
	  bl        0x61704
	  lfs       f0, 0x14(r31)
	  lfs       f2, 0x54(r1)
	  fmuls     f0, f0, f1
	  fmr       f1, f27
	  fadds     f0, f2, f0
	  stfs      f0, 0x60(r1)
	  bl        0x6187C
	  addi      r0, r27, 0x1
	  lfs       f0, 0x14(r31)
	  xoris     r0, r0, 0x8000
	  lfs       f2, 0x58(r1)
	  stw       r0, 0x84(r1)
	  fmuls     f0, f0, f1
	  stw       r29, 0x80(r1)
	  fadds     f1, f2, f0
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f31
	  stfs      f1, 0x64(r1)
	  lfs       f1, 0x5C(r1)
	  fmuls     f0, f30, f0
	  stfs      f1, 0x68(r1)
	  fmuls     f0, f29, f0
	  fsubs     f27, f28, f0
	  fmr       f1, f27
	  bl        0x616A0
	  lfs       f0, 0x14(r31)
	  lfs       f2, 0x54(r1)
	  fmuls     f0, f0, f1
	  fmr       f1, f27
	  fadds     f0, f2, f0
	  stfs      f0, 0x6C(r1)
	  bl        0x61818
	  lfs       f0, 0x14(r31)
	  addi      r28, r1, 0x54
	  lfs       f2, 0x58(r1)
	  li        r3, 0xA0
	  fmuls     f0, f0, f1
	  li        r4, 0
	  li        r5, 0x3
	  fadds     f0, f2, f0
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x74(r1)
	  bl        0x566D4
	  lfs       f2, 0x5C(r1)
	  addi      r27, r27, 0x1
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x54(r1)
	  lwz       r0, 0x50(r1)
	  stfs      f0, -0x8000(r30)
	  stfs      f1, -0x8000(r30)
	  stfs      f2, -0x8000(r30)
	  stw       r0, -0x8000(r30)
	  lfs       f2, 0x14(r28)
	  lfs       f1, 0x10(r28)
	  lfs       f0, 0xC(r28)
	  stfs      f0, -0x8000(r30)
	  stfs      f1, -0x8000(r30)
	  stfs      f2, -0x8000(r30)
	  stw       r0, -0x8000(r30)
	  lfs       f2, 0x20(r28)
	  lfs       f1, 0x1C(r28)
	  lfs       f0, 0x18(r28)
	  stfs      f0, -0x8000(r30)
	  stfs      f1, -0x8000(r30)
	  stfs      f2, -0x8000(r30)
	  stw       r0, -0x8000(r30)

	.loc_0x424:
	  lwz       r0, 0x0(r31)
	  cmpw      r27, r0
	  blt+      .loc_0x2F0
	  lmw       r27, 0x8C(r1)
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lfd       f29, 0xB0(r1)
	  lfd       f28, 0xA8(r1)
	  lfd       f27, 0xA0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BA594
 * Size:	00006C
 */
void zen::DrawNaviLifeCircle::drawLifeCircle()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x3120(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  mr        r3, r0
	  lwz       r4, 0x18(r31)
	  bl        -0xA3184
	  lwz       r4, 0x224(r3)
	  mr        r5, r3
	  lfs       f1, 0x58(r5)
	  mr        r3, r31
	  lfs       f0, 0x3C8(r4)
	  fdivs     f1, f1, f0
	  bl        -0x49C
	  b         .loc_0x58

	.loc_0x4C:
	  mr        r3, r31
	  lfs       f1, -0x47E0(r2)
	  bl        -0x4AC

	.loc_0x58:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
