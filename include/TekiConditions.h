#ifndef _TEKICONDITION_H
#define _TEKICONDITION_H

#include "types.h"
#include "Condition.h"
#include "Vector.h"

struct Teki;

/**
 * @brief TODO
 */
struct TekiCondition : public Condition {
	virtual bool satisfy(Creature*) { return true; } // _08

	// _00     = VTBL
	// _00-_04 = Condition
};

/**
 * @brief TODO
 */
struct TekiAndCondition : public TekiCondition {
	TekiAndCondition(Condition* condA, Condition* condB)
	{
		mConditionA = condA;
		mConditionB = condB;
	}

	virtual bool satisfy(Creature* target) // _08
	{
		return mConditionA->satisfy(target) && mConditionB->satisfy(target);
	}

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Condition* mConditionA; // _04
	Condition* mConditionB; // _08
};

/**
 * @brief TODO
 */
struct TekiOrCondition : public TekiCondition {
	TekiOrCondition(Condition* condA, Condition* condB)
	{
		mConditionA = condA;
		mConditionB = condB;
	}

	virtual bool satisfy(Creature* target) // _08
	{
		return mConditionA->satisfy(target) || mConditionB->satisfy(target);
	}

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Condition* mConditionA; // _04
	Condition* mConditionB; // _08
};

/**
 * @brief TODO
 */
struct TekiNotCondition : public TekiCondition {
	TekiNotCondition(Condition* notCond) { mNotCondition = notCond; }

	virtual bool satisfy(Creature* target) { return !mNotCondition->satisfy(target); } // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Condition* mNotCondition; // _04
};

/**
 * @brief TODO
 */
struct TekiAngleCondition : public TekiCondition {
	TekiAngleCondition(Teki* teki, f32 angle)
	{
		mTeki  = teki;
		mAngle = angle;
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
	f32 mAngle;  // _08
};

/**
 * @brief TODO
 */
struct TekiAttackableCondition : public TekiCondition {
	TekiAttackableCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct TekiCollecTargetPelletCondition : public TekiCondition {
	TekiCollecTargetPelletCondition(Teki* collec, int carryPower)
	{
		mCollec     = collec;
		mCarryPower = carryPower;
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mCollec;   // _04
	int mCarryPower; // _08
};

/**
 * @brief TODO
 */
struct TekiCreaturePointerCondition : public TekiCondition {
	TekiCreaturePointerCondition(Creature* target) { mCreature = target; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Creature* mCreature; // _04
};

/**
 * @brief TODO
 */
struct TekiDistanceCondition : public TekiCondition {
	TekiDistanceCondition(Teki* teki, f32 distance)
	{
		mTeki     = teki;
		mDistance = distance;
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki;   // _04
	f32 mDistance; // _08
};

/**
 * @brief TODO
 */
struct TekiFreeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
};

/**
 * @brief TODO
 */
struct TekiLowerCondition : public TekiCondition {
	TekiLowerCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct TekiLowerRangeCondition : public TekiCondition {
	TekiLowerRangeCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct TekiNapkidShortRangeCondition : public TekiCondition {
	TekiNapkidShortRangeCondition(Teki* teki)
	    : mTeki(teki)
	{
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki;
};

/**
 * @brief TODO
 */
struct TekiNapkidTargetPikiCondition : public TekiCondition {
	TekiNapkidTargetPikiCondition(Teki* teki)
	    : mTeki(teki)
	{
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
	Teki* mTeki;
};

/**
 * @brief TODO
 */
struct TekiNaviCondition : public TekiCondition {
	TekiNaviCondition() { }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
};

/**
 * @brief TODO
 */
struct TekiNaviPikiCondition : public TekiCondition {
	TekiNaviPikiCondition() { }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
};

/**
 * @brief TODO
 */
struct TekiPelletCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
};

/**
 * @brief TODO
 */
struct TekiPikiStateCondition : public TekiCondition {
	TekiPikiStateCondition(int stateID) { mPikiStateID = stateID; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	int mPikiStateID; // _04
};

/**
 * @brief TODO
 */
struct TekiPositionCircleDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Vector3f mPosition; // _04
	f32 mRadius;        // _10
};

/**
 * @brief TODO
 */
struct TekiPositionDistanceCondition : public TekiCondition {
	TekiPositionDistanceCondition(Vector3f pos, f32 dist)
	{
		mPosition.input(pos);
		mDistance = dist;
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Vector3f mPosition; // _04
	f32 mDistance;      // _10
};

/**
 * @brief TODO
 */
struct TekiPositionSphereDistanceCondition : public TekiCondition {
	TekiPositionSphereDistanceCondition(Vector3f pos, f32 dist)
	{
		mPosition.input(pos);
		mRadius = dist;
	}

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Vector3f mPosition; // _04
	f32 mRadius;        // _10
};

/**
 * @brief TODO
 */
struct TekiRecognitionCondition : public TekiCondition {
	TekiRecognitionCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct TekiSphereDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki;   // _04
	f32 mDistance; // _08
};

/**
 * @brief TODO
 */
struct TekiStateCondition : public TekiCondition {
	TekiStateCondition(int stateID) { mStateID = stateID; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	int mStateID; // _04
};

/**
 * @brief TODO
 */
struct TekiStickerCondition : public TekiCondition {
	TekiStickerCondition(Teki* teki) { mStickTarget = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mStickTarget; // _04
};

/**
 * @brief TODO
 */
struct TekiStickingCondition : public TekiCondition {
	TekiStickingCondition() { }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiTypeCondition : public TekiCondition {
	TekiTypeCondition(int type) { mTekiType = type; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	int mTekiType; // _04
};

/**
 * @brief TODO
 */
struct TekiVisibleCondition : public TekiCondition {
	TekiVisibleCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct TekiVisibleHeightCondition : public TekiCondition {
	TekiVisibleHeightCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

#endif
