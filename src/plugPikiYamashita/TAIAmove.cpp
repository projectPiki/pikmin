#include "TAI/Amove.h"
#include "nlib/Math.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "MapMgr.h"
#include "WorkObject.h"
#include "ItemMgr.h"
#include "GoalItem.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TAIAmove")

/*
 * --INFO--
 * Address:	801A8C2C
 * Size:	000094
 */
void TAIAappearKabekui::start(Teki& teki)
{
	TAIAsetMotionSpeed::start(teki);
	teki.setStaySwitch(false);
	if (_10) {
		teki.setTekiOption(BTeki::TEKI_OPTION_VISIBLE);
	}
}

/*
 * --INFO--
 * Address:	801A8CC0
 * Size:	0001A4
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

/*
 * --INFO--
 * Address:	801A8E64
 * Size:	000140
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

/*
 * --INFO--
 * Address:	801A8FA4
 * Size:	000008
 */
bool TAIAsetTargetPointWorkObject::act(Teki& teki)
{
	return true;
}

/*
 * --INFO--
 * Address:	801A8FAC
 * Size:	0001B0
 */
bool TAIAgoGoalPath::makePath(Teki& teki)
{
	GoalItem* onyon = itemMgr->getNearestContainer(teki.getPosition(), 12800.0f);
	if (onyon) {
		// `TAIAgoGoalPath` is obstructed by blocked paths, but requests a position route that permits them.
#ifdef BUGFIX
		teki.makePositionRoute(teki.getPosition(), onyon->getPosition(), false);
#else
		teki.makePositionRoute(teki.getPosition(), onyon->getPosition(), true);
#endif
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

/*
 * --INFO--
 * Address:	801A915C
 * Size:	00004C
 */
void TAIAgoGoalPath::start(Teki& teki)
{
	teki.setTableIndex(0);
	makePath(teki);
	TAIAgoTargetPriorityFaceDir::start(teki);
}

/*
 * --INFO--
 * Address:	801A91A8
 * Size:	000118
 */
bool TAIAgoGoalPath::act(Teki& teki)
{
	bool res = false;
	if (TAIAgoTargetPriorityFaceDir::act(teki)) {
		teki.setTableIndex(teki.getTableIndex() + 1);
		// If Dororo (Smoky Progg) plots a route containing the maximum number of waypoints, `getRouteWayPoint` will
		// eventually return an un-checked nullptr.  Without this bounds-check, a crash is possible in Distant Spring.
#ifdef BUGFIX
		if (teki.getTableIndex() >= teki.mRouteWayPointCount || teki.getTableIndex() >= teki.mRouteWayPointMax)
#else
		if (teki.getTableIndex() >= teki.mRouteWayPointCount)
#endif
		{
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

/*
 * --INFO--
 * Address:	801A92C0
 * Size:	0000EC
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

/*
 * --INFO--
 * Address:	801A93AC
 * Size:	000100
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

/*
 * --INFO--
 * Address:	801A94AC
 * Size:	000008
 */
bool TAIAsetTargetPointCircleRandom::act(Teki& teki)
{
	return true;
}

/*
 * --INFO--
 * Address:	801A94B4
 * Size:	000020
 */
void TAIAsetTargetPointCircle::start(Teki& teki)
{
	setTargetPoint(teki);
}

/*
 * --INFO--
 * Address:	801A94D4
 * Size:	000024
 */
bool TAIAsetTargetPointCircle::act(Teki& teki)
{
	setTargetPoint(teki);
	return true;
}

/*
 * --INFO--
 * Address:	801A94F8
 * Size:	000110
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

/*
 * --INFO--
 * Address:	801A9608
 * Size:	000038
 */
void TAIAgoTarget::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.resetFlag400();
}

/*
 * --INFO--
 * Address:	801A9640
 * Size:	000108
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

/*
 * --INFO--
 * Address:	801A9760
 * Size:	000038
 */
void TAIAgoTargetPriorityFaceDir::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/*
 * --INFO--
 * Address:	801A9798
 * Size:	00009C
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

/*
 * --INFO--
 * Address:	801A9834
 * Size:	0000B8
 */
bool TAIAgoTargetPriorityFaceDir::checkArrival(Teki& teki)
{
	return teki.mTargetPosition.distance(teki.getPosition()) <= teki.getParameterF(TPF_WalkVelocity);
}

/*
 * --INFO--
 * Address:	801A98EC
 * Size:	000018
 */
f32 TAIAgoTargetPriorityFaceDir::getWalkVelocity(Teki& teki)
{
	return teki.getParameterF(TPF_WalkVelocity);
}

/*
 * --INFO--
 * Address:	801A9904
 * Size:	000038
 */
void TAIAapproachTargetPriorityFaceDir::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/*
 * --INFO--
 * Address:	801A993C
 * Size:	000088
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void TAIAlookAround::setTargetDirection(Teki& teki, f32 angle)
{
	teki.mTargetAngle = (angle + zen::Rand(angle)) * ((zen::Rand(10.0f) > 5.0f) ? 1.0f : -1.0f) + teki.mFaceDirection;
	teki.mTargetAngle = roundAng(teki.mTargetAngle);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A99DC
 * Size:	0000DC
 */
void TAIAlookAround::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFrameCounter(0.0f);
	teki.setStatus(2);
	setTargetDirection(teki, 40.0f * PI / 180.0f);
}

/*
 * --INFO--
 * Address:	801A9AB8
 * Size:	00031C
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
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
			}
			if (teki.mTekiAnimator->isFinishing()) {
				teki.mTekiAnimator->startMotion(PaniMotionInfo(motionID, &teki));
			}
		} else if (teki.turnToward(teki.mTargetAngle, teki.getParameterF(TPF_TurnVelocity))) {
			teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
			teki.setFrameCounter(0.0f);
			teki.setStatus(1);
		}
		break;
	case 1:
		if (teki.mTekiAnimator->getCurrentMotionIndex() != mMotionID || teki.mTekiAnimator->isFinished()) {
			if (!teki.mTekiAnimator->isFinished()) {
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
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
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
			}
		}
		break;
	}

	u32 badCompiler[2];
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
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

/*
 * --INFO--
 * Address:	801A9DD4
 * Size:	0000CC
 */
void TAIAturnToTarget::start(Teki& teki)
{
	teki.setFlag400();
	teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);
	mMotionID         = getTurnMotionIndex(teki);
	TAIAreserveMotion::start(teki);
}

/*
 * --INFO--
 * Address:	801A9EA0
 * Size:	0001E8
 */
bool TAIAturnToTarget::act(Teki& teki)
{
	bool res     = false;
	int motionID = getTurnMotionIndex(teki);
	if (teki.mTekiAnimator->getCurrentMotionIndex() != motionID || teki.mTekiAnimator->isFinished()) {
		if (!teki.mTekiAnimator->isFinished()) {
			teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
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
					teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
				}
				res = true;
			}
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AA088
 * Size:	000078
 */
void TAIAstop::start(Teki& teki)
{
	teki.stopMove();
}

/*
 * --INFO--
 * Address:	801AA100
 * Size:	00005C
 */
void TAIArandomWalk::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	makeTargetPosition(teki);
	teki.resetFlag400();
	teki.mProps->mCreatureProps.mFaceDirAdjust(0.1f);
}

/*
 * --INFO--
 * Address:	801AA15C
 * Size:	0000E8
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

	u32 badCompiler;
	return res;
}

/*
 * --INFO--
 * Address:	801AA244
 * Size:	000100
 */
void TAIArandomWalk::makeTargetPosition(Teki& teki)
{
	f32 angle = 2.0f * NSystem::random() * NMathF::pi;
	f32 dist  = 200.0f * NSystem::random();
	Vector3f offset(dist * NMathF::sin(angle), 0.0f, dist * NMathF::cos(angle));
	teki.mTargetPosition.add2(teki.getPosition(), offset);
}

/*
 * --INFO--
 * Address:	801AA344
 * Size:	000020
 */
void TAIAturnOccasion::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
}

/*
 * --INFO--
 * Address:	801AA364
 * Size:	0000B4
 */
bool TAIAturnOccasion::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		teki.mTargetAngle = teki.calcTargetDirection(teki.mTargetPosition);
		return teki.turnToward(teki.mTargetAngle, teki.getParameterF(TPF_TurnVelocity));
	}
	return false;
}

