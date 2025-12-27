#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "GoalItem.h"
#include "ItemMgr.h"
#include "MapMgr.h"
#include "TAI/Amove.h"
#include "WorkObject.h"
#include "nlib/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(22)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIAmove")

/**
 * @todo: Documentation
 */
void TAIAappearKabekui::start(Teki& teki)
{
	TAIAsetMotionSpeed::start(teki);
	teki.setStaySwitch(false);
	if (_10) {
		teki.setTekiOption(BTeki::TEKI_OPTION_VISIBLE);
	}
}

/**
 * @todo: Documentation
 */
bool TAIAappearKabekui::act(Teki& teki)
{
	CollPart* part = teki.mCollInfo->getSphere('cent');
	Vector3f effPos;
	effPos.set(part->mCentre.x, mapMgr->getMinY(part->mCentre.x, part->mCentre.z, true), part->mCentre.z);
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		teki.setStaySwitch(true);
		teki.playEventSound(&teki, SE_WALLEAT_APPEAR);
	}

	if (teki.getStaySwitch() && (zen::RoundOff(teki.mTekiAnimator->mAnimationCounter) % 7) == 0) {
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, effPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, effPos, nullptr, nullptr);
	}
	if (teki.mCurrentAnimEvent == KEY_Finished) {
		teki.setManualAnimation(false);
		if (!_10) {
			teki.clearTekiOption(BTeki::TEKI_OPTION_VISIBLE);
		}
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
void TAIAsetTargetPointWorkObject::start(Teki& teki)
{
	WorkObject* obj = teki.getWorkObjectPointer();
	teki.mTargetPosition.set(teki.getPosition());
	if (!obj) {
		return;
	}

	if (obj->isBridge()) {
		Bridge* bridge = (Bridge*)obj;
		Vector3f offset;
		offset = bridge->getBridgeXVec();
		offset.multiply(bridge->getStageWidth() * (zen::Rand(1.0f) - 0.5f) * 0.8f);
		teki.mTargetPosition.set(bridge->getStartPos() + offset);
	}
}

/**
 * @todo: Documentation
 */
bool TAIAsetTargetPointWorkObject::act(Teki& teki)
{
	return true;
}

/**
 * @todo: Documentation
 */
bool TAIAgoGoalPath::makePath(Teki& teki)
{
	GoalItem* onyon = itemMgr->getNearestContainer(teki.getPosition(), 12800.0f);
	if (onyon) {
		// `TAIAgoGoalPath` is obstructed by blocked paths, but requests a position route that permits them.
		teki.makePositionRoute(teki.getPosition(), onyon->getPosition(), TERNARY_BUGFIX(false, true));
		if (teki.mRouteWayPointCount > 0) {
			teki.mTargetPosition.set(teki.getRouteWayPoint(teki.getTableIndex())->mPosition);
		} else {
			teki.mTargetPosition.set(teki.getPosition());
		}
	} else {
		PRINT("PATH ERROR! Goal is not found.\n");
		teki.mTargetPosition.set(teki.getPosition());
		teki.mRouteWayPointCount = 1;
	}

	if (teki.mRouteWayPointCount == 1) {
		Vector3f dir;
		dir.set(teki.getPosition() - onyon->getPosition());
		if (dir.length() < teki.getParameterF(TPF_DangerTerritoryRange)) {
			PRINT("Goal \n");
			return true;
		}

		PRINT("yet \n");
		return false;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void TAIAgoGoalPath::start(Teki& teki)
{
	teki.setTableIndex(0);
	makePath(teki);
	TAIAgoTargetPriorityFaceDir::start(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAgoGoalPath::act(Teki& teki)
{
	bool res = false;
	if (TAIAgoTargetPriorityFaceDir::act(teki)) {
		teki.setTableIndex(teki.getTableIndex() + 1);
		// If Dororo (Smoky Progg) plots a route containing the maximum number of waypoints, `getRouteWayPoint` will
		// eventually return an un-checked nullptr.  Without this bounds-check, a crash is possible in Distant Spring.
		if (teki.getTableIndex() >= teki.mRouteWayPointCount || TERNARY_BUGFIX(teki.getTableIndex() >= teki.mRouteWayPointMax, false)) {
			teki.setTableIndex(0);
			if (makePath(teki)) {
				PRINT("GOAL! \n");
				res = true;
			}
		} else {
			WayPoint* wp = teki.getRouteWayPoint(teki.getTableIndex());
			if (wp->mIsOpen) {
				teki.mTargetPosition.set(wp->mPosition);
			} else {
				int idx = teki.getTableIndex() - 2;
				if (idx >= 0) {
					if (teki.getRouteWayPoint(idx)->mIsOpen) {
						PRINT("newTableIndex! \n");
						teki.setTableIndex(idx);
					} else {
						PRINT("STALL!\n");
						res = true;
					}
				} else {
					PRINT("WARNING! generator position is wrong.\n");
				}

				teki.mTargetPosition.set(teki.getRouteWayPoint(teki.getTableIndex())->mPosition);
			}
		}
	}

	return res;
}

/**
 * @todo: Documentation
 */
bool TAIAgoGoalPath::checkArrival(Teki& teki)
{
	WayPoint* wp = teki.getRouteWayPoint(teki.getTableIndex());
	if (wp) {
		f32 rad = teki.getCentreSize() + wp->mRadius;
		return teki.mTargetPosition.distance(teki.getPosition()) <= rad;
	}
	PRINT("path is none. \n");
	return true;
}

/**
 * @todo: Documentation
 */
void TAIAsetTargetPointCircleRandom::start(Teki& teki)
{
	f32 angle = zen::Rand(TAU);
	f32 dist  = zen::Rand(teki.getParameterF(TPF_DangerTerritoryRange));
	f32 x     = dist * NMathF::sin(angle) + teki.mPersonality->mNestPosition.x;
	f32 z     = dist * NMathF::cos(angle) + teki.mPersonality->mNestPosition.z;
	f32 y     = mapMgr->getMinY(x, z, true);
	teki.mTargetPosition.set(x, y, z);
}

/**
 * @todo: Documentation
 */
bool TAIAsetTargetPointCircleRandom::act(Teki& teki)
{
	return true;
}

/**
 * @todo: Documentation
 */
void TAIAsetTargetPointCircle::start(Teki& teki)
{
	setTargetPoint(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAsetTargetPointCircle::act(Teki& teki)
{
	setTargetPoint(teki);
	return true;
}

/**
 * @todo: Documentation
 */
void TAIAsetTargetPointCircle::setTargetPoint(Teki& teki)
{
	f32 angle = mAngleOffset + zen::Rand(mAngleOffset)
	          + NMathF::atan2(teki.getPosition().x - teki.mPersonality->mNestPosition.x,
	                          teki.getPosition().z - teki.mPersonality->mNestPosition.z);
	f32 dist = teki.getParameterF(TPF_SafetyTerritoryRange);
	f32 x    = dist * NMathF::sin(angle) + teki.mPersonality->mNestPosition.x;
	f32 z    = dist * NMathF::cos(angle) + teki.mPersonality->mNestPosition.z;
	f32 y    = mapMgr->getMinY(x, z, true);
	teki.mTargetPosition.set(x, y, z);
}

/**
 * @todo: Documentation
 */
void TAIAgoTarget::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.resetFlag400();
}

/**
 * @todo: Documentation
 */
bool TAIAgoTarget::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mTargetPosition.distance(teki.getPosition()) <= teki.getParameterF(TPF_WalkVelocity)) {
			res = true;
		} else {
			teki.moveToward(teki.mTargetPosition, getVelocity(teki));
		}
	}
	return res;
}

/**
 * @todo: Documentation
 */
void TAIAgoTargetPriorityFaceDir::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/**
 * @todo: Documentation
 */
bool TAIAgoTargetPriorityFaceDir::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (checkArrival(teki)) {
			res = true;
		} else {
			teki.moveTowardPriorityFaceDir(teki.mTargetPosition, getWalkVelocity(teki));
		}
	}
	return res;
}

/**
 * @todo: Documentation
 */
bool TAIAgoTargetPriorityFaceDir::checkArrival(Teki& teki)
{
	return teki.mTargetPosition.distance(teki.getPosition()) <= teki.getParameterF(TPF_WalkVelocity);
}

/**
 * @todo: Documentation
 */
f32 TAIAgoTargetPriorityFaceDir::getWalkVelocity(Teki& teki)
{
	return teki.getParameterF(TPF_WalkVelocity);
}

/**
 * @todo: Documentation
 */
void TAIAapproachTargetPriorityFaceDir::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/**
 * @todo: Documentation
 */
bool TAIAapproachTargetPriorityFaceDir::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		Creature* target = teki.getCreaturePointer(0);
		if (target) {
			teki.moveTowardPriorityFaceDir(target->getPosition(), getVelocity(teki));
			return false;
		}
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D0
 */
void TAIAlookAround::setTargetDirection(Teki& teki, f32 angle)
{
	teki.mTargetAngle = (angle + zen::Rand(angle)) * ((zen::Rand(10.0f) > 5.0f) ? 1.0f : -1.0f) + teki.mFaceDirection;
	teki.mTargetAngle = roundAng(teki.mTargetAngle);
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void TAIAlookAround::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFrameCounter(0.0f);
	teki.setStatus(2);
	setTargetDirection(teki, 40.0f * PI / 180.0f);
}

/**
 * @todo: Documentation
 */
bool TAIAlookAround::act(Teki& teki)
{
	switch (teki.getStatus()) {
	case 2:
		if (TAIAreserveMotion::act(teki)) {
			teki.setStatus(1);
		}
		break;
	case 0:
		int motionID;
		if (angDist(teki.mTargetAngle, teki.mFaceDirection) > 0.0f) {
			motionID = _0C;
		} else {
			motionID = _10;
		}

		if (teki.mTekiAnimator->getCurrentMotionIndex() != motionID || teki.mTekiAnimator->isFinished()) {
			if (!teki.mTekiAnimator->isFinished()) {
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
			}
			if (teki.mTekiAnimator->isFinishing()) {
				teki.mTekiAnimator->startMotion(PaniMotionInfo(motionID, &teki));
			}
		} else if (teki.turnToward(teki.mTargetAngle, teki.getParameterF(TPF_TurnVelocity))) {
			teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
			teki.setFrameCounter(0.0f);
			teki.setStatus(1);
		}
		break;
	case 1:
		if (teki.mTekiAnimator->getCurrentMotionIndex() != mMotionID || teki.mTekiAnimator->isFinished()) {
			if (!teki.mTekiAnimator->isFinished()) {
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
			}
			if (teki.mTekiAnimator->isFinishing()) {
				teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
			}
		} else {
			teki.addFrameCounter(gsys->getFrameTime());
			if (teki.getFrameCounter() > 0.7f) {
				teki.setFrameCounter(0.0f);
				teki.setStatus(0);
				setTargetDirection(teki, 40.0f * PI / 180.0f);
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
			}
		}
		break;
	}

	STACK_PAD_VAR(2);
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
int TAIAturnToTarget::getTurnMotionIndex(Teki& teki)
{
	f32 angle = teki.mTargetAngle; // don't ask.
	f32 ang   = angDist(teki.mTargetAngle, teki.mFaceDirection);
	if (ang > 0.0f) {
		return mLeftTurnAnimID;
	}
	return mRightTurnAnimID;
}

/**
 * @todo: Documentation
 */
void TAIAturnToTarget::start(Teki& teki)
{
	teki.setFlag400();
	teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);
	mMotionID         = getTurnMotionIndex(teki);
	TAIAreserveMotion::start(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAturnToTarget::act(Teki& teki)
{
	bool res     = false;
	int motionID = getTurnMotionIndex(teki);
	if (teki.mTekiAnimator->getCurrentMotionIndex() != motionID || teki.mTekiAnimator->isFinished()) {
		if (!teki.mTekiAnimator->isFinished()) {
			teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
		}
		if (teki.mTekiAnimator->isFinishing()) {
			teki.mTekiAnimator->startMotion(PaniMotionInfo(motionID, &teki));
		}
	} else {
		teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);

		if (teki.mTekiAnimator->isFinishing()) {
			PRINT("KOKO NI KURUNO HA OKASIIDE  !!!!!!!!&&&&&&&&&&&&&&&&&&&&\n"); // 'it's strange to do this by itself !!!!!'
			ERROR("KOKO NI KURUNO HA OKASIIDE  !!!!!!!!&&&&&&&&&&&&&&&&&&&&\n");
		} else {
			if (teki.turnToward(teki.mTargetAngle, getTurnVelocity(teki))) {
				if (_14) {
					teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
				}
				res = true;
			}
		}
	}

	return res;
}

/**
 * @todo: Documentation
 */
void TAIAstop::start(Teki& teki)
{
	teki.stopMove();
}

/**
 * @todo: Documentation
 */
void TAIArandomWalk::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	makeTargetPosition(teki);
	teki.resetFlag400();
	teki.mProps->mCreatureProps.mFaceDirAdjust(0.1f);
}

/**
 * @todo: Documentation
 */
bool TAIArandomWalk::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mTargetPosition.distance(teki.getPosition()) <= teki.getParameterF(TPF_WalkVelocity)) {
			res = true;
		} else {
			f32 speed = teki.getParameterF(TPF_WalkVelocity);
			teki.moveToward(teki.mTargetPosition, speed);
		}
	}

	STACK_PAD_VAR(1);
	return res;
}

