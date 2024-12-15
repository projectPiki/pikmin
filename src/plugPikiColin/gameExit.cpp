#include "GameExitSection.h"
#include "gameflow.h"
#include "FlowController.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "GameExit");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005B690
 * Size:	00009C
 */
GameExitSection::GameExitSection()
{
	gsys->resetHeap(2, 1);
	gsys->mCurrMemInfo = nullptr;
	gsys->_214.initCore("");
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
		gameflow._2B0           = flowCont._244 + 3;
	} else {
		gameflow.mGameSectionID = SECTION_Titles;
	}

	gsys->softReset();
}
