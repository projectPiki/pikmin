#include "Piki.h"
#include "Route.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("pikidoKill");

/*
 * --INFO--
 * Address:	800CD950
 * Size:	000380
 */
void Piki::doKill()
{
	if (mRouteHandle) {
		routeMgr->getPathFinder('test')->releaseHandle(mRouteHandle);
		mRouteHandle  = 0;
		mDoRouteASync = 0;
	}

	mLookAtTarget.clear();

	if (mIsPanicked) {
		_428->kill();
		mIsPanicked = false;
	}

	mBurnEffect->kill();
	mRippleEffect->kill();
	mSlimeEffect->kill();

	if (pikiUpdateMgr) { }

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  lwz       r30, 0x2D0(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0x4C
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x2D974
	  mr        r4, r30
	  bl        -0x2E258
	  li        r0, 0
	  stw       r0, 0x2D0(r31)
	  stb       r0, 0x2D4(r31)

	.loc_0x4C:
	  li        r30, 0
	  stw       r30, 0x338(r31)
	  lbz       r0, 0x424(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  lwz       r3, 0x428(r31)
	  bl        0x46B60
	  stb       r30, 0x424(r31)

	.loc_0x6C:
	  lwz       r3, 0x42C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x430(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x434(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3040(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xBC
	  addi      r3, r31, 0x40C
	  bl        -0x28534

	.loc_0xBC:
	  lwz       r0, 0x3048(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xD0
	  addi      r3, r31, 0x418
	  bl        -0x28548

	.loc_0xD0:
	  lwz       r0, 0x304C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  addi      r3, r31, 0x174
	  bl        -0x2855C

	.loc_0xE4:
	  mr        r3, r31
	  bl        -0x54E4
	  lwz       r4, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x274
	  cmpwi     r3, 0x8
	  beq-      .loc_0x274
	  lwz       r0, 0x520(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x274
	  lhz       r0, 0x4FC(r31)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x274
	  lbz       r0, 0x584(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x274
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x658B0
	  mr.       r30, r3
	  beq-      .loc_0x274
	  mr        r3, r30
	  bl        0x48610
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x274
	  addi      r3, r31, 0x94
	  bl        -0x7550
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x274
	  mr        r3, r30
	  bl        0x485C8
	  cmpwi     r3, 0x5
	  beq-      .loc_0x274
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  addi      r30, r3, 0x3F8
	  bl        0x14A5A0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6998(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x699C(r2)
	  stw       r0, 0x58(r1)
	  lfs       f1, -0x69A0(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, 0x0(r30)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x274
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0xF
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x274
	  lis       r3, 0x803A
	  lfs       f0, 0x94(r31)
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  li        r4, 0x1
	  stfs      f0, 0x4C(r1)
	  addi      r29, r3, 0x2C
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x54(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x4C(r1)
	  lfs       f2, 0x54(r1)
	  bl        -0x65C64
	  stfs      f1, 0x50(r1)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x4C
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lhz       r4, 0x510(r31)
	  bl        0x1EF10
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x268
	  mr        r4, r30
	  bl        -0x8320

	.loc_0x268:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x42EE0

	.loc_0x274:
	  lbz       r0, 0x584(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x2E0
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x44C(r31)
	  lfs       f2, 0x454(r31)
	  bl        -0x65B78
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x44C
	  li        r4, 0x26
	  li        r6, 0
	  li        r7, 0
	  bl        0xCEF40
	  lwz       r3, 0x3038(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x1
	  li        r5, 0x33
	  bl        -0x297D8
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E58
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)

	.loc_0x2E0:
	  lwz       r3, 0x4F8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F4
	  li        r4, 0
	  bl        -0x88FC

	.loc_0x2F4:
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E88
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x448FC
	  lwz       r3, 0x490(r31)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x500(r31)
	  mr        r4, r31
	  lwz       r5, 0x3068(r13)
	  lwz       r3, 0x60(r5)
	  addi      r0, r3, 0x1
	  stw       r0, 0x60(r5)
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}
