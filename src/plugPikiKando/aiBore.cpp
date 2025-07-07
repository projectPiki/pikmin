#include "Boss.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "ItemMgr.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "PikiAI.h"
#include "SoundMgr.h"
#include "UtilityKando.h"
#include "sysNew.h"
#include "system.h"
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
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800AA51C
 * Size:	000108
 */
ActFreeSelect::ActFreeSelect(Piki* piki)
    : Action(piki, true)
{
	setName("freebore");
	setChildren(CHILD_COUNT, new ActWatch(piki), nullptr, new ActBoreTalk(piki), nullptr, new ActBoreOneshot(piki), nullptr,
	            new ActBoreRest(piki), nullptr);
}

/*
 * --INFO--
 * Address:	800AA624
 * Size:	0000F4
 */
void ActFreeSelect::init(Creature* creature)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, mPiki), PaniMotionInfo(PIKIANIM_Wait));
	mActionTimer   = 2.0f + gsys->getFrameTime();
	mIsTimerActive = 1;
	mCurrActionIdx = CHILD_NULL;

	_1C                  = PI * (gsys->getRand(1.0f) - 0.5f) / 3.0f;
	mIsChildActionActive = 0;
	mIsFinished          = 0;
}

/*
 * --INFO--
 * Address:	800AA718
 * Size:	000084
 */
