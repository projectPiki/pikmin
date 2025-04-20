#ifndef _TAI_AMOTION_H
#define _TAI_AMOTION_H

#include "types.h"
#include "TAI/Action.h"
#include "teki.h"

/**
 * @brief TODO
 */
struct TAIAmotion : public TaiAction {
	TAIAmotion(int nextState, int motionID);

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMotionID; // _08
};

/**
 * @brief TODO
 */
struct TAIAreserveMotion : public TaiAction {
	TAIAreserveMotion(int nextState, int motionID);

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMotionID; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct TAIAmotionLoop : public TAIAreserveMotion {
	TAIAmotionLoop(int nextState, int motionIdx, f32 frameMax)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
		mFrameMax = frameMax;
	}

	virtual void start(Teki&);     // _08
	virtual bool act(Teki&);       // _10
	virtual f32 getFrameMax(Teki&) // _1C (weak)
	{
		return mFrameMax;
	}

	// _04     = VTBL
	// _00-_0C = TaiAreserveMotion
	f32 mFrameMax; // _0C
};

/**
 * @brief TODO
 */
struct TAIAsetMotionSpeed : public TAIAmotion {
	TAIAsetMotionSpeed(int nextState, int motionID, f32 motionSpeed)
	    : TAIAmotion(nextState, motionID)
	{
		mMotionSpeed = motionSpeed;
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAmotion::start(teki);
		teki.setAnimSpeed(mMotionSpeed);
	}

	// _04     = VTBL
	// _00-_0C = TaiAmotion
	f32 mMotionSpeed; // _0C
};

#endif