/**
 * @todo: Documentation
 */
void TAIArandomWalk::makeTargetPosition(Teki& teki)
{
	f32 angle = 2.0f * NSystem::random() * NMathF::pi;
	f32 dist  = 200.0f * NSystem::random();
	Vector3f offset(dist * NMathF::sin(angle), 0.0f, dist * NMathF::cos(angle));
	teki.mTargetPosition.add2(teki.getPosition(), offset);
}

/**
 * @todo: Documentation
 */
void TAIAturnOccasion::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAturnOccasion::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);
		return teki.turnToward(teki.mTargetAngle, teki.getParameterF(TPF_TurnVelocity));
	}
	return false;
}

/**
 * @todo: Documentation
 */
void TAIAturnFocusCreature::start(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		teki.mTargetAngle = teki.calcTargetDirection(target->getPosition());
	} else {
		teki.mTargetAngle = teki.mFaceDirection;
	}

	teki.resetFlag400();
	mMotionID = getTurnMotionIndex(teki);
	TAIAreserveMotion::start(teki);
	teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	teki.mVelocity = teki.mTargetVelocity;
}

/**
 * @todo: Documentation
 */
bool TAIAturnFocusCreature::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		teki.mTargetPosition = NVector3f(target->getPosition());
		return TAIAturnToTarget::act(teki);
	}
	return true;
}

