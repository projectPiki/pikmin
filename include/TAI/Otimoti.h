#ifndef _TAI_OTIMOTI_H
#define _TAI_OTIMOTI_H

#include "types.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

/////////// Frog (Yellow and White) AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiOtimotiSoundTable : public PaniSoundTable {
	TaiOtimotiSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiOtimotiParameters : public TekiParameters {
	TaiOtimotiParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiBlackFrogSoundTable : public PaniSoundTable {
	TaiBlackFrogSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiBlackFrogParameters : public TekiParameters {
	TaiBlackFrogParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiOtimotiStrategy : public TaiStrategy {
	TaiOtimotiStrategy(TekiParameters*);

	virtual void start(Teki&);                    // _08
	virtual void draw(Teki&, Graphics&);          // _18
	virtual void drawDebugInfo(Teki&, Graphics&); // _1C

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiStartDroppingWaterAction : public TaiAction {
	inline TaiOtimotiStartDroppingWaterAction() // TODO: this is a guess
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
struct TaiOtimotiFlickAction : public TaiAction {
	inline TaiOtimotiFlickAction() // TODO: this is a guess
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
struct TaiOtimotiFailToJumpAction : public TaiAction {
	inline TaiOtimotiFailToJumpAction() // TODO: this is a guess
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
struct TaiOtimotiJumpingAction : public TaiAction {
	inline TaiOtimotiJumpingAction() // TODO: this is a guess
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
struct TaiOtimotiAirWaitingAction : public TaiAction {
	inline TaiOtimotiAirWaitingAction() // TODO: this is a guess
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
struct TaiOtimotiDroppingAction : public TaiAction {
	inline TaiOtimotiDroppingAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);           // _08
	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiPressingAction : public TaiAction {
	inline TaiOtimotiPressingAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);           // _08
	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiBouncingAction : public TaiAction {
	inline TaiOtimotiBouncingAction() // TODO: this is a guess
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
struct TaiOtimotiAttackingAction : public TaiAction {
	inline TaiOtimotiAttackingAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);           // _08
	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiAttackingEffectAction : public TaiAction {
	inline TaiOtimotiAttackingEffectAction() // TODO: this is a guess
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
struct TaiOtimotiLegEffectAction : public TaiJointEffectAction {
	TaiOtimotiLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

#endif
