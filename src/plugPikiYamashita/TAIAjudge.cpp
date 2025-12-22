#include "DebugLog.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "TAI/Ajudge.h"
#include "TekiConditions.h"
#include "WorkObject.h"
#include "teki.h"

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
DEFINE_PRINT("TAIAjudge")

void TAIAsearchWorkObject::start(Teki& teki)
{
}

bool TAIAsearchWorkObject::act(Teki& teki)
{
	bool res    = false;
	f32 minDist = teki.getParameterF(TPF_DangerTerritoryRange);
	Iterator iter(workObjectMgr);
	teki.setWorkObjectPointer(nullptr);

	CI_LOOP(iter)
	{
		WorkObject* obj = (WorkObject*)*iter;
		f32 dist        = teki.getPosition().distance(obj->getPosition());
		if (dist < minDist) {
			bool isDestroyable = false;
			if (obj->isBridge() && static_cast<Bridge*>(obj)->getFirstFinishedStage() >= 0) {
				isDestroyable = true;
			}

			if (isDestroyable) {
				minDist = dist;
				teki.setWorkObjectPointer(obj);
				res = true;
			}
		}
	}

	return res;
}

bool TAIAlessLife::act(Teki& teki)
{
	if (getLifePercent(teki) < getLifePercentThreshold(teki)) {
		return true;
	}
	return false;
}

bool TAIAmoreLife::act(Teki& teki)
{
	if (getLifePercent(teki) > getLifePercentThreshold(teki)) {
		return true;
	}
	return false;
}

bool TAIAjudgeOptionalRange::act(Teki& teki)
{
	if (setTargetPosition(teki)) {
		return judgement(teki);
	}

	return true;
}

bool TAIAjudgeOptionalRange::setTargetPositionCreature(Teki& teki)
{
	bool res;
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		teki.mTargetPosition = NVector3f(target->getPosition());
		res                  = true;
	} else {
		res = false;
	}
	return res;
}

bool TAIAinsideOptionalRange::judgement(Teki& teki)
{
	f32 dist = teki.mTargetPosition.distance(teki.getPosition());
	return dist < getOptionalRange(teki);
}

bool TAIAoutsideOptionalRange::judgement(Teki& teki)
{
	f32 dist = teki.mTargetPosition.distance(teki.getPosition());
	return dist > getOptionalRange(teki);
}

bool TAIAcheckInsideRangePiki::act(Teki& teki)
{
	bool res      = false;
	int pikiCount = 0;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (teki.getPosition().distance(piki->getPosition()) < getRange(teki)) {
			pikiCount++;
		}
	}

	if (pikiCount >= getPikiMax(teki)) {
		res = true;
	}

	return res;
}

bool TAIAinsideTerritoryRangeNavi::act(Teki& teki)
{
	bool res   = false;
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		teki.mTargetPosition = NVector3f(navi->getPosition());
		f32 dist             = teki.mTargetPosition.distance(teki.mPersonality->mNestPosition);
		if (dist < teki.getParameterF(TPF_DangerTerritoryRange)) {
			teki.setCreaturePointer(0, navi);
			res = true;
		}
	}

	return res;
}

bool TAIAoutsideTerritoryRangeNavi::act(Teki& teki)
{
	bool res   = false;
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		teki.mTargetPosition = NVector3f(navi->getPosition());
		f32 dist             = teki.mTargetPosition.distance(teki.mPersonality->mNestPosition);
		if (dist > teki.getParameterF(TPF_DangerTerritoryRange)) {
			res = true;
		}
	}

	return res;
}

bool TAIAvisibleNavi::act(Teki& teki)
{
	Navi* navi = naviMgr->getNavi();
	if (teki.visibleCreature(*navi)) {
		teki.setCreaturePointer(0, navi);
		return true;
	}
	return false;
}

bool TAIAvisiblePiki::act(Teki& teki)
{
	bool res = false;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (teki.visibleCreature(*piki) && piki->getStickObject() != &teki) {
			teki.setCreaturePointer(0, piki);
			res = true;
			break;
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
bool TAIAattackableTarget::checkDist(Teki& teki)
{
	return (teki.mTargetPosition.distance(teki.getPosition()) < teki.getParameterF(TPF_AttackableRange)) ? TRUE : FALSE;
}

bool TAIAattackableTarget::checkAngle(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);

	// yes the ternary is necessary, and yes they specifically have to be TRUE and FALSE not true and false.
	return (teki.calcTargetAngle(target->getPosition()) < NMathF::d2r(teki.getParameterF(TPF_AttackableAngle)) / 2.0f) ? TRUE : FALSE;
}

bool TAIAattackableTarget::judge(Teki& teki)
{
	return checkDist(teki) && checkAngle(teki);
}

bool TAIAattackableTarget::act(Teki& teki)
{
	bool res         = true;
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		teki.mTargetPosition = NVector3f(target->getPosition());
		if (!judge(teki)) {
			res = false;
		}
	}
	return res;
}

bool TAIAunvisibleTarget::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		bool res = !teki.visibleCreature(*target);
		if (res) {
			PRINT("creature is lost ---------------!!!! \n");
		}

		return res;
	}

	return true;
}

bool TAIAstickingPiki::act(Teki& teki)
{
	int pikiCount = teki.countPikis(TekiStickerCondition(&teki));
	if (pikiCount >= getPikiNum(teki)) {
		return true;
	}
	return false;

	// what is UP with these conditions man.
	TekiStickerCondition(nullptr);
}

void TAIAdistanceTarget::start(Teki& teki)
{
	f32 v      = tanf(_08);
	f32 height = teki.getParameterF(TPF_FlightHeight);
	mDistance  = height / v;
}

bool TAIAdistanceTarget::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		teki.mTargetPosition = NVector3f(target->getPosition());
		return (teki.mTargetPosition.distance(teki.getPosition()) > mDistance);
	}

	return true;
}

void TAIAcheckTurnAngle::start(Teki& teki)
{
	teki.setAngle(teki.mFaceDirection);
	teki.setFrameCounter(0.0f);
}

bool TAIAcheckTurnAngle::act(Teki& teki)
{
	bool res    = false;
	f32 angDiff = teki.mFaceDirection - teki.getAngle();
	if (zen::Abs(angDiff) > PI) {
		if (angDiff > 0.0f) {
			angDiff = angDiff - TAU;
		} else {
			angDiff = angDiff + TAU;
		}
	}

	if (_0C) {
		if (angDiff > 0.0f) {
			if (teki.getFrameCounter() < 0.0f) {
				teki.setFrameCounter(0.0f);
			}
		} else {
			if (teki.getFrameCounter() > 0.0f) {
				teki.setFrameCounter(0.0f);
			}
		}
	}

	teki.addFrameCounter(angDiff);
	teki.setAngle(teki.mFaceDirection);
	if (zen::Abs(teki.getFrameCounter()) > _08) {
		res = true;
	}
	return res;
}
