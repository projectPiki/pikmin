#ifndef _TAI_BEATLE_H
#define _TAI_BEATLE_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Areaction.h"
#include "TAI/Ajudge.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Armored Cannon Beetle AI Actions ///////////

/*
 * @brief TODO
 */
struct TAIbeatleSoundTable : public PaniSoundTable {
	TAIbeatleSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIbeatleParameters : public TekiParameters {
	TAIbeatleParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIbeatleStrategy : public YaiStrategy {
	TAIbeatleStrategy();

	virtual void act(Teki&);                           // _0C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIbeatleAnimation : public TAIanimation {
	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitBeatle : public TaiAction {
	inline TAIAinitBeatle() // TODO: this is a guess
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
struct TAIAcheckInsideRangePikiBeatle : public TAIAcheckInsideRangePiki {
	inline TAIAcheckInsideRangePikiBeatle() // TODO: this is a guess
	{
	}

	virtual f32 getRange(Teki&); // _20

	// _04     = VTBL
	// _00-_08 = TAIAcheckInsideRangePiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdisableStick : public TaiAction {
	inline TAIAdisableStick() // TODO: this is a guess
	    : TaiAction(-1)
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
struct TAIAflickingBeatle : public TAIAflicking {
	inline TAIAflickingBeatle() // TODO: this is a guess
	{
	}

	virtual void flick(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingAfterMotionLoopBeatle : public TAIAflickingAfterMotionLoop {
	inline TAIAflickingAfterMotionLoopBeatle() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);       // _08
	virtual bool act(Teki&);         // _10
	virtual f32 getFrameMax(Teki&);  // _1C
	virtual bool permitFlick(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAflickingAfterMotionLoop?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIArockAttack : public TAIAreserveMotion {
	inline TAIArockAttack() // TODO: this is a guess
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
struct TAIAinsideOptionalRangeBeatle : public TAIAinsideOptionalRange {
	inline TAIAinsideOptionalRangeBeatle() // TODO: this is a guess
	{
	}

	virtual void setTargetPosition(Teki&); // _1C
	virtual f32 getOptionalRange(Teki&);   // _20

	// _04     = VTBL
	// _00-_08 = TAIAinsideOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAvisiblePikiBeatle : public TaiAction {
	inline TAIAvisiblePikiBeatle() // TODO: this is a guess
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
struct TAIAdamageBeatle : public TAIAdamage {
	inline TAIAdamageBeatle() // TODO: this is a guess
	{
	}

	virtual bool judgeDamage(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdyingBeatle : public TAIAdying {
	inline TAIAdyingBeatle() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

#endif
