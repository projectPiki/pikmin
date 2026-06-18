#include "DebugLog.h"
#include "Demo.h"
#include "GameStat.h"
#include "GoalItem.h"
#include "ItemMgr.h"
#include "NaviMgr.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "Traversable.h"
#include "UfoItem.h"
#include "gameflow.h"

/**
 * @note: Fabricated
 */
BEGIN_ENUM_TYPE(DemoEventSender)
enum {
	Navi,
	UFO,
	BluOnion,
	RedOnion,
	YelOnion,
	Game,
} END_ENUM_TYPE;

/**
 * @note: Fabricated
 */
BEGIN_ENUM_TYPE(DemoEventGame)
enum {
	DayEnd,
	EnterPikis,
} END_ENUM_TYPE;

/**
 * @note: Fabricated
 */
BEGIN_ENUM_TYPE(DemoEventNavi)
enum {
	Fue,
} END_ENUM_TYPE;

/**
 * @note: Fabricated
 */
BEGIN_ENUM_TYPE(DemoEventUFO)
enum {
	SuckNavi,
	Takeoff,
	Henka,
	BGStart,
	SuckNaviDown,
	SuckNaviZERO,
	SuckFinish,
	GalaxStart,
} END_ENUM_TYPE;

/**
 * @note: Fabricated
 */
BEGIN_ENUM_TYPE(DemoEventOnion)
enum {
	EmitPiki,
	Takeoff,
	EraseCone,
	Land,
	EmitCone,
	Boot,
	BonusPiki,
} END_ENUM_TYPE;

/**
 * @note: Fabricated
 */
struct DemoEventInfo {
	int mIndex;            // _00
	immut char* mName;     // _04, sender name in `infos`, event name in its children.
	DemoEventInfo* mChild; // _08
};

static DemoEventInfo gameInfos[] = {
	{ DemoEventGame::DayEnd, "dayend" },
	{ DemoEventGame::EnterPikis, "enterPikis" },
	{ -1, "end" },
};

static DemoEventInfo naviInfos[] = {
	{ DemoEventNavi::Fue, "fue" },
	{ -1, "end" },
};

static DemoEventInfo ufoInfos[] = {
	{ DemoEventUFO::SuckNavi, "SuckNavi" },
	{ DemoEventUFO::Takeoff, "Takeoff" },
	{ DemoEventUFO::Henka, "Henka" },
	{ DemoEventUFO::BGStart, "BG Start" },
	{ DemoEventUFO::SuckNaviDown, "SuckNaviDown" },
	{ DemoEventUFO::SuckNaviZERO, "SuckNaviZERO" },
	{ DemoEventUFO::SuckFinish, "Suck Finish" },
	{ DemoEventUFO::GalaxStart, "Galax Start" },
	{ -1, "end" },

};

static DemoEventInfo onionInfos[] = {
	{ DemoEventOnion::EmitPiki, "EmitPiki" },   { DemoEventOnion::Takeoff, "Takeoff" },
	{ DemoEventOnion::EraseCone, "EraseCone" }, { DemoEventOnion::Land, "Land" },
	{ DemoEventOnion::EmitCone, "EmitCone" },   { DemoEventOnion::Boot, "Boot" },
	{ DemoEventOnion::BonusPiki, "BonusPiki" }, { -1, "end" },
};

static DemoEventInfo infos[] = {
	{ DemoEventSender::Navi, "NAVI", naviInfos },           { DemoEventSender::UFO, "UFO", ufoInfos },
	{ DemoEventSender::BluOnion, "BLU_ONION", onionInfos }, { DemoEventSender::RedOnion, "RED_ONION", onionInfos },
	{ DemoEventSender::YelOnion, "YEL_ONION", onionInfos }, { DemoEventSender::Game, "GAME", gameInfos },
};

static immut char* noNames[] = {
	"0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10", "11", "12", "13", "14", "15",
	"16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31",
};

DemoEventMgr* demoEventMgr;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("demoEvent")

/**
 * @todo: Documentation
 * @note UNUSED Size: 000090 (Matching by size)
 */
