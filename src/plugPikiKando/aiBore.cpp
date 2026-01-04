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

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 */
ActFreeSelect::ActFreeSelect(Piki* piki)
    : Action(piki, true)
{
	setName("freebore");
	setChildren(CHILD_COUNT,                       //
	            new ActWatch(piki), nullptr,       //
	            new ActBoreTalk(piki), nullptr,    //
	            new ActBoreOneshot(piki), nullptr, //
	            new ActBoreRest(piki), nullptr     //
	);
}

/**
 * @todo: Documentation
 */
void ActFreeSelect::init(Creature* creature)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, mPiki), PaniMotionInfo(PIKIANIM_Wait));
	mActionTimer   = 2.0f + gsys->getFrameTime();
	mIsTimerActive = true;
	mCurrActionIdx = CHILD_NULL;

	_1C                  = PI * (gsys->getRand(1.0f) - 0.5f) / 3.0f;
	mIsChildActionActive = false;
	mIsFinished          = false;
}

/**
 * @todo: Documentation
 */
void ActFreeSelect::finishRest()
{
	switch (mCurrActionIdx) {
	case CHILD_BoreRest:
	{
		static_cast<ActBoreRest*>(mChildActions[mCurrActionIdx].mAction)->finishRest();
		mIsChildActionActive = true;
		break;
	}
	case CHILD_BoreOneshot:
	{
		static_cast<ActBoreOneshot*>(mChildActions[mCurrActionIdx].mAction)->finish();
		mIsChildActionActive = true;
		break;
	}
	default:
	{
		mIsFinished = true;
		break;
	}
	}
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void ActFreeSelect::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActFreeSelect::procTargetMsg(Piki* piki, MsgTarget* msg)
{
	if (mIsTimerActive) {
		mIsTimerActive = false;
		mCurrActionIdx = CHILD_Watch;
		mChildActions[mCurrActionIdx].initialise(msg->mTarget);
		return;
	}

	if (mCurrActionIdx == CHILD_BoreTalk) {
		ActBoreTalk* boreTalk             = static_cast<ActBoreTalk*>(mChildActions[mCurrActionIdx].mAction);
		boreTalk->mIsLookHandledElsewhere = FALSE;
		boreTalk->mTarget                 = msg->mTarget;
	}
}

/**
 * @todo: Documentation
 */
void ActFreeSelect::determine()
{
	if (gsys->getRand(1.0f) > 0.5f) {
		mActionTimer = 2.0f + gsys->getFrameTime();
		return;
	}

	immut Choice choices[CHILD_COUNT] = {
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
	{
		nearestTeki = (tekiMgr) ? tekiMgr->findClosest(mPiki->mSRT.t, nullptr) : nullptr;

		nearestItem = itemMgr->findClosest(mPiki->mSRT.t, nullptr);
		nearestNavi = naviMgr->findClosest(mPiki->mSRT.t, nullptr);

		if (bossMgr) {
			nearestBoss = bossMgr->findClosest(mPiki->mSRT.t, nullptr);
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
	}
	case CHILD_BoreTalk:
	{
		break;
	}
	}

	mChildActions[mCurrActionIdx].initialise(target);

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
ActBoreSelect::ActBoreSelect(Piki* piki)
    : Action(piki, true)
{
	setName("bore");
	setChildren(CHILD_COUNT,                       //
	            new ActWatch(piki), nullptr,       //
	            new ActBoreTalk(piki), nullptr,    //
	            new ActBoreOneshot(piki), nullptr, //
	            new ActBoreRest(piki), nullptr     //
	);
}

/**
 * @todo: Documentation
 */
void ActBoreSelect::init(Creature* creature)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, mPiki), PaniMotionInfo(PIKIANIM_Wait));
	mActionTimer   = 2.0f + gsys->getFrameTime();
	mIsTimerActive = true;
	mCurrActionIdx = CHILD_NULL;

	_1C                  = PI * (gsys->getRand(1.0f) - 0.5f) / 3.0f;
	mIsChildActionActive = false;
	mStop                = false;
}

/**
 * @todo: Documentation
 */
