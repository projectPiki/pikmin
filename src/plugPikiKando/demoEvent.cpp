#include "Demo.h"
#include "Traversable.h"
#include "gameflow.h"
#include "PikiMgr.h"
#include "ItemMgr.h"
#include "GoalItem.h"
#include "NaviMgr.h"
#include "UfoItem.h"
#include "GameStat.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "PlayerState.h"
#include "DebugLog.h"

DemoEventMgr* demoEventMgr;

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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
char* DemoEventMgr::getEventName(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* DemoEventMgr::getSenderName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008313C
 * Size:	000004
 */
DemoEventMgr::DemoEventMgr()
{
}

/*
 * --INFO--
 * Address:	80083140
 * Size:	00044C
 */
void DemoEventMgr::act(int cmd, int type)
{
	switch (cmd) {
	case 5:
		switch (type) {
		case 0:
			gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
			break;

		case 1:
			int count = 0;
			Iterator it(pikiMgr);
			CI_LOOP(it)
			{
				Piki* piki = (Piki*)(*it);
				if (piki->isAlive()) {
					GoalItem* goal = itemMgr->getContainer(piki->mColor);
					if (goal) {
						goal->enterGoal(piki);
						count++;
					}
				}
			}
			PRINT("***** FORCE ENTERPIKIS %d\n", count);
			break;
		}
		break;
	case 0:
		switch (type) {
		case 0:
			naviMgr->getNavi()->enterAllPikis();
			break;
		}
		break;
	case 1:
		UfoItem* ufo = itemMgr->getUfo();
		if (ufo) {
			switch (type) {
			case 0:
				ufo->startConeEffect(0);
				break;
			case 4:
				ufo->startConeEffect(1);
				break;
			case 5:
				ufo->startConeEffect(2);
				break;
			case 6:
				ufo->finishConeEffect();
				ufo->setSpotActive(false);
				playerState->setNavi(true);
				Navi* navi = naviMgr->getNavi();
				if (navi) {
					PRINT("**** RIDE UFO \n");
					navi->rideUfo();
				}
				break;
			case 1:
				ufo->startTakeoff();
				pikiMgr->dumpAll();
				break;
			case 2:
				ufo->startLevelFlag(playerState->mShipUpgradeLevel);
				break;
			case 3:
				PRINT("__________________________________________________\n");
				PRINT("******************* START YOZORA *****************\n");
				PRINT("__________________________________________________\n");
				ufo->startYozora();
				break;
			case 7:
				PRINT("__________________________________________________\n");
				PRINT("******************* START GALAXY *****************\n");
				PRINT("__________________________________________________\n");
				ufo->startGalaxy();
				break;
			}
		}
		break;
	case 2:
	case 3:
	case 4:
		int goalID     = cmd - 2;
		GoalItem* goal = itemMgr->getContainer(goalID);
		if (goal) {
			switch (type) {
			case 0:
				goal->mCurrAnimId++;
				goal->emitPiki();
				break;
			case 2:
				goal->startConeShrink();
				break;
			case 4:
				if (playerState->hasContainer(goalID + 3)) {
					goal->startConeEmit();
				}
				break;
			case 1:
				if (playerState->hasContainer(goalID)) {
					goal->startTakeoff();
				}
				break;
			case 3:
				if (playerState->hasContainer(goalID)) {
					goal->startLand();
				}
				break;
			case 5:
				PRINT("boot onion\n");
				goal->startBoot();
				playerState->setContainer(goalID + 3);
				if (playerState->isTutorial() && playerState->mShipEffectPartFlag & 8) {
					naviMgr->getNavi();
					playerState->mShipEffectPartFlag &= ~8;
					cameraMgr->mCamera->finishMotion();
					cameraMgr->mCamera->_30 = 1;
					cameraMgr->mCamera->startMotion(1, 0);
					PRINT("*** FINISH MOTION \n");
				}
				break;
			case 6:
				if (playerState->hasContainer(goalID) && GameStat::allPikis[goalID] == 0) {
					PRINT("***** SUPPLY 1 PiKI (COLOR = %d)\n", goalID);
					playerState->mResultFlags.setOn(RESFLAG_PikminSeedStageUp);
					goal->mCurrAnimId++;
					goal->emitPiki();
				}
				break;
			}
		}
		break;
	}

	STACK_PAD_VAR(2);
}
