#ifndef _TAI_OTAMA_H
#define _TAI_OTAMA_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Wogpole (オタマ) ///////////

BEGIN_ENUM_TYPE(TAIotamaFloatParams)
enum {
	MinWaitTime = TPF_COUNT, // 50
	MaxWaitTime,             // 51
	COUNT,                   // 52
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIotamaStateID)
enum {
	Dead         = 0,
	Wait         = 1,
	SetTarget    = 2,
	GoTarget     = 3,
	AppealTarget = 4,
	AppealRun    = 5,
	RunAway      = 6,
	COUNT, // 7
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct TAIotamaSoundTable : public PaniSoundTable {
	TAIotamaSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIotamaParameters : public TekiParameters {
	TAIotamaParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIotamaStrategy : public YaiStrategy {
	TAIotamaStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIotamaAnimation : public TAIanimation {
	TAIotamaAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/otama/anims.bun") // yep, really had this.
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
