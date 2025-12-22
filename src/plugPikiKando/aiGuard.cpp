#include "DebugLog.h"
#include "PikiAI.h"
#include "PikiMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("aiGuard")

ActGuard::ActGuard(Piki* piki)
    : Action(piki, true)
{
	mTarget.clear();
	mLeftGuard.clear();
	mRightGuard.clear();
	mIsGuardable      = false;
	mFormationSpacing = 30.0f;
}

void ActGuard::init(Creature*)
{
	mTarget.clear();
	mLeftGuard.clear();
	mRightGuard.clear();
	Piki* friendPiki = findFriend();
	if (friendPiki) {
		mTarget.set(friendPiki);
	}

	mTimer       = 6.0f;
	mIsWaiting   = false;
	mIsGuardable = true;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
}

void ActGuard::cleanup()
{
	mTarget.reset();
	if (!mRightGuard.isNull()) {
		static_cast<ActGuard*>(static_cast<Piki*>(mRightGuard.getPtr())->mActiveAction->getCurrAction())->mLeftGuard.reset();
		mRightGuard.reset();
	}

	if (!mLeftGuard.isNull()) {
		static_cast<ActGuard*>(static_cast<Piki*>(mLeftGuard.getPtr())->mActiveAction->getCurrAction())->mRightGuard.reset();
		mLeftGuard.reset();
	}

	mIsGuardable = false;

	// this isn't elaborated on in the DLL either.
	rand();
	STACK_PAD_VAR(4);
}

void ActGuard::dump()
{
	if (mTarget.isNull()) {
		PRINT(" target is null (%x)\n", mTarget.getPtr());
	} else {
		PRINT(" xx target = %x(%.1f,%.1f) timer = %.1f\n", mTarget.getPtr(), mTarget.getPtr()->mSRT.t.x, mTarget.getPtr()->mSRT.t.z,
		      mTimer);
	}

	PRINT(" wait = %s landPos=(%.1f,%.1f)\n", mIsWaiting ? "true" : "false", mLandPosition.x, mLandPosition.z);
	PRINT(" currPos(%.1f,%.1f)\n", mPiki->mSRT.t.x, mPiki->mSRT.t.z);
}

int ActGuard::exec()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mTarget.isNull()) {
		mTimer -= gsys->getFrameTime();
		if (mTimer < 0.0f) {
			return ACTOUT_Fail;
		}

		init(nullptr);
		return ACTOUT_Continue;
	}

	if (mIsWaiting) {
		Creature* sidePiki = mLeftGuard.getPtr();
		if (sidePiki) {
			Vector3f dir     = sidePiki->mSRT.t - mPiki->mSRT.t;
			f32 angle        = atan2f(dir.x, dir.z);
			f32 dist         = dir.length();
			dir              = dir * (1.0f / dist);
			Vector3f offset  = (dist - mFormationSpacing) * dir * gsys->getFrameTime() * 13.0f;
			mPiki->mVelocity = mPiki->mVelocity + offset - mPiki->mVelocity * gsys->getFrameTime() * 0.1f;

			if (angDist(angle, sidePiki->mFaceDirection) > 0.0f) {
				mPiki->mFaceDirection += angDist(roundAng(angle - HALF_PI), mPiki->mFaceDirection) * gsys->getFrameTime() / 0.5f;
			} else {
				mPiki->mFaceDirection += angDist(roundAng(angle + HALF_PI), mPiki->mFaceDirection) * gsys->getFrameTime() / 0.5f;
			}
		}

		sidePiki = mRightGuard.getPtr();
		if (sidePiki) {
			Vector3f dir     = sidePiki->mSRT.t - mPiki->mSRT.t;
			f32 dist         = dir.length();
			dir              = dir * (1.0f / dist);
			Vector3f offset  = (dist - mFormationSpacing) * dir * gsys->getFrameTime() * 13.0f;
			mPiki->mVelocity = mPiki->mVelocity + offset - mPiki->mVelocity * gsys->getFrameTime() * 0.1f;
		}

		return ACTOUT_Continue;
	}

	if (!mLeftGuard.isNull() || !mRightGuard.isNull()) {
		PRINT("############ left is %x right is %x but wait is false\n", mLeftGuard.getPtr(), mRightGuard.getPtr());
	}

	setGoal();

	bool doSet = false;
	if (mFormationSide == Right) {
		doSet = setRight();
	} else {
		doSet = setLeft();
	}

	if (doSet) {
		mIsWaiting        = true;
		mFormationSpacing = 30.0f;
		if (mFormationSide == Right) {
			mFormationSide = Left;
		} else {
			mFormationSide = Right;
		}
		Piki* friendPiki = findFriend(mFormationSide);
		if (friendPiki) {
			mTarget.set(friendPiki);
			if (mFormationSide == Right) {
				setRight();
			} else {
				setLeft();
			}
		}
	} else {
		mTarget.reset();
	}

	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return ACTOUT_Continue;
}

