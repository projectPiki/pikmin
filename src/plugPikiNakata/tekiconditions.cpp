#include "TekiConditions.h"
#include "DebugLog.h"
#include "Piki.h"
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
DEFINE_PRINT("tekiconditions")

/**
 * @TODO: Documentation
 */
bool TekiPikiStateCondition::satisfy(Creature* target) immut
{
	STACK_PAD_VAR(1);
	if (target->mObjType != OBJTYPE_Piki) {
		return false;
	}

	Piki* piki = static_cast<Piki*>(target);
	return piki->getState() == mPikiStateID;
}

/**
 * @TODO: Documentation
 */
bool TekiStateCondition::satisfy(Creature* target) immut
{
	if (target->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(target)->mStateID == mStateID;
}

/**
 * @TODO: Documentation
 */
bool TekiTypeCondition::satisfy(Creature* target) immut
{
	if (target->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(target)->mTekiType == mTekiType;
}

/**
 * @TODO: Documentation
 */
bool TekiFreeCondition::satisfy(Creature* target) immut
{
	return target->isFree();
}

/**
 * @TODO: Documentation
 */
bool TekiNaviCondition::satisfy(Creature* target) immut
{
	return target->mObjType == OBJTYPE_Navi;
}

/**
 * @TODO: Documentation
 */
bool TekiNaviPikiCondition::satisfy(Creature* target) immut
{
	return target->mObjType == OBJTYPE_Navi || target->mObjType == OBJTYPE_Piki;
}

/**
 * @TODO: Documentation
 */
bool TekiPelletCondition::satisfy(Creature* target) immut
{
	return BTeki::isPellet(target->mObjType);
}

/**
 * @TODO: Documentation
 */
bool TekiPositionDistanceCondition::satisfy(Creature* target) immut
{
	return mPosition.distance(target->getPosition()) <= mDistance;
}

/**
 * @TODO: Documentation
 */
bool TekiPositionCircleDistanceCondition::satisfy(Creature* target) immut
{
	return BTeki::calcCircleDistanceStatic(mPosition, mRadius, target->getPosition(), target->getSize()) <= 0.0f;
}

/**
 * @TODO: Documentation
 */
bool TekiPositionSphereDistanceCondition::satisfy(Creature* target) immut
{
	return BTeki::calcSphereDistanceStatic(mPosition, mRadius, target->getPosition(), target->getSize()) <= 0.0f;
}

/**
 * @TODO: Documentation
 */
bool TekiStickingCondition::satisfy(Creature* target) immut
{
	return target->getStickObject() != nullptr;
}

/**
 * @TODO: Documentation
 */
bool TekiRecognitionCondition::satisfy(Creature* target) immut
{
	return target->isVisible() && target->isAlive() && !target->isBuried();
}

/**
 * @TODO: Documentation
 */
bool TekiCreaturePointerCondition::satisfy(Creature* target) immut
{
	return mCreature == target;
}

/**
 * @TODO: Documentation
 */
bool TekiDistanceCondition::satisfy(Creature* target) immut
{
	if (mTeki->cullableCenter(*target, mDistance)) {
		return false;
	}

	return mTeki->calcSphereDistance(*target) <= mDistance;
}

/**
 * @TODO: Documentation
 */
bool TekiSphereDistanceCondition::satisfy(Creature* target) immut
{
	STACK_PAD_VAR(1);
	if (mTeki->cullableSphere(*target, mDistance)) {
		return false;
	}

	return sphereDist(mTeki, target) <= mDistance;
}

/**
 * @TODO: Documentation
 */
bool TekiStickerCondition::satisfy(Creature* target) immut
{
	return target->getStickObject() == mStickTarget;
}

/**
 * @TODO: Documentation
 */
bool TekiLowerRangeCondition::satisfy(Creature* target) immut
{
	f32 lowerRange = mTeki->getLowerRange();
	if (mTeki->cullableCenter(*target, lowerRange)) {
		return false;
	}

	return mTeki->calcSphereDistance(*target) <= lowerRange;
}

/**
 * @TODO: Documentation
 */
bool TekiAttackableCondition::satisfy(Creature* target) immut
{
	return mTeki->attackableCreature(*target);
}

/**
 * @TODO: Documentation
 */
bool TekiVisibleCondition::satisfy(Creature* target) immut
{
	return mTeki->visibleCreature(*target);
}

/**
 * @TODO: Documentation
 */
bool TekiVisibleHeightCondition::satisfy(Creature* target) immut
{
	f32 visHeight = mTeki->getParameterF(TPF_VisibleHeight);
	if (target->getPosition().y > mTeki->getPosition().y + visHeight) {
		return false;
	}

	return true;
}

/**
 * @TODO: Documentation
 */
bool TekiLowerCondition::satisfy(Creature* target) immut
{
	// fucking amazing work nakata.
	return TekiAndCondition(&TekiLowerRangeCondition(mTeki), &TekiNotCondition(&TekiStickerCondition(mTeki))).satisfy(target);
	return TekiAndCondition(&TekiLowerRangeCondition(mTeki), &TekiNotCondition(&TekiStickerCondition(mTeki))).satisfy(target);
}

/**
 * @TODO: Documentation
 */
bool TekiAngleCondition::satisfy(Creature* target) immut
{
	f32 targetAngle = mTeki->calcTargetAngle(target->getPosition());
	if (targetAngle > NMathF::d2r(mAngle / 2.0f)) {
		return false;
	}

	return true;
}
