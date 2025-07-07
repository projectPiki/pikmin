#ifndef _TAI_KINOKO_H
#define _TAI_KINOKO_H

#include "PaniAnimator.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"
#include "types.h"

/////////// Puffstool AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiKinokoFloatParams {
	KINOKOPF_TurningAwayPeriod = TPF_COUNT, // 50
	KINOKOPF_RunningAwayPeriod,             // 51
	KINOKOPF_FlickPeriod,                   // 52
	KINOKOPF_StandingUpPeriod,              // 53
	KINOKOPF_StandingDamageRate,            // 54
	KINOKOPF_NormalEyeScale,                // 55
	KINOKOPF_AngryEyeScale,                 // 56
	KINOKOPF_WaitingPeriod,                 // 57
	KINOKOPF_SlowTurnVelocity,              // 58
	KINOKOPF_GoingHomeTerritoryRange,       // 59
	KINOKOPF_COUNT,                         // 60
};

/**
 * @brief TODO
 */
enum TaiKinokoIntParams {
	KINOKOPI_TurningOverDamageCount = TPI_COUNT, // 20
	KINOKOPI_FlickLoopCount,                     // 21
	KINOKOPI_COUNT,                              // 22
};

/**
 * @brief TODO
 */
enum TaiKinokoStateID {
	KINOKOSTATE_DeadUpright     = 0,
	KINOKOSTATE_DeadFlipped     = 1,
	KINOKOSTATE_Wait            = 2,
	KINOKOSTATE_TurningAway     = 3,
	KINOKOSTATE_RunningAway     = 4,
	KINOKOSTATE_TurningOver     = 5,
	KINOKOSTATE_Flipped         = 6,
	KINOKOSTATE_Flick           = 7,
	KINOKOSTATE_SporeAttackFlip = 8,
	KINOKOSTATE_UnusedMotion    = 9,
	KINOKOSTATE_TurnToHome      = 10,
	KINOKOSTATE_GoingHome       = 11,
	KINOKOSTATE_SporeAttackRun  = 12,
	KINOKOSTATE_COUNT, // 13
};

/**
 * @brief TODO
 */
struct TaiKinokoSoundTable : public PaniSoundTable {
	TaiKinokoSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiKinokoParameters : public TekiParameters {
	TaiKinokoParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiKinokoStrategy : public TaiStrategy {
	TaiKinokoStrategy(TekiParameters*);

	virtual void start(Teki&);             // _08
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

/**
 * @brief TODO
 */
struct TaiKinokoTurningOverAction : public TaiAction {
	TaiKinokoTurningOverAction()
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
struct TaiKinokoChargingSporesAction : public TaiAction {
	TaiKinokoChargingSporesAction()
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
struct TaiKinokoDischargingSporesAction : public TaiAction {
	TaiKinokoDischargingSporesAction()
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
struct TaiKinokoTerritoryRunningAwayAction : public TaiAction {
	TaiKinokoTerritoryRunningAwayAction()
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
struct TaiKinokoLegEffectAction : public TaiJointEffectAction {
	TaiKinokoLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

#endif