void ActBoreSelect::stop()
{
	mStop = true;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void ActBoreSelect::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActBoreSelect::procTargetMsg(Piki* piki, MsgTarget* msg)
{
	if (mIsTimerActive) {
		mIsTimerActive = false;
		mCurrActionIdx = CHILD_Watch;
		mChildActions[mCurrActionIdx].initialise(msg->mTarget);
		return;
	}

	if (mCurrActionIdx == CHILD_BoreTalk) {
		ActBoreTalk* boreTalk             = static_cast<ActBoreTalk*>(mChildActions[mCurrActionIdx].mAction);
		boreTalk->mIsLookHandledElsewhere = FALSE;
		boreTalk->mTarget                 = msg->mTarget;
	}
}

/**
 * @todo: Documentation
 */
void ActBoreSelect::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	if (mCurrActionIdx != CHILD_NULL) {
		mChildActions[mCurrActionIdx].mAction->procAnimMsg(piki, msg);
		return;
	}

	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
	{
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
void ActBoreSelect::determine()
{
	if (gsys->getRand(1.0f) > 0.5f) {
		mActionTimer = 2.0f + gsys->getFrameTime();
		return;
	}

	immut Choice choices[CHILD_COUNT] = {
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
	{
		nearestTeki = (tekiMgr) ? tekiMgr->findClosest(mPiki->mSRT.t, nullptr) : nullptr;

		nearestItem = itemMgr->findClosest(mPiki->mSRT.t, nullptr);
		nearestNavi = naviMgr->findClosest(mPiki->mSRT.t, nullptr);

		nearestBoss = (bossMgr) ? bossMgr->findClosest(mPiki->mSRT.t, nullptr) : nullptr;

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
	}
	case CHILD_BoreTalk:
	{
		break;
	}
	}

	mChildActions[mCurrActionIdx].initialise(target);

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
ActBoreTalk::ActBoreTalk(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @todo: Documentation
 */
void ActBoreTalk::init(Creature* creature)
{
	mIsAnimFinished         = false;
	mIsLookHandledElsewhere = FALSE;
	Iterator iter(&mPiki->mSearchBuffer);
	iter.first();
	mTarget = *iter;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Asibumi, this), PaniMotionInfo(PIKIANIM_Asibumi));
	mPiki->enableMotionBlend();

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void ActBoreTalk::startTalk()
{
	Iterator iter(&mPiki->mSearchBuffer);
	mPiki->turnTo(mTarget->mSRT.t);

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

/**
 * @todo: Documentation
 */
int ActBoreTalk::exec()
{
	if (!mTarget) {
		return ACTOUT_Fail;
	}

	if (!mIsLookHandledElsewhere) {
		Vector3f dir          = mTarget->mSRT.t - mPiki->mSRT.t;
		f32 ang               = atan2f(dir.x, dir.z);
		ang                   = angDist(ang, mPiki->mFaceDirection);
		mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.1f * ang);

		if (quickABS(ang) < 0.1f) {
			mIsLookHandledElsewhere = TRUE;
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

/**
 * @todo: Documentation
 */
void ActBoreTalk::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActBoreTalk::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	if (mIsLookHandledElsewhere && event.mEventType == KEY_Finished) {
		mIsAnimFinished = true;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
ActBoreListen::ActBoreListen(Piki* piki)
    : Action(piki, true)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void ActBoreListen::init(Creature*)
{
}

/**
 * @todo: Documentation
 */
int ActBoreListen::exec()
{
	return 0;
}

/**
 * @todo: Documentation
 */
void ActBoreListen::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActBoreListen::procAnimMsg(Piki*, MsgAnim*)
{
}

/**
 * @todo: Documentation
 */
ActBoreOneshot::ActBoreOneshot(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @todo: Documentation
 */
void ActBoreOneshot::finish()
{
	mPiki->mPikiAnimMgr.finishMotion(this);
}

/**
 * @todo: Documentation
 */
void ActBoreOneshot::init(Creature* creature)
{
	mIsAnimFinished         = false;
	immut Choice choices[4] = {
		{ PIKIANIM_Akubi, 0.35f },
		{ PIKIANIM_Rinbow, 0.35f },
		{ PIKIANIM_Sagasu2, 0.2f },
		{ PIKIANIM_Iraira, 0.1f },
	};

	int randAnim = selectRandomly(choices, 4);

	mPiki->startMotion(PaniMotionInfo(randAnim, this), PaniMotionInfo(randAnim));
}

/**
 * @todo: Documentation
 */
int ActBoreOneshot::exec()
{
	if (mIsAnimFinished) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBoreOneshot::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActBoreOneshot::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	if (event.mEventType == KEY_Finished) {
		mIsAnimFinished = true;
	}
}

/**
 * @todo: Documentation
 */
ActBoreRest::ActBoreRest(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @todo: Documentation
 */
void ActBoreRest::init(Creature* creature)
{
	mRestState = 0;
	sitDown();
	mRestTimer      = 5.0f + (4.0f * gsys->getRand(1.0f));
	mForceComplete  = false;
	mIsAnimFinished = false;
	mIsFinished     = false;
}

/**
 * @todo: Documentation
 */
void ActBoreRest::sitDown()
{
	switch (mRestState) {
	case 0:
	{
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, this), PaniMotionInfo(PIKIANIM_Suwaru));
		mRestState = 1;
		break;
	}
	case 1:
	{
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Neru, this), PaniMotionInfo(PIKIANIM_Neru));
		mRestState = 3;
		break;
	}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
void ActBoreRest::standUp()
{
	switch (mRestState) {
	case 1:
	{
		mPiki->mPikiAnimMgr.finishMotion(this);
		mIsAnimFinished = true;
		break;
	}
	case 3:
	{
		mPiki->mPikiAnimMgr.finishMotion(this);
		mIsAnimFinished = true;
		break;
	}
	}
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void ActBoreRest::cleanup()
{
}

/**
 * @todo: Documentation
 */
void ActBoreRest::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
	{
		if (mIsAnimFinished) {
			switch (mRestState) {
			case 1:
			{
				mIsAnimFinished = false;
				mRestState      = 0;
				mForceComplete  = true;
				break;
			}
			case 3:
			{
				mIsAnimFinished = false;
				mRestState      = 1;
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, this), PaniMotionInfo(PIKIANIM_Suwaru));
				mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 30.0f;
				mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 30.0f;
				break;
			}
			}
		}
		break;
	}
	case KEY_LoopEnd:
	{
		break;
	}
	}
}
