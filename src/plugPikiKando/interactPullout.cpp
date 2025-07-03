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
DEFINE_ERROR(__LINE__) // Never used in the DLL

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
bool InteractPullout::actCommon(Creature*)
{
	return true;
}

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
	piki->mFaceDirection = roundAng(mOwner->mFaceDirection);
	piki->mRotation.set(0.0f, piki->mFaceDirection, 0.0f);
	PRINT("nukarePiki:faceDir = %.1f\n", piki->mFaceDirection);

	piki->mFSM->transit(piki, PIKISTATE_Nukare);
	if (piki->mNavi->mIsFastPluckEnabled) {
		piki->mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Nukare_Fast, piki), PaniMotionInfo(PIKIANIM_Nukare_Fast));
	} else {
		piki->mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Nukareru, piki), PaniMotionInfo(PIKIANIM_Nukareru));
	}

	Vector3f sideComponent = piki->mPosition - mOwner->mPosition;

	f32 backPullDist = 43.838402f;
	f32 perpDist     = 15.0f;

	f32 scale = 1.0f; // i assume this got changed at times during development

	backPullDist *= scale;
	perpDist *= scale;

	f32 angle = mOwner->mFaceDirection;

	Vector3f perpOffset(-perpDist * cosf(angle), 0.0f, perpDist * sinf(angle));

	sideComponent.add(perpOffset);

	f32 strength = 1.0f;
	if (piki->mFormationPriority == 1) {
		strength = C_PIKI_PROP(piki)._13C();
	} else if (piki->mFormationPriority == 2) {
		strength = C_PIKI_PROP(piki)._14C();
	} else {
		strength = C_PIKI_PROP(piki)._12C();
	}

	backPullDist *= strength;
	sideComponent = sideComponent * strength;

	piki->mPluckVelocity = mOwner->mPosition + Vector3f(-backPullDist * sinf(angle), 0.0f, -backPullDist * cosf(angle)) + sideComponent;

	return true;
}
