#ifndef _TAI_MOTIONACTIONS_H
#define _TAI_MOTIONACTIONS_H

#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiMotionAction : public TaiAction {
	TaiMotionAction(int nextState, int motionIdx)
	    : TaiAction(nextState)
	    , mMotionIdx(motionIdx)
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
 *
 * @note Size: 0xC.
 */
struct TaiContinuousMotionAction : public TaiMotionAction {
	TaiContinuousMotionAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);         // _08
	virtual bool act(Teki&);           // _10
	virtual bool motionStarted(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TaiMotionAction
};

/**
 * @brief TODO
 */
struct TaiFinishMotionAction : public TaiMotionAction {
	TaiFinishMotionAction(int nextState)
	    : TaiMotionAction(nextState, 0)
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
	TaiStoppingMoveAction(int p1)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		_08 = p1;
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiFinishStoppingMoveAction : public TaiAction {
	TaiFinishStoppingMoveAction()
	    : TaiAction(TAI_NO_TRANSIT)
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
