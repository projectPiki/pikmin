#ifndef _TAI_MIZINKO_H
#define _TAI_MIZINKO_H

#include "types.h"
#include "TAI/TimerActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

/////////// Honeywisp Spawner AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiMizigenParameters : public TekiParameters {
	TaiMizigenParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiMizigenStrategy : public TaiStrategy {
	TaiMizigenStrategy(TekiParameters*);

	virtual void start(Teki&); // _08

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizigenGeneratingAction : public TaiAction {
	inline TaiMizigenGeneratingAction() // TODO: this is a guess
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
struct TaiMizigenNaviApprouchAction : public TaiAction {
	inline TaiMizigenNaviApprouchAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/////////// Honeywisp AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiMizinkoSoundTable : public PaniSoundTable {
	TaiMizinkoSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiMizinkoParameters : public TekiParameters {
	TaiMizinkoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiMizinkoStrategy : public TaiStrategy {
	TaiMizinkoStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	bool hasWater(Teki&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoCryTimerAction : public TaiTimerAction {
	inline TaiMizinkoCryTimerAction() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiTimerAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoMovingTimerAction : public TaiTimerAction {
	inline TaiMizinkoMovingTimerAction() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiTimerAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoFadingAction : public TaiAction {
	inline TaiMizinkoFadingAction() // TODO: this is a guess
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
struct TaiMizinkoGoingAction : public TaiAction {
	inline TaiMizinkoGoingAction() // TODO: this is a guess
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
struct TaiMizinkoComingAction : public TaiAction {
	inline TaiMizinkoComingAction() // TODO: this is a guess
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
struct TaiMizinkoDropWaterAction : public TaiAction {
	inline TaiMizinkoDropWaterAction() // TODO: this is a guess
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
struct TaiMizinkoWaitingAction : public TaiAction {
	inline TaiMizinkoWaitingAction() // TODO: this is a guess
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
struct TaiMizinkoFlyingAwayAction : public TaiAction {
	inline TaiMizinkoFlyingAwayAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