/**
 * @todo: Documentation
 */
void TAIAwait::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.stopMove();
	teki.setFrameCounter(0.0f);
}

/**
 * @todo: Documentation
 */
bool TAIAwait::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.addFrameCounter(gsys->getFrameTime()) > getWaitCounterMax(teki)) {
			teki.setFrameCounter(0.0f);
			res = true;
		}
	}
	return res;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
void TAIApatrol::changeStatus(int status, Teki& teki)
{
	teki.setStatus(status);
	switch (teki.getStatus()) {
	case 1:
		teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		teki.setFlag400();
		break;
	case 0:
		teki.resetFlag400();
		break;
	}
}

/**
 * @todo: Documentation
 */
TAIApatrol::TAIApatrol(int nextState, int p2, int leftMotionID, int rightMotionID, immut Vector3f* p5, int p6, bool p7)
    : TAIAturnToTarget(nextState, leftMotionID, rightMotionID, p7)
{
	_20 = p2;
	_18 = p5;
	_1C = p6;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000070
 */
void TAIApatrol::setTargetPosition(Teki& teki)
{
	immut Vector3f& vec = _18[teki.getTableIndex()];
	f32 rad             = teki.getParameterF(TPF_DangerTerritoryRange);
	teki.mTargetPosition.set(vec.x * rad + teki.mPersonality->mNestPosition.x, vec.y * rad + teki.mPersonality->mNestPosition.y,
	                         vec.z * rad + teki.mPersonality->mNestPosition.z);
	teki.setFrameCounter(0.0f);
}

/**
 * @todo: Documentation
 */
void TAIApatrol::start(Teki& teki)
{
	teki.setTableIndex(0);
	for (int i = 0; i < _1C; i++) {
		setTargetPosition(teki);

		f32 sum = zen::Abs(teki.getPosition().x - teki.mTargetPosition.x) + zen::Abs(teki.getPosition().y - teki.mTargetPosition.y)
		        + zen::Abs(teki.getPosition().z - teki.mTargetPosition.z);
		f32 minDist;
		if (i == 0) {
			minDist = sum;
		} else if (sum > minDist) {
			teki.setTableIndex(i);
		}
	}

	setTargetPosition(teki);
	TAIAturnToTarget::start(teki);
	changeStatus(1, teki);
}

/**
 * @todo: Documentation
 */
bool TAIApatrol::act(Teki& teki)
{
	switch (teki.getStatus()) {
	case 1:
		if (TAIAturnToTarget::act(teki)) {
			changeStatus(0, teki);
		}
		break;
	case 0:
		if (teki.mTekiAnimator->getCurrentMotionIndex() != _20 || teki.mTekiAnimator->isFinished()) {
			if (!teki.mTekiAnimator->isFinished()) {
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
			}
			if (teki.mTekiAnimator->isFinishing()) {
				teki.mTekiAnimator->startMotion(PaniMotionInfo(_20, &teki));
			}
		} else {
			f32 dist = teki.mTargetPosition.distance(teki.getPosition());
			teki.addFrameCounter(gsys->getFrameTime());
			if (dist <= teki.getParameterF(TPF_WalkVelocity) || teki.getFrameCounter() > getTimeout(teki)) {
				teki.setTableIndex(teki.getTableIndex() + 1);
				if (teki.getTableIndex() >= _1C) {
					teki.setTableIndex(0);
				}
				setTargetPosition(teki);
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
				changeStatus(1, teki);
			} else {
				teki.moveToward(teki.mTargetPosition, teki.getParameterF(TPF_WalkVelocity));
			}
		}
		break;
	default:
		ERROR("unknown status %d \n", teki.getStatus());
		break;
	}

	STACK_PAD_TERNARY(&teki, 1);
	return false;
}

/**
 * @todo: Documentation
 */
void TAIAstepBack::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/**
 * @todo: Documentation
 */
bool TAIAstepBack::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		f32 speed        = getVelocity(teki);
		Creature* target = teki.getCreaturePointer(0);
		if (target) {
			teki.mTargetAngle
			    = NMathF::atan2(target->getPosition().x - teki.getPosition().x, target->getPosition().z - teki.getPosition().z);
			teki.mFaceDirection
			    += angDist(teki.mTargetAngle, teki.mFaceDirection) * teki.getParameterF(TPF_TurnVelocity) * gsys->getFrameTime() * 10.0f;
			teki.mFaceDirection = roundAng(teki.mFaceDirection);
			teki.mSRT.r.set(0.0f, teki.mFaceDirection, 0.0f);
			teki.mTargetVelocity.set(NMathF::sin(teki.mFaceDirection), 0.0f, NMathF::cos(teki.mFaceDirection));
			teki.mTargetVelocity.multiply(-speed);
			return false;
		}

		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void TAIAturnHome::start(Teki& teki)
{
	teki.mTargetPosition.set(teki.mPersonality->mNestPosition);
	teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);
	if (angDist(teki.mTargetAngle, teki.mFaceDirection) > 0.0f) {
		mMotionID = _0C;
	} else {
		mMotionID = _10;
	}

	TAIAturnOccasion::start(teki);
	teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	teki.mVelocity = teki.mTargetVelocity;
}

