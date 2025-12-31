#include "GameExitSection.h"

#include "DebugLog.h"
#include "FlowController.h"
#include "gameflow.h"
#include "system.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameExit");

/**
 * @brief Constructs cleanup section, resetting the app heap and memory info.
 */
GameExitSection::GameExitSection()
{
	gsys->resetHeap(SYSHEAP_App, AYU_STACK_GROW_DOWN);
	gsys->mCurrMemInfo = nullptr;
	PRINT("clearing aram directory!\n");
	gsys->mAramRoot.initCore("");
}

/**
 * @brief Decides on next section and transits - either to the credits cutscene if we finished the game, or to title screen.
 */
void GameExitSection::update()
{
	// reset our OnePlayerSection target for the next time we try and enter story or challenge mode
	gameflow.mNextOnePlayerSectionID = ONEPLAYER_GameSetup;
	if (flowCont.mEndingType != ENDING_None) {
		// play the credits!
		gameflow.mNextGameSectionID = SECTION_MovSample;
		gameflow.mCurrIntroMovieID  = flowCont.mEndingType + MOV_ENDING_OFFSET;
	} else {
		// go to title
		gameflow.mNextGameSectionID = SECTION_Titles;
	}

	// force transit
	gsys->softReset();
}
