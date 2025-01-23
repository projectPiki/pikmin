#include "PikiAI.h"
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
 * Address:	800C12E8
 * Size:	000098
 */
ActRescue::ActRescue(Piki* piki)
    : Action(piki, false)
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
	  addi      r0, r31, 0x34
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x34(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  li        r5, 0x1
	  bl        0x2AAC
	  lis       r3, 0x802B
	  addi      r3, r3, 0x78D4
	  stw       r3, 0x0(r31)
	  addi      r6, r3, 0x68
	  addi      r4, r31, 0x34
	  lwz       r5, 0x14(r31)
	  subi      r0, r13, 0x4570
	  addi      r3, r31, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r31)
	  sub       r4, r4, r5
	  stw       r4, 0x4(r5)
	  lfs       f0, -0x6B68(r2)
	  stfs      f0, 0x2C(r31)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1380
 * Size:	000044
 */
void ActRescue::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x20
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C

	.loc_0x20:
	  li        r0, 0
	  stw       r0, 0x1C(r3)
	  b         .loc_0x30

	.loc_0x2C:
	  stw       r4, 0x1C(r3)

	.loc_0x30:
	  bl        0x1CC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C13C4
 * Size:	00014C
 */
int ActRescue::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x1C(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x34
	  lwz       r4, 0xC(r31)
	  li        r0, 0x7
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x138

	.loc_0x34:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x60
	  lwz       r4, 0xC(r31)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x138

	.loc_0x60:
	  lwz       r3, 0x1C(r31)
	  bl        0x712C
	  cmpwi     r3, 0x18
	  beq-      .loc_0x90
	  cmpwi     r3, 0xD
	  beq-      .loc_0x90
	  cmpwi     r3, 0xE
	  beq-      .loc_0x90
	  lhz       r3, 0x20(r31)
	  addi      r0, r3, 0x1
	  sth       r0, 0x20(r31)
	  b         .loc_0x98

	.loc_0x90:
	  li        r0, 0
	  sth       r0, 0x20(r31)

	.loc_0x98:
	  lhz       r0, 0x18(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xF0
	  bge-      .loc_0xB8
	  cmpwi     r0, 0
	  beq-      .loc_0xC4
	  bge-      .loc_0x128
	  b         .loc_0x134

	.loc_0xB8:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x134
	  b         .loc_0x11C

	.loc_0xC4:
	  lhz       r0, 0x20(r31)
	  cmplwi    r0, 0x14
	  ble-      .loc_0xE4
	  lwz       r4, 0xC(r31)
	  li        r0, 0x6
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0x138

	.loc_0xE4:
	  mr        r3, r31
	  bl        0x134
	  b         .loc_0x138

	.loc_0xF0:
	  lhz       r0, 0x20(r31)
	  cmplwi    r0, 0x14
	  ble-      .loc_0x110
	  lwz       r4, 0xC(r31)
	  li        r0, 0x6
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0x138

	.loc_0x110:
	  mr        r3, r31
	  bl        0x474
	  b         .loc_0x138

	.loc_0x11C:
	  mr        r3, r31
	  bl        0x5F4
	  b         .loc_0x138

	.loc_0x128:
	  mr        r3, r31
	  bl        0x260
	  b         .loc_0x138

	.loc_0x134:
	  li        r3, 0

	.loc_0x138:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1510
 * Size:	00006C
 */
void ActRescue::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1C
	  bgelr-
	  cmpwi     r0, 0
	  bge-      .loc_0x48
	  blr

	.loc_0x1C:
	  lhz       r4, 0x18(r3)
	  cmplwi    r4, 0x1
	  beq-      .loc_0x3C
	  lbz       r0, 0x32(r3)
	  cmplwi    r0, 0
	  bnelr-
	  cmplwi    r4, 0x3
	  bnelr-

	.loc_0x3C:
	  li        r0, 0x1
	  stb       r0, 0x30(r3)
	  blr

	.loc_0x48:
	  lbz       r0, 0x32(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lhz       r0, 0x18(r3)
	  cmplwi    r0, 0x3
	  bnelr-
	  li        r0, 0x1
	  stb       r0, 0x31(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C157C
 * Size:	000064
 */
void ActRescue::initApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  sth       r0, 0x18(r3)
	  addi      r3, r1, 0xC
	  bl        0x5D9B4
	  addi      r31, r3, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x5D9A4
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x9414
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C15E0
 * Size:	0000E4
 */
int ActRescue::exeApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  lwz       r4, 0xC(r3)
	  lwz       r3, 0x1C(r3)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x38(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  lfs       f2, 0x40(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB3A0C
	  lfs       f0, -0x6B68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xA0
	  lfs       f0, 0x38(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x40(r1)

	.loc_0xA0:
	  lfs       f0, -0x6B64(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xBC
	  mr        r3, r31
	  bl        .loc_0xE4
	  li        r3, 0
	  b         .loc_0xD0

	.loc_0xBC:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x38
	  lfs       f1, -0x6B60(r2)
	  bl        0xA730
	  li        r3, 0

	.loc_0xD0:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0xE4:
	*/
}

/*
 * --INFO--
 * Address:	800C16C4
 * Size:	00008C
 */
void ActRescue::initRescue()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r3
	  sth       r0, 0x18(r3)
	  mr        r30, r29
	  beq-      .loc_0x30
	  lwz       r30, 0x14(r29)

	.loc_0x30:
	  addi      r3, r1, 0xC
	  li        r4, 0x24
	  bl        0x5D85C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x24
	  bl        0x5D87C
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x92B8
	  lwz       r3, 0xC(r29)
	  bl        0x94E4
	  li        r0, 0
	  stb       r0, 0x30(r29)
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
 * Address:	800C1750
 * Size:	000078
 */
int ActRescue::exeRescue()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lfs       f0, -0x4568(r13)
	  lwz       r3, 0xC(r3)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4564(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4560(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x30(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  lwz       r4, 0x1C(r31)
	  li        r5, 0xD
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        .loc_0x78

	.loc_0x60:
	  lwz       r0, 0x1C(r1)
	  li        r3, 0
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x78:
	*/
}

/*
 * --INFO--
 * Address:	800C17C8
 * Size:	000184
 */
void ActRescue::initGo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  stw       r30, 0xC8(r1)
	  addi      r30, r3, 0
	  sth       r0, 0x18(r3)
	  lis       r3, 0x7465
	  addi      r4, r3, 0x7374
	  lwz       r5, 0xC(r30)
	  lwz       r3, 0x302C(r13)
	  addi      r5, r5, 0x94
	  bl        -0x20724
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x24(r30)
	  stw       r0, 0x28(r30)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x2C(r30)
	  lwz       r3, 0xC(r30)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x24(r30)
	  lfs       f0, 0x28(r30)
	  lfs       f2, 0x4(r3)
	  fsubs     f31, f3, f1
	  lfs       f1, 0x8(r3)
	  fsubs     f30, f2, f0
	  lfs       f0, 0x2C(r30)
	  fsubs     f29, f1, f0
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB3C28
	  lfs       f0, -0x6B68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xBC
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0xBC:
	  lfs       f0, 0xC(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x150
	  fmuls     f2, f31, f0
	  lfs       f3, -0x455C(r13)
	  fmuls     f1, f30, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0x70(r1)
	  fmuls     f1, f1, f3
	  lfs       f2, 0x70(r1)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  stfs      f2, 0x64(r1)
	  lfs       f2, 0x64(r1)
	  stfs      f2, 0x90(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x24(r30)
	  lfs       f0, 0x90(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f1, 0x28(r30)
	  lfs       f0, 0x94(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x2C(r30)
	  lfs       f0, 0x98(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lwz       r3, 0x9C(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r3, 0x24(r30)
	  stw       r0, 0x28(r30)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0x2C(r30)

	.loc_0x150:
	  lfs       f1, 0x28(r30)
	  lfs       f0, -0x6B48(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r30)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C194C
 * Size:	00016C
 */
int ActRescue::exeGo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r3
	  lwz       r3, 0xC(r3)
	  lfs       f1, 0xA0(r3)
	  bl        0x15A1E8
	  lwz       r3, 0xC(r31)
	  fmr       f31, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x15A36C
	  lfs       f2, -0x6B44(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f1, f1, f2
	  lfsu      f0, 0x94(r3)
	  lfs       f3, -0x4558(r13)
	  fmuls     f4, f31, f2
	  fadds     f0, f0, f1
	  fmuls     f3, f3, f2
	  lfs       f1, -0x6B40(r2)
	  stfs      f0, 0x38(r1)
	  fadds     f3, f3, f1
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f0, f4
	  stfs      f0, 0x58(r1)
	  lwz       r4, 0x1C(r31)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0x9C(r4)
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x24(r31)
	  lfs       f3, 0x28(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x2C(r31)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x60(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x64(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  lfs       f2, 0x68(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB3DFC
	  lfs       f0, -0x6B68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x124
	  lfs       f0, 0x60(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x68(r1)

	.loc_0x124:
	  lfs       f0, -0x6B3C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x140
	  mr        r3, r31
	  bl        .loc_0x16C
	  li        r3, 0
	  b         .loc_0x154

	.loc_0x140:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x60
	  lfs       f1, -0x6B38(r2)
	  bl        0xA340
	  li        r3, 0

	.loc_0x154:
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr

	.loc_0x16C:
	*/
}

/*
 * --INFO--
 * Address:	800C1AB8
 * Size:	000020
 */
void ActRescue::initThrow()
{
	/*
	.loc_0x0:
	  li        r0, 0x3
	  sth       r0, 0x18(r3)
	  li        r4, 0
	  li        r0, 0x1
	  stb       r4, 0x30(r3)
	  stb       r4, 0x31(r3)
	  stb       r0, 0x32(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1AD8
 * Size:	0002B4
 */
int ActRescue::exeThrow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stw       r31, 0xC4(r1)
	  mr        r31, r3
	  stw       r30, 0xC0(r1)
	  stw       r29, 0xBC(r1)
	  lwz       r3, 0x1C(r3)
	  bl        0x6A58
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4554(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4550(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x454C(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x32(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x104
	  lwz       r3, 0xC(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f3, 0x24(r31)
	  lfs       f2, 0x2C(r31)
	  lfs       f0, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x159EB4
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x8959C
	  fmr       f31, f1
	  lfs       f0, -0x6B34(r2)
	  fabs      f1, f31
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xD8
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x32(r31)
	  mr        r29, r31
	  beq-      .loc_0xA8
	  lwz       r29, 0x14(r31)

	.loc_0xA8:
	  addi      r3, r1, 0x5C
	  li        r4, 0x1B
	  bl        0x5D3D0
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x64
	  li        r4, 0x1B
	  bl        0x5D3F0
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x8E2C

	.loc_0xD8:
	  lwz       r4, 0x2DEC(r13)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x28C(r4)
	  lfs       f1, -0x6B30(r2)
	  fmuls     f0, f31, f0
	  lfs       f2, 0xA0(r3)
	  fmuls     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x89648
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)

	.loc_0x104:
	  lbz       r0, 0x30(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x270
	  lwz       r3, 0x1C(r31)
	  bl        0x6968
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x1C(r31)
	  addi      r4, r4, 0x94
	  lfs       f0, -0x6B68(r2)
	  addi      r3, r3, 0x94
	  lfs       f3, 0x4(r4)
	  lfs       f4, 0x4(r3)
	  lfs       f2, 0x0(r3)
	  lfs       f1, 0x0(r4)
	  fsubs     f4, f4, f3
	  lfs       f3, 0x8(r3)
	  fsubs     f5, f2, f1
	  lfs       f2, 0x8(r4)
	  fmuls     f1, f4, f4
	  fsubs     f3, f3, f2
	  fmuls     f2, f5, f5
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1C4
	  fsqrte    f1, f4
	  lfd       f3, -0x6B58(r2)
	  lfd       f2, -0x6B50(r2)
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
	  stfs      f0, 0x3C(r1)
	  lfs       f4, 0x3C(r1)

	.loc_0x1C4:
	  lfs       f0, -0x6B2C(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x268
	  lfs       f1, -0x4548(r13)
	  addi      r3, r1, 0x78
	  lfs       f0, -0x6B68(r2)
	  addi      r5, r31, 0x24
	  stfs      f1, 0x84(r1)
	  lfs       f1, -0x4544(r13)
	  addi      r6, r1, 0x84
	  stfs      f0, 0x80(r1)
	  lfs       f2, -0x4540(r13)
	  stfs      f1, 0x88(r1)
	  lfs       f1, -0x6B3C(r2)
	  stfs      f0, 0x7C(r1)
	  stfs      f2, 0x8C(r1)
	  stfs      f0, 0x78(r1)
	  lwz       r4, 0xC(r31)
	  addi      r4, r4, 0x94
	  bl        0x50FFC
	  lwz       r4, 0x1C(r31)
	  li        r5, 0xE
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x1C(r31)
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stw       r3, 0x70(r4)
	  stw       r0, 0x74(r4)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0x78(r4)
	  lwz       r4, 0x1C(r31)
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0xAC(r4)

	.loc_0x268:
	  li        r0, 0
	  stb       r0, 0x30(r31)

	.loc_0x270:
	  lbz       r0, 0x31(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x290
	  lwz       r4, 0xC(r31)
	  li        r0, 0x6
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0x294

	.loc_0x290:
	  li        r3, 0

	.loc_0x294:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  lwz       r29, 0xBC(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1D8C
 * Size:	000004
 */
void ActRescue::cleanup()
{
}

/*
 * --INFO--
 * Address:	800C1D90
 * Size:	000080
 */
ActRescue::~ActRescue()
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
	  addi      r3, r3, 0x78D4
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x34
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x2028
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x7AC44

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
