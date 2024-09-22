#ifndef _TAI_ATTACKACTIONS_H
#define _TAI_ATTACKACTIONS_H

#include "types.h"
#include "TAI/MotionActions.h"

/**
 * @brief TODO
 */
struct TaiAttackableNaviPikiAction : public TaiAction {
	inline TaiAttackableNaviPikiAction() // TODO: this is a guess
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
	inline TaiAnimationSwallowingAction() // TODO: this is a guess
	    : TaiAction(0)
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
	inline TaiBangingAction() // TODO: this is a guess
	    : TaiAction(0)
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
	inline TaiFlickAction() // TODO: this is a guess
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
	inline TaiFlickingAction() // TODO: this is a guess
	    : TaiMotionAction(0)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiFlickingUpperAction : public TaiMotionAction {
	inline TaiFlickingUpperAction() // TODO: this is a guess
	    : TaiMotionAction(0)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

#endif
