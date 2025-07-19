#include "DebugLog.h"
#include "Peve/MotionEvents.h"
#include "PikiMgr.h"
#include "TAI/MoveActions.h"
#include "TekiConditions.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("taimoveactions")

/*
 * --INFO--
 * Address:	80134560
 * Size:	000028
 */
bool TaiMoveNestPositionAction::act(Teki& teki)
{
	teki.moveNestPosition();
	return false;
}

/*
 * --INFO--
 * Address:	80134588
 * Size:	000078
 */
void TaiStopMoveAction::start(Teki& teki)
{
	teki.stopMove();
}

/*
 * --INFO--
 * Address:	80134600
 * Size:	00001C
 */
void TaiStartFlyingAction::start(Teki& teki)
{
	teki.startFlying();
}

/*
 * --INFO--
 * Address:	8013461C
 * Size:	00001C
 */
void TaiFinishFlyingAction::start(Teki& teki)
{
	teki.finishFlying();
}

/*
 * --INFO--
 * Address:	80134638
 * Size:	000080
 */
bool TaiMakeVelocityDirectionAction::act(Teki& teki)
{
	NVector3f dir;
	teki.mVelocityIO.output(dir);
	if (dir.lengthXZ() > 0.0f) {
		teki.inputDirectionVector(dir);
	}
	return false;
}

/*
 * --INFO--
 * Address:	801346B8
 * Size:	000080
 */
