#ifndef _TAI_SWALLOW_H
#define _TAI_SWALLOW_H

#include "PaniAnimator.h"
#include "TAI/EffectActions.h"
#include "TAI/MotionActions.h"
#include "TekiParameters.h"
#include "types.h"

/////////// (Big) Bulborb AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiSwallowFloatParams {
	SWALLOWPF_NoticeDistance = TPF_COUNT, // 50
	SWALLOWPF_LowerDamageRate,            // 51
	SWALLOWPF_LowerDamageCountRate,       // 52
	SWALLOWPF_TurnVelocityFuncMaxCount,   // 53
	SWALLOWPF_TurnVelocityFuncMaxRate,    // 54
	SWALLOWPF_FlickLowerAngle,            // 55
	SWALLOWPF_COUNT,                      // 56
};

/**
 * @brief TODO
 */
enum TaiSwallowStateID {
	SWALLOWSTATE_Unk0  = 0,
	SWALLOWSTATE_Unk1  = 1,
	SWALLOWSTATE_Unk2  = 2,
	SWALLOWSTATE_Unk3  = 3,
	SWALLOWSTATE_Unk4  = 4,
	SWALLOWSTATE_Unk5  = 5,
	SWALLOWSTATE_Unk6  = 6,
	SWALLOWSTATE_Unk7  = 7,
	SWALLOWSTATE_Unk8  = 8,
	SWALLOWSTATE_Unk9  = 9,
	SWALLOWSTATE_Unk10 = 10,
	SWALLOWSTATE_Unk11 = 11,
	SWALLOWSTATE_Unk12 = 12,
	SWALLOWSTATE_Unk13 = 13,
	SWALLOWSTATE_Unk14 = 14,
	SWALLOWSTATE_Unk15 = 15,
	SWALLOWSTATE_COUNT, // 16
};

/**
 * @brief TODO
 */
struct TaiSwallowSoundTable : public PaniSoundTable {
	TaiSwallowSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiSwallowParameters : public TekiParameters {
	TaiSwallowParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiBlackSwallowParameters : public TekiParameters {
	TaiBlackSwallowParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiSwallowStrategy : public TaiStrategy {
	TaiSwallowStrategy(TekiParameters*);

	virtual void start(Teki&);                         // _08
	virtual void draw(Teki&, Graphics&);               // _18
	virtual void drawDebugInfo(Teki&, Graphics&);      // _1C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	bool isSleeping(Teki&);

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

/**
 * @brief TODO
 */
struct TaiSwallowReceiveMessageAction : public TaiAction {
	TaiSwallowReceiveMessageAction(int nextState, int p2)
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiSwallowTurningAction : public TaiContinuousMotionAction {
	TaiSwallowTurningAction(int nextState, int motionIdx, f32 turnSpeed)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mTurnSpeed = turnSpeed;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTurnSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiSwallowFlickingAction : public TaiMotionAction {
	TaiSwallowFlickingAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	void flick(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowSwallowingFlickAction : public TaiAction {
	inline TaiSwallowSwallowingFlickAction() // TODO: this is a guess
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
struct TaiSwallowSnoreAction : public TaiAction {
	TaiSwallowSnoreAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowNoticeAction : public TaiAction {
	TaiSwallowNoticeAction(int nextState)
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
struct TaiSwallowLegEffectAction : public TaiJointEffectAction {
	TaiSwallowLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowMissAttackingEffectAction : public TaiJointEffectAction {
	TaiSwallowMissAttackingEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

#endif
