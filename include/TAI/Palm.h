#ifndef _TAI_PALM_H
#define _TAI_PALM_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

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

#endif
