#include "GameCreditsSection.h"
#include "system.h"
#include "FlowController.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("GameCreditsSection");

/*
 * --INFO--
 * Address:	8019B888
 * Size:	000094
 */
GameCreditsSection::GameCreditsSection()
{
	Node::init("<GameCreditsSection>");
	gsys->setFrameClamp(1);
	flowCont._24C = 0;
	flowCont._250 = 0;
}
