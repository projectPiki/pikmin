#include "BaseInf.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "GemItem.h"
#include "Stickers.h"

// theres a lot more to this
GemTable table[5] = {
	{ 1, 3, 1, 2, 1, 0, 16.0f },      { 5, 10, 5, 5, 3, 5, 32.0f },    { 10, 20, 10, 10, 6, 2, 48.0f },
	{ 20, 50, 20, 20, 10, 0, 64.0f }, { 50, 200, 50, 0, 0, 0, 16.0f },
};

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
DEFINE_PRINT("gemItem")

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
bool GemItem::ignoreAtari(Creature*)
{
	if (getStickObject()) {
		return true;
	}

	if (mObjType == OBJTYPE_GemItem && mIsFree) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GemItem::setAtariFree()
{
	mIsFree = true;
	playEventSound(this, SE_PELLET_BORN);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void GemItem::bounceCallback()
{
	if (mIsFree) {
		effectMgr->create(EffectMgr::EFF_BigDustRing, mPosition, nullptr, nullptr);
	}

	mIsFree = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
GemItem::GemItem(CreatureProp* props, int p2, Shape** shapes, Shape**, Shape**, SimpleAI* ai, f32 a1, int, int)
    : ItemCreature(p2, props, shapes[0])
    , mGemCollInfo(0)
{
	mGemType         = p2;
	mColor           = 0;
	mItemShapeObject = itemMgr->getPelletShapeObject(mColor, p2);
	mStateMachine    = ai;
	mSizeScale       = a1;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void GemItem::initParam(int type)
{
	setColorType(type);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4390
 * Size:	0000E4
 */
void GemItem::setColorType(int col)
{
	mColor = col;
	if (col >= 3) {
		col = gsys->getRand(1.0f) * 3.0f;
		if (col >= 3) {
			col = 0;
		}
	}
	mColor = col;

	if (mGemType < 0 || mGemType >= 5) {
		PRINT("illegal gem type !\n", mGemType);
		mGemType = 0;
	}
	mItemShapeObject = itemMgr->getPelletShapeObject(mColor, mGemType);

	if (mItemShapeObject) {
		mItemAnimator.init(&mItemShapeObject->mAnimContext, mItemShapeObject->mAnimMgr, itemMgr->mItemMotionTable);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void GemItem::startAI(int)
{
	mSeContext = &mGemSe;
	mSeContext->setContext(this, 2);
	mCollInfo = &mGemCollInfo;
	mGemCollInfo.initInfo(mItemShapeObject->mShape, mGemColl, nullptr);
	mScale.set(1.0f, 1.0f, 1.0f);
	mRotation.set(1.0f, mFaceDirection, 1.0f);
	resetCreatureFlag(CF_Unk8);
	C_SAI(this)->start(this, GemAI::GEM_Unk0);
	mIsBeingLifted = false;
	mIsRising      = false;
	playSound(0);
	// v func
	_3CC    = 0;
	mIsFree = 0;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000278
 */
void GemItem::update()
{
	// a lot of this is just estimating based on the dll

	if (mIsRising) {
		updateLiftup();
	}
	f32 motionScl;
	if (mColor == 1 && mGemType == 1) {
		motionScl = 1.333333f;
	} else {
		motionScl = 2.666666f;
	}
	ItemCreature::update();
	if (mStickListHead) {
		f32 speed = mVelocity.length();
		setMotionSpeed(speed * motionScl);
		f32 s = getMotionSpeed();
		if (s > 1000.0f) {
			PRINT("motionSpeed = %f : vel(%.1f %.1f %.1f) : getSpeedScl %.1f motionScl %.1f\n", getMotionSpeed(), mVelocity.x, mVelocity.y,
			      mVelocity.z, motionScl, motionScl);
		}
	} else {
		// some virtual func

		if (mCurrentState->getID()) {
			// some virtual func
			if (mIsBeingLifted) {
				stopEventSound(this, SE_LIFT_TRY);
				stopEventSound(this, SE_LIFT_MOVE);
				finishPick();
			}
			setCreatureFlag(CF_Unk8); // this is a further inline
			if (isCreatureFlag(CF_IsOnGround)) {
				mVelocity = mVelocity * 1.5f;
			}
		}
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
bool GemItem::reachCapacity()
{
	Stickers stick(this);
	return mMaxAttachedObjects < stick.getNumStickers();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00019C
 */
void GemItem::updateLiftup()
{
	f32 prevHeight = mCurrentHeight;
	mCurrentHeight += gsys->getFrameTime() * 3.333333f;
	if (mCurrentHeight > mTargetHeight) {
		mCurrentHeight = mTargetHeight;
		mIsRising      = false;
	}
	enableGroundOffset(mCurrentHeight);
	mPosition.y += mCurrentHeight - prevHeight;

	Stickers stick(this);
	Iterator it(nullptr);
	CI_LOOP(it)
	{
		Creature* obj          = *it;
		obj->mAttachPosition.y = obj->mAttachPosition.y - (mCurrentHeight - prevHeight);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void GemItem::startPick(f32 val)
{
	playSound(0);
	getCurrentMotionName();
	setFree(false);
	mTargetHeight  = val;
	mCurrentHeight = 0;
	mIsRising      = true;
	mVelocity.y    = 0.0f;
	enableGroundOffset(0.0f);
	mIsBeingLifted = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void GemItem::finishPick()
{
	PRINT("FINISH PICK ++++++++++++++\n");
	mIsRising     = 0;
	mTargetHeight = 0;
	disableGroundOffset();
	setFree(true);
	mIsBeingLifted = 0;
	resetCreatureFlag(CF_IsFlying);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
f32 GemItem::getSize()
{
	return 41.0f * mSizeScale / 0.4f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
f32 GemItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800E4474
 * Size:	0001FC
 */
void GemItem::split()
{
	if (!_3E4) {
		return;
	}

	int splitAmount = table[mGemType].mSplitAmount;
	if (splitAmount > 0) {
		PRINT("gem type %d split !\n", mGemType);
		_3E4 = 0;
		kill(false);
		int objType;
		if (mGemType == 1) {
			objType = OBJTYPE_Gem1;
		} else {
			objType = OBJTYPE_Gem5;
		}

		for (int i = 0; i < splitAmount; i++) {
			Creature* obj = itemMgr->birth(objType);
			Vector3f pos  = mPosition;
			mPosition.y += 10.0f;

			f32 angle      = 2.0f * (PI * gsys->getRand(1.0f));
			f32 vertSpeed  = 240.0f;
			f32 horizSpeed = 40.0f;

			Vector3f velocity(horizSpeed * sinf(angle), vertSpeed, horizSpeed * cosf(angle));

			if (obj) {
				obj->init(pos);
				obj->startAI(0);
				obj->initParam(mColor);
				obj->mVelocity = velocity;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GemItem::refresh(Graphics& gfx)
{
	ItemCreature::refresh(gfx);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GemItem::doStore(CreatureInf* inf)
{
	inf->mObjInfo1 = mGemType;
	inf->mObjInfo2 = mColor;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GemItem::doRestore(CreatureInf* inf)
{
	mGemType = inf->mObjInfo1;
	mColor   = inf->mObjInfo2;
	initParam(mColor);
	startAI(0);
	PRINT("DO RESTORE END ****\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void GemItem::doKill()
{
	mSeContext->releaseEvent();
	itemMgr->kill(this); // guess here because I cant tell from the dll
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool GemItem::isAlive()
{
	return true;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GemItem::setRouteTracer(RouteTracer*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4670
 * Size:	00000C
 */
void ItemCreature::finalSetup()
{
	_3C4 = true;
}
