#ifndef _TAI_KINOKO_H
#define _TAI_KINOKO_H

#include "types.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"

/////////// Puffstool AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiKinokoSoundTable {
	TaiKinokoSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiKinokoParameters : public TekiParameters {
	TaiKinokoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiKinokoStrategy : public TaiStrategy {
	TaiKinokoStrategy(TekiParameters*);

	virtual void start(Teki&);             // _08
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiKinokoTurningOverAction : public TaiAction {
	inline TaiKinokoTurningOverAction() // TODO: this is a guess
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
struct TaiKinokoChargingSporesAction : public TaiAction {
	inline TaiKinokoChargingSporesAction() // TODO: this is a guess
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
struct TaiKinokoDischargingSporesAction : public TaiAction {
	inline TaiKinokoDischargingSporesAction() // TODO: this is a guess
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
struct TaiKinokoTerritoryRunningAwayAction : public TaiAction {
	inline TaiKinokoTerritoryRunningAwayAction() // TODO: this is a guess
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
struct TaiKinokoLegEffectAction : public TaiJointEffectAction {
	TaiKinokoLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

#endif
