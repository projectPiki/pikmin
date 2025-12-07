#ifndef _TAI_TAMAGO_H
#define _TAI_TAMAGO_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Giant Egg AI Actions ///////////

/**
 * @brief TODO
 */
enum TAItamagoStateID {
	TAMAGOSTATE_Dead      = 0,
	TAMAGOSTATE_Wait      = 1,
	TAMAGOSTATE_CountDown = 2,
	TAMAGOSTATE_Hatch     = 3,
	TAMAGOSTATE_COUNT, // 4
};

/**
 * @brief TODO
 */
enum TAItamagoFloatParams {
	TAMAGOPF_MinEmergenceTime = TPF_COUNT, // 50
	TAMAGOPF_MaxEmergenceTime,             // 51
	TAMAGOPF_COUNT,                        // 52
};

/**
 * @brief TODO
 */
struct TAItamagoSoundTable : public PaniSoundTable {
	TAItamagoSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TAItamagoParameters : public TekiParameters {
	TAItamagoParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TAItamagoStrategy : public YaiStrategy {
	TAItamagoStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy
};

/**
 * @brief TODO
 */
struct TAItamagoAnimation : public TAIanimation {
	TAItamagoAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/tamago/anims.bun") // yep, they really had this
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
};

#endif