/*
 * --INFO--
 * Address:	801AA418
 * Size:	000118
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

/*
 * --INFO--
 * Address:	801AA530
 * Size:	000078
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

/*
 * --INFO--
 * Address:	801AA5A8
 * Size:	000084
 */
void TAIAwait::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.stopMove();
	teki.setFrameCounter(0.0f);
}

/*
 * --INFO--
 * Address:	801AA62C
 * Size:	000098
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

/*
 * --INFO--
 * Address:	........
 * Size:	000058
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

/*
 * --INFO--
 * Address:	801AA6CC
 * Size:	00007C
 */
TAIApatrol::TAIApatrol(int nextState, int p2, int leftMotionID, int rightMotionID, Vector3f* p5, int p6, bool p7)
    : TAIAturnToTarget(nextState, leftMotionID, rightMotionID, p7)
{
	_20 = p2;
	_18 = p5;
	_1C = p6;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void TAIApatrol::setTargetPosition(Teki& teki)
{
	int idx       = teki.getTableIndex();
	Vector3f& vec = _18[idx];
	f32 rad       = teki.getParameterF(TPF_DangerTerritoryRange);
	teki.mTargetPosition.set(vec.x * rad + teki.mPersonality->mNestPosition.x, vec.y * rad + teki.mPersonality->mNestPosition.y,
	                         vec.z * rad + teki.mPersonality->mNestPosition.z);
	teki.setFrameCounter(0.0f);
}

/*
 * --INFO--
 * Address:	801AA748
 * Size:	0002B0
 */
void TAIApatrol::start(Teki& teki)
{
	teki.setTableIndex(0);
	for (int i = 0; i < _1C; i++) {
		setTargetPosition(teki);
		f32 y = zen::Abs(teki.getPosition().y - teki.mTargetPosition.y);
		f32 x = zen::Abs(teki.getPosition().x - teki.mTargetPosition.x);
		f32 z = zen::Abs(teki.getPosition().z - teki.mTargetPosition.z);
		f32 v = x + y + z;
		f32 minDist;
		if (i == 0) {
			minDist = v;
		} else if (v > minDist) {
			teki.setTableIndex(i);
		}
	}

	setTargetPosition(teki);
	TAIAturnToTarget::start(teki);
	changeStatus(1, teki);

	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xA8(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xA4(r1)
	  stw       r28, 0xA0(r1)
	  li        r28, 0
	  stw       r0, 0x470(r4)
	  lfs       f30, -0x4A68(r2)
	  b         .loc_0x118

	.loc_0x40:
	  lwz       r0, 0x470(r31)
	  li        r4, 0xF
	  lwz       r3, 0x2C4(r31)
	  mulli     r0, r0, 0xC
	  lwz       r5, 0x18(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  add       r29, r5, r0
	  bl        -0x882D4
	  lfs       f0, 0x0(r29)
	  lwz       r3, 0x2C8(r31)
	  lfs       f3, 0x4(r29)
	  fmuls     f0, f0, f1
	  lfs       f2, 0x10(r3)
	  lfs       f5, 0x8(r29)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x14(r3)
	  fadds     f0, f2, f0
	  lfs       f2, 0x18(r3)
	  fmuls     f1, f5, f1
	  fadds     f3, f4, f3
	  stfs      f0, 0x388(r31)
	  fadds     f0, f2, f1
	  stfs      f3, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  stfs      f30, 0x478(r31)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x38C(r31)
	  fsubs     f2, f1, f0
	  fcmpo     cr0, f2, f30
	  bge-      .loc_0xC0
	  fneg      f2, f2

	.loc_0xC0:
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x388(r31)
	  fsubs     f3, f1, f0
	  fcmpo     cr0, f3, f30
	  bge-      .loc_0xD8
	  fneg      f3, f3

	.loc_0xD8:
	  lfs       f1, 0x9C(r31)
	  lfs       f0, 0x390(r31)
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f30
	  bge-      .loc_0xF0
	  fneg      f1, f1

	.loc_0xF0:
	  fadds     f0, f3, f2
	  cmpwi     r28, 0
	  fadds     f0, f1, f0
	  bne-      .loc_0x108
	  fmr       f31, f0
	  b         .loc_0x114

	.loc_0x108:
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x114
	  stw       r28, 0x470(r31)

	.loc_0x114:
	  addi      r28, r28, 0x1

	.loc_0x118:
	  lwz       r0, 0x1C(r30)
	  cmpw      r28, r0
	  blt+      .loc_0x40
	  lwz       r0, 0x470(r31)
	  li        r4, 0xF
	  lwz       r3, 0x2C4(r31)
	  mulli     r0, r0, 0xC
	  lwz       r5, 0x18(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  add       r29, r5, r0
	  bl        -0x883B8
	  lfs       f0, 0x0(r29)
	  addi      r6, r1, 0x70
	  lwz       r3, 0x2C8(r31)
	  addi      r5, r1, 0x6C
	  lfs       f3, 0x4(r29)
	  fmuls     f0, f0, f1
	  lfs       f2, 0x10(r3)
	  lfs       f5, 0x8(r29)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x14(r3)
	  fadds     f0, f2, f0
	  lfs       f2, 0x18(r3)
	  fmuls     f1, f5, f1
	  addi      r4, r1, 0x68
	  fadds     f3, f4, f3
	  stfs      f0, 0x388(r31)
	  fadds     f0, f2, f1
	  addi      r3, r1, 0x80
	  stfs      f3, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  stfs      f0, 0x88(r1)
	  stfs      f0, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  lfs       f1, 0x390(r31)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x38C(r31)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  bl        -0x14D2A4
	  lfs       f1, 0x80(r1)
	  lfs       f2, 0x88(r1)
	  bl        -0x8CB34
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x172398
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x21C
	  lwz       r0, 0xC(r30)
	  b         .loc_0x220

	.loc_0x21C:
	  lwz       r0, 0x10(r30)

	.loc_0x220:
	  stw       r0, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x2390
	  li        r0, 0x1
	  stw       r0, 0x46C(r31)
	  lwz       r0, 0x46C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x254
	  bge-      .loc_0x288
	  cmpwi     r0, 0
	  bge-      .loc_0x27C
	  b         .loc_0x288

	.loc_0x254:
	  lfs       f0, 0x1594(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1598(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x159C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  b         .loc_0x288

	.loc_0x27C:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)

	.loc_0x288:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  lwz       r28, 0xA0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA9F8
 * Size:	000354
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
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
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
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
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

	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stw       r31, 0xFC(r1)
	  mr        r31, r4
	  stw       r30, 0xF8(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x46C(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3C
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  bge-      .loc_0xAC
	  b         .loc_0x334

	.loc_0x3C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0xB9C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x334
	  li        r0, 0
	  stw       r0, 0x46C(r31)
	  lwz       r0, 0x46C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x74
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  bge-      .loc_0x9C
	  b         .loc_0x334

	.loc_0x74:
	  lfs       f0, 0x1594(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1598(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x159C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0x9C:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0xAC:
	  lwz       r4, 0x2CC(r31)
	  lwz       r0, 0x20(r30)
	  lwz       r3, 0x44(r4)
	  cmpw      r0, r3
	  bne-      .loc_0xCC
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x13C

	.loc_0xCC:
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x100
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xE8
	  lwz       r5, 0x2C0(r31)

	.loc_0xE8:
	  addi      r3, r1, 0xEC
	  li        r4, -0x1
	  bl        -0x8BB5C
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8B8C4

	.loc_0x100:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x334
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x120
	  lwz       r5, 0x2C0(r31)

	.loc_0x120:
	  lwz       r4, 0x20(r30)
	  addi      r3, r1, 0xE4
	  bl        -0x8BB94
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8B96C
	  b         .loc_0x334

	.loc_0x13C:
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x388(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x38C(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA8(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f1, 0xC4(r1)
	  stfs      f3, 0xC8(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  lfs       f2, 0xC8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19CF5C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x478(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f2, f0
	  stfs      f0, 0x478(r31)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x200
	  mr        r3, r30
	  lfs       f31, 0x478(r31)
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x314

	.loc_0x200:
	  lwz       r3, 0x470(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x470(r31)
	  lwz       r3, 0x470(r31)
	  lwz       r0, 0x1C(r30)
	  cmpw      r3, r0
	  blt-      .loc_0x224
	  li        r0, 0
	  stw       r0, 0x470(r31)

	.loc_0x224:
	  lwz       r0, 0x470(r31)
	  li        r4, 0xF
	  lwz       r3, 0x2C4(r31)
	  mulli     r0, r0, 0xC
	  lwz       r5, 0x18(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  add       r30, r5, r0
	  bl        -0x88768
	  lfs       f0, 0x0(r30)
	  cmplwi    r31, 0
	  lwz       r3, 0x2C8(r31)
	  mr        r5, r31
	  lfs       f3, 0x4(r30)
	  fmuls     f0, f0, f1
	  lfs       f2, 0x10(r3)
	  lfs       f5, 0x8(r30)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x14(r3)
	  fadds     f0, f2, f0
	  lfs       f2, 0x18(r3)
	  fmuls     f1, f5, f1
	  fadds     f3, f4, f3
	  stfs      f0, 0x388(r31)
	  fadds     f0, f2, f1
	  stfs      f3, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x478(r31)
	  beq-      .loc_0x2A0
	  lwz       r5, 0x2C0(r31)

	.loc_0x2A0:
	  addi      r3, r1, 0xDC
	  li        r4, -0x1
	  bl        -0x8BD14
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8BA7C
	  li        r0, 0x1
	  stw       r0, 0x46C(r31)
	  lwz       r0, 0x46C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2DC
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  bge-      .loc_0x304
	  b         .loc_0x334

	.loc_0x2DC:
	  lfs       f0, 0x1594(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1598(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x159C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0x304:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0x314:
	  lwz       r5, 0x2C4(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0x388
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f1, 0xC(r5)
	  bl        -0x63938

	.loc_0x334:
	  lwz       r0, 0x10C(r1)
	  li        r3, 0
	  lfd       f31, 0x100(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AAD54
 * Size:	000038
 */
void TAIAstepBack::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/*
 * --INFO--
 * Address:	801AAD8C
 * Size:	000164
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
			teki.mRotation.set(0.0f, teki.mFaceDirection, 0.0f);
			teki.mTargetVelocity.set(NMathF::sin(teki.mFaceDirection), 0.0f, NMathF::cos(teki.mFaceDirection));
			teki.mTargetVelocity.multiply(-speed);
			return false;
		}

		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801AAF08
 * Size:	000110
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

/*
 * --INFO--
 * Address:	801AB018
 * Size:	0000C4
 */
bool TAIAturnHome::act(Teki& teki)
{
	return TAIAturnOccasion::act(teki);
}

/*
 * --INFO--
 * Address:	801AB0DC
 * Size:	000038
 */
void TAIAgoingHome::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.resetFlag400();
}

/*
 * --INFO--
 * Address:	801AB114
 * Size:	0000F0
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

/*
 * --INFO--
 * Address:	801AB204
 * Size:	000038
 */
void TAIAgoingHomePriorityFaceDir::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
}

/*
 * --INFO--
 * Address:	801AB23C
 * Size:	0000F0
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

/*
 * --INFO--
 * Address:	801AB32C
 * Size:	00002C
 */
void TAIAflyingBase::start(Teki& teki)
{
	teki.startFlying();
	teki.setChokeSwitch(false);
}

/*
 * --INFO--
 * Address:	801AB358
 * Size:	000078
 */
bool TAIAflyingBase::act(Teki& teki)
{
	teki.flyingStay(getFlyingStayVelocity(teki));
	if (teki.getYFromSeaLevel() > teki.getParameterF(TPF_FlightHeight)) {
		teki.setChokeSwitch(true);
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
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

/*
 * --INFO--
 * Address:	801AB40C
 * Size:	0001B0
 */
void TAIAflyingInTerritory::start(Teki& teki)
{
	teki.setFlag400();
	teki.startFlying();
	teki.resetFlag400();
	setTargetPosition(teki);
}

/*
 * --INFO--
 * Address:	801AB5BC
 * Size:	000430
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

/*
 * --INFO--
 * Address:	801AB9EC
 * Size:	000050
 */
void TAIAflyingToGoal::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFlag400();
	teki.startFlying();
}

/*
 * --INFO--
 * Address:	801ABA3C
 * Size:	000330
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

/*
 * --INFO--
 * Address:	801ABD8C
 * Size:	000080
 */
void TAIAflyingDistanceInTerritory::start(Teki& teki)
{
	TAIAflyingToGoal::start(teki);
	teki.setFlag400();
	goal(teki);
}

/*
 * --INFO--
 * Address:	801ABE0C
 * Size:	000048
 */
bool TAIAflyingDistanceInTerritory::act(Teki& teki)
{
	teki.turnToTarget();
	return TAIAflyingToGoal::act(teki);
}

/*
 * --INFO--
 * Address:	801ABE54
 * Size:	000348
 */
bool TAIAflyingDistanceInTerritory::goal(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		Vector3f pos;
		f32 ratio = zen::Abs(teki.getPosition().y - target->getPosition().y) / NMathF::tan(_00);
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

	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	return true;
}

/*
 * --INFO--
 * Address:	801AC19C
 * Size:	00003C
 */
void TAIAflyingDistance::start(Teki& teki)
{
	teki.setFlag400();
	teki.startFlying();
	teki.mProps->mCreatureProps.mFaceDirAdjust(_08);
	teki.setSpeed(0.0f);
}

/*
 * --INFO--
 * Address:	801AC1D8
 * Size:	0003A0
 */
bool TAIAflyingDistance::act(Teki& teki)
{
	f32 vel          = teki.getParameterF(TPF_RunVelocity);
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		bool check = false;
		f32 ratio  = zen::Abs(teki.getPosition().y - target->getPosition().y) / NMathF::tan(_00);
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

		teki.mRotation.set(0.0f, teki.mFaceDirection, 0.0f);
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

	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	PRINT("fake", &teki ? "fake" : "fake");
	return true;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stfd      f29, 0x140(r1)
	  stw       r31, 0x13C(r1)
	  mr        r31, r4
	  stw       r30, 0x138(r1)
	  stw       r29, 0x134(r1)
	  stw       r28, 0x130(r1)
	  mr        r28, r3
	  lwz       r4, 0x2C4(r4)
	  lwz       r30, 0x418(r31)
	  lwz       r3, 0x84(r4)
	  cmplwi    r30, 0
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f31, 0x10(r3)
	  beq-      .loc_0x370
	  lfs       f2, 0x98(r31)
	  li        r29, 0
	  lfs       f1, 0x98(r30)
	  lfs       f0, -0x4A68(r2)
	  fsubs     f29, f2, f1
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x70
	  fneg      f29, f29

	.loc_0x70:
	  lfs       f1, 0x8(r28)
	  bl        0x6F884
	  addi      r3, r28, 0x8
	  fmr       f30, f1
	  lwz       r12, 0x14(r28)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fdivs     f2, f29, f30
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x118(r1)
	  stfs      f0, 0x114(r1)
	  stfs      f0, 0x110(r1)
	  fadds     f30, f2, f1
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x94(r30)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xE4(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xE4(r1)
	  stfs      f0, 0x110(r1)
	  stfs      f1, 0x114(r1)
	  stfs      f3, 0x118(r1)
	  lfs       f1, 0x110(r1)
	  lfs       f0, 0x114(r1)
	  lfs       f2, 0x118(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19E69C
	  fsubs     f1, f1, f30
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  fmr       f29, f1
	  bge-      .loc_0x124
	  fneg      f30, f29
	  b         .loc_0x128

	.loc_0x124:
	  fmr       f30, f29

	.loc_0x128:
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  mr        r4, r31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f30, f1
	  bge-      .loc_0x16C
	  lwz       r3, 0x2DEC(r13)
	  li        r29, 0x1
	  lfs       f1, -0x4A08(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x490(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x490(r31)
	  b         .loc_0x1D4

	.loc_0x16C:
	  lfs       f0, -0x4A68(r2)
	  lfs       f1, -0x4A04(r2)
	  fcmpo     cr0, f29, f0
	  fmuls     f1, f1, f31
	  bge-      .loc_0x188
	  fneg      f0, f29
	  b         .loc_0x18C

	.loc_0x188:
	  fmr       f0, f29

	.loc_0x18C:
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x1B0
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f29, f0
	  ble-      .loc_0x1A8
	  lfs       f0, -0x4A60(r2)
	  b         .loc_0x1AC

	.loc_0x1A8:
	  lfs       f0, -0x4A24(r2)

	.loc_0x1AC:
	  fmuls     f29, f1, f0

	.loc_0x1B0:
	  lfs       f0, -0x4A0C(r2)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f0, f0, f29
	  lfs       f1, 0x490(r31)
	  lfs       f2, 0x28C(r3)
	  fmuls     f0, f0, f2
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x490(r31)

	.loc_0x1D4:
	  lfs       f1, 0x490(r31)
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1EC
	  fneg      f0, f1
	  b         .loc_0x1F0

	.loc_0x1EC:
	  fmr       f0, f1

	.loc_0x1F0:
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x218
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x20C
	  lfs       f0, -0x4A60(r2)
	  b         .loc_0x210

	.loc_0x20C:
	  lfs       f0, -0x4A24(r2)

	.loc_0x210:
	  fmuls     f0, f31, f0
	  stfs      f0, 0x490(r31)

	.loc_0x218:
	  lfs       f1, 0x94(r31)
	  lfs       f3, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        -0x8E600
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x173E64
	  lwz       r4, 0x224(r31)
	  fmr       f30, f1
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  fmuls     f1, f30, f2
	  lfs       f3, -0x4A2C(r2)
	  lfs       f2, 0xA0(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f3, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x173EC8
	  stfs      f1, 0xA0(r31)
	  lfs       f0, 0x15C8(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x15CC(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f1, 0xA0(r31)
	  bl        0x6F6E0
	  lfs       f0, 0x490(r31)
	  lfs       f2, 0xA0(r31)
	  fmuls     f31, f1, f0
	  fmr       f1, f2
	  bl        0x6F860
	  lfs       f0, 0x490(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xA4(r31)
	  stfs      f31, 0xAC(r31)
	  lwz       r3, 0x2C4(r31)
	  lfs       f0, -0x4A68(r2)
	  lwz       r3, 0x84(r3)
	  fcmpo     cr0, f30, f0
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f2, 0x24(r3)
	  bge-      .loc_0x2EC
	  fneg      f3, f30
	  b         .loc_0x2F0

	.loc_0x2EC:
	  fmr       f3, f30

	.loc_0x2F0:
	  lfs       f1, -0x4A00(r2)
	  lfs       f0, -0x49FC(r2)
	  fmuls     f1, f1, f2
	  fdivs     f0, f1, f0
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x350
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x350
	  lfs       f1, 0x490(r31)
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x324
	  fneg      f1, f1

	.loc_0x324:
	  lfs       f0, -0x4A60(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x350
	  lfs       f0, 0x15D0(r13)
	  li        r3, 0x1
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x15D4(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x15D8(r13)
	  stfs      f0, 0xAC(r31)
	  b         .loc_0x354

	.loc_0x350:
	  li        r3, 0

	.loc_0x354:
	  lwz       r4, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  b         .loc_0x374

	.loc_0x370:
	  li        r3, 0x1

	.loc_0x374:
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lwz       r31, 0x13C(r1)
	  lwz       r30, 0x138(r1)
	  lwz       r29, 0x134(r1)
	  lwz       r28, 0x130(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC598
 * Size:	000080
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

/*
 * --INFO--
 * Address:	801AC618
 * Size:	0002BC
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

/*
 * --INFO--
 * Address:	801AC8F4
 * Size:	000090
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

/*
 * --INFO--
 * Address:	801AC984
 * Size:	000110
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

/*
 * --INFO--
 * Address:	801ACA98
 * Size:	000090
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

/*
 * --INFO--
 * Address:	801ACB28
 * Size:	000118
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

/*
 * --INFO--
 * Address:	801ACC40
 * Size:	000014
 */
void TAIAtakeOff::startFlying(Teki& teki)
{
	teki.setFlyingSwitch(true);
}
