#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Interactions.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "Stickers.h"
#include "Tai/AttackActions.h"
#include "TekiConditions.h"
#include "TekiParameters.h"
#include "TekiPersonality.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taiattackactions")

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
bool TaiAttackablePikiAction::act(Teki& teki)
{
	TekiAttackableCondition cond(&teki);
	Creature* nearest = pikiMgr->findClosest(teki.mSRT.t, &cond);
	if (!nearest) {
		return false;
	}

	teki.setCreaturePointer(0, nearest);
	// sigh
	STACK_PAD_VAR(2);
	return true;
}

/**
 * @todo: Documentation
 */
void TaiAnimationSwallowingAction::start(Teki& teki)
{
	if (teki.getCreaturePointer(0)) {
		teki.setTekiOption(BTeki::TEKI_OPTION_INVINCIBLE);
	}
}

/**
 * @todo: Documentation
 */
bool TaiAnimationSwallowingAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		PRINT_NAKATA("TaiAnimationSwallowingAction::act:ACTION_0:%08x:\n", &teki);
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
			PRINT_NAKATA("TaiAnimationSwallowingAction::act:mouthPart==null:%08x\n", &teki);
		} else {
			numSlots = mouth->getChildCount();
		}

		InteractKill NRef kill = InteractKill(&teki, 0);
		bool check1            = false;
		Navi* navi             = naviMgr->getNavi();

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
				PRINT_NAKATA("TaiAnimationSwallowingAction::act:ACTION_0:swallow:%08x:%08x,%d\n", &teki, piki, swallowPikiNum);
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
			PRINT_NAKATA("TaiAnimationSwallowingAction::act:ACTION_1:stick:%08x:%08x\n", &teki, stuck);
			PRINT_NAKATA("TaiAnimationSwallowingAction::act:ACTION_1:count:%08x:%d\n", &teki, stuckList.getNumStickers());
			if (!stuck) {
				PRINT("?TaiAnimationSwallowingAction::act:ANIMATION_KEY_OPTION_ACTION_1:%08x:creature==null\n", &teki);
				break;
			}

			if (stuck->isStickToMouth()) {
				PRINT_NAKATA("TaiAnimationSwallowingAction::act:ACTION_1:kill:%08x:%08x\n", &teki, stuck);
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

/**
 * @todo: Documentation
 */
void TaiAnimationSwallowingAction::finish(Teki& teki)
{
	Stickers stuckList(&teki);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		PRINT_NAKATA("TaiAnimationSwallowingAction::finish:stick:%08x:%08x\n", &teki, stuck);
		if (!stuck) {
			PRINT("?TaiAnimationSwallowingAction::finish:%08x:creature==null\n", &teki);
			return;
		}

		if (stuck->isStickToMouth()) {
			PRINT_NAKATA("TaiAnimationSwallowingAction::finish:release:%08x:%08x\n", &teki, stuck);
			stuck->endStickMouth();
			iter.dec();
		}
	}
}

/**
 * @todo: Documentation
 */
bool TaiBangingAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity) {
		event.mOther->stimulate(InteractPress(event.mTeki, event.mTeki->getParameterF(TPF_AttackPower)));
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool TaiFlickAction::act(Teki& teki)
{
	int pikiCount = teki.countPikis(TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiLowerRangeCondition(&teki)));
	return teki.mDamageCount >= f32(teki.getFlickDamageCount(pikiCount));

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/**
 * @todo: Documentation
 */
bool TaiTargetStickAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		return false;
	}

	return target->getStickObject() == &teki;
}

/**
 * @todo: Documentation
 */
void TaiFlickingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @todo: Documentation
 */
void TaiFlickingAction::finish(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
bool TaiFlickingUpperAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		teki.flickUpper();
	}
	STACK_PAD_VAR(1);
	return TaiMotionAction::act(teki);
}
