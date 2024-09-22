#ifndef _TEKICONDITION_H
#define _TEKICONDITION_H

#include "types.h"
#include "Condition.h"

/**
 * @brief TODO
 */
struct TekiCondition : public Condition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiAndCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiOrCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNotCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiAngleCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiAttackableCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiCollecTargetPelletCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiCreaturePointerCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiFreeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiLowerCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiLowerRangeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNapkidShortRangeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNapkidTargetPikiCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNaviCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiNaviPikiCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPelletCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPikiStateCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPositionCircleDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPositionDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiPositionSphereDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiRecognitionCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiSphereDistanceCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiStateCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiStickerCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiStickingCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiTypeCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiVisibleCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TekiVisibleHeightCondition : public TekiCondition {
	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = TekiCondition?
	// TODO: members
};

#endif
