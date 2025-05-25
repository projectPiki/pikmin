#include "CodeInitializer.h"
#include "nlib/System.h"
#include "PaniPikiAnimator.h"
#include "system.h"
#include "teki.h"
#include "DebugLog.h"

BOOL nakataDebugMode;

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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	8011B6AC
 * Size:	000038
 */
void NakataCodeInitializer::init()
{
	nakataDebugMode = TRUE;
	NSystem::initSystem(gsys);
	PaniPikiAnimMgr::motionTable = nullptr;
	TekiMgr::initTekiMgr();
}
