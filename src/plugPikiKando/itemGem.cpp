#include "BaseInf.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "GemItem.h"
#include "GlobalGameOptions.h"
#include "Stickers.h"
#include "jaudio/pikiinter.h"

// theres a lot more to this
GemTable table[5] = {
	{ 1, 3, 1, 2, 1, 0, 16.0f },      { 5, 10, 5, 5, 3, 5, 32.0f },    { 10, 20, 10, 10, 6, 2, 48.0f },
	{ 20, 50, 20, 20, 10, 0, 64.0f }, { 50, 200, 50, 0, 0, 0, 16.0f },
};

// Only four?  That seems like a bug...  Was the 50 pellet already cut so early?
// Linker Map says this was 0x10 bytes large, and this is the data structure directly following `table` in the memory of the DLL.
f32 gemSpeedScales[4] = { 2.0f, 1.5f, 1.2f, 1.0f };

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("gemItem")

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
bool GemItem::ignoreAtari(Creature* creature)
{
	if (creature->getStickObject() == this) {
		return true;
	}
	if (creature->mObjType == OBJTYPE_GemItem && mIsFree) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030 (Matching by size)
 */
void GemItem::setAtariFree()
{
	mIsFree = true;
	playEventSound(this, SE_PELLET_BORN);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054 (Matching by size)
 */
void GemItem::bounceCallback()
{
	if (mIsFree) {
		effectMgr->create(EffectMgr::EFF_BigDustRing, mSRT.t, nullptr, nullptr);
	}
	mIsFree = false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000108 (Matching by size)
 */
GemItem::GemItem(CreatureProp* props, int gemType, Shape** shapes, Shape**, Shape**, SimpleAI* ai, f32 sizeScale, int, int)
    : ItemCreature(OBJTYPE_GemItem, props, nullptr)
    , mGemCollInfo(0)
{
	mGemType         = gemType;
	mColor           = 0;
	mItemShapeObject = itemMgr->getPelletShapeObject(mColor, gemType);
	mStateMachine    = ai;
	mSizeScale       = sizeScale;

	const GemTable& tableEntry = table[mGemType];

	mGemNumber        = tableEntry.mGemNumber;
	mMaxStickers      = tableEntry.mMaxCarry;
	mMinStickers      = tableEntry.mMinCarry;
	mMatchingSeeds    = tableEntry.mMatchingSeeds;
	mNonMatchingSeeds = tableEntry.mNonMatchingSeeds;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068 (Matching by size)
 */
void GemItem::initParam(int type)
{
	setColorType(type);

	const GemTable& tableEntry = table[mGemType];

	mGemNumber        = tableEntry.mGemNumber;
	mMaxStickers      = tableEntry.mMaxCarry;
	mMinStickers      = tableEntry.mMinCarry;
	mMatchingSeeds    = tableEntry.mMatchingSeeds;
	mNonMatchingSeeds = tableEntry.mNonMatchingSeeds;
}

/**
 * @todo: Documentation
 */
void GemItem::setColorType(int color)
{
	mColor = color;
	if (color >= PikiColorCount) {
		color = gsys->getRand(1.0f) * f32(PikiColorCount);
		if (color >= PikiColorCount) {
			color = Blue;
		}
	}
	mColor = color;

	if (mGemType < 0 || mGemType >= 5) {
		PRINT("illegal gem type !\n", mGemType);
		mGemType = 0;
	}
	mItemShapeObject = itemMgr->getPelletShapeObject(mColor, mGemType);

	if (mItemShapeObject) {
		mItemAnimator.init(&mItemShapeObject->mAnimContext, mItemShapeObject->mAnimMgr, itemMgr->mItemMotionTable);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000FC (Matching by size)
 */
void GemItem::startAI(int)
{
	mSeContext = &mGemSe;
	mSeContext->setContext(this, JACEVENT_Pellet);

	mCollInfo = &mGemCollInfo;
	mCollInfo->initInfo(mItemShapeObject->mShape, mGemColl, mCollInfoIDs);

	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mSRT.r.set(0.0f, mFaceDirection, 0.0f);
	enableGravity();
	C_SAI(this)->start(this, GemAI::GEM_Unk0);
	mIsAlive       = true;
	mIsBeingLifted = false;
	// Is this an idiom for something?
	startMotion(0);
	stopMotion();
	mIsRising    = false;
	mRouteTracer = nullptr;
	mIsFree      = false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000278 (Matching by size)
 */
void GemItem::update()
{
	f32 motionScl = 0.5f;

	if (mIsRising) {
		updateLiftup();
	}
	if (mColor == Red && mGemType == 1) {
		motionScl = 1.333333f;
	} else if (mColor == Yellow || mGemType == 2) {
		motionScl = 2.666666f;
	}
	ItemCreature::update();
	if (mStickListHead) {
		setMotionSpeed(mVelocity.length() * gemSpeedScales[mGemType] * motionScl);
		if (getMotionSpeed() > 1000.0f) {
			PRINT("motionSpeed = %f : vel(%.1f %.1f %.1f) : getSpeedScl %.1f motionScl %.1f\n", getMotionSpeed(), mVelocity.x, mVelocity.y,
			      mVelocity.z, gemSpeedScales[mGemType], motionScl);
		}
	} else if (getCurrState()->getID() == GemAI::GEM_Rise) {
		mIsAlive = false;
		setMotionSpeed(210.0f);
	} else {
		stopMotion();
		if (mIsBeingLifted) {
			stopEventSound(this, SE_LIFT_MOVE);
			stopEventSound(this, SE_LIFT_TRY);
			finishPick();
		}
		enableGravity();
		if (isCreatureFlag(CF_IsOnGround)) {
			mVelocity = mVelocity * 0.9f;
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050 (Matching by size)
 */
bool GemItem::reachCapacity()
{
	Stickers stick(this);
	if (stick.getNumStickers() >= mMaxStickers) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00019C (Matching by size)
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
	mSRT.t.y += mCurrentHeight - prevHeight;

	Stickers stick(this);
	Iterator it(&stick);
	CI_LOOP(it)
	{
		(*it)->mAttachPosition.y -= mCurrentHeight - prevHeight;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098 (Matching by size)
 */
void GemItem::startPick(f32 val)
{
	startMotion(0);
	setMotionSpeed(30.0f);
	setFree(false);
	mTargetHeight  = val;
	mCurrentHeight = 0.0f;
	mIsRising      = true;
	mVelocity.y    = 0.0f;
	enableGroundOffset(0.0f);
	mIsBeingLifted = true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
void GemItem::finishPick()
{
	PRINT("FINISH PICK ++++++++++++++\n");
	mIsRising     = false;
	mTargetHeight = 0.0f;
	disableGroundOffset();
	setFree(true);
	mIsBeingLifted = false;
	resetCreatureFlag(CF_IsFlying);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018 (Matching by size)
 */
f32 GemItem::getSize()
{
	return mSizeScale * 41.0f / 0.4f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
f32 GemItem::getiMass()
{
	return 0.0f;
}

/**
 * @todo: Documentation
 */
void GemItem::split()
{
	if (!mIsAlive) {
		return;
	}

	int splitAmount = table[mGemType].mSplitAmount;
	if (splitAmount > 0) {
		PRINT("gem type %d split !\n", mGemType);
		mIsAlive = false;
		kill(false);
		int objType;
		if (mGemType == 1) {
			objType = OBJTYPE_Gem1;
		} else {
			objType = OBJTYPE_Gem5;
		}

		for (int i = 0; i < splitAmount; i++) {
			Creature* obj = itemMgr->birth(objType);
			Vector3f pos  = mSRT.t;
			mSRT.t.y += 10.0f;

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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048 (Matching by size)
 */
void GemItem::refresh(Graphics& gfx)
{
	ItemCreature::refresh(gfx);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014 (Matching by size)
 */
void GemItem::doStore(CreatureInf* inf)
{
	inf->mObjInfo1 = mGemType;
	inf->mObjInfo2 = mColor;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000064 (Matching by size)
 */
void GemItem::doRestore(CreatureInf* inf)
{
	mGemType = inf->mObjInfo1;
	mColor   = inf->mObjInfo2;
	initParam(mColor);
	startAI(0);
	PRINT("DO RESTORE END ****\n");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000038 (Matching by size)
 */
void GemItem::doKill()
{
	mSeContext->releaseEvent();
	ItemCreature::doKill();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
bool GemItem::isAlive()
{
	return mIsAlive;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void GemItem::setRouteTracer(RouteTracer* routeTracer)
{
	mRouteTracer = routeTracer;
}
