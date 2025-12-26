#include "PelletState.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GoalItem.h"
#include "Interface.h"
#include "MapMgr.h"
#include "MoviePlayer.h"
#include "Pellet.h"
#include "PlayerState.h"
#include "Stickers.h"
#include "Suckable.h"
#include "UfoItem.h"
#include "UtEffect.h"
#include "gameflow.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pelletState");

/**
 * @todo: Documentation
 */
void PelletStateMachine::init(Pellet* pelt)
{
	create(PELSTATE_StateCount);
	registerState(new PelletNormalState);
	registerState(new PelletAppearState);
	registerState(new PelletSwallowedState);
	registerState(new PelletGoalState);
	registerState(new PelletDeadState);
	registerState(new PelletUfoLoadState);
}

/**
 * @todo: Documentation
 */
PelletUfoLoadState::PelletUfoLoadState()
    : PelletState(PELSTATE_UfoLoad, "UFOLOAD")
{
}

/**
 * @todo: Documentation
 */
void PelletUfoLoadState::init(Pellet*)
{
	mWaitTime = 8;
}

/**
 * @todo: Documentation
 */
void PelletUfoLoadState::exec(Pellet* pelt)
{
	if (--mWaitTime == 0) {
		transit(pelt, PELSTATE_Appear);
		return;
	}

	Vector3f pos(pelt->mSRT.t);
	pelt->mSRT.t.y = mapMgr->getMinY(pos.x, pos.z, true);
	PRINT("setting ufo parts(%s) : y=%f\n", pelt->mConfig->mName, pelt->mSRT.t.y);
}

/**
 * @todo: Documentation
 */
void PelletUfoLoadState::cleanup(Pellet* pelt)
{
	pelt->disableFixPos();
	pelt->enableFixPos();
}

/**
 * @todo: Documentation
 */
PelletDeadState::PelletDeadState()
    : PelletState(PELSTATE_Dead, "DEAD")
{
}

/**
 * @todo: Documentation
 */
void PelletDeadState::init(Pellet* pelt)
{
}

/**
 * @todo: Documentation
 */
void PelletDeadState::exec(Pellet*)
{
}

/**
 * @todo: Documentation
 */
void PelletDeadState::cleanup(Pellet*)
{
}

/**
 * @todo: Documentation
 */
PelletNormalState::PelletNormalState()
    : PelletState(PELSTATE_Normal, "NORMAL")
{
}

/**
 * @todo: Documentation
 */
void PelletNormalState::init(Pellet*)
{
}

/**
 * @todo: Documentation
 */
void PelletNormalState::exec(Pellet*)
{
}

/**
 * @todo: Documentation
 */
void PelletNormalState::cleanup(Pellet*)
{
}

/**
 * @todo: Documentation
 */
PelletSwallowedState::PelletSwallowedState()
    : PelletState(PELSTATE_Swallowed, "SWALLOWED")
{
}

/**
 * @todo: Documentation
 */
void PelletSwallowedState::init(Pellet*)
{
}

/**
 * @todo: Documentation
 */
void PelletSwallowedState::exec(Pellet* pelt)
{
	if (!pelt->isStickToMouth()) {
		PRINT("pellet ha tasukatta !\n");
		transit(pelt, PELSTATE_Normal);
	}
}

/**
 * @todo: Documentation
 */
void PelletSwallowedState::cleanup(Pellet* pelt)
{
	pelt->endStickMouth();
}

/**
 * @todo: Documentation
 */
PelletAppearState::PelletAppearState()
    : PelletState(PELSTATE_Appear, "APPEAR")
{
}

/**
 * @todo: Documentation
 */
void PelletAppearState::init(Pellet* pelt)
{
	f32 scale     = pelt->mConfig->mPelletScale();
	mCurrentScale = 0.1f;
	pelt->mSRT.s.set(mCurrentScale * scale, mCurrentScale * scale, mCurrentScale * scale);
	mTransitionTimer = 2.0f;
}

/**
 * @todo: Documentation
 */
void PelletAppearState::procBounceMsg(Pellet* pelt, MsgBounce* msg)
{
	transit(pelt, PELSTATE_Normal);
}

/**
 * @todo: Documentation
 */
void PelletAppearState::exec(Pellet* pelt)
{
	f32 scale = pelt->mConfig->mPelletScale();
	pelt->invalidateCollisions();
	mCurrentScale += gsys->getFrameTime() * 3.3333333f;
	if (mCurrentScale >= 1.0f) {
		mCurrentScale = 1.0f;
		pelt->mSRT.s.set(scale, scale, scale);
	} else {
		pelt->mSRT.s.set(mCurrentScale * scale, mCurrentScale * scale, mCurrentScale * scale);
	}

	if (mCurrentScale >= 1.0f) {
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			transit(pelt, PELSTATE_Normal);
		}
	}
}

/**
 * @todo: Documentation
 */
void PelletAppearState::cleanup(Pellet*)
{
}

/**
 * @todo: Documentation
 */
PelletGoalState::PelletGoalState()
    : PelletState(PELSTATE_Goal, "GOAL")
{
}

/**
 * @todo: Documentation
 */
