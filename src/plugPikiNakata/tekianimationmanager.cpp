#include "TekiAnimationManager.h"
#include "Dolphin/os.h"
#include "Teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "tekianimationmanager");
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
 * Address:	80143E48
 * Size:	000094
 */
TekiAnimationManager::TekiAnimationManager(TekiMgr* mgr)
    : Node("TekiAnimationManager")
{
	mTekiMgr = mgr;
}

/*
 * --INFO--
 * Address:	80143EDC
 * Size:	000080
 */
void TekiAnimationManager::read(RandomAccessStream& input)
{
	for (int i = 0; i < TEKI_TypeCount; i++) {
		mTekiMgr->mTekiShapes[i]->mAnimMgr->read(input);
	}
}
