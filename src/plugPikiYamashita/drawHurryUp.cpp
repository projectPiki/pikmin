#include "zen/DrawHurryUp.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	801C049C
 * Size:	000308
 */
zen::DrawHurryUp::DrawHurryUp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0x280
	  stwu      r1, -0xA8(r1)
	  li        r7, 0x1E0
	  stw       r31, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  stw       r29, 0x9C(r1)
	  stw       r3, 0x8(r1)
	  addi      r3, r1, 0x48
	  lwz       r29, 0x8(r1)
	  addi      r30, r29, 0x4
	  bl        -0xCEAC
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x48
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        -0xFB28
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  lis       r3, 0x802E
	  stb       r0, 0xEC(r30)
	  addi      r4, r3, 0x1590
	  addi      r3, r30, 0
	  stw       r0, 0xF0(r30)
	  li        r5, 0
	  li        r6, 0
	  stw       r0, 0xF4(r30)
	  li        r7, 0x1
	  lfs       f0, -0x4700(r2)
	  stfs      f0, 0x138(r29)
	  stfs      f0, 0x134(r29)
	  stfs      f0, 0x130(r29)
	  stfs      f0, 0x144(r29)
	  stfs      f0, 0x140(r29)
	  stfs      f0, 0x13C(r29)
	  stfs      f0, 0x150(r29)
	  stfs      f0, 0x14C(r29)
	  stfs      f0, 0x148(r29)
	  stw       r0, 0x0(r29)
	  stb       r0, 0x100(r29)
	  bl        -0xD95C
	  li        r3, 0xE4
	  bl        -0x179560
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xF8
	  lfs       f1, -0x46FC(r2)
	  li        r4, 0
	  lfs       f2, -0x46F8(r2)
	  li        r5, 0
	  lfs       f3, -0x46F4(r2)
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        -0x10400

	.loc_0xF8:
	  lwz       r29, 0x8(r1)
	  lis       r4, 0x726F
	  li        r0, 0x1
	  stw       r30, 0xFC(r29)
	  addi      r3, r29, 0x4
	  addi      r4, r4, 0x6F74
	  lfs       f0, -0x4700(r2)
	  li        r5, 0x1
	  stfs      f0, 0x104(r29)
	  lfs       f0, -0x46F8(r2)
	  stfs      f0, 0x108(r29)
	  lfs       f0, -0x46F0(r2)
	  stfs      f0, 0x12C(r29)
	  stw       r0, 0x10C(r29)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x110(r29)
	  addi      r3, r29, 0x4
	  lis       r30, 0x6875
	  lwz       r12, 0x4(r29)
	  addi      r4, r30, 0x7272
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x114(r29)
	  addi      r3, r29, 0x4
	  lis       r31, 0x7375
	  lwz       r12, 0x4(r29)
	  addi      r4, r31, 0x6E64
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x118(r29)
	  addi      r3, r29, 0x4
	  addi      r4, r30, 0x7232
	  lwz       r12, 0x4(r29)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x11C(r29)
	  addi      r3, r29, 0x4
	  addi      r4, r31, 0x6E32
	  lwz       r12, 0x4(r29)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x120(r29)
	  addi      r3, r29, 0x4
	  addi      r4, r31, 0x6E6C
	  lwz       r12, 0x4(r29)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x124(r29)
	  addi      r3, r29, 0x4
	  addi      r4, r31, 0x6E77
	  lwz       r12, 0x4(r29)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x128(r29)
	  lis       r4, 0x4330
	  addi      r3, r29, 0
	  lwz       r5, 0x114(r29)
	  lfd       f2, -0x46E8(r2)
	  lha       r0, 0x18(r5)
	  lha       r5, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x94(r1)
	  xoris     r0, r5, 0x8000
	  stw       r4, 0x90(r1)
	  stw       r0, 0x8C(r1)
	  lfd       f0, 0x90(r1)
	  stw       r4, 0x88(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x88(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x130(r29)
	  stfs      f0, 0x134(r29)
	  lfs       f0, 0x1B20(r13)
	  stfs      f0, 0x138(r29)
	  lwz       r5, 0x118(r29)
	  lha       r0, 0x18(r5)
	  lha       r5, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x84(r1)
	  xoris     r0, r5, 0x8000
	  stw       r4, 0x80(r1)
	  stw       r0, 0x7C(r1)
	  lfd       f0, 0x80(r1)
	  stw       r4, 0x78(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x13C(r29)
	  stfs      f0, 0x140(r29)
	  lfs       f0, 0x1B24(r13)
	  stfs      f0, 0x144(r29)
	  lwz       r5, 0x124(r29)
	  lha       r0, 0x18(r5)
	  lha       r5, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x74(r1)
	  xoris     r0, r5, 0x8000
	  stw       r4, 0x70(r1)
	  stw       r0, 0x6C(r1)
	  lfd       f0, 0x70(r1)
	  stw       r4, 0x68(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x148(r29)
	  stfs      f0, 0x14C(r29)
	  lfs       f0, 0x1B28(r13)
	  stfs      f0, 0x150(r29)
	  bl        .loc_0x308
	  mr        r3, r29
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr

	.loc_0x308:
	*/
}

/*
 * --INFO--
 * Address:	801C07A4
 * Size:	000110
 */
void zen::DrawHurryUp::initPanes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  stw       r30, 0x70(r1)
	  stw       r29, 0x6C(r1)
	  li        r29, 0
	  lwz       r5, 0x110(r3)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lfs       f0, 0x12C(r31)
	  lwz       r3, 0x110(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x11C(r31)
	  stb       r29, 0xF0(r3)
	  lwz       r3, 0x120(r31)
	  stb       r29, 0xF0(r3)
	  lwz       r3, 0x114(r31)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  subi      r4, r4, 0x2BC
	  mtlr      r12
	  blrl
	  lwz       r3, 0x114(r31)
	  li        r30, 0x64
	  stb       r30, 0xF0(r3)
	  lwz       r3, 0x118(r31)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0x2BC
	  mtlr      r12
	  blrl
	  lwz       r3, 0x118(r31)
	  addi      r4, r31, 0x148
	  stb       r30, 0xF0(r3)
	  lwz       r3, 0x124(r31)
	  stb       r29, 0xF0(r3)
	  lwz       r3, 0x124(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x128(r31)
	  stb       r29, 0xF0(r3)
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C08B4
 * Size:	00012C
 */
void zen::DrawHurryUp::start(zen::DrawHurryUp::messageTypeFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  li        r31, 0
	  stw       r30, 0x78(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x74(r1)
	  stb       r0, 0x100(r3)
	  stw       r31, 0x0(r3)
	  lfs       f0, -0x4700(r2)
	  stfs      f0, 0x104(r3)
	  lfs       f0, -0x46E0(r2)
	  stfs      f0, 0x108(r3)
	  lwz       r5, 0x110(r3)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lfs       f0, 0x12C(r30)
	  lwz       r3, 0x110(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x11C(r30)
	  stb       r31, 0xF0(r3)
	  lwz       r3, 0x120(r30)
	  stb       r31, 0xF0(r3)
	  lwz       r3, 0x114(r30)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  subi      r4, r4, 0x2BC
	  mtlr      r12
	  blrl
	  lwz       r3, 0x114(r30)
	  li        r29, 0x64
	  stb       r29, 0xF0(r3)
	  lwz       r3, 0x118(r30)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0x2BC
	  mtlr      r12
	  blrl
	  lwz       r3, 0x118(r30)
	  addi      r4, r30, 0x148
	  stb       r29, 0xF0(r3)
	  lwz       r3, 0x124(r30)
	  stb       r31, 0xF0(r3)
	  lwz       r3, 0x124(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x128(r30)
	  stb       r31, 0xF0(r3)
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C09E0
 * Size:	0001AC
 */
void zen::DrawHurryUp::startStatus()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x104(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x104(r3)
	  lfs       f2, 0x104(r3)
	  lfs       f1, 0x108(r3)
	  lfs       f0, -0x46F8(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  fmr       f31, f1
	  ble-      .loc_0x50
	  fmr       f31, f0

	.loc_0x50:
	  lfs       f2, 0x134(r31)
	  lfs       f0, -0x4700(r2)
	  lfs       f1, -0x46F8(r2)
	  fcmpo     cr0, f2, f0
	  fsubs     f30, f1, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x78
	  lfs       f0, -0x46E0(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x80

	.loc_0x78:
	  lfs       f0, -0x46E0(r2)
	  fsubs     f0, f2, f0

	.loc_0x80:
	  fctiwz    f2, f0
	  lfs       f3, 0x130(r31)
	  lfs       f0, -0x46DC(r2)
	  lwz       r3, 0x114(r31)
	  fsubs     f1, f3, f0
	  fadds     f0, f0, f3
	  lwz       r12, 0x0(r3)
	  stfd      f2, 0x30(r1)
	  fmuls     f1, f1, f31
	  fmuls     f0, f0, f30
	  lwz       r12, 0x14(r12)
	  lwz       r5, 0x34(r1)
	  fadds     f0, f1, f0
	  mtlr      r12
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r4, 0x2C(r1)
	  blrl
	  lfs       f1, 0x140(r31)
	  lfs       f0, -0x4700(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE8
	  lfs       f0, -0x46E0(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xF0

	.loc_0xE8:
	  lfs       f0, -0x46E0(r2)
	  fsubs     f0, f1, f0

	.loc_0xF0:
	  fctiwz    f2, f0
	  lfs       f3, 0x13C(r31)
	  lfs       f0, -0x46DC(r2)
	  lwz       r3, 0x118(r31)
	  fadds     f1, f0, f3
	  fsubs     f0, f3, f0
	  lwz       r12, 0x0(r3)
	  stfd      f2, 0x28(r1)
	  fmuls     f1, f1, f31
	  fmuls     f0, f0, f30
	  lwz       r12, 0x14(r12)
	  lwz       r5, 0x2C(r1)
	  fadds     f0, f1, f0
	  mtlr      r12
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r4, 0x34(r1)
	  blrl
	  lfs       f0, -0x46E0(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x16C
	  fsubs     f0, f31, f0
	  lfs       f1, -0x46D8(r2)
	  lwz       r3, 0x11C(r31)
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x120(r31)
	  stb       r0, 0xF0(r3)

	.loc_0x16C:
	  lfs       f0, -0x46F8(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x190
	  lfs       f0, -0x4700(r2)
	  li        r0, 0x1
	  stfs      f0, 0x104(r31)
	  lfs       f0, -0x46D4(r2)
	  stfs      f0, 0x108(r31)
	  stw       r0, 0x0(r31)

	.loc_0x190:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void zen::DrawHurryUp::enlargeStatus()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void zen::DrawHurryUp::brightShotStatus()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::DrawHurryUp::brightStatus()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C0B8C
 * Size:	0001F8
 */
bool zen::DrawHurryUp::endStatus()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  li        r30, 0
	  stw       r29, 0x44(r1)
	  mr        r29, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x104(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x104(r3)
	  lfs       f2, 0x104(r3)
	  lfs       f1, 0x108(r3)
	  lfs       f0, -0x46F8(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  fmr       f31, f1
	  ble-      .loc_0x58
	  fmr       f31, f0

	.loc_0x58:
	  lfs       f0, -0x46D0(r2)
	  fmuls     f1, f0, f31
	  bl        0x5AF68
	  fneg      f1, f1
	  lfs       f2, -0x46F8(r2)
	  lfs       f3, -0x46E0(r2)
	  lfs       f0, -0x46D0(r2)
	  fadds     f1, f2, f1
	  fmuls     f1, f3, f1
	  fmuls     f1, f0, f1
	  bl        0x5AF48
	  lfs       f0, -0x46F8(r2)
	  lfs       f2, -0x46BC(r2)
	  fadds     f1, f0, f1
	  lwz       r3, 0x124(r29)
	  fsubs     f0, f0, f31
	  fmuls     f1, f2, f1
	  fctiwz    f1, f1
	  stfd      f1, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stfd      f1, 0x38(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r31, 0x3C(r1)
	  lfs       f3, 0x14C(r29)
	  lfs       f1, -0x46B8(r2)
	  fmuls     f2, f3, f0
	  lfs       f0, -0x4700(r2)
	  fadds     f1, f1, f3
	  fmuls     f1, f1, f31
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE8
	  lfs       f0, -0x46E0(r2)
	  fadds     f1, f0, f1
	  b         .loc_0xF0

	.loc_0xE8:
	  lfs       f0, -0x46E0(r2)
	  fsubs     f1, f1, f0

	.loc_0xF0:
	  lfs       f0, 0x148(r29)
	  fctiwz    f1, f1
	  lwz       r3, 0x124(r29)
	  fctiwz    f2, f0
	  lfs       f0, -0x46B4(r2)
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x30(r1)
	  fmuls     f1, f0, f31
	  stfd      f2, 0x38(r1)
	  lwz       r12, 0x1C(r12)
	  lwz       r5, 0x34(r1)
	  mtlr      r12
	  lwz       r4, 0x3C(r1)
	  blrl
	  lwz       r3, 0x128(r29)
	  stb       r31, 0xF0(r3)
	  lwz       r3, 0x11C(r29)
	  stb       r31, 0xF0(r3)
	  lwz       r3, 0x120(r29)
	  stb       r31, 0xF0(r3)
	  lfs       f0, -0x46F8(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x1D4
	  li        r0, 0
	  stb       r0, 0x100(r29)
	  li        r30, 0x1
	  lwz       r4, 0x2F6C(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x1D4
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r3, 0x1DC(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D4
	  addi      r3, r4, 0x54
	  li        r4, 0x13
	  bl        -0x13E84C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1D4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x13
	  addi      r3, r3, 0x54
	  bl        -0x13E864
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1D4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x13
	  addi      r3, r3, 0x54
	  bl        -0x13E5F0
	  lwz       r3, 0x1E8(r31)
	  li        r4, 0
	  li        r5, 0x13
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1D4:
	  mr        r3, r30
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C0D84
 * Size:	0002C0
 */
bool zen::DrawHurryUp::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  li        r30, 0
	  stw       r29, 0x74(r1)
	  mr        r29, r3
	  lbz       r0, 0x100(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x29C
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xFC
	  bge-      .loc_0x50
	  cmpwi     r0, 0
	  beq-      .loc_0x60
	  bge-      .loc_0x6C
	  b         .loc_0x294

	.loc_0x50:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x288
	  bge-      .loc_0x294
	  b         .loc_0x1C0

	.loc_0x60:
	  mr        r3, r29
	  bl        -0x408
	  b         .loc_0x294

	.loc_0x6C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x104(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x104(r29)
	  lfs       f2, 0x104(r29)
	  lfs       f1, 0x108(r29)
	  lfs       f0, -0x46F8(r2)
	  fdivs     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x9C
	  fmr       f31, f0

	.loc_0x9C:
	  lfs       f0, -0x46D0(r2)
	  fmuls     f1, f0, f31
	  bl        0x5AD2C
	  fneg      f0, f1
	  lfs       f2, -0x46F8(r2)
	  lfs       f3, 0x12C(r29)
	  lfs       f1, -0x46E0(r2)
	  fcmpu     cr0, f2, f31
	  fadds     f0, f2, f0
	  lwz       r3, 0x110(r29)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  bne-      .loc_0x294
	  lfs       f0, -0x4700(r2)
	  li        r0, 0x2
	  stfs      f0, 0x104(r29)
	  stfs      f1, 0x108(r29)
	  stw       r0, 0x0(r29)
	  b         .loc_0x294

	.loc_0xFC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x104(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x104(r29)
	  lfs       f2, 0x104(r29)
	  lfs       f1, 0x108(r29)
	  lfs       f0, -0x46F8(r2)
	  fdivs     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x12C
	  fmr       f31, f0

	.loc_0x12C:
	  lfs       f0, -0x46D0(r2)
	  fmuls     f1, f0, f31
	  bl        0x5AC9C
	  fneg      f0, f1
	  lfs       f1, -0x46F8(r2)
	  lfs       f2, -0x46E0(r2)
	  lfs       f3, -0x46CC(r2)
	  fadds     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f1, f3, f0
	  bl        0x5AC7C
	  lfs       f0, -0x46F8(r2)
	  lfs       f2, -0x46C8(r2)
	  fsubs     f0, f0, f1
	  lwz       r3, 0x124(r29)
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x124(r29)
	  lfs       f0, -0x46C4(r2)
	  lwz       r12, 0x0(r3)
	  fmuls     f1, f0, f31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x46F8(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x294
	  lfs       f0, -0x4700(r2)
	  li        r0, 0x3
	  stfs      f0, 0x104(r29)
	  lfs       f0, -0x46C0(r2)
	  stfs      f0, 0x108(r29)
	  stw       r0, 0x0(r29)
	  b         .loc_0x294

	.loc_0x1C0:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x104(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x104(r29)
	  lfs       f2, 0x104(r29)
	  lfs       f1, 0x108(r29)
	  lfs       f0, -0x46F8(r2)
	  fdivs     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1F0
	  fmr       f31, f0

	.loc_0x1F0:
	  lfs       f0, -0x46D0(r2)
	  fmuls     f1, f0, f31
	  bl        0x5ABD8
	  fneg      f0, f1
	  lfs       f1, -0x46F8(r2)
	  lfs       f2, -0x46E0(r2)
	  lfs       f3, -0x46D0(r2)
	  fadds     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f1, f3, f0
	  bl        0x5ABB8
	  lfs       f0, -0x46F8(r2)
	  lwz       r3, 0x124(r29)
	  fsubs     f0, f0, f1
	  lfs       f2, -0x46BC(r2)
	  lwz       r12, 0x0(r3)
	  lfs       f1, -0x4700(r2)
	  fmuls     f0, f2, f0
	  lwz       r12, 0x20(r12)
	  fctiwz    f0, f0
	  mtlr      r12
	  stfd      f0, 0x68(r1)
	  lwz       r31, 0x6C(r1)
	  blrl
	  lwz       r3, 0x124(r29)
	  stb       r31, 0xF0(r3)
	  lwz       r3, 0x128(r29)
	  stb       r31, 0xF0(r3)
	  lfs       f0, -0x46F8(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x294
	  lfs       f0, -0x4700(r2)
	  li        r0, 0x4
	  stfs      f0, 0x104(r29)
	  lfs       f0, -0x46E0(r2)
	  stfs      f0, 0x108(r29)
	  stw       r0, 0x0(r29)
	  b         .loc_0x294

	.loc_0x288:
	  mr        r3, r29
	  bl        -0x484
	  mr        r30, r3

	.loc_0x294:
	  addi      r3, r29, 0x4
	  bl        -0xE4CC

	.loc_0x29C:
	  mr        r3, r30
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C1044
 * Size:	00005C
 */
void zen::DrawHurryUp::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lbz       r0, 0x100(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  lwz       r3, 0xFC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0xFC(r31)
	  addi      r3, r31, 0x4
	  li        r4, 0
	  li        r5, 0
	  bl        -0xE1B4

	.loc_0x48:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
