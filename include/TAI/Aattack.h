#ifndef _TAI_AATTACK_H
#define _TAI_AATTACK_H

#include "TAI/Amotion.h"
#include "types.h"

struct Bridge;

/**
 * @brief TODO
 */
struct TAIAattackWorkObject : public TAIAreserveMotion {
public:
	inline TAIAattackWorkObject(int nextState, int motionID, int p3) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
		_0C = motionID;
		_10 = p3;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual f32 getDamage(Teki&) { return 1.0f; }             // _1C
	virtual f32 getAttackPointRadius(Teki&) { return 10.0f; } // _20
	virtual void attackEffect(Teki&) { }                      // _24

	bool attackWorkObject(Teki&);
	bool setTargetPosition(Teki&);
	int getLastFinishedStageBridge(Bridge*);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
	int _0C; // _0C
	int _10; // _10
};

/**
 * @brief TODO
 */
struct TAIAflickingAfterMotionLoop : public TAIAmotionLoop {
public:
	TAIAflickingAfterMotionLoop(int nextState, int motionIdx, f32 frameMax)
	    : TAIAmotionLoop(nextState, motionIdx, frameMax)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual f32 getFrameMax(Teki&) { return mFrameMax; } // _1C
	virtual bool permitFlick(Teki&);                     // _20

	// _04     = VTBL
	// _00-_10 = TAIAmotionLoop
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtargetNavi : public TaiAction {
public:
	inline TAIAtargetNavi() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtargetPiki : public TaiAction {
public:
	inline TAIAtargetPiki() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAfireBreath : public TAIAreserveMotion {
public:
	TAIAfireBreath(int nextState, int motionID, zen::CallBack1<Teki&>* cb)
	    : TAIAreserveMotion(nextState, motionID)
	{
		mCallBack = cb;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual f32 getPreviousAnimSpeed(Teki&) { return 30.0f; } // _1C
	virtual f32 getAttackAnimSpeed(Teki&) { return 30.0f; }   // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	zen::CallBack1<Teki&>* mCallBack; // _0C
};

/**
 * @brief TODO
 */
struct TAIAflickCheck : public TaiAction {
public:
	TAIAflickCheck(int nextState, int damageCountLimit)
	    : TaiAction(nextState)
	{
		mDamageCountLimit = damageCountLimit;
	}

	virtual bool act(Teki&); // _10

protected:
	virtual int getDamageCountLimit(Teki&) { return mDamageCountLimit; } // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mDamageCountLimit; // _08
};

/**
 * @brief TODO
 */
struct TAIAflicking : public TAIAmotion {
public:
	TAIAflicking(int nextState, int motionIdx)
	    : TAIAmotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual void flick(Teki&);                                             // _1C
	virtual f32 getFlickDirection(Teki&) { return FLICK_BACKWARDS_ANGLE; } // _20

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingReserveMotion : public TAIAreserveMotion {
public:
	TAIAflickingReserveMotion(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual void flick(Teki&);                                             // _1C
	virtual f32 getFlickDirection(Teki&) { return FLICK_BACKWARDS_ANGLE; } // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAbiteForKabekui : public TAIAreserveMotion {
public:
	inline TAIAbiteForKabekui(int nextState, int p2, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
		_0C = nextState;
		_10 = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual f32 getPikiAttackSize(Teki&) { return 15.0f; } // _1C
	virtual f32 getNaviAttackSize(Teki&) { return 15.0f; } // _20

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
public:
	inline TAIAeatPiki(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual void eatEffect(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

#endif