bool TaiMakeAccelerationDirectionAction::act(Teki& teki)
{
	NVector3f dir;
	teki.mAccelerationIO.output(dir);
	if (dir.lengthXZ() > 0.0f) {
		teki.inputDirectionVector(dir);
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134738
 * Size:	0000D0
 */
bool TaiMakingNextVelocityAction::act(Teki& teki)
{
	f32 fTime = NSystem::getFrameTime();
	NVector3f vel;
	teki.mPositionIO.output(vel);
	vel.sub(teki.getPosition());
	vel.scale(1.0f / fTime);
	teki.inputVelocity(vel);
	return false;
}

/*
 * --INFO--
 * Address:	80134808
 * Size:	0000D0
 */
bool TaiMakingNextDriveAction::act(Teki& teki)
{
	NVector3f drive;
	teki.mPositionIO.output(drive);
	drive.sub(teki.getPosition());
	drive.normalizeCheck();
	drive.scale(mDriveMag);
	teki.inputDrive(drive);
	return false;
}

/*
 * --INFO--
 * Address:	801348D8
 * Size:	000034
 */
bool TaiAccelerationAction::act(Teki& teki)
{
	teki.mAccelEvent->update();
	return false;
}

/*
 * --INFO--
 * Address:	8013490C
 * Size:	000034
 */
bool TaiParabolaAction::act(Teki& teki)
{
	teki.mParabolaEvent->update();
	return false;
}

/*
 * --INFO--
 * Address:	80134940
 * Size:	000034
 */
bool TaiCircleMoveAction::act(Teki& teki)
{
	teki.mCircleMoveEvent->update();
	return false;
}

/*
 * --INFO--
 * Address:	80134974
 * Size:	000034
 */
bool TaiHorizontalSinWaveAction::act(Teki& teki)
{
	teki.mSinWaveEvent->update();
	return false;
}

/*
 * --INFO--
 * Address:	801349A8
 * Size:	0000A8
 */
bool TaiClampMaxHeightAction::act(Teki& teki)
{
	NVector3f pos;
	teki.mPositionIO.output(pos);
	if (pos.y > teki.getSeaLevel() + mMaxHeight) {
		pos.y = teki.getSeaLevel() + mMaxHeight;
		teki.mPositionIO.input(pos);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134A50
 * Size:	0000A8
 */
bool TaiClampMinHeightAction::act(Teki& teki)
{
	NVector3f pos;
	teki.mPositionIO.output(pos);
	if (pos.y < teki.getSeaLevel() + mMinHeight) {
		pos.y = teki.getSeaLevel() + mMinHeight;
		teki.mPositionIO.input(pos);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134AF8
 * Size:	00008C
 */
bool TaiClampMinVelocityYAction::act(Teki& teki)
{
	NVector3f vel;
	teki.mVelocityIO.output(vel);
	if (vel.y < mMinVertSpeed) {
		PRINT_NAKATA("TaiClampMinVelocityYAction::act:%08x:%f,%f\n", &teki, vel.y, mMinVertSpeed);
		vel.y = mMinVertSpeed;
		teki.mVelocityIO.input(vel);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134B84
 * Size:	000020
 */
void TaiImpassableAction::start(Teki& teki)
{
	resetPosition(teki);
}

/*
 * --INFO--
 * Address:	80134BA4
 * Size:	0000AC
 */
bool TaiImpassableAction::act(Teki& teki)
{
	f32 distXZ = teki.mTargetPosition.distanceXZ(teki.getPosition());
	if (distXZ >= mMaxDistance) {
		resetPosition(teki);
		return false;
	}

	if (!teki.timerElapsed(mTimerIdx)) {
		return false;
	}

	PRINT_NAKATA("TaiImpassableAction::act:%08x:%f,%f,%f\n", &teki, distXZ, mMaxDistance, mTimerLength);
	return true;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80134C50
 * Size:	000030
 */
void TaiImpassableAction::resetPosition(Teki& teki)
{
	teki.mTargetPosition.input(teki.getPosition());
	teki.mTimers[mTimerIdx] = mTimerLength;
}

/*
 * --INFO--
 * Address:	80134C80
 * Size:	000044
 */
void TaiRandomWanderingRouteAction::start(Teki& teki)
{
	TaiContinuousMotionAction::start(teki);
	makeTargetPosition(teki);
}

/*
 * --INFO--
 * Address:	80134CC4
 * Size:	000004
 */
void TaiRandomWanderingRouteAction::finish(Teki& teki)
{
}

/*
 * --INFO--
 * Address:	80134CC8
 * Size:	00013C
 */
bool TaiRandomWanderingRouteAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	if (teki.mRouteWayPointCount == 0) {
		makeTargetPosition(teki);
		return false;
	}

	if (teki.mRouteWayPointCount > teki.mRouteWayPointMax && teki.mCurrRouteWayPointID > teki.mRouteWayPointMax - 1) {
		PRINT_NAKATA("TaiRandomWanderingRouteAction::act:o.routeWayPointCount>o.routeWayPointMax:%08x,%d/%d\n", &teki,
		             teki.mCurrRouteWayPointID, teki.mRouteWayPointCount);
		makeTargetPosition(teki);
		return false;
	}

	if (teki.mCurrRouteWayPointID > teki.mRouteWayPointCount - 1) {
		makeTargetPosition(teki);
		return false;
	}

	WayPoint* wp = teki.getRouteWayPoint(teki.mCurrRouteWayPointID);
	if (!wp) {
		PRINT("?TaiRandomWanderingRouteAction::act:%08x:wayPoint==null:%d/%d\n", &teki, teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		makeTargetPosition(teki);
		return false;
	}

	if (!wp->mIsOpen) {
		PRINT("!TaiRandomWanderingRouteAction::act:%08x:!wayPoint->on:%d/%d\n", &teki, teki.mCurrRouteWayPointID, teki.mRouteWayPointCount);
		makeTargetPosition(teki);
		return false;
	}

	if (teki.moveToward(wp->mPosition, mTargetPosition)) {
		PRINT_NAKATA("TaiRandomWanderingRouteAction::act:%08x,%d/%d\n", &teki, teki.mCurrRouteWayPointID, teki.mRouteWayPointCount);
		teki.mCurrRouteWayPointID++;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134E04
 * Size:	000070
 */
void TaiRandomWanderingRouteAction::makeTargetPosition(Teki& teki)
{
	int wpIdx        = teki.getTargetNearestWayPoint(teki.getPosition())->mIndex;
	int randRouteNum = NSystem::randomInt(routeMgr->getNumWayPoints(teki.mPathHandle) - 1);
	teki.makeWayPointRoute(wpIdx, randRouteNum, false);
	teki.mCurrRouteWayPointID = 0;
}

/*
 * --INFO--
 * Address:	80134E74
 * Size:	000088
 */
bool TaiTracingAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiTracingAction::act:target==null:%08x\n", &teki);
		return false;
	}

	teki.moveToward(target->getPosition(), mTraceSpeed);
	return false;
}

/*
 * --INFO--
 * Address:	80134EFC
 * Size:	000004
 */
void TaiGoingHomeAction::finish(Teki& teki)
{
}

/*
 * --INFO--
 * Address:	80134F00
 * Size:	000078
 */
bool TaiGoingHomeAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}
	teki.moveToward(teki.getNestPosition(), mMoveSpeed);
	return false;
}

/*
 * --INFO--
 * Address:	80134F78
 * Size:	000044
 */
bool TaiDirectTurnAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiDirectTurnAction::start:target==null:%08x\n", &teki); // that's not what this function is, nakata.
		return false;
	}

	teki.turnTo(target->getPosition());
	return false;
}

/*
 * --INFO--
 * Address:	80134FBC
 * Size:	00014C
 */
bool TaiTurningAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiTurnAction::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiRecognitionCondition recogCond(&teki);
	if (!recogCond.satisfy(target)) {
		PRINT_NAKATA("!TaiTurnAction::act:!condition.satisfy:%08x\n", &teki);
		return true;
	}

	f32 key = teki.mTekiAnimator->getKeyValueByKeyType(0);
	if (teki.mTekiAnimator->getCounter() < key) {
		return false;
	}

	teki.mTargetAngle = teki.calcTargetDirection(target->getPosition());
	return teki.turnToward(teki.mTargetAngle, mTurnSpeed);
}

/*
 * --INFO--
 * Address:	80135108
 * Size:	00015C
 */
bool TaiTurningAwayAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiTurningAwayAction::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiRecognitionCondition recogCond(&teki);
	if (!recogCond.satisfy(target)) {
		PRINT_NAKATA("!TaiTurningAwayAction::act:!condition.satisfy:%08x\n", &teki);
		return true;
	}

	f32 key = teki.mTekiAnimator->getKeyValueByKeyType(0);
	if (teki.mTekiAnimator->getCounter() < key) {
		return false;
	}

	teki.mTargetAngle = teki.calcTargetDirection(target->getPosition());
	teki.mTargetAngle += NMathF::pi;
	return teki.turnToward(teki.mTargetAngle, mTurnSpeed);
}

/*
 * --INFO--
 * Address:	80135264
 * Size:	000194
 */
bool TaiTraceTurningAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiTraceTurnAction::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiRecognitionCondition recogCond(&teki);
	if (!recogCond.satisfy(target)) {
		PRINT_NAKATA("!TaiTraceTurnAction2::act:%08x\n", &teki);
		return true;
	}

	f32 key = teki.mTekiAnimator->getKeyValueByKeyType(0);
	if (teki.mTekiAnimator->getCounter() < key) {
		return false;
	}

	if (teki.calcTargetAngle(target->getPosition()) <= NMathF::d2r(teki.getParameterF(TPF_TraceAngle) / 2.0f)) {
		return true;
	}

	teki.mTargetAngle = teki.calcTargetDirection(target->getPosition());
	return teki.turnToward(teki.mTargetAngle, mTurnSpeed);
}

/*
 * --INFO--
 * Address:	801353F8
 * Size:	0000D0
 */
bool TaiOutOfTraceAngleAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT_NAKATA("!TaiOutOfTraceAngleAction::act:target==null:%08x\n", &teki);
		return false;
	}

	TekiRecognitionCondition recogCond(&teki);
	if (!recogCond.satisfy(target)) {
		return false;
	}

	if (teki.calcTargetAngle(target->getPosition()) <= NMathF::d2r(teki.getParameterF(TPF_TraceAngle) / 2.0f)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	801354C8
 * Size:	000130
 */
bool TaiTurningToTargetPositionAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	f32 keyValue = teki.mTekiAnimator->getKeyValueByKeyType(0);
	if (teki.mTekiAnimator->getCounter() < keyValue) {
		return false;
	}

	if (teki.calcTargetAngle(teki.mTargetPosition) <= NMathF::d2r(teki.getParameterF(TPF_TraceAngle) / 2.0f)) {
		return true;
	}

	teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);
	return teki.turnToward(teki.mTargetAngle, mTurnSpeed);
}

