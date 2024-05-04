#ifndef _TAIMOVEACTIONS_H
#define _TAIMOVEACTIONS_H

#include "TaiAction.h"
#include "TaiContinuousMotionAction.h"

/**
 * @brief TODO
 */
struct TaiMoveNestPositionAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiStopMoveAction : public TaiAction {
	virtual void start(Teki&); // _08
};

/**
 * @brief TODO
 */
struct TaiStartFlyingAction : public TaiAction {
	virtual void start(Teki&); // _08
};

/**
 * @brief TODO
 */
struct TaiFinishFlyingAction : public TaiAction {
	virtual void start(Teki&); // _08
};

/**
 * @brief TODO
 */
struct TaiMakeVelocityDirectionAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiMakeAccelerationDirectionAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiMakingNextVelocityAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiMakingNextDriveAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiAccelerationAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiParabolaAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiCircleMoveAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiHorizontalSinWaveAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiClampMaxHeightAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiClampMinHeightAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiClampMinVelocityYAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiImpassableAction : public TaiAction {
	virtual void start(Teki&); // _08
	virtual int act(Teki&);   // _10

    void resetPosition(Teki&);
};

/**
 * @brief TODO
 */
struct TaiRandomWanderingRouteAction : public TaiContinuousMotionAction {
	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual int act(Teki&);    // _10

    void makeTargetPosition(Teki&);
};

struct TaiTracingAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiGoingHomeAction : public TaiContinuousMotionAction {
	virtual void finish(Teki&); // _0C
	virtual int act(Teki&);    // _10
};

/**
 * @brief TODO
 */
struct TaiDirectTurnAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiTurningAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiTurningAwayAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiTraceTurningAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiOutOfTraceAngleAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiTurningToTargetPositionAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiRotatingAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiRunningAwayToTargetDirectionAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiRunningAwayAction : public TaiContinuousMotionAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiWatchOffTerritoryCenterAction : public TaiAction {
	virtual int act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TaiTargetNestAction : public TaiAction {
	virtual void start(Teki&); // _08
};

/**
 * @brief TODO
 */
struct TaiHeadOnCollisionAvoidanceAction : public TaiAction {
	virtual int actByEvent(TekiEvent&); // _14
};

#endif /* _TAIMOVEACTIONS_H */
