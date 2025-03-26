#ifndef _TAI_JUDGEMENTACTIONS_H
#define _TAI_JUDGEMENTACTIONS_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiVisibleTargetAction : public TaiAction {
	TaiVisibleTargetAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiContactTargetAction : public TaiAction {
	TaiContactTargetAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiSeparateTargetAction : public TaiAction {
	TaiSeparateTargetAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTargetLostAction : public TaiAction {
	TaiTargetLostAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiOutsideTerritoryAction : public TaiAction {
	TaiOutsideTerritoryAction(int nextState, f32 radius)
	    : TaiAction(nextState)
	{
		mTerritoryRadius = radius;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mTerritoryRadius; // _08
};

/**
 * @brief TODO
 */
struct TaiInsideTerritoryAction : public TaiAction {
	TaiInsideTerritoryAction(int nextState, f32 radius)
	    : TaiAction(nextState)
	{
		mTerritoryRadius = radius;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mTerritoryRadius; // _08
};

/**
 * @brief TODO
 */
struct TaiTargetVisibleNaviPikiAction : public TaiAction {
	TaiTargetVisibleNaviPikiAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTargetVisibleNaviAction : public TaiAction {
	TaiTargetVisibleNaviAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiHasStickersInMouthAction : public TaiAction {
	inline TaiHasStickersInMouthAction() // TODO: this is a guess
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
struct TaiHasStickersOnBodyAction : public TaiAction {
	inline TaiHasStickersOnBodyAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
