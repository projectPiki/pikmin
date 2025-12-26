#include "TekiAnimationManager.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("tekianimationmanager")

/**
 * @todo: Documentation
 */
TekiAnimationManager::TekiAnimationManager(TekiMgr* mgr)
    : Node("TekiAnimationManager")
{
	mTekiMgr = mgr;
}

/**
 * @todo: Documentation
 */
void TekiAnimationManager::read(RandomAccessStream& input)
{
	for (int i = 0; i < TEKI_TypeCount; i++) {
		mTekiMgr->mTekiShapes[i]->mAnimMgr->read(input);
	}
}
