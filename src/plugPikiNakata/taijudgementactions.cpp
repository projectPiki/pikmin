#include "DebugLog.h"
#include "NaviMgr.h"
#include "Stickers.h"
#include "TAI/JudgementActions.h"
#include "TekiConditions.h"
#include "teki.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taijudgementactions")

/**
 * @TODO: Documentation
 */
bool TaiVisibleTargetAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiVisibleTargetAction::act:target==null:%08x\n", &teki);
		return false;
	}
	if (!teki.visibleCreature(*target)) {
		return false;
	}

	return true;
}

/**
 * @TODO: Documentation
 */
bool TaiContactTargetAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiContactTargetAction::act:target==null:%08x\n", &teki);
		return false;
	}
	if (!teki.contactCreature(*target)) {
		return false;
	}

	return true;
}

/**
 * @TODO: Documentation
 */
bool TaiSeparateTargetAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiSeparateTargetAction::act:target==null:%08x\n", &teki);
		return true;
	}
	if (!teki.separateCreature(*target)) {
		return false;
	}

	return true;
}

/**
 * @TODO: Documentation
 */
bool TaiTargetLostAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("TaiTargetLostAction::act:target==null:%08x\n", &teki);
		return true;
	}
	if (!teki.visibleCreature(*target)) {
		teki.clearCreaturePointer(0);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiOutsideTerritoryAction::act(Teki& teki)
{
	return teki.getTerritoryDistance() > mTerritoryRadius;
}

/**
 * @TODO: Documentation
 */
bool TaiInsideTerritoryAction::act(Teki& teki)
{
	return teki.getTerritoryDistance() <= mTerritoryRadius;
}

/**
 * @TODO: Documentation
 */
bool TaiTargetVisibleNaviPikiAction::act(Teki& teki)
{
	Creature* naviPiki = teki.getClosestNaviPiki(TekiVisibleCondition(&teki), nullptr);
	if (!naviPiki) {
		return false;
	}

	teki.setCreaturePointer(0, naviPiki);
	return true;

	TekiVisibleCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
bool TaiTargetVisibleNaviAction::act(Teki& teki)
{
	Creature* navi = naviMgr->findClosest(teki.getPosition(), &TekiAndCondition(&TekiVisibleCondition(&teki), &TekiNaviCondition()));
	if (!navi) {
		return false;
	}

	teki.setCreaturePointer(0, navi);
	return true;

	TekiNaviCondition();
	TekiVisibleCondition(nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/**
 * @TODO: Documentation
 */
bool TaiHasStickersInMouthAction::act(Teki& teki)
{
	Stickers stuckList(&teki);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (!stuck) {
			PRINT("?TaiHasStickersInMouthAction::act:%08x:creature==null\n", &teki);
			break;
		}
		if (stuck->isStickToMouth()) {
			return true;
		}
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiHasStickersOnBodyAction::act(Teki& teki)
{
	Stickers stuckList(&teki);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (!stuck) {
			PRINT("?TaiHasStickersOnBodyAction::act:%08x:creature==null\n", &teki);
			break;
		}
		if (!stuck->isStickToMouth()) {
			return true;
		}
	}

	return false;
}
