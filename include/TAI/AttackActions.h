#ifndef _TAI_ATTACKACTIONS_H
#define _TAI_ATTACKACTIONS_H

#include "TAI/MotionActions.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TaiAttackableNaviPikiAction : public TaiAction {
	TaiAttackableNaviPikiAction(int nextState)
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
struct TaiAttackablePikiAction : public TaiAction {
	inline TaiAttackablePikiAction() // TODO: this is a guess
	    : TaiAction(0)
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
struct TaiAttackableNaviAction : public TaiAction {
	inline TaiAttackableNaviAction() // TODO: this is a guess
	    : TaiAction(0)
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
struct TaiAnimationSwallowingAction : public TaiAction {
	TaiAnimationSwallowingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiBangingAction : public TaiAction {
	TaiBangingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiFlickAction : public TaiAction {
	TaiFlickAction(int nextState)
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
struct TaiTargetStickAction : public TaiAction {
	inline TaiTargetStickAction() // TODO: this is a guess
	    : TaiAction(0)
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
struct TaiFlickingAction : public TaiMotionAction {
	TaiFlickingAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_0C = TaiMotionAction
};

/**
 * @brief TODO
 */
struct TaiFlickingUpperAction : public TaiMotionAction {
	inline TaiFlickingUpperAction(int nextState, int motionIdx) // TODO: this is a guess
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

#endif
