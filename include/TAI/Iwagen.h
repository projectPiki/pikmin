#ifndef _TAI_IWAGEN_H
#define _TAI_IWAGEN_H

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"
#include "types.h"

/////////// Rock AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiIwagonStateID {
	IWAGONSTATE_Die  = 0,
	IWAGONSTATE_Roll = 1,
	IWAGONSTATE_COUNT, // 2
};

/**
 * @brief TODO
 */
struct TaiIwagonParameters : public TekiParameters {
	TaiIwagonParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiIwagonSoundTable : public PaniSoundTable {
	TaiIwagonSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiIwagonStrategy : public TaiStrategy {
	TaiIwagonStrategy(TekiParameters*);

	virtual void start(Teki&); // _08

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

/**
 * @brief TODO
 */
struct TaiIwagonDustEffectAction : public TaiAction {
	TaiIwagonDustEffectAction()
	    : TaiAction(TAI_NO_TRANSIT)
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
	TaiIwagonRollingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/////////// Rock Spawner (unused) AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiIwagenFloatParams {
	IWAGENPF_IwagonScale = TPF_COUNT,
	IWAGENPF_COUNT, // 51
};

/**
 * @brief TODO
 */
enum TaiIwagenStateID {
	IWAGENSTATE_Wait  = 0,
	IWAGENSTATE_Shoot = 1,
	IWAGENSTATE_Reset = 2,
	IWAGENSTATE_COUNT, // 3
};

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
	TaiIwagenShootingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
