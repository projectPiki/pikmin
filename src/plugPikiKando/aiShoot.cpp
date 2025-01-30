#include "PikiAI.h"
#include "Navi.h"
#include "teki.h"
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
 * Address:	800C216C
 * Size:	000120
 */
ActShoot::ActShoot(Piki* piki)
    : AndAction(piki)
{
	setChildren(CHILD_COUNT, new ActGoto(piki), new ActGoto::Initialiser(220.0f, 100.0f, nullptr), new ActShootCreature(piki), nullptr);
	mTarget.clear();
	_18 = 0;
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
		mNavi     = static_cast<Navi*>(target);
		newTarget = findTarget();
		_18       = 1;
	} else {
		mNavi     = nullptr;
		_1C       = 0;
		_18       = 0;
		newTarget = target;
	}

	if (newTarget) {
		mTarget.set(newTarget);
		AndAction::init(newTarget);
	}
	u32 badCompiler;
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
	Creature* targets[100];
	Iterator iter(_1C);
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
		return targets[int(unitRandFloat() * count)];
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
		if (_18) {
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
		mState = STATE_Unk2;
		break;
	case KEY_Action1:
		mState = STATE_Unk1;
		break;
	case KEY_Finished:
		mState      = STATE_Unk4;
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
	mState = STATE_Unk0;
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800C2890
 * Size:	0002DC
 */
int ActShootCreature::exec()
{
	if (mState == STATE_Unk0) {
		mState = STATE_Unk1;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Attack, this), PaniMotionInfo(PIKIANIM_Attack));
	}

	if (mState == STATE_Unk4) {
		mChaseTimer -= gsys->getFrameTime();
		if (mChaseTimer < 0.0f) {
			mState = STATE_Unk5;
		}
	}

	if (!mTarget.getPtr()->isVisible()) {
		return ACTOUT_Success;
	}

	if (mState == STATE_Unk4) {
		Vector3f dir = mTarget.getPtr()->mPosition - mPiki->mPosition;
		f32 dist     = dir.length();

		dir = (1.0f / dist) * dir;
		if (dist < 100.0f) {
			dir = dir * -1.0f;
			mPiki->setSpeed(1.0f, dir);
		} else if (dist > 220.0f) {
			mPiki->setSpeed(1.0f, dir);
		} else {
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		}
	}

	Vector3f sep = mTarget.getPtr()->mPosition - mPiki->mPosition;
	f32 angle    = atan2f(sep.x, sep.z);
	mPiki->mFaceDirection += 0.4f * angDist(angle, mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection);
	if (mState == STATE_Unk5) {
		return ACTOUT_Success;
	}
	if (mState == STATE_Unk2) {
		mState = STATE_Unk3;
	}
	return ACTOUT_Continue;
}
