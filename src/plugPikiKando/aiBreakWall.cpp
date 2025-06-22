#include "PikiAI.h"
#include "PikiState.h"
#include "BuildingItem.h"
#include "AIPerf.h"
#include "UtEffect.h"
#include "gameflow.h"
#include "Interactions.h"
#include "FlowController.h"
#include "Dolphin/os.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("aiBreakWall")

/*
 * --INFO--
 * Address:	800AE13C
 * Size:	000070
 */
ActBreakWall::ActBreakWall(Piki* piki)
    : Action(piki, true)
{
	setName("breakWall");
}

/*
 * --INFO--
 * Address:	800AE1AC
 * Size:	000154
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
	mIsAttackReady      = 0;
	mPiki->mWantToStick = 0;
	mWorkTimer          = (4.0f * gsys->getRand(1.0f));
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AE300
 * Size:	0000C4
 */
void ActBreakWall::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (piki->getState() != PIKISTATE_LookAt) {
		Creature* collider = msg->mEvent.mCollider;
		if (collider == mWall && mState != STATE_BreakWall && msg->mEvent.mColliderPart->getID() == 'gate' && !piki->isStickTo()) {
			mHitPikminPosition = piki->mPosition;
			initBreakWall();
		}
		collider->isPiki();
	}
}

/*
 * --INFO--
 * Address:	800AE3C4
 * Size:	000190
 */
void ActBreakWall::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mIsAttackReady = 1;
		break;
	case KEY_Action1:
		mIsAttackReady = 0;
		break;
	case KEY_Finished:
		mWorkTimer = (4.0f * gsys->getRand(1.0f));
		startWorkMotion();
		mIsAttackReady = 0;
		break;
	case KEY_PlayEffect:
		if (!mPiki->isCreatureFlag(CF_IsAICullingActive) && (AIPerf::optLevel <= 0 || mPiki->mOptUpdateContext.updatable())) {
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

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	800AE554
 * Size:	000148
 */
int ActBreakWall::exec()
{
	if (!mWall || !mWall->isAlive()) {
		return ACTOUT_Fail;
	}

	switch (mState) {
	case STATE_GotoWall:
		return gotoWall();

	case STATE_BreakWall:
		Vector3f sep = mHitPikminPosition - mPiki->mPosition;
		if (sep.length() > 5.0f) {
			mState = STATE_GotoWall;
			break;
		}
		return breakWall();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AE6BC
 * Size:	0000C8
 */
int ActBreakWall::gotoWall()
{
	Vector3f direction = mWall->mPosition - mPiki->mPosition;
	direction.normalise();
	mPiki->setSpeed(1.0f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AE784
 * Size:	000090
 */
void ActBreakWall::initBreakWall()
{
	mWorkTimer = (4.0f * gsys->getRand(1.0f));
	startWorkMotion();
	mState           = STATE_BreakWall;
	mStartAttackTime = gameflow.mWorldClock.mMinutes;
}

/*
 * --INFO--
 * Address:	800AE814
 * Size:	0000F4
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

/*
 * --INFO--
 * Address:	800AE908
 * Size:	0002E4
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

	int timeSinceLastAttack = (gameflow.mWorldClock.mMinutes - mStartAttackTime + 60) % 60;
	if (flowCont.mCurrentStage->mStageID == STAGE_Practice) {
		timeSinceLastAttack = 1;
	}

	if (timeSinceLastAttack > 0 && mIsAttackReady) {
		InteractAttack attack(mPiki, nullptr, timeSinceLastAttack / 60.0f, false);
		mIsAttackReady = 0;
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

		mStartAttackTime = gameflow.mWorldClock.mMinutes;
	}

	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AEC08
 * Size:	000004
 */
void ActBreakWall::cleanup()
{
}
