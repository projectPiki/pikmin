#include "TAI/JudgementActions.h"
#include "teki.h"
#include "NaviMgr.h"
#include "Stickers.h"
#include "TekiConditions.h"
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
DEFINE_PRINT("taijudgementactions")

/*
 * --INFO--
 * Address:	8012F4CC
 * Size:	000050
 */
bool TaiVisibleTargetAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("!TaiVisibleTargetAction::act:target==null:%08x\n", &teki);
		return false;
	}
	if (!teki.visibleCreature(*target)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8012F51C
 * Size:	000050
 */
bool TaiContactTargetAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("!TaiContactTargetAction::act:target==null:%08x\n", &teki);
		return false;
	}
	if (!teki.contactCreature(*target)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8012F56C
 * Size:	000050
 */
bool TaiSeparateTargetAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("!TaiSeparateTargetAction::act:target==null:%08x\n", &teki);
		return true;
	}
	if (!teki.separateCreature(*target)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8012F5BC
 * Size:	000074
 */
bool TaiTargetLostAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("TaiTargetLostAction::act:target==null:%08x\n", &teki);
		return true;
	}
	if (!teki.visibleCreature(*target)) {
		teki.clearCreaturePointer(0);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8012F630
 * Size:	0000BC
 */
bool TaiOutsideTerritoryAction::act(Teki& teki)
{
	return teki.getTerritoryDistance() > mTerritoryRadius;
}

/*
 * --INFO--
 * Address:	8012F6EC
 * Size:	0000C0
 */
bool TaiInsideTerritoryAction::act(Teki& teki)
{
	return teki.getTerritoryDistance() <= mTerritoryRadius;
}

/*
 * --INFO--
 * Address:	8012F7AC
 * Size:	0000AC
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

/*
 * --INFO--
 * Address:	8012F858
 * Size:	0000F0
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

/*
 * --INFO--
 * Address:	8012F948
 * Size:	000128
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

/*
 * --INFO--
 * Address:	8012FA70
 * Size:	000128
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
