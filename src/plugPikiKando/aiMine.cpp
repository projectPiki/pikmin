#include "BombItem.h"
#include "DebugLog.h"
#include "Interactions.h"
#include "ItemObject.h"
#include "PikiAI.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(13)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 */
ActMine::ActMine(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @TODO: Documentation
 */
void ActMine::init(Creature* target)
{
	mPiki->mActionState = 0;
	if (target->mObjType != OBJTYPE_BombGen) {
		ERROR("THIS IS NOT BOMB GEN (%s)!\n", ObjType::getName(target->mObjType));
	}

	mBombGen = static_cast<BombGenItem*>(target);
	initWatch();
	mState = STATE_Watch;
}

/**
 * @TODO: Documentation
 */
void ActMine::initWatch()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, this), PaniMotionInfo(PIKIANIM_Sagasu2));
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
int ActMine::exeWatch()
{
	return ACTOUT_Continue;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000E8
 */
int ActMine::exeGo()
{
	Vector3f dir = mBombGen->mSRT.t - mPiki->mSRT.t;
	f32 dist     = dir.normalise();
	if (dist < 15.0f) {
		initMine();
		mState = STATE_Mine;
	} else {
		mPiki->setSpeed(0.7f, dir);
	}

	return ACTOUT_Continue;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
void ActMine::initMine()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
	mPiki->enableMotionBlend();
	mIsMineActionReady = false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
void ActMine::initGo()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/**
 * @TODO: Documentation
 */
int ActMine::exeMine()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (!mIsMineActionReady) {
		return ACTOUT_Continue;
	}

	if (!mBombGen->pick()) {
		return ACTOUT_Fail;
	}

	BombItem* bomb = static_cast<BombItem*>(itemMgr->birth(OBJTYPE_Bomb));
	if (bomb) {
		PRINT("new bomb = %x\n", bomb);
		bomb->init(mPiki->mSRT.t);
		bomb->startAI(0);
		bomb->dump();
		if (!bomb->stimulate(InteractGrab(mPiki))) {
			PRINT("piki%x BOMB PICK FAILED\n", mPiki);
			return ACTOUT_Fail;
		}

		mPiki->mEmotion = PikiEmotion::Victorious;
		return ACTOUT_Success;
	}

	mPiki->mEmotion = PikiEmotion::Sad;
	return ACTOUT_Fail;
}

/**
 * @TODO: Documentation
 */
int ActMine::exec()
{
	if (!mBombGen) {
		return ACTOUT_Fail;
	}

	if (!mBombGen->pickable()) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	if (mPiki->isHolding()) {
		mPiki->mEmotion = PikiEmotion::Victorious;
		return ACTOUT_Success;
	}

	int res = ACTOUT_Continue;
	switch (mState) {
	case STATE_Watch:
		res = exeWatch();
		break;
	case STATE_Go:
		res = exeGo();
		break;
	case STATE_Mine:
		res = exeMine();
		break;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
void ActMine::cleanup()
{
}

/**
 * @TODO: Documentation
 */
void ActMine::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		if (mState == STATE_Watch) {
			initGo();
			mState = STATE_Go;
		}
		break;
	case KEY_Action0:
		if (mState == STATE_Mine) {
			mIsMineActionReady = true;
		}
		break;
	}
}
