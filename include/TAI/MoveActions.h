#ifndef _TAI_MOVEACTIONS_H
#define _TAI_MOVEACTIONS_H

#include "TAI/Action.h"
#include "TAI/MotionActions.h"

/**
 * @brief TODO
 */
struct TaiMoveNestPositionAction : public TaiAction {
	TaiMoveNestPositionAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiStopMoveAction : public TaiAction {
	TaiStopMoveAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiStartFlyingAction : public TaiAction {
	inline TaiStartFlyingAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiFinishFlyingAction : public TaiAction {
	inline TaiFinishFlyingAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakeVelocityDirectionAction : public TaiAction {
	inline TaiMakeVelocityDirectionAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakeAccelerationDirectionAction : public TaiAction {
	inline TaiMakeAccelerationDirectionAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakingNextVelocityAction : public TaiAction {
	TaiMakingNextVelocityAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiMakingNextDriveAction : public TaiAction {
	TaiMakingNextDriveAction(f32 driveMag)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mDriveMag = driveMag;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	f32 mDriveMag; // _08
};

/**
 * @brief TODO
 */
struct TaiAccelerationAction : public TaiAction {
	TaiAccelerationAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiParabolaAction : public TaiAction {
	TaiParabolaAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiCircleMoveAction : public TaiAction {
	inline TaiCircleMoveAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiHorizontalSinWaveAction : public TaiAction {
	TaiHorizontalSinWaveAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiClampMaxHeightAction : public TaiAction {
	TaiClampMaxHeightAction(int nextState, f32 maxHeight)
	    : TaiAction(nextState)
	{
		mMaxHeight = maxHeight;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	f32 mMaxHeight; // _08
};

/**
 * @brief TODO
 */
struct TaiClampMinHeightAction : public TaiAction {
	TaiClampMinHeightAction(int nextState, f32 minHeight)
	    : TaiAction(nextState)
	{
		mMinHeight = minHeight;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	f32 mMinHeight; // _08
};

/**
 * @brief TODO
 */
struct TaiClampMinVelocityYAction : public TaiAction {
	TaiClampMinVelocityYAction(int nextState, f32 minVSpeed)
	    : TaiAction(nextState)
	{
		mMinVertSpeed = minVSpeed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	f32 mMinVertSpeed; // _08
};

/**
 * @brief TODO
 */
struct TaiImpassableAction : public TaiAction {
	TaiImpassableAction(int nextState, int timerIdx, f32 length, f32 maxDist)
	    : TaiAction(nextState)
	{
		mTimerIdx    = timerIdx;
		mTimerLength = length;
		mMaxDistance = maxDist;
	}

	virtual void start(Teki& teki); // _08
	virtual bool act(Teki& teki);   // _10

	void resetPosition(Teki& teki);

	// _04 = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx;    // _08
	f32 mTimerLength; // _0C
	f32 mMaxDistance; // _10
};

/**
 * @brief TODO
 */
struct TaiRandomWanderingRouteAction : public TaiContinuousMotionAction {
	TaiRandomWanderingRouteAction(int motionIdx, f32 p2)
	    : TaiContinuousMotionAction(TAI_NO_TRANSIT, motionIdx)
	{
		mTargetPosition = p2;
	}

	virtual void start(Teki& teki);  // _08
	virtual void finish(Teki& teki); // _0C
	virtual bool act(Teki& teki);    // _10

	void makeTargetPosition(Teki& teki);

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTargetPosition; // _0C
};

struct TaiTracingAction : public TaiContinuousMotionAction {
	inline TaiTracingAction(int motionIdx, f32 p2)
	    : TaiContinuousMotionAction(TAI_NO_TRANSIT, motionIdx)
	{
		mTraceSpeed = p2;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTraceSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiGoingHomeAction : public TaiContinuousMotionAction {
	TaiGoingHomeAction(int motionIdx, f32 p2)
	    : TaiContinuousMotionAction(TAI_NO_TRANSIT, motionIdx)
	{
		mMoveSpeed = p2;
	}

	virtual void finish(Teki& teki); // _0C
	virtual bool act(Teki& teki);    // _10

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mMoveSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiDirectTurnAction : public TaiAction {
	inline TaiDirectTurnAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTurningAction : public TaiContinuousMotionAction {
	TaiTurningAction(int nextState, int motionIdx, f32 turnSpeed)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mTurnSpeed = turnSpeed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTurnSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiTurningAwayAction : public TaiContinuousMotionAction {
	TaiTurningAwayAction(int nextState, int motionIdx, f32 turnSpeed)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mTurnSpeed = turnSpeed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_10 = TaiContinuousMotionAction
	f32 mTurnSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiTraceTurningAction : public TaiContinuousMotionAction {
	TaiTraceTurningAction(int nextState, int motionIdx, f32 turnSpeed)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mTurnSpeed = turnSpeed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTurnSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiOutOfTraceAngleAction : public TaiAction {
	TaiOutOfTraceAngleAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTurningToTargetPositionAction : public TaiContinuousMotionAction {
	TaiTurningToTargetPositionAction(int nextState, int motionIdx, f32 turnSpeed)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mTurnSpeed = turnSpeed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTurnSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiRotatingAction : public TaiAction {
	TaiRotatingAction(f32 speed)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mRotateSpeed = speed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	f32 mRotateSpeed; // _08
};

/**
 * @brief TODO
 */
struct TaiRunningAwayToTargetDirectionAction : public TaiContinuousMotionAction {
	TaiRunningAwayToTargetDirectionAction(int nextState, int motionIdx, f32 p3)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mRunningSpeed = p3;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mRunningSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiRunningAwayAction : public TaiContinuousMotionAction {
	TaiRunningAwayAction(int nextState, int motionIdx, f32 speed) // this is unused and just a guess
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mRunningSpeed = speed;
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiContinuousMotionAction
	f32 mRunningSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiWatchOffTerritoryCenterAction : public TaiAction {
	TaiWatchOffTerritoryCenterAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki); // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiTargetNestAction : public TaiAction {
	TaiTargetNestAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki& teki); // _08

	// _04 = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiHeadOnCollisionAvoidanceAction : public TaiAction {
	TaiHeadOnCollisionAvoidanceAction(f32 speed)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		_08 = speed;
	}

	virtual bool actByEvent(immut TekiEvent& event); // _14

	// _04 = VTBL
	// _00-_08 = TaiAction
	f32 _08; // _08
};

#endif
