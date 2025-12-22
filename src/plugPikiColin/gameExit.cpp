#include "DebugLog.h"
#include "FlowController.h"
#include "GameExitSection.h"
#include "gameflow.h"
#include "system.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameExit");

/**
 * @TODO: Documentation
 */
GameExitSection::GameExitSection()
{
	gsys->resetHeap(2, 1);
	gsys->mCurrMemInfo = nullptr;
	PRINT("clearing aram directory!\n");
	gsys->mAramRoot.initCore("");
}

/**
 * @TODO: Documentation
 */
void GameExitSection::update()
{
	gameflow.mNextOnePlayerSectionID = ONEPLAYER_GameSetup;
	if (flowCont._244) {
		gameflow.mGameSectionID = SECTION_MovSample;
		gameflow.mIntroMovieId  = flowCont._244 + 3;
	} else {
		gameflow.mGameSectionID = SECTION_Titles;
	}

	gsys->softReset();
}
