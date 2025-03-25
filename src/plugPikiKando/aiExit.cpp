#include "PikiAI.h"
#include "RopeCreature.h"
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
 * Address:	800B8D68
 * Size:	000060
 */
ActExit::ActExit(Piki* piki)
    : Action(piki, true)
{
	setName("Exit");
	mCurrActionIdx = -1;
}

/*
 * --INFO--
 * Address:	800B8DC8
 * Size:	0000C0
 */
void ActExit::init(Creature*)
{
	mPiki->mActionState = 0;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
	mPiki->mScale.set(0.0f, 0.0f, 0.0f);
	mPrevPosition = mPiki->mPosition;
	mPiki->mOdometer.start(1.0f, 5.0f);
	mHasCollided = false;
}

/*
 * --INFO--
 * Address:	800B8E88
 * Size:	00002C
 */
void ActExit::procCollideMsg(Piki*, MsgCollide* msg)
{
	if (msg->mEvent.mCollider->mObjType != OBJTYPE_Goal && !msg->mEvent.mCollider->isPiki()
	    && msg->mEvent.mCollider->mObjType != OBJTYPE_Navi) {
		mHasCollided = true;
	}
}

/*
 * --INFO--
 * Address:	800B8EB4
 * Size:	0002E8
 */
int ActExit::exec()
{
	if (mHasCollided || !mPiki->mRope) {
		mPiki->mScale.set(1.0f, 1.0f, 1.0f);
		PRINT("*** EXIT ** NO ROPE\n");
		return ACTOUT_Fail;
	}

	if (!mPiki->mOdometer.moving(mPiki->mPosition, mPrevPosition)) {
		mPiki->endRope();
		mPiki->mScale.set(1.0f, 1.0f, 1.0f);
		return ACTOUT_Fail;
	}

	mPrevPosition = mPiki->mPosition;
	if (mPiki->mRopePosRatio > 0.72f) {
		PRINT("piki->ropePos = %f\n", mPiki->mRopePosRatio);
		mPiki->mIsCallable = false;
		f32 scale          = (1.0f - mPiki->mRopePosRatio) / (1.0f - 0.72f) * 1.0f;
		if (scale < 0.0f) {
			scale = 0.0f;
		}
		mPiki->mScale.set(scale, scale, scale);
	} else {
		mPiki->mScale.set(1.0f, 1.0f, 1.0f);
	}

	if (mPiki->mFloorTri) {
		return ACTOUT_Success;
	}

	if (mPiki->mRopePosRatio < 0.0f) {
		return ACTOUT_Success;
	}

	f32 baseVelocity = 70.0f;
	f32 sideVelocity = 8.0f * (gsys->getRand(1.0f) - 0.5f);
	Vector3f ropeDir(mPiki->mRope->mRopeDirection);
	Vector3f faceDir(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
	Vector3f sideDir(faceDir);
	sideDir.CP(ropeDir);
	sideDir.normalise();

	mPiki->mVelocity = ropeDir * -baseVelocity + sideDir * sideVelocity;
	return ACTOUT_Continue;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800B919C
 * Size:	0000C0
 */
void ActExit::cleanup()
{
	if (mPiki->isAlive()) {
		mPiki->mScale.set(1.0f, 1.0f, 1.0f);
	}

	mPiki->mIsCallable = true;
	mPiki->endRope();
	f32 angle = mPiki->mFaceDirection;
	mPiki->mVelocity.set(50.0f * sinf(angle), 200.0f, 50.0f * cosf(angle));
}
