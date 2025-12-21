#include "Piki.h"
#include "AIConstant.h"
#include "AIPerf.h"
#include "Boss.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "FlowController.h"
#include "GoalItem.h"
#include "ItemMgr.h"
#include "ItemObject.h"
#include "KMath.h"
#include "MapCode.h"
#include "MoviePlayer.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "Pellet.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "UfoItem.h"
#include "UtilityKando.h"
#include "WeedsItem.h"
#include "WorkObject.h"
#include "gameflow.h"
#include "teki.h"
#include "timers.h"
#include "zen/Math.h"

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
DEFINE_ERROR(43)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("piki");

/*
 * --INFO--
 * Address:	800C6558
 * Size:	000300
 */
bool Piki::isSafeMePos(immut Vector3f& pos)
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
	} else if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(PMUPDATE_FreePiki)) {
		return false;
	} else if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(PMUPDATE_FormationPiki)) {
		return false;
	} else if (!pikiMgr->isUpdating(PMUPDATE_WorkPiki)) {
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
					mPathBuffers[i].mDirection   = piki->mPathBuffers[i].mDirection;
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
		handle = routeMgr->getPathFinder('test')->findSyncOnyon(mSRT.t, mPathBuffers, sourceWaypointIndex, destinationType, isRetryAttempt);
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
	STACK_PAD_VAR(1); // some other temp, whatever.

	int traceRes = moveRouteTrace(p1);
	if (traceRes != 2) {
		return traceRes;
	}

	if (mUseAsyncPathfinding) {
		return 2;
	}

	Vector3f centre = mRouteTargetCreature->getCentre();
	centre.sub(mSRT.t);
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
bool Piki::initRouteTrace(immut Vector3f& targetPos, bool p2)
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
	routeMgr->findNearestEdgeAvoidOff(&wp1, &wp2, 'test', mSRT.t, onlyLand, true, false);

	WayPoint* nearestPikiWP;
	if (wp1 && wp2) {
		Vector3f wp1Dist = wp1->mPosition - mSRT.t;
		Vector3f wp2Dist = wp2->mPosition - mSRT.t;
		if (wp1Dist.length() > wp2Dist.length()) {
			nearestPikiWP = wp2;
		} else {
			nearestPikiWP = wp1;
		}
	} else {
		PRINT("gakkari desu ...\n");
		nearestPikiWP = routeMgr->findNearestWayPoint('test', mSRT.t, onlyLand);
	}

	WayPoint* nearestTargetWP = routeMgr->findNearestWayPoint('test', targetPos, false);
	mRouteStartPos            = mSRT.t;
	mRouteGoalPos             = targetPos;

	if (onlyLand) {
		PathFinder::setMode(PathFinderMode::AvoidWater);
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
	Sphere sphere(mSRT.t, 0.0f);
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
			Sphere sphere(mSRT.t, 0.0f);
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
			PRINT_GLOBAL("wait for r-handle");
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

	f32 ctrlRatio = crDir.DP(mSRT.t - cr0) / crDist;
	if (ctrlRatio < 0.0f) {
		ctrlRatio = 0.0f;
	}
	if (ctrlRatio > 1.0f) {
		ctrlRatio = 1.0f;
	}

	Vector3f dirToPath;
	dirToPath      = (ctrlRatio * crDist) * crDir + cr0;
	dirToPath      = dirToPath - mSRT.t;
	dirToPath.y    = 0.0f;
	f32 distToPath = dirToPath.normalise();

	f32 ctrlPtsWeight     = (1.0f - ctrlRatio) * crGetRadius(mCurrRoutePoint) + ctrlRatio * crGetRadius(mCurrRoutePoint + 1);
	f32 alignToPathWeight = absF(distToPath) / ctrlPtsWeight;
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
	seSystem->playPikiSound(SEF_PIKI_FIRED, mSRT.t);
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
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Attack;
		mActiveAction->mChildActions[PikiAction::Attack].initialise(target);
		mMode = PikiMode::AttackMode;
		break;

	case PIKISITCH_Unk2:
		ERROR("U CAN'T DO IT RIGHT !\n"); // LOL
		break;

	case PIKISITCH_Unk14:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Bou;
		mActiveAction->mChildActions[PikiAction::Bou].initialise(target);
		mMode = PikiMode::BoMode;
		break;

	case PIKISITCH_Unk9:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Transport;
		mActiveAction->mChildActions[PikiAction::Transport].initialise(target);
		mMode = PikiMode::TransportMode;
		break;

	case PIKISITCH_Unk10:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Rescue;
		mActiveAction->mChildActions[PikiAction::Rescue].initialise(target);
		mMode = PikiMode::RescueMode;
		break;

	case PIKISITCH_Unk11:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Weed;
		mActiveAction->mChildActions[PikiAction::Weed].initialise(target);
		mMode = PikiMode::WeedMode;
		break;

	case PIKISITCH_Unk13:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::BoMake;
		mActiveAction->mChildActions[PikiAction::BoMake].initialise(target);
		mMode = PikiMode::BomakeMode;
		break;

	case PIKISITCH_Unk12:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Stone;
		mActiveAction->mChildActions[PikiAction::Stone].initialise(target);
		mMode = PikiMode::PebbleMode;
		break;

	case PIKISITCH_Unk4:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Mine;
		mActiveAction->mChildActions[PikiAction::Mine].initialise(target);
		mMode = PikiMode::MineMode;
		break;

	case PIKISITCH_Unk3:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::PickItem;
		mActiveAction->mChildActions[PikiAction::PickItem].initialise(target);
		mMode = PikiMode::PickMode;
		break;

	case PIKISITCH_Unk7:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Bridge;
		mActiveAction->mChildActions[PikiAction::Bridge].initialise(target);
		mMode = PikiMode::BridgeMode;
		break;

	case PIKISITCH_Unk8:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
		mActiveAction->abandon(nullptr);
		mActiveAction->mCurrActionIdx = PikiAction::Push;
		mActiveAction->mChildActions[PikiAction::Push].initialise(target);
		mMode = PikiMode::PushstoneMode;
		break;

	case PIKISITCH_Unk6:
		seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
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
	f32 minTestDist = pikiMgr->mPikiParms->mPikiParms.mIdleAttackSearchRange();

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
	minTestDist            = pikiMgr->mPikiParms->mPikiParms.mIdleWorkSearchRange();
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
				STACK_PAD_VAR(1);
				for (int i = 0; i < flagPart->getChildCount(); i++) {
					checker.update();
					CollPart* childPart = flagPart->getChildAt(i);
					Vector3f partDir    = childPart->mCentre - mSRT.t;
					f32 objDist         = partDir.length() - childPart->mRadius - getCentreSize();
					if (objDist <= minTestDist) {
						minTestDist = objDist;
						wallTarget  = obj;
					}
				}
			}
		} else if (obj->mObjType == OBJTYPE_GrassGen && obj->isAlive()) {
			f32 objDist = centreDist(this, obj);
			if (objDist <= minTestDist + obj->getCentreSize()) {
				GrassGen* grassGen = static_cast<GrassGen*>(obj);
				if (grassGen->workable()) {
					minTestDist = objDist;
					grassTarget = obj;
				}
			}

		} else if (obj->mObjType == OBJTYPE_RockGen && obj->isAlive()) {
			f32 objDist = centreDist(this, obj);
			if (objDist <= minTestDist + obj->getCentreSize()) {
				RockGen* rockGen = static_cast<RockGen*>(obj);
				if (rockGen->workable()) {
					minTestDist  = objDist;
					pebbleTarget = obj;
				}
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
	minTestDist            = pikiMgr->mPikiParms->mPikiParms.mIdleWorkSearchRange();
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

	minTestDist = pikiMgr->mPikiParms->mPikiParms.mIdleWorkSearchRange();
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
	minTestDist          = pikiMgr->mPikiParms->mPikiParms.mIdleAttackSearchRange();

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
		if (workDist < test && !workObj->isFinished() && workObj->workable(mSRT.t)) {
			minTestDist = workDist;
			workTarget  = workObj;
		}
	}

	if (workTarget) {
		WorkObject* workObj = static_cast<WorkObject*>(workTarget);
		if (workObj->workable(mSRT.t)) {
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
		minTestDist             = pikiMgr->mPikiParms->mPikiParms.mIdleAttackSearchRange();
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
		return !static_cast<PikiPushState*>(getCurrState())->mIsFinishing;
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
bool Piki::stimulate(immut Interaction& interaction)
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
void Piki::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	if (mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == 56 && event.mEventType == KEY_PlayEffect) {
		EffectParm parm(mSRT.t);
		UtEffectMgr::cast(KandoEffect::Bubbles, parm);
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
	if (mGroundTriangle) {
		attr = MapCode::getAttribute(mGroundTriangle);
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
		if (obj && obj->mGroundTriangle && MapCode::getAttribute(obj->mGroundTriangle) == ATTR_Water) {
			if (absF(obj->mSRT.t.y - mSRT.t.y) < 10.0f) {
				isDrownSurface = true;
			}
		}
	}

	if (isDrownSurface && isAlive() && state != PIKISTATE_Dead && state != PIKISTATE_Dying && state != PIKISTATE_Pressed
	    && state != PIKISTATE_WaterHanged) {
		seSystem->playSoundDirect(5, SEW_PIKI_WATERDROP, mSRT.t);
		startMotion(PaniMotionInfo(PIKIANIM_TYakusui, this), PaniMotionInfo(PIKIANIM_TYakusui));
		mFSM->transit(this, PIKISTATE_Drown);
		EffectParm rippleParm(&mSRT.t);
		EffectParm parm(mSRT.t);
		rippleParm.mScale = 2.0f;

		mRippleEffect->emit(rippleParm);
		UtEffectMgr::cast(KandoEffect::Bubbles, parm);
		mInWaterTimer = 1;
		return;
	}

	if (mMode == PikiMode::GuardMode) {
		mSRT.t.y = 0.0f;
		setCreatureFlag(CF_IsOnGround);
		mVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	800CA9D8
 * Size:	000234
 */
void Piki::startMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
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
		Creature* target = mLookAtCreature.getPtr();
		if (!isLooking()) {
			if (!target) {
				int rand = gsys->getRand(1.0f) * 2.0f;
				if (rand == 0) {
					startHimaLook(&mNavi->mCursorWorldPos);
				} else {
					startHimaLook(&mNavi->mNaviLightPosition);
				}
				return;
			}

			startHimaLook(&target->mSRT.t);
			mLookAtCreature.set(target);
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
				startHimaLook(&target->mSRT.t);
			}

			if (isStickTo()) {
				PRINT("++++++++++++ PIKI STICK TO AND START LOOK !\n");
			}

			mLookAtCreature.set(target);
		}
		return;

	default:
		finishLook();
		return;
	}

	STACK_PAD_VAR(2); // idk what this is from
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
void Piki::swapMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
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
void Piki::checkBridgeWall(Creature* object, immut Vector3f& direction)
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
			if (action && static_cast<ActCrowd*>(action)->mState == ActCrowd::STATE_Formed) {
				WorkObject* workObj = static_cast<WorkObject*>(object);
				if (workObj->isBridge()) {
					Bridge* bridge = static_cast<Bridge*>(workObj);
					f32 zComp      = direction.DP(bridge->getBridgeZVec());
					if (bridge->mDoUseJointSegments && zComp < -0.8f && !bridge->isFinished()) {
						PRINT("** BRIDGE AI START\n");
						seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
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
void Piki::collisionCallback(immut CollEvent& event)
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
				if (action && action->mState != ActCrowd::STATE_Formed) {
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
		if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
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
		if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
			mActiveAction->abandon(nullptr);
			mActiveAction->mCurrActionIdx = PikiAction::Attack;
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].initialise(collider);
			mMode = PikiMode::AttackMode;
			return;
		}
	}

	if (distCheck && collider->isSluice() && mMode == PikiMode::FormationMode && collider->isAlive()) {
		ActCrowd* crowd = static_cast<ActCrowd*>(mActiveAction->getCurrAction());
		if (collPart->getID().match('gate') && crowd && crowd->mState == ActCrowd::STATE_Formed) {
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
				if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
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
			if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
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
			if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
				seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
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
		if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
			seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
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
			if (crowd && crowd->mState == ActCrowd::STATE_Formed) {
				seSystem->playPikiSound(SEF_PIKI_FIND, mSRT.t);
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
		(mMode); // Probably a PRINT or ERROR here, but this isn't in the DLL
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
	mLookatPosPtr = nullptr;
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
	mDeathTimer      = 0.0f;
	mSearchBuffer.init(mPikiSearchData, 6);
	_68              = 1;
	mPanickedEffect  = new PermanentEffect();
	mIsPanicked      = false;
	mPushTargetPiki  = 0;
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
void Piki::setSpeed(f32 speedRatio, immut Vector3f& direction)
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
	return pikiMgr->mPikiParms->mPikiParms.mInvMass();
}

/*
 * --INFO--
 * Address:	800CBFDC
 * Size:	000068
 */
void Piki::resetPosition(immut Vector3f& pos)
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
	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mRouteHandle         = 0;
	mUseAsyncPathfinding = false;
	_528                 = 0.0f;
	mLookAtCreature.clear();
	mLookatPosPtr = nullptr;
	mIsLooking    = false;
	forceFinishLook();
	mEmotion          = PikiEmotion::None;
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
	_519              = false;
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
	mHealth = pikiMgr->mPikiParms->mPikiParms.mPikiMaxHealth();
	mFSM->transit(this, PIKISTATE_Normal);
	mFloweringTimer = 0;
	mFSM->transit(this, PIKISTATE_Normal);
	mPikiSize = pikiMgr->mPikiParms->mPikiParms.mMinPikiSize()
	          + (pikiMgr->mPikiParms->mPikiParms.mMaxPikiSize() - pikiMgr->mPikiParms->mPikiParms.mMinPikiSize()) * gsys->getRand(1.0f);
	mOldFaceDirection = mFaceDirection;
	initBirth();
	mRouteDestinationIndex = -1;
	mRouteSourceIndex      = -1;
	mRouteTargetCreature   = nullptr;
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

	Creature* target = mLookAtCreature.getPtr();
	if (target && (!target->isVisible() || !target->isAlive())) {
		mLookAtCreature.reset();
		target = nullptr;
	}

	f32 minDist = 128000.0f;
	if (target) {
		minDist = qdist2(mSRT.t.x, mSRT.t.z, target->mSRT.t.x, target->mSRT.t.z) - target->getBoundingSphereRadius();
		if (minDist > 200.0f) {
			mLookAtCreature.reset();
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
			f32 tekiDist = qdist2(mSRT.t.x, mSRT.t.z, teki->mSRT.t.x, teki->mSRT.t.z) - teki->getBoundingSphereRadius();
			if (tekiDist < minDist) {
				newTarget = teki;
				minDist   = tekiDist;
			}
		}
	}

	if (target != newTarget && gsys->getRand(1.0f) > 0.2f) {
		if (target) {
			mLookAtCreature.reset();
		}
		if (gsys->getRand(1.0f) > 0.2f) {
			newTarget = mNavi;
		}

		mLookAtCreature.set(newTarget);
	}
}

/*
 * --INFO--
 * Address:	800CC6D4
 * Size:	000050
 */
void Piki::doAnimation()
{
	updateWalkAnimation();
	mLastAnimPosition = mSRT.t;
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

		Vector3f sep = mSRT.t - mLastAnimPosition;
		sep.y        = 0.0f;
		f32 speed    = sep.length() / gsys->getFrameTime();

		int lowerMotionID = mPikiAnimMgr.getLowerAnimator().getCurrentMotionIndex();
		if (lowerMotionID != PIKIANIM_Wait && lowerMotionID != PIKIANIM_Walk && lowerMotionID != PIKIANIM_Asibumi
		    && lowerMotionID != PIKIANIM_Run && lowerMotionID != PIKIANIM_Nigeru) {
			mMotionSpeed = 30.0f;
			return;
		}

		int upperMotionID = mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex();
		f32 angleDiff     = absF(mFaceDirection - mOldFaceDirection);
		doMotionBlend();
		int newMotionID;
		if (speed < pikiMgr->mPikiParms->mPikiParms.mStepSpeedThreshold()) {
			newMotionID = PIKIANIM_Wait;
			if (angleDiff > 0.01f) {
				newMotionID = PIKIANIM_Asibumi;
			}
			speed = 30.0f; // waiting + turning always at 30 fps
		} else if (speed < pikiMgr->mPikiParms->mPikiParms.mWalkSpeedThreshold()) {
			newMotionID = PIKIANIM_Asibumi;
			speed       = 30.0f; // stepping always at 30 fps
		} else if (speed < pikiMgr->mPikiParms->mPikiParms.mRunSpeedThreshold()) {
			newMotionID = PIKIANIM_Walk;
			f32 diff    = speed - pikiMgr->mPikiParms->mPikiParms.mWalkSpeedThreshold();
			f32 ratio
			    = diff / (pikiMgr->mPikiParms->mPikiParms.mRunSpeedThreshold() - pikiMgr->mPikiParms->mPikiParms.mWalkSpeedThreshold());

			// gradually scale anim speed from mMinWalkAnimSpeed to mMaxWalkAnimSpeed
			speed = pikiMgr->mPikiParms->mPikiParms.mMinWalkAnimSpeed()
			      + (pikiMgr->mPikiParms->mPikiParms.mMaxWalkAnimSpeed() - pikiMgr->mPikiParms->mPikiParms.mMinWalkAnimSpeed()) * ratio;

		} else if (speed < pikiMgr->mPikiParms->mPikiParms.mEscapeSpeedThreshold()) {
			newMotionID = PIKIANIM_Run;
			f32 diff    = speed - pikiMgr->mPikiParms->mPikiParms.mRunSpeedThreshold();
			f32 ratio
			    = diff / (pikiMgr->mPikiParms->mPikiParms.mEscapeSpeedThreshold() - pikiMgr->mPikiParms->mPikiParms.mRunSpeedThreshold());

			// gradually scale anim speed from mMinRunAnimSpeed to mMaxRunAnimSpeed
			speed = pikiMgr->mPikiParms->mPikiParms.mMinRunAnimSpeed()
			      + (pikiMgr->mPikiParms->mPikiParms.mMaxRunAnimSpeed() - pikiMgr->mPikiParms->mPikiParms.mMinRunAnimSpeed()) * ratio;

		} else {
			newMotionID = PIKIANIM_Nigeru;
			speed       = pikiMgr->mPikiParms->mPikiParms.mEscapeAnimSpeed(); // escape always at set anim speed
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

int stupid_pikiRealAI()
{
	int x;
	return x;
}

void Piki::realAI()
{

	// Brocoli: This is abhorrently stupid, why this works should be investigated.
	stupid_pikiRealAI();
	stupid_pikiRealAI();
	stupid_pikiRealAI();
	stupid_pikiRealAI();

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
			PRINT(" int=%d int2=%d real=%f real1=%f real2=%f\n", aiC->mCurrAnimId, aiC->mCounter, aiC->mCurrentItemHealth, aiC->_2DC,
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
	if (mGroundTriangle) {
		attr = MapCode::getAttribute(mGroundTriangle);
	}

	bool isInWater = false;
	if (attr == ATTR_Water) {
		isInWater = true;
	} else if (isStickTo()) {
		Creature* stickObj = getStickObject();
		if (stickObj && stickObj->mGroundTriangle && MapCode::getAttribute(stickObj->mGroundTriangle) == ATTR_Water
		    && absF(stickObj->mSRT.t.y - mSRT.t.y) < 10.0f) {
			isInWater = true;
		}
	}

	if (isInWater && getState() != PIKISTATE_WaterHanged) {
		if (mInWaterTimer == 0) {
			EffectParm rippleParm(&mShadowPos);
			EffectParm castParm(mShadowPos);
			mRippleEffect->emit(rippleParm);
			UtEffectMgr::cast(KandoEffect::Bubbles, castParm);
			seSystem->playSoundDirect(5, SEW_PIKI_WATERDROP, mSRT.t);
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
			if (mInWaterTimer >= int(gsys->getRand(1.0f) * pikiMgr->mPikiParms->mPikiParms.mRandStartDrownFrames())
			                         + pikiMgr->mPikiParms->mPikiParms.mMinStartDrownFrames()) {
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
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
immut char* Piki::getCurrentMotionName()
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

		gsys->mTimer->start("ai exec", true);
		if (AIPerf::optLevel <= 2 || mOptUpdateContext.updatable()) {
			mActiveAction->exec();
		}
		gsys->mTimer->stop("ai exec");
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
	STACK_PAD_VAR(6); // idk
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

// This seems to be an outdated reference to the PikiStateID enum.
const char* states_str[] = {
	"NORMAL",    "GROW",   "BURY",   "NUKARE",  "DYING",   "DEAD",    "BUTUKARI",
	"TRANSFORM", "GROWUP", "ABSORB", "ILLEGAL", "ILLEGAL", "ILLEGAL", "ILLEGAL",
};

const char* _standStr[STANDTYPE_COUNT] = {
	"GROUND",
	"TEKIPLAT",
	"PLAT",
	"AIR",
};

const char* _modeStr[PikiMode::COUNT] = {
	"FREE_MODE",   "FORMATION_MODE", "ATTACK_MODE",    "NUKU_MODE",      "GUARD_MODE",   "PICK_MODE",   "DECOY_MODE",
	"ARROW_MODE",  "CARRY_MODE",     "TRANSPORT_MODE", "ROPE_MODE",      "ENTER_MODE",   "EXIT_MODE",   "BREAKWALL_MODE",
	"MINE_MODE",   "KINOKO_MODE",    "BRIDGE_MODE",    "PUSHSTONE_MODE", "PUTBOMB_MODE", "RESCUE_MODE", "WEED_MODE",
	"PEBBLE_MODE", "BOMAKE_MODE",    "BO_MODE",        "WARRIOR_MODE",
};

static const char* _colorNames[PikiColorCount] = {
	"blue",
	"red",
	"yellow",
};

/*
 * --INFO--
 * Address:	800CD418
 * Size:	000250
 */
void Piki::dump()
{
	// they probably used a lot more temps and a lot less ternaries, whatever.
	STACK_PAD_VAR(4);

	rumbleMgr->stop();
	if (directDumpMode) {
		PRINT("--- piki %x (color=%s) info fl %d col %d---\n", this, _colorNames[mColor], mHappa, mColor);
		PRINT(" * state     (%s:%d)\n", mFSM->getCurrName(this), getState());
		PRINT(" * mode      (%s:%d)\n", _modeStr[mMode], mMode);
		PRINT(" * callable = %s\n", mIsCallable ? "true" : "false");

		// this feels like it should be a ternary but that spawns inline calls.
		const char* actionName;
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
			const char* naviName;
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

			PRINT("<form> md %d koke %s route %s wait %s st %d" MISSING_NEWLINE, action->mMode, action->mIsTripping ? "Y" : "N",
			      action->mHasRoute ? "Y" : "N", action->mIsWaiting ? "Y" : "N", action->mState);
		}

		PRINT(" _stickObject=%x(%d) : _stickToObject=%s\n", getStickObject(), getStickObject() ? getStickObject()->mObjType : -1,
		      mStickPart ? mStickPart->getTypeString() : "none");
		PRINT(" floorCollTri=%x\n", mGroundTriangle);
		PRINT(" standType = %s fluteBooking = %s\n", _standStr[getStandType()], mIsWhistlePending ? "true" : "-");
		PRINT(" wantToStick = %s\n", mWantToStick ? "true" : "false");

		// why not use the inline to get it, idk
		if (mActiveAction->mCurrActionIdx != PikiAction::NOACTION) {
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].mAction->dump();
		}

	} else {
		PRINT("--- piki %x (color=%s) info --\n", this, _colorNames[mColor]);
		PRINT(" * state     (%s:%d)\n", mFSM->getCurrName(this), getState());
		PRINT(" * mode      (%s:%d)\n", _modeStr[mMode], mMode);
		PRINT(" * callable = %s\n", mIsCallable ? "true" : "false");

		// this feels like it should be a ternary but that spawns inline calls.
		const char* actionName;
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
			const char* naviName;
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
		PRINT(" floorCollTri=%x\n", mGroundTriangle);
		PRINT(" standType = %s\n", _standStr[getStandType()]);
		PRINT(" wantToStick = %s\n", mWantToStick ? "true" : "false");

		// why not use the inline to get it, idk
		if (mActiveAction->mCurrActionIdx != PikiAction::NOACTION) {
			mActiveAction->mChildActions[mActiveAction->mCurrActionIdx].mAction->dump();
		}
	}
}
