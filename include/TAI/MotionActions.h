#ifndef _TAI_MOTIONACTIONS_H
#define _TAI_MOTIONACTIONS_H

#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiMotionAction : public TaiAction {
	inline TaiMotionAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiContinuousMotionAction : public TaiMotionAction {
	inline TaiContinuousMotionAction() // TODO: this is a guess
	    : TaiMotionAction(0)
	{
	}

	virtual void start(Teki&);         // _08
	virtual bool act(Teki&);           // _10
	virtual void motionStarted(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiFinishMotionAction : public TaiMotionAction {
	inline TaiFinishMotionAction() // TODO: this is a guess
	    : TaiMotionAction(0)
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
	inline TaiAnimationKeyAction() // TODO: this is a guess
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
struct TaiCountLoopAction : public TaiAction {
	inline TaiCountLoopAction() // TODO: this is a guess
	    : TaiAction(0)
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
struct TaiSwitchMotionAction : public TaiMotionAction {
	inline TaiSwitchMotionAction() // TODO: this is a guess
	    : TaiMotionAction(0)
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
