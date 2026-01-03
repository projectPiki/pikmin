#include "AIPerf.h"
#include "BaseInf.h"
#include "Controller.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "GameStat.h"
#include "GlobalGameOptions.h"
#include "GoalItem.h"
#include "Interactions.h"
#include "Menu.h"
#include "NaviMgr.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "UfoItem.h"
#include "WorkObject.h"

bool AIPerf::useLOD       = true;
bool AIPerf::showColls    = true;
bool AIPerf::useCollSort  = true;
bool AIPerf::bridgeFast   = true;
bool AIPerf::useASync     = true;
int AIPerf::useGrid       = 2;
int AIPerf::gridShift     = 4;
bool AIPerf::aiGrid       = true;
bool AIPerf::insQuick     = true;
bool AIPerf::iteratorCull = true;
bool AIPerf::pikiMabiki   = true;
int AIPerf::optLevel      = 2;

bool AIPerf::showRoute;
bool AIPerf::generatorMode;
int AIPerf::moveType;
bool AIPerf::kandoOnly;
bool AIPerf::soundDebug;
bool AIPerf::updateSearchBuffer;
bool AIPerf::loopOptimise;
bool AIPerf::useUpdateMgr;
int AIPerf::ufoLevel;
int AIPerf::searchCnt;
int AIPerf::searchCullCnt;
int AIPerf::searchInsertCnt;
int AIPerf::collisionCnt;
int AIPerf::iteratorCullCnt;
int AIPerf::aiCullCnt;
int AIPerf::viewCullCnt;
int AIPerf::outsideViewCnt;
int AIPerf::drawshapeCullCnt;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("aiPerf");

const char* gridStrings[] = { "[grid off]", "[grid xyz]", "[grid xz]" };

/**
 * @todo: Documentation
 */
void AIPerf::clearCounts()
{
	AIPerf::drawshapeCullCnt = 0;
	AIPerf::outsideViewCnt   = 0;
	AIPerf::viewCullCnt      = 0;
	AIPerf::aiCullCnt        = 0;
	AIPerf::iteratorCullCnt  = 0;
	AIPerf::collisionCnt     = 0;
	AIPerf::searchInsertCnt  = 0;
	AIPerf::searchCullCnt    = 0;
	AIPerf::searchCnt        = 0;
}

/**
 * @todo: Documentation
 */
