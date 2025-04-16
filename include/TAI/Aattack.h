#ifndef _TAI_AATTACK_H
#define _TAI_AATTACK_H

#include "types.h"
#include "TAI/Amotion.h"

struct Bridge;

/**
 * @brief TODO
 */
struct TAIAattackWorkObject : public TAIAreserveMotion {
	inline TAIAattackWorkObject(int nextState, int motionID, int p3) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
		_0C = motionID;
		_10 = p3;
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10
	virtual f32 getDamage(Teki&);            // _1C
	virtual f32 getAttackPointRadius(Teki&); // _20
	virtual void attackEffect(Teki&);        // _24

	bool attackWorkObject(Teki&);
	bool setTargetPosition(Teki&);
	int getLastFinishedStageBridge(Bridge*);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
	int _0C;
	int _10;
};

/**
 * @brief TODO
 */
struct TAIAflickingAfterMotionLoop : public TAIAmotionLoop {
	TAIAflickingAfterMotionLoop(int nextState, int motionIdx, f32 frameMax)
	    : TAIAmotionLoop(nextState, motionIdx, frameMax)
	{
	}

	virtual void start(Teki&);       // _08
	virtual bool act(Teki&);         // _10
	virtual f32 getFrameMax(Teki&);  // _1C
	virtual bool permitFlick(Teki&); // _20

	// _04     = VTBL
	// _00-_10 = TAIAmotionLoop
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtargetNavi : public TaiAction {
	inline TAIAtargetNavi() // TODO: this is a guess
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
struct TAIAtargetPiki : public TaiAction {
	inline TAIAtargetPiki() // TODO: this is a guess
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
struct TAIAfireBreath : public TAIAreserveMotion {
	inline TAIAfireBreath() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10
	virtual f32 getPreviousAnimSpeed(Teki&); // _1C
	virtual f32 getAttackAnimSpeed(Teki&);   // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickCheck : public TaiAction {
	TAIAflickCheck(int nextState, int damageCountLimit)
	    : TaiAction(nextState)
	{
		mDamageCountLimit = damageCountLimit;
	}

	virtual bool act(Teki&);                // _10
	virtual int getDamageCountLimit(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mDamageCountLimit; // _08
};

/**
 * @brief TODO
 */
struct TAIAflicking : public TAIAmotion {
	TAIAflicking(int nextState, int motionIdx)
	    : TAIAmotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);            // _08
	virtual bool act(Teki&);              // _10
	virtual void flick(Teki&);            // _1C
	virtual f32 getFlickDirection(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingReserveMotion : public TAIAreserveMotion {
	inline TAIAflickingReserveMotion() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);            // _08
	virtual bool act(Teki&);              // _10
	virtual void flick(Teki&);            // _1C
	virtual f32 getFlickDirection(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAbiteForKabekui : public TAIAreserveMotion {
	inline TAIAbiteForKabekui(int nextState, int p2, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
		_0C = nextState;
		_10 = p2;
	}

	virtual void start(Teki&);            // _08
	virtual bool act(Teki&);              // _10
	virtual f32 getPikiAttackSize(Teki&); // _1C
	virtual f32 getNaviAttackSize(Teki&); // _20

	bool hitCheck(Teki&);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
	int _0C;
	int _10;
};

/**
 * @brief TODO
 */
struct TAIAeatPiki : public TAIAreserveMotion {
	inline TAIAeatPiki(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);     // _08
	virtual bool act(Teki&);       // _10
	virtual void eatEffect(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

#endif
