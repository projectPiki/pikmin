#ifndef _TAI_OTAMA_H
#define _TAI_OTAMA_H

#include "types.h"
#include "TAI/Areaction.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"

/////////// Wolpole AI Actions ///////////

/*
 * @brief TODO
 */
struct TAIotamaSoundTable {
	TAIotamaSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIotamaParameters : public TekiParameters {
	TAIotamaParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
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
	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIArunAwayOtama : public TAIAreserveMotion {
	inline TAIArunAwayOtama() // TODO: this is a guess
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
struct TAIAappealOtama : public TAIAflickingReserveMotion {
	inline TAIAappealOtama() // TODO: this is a guess
	{
	}

	virtual void flick(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAflickingReserveMotion?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsetTargetOtama : public TAIAsetTargetPointCircleRandom {
	inline TAIAsetTargetOtama() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TAIAsetTargetPointCircleRandom?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwaitOtama : public TAIAreserveMotion {
	inline TAIAwaitOtama() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

#endif
