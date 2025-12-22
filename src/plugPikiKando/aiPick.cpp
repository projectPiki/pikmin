#include "DebugLog.h"
#include "Interactions.h"
#include "ItemMgr.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("PickItem")

/**
 * @TODO: Documentation
 */
ActPickItem::ActPickItem(Piki* piki)
    : AndAction(piki)
{
	setName("pick item");
	setChildren(CHILD_COUNT,                //
	            new ActGoto(piki), nullptr, //
	            new ActPick(piki), nullptr  //
	);
	mTargetItem.clear();
}

/**
 * @TODO: Documentation
 */
Creature* ActPickItem::findItem()
{
	Iterator iter(itemMgr);
	f32 minDist           = 200.0f;
	Creature* closestItem = nullptr;
	CI_LOOP(iter)
	{
		Creature* item = *iter;
		if (roughCull(item, mPiki, minDist)) {
			continue;
		}

		if (item->mObjType == OBJTYPE_Bomb && item->isVisible() && !item->isGrabbed()) {
			f32 dist = qdist2(item, mPiki);
			if (dist < minDist) {
				minDist     = dist;
				closestItem = item;
			}
		}
	}

	return closestItem;
}

/**
 * @TODO: Documentation
 */
void ActPickItem::init(Creature* target)
{
	mPiki->mActionState = 0;
	if (!target) {
		target = findItem();
	}

	if (target) {
		mTargetItem.set(target);
		AndAction::init(target);
		PRINT(" set target to %x\n", target);
	} else {
		mTargetItem.reset();
	}
}

/**
 * @TODO: Documentation
 */
int ActPickItem::exec()
{
	if (mPiki->isHolding()) {
		mPiki->mActionState = 0;
		mPiki->mEmotion     = PikiEmotion::Victorious;
		return ACTOUT_Success;
	}

	Creature* bomb = mTargetItem.getPtr();
	if (mTargetItem.isNull()) {
		PRINT("PICKEE IS NULL!\n");
		return ACTOUT_Fail;
	}

	if (!bomb->isVisible()) {
		PRINT("BOMB IS NOT VISIBLE\n");
		return ACTOUT_Fail;
	}

	if (bomb->getHolder() && bomb->getHolder() != mPiki) {
		PRINT("BOMB HOLDER IS NOT ME (%x) ME IS %x\n", bomb->getHolder(), mPiki);
		mPiki->mEmotion = PikiEmotion::Searching;
		return ACTOUT_Fail;
	}

	int res = AndAction::exec();
	if (res == ACTOUT_Fail) {
		init(nullptr);
		return ACTOUT_Continue;
	}
	return res;
}

/**
 * @TODO: Documentation
 */
void ActPickItem::cleanup()
{
	PRINT("### piki is%sholding\n", mPiki->isHolding() ? " " : " not ");
	mTargetItem.reset();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
ActFlower::ActFlower(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @TODO: Documentation
 */
void ActFlower::init(Creature*)
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mFSM->transit(mPiki, PIKISTATE_UNUSED32);
	mIsAnimationComplete = false;
	if (!mPiki->isHolding()) {
		mIsCarryEmpty = true;
		return;
	}

	mIsCarryEmpty = false;
	if (mPiki->mFloweringTimer + 1 >= C_PIKI_PROP(mPiki).mFlowerEnergyRequirement()) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp2, this), PaniMotionInfo(PIKIANIM_GrowUp2));
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, this), PaniMotionInfo(PIKIANIM_GrowUp1));
	}

	mElapsedTime = 0.0f;
}

/**
 * @TODO: Documentation
 */
void ActFlower::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		Creature* held = mPiki->getHoldCreature();
		held->stimulate(InteractRelease(mPiki, 1.0f));
		held->kill(false);
		mPiki->mFloweringTimer++;
		if (mPiki->mFloweringTimer >= C_PIKI_PROP(mPiki).mFlowerEnergyRequirement()) {
			mPiki->setFlower(Flower);
			if (mPiki->mFloweringTimer > 100) {
				mPiki->mFloweringTimer = 100;
			}
		} else if (mPiki->mFloweringTimer >= C_PIKI_PROP(mPiki).mBudEnergyRequirement()) {
			mPiki->setFlower(Bud);
		}
		break;
	case KEY_Finished:
		mIsAnimationComplete = true;
		break;
	}
}

/**
 * @TODO: Documentation
 */
void ActFlower::cleanup()
{
	mPiki->mFSM->transit(mPiki, PIKISTATE_Normal);
}

/**
 * @TODO: Documentation
 */
int ActFlower::exec()
{
	if (mIsCarryEmpty) {
		return ACTOUT_Fail;
	}

	mElapsedTime += gsys->getFrameTime();

	Creature* heldItem = mPiki->getHoldCreature();
	if (heldItem) {
		// The iconic nectar drinking animation
		f32 shrinkScale = (1.0f - mElapsedTime / 1.0f) * 0.3f;
		heldItem->mSRT.s.set(shrinkScale, shrinkScale, shrinkScale);
	}

	if (mIsAnimationComplete) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}
