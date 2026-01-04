#include "AIPerf.h"
#include "BuildingItem.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
#include "Interactions.h"
#include "PikiAI.h"
#include "PikiState.h"
#include "UtEffect.h"
#include "gameflow.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("aiBreakWall")

/**
 * @todo: Documentation
 */
ActBreakWall::ActBreakWall(Piki* piki)
    : Action(piki, true)
{
	setName("breakWall");
}

/**
 * @todo: Documentation
 */
void ActBreakWall::init(Creature* creature)
{
	mFailAttackCounter  = 0;
	mPiki->mActionState = 2;
	mPiki->mEmotion     = PikiEmotion::Happy;

	if (creature->isSluice()) {
		mWall = static_cast<BuildingItem*>(creature);
	} else {
		mWall = nullptr;
	}

	mState              = STATE_GotoWall;
	mIsAttackReady      = false;
	mPiki->mWantToStick = false;
	mWorkTimer          = (4.0f * gsys->getRand(1.0f));
#if defined(VERSION_PIKIDEMO)
#else
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
#endif
}

/**
 * @todo: Documentation
 */
void ActBreakWall::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (piki->getState() != PIKISTATE_LookAt) {
		Creature* collider = msg->mEvent.mCollider;
		if (collider == mWall && mState != STATE_BreakWall && msg->mEvent.mColliderPart->getID() == 'gate' && !piki->isStickTo()) {
			mHitPikminPosition = piki->mSRT.t;
			initBreakWall();
		}
		collider->isPiki();
	}
}

/**
 * @todo: Documentation
 */
void ActBreakWall::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
	{
		mIsAttackReady = true;
		break;
	}
	case KEY_Action1:
	{
		mIsAttackReady = false;
		break;
	}
	case KEY_Finished:
	{
		mWorkTimer = (4.0f * gsys->getRand(1.0f));
		startWorkMotion();
		mIsAttackReady = false;
		break;
	}
	case KEY_PlayEffect:
	{
		if (!mPiki->isCreatureFlag(CF_UseAICulling) && (AIPerf::optLevel <= 0 || mPiki->mOptUpdateContext.updatable())) {
			Vector3f vec = mPiki->mEffectPos;
			EffectParm parm(vec);
			if (mWall->mObjType == OBJTYPE_SluiceSoft) {
				UtEffectMgr::cast(KandoEffect::WallHit1, parm);
			} else if (mWall->mObjType == OBJTYPE_SluiceHard) {
				UtEffectMgr::cast(KandoEffect::WallHit2, parm);
			} else {
				UtEffectMgr::cast(KandoEffect::WallHit3, parm);
			}
		}
		break;
	}
	}

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
int ActBreakWall::exec()
{
	if (!mWall || !mWall->isAlive()) {
		return ACTOUT_Fail;
	}

	switch (mState) {
	case STATE_GotoWall:
	{
		return gotoWall();
	}
	case STATE_BreakWall:
	{
		Vector3f sep = mHitPikminPosition - mPiki->mSRT.t;
		if (sep.length() > 5.0f) {
			mState = STATE_GotoWall;
			break;
		}
		return breakWall();
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
int ActBreakWall::gotoWall()
{
	Vector3f direction = mWall->mSRT.t - mPiki->mSRT.t;
	direction.normalise();
	mPiki->setSpeed(1.0f, direction);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBreakWall::initBreakWall()
{
	mWorkTimer = (4.0f * gsys->getRand(1.0f));
	startWorkMotion();
	mState           = STATE_BreakWall;
	mStartAttackTime = gameflow.mWorldClock.mCurrentGameMinute;
}

/**
 * @todo: Documentation
 */
void ActBreakWall::startWorkMotion()
{
	if (mWorkTimer == 0) {
		if (mPiki->getCollidePlatformCreature()) {
			Vector3f normal = mPiki->getCollidePlatformNormal();
			if (normal.y > 0.7f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Job2, this), PaniMotionInfo(PIKIANIM_Job2));
				return;
			}
		}

		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	}
}

/**
 * @todo: Documentation
 */
int ActBreakWall::breakWall()
{
	if (mWorkTimer != 0) {
		mWorkTimer--;
		if (mWorkTimer == 0) {
			startWorkMotion();
		}
		return ACTOUT_Continue;
	}

	int timeSinceLastAttack = (gameflow.mWorldClock.mCurrentGameMinute - mStartAttackTime + 60) % 60;
	if (flowCont.mCurrentStage->mStageID == STAGE_Practice) {
		timeSinceLastAttack = 1;
	}

	if (timeSinceLastAttack > 0 && mIsAttackReady) {
		InteractAttack attack(mPiki, nullptr, timeSinceLastAttack / 60.0f, false);
		mIsAttackReady = false;
		if (!mWall->stimulate(attack)) {
			if (mWall->isCompleted()) {
				return ACTOUT_Success;
			}
			mFailAttackCounter++;
			if (mFailAttackCounter >= int((3.0f * gsys->getRand(1.0f))) + 3) {
				mPiki->mEmotion     = PikiEmotion::Sad;
				mPiki->mActionState = 0;
				return ACTOUT_Fail;
			}
		}

		mStartAttackTime = gameflow.mWorldClock.mCurrentGameMinute;
	}

	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBreakWall::cleanup()
{
}
