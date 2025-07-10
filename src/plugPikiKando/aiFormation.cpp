#include "DebugLog.h"
#include "FormationMgr.h"
#include "Navi.h"
#include "PikiAI.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(8)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("aiFormation")

/*
 * --INFO--
 * Address:	800B98D8
 * Size:	00032C
 */
void ActFormation::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		break;

	case KEY_Finished:
		if (mIsIdling || mHasStartedIdleAnim) {
			if (mHasStartedIdleAnim) {
				mIdleTimer          = (15.0f * gsys->getRand(1.0f)) + 15.0f;
				mHasStartedIdleAnim = false;
			}
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, this), PaniMotionInfo(PIKIANIM_Wait));
			break;
		}

		if (mIsTripping == FALSE) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Korobu, this), PaniMotionInfo(PIKIANIM_Korobu));
			Vector3f dir(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
			f32 speed              = mPiki->mVelocity.length();
			mPiki->mVelocity       = speed * dir;
			mPiki->mTargetVelocity = speed * dir;
			mIdleTimer             = gsys->getRand(1.0f) + 0.8f;
			mIsTripping            = TRUE;
			break;
		}

		if (mIsTripping == TRUE) {
			mIsOnFloorTripped = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
			break;
		}

		if (mHasStartedRunAnim) {
			mHasStartedRunAnim = false;
			if (mDistanceToTarget > 5.0f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
			}
		}

		break;
	}
}

/*
 * --INFO--
 * Address:	800B9C04
 * Size:	00005C
 */
ActFormation::ActFormation(Piki* piki)
    : Action(piki, true)
{
	mFormMgr = nullptr;
}

/*
 * --INFO--
 * Address:	800B9C60
 * Size:	000148
 */
void ActFormation::getFormPoint()
{
	mPiki->mFormPoint = mFormMgr->getFormPoint(mPiki);
	PRINT("piki %x got formPt %x owner is %x\n", mPiki, mPiki->mFormPoint, mPiki->mFormPoint->getOwner());

	Iterator iter(mFormMgr);
	CI_LOOP(iter)
	{
		Creature* member = *iter;
		if (member->mFormPoint == mPiki->mFormPoint && mPiki != member) {
			PRINT("########################################\n");
			PRINT(" creature %x and piki %x share same formPoint %x\n", member, mPiki, member->mFormPoint);
			PRINT(" owner is %x\n", member->mFormPoint->getOwner());
			while (true) {
				// bad code gets locked in the INFINITE WHILE LOOP
				;
			}
		}
	}
	mUseLastFormationPosition = false;
}

/*
 * --INFO--
 * Address:	800B9DA8
 * Size:	0000F4
 */
void ActFormation::init(Creature* target)
{
	if (mPiki->isKinoko()) {
		ERROR("formation kinoko!");
	}

	mInFormation = true;

	if (target->mObjType != OBJTYPE_Navi) {
		PRINT("target is not navi (%d)\n", target->mObjType);
	}

	Navi* navi                = static_cast<Navi*>(target);
	mFormMgr                  = navi->mFormMgr;
	mUseLastFormationPosition = true;
	mIdleTimer                = (2.0f * gsys->getRand(1.0f)) + 4.0f;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
	mPiki->unsetPastel();
	mIsIdling           = false;
	mHasStartedIdleAnim = false;
	mIsOnFloorTripped   = false;
	mIsTripping         = FALSE;
}

/*
 * --INFO--
 * Address:	800B9E9C
 * Size:	00004C
 */
void ActFormation::cleanup()
{
	if (mFormMgr) {
		mFormMgr->exit(mPiki);
		mPiki->mFormPoint = nullptr;
		mFormMgr          = nullptr;
	}
}

/*
 * --INFO--
 * Address:	800B9EE8
 * Size:	0006A4
 */
int ActFormation::exec()
{
	if (mIsOnFloorTripped) {
		mIdleTimer -= gsys->getFrameTime();
		if (mIdleTimer < 0.0f) {
			mPiki->mPikiAnimMgr.finishMotion(this);
		}

		return ACTOUT_Continue;
	}

	Vector3f pos;
	if (mUseLastFormationPosition) {
		pos = mFormMgr->getLastCentre();
	} else {
		pos = mPiki->mFormPoint->getPos();
	}

	Vector3f directionToTarget = pos - mPiki->mPosition;
	f32 distanceToTarget       = directionToTarget.length();
	mDistanceToTarget          = distanceToTarget;
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (mUseLastFormationPosition && distanceToTarget < 100.0f) {
		getFormPoint();
	} else if (!mUseLastFormationPosition && distanceToTarget < 6.0f) {
		mInFormation = false;
		mPiki->mFaceDirection += 2.5f * (angDist(mPiki->mNavi->mFaceDirection, mPiki->mFaceDirection) * gsys->getFrameTime());

		if (!mIsIdling) {
			mPiki->mPikiAnimMgr.finishMotion(this);
			mIsIdling           = true;
			mIdleTimer          = (15.0f * gsys->getRand(1.0f)) + 15.0f;
			mHasStartedIdleAnim = false;
		} else {
			mIdleTimer -= gsys->getFrameTime();
			if (mIdleTimer < 0.0f && !mHasStartedIdleAnim) {
				// this is set up for far more flexibility than it ended up having wtf
				int baseIdx[1]    = { PIKIANIM_Wait };
				f32 v             = 1.0f;
				int randOffsetIdx = int(v * gsys->getRand(1.0f));
				if (randOffsetIdx >= 1) {
					randOffsetIdx = 0;
				}
				mPiki->startMotion(PaniMotionInfo(baseIdx[randOffsetIdx], this), PaniMotionInfo(baseIdx[randOffsetIdx]));
				mHasStartedIdleAnim = true;
			}
		}

		return ACTOUT_Continue;
	}

	if (!mIsIdling && !mIsOnFloorTripped && gsys->getRand(1.0f) > 0.99f && gsys->getRand(1.0f) > 0.99f
	    && mPiki->mVelocity.length() > mPiki->getSpeed(0.5f)) {
		mPiki->mPikiAnimMgr.finishMotion(this);
		mIsTripping       = FALSE;
		mIsOnFloorTripped = true;
		return ACTOUT_Continue;
	}

	if (mIsIdling) {
		mIsIdling          = false;
		mHasStartedRunAnim = false;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
	}

	Vector3f zeroVector(0.0f, 0.0f, 0.0f);
	Vector3f normalisedDirection = pos - mPiki->mPosition;
	normalisedDirection.normalise();

	Vector3f perpDirection(-normalisedDirection.z, 0.0f, normalisedDirection.x);
	bool shouldApplyDrag = false;

	Vector3f flatDirection = pos - mPiki->mPosition;
	flatDirection.y        = 0.0f;
	f32 flatDistance       = flatDirection.length();
	if (flatDistance > 0.0f) {
		flatDirection = (1.0f / flatDistance) * flatDirection;
	} else {
		f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
		flatDirection.set(cosf(randAngle), 0.0f, sinf(randAngle));
	}

	f32 speedMultiplier = 0.0f;
	if (flatDistance > 30.0f) {
		speedMultiplier = (flatDistance - 30.0f) / 10.0f;
		if (speedMultiplier > 1.0f) {
			speedMultiplier = 1.0f;
		}
	}

	mPiki->setSpeed(speedMultiplier, flatDirection);
	f32 dragFactor = 1.0f;
	if (shouldApplyDrag) {
		mPiki->mTargetVelocity = (1.0f - dragFactor) * mPiki->mTargetVelocity + dragFactor * zeroVector;
	}

	return ACTOUT_Continue;
}
