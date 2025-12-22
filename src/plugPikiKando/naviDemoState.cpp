#include "Boss.h"
#include "CPlate.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GameStat.h"
#include "GoalItem.h"
#include "ItemMgr.h"
#include "Kontroller.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "system.h"
#include "teki.h"
#include "zen/DrawAccount.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(41)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("naviDemo")

void NaviDemoSunsetState::DemoStateMachine::init(NaviDemoSunsetState*)
{
	create(36); // NOT 5 as it should be
	registerState(new GoState);
	registerState(new LookState);
	registerState(new WhistleState);
	registerState(new WaitState);
	registerState(new SitState);
}

void NaviDemoSunsetState::GoState::init(NaviDemoSunsetState* state)
{
	state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Run, state->mNavi), PaniMotionInfo(PIKIANIM_Run));
	_14 = false;
}

void NaviDemoSunsetState::GoState::exec(NaviDemoSunsetState* state)
{
	if (_14) {
		state->mNavi->mVelocity.multiply(0.9f);
		state->mNavi->mTargetVelocity = state->mNavi->mVelocity;
		return;
	}

	Vector3f diff = state->mGoalPos - state->mNavi->mSRT.t;
	f32 dist      = std::sqrtf(diff.x * diff.x + diff.z * diff.z);
	f32 nrm       = diff.normalise() / state->_2C;

	if (nrm > 0.7f && nrm < 0.71f && gsys->getRand(1.0f) >= 0.9999f) {
		_14 = true;
		state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Korobu, state->mNavi), PaniMotionInfo(PIKIANIM_Korobu));
		_10 = (int)(4.0f * gsys->getRand(1.0f)) + 2;
		return;
	}

	if (dist <= 5.0f) {
		state->mNavi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		transit(state, DEMOSTATE_Look);

	} else {
		diff                          = (diff * C_NAVI_PROP(state->mNavi)._CC()) * (nrm * 0.6f + 0.4f);
		state->mNavi->mTargetVelocity = diff;
	}

	STACK_PAD_VAR(1);
}

void NaviDemoSunsetState::GoState::procAnimMsg(NaviDemoSunsetState* state, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 6:
		if (_14) {
			_10--;
			state->mNavi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			state->mNavi->mVelocity.set(0.0f, 0.0f, 0.0f);
			if (_10 <= 0) {
				state->mNavi->mNaviAnimMgr.finishMotion(state->mNavi);
			}
		}
		break;
	case 0:
		state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Walk, state->mNavi), PaniMotionInfo(PIKIANIM_Walk));
		_14 = false;
		break;
	}
}

void NaviDemoSunsetState::GoState::cleanup(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::LookState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, state->mNavi), PaniMotionInfo(PIKIANIM_Sagasu2));
	cameraMgr->mCamera->finishMotion();
}

void NaviDemoSunsetState::LookState::exec(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::LookState::cleanup(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::LookState::procAnimMsg(NaviDemoSunsetState* state, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 0:
		if (GameStat::allPikis == 0) {
			transit(state, DEMOSTATE_Sit);
		} else {
			transit(state, DEMOSTATE_Whistle);
		}
		break;
	}
}

void NaviDemoSunsetState::WhistleState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(PIKIANIM_Fue, state->mNavi), PaniMotionInfo(PIKIANIM_Fue));
	_10           = 0;
	flowCont._23C = 1;
}

void NaviDemoSunsetState::WhistleState::exec(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::WhistleState::procAnimMsg(NaviDemoSunsetState* state, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 6:
		_10++;
		if (_10 == 8) {
			enterAllPikis(state);
		}
		if (_10 == 16) {
			state->mNavi->mNaviAnimMgr.finishMotion(state->mNavi);
		}
		break;
	case 0:
		transit(state, 3);
		break;
	}
}

void NaviDemoSunsetState::WhistleState::enterAllPikis(NaviDemoSunsetState* state)
{
	// This has a capacity of 200 in the vanilla game for some reason.
	Piki* pikiList[MAX_PIKI_ON_FIELD == 100 ? 200 : MAX_PIKI_ON_FIELD];
	Navi* navi = state->mNavi;
	Iterator it(itemMgr);
	GoalItem* goals[3];
	STACK_PAD_VAR(3);
	char goalBuf[256];
	CI_LOOP(it)
	{
		GoalItem* goal = (GoalItem*)*it;
		if (goal->mObjType == OBJTYPE_Goal) {
			goals[goal->mOnionColour] = goal;
		}
	}

	int i;
	for (i = 0; i < 3; i++) {
		if (!goals[i]) {
			sprintf(goalBuf, "no goal (%d)", i);
			PRINT("no goal %d\n", i);
		}
	}

	int pikis = 0;
	Iterator it2(navi->mPlateMgr);
	char colorBuf[256];
	CI_LOOP(it2)
	{
		Piki* piki = (Piki*)*it2;
		if (piki->isAlive()) {
			pikiList[pikis++] = piki;
		}
	}

	for (i = 0; i < pikis; i++) {
		if (pikiList[i]->mColor >= PikiColorCount) {
			PRINT("COLOR ID = %d\n", pikiList[i]->mColor);
			sprintf(colorBuf, "COLOR %d !!", pikiList[i]->mColor);
			ERROR(colorBuf);
		}

		navi->mGoalItem = goals[pikiList[i]->mColor];

		if (!navi->mGoalItem) {
			PRINT("navi accesscontainer = 0\n");
			ERROR("navi->ac=0");
		}
		pikiList[i]->changeMode(PikiMode::EnterMode, nullptr);
	}
}

