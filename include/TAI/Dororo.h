#ifndef _TAI_DORORO_H
#define _TAI_DORORO_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/Amove.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

struct CollPart;

/////////// Smoky Progg AI Actions ///////////

/*
 * @brief TODO
 */
struct TAIdororoSoundTable : public PaniSoundTable {
	TAIdororoSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIdororoParameters : public TekiParameters {
	TAIdororoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIdororoStrategy : public YaiStrategy {
	TAIdororoStrategy();

	virtual void start(Teki&);             // _08
	virtual void act(Teki&);               // _0C
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	void createCloudOfDust(Teki&, CollPart*);

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIdororoAnimation : public TAIanimation {
	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitDororo : public TaiAction {
	inline TAIAinitDororo() // TODO: this is a guess
	    : TaiAction(-1)
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
struct TAIAgravityDororo : public TaiAction {
	inline TAIAgravityDororo() // TODO: this is a guess
	    : TaiAction(-1)
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
struct TAIAcheckBarkDororo : public TaiAction {
	inline TAIAcheckBarkDororo() // TODO: this is a guess
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
struct TAIAbarkDororo : public TAIAmotionLoop {
	inline TAIAbarkDororo() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAmotionLoop?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtransformationDororo : public TAIAreserveMotion {
	inline TAIAtransformationDororo() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAbirthDororo : public TAIAreserveMotion {
	inline TAIAbirthDororo() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwaitDororo : public TAIAwait {
	inline TAIAwaitDororo() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);            // _08
	virtual f32 getWaitCounterMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAwait?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingDororo : public TAIAflicking {
	inline TAIAflickingDororo() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoGoalPathDororo : public TAIAgoGoalPath {
	inline TAIAgoGoalPathDororo() // TODO: this is a guess
	{
	}

	virtual f32 getWalkVelocity(Teki&); // _20

	// _04     = VTBL
	// _00-_08 = TAIAgoGoalPath?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAkillTouchPiki : public TaiAction {
	inline TAIAkillTouchPiki() // TODO: this is a guess
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
struct TAIAdyingDororo : public TAIAdying {
	inline TAIAdyingDororo() // TODO: this is a guess
	    : TAIAdying(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

#endif
