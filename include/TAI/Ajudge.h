#ifndef _TAI_AJUDGE_H
#define _TAI_AJUDGE_H

#include "TAI/Action.h"
#include "teki.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TAIAsearchWorkObject : public TaiAction {
public:
	inline TAIAsearchWorkObject(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAjudgeLife : public TaiAction {
public:
	TAIAjudgeLife(int nextState)
	    : TaiAction(nextState)
	{
	}

protected:
	virtual f32 getLifePercentThreshold(Teki&) = 0; // _1C

	f32 getLifePercent(Teki& teki) { return teki.mHealth / teki.getParameterF(TPF_Life); }

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlessLife : public TAIAjudgeLife {
public:
	TAIAlessLife(int nextState)
	    : TAIAjudgeLife(nextState)
	{
	}

	virtual bool act(Teki&);                        // _10

protected:
	virtual f32 getLifePercentThreshold(Teki&) = 0; // _1C

	// _04     = VTBL
	// _00-_08 = TAIAjudgeLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAmoreLife : public TAIAjudgeLife {
public:
	TAIAmoreLife(int nextState)
	    : TAIAjudgeLife(nextState)
	{
	}

	virtual bool act(Teki&);                        // _10

protected:
	virtual f32 getLifePercentThreshold(Teki&) = 0; // _1C

	// _04     = VTBL
	// _00-_08 = TAIAjudgeLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAjudgeOptionalRange : public TaiAction {
public:
	TAIAjudgeOptionalRange(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&);                   // _10

protected:
	virtual bool setTargetPosition(Teki&) = 0; // _1C
	virtual f32 getOptionalRange(Teki&)   = 0; // _20
	virtual bool judgement(Teki&)         = 0; // _24

	bool setTargetPositionCreature(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinsideOptionalRange : public TAIAjudgeOptionalRange {
public:
	TAIAinsideOptionalRange(int nextState) // TODO: this is a guess
	    : TAIAjudgeOptionalRange(nextState)
	{
	}

protected:
	virtual bool setTargetPosition(Teki&) = 0; // _1C
	virtual f32 getOptionalRange(Teki&)   = 0; // _20
	virtual bool judgement(Teki&);             // _24

	// _04     = VTBL
	// _00-_08 = TAIAjudgeOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideOptionalRange : public TAIAjudgeOptionalRange {
public:
	TAIAoutsideOptionalRange(int nextState)
	    : TAIAjudgeOptionalRange(nextState)
	{
	}

protected:
	virtual bool setTargetPosition(Teki&) = 0; // _1C
	virtual f32 getOptionalRange(Teki&)   = 0; // _20
	virtual bool judgement(Teki&);             // _24

	// _04     = VTBL
	// _00-_08 = TAIAjudgeOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckInsideRangePiki : public TaiAction {
public:
	TAIAcheckInsideRangePiki(int nextState, int pikiMax, f32 range)
	    : TaiAction(nextState)
	{
		mPikiMax = pikiMax;
		mRange   = range;
	}

	virtual bool act(Teki&);                           // _10

protected:
	virtual int getPikiMax(Teki&) { return mPikiMax; } // _1C
	virtual f32 getRange(Teki&) { return mRange; }     // _20

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mPikiMax; // _08
	f32 mRange;   // _0C
};

/**
 * @brief TODO
 */
struct TAIAinsideTerritoryRangeNavi : public TaiAction {
public:
	TAIAinsideTerritoryRangeNavi(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideTerritoryRangeNavi : public TaiAction {
public:
	inline TAIAoutsideTerritoryRangeNavi() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAvisibleNavi : public TaiAction {
public:
	inline TAIAvisibleNavi(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAvisiblePiki : public TaiAction {
public:
	TAIAvisiblePiki(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackableTarget : public TaiAction {
public:
	inline TAIAattackableTarget(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&);   // _10

protected:
	virtual bool judge(Teki&); // _1C

	bool checkAngle(Teki&);
	bool checkDist(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAunvisibleTarget : public TaiAction {
public:
	inline TAIAunvisibleTarget(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPiki : public TaiAction {
public:
	TAIAstickingPiki(int nextState, int stickNum)
	    : TaiAction(nextState)
	{
		mStickingPikiNum = stickNum;
	}

	virtual void start(Teki&) { }                              // _08
	virtual bool act(Teki&);                                   // _10

protected:
	virtual int getPikiNum(Teki&) { return mStickingPikiNum; } // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mStickingPikiNum; // _08
};

/**
 * @brief TODO
 */
struct TAIAdistanceTarget : public TaiAction {
public:
	TAIAdistanceTarget() // this never gets called, so who knows
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 _08;       // _08
	f32 mDistance; // _0C
};

/**
 * @brief TODO
 */
struct TAIAcheckTurnAngle : public TaiAction {
public:
	TAIAcheckTurnAngle(int nextState, f32 p2, bool p3)
	    : TaiAction(nextState)
	{
		_08 = p2;
		_0C = p3;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 _08;  // _08
	bool _0C; // _0C
};

/**
 * @brief TODO
 */
struct TAIAoutsideTerritory : public TaiAction {
public:
	TAIAoutsideTerritory(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		return teki.getTerritoryDistance() > teki.getParameterF(TPF_DangerTerritoryRange);
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackableAngleTarget : public TAIAattackableTarget {
public:
	inline TAIAattackableAngleTarget(int nextState) // TODO: this is a guess
	    : TAIAattackableTarget(nextState)
	{
	}

protected:
	virtual bool judge(Teki& teki) // _1C
	{
		return TAIAattackableTarget::checkAngle(teki);
	}

	// _04     = VTBL
	// _00-_08 = TAIAattackableTarget?
	// TODO: members
};

#endif
