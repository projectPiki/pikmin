#include "BombItem.h"
#include "DebugLog.h"
#include "Interactions.h"
#include "ItemObject.h"
#include "PikiAI.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(13)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800B92C0
 * Size:	000080
 */
ActMine::ActMine(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800B9340
 * Size:	000064
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

/*
 * --INFO--
 * Address:	800B93A4
 * Size:	000090
 */
void ActMine::initWatch()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, this), PaniMotionInfo(PIKIANIM_Sagasu2));
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
int ActMine::exeWatch()
{
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
int ActMine::exeGo()
{
	Vector3f dir = mBombGen->mPosition - mPiki->mPosition;
	f32 dist     = dir.normalise();
	if (dist < 15.0f) {
		initMine();
		mState = STATE_Mine;
	} else {
		mPiki->setSpeed(0.7f, dir);
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void ActMine::initMine()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
	mPiki->enableMotionBlend();
	mIsMineActionReady = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void ActMine::initGo()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800B9434
 * Size:	00014C
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
		bomb->init(mPiki->mPosition);
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

/*
 * --INFO--
 * Address:	800B9580
 * Size:	000200
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

/*
 * --INFO--
 * Address:	800B9780
 * Size:	000004
 */
void ActMine::cleanup()
{
}

/*
 * --INFO--
 * Address:	800B9784
 * Size:	0000C0
 */
void ActMine::animationKeyUpdated(PaniAnimKeyEvent& event)
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