void ActFreeSelect::finishRest()
{
	switch (mCurrActionIdx) {
	case CHILD_BoreRest:
		static_cast<ActBoreRest*>(mChildActions[mCurrActionIdx].mAction)->finishRest();
		mIsChildActionActive = 1;
		break;
	case CHILD_BoreOneshot:
		static_cast<ActBoreOneshot*>(mChildActions[mCurrActionIdx].mAction)->finish();
		mIsChildActionActive = 1;
		break;
	default:
		mIsFinished = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800AA79C
 * Size:	000108
 */
int ActFreeSelect::exec()
{
	if (mIsFinished) {
		return ACTOUT_Success;
	}

	if (mIsChildActionActive) {
		return mChildActions[mCurrActionIdx].mAction->exec();
	}

	if (mIsTimerActive) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mActionTimer -= gsys->getFrameTime();
		if (mActionTimer < 0.0f) {
			determine();
		}
	} else {
		if (mChildActions[mCurrActionIdx].mAction->exec()) {
			init(nullptr);
		}
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AA8A4
 * Size:	000004
 */
void ActFreeSelect::cleanup()
{
}

/*
 * --INFO--
 * Address:	800AA8A8
 * Size:	000078
 */
void ActFreeSelect::procTargetMsg(Piki* piki, MsgTarget* msg)
{
	if (mIsTimerActive) {
		mIsTimerActive = 0;
		mCurrActionIdx = CHILD_Watch;
		mChildActions[mCurrActionIdx].initialise(msg->mTarget);
		return;
	}

	if (mCurrActionIdx == CHILD_BoreTalk) {
		ActBoreTalk* boreTalk             = static_cast<ActBoreTalk*>(mChildActions[mCurrActionIdx].mAction);
		boreTalk->mIsLookHandledElsewhere = 0;
		boreTalk->mTarget                 = msg->mTarget;
	}
}

/*
 * --INFO--
 * Address:	800AA920
 * Size:	0002D8
 */
void ActFreeSelect::determine()
{
	if (gsys->getRand(1.0f) > 0.5f) {
		mActionTimer = 2.0f + gsys->getFrameTime();
		return;
	}

	Choice choices[CHILD_COUNT] = {
		{ CHILD_Watch, 0.2f },
		{ CHILD_BoreTalk, 0.1f },
		{ CHILD_BoreOneshot, 0.3f },
		{ CHILD_BoreRest, 0.3f },
	};

	int randIdx = selectRandomly(choices, CHILD_COUNT);

	if (mPiki->isHolding()) {
		randIdx = CHILD_Watch;
	}

	Creature* target;
	Creature* nearestItem;
	Creature* nearestNavi;
	Creature* nearestTeki;
	Creature* nearestBoss;
	mIsTimerActive = false;
	mCurrActionIdx = randIdx;
	target         = nullptr;
	switch (randIdx) {
	case CHILD_Watch:

		nearestTeki = (tekiMgr) ? tekiMgr->findClosest(mPiki->mPosition, nullptr) : nullptr;

		nearestItem = itemMgr->findClosest(mPiki->mPosition, nullptr);
		nearestNavi = naviMgr->findClosest(mPiki->mPosition, nullptr);

		if (bossMgr) {
			nearestBoss = bossMgr->findClosest(mPiki->mPosition, nullptr);
		} else {
			nearestBoss = nullptr;
		}

		if (nearestBoss) {
			target = nearestBoss;
			break;
		}

		// these are probably not distances, rename later
		f32 enemyDist = (nearestTeki) ? nearestTeki->mVelocity.length() : 0.0f;
		f32 itemDist  = (nearestItem) ? nearestItem->mVelocity.length() : 0.0f;
		f32 naviDist  = (nearestNavi) ? nearestNavi->mVelocity.length() : 0.0f;

		if (enemyDist > itemDist && enemyDist > naviDist) {
			target = nearestTeki;
			break;
		}

		if (itemDist > naviDist) {
			target = nearestItem;
			break;
		}

		target = nearestNavi;
		break;
	case CHILD_BoreTalk:
		break;
	}

	mChildActions[mCurrActionIdx].initialise(target);

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	800AABF8
 * Size:	000104
 */
ActBoreSelect::ActBoreSelect(Piki* piki)
    : Action(piki, true)
{
	mName = "bore";
	setChildren(CHILD_COUNT, new ActWatch(piki), nullptr, new ActBoreTalk(piki), nullptr, new ActBoreOneshot(piki), nullptr,
	            new ActBoreRest(piki), nullptr);
}

/*
 * --INFO--
 * Address:	800AACFC
 * Size:	0000F4
 */
void ActBoreSelect::init(Creature* creature)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, mPiki), PaniMotionInfo(PIKIANIM_Wait));
	mActionTimer   = 2.0f + gsys->getFrameTime();
	mIsTimerActive = 1;
	mCurrActionIdx = CHILD_NULL;

	_1C                  = PI * (gsys->getRand(1.0f) - 0.5f) / 3.0f;
	mIsChildActionActive = 0;
	mStop                = 0;
}

/*
 * --INFO--
 * Address:	800AADF0
 * Size:	00000C
 */
void ActBoreSelect::stop()
{
	mStop = 1;
}

/*
 * --INFO--
 * Address:	800AADFC
 * Size:	000184
 */
int ActBoreSelect::exec()
{
	if (mIsChildActionActive) {
		return mChildActions[mCurrActionIdx].mAction->exec();
	}

	if (mPiki->mNavi->mNeutralTime < 1.0f || mStop) {
		if (mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == 3) {
			return ACTOUT_Success;
		}

		if (mCurrActionIdx == CHILD_BoreRest) {
			static_cast<ActBoreRest*>(mChildActions[mCurrActionIdx].mAction)->finishRest();
			mIsChildActionActive = true;
			return ACTOUT_Continue;
		}

		if (mCurrActionIdx == CHILD_BoreOneshot) {
			static_cast<ActBoreOneshot*>(mChildActions[mCurrActionIdx].mAction)->finish();
			mIsChildActionActive = true;
			return ACTOUT_Continue;
		}
		return ACTOUT_Success;
	}

	if (mIsTimerActive) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mActionTimer -= gsys->getFrameTime();
		if (mActionTimer < 0.0f) {
			determine();
		}
	} else {
		if (mChildActions[mCurrActionIdx].mAction->exec()) {
			init(nullptr);
		}
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AAF80
 * Size:	000004
 */
void ActBoreSelect::cleanup()
{
}

/*
 * --INFO--
 * Address:	800AAF84
 * Size:	000078
 */
void ActBoreSelect::procTargetMsg(Piki* piki, MsgTarget* msg)
{
	if (mIsTimerActive) {
		mIsTimerActive = 0;
		mCurrActionIdx = CHILD_Watch;
		mChildActions[mCurrActionIdx].initialise(msg->mTarget);
		return;
	}

	if (mCurrActionIdx == CHILD_BoreTalk) {
		ActBoreTalk* boreTalk             = static_cast<ActBoreTalk*>(mChildActions[mCurrActionIdx].mAction);
		boreTalk->mIsLookHandledElsewhere = 0;
		boreTalk->mTarget                 = msg->mTarget;
	}
}

/*
 * --INFO--
 * Address:	800AAFFC
 * Size:	0000BC
 */
void ActBoreSelect::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	if (mCurrActionIdx != CHILD_NULL) {
		mChildActions[mCurrActionIdx].mAction->procAnimMsg(piki, msg);
		return;
	}

	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		break;
	}
}

/*
 * --INFO--
 * Address:	800AB0B8
 * Size:	0002D8
 */