/**
 * @todo: Documentation
 */
bool TAIAturnHome::act(Teki& teki)
{
	return TAIAturnOccasion::act(teki);
}

/**
 * @todo: Documentation
 */
void TAIAgoingHome::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.resetFlag400();
}

/**
 * @todo: Documentation
 */
bool TAIAgoingHome::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mPersonality->mNestPosition.distance(teki.getPosition()) <= teki.getParameterF(TPF_SafetyTerritoryRange)) {
			res = true;
		} else {
			teki.moveToward(teki.mPersonality->mNestPosition, teki.getParameterF(TPF_RunVelocity));
		}
	}
	return res;
}

/**
 * @todo: Documentation
 */
void TAIAgoingHomePriorityFaceDir::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/**
 * @todo: Documentation
 */
bool TAIAgoingHomePriorityFaceDir::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mPersonality->mNestPosition.distance(teki.getPosition()) <= teki.getParameterF(TPF_SafetyTerritoryRange)) {
			res = true;
		} else {
			teki.moveTowardPriorityFaceDir(teki.mPersonality->mNestPosition, teki.getParameterF(TPF_RunVelocity));
		}
	}
	return res;
}

/**
 * @todo: Documentation
 */
void TAIAflyingBase::start(Teki& teki)
{
	teki.startFlying();
	teki.setChokeSwitch(false);
}