/*
 * --INFO--
 * Address:	801355F8
 * Size:	00002C
 */
bool TaiRotatingAction::act(Teki& teki)
{
	teki.rotateTeki(mRotateSpeed);
	return false;
}

/*
 * --INFO--
 * Address:	80135624
 * Size:	0000AC
 */
bool TaiRunningAwayToTargetDirectionAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	Vector3f dir;
	BTeki::outputDirectionVector(teki.mTargetAngle, dir);
	teki.mTargetVelocity.scale2(mRunningSpeed, dir);
	return false;
}

/*
 * --INFO--
 * Address:	801356D0
 * Size:	00036C
 */
bool TaiRunningAwayAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	NVector3f drive(0.0f, 0.0f, 0.0f);
	TekiRecognitionCondition recogCond(&teki);
	f32 range = teki.getParameterF(TPF_VisibleRange);
	f32 linFuncValues[2];
	NClampLinearFunction linFunc(linFuncValues);
	linFunc.makeClampLinearFunction(0.0f, 10.0f, range, 0.0f);
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (!piki) {
			PRINT("?TaiRunningAwayAction::act:%08x:creature==null\n", &teki);
			break;
		}
		if (!recogCond.satisfy(piki)) {
			continue;
		}
		f32 dist = teki.calcSphereDistance(*piki);
		if (dist <= range) {
			NVector3f dir;
			dir.sub2(teki.getPosition(), piki->getPosition());
			dir.normalizeCheck();
			f32 val = linFunc.getValue(dist);
			dir.scale(val);
			drive.add(dir);
		}
	}
	drive.y = 0.0f;
	drive.normalizeCheck();
	drive.scale(mRunningSpeed);
	teki.inputDrive(drive);
	return false;
}

