#ifndef _TAI_NAPKID_H
#define _TAI_NAPKID_H

#include "PaniAnimator.h"
#include "TAI/MotionActions.h"
#include "TekiParameters.h"
#include "types.h"

/////////// Snitchbug AI Actions ///////////

/**
 * @brief TODO: name members
 */
BEGIN_ENUM_TYPE(TaiNapkidIntParms)
enum {
	StruggleLoopCount = TPI_COUNT,
	COUNT,
} END_ENUM_TYPE;

/**
 * @brief TODO: name members
 */
BEGIN_ENUM_TYPE(TaiNapkidFloatParms)
enum {
	CarryingVelocity = TPF_COUNT,
	CarryFlightHeight,
	TakingOffFlightHeight,
	WanderingHoverPeriod,
	WanderingHoverProbability,
	HoveringWanderPeriod,
	HoveringWanderProbability,
	HoveringWashPeriod,
	HoveringWashProbability,
	WashingWanderPeriod,
	WashingWanderProbability,
	ThrowPeriod,
	ThrowVelocity,
	COUNT,
} END_ENUM_TYPE;

/**
 * @brief TODO: name members
 */
BEGIN_ENUM_TYPE(TaiNapkidStateID)
enum {
	Dying          = 0,
	Wandering      = 1,
	IdleFlying     = 2,
	IdleChatting   = 3,
	Chasing        = 4,
	Outrunning     = 5,
	Evading        = 6,
	AttackingSetup = 7,
	Attacking      = 8,
	Catching       = 9,
	AttackDeciding = 10,
	CarryingSetup  = 11,
	AttackMissing  = 12,
	Carrying       = 13,
	Throwing       = 14,
	ShockFalling   = 15,
	LoopFalling    = 16,
	Landing        = 17,
	Struggling     = 18,
	GettingUp      = 19,
	HeightDeciding = 20,
	Flicking       = 21,
	Rising         = 22,
	COUNT, // 23
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TaiNapkidSoundTable : public PaniSoundTable {
	TaiNapkidSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiNapkidParameters : public TekiParameters {
	TaiNapkidParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiNapkidStrategy : public TaiStrategy {
	TaiNapkidStrategy(TekiParameters*);

	virtual void start(Teki&);                    // _08
	virtual void draw(Teki&, Graphics&);          // _18
	virtual void drawDebugInfo(Teki&, Graphics&); // _1C

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiNapkidWanderingRouteAction : public TaiContinuousMotionAction {
	inline TaiNapkidWanderingRouteAction(int motionIdx, f32 p2) // TODO: this is a guess
	    : TaiContinuousMotionAction(TAI_NO_TRANSIT, motionIdx)
	{
		_0C = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void makeTargetPosition(Teki&);

	// _04     = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 _0C;
};

/**
 * @brief TODO
 */
struct TaiNapkidTargetPikiAction : public TaiAction {
	inline TaiNapkidTargetPikiAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidPikiLostAction : public TaiAction {
	inline TaiNapkidPikiLostAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidShortRangeAction : public TaiAction {
	inline TaiNapkidShortRangeAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidStraightFlyingAction : public TaiAction {
	inline TaiNapkidStraightFlyingAction(int nextState, f32 p2) // TODO: this is a guess
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 _08;
};

/**
 * @brief TODO
 */
struct TaiNapkidCirclingAction : public TaiAction {
	inline TaiNapkidCirclingAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidFlyingAction : public TaiAction {
	inline TaiNapkidFlyingAction(f32 flightHeight) // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mFlightHeight = flightHeight;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 mFlightHeight;
};

/**
 * @brief TODO
 */
struct TaiNapkidAscendingAction : public TaiAction {
	inline TaiNapkidAscendingAction() // TODO: i believe this is unused
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 _08;
};

/**
 * @brief TODO
 */
struct TaiNapkidApproachPikiAction : public TaiAction {
	inline TaiNapkidApproachPikiAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidCatchingAction : public TaiAction {
	inline TaiNapkidCatchingAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidCatchDescendingAction : public TaiAction {
	inline TaiNapkidCatchDescendingAction() // TODO: this is a guess
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
struct TaiNapkidCatchTracingAction : public TaiAction {
	inline TaiNapkidCatchTracingAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiNapkidCatchFlyingAction : public TaiAction {
	inline TaiNapkidCatchFlyingAction() // TODO: this is a guess
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
struct TaiNapkidCatchAscendingAction : public TaiAction {
	inline TaiNapkidCatchAscendingAction() // TODO: this is a guess
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
struct TaiNapkidTakingOffAscendingAction : public TaiAction {
	inline TaiNapkidTakingOffAscendingAction() // TODO: this is a guess
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
struct TaiNapkidRisingAscendingAction : public TaiAction {
	inline TaiNapkidRisingAscendingAction() // TODO: this is a guess
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
struct TaiNapkidThrowingPikiAction : public TaiAction {
	inline TaiNapkidThrowingPikiAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiNapkidFlickAction : public TaiAction {
	inline TaiNapkidFlickAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiNapkidFallingAction : public TaiAction {
	inline TaiNapkidFallingAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiNapkidShockFallingAction : public TaiAction {
	inline TaiNapkidShockFallingAction() // TODO: this is a guess
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
struct TaiNapkidFallingWaterEffectAction : public TaiAction {
	inline TaiNapkidFallingWaterEffectAction() // TODO: this is a guess
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
struct TaiNapkidStartDroppingWaterAction : public TaiAction {
	inline TaiNapkidStartDroppingWaterAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
