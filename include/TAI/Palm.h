#ifndef _TAI_PALM_H
#define _TAI_PALM_H

#include "PaniAnimator.h"
#include "TAI/MotionActions.h"
#include "TAI/ReactionActions.h"
#include "TekiParameters.h"
#include "types.h"

/////////// Pellet Posy AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiPalmFloatParams {
	PALMPF_ChangingColorPeriod = TPF_COUNT, // 50
	PALMPF_ChangingColorPeriodRandomRate,   // 51
	PALMPF_GrowingPeriod,                   // 52
	PALMPF_COUNT,                           // 53
};

/**
 * @brief TODO
 */
enum TaiPalmStateID {
	PALMSTATE_Dead   = 0,
	PALMSTATE_Damage = 1,
	PALMSTATE_Grow   = 2,
	PALMSTATE_Normal = 3,
	PALMSTATE_COUNT, // 4
};

/**
 * @brief TODO
 */
struct TaiPalmSoundTable : public PaniSoundTable {
	TaiPalmSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiPalmParameters : public TekiParameters {
	TaiPalmParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiPalmStrategy : public TaiStrategy {
	TaiPalmStrategy(TekiParameters*);

	virtual void start(Teki&);             // _08
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	int translateMotionIndex(Teki&, int);

	// _00     = VTBL
	// _00-_14 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiPalmMotionAction : public TaiMotionAction {
	TaiPalmMotionAction(int nextState, int p2)
	    : TaiMotionAction(nextState, p2)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiPalmDyingAction : public TaiDyingAction {
	TaiPalmDyingAction(int p1)
	    : TaiDyingAction(p1)
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
struct TaiPalmDamagingAction : public TaiDamagingAction {
	TaiPalmDamagingAction(int nextState, int p2)
	    : TaiDamagingAction(nextState, p2)
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
struct TaiPalmGrowingAction : public TaiAction {
	TaiPalmGrowingAction()
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
struct TaiPalmGrowAction : public TaiAction {
	TaiPalmGrowAction(int nextState, int p2)
	    : TaiAction(nextState)
	{
		mTimerIdx = p2;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx; // _08
};

/**
 * @brief TODO
 */
struct TaiPalmFlowerDamageAction : public TaiAction {
	TaiPalmFlowerDamageAction(int nextState)
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
struct TaiPalmSunflowerAction : public TaiAction {
	TaiPalmSunflowerAction()
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
struct TaiPalmSettingPelletAction : public TaiAction {
	TaiPalmSettingPelletAction()
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
struct TaiPalmChangingColorAction : public TaiAction {
	TaiPalmChangingColorAction(int p1, f32 p2, f32 p3)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mTimerIdx      = p1;
		mAvgTimerValue = p2;
		mTimerRange    = p3;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetTimer(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx;      // _08
	f32 mAvgTimerValue; // _0C
	f32 mTimerRange;    // _10
};

#endif