void AIPerf::addMenu(Menu* menu)
{
	char* unused = new char[0x40];
	menu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(menu, &Menu::menuCloseMenu));

	char* bridgeText = new char[0x40];
	sprintf(bridgeText, "%s", AIPerf::bridgeFast ? "Bridge Opt [on]" : "Bridge opt [off]");
	menu->addOption(0, bridgeText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleBridge));

	char* routeText = new char[0x40];
	sprintf(routeText, "%s", AIPerf::showRoute ? "Route Debug [on]" : "Route Debug [off]");
	menu->addOption(0, routeText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleShowRoute));

	char* optLevelText = new char[0x40];
	sprintf(optLevelText, "Opt Level %d", AIPerf::optLevel);
	menu->addOption(0, optLevelText, nullptr);
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_Y, new Delegate1<AIPerf, Menu&>(this, &AIPerf::decOptLevel));
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_X, new Delegate1<AIPerf, Menu&>(this, &AIPerf::incOptLevel));

	char* collSortText = new char[0x40];
	sprintf(collSortText, "%s", AIPerf::useCollSort ? "[use Coll Sort]" : "[ignore Coll Sort]");
	menu->addOption(0, collSortText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleCollSort));

	char* kandoDebugText = new char[0x40];
	sprintf(kandoDebugText, "%s", AIPerf::kandoOnly ? "Kando Debug [on]" : "Kando Debug [off]");
	menu->addOption(0, kandoDebugText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleKando));

	char* soundText = new char[0x40];
	sprintf(soundText, "%s", AIPerf::soundDebug ? "Sound Debug [on]" : "Sound Debug [off]");
	menu->addOption(0, soundText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleSoundDebug));

	char* modeText = new char[0x40];
	sprintf(modeText, "%s", AIPerf::generatorMode ? "Generator Mode" : "Game Mode");
	menu->addOption(0, modeText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleGeneratorMode));

	char* moveTypeText      = new char[0x40];
	const char* moveTypes[] = { "stop", "no stop", "slip" };
	sprintf(moveTypeText, "%s", moveTypes[AIPerf::moveType]);
	menu->addOption(0, moveTypeText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleMoveType));

	char* lodText = new char[0x40];
	sprintf(lodText, "%s", AIPerf::useLOD ? "LOD [on]" : "LOD [off]");
	menu->addOption(0, lodText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleLOD));

	char* collsText = new char[0x40];
	sprintf(collsText, "%s", AIPerf::showColls ? "Colls [on]" : "Colls [off]");
	menu->addOption(0, collsText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleColls));

	char* asyncText = new char[0x40];
	sprintf(asyncText, "%s", AIPerf::useASync ? "ASYNC [on]" : "ASYNC [off]");
	menu->addOption(0, asyncText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleASync));

	char* insQuickText = new char[0x40];
	sprintf(insQuickText, "%s", AIPerf::insQuick ? "Ins [Fast]" : "Ins [Slow]");
	menu->addOption(0, insQuickText, new Delegate1<AIPerf, Menu&>(this, &AIPerf::toggleInsQuick));

	char* ufoLevelText = new char[0x40];
	sprintf(ufoLevelText, "UFO LEVEL %d", AIPerf::ufoLevel);
	menu->addOption(0, ufoLevelText, nullptr);
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_Y, new Delegate1<AIPerf, Menu&>(this, &AIPerf::decUfoLevel));
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_X, new Delegate1<AIPerf, Menu&>(this, &AIPerf::incUfoLevel));

	menu->addOption(0, "Flower Pikis", nullptr);
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, TERNARY_BUGFIX(KBBTN_A, KBBTN_Y),
	                  new Delegate1<AIPerf, Menu&>(this, &AIPerf::flowerPiki));

	menu->addOption(0, "Break sluice", nullptr);
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, TERNARY_BUGFIX(KBBTN_A, KBBTN_Y),
	                  new Delegate1<AIPerf, Menu&>(this, &AIPerf::breakSluice));

	menu->addOption(0, "COLLECT PIKIS", nullptr);
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, TERNARY_BUGFIX(KBBTN_A, KBBTN_Y),
	                  new Delegate1<AIPerf, Menu&>(this, &AIPerf::collectPikis));

	menu->addOption(0, "FULLFILL PIKI", nullptr);
	menu->addKeyEvent(Menu::KeyEventType::OnInputRelease, TERNARY_BUGFIX(KBBTN_A, KBBTN_Y),
	                  new Delegate1<AIPerf, Menu&>(this, &AIPerf::fullfillPiki));
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleMoveType(Menu& menu)
{
	AIPerf::moveType = (AIPerf::moveType + 1) % 3;

	const char* types[] = { "stop", "no stop", "slip" };
	sprintf(menu.mCurrentItem->mLabel, "%s", types[AIPerf::moveType]);
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleGeneratorMode(Menu& menu)
{
	AIPerf::generatorMode = AIPerf::generatorMode ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::generatorMode ? "Generator Mode" : "Game Mode");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleBridge(Menu& menu)
{
	AIPerf::bridgeFast = AIPerf::bridgeFast ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::bridgeFast ? "Bridge Opt [on]" : "Bridge Opt [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleShowRoute(Menu& menu)
{
	AIPerf::showRoute = AIPerf::showRoute ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::showRoute ? "Route Debug [on]" : "Route Debug [off]");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void AIPerf::toggleAIGrid(Menu& menu)
{
	AIPerf::aiGrid = AIPerf::aiGrid ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::aiGrid ? "AI GRID [on]" : "AI GRID [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleKando(Menu& menu)
{
	AIPerf::kandoOnly = AIPerf::kandoOnly ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::kandoOnly ? "Kando Debug [on]" : "KandoDebug [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleLOD(Menu& menu)
{
	AIPerf::useLOD = AIPerf::useLOD ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::useLOD ? "LOD [on]" : "LOD [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleColls(Menu& menu)
{
	AIPerf::showColls = AIPerf::showColls ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::showColls ? "Colls [on]" : "Colls [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleASync(Menu& menu)
{
	AIPerf::useASync = AIPerf::useASync ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::useASync ? "ASYNC [on]" : "ASYNC [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleInsQuick(Menu& menu)
{
	AIPerf::insQuick = AIPerf::insQuick ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::insQuick ? "Ins [Fast]" : "Ins [Slow]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleSoundDebug(Menu& menu)
{
	AIPerf::soundDebug = AIPerf::soundDebug ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::soundDebug ? "Sound Debug [on]" : "Sound Debug [off]");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void AIPerf::toggleUpdateMgr(Menu& menu)
{
	AIPerf::useUpdateMgr = AIPerf::useUpdateMgr ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::useUpdateMgr ? "updateMgr [on]" : "updateMgr [off]");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void AIPerf::togglePikiMabiki(Menu& menu)
{
	AIPerf::pikiMabiki = AIPerf::pikiMabiki ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::pikiMabiki ? "pikiMabiki [on]" : "pikiMabiki [off]");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void AIPerf::togglePsOptimise(Menu& menu)
{
	// Wrong, no idea what the variable in here is meant to be
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::pikiMabiki ? "psOptimise [on]" : "psOptimise [off]");
}

/**
 * @todo: Documentation
 */
void AIPerf::toggleCollSort(Menu& menu)
{
	AIPerf::useCollSort = AIPerf::useCollSort ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::useCollSort ? "[use Coll Sort]" : "[ignore Coll Sort]");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void AIPerf::toggleIteratorCull(Menu& menu)
{
	AIPerf::iteratorCull = AIPerf::iteratorCull ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::iteratorCull ? "[it-cull on]" : "[it-cull off]");
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000070
 */
void AIPerf::toggleUseGrid(Menu& menu)
{
	AIPerf::useGrid = (AIPerf::useGrid + 1) % 3;
	sprintf(menu.mCurrentItem->mLabel, "%s", gridStrings[AIPerf::useGrid]);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void AIPerf::incGridShift(Menu& menu)
{
	if (AIPerf::gridShift < 8) {
		AIPerf::gridShift++;
	}

	sprintf(menu.mCurrentItem->mLabel, "grid shift %d", AIPerf::gridShift);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void AIPerf::decGridShift(Menu& menu)
{
	if (AIPerf::gridShift > 0) {
		AIPerf::gridShift--;
	}

	sprintf(menu.mCurrentItem->mLabel, "grid shift %d", AIPerf::gridShift);
}

/**
 * @todo: Documentation
 */
void AIPerf::incOptLevel(Menu& menu)
{
	if (AIPerf::optLevel < 3) {
		AIPerf::optLevel++;
	}

	sprintf(menu.mCurrentItem->mLabel, "Opt Level %d", AIPerf::optLevel);
}

/**
 * @todo: Documentation
 */
void AIPerf::decOptLevel(Menu& menu)
{
	if (AIPerf::optLevel > 0) {
		AIPerf::optLevel--;
	}

	sprintf(menu.mCurrentItem->mLabel, "Opt Level %d", AIPerf::optLevel);
}

u32 ufoParts[] = {
	UFOID_MainEngine,
	UFOID_Bowsprit,
	UFOID_GluonDrive,
	UFOID_AntiDioxinFilter,
	UFOID_EternalFuelDynamo,
	UFOID_WhimsicalRadar,
	UFOID_InterstellarRadio,
	UFOID_GuardSatellite,
	UFOID_ChronosReactor,
	UFOID_RadiationCanopy,
	UFOID_GeigerCounter,
	UFOID_Sagittarius,
	UFOID_Libra,
	UFOID_OmegaStabilizer,
	UFOID_IoniumJet1,
	UFOID_IoniumJet2,
	UFOID_ShockAbsorber,
	UFOID_GravityJumper,
	UFOID_PilotSeat,
	UFOID_NovaBlaster,
	UFOID_AutomaticGear,
	UFOID_ZirconiumRotor,
	UFOID_ExtraordinaryBolt,
	UFOID_RepairTypeBolt,
	UFOID_SpaceFloat,
	UFOID_MassageMachine,
	UFOID_SecretSafe,
	UFOID_PositronGenerator,
	UFOID_AnalogComputer,
	UFOID_UVLamp,
};

/**
 * @todo: Documentation
 */
void AIPerf::incUfoLevel(Menu& menu)
{
	if (AIPerf::ufoLevel <= MAX_UFO_PARTS) {
		bool isInvisiblePart = false;
		if (AIPerf::ufoLevel >= UFO_ShockAbsorber) {
			// "Naka" ship parts are not visible on the UFO.
			isInvisiblePart = true;
		}

		UfoItem* shipInstance = itemMgr->getUfo();
		int lastLevel         = playerState->mShipUpgradeLevel;

		if (shipInstance) {
			if (AIPerf::ufoLevel == 0) {
				shipInstance->mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::WaitTutorial, shipInstance));
			} else {
				shipInstance->mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::Wait, shipInstance));
			}

			shipInstance->mAnimator.setMotionSpeed(0, 30.0f);
		}

		playerState->getUfoParts(ufoParts[AIPerf::ufoLevel], isInvisiblePart);
		playerState->ufoAssignStart();

		if (shipInstance && lastLevel != playerState->mShipUpgradeLevel) {
			PRINT("*** START HENKA MOTION LEVEL %d (lastLevel %d)\n", playerState->mShipUpgradeLevel, lastLevel);
			shipInstance->startLevelFlag(playerState->mShipUpgradeLevel);
		}

		AIPerf::ufoLevel++;
	}

	sprintf(menu.mCurrentItem->mLabel, "UFO Level %d", AIPerf::ufoLevel);
}

/**
 * @todo: Documentation
 */
void AIPerf::decUfoLevel(Menu& menu)
{
	sprintf(menu.mCurrentItem->mLabel, "UFO Level %d", AIPerf::ufoLevel);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void AIPerf::toggleUpdateSearchBuffer(Menu& menu)
{
	AIPerf::updateSearchBuffer = AIPerf::updateSearchBuffer ? 0 : 1;
	sprintf(menu.mCurrentItem->mLabel, "%s", AIPerf::updateSearchBuffer ? "[upd srchbuff]" : "[don't upd srchbuff]");
}

/**
 * @todo: Documentation
 */
void AIPerf::collectPikis(Menu& menu)
{
	Navi* navi         = naviMgr->getNavi();
	Vector3f playerPos = navi->mCursorWorldPos;

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && !piki->isStickTo()) {
			piki->mSRT.t = playerPos;
		}
	}
}

/**
 * Collects all pikis and puts them in the onion.
 */
void AIPerf::fullfillPiki(Menu& menu)
{
	for (int i = 0; i < PikiColorCount; i++) {
		if (!playerState->hasContainer(i)) {
			continue;
		}

		GoalItem* currentOnion = itemMgr->getContainer(i);
		if (currentOnion) {
			for (int i = 0; i < MAX_PIKI_ON_FIELD; i++) {
				pikiInfMgr.incPiki(currentOnion->mOnionColour, Leaf);
				currentOnion->mHeldPikis[Leaf]++;
				GameStat::containerPikis.inc(currentOnion->mOnionColour);
				GameStat::update();
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void AIPerf::flowerPiki(Menu& menu)
{
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Piki* piki = (Piki*)*iter;
		piki->setFlower(2);
	}
}

/**
 * @todo: Documentation
 */
void AIPerf::breakSluice(Menu& menu)
{
	Navi* player = naviMgr->getNavi();
	if (player && itemMgr) {
		Creature* nearestWall = nullptr;
		f32 distanceToWall    = 1000.0f;
		Iterator wallIter(itemMgr->getMeltingPotMgr());
		CI_LOOP(wallIter)
		{
			Creature* wall = *wallIter;
			if (!wall->isSluice()) {
				continue;
			}

			f32 distance = qdist2(player->mCursorWorldPos.x, player->mCursorWorldPos.z, wall->mSRT.t.x, wall->mSRT.t.z);
			if (distance < distanceToWall) {
				distanceToWall = distance;
				nearestWall    = wall;
			}
		}

		Bridge* closestBridge = nullptr;
		f32 distToBridge      = 1000.0f;
		Iterator bridgeIter(workObjectMgr);
		CI_LOOP(bridgeIter)
		{
			WorkObject* i = (WorkObject*)*bridgeIter;
			if (!i->isBridge()) {
				continue;
			}

			f32 distance = qdist2(player->mCursorWorldPos.x, player->mCursorWorldPos.z, i->mSRT.t.x, i->mSRT.t.z);
			if (distance < distToBridge) {
				distToBridge  = distance;
				closestBridge = (Bridge*)i;
			}
		}

		if (nearestWall && closestBridge) {
			if (distanceToWall < distToBridge) {
				closestBridge = nullptr;
			} else {
				nearestWall = nullptr;
			}
		}

		if (nearestWall) {
			InteractBomb bomb(player, 12800.0f, nullptr);
			nearestWall->stimulate(bomb);
		} else if (closestBridge) {
			// Complete construction up to the current phase.
			int constructionPhase = closestBridge->getStage();
			for (int i = 0; i < constructionPhase; i++) {
				closestBridge->setStageFinished(i, true);
				closestBridge->mStageProgressList[i] = 1000.0f;
			}

			closestBridge->mStartWaypoint->setFlag(true);
			closestBridge->mEndWaypoint->setFlag(true);
		}
	}
}
