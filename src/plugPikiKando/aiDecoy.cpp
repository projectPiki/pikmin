#include "DebugLog.h"
#include "NaviMgr.h"
#include "PikiAI.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 */
ActDecoy::ActDecoy(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @todo: Documentation
 */
Creature* ActDecoy::findTeki()
{
	f32 minDist           = 300.0f;
	Creature* closestTeki = nullptr;
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		f32 dist       = qdist2(teki, mPiki);
		if (teki->isVisible() && teki->isAlive() && dist < minDist) {
			minDist     = dist;
			closestTeki = teki;
		}
	}

	return closestTeki;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001EC
 */
Creature* ActDecoy::update()
{
	Creature* teki = findTeki();
	if (teki) {
		f32 dist = qdist2(teki, mPiki);
		if (dist < 60.0f) {
			mState = 0;
		} else {
			mState = 2;
		}
	} else {
		if (mState != 3) {
			mDecoyTimer = 5.0f;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
		}

		mState = 3;
	}

	return teki;
}

/**
 * @todo: Documentation
 */
void ActDecoy::init(Creature* target)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

/**
 * @todo: Documentation
 */
void ActDecoy::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActDecoy::animationKeyUpdated(immut PaniAnimKeyEvent&)
{
}

/**
 * @todo: Documentation
 */
int ActDecoy::exec()
{
	Creature* teki = update();
	switch (mState) {
	case 3:
	{
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mDecoyTimer -= gsys->getFrameTime();
		if (mDecoyTimer < 0.0f) {
			return ACTOUT_Success;
		}
		break;
	}
	case 2:
	{
		Vector3f dir = mPiki->mSRT.t - teki->mSRT.t;
		f32 dist     = dir.length();
		dir          = dir * (-1.0f / dist);
		if (dist < 80.0f && dist > 60.0f) {
			mPiki->mFaceDirection += angDist(atan2f(dir.x, dir.z), mPiki->mFaceDirection) * gsys->getFrameTime() * 3.0f;
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		} else {
			mPiki->setSpeed(0.5f, dir);
		}
		break;
	}
	case 0:
	{
		Navi* navi       = naviMgr->getNavi();
		Vector3f naviDir = mPiki->mSRT.t - navi->mSRT.t;
		naviDir.normalise();
		Vector3f tekiDir = mPiki->mSRT.t - teki->mSRT.t;
		f32 dist         = tekiDir.length();
		tekiDir          = tekiDir * (1.0f / dist);
		tekiDir          = tekiDir + f32(quickABS(tekiDir.DP(naviDir))) * naviDir * 1.3f;
		tekiDir.normalise();
		mPiki->setSpeed(1.0f, tekiDir);
		if (dist > 60.0f) {
			mState = 2;
		}
		break;
	}
	}

	return ACTOUT_Continue;
}