/**
 * @todo: Documentation
 */
bool TAIAflyingBase::act(Teki& teki)
{
	teki.flyingStay(getFlyingStayVelocity(teki));
	if (teki.getYFromSeaLevel() > teki.getParameterF(TPF_FlightHeight)) {
		teki.setChokeSwitch(true);
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000144
 */
void TAIAflyingInTerritory::setTargetPosition(Teki& teki)
{
	Vector3f offset;
	offset.set(zen::Rand(2.0f) - 1.0f, 0.0f, zen::Rand(2.0f) - 1.0f);
	offset.normalize();
	offset.multiply(teki.getParameterF(TPF_SafetyTerritoryRange));
	teki.mTargetPosition.set(offset.x + teki.mPersonality->mNestPosition.x, teki.getParameterF(TPF_FlightHeight),
	                         offset.z + teki.mPersonality->mNestPosition.z);
	teki.mProps->mCreatureProps.mFaceDirAdjust(mFaceDirAdjust);
}

/**
 * @todo: Documentation
 */
void TAIAflyingInTerritory::start(Teki& teki)
{
	teki.setFlag400();
	teki.startFlying();
	teki.resetFlag400();
	setTargetPosition(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAflyingInTerritory::act(Teki& teki)
{
	Vector3f dir;
	f32 speed  = teki.getParameterF(TPF_WalkVelocity);
	f32 yPos   = teki.getYFromSeaLevel();
	f32 ySpeed = teki.mTargetVelocity.y;

	if (teki.mTargetPosition.distance(Vector3f(teki.getPosition().x, yPos, teki.getPosition().z)) <= teki.getParameterF(TPF_WalkVelocity)) {
		setTargetPosition(teki);
	}

	dir.x = teki.mTargetPosition.x - teki.getPosition().x;
	dir.y = 0.0f;
	dir.z = teki.mTargetPosition.z - teki.getPosition().z;

	f32 dist = dir.length();

	if (dist > speed * 0.1f) {
		dir.div(dist);
		dir.multiply(0.1f * speed);
	}

	dir.multiply(gsys->getFrameTime() * 900.0f * gsys->getFrameTime());
	teki.mTargetVelocity.add(dir);

	dist = teki.mTargetVelocity.length();
	if (dist > speed) {
		teki.mTargetVelocity.div(dist);
		teki.mTargetVelocity.multiply(speed);
	}
	teki.mTargetVelocity.y = ySpeed;
	teki.mVelocity         = teki.mTargetVelocity;
	return false;
}

/**
 * @todo: Documentation
 */
void TAIAflyingToGoal::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
	teki.startFlying();
}

/**
 * @todo: Documentation
 */
bool TAIAflyingToGoal::act(Teki& teki)
{
	Vector3f dir;
	f32 vel = getVelocity(teki);
	teki.getYFromSeaLevel();

	if (TAIAreserveMotion::act(teki)) {
		f32 ySpeed             = teki.mTargetVelocity.y;
		teki.mTargetVelocity.y = 0.0f;
		dir.x                  = teki.mTargetPosition.x - teki.getPosition().x;
		dir.y                  = 0.0f;
		dir.z                  = teki.mTargetPosition.z - teki.getPosition().z;

		f32 dist = dir.length();
		if (dist > vel * 0.1f) {
			dir.div(dist);
			dir.multiply(0.1f * vel);
		}

		dir.multiply(gsys->getFrameTime() * 900.0f * gsys->getFrameTime());
		teki.mTargetVelocity.add(dir);

		f32 speed = teki.mTargetVelocity.length();
		if (speed > vel) {
			teki.mTargetVelocity.div(speed);
			teki.mTargetVelocity.multiply(vel);
		}

		teki.mTargetVelocity.y = ySpeed;
		teki.mVelocity         = teki.mTargetVelocity;

		f32 x = teki.mTargetPosition.x - teki.getPosition().x;
		f32 z = teki.mTargetPosition.z - teki.getPosition().z;

		f32 dist2 = std::sqrtf(x * x + z * z);
		if (dist2 <= teki.getParameterF(TPF_WalkVelocity)) {
			return goal(teki);
		}

		return false;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void TAIAflyingDistanceInTerritory::start(Teki& teki)
{
	TAIAflyingToGoal::start(teki);
	teki.setFlag400();
	goal(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAflyingDistanceInTerritory::act(Teki& teki)
{
	teki.turnToTarget();
	return TAIAflyingToGoal::act(teki);
}

/**
 * @todo: Documentation
 */
bool TAIAflyingDistanceInTerritory::goal(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		Vector3f pos;
		f32 ratio = zen::Abs(teki.getPosition().y - target->getPosition().y) / NMathF::tan(mDiveAngle);
		f32 vel   = getOffset(teki) + ratio;
		pos.set(teki.mPersonality->mNestPosition - target->getPosition());
		if (pos.length() > 0.0f) {
			pos.normalize();
		} else {
			pos.set(1.0f, 0.0f, 0.0f);
		}

		pos.multiply(vel);
		pos.add(target->getPosition());
		teki.mTargetPosition.set(pos);

		if (teki.mTargetPosition.distance(teki.mPersonality->mNestPosition) > teki.getParameterF(TPF_DangerTerritoryRange)) {
			PRINT("out of territory range .\n");
			pos.set(teki.mTargetPosition - teki.mPersonality->mNestPosition);
			pos.normalize();
			teki.mTargetPosition.set(teki.mPersonality->mNestPosition + pos * teki.getParameterF(TPF_DangerTerritoryRange));
		}
		return true;
	}

	ERROR("HEAVEN !!!\n"); // lol
	teki.mTargetPosition.set(teki.mPersonality->mNestPosition);
	return true;
}

/**
 * @todo: Documentation
 */
void TAIAflyingDistance::start(Teki& teki)
{
	teki.setFlag400();
	teki.startFlying();
	teki.mProps->mCreatureProps.mFaceDirAdjust(mFaceDir);
	teki.setSpeed(0.0f);
}

/**
 * @todo: Documentation
 */
bool TAIAflyingDistance::act(Teki& teki)
{
	f32 vel          = teki.getParameterF(TPF_RunVelocity);
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		bool check = false;
		f32 ratio  = zen::Abs(teki.getPosition().y - target->getPosition().y) / NMathF::tan(mDiveAngle);
		f32 offset = getOffset(teki) + ratio;
		f32 dist   = target->getPosition().distance(teki.getPosition()) - offset;
		f32 speed;
		if (zen::Abs(dist) < getGoalAreaRange(teki)) {
			speed = teki.getSpeed();
			teki.setSpeed(27.0f * gsys->getFrameTime() * speed);
			check = true;

		} else {
			speed = 0.05f * vel;
			if (zen::Abs(dist) > speed) {
				dist = ((dist > 0.0f) ? 1.0f : -1.0f) * speed;
			}
			speed = dist * 900.0f;
			teki.addSpeed(gsys->getFrameTime() * speed * gsys->getFrameTime());
		}

		if (zen::Abs(teki.getSpeed()) > vel) {
			teki.setSpeed(((teki.getSpeed() > 0.0f) ? 1.0f : -1.0f) * vel);
		}

		teki.mTargetAngle = NMathF::atan2(target->getPosition().x - teki.getPosition().x, target->getPosition().z - teki.getPosition().z);

		f32 angSep = angDist(teki.mTargetAngle, teki.mFaceDirection);

		teki.mFaceDirection += angSep * teki.mProps->mCreatureProps.mFaceDirAdjust() * gsys->getFrameTime() * 10.0f;
		teki.mFaceDirection = roundAng(teki.mFaceDirection);

		teki.mSRT.r.set(0.0f, teki.mFaceDirection, 0.0f);
		teki.mTargetVelocity.set(NMathF::sin(teki.mFaceDirection) * teki.getSpeed(), teki.mTargetVelocity.y,
		                         NMathF::cos(teki.mFaceDirection) * teki.getSpeed());

		bool res;
		f32 angle = teki.getParameterF(TPF_AttackableAngle);
		if (zen::Abs(angSep) < angle * PI / 180.0f && check && zen::Abs(teki.getSpeed()) < 1.0f) {
			teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			res = true;
		} else {
			res = false;
		}
		teki.mVelocity = teki.mTargetVelocity;
		return res;
	}

	return true;
}

/**
 * @todo: Documentation
 */
void TAIAdescent::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
	teki.startFlying();
	f32 y = mapMgr->getMinY(teki.getPosition().x, teki.getPosition().z, true);
	teki.mTargetPosition.set(teki.getPosition().x, y, teki.getPosition().z);
	teki.setFrameCounter(0.0f);
}

/**
 * @todo: Documentation
 */
bool TAIAdescent::act(Teki& teki)
{
	Vector3f accel;
	f32 height = teki.getYFromSeaLevel();
	PRINT("descent height %f \n", height);
	if (TAIAreserveMotion::act(teki)) {
		if (teki.addFrameCounter(gsys->getFrameTime()) > getForceDescentFrame(teki)) {
			teki.finishFlying();
		}

		if (height > 15.0f) {
			f32 vel = getFlyingVelocity(teki);
			accel.x = teki.mTargetPosition.x - teki.getPosition().x;
			accel.y = -vel * 0.05f;
			accel.z = teki.mTargetPosition.z - teki.getPosition().z;

			f32 len = accel.length();
			if (len > vel * 0.1f) {
				accel.div(len);
				accel.multiply(vel * 0.1f);
			}
			teki.mTargetVelocity.add(accel);
			f32 speed = teki.mTargetVelocity.length();
			if (speed > vel) {
				teki.mTargetVelocity.div(speed);
				teki.mTargetVelocity.multiply(vel);
			}
			teki.mVelocity = teki.mTargetVelocity;
			return false;
		}

		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
void TAIAlanding::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
	teki.finishFlying();
	teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	teki.mVelocity = teki.mTargetVelocity;
	teki.setStaySwitch(true);
}

/**
 * @todo: Documentation
 */
bool TAIAlanding::act(Teki& teki)
{
	if (teki.getYFromSeaLevel() < teki.getCentreSize() && teki.getStaySwitch()) {
		landingEffect(teki);
		teki.setStaySwitch(false);
	}

	if (TAIAreserveMotion::act(teki)) {
		if (teki.mCurrentAnimEvent == KEY_Action0 && teki.getYFromSeaLevel() < 1.0f) {
			landingEffect(teki);
		}
		if (teki.mTekiAnimator->isFinishing()) {
			teki.mDamageCount = 0.0f;
			return true;
		}
		return false;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void TAIAtakeOff::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
	teki.startFlying();
	teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	teki.mVelocity = teki.mTargetVelocity;
	teki.setFlyingSwitch(false);
}

/**
 * @todo: Documentation
 */
bool TAIAtakeOff::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			startFlying(teki);
		}

		if (teki.getFlyingSwitch()) {
			f32 height = teki.getYFromSeaLevel();
			f32 vel    = teki.getParameterF(TPF_WalkVelocity);
			teki.mTargetVelocity.y += vel * 0.5f * ((height < teki.getParameterF(TPF_FlightHeight)) ? 1.0f : -1.0f);
			if (teki.mTargetVelocity.y > vel) {
				teki.mTargetVelocity.y = vel;
			}

			if (teki.mTargetVelocity.y < -vel) {
				teki.mTargetVelocity.y = -vel;
			}

			teki.mVelocity = teki.mTargetVelocity;
		}

		if (teki.mCurrentAnimEvent == KEY_Finished) {
			return true;
		}

		return false;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void TAIAtakeOff::startFlying(Teki& teki)
{
	teki.setFlyingSwitch(true);
}
