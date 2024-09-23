#ifndef _TAI_IWAGEN_H
#define _TAI_IWAGEN_H

#include "types.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

/////////// Rock AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiIwagonParameters : public TekiParameters {
	TaiIwagonParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiIwagonSoundTable {
	TaiIwagonSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiIwagonStrategy : public TaiStrategy {
	TaiIwagonStrategy(TekiParameters*);

	virtual void start(Teki&); // _08

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiIwagonDustEffectAction : public TaiAction {
	inline TaiIwagonDustEffectAction() // TODO: this is a guess
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
struct TaiIwagonRollingAction : public TaiAction {
	inline TaiIwagonRollingAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/////////// Rock Spawner (unused) AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiIwagenParameters : public TekiParameters {
	TaiIwagenParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiIwagenStrategy : public TaiStrategy {
	TaiIwagenStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiIwagenShootingAction : public TaiAction {
	inline TaiIwagenShootingAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
