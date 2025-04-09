#ifndef _TAI_AREACTION_H
#define _TAI_AREACTION_H

#include "types.h"
#include "TAI/Amotion.h"
#include "EffectMgr.h"

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
	TAIAdeadCheck(int nextState)
	    : TaiAction(nextState)
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
	TAIAdying(int nextState, int motionID)
	    : TAIAmotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAmotion
};

/**
 * @brief TODO
 */
struct TAIAdyingKabekui : public TAIAdying {
	TAIAdyingKabekui(int nextState, int motionID, EffectMgr::effTypeTable effID)
	    : TAIAdying(nextState, motionID)
	{
		mEffectType = effID;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAdying
	EffectMgr::effTypeTable mEffectType; // _0C
};

/**
 * @brief TODO
 */
struct TAIAdyingCrushKabekui : public TAIAdyingKabekui {
	TAIAdyingCrushKabekui(int nextState, int motionID, EffectMgr::effTypeTable effID)
	    : TAIAdyingKabekui(nextState, motionID, effID)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_10 = TAIAdyingKabekui
};

/**
 * @brief TODO
 */
struct TAIAdamage : public TaiAction {
	TAIAdamage(int nextState, bool p2)
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual bool act(Teki&);                         // _10
	virtual bool judgeDamage(Teki&) { return true; } // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	bool _08; // _08
};

/**
 * @brief TODO
 */
struct TAIAinWater : public TaiAction {
	TAIAinWater(int nextState)
	    : TaiAction(nextState)
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
	TAIAinWaterDamage(int nextState, f32 damage, bool p3)
	    : TAIAinWater(nextState)
	{
		mDamage = damage;
		_0C     = p3;
	}

	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	void createEffect(Teki&);

	// _04     = VTBL
	// _00-_08 = TAIAinWater
	f32 mDamage; // _08
	bool _0C;    // _0C
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
	TAIAtimerReaction(int nextState, f32 frameMax)
	    : TaiAction(nextState)
	{
		mFrameMax = frameMax;
	}

	virtual void start(Teki& teki) // _08
	{
		teki.setFrameCounter(0.0f);
	}
	virtual bool act(Teki& teki) // _10
	{
		f32 counter = teki.addFrameCounter(gsys->getFrameTime());
		if (counter > getFrameMax(teki)) {
			return true;
		}
		return false;
	}
	virtual f32 getFrameMax(Teki& teki) { return mFrameMax; } // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mFrameMax; // _08
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
