#include "GameCreditsSection.h"
#include "system.h"
#include "OnePlayerSection.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "GameCreditsSection");
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
 * Address:	8019B888
 * Size:	000094
 */
GameCreditsSection::GameCreditsSection()
{
	Node::init("<GameCreditsSection>");
	gsys->mFrameRate = 1;
	flowCont._24C    = 0;
	flowCont._250    = 0;
}
