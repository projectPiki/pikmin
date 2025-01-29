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
	_18.clear();
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
		_18.set(target);
		AndAction::init(target);
		PRINT(" set target to %x\n", target);
	} else {
		_18.reset();
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

	Creature* item = _18.getPtr();
	if (_18.isNull()) {
		PRINT("PICKEE IS NULL!\n");
		return ACTOUT_Fail;
	}

	if (!item->isVisible()) {
		PRINT("BOMB IS NOT VISIBLE\n");
		return ACTOUT_Fail;
	}

	if (item->getHolder() && item->getHolder() != mPiki) {
		PRINT("BOMB HOLDER IS NOT ME (%x) ME IS %x\n", item->getHolder(), mPiki);
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

	_18.reset();
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
	_1C = 0;
	if (!mPiki->isHolding()) {
		_1D = 1;
		return;
	}

	_1D = 0;
	if (mPiki->_514 + 1 >= C_PIKI_PROP(mPiki).mFlowerEnergyRequirement()) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp2, this), PaniMotionInfo(PIKIANIM_GrowUp2));
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, this), PaniMotionInfo(PIKIANIM_GrowUp1));
	}

	_18 = 0.0f;
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
		mPiki->_514++;
		if (mPiki->_514 >= C_PIKI_PROP(mPiki).mFlowerEnergyRequirement()) {
			mPiki->setFlower(Flower);
			if (mPiki->_514 > 100) {
				mPiki->_514 = 100;
			}
		} else if (mPiki->_514 >= C_PIKI_PROP(mPiki).mBudEnergyRequirement()) {
			mPiki->setFlower(Bud);
		}
		break;
	case KEY_Finished:
		_1C = 1;
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
	if (_1D) {
		return ACTOUT_Fail;
	}

	_18 += gsys->getFrameTime();

	Creature* held = mPiki->getHoldCreature();
	if (held) {
		f32 scale = (1.0f - _18 / 1.0f) * 0.3f;
		held->mScale.set(scale, scale, scale);
	}

	if (_1C) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}
