#include "Piki.h"
#include "PikiState.h"
#include "PikiMgr.h"
#include "ItemMgr.h"
#include "GoalItem.h"
#include "Pellet.h"
#include "zen/Math.h"
#include "KMath.h"
#include "UfoItem.h"
#include "PikiAI.h"
#include "PlayerState.h"
#include "AIPerf.h"
#include "AIConstant.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "teki.h"
#include "Boss.h"
#include "MoviePlayer.h"
#include "MapCode.h"
#include "ItemObject.h"
#include "WeedsItem.h"
#include "UtilityKando.h"
#include "RumbleMgr.h"
#include "gameflow.h"
#include "FlowController.h"
#include "WorkObject.h"
#include "EffectMgr.h"
#include "DebugLog.h"

Colour Piki::pikiColors[6] = {
	Colour(0, 50, 255, 255),  // blue
	Colour(255, 30, 0, 255),  // red
	Colour(255, 210, 0, 255), // yellow
	Colour(255, 255, 255, 0), // white
};

Colour Piki::kinokoColors[6] = {
	Colour(40, 0, 80, 255),   // deep purple
	Colour(40, 0, 80, 255),   // deep purple
	Colour(40, 0, 80, 255),   // deep purple
	Colour(40, 0, 80, 255),   // deep purple
	Colour(255, 255, 255, 0), // white
};

bool Piki::directDumpMode;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	800C6558
 * Size:	000300
 */
