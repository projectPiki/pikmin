#ifndef _TAI_AREACTION_H
#define _TAI_AREACTION_H

#include "EffectMgr.h"
#include "TAI/Amotion.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TAIAhitCheckFlyingPiki : public TaiAction {
public:
	inline TAIAhitCheckFlyingPiki(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(immut TekiEvent&); // _14

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdeadCheck : public TaiAction {
public:
	TAIAdeadCheck(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdie : public TaiAction {
public:
	inline TAIAdie() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdying : public TAIAmotion {
public:
	TAIAdying(int nextState, int motionID)
	    : TAIAmotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAmotion
};

/**
 * @brief TODO
 */
struct TAIAdyingKabekui : public TAIAdying {
public:
	TAIAdyingKabekui(int nextState, int motionID, EffectMgr::effTypeTable effID)
	    : TAIAdying(nextState, motionID)
	{
		mEffectType = effID;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAdying
	EffectMgr::effTypeTable mEffectType; // _0C
};

/**
 * @brief TODO
 */
struct TAIAdyingCrushKabekui : public TAIAdyingKabekui {
public:
	TAIAdyingCrushKabekui(int nextState, int motionID, EffectMgr::effTypeTable effID)
	    : TAIAdyingKabekui(nextState, motionID, effID)
	{
	}

	virtual void start(Teki&); // _08

protected:
	// _04     = VTBL
	// _00-_10 = TAIAdyingKabekui
};

/**
 * @brief TODO
 */
struct TAIAdamage : public TaiAction {
public:
	TAIAdamage(int nextState, bool p2)
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual bool act(Teki&); // _10

protected:
	virtual bool judgeDamage(Teki&) { return true; } // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	bool _08; // _08
};

/**
 * @brief TODO
 */
struct TAIAinWater : public TaiAction {
public:
	TAIAinWater(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&);                   // _10
	virtual bool actByEvent(immut TekiEvent&); // _14

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinWaterDamage : public TAIAinWater {
public:
	TAIAinWaterDamage(int nextState, f32 damage, bool p3)
	    : TAIAinWater(nextState)
	{
		mDamage = damage;
		_0C     = p3;
	}

	virtual bool act(Teki&);                   // _10
	virtual bool actByEvent(immut TekiEvent&); // _14

protected:
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
public:
	TAIAnoReaction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&) { return true; } // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtimerReaction : public TaiAction {
public:
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

protected:
	virtual f32 getFrameMax(Teki& teki) { return mFrameMax; } // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mFrameMax; // _08
};

/**
 * @brief TODO
 */
struct TAIAinvincibleOff : public TaiAction {
public:
	inline TAIAinvincibleOff(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.clearTekiOption(Teki::TEKI_OPTION_INVINCIBLE);
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinvincibleOn : public TaiAction {
public:
	inline TAIAinvincibleOn(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.setTekiOption(Teki::TEKI_OPTION_INVINCIBLE);
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAshadowOff : public TaiAction {
public:
	inline TAIAshadowOff(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.clearTekiOption(Teki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
		teki.clearTekiOption(Teki::TEKI_OPTION_SHADOW_VISIBLE);
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAshadowOn : public TaiAction {
public:
	inline TAIAshadowOn(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.setTekiOption(Teki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
		teki.setTekiOption(Teki::TEKI_OPTION_SHADOW_VISIBLE);
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
