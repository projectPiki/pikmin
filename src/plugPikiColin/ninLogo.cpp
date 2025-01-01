#include "NinLogoSection.h"
#include "NinLogoSetupSection.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	80061250
 * Size:	000180
 */
void NinLogoSection::init()
{
	Node::init("<NinLogoSection>");
	gsys->mTimerState = TS_Off;
	add(new NinLogoSetupSection());
}
