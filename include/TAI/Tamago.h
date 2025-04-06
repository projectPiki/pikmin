#ifndef _TAI_TAMAGO_H
#define _TAI_TAMAGO_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Giant Egg AI Actions ///////////

/*
 * @brief TODO
 */
struct TAItamagoSoundTable : public PaniSoundTable {
	TAItamagoSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAItamagoParameters : public TekiParameters {
	TAItamagoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAItamagoStrategy : public YaiStrategy {
	TAItamagoStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcountStartTamago : public TaiAction {
	inline TAIAcountStartTamago() // TODO: this is a guess
	    : TaiAction(-1)
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
struct TAIAhatch : public TAIAmotion {
	inline TAIAhatch() // TODO: this is a guess
	    : TAIAmotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtimerReactionTamago : public TAIAtimerReaction {
	inline TAIAtimerReactionTamago() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdyingTamago : public TAIAmotion {
	inline TAIAdyingTamago() // TODO: this is a guess
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
