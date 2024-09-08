#include "GameExitSection.h"
#include "gameflow.h"
#include "OnePlayerSection.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "GameExit");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
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
	gsys->_19C = 0;
	gsys->_214.initCore("");
}

/*
 * --INFO--
 * Address:	8005B72C
 * Size:	000050
 */
void GameExitSection::update()
{
	gameflow._1F4 = 0;
	if (flowCont._244) {
		gameflow._1F0 = 2;
		gameflow._2B0 = flowCont._244 + 3;
	} else {
		gameflow._1F0 = 1;
	}

	gsys->mPending = true;
}
