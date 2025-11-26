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
	    : TaiMotionAction(nextState, 0) // TODO: Should be `TekiMotion::Dead`, but headers...
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
	TaiCountLoopAction(int nextState, int maxLoops)
	    : TaiAction(nextState)
	    , mMaxLoopCount(maxLoops)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMaxLoopCount; // _08
};

/**
 * @brief TODO
 */
struct TaiSwitchMotionAction : public TaiMotionAction {
	TaiSwitchMotionAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_0C = TaiMotionAction
};

/**
 * @brief TODO
 */
struct TaiOutsideKeyStopMoveAction : public TaiAction {
	TaiOutsideKeyStopMoveAction(int startKeyType, int endKeyType)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mStartKeyType = startKeyType;
		mEndKeyType   = endKeyType;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mStartKeyType; // _08
	int mEndKeyType;   // _0C
};

/**
 * @brief TODO
 */
struct TaiStoppingMoveAction : public TaiAction {
	TaiStoppingMoveAction(int motionIdx)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mMotionIdx = motionIdx;
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMotionIdx; // _08
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
	TaiSetFrameMotionAction() // straight up never used
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mKeyType; // _08
};

/**
 * @brief TODO
 */
struct TaiRandomSetAnimationCounterAction : public TaiAction {
	TaiRandomSetAnimationCounterAction(int minKeyType, int maxKeyType)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mMinKeyType = minKeyType;
		mMaxKeyType = maxKeyType;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMinKeyType; // _08
	int mMaxKeyType; // _0C
};

#endif
