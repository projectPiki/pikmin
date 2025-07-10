#include "DebugLog.h"
#include "Navi.h"
#include "PikiAI.h"
#include "teki.h"

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
DEFINE_PRINT("aiShoot")

/*
 * --INFO--
 * Address:	800C216C
 * Size:	000120
 */
ActShoot::ActShoot(Piki* piki)
    : AndAction(piki)
{
	setChildren(CHILD_COUNT, new ActGoto(piki), new ActGoto::Initialiser(220.0f, 100.0f, nullptr), new ActShootCreature(piki), nullptr);
	mTarget.clear();
	mTargetIsPlayer = false;
}

/*
 * --INFO--
 * Address:	800C228C
 * Size:	0000B0
 */
void ActShoot::init(Creature* target)
{
	if (!target) {
		PRINT("commander is 0 karl gotti!!!!!!!!!!1\n");
	}

	Creature* newTarget;
	if (target->mObjType == OBJTYPE_Navi) {
		mNavi           = static_cast<Navi*>(target);
		newTarget       = findTarget();
		mTargetIsPlayer = true;
	} else {
		mNavi             = nullptr;
		mTargetObjectPool = 0;
		mTargetIsPlayer   = false;
		newTarget         = target;
	}

	if (newTarget) {
		mTarget.set(newTarget);
		AndAction::init(newTarget);
	}

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	800C233C
 * Size:	000178
 */
Creature* ActShoot::findTarget()
{
	f32 minDist           = 500.0f;
	Creature* closestTeki = nullptr;
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		f32 dist       = qdist2(teki, mPiki);
		if (teki->isAlive() && teki->isVisible() && dist < minDist) {
			minDist     = dist;
			closestTeki = teki;
		}
	}
	return closestTeki;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000288
 */
Creature* ActShoot::decideTarget()
{
	f32 minDist = 12800.0f;
	u32 unused  = 0;
	Creature* targets[MAX_PIKI_ON_FIELD];
	Iterator iter(mTargetObjectPool);
	int count = 0;
	CI_LOOP(iter)
	{
		if ((*iter)->isAlive()) {
			f32 dist = qdist2(*iter, mPiki);
			if (dist > 220.0f - 10.0f && dist < 220.0f + 10.0f) {
				return *iter;
			}

			targets[count++] = *iter;
		}
	}

	if (count != 0) {
		return targets[int(gsys->getRand(1.0f) * count)];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	800C24B4
 * Size:	0001CC
 */
int ActShoot::exec()
{
	if (mTarget.isNull()) {
		return ACTOUT_Success;
	}

	int res = AndAction::exec();
	if (res != ACTOUT_Continue) {
		if (mTargetIsPlayer) {
			Creature* target = findTarget();
			if (target) {
				init(mNavi);
				return ACTOUT_Continue;
			}

			PRINT("all targets are removed !\n");
			return ACTOUT_Success;
		}

		return ACTOUT_Success;
	}

	return res;
}

/*
 * --INFO--
 * Address:	800C2680
 * Size:	000040
 */
void ActShoot::cleanup()
{
	PRINT("ActShoot cleanup\n");
	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800C26C0
 * Size:	000040
 */
void ActShootCreature::cleanup()
{
	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800C2700
 * Size:	0000AC
 */
void ActShootCreature::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mState = STATE_PrepareShoot;
		break;
	case KEY_Action1:
		mState = STATE_ReadyToShoot;
		break;
	case KEY_Finished:
		mState      = STATE_Chasing;
		mChaseTimer = 1.8f;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
		break;
	}
}

/*
 * --INFO--
 * Address:	800C27AC
 * Size:	00005C
 */
ActShootCreature::ActShootCreature(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800C2808
 * Size:	000088
 */
void ActShootCreature::init(Creature* target)
{
	mTarget.set(target);
	mState = STATE_Start;
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800C2890
 * Size:	0002DC
 */
int ActShootCreature::exec()
{
	if (mState == STATE_Start) {
		mState = STATE_ReadyToShoot;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Attack, this), PaniMotionInfo(PIKIANIM_Attack));
	}

	if (mState == STATE_Chasing) {
		mChaseTimer -= gsys->getFrameTime();
		if (mChaseTimer < 0.0f) {
			mState = STATE_Complete;
		}
	}

	if (!mTarget.getPtr()->isVisible()) {
		return ACTOUT_Success;
	}

	if (mState == STATE_Chasing) {
		Vector3f dirToTarget = mTarget.getPtr()->mPosition - mPiki->mPosition;
		f32 distanceToTarget = dirToTarget.length();

		dirToTarget = (1.0f / distanceToTarget) * dirToTarget;
		if (distanceToTarget < 100.0f) {
			dirToTarget = dirToTarget * -1.0f;
			mPiki->setSpeed(1.0f, dirToTarget);
		} else if (distanceToTarget > 220.0f) {
			mPiki->setSpeed(1.0f, dirToTarget);
		} else {
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		}
	}

	Vector3f sep    = mTarget.getPtr()->mPosition - mPiki->mPosition;
	f32 targetAngle = atan2f(sep.x, sep.z);

	mPiki->mFaceDirection += 0.4f * angDist(targetAngle, mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection);

	if (mState == STATE_Complete) {
		return ACTOUT_Success;
	}

	if (mState == STATE_PrepareShoot) {
		mState = STATE_Shooting;
	}

	return ACTOUT_Continue;
}
