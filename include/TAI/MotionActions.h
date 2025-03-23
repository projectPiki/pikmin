#ifndef _TAI_MOTIONACTIONS_H
#define _TAI_MOTIONACTIONS_H

#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiMotionAction : public TaiAction {
	TaiMotionAction(int nextState, int p2)
	    : TaiAction(nextState)
	    , mMotionIdx(p2)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMotionIdx; // _08
};

/**
 * @brief TODO
 */
struct TaiContinuousMotionAction : public TaiMotionAction {
	TaiContinuousMotionAction(int p1, int p2) // TODO: this is a guess
	    : TaiMotionAction(p1, p2)
	{
	}

	virtual void start(Teki&);         // _08
	virtual bool act(Teki&);           // _10
	virtual bool motionStarted(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiFinishMotionAction : public TaiMotionAction {
	inline TaiFinishMotionAction() // TODO: this is a guess
	    : TaiMotionAction(0, 0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiAnimationKeyAction : public TaiAction {
	TaiAnimationKeyAction(int nextState, int animKeyOpt)
	    : TaiAction(nextState)
	{
		mAnimKeyOpt = animKeyOpt;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mAnimKeyOpt; // _08
};

/**
 * @brief TODO
 */
struct TaiCountLoopAction : public TaiAction {
	TaiCountLoopAction(int nextState, int p2)
	    : TaiAction(nextState)
	    , _08(p2)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiSwitchMotionAction : public TaiMotionAction {
	inline TaiSwitchMotionAction() // TODO: this is a guess
	    : TaiMotionAction(0, 0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOutsideKeyStopMoveAction : public TaiAction {
	inline TaiOutsideKeyStopMoveAction() // TODO: this is a guess
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
struct TaiStoppingMoveAction : public TaiAction {
	inline TaiStoppingMoveAction() // TODO: this is a guess
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
struct TaiFinishStoppingMoveAction : public TaiAction {
	inline TaiFinishStoppingMoveAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSetFrameMotionAction : public TaiAction {
	inline TaiSetFrameMotionAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiRandomSetAnimationCounterAction : public TaiAction {
	inline TaiRandomSetAnimationCounterAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
