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

bool TaiMoveNestPositionAction::act(Teki& teki)
{
	teki.moveNestPosition();
	return false;
}

void TaiStopMoveAction::start(Teki& teki)
{
	teki.stopMove();
}

void TaiStartFlyingAction::start(Teki& teki)
{
	teki.startFlying();
}

void TaiFinishFlyingAction::start(Teki& teki)
{
	teki.finishFlying();
}

bool TaiMakeVelocityDirectionAction::act(Teki& teki)
{
	NVector3f dir;
	teki.mVelocityIO.output(dir);
	if (dir.lengthXZ() > 0.0f) {
		teki.inputDirectionVector(dir);
	}
	return false;
}

bool TaiMakeAccelerationDirectionAction::act(Teki& teki)
{
	NVector3f dir;
	teki.mAccelerationIO.output(dir);
	if (dir.lengthXZ() > 0.0f) {
		teki.inputDirectionVector(dir);
	}
	return false;
}

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

bool TaiAccelerationAction::act(Teki& teki)
{
	teki.mAccelEvent->update();
	return false;
}

bool TaiParabolaAction::act(Teki& teki)
{
	teki.mParabolaEvent->update();
	return false;
}

bool TaiCircleMoveAction::act(Teki& teki)
{
	teki.mCircleMoveEvent->update();
	return false;
}

bool TaiHorizontalSinWaveAction::act(Teki& teki)
{
	teki.mSinWaveEvent->update();
	return false;
}

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

void TaiImpassableAction::start(Teki& teki)
{
	resetPosition(teki);
}

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

void TaiImpassableAction::resetPosition(Teki& teki)
{
	teki.mTargetPosition.input(teki.getPosition());
	teki.mTimers[mTimerIdx] = mTimerLength;
}

void TaiRandomWanderingRouteAction::start(Teki& teki)
{
	TaiContinuousMotionAction::start(teki);
	makeTargetPosition(teki);
}

void TaiRandomWanderingRouteAction::finish(Teki& teki)
{
}

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

void TaiRandomWanderingRouteAction::makeTargetPosition(Teki& teki)
{
	int wpIdx        = teki.getTargetNearestWayPoint(teki.getPosition())->mIndex;
	int randRouteNum = NSystem::randomInt(routeMgr->getNumWayPoints(teki.mPathHandle) - 1);
	teki.makeWayPointRoute(wpIdx, randRouteNum, false);
	teki.mCurrRouteWayPointID = 0;
}

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

void TaiGoingHomeAction::finish(Teki& teki)
{
}

bool TaiGoingHomeAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}
	teki.moveToward(teki.getNestPosition(), mMoveSpeed);
	return false;
}

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

bool TaiRotatingAction::act(Teki& teki)
{
	teki.rotateTeki(mRotateSpeed);
	return false;
}

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

bool TaiWatchOffTerritoryCenterAction::act(Teki& teki)
{
	return (teki.calcTargetAngle(teki.getNestPosition()) > NMathF::pi * 0.1f);
}

void TaiTargetNestAction::start(Teki& teki)
{
	teki.mTargetPosition.input(teki.getNestPosition());
}

bool TaiHeadOnCollisionAvoidanceAction::actByEvent(immut TekiEvent& event)
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
