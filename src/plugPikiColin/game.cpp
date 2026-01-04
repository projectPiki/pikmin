#include "OnePlayerSection.h"

#include "CardSelectSection.h"
#include "CmdStream.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
#include "GameCourseClearSection.h"
#include "GameCreditsSection.h"
#include "GameExitSection.h"
#include "GameSetupSection.h"
#include "GameStageClearSection.h"
#include "IntroGameSection.h"
#include "MapSelect.h"
#include "MemStat.h"
#include "NewPikiGame.h"
#include "gameflow.h"
#include "sysNew.h"
#include "system.h"
#include <stdio.h>
#include <string.h>

/// Specialised global game flow controller for single-player gameplay (story or challenge mode).
FlowController flowCont;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameOnePlayer");

/**
 * @brief Stubbed function, appears to be for writing stage info to a file stream.
 * @note UNUSED Size: 000004
 */
void StageInfo::write(RandomAccessStream&)
{
	PRINT("writing information for stage %d\n", mStageID);
	// UNUSED FUNCTION
}

/**
 * @brief Stubbed function, appears to be for reading stage info from a file stream.
 */
void StageInfo::read(RandomAccessStream&)
{
	PRINT("reading information for stage %d\n", mStageID);
}

/**
 * @brief Reads in and parses generator information from a file stream.
 *
 * @param commands Stream of commands to be parsed and stored.
 */
void StageInfo::parseGenerators(CmdStream* commands)
{
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);
		if (!commands->isToken("genfile")) {
			continue;
		}

		GenFileInfo* fileInfo = new GenFileInfo;

		// generator file name - [#-#].gen
		fileInfo->setName(StdSystem::stringDup(commands->getToken(true)));

		u32 startDay;
		sscanf(commands->getToken(true), "%d", &startDay);

		u32 endDay;
		sscanf(commands->getToken(true), "%d", &endDay);

		u32 duration;
		sscanf(commands->getToken(true), "%d", &duration);

		fileInfo->mFirstSpawnDay = startDay;
		fileInfo->mLastSpawnDay  = endDay;
		fileInfo->mDayLimit      = duration;

		PRINT("adding new genfile info %s : %d, %d -> %d\n", fileInfo->mName, fileInfo->mFirstSpawnDay, fileInfo->mLastSpawnDay,
		      fileInfo->mDayLimit);
		mGenFileList.add(fileInfo);
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/**
 * @brief Finds and sets the current stage by filename.
 *
 * @param fileName File name of stage to set as current stage.
 * @note UNUSED Size: 000094
 */
void FlowController::setStage(immut char* fileName)
{
	FOREACH_NODE(StageInfo, mStageList.mChild, stage)
	{
		if (strcmp(stage->mFileName, fileName) == 0) {
			mCurrentStage = stage;
			sprintf(mCurrStageFilePath, "%s", stage->mFileName);
			sprintf(mDoorStageFilePath, "%s", stage->mFileName);
			break;
		}
	}
}

/**
 * @brief Parses the stages list (stages/stages.ini) and stores info about each map.
 *
 * @param fileName Name of stages file to parse (only ever called as stages/stages.ini).
 */
void FlowController::readMapList(immut char* fileName)
{
	mStageList.initCore("stages");

	// try and open file
	RandomAccessStream* file = gsys->openFile(fileName, true, true);
	if (!file) {
		return;
	}

	CmdStream* commands = new CmdStream(file);
	StageInfo* newStage;
	u16 stageIdx = 0;
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);

		// each stage starts with "new_map"
		if (!commands->isToken("new_map")) {
			continue;
		}

		memStat->start("stageInfo");

		newStage              = new StageInfo();
		newStage->mStageIndex = stageIdx;
		newStage->mStageInf.init();
		mStageList.add(newStage);
		memStat->end("stageInfo");
		stageIdx++;

		// in reality, every new_map is noted as visible - others are just commented out.
		commands->getToken(true);
		newStage->mIsVisible = strcmp(commands->mCurrentToken, "visible") == 0 ? TRUE : FALSE;

		// {
		commands->getToken(true);

		while (!commands->endOfCmds() && !commands->endOfSection()) {

			commands->getToken(true);
			if (commands->isToken("name")) {
				newStage->mStageName = StdSystem::stringDup(commands->getToken(true));
				PRINT("adding new stage %s\n", newStage->mStageName);
				continue;
			}

			if (commands->isToken("id")) {
				// only playable maps (story and challenge) have ids - test maps don't
				u32 stageID;
				sscanf(commands->getToken(true), "%d", &stageID);
				newStage->mStageID = stageID;
				continue;
			}

			if (commands->isToken("chid")) {
				// only challenge mode stages have challenge mode IDs - these are always the same as id
				u32 chID;
				sscanf(commands->getToken(true), "%d", &chID);
				newStage->mChalStageID = chID;
				continue;
			}

			if (commands->isToken("file")) {
				// stage info file (stages/[name].ini)
				newStage->mFileName = StdSystem::stringDup(commands->getToken(true));
				continue;
			}

			if (commands->isToken("generator")) {
				// block of genfile information, for changing spawns depending on day number
				// only for Impact Site, Forest of Hope, Forest Navel and Distant Spring
				commands->getToken(true);
				newStage->parseGenerators(commands);
			}
		}

		if (!commands->endOfCmds()) {
			commands->getToken(true);
		}
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
	file->close();
}