/*
 * --INFO--
 * Address:	80135A3C
 * Size:	000044
 */
bool TaiWatchOffTerritoryCenterAction::act(Teki& teki)
{
	return (teki.calcTargetAngle(teki.getNestPosition()) > NMathF::pi * 0.1f);
}

/*
 * --INFO--
 * Address:	80135A80
 * Size:	000020
 */
void TaiTargetNestAction::start(Teki& teki)
{
	teki.mTargetPosition.input(teki.getNestPosition());
}

/*
 * --INFO--
 * Address:	80135AA0
 * Size:	000180
 */
bool TaiHeadOnCollisionAvoidanceAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity) {
		Creature* other = event.mOther;
		if (other->mObjType == OBJTYPE_Teki) {
			Teki* otherTeki = (Teki*)other;
			Teki* teki      = event.mTeki;

			if (otherTeki->mTekiType == teki->mTekiType) {
				NVector3f thisDir;
				teki->outputDirectionVector(thisDir);

				NVector3f newVel;
				newVel.cross(thisDir, NVector3f(0.0f, 1.0f, 0.0f));
				newVel.normalizeCheck();
				newVel.scale(_08);
				newVel.add(teki->getDrive());
				teki->inputVelocity(newVel);
			}
		}
	}

	return false;
}
