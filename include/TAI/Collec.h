#ifndef _TAI_COLLEC_H
#define _TAI_COLLEC_H

#include "types.h"
#include "TAI/TimerActions.h"
#include "TAI/MotionActions.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

struct NVector3f;

/////////// Breadbug AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiCollecIntParams {
	COLLECPI_CarryPower = TPI_COUNT,
	COLLECPI_COUNT, // 21
};

/**
 * @brief TODO
 */
enum TaiCollecFloatParams {
	COLLECPF_BouncingDamage = TPF_COUNT,  // 50
	COLLECPF_PressedDamage,               // 51
	COLLECPF_GoingUndergroundDistance,    // 52
	COLLECPF_UndergroundPeriod,           // 53
	COLLECPF_UndergroundPeriodRandomRate, // 54
	COLLECPF_FallingRotationVelocity,     // 55
	COLLECPF_DangerLife,                  // 56
	COLLECPF_RunningAwayPeriod,           // 57
	COLLECPF_ImpassablePeriod,            // 58
	COLLECPF_ImpassableDistance,          // 59
	COLLECPF_COUNT,                       // 60
};

/**
 * @brief TODO
 */
enum TaiCollecStateID {
	COLLECSTATE_Unk0  = 0,
	COLLECSTATE_Unk1  = 1,
	COLLECSTATE_Unk2  = 2,
	COLLECSTATE_Unk3  = 3,
	COLLECSTATE_Unk4  = 4,
	COLLECSTATE_Unk5  = 5,
	COLLECSTATE_Unk6  = 6,
	COLLECSTATE_Unk7  = 7,
	COLLECSTATE_Unk8  = 8,
	COLLECSTATE_Unk9  = 9,
	COLLECSTATE_Unk10 = 10,
	COLLECSTATE_Unk11 = 11,
	COLLECSTATE_Unk12 = 12,
	COLLECSTATE_Unk13 = 13,
	COLLECSTATE_Unk14 = 14,
	COLLECSTATE_COUNT, // 15
};

/**
 * @brief TODO
 */
struct TaiCollecSoundTable : public PaniSoundTable {
	TaiCollecSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecParameters : public TekiParameters {
	TaiCollecParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecStrategy : public TaiStrategy {
	TaiCollecStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// unused/inlined:
	void outputUndergroundPosition(Teki&, NVector3f&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecImpassableAction : public TaiAction {
	TaiCollecImpassableAction(int nextState, int p2, f32 p3, f32 p4)
	    : TaiAction(nextState)
	{
		mTimerIdx    = p2;
		mTimerLength = p3;
		mMaxDistance = p4;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetPosition(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx;    // _08
	f32 mTimerLength; // _0C
	f32 mMaxDistance; // _10
};

/**
 * @brief TODO
 */
struct TaiCollecLetGoOfPelletAction : public TaiAction {
	TaiCollecLetGoOfPelletAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecTargetPelletAction : public TaiAction {
	TaiCollecTargetPelletAction(int nextState)
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
struct TaiCollecVisibleHeightPelletLostAction : public TaiAction {
	TaiCollecVisibleHeightPelletLostAction(int nextState)
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
struct TaiCollecVisibleHeightPelletLostTimerAction : public TaiTimerAction {
	TaiCollecVisibleHeightPelletLostTimerAction(int timerIdx, f32 timerLength)
	    : TaiTimerAction(TAI_NO_TRANSIT, timerIdx, timerLength, 0.0f)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiTimerAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecPelletLostAction : public TaiAction {
	TaiCollecPelletLostAction(int nextState)
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
struct TaiCollecPelletDisappearedAction : public TaiAction {
	TaiCollecPelletDisappearedAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiCollecHoldPelletAction : public TaiAction {
	TaiCollecHoldPelletAction(int nextState)
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
struct TaiCollecCatchingAction : public TaiAction {
	TaiCollecCatchingAction()
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
struct TaiCollecCarryingAction : public TaiAction {
	TaiCollecCarryingAction(int nextState)
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
struct TaiCollecBeingDraggedAction : public TaiAction {
	TaiCollecBeingDraggedAction()
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
struct TaiCollecWinCarryingAction : public TaiAction {
	TaiCollecWinCarryingAction(int nextState)
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
struct TaiCollecDefeatCarryingAction : public TaiAction {
	TaiCollecDefeatCarryingAction(int nextState)
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
struct TaiCollecPutAction : public TaiAction {
	TaiCollecPutAction(int nextState)
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
struct TaiCollecPuttingPelletAction : public TaiAction {
	TaiCollecPuttingPelletAction(int nextState)
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
struct TaiCollecCarryingToNestAction : public TaiContinuousMotionAction {
	TaiCollecCarryingToNestAction(int nextState, int motionIdx, int p3)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		_0C = p3;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void makePositionRoute(Teki&);

	// _04     = VTBL
	// _00-_0C = TaiContinuousMotionAction
	int _0C; // _0C
};

/**
 * @brief TODO
 */
struct TaiCollecRouteImpassableAction : public TaiAction {
	TaiCollecRouteImpassableAction(int nextState)
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
struct TaiCollecRoundCarryAction : public TaiAction {
	TaiCollecRoundCarryAction()
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
struct TaiCollecPelletStartContainerizedAction : public TaiAction {
	TaiCollecPelletStartContainerizedAction(int nextState)
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
struct TaiCollecPelletFinishContainerizedAction : public TaiAction {
	TaiCollecPelletFinishContainerizedAction(int nextState)
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
struct TaiCollecDeadFallingAction : public TaiAction {
	TaiCollecDeadFallingAction(int nextState)
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
struct TaiCollecFallingAction : public TaiAction {
	TaiCollecFallingAction(int nextState)
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
struct TaiCollecGetOutAction : public TaiAction {
	TaiCollecGetOutAction()
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
struct TaiCollecLegEffectAction : public TaiJointEffectAction {
	TaiCollecLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/////////// Breadbug Nest AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiHollecStateID {
	HOLLECSTATE_Unk0 = 0,
	HOLLECSTATE_COUNT, // 1
};

/**
 * @brief TODO
 */
struct TaiHollecParameters : public TekiParameters {
	TaiHollecParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiHollecStrategy : public TaiStrategy {
	TaiHollecStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

#endif
