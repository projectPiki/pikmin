#ifndef _TAI_HIBAA_H
#define _TAI_HIBAA_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Fire Geyser (間欠炎) ///////////

BEGIN_ENUM_TYPE(TAIhibaAFloatParams)
enum {
	WaitTime = TPF_COUNT, // 50
	AttackTime,           // 51
	COUNT,                // 52
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIhibaAStateID)
enum {
	Init   = 0,
	Wait   = 1,
	Attack = 2,
	COUNT, // 3
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct TAIhibaASoundTable : public PaniSoundTable {
	TAIhibaASoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIhibaAParameters : public TekiParameters {
	TAIhibaAParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIhibaAStrategy : public YaiStrategy {
	TAIhibaAStrategy();

	virtual void act(Teki&);             // _0C
	virtual void draw(Teki&, Graphics&); // _18

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIhibaAAnimation : public TAIanimation {
	TAIhibaAAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/hibaA/anims.bun") // yep, really had this.
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
