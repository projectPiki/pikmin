#ifndef _TAIMOVEACTIONS_H
#define _TAIMOVEACTIONS_H

#include "TaiAction.h"
#include "TaiContinuousMotionAction.h"

/**
 * @brief TODO
 */
struct TaiMoveNestPositionAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiStopMoveAction : public TaiAction {
	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiStartFlyingAction : public TaiAction {
	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiFinishFlyingAction : public TaiAction {
	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakeVelocityDirectionAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakeAccelerationDirectionAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakingNextVelocityAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakingNextDriveAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiAccelerationAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiParabolaAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiCircleMoveAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiHorizontalSinWaveAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiClampMaxHeightAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiClampMinHeightAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiClampMinVelocityYAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiImpassableAction : public TaiAction {
	virtual void start(Teki& teki); // _08
	virtual bool act(Teki& teki);   // _10

	void resetPosition(Teki& teki);

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiRandomWanderingRouteAction : public TaiContinuousMotionAction {
	virtual void start(Teki& teki);  // _08
	virtual void finish(Teki& teki); // _0C
	virtual bool act(Teki& teki);    // _10

	void makeTargetPosition(Teki& teki);

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

struct TaiTracingAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiGoingHomeAction : public TaiContinuousMotionAction {
	virtual void finish(Teki& teki); // _0C
	virtual bool act(Teki& teki);    // _10
};

/**
 * @brief TODO
 */
struct TaiDirectTurnAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTurningAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiTurningAwayAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiTraceTurningAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiOutOfTraceAngleAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTurningToTargetPositionAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiRotatingAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiRunningAwayToTargetDirectionAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiRunningAwayAction : public TaiContinuousMotionAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction?
};

/**
 * @brief TODO
 */
struct TaiWatchOffTerritoryCenterAction : public TaiAction {
	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTargetNestAction : public TaiAction {
	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiHeadOnCollisionAvoidanceAction : public TaiAction {
	virtual bool actByEvent(TekiEvent& event); // _14

	// _04 = VTBL
	// _00-_08 = TaiAction
};

#endif
