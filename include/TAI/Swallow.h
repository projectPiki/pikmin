#ifndef _TAI_SWALLOW_H
#define _TAI_SWALLOW_H

#include "types.h"
#include "TAI/MotionActions.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

/////////// (Big) Bulborb AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiSwallowSoundTable : public PaniSoundTable {
	TaiSwallowSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiSwallowParameters : public TekiParameters {
	TaiSwallowParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiBlackSwallowParameters : public TekiParameters {
	TaiBlackSwallowParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiSwallowStrategy : public TaiStrategy {
	TaiSwallowStrategy(TekiParameters*);

	virtual void start(Teki&);                         // _08
	virtual void draw(Teki&, Graphics&);               // _18
	virtual void drawDebugInfo(Teki&, Graphics&);      // _1C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	bool isSleeping(Teki&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowReceiveMessageAction : public TaiAction {
	inline TaiSwallowReceiveMessageAction() // TODO: this is a guess
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
struct TaiSwallowTurningAction : public TaiContinuousMotionAction {
	inline TaiSwallowTurningAction() // TODO: this is a guess
	    : TaiContinuousMotionAction(0, 0)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiContinuousMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowFlickingAction : public TaiMotionAction {
	inline TaiSwallowFlickingAction() // TODO: this is a guess
	    : TaiMotionAction(-1, 0)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	void flick(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowSwallowingFlickAction : public TaiAction {
	inline TaiSwallowSwallowingFlickAction() // TODO: this is a guess
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
struct TaiSwallowSnoreAction : public TaiAction {
	inline TaiSwallowSnoreAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowNoticeAction : public TaiAction {
	inline TaiSwallowNoticeAction() // TODO: this is a guess
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
struct TaiSwallowLegEffectAction : public TaiJointEffectAction {
	TaiSwallowLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowMissAttackingEffectAction : public TaiJointEffectAction {
	TaiSwallowMissAttackingEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

#endif