Piki* ActGuard::findFriend()
{
	Iterator iter(pikiMgr);
	Piki* friendPiki = nullptr;
	f32 minDist      = 70.0f;

	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki != mPiki && piki->isVisible() && piki->mMode == PikiMode::GuardMode
		    && static_cast<ActGuard*>(piki->mActiveAction->getCurrAction())->mIsGuardable) {
			f32 dist = qdist2(piki, mPiki);
			if (dist < minDist && (!getLeft(piki) || !getRight(piki))) {
				friendPiki = piki;
				minDist    = dist;
			}
		}
	}

	if (friendPiki) {
		Vector3f dir = mPiki->mSRT.t - friendPiki->mSRT.t;
		_2C          = atan2f(dir.x, dir.z);
	}

	return friendPiki;
}

int ActGuard::checkLoop(Piki* piki)
{
	Piki* currPiki = piki;
	int count      = -1;
	while (getLeft(currPiki) && getLeft(currPiki) != piki) {
		Piki* next = getLeft(currPiki);
		if (next == mPiki) {
			return count;
		}

		currPiki = next;
		count++;
	}

	count = -1;
	while (getRight(currPiki) && getRight(currPiki) != piki) {
		Piki* next = getRight(currPiki);
		if (next == mPiki) {
			return count;
		}

		currPiki = next;
		count++;
	}
	return -1;
}

Piki* ActGuard::findFriend(int side)
{
	Iterator iter(pikiMgr);
	Piki* friendPiki = nullptr;
	f32 minDist      = 90.0f;
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki != mTarget.getPtr() && piki != mPiki && piki->isVisible() && piki->mMode == PikiMode::GuardMode
		    && static_cast<ActGuard*>(piki->mActiveAction->getCurrAction())->mIsGuardable) {
			f32 dist = qdist2(piki, mPiki);
			if (getLeft(piki) && side == Left) {
				continue;
			}

			if (getRight(piki) && side == Right) {
				continue;
			}

			int loopIdx = checkLoop(piki);
			if (loopIdx != -1 && loopIdx < 3) {
				continue;
			}
			if (dist < minDist && (!getLeft(piki) || !getRight(piki))) {
				friendPiki = piki;
				minDist    = dist;
			}
		}
	}

	if (friendPiki) {
		Vector3f dir = mPiki->mSRT.t - friendPiki->mSRT.t;
		_2C          = atan2f(dir.x, dir.z);
	}

	return friendPiki;
}

void ActGuard::setGoal()
{
	Piki* target = static_cast<Piki*>(mTarget.getPtr());
	if (getLeft(target) && !getRight(target)) {
		mFormationSide = Right;
	} else if (!getLeft(target) && getRight(target)) {
		mFormationSide = Left;
	} else if (!getLeft(target) && !getRight(target)) {
		if (gsys->getRand(1.0f) > 0.5f) {
			mFormationSide = Right;
		} else {
			mFormationSide = Left;
		}
	} else {
		mTarget.reset();
		return;
	}

	Vector3f targetPos(target->mSRT.t);
	f32 rad = 2.5f * target->getSize();

	f32 angle = (mFormationSide == Right) ? _2C : PI - _2C;

	targetPos = targetPos + Vector3f(rad * sinf(angle), 0.0f, rad * cosf(angle));
	_20       = targetPos;
}

Piki* ActGuard::getLeft(Piki* piki)
{
	Piki* left = nullptr;
	if (piki->isVisible() && piki->mMode == PikiMode::GuardMode) {
		left = static_cast<Piki*>(static_cast<ActGuard*>(piki->mActiveAction->getCurrAction())->mLeftGuard.getPtr());
	}

	return left;
}

Piki* ActGuard::getRight(Piki* piki)
{
	Piki* right = nullptr;
	if (piki->isVisible() && piki->mMode == PikiMode::GuardMode) {
		right = static_cast<Piki*>(static_cast<ActGuard*>(piki->mActiveAction->getCurrAction())->mRightGuard.getPtr());
	}

	return right;
}

bool ActGuard::setLeft()
{
	Piki* target = static_cast<Piki*>(mTarget.getPtr());
	if (target->isVisible() && target->mMode == PikiMode::GuardMode) {
		if (getLeft(target)) {
			PRINT("CANNOT HAPPEN !!!! left hand duplicates %x->%x\n", mPiki, target);
		}

		static_cast<ActGuard*>(target->mActiveAction->getCurrAction())->mLeftGuard.set(mPiki);
		static_cast<ActGuard*>(target->mActiveAction->getCurrAction())->mLandPosition.set(target->mSRT.t);
		static_cast<ActGuard*>(target->mActiveAction->getCurrAction())->mIsWaiting = true;
		mRightGuard.set(target);
		return true;
	}

	return false;
}

bool ActGuard::setRight()
{
	Piki* target = static_cast<Piki*>(mTarget.getPtr());
	if (target->isVisible() && target->mMode == PikiMode::GuardMode) {
		if (getRight(target)) {
			PRINT("CANNOT HAPPEN !!!! right hand duplicates %x->%x\n", mPiki, target);
		}

		static_cast<ActGuard*>(target->mActiveAction->getCurrAction())->mRightGuard.set(mPiki);
		static_cast<ActGuard*>(target->mActiveAction->getCurrAction())->mLandPosition.set(target->mSRT.t);
		static_cast<ActGuard*>(target->mActiveAction->getCurrAction())->mIsWaiting = true;
		mLeftGuard.set(target);
		return true;
	}

	return false;
}
