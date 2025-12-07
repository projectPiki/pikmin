#ifndef _TAI_USUBA_H
#define _TAI_USUBA_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Usuba (ウスバ) [Unused Enemy] ///////////

/**
 * @brief TODO
 */
enum TAIusubaStateID {
	USUBASTATE_Die = 0,
	USUBASTATE_Fly = 1,
	USUBASTATE_COUNT, // 2
};

/**
 * @brief TODO
 */
struct TAIusubaSoundTable : public PaniSoundTable {
	TAIusubaSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIusubaParameters : public TekiParameters {
	TAIusubaParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TAIusubaStrategy : public YaiStrategy {
	TAIusubaStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy
};

/**
 * @brief TODO
 */
struct TAIusubaAnimation : public TAIanimation {
	TAIusubaAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/usuba/anims.bun") // yep, really had this.
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
};

#endif