void ActBoreSelect::determine()
{
	if (gsys->getRand(1.0f) > 0.5f) {
		mActionTimer = 2.0f + gsys->getFrameTime();
		return;
	}

	Choice choices[CHILD_COUNT] = {
		{ CHILD_Watch, 0.1f },
		{ CHILD_BoreTalk, 0.5f },
		{ CHILD_BoreOneshot, 0.3f },
		{ CHILD_BoreRest, 0.1f },
	};

	int randIdx = selectRandomly(choices, CHILD_COUNT);

	if (mPiki->mGrabbedCreature.mPtr) {
		randIdx = CHILD_Watch;
	}

	Creature* target;
	Creature* nearestItem;
	Creature* nearestNavi;
	Creature* nearestTeki;
	Creature* nearestBoss;
	mIsTimerActive = false;
	mCurrActionIdx = randIdx;
	target         = nullptr;
	switch (randIdx) {
	case CHILD_Watch:

		nearestTeki = (tekiMgr) ? tekiMgr->findClosest(mPiki->mPosition, nullptr) : nullptr;

		nearestItem = itemMgr->findClosest(mPiki->mPosition, nullptr);
		nearestNavi = naviMgr->findClosest(mPiki->mPosition, nullptr);

		nearestBoss = (bossMgr) ? bossMgr->findClosest(mPiki->mPosition, nullptr) : nullptr;

		if (nearestBoss) {
			target = nearestBoss;
			break;
		}

		// these are probably not distances, rename later
		f32 enemySpeed = (nearestTeki) ? nearestTeki->mVelocity.length() : 0.0f;
		f32 itemSpeed  = (nearestItem) ? nearestItem->mVelocity.length() : 0.0f;
		f32 naviSpeed  = (nearestNavi) ? nearestNavi->mVelocity.length() : 0.0f;

		if (enemySpeed > itemSpeed && enemySpeed > naviSpeed) {
			target = nearestTeki;
			break;
		}

		if (itemSpeed > naviSpeed) {
			target = nearestItem;
			break;
		}

		target = nearestNavi;
		break;
	case CHILD_BoreTalk:
		break;
	}

	mChildActions[mCurrActionIdx].initialise(target);

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800AB390
 * Size:	000080
 */
ActBoreTalk::ActBoreTalk(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800AB410
 * Size:	0000E8
 */
void ActBoreTalk::init(Creature* creature)
{
	mIsAnimFinished         = false;
	mIsLookHandledElsewhere = 0;
	Iterator iter(&mPiki->mSearchBuffer);
	iter.first();
	mTarget = *iter;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Asibumi, this), PaniMotionInfo(PIKIANIM_Asibumi));
	mPiki->enableMotionBlend();

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800AB4F8
 * Size:	000214
 */
void ActBoreTalk::startTalk()
{
	Iterator iter(&mPiki->mSearchBuffer);
	mPiki->turnTo(mTarget->mPosition);

	CI_LOOP(iter)
	{
		Creature* c = *iter;
		c->stimulate(InteractTalk(mPiki));
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Chatting, this), PaniMotionInfo(PIKIANIM_Chatting));
	mPiki->enableMotionBlend();
	f32 r      = gsys->getRand(1.0f);
	mTalkTimer = 2.0f * r + 5.0f;

	if (mPiki->mMode != PikiMode::FormationMode) {
		return;
	}
	Navi* navi = mPiki->mNavi;
	if (!navi->mPlateMgr) {
		return;
	}

	if (navi->getCurrState()->getID() != NAVISTATE_DemoSunset && navi->getCurrState()->getID() != NAVISTATE_Dead) {
		seMgr->setPikiNum(0);
	}
}

/*
 * --INFO--
 * Address:	800AB70C
 * Size:	000128
 */
