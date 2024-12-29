#include "Interactions.h"
#include "Piki.h"
#include "PikiMgr.h"
#include "Navi.h"
#include "PikiState.h"
#include "stl/math.h"
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
DEFINE_PRINT("interactPullout");

/*
 * --INFO--
 * Address:	8007CB38
 * Size:	000008
 */
bool InteractPullout::actCommon(Creature*) { return true; }

/*
 * --INFO--
 * Address:	8007CB40
 * Size:	0002BC
 */
bool InteractPullout::actPiki(Piki* piki)
{
	if (piki->getState() == PIKISTATE_Nukare) {
		PRINT(" ---- %x is being pulling out\n", piki);
		return false;
	}

	PRINT(" ##### %x pulls out piki %x\n", mOwner, piki);
	piki->mDirection = roundAng(mOwner->mDirection);
	piki->mRotation.set(0.0f, piki->mDirection, 0.0f);
	PRINT("nukarePiki:faceDir = %.1f\n", piki->mDirection);

	piki->mFSM->transit(piki, PIKISTATE_Nukare);
	if (piki->mNavi->_7E5) {
		piki->mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Nukare_Fast, piki), PaniMotionInfo(PIKIANIM_Nukare_Fast));
	} else {
		piki->mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Nukareru, piki), PaniMotionInfo(PIKIANIM_Nukareru));
	}

	Vector3f diff = piki->mPosition - mOwner->mPosition;

	f32 scale    = 1.0f;
	f32 xyzAngle = 43.838402f * scale;
	f32 angle    = mOwner->mDirection;
	Vector3f offset(cosf(angle) * -15.0f * scale, 0.0f, sinf(angle) * 15.0f * scale);

	diff.add(offset);

	f32 strength = 1.0f;
	if (piki->_4B8 == 1) {
		// strength = piki->getPikiProp()->mPikiParms
	} else if (piki->_4B8 == 2) {
		// strength = ...
	} else {
		// strength = ...
	}

	diff = diff * strength;

	piki->_4AC = diff;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stfd      f31, 0x158(r1)
	  stfd      f30, 0x150(r1)
	  stfd      f29, 0x148(r1)
	  stfd      f28, 0x140(r1)
	  stfd      f27, 0x138(r1)
	  stfd      f26, 0x130(r1)
	  stfd      f25, 0x128(r1)
	  stw       r31, 0x124(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x120(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  stw       r29, 0x11C(r1)
	  stw       r28, 0x118(r1)
	  bl        0x4B9D0
	  cmpwi     r3, 0x3
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x280

	.loc_0x58:
	  lwz       r3, 0x4(r30)
	  lfs       f1, 0xA0(r3)
	  bl        -0x44618
	  stfs      f1, 0xA0(r31)
	  mr        r4, r31
	  li        r5, 0x3
	  lfs       f0, -0x6310(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, -0x630C(r13)
	  stfs      f0, 0x90(r31)
	  lwz       r3, 0x490(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x504(r31)
	  lbz       r0, 0x7E5(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0xBC
	  addi      r28, r28, 0x2B8

	.loc_0xBC:
	  addi      r3, r1, 0xE8
	  li        r4, 0x53
	  bl        0xA2354
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xF0
	  li        r4, 0x53
	  bl        0xA2374
	  addi      r4, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r31, 0x354
	  bl        0xA2E40
	  b         .loc_0x130

	.loc_0xF0:
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x100
	  addi      r28, r28, 0x2B8

	.loc_0x100:
	  addi      r3, r1, 0xD8
	  li        r4, 0x6
	  bl        0xA2310
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xE0
	  li        r4, 0x6
	  bl        0xA2330
	  addi      r4, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r31, 0x354
	  bl        0xA2DFC

	.loc_0x130:
	  lwz       r5, 0x4(r30)
	  lfs       f3, 0x94(r31)
	  lfs       f2, 0x94(r5)
	  lfs       f4, 0x98(r31)
	  fsubs     f29, f3, f2
	  lfs       f0, 0x98(r5)
	  lfs       f31, 0xA0(r5)
	  fsubs     f28, f4, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x9C(r5)
	  fmr       f1, f31
	  lfs       f26, -0x76A0(r2)
	  lfs       f0, -0x7698(r2)
	  fsubs     f27, f3, f2
	  lfs       f25, -0x769C(r2)
	  fmuls     f26, f26, f0
	  fmuls     f25, f25, f0
	  bl        0x19F034
	  fmuls     f30, f25, f1
	  fmr       f1, f31
	  bl        0x19EE94
	  fneg      f2, f25
	  lfs       f0, -0x6308(r13)
	  lwz       r0, 0x4B8(r31)
	  fadds     f27, f27, f30
	  fadds     f28, f28, f0
	  fmuls     f0, f2, f1
	  cmpwi     r0, 0x1
	  fadds     f29, f29, f0
	  bne-      .loc_0x1B4
	  lwz       r3, 0x224(r31)
	  lfs       f25, 0x148(r3)
	  b         .loc_0x1D0

	.loc_0x1B4:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x1C8
	  lwz       r3, 0x224(r31)
	  lfs       f25, 0x158(r3)
	  b         .loc_0x1D0

	.loc_0x1C8:
	  lwz       r3, 0x224(r31)
	  lfs       f25, 0x138(r3)

	.loc_0x1D0:
	  fmuls     f26, f26, f25
	  fmr       f1, f31
	  bl        0x19EE3C
	  fneg      f26, f26
	  fmuls     f30, f26, f1
	  fmr       f1, f31
	  bl        0x19EFC0
	  fmuls     f0, f26, f1
	  lfs       f5, -0x6304(r13)
	  fmuls     f2, f29, f25
	  li        r3, 0x1
	  fmuls     f1, f28, f25
	  stfs      f0, 0xA4(r1)
	  fmuls     f0, f27, f25
	  lwz       r4, 0x4(r30)
	  lfsu      f4, 0x94(r4)
	  lfs       f3, 0xA4(r1)
	  lfs       f6, 0x4(r4)
	  fadds     f3, f4, f3
	  lfs       f7, 0x8(r4)
	  fadds     f5, f6, f5
	  fadds     f4, f7, f30
	  stfs      f3, 0x84(r1)
	  lfs       f3, 0x84(r1)
	  stfs      f3, 0xB4(r1)
	  stfs      f5, 0xB8(r1)
	  stfs      f4, 0xBC(r1)
	  lfs       f3, 0xB4(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x78(r1)
	  lfs       f2, 0x78(r1)
	  stfs      f2, 0xC0(r1)
	  lfs       f2, 0xB8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xC4(r1)
	  lfs       f1, 0xBC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC8(r1)
	  lwz       r4, 0xC0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r4, 0x4AC(r31)
	  stw       r0, 0x4B0(r31)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0x4B4(r31)

	.loc_0x280:
	  lwz       r0, 0x164(r1)
	  lfd       f31, 0x158(r1)
	  lfd       f30, 0x150(r1)
	  lfd       f29, 0x148(r1)
	  lfd       f28, 0x140(r1)
	  lfd       f27, 0x138(r1)
	  lfd       f26, 0x130(r1)
	  lfd       f25, 0x128(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  lwz       r29, 0x11C(r1)
	  lwz       r28, 0x118(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
}
