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
DEFINE_ERROR();

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
	if (!playerState->isTutorial() && !playerState->mDemoFlags.isFlag(16) && stage <= 1) {
		playerState->mDemoFlags.setFlag(16, nullptr);
		return true;
	}

	// red onion check
	if (stage == 0 && !playerState->mDemoFlags.isFlag(0)) {
		Creature* goal = (Creature*)itemMgr->getContainer(1);
		if (goal && qdist2(goal, this) <= demoParms->mParms.mOnionBootTriggerRadius()) {
			playerState->mDemoFlags.setFlag(0, goal);
			return true;
		}
	}

	// blue onion check
	if (stage == 2 && !playerState->mDemoFlags.isFlag(2)) {
		GoalItem* goal = itemMgr->getContainer(0);
		if (goal && qdist2(goal, this) <= demoParms->mParms.mOnionBootTriggerRadius()) {
			playerState->mDemoFlags.setFlag(2, goal);
			goal->setMotionSpeed(30.0f);
			return true;
		}
	}

	// yellow onion check
	if (stage == 1 && !playerState->mDemoFlags.isFlag(1)) {
		GoalItem* goal = itemMgr->getContainer(2);
		if (goal && qdist2(goal, this) <= demoParms->mParms.mOnionBootTriggerRadius()) {
			playerState->mDemoFlags.setFlag(1, goal);
			goal->setMotionSpeed(30.0f);
			return true;
		}
	}

	// pikmin seed in ground cutscene
	if (!playerState->mDemoFlags.isFlag(3) && playerState->isTutorial()) {
		PikiHeadItem* item = (PikiHeadItem*)itemMgr->getPikiHeadMgr()->findClosest(mPosition, nullptr);
		if (item && item->mFloorTri && item->getCurrState()->getID() == 6
		    && qdist2(item, this) <= demoParms->mParms.mSeedDemoTriggerRadius()) {
			playerState->mDemoFlags.setFlag(3, item);
			PRINT("** SET TIMER %.1f\n", demoParms->mParms.mSeedDemoTriggerRadius());
			playerState->mDemoFlags.setTimer(demoParms->mParms.mSeedDemoWaitTime(), 7, item);
			return true;
		}
	}

	// find main engine
	if (stage == 0 && !playerState->mDemoFlags.isFlag(12)) {
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
					playerState->mDemoFlags.setFlag(12, obj);
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
				int id = PelletMgr::getUfoIndexFromID(obj->mConfig->_2C.mId);
				if (!playerState->mDemoFlags.isFlag(id + 32)) {
					gameflow.mMovieType    = 3;
					gameflow.mMovieInfoNum = id;
					playerState->mDemoFlags.setFlag(id + 32, obj);
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
	if (mPikiUpdateContext.updatable() && flowCont.mCurrentStage->mStageID == 0 && !playerState->mDemoFlags.isFlag(12)) {
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
					playerState->mDemoFlags.setFlag(12, obj);
				}
			}
		}
	}
}
