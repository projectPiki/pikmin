#ifndef _TAI_AREACTION_H
#define _TAI_AREACTION_H

#include "types.h"
#include "TAI/Amotion.h"

/**
 * @brief TODO
 */
struct TAIAhitCheckFlyingPiki : public TaiAction {
	inline TAIAhitCheckFlyingPiki() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdeadCheck : public TaiAction {
	inline TAIAdeadCheck() // TODO: this is a guess
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
struct TAIAdie : public TaiAction {
	inline TAIAdie() // TODO: this is a guess
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
struct TAIAdying : public TAIAmotion {
	inline TAIAdying() // TODO: this is a guess
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
struct TAIAdyingKabekui : public TAIAdying {
	inline TAIAdyingKabekui() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdyingCrushKabekui : public TAIAdyingKabekui {
	inline TAIAdyingCrushKabekui() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_0C = TAIAdyingKabekui?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdamage : public TaiAction {
	inline TAIAdamage() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&);         // _10
	virtual bool judgeDamage(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinWater : public TaiAction {
	inline TAIAinWater() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinWaterDamage : public TAIAinWater {
	inline TAIAinWaterDamage() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	void createEffect(Teki&);

	// _04     = VTBL
	// _00-_08 = TAIAinWater?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAnoReaction : public TaiAction {
	inline TAIAnoReaction() // TODO: this is a guess
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
struct TAIAtimerReaction : public TaiAction {
	inline TAIAtimerReaction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinvincibleOff : public TaiAction {
	inline TAIAinvincibleOff() // TODO: this is a guess
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
struct TAIAinvincibleOn : public TaiAction {
	inline TAIAinvincibleOn() // TODO: this is a guess
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
struct TAIAshadowOff : public TaiAction {
	inline TAIAshadowOff() // TODO: this is a guess
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
struct TAIAshadowOn : public TaiAction {
	inline TAIAshadowOn() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
