#include "NaviState.h"
#include "NaviMgr.h"
#include "system.h"
#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"
#include "PikiState.h"
#include "GameStat.h"
#include "ItemMgr.h"
#include "CPlate.h"
#include "GoalItem.h"
#include "teki.h"
#include "Boss.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "Kontroller.h"
#include "zen/DrawAccount.h"
#include "FlowController.h"
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
DEFINE_PRINT("naviDemo")

/*
 * --INFO--
 * Address:	8010B0E0
 * Size:	000478
 */
void NaviDemoSunsetState::DemoStateMachine::init(NaviDemoSunsetState*)
{
	create(36); // NOT 5 as it should be
	registerState(new GoState);
	registerState(new LookState);
	registerState(new WhistleState);
	registerState(new WaitState);
	registerState(new SitState);
}

/*
 * --INFO--
 * Address:	8010B558
 * Size:	000090
 */
void NaviDemoSunsetState::GoState::init(NaviDemoSunsetState* state)
{
	state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(0, state->mNavi), PaniMotionInfo(0));
	_14 = false;
}

/*
 * --INFO--
 * Address:	8010B5E8
 * Size:	00034C
 */
void NaviDemoSunsetState::GoState::exec(NaviDemoSunsetState* state)
{
	if (_14) {
		state->mNavi->mVelocity.multiply(0.9f);
		state->mNavi->mTargetVelocity = state->mNavi->mVelocity;
		return;
	}

	Vector3f diff = state->mGoalPos - state->mNavi->mPosition;
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

	u32 badCompiler[1];
}

/*
 * --INFO--
 * Address:	8010BA1C
 * Size:	00012C
 */
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
		state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(2, state->mNavi), PaniMotionInfo(2));
		_14 = false;
		break;
	}
}

/*
 * --INFO--
 * Address:	8010BB48
 * Size:	000004
 */
void NaviDemoSunsetState::GoState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BB4C
 * Size:	000084
 */
void NaviDemoSunsetState::LookState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(65, state->mNavi), PaniMotionInfo(65));
	cameraMgr->mCamera->finishMotion();
}

/*
 * --INFO--
 * Address:	8010BBD0
 * Size:	000004
 */
void NaviDemoSunsetState::LookState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BBD4
 * Size:	000004
 */
void NaviDemoSunsetState::LookState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BBD8
 * Size:	00007C
 */
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

/*
 * --INFO--
 * Address:	8010BC54
 * Size:	00009C
 */
void NaviDemoSunsetState::WhistleState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(49, state->mNavi), PaniMotionInfo(49));
	_10           = 0;
	flowCont._23C = 1;
}

/*
 * --INFO--
 * Address:	8010BCF0
 * Size:	000004
 */
void NaviDemoSunsetState::WhistleState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BCF4
 * Size:	0000C0
 */
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

/*
 * --INFO--
 * Address:	8010BDB4
 * Size:	0002C8
 */
void NaviDemoSunsetState::WhistleState::enterAllPikis(NaviDemoSunsetState* state)
{

	Piki* pikiList[MAX_PIKI_ON_FIELD + 100];
	Navi* navi = state->mNavi;
	Iterator it(itemMgr);
	GoalItem* goals[3];
	u32 badCompiler[3];
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
		if (pikiList[i]->mColor >= 3) {
			PRINT("COLOR ID = %d\n", pikiList[i]->mColor);
			sprintf(colorBuf, "COLOR %d !!", pikiList[i]->mColor);
			ERROR(colorBuf);
		}

		navi->mGoalItem = goals[pikiList[i]->mColor];
		pikiList[i]->changeMode(11, nullptr);
	}
}

/*
 * --INFO--
 * Address:	8010C07C
 * Size:	000004
 */
void NaviDemoSunsetState::WhistleState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C080
 * Size:	000078
 */
void NaviDemoSunsetState::WaitState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(PIKIANIM_Wait, state->mNavi), PaniMotionInfo(PIKIANIM_Wait));
}

/*
 * --INFO--
 * Address:	8010C0F8
 * Size:	000004
 */
void NaviDemoSunsetState::WaitState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C0FC
 * Size:	000004
 */
void NaviDemoSunsetState::WaitState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C100
 * Size:	000078
 */
void NaviDemoSunsetState::SitState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, state->mNavi), PaniMotionInfo(PIKIANIM_Suwaru));
}

/*
 * --INFO--
 * Address:	8010C178
 * Size:	000004
 */
void NaviDemoSunsetState::SitState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C17C
 * Size:	000004
 */
void NaviDemoSunsetState::SitState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C180
 * Size:	0000D4
 */
NaviDemoSunsetState::NaviDemoSunsetState()
    : NaviState(NAVISTATE_DemoSunset)
{
	mStateMachine = new DemoStateMachine;
	mStateMachine->init(this);
}

/*
 * --INFO--
 * Address:	8010C254
 * Size:	000200
 */
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
			mStartPos = obj->mPosition;
		} else if (obj->mObjType == OBJTYPE_SunsetGoal) {
			mGoalPos = obj->mPosition;
		}
	}

	setActors(navi);
	_30 = 30.0f;
	cameraMgr->mCamera->startMotion(*(PcamMotionInfo*)((int)cameraMgr->mCamera + 0x38)); // I really dont want to figure out this struct yet
	mOpenedAccount = false;
}

/*
 * --INFO--
 * Address:	8010C454
 * Size:	0004A0
 */
void NaviDemoSunsetState::setActors(Navi* navi)
{
	navi->mPosition = mStartPos;

	Vector3f dist        = mGoalPos - mStartPos;
	_2C                  = dist.normalise();
	navi->mFaceDirection = atan2f(dist.x, dist.z);
	navi->makeCStick(false);

	Iterator iterParty(navi->mPlateMgr);
	CI_LOOP(iterParty)
	{
		Piki* piki        = (Piki*)*iterParty;
		ActCrowd* act     = (ActCrowd*)piki->mActiveAction->getCurrAction();
		Vector3f newpos   = navi->mPlateMgr->mSlotList[act->mCPlateSlotID].mOffsetFromCenter + navi->mPlateMgr->mPlateCenter;
		piki->mPosition   = newpos;
		piki->mPosition.y = mapMgr->getMinY(piki->mPosition.x, piki->mPosition.z, true);
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

/*
 * --INFO--
 * Address:	8010C8F4
 * Size:	000160
 */
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

/*
 * --INFO--
 * Address:	8010CA94
 * Size:	000218
 */
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

/*
 * --INFO--
 * Address:	8010CCAC
 * Size:	000034
 */
void NaviDemoSunsetState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	mStateMachine->procMsg(this, msg);
}
