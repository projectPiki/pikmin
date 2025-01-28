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
	mActor->_408 = 0;
	mActor->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
	mActor->mScale.set(0.0f, 0.0f, 0.0f);
	_14 = mActor->mPosition;
	mActor->mOdometer.start(1.0f, 5.0f);
	_20 = false;
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
		_20 = true;
	}
}

/*
 * --INFO--
 * Address:	800B8EB4
 * Size:	0002E8
 */
int ActExit::exec()
{
	if (_20 || !mActor->mRope) {
		mActor->mScale.set(1.0f, 1.0f, 1.0f);
		PRINT("*** EXIT ** NO ROPE\n");
		return ACTOUT_Fail;
	}

	if (!mActor->mOdometer.moving(mActor->mPosition, _14)) {
		mActor->endRope();
		mActor->mScale.set(1.0f, 1.0f, 1.0f);
		return ACTOUT_Fail;
	}

	_14 = mActor->mPosition;
	if (mActor->mRopeRatio > 0.72f) {
		PRINT("piki->ropePos = %f\n", mActor->mRopeRatio);
		mActor->mIsCallable = false;
		f32 scale           = (1.0f - mActor->mRopeRatio) / (1.0f - 0.72f) * 1.0f;
		if (scale < 0.0f) {
			scale = 0.0f;
		}
		mActor->mScale.set(scale, scale, scale);
	} else {
		mActor->mScale.set(1.0f, 1.0f, 1.0f);
	}

	if (mActor->mFloorTri) {
		return ACTOUT_Success;
	}

	if (mActor->mRopeRatio < 0.0f) {
		return ACTOUT_Success;
	}

	f32 val     = 70.0f;
	f32 randVal = 8.0f * randBalanced(0.5f);
	Vector3f ropeDir(mActor->mRope->mRopeDirection);
	Vector3f faceDir(sinf(mActor->mFaceDirection), 0.0f, cosf(mActor->mFaceDirection));
	Vector3f sideDir(faceDir);
	sideDir.CP(ropeDir);
	sideDir.normalise();

	mActor->mVelocity = ropeDir * -val + sideDir * randVal;
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
	if (mActor->isAlive()) {
		mActor->mScale.set(1.0f, 1.0f, 1.0f);
	}

	mActor->mIsCallable = true;
	mActor->endRope();
	f32 angle = mActor->mFaceDirection;
	mActor->mVelocity.set(50.0f * sinf(angle), 200.0f, 50.0f * cosf(angle));
}
