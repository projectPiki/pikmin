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
	NAPKIDPF_Unk1,
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
	NAPKIDSTATE_Dying,
	NAPKIDSTATE_Unk1,
	NAPKIDSTATE_Unk2,
	NAPKIDSTATE_Unk3,
	NAPKIDSTATE_Unk4,
	NAPKIDSTATE_Unk5,
	NAPKIDSTATE_Unk6,
	NAPKIDSTATE_Unk7,
	NAPKIDSTATE_Unk8,
	NAPKIDSTATE_Unk9,
	NAPKIDSTATE_Unk10,
	NAPKIDSTATE_Unk11,
	NAPKIDSTATE_Unk12,
	NAPKIDSTATE_Unk13,
	NAPKIDSTATE_Unk14,
	NAPKIDSTATE_Unk15,
	NAPKIDSTATE_Unk16,
	NAPKIDSTATE_Unk17,
	NAPKIDSTATE_Unk18,
	NAPKIDSTATE_Unk19,
	NAPKIDSTATE_Unk20,
	NAPKIDSTATE_Unk21,
	NAPKIDSTATE_Unk22,
	NAPKIDSTATE_COUNT,
};

/**
 * @brief TODO: name members
 */
enum TaiNapkidMotionID {
	NAPKIDANIM_Unk0,
	NAPKIDANIM_Unk1,
	NAPKIDANIM_Unk2,
	NAPKIDANIM_Unk3,
	NAPKIDANIM_Unk4,
	NAPKIDANIM_Unk5,
	NAPKIDANIM_Unk6,
	NAPKIDANIM_Unk7,
	NAPKIDANIM_Unk8,
	NAPKIDANIM_Unk9,
	NAPKIDANIM_Unk10,
	NAPKIDANIM_Unk11,
	NAPKIDANIM_Unk12,
	NAPKIDANIM_Unk13,
	NAPKIDANIM_COUNT,
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
	inline TaiNapkidFlyingAction(f32 p1) // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
		_08 = p1;
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
