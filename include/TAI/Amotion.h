#ifndef _TAI_AMOTION_H
#define _TAI_AMOTION_H

#include "TAI/Action.h"
#include "teki.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TAIAmotion : public TaiAction {
public:
	TAIAmotion(int nextState, int motionID);

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMotionID; // _08
};

/**
 * @brief TODO
 */
struct TAIAreserveMotion : public TaiAction {
public:
	TAIAreserveMotion(int nextState, int motionID);

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
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
public:
	TAIAmotionLoop(int nextState, int motionIdx, f32 frameMax)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
		mFrameMax = frameMax;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
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
public:
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

protected:
	// _04     = VTBL
	// _00-_0C = TaiAmotion
	f32 mMotionSpeed; // _0C
};

#endif
