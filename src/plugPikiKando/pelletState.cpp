#include "PelletState.h"
#include "Suckable.h"
#include "Pellet.h"
#include "MapMgr.h"
#include "sysNew.h"
#include "gameflow.h"
#include "FlowController.h"
#include "PlayerState.h"
#include "GoalItem.h"
#include "Interface.h"
#include "Stickers.h"
#include "DebugLog.h"
#include "UtEffect.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("pelletState");

/*
 * --INFO--
 * Address:	8009A02C
 * Size:	000400
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

/*
 * --INFO--
 * Address:	8009A42C
 * Size:	00004C
 */
PelletUfoLoadState::PelletUfoLoadState()
    : PelletState(PELSTATE_UfoLoad, "UFOLOAD")
{
}

/*
 * --INFO--
 * Address:	8009A478
 * Size:	00000C
 */
void PelletUfoLoadState::init(Pellet*)
{
	mWaitTime = 8;
}

/*
 * --INFO--
 * Address:	8009A484
 * Size:	000070
 */
void PelletUfoLoadState::exec(Pellet* pelt)
{
	if (--mWaitTime == 0) {
		transit(pelt, PELSTATE_Appear);
		return;
	}

	Vector3f pos(pelt->mPosition);
	pelt->mPosition.y = mapMgr->getMinY(pos.x, pos.z, true);
	PRINT("setting ufo parts(%s) : y=%f\n", pelt->mConfig->mName, pelt->mPosition.y);
}

/*
 * --INFO--
 * Address:	8009A524
 * Size:	00001C
 */
void PelletUfoLoadState::cleanup(Pellet* pelt)
{
	pelt->resetUnk22();
	pelt->setUnk22();
}

/*
 * --INFO--
 * Address:	8009A540
 * Size:	00004C
 */
PelletDeadState::PelletDeadState()
    : PelletState(PELSTATE_Dead, "DEAD")
{
}

/*
 * --INFO--
 * Address:	8009A58C
 * Size:	000004
 */
void PelletDeadState::init(Pellet* pelt)
{
}

/*
 * --INFO--
 * Address:	8009A590
 * Size:	000004
 */
