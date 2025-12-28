#include "DebugLog.h"
#include "FlowController.h"
#include "GameExitSection.h"
#include "gameflow.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameExit");

/**
 * @todo: Documentation
 */
GameExitSection::GameExitSection()
{
	gsys->resetHeap(SYSHEAP_App, AYU_STACK_GROW_DOWN);
	gsys->mCurrMemInfo = nullptr;
	PRINT("clearing aram directory!\n");
	gsys->mAramRoot.initCore("");
}

/**
 * @todo: Documentation
 */
void GameExitSection::update()
{
	gameflow.mNextOnePlayerSectionID = ONEPLAYER_GameSetup;
	if (flowCont.mEndingType != ENDING_None) {
		gameflow.mNextGameSectionID = SECTION_MovSample;
		gameflow.mCurrIntroMovieID  = flowCont.mEndingType + MOV_ENDING_OFFSET;
	} else {
		gameflow.mNextGameSectionID = SECTION_Titles;
	}

	gsys->softReset();
}
