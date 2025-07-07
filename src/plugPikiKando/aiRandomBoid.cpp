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
DEFINE_PRINT("aiRandomBoid")

/*
 * --INFO--
 * Address:	800C0A10
 * Size:	0002F8
 */
void ActRandomBoid::AnimListener::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		mAction->mIsAnimFinishing = 0;
		switch (mAction->mState) {
		case STATE_Boid:
			f32 angle = 2.0f * (PI * gsys->getRand(1.0f));
			if (gsys->getRand(1.0f) > 0.8f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
				mPiki->setSpeed(-1.2f, Vector3f(cosf(angle), 0.0f, sinf(angle)));
				return;
			}

			if (gsys->getRand(1.0f) > 0.8f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
				mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
				return;
			}

			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
			mPiki->setSpeed(0.0f, Vector3f(cosf(angle), 0.0f, sinf(angle)));
			break;
		case STATE_Stop:
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
			break;
		case STATE_Random:
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
			f32 angle2 = 2.0f * (PI * gsys->getRand(1.0f));
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			break;
		}
		break;
	case KEY_Action0:
		break;
	}
}

/*
 * --INFO--
 * Address:	800C0D08
 * Size:	00008C
 */
ActRandomBoid::ActRandomBoid(Piki* piki)
    : Action(piki, true)
{
	mListener = new AnimListener(this, piki);
}

/*
 * --INFO--
 * Address:	800C0D94
 * Size:	000004
 */
void ActRandomBoid::Initialiser::initialise(Action*)
{
}

/*
 * --INFO--
 * Address:	800C0D98
 * Size:	0000E8
 */
void ActRandomBoid::init(Creature*)
{
	mState      = STATE_Boid;
	mStateTimer = int((10.0f * gsys->getRand(1.0f))) + 20;
	f32 angle   = 2.0f * (PI * gsys->getRand(1.0f));
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, mListener), PaniMotionInfo(PIKIANIM_Run, mListener));
	mListener->_0C   = 0;
	mIsAnimFinishing = 0;
}

/*
 * --INFO--
 * Address:	800C0E80
 * Size:	000004
 */
void ActRandomBoid::cleanup()
{
}

/*
 * --INFO--
 * Address:	800C0E84
 * Size:	0003BC
 */
int ActRandomBoid::exec()
{
	if (mIsAnimFinishing) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return ACTOUT_Continue;
	}

	if (--mStateTimer < 0) {
		mStateTimer    = int((12.0f * gsys->getRand(1.0f))) + 38;
		int startState = mState;
		if (mState == STATE_Boid && gsys->getRand(1.0f) > 0.5f) {
			mState = STATE_Idle;
			mPiki->mPikiAnimMgr.finishMotion(mListener);
			mIsAnimFinishing = 1;
			mStateTimer += int((50.0f * gsys->getRand(1.0f))) + 30;
		} else if (gsys->getRand(1.0f) > 0.65f) {
			if (gsys->getRand(1.0f) > 0.75f) {
				mState = STATE_Random;
				if (startState != STATE_Random) {
					mPiki->mPikiAnimMgr.finishMotion(mListener);
					mIsAnimFinishing = 1;
				}
			} else {
				mState = STATE_Boid;
				if (startState != STATE_Stop && startState != STATE_Boid) {
					mPiki->mPikiAnimMgr.finishMotion(mListener);
					mIsAnimFinishing = 1;
				}
			}

			f32 randomAngle = 2.0f * (PI * gsys->getRand(1.0f));
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			mStateTimer += 120;
		} else {
			mStateTimer += 120;
			mState = STATE_Stop;
			if (startState != STATE_Stop || startState != STATE_Boid) {
				mPiki->mPikiAnimMgr.finishMotion(mListener);
				mIsAnimFinishing = 1;
				return ACTOUT_Continue;
			}
		}

		return ACTOUT_Continue;
	}

	if (mState == STATE_Stop) {
		mStateTimer = 1;
	}

	if (mState == STATE_Idle) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}

	STACK_PAD_VAR(15);
	Vector3f avoidVec;
	if (mPiki->getAvoid(mPiki->mTargetVelocity, avoidVec)) {
		mPiki->mTargetVelocity = mPiki->mTargetVelocity + mPiki->getSpeed(0.5f) * avoidVec;
	}

	return ACTOUT_Continue;

	STACK_PAD_TERNARY(mPiki, 12);
	STACK_PAD_TERNARY(mPiki, 1);
	STACK_PAD_INLINE(12);
	STACK_PAD_INLINE(12);
	STACK_PAD_INLINE(5);
	STACK_PAD_STRUCT(3);
	STACK_PAD_VAR(13);
}

static char* stateName[] = {
	"ランダム", // 'random'
	"Boid",
	"停止", // 'stop'
};

/*
 * --INFO--
 * Address:	800C1240
 * Size:	000044
 */
void ActRandomBoid::getInfo(char* buf)
{
	sprintf(buf, "%s", stateName[mState]);
}
