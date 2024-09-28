#ifndef _TAI_USUBA_H
#define _TAI_USUBA_H

#include "types.h"
#include "TAI/Areaction.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Usuba (Unused Enemy) AI Actions ///////////

/*
 * @brief TODO
 */
struct TAIusubaSoundTable : public PaniSoundTable {
	TAIusubaSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIusubaParameters : public TekiParameters {
	TAIusubaParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIusubaStrategy : public YaiStrategy {
	TAIusubaStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIusubaAnimation : public TAIanimation {
	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyUsuba : public TAIAmotion {
	inline TAIAflyUsuba() // TODO: this is a guess
	    : TAIAmotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

#endif
