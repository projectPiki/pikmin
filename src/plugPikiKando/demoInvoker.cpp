#include "Navi.h"
#include "Piki.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "Pellet.h"
#include "ItemMgr.h"
#include "GoalItem.h"
#include "gameflow.h"
#include "PikiHeadItem.h"
#include "FlowController.h"
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
DEFINE_PRINT("demoInvoker");

/*
 * --INFO--
 * Address:	80082818
 * Size:	0006D8
 */
bool Navi::demoCheck()
{
	int stage = flowCont.mCurrentStage->mStageID;
	if (!playerState->isTutorial() && !playerState->mDemoFlags.isFlag(DEMOFLAG_OnyonMenuInfo) && stage <= STAGE_Forest) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_OnyonMenuInfo, nullptr);
		return true;
	}

	// red onion check
	if (stage == STAGE_Practice && !playerState->mDemoFlags.isFlag(DEMOFLAG_DiscoverRedOnyon)) {
		GoalItem* redOnyon = itemMgr->getContainer(Red);
		if (redOnyon && qdist2(redOnyon, this) <= demoParms->mParms.mOnionBootTriggerRadius()) {
			playerState->mDemoFlags.setFlag(DEMOFLAG_DiscoverRedOnyon, redOnyon);
			return true;
		}
	}

	// blue onion check
	if (stage == STAGE_Cave && !playerState->mDemoFlags.isFlag(DEMOFLAG_DiscoverBlueOnyon)) {
		GoalItem* blueOnyon = itemMgr->getContainer(Blue);
		if (blueOnyon && qdist2(blueOnyon, this) <= demoParms->mParms.mOnionBootTriggerRadius()) {
			playerState->mDemoFlags.setFlag(DEMOFLAG_DiscoverBlueOnyon, blueOnyon);
			blueOnyon->setMotionSpeed(30.0f);
			return true;
		}
	}

	// yellow onion check
	if (stage == STAGE_Forest && !playerState->mDemoFlags.isFlag(DEMOFLAG_DiscoverYellowOnyon)) {
		GoalItem* yellowOnyon = itemMgr->getContainer(Yellow);
		if (yellowOnyon && qdist2(yellowOnyon, this) <= demoParms->mParms.mOnionBootTriggerRadius()) {
			playerState->mDemoFlags.setFlag(DEMOFLAG_DiscoverYellowOnyon, yellowOnyon);
			yellowOnyon->setMotionSpeed(30.0f);
			return true;
		}
	}

	// pikmin seed in ground cutscene
	if (!playerState->mDemoFlags.isFlag(DEMOFLAG_ApproachSeed) && playerState->isTutorial()) {
		PikiHeadItem* item = (PikiHeadItem*)itemMgr->getPikiHeadMgr()->findClosest(mPosition, nullptr);
		if (item && item->mGroundTriangle && item->getCurrState()->getID() == 6
		    && qdist2(item, this) <= demoParms->mParms.mSeedDemoTriggerRadius()) {
			playerState->mDemoFlags.setFlag(DEMOFLAG_ApproachSeed, item);
			PRINT("** SET TIMER %.1f\n", demoParms->mParms.mSeedDemoTriggerRadius());
			playerState->mDemoFlags.setTimer(demoParms->mParms.mSeedDemoWaitTime(), DEMOFLAG_NoPikminTimeout, item);
			return true;
		}
	}

	// find main engine
	if (stage == STAGE_Practice && !playerState->mDemoFlags.isFlag(DEMOFLAG_ApproachEngine)) {
		Iterator it(pelletMgr);
		f32 maxDist = demoParms->mParms.mDemoTriggerRadius();
		CI_LOOP(it)
		{
			Pellet* obj = (Pellet*)(*it);
			if (obj->mConfig->mPelletType() == PELTYPE_UfoPart) {
				Vector3f diff = obj->mPosition - mPosition;
				f32 len       = sqrtf(diff.x * diff.x + diff.z * diff.z);
				len -= obj->getBottomRadius();
				if (len <= maxDist) {
					playerState->mDemoFlags.setFlag(DEMOFLAG_ApproachEngine, obj);
					return true;
				}
			}
		}
	}

	// find other ship parts
	Iterator it(pelletMgr);
	f32 maxDist = demoParms->mParms.mDemoTriggerRadius();
	CI_LOOP(it)
	{
		Pellet* obj = (Pellet*)(*it);
		if (obj->mConfig->mPelletType() == PELTYPE_UfoPart && obj->onGround()) {
			Vector3f diff = obj->mPosition - mPosition;
			f32 len       = sqrtf(diff.x * diff.x + diff.z * diff.z);
			len -= obj->getBottomRadius();
			if (len <= maxDist) {
				int id = PelletMgr::getUfoIndexFromID(obj->mConfig->mModelId.mId);
				if (!playerState->mDemoFlags.isFlag(id + DEMOFLAG_UfoPartDiscoveryOffset)) {
					gameflow.mMovieType    = 3;
					gameflow.mMovieInfoNum = id;
					playerState->mDemoFlags.setFlag(id + DEMOFLAG_UfoPartDiscoveryOffset, obj);
					return true;
				}
			}
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	80082EF0
 * Size:	00024C
 */
void Piki::demoCheck()
{
	// pikmin also trigger the approach engine cutscene - can't avoid it by throwing/csticking
	if (mPikiUpdateContext.updatable() && flowCont.mCurrentStage->mStageID == STAGE_Practice
	    && !playerState->mDemoFlags.isFlag(DEMOFLAG_ApproachEngine)) {
		Iterator it(pelletMgr);
		f32 maxDist = demoParms->mParms.mDemoTriggerRadius();
		CI_LOOP(it)
		{
			Pellet* obj = (Pellet*)(*it);
			if (obj->mConfig->mPelletType() == PELTYPE_UfoPart) {
				Vector3f diff = obj->mPosition - mPosition;
				f32 len       = sqrtf(diff.x * diff.x + diff.z * diff.z);
				len -= obj->getBottomRadius();
				if (len <= maxDist) {
					playerState->mDemoFlags.setFlag(DEMOFLAG_ApproachEngine, obj);
				}
			}
		}
	}
}
