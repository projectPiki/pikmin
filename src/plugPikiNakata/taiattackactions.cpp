#include "Tai/AttackActions.h"
#include "teki.h"
#include "TekiPersonality.h"
#include "TekiParameters.h"
#include "TekiConditions.h"
#include "Interactions.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "Stickers.h"
#include "PikiState.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("taiattackactions")

/*
 * --INFO--
 * Address:	80127604
 * Size:	0000AC
 */
bool TaiAttackableNaviPikiAction::act(Teki& teki)
{
	TekiAttackableCondition cond(&teki);
	Creature* naviPiki = teki.getClosestNaviPiki(cond, nullptr);
	if (!naviPiki) {
		return false;
	}

	teki.setCreaturePointer(0, naviPiki);

	// .
	STACK_PAD_VAR(2);

	return true;
}

/*
 * --INFO--
 * Address:	801276B0
 * Size:	00008C
 */
bool TaiAttackableNaviAction::act(Teki& teki)
{
	Navi* navi = naviMgr->getNavi();
	if (teki.attackableCreature(*navi)) {
		teki.setCreaturePointer(0, navi);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012773C
 * Size:	0000B8
 */
bool TaiAttackablePikiAction::act(Teki& teki)
{
	TekiAttackableCondition cond(&teki);
	Creature* nearest = pikiMgr->findClosest(teki.mPosition, &cond);
	if (!nearest) {
		return false;
	}

	teki.setCreaturePointer(0, nearest);
	// sigh
	STACK_PAD_VAR(2);
	return true;
}

/*
 * --INFO--
 * Address:	801277F4
 * Size:	000040
 */
void TaiAnimationSwallowingAction::start(Teki& teki)
{
	if (teki.getCreaturePointer(0)) {
		teki.setTekiOption(BTeki::TEKI_OPTION_INVINCIBLE);
	}
}

/*
 * --INFO--
 * Address:	80127844
 * Size:	000660
 */
bool TaiAnimationSwallowingAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		PRINT("TaiAnimationSwallowingAction::act:ACTION_0:%08x:\n", &teki);
		teki.flickUpper();
		Vector3f center;
		teki.outputHitCenter(center);

		TekiAndCondition andCond1(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickerCondition(&teki)));
		TekiAndCondition andCond2(&andCond1, &TekiNotCondition(&TekiPikiStateCondition(PIKISTATE_Flick)));
		TekiAndCondition andCond3(&andCond2, &TekiPositionSphereDistanceCondition(center, teki.getAttackHitRange()));

		int swallowPikiNum = 0;
		int numSlots       = 0;
		CollPart* mouth    = teki.mCollInfo->getSphere('slot');
		if (!mouth) {
			PRINT("TaiAnimationSwallowingAction::act:mouthPart==null:%08x\n", &teki);
		} else {
			numSlots = mouth->getChildCount();
		}

		InteractKill& kill = InteractKill(&teki, 0);
		bool check1        = false;
		Navi* navi         = naviMgr->getNavi();

		if (andCond3.satisfy(navi)) {
			navi->stimulate(InteractSwallow(&teki, nullptr, 0));
			check1 = true;
		}

		bool check2 = false;
		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Creature* piki = *iter;
			if (!piki) {
				PRINT("?TaiAnimationSwallowingAction::act:%08x:creature==null\n", &teki);
				break;
			}

			if (!andCond3.satisfy(piki)) {
				continue;
			}

			if (swallowPikiNum >= teki.getParameterI(TPI_SwallowCount)) {
				continue;
			}

			if (mouth && swallowPikiNum < numSlots) {
				PRINT("TaiAnimationSwallowingAction::act:ACTION_0:swallow:%08x:%08x,%d\n", &teki, piki, swallowPikiNum);
				piki->stimulate(InteractSwallow(&teki, mouth->getChildAt(swallowPikiNum++), 0));
			} else {
				piki->stimulate(kill);
				swallowPikiNum++;
			}
			check2 = true;
		}

		teki.clearTekiOption(BTeki::TEKI_OPTION_INVINCIBLE);
		if (check1) {
			if (check2) {
				teki.mActionStateId = 3;
			} else {
				teki.mActionStateId = 1;
			}
		} else {
			if (check2) {
				teki.mActionStateId = 2;
			} else {
				teki.mActionStateId = 0;
				return true;
			}
		}
	} else if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_1)) {
		Stickers stuckList(&teki);
		Iterator iter(&stuckList);
		CI_LOOP(iter)
		{
			Creature* stuck = *iter;
			PRINT("TaiAnimationSwallowingAction::act:ACTION_1:stick:%08x:%08x\n", &teki, stuck);
			PRINT("TaiAnimationSwallowingAction::act:ACTION_1:count:%08x:%d\n", &teki, stuckList.getCount());
			if (!stuck) {
				PRINT("?TaiAnimationSwallowingAction::act:ANIMATION_KEY_OPTION_ACTION_1:%08x:creature==null\n", &teki);
				break;
			}

			if (stuck->isStickToMouth()) {
				PRINT("TaiAnimationSwallowingAction::act:ACTION_1:kill:%08x:%08x\n", &teki, stuck);
				stuck->stimulate(InteractKill(&teki, 0));
				iter.dec();
			}
		}
	}

	return false;

	// whatever man.
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiNotCondition(nullptr);
	TekiNotCondition(nullptr);
	TekiNotCondition(nullptr);
}

/*
 * --INFO--
 * Address:	80127EE4
 * Size:	00012C
 */
void TaiAnimationSwallowingAction::finish(Teki& teki)
{
	Stickers stuckList(&teki);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		PRINT("TaiAnimationSwallowingAction::finish:stick:%08x:%08x\n", &teki, stuck);
		if (!stuck) {
			PRINT("?TaiAnimationSwallowingAction::finish:%08x:creature==null\n", &teki);
			return;
		}

		if (stuck->isStickToMouth()) {
			PRINT("TaiAnimationSwallowingAction::finish:release:%08x:%08x\n", &teki, stuck);
			stuck->endStickMouth();
			iter.dec();
		}
	}
}

/*
 * --INFO--
 * Address:	80128010
 * Size:	000088
 */
bool TaiBangingAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity) {
		event.mOther->stimulate(InteractPress(event.mTeki, event.mTeki->getParameterF(TPF_AttackPower)));
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80128098
 * Size:	0000D4
 */
bool TaiFlickAction::act(Teki& teki)
{
	int pikiCount = teki.countPikis(TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiLowerRangeCondition(&teki)));
	return teki.mDamageCount >= f32(teki.getFlickDamageCount(pikiCount));

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8012816C
 * Size:	000028
 */
bool TaiTargetStickAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		return false;
	}

	return target->getStickObject() == &teki;
}

/*
 * --INFO--
 * Address:	80128194
 * Size:	000044
 */
void TaiFlickingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/*
 * --INFO--
 * Address:	801281D8
 * Size:	000034
 */
void TaiFlickingAction::finish(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/*
 * --INFO--
 * Address:	8012820C
 * Size:	00007C
 */
bool TaiFlickingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
		return true;
	}

	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		teki.flick();
		teki.mDamageCount = 0.0f;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80128288
 * Size:	000058
 */
bool TaiFlickingUpperAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		teki.flickUpper();
	}
	STACK_PAD_VAR(1);
	return TaiMotionAction::act(teki);
}