bool Piki::isSafeMePos(Vector3f& pos)
{
	for (int i = PikiMinColor; i < PikiColorCount; i++) {
		GoalItem* onyon = itemMgr->getContainer(i);
		if (onyon && !onyon->insideSafeArea(pos)) {
			return false;
		}
	}

	UfoItem* ship = itemMgr->getUfo();
	if (ship && !ship->insideSafeArea(pos)) {
		return false;
	}

	Iterator iterPot(itemMgr->getMeltingPotMgr());
	CI_LOOP(iterPot)
	{
		Creature* item = *iterPot;
		if (item->isSluice() && !item->insideSafeArea(pos)) {
			return false;
		}
	}

	Iterator iterWork(workObjectMgr);
	CI_LOOP(iterWork)
	{
		Creature* workObj = *iterWork;
		if (!workObj->insideSafeArea(pos)) {
			return false;
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	800C6858
 * Size:	0000AC
 */
void Piki::startDemo()
{
	if (!appearDemo()) {
		mFreeLightEffect->stop();
		mBurnEffect->stop();
		mSlimeEffect->stop();
		mRippleEffect->stop();
		mPanickedEffect->stop();
		PikiState* state = static_cast<PikiState*>(getCurrState());
		if (state) {
			state->stopEffect();
		}
	}
}

/*
 * --INFO--
 * Address:	800C6908
 * Size:	0000A0
 */
void Piki::finishDemo()
{
	mFreeLightEffect->restart();
	mBurnEffect->restart();
	mSlimeEffect->restart();
	mRippleEffect->restart();
	mPanickedEffect->restart();
	PikiState* state = static_cast<PikiState*>(getCurrState());
	if (state) {
		state->restartEffect();
	}
}

/*
 * --INFO--
 * Address:	800C69AC
 * Size:	0000D4
 */
bool Piki::appearDemo()
{
	if (mColor == Blue && gameflow.mDemoFlags & 8) {
		return false;
	} else if (mColor == Red && gameflow.mDemoFlags & 0x10) {
		return false;
	} else if (mColor == Yellow && gameflow.mDemoFlags & 0x20) {
		return false;
	} else if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(1)) {
		return false;
	} else if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(2)) {
		return false;
	} else if (!pikiMgr->isUpdating(4)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800C6A80
 * Size:	000008
 */
int Piki::getUpperMotionIndex()
{
	return mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex();
}

/*
 * --INFO--
 * Address:	800C6A88
 * Size:	000030
 */
void Piki::addCntCallback()
{
	if (!isAlive()) {
		PRINT("dead piki addCnt! %d\n", getCnt());
	}
}

/*
 * --INFO--
 * Address:	800C6AB8
 * Size:	000004
 */
void Piki::subCntCallback()
{
}

/*
 * --INFO--
 * Address:	800C6ABC
 * Size:	000044
 */
f32 Piki::getAttackPower()
{
	if (mColor == Blue) {
		return pikiMgr->mPikiParms->mPikiParms.mBlueAttackPower();
	}
	if (mColor == Red) {
		return pikiMgr->mPikiParms->mPikiParms.mRedAttackPower();
	}

	// yellow
	return pikiMgr->mPikiParms->mPikiParms.mYellowAttackPower();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
PikiState* Piki::getPikiState()
{
	return static_cast<PikiState*>(getCurrState());
}

/*
 * --INFO--
 * Address:	800C6B00
 * Size:	00035C
 */
int Piki::findRoute(int sourceWaypointIndex, int destWaypointIndex, bool isRetryAttempt, bool useAsynchronous)
{
	// First, check if the destination is an onion
	int destinationType = -1;
	for (int i = PikiMinColor; i < PikiColorCount; i++) {
		GoalItem* onyon = itemMgr->getContainer(i);
		if (onyon && onyon->mWaypointIdx == destWaypointIndex) {
			destinationType = i;
			break;
		}
	}

	// Check if the destination is Olimar's ship
	UfoItem* ship = itemMgr->getUfo();
	if (ship && ship->mWaypointID == destWaypointIndex) {
		destinationType = 3;
	}

	// If destination isn't a special point, try to copy an existing path
	// from another Piki that's already calculated this route
	if (destinationType == -1) {
		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Piki* piki = static_cast<Piki*>(*iter);
			// Find another Piki with matching route parameters
			if (piki->mRouteSourceIndex == sourceWaypointIndex && piki->mRouteDestinationIndex == destWaypointIndex
			    && isRetryAttempt == piki->mIsRetryPathfind && piki->mPathBuffers[0].mWayPointIdx == sourceWaypointIndex) {

				bool keepSearching = true;
				int pathLength     = 0;
				int safetyCounter  = 0;

				for (int i = 0; keepSearching; i++) {
					safetyCounter++;
					if (safetyCounter > 1000) {
						ERROR("array violation!\n");
					}

					// Copy waypoint data
					mPathBuffers[i].mWayPointIdx = piki->mPathBuffers[i].mWayPointIdx;
					int currentPoint             = mPathBuffers[i].mWayPointIdx;
					mPathBuffers[i]._04          = piki->mPathBuffers[i]._04;
					pathLength++;

					// Check if we've reached the destination
					if (currentPoint == destWaypointIndex) {
						mRouteSourceIndex      = sourceWaypointIndex;
						mRouteDestinationIndex = destWaypointIndex;
						mIsRetryPathfind       = isRetryAttempt;
						return pathLength;
					}

					// Check if we've examined all possible waypoints
					int totalWaypoints = routeMgr->getNumWayPoints('test');
					if (totalWaypoints <= pathLength) {
						// we've checked all way points on the map
						keepSearching = false;
						PRINT("i is %d : rnum = %d : num = %d\n", i, totalWaypoints, pathLength);
						for (int j = 0; j < totalWaypoints; j++) {
							;
						}
					}
				}
			}
		}
	}

	mRouteSourceIndex      = sourceWaypointIndex;
	mRouteDestinationIndex = destWaypointIndex;
	mIsRetryPathfind       = isRetryAttempt;

	// Calculate new path
	int handle;
	if (destinationType != -1) {
		handle
		    = routeMgr->getPathFinder('test')->findSyncOnyon(mPosition, mPathBuffers, sourceWaypointIndex, destinationType, isRetryAttempt);
		if (!handle) {
			PRINT("ONYON ROOT FAILED\n");
		}
	} else {
		if (useAsynchronous && AIPerf::useASync) {
			mUseAsyncPathfinding = true;
			if (mRouteHandle == 0) {
				mRouteHandle
				    = routeMgr->getPathFinder('test')->findASync(mPathBuffers, sourceWaypointIndex, destWaypointIndex, isRetryAttempt);
				PRINT("*** %x START ASYNC ROUTE FIND (handle=%d)\n", mRouteHandle);
			}
			return -55;
		}

		handle = routeMgr->getPathFinder('test')->findSync(mPathBuffers, sourceWaypointIndex, destWaypointIndex, isRetryAttempt);
	}

	if (!handle) {
		PRINT("root find failed\n");
		mRouteDestinationIndex = -1;
		mRouteSourceIndex      = -1;
	}

	return handle;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
bool Piki::initRouteTraceDynamic(Creature* target)
{
	if (!initRouteTrace(target->getCentre(), true)) {
		mRouteTargetCreature = nullptr;
		return false;
	}
	mRouteTargetCreature = target;
	return true;
}

/*
 * --INFO--
 * Address:	800C6E5C
 * Size:	0001CC
 */
int Piki::moveRouteTraceDynamic(f32 p1)
{
	u32 badCompiler; // some other temp, whatever.

	int traceRes = moveRouteTrace(p1);
	if (traceRes != 2) {
		return traceRes;
	}

	if (mUseAsyncPathfinding) {
		return 2;
	}

	Vector3f centre = mRouteTargetCreature->getCentre();
	centre.sub(mPosition);
	f32 dist = centre.length();
	if (dist < 110.0f) {
		return 0;
	}

	if (mNumRoutePoints >= 4 && f32(mCurrRoutePoint) / f32(mNumRoutePoints) >= 0.75f) {
		PRINT("pathfind again\n");
		if (!initRouteTraceDynamic(mRouteTargetCreature)) {
			return 1;
		}
	}
	return 2;
}

/*
 * --INFO--
 * Address:	800C7028
 * Size:	0004C0
 */
bool Piki::initRouteTrace(Vector3f& targetPos, bool p2)
{
	if (mRouteHandle) {
		routeMgr->getPathFinder('test')->releaseHandle(mRouteHandle);
		mRouteHandle = 0;
	}

	mUseAsyncPathfinding = false;
	bool onlyLand        = true;
	if (mColor == Blue) {
		onlyLand = false;
	}
	PRINT("****** PIKI FIND NEAREST EDGE AVOID OFF================\n");
	WayPoint* wp1;
	WayPoint* wp2;
	routeMgr->findNearestEdgeAvoidOff(&wp1, &wp2, 'test', mPosition, onlyLand, true, false);

	WayPoint* nearestPikiWP;
	if (wp1 && wp2) {
		Vector3f wp1Dist = wp1->mPosition - mPosition;
		Vector3f wp2Dist = wp2->mPosition - mPosition;
		if (wp1Dist.length() > wp2Dist.length()) {
			nearestPikiWP = wp2;
		} else {
			nearestPikiWP = wp1;
		}
	} else {
		PRINT("gakkari desu ...\n");
		nearestPikiWP = routeMgr->findNearestWayPoint('test', mPosition, onlyLand);
	}

	WayPoint* nearestTargetWP = routeMgr->findNearestWayPoint('test', targetPos, false);
	mRouteStartPos            = mPosition;
	mRouteGoalPos             = targetPos;

	if (onlyLand) {
		PathFinder::setMode(1);
	}

	mNumRoutePoints = findRoute(nearestPikiWP->mIndex, nearestTargetWP->mIndex, false, p2);

	if (onlyLand) {
		PathFinder::clearMode();
	}

	if (p2 && mUseAsyncPathfinding && mNumRoutePoints == -55) {
		PRINT("*** ASYNC SUCCESS %x\n", this);
		return true;
	}

	if (mNumRoutePoints <= 0) {
		return false;
	}

	mCurrRoutePoint = -1;

	Vector3f cr1 = crGetPoint(mCurrRoutePoint + 1);
	Vector3f cr2 = crGetPoint(mCurrRoutePoint + 2);

	Tube tube(cr1, cr2, crGetRadius(mCurrRoutePoint + 1), crGetRadius(mCurrRoutePoint + 2));
	f32 collDepth;
	Vector3f pushVec;
	Sphere sphere(mPosition, 0.0f);
	if (tube.collide(sphere, pushVec, collDepth) && crPointOpen(mCurrRoutePoint + 2)) {
		mCurrRoutePoint      = 0;
		mSplineControlPts[0] = crGetPoint(-1);
		mSplineControlPts[1] = crGetPoint(-1);
		mSplineControlPts[2] = crGetPoint(1);
		mSplineControlPts[3] = crGetPoint(2);
	} else {
		crMakeRefs();
	}

	return true;
}

/*
 * --INFO--
 * Address:	800C74E8
 * Size:	000700
 */
int Piki::moveRouteTrace(f32 speedRatio)
{
	if (AIPerf::useASync && mUseAsyncPathfinding) {
		if (mRouteHandle) {
			int numPts = routeMgr->getPathFinder('test')->checkASync(mRouteHandle);
			if (numPts == -2) {
				return 1;
			} else if (numPts == -1) {
				return 2;
			} else if (numPts == -3) {
				ERROR("damedayo-\n");
			}

			PRINT("ROUTE WAS FOUND ! %d points\n", numPts);
			mNumRoutePoints = numPts;
			mCurrRoutePoint = -1;

			Vector3f cr1 = crGetPoint(mCurrRoutePoint + 1);
			Vector3f cr2 = crGetPoint(mCurrRoutePoint + 2);

			Tube tube(cr1, cr2, crGetRadius(mCurrRoutePoint + 1), crGetRadius(mCurrRoutePoint + 2));
			f32 collDepth;
			Vector3f pushVec;
			Sphere sphere(mPosition, 0.0f);
			if (tube.collide(sphere, pushVec, collDepth) && crPointOpen(mCurrRoutePoint + 2)) {
				mCurrRoutePoint      = 0;
				mSplineControlPts[0] = crGetPoint(-1);
				mSplineControlPts[1] = crGetPoint(-1);
				mSplineControlPts[2] = crGetPoint(1);
				mSplineControlPts[3] = crGetPoint(2);
			} else {
				crMakeRefs();
			}

			routeMgr->getPathFinder('test')->releaseHandle(mRouteHandle);
			mRouteHandle         = 0;
			mUseAsyncPathfinding = false;

		} else {
			PRINT("waiting for handle\n");
			PRINT("wait for r-handle");
			mRouteHandle = routeMgr->getPathFinder('test')->findASync(mPathBuffers, mRouteSourceIndex, mRouteDestinationIndex, false);
			return 2;
		}
	}

	Vector3f moveDir(0.0f, 0.0f, 0.0f);

	// find the nearest point on the desired path
	Vector3f cr0   = crGetPoint(mCurrRoutePoint);
	Vector3f cr1   = crGetPoint(mCurrRoutePoint + 1);
	Vector3f crDir = cr1 - cr0;
	f32 crDist     = crDir.normalise();

	f32 ctrlRatio = crDir.DP(mPosition - cr0) / crDist;
	if (ctrlRatio < 0.0f) {
		ctrlRatio = 0.0f;
	}
	if (ctrlRatio > 1.0f) {
		ctrlRatio = 1.0f;
	}

	Vector3f dirToPath;
	dirToPath      = (ctrlRatio * crDist) * crDir + cr0;
	dirToPath      = dirToPath - mPosition;
	dirToPath.y    = 0.0f;
	f32 distToPath = dirToPath.normalise();

	f32 ctrlPtsWeight     = (1.0f - ctrlRatio) * crGetRadius(mCurrRoutePoint) + ctrlRatio * crGetRadius(mCurrRoutePoint + 1);
	f32 alignToPathWeight = zen::Abs(distToPath) / ctrlPtsWeight;
	if (alignToPathWeight > 1.0f) {
		alignToPathWeight = 1.0f;
	} else if (alignToPathWeight < 0.0f) {
		alignToPathWeight = 0.0f;
	}

	if (ctrlRatio >= 1.0f) {
		// we are completely aligned with the path
		// (or further along it)
		if (mCurrRoutePoint >= mNumRoutePoints - 2) {
			// we're basically at the end of the route
			return 0;
		}

		// keep going
		mCurrRoutePoint++;
		ctrlRatio = 0.0f;
		crMakeRefs();
		moveDir = CRSplineTangent(ctrlRatio, mSplineControlPts);
		moveDir.normalise();
		setSpeed(speedRatio, moveDir);
		return 2;
	}

	moveDir = CRSplineTangent(ctrlRatio, mSplineControlPts);
	moveDir.normalise();

	// make a smooth movement back to the path
	moveDir = (1.0f - alignToPathWeight) * moveDir + alignToPathWeight * dirToPath;

	// we're going backwards, abandon the smooth movement
	if (moveDir.DP(crDir) <= 0.0f) {
		moveDir = crDir;
	}
	setSpeed(speedRatio, moveDir);
	return 2;
}

/*
 * --INFO--
 * Address:	800C7BE8
 * Size:	0000B8
 */
Vector3f Piki::crGetPoint(int routePointIdx)
{
	if (routePointIdx < 0) {
		return mRouteStartPos;
	}

	if (routePointIdx >= mNumRoutePoints) {
		return mRouteGoalPos;
	}

	WayPoint* wp = routeMgr->getWayPoint('test', mPathBuffers[routePointIdx].mWayPointIdx);
	if (!wp) {
		PRINT("routePoints=%d idx=%d no waypoint (wp.idx=%d)\n", mNumRoutePoints, routePointIdx, mPathBuffers[routePointIdx].mWayPointIdx);
		ERROR("gakkusi");
	}

	return wp->mPosition;
}

/*
 * --INFO--
 * Address:	800C7CA0
 * Size:	000068
 */
bool Piki::crPointOpen(int routePointIdx)
{
	if (routePointIdx < 0 || routePointIdx >= mNumRoutePoints) {
		return true;
	}

	WayPoint* wp = routeMgr->getWayPoint('test', mPathBuffers[routePointIdx].mWayPointIdx);
	if (!wp) {
		PRINT("routePoints=%d idx=%d no waypoint (wp.idx=%d)\n", mNumRoutePoints, routePointIdx, mPathBuffers[routePointIdx].mWayPointIdx);
		ERROR("gakkusi");
	}

	return wp->mIsOpen;
}

/*
 * --INFO--
 * Address:	800C7D08
 * Size:	000060
 */
f32 Piki::crGetRadius(int routePointIdx)
{
	if (routePointIdx < 0) {
		return 20.0f;
	}

	if (routePointIdx >= mNumRoutePoints) {
		return 50.0f;
	}

	return routeMgr->getWayPoint('test', mPathBuffers[routePointIdx].mWayPointIdx)->mRadius;
}

/*
 * --INFO--
 * Address:	800C7D68
 * Size:	000108
 */
void Piki::crMakeRefs()
{
	for (int i = 0; i < 4; i++) {
		mSplineControlPts[i] = crGetPoint(mCurrRoutePoint + i - 1);
	}
}

/*
 * --INFO--
 * Address:	800C7E70
 * Size:	00001C
 */
bool Piki::hasBomb()
{
	return isHolding();
}

/*
 * --INFO--
 * Address:	800C7E8C
 * Size:	000090
 */
void Piki::startFire()
{
	mFiredState = 1;
	seSystem->playPikiSound(SEF_PIKI_FIRED, mPosition);
	EffectParm parm(&mEffectPos);
	mBurnEffect->emit(parm);
	mIsPanicked = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void Piki::updateFire()
{
	if (mFiredState) {
		int state = getState();
		if (mFiredState != 2 && state != PIKISTATE_Dying && state != PIKISTATE_Dead && state != PIKISTATE_Fired && state != PIKISTATE_Drown
		    && mColor != Red) {
			changeMode(PikiMode::FreeMode, mNavi);
			mFSM->transit(this, PIKISTATE_Fired);
		}
	}
}

/*
 * --INFO--
 * Address:	800C7F1C
 * Size:	000064
 */
void Piki::endFire()
{
	mBurnEffect->kill();
	mIsPanicked = false;
	mFiredState = 2;
	effectMgr->create(EffectMgr::EFF_Piki_FireRecover, mEffectPos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	800C7F80
 * Size:	00013C
 */
bool Piki::isTeki(Piki* target)
{
	int targetState = target->getState();
	if (target->isKinoko() && targetState != PIKISTATE_KinokoChange && targetState != PIKISTATE_Flick && target->getStickObject() == nullptr
	    && !isKinoko()) {
		return true;
	}

	int state = getState();
	if (!target->isKinoko() && isKinoko() && getStickObject() == nullptr && state != PIKISTATE_KinokoChange && state != PIKISTATE_Flick) {
		return true;
	}

	if (flowCont.mNaviOnMap == 1) {
		return target->mNavi != mNavi;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800C80BC
 * Size:	000404
 */
void Piki::actOnSituaton()
{
	if (playerState->inDayEnd()) {
		PRINT("IN DAYEND RETURN!\n");
		return;
	}

	PikiState* currState = static_cast<PikiState*>(getCurrState());
	if (currState && !currState->freeAI()) {
		return;
	}
	Creature* target = nullptr;

	switch (graspSituation(&target)) {
	case PIKISITCH_Unk1:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Attack;
		mActiveAction->mChildActions[PikiAction::Attack].initialise(target);
		mMode = PikiMode::AttackMode;
		break;

	case PIKISITCH_Unk2:
		ERROR("U CAN'T DO IT RIGHT !\n"); // LOL
		break;

	case PIKISITCH_Unk14:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Bou;
		mActiveAction->mChildActions[PikiAction::Bou].initialise(target);
		mMode = PikiMode::BoMode;
		break;

	case PIKISITCH_Unk9:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Transport;
		mActiveAction->mChildActions[PikiAction::Transport].initialise(target);
		mMode = PikiMode::TransportMode;
		break;

	case PIKISITCH_Unk10:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Rescue;
		mActiveAction->mChildActions[PikiAction::Rescue].initialise(target);
		mMode = PikiMode::RescueMode;
		break;

	case PIKISITCH_Unk11:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Weed;
		mActiveAction->mChildActions[PikiAction::Weed].initialise(target);
		mMode = PikiMode::WeedMode;
		break;

	case PIKISITCH_Unk13:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::BoMake;
		mActiveAction->mChildActions[PikiAction::BoMake].initialise(target);
		mMode = PikiMode::BomakeMode;
		break;

	case PIKISITCH_Unk12:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Stone;
		mActiveAction->mChildActions[PikiAction::Stone].initialise(target);
		mMode = PikiMode::PebbleMode;
		break;

	case PIKISITCH_Unk4:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Mine;
		mActiveAction->mChildActions[PikiAction::Mine].initialise(target);
		mMode = PikiMode::MineMode;
		break;

	case PIKISITCH_Unk3:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::PickItem;
		mActiveAction->mChildActions[PikiAction::PickItem].initialise(target);
		mMode = PikiMode::PickMode;
		break;

	case PIKISITCH_Unk7:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Bridge;
		mActiveAction->mChildActions[PikiAction::Bridge].initialise(target);
		mMode = PikiMode::BridgeMode;
		break;

	case PIKISITCH_Unk8:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Push;
		mActiveAction->mChildActions[PikiAction::Push].initialise(target);
		mMode = PikiMode::PushstoneMode;
		break;

	case PIKISITCH_Unk6:
		seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::BreakWall;
		mActiveAction->mChildActions[PikiAction::BreakWall].initialise(target);
		mMode = PikiMode::BreakwallMode;
		break;

	default:
		changeMode(PikiMode::FreeMode, mNavi);
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
int Piki::getNaviID()
{
	if (mNavi) {
		return mNavi->mNaviID;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800C84C8
 * Size:	00004C
 */
bool Piki::doDoAI()
{
	switch (getState()) {
	case PIKISTATE_Normal:
	case PIKISTATE_Flying:
	case PIKISTATE_Wave:
	case PIKISTATE_Push:
	case PIKISTATE_PushPiki:
		return true;

	default:
		return false;
	}
}

/*
 * --INFO--
 * Address:	800C8514
 * Size:	000024
 */
bool Piki::isRopable()
{
	if (mMode != PikiMode::EnterMode && mMode != PikiMode::ExitMode) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800C8538
 * Size:	00001C
 */
Vector3f Piki::getCatchPos(Creature*)
{
	return mCatchPos;
}

/*
 * --INFO--
 * Address:	800C8554
 * Size:	00000C
 */
int Piki::getState()
{
	return mCurrentState->getID();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
int Piki::getLastState()
{
	return mFSM->getLastStateID();
}

/*
 * --INFO--
 * Address:	800C8560
 * Size:	000018
 */
bool Piki::isBuried()
{
	return getState() == PIKISTATE_Bury;
}

/*
 * --INFO--
 * Address:	800C8578
 * Size:	001300
 */
int Piki::graspSituation(Creature** outTarget)
{
	if (!tekiMgr) {
		return PIKISITCH_Unk0;
	}

	if (!bossMgr) {
		return PIKISITCH_Unk0;
	}

	if (isHolding()) {
		return PIKISITCH_Unk0;
	}

	if (getState() == PIKISTATE_Emotion) {
		// cannot expect a piki to be emotional AND handle situations
		// honestly same
		PRINT("EMOTION STATE : GRASP SITUATION\n");
		ERROR("mail to kando");
	}

	if (playerState->inDayEnd()) {
		return PIKISITCH_Unk0;
	}

	f32 minDist = 12800.0f;
	int sitchID = PIKISITCH_Unk0;

	////////// CHECK FOR TEKI OR BOSS TO ATTACK //////////
	f32 minTestDist = pikiMgr->mPikiParms->mPikiParms._2FC();

	Iterator iterTeki(tekiMgr);
	Creature* closestTarget = nullptr;
	CI_LOOP(iterTeki)
	{
		Creature* teki = *iterTeki;
		if (roughCull(teki, this, minTestDist + teki->getCentreSize())) {
			continue;
		}
		if (teki->isVisible() && teki->isAlive() && !teki->isFlying() && teki->isOrganic() && !teki->isStickTo()) {
			f32 tekiDist = qdist2(this, teki);
			if (tekiDist <= minTestDist + teki->getCentreSize()) {
				minTestDist   = tekiDist;
				closestTarget = teki;
			}
		}
	}

	Iterator iterBoss(bossMgr);
	CI_LOOP(iterBoss)
	{
		Creature* boss = *iterBoss;
		if (roughCull(boss, this, minTestDist)) {
			continue;
		}
		if (boss->isVisible() && boss->isAlive() && !boss->isFlying() && boss->isOrganic()) {
			f32 bossDist = qdist2(this, boss);
			if (bossDist <= minTestDist + boss->getCentreSize()) {
				minTestDist   = bossDist;
				closestTarget = boss;
			}
		}
	}

	if (closestTarget && 12800.0f > minTestDist) {
		minDist    = minTestDist;
		*outTarget = closestTarget;
		sitchID    = PIKISITCH_Unk1;
	}

	////////// CHECK FOR PUFFMIN/DROWNING PIKI TO FIGHT/RESCUE //////////
	if (mNavi) {
		minTestDist            = 100.0f;
		Creature* kinokoTarget = nullptr;
		Creature* rescueTarget = nullptr;
		Iterator iterPiki(pikiMgr);
		CI_LOOP(iterPiki)
		{
			Piki* piki = static_cast<Piki*>(*iterPiki);
			if (roughCull(piki, this, minTestDist)) {
				continue;
			}
			if (mColor == Blue && piki->getState() == PIKISTATE_Drown) {
				f32 pikiDist = qdist2(this, piki);
				if (pikiDist <= minTestDist + piki->getCentreSize()) {
					minTestDist  = pikiDist;
					rescueTarget = piki;
					continue;
				}
			}

			if (piki->isTeki(this) && !piki->isBuried() && piki->isVisible() && piki->isAlive() && !piki->isFlying()) {
				f32 pikiDist = qdist2(this, piki);
				if (pikiDist <= minTestDist + piki->getCentreSize()) {
					minTestDist  = pikiDist;
					kinokoTarget = piki;
				}
			}
		}

		if (rescueTarget) {
			if (minTestDist < minDist) {
				minDist    = minTestDist;
				*outTarget = rescueTarget;
				sitchID    = PIKISITCH_Unk10;
			}
		} else if (kinokoTarget) {
			if (minTestDist < minDist) {
				minDist    = minTestDist;
				*outTarget = kinokoTarget;
				sitchID    = PIKISITCH_Unk1;
			}
		}
	}

	////////// CHECK FOR MAP OBJECTS (WALLS, GRASS, ROCKS, STICKS) //////////
	Creature* wallTarget   = nullptr;
	Creature* grassTarget  = nullptr;
	Creature* pebbleTarget = nullptr;
	Creature* boTarget     = nullptr;
	Creature* kusaTarget   = nullptr;
	minTestDist            = pikiMgr->mPikiParms->mPikiParms._30C();
	Iterator iterMP(itemMgr->getMeltingPotMgr());
	CI_LOOP(iterMP)
	{
		Creature* obj = *iterMP;
		if (obj->isSluice() && obj->isAlive()) {
			CollPart* flagPart = obj->mCollInfo->getSphere('flag');
			if (flagPart) {
				if (roughCull(obj, this, flagPart->mRadius + getCentreSize())) {
					continue;
				}

				// we have 5 seconds to solve this or we error.
				LoopChecker checker("sit:sluice", 5.0f);
				u32 badCompiler;
				for (int i = 0; i < flagPart->getChildCount(); i++) {
					checker.update();
					CollPart* childPart = flagPart->getChildAt(i);
					Vector3f partDir    = childPart->mCentre - mPosition;
					f32 objDist         = partDir.length() - childPart->mRadius - getCentreSize();
					if (objDist <= minTestDist) {
						minTestDist = objDist;
						wallTarget  = obj;
					}
				}
			}
		} else if (obj->mObjType == OBJTYPE_GrassGen && obj->isAlive()) {
			f32 objDist = centreDist(this, obj);
			if (objDist <= minTestDist + obj->getCentreSize() && static_cast<GrassGen*>(obj)->workable()) {
				minTestDist = objDist;
				grassTarget = obj;
			}

		} else if (obj->mObjType == OBJTYPE_RockGen && obj->isAlive()) {
			f32 objDist = centreDist(this, obj);
			if (objDist <= minTestDist + obj->getCentreSize() && static_cast<RockGen*>(obj)->workable()) {
				minTestDist  = objDist;
				pebbleTarget = obj;
			}

		} else if (obj->mObjType == OBJTYPE_BoBase && obj->isAlive()) {
			f32 objDist = centreDist(this, obj);
			if (objDist <= minTestDist + obj->getCentreSize()) {
				minTestDist = objDist;
				boTarget    = obj;
			}

		} else if (obj->mObjType == OBJTYPE_Kusa && obj->mHealth >= obj->mMaxHealth) {
			f32 objDist = centreDist(this, obj);
			if (objDist <= minTestDist + obj->getCentreSize()) {
				minTestDist = objDist;
				kusaTarget  = obj;
			}
		}
	}

	// test wall now, test weeds + bo + kusa later
	if (wallTarget && minTestDist < minDist) {
		minDist    = minTestDist;
		*outTarget = wallTarget;
		sitchID    = PIKISITCH_Unk6;
	}

	////////// CHECK FOR PELLETS TO PICK UP //////////
	Creature* pelletTarget = nullptr;
	minTestDist            = pikiMgr->mPikiParms->mPikiParms._30C();
	Iterator iterPellet(pelletMgr);
	CI_LOOP(iterPellet)
	{
		Creature* c    = *iterPellet;
		Pellet* pellet = static_cast<Pellet*>(c);
		if (pellet->isAlive() && pellet->getMinFreeSlotIndex() != -1) {
			if (roughCull(c, this, getCentreSize() + minTestDist + c->getCentreSize())) {
				continue;
			}
			if (c) {
				f32 pelDist = centreDist(this, c);
				if (pelDist <= c->getCentreSize() + minTestDist + getCentreSize()) {
					minTestDist  = pelDist;
					pelletTarget = c;
				}
			}
		}
	}

	if (pelletTarget && minTestDist < minDist) {
		minDist    = minTestDist;
		*outTarget = pelletTarget;
		sitchID    = PIKISITCH_Unk9;
	}

	////////// CHECK FOR THINGS WE CAN GRAB (GRASS(?), BOMBS) //////////
	Creature* removedTarget = nullptr; // this should be here according to the DLL
	Creature* bombTarget    = nullptr;

	minTestDist = pikiMgr->mPikiParms->mPikiParms._30C();
	Iterator iterItem(itemMgr);
	CI_LOOP(iterItem)
	{
		Creature* item = *iterItem;
		if (roughCull(item, this, minTestDist)) {
			continue;
		}

		if (item->isVisible() && item->isAlive() && !item->isGrabbed()) {
			if (item->mObjType == OBJTYPE_GrassGen) {
				f32 grassDist = centreDist(this, item);
				if (grassDist <= item->getCentreSize() + minTestDist) {
					minTestDist = grassDist;
					grassTarget = item;
				}

			} else if (item->mObjType == OBJTYPE_Bomb && mColor == Yellow && item->isVisible()) {
				f32 bombDist = centreDist(this, item);
				if (bombDist <= item->getCentreSize() + minTestDist) {
					minTestDist = bombDist;
					bombTarget  = item;
				}
			}
		}
	}

	// do all the built-up checking so far
	if (removedTarget) {
		if (minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = removedTarget;
			sitchID    = PIKISITCH_Unk2; // unimplemented/commented out
		}
	} else if (bombTarget) {
		if (minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = bombTarget;
			sitchID    = PIKISITCH_Unk3;
		}
	} else if (grassTarget) {
		if (minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = grassTarget;
			sitchID    = PIKISITCH_Unk11;
		}
	} else if (pebbleTarget) {
		if (minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = pebbleTarget;
			sitchID    = PIKISITCH_Unk12;
		}
	} else if (boTarget) {
		if (minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = boTarget;
			sitchID    = PIKISITCH_Unk13;
		}
	} else if (kusaTarget) {
		if (minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = kusaTarget;
			sitchID    = PIKISITCH_Unk14;
		}
	}

	////////// CHECK FOR THINGS TO WORK ON //////////
	Creature* workTarget = nullptr;
	minTestDist          = pikiMgr->mPikiParms->mPikiParms._2FC();

	Iterator iterWork(workObjectMgr);
	CI_LOOP(iterWork)
	{
		WorkObject* workObj = static_cast<WorkObject*>(*iterWork);
		f32 workDist        = sphereDist(workObj, this);
		workObj->isBridge(); // id overlook removing this in a big-ass function like this too, kando
		f32 test = minTestDist;
		if (workObj->isBridge()) {
			test = minTestDist * 7.0f;
		}
		if (workDist < test && !workObj->isFinished() && workObj->workable(mPosition)) {
			minTestDist = workDist;
			workTarget  = workObj;
		}
	}

	if (workTarget) {
		WorkObject* workObj = static_cast<WorkObject*>(workTarget);
		if (workObj->workable(mPosition)) {
			if (workObj->isBridge()) {
				if (minTestDist < minDist) {
					minDist    = minTestDist;
					*outTarget = workTarget;
					sitchID    = PIKISITCH_Unk7;
				}
			} else if (workObj->isHinderRock()) {
				if (minTestDist < minDist) {
					minDist    = minTestDist;
					*outTarget = workTarget;
					sitchID    = PIKISITCH_Unk8;
				}
			}
		}
	}

	////////// CHECK FOR BOMB GENERATORS (YELLOW ONLY) //////////
	if (mColor == Yellow) {
		Creature* bombGenTarget = nullptr;
		minTestDist             = pikiMgr->mPikiParms->mPikiParms._2FC();
		Iterator iterBomb(itemMgr);
		CI_LOOP(iterBomb)
		{
			Creature* bombGen = *iterBomb;
			if (bombGen->mObjType != OBJTYPE_BombGen) {
				continue;
			}

			f32 bombDist = sphereDist(bombGen, this);
			if (bombDist < minTestDist) {
				minTestDist = bombDist;
				if (static_cast<BombGenItem*>(bombGen)->pickable()) {
					bombGenTarget = bombGen;
				}
			}
		}

		if (bombGenTarget && !bombTarget && minTestDist < minDist) {
			minDist    = minTestDist;
			*outTarget = bombGenTarget;
			sitchID    = PIKISITCH_Unk4;
		}
	}

	return sitchID;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x208(r1)
	  stfd      f31, 0x200(r1)
	  stfd      f30, 0x1F8(r1)
	  stfd      f29, 0x1F0(r1)
	  stfd      f28, 0x1E8(r1)
	  stfd      f27, 0x1E0(r1)
	  stfd      f26, 0x1D8(r1)
	  stmw      r16, 0x198(r1)
	  addi      r31, r3, 0
	  addi      r29, r4, 0
	  lwz       r20, 0x3160(r13)
	  cmplwi    r20, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x44:
	  lwz       r0, 0x3168(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x58:
	  lwz       r0, 0x2AC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x6C:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x84:
	  lwz       r4, 0x3068(r13)
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  li        r24, 0
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  li        r21, 0
	  lfs       f31, -0x6A14(r2)
	  lfs       f26, 0x308(r4)
	  mtlr      r12
	  blrl
	  mr        r19, r3
	  b         .loc_0x1EC

	.loc_0xB8:
	  cmpwi     r19, -0x1
	  bne-      .loc_0xE0
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xFC

	.loc_0xE0:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xFC:
	  lwz       r12, 0x0(r18)
	  mr        r3, r18
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f26, f1
	  addi      r3, r18, 0
	  addi      r4, r31, 0
	  bl        -0x3AE04
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1D0
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  lwz       r0, 0xC8(r18)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x1D0
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  lwz       r0, 0x184(r18)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D0
	  addi      r3, r31, 0
	  addi      r4, r18, 0
	  bl        -0x3B898
	  lwz       r12, 0x0(r18)
	  fmr       f27, f1
	  mr        r3, r18
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1D0
	  fmr       f26, f27
	  mr        r21, r18

	.loc_0x1D0:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r19, r3

	.loc_0x1EC:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x214
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x214:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x23C:
	  li        r0, 0

	.loc_0x240:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB8
	  lwz       r19, 0x3168(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  b         .loc_0x37C

	.loc_0x268:
	  cmpwi     r20, -0x1
	  bne-      .loc_0x290
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0x2AC

	.loc_0x290:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x2AC:
	  fmr       f1, f26
	  addi      r3, r18, 0
	  addi      r4, r31, 0
	  bl        -0x3AFA0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x360
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  lwz       r0, 0xC8(r18)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x360
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  addi      r3, r31, 0
	  addi      r4, r18, 0
	  bl        -0x3BA28
	  lwz       r12, 0x0(r18)
	  fmr       f27, f1
	  mr        r3, r18
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x360
	  fmr       f26, f27
	  mr        r21, r18

	.loc_0x360:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0x37C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3A4
	  li        r0, 0x1
	  b         .loc_0x3D0

	.loc_0x3A4:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3CC
	  li        r0, 0x1
	  b         .loc_0x3D0

	.loc_0x3CC:
	  li        r0, 0

	.loc_0x3D0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x268
	  cmplwi    r21, 0
	  beq-      .loc_0x3F8
	  lfs       f0, -0x6A14(r2)
	  fcmpo     cr0, f0, f26
	  ble-      .loc_0x3F8
	  fmr       f31, f26
	  stw       r21, 0x0(r29)
	  li        r24, 0x1

	.loc_0x3F8:
	  lwz       r0, 0x504(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x644
	  lwz       r19, 0x3068(r13)
	  li        r21, 0
	  lfs       f26, -0x6A10(r2)
	  li        r22, 0
	  addi      r3, r19, 0
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  b         .loc_0x5AC

	.loc_0x430:
	  cmpwi     r20, -0x1
	  bne-      .loc_0x454
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x46C

	.loc_0x454:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x46C:
	  fmr       f1, f26
	  addi      r23, r3, 0
	  addi      r4, r31, 0
	  bl        -0x3B160
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x590
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x4E0
	  lwz       r3, 0x52C(r23)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x18
	  bne-      .loc_0x4E0
	  addi      r3, r31, 0
	  addi      r4, r23, 0
	  bl        -0x3BBA4
	  lwz       r12, 0x0(r23)
	  fmr       f27, f1
	  mr        r3, r23
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4E0
	  fmr       f26, f27
	  mr        r22, r23
	  b         .loc_0x590

	.loc_0x4E0:
	  addi      r3, r23, 0
	  addi      r4, r31, 0
	  bl        -0xAE0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x590
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  lwz       r0, 0xC8(r23)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x590
	  addi      r3, r31, 0
	  addi      r4, r23, 0
	  bl        -0x3BC58
	  lwz       r12, 0x0(r23)
	  fmr       f27, f1
	  mr        r3, r23
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x590
	  fmr       f26, f27
	  mr        r21, r23

	.loc_0x590:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0x5AC:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5D4
	  li        r0, 0x1
	  b         .loc_0x600

	.loc_0x5D4:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x5FC
	  li        r0, 0x1
	  b         .loc_0x600

	.loc_0x5FC:
	  li        r0, 0

	.loc_0x600:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x430
	  cmplwi    r22, 0
	  beq-      .loc_0x628
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0x644
	  fmr       f31, f26
	  stw       r22, 0x0(r29)
	  li        r24, 0xA
	  b         .loc_0x644

	.loc_0x628:
	  cmplwi    r21, 0
	  beq-      .loc_0x644
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0x644
	  fmr       f31, f26
	  stw       r21, 0x0(r29)
	  li        r24, 0x1

	.loc_0x644:
	  lwz       r3, 0x30AC(r13)
	  li        r23, 0
	  lwz       r4, 0x3068(r13)
	  li        r30, 0
	  lwz       r27, 0x68(r3)
	  lwz       r4, 0x68(r4)
	  li        r25, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  li        r26, 0
	  lfs       f26, 0x318(r4)
	  li        r28, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x802C
	  lfs       f28, -0x6A48(r2)
	  lfd       f29, -0x6A40(r2)
	  addi      r20, r3, 0
	  lfd       f30, -0x6A38(r2)
	  subi      r22, r4, 0x7B38
	  lis       r21, 0x666C
	  b         .loc_0xA74

	.loc_0x6A0:
	  cmpwi     r20, -0x1
	  bne-      .loc_0x6C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r19, r3
	  b         .loc_0x6E4

	.loc_0x6C8:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r19, r3

	.loc_0x6E4:
	  lwz       r5, 0x6C(r19)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0x708
	  cmpwi     r5, 0x17
	  beq-      .loc_0x708
	  li        r0, 0

	.loc_0x708:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x71C
	  cmpwi     r5, 0x18
	  beq-      .loc_0x71C
	  li        r4, 0

	.loc_0x71C:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x730
	  cmpwi     r5, 0x19
	  beq-      .loc_0x730
	  li        r3, 0

	.loc_0x730:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A4
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A4
	  lwz       r3, 0x220(r19)
	  addi      r4, r21, 0x6167
	  bl        -0x3F5C4
	  mr.       r17, r3
	  beq-      .loc_0xA58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r17)
	  addi      r3, r19, 0
	  addi      r4, r31, 0
	  fadds     f1, f0, f1
	  bl        -0x3B474
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA58
	  lfs       f1, -0x6A0C(r2)
	  addi      r4, r22, 0
	  addi      r3, r1, 0x160
	  bl        0x4D6D0
	  li        r16, 0
	  b         .loc_0x890

	.loc_0x7B0:
	  addi      r3, r1, 0x160
	  bl        0x4D6CC
	  addi      r3, r17, 0
	  addi      r4, r16, 0
	  bl        -0x40F4C
	  lfs       f2, 0x98(r31)
	  mr        r18, r3
	  lfs       f3, 0x8(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f27, f2, f0
	  fcmpo     cr0, f27, f28
	  ble-      .loc_0x858
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f27, 0xB4(r1)

	.loc_0x858:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r18)
	  fsubs     f0, f27, f0
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f26
	  cror      2, 0, 0x2
	  bne-      .loc_0x88C
	  fmr       f26, f0
	  mr        r23, r19

	.loc_0x88C:
	  addi      r16, r16, 0x1

	.loc_0x890:
	  mr        r3, r17
	  bl        -0x4107C
	  cmpw      r16, r3
	  blt+      .loc_0x7B0
	  b         .loc_0xA58

	.loc_0x8A4:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x22
	  bne-      .loc_0x91C
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x91C
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D41C
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  mr        r3, r19
	  bl        0x1B850
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA58
	  fmr       f26, f27
	  mr        r30, r19
	  b         .loc_0xA58

	.loc_0x91C:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x21
	  bne-      .loc_0x994
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x994
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D494
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  mr        r3, r19
	  bl        0x1B788
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA58
	  fmr       f26, f27
	  mr        r25, r19
	  b         .loc_0xA58

	.loc_0x994:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x23
	  bne-      .loc_0x9FC
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9FC
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D50C
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  fmr       f26, f27
	  mr        r26, r19
	  b         .loc_0xA58

	.loc_0x9FC:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0xA58
	  lfs       f1, 0x58(r19)
	  lfs       f0, 0x5C(r19)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xA58
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D56C
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  fmr       f26, f27
	  mr        r28, r19

	.loc_0xA58:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0xA74:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA9C
	  li        r0, 0x1
	  b         .loc_0xAC8

	.loc_0xA9C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xAC4
	  li        r0, 0x1
	  b         .loc_0xAC8

	.loc_0xAC4:
	  li        r0, 0

	.loc_0xAC8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6A0
	  cmplwi    r23, 0
	  beq-      .loc_0xAEC
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xAEC
	  fmr       f31, f26
	  stw       r23, 0x0(r29)
	  li        r24, 0x6

	.loc_0xAEC:
	  lwz       r19, 0x301C(r13)
	  li        r20, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f27, 0x318(r4)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0xC58

	.loc_0xB1C:
	  cmpwi     r21, -0x1
	  bne-      .loc_0xB44
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xB60

	.loc_0xB44:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xB60:
	  addi      r17, r18, 0
	  addi      r3, r17, 0
	  lwz       r12, 0x0(r17)
	  mr        r16, r18
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC3C
	  mr        r3, r17
	  bl        -0x32DA0
	  cmpwi     r3, -0x1
	  beq-      .loc_0xC3C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  fmr       f26, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f27, f1
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  fadds     f1, f0, f26
	  bl        -0x3B8B8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC3C
	  cmplwi    r18, 0
	  beq-      .loc_0xC3C
	  addi      r3, r31, 0
	  addi      r4, r16, 0
	  bl        -0x3D734
	  lwz       r12, 0x0(r31)
	  fmr       f28, f1
	  mr        r3, r31
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r16
	  fmr       f26, f1
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f27, f1
	  fadds     f0, f0, f26
	  fcmpo     cr0, f28, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xC3C
	  fmr       f27, f28
	  mr        r20, r18

	.loc_0xC3C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3

	.loc_0xC58:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC80
	  li        r0, 0x1
	  b         .loc_0xCAC

	.loc_0xC80:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xCA8
	  li        r0, 0x1
	  b         .loc_0xCAC

	.loc_0xCA8:
	  li        r0, 0

	.loc_0xCAC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB1C
	  cmplwi    r20, 0
	  beq-      .loc_0xCD0
	  fcmpo     cr0, f27, f31
	  bge-      .loc_0xCD0
	  fmr       f31, f27
	  stw       r20, 0x0(r29)
	  li        r24, 0x9

	.loc_0xCD0:
	  lwz       r19, 0x30AC(r13)
	  li        r27, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f26, 0x318(r4)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  b         .loc_0xE78

	.loc_0xD00:
	  cmpwi     r20, -0x1
	  bne-      .loc_0xD28
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xD44

	.loc_0xD28:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xD44:
	  fmr       f1, f26
	  addi      r16, r18, 0
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  bl        -0x3BA3C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xE5C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE5C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE5C
	  lwz       r0, 0x2A8(r18)
	  cmplwi    r0, 0
	  bne-      .loc_0xE5C
	  lwz       r0, 0x6C(r18)
	  cmpwi     r0, 0x22
	  bne-      .loc_0xDF0
	  addi      r3, r31, 0
	  addi      r4, r16, 0
	  bl        -0x3D900
	  lwz       r12, 0x0(r16)
	  fmr       f27, f1
	  mr        r3, r16
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE5C
	  fmr       f26, f27
	  mr        r30, r18
	  b         .loc_0xE5C

	.loc_0xDF0:
	  cmpwi     r0, 0xE
	  bne-      .loc_0xE5C
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0xE5C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE5C
	  addi      r3, r31, 0
	  addi      r4, r16, 0
	  bl        -0x3D970
	  lwz       r12, 0x0(r16)
	  fmr       f27, f1
	  mr        r3, r16
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE5C
	  fmr       f26, f27
	  mr        r27, r18

	.loc_0xE5C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0xE78:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xEA0
	  li        r0, 0x1
	  b         .loc_0xECC

	.loc_0xEA0:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xEC8
	  li        r0, 0x1
	  b         .loc_0xECC

	.loc_0xEC8:
	  li        r0, 0

	.loc_0xECC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD00
	  cmplwi    r27, 0
	  beq-      .loc_0xEF4
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r27, 0x0(r29)
	  li        r24, 0x3
	  b         .loc_0xF70

	.loc_0xEF4:
	  cmplwi    r30, 0
	  beq-      .loc_0xF14
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r30, 0x0(r29)
	  li        r24, 0xB
	  b         .loc_0xF70

	.loc_0xF14:
	  cmplwi    r25, 0
	  beq-      .loc_0xF34
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r25, 0x0(r29)
	  li        r24, 0xC
	  b         .loc_0xF70

	.loc_0xF34:
	  cmplwi    r26, 0
	  beq-      .loc_0xF54
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r26, 0x0(r29)
	  li        r24, 0xD
	  b         .loc_0xF70

	.loc_0xF54:
	  cmplwi    r28, 0
	  beq-      .loc_0xF70
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r28, 0x0(r29)
	  li        r24, 0xE

	.loc_0xF70:
	  lwz       r19, 0x3020(r13)
	  li        r20, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f27, 0x308(r4)
	  mtlr      r12
	  blrl
	  lfs       f26, -0x6A08(r2)
	  mr        r18, r3
	  b         .loc_0x1090

	.loc_0xFA4:
	  cmpwi     r18, -0x1
	  bne-      .loc_0xFC8
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xFE0

	.loc_0xFC8:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xFE0:
	  addi      r16, r3, 0
	  addi      r4, r31, 0
	  bl        -0x3DA40
	  lwz       r12, 0x0(r16)
	  fmr       f28, f1
	  mr        r3, r16
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r16
	  fmr       f29, f27
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1028
	  fmuls     f29, f26, f27

	.loc_0x1028:
	  fcmpo     cr0, f28, f29
	  bge-      .loc_0x1074
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1074
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  addi      r4, r31, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1074
	  fmr       f27, f28
	  mr        r20, r16

	.loc_0x1074:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x1090:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10B8
	  li        r0, 0x1
	  b         .loc_0x10E4

	.loc_0x10B8:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x10E0
	  li        r0, 0x1
	  b         .loc_0x10E4

	.loc_0x10E0:
	  li        r0, 0

	.loc_0x10E4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xFA4
	  cmplwi    r20, 0
	  beq-      .loc_0x117C
	  addi      r16, r20, 0
	  addi      r3, r16, 0
	  lwz       r12, 0x0(r16)
	  addi      r4, r31, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x117C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x114C
	  fcmpo     cr0, f27, f31
	  bge-      .loc_0x117C
	  fmr       f31, f27
	  stw       r20, 0x0(r29)
	  li        r24, 0x7
	  b         .loc_0x117C

	.loc_0x114C:
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x160(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x117C
	  fcmpo     cr0, f27, f31
	  bge-      .loc_0x117C
	  fmr       f31, f27
	  stw       r20, 0x0(r29)
	  li        r24, 0x8

	.loc_0x117C:
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x12D0
	  lwz       r20, 0x30AC(r13)
	  li        r19, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f26, 0x308(r4)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0x1254

	.loc_0x11B8:
	  cmpwi     r21, -0x1
	  bne-      .loc_0x11E0
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0x11FC

	.loc_0x11E0:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x11FC:
	  lwz       r0, 0x6C(r18)
	  addi      r16, r18, 0
	  cmpwi     r0, 0xD
	  bne-      .loc_0x1238
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  bl        -0x3DC6C
	  fcmpo     cr0, f1, f26
	  bge-      .loc_0x1238
	  fmr       f26, f1
	  mr        r3, r16
	  bl        0x2E284
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1238
	  mr        r19, r18

	.loc_0x1238:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3

	.loc_0x1254:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x127C
	  li        r0, 0x1
	  b         .loc_0x12A8

	.loc_0x127C:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x12A4
	  li        r0, 0x1
	  b         .loc_0x12A8

	.loc_0x12A4:
	  li        r0, 0

	.loc_0x12A8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x11B8
	  cmplwi    r19, 0
	  beq-      .loc_0x12D0
	  cmplwi    r27, 0
	  bne-      .loc_0x12D0
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0x12D0
	  stw       r19, 0x0(r29)
	  li        r24, 0x4

	.loc_0x12D0:
	  mr        r3, r24

	.loc_0x12D4:
	  lmw       r16, 0x198(r1)
	  lwz       r0, 0x20C(r1)
	  lfd       f31, 0x200(r1)
	  lfd       f30, 0x1F8(r1)
	  lfd       f29, 0x1F0(r1)
	  lfd       f28, 0x1E8(r1)
	  lfd       f27, 0x1E0(r1)
	  lfd       f26, 0x1D8(r1)
	  addi      r1, r1, 0x208
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9878
 * Size:	0000D8
 */
void Piki::initColor(int color)
{
	mColor = color;
	if (flowCont.mNaviOnMap == 1) {
		switch (color) {
		case Blue:
			mPlayerId = 0;
			break;
		case Red:
			mPlayerId = 1;
			break;
		default:
			mPlayerId = -1;
			break;
		}
	} else {
		mPlayerId = 0;
	}

	mCurrentColour = pikiColors[mColor];
	changeShape(mColor);
	mDefaultColour    = mCurrentColour;
	mStartBlendColour = mTargetBlendColour = mCurrentColour;
	mColourBlendRatio                      = 1.0f;
}

/*
 * --INFO--
 * Address:	800C9950
 * Size:	000030
 */
void Piki::startKinoko()
{
	changeShape(PIKI_Kinoko);
}

/*
 * --INFO--
 * Address:	800C9980
 * Size:	000050
 */
void Piki::endKinoko()
{
	mLeaderCreature = nullptr;
	changeShape(mColor);
	setColor(mColor);
}

/*
 * --INFO--
 * Address:	800C99D0
 * Size:	000098
 */
void Piki::setColor(int color)
{
	mColor = color;
	if (isKinoko()) {
		mDefaultColour = kinokoColors[mColor];
	} else {
		mDefaultColour = pikiColors[mColor];
	}

	mStartBlendColour  = mCurrentColour;
	mTargetBlendColour = mDefaultColour;
	mColourBlendRatio  = 0.0f;
}

/*
 * --INFO--
 * Address:	800C9A68
 * Size:	00009C
 */
void Piki::setPastel()
{
	mDefaultColour = pikiColors[mColor];

	Colour pastel = mDefaultColour;
	pastel.r      = (mDefaultColour.r + 160 >= 255) ? 255 : mDefaultColour.r + 160;
	pastel.g      = (mDefaultColour.g + 160 >= 255) ? 255 : mDefaultColour.g + 160;
	pastel.b      = (mDefaultColour.b + 160 >= 255) ? 255 : mDefaultColour.b + 160;

	mTargetBlendColour = pastel;
	mStartBlendColour  = mCurrentColour;
	mColourBlendRatio  = 0.0f;
}

/*
 * --INFO--
 * Address:	800C9B04
 * Size:	000098
 */
void Piki::unsetPastel()
{
	setColor(mColor);
}

/*
 * --INFO--
 * Address:	800C9B9C
 * Size:	0001A8
 */
void Piki::updateColor()
{
	if (mColourBlendRatio >= 1.0f) {
		return;
	}

	mColourBlendRatio += gsys->getFrameTime() / 1.2f;

	if (mColourBlendRatio >= 1.0f) {
		mColourBlendRatio = 1.0f;
	}

	mStartBlendColour.lerpTo(mTargetBlendColour, mColourBlendRatio, mCurrentColour);
}

/*
 * --INFO--
 * Address:	800C9D44
 * Size:	000078
 */
bool Piki::needShadow()
{
	if (mColor == Blue && (gameflow.mDemoFlags & 0x8)) {
		return false;
	}
	if (mColor == Red && (gameflow.mDemoFlags & 0x10)) {
		return false;
	}
	if (mColor == Yellow && (gameflow.mDemoFlags & 0x20)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800C9DBC
 * Size:	000028
 */
bool Piki::isFixed()
{
	if (getState() == PIKISTATE_Push) {
		return !static_cast<PikiPushState*>(getCurrState())->_10;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800C9DE4
 * Size:	000098
 */
void Piki::sendMsg(Msg* msg)
{
	mFSM->procMsg(this, msg);
	if (msg->mMsgType == MSG_Stick && getState() == PIKISTATE_Flick) {
		PRINT("may i stick is %s\n", mayIstick() ? "true" : "false");
	}

	if (!mActiveAction->mIsSuspended) {
		mActiveAction->procMsg(msg);
	}
}

/*
 * --INFO--
 * Address:	800C9EB8
 * Size:	000074
 */
bool Piki::stimulate(Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actPiki(this);
	}

	return false;
}

/*
 * --INFO--
 * Address:	800C9F2C
 * Size:	000074
 */
int Piki::getFormationPri()
{
	switch (mNavi->_80C) {
	case 0:
		return mFormationPriority;

	case 1:
		if (mFormationPriority == 1) {
			return 0;
		} else if (mFormationPriority == 2) {
			return 1;
		}
		return 2;

	case 2:
		return -mFormationPriority;

	default:
		return mFormationPriority;
	}
}

/*
 * --INFO--
 * Address:	800C9FA0
 * Size:	00008C
 */
void Piki::startDamage()
{
	if (getState() == PIKISTATE_Flying) {
		PRINT("FLYING DAMAGED!!!\n");
		for (int i = 0; i < 10; i++) {
			PRINT("\tFLYING DAMAGE ***** **** **** ***\n");
		}
	}

	mActiveAction->resume();
	if (getState() == PIKISTATE_Flick) {
		PRINT("flick & damaged\n");
	}

	setStateDamaged();
	mFSM->resume(this);
}

/*
 * --INFO--
 * Address:	800CA030
 * Size:	0000DC
 */
void Piki::finishDamage()
{
	if (getState() == PIKISTATE_Flick) {
		PRINT("in flick : damage done\n");
	}

	resetStateDamaged();
	mFSM->restart(this);
	if (mIsWhistlePending && isAlive()) {
		changeMode(PikiMode::FormationMode, mNavi);
		endStickObject();
		mIsWhistlePending = false;
		return;
	}

	if (mActiveAction->resumable()) {
		mActiveAction->restart();
	} else {
		PRINT("aiAction->curr = %d is not resumable!\n", mActiveAction->mCurrActionIdx);
		mActiveAction->abandon(nullptr);
	}
}

/*
 * --INFO--
 * Address:	800CA110
 * Size:	0000DC
 */
void Piki::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == 56 && event.mEventType == KEY_PlayEffect) {
		EffectParm parm(mPosition);
		UtEffectMgr::cast(17, parm);
	}

	if (isDamaged() && event.mEventType == KEY_Finished) {
		finishDamage();
		return;
	}

	MsgAnim msg(&event);
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Piki::birthBuried()
{
	mFSM->transit(this, PIKISTATE_Grow);
}

/*
 * --INFO--
 * Address:	800CA1EC
 * Size:	000064
 */
bool Piki::isAtari()
{
	int state = getState();
	if (isGrabbed() || state == PIKISTATE_Absorb || state == PIKISTATE_GrowUp || state == PIKISTATE_Pressed || state == PIKISTATE_Hanged
	    || state == PIKISTATE_WaterHanged || state == PIKISTATE_Swallowed || state == PIKISTATE_Grow || state == PIKISTATE_Bury
	    || state == PIKISTATE_Nukare || state == PIKISTATE_NukareWait || state == PIKISTATE_AutoNuki || state == PIKISTATE_Cliff) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800CA250
 * Size:	0000B8
 */
bool Piki::ignoreAtari(Creature* target)
{
	if (target->mObjType == OBJTYPE_Slime && mColor == Blue) {
		return true;
	}
	if (getStickObject() == target) {
		return true;
	}

	if ((mMode == PikiMode::EnterMode || mMode == PikiMode::ExitMode) && target->isTeki()) {
		return true;
	}

	int state = getState();
	if (state == PIKISTATE_Flying || state == PIKISTATE_Hanged) {
		if (target->mObjType == OBJTYPE_Piki || target->mObjType == OBJTYPE_Navi) {
			return true;
		}
	} else if (target->mObjType == OBJTYPE_Piki) {
		int targState = static_cast<Piki*>(target)->getState();
		if (targState == PIKISTATE_Flying || targState == PIKISTATE_Hanged) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	800CA308
 * Size:	000008
 */
bool Piki::needFlick(Creature*)
{
	return true;
}

/*
 * --INFO--
 * Address:	800CA310
 * Size:	000110
 */
bool Piki::isVisible()
{
	int state = getState();
	if (!isAIActive()) {
		return false;
	}

	return (state != PIKISTATE_Dead && state != PIKISTATE_Dying && state != PIKISTATE_Nukare && state != PIKISTATE_Grow
	        && state != PIKISTATE_UNUSED32 && state != PIKISTATE_GrowUp && state != PIKISTATE_Absorb && state != PIKISTATE_Pressed
	        && state != PIKISTATE_AutoNuki && state != PIKISTATE_NukareWait && state != PIKISTATE_Swallowed);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
bool Piki::isGrowable()
{
	int state = getState();
	return isBuried() && state != PIKISTATE_Absorb && state != PIKISTATE_GrowUp;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
bool Piki::isTamable()
{
	int state = getState();
	return !isDamaged() && state == PIKISTATE_Normal;
}

/*
 * --INFO--
 * Address:	800CA420
 * Size:	0000C4
 */
bool Piki::isThrowable()
{
	if (!isAlive() && isStickTo()) {
		return false;
	}

	int state = getState();
	if (state == PIKISTATE_Bubble || state == PIKISTATE_Fired || state == PIKISTATE_Drown) {
		return false;
	}

	if (state == PIKISTATE_Pressed) {
		return false;
	}

	if (state == PIKISTATE_Kinoko) {
		return false;
	}

	if (isKinoko()) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Piki::growup()
{
	if (getState() == PIKISTATE_Absorb) {
		PRINT("growup : %x\n", this);
		mFSM->transit(this, PIKISTATE_GrowUp);
		return;
	}

	PRINT("transform\n");
	mFSM->transit(this, PIKISTATE_UNUSED32); // ooooo
}

/*
 * --INFO--
 * Address:	800CA4E4
 * Size:	000044
 */
void Piki::offwallCallback(DynCollObject* wall)
{
	_4F0 = 0.0f;
	MsgOffWall msg(wall);
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	800CA528
 * Size:	000058
 */
void Piki::wallCallback(Plane& wallPlane, DynCollObject* wall)
{
	_4E8       = 1;
	mWallPlane = &wallPlane;
	mWallObj   = wall;
	_4EC       = 0.7f;
	MsgWall msg(wallPlane, wall);
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	800CA580
 * Size:	000004
 */
void Piki::jumpCallback()
{
}

/*
 * --INFO--
 * Address:	800CA584
 * Size:	000080
 */
bool Piki::platAttachable()
{
	if (!mWantToStick) {
		return false;
	}

	if (isHolding()) {
		return false;
	}

	if (getState() == PIKISTATE_Flick) {
		return false;
	}

	if (!isAlive()) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800CA604
 * Size:	0000E0
 */
bool Piki::mayIstick()
{
	if (isHolding()) {
		return false;
	}

	int prevState = getLastState();
	int state     = getState();
	if (state == PIKISTATE_LookAt) {
		return false;
	}

	if (state == PIKISTATE_Flick) {
		return false;
	}

	if (!isAlive()) {
		return false;
	}

	if (state == PIKISTATE_Flying || prevState == PIKISTATE_Flying) {
		PRINT("piki might stick!\n");
		return true;
	}

	if (mMode == PikiMode::CarryMode) {
		return true;
	}

	if (mMode == PikiMode::AttackMode) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800CA6E4
 * Size:	000038
 */
void Piki::stickToCallback(Creature*)
{
	MsgStick msg;
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	800CA71C
 * Size:	0002BC
 */
void Piki::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	sendMsg(&msg);

	int attr = ATTR_NULL;
	if (mFloorTri) {
		attr = MapCode::getAttribute(mFloorTri);
	}

	int state = getState();
	if (state == PIKISTATE_Dying || state == PIKISTATE_Dead) {
		return;
	}

	bool isDrownSurface = false;
	if (attr == ATTR_Water && mInWaterTimer == 0 && mColor != Blue) {
		isDrownSurface = true;
	} else if (isStickTo() && mInWaterTimer == 0 && mColor != Blue) {
		Creature* obj = getStickObject();
		if (obj && obj->mFloorTri && MapCode::getAttribute(obj->mFloorTri) == ATTR_Water) {
			if (zen::Abs(obj->mPosition.y - mPosition.y) < 10.0f) {
				isDrownSurface = true;
			}
		}
	}

	if (isDrownSurface && isAlive() && state != PIKISTATE_Dead && state != PIKISTATE_Dying && state != PIKISTATE_Pressed
	    && state != PIKISTATE_WaterHanged) {
		seSystem->playSoundDirect(5, SEW_PIKI_WATERDROP, mPosition);
		startMotion(PaniMotionInfo(PIKIANIM_TYakusui, this), PaniMotionInfo(PIKIANIM_TYakusui));
		mFSM->transit(this, PIKISTATE_Drown);
		EffectParm rippleParm(&mPosition);
		EffectParm parm(mPosition);
		rippleParm._24 = 2.0f;

		mRippleEffect->emit(rippleParm);
		UtEffectMgr::cast(17, parm);
		mInWaterTimer = 1;
		return;
	}

	if (mMode == PikiMode::GuardMode) {
		mPosition.y = 0.0f;
		setCreatureFlag(CF_IsOnGround);
		mVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	800CA9D8
 * Size:	000234
 */
void Piki::startMotion(PaniMotionInfo& motion1, PaniMotionInfo& motion2)
{
	int state = getState();

	// if we're being swallowed, make sure we're doing the correct animation
	if (state == PIKISTATE_Swallowed && motion1.mMotionIdx != PIKIANIM_Esa && motion1.mMotionIdx != PIKIANIM_Fall) {
		// BZZZZT. WRONG.
		PRINT("SWALLOW ** MOTION %d/%d\n", motion1.mMotionIdx, motion2.mMotionIdx);
		dump();
	}

	if (state == PIKISTATE_Bury && motion1.mMotionIdx == PIKIANIM_Damage) {
		PRINT("bury piki start damage ??\n");
	}

	if (state == PIKISTATE_Flick) {
		// make sure we're doing a flick animation
		int motionID = motion1.mMotionIdx;
		if (motionID != PIKIANIM_JHit && motionID != PIKIANIM_GetUp && motionID != PIKIANIM_JKoke && motionID != PIKIANIM_Dead
		    && motionID != PIKIANIM_Dead2 && motionID != PIKIANIM_Dead3 && motionID != PIKIANIM_Walk) {
			PRINT("flick : start motion %d ******** \n", motionID);
		}
	}

	if (isDamaged() && motion1.mMotionIdx != PIKIANIM_Damage) {
		PRINT("DAMAGE : something goes wrong !\n");
		PRINT("%f\n", 0.1f / 0.0f); // HAHAHAHAHA
	}

	if ((state == PIKISTATE_Dying || state == PIKISTATE_Dead) && motion1.mMotionIdx != PIKIANIM_Dead) {
		PRINT("DYING/DEAD : something goes wrong !\n");
	}

	mPikiAnimMgr.startMotion(motion1, motion2);
	mBlendMotionIdx = -1;

	if (playerState->inDayEnd()) {
		return;
	}

	switch (motion1.mMotionIdx) {
	case PIKIANIM_Run:
	case PIKIANIM_Nigeru:
	case PIKIANIM_Walk:
	case PIKIANIM_Wait:
	case PIKIANIM_Iraira:
	case PIKIANIM_Suwaru:
		Creature* target = mLookAtTarget.getPtr();
		if (!isLooking()) {
			if (!target) {
				int rand = System::getRand(1.0f) * 2.0f;
				if (rand == 0) {
					startHimaLook(&mNavi->mCursorWorldPos);
				} else {
					startHimaLook(&mNavi->mNaviLightPosition);
				}
				return;
			}

			startHimaLook(&target->mPosition);
			mLookAtTarget.set(target);
			return;
		}

		if (mIsLooking && target) {
			CollPart* part = nullptr;
			if (target->mCollInfo) {
				part = target->mCollInfo->getRandomCollPart('****');
			}
			if (part) {
				startHimaLook(&part->mCentre);
			} else {
				startHimaLook(&target->mPosition);
			}

			if (isStickTo()) {
				PRINT("++++++++++++ PIKI STICK TO AND START LOOK !\n");
			}

			mLookAtTarget.set(target);
		}
		return;

	default:
		finishLook();
		return;
	}

	u32 badCompiler[4]; // idk what this is from
}

/*
 * --INFO--
 * Address:	800CAC0C
 * Size:	000048
 */
void Piki::enableMotionBlend()
{
	mBlendMotionIdx = mPikiAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	mPikiAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(PIKIANIM_Asibumi));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
bool Piki::doMotionBlend()
{
	return mBlendMotionIdx != -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void Piki::swapMotion(PaniMotionInfo& motion1, PaniMotionInfo& motion2)
{
	f32 upperCounter = mPikiAnimMgr.getUpperAnimator().mAnimationCounter;
	f32 lowerCounter = mPikiAnimMgr.getLowerAnimator().mAnimationCounter;

	mPikiAnimMgr.startMotion(motion1, motion2);
	mPikiAnimMgr.getUpperAnimator().mAnimationCounter = upperCounter;
	mPikiAnimMgr.getLowerAnimator().mAnimationCounter = lowerCounter;

	if (motion1.mMotionIdx == PIKIANIM_Wait) {
		ERROR("swapMotion(wait)");
	}
}

/*
 * --INFO--
 * Address:	800CAC54
 * Size:	000190
 */
void Piki::checkBridgeWall(Creature* object, Vector3f& direction)
{
	int state = getState();
	if (isHolding()) {
		return;
	}

	if (mMode != PikiMode::FormationMode) {
		return;
	}

	if (state != PIKISTATE_Pressed && state != PIKISTATE_Dead && state != PIKISTATE_Dying) {
		if (object && object->mObjType == OBJTYPE_WorkObject) {
			Action* action = mActiveAction->getCurrAction();
			if (action && static_cast<ActCrowd*>(action)->mFormationState == 1) {
				WorkObject* workObj = static_cast<WorkObject*>(object);
				if (workObj->isBridge()) {
					Bridge* bridge = static_cast<Bridge*>(workObj);
					f32 zComp      = direction.DP(bridge->getBridgeZVec());
					if (bridge->_3C8 && zComp < -0.8f && !bridge->isFinished()) {
						PRINT("** BRIDGE AI START\n");
						seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
						mActiveAction->abandon(nullptr);
						mActiveAction->mCurrActionIdx = PikiAction::Bridge;
						mActiveAction->mChildActions[PikiAction::Bridge].initialise(bridge);
						mMode = PikiMode::BridgeMode;
					}
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800CADE4
 * Size:	000B78
 */
void Piki::collisionCallback(CollEvent& event)
{
	Creature* collider = event.mCollider;
	CollPart* collPart = event.mColliderPart;
	if (getState() == PIKISTATE_Emotion) {
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	if (playerState->inDayEnd()) {
		return;
	}

	bool distCheck = true;
	if (!mNavi->_830 && mNavi->_764.length() < 0.1f) {
		distCheck = false;
	}

	if (distCheck && collider->isObjType(OBJTYPE_Kusa) && !isStickTo()) {
		int state = getState();
		if ((state == PIKISTATE_Normal || state == PIKISTATE_Flying) && isAlive()) {
			bool crowdCheck = false;
			if (mMode == PikiMode::FormationMode) {
				ActCrowd* action = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
				if (action && action->mFormationState != 1) {
					crowdCheck = true;
				}
			}

			Vector3f centre = getCentre();
			Sphere sphere(centre, getCentreSize());
			Tube tube;
			collPart->makeTube(tube);
			Vector3f pushVec;
			f32 collDepth;
			if (!crowdCheck && tube.collide(sphere, pushVec, collDepth)) {
				if (state == PIKISTATE_Flying) {
					mFSM->transit(this, PIKISTATE_Normal);
				}

				startStickObject(collider, collPart, -1, 0.0f);
				changeMode(PikiMode::RopeMode, nullptr);
				return;
			}
		}
	}

	MsgCollide msg(event);
	sendMsg(&msg);

	if (isDamaged()) {
		return;
	}

	int state1 = getState();
	if (state1 == PIKISTATE_LookAt || state1 == PIKISTATE_Flick || state1 == PIKISTATE_Swallowed) {
		return;
	}

	PikiState* pState = static_cast<PikiState*>(getCurrState());
	if (pState && !pState->collideAI()) {
		return;
	}

	if (isHolding()) {
		return;
	}

	if (AIConstant::_instance->mConstants.mDoCStickAttack() && (collider->mObjType == OBJTYPE_Teki || collider->isBoss())
	    && collider->isOrganic() && mMode == PikiMode::FormationMode && getState() != PIKISTATE_Pressed) {
		ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
		if (crowd && crowd->mFormationState == 1) {
			mActiveAction->abandon(nullptr);
			mActiveAction->mCurrActionIdx = PikiAction::Attack;
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(collider);
			mMode = PikiMode::AttackMode;
			return;
		}
	}

	if (!isKinoko() && collider->mObjType == OBJTYPE_Piki && mMode == PikiMode::FormationMode && getState() != PIKISTATE_Pressed
	    && static_cast<Piki*>(collider)->isTeki(this)) {
		ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
		if (crowd && crowd->mFormationState == 1) {
			mActiveAction->abandon(nullptr);
			mActiveAction->mCurrActionIdx = PikiAction::Attack;
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(collider);
			mMode = PikiMode::AttackMode;
			return;
		}
	}

	if (distCheck && collider->isSluice() && mMode == PikiMode::FormationMode && collider->isAlive()) {
		ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
		if (collPart->getID().match('gate', '*') && crowd && crowd->mFormationState == 1) {
			mActiveAction->abandon(nullptr);
			mActiveAction->mCurrActionIdx = PikiAction::BreakWall;
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(collider);
			mMode = PikiMode::BreakwallMode;
			return;
		}
	}

	if (distCheck && collider->mObjType == OBJTYPE_WorkObject && mMode == PikiMode::FormationMode) {
		WorkObject* obj = static_cast<WorkObject*>(collider);
		if (obj->isHinderRock()) {
			HinderRock* rock = static_cast<HinderRock*>(obj);
			if (!rock->isFinished()) {
				ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
				if (crowd && crowd->mFormationState == 1) {
					mActiveAction->abandon(nullptr);
					mActiveAction->mCurrActionIdx = PikiAction::Push;
					mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(collider);
					mMode = PikiMode::PushstoneMode;
					return;
				}
			}
		}
	}

	if (distCheck && collider->mObjType == OBJTYPE_Pellet && mMode == PikiMode::FormationMode) {
		Pellet* pellet = static_cast<Pellet*>(collider);
		if (pellet->isAlive() && pellet->getMinFreeSlotIndex() != -1) {
			ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
			if (crowd && crowd->mFormationState == 1) {
				mActiveAction->abandon(nullptr);
				mActiveAction->mCurrActionIdx = PikiAction::Transport;
				mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(collider);
				mMode = PikiMode::TransportMode;
				return;
			}
		}
	}

	if (distCheck && collider->mObjType == OBJTYPE_Bomb && mColor == Yellow && !collider->isGrabbed() && collider->isVisible()
	    && collider->isAlive() && mMode == PikiMode::FormationMode && !isHolding()) {
		changeMode(PikiMode::PickMode, nullptr);
		return;
	}

	if (distCheck && collider->mObjType == OBJTYPE_BombGen && mColor == Yellow && !collider->isGrabbed() && collider->isVisible()
	    && collider->isAlive() && mMode == PikiMode::FormationMode && !isHolding()) {
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Mine;
		mActiveAction->mChildActions[PikiAction::Mine].initialise(collider);
		mMode = PikiMode::MineMode;
		return;
	}

	if (collider->isAlive() && collider->mObjType == OBJTYPE_GrassGen && collider->isAlive() && mMode == PikiMode::FormationMode
	    && !isHolding()) {
		GrassGen* grass = static_cast<GrassGen*>(collider);
		if (grass->workable()) {
			ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
			if (crowd && crowd->mFormationState == 1) {
				seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
				mActiveAction->abandon(nullptr);
				mActiveAction->mCurrActionIdx = PikiAction::Weed;
				mActiveAction->mChildActions[PikiAction::Weed].initialise(collider);
				mMode = PikiMode::WeedMode;
				return;
			}
		}
	}

	if (distCheck && collider->isAlive() && collider->mObjType == OBJTYPE_BoBase && mMode == PikiMode::FormationMode && !isHolding()) {
		ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
		if (crowd && crowd->mFormationState == 1) {
			seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
			mActiveAction->abandon(nullptr);
			mActiveAction->mCurrActionIdx = PikiAction::BoMake;
			mActiveAction->mChildActions[PikiAction::BoMake].initialise(collider);
			mMode = PikiMode::BomakeMode;
			return;
		}
	}

	if (collider->isAlive() && collider->mObjType == OBJTYPE_RockGen && collider->isAlive() && mMode == PikiMode::FormationMode
	    && !isHolding()) {
		RockGen* pebble = static_cast<RockGen*>(collider);
		if (pebble->workable()) {
			ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
			if (crowd && crowd->mFormationState == 1) {
				seSystem->playPikiSound(SEF_PIKI_FIND, mPosition);
				mActiveAction->abandon(nullptr);
				mActiveAction->mCurrActionIdx = PikiAction::Stone;
				mActiveAction->mChildActions[PikiAction::Stone].initialise(collider);
				mMode = PikiMode::PebbleMode;
				return;
			}
		}
	}

	int state2 = getState();
	if (isAlive() && !(state2 == PIKISTATE_Grow || state2 == PIKISTATE_Bury) && !isDamaged() && mMode == PikiMode::FormationMode) {
		PRINT("idk this isn't in the DLL", mMode);
	}
}

/*
 * --INFO--
 * Address:	800CB964
 * Size:	000400
 */
Piki::Piki(CreatureProp* prop)
    : Creature(prop)
{
	mLookatTarget = nullptr;
	if (routeMgr) {
		int numWP = routeMgr->getNumWayPoints('test');
		if (numWP > 0) {
			mPathBuffers = new PathFinder::Buffer[numWP];
		}
	}

	mBurnEffect      = new BurnEffect(&mVelocity);
	mRippleEffect    = new RippleEffect();
	mFreeLightEffect = new FreeLightEffect();
	mSlimeEffect     = new SlimeEffect();
	_48C             = 0.0f;
	mSearchBuffer.init(mPikiSearchData, 6);
	_68              = 1;
	mPanickedEffect  = new PermanentEffect();
	mIsPanicked      = false;
	_4DC             = 0;
	mCurrentState    = nullptr;
	mCollisionRadius = 8.0f;
	mNavi            = nullptr;
	mActiveAction    = new TopAction(this);
	mObjType         = OBJTYPE_Piki;
	mMode            = PikiMode::FormationMode;
	mFSM             = new PikiStateMachine();
	mFSM->init(this);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void Piki::setSpeed(f32 speedRatio)
{
	f32 scale = 1.0f; // i guess they were playing around with this?
	f32 max   = pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed() * scale;
	if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Flower) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxFlowerMoveSpeed();
	} else if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Bud) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxBudMoveSpeed();
	}

	f32 min = pikiMgr->mPikiParms->mPikiParms.mMinMoveSpeed() * scale;

	mMoveSpeed = (max - min) * speedRatio + min;
}

/*
 * --INFO--
 * Address:	800CBD64
 * Size:	000074
 */
f32 Piki::getSpeed(f32 speedRatio)
{
	f32 scale = 1.0f; // i guess they were playing around with this?
	f32 max   = pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed() * scale;
	if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Flower) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxFlowerMoveSpeed();
	} else if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Bud) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxBudMoveSpeed();
	}

	f32 min = pikiMgr->mPikiParms->mPikiParms.mMinMoveSpeed() * scale;

	return (max - min) * speedRatio + min;
}

/*
 * --INFO--
 * Address:	800CBDD8
 * Size:	0000C4
 */
void Piki::setSpeed(f32 speedRatio, Vector3f& direction)
{
	f32 scale = 1.0f; // i guess they were playing around with this?
	f32 max   = pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed() * scale;
	f32 min   = pikiMgr->mPikiParms->mPikiParms.mMinMoveSpeed() * scale;
	if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Flower) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxFlowerMoveSpeed();
	} else if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Bud) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxBudMoveSpeed();
	}

	mMoveSpeed      = (max - min) * speedRatio + min;
	mTargetVelocity = mMoveSpeed * direction;
}

/*
 * --INFO--
 * Address:	800CBE9C
 * Size:	0000DC
 */
void Piki::setSpeed(f32 speedRatio, f32 angle)
{
	f32 scale = 1.0f; // i guess they were playing around with this?
	f32 max   = pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed() * scale;
	if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Flower) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxFlowerMoveSpeed();
	} else if (AIConstant::_instance->mConstants.mDoScaleHappaMoveSpeed() && mHappa == Bud) {
		max = pikiMgr->mPikiParms->mPikiParms.mMaxBudMoveSpeed();
	}

	f32 min = pikiMgr->mPikiParms->mPikiParms.mMinMoveSpeed() * scale;

	mMoveSpeed = (max - min) * speedRatio + min;
	mTargetVelocity.set(mMoveSpeed * cosf(angle), 0.0f, mMoveSpeed * sinf(angle));
}

/*
 * --INFO--
 * Address:	800CBF78
 * Size:	000020
 */
f32 Piki::getSize()
{
	if (getState() == PIKISTATE_Bury) {
		return 2.0f;
	}
	return mPikiSize;
}

/*
 * --INFO--
 * Address:	800CBF98
 * Size:	000044
 */
f32 Piki::getiMass()
{
	int state = getState();
	if (state == PIKISTATE_Push || state == PIKISTATE_PushPiki) {
		return 2.0f;
	}
	if (state == PIKISTATE_Grow || state == PIKISTATE_Bury) {
		return 0.0f;
	}
	return pikiMgr->mPikiParms->mPikiParms._25C();
}

/*
 * --INFO--
 * Address:	800CBFDC
 * Size:	000068
 */
void Piki::resetPosition(Vector3f& pos)
{
	Creature::resetPosition(pos);
	mShadowPos = pos;
	mEffectPos = pos;
}

/*
 * --INFO--
 * Address:	800CC044
 * Size:	0002EC
 */
void Piki::init(Navi* navi)
{
	mHorizontalRotation = 0.0f;
	mVerticalRotation   = 0.0f;
	mScale.set(1.0f, 1.0f, 1.0f);
	mRouteHandle         = 0;
	mUseAsyncPathfinding = false;
	_528                 = 0.0f;
	mLookAtTarget.clear();
	mLookatTarget = nullptr;
	mIsLooking    = 0;
	forceFinishLook();
	mEmotion          = 10;
	mCarryingShipPart = nullptr;
	mLeaderCreature   = nullptr;
	mInWaterTimer     = 0;
	mFiredState       = 0;
	mIsCallable       = true;
	mLastAnimPosition.set(0.0f, 0.0f, 0.0f);
	unsetEraseKill();
	_484 = -1;
	_480 = 0;

	if (pikiUpdateMgr) {
		mPikiUpdateContext.init(pikiUpdateMgr);
	}
	if (pikiLookUpdateMgr) {
		mPikiLookUpdateContext.init(pikiLookUpdateMgr);
	}
	if (pikiOptUpdateMgr) {
		mOptUpdateContext.init(pikiOptUpdateMgr);
	}

	mSwallowMouthPart = nullptr;
	mWantToStick      = false;
	_474              = 0;
	_478              = 0.0f;
	_4D8              = 0;
	mIsWhistlePending = false;
	_4E8              = 0;
	mWallObj          = nullptr;
	_4EC              = 0.0f;
	_4F0              = 0.0f;
	_519              = 0;
	_51C              = 0;
	mMotionSpeed      = 1.0f;
	mNavi             = navi;
	Creature::init();
	int color = gsys->getRand(1.0f) * 3.0f;
	if (color >= PikiColorCount) {
		color = Blue;
	}
	initColor(color);
	mHappa = Leaf;
	resetCreatureFlag(CF_Unk6);
	_500.reset();
	mMode   = PikiMode::FormationMode;
	mHealth = pikiMgr->mPikiParms->mPikiParms.mPikiHealth();
	mFSM->transit(this, PIKISTATE_Normal);
	mFloweringTimer = 0;
	mFSM->transit(this, PIKISTATE_Normal);
	mPikiSize = pikiMgr->mPikiParms->mPikiParms._23C()
	          + (pikiMgr->mPikiParms->mPikiParms._24C() - pikiMgr->mPikiParms->mPikiParms._23C()) * System::getRand(1.0f);
	mOldFaceDirection = mFaceDirection;
	initBirth();
	mRouteDestinationIndex = -1;
	mRouteSourceIndex      = -1;
	mRouteTargetCreature   = nullptr;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800CC334
 * Size:	000038
 */
bool Piki::isAlive()
{
	int state = getState();
	if (state == PIKISTATE_Dying || state == PIKISTATE_Dead) {
		return false;
	}

	return Creature::isAlive();
}

/*
 * --INFO--
 * Address:	800CC36C
 * Size:	000014
 */
bool Piki::isFruit()
{
	return mHappa == Flower;
}

/*
 * --INFO--
 * Address:	800CC380
 * Size:	00034C
 */
void Piki::updateLookCreature()
{
	if (!mPikiLookUpdateContext.updatable()) {
		return;
	}

	if (!tekiMgr) {
		return;
	}

	if (!getPikiState()->useLookUpdate()) {
		return;
	}

	Creature* target = mLookAtTarget.getPtr();
	if (target && (!target->isVisible() || !target->isAlive())) {
		mLookAtTarget.reset();
		target = nullptr;
	}

	f32 minDist = 128000.0f;
	if (target) {
		minDist = qdist2(mPosition.x, mPosition.z, target->mPosition.x, target->mPosition.z) - target->getBoundingSphereRadius();
		if (minDist > 200.0f) {
			mLookAtTarget.reset();
			target  = nullptr;
			minDist = 128000.0f;
		}
	}

	Iterator iter(tekiMgr);
	Creature* newTarget = nullptr;
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		if (teki->isAlive()) {
			f32 tekiDist = qdist2(mPosition.x, mPosition.z, teki->mPosition.x, teki->mPosition.z) - teki->getBoundingSphereRadius();
			if (tekiDist < minDist) {
				newTarget = teki;
				minDist   = tekiDist;
			}
		}
	}

	if (target != newTarget && System::getRand(1.0f) > 0.2f) {
		if (target) {
			mLookAtTarget.reset();
		}
		if (System::getRand(1.0f) > 0.2f) {
			newTarget = mNavi;
		}

		mLookAtTarget.set(newTarget);
	}

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800CC6D4
 * Size:	000050
 */
void Piki::doAnimation()
{
	updateWalkAnimation();
	mLastAnimPosition = mPosition;
	mPikiAnimMgr.updateAnimation(mMotionSpeed);
}

/*
 * --INFO--
 * Address:	800CC724
 * Size:	000448
 */
void Piki::updateWalkAnimation()
{
	int state = getState();
	if (state != PIKISTATE_Flick && state != PIKISTATE_Swallowed && state != PIKISTATE_Emotion && state != PIKISTATE_Absorb
	    && state != PIKISTATE_GrowUp && state != PIKISTATE_KinokoChange) {
		if (hasBomb() && state == PIKISTATE_Normal && mMode == PikiMode::FormationMode
		    && mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Pick) {
			startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
			mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
			mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
			enableMotionBlend();
		}

		Vector3f sep = mPosition - mLastAnimPosition;
		sep.y        = 0.0f;
		f32 speed    = sep.length() / gsys->getFrameTime();

		int lowerMotionID = mPikiAnimMgr.getLowerAnimator().getCurrentMotionIndex();
		if (lowerMotionID != PIKIANIM_Wait && lowerMotionID != PIKIANIM_Walk && lowerMotionID != PIKIANIM_Asibumi
		    && lowerMotionID != PIKIANIM_Run && lowerMotionID != PIKIANIM_Nigeru) {
			mMotionSpeed = 30.0f;
			return;
		}

		int upperMotionID = mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex();
		f32 angleDiff     = zen::Abs(mFaceDirection - mOldFaceDirection);
		doMotionBlend();
		int newMotionID;
		if (speed < pikiMgr->mPikiParms->mPikiParms._19C()) {
			newMotionID = PIKIANIM_Wait;
			if (angleDiff > 0.01f) {
				newMotionID = PIKIANIM_Asibumi;
			}
			speed = 30.0f;
		} else if (speed < pikiMgr->mPikiParms->mPikiParms._1AC()) {
			newMotionID = PIKIANIM_Asibumi;
			speed       = 30.0f;
		} else if (speed < pikiMgr->mPikiParms->mPikiParms._1BC()) {
			newMotionID = PIKIANIM_Walk;
			f32 diff    = speed - pikiMgr->mPikiParms->mPikiParms._1AC();
			f32 ratio   = diff / (pikiMgr->mPikiParms->mPikiParms._1BC() - pikiMgr->mPikiParms->mPikiParms._1AC());
			speed       = pikiMgr->mPikiParms->mPikiParms._1DC()
			      + (pikiMgr->mPikiParms->mPikiParms._1EC() - pikiMgr->mPikiParms->mPikiParms._1DC()) * ratio;

		} else if (speed < pikiMgr->mPikiParms->mPikiParms._1CC()) {
			newMotionID = PIKIANIM_Run;
			f32 diff    = speed - pikiMgr->mPikiParms->mPikiParms._1BC();
			f32 ratio   = diff / (pikiMgr->mPikiParms->mPikiParms._1CC() - pikiMgr->mPikiParms->mPikiParms._1BC());
			speed       = pikiMgr->mPikiParms->mPikiParms._1FC()
			      + (pikiMgr->mPikiParms->mPikiParms._20C() - pikiMgr->mPikiParms->mPikiParms._1FC()) * ratio;

		} else {
			newMotionID = PIKIANIM_Nigeru;
			speed       = pikiMgr->mPikiParms->mPikiParms._21C();
		}

		if (newMotionID != lowerMotionID) {
			if (lowerMotionID == PIKIANIM_Wait && newMotionID != PIKIANIM_Asibumi) {
				_480 = 4;
			}

			if (lowerMotionID != PIKIANIM_Asibumi && newMotionID == PIKIANIM_Wait) {
				_480 = 4;
			}

			if (newMotionID != _484) {
				_480 = 0;
				_484 = newMotionID;
			} else {
				_480++;
			}

			if (_480 < 4) {
				return;
			}
		}

		if (lowerMotionID != newMotionID) {
			if (lowerMotionID == PIKIANIM_Wait || lowerMotionID == PIKIANIM_Asibumi || newMotionID == PIKIANIM_Wait
			    || newMotionID == PIKIANIM_Asibumi) {
				if (!doMotionBlend()) {
					startMotion(PaniMotionInfo(newMotionID), PaniMotionInfo(newMotionID));
				} else {
					mPikiAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(newMotionID));
				}
			} else if (!doMotionBlend() && upperMotionID != PIKIANIM_Wait && upperMotionID != PIKIANIM_Asibumi) {
				if (newMotionID == PIKIANIM_Wait || newMotionID == PIKIANIM_Asibumi) {
					ERROR("SWAP WAIT");
				}
				swapMotion(PaniMotionInfo(newMotionID), PaniMotionInfo(newMotionID));
			} else {
				f32 lowerCounter = mPikiAnimMgr.getLowerAnimator().mAnimationCounter;
				mPikiAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(newMotionID));
				mPikiAnimMgr.getLowerAnimator().mAnimationCounter = lowerCounter;
			}
		}

		mMotionSpeed = speed;
	}
}

/*
 * --INFO--
 * Address:	800CCB6C
 * Size:	00053C
 */
void Piki::realAI()
{
	updateLookCreature();
	if (isLooking() && isStickTo()) {
		PRINT("********** STICK AND LOOKING !!!!!!!!!!!!!!!\n");
	}

	demoCheck();

	Creature* platCreature = getCollidePlatformCreature();
	if (platCreature) {
		Vector3f normal(getCollidePlatformNormal());
		checkBridgeWall(platCreature, normal);
	}

	if (isHolding()) {
		Creature* held = getHoldCreature();
		if (held->mObjType != OBJTYPE_Bomb) {
			// oops, what the hell are we holding if it's not a bomb??
			PRINT("PIKI(%x) HOLDS ! %x\n", this, held);
			held->dump();
			AICreature* aiC = static_cast<AICreature*>(held);
			PRINT("---- aiContext ---\n");
			PRINT(" creature=%x target=%x\n", aiC->mCollidingCreature, aiC->mTargetCreature);
			PRINT(" int=%d int2=%d real=%f real1=%f real2=%f\n", aiC->_2D0, aiC->mCounter, aiC->mCurrentItemHealth, aiC->_2DC,
			      aiC->mMaxHealth);
			PRINT("  currState=%x\n", aiC->mCurrentState);
			PRINT("============================================\n");
			dump();
			PRINT("**** ==========\n");

			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				Creature* piki = *iter;
				if (piki->isHolding() && piki != this && piki->getHoldCreature() == held) {
					ERROR("%x & %x holds !\n", piki, this);
				}
			}
		}
	}

	mCollisionRadius = pikiMgr->mPikiParms->mPikiParms.mCollisionRadius();
	bool isGrowState = false;
	int state        = getState();
	if (getState() == PIKISTATE_Grow) {
		isGrowState = true;
	}

	int attr = ATTR_NULL;
	if (mFloorTri) {
		attr = MapCode::getAttribute(mFloorTri);
	}

	bool isInWater = false;
	if (attr == ATTR_Water) {
		isInWater = true;
	} else if (isStickTo()) {
		Creature* stickObj = getStickObject();
		if (stickObj && stickObj->mFloorTri && MapCode::getAttribute(stickObj->mFloorTri) == ATTR_Water
		    && zen::Abs(stickObj->mPosition.y - mPosition.y) < 10.0f) {
			isInWater = true;
		}
	}

	if (isInWater && getState() != PIKISTATE_WaterHanged) {
		if (mInWaterTimer == 0) {
			EffectParm rippleParm(&mShadowPos);
			EffectParm castParm(mShadowPos);
			mRippleEffect->emit(rippleParm);
			UtEffectMgr::cast(17, castParm);
			seSystem->playSoundDirect(5, SEW_PIKI_WATERDROP, mPosition);
		}

		mIsPanicked = true; // huh. sure.
		mInWaterTimer++;
		if (mInWaterTimer > 1000) {
			mInWaterTimer = 1000;
		}

		if (mColor == Blue) {
			playerState->mResultFlags.setOn(RESFLAG_BluePikminWaterImmunity);
		}

		if (state != PIKISTATE_Swallowed && state != PIKISTATE_Dead && state != PIKISTATE_Dying && state != PIKISTATE_Pressed
		    && state != PIKISTATE_Drown && state != PIKISTATE_Flying && mColor != Blue && isAlive()) {
			if (mInWaterTimer
			    >= int(gsys->getRand(1.0f) * pikiMgr->mPikiParms->mPikiParms._48C()) + pikiMgr->mPikiParms->mPikiParms._47C()) {
				startMotion(PaniMotionInfo(PIKIANIM_TYakusui, this), PaniMotionInfo(PIKIANIM_TYakusui));
				mFSM->transit(this, PIKISTATE_Drown);
			}
		}
	} else {
		if (mInWaterTimer) {
			mInWaterTimer = 0;
			mRippleEffect->kill();
			mIsPanicked = false;
		}

		mInWaterTimer = 0;
	}

	mOldFaceDirection = mFaceDirection;
	updateFire();
	mFSM->exec(this);
	_4E8 = 0;

	u32 badCompiler[5]; // there's some extra inlining or functioning going on with this, but idk what
	                    /*
	                    .loc_0x0:
	                      mflr      r0
	                      stw       r0, 0x4(r1)
	                      stwu      r1, -0x170(r1)
	                      stw       r31, 0x16C(r1)
	                      stw       r30, 0x168(r1)
	                      mr        r30, r3
	                      stw       r29, 0x164(r1)
	                      stw       r28, 0x160(r1)
	                      bl        -0x80C
	                      mr        r3, r30
	                      bl        0xCB48
	                      mr        r3, r30
	                      bl        -0x49CAC
	                      mr        r3, r30
	                      bl        -0x4295C
	                      mr.       r29, r3
	                      beq-      .loc_0x78
	                      addi      r3, r1, 0xC0
	                      addi      r4, r30, 0
	                      bl        -0x42954
	                      lfs       f0, 0xC0(r1)
	                      mr        r3, r30
	                      lfs       f1, 0xC4(r1)
	                      mr        r4, r29
	                      stfs      f0, 0x13C(r1)
	                      lfs       f0, 0xC8(r1)
	                      addi      r5, r1, 0x13C
	                      stfs      f1, 0x140(r1)
	                      stfs      f0, 0x144(r1)
	                      bl        -0x1F8C
	                
	                    .loc_0x78:
	                      lwz       r3, 0x2AC(r30)
	                      cmplwi    r3, 0
	                      beq-      .loc_0x188
	                      lwz       r0, 0x6C(r3)
	                      cmpwi     r0, 0xE
	                      beq-      .loc_0x188
	                      lwz       r12, 0x0(r3)
	                      lwz       r12, 0xC8(r12)
	                      mtlr      r12
	                      blrl
	                      mr        r3, r30
	                      lwz       r12, 0x0(r30)
	                      lwz       r12, 0xC8(r12)
	                      mtlr      r12
	                      blrl
	                      lwz       r29, 0x3068(r13)
	                      mr        r3, r29
	                      lwz       r12, 0x0(r29)
	                      lwz       r12, 0xC(r12)
	                      mtlr      r12
	                      blrl
	                      mr        r31, r3
	                      b         .loc_0x12C
	                
	                    .loc_0xD4:
	                      cmpwi     r31, -0x1
	                      bne-      .loc_0xF8
	                      mr        r3, r29
	                      lwz       r12, 0x0(r29)
	                      li        r4, 0
	                      lwz       r12, 0x8(r12)
	                      mtlr      r12
	                      blrl
	                      b         .loc_0x110
	                
	                    .loc_0xF8:
	                      mr        r3, r29
	                      lwz       r12, 0x0(r29)
	                      mr        r4, r31
	                      lwz       r12, 0x8(r12)
	                      mtlr      r12
	                      blrl
	                
	                    .loc_0x110:
	                      mr        r3, r29
	                      lwz       r12, 0x0(r29)
	                      mr        r4, r31
	                      lwz       r12, 0x10(r12)
	                      mtlr      r12
	                      blrl
	                      mr        r31, r3
	                
	                    .loc_0x12C:
	                      mr        r3, r29
	                      lwz       r12, 0x0(r29)
	                      mr        r4, r31
	                      lwz       r12, 0x14(r12)
	                      mtlr      r12
	                      blrl
	                      rlwinm.   r0,r3,0,24,31
	                      beq-      .loc_0x154
	                      li        r0, 0x1
	                      b         .loc_0x180
	                
	                    .loc_0x154:
	                      mr        r3, r29
	                      lwz       r12, 0x0(r29)
	                      mr        r4, r31
	                      lwz       r12, 0x8(r12)
	                      mtlr      r12
	                      blrl
	                      cmplwi    r3, 0
	                      bne-      .loc_0x17C
	                      li        r0, 0x1
	                      b         .loc_0x180
	                
	                    .loc_0x17C:
	                      li        r0, 0
	                
	                    .loc_0x180:
	                      rlwinm.   r0,r0,0,24,31
	                      beq+      .loc_0xD4
	                
	                    .loc_0x188:
	                      lwz       r3, 0x3068(r13)
	                      li        r0, -0x1
	                      lwz       r3, 0x68(r3)
	                      lfs       f0, 0x278(r3)
	                      stfs      f0, 0x270(r30)
	                      lwz       r3, 0x28C(r30)
	                      lwz       r4, 0x52C(r30)
	                      cmplwi    r3, 0
	                      lwz       r31, 0x4(r4)
	                      beq-      .loc_0x1B8
	                      bl        0x49364
	                      mr        r0, r3
	                
	                    .loc_0x1B8:
	                      cmpwi     r0, 0x5
	                      li        r28, 0
	                      bne-      .loc_0x1CC
	                      li        r28, 0x1
	                      b         .loc_0x214
	                
	                    .loc_0x1CC:
	                      lwz       r29, 0x184(r30)
	                      cmplwi    r29, 0
	                      beq-      .loc_0x214
	                      beq-      .loc_0x214
	                      lwz       r3, 0x28C(r29)
	                      cmplwi    r3, 0
	                      beq-      .loc_0x214
	                      bl        0x4932C
	                      cmpwi     r3, 0x5
	                      bne-      .loc_0x214
	                      lfs       f2, 0x98(r29)
	                      lfs       f1, 0x98(r30)
	                      lfs       f0, -0x69F4(r2)
	                      fsubs     f1, f2, f1
	                      fabs      f1, f1
	                      fcmpo     cr0, f1, f0
	                      bge-      .loc_0x214
	                      li        r28, 0x1
	                
	                    .loc_0x214:
	                      rlwinm.   r0,r28,0,24,31
	                      beq-      .loc_0x44C
	                      lwz       r3, 0x52C(r30)
	                      lwz       r0, 0x4(r3)
	                      cmpwi     r0, 0xD
	                      beq-      .loc_0x44C
	                      lhz       r0, 0x426(r30)
	                      cmplwi    r0, 0
	                      bne-      .loc_0x2D0
	                      lfs       f1, -0x6A48(r2)
	                      addi      r0, r30, 0x44C
	                      lfs       f0, -0x6A20(r2)
	                      addi      r4, r1, 0xF8
	                      stfs      f1, 0x100(r1)
	                      stfs      f1, 0xFC(r1)
	                      stfs      f1, 0xF8(r1)
	                      stfs      f1, 0xD4(r1)
	                      stfs      f1, 0x10C(r1)
	                      stfs      f1, 0xD0(r1)
	                      stfs      f1, 0x108(r1)
	                      stfs      f1, 0xCC(r1)
	                      stfs      f1, 0x104(r1)
	                      stfs      f1, 0xE0(r1)
	                      stw       r0, 0x118(r1)
	                      stfs      f1, 0xDC(r1)
	                      stfs      f0, 0x11C(r1)
	                      stfs      f1, 0xD8(r1)
	                      lwz       r3, 0x44C(r30)
	                      lwz       r0, 0x450(r30)
	                      stw       r3, 0xCC(r1)
	                      stw       r0, 0xD0(r1)
	                      lwz       r0, 0x454(r30)
	                      stw       r0, 0xD4(r1)
	                      stfs      f0, 0xF0(r1)
	                      lwz       r3, 0x430(r30)
	                      lwz       r12, 0x0(r3)
	                      lwz       r12, 0x2C(r12)
	                      mtlr      r12
	                      blrl
	                      li        r3, 0x11
	                      addi      r4, r1, 0xCC
	                      bl        0x474BC
	                      lwz       r3, 0x3038(r13)
	                      addi      r6, r30, 0x94
	                      li        r4, 0x5
	                      li        r5, 0xB4
	                      bl        -0x28A04
	                
	                    .loc_0x2D0:
	                      li        r0, 0x1
	                      stb       r0, 0x424(r30)
	                      lhz       r3, 0x426(r30)
	                      addi      r0, r3, 0x1
	                      sth       r0, 0x426(r30)
	                      lhz       r0, 0x426(r30)
	                      cmplwi    r0, 0x3E8
	                      ble-      .loc_0x2F8
	                      li        r0, 0x3E8
	                      sth       r0, 0x426(r30)
	                
	                    .loc_0x2F8:
	                      lhz       r0, 0x510(r30)
	                      cmplwi    r0, 0
	                      bne-      .loc_0x314
	                      lwz       r3, 0x2F6C(r13)
	                      li        r4, 0x26
	                      addi      r3, r3, 0x70
	                      bl        -0x4947C
	                
	                    .loc_0x314:
	                      cmpwi     r31, 0x8
	                      beq-      .loc_0x480
	                      cmpwi     r31, 0x7
	                      beq-      .loc_0x480
	                      cmpwi     r31, 0x6
	                      beq-      .loc_0x480
	                      cmpwi     r31, 0x21
	                      beq-      .loc_0x480
	                      cmpwi     r31, 0x18
	                      beq-      .loc_0x480
	                      cmpwi     r31, 0xE
	                      beq-      .loc_0x480
	                      lhz       r0, 0x510(r30)
	                      cmplwi    r0, 0
	                      beq-      .loc_0x480
	                      mr        r3, r30
	                      lwz       r12, 0x0(r30)
	                      lwz       r12, 0x88(r12)
	                      mtlr      r12
	                      blrl
	                      rlwinm.   r0,r3,0,24,31
	                      beq-      .loc_0x480
	                      lwz       r3, 0x3068(r13)
	                      lwz       r3, 0x68(r3)
	                      addi      r31, r3, 0x498
	                      bl        0x14B18C
	                      xoris     r3, r3, 0x8000
	                      lwz       r0, 0x0(r31)
	                      stw       r3, 0x15C(r1)
	                      lis       r4, 0x4330
	                      xoris     r0, r0, 0x8000
	                      lwz       r3, 0x3068(r13)
	                      stw       r4, 0x158(r1)
	                      lwz       r3, 0x68(r3)
	                      lfd       f3, -0x6A28(r2)
	                      lfd       f0, 0x158(r1)
	                      stw       r0, 0x154(r1)
	                      fsubs     f2, f0, f3
	                      lfs       f0, -0x69EC(r2)
	                      stw       r4, 0x150(r1)
	                      lfs       f1, -0x6A20(r2)
	                      fdivs     f2, f2, f0
	                      lfd       f0, 0x150(r1)
	                      lwz       r3, 0x488(r3)
	                      lhz       r4, 0x426(r30)
	                      fmuls     f1, f1, f2
	                      fsubs     f0, f0, f3
	                      fmuls     f0, f1, f0
	                      fctiwz    f0, f0
	                      stfd      f0, 0x148(r1)
	                      lwz       r0, 0x14C(r1)
	                      add       r0, r3, r0
	                      cmpw      r4, r0
	                      blt-      .loc_0x480
	                      cmplwi    r30, 0
	                      addi      r29, r30, 0
	                      beq-      .loc_0x3FC
	                      addi      r29, r29, 0x2B8
	                
	                    .loc_0x3FC:
	                      addi      r3, r1, 0xB0
	                      li        r4, 0x38
	                      bl        0x51FE8
	                      addi      r31, r3, 0
	                      addi      r5, r29, 0
	                      addi      r3, r1, 0xB8
	                      li        r4, 0x38
	                      bl        0x52008
	                      addi      r4, r3, 0
	                      addi      r3, r30, 0
	                      addi      r5, r31, 0
	                      bl        -0x25BC
	                      lwz       r3, 0x490(r30)
	                      addi      r4, r30, 0
	                      li        r5, 0x18
	                      lwz       r12, 0x0(r3)
	                      lwz       r12, 0x14(r12)
	                      mtlr      r12
	                      blrl
	                      b         .loc_0x480
	                
	                    .loc_0x44C:
	                      lhz       r0, 0x426(r30)
	                      cmplwi    r0, 0
	                      beq-      .loc_0x478
	                      li        r31, 0
	                      sth       r31, 0x426(r30)
	                      lwz       r3, 0x430(r30)
	                      lwz       r12, 0x0(r3)
	                      lwz       r12, 0x30(r12)
	                      mtlr      r12
	                      blrl
	                      stb       r31, 0x424(r30)
	                
	                    .loc_0x478:
	                      li        r0, 0
	                      sth       r0, 0x426(r30)
	                
	                    .loc_0x480:
	                      lfs       f0, 0xA0(r30)
	                      stfs      f0, 0x34C(r30)
	                      lhz       r0, 0x524(r30)
	                      cmplwi    r0, 0
	                      beq-      .loc_0x4FC
	                      lwz       r3, 0x52C(r30)
	                      cmplwi    r0, 0x2
	                      lwz       r0, 0x4(r3)
	                      beq-      .loc_0x4FC
	                      cmpwi     r0, 0x6
	                      beq-      .loc_0x4FC
	                      cmpwi     r0, 0x7
	                      beq-      .loc_0x4FC
	                      cmpwi     r0, 0x9
	                      beq-      .loc_0x4FC
	                      cmpwi     r0, 0x18
	                      beq-      .loc_0x4FC
	                      lhz       r0, 0x510(r30)
	                      cmplwi    r0, 0x1
	                      beq-      .loc_0x4FC
	                      lwz       r5, 0x504(r30)
	                      addi      r3, r30, 0
	                      li        r4, 0
	                      bl        0x184
	                      lwz       r3, 0x490(r30)
	                      addi      r4, r30, 0
	                      li        r5, 0x9
	                      lwz       r12, 0x0(r3)
	                      lwz       r12, 0x14(r12)
	                      mtlr      r12
	                      blrl
	                
	                    .loc_0x4FC:
	                      lwz       r3, 0x490(r30)
	                      mr        r4, r30
	                      lwz       r12, 0x0(r3)
	                      lwz       r12, 0xC(r12)
	                      mtlr      r12
	                      blrl
	                      li        r0, 0
	                      stw       r0, 0x4E8(r30)
	                      lwz       r0, 0x174(r1)
	                      lwz       r31, 0x16C(r1)
	                      lwz       r30, 0x168(r1)
	                      lwz       r29, 0x164(r1)
	                      lwz       r28, 0x160(r1)
	                      addi      r1, r1, 0x170
	                      mtlr      r0
	                      blr
	                    */
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
char* Piki::getCurrentMotionName()
{
	return mPikiAnimMgr.getUpperAnimator().getCurrentMotionName();
}

/*
 * --INFO--
 * Address:	800CD0E8
 * Size:	0000E4
 */
void Piki::doAI()
{
	int state = getState();
	if (state == PIKISTATE_Unk34) {
		mFaceDirection += 1.2f * (HALF_PI * gsys->getFrameTime());
		mFaceDirection = roundAng(mFaceDirection);
		return;
	}

	if (!isCreatureFlag(CF_Unk6)) {
		if (state == PIKISTATE_Absorb || state == PIKISTATE_GrowUp) {
			dump();
			ERROR(" state is ABSORB or GROWUP!!!!!!!!!!\n");
		}

		if (AIPerf::optLevel <= 2 || mOptUpdateContext.updatable()) {
			mActiveAction->exec();
		}
	}

	_500.reset();
}

/*
 * --INFO--
 * Address:	800CD1CC
 * Size:	00024C
 */
void Piki::changeMode(int newMode, Navi* navi)
{
	u32 badCompiler[6]; // idk
	mActiveAction->abandon(nullptr);
	switch (newMode) {
	case PikiMode::FreeMode:
		mActiveAction->mCurrActionIdx = PikiAction::Free;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(mNavi);
		break;

	case PikiMode::DecoyMode:
		mActiveAction->mCurrActionIdx = PikiAction::Decoy;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(nullptr);
		break;

	case PikiMode::FormationMode:
		mActiveAction->mCurrActionIdx = PikiAction::Crowd;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(mNavi);
		break;

	case PikiMode::PutbombMode:
		mActiveAction->mCurrActionIdx = PikiAction::PutBomb;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(nullptr);
		break;

	case PikiMode::NukuMode:
		mActiveAction->startAction(PikiAction::Pullout, nullptr);
		break;

	case PikiMode::PickMode:
		mActiveAction->mCurrActionIdx = PikiAction::PickItem;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(nullptr);
		PRINT("pick mode start?\n");
		break;

	case PikiMode::ArrowMode:
		mActiveAction->mCurrActionIdx = PikiAction::Shoot;
		break;

	case PikiMode::RopeMode:
		mActiveAction->mCurrActionIdx = PikiAction::Rope;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(nullptr);
		break;

	case PikiMode::EnterMode:
		mActiveAction->mCurrActionIdx = PikiAction::Enter;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(mNavi->mGoalItem);
		break;

	case PikiMode::ExitMode:
		mActiveAction->mCurrActionIdx = PikiAction::Exit;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(mNavi->mGoalItem);
		break;

	case PikiMode::AttackMode:
		if (playerState->inDayEnd()) {
			return;
		}
		mActiveAction->mCurrActionIdx = PikiAction::Attack;
		mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(mNavi);
		break;

	case PikiMode::GuardMode:
		mActiveAction->mCurrActionIdx = PikiAction::Guard;
		PRINT("guard mode %x\n", this);
		break;
	}

	mMode = newMode;
}

char* _standStr[] = { "GROUND", "TEKIPLAT", "PLAT", "AIR" };

char* _modeStr[] = {
	"FREE_MODE",   "FORMATION_MODE", "ATTACK_MODE",    "NUKU_MODE",      "GUARD_MODE",   "PICK_MODE",   "DECOY_MODE",
	"ARROW_MODE",  "CARRY_MODE",     "TRANSPORT_MODE", "ROPE_MODE",      "ENTER_MODE",   "EXIT_MODE",   "BREAKWALL_MODE",
	"MINE_MODE",   "KINOKO_MODE",    "BRIDGE_MODE",    "PUSHSTONE_MODE", "PUTBOMB_MODE", "RESCUE_MODE", "WEED_MODE",
	"PEBBLE_MODE", "BOMAKE_MODE",    "BO_MODE",        "WARRIOR_MODE",
};
static char* _colorNames[] = { "blue", "red", "yellow" };

/*
 * --INFO--
 * Address:	800CD418
 * Size:	000250
 */
void Piki::dump()
{
	// they probably used a lot more temps and a lot less ternaries, whatever.
	u32 badCompiler[4];

	rumbleMgr->stop();
	if (directDumpMode) {
		PRINT("--- piki %x (color=%s) info fl %d col %d---\n", this, _colorNames[mColor], mHappa, mColor);
		PRINT(" * state     (%s:%d)\n", mFSM->getCurrName(this), getState());
		PRINT(" * mode      (%s:%d)\n", _modeStr[mMode], mMode);
		PRINT(" * callable = %s\n", mIsCallable ? "true" : "false");

		// this feels like it should be a ternary but that spawns inline calls.
		char* actionName;
		if (mActiveAction->getCurrAction()) {
			actionName = mActiveAction->getCurrAction()->getName();
		} else {
			actionName = "no curr action";
		}
		PRINT(" * ai        (%s:%d)        suspend=%s\n", actionName, mActiveAction->mCurrActionIdx,
		      mActiveAction->mIsSuspended ? "true" : "false");
		PRINT(" * motion    <%s/%s>\n", mPikiAnimMgr.getUpperAnimator().getCurrentMotionName(),
		      mPikiAnimMgr.getLowerAnimator().getCurrentMotionName());

		if (flowCont.mNaviOnMap == 1) {
			char* naviName;
			if (mNavi) {
				naviName = (mNavi == naviMgr->getNavi(0)) ? "player1" : "player2";
			} else {
				naviName = "no-player";
			}

			PRINT(" * navi = %s : playerID = %d\n", naviName, mPlayerId);
		}

		PRINT(" aiSTOP = %s\n", isAIActive() ? "false" : "true");
		PRINT(" onground = %s\n", isCreatureFlag(CF_IsOnGround) ? "true" : "false");
		PRINT(" vel(%.1f,%.1f) velocity(%.1f,%.1f)\n", mVelocity.x, mVelocity.z, mTargetVelocity.x, mTargetVelocity.z);
		PRINT(" inDamage = %s\n", mIsBeingDamaged ? "true" : "false");
		PRINT(" flags = %x : isVisible=%s isAlive=%s isAtari=%s\n", isVisible() ? "true" : "false", isAlive() ? "true" : "false",
		      isAtari() ? "true" : "false");
		PRINT(" kinoko = %s\n", isKinoko() ? "yes" : "no");
		PRINT(" emotion = %d\n", mEmotion);
		static_cast<PikiState*>(getCurrState())->dump();
		if (mActiveAction->getCurrAction() && mMode == PikiMode::FormationMode) {
			ActCrowd* action = static_cast<ActCrowd*>(mActiveAction->getCurrAction());

			PRINT("<form> md %d koke %s route %s wait %s st %d", action->mMode, action->mIsKokeActive ? "Y" : "N",
			      action->mHasRoute ? "Y" : "N", action->mIsWaiting ? "Y" : "N", action->mFormationState);
		}

		PRINT(" _stickObject=%x(%d) : _stickToObject=%s\n", getStickObject(), getStickObject() ? getStickObject()->mObjType : -1,
		      mStickPart ? mStickPart->getTypeString() : "none");
		PRINT(" floorCollTri=%x\n", mFloorTri);
		PRINT(" standType = %s fluteBooking = %s\n", _standStr[getStandType()], mIsWhistlePending ? "true" : "-");
		PRINT(" wantToStick = %s\n", mWantToStick ? "true" : "false");

		// why not use the inline to get it, idk
		if (mActiveAction->mCurrActionIdx != -1) {
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].mAction->dump();
		}

	} else {
		PRINT("--- piki %x (color=%s) info --\n", this, _colorNames[mColor]);
		PRINT(" * state     (%s:%d)\n", mFSM->getCurrName(this), getState());
		PRINT(" * mode      (%s:%d)\n", _modeStr[mMode], mMode);
		PRINT(" * callable = %s\n", mIsCallable ? "true" : "false");

		// this feels like it should be a ternary but that spawns inline calls.
		char* actionName;
		if (mActiveAction->getCurrAction()) {
			actionName = mActiveAction->getCurrAction()->getName();
		} else {
			actionName = "no curr action";
		}
		PRINT(" * ai        (%s:%d)        suspend=%s\n", actionName, mActiveAction->mCurrActionIdx,
		      mActiveAction->mIsSuspended ? "true" : "false");
		PRINT(" * motion    <%s/%s>\n", mPikiAnimMgr.getUpperAnimator().getCurrentMotionName(),
		      mPikiAnimMgr.getLowerAnimator().getCurrentMotionName());

		if (flowCont.mNaviOnMap == 1) {
			char* naviName;
			if (mNavi) {
				naviName = (mNavi == naviMgr->getNavi(0)) ? "player1" : "player2";
			} else {
				naviName = "no-player";
			}

			PRINT(" * navi = %s : playerID = %d\n", naviName, mPlayerId);
		}

		PRINT(" aiSTOP = %s\n", isAIActive() ? "false" : "true");
		PRINT(" onground = %s\n", isCreatureFlag(CF_IsOnGround) ? "true" : "false");
		PRINT(" vel(%.1f,%.1f) velocity(%.1f,%.1f)\n", mVelocity.x, mVelocity.z, mTargetVelocity.x, mTargetVelocity.z);
		PRINT(" inDamage = %s\n", mIsBeingDamaged ? "true" : "false");
		PRINT(" flags = %x : isVisible=%s isAlive=%s isAtari=%s\n", isVisible() ? "true" : "false", isAlive() ? "true" : "false",
		      isAtari() ? "true" : "false");
		PRINT(" emotion = %d\n", mEmotion);
		static_cast<PikiState*>(getCurrState())->dump();
		PRINT(" _stickObject=%x(%d) : _stickToObject=%s\n", getStickObject(), getStickObject() ? getStickObject()->mObjType : -1,
		      mStickPart ? mStickPart->getTypeString() : "none");
		PRINT(" floorCollTri=%x\n", mFloorTri);
		PRINT(" standType = %s fluteBooking = %s\n", _standStr[getStandType()], mIsWhistlePending ? "true" : "-");
		PRINT(" wantToStick = %s\n", mWantToStick ? "true" : "false");

		// why not use the inline to get it, idk
		if (mActiveAction->mCurrActionIdx != -1) {
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].mAction->dump();
		}
	}
}
