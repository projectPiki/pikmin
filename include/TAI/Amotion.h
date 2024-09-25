#ifndef _TAI_AMOTION_H
#define _TAI_AMOTION_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TAIAmotion : public TaiAction {
	TAIAmotion(int, int);

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TAIAreserveMotion : public TaiAction {
	TAIAreserveMotion(int, int);

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TAIAmotionLoop : public TAIAreserveMotion {
	inline TAIAmotionLoop() // this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual f32 getFrameMax(Teki&); // _1C (weak)

	// _04     = VTBL
	// _00-_0C = TaiAreserveMotion
	f32 mFrameMax; // _0C
};

/**
 * @brief TODO
 */
struct TAIAsetMotionSpeed : public TAIAmotion {
	inline TAIAsetMotionSpeed() // this is a guess
	    : TAIAmotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_0C = TaiAmotion
	// TODO: members
};

#endif
