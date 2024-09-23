#ifndef _TAI_COLLEC_H
#define _TAI_COLLEC_H

#include "types.h"
#include "TAI/TimerActions.h"
#include "TAI/MotionActions.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"

struct NVector3f;

/////////// Breadbug AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiCollecSoundTable {
	TaiCollecSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiCollecParameters : public TekiParameters {
	TaiCollecParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiCollecStrategy : public TaiStrategy {
	TaiCollecStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// unused/inlined:
	void outputUndergroundPosition(Teki&, NVector3f&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecImpassableAction : public TaiAction {
	inline TaiCollecImpassableAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetPosition(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecLetGoOfPelletAction : public TaiAction {
	inline TaiCollecLetGoOfPelletAction() // TODO: this is a guess
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
struct TaiCollecTargetPelletAction : public TaiAction {
	inline TaiCollecTargetPelletAction() // TODO: this is a guess
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
struct TaiCollecVisibleHeightPelletLostAction : public TaiAction {
	inline TaiCollecVisibleHeightPelletLostAction() // TODO: this is a guess
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
struct TaiCollecVisibleHeightPelletLostTimerAction : public TaiTimerAction {
	inline TaiCollecVisibleHeightPelletLostTimerAction() // TODO: this is a guess
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
struct TaiCollecPelletLostAction : public TaiAction {
	inline TaiCollecPelletLostAction() // TODO: this is a guess
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
struct TaiCollecPelletDisappearedAction : public TaiAction {
	inline TaiCollecPelletDisappearedAction() // TODO: this is a guess
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
struct TaiCollecHoldPelletAction : public TaiAction {
	inline TaiCollecHoldPelletAction() // TODO: this is a guess
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
struct TaiCollecCatchingAction : public TaiAction {
	inline TaiCollecCatchingAction() // TODO: this is a guess
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
struct TaiCollecCarryingAction : public TaiAction {
	inline TaiCollecCarryingAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecBeingDraggedAction : public TaiAction {
	inline TaiCollecBeingDraggedAction() // TODO: this is a guess
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
struct TaiCollecWinCarryingAction : public TaiAction {
	inline TaiCollecWinCarryingAction() // TODO: this is a guess
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
struct TaiCollecDefeatCarryingAction : public TaiAction {
	inline TaiCollecDefeatCarryingAction() // TODO: this is a guess
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
struct TaiCollecPutAction : public TaiAction {
	inline TaiCollecPutAction() // TODO: this is a guess
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
struct TaiCollecPuttingPelletAction : public TaiAction {
	inline TaiCollecPuttingPelletAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecCarryingToNestAction : public TaiContinuousMotionAction {
	inline TaiCollecCarryingToNestAction() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void makePositionRoute(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecRouteImpassableAction : public TaiAction {
	inline TaiCollecRouteImpassableAction() // TODO: this is a guess
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
struct TaiCollecRoundCarryAction : public TaiAction {
	inline TaiCollecRoundCarryAction() // TODO: this is a guess
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
struct TaiCollecPelletStartContainerizedAction : public TaiAction {
	inline TaiCollecPelletStartContainerizedAction() // TODO: this is a guess
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
struct TaiCollecPelletFinishContainerizedAction : public TaiAction {
	inline TaiCollecPelletFinishContainerizedAction() // TODO: this is a guess
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
struct TaiCollecDeadFallingAction : public TaiAction {
	inline TaiCollecDeadFallingAction() // TODO: this is a guess
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
struct TaiCollecFallingAction : public TaiAction {
	inline TaiCollecFallingAction() // TODO: this is a guess
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
struct TaiCollecGetOutAction : public TaiAction {
	inline TaiCollecGetOutAction() // TODO: this is a guess
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
struct TaiCollecLegEffectAction : public TaiJointEffectAction {
	TaiCollecLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/////////// Breadbug Nest AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiHollecParameters : public TekiParameters {
	TaiHollecParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiHollecStrategy : public TaiStrategy {
	TaiHollecStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

#endif
