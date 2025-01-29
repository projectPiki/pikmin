#include "PikiAI.h"
#include "PikiState.h"
#include "PikiMgr.h"
#include "Interactions.h"
#include "ItemMgr.h"
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
DEFINE_PRINT("PickItem")

/*
 * --INFO--
 * Address:	800BCAFC
 * Size:	0000E0
 */
ActPickItem::ActPickItem(Piki* piki)
    : AndAction(piki)
{
	setName("pick item");
	setChildren(CHILD_COUNT, new ActGoto(piki), nullptr, new ActPick(piki), nullptr);
	mTargetItem.clear();
}

/*
 * --INFO--
 * Address:	800BCBDC
 * Size:	000180
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

/*
 * --INFO--
 * Address:	800BCD5C
 * Size:	0000B0
 */
void ActPickItem::init(Creature* target)
{
	mPiki->_408 = 0;
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

/*
 * --INFO--
 * Address:	800BCE0C
 * Size:	0000E8
 */
int ActPickItem::exec()
{
	if (mPiki->isHolding()) {
		mPiki->_408     = 0;
		mPiki->mEmotion = 6;
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
		mPiki->mEmotion = 7;
		return ACTOUT_Fail;
	}

	int res = AndAction::exec();
	if (res == ACTOUT_Fail) {
		init(nullptr);
		return ACTOUT_Continue;
	}
	return res;
}

/*
 * --INFO--
 * Address:	800BCEF4
 * Size:	000040
 */
void ActPickItem::cleanup()
{
	if (mPiki->isHolding()) {
		PRINT("### piki is%sholding\n", " ");
	} else {
		PRINT("### piki is%sholding\n", " not ");
	}

	mTargetItem.reset();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
ActFlower::ActFlower(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800BCF34
 * Size:	00015C
 */
void ActFlower::init(Creature*)
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mFSM->transit(mPiki, PIKISTATE_UNUSED32);
	mIsAnimationComplete = 0;
	if (!mPiki->isHolding()) {
		mIsCarryEmpty = 1;
		return;
	}

	mIsCarryEmpty = 0;
	if (mPiki->mFloweringTimer + 1 >= C_PIKI_PROP(mPiki).mFlowerEnergyRequirement()) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp2, this), PaniMotionInfo(PIKIANIM_GrowUp2));
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, this), PaniMotionInfo(PIKIANIM_GrowUp1));
	}

	mElapsedTime = 0.0f;
}

/*
 * --INFO--
 * Address:	800BD090
 * Size:	000120
 */
void ActFlower::animationKeyUpdated(PaniAnimKeyEvent& event)
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
		mIsAnimationComplete = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800BD1B0
 * Size:	000038
 */
void ActFlower::cleanup()
{
	mPiki->mFSM->transit(mPiki, PIKISTATE_Normal);
}

/*
 * --INFO--
 * Address:	800BD1E8
 * Size:	000074
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
		heldItem->mScale.set(shrinkScale, shrinkScale, shrinkScale);
	}

	if (mIsAnimationComplete) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}