immut char* DemoEventMgr::getEventName(int sender, int event)
{
	DemoEventInfo* info = infos[sender].mChild;
	if (!info) {
		return noNames[event];
	}
	for (int i = 0; i < event; ++i) {
		if (info[i].mIndex == -1) {
			return noNames[event];
		}
	}
	if (info[event].mIndex == -1) {
		return noNames[event];
	}
	return info[event].mName;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018 (Matching by size)
 */
immut char* DemoEventMgr::getSenderName(int sender)
{
	return infos[sender].mName;
}

/**
 * @todo: Documentation
 */
DemoEventMgr::DemoEventMgr()
{
}

/**
 * @todo: Documentation
 */
void DemoEventMgr::act(int sender, int event)
{
	switch (sender) {
	case DemoEventSender::Game:
	{
		switch (event) {
		case DemoEventGame::DayEnd:
		{
			gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
			break;
		}
		case DemoEventGame::EnterPikis:
		{
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
		}
		break;
	}
	case DemoEventSender::Navi:
	{
		switch (event) {
		case DemoEventNavi::Fue:
		{
			naviMgr->getNavi()->enterAllPikis();
			break;
		}
		}
		break;
	}
	case DemoEventSender::UFO:
	{
		UfoItem* ufo = itemMgr->getUfo();
		if (ufo) {
			switch (event) {
			case DemoEventUFO::SuckNavi:
			{
				ufo->startConeEffect(0);
				break;
			}
			case DemoEventUFO::SuckNaviDown:
			{
				ufo->startConeEffect(1);
				break;
			}
			case DemoEventUFO::SuckNaviZERO:
			{
				ufo->startConeEffect(2);
				break;
			}
			case DemoEventUFO::SuckFinish:
			{
				ufo->finishConeEffect();
				ufo->setSpotActive(false);
				playerState->setNavi(true);
				Navi* navi = naviMgr->getNavi();
				if (navi) {
					PRINT("**** RIDE UFO \n");
					navi->rideUfo();
				}
				break;
			}
			case DemoEventUFO::Takeoff:
			{
				ufo->startTakeoff();
				pikiMgr->dumpAll();
				break;
			}
			case DemoEventUFO::Henka:
			{
				ufo->startLevelFlag(playerState->mShipUpgradeLevel);
				break;
			}
			case DemoEventUFO::BGStart:
			{
				PRINT("__________________________________________________\n");
				PRINT("******************* START YOZORA *****************\n");
				PRINT("__________________________________________________\n");
				ufo->startYozora();
				break;
			}
			case DemoEventUFO::GalaxStart:
			{
				PRINT("__________________________________________________\n");
				PRINT("******************* START GALAXY *****************\n");
				PRINT("__________________________________________________\n");
				ufo->startGalaxy();
				break;
			}
			}
		}
		break;
	}
	case DemoEventSender::BluOnion:
	case DemoEventSender::RedOnion:
	case DemoEventSender::YelOnion:
	{
		int goalID     = sender - DemoEventSender::BluOnion;
		GoalItem* goal = itemMgr->getContainer(goalID);
		if (goal) {
			switch (event) {
			case DemoEventOnion::EmitPiki:
			{
				goal->mSAICtx.mCurrAnimId++;
				goal->emitPiki();
				break;
			}
			case DemoEventOnion::EraseCone:
			{
				goal->startConeShrink();
				break;
			}
			case DemoEventOnion::EmitCone:
			{
				if (playerState->hasBootContainer(goalID)) {
					goal->startConeEmit();
				}
				break;
			}
			case DemoEventOnion::Takeoff:
			{
				if (playerState->hasContainer(goalID)) {
					goal->startTakeoff();
				}
				break;
			}
			case DemoEventOnion::Land:
			{
				if (playerState->hasContainer(goalID)) {
					goal->startLand();
				}
				break;
			}
			case DemoEventOnion::Boot:
			{
				PRINT("boot onion\n");
				goal->startBoot();
				playerState->setBootContainer(goalID);
				if (playerState->isTutorial() && playerState->mShipEffectPartFlag & 8) {
					Navi* navi = naviMgr->getNavi();
					playerState->mShipEffectPartFlag &= ~8;
					cameraMgr->mCamera->finishMotion();
					cameraMgr->mCamera->mControlsEnabled = true;
#if defined(VERSION_PIKIDEMO)
					cameraMgr->mCamera->startCamera(navi, 1, 0);
#else
					cameraMgr->mCamera->startMotion(1, 0);
#endif
					PRINT("*** FINISH MOTION \n");
				}
				break;
			}
			case DemoEventOnion::BonusPiki:
			{
				if (playerState->hasContainer(goalID) && GameStat::allPikis[goalID] == 0) {
					PRINT("***** SUPPLY 1 PiKI (COLOR = %d)\n", goalID);
					playerState->mResultFlags.setOn(zen::RESFLAG_PikminSeedStageUp);
					goal->mSAICtx.mCurrAnimId++;
					goal->emitPiki();
				}
				break;
			}
			}
		}
		break;
	}
	}
}
