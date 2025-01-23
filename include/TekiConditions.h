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
	virtual bool satisfy(Creature*); // _08

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

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Condition* mConditionA; // _04
	Condition* mConditionB; // _08
};

/**
 * @brief TODO
 */
struct TekiOrCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNotCondition : public TekiCondition {
	TekiNotCondition(Condition* notCond) { mNotCondition = notCond; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Condition* mNotCondition; // _04
};

/**
 * @brief TODO
 */
struct TekiAngleCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiAttackableCondition : public TekiCondition {
	inline TekiAttackableCondition(Teki* teki) { mTeki = teki; }

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	Teki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct TekiCollecTargetPelletCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiCreaturePointerCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiFreeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiLowerCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiLowerRangeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNapkidShortRangeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNapkidTargetPikiCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNaviCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNaviPikiCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPelletCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPikiStateCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPositionCircleDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
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
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiStateCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
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
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiTypeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiVisibleCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiVisibleHeightCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition
	// TODO: members
};

#endif
