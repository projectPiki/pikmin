#ifndef _TAI_AJUDGE_H
#define _TAI_AJUDGE_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TAIAsearchWorkObject : public TaiAction {
	inline TAIAsearchWorkObject() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAjudgeLife : public TaiAction {
	inline TAIAjudgeLife() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual f32 getLifePercentThreshold(Teki&) = 0; // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlessLife : public TAIAjudgeLife {
	inline TAIAlessLife() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&);                        // _10
	virtual f32 getLifePercentThreshold(Teki&) = 0; // _1C

	// _04     = VTBL
	// _00-_08 = TAIAjudgeLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAmoreLife : public TAIAjudgeLife {
	inline TAIAmoreLife() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&);                        // _10
	virtual f32 getLifePercentThreshold(Teki&) = 0; // _1C

	// _04     = VTBL
	// _00-_08 = TAIAjudgeLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAjudgeOptionalRange : public TaiAction {
	inline TAIAjudgeOptionalRange() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&);                   // _10
	virtual void setTargetPosition(Teki&) = 0; // _1C
	virtual f32 getOptionalRange(Teki&)   = 0; // _20
	virtual bool judgement(Teki&)         = 0; // _24

	void setTargetPositionCreature(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinsideOptionalRange : public TAIAjudgeOptionalRange {
	inline TAIAinsideOptionalRange() // TODO: this is a guess
	{
	}

	virtual void setTargetPosition(Teki&) = 0; // _1C
	virtual f32 getOptionalRange(Teki&)   = 0; // _20
	virtual bool judgement(Teki&)         = 0; // _24

	// _04     = VTBL
	// _00-_08 = TAIAjudgeOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideOptionalRange : public TAIAjudgeOptionalRange {
	inline TAIAoutsideOptionalRange() // TODO: this is a guess
	{
	}

	virtual void setTargetPosition(Teki&) = 0; // _1C
	virtual f32 getOptionalRange(Teki&)   = 0; // _20
	virtual bool judgement(Teki&)         = 0; // _24

	// _04     = VTBL
	// _00-_08 = TAIAjudgeOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckInsideRangePiki : public TaiAction {
	inline TAIAcheckInsideRangePiki() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&);       // _10
	virtual int getPikiMax(Teki&); // _1C
	virtual f32 getRange(Teki&);   // _20

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinsideTerritoryRangeNavi : public TaiAction {
	inline TAIAinsideTerritoryRangeNavi() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideTerritoryRangeNavi : public TaiAction {
	inline TAIAoutsideTerritoryRangeNavi() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAvisibleNavi : public TaiAction {
	inline TAIAvisibleNavi() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAvisiblePiki : public TaiAction {
	inline TAIAvisiblePiki() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackableTarget : public TaiAction {
	inline TAIAattackableTarget() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&);   // _10
	virtual bool judge(Teki&); // _1C

	bool checkAngle(Teki&);

	// unused/inlined:
	void checkDist(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAunvisibleTarget : public TaiAction {
	inline TAIAunvisibleTarget() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPiki : public TaiAction {
	inline TAIAstickingPiki() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);     // _08
	virtual bool act(Teki&);       // _10
	virtual int getPikiNum(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mStickingPikiNum; // _08
};

/**
 * @brief TODO
 */
struct TAIAdistanceTarget : public TaiAction {
	inline TAIAdistanceTarget() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckTurnAngle : public TaiAction {
	inline TAIAcheckTurnAngle() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