void PelletGoalState::init(Pellet* pelt)
{
	mTargetIsShip = false;
	if (pelt->mTargetGoal->mObjType == OBJTYPE_Ufo) {
		mTargetIsShip = true;
		if (!playerState->mDemoFlags.isFlag(DEMOFLAG_CollectEngine)) {
			gameflow.mMovieInfoNum = -1;
			gameflow.mMovieType    = -1;
			playerState->mDemoFlags.setFlag(DEMOFLAG_CollectEngine, itemMgr->getUfo());
			// just in case we got the engine without triggering the approach engine cutscene (somehow)
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_ApproachEngine);

		} else {
			bool check = playerState->getNextPowerupNumber() == true;
			for (int i = 0; i < 30; i++) {
				PRINT("nextPowerup = %d\n", playerState->getNextPowerupNumber());
			}
			gameflow.mMovieInfoNum = pelletMgr->getUfoIndexFromID(pelt->mConfig->mModelId.mId);
			gameflow.mMovieType    = check ? 2 : 0;
			PRINT("suicomi movie :- type = %d : info = %d\n", gameflow.mMovieType, gameflow.mMovieInfoNum);
			gameflow.mGameInterface->movie(DEMOID_CollectPart, 0, pelt, &pelt->mSRT.t, &pelt->mSRT.r, -1, true);
		}
		playerState->preloadHenkaMovie();

	} else if (flowCont.mCurrentStage->mStageID == STAGE_Practice) {
		if (!playerState->mDemoFlags.isFlag(DEMOFLAG_CollectFirstPellet)) {
			PRINT("** FIRST PELLET IN\n");
			playerState->mDemoFlags.setFlag(DEMOFLAG_CollectFirstPellet, pelt);
		}
	}

	pelt->startCarryMotion(120.0f);

	Vector3f posDiff  = pelt->mTargetGoal->getSuckPos() - pelt->mTargetGoal->getGoalPos();
	mDistanceToTarget = posDiff.length();

	_10        = 0.0f;
	mWaitTimer = 1.5f;
	pelt->setFlag80();
	pelt->mVelocity.y = 0.0f;

	if (pelt->mTargetGoal->mObjType != OBJTYPE_Ufo) {
		Vector3f pos = pelt->mTargetGoal->getGoalPos();
		EffectParm parm(pos);
		utEffectMgr->cast(KandoEffect::Goal, parm);
	}

	mStartScaleX = pelt->mSRT.s.x;
	pelt->playEventSound(pelt->mTargetGoal, SE_CONTAINER_PELLETIN);
	pelt->mAngularMomentum = pelt->mAngularMomentum + Vector3f(100.0f, 200.0f, 10.0f);

	if (pelt->mTargetGoal->mObjType == OBJTYPE_Ufo) {
		Vector3f goalPos = pelt->mTargetGoal->getGoalPos();
		Vector3f suckPos = pelt->mTargetGoal->getSuckPos();
		EffectParm parm(goalPos, suckPos);
		utEffectMgr->cast(KandoEffect::UfoSuck, parm);
		utEffectMgr->cast(KandoEffect::UfoSuikomi, parm);
	}

	Stickers stick(pelt);
	Iterator it(&stick);
	PRINT("PELLET GOAL START*******\n");
	CI_LOOP(it)
	{
		Creature* obj = *it;
		PRINT("still stick %s\n", ObjType::getName(obj->mObjType));
	}

	if (pelt->mConfig->mPelletType() == PELTYPE_UfoPart) {
		pelt->mTargetGoal->suckMe(pelt);
	}
}

/**
 * @todo: Documentation
 */
void PelletGoalState::exec(Pellet* pelt)
{
	if (mWaitTimer > 0.0f) {
		pelt->mVelocity.z = 0.0f;
		pelt->mVelocity.x = 0.0f;
		mWaitTimer -= gsys->getFrameTime();
		mIsFirstMove = true;
		return;
	}

	if (mIsFirstMove) {
		mStartPosition    = pelt->mSRT.t;
		mSuckProgress     = 0.0f;
		mIsFirstMove      = false;
		Vector3f diff     = pelt->mTargetGoal->getSuckPos() - mStartPosition;
		mDistanceToTarget = diff.length();
		mSuckSpeed        = 0.0f;
	}

	Vector3f diff = (pelt->mTargetGoal->getSuckPos() - mStartPosition);
	pelt->mSRT.t  = mStartPosition + diff * mSuckProgress;
	f32 scale     = (1.0f - mSuckProgress * 0.75f) * mStartScaleX;
	pelt->mSRT.s.set(scale, scale, scale);
	mSuckProgress += (mSuckSpeed * gsys->getFrameTime()) / mDistanceToTarget;
	mSuckSpeed += gsys->getFrameTime() * 720.0f;

	if (mSuckProgress >= 1.0f) {
		if (pelt->mConfig->mPelletType() == PELTYPE_UfoPart) {
			pelt->mTargetGoal->finishSuck(pelt);
		} else {
			pelt->mTargetGoal->suckMe(pelt);
		}

		pelt->mIsAlive = false;
		pelt->kill(false);
		transit(pelt, PELSTATE_Dead);
	}
}

/**
 * @todo: Documentation
 */
void PelletGoalState::cleanup(Pellet*)
{
	PRINT("pelletGoalState * CLEAN UP\n");
	if (mTargetIsShip) {
		utEffectMgr->kill(KandoEffect::UfoSuck);
	}
	PRINT("** DONE\n");
}