void PelletDeadState::exec(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A594
 * Size:	000004
 */
void PelletDeadState::cleanup(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A598
 * Size:	000048
 */
PelletNormalState::PelletNormalState()
    : PelletState(PELSTATE_Normal, "NORMAL")
{
}

/*
 * --INFO--
 * Address:	8009A5E0
 * Size:	000004
 */
void PelletNormalState::init(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A5E4
 * Size:	000004
 */
void PelletNormalState::exec(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A5E8
 * Size:	000004
 */
void PelletNormalState::cleanup(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A5EC
 * Size:	000050
 */
PelletSwallowedState::PelletSwallowedState()
    : PelletState(PELSTATE_Swallowed, "SWALLOWED")
{
}

/*
 * --INFO--
 * Address:	8009A63C
 * Size:	000004
 */
void PelletSwallowedState::init(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A640
 * Size:	00003C
 */
void PelletSwallowedState::exec(Pellet* pelt)
{
	if (!pelt->isStickToMouth()) {
		PRINT("pellet ha tasukatta !\n");
		transit(pelt, PELSTATE_Normal);
	}
}

/*
 * --INFO--
 * Address:	8009A67C
 * Size:	000024
 */
void PelletSwallowedState::cleanup(Pellet* pelt)
{
	pelt->endStickMouth();
}

/*
 * --INFO--
 * Address:	8009A6A0
 * Size:	00004C
 */
PelletAppearState::PelletAppearState()
    : PelletState(PELSTATE_Appear, "APPEAR")
{
}

/*
 * --INFO--
 * Address:	8009A6EC
 * Size:	000030
 */
void PelletAppearState::init(Pellet* pelt)
{
	f32 scale = pelt->mConfig->mPelletScale();
	_10       = 0.1f;
	pelt->mScale.set(_10 * scale, _10 * scale, _10 * scale);
	_14 = 2.0f;
}

/*
 * --INFO--
 * Address:	8009A71C
 * Size:	000030
 */
void PelletAppearState::procBounceMsg(Pellet* pelt, MsgBounce* msg)
{
	transit(pelt, PELSTATE_Normal);
}

/*
 * --INFO--
 * Address:	8009A74C
 * Size:	0000CC
 */
void PelletAppearState::exec(Pellet* pelt)
{
	f32 scale = pelt->mConfig->mPelletScale();
	pelt->invalidateCollisions();
	_10 += gsys->getFrameTime() * 3.3333333f;
	if (_10 >= 1.0f) {
		_10 = 1.0f;
		pelt->mScale.set(scale, scale, scale);
	} else {
		pelt->mScale.set(_10 * scale, _10 * scale, _10 * scale);
	}

	if (_10 >= 1.0f) {
		_14 -= gsys->getFrameTime();
		if (_14 < 0.0f) {
			transit(pelt, PELSTATE_Normal);
		}
	}
}

/*
 * --INFO--
 * Address:	8009A818
 * Size:	000004
 */
void PelletAppearState::cleanup(Pellet*)
{
}

/*
 * --INFO--
 * Address:	8009A81C
 * Size:	00005C
 */
PelletGoalState::PelletGoalState()
    : PelletState(PELSTATE_Goal, "GOAL")
{
}

/*
 * --INFO--
 * Address:	8009A878
 * Size:	00057C
 */
void PelletGoalState::init(Pellet* pelt)
{
	_31 = 0;
	if (pelt->mTargetGoal->mObjType == OBJTYPE_Ufo) {
		_31 = true;
		if (!playerState->mDemoFlags.isFlag(13)) {
			gameflow._1E0 = -1;
			gameflow._1E2 = -1;
			playerState->mDemoFlags.setFlag(13, (Creature*)itemMgr->getUfo());
			playerState->mDemoFlags.setFlagOnly(12);
		} else {
			bool check = playerState->getNextPowerupNumber() == true;
			for (int i = 0; i < 30; i++) {
				PRINT("nextPowerup = %d\n", playerState->getNextPowerupNumber());
			}
			gameflow._1E0 = pelletMgr->getUfoIndexFromID(pelt->mConfig->_2C.mId);
			gameflow._1E2 = check ? 2 : 0;
			PRINT("suicomi movie :- type = %d : info = %d\n", gameflow._1E2, gameflow._1E0);
			gameflow.mGameInterface->movie(79, 0, pelt, &pelt->mPosition, &pelt->mRotation, -1, true);
		}
		playerState->preloadHenkaMovie();

	} else if (flowCont.mCurrentStage->mStageID == 0) {
		if (!playerState->mDemoFlags.isFlag(10)) {
			PRINT("** FIRST PELLET IN\n");
			playerState->mDemoFlags.setFlag(10, pelt);
		}
	}
	pelt->startCarryMotion(120.0f);
	Vector3f posDiff = pelt->mTargetGoal->getSuckPos() - pelt->mTargetGoal->getGoalPos();
	_14              = posDiff.length();
	_10              = 0.0f;
	_18              = 1.5f;
	pelt->setCreatureFlag(0x80); // needs a further inline
	pelt->mVelocity.y = 0.0f;

	if (pelt->mTargetGoal->mObjType != OBJTYPE_Ufo) {
		Vector3f pos = pelt->mTargetGoal->getGoalPos();
		EffectParm parm(pos);
		utEffectMgr->cast(0, parm);
	}
	_1C = pelt->mScale.x;
	pelt->playEventSound(pelt->mTargetGoal, SE_CONTAINER_PELLETIN);
	pelt->mAngularMomentum = pelt->mAngularMomentum + Vector3f(100.0f, 200.0f, 10.0f);

	if (pelt->mTargetGoal->mObjType == OBJTYPE_Ufo) {
		Vector3f pos  = pelt->mTargetGoal->getGoalPos();
		Vector3f pos2 = pelt->mTargetGoal->getSuckPos();
		EffectParm parm(pos, pos2);
		utEffectMgr->cast(21, parm);
		utEffectMgr->cast(22, parm);
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

/*
 * --INFO--
 * Address:	8009ADF4
 * Size:	0002D4
 */
void PelletGoalState::exec(Pellet* pelt)
{
	if (_18 > 0.0f) {
		pelt->mVelocity.z = 0.0f;
		pelt->mVelocity.x = 0.0f;
		_18 -= gsys->getFrameTime();
		_30 = true;
		return;
	}

	if (_30) {
		_24           = pelt->mPosition;
		_20           = 0.0f;
		_30           = false;
		Vector3f diff = pelt->mTargetGoal->getSuckPos() - _24;
		_14           = diff.length();
		_34           = 0.0f;
	}

	Vector3f diff   = (pelt->mTargetGoal->getSuckPos() - _24);
	pelt->mPosition = _24 + diff * _20;
	f32 scale       = (1.0f - _20 * 0.75f) * _1C;
	pelt->mScale.set(scale, scale, scale);
	_20 += (_34 * gsys->getFrameTime()) / _14;
	_34 += gsys->getFrameTime() * 720.0f;

	if (_20 >= 1.0f) {
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

/*
 * --INFO--
 * Address:	8009B0CC
 * Size:	000030
 */
void PelletGoalState::cleanup(Pellet*)
{
	if (_31) {
		utEffectMgr->kill(21);
	}
}
