#ifndef _TAI_NAPKID_H
#define _TAI_NAPKID_H

#include "types.h"
#include "TAI/MotionActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

/////////// Snitchbug AI Actions ///////////

/**
 * @brief TODO: name members
 */
enum TaiNapkidIntParms {
	NAPKIDPI_Unk0 = TPI_COUNT,
	NAPKIDPI_COUNT,
};

/**
 * @brief TODO: name members
 */
enum TaiNapkidFloatParms {
	NAPKIDPF_Unk0 = TPF_COUNT,
	NAPKIDPF_CarryFlightHeight,
	NAPKIDPF_Unk2,
	NAPKIDPF_Unk3,
	NAPKIDPF_Unk4,
	NAPKIDPF_Unk5,
	NAPKIDPF_Unk6,
	NAPKIDPF_Unk7,
	NAPKIDPF_Unk8,
	NAPKIDPF_Unk9,
	NAPKIDPF_Unk10,
	NAPKIDPF_Unk11,
	NAPKIDPF_Unk12,
	NAPKIDPF_COUNT,
};

/**
 * @brief TODO: name members
 */
enum TaiNapkidStateID {
	NAPKIDSTATE_Dying          = 0,
	NAPKIDSTATE_Wandering      = 1,
	NAPKIDSTATE_IdleFlying     = 2,
	NAPKIDSTATE_IdleChatting   = 3,
	NAPKIDSTATE_Chasing        = 4,
	NAPKIDSTATE_Outrunning     = 5,
	NAPKIDSTATE_Evading        = 6,
	NAPKIDSTATE_AttackingSetup = 7,
	NAPKIDSTATE_Attacking      = 8,
	NAPKIDSTATE_Catching       = 9,
	NAPKIDSTATE_AttackDeciding = 10,
	NAPKIDSTATE_CarryingSetup  = 11,
	NAPKIDSTATE_AttackMissing  = 12,
	NAPKIDSTATE_Carrying       = 13,
	NAPKIDSTATE_Throwing       = 14,
	NAPKIDSTATE_ShockFalling   = 15,
	NAPKIDSTATE_LoopFalling    = 16,
	NAPKIDSTATE_Landing        = 17,
	NAPKIDSTATE_Flailing       = 18,
	NAPKIDSTATE_GettingUp      = 19,
	NAPKIDSTATE_HeightDeciding = 20,
	NAPKIDSTATE_Flicking       = 21,
	NAPKIDSTATE_Rising         = 22,
	NAPKIDSTATE_COUNT, // 23
};

/**
 * @brief Napkid animation indices.
 */
enum TaiNapkidMotionID {
	NAPKIDANIM_Dead       = 0,  // 'dead'
	NAPKIDANIM_Idle       = 2,  // 'wait1'
	NAPKIDANIM_Throw      = 4,  // 'waitact1'
	NAPKIDANIM_CarryFly   = 5,  // 'waitact2'
	NAPKIDANIM_Fly        = 6,  // 'move1'
	NAPKIDANIM_Attack     = 8,  // 'attack'
	NAPKIDANIM_Flick      = 9,  // 'flick'
	NAPKIDANIM_Fall       = 10, // 'type1'
	NAPKIDANIM_Flail      = 11, // 'type2'
	NAPKIDANIM_Ascend     = 12, // 'type3'
	NAPKIDANIM_AttackMiss = 13, // 'type4'
	NAPKIDANIM_COUNT,           // 14
};

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

int t = sizeof(TaiContinuousMotionAction);

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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
struct TaiNapkidCatchFlyingAction : public TaiAction {
	inline TaiNapkidCatchFlyingAction() // TODO: this is a guess
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
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
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
