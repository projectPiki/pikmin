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
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800BAF68
 * Size:	00004C
 */
ActGoto::ActGoto(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x8E50
	  lis       r3, 0x802B
	  addi      r0, r3, 0x6BB4
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x1C(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BAFB4
 * Size:	00007C
 */
void ActGoto::Initialiser::initialise(Action*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x18(r4)
	  lwz       r31, 0x4(r3)
	  cmplwi    r31, 0
	  beq-      .loc_0x64
	  lwz       r3, 0x1C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  beq-      .loc_0x50
	  bl        0x29374
	  li        r0, 0
	  stw       r0, 0x1C(r30)

	.loc_0x50:
	  stw       r31, 0x1C(r30)
	  lwz       r3, 0x1C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  bl        0x29348

	.loc_0x64:
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
 * Address:	800BB030
 * Size:	0000D4
 */
void ActGoto::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  bl        0x15D024
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6CC8(r2)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6CD4(r2)
	  stw       r0, 0x28(r1)
	  lfs       f2, -0x6CD8(r2)
	  lfd       f1, 0x28(r1)
	  lfs       f0, -0x6CCC(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6CD0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  lwz       r3, 0x1C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  beq-      .loc_0x7C
	  bl        0x292CC
	  li        r0, 0
	  stw       r0, 0x1C(r30)

	.loc_0x7C:
	  stw       r31, 0x1C(r30)
	  lwz       r3, 0x1C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x90
	  bl        0x292A0

	.loc_0x90:
	  addi      r3, r1, 0x14
	  li        r4, 0
	  bl        0x63E90
	  addi      r31, r3, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0
	  bl        0x63E80
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0xF8F0
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BB104
 * Size:	000040
 */
void ActGoto::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r3, 0x1C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  bl        0x29248
	  li        r0, 0
	  stw       r0, 0x1C(r31)

	.loc_0x2C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BB144
 * Size:	000378
 */
int ActGoto::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E8(r1)
	  stfd      f31, 0x1E0(r1)
	  stfd      f30, 0x1D8(r1)
	  stfd      f29, 0x1D0(r1)
	  stfd      f28, 0x1C8(r1)
	  stfd      f27, 0x1C0(r1)
	  stfd      f26, 0x1B8(r1)
	  stw       r31, 0x1B4(r1)
	  stw       r30, 0x1B0(r1)
	  mr        r30, r3
	  lwz       r31, 0x1C(r3)
	  cmplwi    r31, 0
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x60

	.loc_0x58:
	  li        r3, 0x1
	  b         .loc_0x348

	.loc_0x60:
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  lwz       r4, 0xC(r30)
	  bl        -0x2E344
	  lwz       r3, 0xC(r30)
	  fmr       f29, f1
	  lfs       f0, 0x18(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r3)
	  fcmpo     cr0, f29, f0
	  fsubs     f0, f2, f1
	  fabs      f30, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x108
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  fmr       f28, f1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x14(r30)
	  fadds     f0, f0, f1
	  fadds     f0, f0, f28
	  fcmpo     cr0, f29, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x108
	  lfs       f0, -0x6CC0(r2)
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x100
	  li        r3, 0x1
	  b         .loc_0x348

	.loc_0x100:
	  li        r3, 0x2
	  b         .loc_0x348

	.loc_0x108:
	  lfs       f1, 0x20(r30)
	  lfs       f0, -0x6CBC(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x120
	  li        r3, 0x1
	  b         .loc_0x348

	.loc_0x120:
	  lwz       r3, 0xC(r30)
	  lfsu      f1, 0x94(r3)
	  lfs       f29, 0x94(r31)
	  lfs       f30, 0x98(r31)
	  lfs       f0, 0x4(r3)
	  fsubs     f28, f1, f29
	  lfs       f31, 0x9C(r31)
	  fsubs     f27, f0, f30
	  lfs       f0, 0x8(r3)
	  fmuls     f1, f28, f28
	  fsubs     f26, f0, f31
	  fmuls     f0, f27, f27
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xAD660
	  lfs       f0, -0x6CBC(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x178
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x178:
	  lfs       f3, 0x18(r30)
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x4868(r13)
	  fmuls     f1, f28, f3
	  fmuls     f2, f27, f3
	  stfsu     f0, 0xA4(r3)
	  fmuls     f3, f26, f3
	  fadds     f28, f29, f1
	  lfs       f0, -0x4864(r13)
	  fadds     f30, f30, f2
	  stfs      f0, 0x4(r3)
	  fadds     f29, f31, f3
	  lfs       f0, -0x4860(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r30)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x4(r3)
	  fsubs     f0, f28, f0
	  lfs       f2, 0x8(r3)
	  fsubs     f3, f30, f1
	  stfs      f0, 0x180(r1)
	  fsubs     f1, f29, f2
	  stfs      f3, 0x184(r1)
	  stfs      f1, 0x188(r1)
	  lfs       f3, -0x6CBC(r2)
	  stfs      f3, 0x184(r1)
	  lfs       f1, 0x180(r1)
	  lfs       f0, 0x184(r1)
	  lfs       f2, 0x188(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f4, f2, f0
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x260
	  fsqrte    f1, f4
	  lfd       f3, -0x6CB8(r2)
	  lfd       f2, -0x6CB0(r2)
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
	  stfs      f0, 0xC4(r1)
	  lfs       f4, 0xC4(r1)

	.loc_0x260:
	  lfs       f0, -0x6CBC(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x29C
	  lfs       f1, -0x6CD8(r2)
	  lfs       f0, 0x180(r1)
	  fdivs     f3, f1, f4
	  lfs       f1, 0x184(r1)
	  lfs       f2, 0x188(r1)
	  fmuls     f0, f0, f3
	  fmuls     f4, f1, f3
	  fmuls     f1, f2, f3
	  stfs      f0, 0x180(r1)
	  stfs      f4, 0x184(r1)
	  stfs      f1, 0x188(r1)
	  b         .loc_0x300

	.loc_0x29C:
	  bl        0x15CC90
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6CC8(r2)
	  stw       r0, 0x1AC(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6CD4(r2)
	  stw       r0, 0x1A8(r1)
	  lfs       f2, -0x6CD8(r2)
	  lfd       f1, 0x1A8(r1)
	  lfs       f0, -0x6CA8(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6CCC(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f26, f1, f0
	  fmr       f1, f26
	  bl        0x1608C4
	  fmr       f31, f1
	  fmr       f1, f26
	  bl        0x160724
	  stfs      f1, 0x180(r1)
	  lfs       f0, -0x485C(r13)
	  stfs      f0, 0x184(r1)
	  stfs      f31, 0x188(r1)

	.loc_0x300:
	  lwz       r3, 0xC(r30)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x4(r3)
	  fsubs     f2, f28, f0
	  lfs       f0, 0x8(r3)
	  fsubs     f3, f30, f1
	  fsubs     f4, f29, f0
	  fmuls     f1, f2, f2
	  fmuls     f0, f3, f3
	  fmuls     f2, f4, f4
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xAD834
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0x180
	  lfs       f1, -0x6CD8(r2)
	  bl        0x10954
	  li        r3, 0

	.loc_0x348:
	  lwz       r0, 0x1EC(r1)
	  lfd       f31, 0x1E0(r1)
	  lfd       f30, 0x1D8(r1)
	  lfd       f29, 0x1D0(r1)
	  lfd       f28, 0x1C8(r1)
	  lfd       f27, 0x1C0(r1)
	  lfd       f26, 0x1B8(r1)
	  lwz       r31, 0x1B4(r1)
	  lwz       r30, 0x1B0(r1)
	  addi      r1, r1, 0x1E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BB4BC
 * Size:	000064
 */
ActGoto::~ActGoto()
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
	  beq-      .loc_0x48
	  lis       r3, 0x802B
	  addi      r0, r3, 0x6BB4
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x8918
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x74354

	.loc_0x48:
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
 * Address:	800BB520
 * Size:	000014
 */
void ActGoto::defaultInitialiser()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x6CBC(r2)
	  stfs      f0, 0x18(r3)
	  lfs       f0, -0x6CA4(r2)
	  stfs      f0, 0x14(r3)
	  blr
	*/
}