void NaviDemoSunsetState::WhistleState::cleanup(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::WaitState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(PIKIANIM_Wait, state->mNavi), PaniMotionInfo(PIKIANIM_Wait));
}

void NaviDemoSunsetState::WaitState::exec(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::WaitState::cleanup(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::SitState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, state->mNavi), PaniMotionInfo(PIKIANIM_Suwaru));
}

void NaviDemoSunsetState::SitState::exec(NaviDemoSunsetState*)
{
}

void NaviDemoSunsetState::SitState::cleanup(NaviDemoSunsetState*)
{
}

NaviDemoSunsetState::NaviDemoSunsetState()
    : NaviState(NAVISTATE_DemoSunset)
{
	mStateMachine = new DemoStateMachine;
	mStateMachine->init(this);
}

void NaviDemoSunsetState::init(Navi* navi)
{
	seMgr->setPikiNum(0);
	seMgr->playNaviSound(0, 0);
	mNavi         = navi;
	mCurrentState = nullptr;
	mStateMachine->transit(this, DEMOSTATE_Go);
	mStartPos.set(0.0f, 0.0f, 0.0f);
	mGoalPos.set(0.0f, 0.0f, 400.0f);

	Iterator it(itemMgr);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (obj->mObjType == OBJTYPE_SunsetStart) {
			mStartPos = obj->mSRT.t;
		} else if (obj->mObjType == OBJTYPE_SunsetGoal) {
			mGoalPos = obj->mSRT.t;
		}
	}

	setActors(navi);
	_30 = 30.0f;
	cameraMgr->mCamera->startMotion(cameraMgr->mCamera->mAttentionInfo);
	mOpenedAccount = false;
}

void NaviDemoSunsetState::setActors(Navi* navi)
{
	navi->mSRT.t = mStartPos;

	Vector3f dist        = mGoalPos - mStartPos;
	_2C                  = dist.normalise();
	navi->mFaceDirection = atan2f(dist.x, dist.z);
	navi->makeCStick(false);

	Iterator iterParty(navi->mPlateMgr);
	CI_LOOP(iterParty)
	{
		Piki* piki      = (Piki*)*iterParty;
		ActCrowd* act   = (ActCrowd*)piki->mActiveAction->getCurrAction();
		Vector3f newpos = navi->mPlateMgr->mSlotList[act->mCPlateSlotID].mOffsetFromCenter + navi->mPlateMgr->mPlateCenter;
		piki->mSRT.t    = newpos;
		piki->mSRT.t.y  = mapMgr->getMinY(piki->mSRT.t.x, piki->mSRT.t.z, true);
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Piki* piki = (Piki*)*iterPiki;
		if (piki->mMode != PikiMode::FormationMode || piki->getState() == PIKISTATE_Flying) {
			piki->mEraseOnKill = true;
			piki->kill(false);
			iterPiki.dec();
		}
	}

	tekiMgr->store();
	itemMgr->store();
	tekiMgr->killAll();
	bossMgr->killAll();

	Iterator iterItem(itemMgr);
	CI_LOOP(iterItem)
	{
		Creature* item = *iterItem;
		if (item->mObjType != OBJTYPE_Pikihead && item->mObjType != OBJTYPE_Goal && item->mObjType != OBJTYPE_Fulcrum
		    && item->mObjType != OBJTYPE_Rope) {
			item->kill(false);
		}
	}
}

void NaviDemoSunsetState::exec(Navi* navi)
{
	navi->findNextThrowPiki();
	navi->makeCStick(true);
	navi->mNeutralTime = 0.0f;
	mStateMachine->exec(this);
	_30 -= gsys->getFrameTime();

	if (_30 < 0.0f || (_30 <= 15.0f && navi->mKontroller->keyClick(0x107f000))) {
		flowCont._240 = 1;
		cleanup(navi);
		return;
	}

	if (mOpenedAccount) {
		return;
	}

	if (!(_30 <= 20.0f)) {
		return;
	}

	zen::AccountData data(GameStat::minPikis, GameStat::maxPikis, GameStat::deadPikis, GameStat::killTekis, GameStat::getPellets);
	accountWindow->start(data);
	mOpenedAccount = true;
}

void NaviDemoSunsetState::cleanup(Navi* navi)
{
	Iterator it(pikiMgr);
	CI_LOOP(it)
	{
		Piki* piki = (Piki*)*it;
		if (piki && piki->isAlive()) {
			Iterator it2(itemMgr);
			CI_LOOP(it2)
			{
				GoalItem* item = (GoalItem*)*it2;
				if (item->mObjType == OBJTYPE_Goal && item->mOnionColour == piki->mColor) {
					item->enterGoal(piki);
				}
			}
		}
	}
}

void NaviDemoSunsetState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	mStateMachine->procMsg(this, msg);
}
