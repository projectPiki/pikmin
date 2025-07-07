#include "DebugLog.h"
#include "FlowController.h"
#include "GameExitSection.h"
#include "gameflow.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("GameExit");

/*
 * --INFO--
 * Address:	8005B690
 * Size:	00009C
 */
GameExitSection::GameExitSection()
{
	gsys->resetHeap(2, 1);
	gsys->mCurrMemInfo = nullptr;
	PRINT("clearing aram directory!\n");
	gsys->mAramRoot.initCore("");
}

/*
 * --INFO--
 * Address:	8005B72C
 * Size:	000050
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
