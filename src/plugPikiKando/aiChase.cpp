#include "DebugLog.h"
#include "PikiAI.h"

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
DEFINE_PRINT("aiRandomBoid") // ... no you're not

ActChase::ActChase(Piki* piki)
    : Action(piki, true)
{
	mTarget.reset();
}

void ActChase::Initialiser::initialise(Action*)
{
}

void ActChase::init(Creature* target)
{
	mChaseTimer = 2.0f * gsys->getRand(1.0f) + 4.0f;
	mTarget.set(target);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

void ActChase::cleanup()
{
	Creature* target = mTarget.getPtr();
	mTarget.reset();
}

int ActChase::exec()
{
	STACK_PAD_VAR(2);
	Creature* target = mTarget.getPtr();
	if (!target->isVisible()) {
		return ACTOUT_Fail;
	}

	mChaseTimer -= gsys->getFrameTime();

	if (!mPiki->_500.isNull() && mPiki->_500.getPtr() == mTarget.getPtr()) {
		return ACTOUT_Success;
	}

	if (mChaseTimer < 0.0f) {
		return ACTOUT_Fail;
	}

	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	Vector3f chaseDir = target->mSRT.t - mPiki->mSRT.t;
	chaseDir.y        = 0.0f;
	f32 chaseDist     = chaseDir.length();
	if (chaseDist > 0.0f) {
		chaseDir = (1.0f / chaseDist) * chaseDir;
	} else {
		f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
		chaseDir.set(cosf(randAngle), 0.0f, sinf(randAngle));
	}

	mPiki->setSpeed(1.0f, chaseDir);
	return ACTOUT_Continue;
}
