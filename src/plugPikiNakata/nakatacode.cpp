#include "CodeInitializer.h"
#include "DebugLog.h"
#include "PaniPikiAnimator.h"
#include "nlib/System.h"
#include "system.h"
#include "teki.h"

BOOL nakataDebugMode;

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
DEFINE_PRINT("nakatacode")

void NakataCodeInitializer::init()
{
	nakataDebugMode = TRUE;
	PRINT_NAKATA("NNNNNNNNNNNNNNNNNNNNNNNakataCodeInitializer::init\n"); // lol
	NSystem::initSystem(gsys);
	PaniPikiAnimMgr::motionTable = nullptr;
	TekiMgr::initTekiMgr();
}