int ActBoreTalk::exec()
{
	if (!mTarget) {
		return ACTOUT_Fail;
	}

	if (mIsLookHandledElsewhere == 0) {
		Vector3f dir          = mTarget->mPosition - mPiki->mPosition;
		f32 ang               = atan2f(dir.x, dir.z);
		ang                   = angDist(ang, mPiki->mFaceDirection);
		mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.1f * ang);

		if (quickABS(ang) < 0.1f) {
			mIsLookHandledElsewhere = 1;
			startTalk();
		}
	}

	if (mIsAnimFinished) {
		return ACTOUT_Success;
	}

	mTalkTimer -= gsys->getFrameTime();
	if (mTalkTimer < 0.0f) {
		mPiki->mPikiAnimMgr.finishMotion(this);
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AB834
 * Size:	000004
 */
void ActBoreTalk::cleanup()
{
}

/*
 * --INFO--
 * Address:	800AB838
 * Size:	000024
 */
void ActBoreTalk::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (mIsLookHandledElsewhere && event.mEventType == KEY_Finished) {
		mIsAnimFinished = true;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
ActBoreListen::ActBoreListen(Piki* piki)
    : Action(piki, true)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AB85C
 * Size:	000004
 */
void ActBoreListen::init(Creature*)
{
}

/*
 * --INFO--
 * Address:	800AB860
 * Size:	000008
 */
int ActBoreListen::exec()
{
	return 0;
}

/*
 * --INFO--
 * Address:	800AB868
 * Size:	000004
 */
void ActBoreListen::cleanup()
{
}

/*
 * --INFO--
 * Address:	800AB86C
 * Size:	000004
 */
void ActBoreListen::procAnimMsg(Piki*, MsgAnim*)
{
}

/*
 * --INFO--
 * Address:	800AB870
 * Size:	000080
 */
ActBoreOneshot::ActBoreOneshot(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800AB8F0
 * Size:	000038
 */
void ActBoreOneshot::finish()
{
	mPiki->mPikiAnimMgr.finishMotion(this);
}

/*
 * --INFO--
 * Address:	800AB928
 * Size:	0000E0
 */
void ActBoreOneshot::init(Creature* creature)
{
	mIsAnimFinished   = false;
	Choice choices[4] = {
		{ PIKIANIM_Akubi, 0.35f },
		{ PIKIANIM_Rinbow, 0.35f },
		{ PIKIANIM_Sagasu2, 0.2f },
		{ PIKIANIM_Iraira, 0.1f },
	};

	int randAnim = selectRandomly(choices, 4);

	mPiki->startMotion(PaniMotionInfo(randAnim, this), PaniMotionInfo(randAnim));
}

/*
 * --INFO--
 * Address:	800ABA08
 * Size:	00001C
 */
int ActBoreOneshot::exec()
{
	if (mIsAnimFinished) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800ABA24
 * Size:	000004
 */
void ActBoreOneshot::cleanup()
{
}

/*
 * --INFO--
 * Address:	800ABA28
 * Size:	000018
 */
void ActBoreOneshot::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (event.mEventType == KEY_Finished) {
		mIsAnimFinished = true;
	}
}

/*
 * --INFO--
 * Address:	800ABA40
 * Size:	000080
 */
ActBoreRest::ActBoreRest(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800ABAC0
 * Size:	00008C
 */
void ActBoreRest::init(Creature* creature)
{
	mRestState = 0;
	sitDown();
	mRestTimer      = 5.0f + (4.0f * gsys->getRand(1.0f));
	mIsAnimFinished = mForceComplete = 0;
	mIsFinished                      = 0;
}

/*
 * --INFO--
 * Address:	800ABB4C
 * Size:	0000E8
 */
void ActBoreRest::sitDown()
{
	switch (mRestState) {
	case 0:
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, this), PaniMotionInfo(PIKIANIM_Suwaru));
		mRestState = 1;
		break;
	case 1:
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Neru, this), PaniMotionInfo(PIKIANIM_Neru));
		mRestState = 3;
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void ActBoreRest::standUp()
{
	switch (mRestState) {
	case 1:
		mPiki->mPikiAnimMgr.finishMotion(this);
		mIsAnimFinished = 1;
		break;
	case 3:
		mPiki->mPikiAnimMgr.finishMotion(this);
		mIsAnimFinished = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800ABC34
 * Size:	0002E8
 */
int ActBoreRest::exec()
{
	if (mForceComplete) {
		return ACTOUT_Success;
	}

	if (mIsFinished) {
		if (!mIsAnimFinished) {
			if (mRestState >= 1) {
				standUp();
				return ACTOUT_Continue;
			}
			return ACTOUT_Success;
		}
		return ACTOUT_Continue;
	}

	mRestTimer -= gsys->getFrameTime();

	if (!mIsAnimFinished && mRestTimer < 0.0f) {
		if (mRestState <= 1 && gsys->getRand(1.0f) > 0.5f) {
			sitDown();
		} else if (mRestState >= 1) {
			standUp();
		}
		mRestTimer = 2.0f * gsys->getRand(1.0f) + 3.0f;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800ABF1C
 * Size:	000004
 */
void ActBoreRest::cleanup()
{
}

/*
 * --INFO--
 * Address:	800ABF20
 * Size:	000104
 */
void ActBoreRest::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		if (mIsAnimFinished) {
			switch (mRestState) {
			case 1:
				mIsAnimFinished = 0;
				mRestState      = 0;
				mForceComplete  = 1;
				break;
			case 3:
				mIsAnimFinished = 0;
				mRestState      = 1;
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, this), PaniMotionInfo(PIKIANIM_Suwaru));
				mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 30.0f;
				mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 30.0f;
				break;
			}
		}
		break;
	case KEY_LoopEnd:
		break;
	}
}