#if defined(VERSION_G98E01_PIKIDEMO)
/// Load banner textures for each map (as well as one for entering from title).
static immut char* levNames[]
    = { "intro/map0.bti", "intro/ot_map.bti", "intro/map2.bti", "intro/map3.bti", "intro/map4.bti", "intro/loading.bti" };
#elif defined(VERSION_GPIP01_00)
/// Load banner textures for each map.
static immut char* levNames[STAGE_COUNT] = {
	"map0.bti", "map1.bti", "map2.bti", "map3.bti", "map4.bti",
};
/// PAL-exclusive directory paths for load banner textures, since textures are split out into directories by language.
static immut char* dirNames[] = {
	"intro/eng_tex", "intro/fre_tex", "intro/ger_tex", "intro/spa_tex", "intro/ita_tex",
};
#else
/// Load banner textures for each map.
static immut char* levNames[STAGE_COUNT] = {
	"intro/map0.bti", "intro/map1.bti", "intro/map2.bti", "intro/map3.bti", "intro/map4.bti",
};
#endif

/**
 * @brief Initialises the next queued up story or challenge mode game section.
 *
 * @warning NON-MATCHING! Functionally equivalent.
 */
void OnePlayerSection::init()
{
	Node::init("<OnePlayerSection>");

	// save our current debug print setting in case we change it
	BOOL displayState = gsys->mTogglePrint;

	// keep trying to initialise a section until we get one
	Section* currentSection = nullptr;
	while (!currentSection) {

		// process whatever section ID we have queued up
		int nextSectionType = gameflow.mNextOnePlayerSectionID;
		switch (nextSectionType) {
		case ONEPLAYER_GameSetup:
		{
			// loading section! (post-title screen, pre-file select)
			PRINT("making new SETUP\n");
			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
#if defined(VERSION_G98E01_PIKIDEMO)
			// the demo has a single loading banner for the setup section
			gameflow.mLevelBannerTex       = gameflow.setLoadBanner(levNames[5]);
			gameflow.mLevelBannerFadeValue = 0.0f;

#elif defined(VERSION_GPIP01_00)
			// only show a loading banner during setup for the E3 demos
			if (gameflow.mNextOnePlayerSectionOnDayEnd >= ONEPLAYER_E3_MIN && gameflow.mNextOnePlayerSectionOnDayEnd <= ONEPLAYER_E3_MAX) {
				PRINT("setting banner!\n");
				char bannerTex[128];
				sprintf(bannerTex, "%s/%s", dirNames[gameflow.mGamePrefs.getChildMode()],
				        levNames[gameflow.mNextOnePlayerSectionOnDayEnd - ONEPLAYER_E3_STAGE_OFFSET]);

				gameflow.mLevelBannerTex       = gameflow.setLoadBanner(bannerTex);
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTex = nullptr;
			}
#else
			// only show a loading banner during setup for the E3 demos
			if (gameflow.mNextOnePlayerSectionOnDayEnd >= ONEPLAYER_E3_MIN && gameflow.mNextOnePlayerSectionOnDayEnd <= ONEPLAYER_E3_MAX) {
				PRINT("setting banner!\n");
				gameflow.mLevelBannerTex
				    = gameflow.setLoadBanner(levNames[gameflow.mNextOnePlayerSectionOnDayEnd - ONEPLAYER_E3_STAGE_OFFSET]);
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTex = nullptr;
			}
#endif

			currentSection = new GameSetupSection();
			gsys->endLoading();
			break;
		}
		case ONEPLAYER_CardSelect:
		{
			// file select section!
			PRINT("making new CARDSELECT\n");
			currentSection = new CardSelectSection();
			break;
		}
		case ONEPLAYER_MapSelect:
		{
			// world map section!
			PRINT("making new MAPSELECT\n");
			currentSection = new MapSelectSection();
			break;
		}
		// The following three cases are leftovers from the E3 2001 showfloor demo!  At the event, the title screen had a
		// unique menu that could directly access three different stages: "Tutorial", "Forest Day 1", and "Forest Day 2".
		case ONEPLAYER_E3Tutorial:
		{
			// tutorial level! (impact site for E3 demo)
			if (!gameflow.mLevelBannerTex) {
				PRINT("setting banner!\n");
#if defined(VERSION_GPIP01_00)
				char bannerTex[128];
				sprintf(bannerTex, "%s/%s", dirNames[gameflow.mGamePrefs.getChildMode()],
				        levNames[nextSectionType - ONEPLAYER_E3_STAGE_OFFSET]);
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(bannerTex);
#else
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(levNames[nextSectionType - ONEPLAYER_E3_STAGE_OFFSET]);
#endif
			}

			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			flowCont.setStage("stages/practice.ini");

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 1;

			// force the loop to rerun and load into gameplay
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;

			// next level after this should be forest day 1
			gameflow.mNextOnePlayerSectionOnDayEnd = ONEPLAYER_E3ForestDay1;
			break;
		}
		case ONEPLAYER_E3ForestDay1:
		{
			// forest level 1! (forest of hope day 1 for E3 demo)
			if (!gameflow.mLevelBannerTex) {
				PRINT("setting banner!\n");
#if defined(VERSION_GPIP01_00)
				char bannerTex[128];
				sprintf(bannerTex, "%s/%s", dirNames[gameflow.mGamePrefs.getChildMode()], levNames[nextSectionType - 2]);
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(bannerTex);
#else
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(levNames[nextSectionType - 2]);
#endif
			}
			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			flowCont.setStage("stages/stage1.ini");

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 1;

			// force the loop to rerun and load into gameplay
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;

			// next level after this should be forest day 2
			gameflow.mNextOnePlayerSectionOnDayEnd = ONEPLAYER_E3ForestDay2;
			break;
		}
		case ONEPLAYER_E3ForestDay2:
		{
			// forest level 2! (forest of hope day 2 for E3 demo)
			if (!gameflow.mLevelBannerTex) {
				PRINT("setting banner!\n");
#if defined(VERSION_GPIP01_00)
				char bannerTex[128];
				sprintf(bannerTex, "%s/%s", dirNames[gameflow.mGamePrefs.getChildMode()], levNames[nextSectionType - 2]);
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(bannerTex);
#else
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(levNames[nextSectionType - 2]);
#endif
			}

			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			flowCont.setStage("stages/play_3.ini");

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 2;

			// force the loop to rerun and load into gameplay
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;

			// next level after this should be the credits (hope you enjoyed the demo!)
			gameflow.mNextOnePlayerSectionOnDayEnd = ONEPLAYER_GameCredits;
			break;
		}
		case ONEPLAYER_IntroGame:
		{
			// intro crash landing cutscene!
			PRINT("making new INTRO\n");
			currentSection = new IntroGameSection();
			break;
		}
		case ONEPLAYER_NewPikiGame:
		{
			// gameplay!

			// The exact position of this DLL-exclusive code is unclear because some of the following code is DOL-exclusive.
#ifdef WIN32
			_nsPrint = FALSE;
			_yPrint  = FALSE;
			_kPrint  = FALSE;
			_nPrint  = FALSE;
			_cPrint  = FALSE;
#endif

			if (!gsys->mIsLoadingActive) {
				gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			}

			// this tex nullptr does not wanna load properly here, and keeps getting optimised out into the else block
			Texture* tex = nullptr;
			u32 stageID  = flowCont.mCurrentStage->mStageID;

			// if we're loading into a "valid" story or challenge mode stage, show the area title banner
			if (stageID <= STAGE_COUNT - 1) {
#if defined(VERSION_GPIP01_00)
				char bannerTex[128];
				sprintf(bannerTex, "%s/%s", dirNames[gameflow.mGamePrefs.getChildMode()], levNames[stageID]);
				gameflow.mLevelBannerTex = tex = gameflow.setLoadBanner(bannerTex);
#else
				gameflow.mLevelBannerTex = tex = gameflow.setLoadBanner(levNames[stageID]);
#endif
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTex = tex;
			}
			PRINT("making new MAINGAME\n");
			currentSection = new NewPikiGameSection();
			break;
		}
		case ONEPLAYER_GameCourseClear:
		{
			// this is never actually hit during gameplay
			PRINT("making new COURSECLEAR\n");
			currentSection = new GameCourseClearSection();
			break;
		}
		case ONEPLAYER_GameStageClear:
		{
			// this is never actually hit during gameplay
			PRINT("making new STAGECLEAR\n");
			currentSection = new GameStageClearSection();
			break;
		}
		case ONEPLAYER_GameCredits:
		{
			// this is only hit during the E3 Demo
			PRINT("making new CREDITS\n");
			gsys->startLoading(nullptr, true, 60);
			currentSection = new GameCreditsSection();
			gsys->endLoading();
			break;
		}
		case ONEPLAYER_GameExit:
		{
			// going back to title (or credits movie)!
			PRINT("making new EXIT\n");
			currentSection = new GameExitSection();
			break;
		}
		}

		// if we adjusted the target section ID during our loop, wipe the section and retry
		if (gameflow.mNextOnePlayerSectionID != nextSectionType) {
			currentSection = nullptr;
		}
	}

	// add the new initialised game section to our section list
	add(currentSection);

	// restore debug print setting
	gsys->mTogglePrint = displayState;
}
