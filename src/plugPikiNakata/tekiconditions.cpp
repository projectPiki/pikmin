#include "TekiConditions.h"
#include "DebugLog.h"
#include "Piki.h"
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
DEFINE_PRINT("tekiconditions")

bool TekiPikiStateCondition::satisfy(Creature* target) immut
{
	STACK_PAD_VAR(1);
	if (target->mObjType != OBJTYPE_Piki) {
		return false;
	}

	Piki* piki = static_cast<Piki*>(target);
	return piki->getState() == mPikiStateID;
}

bool TekiStateCondition::satisfy(Creature* target) immut
{
	if (target->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(target)->mStateID == mStateID;
}

bool TekiTypeCondition::satisfy(Creature* target) immut
{
	if (target->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(target)->mTekiType == mTekiType;
}

bool TekiFreeCondition::satisfy(Creature* target) immut
{
	return target->isFree();
}

bool TekiNaviCondition::satisfy(Creature* target) immut
{
	return target->mObjType == OBJTYPE_Navi;
}

bool TekiNaviPikiCondition::satisfy(Creature* target) immut
{
	return target->mObjType == OBJTYPE_Navi || target->mObjType == OBJTYPE_Piki;
}

bool TekiPelletCondition::satisfy(Creature* target) immut
{
	return BTeki::isPellet(target->mObjType);
}

bool TekiPositionDistanceCondition::satisfy(Creature* target) immut
{
	return mPosition.distance(target->getPosition()) <= mDistance;
}

bool TekiPositionCircleDistanceCondition::satisfy(Creature* target) immut
{
	return BTeki::calcCircleDistanceStatic(mPosition, mRadius, target->getPosition(), target->getSize()) <= 0.0f;
}

bool TekiPositionSphereDistanceCondition::satisfy(Creature* target) immut
{
	return BTeki::calcSphereDistanceStatic(mPosition, mRadius, target->getPosition(), target->getSize()) <= 0.0f;
}

bool TekiStickingCondition::satisfy(Creature* target) immut
{
	return target->getStickObject() != nullptr;
}

bool TekiRecognitionCondition::satisfy(Creature* target) immut
{
	return target->isVisible() && target->isAlive() && !target->isBuried();
}

bool TekiCreaturePointerCondition::satisfy(Creature* target) immut
{
	return mCreature == target;
}

bool TekiDistanceCondition::satisfy(Creature* target) immut
{
	if (mTeki->cullableCenter(*target, mDistance)) {
		return false;
	}

	return mTeki->calcSphereDistance(*target) <= mDistance;
}

bool TekiSphereDistanceCondition::satisfy(Creature* target) immut
{
	STACK_PAD_VAR(1);
	if (mTeki->cullableSphere(*target, mDistance)) {
		return false;
	}

	return sphereDist(mTeki, target) <= mDistance;
}

bool TekiStickerCondition::satisfy(Creature* target) immut
{
	return target->getStickObject() == mStickTarget;
}

bool TekiLowerRangeCondition::satisfy(Creature* target) immut
{
	f32 lowerRange = mTeki->getLowerRange();
	if (mTeki->cullableCenter(*target, lowerRange)) {
		return false;
	}

	return mTeki->calcSphereDistance(*target) <= lowerRange;
}

bool TekiAttackableCondition::satisfy(Creature* target) immut
{
	return mTeki->attackableCreature(*target);
}

bool TekiVisibleCondition::satisfy(Creature* target) immut
{
	return mTeki->visibleCreature(*target);
}

bool TekiVisibleHeightCondition::satisfy(Creature* target) immut
{
	f32 visHeight = mTeki->getParameterF(TPF_VisibleHeight);
	if (target->getPosition().y > mTeki->getPosition().y + visHeight) {
		return false;
	}

	return true;
}

bool TekiLowerCondition::satisfy(Creature* target) immut
{
	// fucking amazing work nakata.
	return TekiAndCondition(&TekiLowerRangeCondition(mTeki), &TekiNotCondition(&TekiStickerCondition(mTeki))).satisfy(target);
	return TekiAndCondition(&TekiLowerRangeCondition(mTeki), &TekiNotCondition(&TekiStickerCondition(mTeki))).satisfy(target);
}

bool TekiAngleCondition::satisfy(Creature* target) immut
{
	f32 targetAngle = mTeki->calcTargetAngle(target->getPosition());
	if (targetAngle > NMathF::d2r(mAngle / 2.0f)) {
		return false;
	}

	return true;
}
