#ifndef _TAI_MIZINKO_H
#define _TAI_MIZINKO_H

#include "types.h"
#include "TAI/TimerActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

/////////// Honeywisp Spawner AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiMizigenStateID {
	MIZIGENSTATE_Wait     = 0,
	MIZIGENSTATE_Generate = 1,
	MIZIGENSTATE_COUNT, // 2
};

/**
 * @brief TODO
 */
struct TaiMizigenParameters : public TekiParameters {
	TaiMizigenParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiMizigenStrategy : public TaiStrategy {
	TaiMizigenStrategy(TekiParameters*);

	virtual void start(Teki&); // _08

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizigenGeneratingAction : public TaiAction {
	TaiMizigenGeneratingAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiMizigenNaviApprouchAction : public TaiAction {
	TaiMizigenNaviApprouchAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/////////// Honeywisp AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiMizinkoFloatParams {
	MIZINKOPF_DropDistance = TPF_COUNT,  // 50
	MIZINKOPF_PathDistance,              // 51
	MIZINKOPF_FlyingAwayVelocity,        // 52
	MIZINKOPF_FlyingAwayAccel,           // 53
	MIZINKOPF_FadePeriod,                // 54
	MIZINKOPF_HidingPeriod,              // 55
	MIZINKOPF_HidingPeriodRandomRate,    // 56
	MIZINKOPF_FlightHeightRandomRate,    // 57
	MIZINKOPF_FlightAmplitude,           // 58
	MIZINKOPF_FlightAmplitudeRandomRate, // 59
	MIZINKOPF_AngularVelocity,           // 60
	MIZINKOPF_AngularVelocityRandomRate, // 61
	MIZINKOPF_CryPeriod,                 // 62
	MIZINKOPF_CryPeriodRandomRate,       // 63
	MIZINKOPF_COUNT,                     // 64
};

/**
 * @brief TODO
 */
enum TaiMizinkoStateID {
	MIZINKOSTATE_Going       = 0,
	MIZINKOSTATE_HidingDest  = 1,
	MIZINKOSTATE_Coming      = 2,
	MIZINKOSTATE_HidingStart = 3,
	MIZINKOSTATE_DropWater   = 4,
	MIZINKOSTATE_FlyingAway  = 5,
	MIZINKOSTATE_Dead        = 6,
	MIZINKOSTATE_COUNT, // 7
};

/**
 * @brief TODO
 */
struct TaiMizinkoSoundTable : public PaniSoundTable {
	TaiMizinkoSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoParameters : public TekiParameters {
	TaiMizinkoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoStrategy : public TaiStrategy {
	TaiMizinkoStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	bool hasWater(Teki&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoCryTimerAction : public TaiTimerAction {
	TaiMizinkoCryTimerAction(int p1, f32 p2, f32 p3)
	    : TaiTimerAction(TAI_NO_TRANSIT, p1, p2, p3)
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
struct TaiMizinkoMovingTimerAction : public TaiTimerAction {
	TaiMizinkoMovingTimerAction(int nextState)
	    : TaiTimerAction(nextState, 0, 0.0f, 0.0f)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_10 = TaiTimerAction
};

/**
 * @brief TODO
 */
struct TaiMizinkoFadingAction : public TaiAction {
	TaiMizinkoFadingAction()
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
struct TaiMizinkoGoingAction : public TaiAction {
	TaiMizinkoGoingAction()
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
struct TaiMizinkoComingAction : public TaiAction {
	TaiMizinkoComingAction()
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
struct TaiMizinkoDropWaterAction : public TaiAction {
	TaiMizinkoDropWaterAction()
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
struct TaiMizinkoWaitingAction : public TaiAction {
	TaiMizinkoWaitingAction()
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
struct TaiMizinkoFlyingAwayAction : public TaiAction {
	TaiMizinkoFlyingAwayAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
